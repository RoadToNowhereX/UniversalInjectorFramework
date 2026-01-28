#include "pch.h"
#include "text_processor.h"

#include <bitset>
#include <regex>

#include "ansi.h"
#include "config.h"
#include "encoding.h"
#include "hooks.h"
#include "utils.h"

using namespace uif::ansi;
using api = uif::features::text_processor::api;

namespace uif::features
{
#pragma region Rules

	namespace {
		class replace_chars_rule : public text_processor::processing_rule
		{
			std::wstring source;
			std::wstring target;

		public:
			explicit replace_chars_rule(std::wstring sourceChars, std::wstring targetChars)
				: source(std::move(sourceChars)), target(std::move(targetChars))
			{
			}

			bool process(std::wstring& value) override
			{
				const size_t substCount = std::min(source.length(), target.length());
				const size_t valueLength = value.length();

				if (substCount == 0) return false;
				bool anyMatch = false;

				for (size_t i = 0; i < valueLength; ++i)
				{
					for (size_t j = 0; j < substCount; j++)
					{
						if (value[i] == source[j])
						{
							value[i] = target[j];
							anyMatch = true;
							goto nextChar;
						}
					}

				nextChar:;
				}

				return anyMatch;
			}
		};

		class replace_full_string_rule : public text_processor::processing_rule
		{
			std::vector<std::wstring> source;
			std::vector<std::wstring> target;

		public:
			explicit replace_full_string_rule(std::vector<std::wstring> source, std::vector<std::wstring> target)
				: source(std::move(source)), target(std::move(target))
			{
			}

			bool process(std::wstring& value) override
			{
				size_t count = std::min(source.size(), target.size());
				for (size_t i = 0; i < count; ++i)
				{
					if (value == source[i])
					{
						value.assign(target[i]);
						return true;
					}
				}

				return false;
			}
		};

		class replace_substring_rule : public text_processor::processing_rule
		{
			std::vector<std::wstring> source;
			std::vector<std::wstring> target;

		public:
			explicit replace_substring_rule(std::vector<std::wstring> source, std::vector<std::wstring> target)
				: source(std::move(source)), target(std::move(target))
			{
			}

			bool process(std::wstring& value) override
			{
				bool anyMatch = false;

				size_t count = std::min(source.size(), target.size());
				for (size_t i = 0; i < count; ++i)
				{
					const std::wstring& matchString = source[i];
					const std::wstring& replacement = target[i];

					if (matchString.empty()) continue;

					size_t startPos = 0;
					while ((startPos = value.find(matchString, startPos)) != std::string::npos)
					{
						value.replace(startPos, matchString.length(), replacement);
						startPos += replacement.length();
						anyMatch = true;
					}
				}

				return anyMatch;
			}
		};

		class replace_regex_rule : public text_processor::processing_rule
		{
			std::vector<std::wregex> patterns;
			std::vector<std::wstring> replacements;

		public:
			explicit replace_regex_rule(std::vector<std::wregex> patterns, std::vector<std::wstring> replacements)
				: patterns(std::move(patterns)), replacements(std::move(replacements))
			{
			}

			bool process(std::wstring& value) override
			{
				std::wstring original = value;

				size_t count = std::min(patterns.size(), replacements.size());
				for (size_t i = 0; i < count; ++i)
				{
					const std::wregex& pattern = patterns[i];
					const std::wstring& replacement = replacements[i];

					value = std::regex_replace(value, pattern, replacement);
				}

				return value != original;
			}
		};

		class overwrite_rule : public text_processor::processing_rule
		{
			std::wstring overwrite_value;

		public:
			explicit overwrite_rule(std::wstring value)
				: overwrite_value(std::move(value))
			{
			}

			bool process(std::wstring& value) override
			{
				value.assign(overwrite_value);
				return true;
			}
		};
	}

#pragma endregion

#pragma region Initialization

	void text_processor::initialize()
	{
		for (size_t i = 0; i < api_count; ++i)
		{
			if (api_descriptors[i].api != static_cast<api>(i))
			{
				std::cout << *this << dark_red(" Error:") << " corrupt text processor api descriptor table detected. disabling text processor\n";
				_enabled = false;
				return;
			}
		}

		conversion_codepage = config().value("conversion_codepage", CP_SHIFTJIS);
		use_tunnel_decoder = config().value("use_tunnel_decoder", false);

		if (use_tunnel_decoder)
		{
			if (conversion_codepage != CP_SHIFTJIS)
			{
				std::cout << *this << dark_red(" Error:") << " tunnel decoder cannot be used with code page " << cyan(conversion_codepage) << ". disabling tunnel decoder\n";
				use_tunnel_decoder = false;
			}
			else if (!config()["tunnel_mapping"].is_string())
			{
				std::cout << *this << dark_red(" Error:") << " no tunnel decoder mapping specified. disabling tunnel decoder\n";
				use_tunnel_decoder = false;
			}
			else
			{
				tunnel_mapping = encoding::utf8_to_utf16(config()["tunnel_mapping"].get<std::string>());
			}
		}

		const auto& apiSetObject = config()["api_sets"];
		if (apiSetObject.is_object())
		{
			for (const auto& apiSet : apiSetObject.items())
			{
				api_mask mask{};
				parse_mask(apiSet.value(), mask);
				custom_api_sets.emplace_back(apiSet.key(), mask);
			}
		}

		const auto& rulesArray = config()["rules"];
		if (rulesArray.is_array())
		{
			for (auto& ruleObject : rulesArray)
			{
				if (!ruleObject.is_object()) {
					std::cout << *this << dark_red(" Error:") << " expected object\n";
					continue;
				}

				auto* rule = parse_rule(ruleObject);
				if (rule == nullptr) continue;

				rule->mask = parse_mask(ruleObject["apis"]);

				rules.push_back(rule);
			}
		}

		if (rules.empty())
		{
			std::cout << *this << dark_red(" Warning:") << " no rules specified\n";
		}

		set_enabled_apis(parse_mask(config()["enabled_apis"]));

		enable_api(api::DefWindowProcA);
		enable_api(api::DefWindowProcW);
		enable_api(api::DefDlgProcA);
		enable_api(api::DefDlgProcW);
	}

	void text_processor::finalize()
	{
		set_enabled_apis(api_mask{});
	}

	std::vector<std::wstring> text_processor::parse_strings(const nlohmann::basic_json<>& value)
	{
		std::vector<std::wstring> result{};

		if (value.is_string())
		{
			result.push_back(encoding::utf8_to_utf16(value.get<std::string>()));
		}
		else if (value.is_array())
		{
			for (const auto& string : value)
			{
				result.push_back(encoding::utf8_to_utf16(string.get<std::string>()));
			}
		}

		return result;
	}

	text_processor::processing_rule* text_processor::parse_rule(const nlohmann::basic_json<>& rule) const
	{
		const auto& type = rule.value("type", "<null>");

		if (type == "replace_chars")
		{
			const auto sourceChars = encoding::utf8_to_utf16(rule.value("source_chars", ""));
			const auto targetChars = encoding::utf8_to_utf16(rule.value("target_chars", ""));

			if (sourceChars.empty() || targetChars.empty())
			{
				std::cout << *this << dark_red(" Warning:") << " no substitutions defined for replace_chars rule\n";
				return nullptr;
			}

			return new replace_chars_rule(sourceChars, targetChars);
		}

		if (type == "replace_full_string")
		{
			const auto matchStrings = parse_strings(rule["match"]);
			const auto replacements = parse_strings(rule["replacement"]);

			if (matchStrings.empty() || replacements.empty())
			{
				std::cout << *this << dark_red(" Warning:") << " no substitutions defined for replace_full_string rule\n";
				return nullptr;
			}

			if (matchStrings.size() != replacements.size())
			{
				std::cout << *this << dark_red(" Warning:") << " different number of match and replacement strings\n";
			}

			return new replace_full_string_rule(matchStrings, replacements);
		}

		if (type == "replace_substring")
		{
			const auto matchStrings = parse_strings(rule["match"]);
			const auto replacements = parse_strings(rule["replacement"]);

			return new replace_substring_rule(matchStrings, replacements);
		}

		if (type == "replace_regex")
		{
			const auto matchStrings = parse_strings(rule["match"]);
			const auto replacements = parse_strings(rule["replacement"]);

			size_t count = std::min(matchStrings.size(), replacements.size());
			std::vector<std::wregex> patterns(count);
			for (size_t i = 0; i < count; ++i)
			{
				patterns[i] = std::wregex(matchStrings[i]);
			}

			return new replace_regex_rule(patterns, replacements);
		}

		if (type == "overwrite")
		{
			const auto overwrite_value = encoding::utf8_to_utf16(rule.value("value", "<null>"));

			return new overwrite_rule(overwrite_value);
		}

		std::cout << *this << dark_red(" Error:") << " unknown rule type: " << type << "\n";
		return nullptr;
	}

	text_processor::api_mask text_processor::parse_mask(const nlohmann::basic_json<>& value)
	{
		api_mask mask{};

		if (value.is_null())
		{
			mask.set();
		}
		else
		{
			parse_mask(value, mask);
		}

		return mask;
	}

	void text_processor::parse_mask(const nlohmann::basic_json<>& value, api_mask& mask)
	{
		if (value.is_array())
		{
			for (const auto& element : value)
			{
				parse_mask(element, mask);
			}
			return;
		}

		if (!value.is_string())
			return;

		const auto name = value.get<std::string>();
		if (name == "*")
		{
			mask.set();
		}
		else if (name.starts_with('@'))
		{
			const char* apiSetName = name.c_str() + 1;

			// check custom api sets first so they can overwrite default names
			for (auto& apiSet : custom_api_sets)
			{
				if (strcmp(apiSet.name.c_str(), apiSetName) == 0)
				{
					mask |= apiSet.mask;
					return;
				}
			}

			for (auto& apiSet : default_api_sets)
			{
				if (strcmp(apiSet.name.c_str(), apiSetName) == 0)
				{
					mask |= apiSet.mask;
					return;
				}
			}

			std::cout << *this << dark_yellow(" Warning:") << " unknown api set: " << apiSetName << "\n";
		}
		else
		{
			for (auto& descriptor : api_descriptors)
			{
				if (strcmp(descriptor.name, name.c_str()) == 0)
				{
					mask.set(static_cast<size_t>(descriptor.api));
					return;
				}
			}

			std::cout << *this << dark_yellow(" Warning:") << " unknown api: " << name << "\n";
		}
	}

#pragma endregion

#pragma region API Status

	bool text_processor::is_api_enabled(api api) const
	{
		const auto index = static_cast<size_t>(api);
		if (index >= api_count)
			return false;

		return enabled_apis.test(index);
	}

	bool text_processor::enable_api(api api)
	{
		const auto index = static_cast<size_t>(api);
		if (index >= api_count)
			return false;

		if (enabled_apis.test(index))
			return false;

		const auto& descriptor = api_descriptors[index];
		if (descriptor.hook != nullptr)
		{
			if (!hooks::hook_import(this, descriptor.name, descriptor.hook))
			{
				return false;
			}
		}
		// TODO handle window message hooks

		enabled_apis.set(index);

		return true;
	}

	bool text_processor::disable_api(api api)
	{
		const auto index = static_cast<size_t>(api);
		if (index >= api_count)
			return false;

		if (!enabled_apis.test(index))
			return false;

		const auto& descriptor = api_descriptors[index];
		if (descriptor.hook != nullptr)
		{
			hooks::unhook_import(this, descriptor.name, descriptor.hook);
		}
		// TODO handle window message hooks

		enabled_apis.set(index);

		return true;
	}

	void text_processor::set_enabled_apis(api_mask mask)
	{
		for (size_t i = 0; i < api_count; ++i)
		{
			if (mask[i] != enabled_apis[i])
			{
				if (mask[i])
				{
					enable_api(static_cast<api>(i));
				}
				else
				{
					disable_api(static_cast<api>(i));
				}
			}
		}
	}

#pragma endregion

#pragma region Processing

	std::wstring text_processor::convert(const std::string& value, api api) const
	{
		if (use_tunnel_decoder)
		{
			return encoding::decode_shiftjis_tunnel(value.c_str(), static_cast<int>(value.length()), tunnel_mapping);
		}
		else
		{
			return encoding::to_widechar(value, conversion_codepage);
		}
	}

	// overload to allow templating over string type
	// ReSharper disable once CppMemberFunctionMayBeStatic
	std::wstring text_processor::convert(const std::wstring& value, api api) const
	{
		return value;
	}

	std::wstring text_processor::process(const std::string& value, api api) const
	{
		return process(convert(value, api), api);
	}

	std::wstring text_processor::process(const std::wstring& value, api api) const
	{
		const auto& descriptor = api_descriptors[static_cast<size_t>(api)];

		if (!is_api_enabled(api))
		{
			if (_debug)
			{
				std::cout << *this << ' ' << yellow(descriptor.name) << ": " << red("api disabled") << '\n';
			}
			return value;
		}

		std::wstring result = value;
		int applicableRules = 0;
		int successfulRules = 0;

		for (const auto& rule : rules)
		{
			if (rule->applies_to_api(api))
			{
				applicableRules++;
				if (rule->process(result))
				{
					successfulRules++;
				}
			}
		}

		if (_debug)
		{
			if (successfulRules > 0)
			{
				std::cout << *this << ' ' << yellow(descriptor.name) << ": " << applicableRules << "/" << rules.size() << " rules applied, " << successfulRules << " successful\n";
				std::cout << *this << ' ';
				std::wcout << dark_white_bg(dark_black(value)) << L'\n';
				std::cout << *this << ' ';
				std::wcout << dark_white_bg(dark_black(result)) << L'\n';
			}
			else if (applicableRules > 0)
			{
				std::cout << *this << ' ' << yellow(descriptor.name) << ": " << applicableRules << "/" << rules.size() << " rules applied, none successful\n";
			}
			else
			{
				std::cout << *this << ' ' << yellow(descriptor.name) << ": no rules applied\n";
			}
		}

		return result;
	}

	std::optional<std::wstring> text_processor::process(const char* value, api api) const
	{
		return value ? std::optional{ process(std::string(value), api) } : std::nullopt;
	}

	std::optional<std::wstring> text_processor::process(const wchar_t* value, api api) const
	{
		return value ? std::optional{ process(std::wstring(value), api) } : std::nullopt;
	}

#pragma endregion
}
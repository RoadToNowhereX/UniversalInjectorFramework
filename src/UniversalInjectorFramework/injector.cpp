#include "pch.h"

#include "ansi.h"
#include "libraries.h"

#include "features/allocate_console.h"
#include "features/start_suspended.h"
#include "features/character_substitution.h"
#include "features/yuka_engine_fixes.h"
#include "features/tunnel_decoder.h"
#include "features/font_manager.h"
#include "features/play_timer.h"

using namespace uif::ansi;

namespace uif
{
	injector* injector::_instance;

	injector& injector::instance()
	{
		if(_instance == nullptr)
			_instance = new injector();
		return *_instance;
	}

	injector::injector() : game_module(GetModuleHandle(nullptr)), _config("config.json") {}

	config& injector::config()
	{
		return _config;
	}

	template <typename T>
	void injector::initialize_feature()
	{
		features::feature_base* feature = new T(*this);
		feature->initialize();
		features.push_back(feature);
	}

	void injector::attach()
	{
		initialize_feature<features::allocate_console>();

		char name[MAX_PATH];
		GetModuleFileNameA(game_module, name, MAX_PATH);
		std::cout << white("[injector] ======================================================\n");
		std::cout << white("[injector]") << " Injecting into module " << yellow(name) << " at address " << blue(game_module) << '\n';

		libraries::load();

		initialize_feature<features::start_suspended>();
		initialize_feature<features::character_substitution>();
		initialize_feature<features::yuka_engine_fixes>();
		initialize_feature<features::tunnel_decoder>();
		initialize_feature<features::font_manager>();
		initialize_feature<features::play_timer>();

		std::cout << white("[injector]") << green(" Initialization complete\n");
		std::cout << white("[injector] ======================================================\n");
	}

	void injector::detach()
	{
		std::cout << white("[injector] ======================================================\n");
		std::cout << white("[injector]") << " Detaching...\n";

		for(auto* feature : features)
		{
			feature->finalize();
		}
		features.clear();

		libraries::unload();

		std::cout << white("[injector]") << cyan(" Shutting down. Goodbye :)\n");
		std::cout << white("[injector] ======================================================\n");
	}

	HMODULE injector::load_real_library(const std::string& dllName)
	{
		std::string dllPath;

		if(config().contains("/real_library_location"_json_pointer))
		{
			const auto& value = config()["/real_library_location"_json_pointer];
			if(value.is_string())
			{
				value.get_to(dllPath);
			}
		}

		if(dllPath.empty())
		{
			char sysDir[MAX_PATH];
			GetSystemDirectoryA(sysDir, MAX_PATH);
			dllPath = std::string(sysDir) + '\\' + dllName;
		}

		std::cout << white("[injector]") << " Loading original library from " << dllPath << "\n";

		const auto result = LoadLibraryA(dllPath.c_str());

		if(result == nullptr)
		{
			std::cout << white("[injector]") << red(" Error:") << " Failed to load original library\n";
			const std::string error = "Unable to locate original library.\nPlease check the configuration file.\n\nPath: " + dllPath;
			MessageBoxA(nullptr, error.c_str(), "Universal Injector", MB_ICONERROR);
			ExitProcess(1);
		}

		return result;
	}
}

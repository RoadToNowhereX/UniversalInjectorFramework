#include "pch.h"

#ifdef UIF_LIB_IPHLPAPI

#include "injector.h"

struct {
	HMODULE dll;
	FARPROC AddIPAddress;
	FARPROC AllocateAndGetInterfaceInfoFromStack;
	FARPROC AllocateAndGetIpAddrTableFromStack;
	FARPROC CancelIPChangeNotify;
	FARPROC CancelIfTimestampConfigChange;
	FARPROC CancelMibChangeNotify2;
	FARPROC CaptureInterfaceHardwareCrossTimestamp;
	FARPROC CloseCompartment;
	FARPROC CloseGetIPPhysicalInterfaceForDestination;
	FARPROC ConvertCompartmentGuidToId;
	FARPROC ConvertCompartmentIdToGuid;
	FARPROC ConvertGuidToStringA;
	FARPROC ConvertGuidToStringW;
	FARPROC ConvertInterfaceAliasToLuid;
	FARPROC ConvertInterfaceGuidToLuid;
	FARPROC ConvertInterfaceIndexToLuid;
	FARPROC ConvertInterfaceLuidToAlias;
	FARPROC ConvertInterfaceLuidToGuid;
	FARPROC ConvertInterfaceLuidToIndex;
	FARPROC ConvertInterfaceLuidToNameA;
	FARPROC ConvertInterfaceLuidToNameW;
	FARPROC ConvertInterfaceNameToLuidA;
	FARPROC ConvertInterfaceNameToLuidW;
	FARPROC ConvertInterfacePhysicalAddressToLuid;
	FARPROC ConvertIpv4MaskToLength;
	FARPROC ConvertLengthToIpv4Mask;
	FARPROC ConvertRemoteInterfaceAliasToLuid;
	FARPROC ConvertRemoteInterfaceGuidToLuid;
	FARPROC ConvertRemoteInterfaceIndexToLuid;
	FARPROC ConvertRemoteInterfaceLuidToAlias;
	FARPROC ConvertRemoteInterfaceLuidToGuid;
	FARPROC ConvertRemoteInterfaceLuidToIndex;
	FARPROC ConvertStringToGuidA;
	FARPROC ConvertStringToGuidW;
	FARPROC ConvertStringToInterfacePhysicalAddress;
	FARPROC CreateAnycastIpAddressEntry;
	FARPROC CreateCompartment;
	FARPROC CreateFlVirtualInterface;
	FARPROC CreateIpForwardEntry;
	FARPROC CreateIpForwardEntry2;
	FARPROC CreateIpNetEntry;
	FARPROC CreateIpNetEntry2;
	FARPROC CreatePersistentTcpPortReservation;
	FARPROC CreatePersistentUdpPortReservation;
	FARPROC CreateProxyArpEntry;
	FARPROC CreateSortedAddressPairs;
	FARPROC CreateUnicastIpAddressEntry;
	FARPROC DeleteAnycastIpAddressEntry;
	FARPROC DeleteCompartment;
	FARPROC DeleteFlVirtualInterface;
	FARPROC DeleteIPAddress;
	FARPROC DeleteIpForwardEntry;
	FARPROC DeleteIpForwardEntry2;
	FARPROC DeleteIpNetEntry;
	FARPROC DeleteIpNetEntry2;
	FARPROC DeletePersistentTcpPortReservation;
	FARPROC DeletePersistentUdpPortReservation;
	FARPROC DeleteProxyArpEntry;
	FARPROC DeleteUnicastIpAddressEntry;
	FARPROC DisableMediaSense;
	FARPROC EnableRouter;
	FARPROC FlushIpNetTable;
	FARPROC FlushIpNetTable2;
	FARPROC FlushIpPathTable;
	FARPROC FreeDnsSettings;
	FARPROC FreeInterfaceDnsSettings;
	FARPROC FreeMibTable;
	FARPROC GetAdapterIndex;
	FARPROC GetAdapterOrderMap;
	FARPROC GetAdaptersAddresses;
	FARPROC GetAdaptersInfo;
	FARPROC GetAnycastIpAddressEntry;
	FARPROC GetAnycastIpAddressTable;
	FARPROC GetBestInterface;
	FARPROC GetBestInterfaceEx;
	FARPROC GetBestRoute;
	FARPROC GetBestRoute2;
	FARPROC GetCurrentThreadCompartmentId;
	FARPROC GetCurrentThreadCompartmentScope;
	FARPROC GetDefaultCompartmentId;
	FARPROC GetDnsSettings;
	FARPROC GetExtendedTcpTable;
	FARPROC GetExtendedUdpTable;
	FARPROC GetFlVirtualInterface;
	FARPROC GetFlVirtualInterfaceTable;
	FARPROC GetFriendlyIfIndex;
	FARPROC GetIcmpStatistics;
	FARPROC GetIcmpStatisticsEx;
	FARPROC GetIfEntry;
	FARPROC GetIfEntry2;
	FARPROC GetIfEntry2Ex;
	FARPROC GetIfStackTable;
	FARPROC GetIfTable;
	FARPROC GetIfTable2;
	FARPROC GetIfTable2Ex;
	FARPROC GetInterfaceActiveTimestampCapabilities;
	FARPROC GetInterfaceCompartmentId;
	FARPROC GetInterfaceCurrentTimestampCapabilities;
	FARPROC GetInterfaceDnsSettings;
	FARPROC GetInterfaceHardwareTimestampCapabilities;
	FARPROC GetInterfaceInfo;
	FARPROC GetInterfaceSupportedTimestampCapabilities;
	FARPROC GetInvertedIfStackTable;
	FARPROC GetIpAddrTable;
	FARPROC GetIpErrorString;
	FARPROC GetIpForwardEntry2;
	FARPROC GetIpForwardTable;
	FARPROC GetIpForwardTable2;
	FARPROC GetIpInterfaceEntry;
	FARPROC GetIpInterfaceTable;
	FARPROC GetIpNetEntry2;
	FARPROC GetIpNetTable;
	FARPROC GetIpNetTable2;
	FARPROC GetIpNetworkConnectionBandwidthEstimates;
	FARPROC GetIpPathEntry;
	FARPROC GetIpPathTable;
	FARPROC GetIpStatistics;
	FARPROC GetIpStatisticsEx;
	FARPROC GetJobCompartmentId;
	FARPROC GetMulticastIpAddressEntry;
	FARPROC GetMulticastIpAddressTable;
	FARPROC GetNetworkConnectivityHint;
	FARPROC GetNetworkConnectivityHintForInterface;
	FARPROC GetNetworkInformation;
	FARPROC GetNetworkParams;
	FARPROC GetNumberOfInterfaces;
	FARPROC GetOwnerModuleFromPidAndInfo;
	FARPROC GetOwnerModuleFromTcp6Entry;
	FARPROC GetOwnerModuleFromTcpEntry;
	FARPROC GetOwnerModuleFromUdp6Entry;
	FARPROC GetOwnerModuleFromUdpEntry;
	FARPROC GetPerAdapterInfo;
	FARPROC GetPerTcp6ConnectionEStats;
	FARPROC GetPerTcp6ConnectionStats;
	FARPROC GetPerTcpConnectionEStats;
	FARPROC GetPerTcpConnectionStats;
	FARPROC GetRTTAndHopCount;
	FARPROC GetSessionCompartmentId;
	FARPROC GetTcp6Table;
	FARPROC GetTcp6Table2;
	FARPROC GetTcpStatistics;
	FARPROC GetTcpStatisticsEx;
	FARPROC GetTcpStatisticsEx2;
	FARPROC GetTcpTable;
	FARPROC GetTcpTable2;
	FARPROC GetTeredoPort;
	FARPROC GetUdp6Table;
	FARPROC GetUdpStatistics;
	FARPROC GetUdpStatisticsEx;
	FARPROC GetUdpStatisticsEx2;
	FARPROC GetUdpTable;
	FARPROC GetUniDirectionalAdapterInfo;
	FARPROC GetUnicastIpAddressEntry;
	FARPROC GetUnicastIpAddressTable;
	FARPROC GetWPAOACSupportLevel;
	FARPROC Icmp6CreateFile;
	FARPROC Icmp6ParseReplies;
	FARPROC Icmp6SendEcho2;
	FARPROC IcmpCloseHandle;
	FARPROC IcmpCreateFile;
	FARPROC IcmpParseReplies;
	FARPROC IcmpSendEcho;
	FARPROC IcmpSendEcho2;
	FARPROC IcmpSendEcho2Ex;
	FARPROC InitializeCompartmentEntry;
	FARPROC InitializeFlVirtualInterfaceEntry;
	FARPROC InitializeIpForwardEntry;
	FARPROC InitializeIpInterfaceEntry;
	FARPROC InitializeUnicastIpAddressEntry;
	FARPROC InternalCleanupPersistentStore;
	FARPROC InternalCreateAnycastIpAddressEntry;
	FARPROC InternalCreateIpForwardEntry;
	FARPROC InternalCreateIpForwardEntry2;
	FARPROC InternalCreateIpNetEntry;
	FARPROC InternalCreateIpNetEntry2;
	FARPROC InternalCreateOrRefIpForwardEntry2;
	FARPROC InternalCreateUnicastIpAddressEntry;
	FARPROC InternalDeleteAnycastIpAddressEntry;
	FARPROC InternalDeleteIpForwardEntry;
	FARPROC InternalDeleteIpForwardEntry2;
	FARPROC InternalDeleteIpNetEntry;
	FARPROC InternalDeleteIpNetEntry2;
	FARPROC InternalDeleteUnicastIpAddressEntry;
	FARPROC InternalFindInterfaceByAddress;
	FARPROC InternalGetAnycastIpAddressEntry;
	FARPROC InternalGetAnycastIpAddressTable;
	FARPROC InternalGetBoundTcp6EndpointTable;
	FARPROC InternalGetBoundTcpEndpointTable;
	FARPROC InternalGetForwardIpTable2;
	FARPROC InternalGetIPPhysicalInterfaceForDestination;
	FARPROC InternalGetIfEntry2;
	FARPROC InternalGetIfTable;
	FARPROC InternalGetIfTable2;
	FARPROC InternalGetIpAddrTable;
	FARPROC InternalGetIpForwardEntry2;
	FARPROC InternalGetIpForwardTable;
	FARPROC InternalGetIpInterfaceEntry;
	FARPROC InternalGetIpInterfaceTable;
	FARPROC InternalGetIpNetEntry2;
	FARPROC InternalGetIpNetTable;
	FARPROC InternalGetIpNetTable2;
	FARPROC InternalGetMulticastIpAddressEntry;
	FARPROC InternalGetMulticastIpAddressTable;
	FARPROC InternalGetRtcSlotInformation;
	FARPROC InternalGetTcp6Table2;
	FARPROC InternalGetTcp6TableWithOwnerModule;
	FARPROC InternalGetTcp6TableWithOwnerPid;
	FARPROC InternalGetTcpDynamicPortRange;
	FARPROC InternalGetTcpTable;
	FARPROC InternalGetTcpTable2;
	FARPROC InternalGetTcpTableEx;
	FARPROC InternalGetTcpTableWithOwnerModule;
	FARPROC InternalGetTcpTableWithOwnerPid;
	FARPROC InternalGetTunnelPhysicalAdapter;
	FARPROC InternalGetUdp6Table2;
	FARPROC InternalGetUdp6TableWithOwnerModule;
	FARPROC InternalGetUdp6TableWithOwnerPid;
	FARPROC InternalGetUdpDynamicPortRange;
	FARPROC InternalGetUdpTable;
	FARPROC InternalGetUdpTable2;
	FARPROC InternalGetUdpTableEx;
	FARPROC InternalGetUdpTableWithOwnerModule;
	FARPROC InternalGetUdpTableWithOwnerPid;
	FARPROC InternalGetUnicastIpAddressEntry;
	FARPROC InternalGetUnicastIpAddressTable;
	FARPROC InternalIcmpCreateFileEx;
	FARPROC InternalSetIfEntry;
	FARPROC InternalSetIpForwardEntry;
	FARPROC InternalSetIpForwardEntry2;
	FARPROC InternalSetIpInterfaceEntry;
	FARPROC InternalSetIpNetEntry;
	FARPROC InternalSetIpNetEntry2;
	FARPROC InternalSetIpStats;
	FARPROC InternalSetTcpDynamicPortRange;
	FARPROC InternalSetTcpEntry;
	FARPROC InternalSetTeredoPort;
	FARPROC InternalSetUdpDynamicPortRange;
	FARPROC InternalSetUnicastIpAddressEntry;
	FARPROC IpReleaseAddress;
	FARPROC IpRenewAddress;
	FARPROC LookupPersistentTcpPortReservation;
	FARPROC LookupPersistentUdpPortReservation;
	FARPROC NTPTimeToNTFileTime;
	FARPROC NTTimeToNTPTime;
	FARPROC NhGetGuidFromInterfaceName;
	FARPROC NhGetInterfaceDescriptionFromGuid;
	FARPROC NhGetInterfaceNameFromDeviceGuid;
	FARPROC NhGetInterfaceNameFromGuid;
	FARPROC NhpAllocateAndGetInterfaceInfoFromStack;
	FARPROC NotifyAddrChange;
	FARPROC NotifyCompartmentChange;
	FARPROC NotifyIfTimestampConfigChange;
	FARPROC NotifyIpInterfaceChange;
	FARPROC NotifyNetworkConnectivityHintChange;
	FARPROC NotifyRouteChange;
	FARPROC NotifyRouteChange2;
	FARPROC NotifyStableUnicastIpAddressTable;
	FARPROC NotifyTeredoPortChange;
	FARPROC NotifyUnicastIpAddressChange;
	FARPROC OpenCompartment;
	FARPROC ParseNetworkString;
	FARPROC PfAddFiltersToInterface;
	FARPROC PfAddGlobalFilterToInterface;
	FARPROC PfBindInterfaceToIPAddress;
	FARPROC PfBindInterfaceToIndex;
	FARPROC PfCreateInterface;
	FARPROC PfDeleteInterface;
	FARPROC PfDeleteLog;
	FARPROC PfGetInterfaceStatistics;
	FARPROC PfMakeLog;
	FARPROC PfRebindFilters;
	FARPROC PfRemoveFilterHandles;
	FARPROC PfRemoveFiltersFromInterface;
	FARPROC PfRemoveGlobalFilterFromInterface;
	FARPROC PfSetLogBuffer;
	FARPROC PfTestPacket;
	FARPROC PfUnBindInterface;
	FARPROC RegisterInterfaceTimestampConfigChange;
	FARPROC ResolveIpNetEntry2;
	FARPROC ResolveNeighbor;
	FARPROC RestoreMediaSense;
	FARPROC SendARP;
	FARPROC SetAdapterIpAddress;
	FARPROC SetCurrentThreadCompartmentId;
	FARPROC SetCurrentThreadCompartmentScope;
	FARPROC SetDnsSettings;
	FARPROC SetFlVirtualInterface;
	FARPROC SetIfEntry;
	FARPROC SetInterfaceDnsSettings;
	FARPROC SetIpForwardEntry;
	FARPROC SetIpForwardEntry2;
	FARPROC SetIpInterfaceEntry;
	FARPROC SetIpNetEntry;
	FARPROC SetIpNetEntry2;
	FARPROC SetIpStatistics;
	FARPROC SetIpStatisticsEx;
	FARPROC SetIpTTL;
	FARPROC SetJobCompartmentId;
	FARPROC SetNetworkInformation;
	FARPROC SetPerTcp6ConnectionEStats;
	FARPROC SetPerTcp6ConnectionStats;
	FARPROC SetPerTcpConnectionEStats;
	FARPROC SetPerTcpConnectionStats;
	FARPROC SetSessionCompartmentId;
	FARPROC SetTcpEntry;
	FARPROC SetUnicastIpAddressEntry;
	FARPROC UnenableRouter;
	FARPROC UnregisterInterfaceTimestampConfigChange;
	FARPROC do_echo_rep;
	FARPROC do_echo_req;
	FARPROC if_indextoname;
	FARPROC if_nametoindex;
	FARPROC register_icmp;
} iphlpapi;

void lib_iphlpapi_AddIPAddress() { iphlpapi.AddIPAddress(); }
void lib_iphlpapi_AllocateAndGetInterfaceInfoFromStack() { iphlpapi.AllocateAndGetInterfaceInfoFromStack(); }
void lib_iphlpapi_AllocateAndGetIpAddrTableFromStack() { iphlpapi.AllocateAndGetIpAddrTableFromStack(); }
void lib_iphlpapi_CancelIPChangeNotify() { iphlpapi.CancelIPChangeNotify(); }
void lib_iphlpapi_CancelIfTimestampConfigChange() { iphlpapi.CancelIfTimestampConfigChange(); }
void lib_iphlpapi_CancelMibChangeNotify2() { iphlpapi.CancelMibChangeNotify2(); }
void lib_iphlpapi_CaptureInterfaceHardwareCrossTimestamp() { iphlpapi.CaptureInterfaceHardwareCrossTimestamp(); }
void lib_iphlpapi_CloseCompartment() { iphlpapi.CloseCompartment(); }
void lib_iphlpapi_CloseGetIPPhysicalInterfaceForDestination() { iphlpapi.CloseGetIPPhysicalInterfaceForDestination(); }
void lib_iphlpapi_ConvertCompartmentGuidToId() { iphlpapi.ConvertCompartmentGuidToId(); }
void lib_iphlpapi_ConvertCompartmentIdToGuid() { iphlpapi.ConvertCompartmentIdToGuid(); }
void lib_iphlpapi_ConvertGuidToStringA() { iphlpapi.ConvertGuidToStringA(); }
void lib_iphlpapi_ConvertGuidToStringW() { iphlpapi.ConvertGuidToStringW(); }
void lib_iphlpapi_ConvertInterfaceAliasToLuid() { iphlpapi.ConvertInterfaceAliasToLuid(); }
void lib_iphlpapi_ConvertInterfaceGuidToLuid() { iphlpapi.ConvertInterfaceGuidToLuid(); }
void lib_iphlpapi_ConvertInterfaceIndexToLuid() { iphlpapi.ConvertInterfaceIndexToLuid(); }
void lib_iphlpapi_ConvertInterfaceLuidToAlias() { iphlpapi.ConvertInterfaceLuidToAlias(); }
void lib_iphlpapi_ConvertInterfaceLuidToGuid() { iphlpapi.ConvertInterfaceLuidToGuid(); }
void lib_iphlpapi_ConvertInterfaceLuidToIndex() { iphlpapi.ConvertInterfaceLuidToIndex(); }
void lib_iphlpapi_ConvertInterfaceLuidToNameA() { iphlpapi.ConvertInterfaceLuidToNameA(); }
void lib_iphlpapi_ConvertInterfaceLuidToNameW() { iphlpapi.ConvertInterfaceLuidToNameW(); }
void lib_iphlpapi_ConvertInterfaceNameToLuidA() { iphlpapi.ConvertInterfaceNameToLuidA(); }
void lib_iphlpapi_ConvertInterfaceNameToLuidW() { iphlpapi.ConvertInterfaceNameToLuidW(); }
void lib_iphlpapi_ConvertInterfacePhysicalAddressToLuid() { iphlpapi.ConvertInterfacePhysicalAddressToLuid(); }
void lib_iphlpapi_ConvertIpv4MaskToLength() { iphlpapi.ConvertIpv4MaskToLength(); }
void lib_iphlpapi_ConvertLengthToIpv4Mask() { iphlpapi.ConvertLengthToIpv4Mask(); }
void lib_iphlpapi_ConvertRemoteInterfaceAliasToLuid() { iphlpapi.ConvertRemoteInterfaceAliasToLuid(); }
void lib_iphlpapi_ConvertRemoteInterfaceGuidToLuid() { iphlpapi.ConvertRemoteInterfaceGuidToLuid(); }
void lib_iphlpapi_ConvertRemoteInterfaceIndexToLuid() { iphlpapi.ConvertRemoteInterfaceIndexToLuid(); }
void lib_iphlpapi_ConvertRemoteInterfaceLuidToAlias() { iphlpapi.ConvertRemoteInterfaceLuidToAlias(); }
void lib_iphlpapi_ConvertRemoteInterfaceLuidToGuid() { iphlpapi.ConvertRemoteInterfaceLuidToGuid(); }
void lib_iphlpapi_ConvertRemoteInterfaceLuidToIndex() { iphlpapi.ConvertRemoteInterfaceLuidToIndex(); }
void lib_iphlpapi_ConvertStringToGuidA() { iphlpapi.ConvertStringToGuidA(); }
void lib_iphlpapi_ConvertStringToGuidW() { iphlpapi.ConvertStringToGuidW(); }
void lib_iphlpapi_ConvertStringToInterfacePhysicalAddress() { iphlpapi.ConvertStringToInterfacePhysicalAddress(); }
void lib_iphlpapi_CreateAnycastIpAddressEntry() { iphlpapi.CreateAnycastIpAddressEntry(); }
void lib_iphlpapi_CreateCompartment() { iphlpapi.CreateCompartment(); }
void lib_iphlpapi_CreateFlVirtualInterface() { iphlpapi.CreateFlVirtualInterface(); }
void lib_iphlpapi_CreateIpForwardEntry() { iphlpapi.CreateIpForwardEntry(); }
void lib_iphlpapi_CreateIpForwardEntry2() { iphlpapi.CreateIpForwardEntry2(); }
void lib_iphlpapi_CreateIpNetEntry() { iphlpapi.CreateIpNetEntry(); }
void lib_iphlpapi_CreateIpNetEntry2() { iphlpapi.CreateIpNetEntry2(); }
void lib_iphlpapi_CreatePersistentTcpPortReservation() { iphlpapi.CreatePersistentTcpPortReservation(); }
void lib_iphlpapi_CreatePersistentUdpPortReservation() { iphlpapi.CreatePersistentUdpPortReservation(); }
void lib_iphlpapi_CreateProxyArpEntry() { iphlpapi.CreateProxyArpEntry(); }
void lib_iphlpapi_CreateSortedAddressPairs() { iphlpapi.CreateSortedAddressPairs(); }
void lib_iphlpapi_CreateUnicastIpAddressEntry() { iphlpapi.CreateUnicastIpAddressEntry(); }
void lib_iphlpapi_DeleteAnycastIpAddressEntry() { iphlpapi.DeleteAnycastIpAddressEntry(); }
void lib_iphlpapi_DeleteCompartment() { iphlpapi.DeleteCompartment(); }
void lib_iphlpapi_DeleteFlVirtualInterface() { iphlpapi.DeleteFlVirtualInterface(); }
void lib_iphlpapi_DeleteIPAddress() { iphlpapi.DeleteIPAddress(); }
void lib_iphlpapi_DeleteIpForwardEntry() { iphlpapi.DeleteIpForwardEntry(); }
void lib_iphlpapi_DeleteIpForwardEntry2() { iphlpapi.DeleteIpForwardEntry2(); }
void lib_iphlpapi_DeleteIpNetEntry() { iphlpapi.DeleteIpNetEntry(); }
void lib_iphlpapi_DeleteIpNetEntry2() { iphlpapi.DeleteIpNetEntry2(); }
void lib_iphlpapi_DeletePersistentTcpPortReservation() { iphlpapi.DeletePersistentTcpPortReservation(); }
void lib_iphlpapi_DeletePersistentUdpPortReservation() { iphlpapi.DeletePersistentUdpPortReservation(); }
void lib_iphlpapi_DeleteProxyArpEntry() { iphlpapi.DeleteProxyArpEntry(); }
void lib_iphlpapi_DeleteUnicastIpAddressEntry() { iphlpapi.DeleteUnicastIpAddressEntry(); }
void lib_iphlpapi_DisableMediaSense() { iphlpapi.DisableMediaSense(); }
void lib_iphlpapi_EnableRouter() { iphlpapi.EnableRouter(); }
void lib_iphlpapi_FlushIpNetTable() { iphlpapi.FlushIpNetTable(); }
void lib_iphlpapi_FlushIpNetTable2() { iphlpapi.FlushIpNetTable2(); }
void lib_iphlpapi_FlushIpPathTable() { iphlpapi.FlushIpPathTable(); }
void lib_iphlpapi_FreeDnsSettings() { iphlpapi.FreeDnsSettings(); }
void lib_iphlpapi_FreeInterfaceDnsSettings() { iphlpapi.FreeInterfaceDnsSettings(); }
void lib_iphlpapi_FreeMibTable() { iphlpapi.FreeMibTable(); }
void lib_iphlpapi_GetAdapterIndex() { iphlpapi.GetAdapterIndex(); }
void lib_iphlpapi_GetAdapterOrderMap() { iphlpapi.GetAdapterOrderMap(); }
void lib_iphlpapi_GetAdaptersAddresses() { iphlpapi.GetAdaptersAddresses(); }
void lib_iphlpapi_GetAdaptersInfo() { iphlpapi.GetAdaptersInfo(); }
void lib_iphlpapi_GetAnycastIpAddressEntry() { iphlpapi.GetAnycastIpAddressEntry(); }
void lib_iphlpapi_GetAnycastIpAddressTable() { iphlpapi.GetAnycastIpAddressTable(); }
void lib_iphlpapi_GetBestInterface() { iphlpapi.GetBestInterface(); }
void lib_iphlpapi_GetBestInterfaceEx() { iphlpapi.GetBestInterfaceEx(); }
void lib_iphlpapi_GetBestRoute() { iphlpapi.GetBestRoute(); }
void lib_iphlpapi_GetBestRoute2() { iphlpapi.GetBestRoute2(); }
void lib_iphlpapi_GetCurrentThreadCompartmentId() { iphlpapi.GetCurrentThreadCompartmentId(); }
void lib_iphlpapi_GetCurrentThreadCompartmentScope() { iphlpapi.GetCurrentThreadCompartmentScope(); }
void lib_iphlpapi_GetDefaultCompartmentId() { iphlpapi.GetDefaultCompartmentId(); }
void lib_iphlpapi_GetDnsSettings() { iphlpapi.GetDnsSettings(); }
void lib_iphlpapi_GetExtendedTcpTable() { iphlpapi.GetExtendedTcpTable(); }
void lib_iphlpapi_GetExtendedUdpTable() { iphlpapi.GetExtendedUdpTable(); }
void lib_iphlpapi_GetFlVirtualInterface() { iphlpapi.GetFlVirtualInterface(); }
void lib_iphlpapi_GetFlVirtualInterfaceTable() { iphlpapi.GetFlVirtualInterfaceTable(); }
void lib_iphlpapi_GetFriendlyIfIndex() { iphlpapi.GetFriendlyIfIndex(); }
void lib_iphlpapi_GetIcmpStatistics() { iphlpapi.GetIcmpStatistics(); }
void lib_iphlpapi_GetIcmpStatisticsEx() { iphlpapi.GetIcmpStatisticsEx(); }
void lib_iphlpapi_GetIfEntry() { iphlpapi.GetIfEntry(); }
void lib_iphlpapi_GetIfEntry2() { iphlpapi.GetIfEntry2(); }
void lib_iphlpapi_GetIfEntry2Ex() { iphlpapi.GetIfEntry2Ex(); }
void lib_iphlpapi_GetIfStackTable() { iphlpapi.GetIfStackTable(); }
void lib_iphlpapi_GetIfTable() { iphlpapi.GetIfTable(); }
void lib_iphlpapi_GetIfTable2() { iphlpapi.GetIfTable2(); }
void lib_iphlpapi_GetIfTable2Ex() { iphlpapi.GetIfTable2Ex(); }
void lib_iphlpapi_GetInterfaceActiveTimestampCapabilities() { iphlpapi.GetInterfaceActiveTimestampCapabilities(); }
void lib_iphlpapi_GetInterfaceCompartmentId() { iphlpapi.GetInterfaceCompartmentId(); }
void lib_iphlpapi_GetInterfaceCurrentTimestampCapabilities() { iphlpapi.GetInterfaceCurrentTimestampCapabilities(); }
void lib_iphlpapi_GetInterfaceDnsSettings() { iphlpapi.GetInterfaceDnsSettings(); }
void lib_iphlpapi_GetInterfaceHardwareTimestampCapabilities() { iphlpapi.GetInterfaceHardwareTimestampCapabilities(); }
void lib_iphlpapi_GetInterfaceInfo() { iphlpapi.GetInterfaceInfo(); }
void lib_iphlpapi_GetInterfaceSupportedTimestampCapabilities() { iphlpapi.GetInterfaceSupportedTimestampCapabilities(); }
void lib_iphlpapi_GetInvertedIfStackTable() { iphlpapi.GetInvertedIfStackTable(); }
void lib_iphlpapi_GetIpAddrTable() { iphlpapi.GetIpAddrTable(); }
void lib_iphlpapi_GetIpErrorString() { iphlpapi.GetIpErrorString(); }
void lib_iphlpapi_GetIpForwardEntry2() { iphlpapi.GetIpForwardEntry2(); }
void lib_iphlpapi_GetIpForwardTable() { iphlpapi.GetIpForwardTable(); }
void lib_iphlpapi_GetIpForwardTable2() { iphlpapi.GetIpForwardTable2(); }
void lib_iphlpapi_GetIpInterfaceEntry() { iphlpapi.GetIpInterfaceEntry(); }
void lib_iphlpapi_GetIpInterfaceTable() { iphlpapi.GetIpInterfaceTable(); }
void lib_iphlpapi_GetIpNetEntry2() { iphlpapi.GetIpNetEntry2(); }
void lib_iphlpapi_GetIpNetTable() { iphlpapi.GetIpNetTable(); }
void lib_iphlpapi_GetIpNetTable2() { iphlpapi.GetIpNetTable2(); }
void lib_iphlpapi_GetIpNetworkConnectionBandwidthEstimates() { iphlpapi.GetIpNetworkConnectionBandwidthEstimates(); }
void lib_iphlpapi_GetIpPathEntry() { iphlpapi.GetIpPathEntry(); }
void lib_iphlpapi_GetIpPathTable() { iphlpapi.GetIpPathTable(); }
void lib_iphlpapi_GetIpStatistics() { iphlpapi.GetIpStatistics(); }
void lib_iphlpapi_GetIpStatisticsEx() { iphlpapi.GetIpStatisticsEx(); }
void lib_iphlpapi_GetJobCompartmentId() { iphlpapi.GetJobCompartmentId(); }
void lib_iphlpapi_GetMulticastIpAddressEntry() { iphlpapi.GetMulticastIpAddressEntry(); }
void lib_iphlpapi_GetMulticastIpAddressTable() { iphlpapi.GetMulticastIpAddressTable(); }
void lib_iphlpapi_GetNetworkConnectivityHint() { iphlpapi.GetNetworkConnectivityHint(); }
void lib_iphlpapi_GetNetworkConnectivityHintForInterface() { iphlpapi.GetNetworkConnectivityHintForInterface(); }
void lib_iphlpapi_GetNetworkInformation() { iphlpapi.GetNetworkInformation(); }
void lib_iphlpapi_GetNetworkParams() { iphlpapi.GetNetworkParams(); }
void lib_iphlpapi_GetNumberOfInterfaces() { iphlpapi.GetNumberOfInterfaces(); }
void lib_iphlpapi_GetOwnerModuleFromPidAndInfo() { iphlpapi.GetOwnerModuleFromPidAndInfo(); }
void lib_iphlpapi_GetOwnerModuleFromTcp6Entry() { iphlpapi.GetOwnerModuleFromTcp6Entry(); }
void lib_iphlpapi_GetOwnerModuleFromTcpEntry() { iphlpapi.GetOwnerModuleFromTcpEntry(); }
void lib_iphlpapi_GetOwnerModuleFromUdp6Entry() { iphlpapi.GetOwnerModuleFromUdp6Entry(); }
void lib_iphlpapi_GetOwnerModuleFromUdpEntry() { iphlpapi.GetOwnerModuleFromUdpEntry(); }
void lib_iphlpapi_GetPerAdapterInfo() { iphlpapi.GetPerAdapterInfo(); }
void lib_iphlpapi_GetPerTcp6ConnectionEStats() { iphlpapi.GetPerTcp6ConnectionEStats(); }
void lib_iphlpapi_GetPerTcp6ConnectionStats() { iphlpapi.GetPerTcp6ConnectionStats(); }
void lib_iphlpapi_GetPerTcpConnectionEStats() { iphlpapi.GetPerTcpConnectionEStats(); }
void lib_iphlpapi_GetPerTcpConnectionStats() { iphlpapi.GetPerTcpConnectionStats(); }
void lib_iphlpapi_GetRTTAndHopCount() { iphlpapi.GetRTTAndHopCount(); }
void lib_iphlpapi_GetSessionCompartmentId() { iphlpapi.GetSessionCompartmentId(); }
void lib_iphlpapi_GetTcp6Table() { iphlpapi.GetTcp6Table(); }
void lib_iphlpapi_GetTcp6Table2() { iphlpapi.GetTcp6Table2(); }
void lib_iphlpapi_GetTcpStatistics() { iphlpapi.GetTcpStatistics(); }
void lib_iphlpapi_GetTcpStatisticsEx() { iphlpapi.GetTcpStatisticsEx(); }
void lib_iphlpapi_GetTcpStatisticsEx2() { iphlpapi.GetTcpStatisticsEx2(); }
void lib_iphlpapi_GetTcpTable() { iphlpapi.GetTcpTable(); }
void lib_iphlpapi_GetTcpTable2() { iphlpapi.GetTcpTable2(); }
void lib_iphlpapi_GetTeredoPort() { iphlpapi.GetTeredoPort(); }
void lib_iphlpapi_GetUdp6Table() { iphlpapi.GetUdp6Table(); }
void lib_iphlpapi_GetUdpStatistics() { iphlpapi.GetUdpStatistics(); }
void lib_iphlpapi_GetUdpStatisticsEx() { iphlpapi.GetUdpStatisticsEx(); }
void lib_iphlpapi_GetUdpStatisticsEx2() { iphlpapi.GetUdpStatisticsEx2(); }
void lib_iphlpapi_GetUdpTable() { iphlpapi.GetUdpTable(); }
void lib_iphlpapi_GetUniDirectionalAdapterInfo() { iphlpapi.GetUniDirectionalAdapterInfo(); }
void lib_iphlpapi_GetUnicastIpAddressEntry() { iphlpapi.GetUnicastIpAddressEntry(); }
void lib_iphlpapi_GetUnicastIpAddressTable() { iphlpapi.GetUnicastIpAddressTable(); }
void lib_iphlpapi_GetWPAOACSupportLevel() { iphlpapi.GetWPAOACSupportLevel(); }
void lib_iphlpapi_Icmp6CreateFile() { iphlpapi.Icmp6CreateFile(); }
void lib_iphlpapi_Icmp6ParseReplies() { iphlpapi.Icmp6ParseReplies(); }
void lib_iphlpapi_Icmp6SendEcho2() { iphlpapi.Icmp6SendEcho2(); }
void lib_iphlpapi_IcmpCloseHandle() { iphlpapi.IcmpCloseHandle(); }
void lib_iphlpapi_IcmpCreateFile() { iphlpapi.IcmpCreateFile(); }
void lib_iphlpapi_IcmpParseReplies() { iphlpapi.IcmpParseReplies(); }
void lib_iphlpapi_IcmpSendEcho() { iphlpapi.IcmpSendEcho(); }
void lib_iphlpapi_IcmpSendEcho2() { iphlpapi.IcmpSendEcho2(); }
void lib_iphlpapi_IcmpSendEcho2Ex() { iphlpapi.IcmpSendEcho2Ex(); }
void lib_iphlpapi_InitializeCompartmentEntry() { iphlpapi.InitializeCompartmentEntry(); }
void lib_iphlpapi_InitializeFlVirtualInterfaceEntry() { iphlpapi.InitializeFlVirtualInterfaceEntry(); }
void lib_iphlpapi_InitializeIpForwardEntry() { iphlpapi.InitializeIpForwardEntry(); }
void lib_iphlpapi_InitializeIpInterfaceEntry() { iphlpapi.InitializeIpInterfaceEntry(); }
void lib_iphlpapi_InitializeUnicastIpAddressEntry() { iphlpapi.InitializeUnicastIpAddressEntry(); }
void lib_iphlpapi_InternalCleanupPersistentStore() { iphlpapi.InternalCleanupPersistentStore(); }
void lib_iphlpapi_InternalCreateAnycastIpAddressEntry() { iphlpapi.InternalCreateAnycastIpAddressEntry(); }
void lib_iphlpapi_InternalCreateIpForwardEntry() { iphlpapi.InternalCreateIpForwardEntry(); }
void lib_iphlpapi_InternalCreateIpForwardEntry2() { iphlpapi.InternalCreateIpForwardEntry2(); }
void lib_iphlpapi_InternalCreateIpNetEntry() { iphlpapi.InternalCreateIpNetEntry(); }
void lib_iphlpapi_InternalCreateIpNetEntry2() { iphlpapi.InternalCreateIpNetEntry2(); }
void lib_iphlpapi_InternalCreateOrRefIpForwardEntry2() { iphlpapi.InternalCreateOrRefIpForwardEntry2(); }
void lib_iphlpapi_InternalCreateUnicastIpAddressEntry() { iphlpapi.InternalCreateUnicastIpAddressEntry(); }
void lib_iphlpapi_InternalDeleteAnycastIpAddressEntry() { iphlpapi.InternalDeleteAnycastIpAddressEntry(); }
void lib_iphlpapi_InternalDeleteIpForwardEntry() { iphlpapi.InternalDeleteIpForwardEntry(); }
void lib_iphlpapi_InternalDeleteIpForwardEntry2() { iphlpapi.InternalDeleteIpForwardEntry2(); }
void lib_iphlpapi_InternalDeleteIpNetEntry() { iphlpapi.InternalDeleteIpNetEntry(); }
void lib_iphlpapi_InternalDeleteIpNetEntry2() { iphlpapi.InternalDeleteIpNetEntry2(); }
void lib_iphlpapi_InternalDeleteUnicastIpAddressEntry() { iphlpapi.InternalDeleteUnicastIpAddressEntry(); }
void lib_iphlpapi_InternalFindInterfaceByAddress() { iphlpapi.InternalFindInterfaceByAddress(); }
void lib_iphlpapi_InternalGetAnycastIpAddressEntry() { iphlpapi.InternalGetAnycastIpAddressEntry(); }
void lib_iphlpapi_InternalGetAnycastIpAddressTable() { iphlpapi.InternalGetAnycastIpAddressTable(); }
void lib_iphlpapi_InternalGetBoundTcp6EndpointTable() { iphlpapi.InternalGetBoundTcp6EndpointTable(); }
void lib_iphlpapi_InternalGetBoundTcpEndpointTable() { iphlpapi.InternalGetBoundTcpEndpointTable(); }
void lib_iphlpapi_InternalGetForwardIpTable2() { iphlpapi.InternalGetForwardIpTable2(); }
void lib_iphlpapi_InternalGetIPPhysicalInterfaceForDestination() { iphlpapi.InternalGetIPPhysicalInterfaceForDestination(); }
void lib_iphlpapi_InternalGetIfEntry2() { iphlpapi.InternalGetIfEntry2(); }
void lib_iphlpapi_InternalGetIfTable() { iphlpapi.InternalGetIfTable(); }
void lib_iphlpapi_InternalGetIfTable2() { iphlpapi.InternalGetIfTable2(); }
void lib_iphlpapi_InternalGetIpAddrTable() { iphlpapi.InternalGetIpAddrTable(); }
void lib_iphlpapi_InternalGetIpForwardEntry2() { iphlpapi.InternalGetIpForwardEntry2(); }
void lib_iphlpapi_InternalGetIpForwardTable() { iphlpapi.InternalGetIpForwardTable(); }
void lib_iphlpapi_InternalGetIpInterfaceEntry() { iphlpapi.InternalGetIpInterfaceEntry(); }
void lib_iphlpapi_InternalGetIpInterfaceTable() { iphlpapi.InternalGetIpInterfaceTable(); }
void lib_iphlpapi_InternalGetIpNetEntry2() { iphlpapi.InternalGetIpNetEntry2(); }
void lib_iphlpapi_InternalGetIpNetTable() { iphlpapi.InternalGetIpNetTable(); }
void lib_iphlpapi_InternalGetIpNetTable2() { iphlpapi.InternalGetIpNetTable2(); }
void lib_iphlpapi_InternalGetMulticastIpAddressEntry() { iphlpapi.InternalGetMulticastIpAddressEntry(); }
void lib_iphlpapi_InternalGetMulticastIpAddressTable() { iphlpapi.InternalGetMulticastIpAddressTable(); }
void lib_iphlpapi_InternalGetRtcSlotInformation() { iphlpapi.InternalGetRtcSlotInformation(); }
void lib_iphlpapi_InternalGetTcp6Table2() { iphlpapi.InternalGetTcp6Table2(); }
void lib_iphlpapi_InternalGetTcp6TableWithOwnerModule() { iphlpapi.InternalGetTcp6TableWithOwnerModule(); }
void lib_iphlpapi_InternalGetTcp6TableWithOwnerPid() { iphlpapi.InternalGetTcp6TableWithOwnerPid(); }
void lib_iphlpapi_InternalGetTcpDynamicPortRange() { iphlpapi.InternalGetTcpDynamicPortRange(); }
void lib_iphlpapi_InternalGetTcpTable() { iphlpapi.InternalGetTcpTable(); }
void lib_iphlpapi_InternalGetTcpTable2() { iphlpapi.InternalGetTcpTable2(); }
void lib_iphlpapi_InternalGetTcpTableEx() { iphlpapi.InternalGetTcpTableEx(); }
void lib_iphlpapi_InternalGetTcpTableWithOwnerModule() { iphlpapi.InternalGetTcpTableWithOwnerModule(); }
void lib_iphlpapi_InternalGetTcpTableWithOwnerPid() { iphlpapi.InternalGetTcpTableWithOwnerPid(); }
void lib_iphlpapi_InternalGetTunnelPhysicalAdapter() { iphlpapi.InternalGetTunnelPhysicalAdapter(); }
void lib_iphlpapi_InternalGetUdp6Table2() { iphlpapi.InternalGetUdp6Table2(); }
void lib_iphlpapi_InternalGetUdp6TableWithOwnerModule() { iphlpapi.InternalGetUdp6TableWithOwnerModule(); }
void lib_iphlpapi_InternalGetUdp6TableWithOwnerPid() { iphlpapi.InternalGetUdp6TableWithOwnerPid(); }
void lib_iphlpapi_InternalGetUdpDynamicPortRange() { iphlpapi.InternalGetUdpDynamicPortRange(); }
void lib_iphlpapi_InternalGetUdpTable() { iphlpapi.InternalGetUdpTable(); }
void lib_iphlpapi_InternalGetUdpTable2() { iphlpapi.InternalGetUdpTable2(); }
void lib_iphlpapi_InternalGetUdpTableEx() { iphlpapi.InternalGetUdpTableEx(); }
void lib_iphlpapi_InternalGetUdpTableWithOwnerModule() { iphlpapi.InternalGetUdpTableWithOwnerModule(); }
void lib_iphlpapi_InternalGetUdpTableWithOwnerPid() { iphlpapi.InternalGetUdpTableWithOwnerPid(); }
void lib_iphlpapi_InternalGetUnicastIpAddressEntry() { iphlpapi.InternalGetUnicastIpAddressEntry(); }
void lib_iphlpapi_InternalGetUnicastIpAddressTable() { iphlpapi.InternalGetUnicastIpAddressTable(); }
void lib_iphlpapi_InternalIcmpCreateFileEx() { iphlpapi.InternalIcmpCreateFileEx(); }
void lib_iphlpapi_InternalSetIfEntry() { iphlpapi.InternalSetIfEntry(); }
void lib_iphlpapi_InternalSetIpForwardEntry() { iphlpapi.InternalSetIpForwardEntry(); }
void lib_iphlpapi_InternalSetIpForwardEntry2() { iphlpapi.InternalSetIpForwardEntry2(); }
void lib_iphlpapi_InternalSetIpInterfaceEntry() { iphlpapi.InternalSetIpInterfaceEntry(); }
void lib_iphlpapi_InternalSetIpNetEntry() { iphlpapi.InternalSetIpNetEntry(); }
void lib_iphlpapi_InternalSetIpNetEntry2() { iphlpapi.InternalSetIpNetEntry2(); }
void lib_iphlpapi_InternalSetIpStats() { iphlpapi.InternalSetIpStats(); }
void lib_iphlpapi_InternalSetTcpDynamicPortRange() { iphlpapi.InternalSetTcpDynamicPortRange(); }
void lib_iphlpapi_InternalSetTcpEntry() { iphlpapi.InternalSetTcpEntry(); }
void lib_iphlpapi_InternalSetTeredoPort() { iphlpapi.InternalSetTeredoPort(); }
void lib_iphlpapi_InternalSetUdpDynamicPortRange() { iphlpapi.InternalSetUdpDynamicPortRange(); }
void lib_iphlpapi_InternalSetUnicastIpAddressEntry() { iphlpapi.InternalSetUnicastIpAddressEntry(); }
void lib_iphlpapi_IpReleaseAddress() { iphlpapi.IpReleaseAddress(); }
void lib_iphlpapi_IpRenewAddress() { iphlpapi.IpRenewAddress(); }
void lib_iphlpapi_LookupPersistentTcpPortReservation() { iphlpapi.LookupPersistentTcpPortReservation(); }
void lib_iphlpapi_LookupPersistentUdpPortReservation() { iphlpapi.LookupPersistentUdpPortReservation(); }
void lib_iphlpapi_NTPTimeToNTFileTime() { iphlpapi.NTPTimeToNTFileTime(); }
void lib_iphlpapi_NTTimeToNTPTime() { iphlpapi.NTTimeToNTPTime(); }
void lib_iphlpapi_NhGetGuidFromInterfaceName() { iphlpapi.NhGetGuidFromInterfaceName(); }
void lib_iphlpapi_NhGetInterfaceDescriptionFromGuid() { iphlpapi.NhGetInterfaceDescriptionFromGuid(); }
void lib_iphlpapi_NhGetInterfaceNameFromDeviceGuid() { iphlpapi.NhGetInterfaceNameFromDeviceGuid(); }
void lib_iphlpapi_NhGetInterfaceNameFromGuid() { iphlpapi.NhGetInterfaceNameFromGuid(); }
void lib_iphlpapi_NhpAllocateAndGetInterfaceInfoFromStack() { iphlpapi.NhpAllocateAndGetInterfaceInfoFromStack(); }
void lib_iphlpapi_NotifyAddrChange() { iphlpapi.NotifyAddrChange(); }
void lib_iphlpapi_NotifyCompartmentChange() { iphlpapi.NotifyCompartmentChange(); }
void lib_iphlpapi_NotifyIfTimestampConfigChange() { iphlpapi.NotifyIfTimestampConfigChange(); }
void lib_iphlpapi_NotifyIpInterfaceChange() { iphlpapi.NotifyIpInterfaceChange(); }
void lib_iphlpapi_NotifyNetworkConnectivityHintChange() { iphlpapi.NotifyNetworkConnectivityHintChange(); }
void lib_iphlpapi_NotifyRouteChange() { iphlpapi.NotifyRouteChange(); }
void lib_iphlpapi_NotifyRouteChange2() { iphlpapi.NotifyRouteChange2(); }
void lib_iphlpapi_NotifyStableUnicastIpAddressTable() { iphlpapi.NotifyStableUnicastIpAddressTable(); }
void lib_iphlpapi_NotifyTeredoPortChange() { iphlpapi.NotifyTeredoPortChange(); }
void lib_iphlpapi_NotifyUnicastIpAddressChange() { iphlpapi.NotifyUnicastIpAddressChange(); }
void lib_iphlpapi_OpenCompartment() { iphlpapi.OpenCompartment(); }
void lib_iphlpapi_ParseNetworkString() { iphlpapi.ParseNetworkString(); }
void lib_iphlpapi_PfAddFiltersToInterface() { iphlpapi.PfAddFiltersToInterface(); }
void lib_iphlpapi_PfAddGlobalFilterToInterface() { iphlpapi.PfAddGlobalFilterToInterface(); }
void lib_iphlpapi_PfBindInterfaceToIPAddress() { iphlpapi.PfBindInterfaceToIPAddress(); }
void lib_iphlpapi_PfBindInterfaceToIndex() { iphlpapi.PfBindInterfaceToIndex(); }
void lib_iphlpapi_PfCreateInterface() { iphlpapi.PfCreateInterface(); }
void lib_iphlpapi_PfDeleteInterface() { iphlpapi.PfDeleteInterface(); }
void lib_iphlpapi_PfDeleteLog() { iphlpapi.PfDeleteLog(); }
void lib_iphlpapi_PfGetInterfaceStatistics() { iphlpapi.PfGetInterfaceStatistics(); }
void lib_iphlpapi_PfMakeLog() { iphlpapi.PfMakeLog(); }
void lib_iphlpapi_PfRebindFilters() { iphlpapi.PfRebindFilters(); }
void lib_iphlpapi_PfRemoveFilterHandles() { iphlpapi.PfRemoveFilterHandles(); }
void lib_iphlpapi_PfRemoveFiltersFromInterface() { iphlpapi.PfRemoveFiltersFromInterface(); }
void lib_iphlpapi_PfRemoveGlobalFilterFromInterface() { iphlpapi.PfRemoveGlobalFilterFromInterface(); }
void lib_iphlpapi_PfSetLogBuffer() { iphlpapi.PfSetLogBuffer(); }
void lib_iphlpapi_PfTestPacket() { iphlpapi.PfTestPacket(); }
void lib_iphlpapi_PfUnBindInterface() { iphlpapi.PfUnBindInterface(); }
void lib_iphlpapi_RegisterInterfaceTimestampConfigChange() { iphlpapi.RegisterInterfaceTimestampConfigChange(); }
void lib_iphlpapi_ResolveIpNetEntry2() { iphlpapi.ResolveIpNetEntry2(); }
void lib_iphlpapi_ResolveNeighbor() { iphlpapi.ResolveNeighbor(); }
void lib_iphlpapi_RestoreMediaSense() { iphlpapi.RestoreMediaSense(); }
void lib_iphlpapi_SendARP() { iphlpapi.SendARP(); }
void lib_iphlpapi_SetAdapterIpAddress() { iphlpapi.SetAdapterIpAddress(); }
void lib_iphlpapi_SetCurrentThreadCompartmentId() { iphlpapi.SetCurrentThreadCompartmentId(); }
void lib_iphlpapi_SetCurrentThreadCompartmentScope() { iphlpapi.SetCurrentThreadCompartmentScope(); }
void lib_iphlpapi_SetDnsSettings() { iphlpapi.SetDnsSettings(); }
void lib_iphlpapi_SetFlVirtualInterface() { iphlpapi.SetFlVirtualInterface(); }
void lib_iphlpapi_SetIfEntry() { iphlpapi.SetIfEntry(); }
void lib_iphlpapi_SetInterfaceDnsSettings() { iphlpapi.SetInterfaceDnsSettings(); }
void lib_iphlpapi_SetIpForwardEntry() { iphlpapi.SetIpForwardEntry(); }
void lib_iphlpapi_SetIpForwardEntry2() { iphlpapi.SetIpForwardEntry2(); }
void lib_iphlpapi_SetIpInterfaceEntry() { iphlpapi.SetIpInterfaceEntry(); }
void lib_iphlpapi_SetIpNetEntry() { iphlpapi.SetIpNetEntry(); }
void lib_iphlpapi_SetIpNetEntry2() { iphlpapi.SetIpNetEntry2(); }
void lib_iphlpapi_SetIpStatistics() { iphlpapi.SetIpStatistics(); }
void lib_iphlpapi_SetIpStatisticsEx() { iphlpapi.SetIpStatisticsEx(); }
void lib_iphlpapi_SetIpTTL() { iphlpapi.SetIpTTL(); }
void lib_iphlpapi_SetJobCompartmentId() { iphlpapi.SetJobCompartmentId(); }
void lib_iphlpapi_SetNetworkInformation() { iphlpapi.SetNetworkInformation(); }
void lib_iphlpapi_SetPerTcp6ConnectionEStats() { iphlpapi.SetPerTcp6ConnectionEStats(); }
void lib_iphlpapi_SetPerTcp6ConnectionStats() { iphlpapi.SetPerTcp6ConnectionStats(); }
void lib_iphlpapi_SetPerTcpConnectionEStats() { iphlpapi.SetPerTcpConnectionEStats(); }
void lib_iphlpapi_SetPerTcpConnectionStats() { iphlpapi.SetPerTcpConnectionStats(); }
void lib_iphlpapi_SetSessionCompartmentId() { iphlpapi.SetSessionCompartmentId(); }
void lib_iphlpapi_SetTcpEntry() { iphlpapi.SetTcpEntry(); }
void lib_iphlpapi_SetUnicastIpAddressEntry() { iphlpapi.SetUnicastIpAddressEntry(); }
void lib_iphlpapi_UnenableRouter() { iphlpapi.UnenableRouter(); }
void lib_iphlpapi_UnregisterInterfaceTimestampConfigChange() { iphlpapi.UnregisterInterfaceTimestampConfigChange(); }
void lib_iphlpapi_do_echo_rep() { iphlpapi.do_echo_rep(); }
void lib_iphlpapi_do_echo_req() { iphlpapi.do_echo_req(); }
void lib_iphlpapi_if_indextoname() { iphlpapi.if_indextoname(); }
void lib_iphlpapi_if_nametoindex() { iphlpapi.if_nametoindex(); }
void lib_iphlpapi_register_icmp() { iphlpapi.register_icmp(); }

bool load_library_iphlpapi() {
	iphlpapi.dll = uif::injector::instance().load_real_library("iphlpapi.dll");
	iphlpapi.AddIPAddress = GetProcAddress(iphlpapi.dll, "AddIPAddress");
	iphlpapi.AllocateAndGetInterfaceInfoFromStack = GetProcAddress(iphlpapi.dll, "AllocateAndGetInterfaceInfoFromStack");
	iphlpapi.AllocateAndGetIpAddrTableFromStack = GetProcAddress(iphlpapi.dll, "AllocateAndGetIpAddrTableFromStack");
	iphlpapi.CancelIPChangeNotify = GetProcAddress(iphlpapi.dll, "CancelIPChangeNotify");
	iphlpapi.CancelIfTimestampConfigChange = GetProcAddress(iphlpapi.dll, "CancelIfTimestampConfigChange");
	iphlpapi.CancelMibChangeNotify2 = GetProcAddress(iphlpapi.dll, "CancelMibChangeNotify2");
	iphlpapi.CaptureInterfaceHardwareCrossTimestamp = GetProcAddress(iphlpapi.dll, "CaptureInterfaceHardwareCrossTimestamp");
	iphlpapi.CloseCompartment = GetProcAddress(iphlpapi.dll, "CloseCompartment");
	iphlpapi.CloseGetIPPhysicalInterfaceForDestination = GetProcAddress(iphlpapi.dll, "CloseGetIPPhysicalInterfaceForDestination");
	iphlpapi.ConvertCompartmentGuidToId = GetProcAddress(iphlpapi.dll, "ConvertCompartmentGuidToId");
	iphlpapi.ConvertCompartmentIdToGuid = GetProcAddress(iphlpapi.dll, "ConvertCompartmentIdToGuid");
	iphlpapi.ConvertGuidToStringA = GetProcAddress(iphlpapi.dll, "ConvertGuidToStringA");
	iphlpapi.ConvertGuidToStringW = GetProcAddress(iphlpapi.dll, "ConvertGuidToStringW");
	iphlpapi.ConvertInterfaceAliasToLuid = GetProcAddress(iphlpapi.dll, "ConvertInterfaceAliasToLuid");
	iphlpapi.ConvertInterfaceGuidToLuid = GetProcAddress(iphlpapi.dll, "ConvertInterfaceGuidToLuid");
	iphlpapi.ConvertInterfaceIndexToLuid = GetProcAddress(iphlpapi.dll, "ConvertInterfaceIndexToLuid");
	iphlpapi.ConvertInterfaceLuidToAlias = GetProcAddress(iphlpapi.dll, "ConvertInterfaceLuidToAlias");
	iphlpapi.ConvertInterfaceLuidToGuid = GetProcAddress(iphlpapi.dll, "ConvertInterfaceLuidToGuid");
	iphlpapi.ConvertInterfaceLuidToIndex = GetProcAddress(iphlpapi.dll, "ConvertInterfaceLuidToIndex");
	iphlpapi.ConvertInterfaceLuidToNameA = GetProcAddress(iphlpapi.dll, "ConvertInterfaceLuidToNameA");
	iphlpapi.ConvertInterfaceLuidToNameW = GetProcAddress(iphlpapi.dll, "ConvertInterfaceLuidToNameW");
	iphlpapi.ConvertInterfaceNameToLuidA = GetProcAddress(iphlpapi.dll, "ConvertInterfaceNameToLuidA");
	iphlpapi.ConvertInterfaceNameToLuidW = GetProcAddress(iphlpapi.dll, "ConvertInterfaceNameToLuidW");
	iphlpapi.ConvertInterfacePhysicalAddressToLuid = GetProcAddress(iphlpapi.dll, "ConvertInterfacePhysicalAddressToLuid");
	iphlpapi.ConvertIpv4MaskToLength = GetProcAddress(iphlpapi.dll, "ConvertIpv4MaskToLength");
	iphlpapi.ConvertLengthToIpv4Mask = GetProcAddress(iphlpapi.dll, "ConvertLengthToIpv4Mask");
	iphlpapi.ConvertRemoteInterfaceAliasToLuid = GetProcAddress(iphlpapi.dll, "ConvertRemoteInterfaceAliasToLuid");
	iphlpapi.ConvertRemoteInterfaceGuidToLuid = GetProcAddress(iphlpapi.dll, "ConvertRemoteInterfaceGuidToLuid");
	iphlpapi.ConvertRemoteInterfaceIndexToLuid = GetProcAddress(iphlpapi.dll, "ConvertRemoteInterfaceIndexToLuid");
	iphlpapi.ConvertRemoteInterfaceLuidToAlias = GetProcAddress(iphlpapi.dll, "ConvertRemoteInterfaceLuidToAlias");
	iphlpapi.ConvertRemoteInterfaceLuidToGuid = GetProcAddress(iphlpapi.dll, "ConvertRemoteInterfaceLuidToGuid");
	iphlpapi.ConvertRemoteInterfaceLuidToIndex = GetProcAddress(iphlpapi.dll, "ConvertRemoteInterfaceLuidToIndex");
	iphlpapi.ConvertStringToGuidA = GetProcAddress(iphlpapi.dll, "ConvertStringToGuidA");
	iphlpapi.ConvertStringToGuidW = GetProcAddress(iphlpapi.dll, "ConvertStringToGuidW");
	iphlpapi.ConvertStringToInterfacePhysicalAddress = GetProcAddress(iphlpapi.dll, "ConvertStringToInterfacePhysicalAddress");
	iphlpapi.CreateAnycastIpAddressEntry = GetProcAddress(iphlpapi.dll, "CreateAnycastIpAddressEntry");
	iphlpapi.CreateCompartment = GetProcAddress(iphlpapi.dll, "CreateCompartment");
	iphlpapi.CreateFlVirtualInterface = GetProcAddress(iphlpapi.dll, "CreateFlVirtualInterface");
	iphlpapi.CreateIpForwardEntry = GetProcAddress(iphlpapi.dll, "CreateIpForwardEntry");
	iphlpapi.CreateIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "CreateIpForwardEntry2");
	iphlpapi.CreateIpNetEntry = GetProcAddress(iphlpapi.dll, "CreateIpNetEntry");
	iphlpapi.CreateIpNetEntry2 = GetProcAddress(iphlpapi.dll, "CreateIpNetEntry2");
	iphlpapi.CreatePersistentTcpPortReservation = GetProcAddress(iphlpapi.dll, "CreatePersistentTcpPortReservation");
	iphlpapi.CreatePersistentUdpPortReservation = GetProcAddress(iphlpapi.dll, "CreatePersistentUdpPortReservation");
	iphlpapi.CreateProxyArpEntry = GetProcAddress(iphlpapi.dll, "CreateProxyArpEntry");
	iphlpapi.CreateSortedAddressPairs = GetProcAddress(iphlpapi.dll, "CreateSortedAddressPairs");
	iphlpapi.CreateUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "CreateUnicastIpAddressEntry");
	iphlpapi.DeleteAnycastIpAddressEntry = GetProcAddress(iphlpapi.dll, "DeleteAnycastIpAddressEntry");
	iphlpapi.DeleteCompartment = GetProcAddress(iphlpapi.dll, "DeleteCompartment");
	iphlpapi.DeleteFlVirtualInterface = GetProcAddress(iphlpapi.dll, "DeleteFlVirtualInterface");
	iphlpapi.DeleteIPAddress = GetProcAddress(iphlpapi.dll, "DeleteIPAddress");
	iphlpapi.DeleteIpForwardEntry = GetProcAddress(iphlpapi.dll, "DeleteIpForwardEntry");
	iphlpapi.DeleteIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "DeleteIpForwardEntry2");
	iphlpapi.DeleteIpNetEntry = GetProcAddress(iphlpapi.dll, "DeleteIpNetEntry");
	iphlpapi.DeleteIpNetEntry2 = GetProcAddress(iphlpapi.dll, "DeleteIpNetEntry2");
	iphlpapi.DeletePersistentTcpPortReservation = GetProcAddress(iphlpapi.dll, "DeletePersistentTcpPortReservation");
	iphlpapi.DeletePersistentUdpPortReservation = GetProcAddress(iphlpapi.dll, "DeletePersistentUdpPortReservation");
	iphlpapi.DeleteProxyArpEntry = GetProcAddress(iphlpapi.dll, "DeleteProxyArpEntry");
	iphlpapi.DeleteUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "DeleteUnicastIpAddressEntry");
	iphlpapi.DisableMediaSense = GetProcAddress(iphlpapi.dll, "DisableMediaSense");
	iphlpapi.EnableRouter = GetProcAddress(iphlpapi.dll, "EnableRouter");
	iphlpapi.FlushIpNetTable = GetProcAddress(iphlpapi.dll, "FlushIpNetTable");
	iphlpapi.FlushIpNetTable2 = GetProcAddress(iphlpapi.dll, "FlushIpNetTable2");
	iphlpapi.FlushIpPathTable = GetProcAddress(iphlpapi.dll, "FlushIpPathTable");
	iphlpapi.FreeDnsSettings = GetProcAddress(iphlpapi.dll, "FreeDnsSettings");
	iphlpapi.FreeInterfaceDnsSettings = GetProcAddress(iphlpapi.dll, "FreeInterfaceDnsSettings");
	iphlpapi.FreeMibTable = GetProcAddress(iphlpapi.dll, "FreeMibTable");
	iphlpapi.GetAdapterIndex = GetProcAddress(iphlpapi.dll, "GetAdapterIndex");
	iphlpapi.GetAdapterOrderMap = GetProcAddress(iphlpapi.dll, "GetAdapterOrderMap");
	iphlpapi.GetAdaptersAddresses = GetProcAddress(iphlpapi.dll, "GetAdaptersAddresses");
	iphlpapi.GetAdaptersInfo = GetProcAddress(iphlpapi.dll, "GetAdaptersInfo");
	iphlpapi.GetAnycastIpAddressEntry = GetProcAddress(iphlpapi.dll, "GetAnycastIpAddressEntry");
	iphlpapi.GetAnycastIpAddressTable = GetProcAddress(iphlpapi.dll, "GetAnycastIpAddressTable");
	iphlpapi.GetBestInterface = GetProcAddress(iphlpapi.dll, "GetBestInterface");
	iphlpapi.GetBestInterfaceEx = GetProcAddress(iphlpapi.dll, "GetBestInterfaceEx");
	iphlpapi.GetBestRoute = GetProcAddress(iphlpapi.dll, "GetBestRoute");
	iphlpapi.GetBestRoute2 = GetProcAddress(iphlpapi.dll, "GetBestRoute2");
	iphlpapi.GetCurrentThreadCompartmentId = GetProcAddress(iphlpapi.dll, "GetCurrentThreadCompartmentId");
	iphlpapi.GetCurrentThreadCompartmentScope = GetProcAddress(iphlpapi.dll, "GetCurrentThreadCompartmentScope");
	iphlpapi.GetDefaultCompartmentId = GetProcAddress(iphlpapi.dll, "GetDefaultCompartmentId");
	iphlpapi.GetDnsSettings = GetProcAddress(iphlpapi.dll, "GetDnsSettings");
	iphlpapi.GetExtendedTcpTable = GetProcAddress(iphlpapi.dll, "GetExtendedTcpTable");
	iphlpapi.GetExtendedUdpTable = GetProcAddress(iphlpapi.dll, "GetExtendedUdpTable");
	iphlpapi.GetFlVirtualInterface = GetProcAddress(iphlpapi.dll, "GetFlVirtualInterface");
	iphlpapi.GetFlVirtualInterfaceTable = GetProcAddress(iphlpapi.dll, "GetFlVirtualInterfaceTable");
	iphlpapi.GetFriendlyIfIndex = GetProcAddress(iphlpapi.dll, "GetFriendlyIfIndex");
	iphlpapi.GetIcmpStatistics = GetProcAddress(iphlpapi.dll, "GetIcmpStatistics");
	iphlpapi.GetIcmpStatisticsEx = GetProcAddress(iphlpapi.dll, "GetIcmpStatisticsEx");
	iphlpapi.GetIfEntry = GetProcAddress(iphlpapi.dll, "GetIfEntry");
	iphlpapi.GetIfEntry2 = GetProcAddress(iphlpapi.dll, "GetIfEntry2");
	iphlpapi.GetIfEntry2Ex = GetProcAddress(iphlpapi.dll, "GetIfEntry2Ex");
	iphlpapi.GetIfStackTable = GetProcAddress(iphlpapi.dll, "GetIfStackTable");
	iphlpapi.GetIfTable = GetProcAddress(iphlpapi.dll, "GetIfTable");
	iphlpapi.GetIfTable2 = GetProcAddress(iphlpapi.dll, "GetIfTable2");
	iphlpapi.GetIfTable2Ex = GetProcAddress(iphlpapi.dll, "GetIfTable2Ex");
	iphlpapi.GetInterfaceActiveTimestampCapabilities = GetProcAddress(iphlpapi.dll, "GetInterfaceActiveTimestampCapabilities");
	iphlpapi.GetInterfaceCompartmentId = GetProcAddress(iphlpapi.dll, "GetInterfaceCompartmentId");
	iphlpapi.GetInterfaceCurrentTimestampCapabilities = GetProcAddress(iphlpapi.dll, "GetInterfaceCurrentTimestampCapabilities");
	iphlpapi.GetInterfaceDnsSettings = GetProcAddress(iphlpapi.dll, "GetInterfaceDnsSettings");
	iphlpapi.GetInterfaceHardwareTimestampCapabilities = GetProcAddress(iphlpapi.dll, "GetInterfaceHardwareTimestampCapabilities");
	iphlpapi.GetInterfaceInfo = GetProcAddress(iphlpapi.dll, "GetInterfaceInfo");
	iphlpapi.GetInterfaceSupportedTimestampCapabilities = GetProcAddress(iphlpapi.dll, "GetInterfaceSupportedTimestampCapabilities");
	iphlpapi.GetInvertedIfStackTable = GetProcAddress(iphlpapi.dll, "GetInvertedIfStackTable");
	iphlpapi.GetIpAddrTable = GetProcAddress(iphlpapi.dll, "GetIpAddrTable");
	iphlpapi.GetIpErrorString = GetProcAddress(iphlpapi.dll, "GetIpErrorString");
	iphlpapi.GetIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "GetIpForwardEntry2");
	iphlpapi.GetIpForwardTable = GetProcAddress(iphlpapi.dll, "GetIpForwardTable");
	iphlpapi.GetIpForwardTable2 = GetProcAddress(iphlpapi.dll, "GetIpForwardTable2");
	iphlpapi.GetIpInterfaceEntry = GetProcAddress(iphlpapi.dll, "GetIpInterfaceEntry");
	iphlpapi.GetIpInterfaceTable = GetProcAddress(iphlpapi.dll, "GetIpInterfaceTable");
	iphlpapi.GetIpNetEntry2 = GetProcAddress(iphlpapi.dll, "GetIpNetEntry2");
	iphlpapi.GetIpNetTable = GetProcAddress(iphlpapi.dll, "GetIpNetTable");
	iphlpapi.GetIpNetTable2 = GetProcAddress(iphlpapi.dll, "GetIpNetTable2");
	iphlpapi.GetIpNetworkConnectionBandwidthEstimates = GetProcAddress(iphlpapi.dll, "GetIpNetworkConnectionBandwidthEstimates");
	iphlpapi.GetIpPathEntry = GetProcAddress(iphlpapi.dll, "GetIpPathEntry");
	iphlpapi.GetIpPathTable = GetProcAddress(iphlpapi.dll, "GetIpPathTable");
	iphlpapi.GetIpStatistics = GetProcAddress(iphlpapi.dll, "GetIpStatistics");
	iphlpapi.GetIpStatisticsEx = GetProcAddress(iphlpapi.dll, "GetIpStatisticsEx");
	iphlpapi.GetJobCompartmentId = GetProcAddress(iphlpapi.dll, "GetJobCompartmentId");
	iphlpapi.GetMulticastIpAddressEntry = GetProcAddress(iphlpapi.dll, "GetMulticastIpAddressEntry");
	iphlpapi.GetMulticastIpAddressTable = GetProcAddress(iphlpapi.dll, "GetMulticastIpAddressTable");
	iphlpapi.GetNetworkConnectivityHint = GetProcAddress(iphlpapi.dll, "GetNetworkConnectivityHint");
	iphlpapi.GetNetworkConnectivityHintForInterface = GetProcAddress(iphlpapi.dll, "GetNetworkConnectivityHintForInterface");
	iphlpapi.GetNetworkInformation = GetProcAddress(iphlpapi.dll, "GetNetworkInformation");
	iphlpapi.GetNetworkParams = GetProcAddress(iphlpapi.dll, "GetNetworkParams");
	iphlpapi.GetNumberOfInterfaces = GetProcAddress(iphlpapi.dll, "GetNumberOfInterfaces");
	iphlpapi.GetOwnerModuleFromPidAndInfo = GetProcAddress(iphlpapi.dll, "GetOwnerModuleFromPidAndInfo");
	iphlpapi.GetOwnerModuleFromTcp6Entry = GetProcAddress(iphlpapi.dll, "GetOwnerModuleFromTcp6Entry");
	iphlpapi.GetOwnerModuleFromTcpEntry = GetProcAddress(iphlpapi.dll, "GetOwnerModuleFromTcpEntry");
	iphlpapi.GetOwnerModuleFromUdp6Entry = GetProcAddress(iphlpapi.dll, "GetOwnerModuleFromUdp6Entry");
	iphlpapi.GetOwnerModuleFromUdpEntry = GetProcAddress(iphlpapi.dll, "GetOwnerModuleFromUdpEntry");
	iphlpapi.GetPerAdapterInfo = GetProcAddress(iphlpapi.dll, "GetPerAdapterInfo");
	iphlpapi.GetPerTcp6ConnectionEStats = GetProcAddress(iphlpapi.dll, "GetPerTcp6ConnectionEStats");
	iphlpapi.GetPerTcp6ConnectionStats = GetProcAddress(iphlpapi.dll, "GetPerTcp6ConnectionStats");
	iphlpapi.GetPerTcpConnectionEStats = GetProcAddress(iphlpapi.dll, "GetPerTcpConnectionEStats");
	iphlpapi.GetPerTcpConnectionStats = GetProcAddress(iphlpapi.dll, "GetPerTcpConnectionStats");
	iphlpapi.GetRTTAndHopCount = GetProcAddress(iphlpapi.dll, "GetRTTAndHopCount");
	iphlpapi.GetSessionCompartmentId = GetProcAddress(iphlpapi.dll, "GetSessionCompartmentId");
	iphlpapi.GetTcp6Table = GetProcAddress(iphlpapi.dll, "GetTcp6Table");
	iphlpapi.GetTcp6Table2 = GetProcAddress(iphlpapi.dll, "GetTcp6Table2");
	iphlpapi.GetTcpStatistics = GetProcAddress(iphlpapi.dll, "GetTcpStatistics");
	iphlpapi.GetTcpStatisticsEx = GetProcAddress(iphlpapi.dll, "GetTcpStatisticsEx");
	iphlpapi.GetTcpStatisticsEx2 = GetProcAddress(iphlpapi.dll, "GetTcpStatisticsEx2");
	iphlpapi.GetTcpTable = GetProcAddress(iphlpapi.dll, "GetTcpTable");
	iphlpapi.GetTcpTable2 = GetProcAddress(iphlpapi.dll, "GetTcpTable2");
	iphlpapi.GetTeredoPort = GetProcAddress(iphlpapi.dll, "GetTeredoPort");
	iphlpapi.GetUdp6Table = GetProcAddress(iphlpapi.dll, "GetUdp6Table");
	iphlpapi.GetUdpStatistics = GetProcAddress(iphlpapi.dll, "GetUdpStatistics");
	iphlpapi.GetUdpStatisticsEx = GetProcAddress(iphlpapi.dll, "GetUdpStatisticsEx");
	iphlpapi.GetUdpStatisticsEx2 = GetProcAddress(iphlpapi.dll, "GetUdpStatisticsEx2");
	iphlpapi.GetUdpTable = GetProcAddress(iphlpapi.dll, "GetUdpTable");
	iphlpapi.GetUniDirectionalAdapterInfo = GetProcAddress(iphlpapi.dll, "GetUniDirectionalAdapterInfo");
	iphlpapi.GetUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "GetUnicastIpAddressEntry");
	iphlpapi.GetUnicastIpAddressTable = GetProcAddress(iphlpapi.dll, "GetUnicastIpAddressTable");
	iphlpapi.GetWPAOACSupportLevel = GetProcAddress(iphlpapi.dll, "GetWPAOACSupportLevel");
	iphlpapi.Icmp6CreateFile = GetProcAddress(iphlpapi.dll, "Icmp6CreateFile");
	iphlpapi.Icmp6ParseReplies = GetProcAddress(iphlpapi.dll, "Icmp6ParseReplies");
	iphlpapi.Icmp6SendEcho2 = GetProcAddress(iphlpapi.dll, "Icmp6SendEcho2");
	iphlpapi.IcmpCloseHandle = GetProcAddress(iphlpapi.dll, "IcmpCloseHandle");
	iphlpapi.IcmpCreateFile = GetProcAddress(iphlpapi.dll, "IcmpCreateFile");
	iphlpapi.IcmpParseReplies = GetProcAddress(iphlpapi.dll, "IcmpParseReplies");
	iphlpapi.IcmpSendEcho = GetProcAddress(iphlpapi.dll, "IcmpSendEcho");
	iphlpapi.IcmpSendEcho2 = GetProcAddress(iphlpapi.dll, "IcmpSendEcho2");
	iphlpapi.IcmpSendEcho2Ex = GetProcAddress(iphlpapi.dll, "IcmpSendEcho2Ex");
	iphlpapi.InitializeCompartmentEntry = GetProcAddress(iphlpapi.dll, "InitializeCompartmentEntry");
	iphlpapi.InitializeFlVirtualInterfaceEntry = GetProcAddress(iphlpapi.dll, "InitializeFlVirtualInterfaceEntry");
	iphlpapi.InitializeIpForwardEntry = GetProcAddress(iphlpapi.dll, "InitializeIpForwardEntry");
	iphlpapi.InitializeIpInterfaceEntry = GetProcAddress(iphlpapi.dll, "InitializeIpInterfaceEntry");
	iphlpapi.InitializeUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InitializeUnicastIpAddressEntry");
	iphlpapi.InternalCleanupPersistentStore = GetProcAddress(iphlpapi.dll, "InternalCleanupPersistentStore");
	iphlpapi.InternalCreateAnycastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalCreateAnycastIpAddressEntry");
	iphlpapi.InternalCreateIpForwardEntry = GetProcAddress(iphlpapi.dll, "InternalCreateIpForwardEntry");
	iphlpapi.InternalCreateIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "InternalCreateIpForwardEntry2");
	iphlpapi.InternalCreateIpNetEntry = GetProcAddress(iphlpapi.dll, "InternalCreateIpNetEntry");
	iphlpapi.InternalCreateIpNetEntry2 = GetProcAddress(iphlpapi.dll, "InternalCreateIpNetEntry2");
	iphlpapi.InternalCreateOrRefIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "InternalCreateOrRefIpForwardEntry2");
	iphlpapi.InternalCreateUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalCreateUnicastIpAddressEntry");
	iphlpapi.InternalDeleteAnycastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalDeleteAnycastIpAddressEntry");
	iphlpapi.InternalDeleteIpForwardEntry = GetProcAddress(iphlpapi.dll, "InternalDeleteIpForwardEntry");
	iphlpapi.InternalDeleteIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "InternalDeleteIpForwardEntry2");
	iphlpapi.InternalDeleteIpNetEntry = GetProcAddress(iphlpapi.dll, "InternalDeleteIpNetEntry");
	iphlpapi.InternalDeleteIpNetEntry2 = GetProcAddress(iphlpapi.dll, "InternalDeleteIpNetEntry2");
	iphlpapi.InternalDeleteUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalDeleteUnicastIpAddressEntry");
	iphlpapi.InternalFindInterfaceByAddress = GetProcAddress(iphlpapi.dll, "InternalFindInterfaceByAddress");
	iphlpapi.InternalGetAnycastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalGetAnycastIpAddressEntry");
	iphlpapi.InternalGetAnycastIpAddressTable = GetProcAddress(iphlpapi.dll, "InternalGetAnycastIpAddressTable");
	iphlpapi.InternalGetBoundTcp6EndpointTable = GetProcAddress(iphlpapi.dll, "InternalGetBoundTcp6EndpointTable");
	iphlpapi.InternalGetBoundTcpEndpointTable = GetProcAddress(iphlpapi.dll, "InternalGetBoundTcpEndpointTable");
	iphlpapi.InternalGetForwardIpTable2 = GetProcAddress(iphlpapi.dll, "InternalGetForwardIpTable2");
	iphlpapi.InternalGetIPPhysicalInterfaceForDestination = GetProcAddress(iphlpapi.dll, "InternalGetIPPhysicalInterfaceForDestination");
	iphlpapi.InternalGetIfEntry2 = GetProcAddress(iphlpapi.dll, "InternalGetIfEntry2");
	iphlpapi.InternalGetIfTable = GetProcAddress(iphlpapi.dll, "InternalGetIfTable");
	iphlpapi.InternalGetIfTable2 = GetProcAddress(iphlpapi.dll, "InternalGetIfTable2");
	iphlpapi.InternalGetIpAddrTable = GetProcAddress(iphlpapi.dll, "InternalGetIpAddrTable");
	iphlpapi.InternalGetIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "InternalGetIpForwardEntry2");
	iphlpapi.InternalGetIpForwardTable = GetProcAddress(iphlpapi.dll, "InternalGetIpForwardTable");
	iphlpapi.InternalGetIpInterfaceEntry = GetProcAddress(iphlpapi.dll, "InternalGetIpInterfaceEntry");
	iphlpapi.InternalGetIpInterfaceTable = GetProcAddress(iphlpapi.dll, "InternalGetIpInterfaceTable");
	iphlpapi.InternalGetIpNetEntry2 = GetProcAddress(iphlpapi.dll, "InternalGetIpNetEntry2");
	iphlpapi.InternalGetIpNetTable = GetProcAddress(iphlpapi.dll, "InternalGetIpNetTable");
	iphlpapi.InternalGetIpNetTable2 = GetProcAddress(iphlpapi.dll, "InternalGetIpNetTable2");
	iphlpapi.InternalGetMulticastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalGetMulticastIpAddressEntry");
	iphlpapi.InternalGetMulticastIpAddressTable = GetProcAddress(iphlpapi.dll, "InternalGetMulticastIpAddressTable");
	iphlpapi.InternalGetRtcSlotInformation = GetProcAddress(iphlpapi.dll, "InternalGetRtcSlotInformation");
	iphlpapi.InternalGetTcp6Table2 = GetProcAddress(iphlpapi.dll, "InternalGetTcp6Table2");
	iphlpapi.InternalGetTcp6TableWithOwnerModule = GetProcAddress(iphlpapi.dll, "InternalGetTcp6TableWithOwnerModule");
	iphlpapi.InternalGetTcp6TableWithOwnerPid = GetProcAddress(iphlpapi.dll, "InternalGetTcp6TableWithOwnerPid");
	iphlpapi.InternalGetTcpDynamicPortRange = GetProcAddress(iphlpapi.dll, "InternalGetTcpDynamicPortRange");
	iphlpapi.InternalGetTcpTable = GetProcAddress(iphlpapi.dll, "InternalGetTcpTable");
	iphlpapi.InternalGetTcpTable2 = GetProcAddress(iphlpapi.dll, "InternalGetTcpTable2");
	iphlpapi.InternalGetTcpTableEx = GetProcAddress(iphlpapi.dll, "InternalGetTcpTableEx");
	iphlpapi.InternalGetTcpTableWithOwnerModule = GetProcAddress(iphlpapi.dll, "InternalGetTcpTableWithOwnerModule");
	iphlpapi.InternalGetTcpTableWithOwnerPid = GetProcAddress(iphlpapi.dll, "InternalGetTcpTableWithOwnerPid");
	iphlpapi.InternalGetTunnelPhysicalAdapter = GetProcAddress(iphlpapi.dll, "InternalGetTunnelPhysicalAdapter");
	iphlpapi.InternalGetUdp6Table2 = GetProcAddress(iphlpapi.dll, "InternalGetUdp6Table2");
	iphlpapi.InternalGetUdp6TableWithOwnerModule = GetProcAddress(iphlpapi.dll, "InternalGetUdp6TableWithOwnerModule");
	iphlpapi.InternalGetUdp6TableWithOwnerPid = GetProcAddress(iphlpapi.dll, "InternalGetUdp6TableWithOwnerPid");
	iphlpapi.InternalGetUdpDynamicPortRange = GetProcAddress(iphlpapi.dll, "InternalGetUdpDynamicPortRange");
	iphlpapi.InternalGetUdpTable = GetProcAddress(iphlpapi.dll, "InternalGetUdpTable");
	iphlpapi.InternalGetUdpTable2 = GetProcAddress(iphlpapi.dll, "InternalGetUdpTable2");
	iphlpapi.InternalGetUdpTableEx = GetProcAddress(iphlpapi.dll, "InternalGetUdpTableEx");
	iphlpapi.InternalGetUdpTableWithOwnerModule = GetProcAddress(iphlpapi.dll, "InternalGetUdpTableWithOwnerModule");
	iphlpapi.InternalGetUdpTableWithOwnerPid = GetProcAddress(iphlpapi.dll, "InternalGetUdpTableWithOwnerPid");
	iphlpapi.InternalGetUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalGetUnicastIpAddressEntry");
	iphlpapi.InternalGetUnicastIpAddressTable = GetProcAddress(iphlpapi.dll, "InternalGetUnicastIpAddressTable");
	iphlpapi.InternalIcmpCreateFileEx = GetProcAddress(iphlpapi.dll, "InternalIcmpCreateFileEx");
	iphlpapi.InternalSetIfEntry = GetProcAddress(iphlpapi.dll, "InternalSetIfEntry");
	iphlpapi.InternalSetIpForwardEntry = GetProcAddress(iphlpapi.dll, "InternalSetIpForwardEntry");
	iphlpapi.InternalSetIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "InternalSetIpForwardEntry2");
	iphlpapi.InternalSetIpInterfaceEntry = GetProcAddress(iphlpapi.dll, "InternalSetIpInterfaceEntry");
	iphlpapi.InternalSetIpNetEntry = GetProcAddress(iphlpapi.dll, "InternalSetIpNetEntry");
	iphlpapi.InternalSetIpNetEntry2 = GetProcAddress(iphlpapi.dll, "InternalSetIpNetEntry2");
	iphlpapi.InternalSetIpStats = GetProcAddress(iphlpapi.dll, "InternalSetIpStats");
	iphlpapi.InternalSetTcpDynamicPortRange = GetProcAddress(iphlpapi.dll, "InternalSetTcpDynamicPortRange");
	iphlpapi.InternalSetTcpEntry = GetProcAddress(iphlpapi.dll, "InternalSetTcpEntry");
	iphlpapi.InternalSetTeredoPort = GetProcAddress(iphlpapi.dll, "InternalSetTeredoPort");
	iphlpapi.InternalSetUdpDynamicPortRange = GetProcAddress(iphlpapi.dll, "InternalSetUdpDynamicPortRange");
	iphlpapi.InternalSetUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "InternalSetUnicastIpAddressEntry");
	iphlpapi.IpReleaseAddress = GetProcAddress(iphlpapi.dll, "IpReleaseAddress");
	iphlpapi.IpRenewAddress = GetProcAddress(iphlpapi.dll, "IpRenewAddress");
	iphlpapi.LookupPersistentTcpPortReservation = GetProcAddress(iphlpapi.dll, "LookupPersistentTcpPortReservation");
	iphlpapi.LookupPersistentUdpPortReservation = GetProcAddress(iphlpapi.dll, "LookupPersistentUdpPortReservation");
	iphlpapi.NTPTimeToNTFileTime = GetProcAddress(iphlpapi.dll, "NTPTimeToNTFileTime");
	iphlpapi.NTTimeToNTPTime = GetProcAddress(iphlpapi.dll, "NTTimeToNTPTime");
	iphlpapi.NhGetGuidFromInterfaceName = GetProcAddress(iphlpapi.dll, "NhGetGuidFromInterfaceName");
	iphlpapi.NhGetInterfaceDescriptionFromGuid = GetProcAddress(iphlpapi.dll, "NhGetInterfaceDescriptionFromGuid");
	iphlpapi.NhGetInterfaceNameFromDeviceGuid = GetProcAddress(iphlpapi.dll, "NhGetInterfaceNameFromDeviceGuid");
	iphlpapi.NhGetInterfaceNameFromGuid = GetProcAddress(iphlpapi.dll, "NhGetInterfaceNameFromGuid");
	iphlpapi.NhpAllocateAndGetInterfaceInfoFromStack = GetProcAddress(iphlpapi.dll, "NhpAllocateAndGetInterfaceInfoFromStack");
	iphlpapi.NotifyAddrChange = GetProcAddress(iphlpapi.dll, "NotifyAddrChange");
	iphlpapi.NotifyCompartmentChange = GetProcAddress(iphlpapi.dll, "NotifyCompartmentChange");
	iphlpapi.NotifyIfTimestampConfigChange = GetProcAddress(iphlpapi.dll, "NotifyIfTimestampConfigChange");
	iphlpapi.NotifyIpInterfaceChange = GetProcAddress(iphlpapi.dll, "NotifyIpInterfaceChange");
	iphlpapi.NotifyNetworkConnectivityHintChange = GetProcAddress(iphlpapi.dll, "NotifyNetworkConnectivityHintChange");
	iphlpapi.NotifyRouteChange = GetProcAddress(iphlpapi.dll, "NotifyRouteChange");
	iphlpapi.NotifyRouteChange2 = GetProcAddress(iphlpapi.dll, "NotifyRouteChange2");
	iphlpapi.NotifyStableUnicastIpAddressTable = GetProcAddress(iphlpapi.dll, "NotifyStableUnicastIpAddressTable");
	iphlpapi.NotifyTeredoPortChange = GetProcAddress(iphlpapi.dll, "NotifyTeredoPortChange");
	iphlpapi.NotifyUnicastIpAddressChange = GetProcAddress(iphlpapi.dll, "NotifyUnicastIpAddressChange");
	iphlpapi.OpenCompartment = GetProcAddress(iphlpapi.dll, "OpenCompartment");
	iphlpapi.ParseNetworkString = GetProcAddress(iphlpapi.dll, "ParseNetworkString");
	iphlpapi.PfAddFiltersToInterface = GetProcAddress(iphlpapi.dll, "PfAddFiltersToInterface");
	iphlpapi.PfAddGlobalFilterToInterface = GetProcAddress(iphlpapi.dll, "PfAddGlobalFilterToInterface");
	iphlpapi.PfBindInterfaceToIPAddress = GetProcAddress(iphlpapi.dll, "PfBindInterfaceToIPAddress");
	iphlpapi.PfBindInterfaceToIndex = GetProcAddress(iphlpapi.dll, "PfBindInterfaceToIndex");
	iphlpapi.PfCreateInterface = GetProcAddress(iphlpapi.dll, "PfCreateInterface");
	iphlpapi.PfDeleteInterface = GetProcAddress(iphlpapi.dll, "PfDeleteInterface");
	iphlpapi.PfDeleteLog = GetProcAddress(iphlpapi.dll, "PfDeleteLog");
	iphlpapi.PfGetInterfaceStatistics = GetProcAddress(iphlpapi.dll, "PfGetInterfaceStatistics");
	iphlpapi.PfMakeLog = GetProcAddress(iphlpapi.dll, "PfMakeLog");
	iphlpapi.PfRebindFilters = GetProcAddress(iphlpapi.dll, "PfRebindFilters");
	iphlpapi.PfRemoveFilterHandles = GetProcAddress(iphlpapi.dll, "PfRemoveFilterHandles");
	iphlpapi.PfRemoveFiltersFromInterface = GetProcAddress(iphlpapi.dll, "PfRemoveFiltersFromInterface");
	iphlpapi.PfRemoveGlobalFilterFromInterface = GetProcAddress(iphlpapi.dll, "PfRemoveGlobalFilterFromInterface");
	iphlpapi.PfSetLogBuffer = GetProcAddress(iphlpapi.dll, "PfSetLogBuffer");
	iphlpapi.PfTestPacket = GetProcAddress(iphlpapi.dll, "PfTestPacket");
	iphlpapi.PfUnBindInterface = GetProcAddress(iphlpapi.dll, "PfUnBindInterface");
	iphlpapi.RegisterInterfaceTimestampConfigChange = GetProcAddress(iphlpapi.dll, "RegisterInterfaceTimestampConfigChange");
	iphlpapi.ResolveIpNetEntry2 = GetProcAddress(iphlpapi.dll, "ResolveIpNetEntry2");
	iphlpapi.ResolveNeighbor = GetProcAddress(iphlpapi.dll, "ResolveNeighbor");
	iphlpapi.RestoreMediaSense = GetProcAddress(iphlpapi.dll, "RestoreMediaSense");
	iphlpapi.SendARP = GetProcAddress(iphlpapi.dll, "SendARP");
	iphlpapi.SetAdapterIpAddress = GetProcAddress(iphlpapi.dll, "SetAdapterIpAddress");
	iphlpapi.SetCurrentThreadCompartmentId = GetProcAddress(iphlpapi.dll, "SetCurrentThreadCompartmentId");
	iphlpapi.SetCurrentThreadCompartmentScope = GetProcAddress(iphlpapi.dll, "SetCurrentThreadCompartmentScope");
	iphlpapi.SetDnsSettings = GetProcAddress(iphlpapi.dll, "SetDnsSettings");
	iphlpapi.SetFlVirtualInterface = GetProcAddress(iphlpapi.dll, "SetFlVirtualInterface");
	iphlpapi.SetIfEntry = GetProcAddress(iphlpapi.dll, "SetIfEntry");
	iphlpapi.SetInterfaceDnsSettings = GetProcAddress(iphlpapi.dll, "SetInterfaceDnsSettings");
	iphlpapi.SetIpForwardEntry = GetProcAddress(iphlpapi.dll, "SetIpForwardEntry");
	iphlpapi.SetIpForwardEntry2 = GetProcAddress(iphlpapi.dll, "SetIpForwardEntry2");
	iphlpapi.SetIpInterfaceEntry = GetProcAddress(iphlpapi.dll, "SetIpInterfaceEntry");
	iphlpapi.SetIpNetEntry = GetProcAddress(iphlpapi.dll, "SetIpNetEntry");
	iphlpapi.SetIpNetEntry2 = GetProcAddress(iphlpapi.dll, "SetIpNetEntry2");
	iphlpapi.SetIpStatistics = GetProcAddress(iphlpapi.dll, "SetIpStatistics");
	iphlpapi.SetIpStatisticsEx = GetProcAddress(iphlpapi.dll, "SetIpStatisticsEx");
	iphlpapi.SetIpTTL = GetProcAddress(iphlpapi.dll, "SetIpTTL");
	iphlpapi.SetJobCompartmentId = GetProcAddress(iphlpapi.dll, "SetJobCompartmentId");
	iphlpapi.SetNetworkInformation = GetProcAddress(iphlpapi.dll, "SetNetworkInformation");
	iphlpapi.SetPerTcp6ConnectionEStats = GetProcAddress(iphlpapi.dll, "SetPerTcp6ConnectionEStats");
	iphlpapi.SetPerTcp6ConnectionStats = GetProcAddress(iphlpapi.dll, "SetPerTcp6ConnectionStats");
	iphlpapi.SetPerTcpConnectionEStats = GetProcAddress(iphlpapi.dll, "SetPerTcpConnectionEStats");
	iphlpapi.SetPerTcpConnectionStats = GetProcAddress(iphlpapi.dll, "SetPerTcpConnectionStats");
	iphlpapi.SetSessionCompartmentId = GetProcAddress(iphlpapi.dll, "SetSessionCompartmentId");
	iphlpapi.SetTcpEntry = GetProcAddress(iphlpapi.dll, "SetTcpEntry");
	iphlpapi.SetUnicastIpAddressEntry = GetProcAddress(iphlpapi.dll, "SetUnicastIpAddressEntry");
	iphlpapi.UnenableRouter = GetProcAddress(iphlpapi.dll, "UnenableRouter");
	iphlpapi.UnregisterInterfaceTimestampConfigChange = GetProcAddress(iphlpapi.dll, "UnregisterInterfaceTimestampConfigChange");
	iphlpapi.do_echo_rep = GetProcAddress(iphlpapi.dll, "do_echo_rep");
	iphlpapi.do_echo_req = GetProcAddress(iphlpapi.dll, "do_echo_req");
	iphlpapi.if_indextoname = GetProcAddress(iphlpapi.dll, "if_indextoname");
	iphlpapi.if_nametoindex = GetProcAddress(iphlpapi.dll, "if_nametoindex");
	iphlpapi.register_icmp = GetProcAddress(iphlpapi.dll, "register_icmp");
	return true;
}

bool unload_library_iphlpapi() {
	FreeLibrary(iphlpapi.dll);
	iphlpapi.dll = nullptr;
	return true;
}

#else

bool load_library_iphlpapi() {
	return false;
}

bool unload_library_iphlpapi() {
	return false;
}

#endif

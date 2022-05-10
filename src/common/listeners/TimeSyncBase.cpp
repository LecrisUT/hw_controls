//
// Created by lecris on 5/10/22.
//

#include "TimeSyncBase.hpp"
#include <iostream>

using namespace AsteroidOS::HW_CONTROLS;

TimeSyncBase::TimeSyncBase( DaemonBase& parent ) :
		ListenerBase(parent, "org.freedesktop.timedate1", "/org/freedesktop/timedate1") {
	Proxy->registerSignalHandler("org.freedesktop.DBus.Properties", "PropertiesChanged",
	                             [this]( sdbus::Signal& s ) { Callback(s); });
}
void TimeSyncBase::Callback( sdbus::Signal& signal ) {
	std::string interface;
	signal >> interface;
	if (interface != "org.freedesktop.timedate1") {
		std::cerr << "Received unexpected signal:\nInterface = " << interface << std::endl;
		return;
	}
	std::map<std::string, sdbus::Variant> changed_props;
	signal >> changed_props;
	for (const auto& prop: changed_props)
		if (prop.first != "NTP" && prop.first != "Timezone" && prop.first != "LocalRTC")
			std::cerr << "Received unexpected changed property:Property = " << prop.first << std::endl;
	if (changed_props.contains("NTP") || changed_props.contains("Timezone") || changed_props.contains("LocalRTC")) {
		auto res = SyncTime();
		if (!res)
			std::cerr << "SyncTime() failed\n";
	}
}

//
// Created by lecris on 5/10/22.
//

#include "TimeSync.hpp"
#include <iostream>

using namespace AsteroidOS::HW_CONTROLS;

TimeSync::TimeSync( DaemonBase& parent ) :
		TimeSyncBase(parent) { }
bool TimeSync::SyncTime() {
	std::cout << "Syncing LCD time\n";
	return true;
}

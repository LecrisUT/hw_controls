//
// Created by lecris on 5/10/22.
//

#include "Daemon.hpp"
#include "listeners/TimeSync.hpp"

using namespace AsteroidOS::HW_CONTROLS;
Daemon::Daemon():
		DaemonBase("catfish"){
	Listeners.push_back(std::make_unique<TimeSync>(*this));
}

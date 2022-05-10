//
// Created by lecris on 5/10/22.
//

#include "Daemon.hpp"

using namespace AsteroidOS::HW_CONTROLS;

narwhal::Daemon::Daemon() = default;
std::shared_ptr<DaemonBase> DaemonBase::GetDaemon() {
	static auto daemon = std::make_shared<narwhal::Daemon>();
	return daemon;
}

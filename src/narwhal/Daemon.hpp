//
// Created by lecris on 5/10/22.
//

#ifndef HW_CONTROLS_NARWHAL_DAEMON_HPP
#define HW_CONTROLS_NARWHAL_DAEMON_HPP

#include "common/DaemonBase.hpp"

namespace AsteroidOS::HW_CONTROLS::narwhal {
	class Daemon:
			public DaemonBase{
	public:
		Daemon();
	};
}

#endif //HW_CONTROLS_NARWHAL_DAEMON_HPP

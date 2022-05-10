//
// Created by lecris on 5/10/22.
//

#ifndef HW_CONTROLS_SRC_COMMON_LISTENERS_TIMESYNCLISTENER_HPP
#define HW_CONTROLS_SRC_COMMON_LISTENERS_TIMESYNCLISTENER_HPP

#include "common/DaemonBase.hpp"

namespace AsteroidOS::HW_CONTROLS {
	class TimeSyncListener :
			public ListenerBase {
	public:
		explicit TimeSyncListener( DaemonBase& parent);
		void Callback(sdbus::Signal& signal);
	};
}

#endif //HW_CONTROLS_SRC_COMMON_LISTENERS_TIMESYNCLISTENER_HPP

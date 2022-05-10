//
// Created by lecris on 5/10/22.
//

#ifndef HW_CONTROLS_SRC_COMMON_LISTENERS_TIMESYNCBASE_HPP
#define HW_CONTROLS_SRC_COMMON_LISTENERS_TIMESYNCBASE_HPP

#include "common/DaemonBase.hpp"

namespace AsteroidOS::HW_CONTROLS {
	class TimeSyncBase :
			public ListenerBase {
	protected:
		explicit TimeSyncBase(DaemonBase& parent);
		void Callback(sdbus::Signal& signal);
	public:
		virtual bool SyncTime() = 0;
	};
}

#endif //HW_CONTROLS_SRC_COMMON_LISTENERS_TIMESYNCBASE_HPP

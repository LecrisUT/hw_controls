//
// Created by lecris on 5/10/22.
//

#ifndef HW_CONTROLS_SRC_CATFISH_TIMESYNC_HPP
#define HW_CONTROLS_SRC_CATFISH_TIMESYNC_HPP

#include "common/listeners/TimeSyncBase.hpp"

namespace AsteroidOS::HW_CONTROLS {
	class TimeSync:
			public TimeSyncBase{
	public:
		explicit TimeSync( DaemonBase& parent );
		bool SyncTime() override;
	};
}

#endif //HW_CONTROLS_SRC_CATFISH_TIMESYNC_HPP

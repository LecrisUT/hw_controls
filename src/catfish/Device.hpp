//
// Created by lecris on 5/10/22.
//

#ifndef HW_CONTROLS_CATFISH_DEVICE_HPP
#define HW_CONTROLS_CATFISH_DEVICE_HPP

#include "common/DeviceBase.hpp"

namespace AsteroidOS::HW_CONTROLS::catfish {
	class Device:
			public DeviceBase{
	public:
		Device();
		bool SyncTime() override;
	};

}

#endif //HW_CONTROLS_CATFISH_DEVICE_HPP

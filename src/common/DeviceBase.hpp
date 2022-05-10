//
// Created by lecris on 5/10/22.
//

#ifndef HW_CONTROLS_DEVICEBASE_HPP
#define HW_CONTROLS_DEVICEBASE_HPP

#include <memory>
#include <set>

namespace AsteroidOS::HW_CONTROLS {
	enum Implementation {
		syncTime,
	};
	class DeviceBase {
	public:
		const std::string Name;
		const std::set<Implementation> Implementations;
		static std::shared_ptr<DeviceBase> GetDevice();
	protected:
		DeviceBase( std::string_view name, std::set<Implementation>&& implementations );
	public:
		virtual bool SyncTime();
	};
}

#endif //HW_CONTROLS_DEVICEBASE_HPP

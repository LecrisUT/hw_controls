//
// Created by lecris on 5/10/22.
//

#ifndef HW_CONTROLS_DAEMONBASE_HPP
#define HW_CONTROLS_DAEMONBASE_HPP

#include "DeviceBase.hpp"
#include <sdbus-c++/sdbus-c++.h>
#include <memory>
#include <map>

namespace AsteroidOS::HW_CONTROLS {
	class ListenerBase;
	class DaemonBase {
	public:
		using ObjectMap = std::map<std::string, std::unique_ptr<sdbus::IObject>>;
		using ListenerVec = std::vector<std::unique_ptr<ListenerBase>>;
		const std::unique_ptr<sdbus::IConnection> Connection;
		ObjectMap Objects;
		ListenerVec Listeners;
		const std::shared_ptr<DeviceBase> Device;
		static std::shared_ptr<DaemonBase> GetDaemon();
	protected:
		DaemonBase();

	public:
		virtual void EnertLoop();
		std::pair<ObjectMap::iterator,bool> AddObject(const std::string& Name);
		void FinishRegistration();
	};
	class ListenerBase {
	public:
		DaemonBase& Parent;
		const std::unique_ptr<sdbus::IProxy> Proxy;
	protected:
		ListenerBase( DaemonBase& parent, const std::string& Destination, const std::string& Object );
	};
}

#endif //HW_CONTROLS_DAEMONBASE_HPP

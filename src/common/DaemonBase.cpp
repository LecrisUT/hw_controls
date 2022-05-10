//
// Created by lecris on 5/10/22.
//

#include "DaemonBase.hpp"
#include "listeners/TimeSyncListener.hpp"
#include <iostream>

using namespace AsteroidOS::HW_CONTROLS;

void DaemonBase::EnertLoop() {
	Connection->enterEventLoop();
}
DaemonBase::DaemonBase() :
		Device(DeviceBase::GetDevice()),
		Connection(sdbus::createSystemBusConnection("org.asteroidos.hwcontrols")) {
	auto res = AddObject("/org/asteroidos/hwcontrols");
	assert(res.second);
	auto& obj = res.first->second;
	obj->registerProperty("Device").
			onInterface("org.asteroidos.hwcontrols").
			withGetter([this]() { return this->Device->Name; });
	if (Device->Implementations.contains(syncTime))
		Listeners.push_back(std::make_unique<TimeSyncListener>(*this));
}
std::pair<DaemonBase::ObjectMap::iterator, bool> DaemonBase::AddObject( const std::string& Name ) {
	return Objects.insert({Name, sdbus::createObject(*Connection, Name)});
}
void DaemonBase::FinishRegistration() {
	for (const auto& obj: Objects)
		obj.second->finishRegistration();
	for (const auto& listener: Listeners)
		listener->Proxy->finishRegistration();
}

ListenerBase::ListenerBase( DaemonBase& parent, const std::string& Destination, const std::string& Object ) :
		Parent(parent), Proxy(sdbus::createProxy(*Parent.Connection, Destination, Object)) { }

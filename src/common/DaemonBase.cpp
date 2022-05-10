//
// Created by lecris on 5/10/22.
//

#include "DaemonBase.hpp"
#include <iostream>

using namespace AsteroidOS::HW_CONTROLS;

void DaemonBase::EnertLoop() {
	Connection->enterEventLoop();
}
DaemonBase::DaemonBase( std::string_view device ) :
		Device(device), Connection(sdbus::createSystemBusConnection("org.asteroidos.hwcontrols")) {
	auto res = AddObject("/org/asteroidos/hwcontrols");
	assert(res.second);
	auto& obj = res.first->second;
	obj->registerProperty("Device").
			onInterface("org.asteroidos.hwcontrols").
			withGetter([this]() { return this->Device; });
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

//
// Created by lecris on 5/10/22.
//

#include "DeviceBase.hpp"
#include <iostream>

using namespace AsteroidOS::HW_CONTROLS;

DeviceBase::DeviceBase( std::string_view name, std::set<Implementation>&& implementations ) :
		Name(name), Implementations(implementations) { }
bool DeviceBase::SyncTime() {
	std::cout << "No implementation";
	return false;
}

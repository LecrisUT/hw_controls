//
// Created by lecris on 5/10/22.
//

#include "Device.hpp"
#include <iostream>

using namespace AsteroidOS::HW_CONTROLS;

narwhal::Device::Device() :
		DeviceBase("catfish", {syncTime}) { }
bool narwhal::Device::SyncTime() {
	std::cout << "Syncing LCD time\n";
	return true;
}

std::shared_ptr<DeviceBase> DeviceBase::GetDevice() {
	static auto device = std::make_shared<narwhal::Device>();
	return device;
}

//
// Created by lecris on 5/10/22.
//

#include "Device.hpp"

using namespace AsteroidOS::HW_CONTROLS;

stub::Device::Device() :
		DeviceBase("[No Device]", {}) { }
std::shared_ptr<DeviceBase> DeviceBase::GetDevice() {
	static auto device = std::make_shared<stub::Device>();
	return device;
}

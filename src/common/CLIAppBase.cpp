//
// Created by lecris on 5/9/22.
//

#include "CLIAppBase.h"

using namespace AsteroidOS::HW_CONTROLS;

CLIAppBase::CLIAppBase() :
		Device(DeviceBase::GetDevice()) {
	this->name("Hw-controls");
	std::string description = "hw-controls: Helper tool for various extra/specific hardware\nDevice: ";
	description += Device->Name;
	this->description(description);
	if (Device->Implementations.contains(syncTime)){
		auto syncTime = this->add_subcommand("syncTime", "Sync hardware time with linux time");
		syncTime->callback([this]() { Device->SyncTime(); });
	}
}

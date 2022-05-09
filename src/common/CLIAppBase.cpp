//
// Created by lecris on 5/9/22.
//

#include "CLIAppBase.h"

using namespace AsteroidOS::HW_CONTROLS;

CLIAppBase::CLIAppBase( std::string_view device ) {
	std::string description = "hw-controls: Helper tool for various extra/specific hardware\nDevice: ";
	description += device;
	this->description(description);
}

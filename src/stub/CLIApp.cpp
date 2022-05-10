//
// Created by lecris on 5/9/22.
//

#include "CLIApp.h"

using namespace AsteroidOS::HW_CONTROLS;

stub::CLIApp::CLIApp() = default;

std::shared_ptr<CLIAppBase> CLIAppBase::GetApp() {
	static auto app = std::make_shared<stub::CLIApp>();
	return app;
}

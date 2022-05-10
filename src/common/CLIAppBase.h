//
// Created by lecris on 5/9/22.
//

#ifndef HW_CONTROLS_CLIAPPBASE_H
#define HW_CONTROLS_CLIAPPBASE_H

#include "DeviceBase.hpp"
#include <string>
#include <CLI/CLI.hpp>

namespace AsteroidOS::HW_CONTROLS {
	class CLIAppBase :
			public CLI::App {
	public:
		const std::shared_ptr<DeviceBase> Device;
		CLIAppBase();
		static std::shared_ptr<CLIAppBase> GetApp();
	};
} // HW_CONTROLS

#endif //HW_CONTROLS_CLIAPPBASE_H

//
// Created by lecris on 5/9/22.
//

#ifndef HW_CONTROLS_CLIAPPBASE_H
#define HW_CONTROLS_CLIAPPBASE_H

#include <string>
#include <CLI/CLI.hpp>

namespace AsteroidOS::HW_CONTROLS {
	class CLIAppBase :
			public CLI::App {
	public:
		explicit CLIAppBase( std::string_view device );
	};
	class CLIApp;
} // HW_CONTROLS

#endif //HW_CONTROLS_CLIAPPBASE_H

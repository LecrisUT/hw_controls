#include "CLIAppBase.h"

#include <CLI/CLI.hpp>

using namespace AsteroidOS::HW_CONTROLS;

int main( int argc, char** argv ) {
	auto app = CLIAppBase::GetApp();
	try {
		app->parse(argc, argv);
		if (argc <= 1)
			throw CLI::CallForAllHelp();
	} catch (const CLI::ParseError& e) {
		return app->exit(e);
	}
	return 0;
}

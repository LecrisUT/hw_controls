#include "Daemon.hpp"
//#include <CLI/CLI.hpp>

using namespace AsteroidOS::HW_CONTROLS;

int main( int argc, char** argv ) {
	Daemon app;
	app.FinishRegistration();
	app.EnertLoop();
}

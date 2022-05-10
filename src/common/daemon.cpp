#include "DaemonBase.hpp"
//#include <CLI/CLI.hpp>

using namespace AsteroidOS::HW_CONTROLS;

int main( int argc, char** argv ) {
	auto daemon = DaemonBase::GetDaemon();
	daemon->FinishRegistration();
	daemon->EnertLoop();
}

find_package(CLI11 REQUIRED)
find_package(sdbus-c++ REQUIRED)

add_executable(hw-tools cli.cpp CLIAppBase.cpp DeviceBase.cpp)
target_link_libraries(hw-tools PUBLIC DeviceCLI CLI11::CLI11)

add_executable(hw-toolsd daemon.cpp DaemonBase.cpp DeviceBase.cpp)
target_link_libraries(hw-toolsd PUBLIC DeviceDaemon CLI11::CLI11 SDBusCpp::sdbus-c++)

install(TARGETS hw-tools hw-toolsd RUNTIME
		DESTINATION bin)

add_subdirectory(listeners)

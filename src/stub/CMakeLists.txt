target_sources(DeviceCLI INTERFACE CLIApp.cpp)
target_include_directories(DeviceCLI INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_sources(DeviceDaemon INTERFACE Daemon.cpp)
target_include_directories(DeviceDaemon INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

find_package(CLI11 REQUIRED)

add_executable(hw-tools cli.cpp CLIAppBase.cpp)
target_link_libraries(hw-tools PUBLIC DeviceCLI)
install(TARGETS hw-tools DESTINATION bin)
target_sources(DeviceDaemon INTERFACE TimeSync.cpp)
target_link_libraries(DeviceDaemon
		INTERFACE TimeSync)

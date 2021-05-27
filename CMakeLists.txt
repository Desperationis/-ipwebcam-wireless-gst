set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

cmake_minimum_required(VERSION 3.5)

project(ipwebcam-wireless-gst VERSION 1.0)

add_executable(output)

find_package(PkgConfig REQUIRED)

pkg_check_modules(GST REQUIRED gstreamer-1.0)

target_include_directories(output PUBLIC ${GST_INCLUDE_DIRS})

target_sources(output 
		PUBLIC 
		main.c
		)

target_link_libraries(output 
		${GST_LIBRARIES}
	)

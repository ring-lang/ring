# Description : Build Ring using CMake
# Author      : Mahmoud Fayed <msfclipper@yahoo.com>

cmake_minimum_required (VERSION 2.6)
project (ring)

# Header Files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ringw.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/test.c)

# Check the Operating System
IF (WIN32)

	message("Building Ring for Windows")

	add_library(ring SHARED ${SOURCES})
	target_link_libraries (ring)

ELSE(WIN32)

	IF(NOT APPLE)
		message("Building Ring for Linux")
	ELSE(NOT APPLE)
		message("Building Ring For MacOS X")
	ENDIF(NOT APPLE)

	add_library(ring SHARED ${SOURCES})
	target_link_libraries (ring m dl)

ENDIF(WIN32)

# Create Executable 
ADD_EXECUTABLE (ringlang ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
TARGET_LINK_LIBRARIES (ringlang ring)
set_target_properties(ringlang PROPERTIES OUTPUT_NAME ring)

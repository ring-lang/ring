# Description : Build Ring using CMake
# Author      : Mahmoud Fayed <msfclipper@yahoo.com>
# Date        : 2016.08.21

cmake_minimum_required (VERSION 2.6)
project (ring)

# Header Files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")

list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ringw.c)

# Check the Operating System
IF (WIN32)

	message("Building Ring for Windows")

	# Libraries
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/LibCurl/include)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/MySQL/include)
	include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/openssl/include)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/LibCurl/lib)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/MySQL/lib)
	link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/openssl/lib)

	add_library(ring SHARED ${SOURCES})
	target_link_libraries (ring odbc32 libmysql libeay32 libcurl)

ELSE(WIN32)

	message("Building Ring for Linux or MacOS X")

	# Libraries
	include_directories(/usr/include/mysql)
	link_directories(/usr/lib/mysql/lib)

	add_library(ring SHARED ${SOURCES})
	target_link_libraries (ring m dl odbc mysqlclient ssl crypto curl)

ENDIF(WIN32)

# Create Executable 
ADD_EXECUTABLE (ringlang ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
TARGET_LINK_LIBRARIES (ringlang ring)
set_target_properties(ringlang PROPERTIES OUTPUT_NAME ring)

# Description : Build Ring using CMake
# Author      : Mahmoud Fayed <msfclipper@yahoo.com>

cmake_minimum_required(VERSION 3.5)
project(ring)

# Header Files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ringw.c)

# Check the Operating System
if(WIN32)
    message("Building Ring for Windows")
    # Create Shared Library
    add_library(ring SHARED ${SOURCES})
    target_link_libraries(ring)
    # Create Static Library
    add_library(ringstatic STATIC ${SOURCES})
    target_link_libraries(ringstatic m)
else()
    if(APPLE)
        message("Building Ring for MacOS X")
    else()
        execute_process(COMMAND lsb_release -d OUTPUT_VARIABLE LINUX_DISTRO OUTPUT_STRIP_TRAILING_WHITESPACE)
        string(REPLACE "Description:" "" DISTRO_NAME ${LINUX_DISTRO})
        string(STRIP ${DISTRO_NAME} DISTRO_NAME)
        message("Building Ring for: ${DISTRO_NAME}")
    endif()
    # Create Shared Library
    add_library(ring SHARED ${SOURCES})
    target_link_libraries(ring m dl)
    # Create Static Library
    add_library(ringstatic STATIC ${SOURCES})
    target_link_libraries(ringstatic m dl)
endif()

# Create Executable 
add_executable(ringlang ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
target_link_libraries(ringlang ring)
set_target_properties(ringlang PROPERTIES OUTPUT_NAME ring)

# Check the Operating System for installation
if(WIN32)
    install(TARGETS ringlang ring DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
    install(TARGETS ring ringstatic DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
else()
    install(TARGETS ringlang DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../bin)
    install(TARGETS ring ringstatic DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../lib)
endif()

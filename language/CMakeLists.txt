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
        # Read the contents of /etc/os-release
        file(READ "/etc/os-release" OS_RELEASE_CONTENT)
        # Extract the distro name from the content (From PRETTY_NAME)
        string(REGEX MATCH "PRETTY_NAME=\"([^\"]+)\"" MATCHED_NAME "${OS_RELEASE_CONTENT}")
        # If a match is found, extract the name
        if(MATCHED_NAME)
            string(REGEX REPLACE "PRETTY_NAME=\"([^\"]+)\"" "\\1" DISTRO_NAME "${MATCHED_NAME}")
            message(STATUS "Building Ring for: ${DISTRO_NAME}")
        else()
            message(STATUS "Building Ring for: Unknown")
        endif()
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
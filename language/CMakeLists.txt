# Description : Build Ring using CMake
# Author      : Mahmoud Fayed <msfclipper@yahoo.com>
#             : Youssef Saeed <youssefelkholey@gmail.com>

cmake_minimum_required(VERSION 3.16)
project(ring C)

# An option to build a static ring executable
option(RING_STATIC "Build a static 'ring' executable." OFF)

# An option to enable computed goto for the VM (GCC/Clang only)
option(RING_COMPUTED_GOTO "Enable computed goto VM dispatch (requires GCC or Clang)." OFF)

# Validate computed goto option
if(RING_COMPUTED_GOTO)
    if(NOT CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
        message(WARNING "RING_COMPUTED_GOTO requires GCC or Clang. Disabling.")
        set(RING_COMPUTED_GOTO OFF)
    endif()
endif()

# Header Files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ringw.c)

# Add computed goto source file if enabled
if(RING_COMPUTED_GOTO)
    list(APPEND SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/build/vmcgoto/vmcgoto.c)
endif()

# Add compile definitions for computed goto
if(RING_COMPUTED_GOTO)
    add_compile_definitions(RING_VM_COMPUTEDGOTO)
endif()

# Check the Operating System
if(WIN32)
    message("Building Ring for Windows")
    # Create Shared Library (if not building a static executable)
    if(NOT RING_STATIC)
        add_library(ring SHARED ${SOURCES})
        target_link_libraries(ring)
    endif()
    # Create Static Library
    add_library(ringstatic STATIC ${SOURCES})
else()
    if(APPLE)
        message("Building Ring for macOS")
    else()
        # Check if /etc/os-release exists before reading it
        if(EXISTS "/etc/os-release")
            # Read the contents of /etc/os-release
            file(READ "/etc/os-release" OS_RELEASE_CONTENT)
            # Extract the OS name from PRETTY_NAME field in os-release file
            string(REGEX MATCH "PRETTY_NAME=\"([^\"]+)\"" MATCHED_NAME "${OS_RELEASE_CONTENT}")
            # If a match is found, extract the name
            if(MATCHED_NAME)
                string(REGEX REPLACE "PRETTY_NAME=\"([^\"]+)\"" "\\1" OS_NAME "${MATCHED_NAME}")
                message(STATUS "Building Ring for: ${OS_NAME}")
            else()
                message(STATUS "Building Ring for: Unknown")
            endif()
        else()
            message(STATUS "Building Ring for: Unknown")
        endif()
    endif()
    # Create Shared Library (if not building a static executable)
    if(NOT RING_STATIC)
        add_library(ring SHARED ${SOURCES})
        target_link_libraries(ring PUBLIC m dl)
    endif()
    # Create Static Library
    add_library(ringstatic STATIC ${SOURCES})
    target_link_libraries(ringstatic PUBLIC m dl)
endif()

# Create Executable 
add_executable(ringlang ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
set_target_properties(ringlang PROPERTIES OUTPUT_NAME ring)

if(RING_STATIC)
    target_link_libraries(ringlang ringstatic)
    if(NOT WIN32 AND NOT APPLE)
        set_target_properties(ringlang PROPERTIES LINK_FLAGS "-static")
    endif()
else()
    target_link_libraries(ringlang ring)
endif()

# Check the Operating System for installation
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
if(RING_STATIC)
    install(TARGETS ringlang DESTINATION ${PARENT_DIR}/bin)
    install(TARGETS ringstatic DESTINATION ${PARENT_DIR}/lib)
else()
    if(WIN32)
        install(TARGETS ringlang ring DESTINATION ${PARENT_DIR}/bin)
        install(TARGETS ring ringstatic DESTINATION ${PARENT_DIR}/lib)
    else()
        install(TARGETS ringlang DESTINATION ${PARENT_DIR}/bin)
        install(TARGETS ring ringstatic DESTINATION ${PARENT_DIR}/lib)
    endif()
endif()
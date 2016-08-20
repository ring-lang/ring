cmake_minimum_required (VERSION 2.6)
project (ring)

# Header Files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")

list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ringw.c)

add_executable(ring ${SOURCES})
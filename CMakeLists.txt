cmake_minimum_required (VERSION 2.6)
project (ring)

# Header Files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")

add_executable(ring ${SOURCES})
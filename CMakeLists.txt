cmake_minimum_required (VERSION 2.6)
project (ring)

# Header Files
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.c")

list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ringw.c)

# Libraries
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/LibCurl/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/MySQL/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/openssl/include)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/LibCurl/lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/MySQL/lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libdepwin/openssl/lib)

add_library(ring SHARED ${SOURCES})

target_link_libraries (ring libcurl libmysql libeay32 odbc32)

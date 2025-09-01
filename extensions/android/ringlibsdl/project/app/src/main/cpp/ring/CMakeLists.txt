cmake_minimum_required(VERSION 3.16)
project(ring)

file(GLOB RING_SOURCES "src/*.c")
list(REMOVE_ITEM RING_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ring.c)
list(REMOVE_ITEM RING_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/ringw.c)

add_library(ring STATIC ${RING_SOURCES})

target_include_directories(ring PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

target_link_libraries(ring PUBLIC
    SDL2
    SDL2_image
    SDL2_mixer
    SDL2_net
    SDL2_ttf
    android
    log
)
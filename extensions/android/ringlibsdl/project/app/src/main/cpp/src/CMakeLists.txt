cmake_minimum_required(VERSION 3.16)

project(MY_APP)

add_library(main SHARED)

target_sources(main PRIVATE ringapp.c)

target_link_libraries(main
    ring
)



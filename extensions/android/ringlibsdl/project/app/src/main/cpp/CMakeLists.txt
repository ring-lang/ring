cmake_minimum_required(VERSION 3.16)

project(GAME)

# A workaround for issues with large file support on some Android ABIs
if((ANDROID_ABI STREQUAL "armeabi-v7a" OR ANDROID_ABI STREQUAL "x86") AND ANDROID_PLATFORM_LEVEL LESS 24)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -U_FILE_OFFSET_BITS")
endif()

# Add SDL2 and its related libraries as subdirectories
add_subdirectory(SDL)
add_subdirectory(SDL_image)
add_subdirectory(SDL_mixer)
add_subdirectory(SDL_net)
add_subdirectory(SDL_ttf)

# Add Ring as a subdirectory
add_subdirectory(ring)

# Your main app
add_subdirectory(src)
cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(ringpico)

pico_sdk_init()

include_directories(
	ring/include 
	picolib/include
)

# Add source files
file(GLOB SOURCES 
	"ring/src/*.c"
	"picolib/src/pico_e.c"
	"picolib/src/loadapp/loadapp.c"
)

list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/ring/src/ring.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/ring/src/ringw.c)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/ring/src/dll_e.c)

add_executable(${PROJECT_NAME}
        ${SOURCES}        
)

# pull in common dependencies
target_link_libraries(${PROJECT_NAME} 
	pico_stdlib 
	hardware_adc 
	hardware_i2c
	hardware_spi
	hardware_pwm
	hardware_uart
)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(${PROJECT_NAME})

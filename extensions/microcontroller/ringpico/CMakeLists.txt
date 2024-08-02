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

add_executable(ringpico
        ${SOURCES}        
)

# pull in common dependencies
target_link_libraries(ringpico pico_stdlib)

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(ringpico)

# add url via pico_set_program_url
example_auto_set_url(ringpico)

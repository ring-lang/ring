gcc -c -fpic -O2 ring_libsdl.c -I $PWD/../../language/include -I /usr/include/SDL2
gcc -shared -o $PWD/../../lib/libringsdl.so ring_libsdl.o -L $PWD/../../lib -lring `pkg-config --cflags --libs sdl2 SDL2_ttf SDL2_image SDL2_mixer SDL2_net SDL2_gfx`
[ -f ring_libsdl.o ] && rm ring_libsdl.o
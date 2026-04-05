gcc -c -fpic -O2 ring_libsdl.c -I $PWD/../../language/include $(pkg-config --cflags sdl2 SDL2_ttf SDL2_image SDL2_mixer SDL2_net)

gcc -shared -o $PWD/../../lib/libringsdl.so ring_libsdl.o -L $PWD/../../lib -lring $(pkg-config --libs sdl2 SDL2_ttf SDL2_image SDL2_mixer SDL2_net)

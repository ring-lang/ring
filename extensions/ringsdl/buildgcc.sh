gcc -c -fpic ring_libsdl.c -I $PWD/../../language/include -I /usr/include/SDL2
gcc -shared -o $PWD/../../lib/libringsdl.so ring_libsdl.o -L $PWD/../../lib -lring `pkg-config --cflags --libs sdl2`

 



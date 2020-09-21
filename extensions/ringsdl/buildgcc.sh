gcc -c -fpic ring_libsdl.c -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libringsdl.so ring_libsdl.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lsdl2 -lsdl2_image -lsdl2_mixer -lsdl2_ttf

 



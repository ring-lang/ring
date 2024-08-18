gcc -c -fpic -O2 ring_raylib.c -I $PWD/../../../language/include -I linux_raylib-5/include
gcc -shared -o $PWD/../../../lib/libringraylib.so ring_raylib.o -L $PWD/../../../lib -lring -L $PWD/linux_raylib-5/lib -lraylib

 



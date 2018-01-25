gcc -c -fpic ring_libuv.c -I $PWD/../../include
gcc -shared -o $PWD/../../lib/libring_uv.so ring_libuv.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -luv

 



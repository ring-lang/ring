gcc -c -fpic ring_stbimage.c -I $PWD/../../include
gcc -shared -o $PWD/../../lib/libring_stbimage.so ring_stbimage.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu

 



gcc -c -fpic -O2 ring_libzip.c -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libring_libzip.so ring_libzip.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu

 



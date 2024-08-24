gcc -c -fpic -O2 ring_tilengine.c -I $PWD/../../language/include -I linux_tilengine/include
gcc -shared -o $PWD/../../lib/libring_tilengine.so ring_tilengine.o -L $PWD/../../lib -lring -L $PWD/linux_tilengine/lib -ltilengine

 



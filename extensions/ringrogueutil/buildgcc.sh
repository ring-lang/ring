gcc -c -fpic -O2 ring_rogueutil.c -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libring_rogueutil.so ring_rogueutil.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu

 



gcc -c -fpic -O2 ring_regex.c -I $PWD/../../language/include 
gcc -shared -o $PWD/../../lib/libring_regex.so ring_regex.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu 

 

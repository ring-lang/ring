gcc -c -fpic -O2 ring_vmodbc.c -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libring_odbc.so ring_vmodbc.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lodbc

 



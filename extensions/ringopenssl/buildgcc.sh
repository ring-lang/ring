gcc -c -fpic -O2 ring_vmopenssl.c -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libring_openssl.so ring_vmopenssl.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lssl -lcrypto

 



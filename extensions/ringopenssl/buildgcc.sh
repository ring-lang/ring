gcc -c -fpic ring_vmopenssl.c -I $PWD/../../include
gcc -shared -o $PWD/../../lib/libring_openssl.so ring_vmopenssl.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lssl -lcrypto

 



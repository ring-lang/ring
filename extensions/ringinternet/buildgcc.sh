gcc -c -fpic ring_internet.c -I $PWD/../../include
gcc -shared -o $PWD/../../lib/libring_internet.so ring_internet.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lcurl -lssl -lcrypto

 



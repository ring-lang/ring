gcc -c -fpic ring_libcurl.c -I $PWD/../../include
gcc -shared -o $PWD/../../lib/libring_libcurl.so ring_libcurl.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lcurl -lssl -lcrypto

 



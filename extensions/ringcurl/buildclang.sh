clang -c -fpic -O2 ring_libcurl.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_libcurl.dylib ring_libcurl.o  -L $PWD/../../lib -L /usr/local/opt/openssl/lib -lring -lcurl -lssl -lcrypto

 



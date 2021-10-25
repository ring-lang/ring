clang -c -fpic -O2 ring_vmopenssl.c -I $PWD/../../language/include -I /usr/local/include -I /usr/local/opt/openssl/include
clang -dynamiclib -o $PWD/../../lib/libring_openssl.dylib ring_vmopenssl.o  -L $PWD/../../lib -L /usr/local/opt/openssl/lib -lring -lssl -lcrypto

 



clang -c -fpic ring_vmopenssl.c -I $PWD/../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_openssl.dylib ring_vmopenssl.o  -L $PWD/../../lib  -lring -lssl -lcrypto

 



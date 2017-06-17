clang -c -fpic ring_vmopenssl.c -I $PWD/../../include -I /usr/local/include -I /usr/local/opt/openssl/include
clang -dynamiclib -o $PWD/../../lib/libring_openssl.dylib ring_vmopenssl.o  -L $PWD/../../lib  -lring -lssl -lcrypto

 



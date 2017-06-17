clang -c -fpic ring_internet.c -I $PWD/../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_internet.dylib ring_internet.o  -L $PWD/../../lib  -lring -lcurl -lssl -lcrypto

 



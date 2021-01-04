clang -c -fpic -O2 ring_internet.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_internet.dylib ring_internet.o  -L $PWD/../../lib  -lring -lcurl -lssl -lcrypto

 



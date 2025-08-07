BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_internet.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_internet.dylib ring_internet.o  -L $PWD/../../lib -L $BREW_PREFIX/opt/openssl/lib  -lring -lcurl -lssl -lcrypto

 



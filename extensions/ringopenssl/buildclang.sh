BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_vmopenssl.c -I $PWD/../../language/include -I $BREW_PREFIX/include -I $BREW_PREFIX/opt/openssl/include
clang -dynamiclib -o $PWD/../../lib/libring_openssl.dylib ring_vmopenssl.o  -L $PWD/../../lib -L $BREW_PREFIX/opt/openssl/lib -lring -lssl -lcrypto

 



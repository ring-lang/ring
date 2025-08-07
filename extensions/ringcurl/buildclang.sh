BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_libcurl.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_libcurl.dylib ring_libcurl.o  -L $PWD/../../lib -L $BREW_PREFIX/opt/openssl/lib -lring -lcurl -lssl -lcrypto

 



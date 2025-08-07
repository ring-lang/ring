BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_libzip.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_libzip.dylib ring_libzip.o  -L $PWD/../../lib  -lring 

 



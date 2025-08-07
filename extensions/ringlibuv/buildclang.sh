BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_libuv.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_uv.dylib ring_libuv.o  -L $PWD/../../lib -L $BREW_PREFIX/lib  -lring -luv

 



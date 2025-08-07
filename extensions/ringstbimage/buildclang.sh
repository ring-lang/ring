BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_stbimage.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_stbimage.dylib ring_stbimage.o  -L $PWD/../../lib  -lring 

 



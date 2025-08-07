BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_rogueutil.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_rogueutil.dylib ring_rogueutil.o  -L $PWD/../../lib  -lring 

 



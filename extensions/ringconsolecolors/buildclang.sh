BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_consolecolors.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_consolecolors.dylib ring_consolecolors.o  -L $PWD/../../lib  -lring 

 



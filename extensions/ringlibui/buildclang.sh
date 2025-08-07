BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_libui.c -I $PWD/../../language/include -I $BREW_PREFIX/include -I macOS
clang -dynamiclib -o $PWD/../../lib/libring_libui.dylib ring_libui.o macOS/libui.dylib -L $PWD/../../lib  -lring 

 



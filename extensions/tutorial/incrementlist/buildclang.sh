BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 mylib.c -I $PWD/../../../language/include
clang -dynamiclib -o libmylib.dylib mylib.o  -L $PWD/../../../lib  -lring
cp libmylib.dylib $BREW_PREFIX/lib
 



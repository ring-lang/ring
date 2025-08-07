BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_vmodbc.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_odbc.dylib ring_vmodbc.o  -L $PWD/../../lib -L $BREW_PREFIX/lib -lring -lodbc 

 



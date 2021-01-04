clang -c -fpic -O2 ring_libzip.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_libzip.dylib ring_libzip.o  -L $PWD/../../lib  -lring 

 



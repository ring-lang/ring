clang -c -fpic -O2 ring_stbimage.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_stbimage.dylib ring_stbimage.o  -L $PWD/../../lib  -lring 

 



clang -c -fpic ring_stbimage.c -I $PWD/../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_stbimage.dylib ring_stbimage.o  -L $PWD/../../lib  -lring 

 



clang -c -fpic -O2 ring_libuv.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_uv.dylib ring_libuv.o  -L $PWD/../../lib  -lring -luv

 



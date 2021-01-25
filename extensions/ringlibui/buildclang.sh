clang -c -fpic -O2 ring_libui.c -I $PWD/../../language/include -I /usr/local/include -I macOS
clang -dynamiclib -o $PWD/../../lib/libring_libui.dylib ring_libui.o macOS/libui.a -L $PWD/../../lib  -lring 

 



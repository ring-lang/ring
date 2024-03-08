clang -c -fpic -O2 ring_rogueutil.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_rogueutil.dylib ring_rogueutil.o  -L $PWD/../../lib  -lring 

 



clang -c -fpic -O2 ring_vmodbc.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_odbc.dylib ring_vmodbc.o  -L $PWD/../../lib  -lring -lodbc 

 



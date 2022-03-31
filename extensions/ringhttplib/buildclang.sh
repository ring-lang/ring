clang -c -fpic -O2 ring_httplib.cpp -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_httplib.dylib ring_httplib.o -L $PWD/../../lib  -lring 

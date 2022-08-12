clang -c -fpic -O2 ring_regex.c -I $PWD/../../language/include -I /usr/local/include 
clang -dynamiclib -o $PWD/../../lib/libring_regex.dylib ring_regex.o  -L $PWD/../../lib -lring 

 



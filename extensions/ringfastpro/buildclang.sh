clang -c -fpic -O2 fastpro.c -I $PWD/../../language/include
clang -dynamiclib -o libring_fastpro.dylib fastpro.o  -L $PWD/../../lib  -lring
cp libring_fastpro.dylib /usr/local/lib
 



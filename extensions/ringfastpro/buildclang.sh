clang -c -fpic -O2 fastpro.c -I $PWD/../../language/include
clang -dynamiclib -o $PWD/../../lib/libring_fastpro.dylib fastpro.o  -L $PWD/../../lib  -lring 
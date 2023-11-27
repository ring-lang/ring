clang -c -fpic -O2 listpro.c -I $PWD/../../language/include
clang -dynamiclib -o liblistpro.dylib listpro.o  -L $PWD/../../lib  -lring
cp liblistpro.dylib /usr/local/lib
 



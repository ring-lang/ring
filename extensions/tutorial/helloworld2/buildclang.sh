clang -c -fpic mylib.c -I $PWD/../../../include
clang -dynamiclib -o libmylib.dylib mylib.o  -L $PWD/../../../lib  -lring
cp libmylib.dylib /usr/local/lib
 



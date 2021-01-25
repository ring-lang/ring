clang -c -fpic -O2 ext/sockets.c -I $PWD/../../language/include
clang -dynamiclib -o libring_sockets.dylib sockets.o  -L $PWD/../../language/lib  -lring
cp libring_sockets.dylib /usr/local/lib


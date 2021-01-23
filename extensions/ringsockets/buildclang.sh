clang -c -fpic -O2 ext/sockets.c -I $PWD/../../../include
clang -dynamiclib -o libring_sockets.dylib sockets.o  -L $PWD/../../../lib  -lring
cp libring_sockets.dylib /usr/local/lib


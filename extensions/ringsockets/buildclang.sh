clang -c -fpic -O2 ext/sockets.c -I $PWD/../../../include
clang -dynamiclib -o socketslib.dylib sockets.o  -L $PWD/../../../lib  -lring
cp socketslib.dylib /usr/local/lib


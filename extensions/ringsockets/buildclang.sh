clang -c -fpic -O2 ext/sockets.c -I $PWD/../../../include
clang -dynamiclib -o ring_sockets.dylib sockets.o  -L $PWD/../../../lib  -lring
cp ring_sockets.dylib /usr/local/lib


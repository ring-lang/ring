clang -c -fpic ext/socket.c -I $PWD/../../../include
clang -dynamiclib -o socketlib.dylib socket.o  -L $PWD/../../../lib  -lring
cp socketlib.dylib /usr/local/lib
clang -c -fpic ring_consolecolors.c -I $PWD/../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_consolecolors.dylib ring_consolecolors.o  -L $PWD/../../lib  -lring 

 



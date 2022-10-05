clang -c -fpic -O2 ext/*.c -I $PWD/ext/ -I $PWD/../../language/include
clang -dynamiclib -o $PWD/../../lib/libring_sockets.dylib *.o  -L $PWD/../../lib -lring
rm *.o
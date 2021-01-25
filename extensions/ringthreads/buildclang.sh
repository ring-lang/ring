clang -c -fpic -O2 ring_threads.c -I $PWD/../../language/include
clang -dynamiclib -o $PWD/../../lib/libring_threads.dylib ring_threads.o  -L $PWD/../../lib -lring


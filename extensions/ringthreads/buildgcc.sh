gcc -c -fpic -O2 ring_threads.c -o ring_threads.o -I ../../language/include/
gcc -shared -o $PWD/../../lib/libring_threads.so ring_threads.o -L ../../lib/ -lring
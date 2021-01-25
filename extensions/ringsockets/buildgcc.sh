gcc -c -fpic -O2 ext/sockets.c -o sockets.o -I ../../language/include/
gcc -shared -o $PWD/../../lib/libring_sockets.so sockets.o -L ../../lib/ -lring
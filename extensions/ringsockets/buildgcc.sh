gcc -c -fpic -O2 ext/*.c -I ext/ -I ../../language/include/
gcc -shared -o $PWD/../../lib/libring_sockets.so *.o -L ../../lib/ -lring
rm *.o
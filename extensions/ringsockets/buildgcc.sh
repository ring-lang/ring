gcc -c -fpic -O2 ext/sockets.c -o sockets.o -I ../../../ring/language/include/
gcc -shared -o sockets.so sockets.o -L ../../../ring/lib/ -lring
sudo cp sockets.so /usr/lib/
sudo cp sockets.so /usr/lib64/

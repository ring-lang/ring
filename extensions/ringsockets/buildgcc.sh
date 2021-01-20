gcc -c -fpic -O2 ext/sockets.c -o sockets.o -I ../../../ring/language/include/
gcc -shared -o ring_sockets.so sockets.o -L ../../../ring/lib/ -lring
sudo cp ring_sockets.so /usr/lib/
sudo cp ring_sockets.so /usr/lib64/

gcc -c -fpic -O2 ext/sockets.c -o sockets.o -I ../../language/include/
gcc -shared -o libring_sockets.so sockets.o -L ../../lib/ -lring
sudo cp libring_sockets.so /usr/lib/
sudo cp libring_sockets.so /usr/lib64/

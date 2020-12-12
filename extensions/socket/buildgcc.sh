gcc -c -fpic ext/socket.c -o socket.o -I ../../../ring/language/include/
gcc -shared -o socket.so socket.o -L ../../../ring/lib/ -lring
sudo cp socket.so /usr/lib/
sudo cp socket.so /usr/lib64/

gcc -c -fpic -O2 ring_internet.c -I $PWD/../../language/include $(pkg-config --cflags libcurl)

gcc -shared -o $PWD/../../lib/libring_internet.so ring_internet.o -L $PWD/../../lib -lring $(pkg-config --libs libcurl)

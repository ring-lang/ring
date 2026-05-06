gcc -c -fpic -O2 ring_libcurl.c -I $PWD/../../language/include $(pkg-config --cflags libcurl)

gcc -shared -o $PWD/../../lib/libring_libcurl.so ring_libcurl.o -L $PWD/../../lib -lring $(pkg-config --libs libcurl)

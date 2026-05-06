gcc -c -fpic -O2 ring_vmopenssl.c -I $PWD/../../language/include $(pkg-config --cflags openssl)

gcc -shared -o $PWD/../../lib/libring_openssl.so ring_vmopenssl.o -L $PWD/../../lib -lring $(pkg-config --libs openssl)

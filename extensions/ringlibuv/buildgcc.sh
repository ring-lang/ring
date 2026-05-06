gcc -c -fpic -O2 ring_libuv.c -I $PWD/../../language/include $(pkg-config --cflags libuv)

gcc -shared -o $PWD/../../lib/libring_uv.so ring_libuv.o -L $PWD/../../lib -lring $(pkg-config --libs libuv)

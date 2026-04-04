gcc -c -fpic -O2 ring_vmodbc.c -I $PWD/../../language/include $(pkg-config --cflags odbc)

gcc -shared -o $PWD/../../lib/libring_odbc.so ring_vmodbc.o -L $PWD/../../lib -lring $(pkg-config --libs odbc)

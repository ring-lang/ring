gcc -c -fpic -O2 ring_pgsql.c -I $PWD/../../language/include $(pkg-config --cflags libpq)

gcc -shared -o $PWD/../../lib/libring_pgsql.so ring_pgsql.o -L $PWD/../../lib -lring $(pkg-config --libs libpq)

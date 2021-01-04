gcc -c -fpic -O2 ring_pgsql.c -I $PWD/../../language/include -I /usr/include/postgresql
gcc -shared -o $PWD/../../lib/libring_pgsql.so ring_pgsql.o -L $PWD/../../lib -lring -L /usr/local/pgsql/lib -lpq 

 



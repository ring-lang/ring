clang -c -fpic -O2 ring_pgsql.c -I $PWD/../../language/include -I /usr/local/include -I /usr/local/opt/libpq/include
clang -dynamiclib -o $PWD/../../lib/libring_pgsql.dylib ring_pgsql.o -L $PWD/../../lib  -lring  -L /usr/local/opt/libpq/lib  -lpq

 



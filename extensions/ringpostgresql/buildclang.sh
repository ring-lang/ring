clang -c -fpic ring_pgsql.c -I $PWD/../../include -I /usr/local/include -I /usr/local/opt/libpq/include
clang -dynamiclib -o $PWD/../../lib/libring_pgsql.dylib ring_pgsql.o -L $PWD/../../lib  -lring  -L /usr/local/opt/libpq/lib  -lpq

 



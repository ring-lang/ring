BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_pgsql.c -I $PWD/../../language/include -I $BREW_PREFIX/include -I $BREW_PREFIX/opt/libpq/include
clang -dynamiclib -o $PWD/../../lib/libring_pgsql.dylib ring_pgsql.o -L $PWD/../../lib  -lring  -L $BREW_PREFIX/opt/libpq/lib  -lpq

 



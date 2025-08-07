BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_vmsqlite.c sqlite3.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_sqlite.dylib ring_vmsqlite.o sqlite3.o -L $PWD/../../lib  -lring 
 



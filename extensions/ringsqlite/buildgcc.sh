gcc -c -fpic -O2 ring_vmsqlite.c sqlite3.c -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libring_sqlite.so ring_vmsqlite.o sqlite3.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -pthread

 



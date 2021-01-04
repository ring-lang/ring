clang -c -fpic -O2 ring_vmmysql.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_mysql.dylib ring_vmmysql.o  -L $PWD/../../lib  -lring -lmysqlclient

 



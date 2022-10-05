clang -c -fpic -O2 ring_vmmysql.c -I $PWD/../../language/include -I /usr/local/include -I /usr/local/opt/mysql-client/include/mysql
clang -dynamiclib -o $PWD/../../lib/libring_mysql.dylib ring_vmmysql.o  -L $PWD/../../lib -L /usr/local/opt/mysql-client/lib -lring -lmysqlclient

 



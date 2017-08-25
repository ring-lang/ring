gcc -c -fpic ring_vmmysql.c -I $PWD/../../include -I /usr/include/mysql 
gcc -shared -o $PWD/../../lib/libring_mysql.so ring_vmmysql.o -L $PWD/../../lib -lring -L /usr/lib/mysql -lmysqlclient

 



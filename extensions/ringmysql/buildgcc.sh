gcc -c -fpic -O2 ring_vmmysql.c -I $PWD/../../language/include -I /usr/include/mysql 
gcc -shared -o $PWD/../../lib/libring_mysql.so ring_vmmysql.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -L /usr/lib/mysql/lib -lmysqlclient

 



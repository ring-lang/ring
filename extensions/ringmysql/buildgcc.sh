gcc -c -fpic -O2 ring_vmmysql.c -I $PWD/../../language/include $(pkg-config --cflags mysqlclient)

gcc -shared -o $PWD/../../lib/libring_mysql.so ring_vmmysql.o -L $PWD/../../lib -lring $(pkg-config --libs mysqlclient)

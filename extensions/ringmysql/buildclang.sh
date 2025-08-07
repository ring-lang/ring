BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_vmmysql.c -I $PWD/../../language/include -I $BREW_PREFIX/include -I $BREW_PREFIX/opt/mysql-client/include/mysql
clang -dynamiclib -o $PWD/../../lib/libring_mysql.dylib ring_vmmysql.o  -L $PWD/../../lib -L $BREW_PREFIX/opt/mysql-client/lib -lring -lmysqlclient

 



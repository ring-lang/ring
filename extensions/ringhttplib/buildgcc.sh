g++ -c -fpic -O2 ring_httplib.cpp -I $PWD/../../language/include
g++ -shared -o $PWD/../../lib/libring_httplib.so ring_httplib.o -L $PWD/../../lib -lring -lpthread

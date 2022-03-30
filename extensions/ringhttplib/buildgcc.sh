gcc -c -fpic -O2 ring_httplib.cpp -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libring_httplib.so ring_httplib.o -L $PWD/../../lib -lring

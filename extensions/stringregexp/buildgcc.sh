gcc -c -fpic -O2 stringregexp.c  -I $PWD/../../language/include   
gcc -shared -o libstringregexp.so stringregexp.o -L $PWD/../../../lib -lring  -lpcre
sudo cp libstringregexp.so /usr/lib
sudo cp libstringregexp.so /usr/lib64

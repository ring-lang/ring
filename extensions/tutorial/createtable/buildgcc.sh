gcc -c -fpic -O2 mylib.c -I $PWD/../../../language/include 
gcc -shared -o libmylib.so mylib.o -L $PWD/../../../lib -lring
sudo cp libmylib.so /usr/lib
sudo cp libmylib.so /usr/lib64

 



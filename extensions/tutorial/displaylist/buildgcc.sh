gcc -c -fpic mylib.c -I $PWD/../../../include 
gcc -shared -o libmylib.so mylib.o -L $PWD/../../../lib -lring
sudo cp libmylib.so /usr/lib
sudo cp libmylib.so /usr/lib64

 



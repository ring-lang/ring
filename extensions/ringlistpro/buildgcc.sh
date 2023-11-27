gcc -c -fpic -O2 listpro.c -I $PWD/../../language/include 
gcc -shared -o liblistpro.so listpro.o -L $PWD/../../lib -lring
sudo cp liblistpro.so /usr/lib
sudo cp liblistpro.so /usr/lib64

 



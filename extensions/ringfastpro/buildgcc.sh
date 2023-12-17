gcc -c -fpic -O2 fastpro.c -I $PWD/../../language/include 
gcc -shared -o libring_fastpro.so fastpro.o -L $PWD/../../lib -lring
sudo cp libring_fastpro.so /usr/lib
sudo cp libring_fastpro.so /usr/lib64

 



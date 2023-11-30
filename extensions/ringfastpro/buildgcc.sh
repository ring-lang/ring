gcc -c -fpic -O2 fastpro.c -I $PWD/../../language/include 
gcc -shared -o libring_fastpro.so fastpro.o -L $PWD/../../lib -lring
sudo cp libfastpro.so /usr/lib
sudo cp libfastpro.so /usr/lib64

 



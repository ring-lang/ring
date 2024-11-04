gcc -c -fpic -O2 fastpro.c -I $PWD/../../language/include 
gcc -shared -o $PWD/../../lib/libring_fastpro.so fastpro.o -L $PWD/../../lib -lring


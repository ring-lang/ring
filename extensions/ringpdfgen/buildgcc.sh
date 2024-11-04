gcc -c -fpic -O2 ring_pdfgen.c -I $PWD/../../language/include 
gcc -shared -o $PWD/../../lib/libring_pdfgen.so ring_pdfgen.o -L $PWD/../../lib -lring
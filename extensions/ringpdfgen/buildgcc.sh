gcc -c -fpic -O2 ring_pdfgen.c -I $PWD/../../language/include 
gcc -shared -o libring_pdfgen.so ring_pdfgen.o -L $PWD/../../lib -lring
sudo cp libring_pdfgen.so /usr/lib
sudo cp libring_pdfgen.so /usr/lib64

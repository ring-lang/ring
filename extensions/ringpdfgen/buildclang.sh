clang -c -fpic -O2 ring_pdfgen.c -I $PWD/../../language/include
clang -dynamiclib -o libring_pdfgen.dylib ring_pdfgen.o  -L $PWD/../../lib  -lring
cp libring_pdfgen.dylib /usr/local/lib

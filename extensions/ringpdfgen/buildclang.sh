clang -c -fpic -O2 ring_pdfgen.c -I $PWD/../../language/include
clang -dynamiclib -o $PWD/../../lib/libring_pdfgen.dylib ring_pdfgen.o  -L $PWD/../../lib  -lring
gcc -c -fpic ring_consolecolors.c -I $PWD/../../include
gcc -shared -o $PWD/../../lib/libring_consolecolors.so ring_consolecolors.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu

 



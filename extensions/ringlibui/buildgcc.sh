gcc -c -fpic -O2 ring_libui.c -I $PWD/../../../language/include -I linux
gcc -shared -o $PWD/../../../lib/libring_libui.so ring_libui.o -L $PWD/../../../lib -lring -L $PWD/linux -llibui

 



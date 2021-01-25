gcc -c -fpic -O2 ring_libui.c -I $PWD/../../language/include -I macOS
gcc -shared -o $PWD/../../lib/libring_libui.dylib ring_libui.o -L $PWD/../../lib -lring -L $PWD/macOS -llibui

 



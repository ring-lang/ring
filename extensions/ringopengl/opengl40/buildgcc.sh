gcc -c -fpic -O2 ring_opengl40.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl40.so ring_opengl40.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lGL -lGLU -lglut

 



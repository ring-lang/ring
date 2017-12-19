gcc -c -fpic ring_opengl13.c -I $PWD/../../../include
gcc -shared -o $PWD/../../../lib/libring_opengl13.so ring_opengl13.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lGL -lGLU -lglut

 



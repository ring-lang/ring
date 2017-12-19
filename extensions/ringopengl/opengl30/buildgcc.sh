gcc -c -fpic ring_opengl30.c -I $PWD/../../../include
gcc -shared -o $PWD/../../../lib/libring_opengl30.so ring_opengl30.o -L $PWD/../../lib -lring -L /usr/lib/i386-linux-gnu -lGL -lGLU -lglut

 



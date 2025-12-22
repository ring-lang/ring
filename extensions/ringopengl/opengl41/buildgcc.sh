gcc -c -fpic -O2 ring_opengl41.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl41.so ring_opengl41.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl41.o

 



gcc -c -fpic -O2 ring_opengl45.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl45.so ring_opengl45.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl45.o

 



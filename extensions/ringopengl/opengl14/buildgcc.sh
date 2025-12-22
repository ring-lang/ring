gcc -c -fpic -O2 ring_opengl14.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl14.so ring_opengl14.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl14.o

 



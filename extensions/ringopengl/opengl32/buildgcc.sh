gcc -c -fpic -O2 ring_opengl32.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl32.so ring_opengl32.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl32.o

 



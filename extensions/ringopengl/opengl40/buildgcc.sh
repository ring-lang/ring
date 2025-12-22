gcc -c -fpic -O2 ring_opengl40.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl40.so ring_opengl40.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl40.o

 



gcc -c -fpic -O2 ring_opengl30.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl30.so ring_opengl30.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl30.o

 



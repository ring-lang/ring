gcc -c -fpic -O2 ring_opengl11.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl11.so ring_opengl11.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl11.o

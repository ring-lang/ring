gcc -c -fpic -O2 ring_opengl20.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl20.so ring_opengl20.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl20.o

 



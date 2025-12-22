gcc -c -fpic -O2 ring_opengl42.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl42.so ring_opengl42.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl42.o

 



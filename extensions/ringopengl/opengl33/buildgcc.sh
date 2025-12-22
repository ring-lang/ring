gcc -c -fpic -O2 ring_opengl33.c -I $PWD/../../../language/include
gcc -shared -o $PWD/../../../lib/libring_opengl33.so ring_opengl33.o -L $PWD/../../lib -lring -lGL -lGLU -lglut -lGLEW
rm -f ring_opengl33.o

 



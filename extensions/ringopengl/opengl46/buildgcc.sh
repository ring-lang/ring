gcc -c -fpic -O2 ring_opengl46.c -I $PWD/../../../language/include $(pkg-config --cflags gl glu glut glew)

gcc -shared -o $PWD/../../../lib/libring_opengl46.so ring_opengl46.o -L $PWD/../../../lib -lring $(pkg-config --libs gl glu glut glew)

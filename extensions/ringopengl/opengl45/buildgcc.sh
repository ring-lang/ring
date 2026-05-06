gcc -c -fpic -O2 ring_opengl45.c -I $PWD/../../../language/include $(pkg-config --cflags gl glu glut glew)

gcc -shared -o $PWD/../../../lib/libring_opengl45.so ring_opengl45.o -L $PWD/../../../lib -lring $(pkg-config --libs gl glu glut glew)

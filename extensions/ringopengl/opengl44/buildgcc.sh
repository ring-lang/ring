gcc -c -fpic -O2 ring_opengl44.c -I $PWD/../../../language/include $(pkg-config --cflags gl glu glut glew)

gcc -shared -o $PWD/../../../lib/libring_opengl44.so ring_opengl44.o -L $PWD/../../../lib -lring $(pkg-config --libs gl glu glut glew)

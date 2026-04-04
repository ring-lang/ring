gcc -c -fpic -O2 ring_opengl31.c -I $PWD/../../../language/include $(pkg-config --cflags gl glu glut glew)

gcc -shared -o $PWD/../../../lib/libring_opengl31.so ring_opengl31.o -L $PWD/../../../lib -lring $(pkg-config --libs gl glu glut glew)

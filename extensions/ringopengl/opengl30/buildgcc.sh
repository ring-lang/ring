gcc -c -fpic -O2 ring_opengl30.c -I $PWD/../../../language/include $(pkg-config --cflags gl glu glut glew)

gcc -shared -o $PWD/../../../lib/libring_opengl30.so ring_opengl30.o -L $PWD/../../../lib -lring $(pkg-config --libs gl glu glut glew)

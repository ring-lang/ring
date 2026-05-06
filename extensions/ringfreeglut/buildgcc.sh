gcc -c -fpic -O2 ring_freeglut.c -I $PWD/../../language/include $(pkg-config --cflags gl glu glut)

gcc -shared -o $PWD/../../lib/libring_freeglut.so ring_freeglut.o -L $PWD/../../lib -lring $(pkg-config --libs gl glu glut)

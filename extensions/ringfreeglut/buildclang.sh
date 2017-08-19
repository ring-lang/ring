clang -c -fpic ring_freeglut.c -I $PWD/../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_freeglut.dylib ring_freeglut.o -framework OpenGL -framework GLUT -L $PWD/../../lib  -lring 

 



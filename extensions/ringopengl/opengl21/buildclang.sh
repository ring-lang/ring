clang -c -fpic -O2 ring_opengl21.c -I $PWD/../../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl21.dylib ring_opengl21.o /usr/local/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



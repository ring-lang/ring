clang -c -fpic -O2 ring_opengl41.c -I $PWD/../../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl41.dylib ring_opengl41.o /usr/local/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



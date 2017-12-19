clang -c -fpic ring_opengl11.c -I $PWD/../../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl11.dylib ring_opengl11.o /usr/local/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



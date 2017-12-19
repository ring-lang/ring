clang -c -fpic ring_opengl12.c -I $PWD/../../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl12.dylib ring_opengl12.o /usr/local/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



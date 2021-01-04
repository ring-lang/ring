clang -c -fpic -O2 ring_opengl40.c -I $PWD/../../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl40.dylib ring_opengl40.o /usr/local/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



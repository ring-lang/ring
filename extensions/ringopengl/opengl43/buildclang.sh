clang -c -fpic -O2 ring_opengl43.c -I $PWD/../../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl43.dylib ring_opengl43.o /usr/local/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



clang -c -fpic -O2 ring_opengl31.c -I $PWD/../../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl31.dylib ring_opengl31.o /usr/local/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



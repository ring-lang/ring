BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_opengl30.c -I $PWD/../../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl30.dylib ring_opengl30.o $BREW_PREFIX/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



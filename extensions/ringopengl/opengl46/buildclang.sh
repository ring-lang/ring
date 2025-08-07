BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_opengl46.c -I $PWD/../../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl46.dylib ring_opengl46.o $BREW_PREFIX/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



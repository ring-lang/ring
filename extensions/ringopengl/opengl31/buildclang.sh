BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_opengl31.c -I $PWD/../../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl31.dylib ring_opengl31.o $BREW_PREFIX/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_opengl20.c -I $PWD/../../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../../lib/libring_opengl20.dylib ring_opengl20.o $BREW_PREFIX/lib/libglew.dylib -framework OpenGL -framework GLUT -L $PWD/../../../lib  -lring 

 



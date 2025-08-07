BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_freeglut.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libring_freeglut.dylib ring_freeglut.o -framework OpenGL -framework GLUT -L $PWD/../../lib  -lring 

 



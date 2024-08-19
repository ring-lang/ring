gcc -c -fpic -O2 ring_raylib.c -I $PWD/../../../language/include -I macOS_raylib-5/include
gcc -shared -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL -o $PWD/../../../lib/libringraylib.dylib ring_raylib.o -L $PWD/../../../lib -lring -L $PWD/macOS_raylib-5/lib -lraylib

 



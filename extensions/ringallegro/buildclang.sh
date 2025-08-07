BREW_PREFIX=$(brew --prefix)

clang -c -fpic -O2 ring_allegro.c -I $PWD/../../language/include -I $BREW_PREFIX/include
clang -dynamiclib -o $PWD/../../lib/libringallegro.dylib ring_allegro.o $BREW_PREFIX/lib/liballegro.dylib $BREW_PREFIX/lib/liballegro_image.dylib $BREW_PREFIX/lib/liballegro_dialog.dylib $BREW_PREFIX/lib/liballegro_ttf.dylib $BREW_PREFIX/lib/liballegro_acodec.dylib $BREW_PREFIX/lib/liballegro_audio.dylib $BREW_PREFIX/lib/liballegro_font.dylib $BREW_PREFIX/lib/liballegro_primitives.dylib $BREW_PREFIX/lib/liballegro_color.dylib $BREW_PREFIX/lib/liballegro_physfs.dylib $BREW_PREFIX/lib/liballegro_memfile.dylib -L $PWD/../../lib  -lring 

 



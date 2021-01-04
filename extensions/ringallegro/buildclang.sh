clang -c -fpic -O2 ring_allegro.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libringallegro.dylib ring_allegro.o /usr/local/lib/liballegro.dylib /usr/local/lib/liballegro_image.dylib /usr/local/lib/liballegro_dialog.dylib /usr/local/lib/liballegro_ttf.dylib /usr/local/lib/liballegro_acodec.dylib /usr/local/lib/liballegro_audio.dylib /usr/local/lib/liballegro_font.dylib /usr/local/lib/liballegro_primitives.dylib /usr/local/lib/liballegro_color.dylib /usr/local/lib/liballegro_physfs.dylib /usr/local/lib/liballegro_memfile.dylib -L $PWD/../../lib  -lring 

 



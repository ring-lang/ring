gcc -c -fpic -O2 ring_allegro.c -I $PWD/../../language/include $(pkg-config --cflags allegro-5 allegro_image-5 allegro_dialog-5 allegro_ttf-5 allegro_acodec-5 allegro_primitives-5)

gcc -shared -o $PWD/../../lib/libringallegro.so ring_allegro.o -L $PWD/../../lib -lring $(pkg-config --libs allegro-5 allegro_image-5 allegro_dialog-5 allegro_ttf-5 allegro_acodec-5 allegro_primitives-5)

# TODO : convert into autotools

mkdir lib/

clang -c -fpic ring_murmurhash.c libmurmurhash/MurmurHash1.c \
    libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c \
    -g -Wall -O3 -I $PWD/../../include -I libmurmurhash/

clang -dynamiclib -o lib/libring_murmurhash.dylib *.o

rm *.o

cp lib/libring_murmurhash.dylib /usr/local/lib/ring/libring_murmurhash.dylib

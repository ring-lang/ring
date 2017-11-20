# TODO : convert into autotools

mkdir lib/

gcc -c -fpic ring_murmurhash.c libmurmurhash/MurmurHash1.c \
    libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c \
    -g -Wall -I $PWD/../../include -I. -O3

gcc --shared -o lib/libringmurmurhash.so *.o

rm *.o

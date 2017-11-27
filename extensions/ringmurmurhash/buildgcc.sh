# TODO : convert into autotools

mkdir lib/

gcc -c -fpic ring_murmurhash.c libmurmurhash/MurmurHash1.c \
    libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c \
    -g -Wall -O3 -I $PWD/../../include -I libmurmurhash/

gcc --shared -o lib/libringmurmurhash.so *.o

rm *.o

cp lib/libringmurmurhash.so /usr/local/lib/ring/libring_murmurhash.so

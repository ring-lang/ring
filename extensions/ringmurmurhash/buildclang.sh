clang -c -fpic ring_murmurhash.c libmurmurhash/MurmurHash1.c libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c -I $PWD/../../include -I $PWD/libmurmurhash/
clang -dynamiclib -o $PWD/../../lib/libring_murmurhash.dylib *.o
rm *.o



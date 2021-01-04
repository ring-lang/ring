#clang -c -fpic -O2 ring_murmurhash.c libmurmurhash/MurmurHash1.c libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c -I $PWD/../../language/include -I $PWD/libmurmurhash/
#clang -dynamiclib -o $PWD/../../lib/libring_murmurhash.dylib *.o -L $PWD/../../lib  -lring 
#rm *.o

echo "We will use gcc instead of clang"

gcc -c -fpic -O2 ring_murmurhash.c libmurmurhash/MurmurHash1.c \
    libmurmurhash/MurmurHash2.c libmurmurhash/MurmurHash3.c \
    -g -Wall -O3 -I $PWD/../../language/include -I libmurmurhash/

gcc -shared -o $PWD/../../lib/libring_murmurhash.dylib *.o -L $PWD/../../lib -lring

rm *.o
clang -c -fpic ring_libcurl.c -I $PWD/../../include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_libcurl.dylib ring_libcurl.o  -L $PWD/../../lib  -lring -lcurl -lssl -lcrypto

 



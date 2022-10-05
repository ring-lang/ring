clang -c -fpic -O2 ring_cjson.c lib/cJSON.c lib/cJSON_Utils.c -I $PWD/../../language/include -I /usr/local/include
clang -dynamiclib -o $PWD/../../lib/libring_cjson.dylib ring_cjson.o cJSON.o cJSON_Utils.o -L $PWD/../../lib  -lring 

 



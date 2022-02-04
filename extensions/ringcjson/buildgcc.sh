gcc -c -fpic -O2 ring_cjson.c lib/cJSON.c lib/cJSON_Utils.c -I $PWD/../../language/include
gcc -shared -o $PWD/../../lib/libring_cjson.so ring_cjson.o cJSON.o cJSON_Utils.o  -L $PWD/../../lib -lring

 



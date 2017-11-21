
#include "ring_murmurhash.h"


RING_API void ringlib_init(RingState *pRingState)
{
    ring_vm_funcregister("murmurhash1", ring_murmurhash1);
    ring_vm_funcregister("murmurhash1_aligned", ring_murmurhash1_aligned);
}

#define LONG2HEX(dest, val) sprintf(dest, "%x", val)

#define MH_RETURN(ret_val, ret_type) { \
    if (ret_type) { \
        char tmp[50]; \
        LONG2HEX(tmp, ret_val); \
        RING_API_RETSTRING(tmp); \
    } else { \
        RING_API_RETNUMBER(ret_val); \
    } \
}


void ring_murmurhash1(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint32_t out;

    if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash1 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash1 expects the first parameter to be an integer");
        return;
    }

    key = RING_API_GETSTRING(1);
    keylen = strlen(key);
    seed = RING_API_GETNUMBER(2);

    out = MurmurHash1(key, keylen, seed);

    MH_RETURN(out, 0);
    return;
}

void ring_murmurhash1_aligned(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint32_t out;

    if (RING_API_PARACOUNT != 2) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash1 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash1 expects the first parameter to be an integer");
        return;
    }

    key = RING_API_GETSTRING(1);
    keylen = strlen(key);
    seed = RING_API_GETNUMBER(2);

    out = MurmurHash1Aligned(key, keylen, seed);

    MH_RETURN(out, 0);
    return;
}

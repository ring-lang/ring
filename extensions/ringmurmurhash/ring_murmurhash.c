
#include "ring_murmurhash.h"


RING_API void ringlib_init(RingState *pRingState)
{
    ring_vm_funcregister("murmurhash1", ring_murmurhash1);
    ring_vm_funcregister("murmurhash1_aligned", ring_murmurhash1_aligned);
}

int is_bool(int tmp)
{
    if (
        tmp == 1 ||
        tmp == 0
    ) {
        return 1;
    } else {
        return 0;
    }
}

#define LONG2HEX(dest, val) sprintf(dest, "%x", val)

#define MH_RETURN(ret_val, ret_type) { \
    if (ret_type) { \
        char tmp[50]; \
        LONG2HEX(tmp, ret_val); \
        RING_API_RETSTRING(tmp); return; \
    } else { \
        RING_API_RETNUMBER(ret_val); return; \
    } \
}


void ring_murmurhash1(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint32_t out;
    int ret_type = 0;

    if (RING_API_PARACOUNT < 2 || RING_API_PARACOUNT > 3) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash1 expects the first parameter to be a string\n");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash1 expects the first parameter to be an integer\n");
        return;
    }

    key = RING_API_GETSTRING(1);
    keylen = strlen(key);
    seed = RING_API_GETNUMBER(2);

    if (RING_API_PARACOUNT == 3) {
        if (RING_API_ISNUMBER(3)) {
            ret_type = RING_API_GETNUMBER(3);
            if (!is_bool(ret_type)) {
                RING_API_ERROR("Third parameter should be boolean value\n");
            }
        } else {
            RING_API_ERROR("murmurhash1 expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHash1(key, keylen, seed);

    MH_RETURN(out, ret_type);
}

void ring_murmurhash1_aligned(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint32_t out;
    int ret_type = 0;

    if (RING_API_PARACOUNT < 2 || RING_API_PARACOUNT > 3) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash1_aligned expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash1_aligned expects the first parameter to be an integer");
        return;
    }

    key = RING_API_GETSTRING(1);
    keylen = strlen(key);
    seed = RING_API_GETNUMBER(2);

    if (RING_API_PARACOUNT == 3) {
        if (RING_API_ISNUMBER(3)) {
            ret_type = RING_API_GETNUMBER(3);
            if (!is_bool(ret_type)) {
                RING_API_ERROR("Third parameter should be boolean value\n");
            }
        } else {
            RING_API_ERROR("murmurhash1_aligned expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHash1Aligned(key, keylen, seed);

    MH_RETURN(out, ret_type);
}


#include "ring_murmurhash.h"


RING_API void ringlib_init(RingState *pRingState)
{
    /* MurmurHash1 functions */
    ring_vm_funcregister("murmurhash1", ring_murmurhash1);
    ring_vm_funcregister("murmurhash1_aligned", ring_murmurhash1_aligned);

    /* MurmurHash2 functions */
    ring_vm_funcregister("murmurhash2", ring_murmurhash2);
    ring_vm_funcregister("murmurhash2a", ring_murmurhash2a);
    ring_vm_funcregister("murmurhash64a", ring_murmurhash64a);
    ring_vm_funcregister("murmurhash64b", ring_murmurhash64b);
    ring_vm_funcregister("murmurhash_neutral2", ring_murmurhash_neutral2);
    ring_vm_funcregister("murmurhash_aligned2", ring_murmurhash_aligned2);
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

#define INT2HEX(dest, val) sprintf(dest, "%x", val)

#define LONG2HEX(dest, val) sprintf(dest, "%lx", val)

#define MH_RETURN_INT(ret_val, ret_type) { \
    if (ret_type) { \
        char tmp[50]; \
        INT2HEX(tmp, ret_val); \
        RING_API_RETSTRING(tmp); return; \
    } else { \
        RING_API_RETNUMBER(ret_val); return; \
    } \
}

#define MH_RETURN_LONG(ret_val, ret_type) { \
    if (ret_type) { \
        char tmp[50]; \
        LONG2HEX(tmp, ret_val); \
        RING_API_RETSTRING(tmp); return; \
    } else { \
        RING_API_RETNUMBER(ret_val); return; \
    } \
}

/* MurmurHash1 functions */
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

    MH_RETURN_INT(out, ret_type);
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

    MH_RETURN_INT(out, ret_type);
}

/* MurmurHash2 functions */
void ring_murmurhash2(void *pPointer)
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
        RING_API_ERROR("murmurhash2 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash2 expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash2 expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHash2(key, keylen, seed);

    MH_RETURN_INT(out, ret_type);
}

void ring_murmurhash2a(void *pPointer)
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
        RING_API_ERROR("murmurhash2a expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash2a expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash2a expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHash2A(key, keylen, seed);

    MH_RETURN_INT(out, ret_type);
}

void ring_murmurhash64a(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint64_t out;
    int ret_type = 0;

    if (RING_API_PARACOUNT < 2 || RING_API_PARACOUNT > 3) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash64a expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash64a expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash64a expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHash64A(key, keylen, seed);

    MH_RETURN_LONG(out, ret_type);
}

void ring_murmurhash64b(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint64_t out;
    int ret_type = 0;

    if (RING_API_PARACOUNT < 2 || RING_API_PARACOUNT > 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash64b expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash64b expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash64b expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHash64B(key, keylen, seed);

    MH_RETURN_LONG(out, ret_type);
}

void ring_murmurhash_neutral2(void *pPointer)
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
        RING_API_ERROR("murmurhash_neutral2 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash_neutral2 expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash_neutral2 expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHashNeutral2(key, keylen, seed);

    MH_RETURN_INT(out, ret_type);
}

void ring_murmurhash_aligned2(void *pPointer)
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
        RING_API_ERROR("murmurhash_aligned2 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash_aligned2 expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash_aligned2 expects the third parameter to be an integer\n");
        }
    }

    out = MurmurHashAligned2(key, keylen, seed);

    MH_RETURN_INT(out, ret_type);
}

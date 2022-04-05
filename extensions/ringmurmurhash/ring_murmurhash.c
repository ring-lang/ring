
#include "ring_murmurhash.h"


RING_API void ringlib_init(RingState *pRingState)
{
    /* MurmurHash1 functions */
    RING_API_REGISTER("murmurhash1", ring_murmurhash1);
    RING_API_REGISTER("murmurhash1_aligned", ring_murmurhash1_aligned);

    /* MurmurHash2 functions */
    RING_API_REGISTER("murmurhash2", ring_murmurhash2);
    RING_API_REGISTER("murmurhash2a", ring_murmurhash2a);
    RING_API_REGISTER("murmurhash64a", ring_murmurhash64a);
    RING_API_REGISTER("murmurhash64b", ring_murmurhash64b);
    RING_API_REGISTER("murmurhash_neutral2", ring_murmurhash_neutral2);
    RING_API_REGISTER("murmurhash_aligned2", ring_murmurhash_aligned2);

    /* MurmurHash3 functions */
    RING_API_REGISTER("murmurhash3_x86_32", ring_murmurhash3_x86_32);
    RING_API_REGISTER("murmurhash3_x86_128", ring_murmurhash3_x86_128);
    RING_API_REGISTER("murmurhash3_x64_128", ring_murmurhash3_x64_128);
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

/* MurmurHash3 functions */
void ring_murmurhash3_x86_32(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint32_t out[1];
    int ret_type = 0;

    if (RING_API_PARACOUNT < 2 || RING_API_PARACOUNT > 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash3_x86_32 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash3_x86_32 expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash3_x86_32 expects the third parameter to be an integer\n");
        }
    }

    MurmurHash3_x86_32(key, keylen, seed, out);

    MH_RETURN_INT(out[0], ret_type);
}


void ring_murmurhash3_x86_128(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint32_t out[4];
    int ret_type = 0;

    List *tmp_list, *ret_val;

    if (RING_API_PARACOUNT < 2 || RING_API_PARACOUNT > 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash3_x86_128 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash3_x86_128 expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash3_x86_128 expects the third parameter to be an integer\n");
        }
    }

    MurmurHash3_x86_128(key, keylen, seed, out);

    ret_val = RING_API_NEWLIST;
    tmp_list = ring_list_newlist_gc(((VM *)pPointer)->pRingState, ret_val);

    for (int i = 0; i < 4; i++) {
        if (ret_type) {
            char tmp[50];
            INT2HEX(tmp, out[i]);
            ring_list_addstring2(tmp_list, (char*) tmp, strlen((char *) tmp));
        } else {
            ring_list_addint(tmp_list, out[i]);
        }
    }

    RING_API_RETLIST(ret_val);
}

void ring_murmurhash3_x64_128(void *pPointer)
{
    char *key = NULL;
    int keylen;
    int seed = 0;
    uint64_t out[2];
    int ret_type = 0;

    List *tmp_list, *ret_val;

    if (RING_API_PARACOUNT < 2 || RING_API_PARACOUNT > 3) {
        RING_API_ERROR(RING_API_MISS2PARA);
        return ;
    }

    if (!RING_API_ISSTRING(1)) {
        RING_API_ERROR("murmurhash3_x64_128 expects the first parameter to be a string");
        return;
    }

    if (!RING_API_ISNUMBER(2)) {
        RING_API_ERROR("murmurhash3_x64_128 expects the first parameter to be an integer");
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
            RING_API_ERROR("murmurhash3_x64_128 expects the third parameter to be an integer\n");
        }
    }

    MurmurHash3_x64_128(key, keylen, seed, out);

    ret_val = RING_API_NEWLIST;
    tmp_list = ring_list_newlist_gc(((VM *)pPointer)->pRingState, ret_val);

    for (int i = 0; i < 2; i++) {
        if (ret_type) {
            char tmp[50];
            LONG2HEX(tmp, out[i]);
            ring_list_addstring2(tmp_list, (char*) tmp, strlen((char *) tmp));
        } else {
            ring_list_addint(tmp_list, out[i]);
        }
    }

    RING_API_RETLIST(ret_val);
}


#include "ring.h"

#include "MurmurHash1.h"
#include "MurmurHash2.h"
#include "MurmurHash3.h"

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

#define LONG2HEX(dest, val) sprintf(dest , RING_UNSIGNEDLONGLONG_FORMAT , (RING_UNSIGNEDLONGLONG) val)

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
void ring_murmurhash1(void *pPointer);
void ring_murmurhash1_aligned(void *pPointer);

/* MurmurHash2 functions */
void ring_murmurhash2(void *pPointer);
void ring_murmurhash2a(void *pPointer);
void ring_murmurhash64a(void *pPointer);
void ring_murmurhash64b(void *pPointer);
void ring_murmurhash_neutral2(void *pPointer);
void ring_murmurhash_aligned2(void *pPointer);

/* MurmurHash3 functions */
void ring_murmurhash3_x86_32(void *pPointer);
void ring_murmurhash3_x86_128(void *pPointer);
void ring_murmurhash3_x64_128(void *pPointer);

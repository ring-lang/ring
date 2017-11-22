
#include "ring.h"

#include "MurmurHash1.h"
#include "MurmurHash2.h"
#include "MurmurHash3.h"

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

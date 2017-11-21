
#include "ring.h"

#include "MurmurHash1.h"
#include "MurmurHash2.h"
#include "MurmurHash3.h"

/* Murmur Hash 1 functions */
void ring_murmurhash1(void *pPointer);
void ring_murmurhash1_aligned(void *pPointer);

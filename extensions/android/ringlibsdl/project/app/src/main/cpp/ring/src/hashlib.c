/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API unsigned ring_hashlib_xorhash(unsigned char *cKey, int nLen) {
	unsigned char *cData = cKey;
	unsigned nHash = 0;
	int i;
	for (i = 0; i < nLen; i++) {
		nHash ^= cData[i];
	}
	return nHash;
}
/* See: https://en.wikipedia.org/wiki/MurmurHash */

RING_API unsigned int ring_hashlib_murmurthree32(const char *cKey, unsigned int nLen, unsigned int nSeed) {
	static const unsigned int c1 = 0xcc9e2d51;
	static const unsigned int c2 = 0x1b873593;
	static const unsigned int r1 = 15;
	static const unsigned int r2 = 13;
	static const unsigned int m = 5;
	static const unsigned int n = 0xe6546b64;
	unsigned int cHash = nSeed;
	const int nBlocks = nLen / 4;
	const unsigned int *pBlocks = (const unsigned int *)cKey;
	int i;
	const unsigned char *tail;
	unsigned int k1 = 0;
	for (i = 0; i < nBlocks; i++) {
		unsigned int k = pBlocks[i];
		k *= c1;
		k = (k << r1) | (k >> (32 - r1));
		k *= c2;
		cHash ^= k;
		cHash = ((cHash << r2) | (cHash >> (32 - r2))) * m + n;
	}
	tail = (const unsigned char *)(cKey + nBlocks * 4);
	switch (nLen & 3) {
	case 3:
		k1 ^= tail[2] << 16;
	case 2:
		k1 ^= tail[1] << 8;
	case 1:
		k1 ^= tail[0];
		k1 *= c1;
		k1 = (k1 << r1) | (k1 >> (32 - r1));
		k1 *= c2;
		cHash ^= k1;
	}
	cHash ^= nLen;
	cHash ^= (cHash >> 16);
	cHash *= 0x85ebca6b;
	cHash ^= (cHash >> 13);
	cHash *= 0xc2b2ae35;
	cHash ^= (cHash >> 16);
	return cHash;
}

/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_hashlib_h
#define ring_hashlib_h

RING_API unsigned ring_hashlib_xorhash(unsigned char *cKey, int nLen);

RING_API unsigned int ring_hashlib_murmurthree32(const char *cKey, unsigned int nLen, unsigned int nSeed);
#endif

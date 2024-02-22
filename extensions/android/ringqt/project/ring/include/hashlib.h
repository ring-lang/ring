/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_hashlib_h
	#define ring_hashlib_h

	unsigned ring_xor_hash(unsigned char *cKey, int nLen);

	unsigned int ring_murmur3_32(const char *cKey, unsigned int nLen, unsigned int nSeed) ;	
#endif
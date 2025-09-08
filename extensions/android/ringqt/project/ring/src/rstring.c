/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API String *ring_string_new_gc(void *pState, const char *cStr) {
	unsigned int x;
	x = strlen(cStr);
	return ring_string_new2_gc(pState, cStr, x);
}

RING_API String *ring_string_new2_gc(void *pState, const char *cStr, unsigned int nStrSize) {
	String *pString;
	unsigned int x, nSize;
	nSize = (unsigned int)nStrSize;
	pString = (struct String *)ring_state_malloc(pState, sizeof(struct String));
	if ((nSize + 1) <= RING_STRING_ARRAYSIZE) {
		pString->cStr = pString->cStrArray;
		pString->nCapacity = RING_STRING_ARRAYSIZE;
	} else {
		pString->cStr = (char *)ring_state_malloc(pState, nSize + 1);
		pString->nCapacity = nSize + 1;
	}
	if (cStr) {
		RING_MEMCPY(pString->cStr, cStr, nSize);
	}
	pString->nSize = nSize;
	pString->cStr[nSize] = '\0';
	return pString;
}

RING_API String *ring_string_delete_gc(void *pState, String *pString) {
	if (pString->cStr != pString->cStrArray) {
		ring_state_free(pState, pString->cStr);
	}
	pString->cStr = NULL;
	ring_state_free(pState, pString);
	return NULL;
}

RING_API void ring_string_set_gc(void *pState, String *pString, const char *cStr) {
	unsigned int x;
	if (pString->cStr == cStr) {
		/* Setting the string by itself - Do nothing! */
		return;
	}
	x = strlen(cStr);
	ring_string_set2_gc(pState, pString, cStr, x);
}

RING_API void ring_string_set2_gc(void *pState, String *pString, const char *cStr, unsigned int nStrSize) {
	unsigned int x, nRequiredSize, nNewCapacity;
	nRequiredSize = (unsigned int)nStrSize;
	if ((pString->cStr == cStr) && (pString->nSize == nRequiredSize)) {
		/* Setting the string by itself - Do nothing! */
		return;
	}
	/* Check if we need to reallocate or delete large buffers when the string is empty */
	nNewCapacity = nRequiredSize + 1;
	if ((nNewCapacity > pString->nCapacity) || (nRequiredSize == 0)) {
		/* Free the old heap buffer if it exists */
		if (pString->cStr != pString->cStrArray) {
			ring_state_free(pState, pString->cStr);
		}
		/* Allocate a new buffer. No growth strategy needed for 'set', just allocate enough */
		if (nNewCapacity <= RING_STRING_ARRAYSIZE) {
			pString->cStr = pString->cStrArray;
			pString->nCapacity = RING_STRING_ARRAYSIZE;
		} else {
			pString->cStr = (char *)ring_state_malloc(pState, nNewCapacity);
			pString->nCapacity = nNewCapacity;
		}
	}
	/* Now we have enough capacity, copy the data. */
	if (cStr) {
		RING_MEMCPY(pString->cStr, cStr, nRequiredSize);
	}
	pString->nSize = nRequiredSize;
	pString->cStr[nRequiredSize] = '\0';
}

RING_API void ring_string_add_gc(void *pState, String *pString, const char *cStr) {
	unsigned int x;
	x = strlen(cStr);
	ring_string_add2_gc(pState, pString, cStr, x);
}

RING_API void ring_string_add2_gc(void *pState, String *pString, const char *cStr, unsigned int nStrSize) {
	unsigned int x, nOriginalSize, nRequiredSize, nNewCapacity;
	char *pNewStr;
	if (nStrSize == 0) {
		/* Adding empty string ---> Do Nothing! */
		return;
	}
	nOriginalSize = pString->nSize;
	/* Check for overflow before addition */
	if (nOriginalSize > UINT_MAX - nStrSize) {
		printf(RING_STRINGSIZEOVERFLOW);
		exit(RING_EXIT_FAIL);
	}
	nRequiredSize = nOriginalSize + nStrSize;
	/* Check if there is enough capacity */
	if ((nRequiredSize + 1) > pString->nCapacity) {
		/* Not enough space, so reallocate with a growth strategy */
		nNewCapacity = pString->nCapacity;
		/* Common strategy: double the capacity until it's large enough */
		if (nNewCapacity == 0) {
			nNewCapacity = RING_STRING_ARRAYSIZE;
		}
		while ((nRequiredSize + 1) > nNewCapacity) {
			nNewCapacity *= 2;
		}
		/* Perform the actual reallocation */
		if (pString->cStr == pString->cStrArray) {
			pNewStr = (char *)ring_state_malloc(pState, nNewCapacity);
			RING_MEMCPY(pNewStr, pString->cStr, nOriginalSize);
		} else {
			pNewStr = (char *)ring_state_realloc(pState, pString->cStr, pString->nCapacity, nNewCapacity);
		}
		pString->cStr = pNewStr;
		pString->nCapacity = nNewCapacity;
	}
	/* We have enough capacity. Just copy the new data. */
	RING_MEMCPY(pString->cStr + nOriginalSize, cStr, nStrSize);
	pString->nSize = nRequiredSize;
	pString->cStr[nRequiredSize] = '\0';
}

RING_API void ring_string_setfromint_gc(void *pState, String *pString, int x) {
	char cStr[RING_SMALLBUF];
	sprintf(cStr, "%d", x);
	ring_string_set_gc(pState, pString, cStr);
}

RING_API unsigned int ring_string_size_gc(void *pState, String *pString) { return pString->nSize; }

RING_API void ring_string_print_gc(void *pState, String *pString) { printf("%s \n", pString->cStr); }

RING_API char *ring_string_strdup_gc(void *pState, const char *cStr) {
	char *cString;
	unsigned int x, nSize;
	nSize = strlen(cStr);
	cString = (char *)ring_state_malloc(pState, nSize + RING_ONE);
	RING_MEMCPY(cString, cStr, nSize);
	cString[nSize] = '\0';
	return cString;
}

RING_API String *ring_string_new(const char *cStr) { return ring_string_new_gc(NULL, cStr); }

RING_API String *ring_string_new2(const char *cStr, unsigned int nStrSize) {
	return ring_string_new2_gc(NULL, cStr, nStrSize);
}

RING_API String *ring_string_delete(String *pString) { return ring_string_delete_gc(NULL, pString); }

RING_API void ring_string_set(String *pString, const char *cStr) { ring_string_set_gc(NULL, pString, cStr); }

RING_API void ring_string_set2(String *pString, const char *cStr, unsigned int nStrSize) {
	ring_string_set2_gc(NULL, pString, cStr, nStrSize);
}

RING_API void ring_string_add(String *pString, const char *cStr) { ring_string_add_gc(NULL, pString, cStr); }

RING_API void ring_string_add2(String *pString, const char *cStr, unsigned int nStrSize) {
	ring_string_add2_gc(NULL, pString, cStr, nStrSize);
}

RING_API void ring_string_setfromint(String *pString, int x) { ring_string_setfromint_gc(NULL, pString, x); }

RING_API unsigned int ring_string_size(String *pString) { return ring_string_size_gc(NULL, pString); }

RING_API void ring_string_print(String *pString) { ring_string_print_gc(NULL, pString); }

RING_API char *ring_string_strdup(const char *cStr) { return ring_string_strdup_gc(NULL, cStr); }

/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_string_h
#define ring_string_h
#define RING_LOOP_THRESHOLD 16
#if RING_LOWMEM
	#define RING_STRING_ARRAYSIZE 8
#else
	#define RING_STRING_ARRAYSIZE 32
#endif
/*
**  nSize is (Allocation Size - 1) i.e. String length execulding the NULL terminator
**  nCapacity is the allocated buffer size
*/
typedef struct String {
	char *cStr;
	unsigned int nSize;
	unsigned int nCapacity;
	char cStrArray[RING_STRING_ARRAYSIZE];
} String;
#define ring_string_tolower_gc(pState, pString) ring_general_lower(pString->cStr)
#define ring_string_toupper_gc(pState, pString) ring_general_upper(pString->cStr)
#define ring_string_get_gc(pState, pString) (pString->cStr)
#define ring_string_tolower(pString) ring_string_tolower_gc(NULL, pString)
#define ring_string_toupper(pString) ring_string_toupper_gc(NULL, pString)
#define ring_string_get(pString) ring_string_get_gc(NULL, pString)
#define RING_MEMCPY(cStrDest, cStrSrc, nSize)                                                                          \
	do {                                                                                                           \
		if ((nSize) < RING_LOOP_THRESHOLD) {                                                                   \
			for (x = 0; x < (nSize); x++) {                                                                \
				(cStrDest)[x] = (cStrSrc)[x];                                                          \
			}                                                                                              \
		} else {                                                                                               \
			memcpy((cStrDest), (cStrSrc), (nSize));                                                        \
		}                                                                                                      \
	} while (0)

RING_API String *ring_string_new_gc(void *pState, const char *cStr);

RING_API String *ring_string_new2_gc(void *pState, const char *cStr, unsigned int nStrSize);

RING_API String *ring_string_delete_gc(void *pState, String *pString);

RING_API void ring_string_set_gc(void *pState, String *pString, const char *cStr);

RING_API void ring_string_set2_gc(void *pState, String *pString, const char *cStr, unsigned int nStrSize);

RING_API void ring_string_add_gc(void *pState, String *pString, const char *cStr);

RING_API void ring_string_add2_gc(void *pState, String *pString, const char *cStr, unsigned int nStrSize);

RING_API void ring_string_setfromint_gc(void *pState, String *pString, int x);

RING_API unsigned int ring_string_size_gc(void *pState, String *pString);

RING_API void ring_string_print_gc(void *pState, String *pString);

RING_API char *ring_string_strdup_gc(void *pState, const char *cStr);

RING_API String *ring_string_new(const char *cStr);

RING_API String *ring_string_new2(const char *cStr, unsigned int nStrSize);

RING_API String *ring_string_delete(String *pString);

RING_API void ring_string_set(String *pString, const char *cStr);

RING_API void ring_string_set2(String *pString, const char *cStr, unsigned int nStrSize);

RING_API void ring_string_add(String *pString, const char *cStr);

RING_API void ring_string_add2(String *pString, const char *cStr, unsigned int nStrSize);

RING_API void ring_string_setfromint(String *pString, int x);

RING_API unsigned int ring_string_size(String *pString);

RING_API void ring_string_print(String *pString);

RING_API char *ring_string_strdup(const char *cStr);
#endif

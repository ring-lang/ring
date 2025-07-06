/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API String * ring_string_new_gc ( void *pState,const char *cStr )
{
	int x  ;
	x = strlen( cStr ) ;
	return ring_string_new2_gc(pState,cStr,x) ;
}

RING_API String * ring_string_new2_gc ( void *pState,const char *cStr,int nStrSize )
{
	String *pString  ;
	unsigned int nSize = (unsigned int) nStrSize;
	unsigned int x  ;

	pString = (struct String *) ring_state_malloc(pState,sizeof(struct String));

	if ( (nSize + 1) <= RING_STRING_ARRAYSIZE ) {
		pString->cStr = pString->cStrArray;
		pString->nCapacity = RING_STRING_ARRAYSIZE;
	} else {
		/* For new strings, allocate exactly what is needed. Growth happens on adds. */
		pString->cStr = (char *) ring_state_malloc(pState, nSize + 1);
		pString->nCapacity = nSize + 1;
	}
	
	if ( cStr ) {
		RING_MEMCPY(pString->cStr, cStr, nSize);
	}

	pString->nSize = nSize;
	pString->cStr[nSize] = '\0' ;
	return pString ;
}

RING_API String * ring_string_delete_gc ( void *pState,String *pString )
{
	if ( pString->cStr != pString->cStrArray ) {
		ring_state_free(pState, pString->cStr);
	}
	pString->cStr = NULL;
	ring_state_free(pState,pString);
	return NULL ;
}

RING_API int ring_string_size ( String *pString )
{
	return pString->nSize ;
}

RING_API void ring_string_set_gc ( void *pState,String *pString,const char *cStr )
{
	int x  ;
	if ( pString->cStr == cStr ) {
		/* Setting the string by itself - Do nothing! */
		return ;
	}
	x = strlen( cStr ) ;
	ring_string_set2_gc(pState,pString,cStr,x);
}

RING_API void ring_string_set2_gc ( void *pState,String *pString,const char *cStr,int nStrSize )
{
	unsigned int nRequiredSize = (unsigned int) nStrSize;
	unsigned int x  ;

	if ( (pString->cStr == cStr) && (pString->nSize == nRequiredSize) ) {
		/* Setting the string by itself - Do nothing! */
		return ;
	}

	/* Check if we need to reallocate */
	if ( (nRequiredSize + 1) > pString->nCapacity ) {
		/* Free the old heap buffer if it exists */
		if ( pString->cStr != pString->cStrArray ) {
			ring_state_free(pState, pString->cStr);
		}

		/* Allocate a new buffer. No growth strategy needed for 'set', just allocate enough. */
		unsigned int nNewCapacity = nRequiredSize + 1;
		
		if ( nNewCapacity <= RING_STRING_ARRAYSIZE ) {
			pString->cStr = pString->cStrArray;
			pString->nCapacity = RING_STRING_ARRAYSIZE;
		} else {
			pString->cStr = (char *) ring_state_malloc(pState, nNewCapacity);
			pString->nCapacity = nNewCapacity;
		}
	}

	/* Now we have enough capacity, copy the data. */
	if ( cStr ) {
		RING_MEMCPY(pString->cStr, cStr, nRequiredSize);
	}
	pString->nSize = nRequiredSize;
	pString->cStr[nRequiredSize] = '\0';
}

RING_API void ring_string_add_gc ( void *pState,String *pString,const char *cStr )
{
	int x  ;
	x = strlen( cStr ) ;
	ring_string_add2_gc(pState,pString,cStr,x);
}

RING_API void ring_string_add2_gc ( void *pState,String *pString,const char *cStr,int nStrSize )
{
	unsigned int nAddSize, nOriginalSize, nRequiredSize  ;
	unsigned int x  ;

	if ( nStrSize == 0 ) {
		/* Adding empty string ---> Do Nothing! */
		return ;
	}
	nAddSize = (unsigned int) nStrSize;
	nOriginalSize = pString->nSize;
	nRequiredSize = nOriginalSize + nAddSize;

	/* Check if there is enough capacity */
	if ( (nRequiredSize + 1) > pString->nCapacity ) {
		/* Not enough space, so reallocate with a growth strategy */
		unsigned int nNewCapacity = pString->nCapacity;
		char *pNewStr;

		/* Common strategy: double the capacity until it's large enough */
		if (nNewCapacity == 0) nNewCapacity = 8;
		while ( (nRequiredSize + 1) > nNewCapacity ) {
			nNewCapacity *= 2;
		}

		/* Perform the actual reallocation */
		if ( pString->cStr == pString->cStrArray ) {
			/* Transition from SSO to Heap */
			pNewStr = (char *) ring_state_malloc(pState, nNewCapacity);
			RING_MEMCPY(pNewStr, pString->cStr, nOriginalSize);
		} else {
			/* Reallocate from heap to a larger heap buffer */
			pNewStr = (char *) ring_state_realloc(pState, pString->cStr, pString->nCapacity, nNewCapacity);
		}
		
		pString->cStr = pNewStr;
		pString->nCapacity = nNewCapacity;
	}

	/* We have enough capacity. Just copy the new data. */
	RING_MEMCPY(pString->cStr + nOriginalSize, cStr, nAddSize);
	pString->nSize = nRequiredSize;
	pString->cStr[nRequiredSize] = '\0';
}

RING_API void ring_string_print ( String *pString )
{
	printf( "%s \n",pString->cStr ) ;
}

RING_API void ring_string_setfromint_gc ( void *pState,String *pString,int x )
{
	char cStr[RING_SMALLBUF]  ; /* Max int is ~11 chars + sign + null. 32 is safe. */
	int nStrSize;

#if RING_NOSNPRINTF
	/* Unsafe, but respects the build flag. Using temp buffer is required. */
	nStrSize = sprintf( cStr , "%d" , x ) ;
	ring_string_set2_gc(pState,pString,cStr, nStrSize);
#else
	/* C99 trick to get required length */
	nStrSize = snprintf( NULL, 0, "%d", x );
	if ( ((unsigned int)nStrSize + 1) <= pString->nCapacity ) {
		/* Optimization: print directly into the string's buffer if it fits */
		snprintf( pString->cStr, pString->nCapacity, "%d", x );
		pString->nSize = nStrSize;
	}
	else {
		/* Otherwise, use set2 which will reallocate */
		snprintf( cStr, RING_SMALLBUF, "%d", x );
		ring_string_set2_gc(pState,pString, cStr, nStrSize);
	}
#endif
}

RING_API char * ring_string_lower ( char *cStr )
{
	unsigned int x, nLen  ;
	nLen = strlen(cStr) ;
	for ( x = 0 ; x < nLen ; x++ ) {
		if ( isalpha((unsigned char) cStr[x]) ) {
			cStr[x] = tolower( cStr[x] );
		}
	}
	return cStr ;
}

RING_API char * ring_string_lower2 ( char *cStr,int nStrSize )
{
	int x  ;
	for ( x = 0 ; x < nStrSize ; x++ ) {
		if ( isalpha((unsigned char) cStr[x]) ) {
			cStr[x] = tolower( cStr[x] );
		}
	}
	return cStr ;
}

RING_API char * ring_string_upper ( char *cStr )
{
	unsigned int x, nLen  ;
	nLen = strlen(cStr) ;
	for ( x = 0 ; x < nLen ; x++ ) {
		if ( isalpha((unsigned char) cStr[x]) ) {
			cStr[x] = toupper( cStr[x] );
		}
	}
	return cStr ;
}

RING_API char * ring_string_upper2 ( char *cStr,int nStrSize )
{
	int x  ;
	for ( x = 0 ; x < nStrSize ; x++ ) {
		if ( isalpha((unsigned char) cStr[x]) ) {
			cStr[x] = toupper( cStr[x] );
		}
	}
	return cStr ;
}

RING_API char * ring_string_find_gc ( void *pState,char *cStr1,char *cStr2 )
{
	return ring_string_find2_gc(pState,cStr1,strlen(cStr1),cStr2,strlen(cStr2)) ;
}

RING_API char * ring_string_find2_gc ( void *pState,char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 )
{
	int nPos,x  ;
	nPos = 0 ;
	if ( (nStrSize1 - nStrSize2) < 0 ) {
		return NULL ;
	}
	while ( nPos <= (nStrSize1 - nStrSize2) ) {
		if ( nStrSize2 < RING_LOOP_THRESHOLD ) {
			x = 0 ;
			while ( (x < nStrSize2) && (cStr1[nPos+x] == cStr2[x] ) ) {
				x++ ;
			}
			if ( x == nStrSize2 ) {
				return cStr1+nPos ;
			}
		}
		else {
			if ( memcmp(cStr1+nPos,cStr2,nStrSize2) == 0 ) {
				return cStr1+nPos ;
			}
		}
		nPos++ ;
	}
	return NULL ;
}

RING_API char * ring_string_find3_gc ( void *pState,char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 )
{
	/* This function is not case sensitive. */
	/* Optimized to avoid all allocations, temporary copies and redundant tolower() calls. */
	char cFirst  ;
	char *pStart, *pEnd  ;
	int i  ;
	(void)pState; /* pState is unused */

	if (nStrSize2 == 0) {
		return cStr1; /* Finding empty string is always at the start */
	}
	if (nStrSize2 > nStrSize1) {
		return NULL; /* Can't find a longer string in a shorter one */
	}

	/* Pre-calculate the first character of the needle, lowercased. */
	cFirst = tolower((unsigned char)cStr2[0]);

	/* Pointer to the last possible starting position in cStr1 */
	pEnd = cStr1 + nStrSize1 - nStrSize2;

	for (pStart = cStr1; pStart <= pEnd; ++pStart) {
		/* Optimization: First-character check. Much faster than memcmp/loop. */
		if (tolower((unsigned char)*pStart) == cFirst) {
			/* If the first char matches, check the rest of the substring case-insensitively. */
			/* strncasecmp (and its Windows equivalent _strnicmp) is ideal if available. */
			/* If not, a manual loop is still much better than the original. */
			for (i = 1; i < nStrSize2; ++i) {
				if (tolower((unsigned char)pStart[i]) != tolower((unsigned char)cStr2[i])) {
					break; /* Mismatch */
				}
			}
			if (i == nStrSize2) {
				return pStart; /* Full match found */
			}
		}
	}

	return NULL; /* No match */
}

RING_API char * ring_string_strdup ( void *pState,const char *cStr )
{
	char *cString  ;
	int x,nSize  ;
	nSize = strlen(cStr) ;
	cString = (char *) ring_state_malloc(pState,nSize+1);
	RING_MEMCPY(cString, cStr, nSize);
	cString[nSize] = '\0' ;
	return cString ;
}

RING_API int ring_string_looksempty ( const char *cStr,int nSize )
{
	int x  ;
	if ( nSize == 0 ) {
		return 1 ;
	}
	for ( x = 0 ; x < nSize ; x++ ) {
		if ( ! ((cStr[x] == ' ' ) || (cStr[x] == '\r' ) || (cStr[x] == '\n' ) || (cStr[x] == '\t' ) ) ) {
			return 0 ;
		}
	}
	return 1 ;
}

RING_API String * ring_string_new2 ( const char *cStr,int nStrSize )
{
	return ring_string_new2_gc(NULL,cStr,nStrSize) ;
}

RING_API String * ring_string_new ( const char *cStr )
{
	return ring_string_new_gc(NULL,cStr) ;
}

RING_API void ring_string_add ( String *pString,const char *cStr )
{
	ring_string_add_gc(NULL,pString,cStr);
}

RING_API void ring_string_add2 ( String *pString,const char *cStr,int nStrSize )
{
	ring_string_add2_gc(NULL,pString,cStr,nStrSize);
}

RING_API void ring_string_set ( String *pString,const char *cStr )
{
	ring_string_set_gc(NULL,pString,cStr);
}

RING_API void ring_string_set2 ( String *pString,const char *cStr,int nStrSize )
{
	ring_string_set2_gc(NULL,pString,cStr,nStrSize);
}

RING_API char * ring_string_find ( char *cStr1,char *cStr2 )
{
	return ring_string_find_gc(NULL,cStr1,cStr2) ;
}

RING_API char * ring_string_find2 ( char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 )
{
	return ring_string_find2_gc(NULL,cStr1,nStrSize1,cStr2,nStrSize2) ;
}

RING_API char * ring_string_find3 ( char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 )
{
	return ring_string_find3_gc(NULL,cStr1,nStrSize1,cStr2,nStrSize2) ;
}

RING_API String * ring_string_delete ( String *pString )
{
	return ring_string_delete_gc(NULL,pString) ;
}

RING_API void ring_string_setfromint ( String *pString,int x )
{
	ring_string_setfromint_gc(NULL,pString,x);
}

RING_API void ring_string_word ( const char *cStr,int nIndex,char *cOutput )
{
	const char *pStart = cStr  ;
	const char *pEnd  ;
	int nWord = 1  ;
	size_t x, nLen  ;

	/* This function will return a specific word from a string using the word index */
	if (nIndex < 1) {
		*cOutput = '\0';
		return;
	}

	/* Scan through the string to find the nIndex-th word */
	while (*pStart) {
		/* Skip leading spaces */
		while (*pStart == ' ') {
			pStart++;
		}

		if (*pStart == '\0') {
			/* End of string, no more words */
			break;
		}

		/* At the beginning of a new word */
		if (nWord == nIndex) {
			/* This is the word we want. Find its end. */
			pEnd = pStart;
			while (*pEnd && *pEnd != ' ') {
				pEnd++;
			}
			
			/* Copy the word to the output buffer, assuming it is large enough */
			nLen = pEnd - pStart;
			RING_MEMCPY(cOutput, pStart, nLen);
			cOutput[nLen] = '\0';
			return;
		}

		/* This is not the word we want. Skip to the end of it and prepare for the next. */
		pEnd = pStart;
		while (*pEnd && *pEnd != ' ') {
			pEnd++;
		}
		pStart = pEnd;
		nWord++;
	}

	/* If we reach here, the word with the given index was not found */
	*cOutput = '\0';
}


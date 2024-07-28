/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

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
	int x  ;
	pString = (struct String *) ring_state_malloc(pState,sizeof(struct String));
	pString->cStr = (char *) ring_string_alloc_gc(pState,pString,nStrSize+1);
	/* if cStr is NULL then the caller wants to adjust the preallocated memory */
	if ( cStr ) {
		/* Copy String */
		RING_MEMCPY(pString->cStr, cStr, nStrSize);
	}
	pString->cStr[nStrSize] = '\0' ;
	pString->nSize = nStrSize ;
	return pString ;
}

RING_API String * ring_string_delete_gc ( void *pState,String *pString )
{
	ring_string_free_gc(pState,pString,pString->cStr);
	pString->cStr = NULL ;
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
	int x  ;
	if ( (pString->nSize == nStrSize) && (pString->cStr == cStr) ) {
		/* Setting the string by itself - Do nothing! */
		return ;
	}
	/* Allocate new buffer only if the new size is different from the current size */
	x = nStrSize + 1 ;
	if ( pString->nSize != nStrSize ) {
		if ( ! cStr ) {
			pString->cStr = (char *) ring_string_realloc_gc(pState,pString,pString->nSize,x) ;
		}
		else {
			ring_string_free_gc(pState,pString,pString->cStr);
			pString->cStr = (char *) ring_string_alloc_gc(pState,pString,x);
		}
	}
	/* if cStr is NULL then the caller wants to adjust the preallocated memory */
	if ( cStr ) {
		/* Copy String */
		RING_MEMCPY(pString->cStr, cStr, nStrSize);
	}
	pString->cStr[nStrSize] = '\0' ;
	pString->nSize = nStrSize ;
}

RING_API void ring_string_add_gc ( void *pState,String *pString,const char *cStr )
{
	int x  ;
	x = strlen( cStr ) ;
	ring_string_add2_gc(pState,pString,cStr,x);
}

RING_API void ring_string_add2_gc ( void *pState,String *pString,const char *cStr,int nStrSize )
{
	int x,x2,nOriginalSize  ;
	if ( nStrSize == 0 ) {
		/* Adding empty string ---> Do Nothing! */
		return ;
	}
	nOriginalSize = ring_string_size(pString) ;
	x2 = nStrSize+nOriginalSize ;
	pString->cStr = (char *) ring_string_realloc_gc(pState,pString,nOriginalSize+1,x2+1);
	/* Copy String */
	RING_MEMCPY(pString->cStr + nOriginalSize, cStr, nStrSize);
	pString->cStr[x2] = '\0' ;
	pString->nSize = x2 ;
}

RING_API void ring_string_print ( String *pString )
{
	printf( "%s \n",pString->cStr ) ;
}

RING_API void ring_string_setfromint_gc ( void *pState,String *pString,int x )
{
	char cStr[RING_SMALLBUF]  ;
	sprintf( cStr , "%d" , x ) ;
	ring_string_set_gc(pState,pString,cStr);
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
	int nPos,x  ;
	char *cStr3  ;
	char *cStr4  ;
	char *pOutput  ;
	/* This function is not case sensitive and work on a copy from cStr1 and cStr2 */
	nPos = 0 ;
	if ( (nStrSize1 - nStrSize2) < 0 ) {
		return NULL ;
	}
	/* Copy Strings and convert to lower case */
	cStr3 = (char *) ring_state_malloc(pState,nStrSize1+1);
	cStr4 = (char *) ring_state_malloc(pState,nStrSize2+1);
	RING_MEMCPY(cStr3,cStr1,nStrSize1);
	RING_MEMCPY(cStr4,cStr2,nStrSize2);
	ring_string_lower2(cStr3,nStrSize1);
	ring_string_lower2(cStr4,nStrSize2);
	pOutput = NULL ;
	while ( nPos <= (nStrSize1 - nStrSize2) ) {
		if ( nStrSize2 < RING_LOOP_THRESHOLD ) {
			x = 0 ;
			while ( (x < nStrSize2) && (cStr3[nPos+x] == cStr4[x] ) ) {
				x++ ;
			}
			if ( x == nStrSize2 ) {
				pOutput = cStr1+nPos ;
				break ;
			}
		}
		else {
			if ( memcmp(cStr3+nPos,cStr4,nStrSize2) == 0 ) {
				pOutput = cStr1+nPos ;
				break ;
			}
		}
		nPos++ ;
	}
	/* Free Memory */
	ring_state_free(pState,cStr3);
	ring_state_free(pState,cStr4);
	return pOutput ;
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

RING_API char * ring_string_alloc_gc ( void *pState,String *pString, int nSize )
{
	if ( nSize <= RING_STRING_ARRAYSIZE ) {
		return (char *) (pString->cStrArray) ;
	}
	return (char *) ring_state_malloc(pState,nSize) ;
}

RING_API void * ring_string_free_gc ( void *pState,String *pString,char *cStr )
{
	if ( ! ( (cStr > ((char *)pString) ) && ( cStr < ( ((char *) pString)+sizeof(String)) ) ) ) {
		ring_state_free(pState,cStr);
	}
	return NULL ;
}

RING_API char * ring_string_realloc_gc ( void *pState,String *pString,int nOldSize,int nNewSize )
{
	char *cStr, *cNewStr  ;
	int x  ;
	cStr = pString->cStr ;
	if ( ! ( (cStr > ((char *)pString) ) && ( cStr < ( ((char *) pString)+sizeof(String)) ) ) ) {
		return (char *) ring_state_realloc(pState,cStr,nOldSize,nNewSize) ;
	}
	if ( nNewSize <= RING_STRING_ARRAYSIZE ) {
		return (char *) (pString->cStrArray) ;
	}
	cNewStr = (char *) ring_state_malloc(pState,nNewSize);
	RING_MEMCPY(cNewStr,pString->cStr,nOldSize);
	return cNewStr ;
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
	char *cString  ;
	int x,nStart,nEnd,nSize,nWord,nOutIndex  ;
	/* This function will return a specific word from a string using the word index */
	nSize = strlen(cStr) ;
	/* Determine the start of the word */
	nStart = 0 ;
	if ( nIndex != 1 ) {
		nWord = 1 ;
		while ( nWord != nIndex ) {
			if ( cStr[++nStart] == ' ' ) {
				nStart++ ;
				nWord++ ;
			}
		}
	}
	/* Determine the End of the word */
	nEnd = nStart ;
	nOutIndex = 0 ;
	while ( (cStr[nEnd] != ' ') && (nEnd != nSize) ) {
		cOutput[nOutIndex] = cStr[nEnd] ;
		nEnd++ ;
		nOutIndex++ ;
	}
	cOutput[nOutIndex] = '\0' ;
}

RING_API void ring_string_swaptwostrings ( String *pString1,String *pString2 )
{
	String TempString  ;
	memcpy(&TempString,pString1,sizeof(String));
	memcpy(pString1,pString2,sizeof(String));
	memcpy(pString2,&TempString,sizeof(String));
}

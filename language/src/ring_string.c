/* Copyright (c) 2013-2019 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Functions */

RING_API String * ring_string_new_gc ( void *pState,const char *str )
{
	int x  ;
	x = strlen( str ) ;
	return ring_string_new2_gc(pState,str,x) ;
}

RING_API String * ring_string_new2_gc ( void *pState,const char *str,int nStrSize )
{
	String *pString  ;
	int x  ;
	pString = (struct String *) ring_state_malloc(pState,sizeof(struct String));
	if ( pString == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	pString->cStr = (char *) ring_state_malloc(pState,nStrSize+1);
	if ( pString->cStr  == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	/* Copy String */
	for ( x = 0 ; x < nStrSize ; x++ ) {
		pString->cStr[x] = str[x] ;
	}
	pString->cStr[nStrSize] = '\0' ;
	pString->nSize = nStrSize ;
	return pString ;
}

RING_API String * ring_string_delete_gc ( void *pState,String *pString )
{
	assert(pString != NULL);
	ring_state_free(pState,pString->cStr);
	pString->cStr = NULL ;
	ring_state_free(pState,pString);
	return NULL ;
}

RING_API int ring_string_size ( String *pString )
{
	assert(pString != NULL);
	return pString->nSize ;
}

RING_API void ring_string_set_gc ( void *pState,String *pString,const char *str )
{
	int x  ;
	assert(pString != NULL);
	x = strlen( str ) ;
	ring_string_set2_gc(pState,pString,str,x);
}

RING_API void ring_string_set2_gc ( void *pState,String *pString,const char *str,int nStrSize )
{
	int x  ;
	assert(pString != NULL);
	assert(pString->cStr != NULL);
	ring_state_free(pState,pString->cStr);
	pString->cStr = (char *) ring_state_malloc(pState,nStrSize+1);
	if ( pString->cStr  == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	/* Copy String */
	for ( x = 0 ; x < nStrSize ; x++ ) {
		pString->cStr[x] = str[x] ;
	}
	pString->cStr[nStrSize] = '\0' ;
	pString->nSize = nStrSize ;
}

RING_API void ring_string_add_gc ( void *pState,String *pString,const char *str )
{
	int x  ;
	x = strlen( str ) ;
	ring_string_add2_gc(pState,pString,str,x);
}

RING_API void ring_string_add2_gc ( void *pState,String *pString,const char *str,int nStrSize )
{
	int x  ;
	int x2  ;
	int nOriginalSize;
	char *cStr  ;
	assert(pString != NULL);
	nOriginalSize = ring_string_size(pString) ;
	x2 = nStrSize+nOriginalSize ;
	pString->cStr = (char *) ring_state_realloc(pState,pString->cStr,x2+1);
	if ( pString->cStr  == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	/* Copy String */
	if (nStrSize < 64) {
		for ( x = 0 ; x < nStrSize ; x++ ) {
			pString->cStr[x+nOriginalSize] = str[x] ;
		}
	} else {
		memcpy (pString->cStr + nOriginalSize, str, nStrSize);
	}
	pString->cStr[x2] = '\0' ;
	pString->nSize = x2 ;
}

RING_API void ring_string_print ( String *pString )
{
	assert(pString != NULL);
	printf( "%s \n",pString->cStr ) ;
}

RING_API void ring_string_setfromint_gc ( void *pState,String *pString,int x )
{
	char cStr[20]  ;
	assert(pString != NULL);
	sprintf( cStr , "%d" , x ) ;
	ring_string_set_gc(pState,pString,cStr);
}

RING_API char * ring_string_lower ( char *cStr )
{
	unsigned int x  ;
	for ( x = 0 ; x < strlen(cStr) ; x++ ) {
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
	unsigned int x  ;
	for ( x = 0 ; x < strlen(cStr) ; x++ ) {
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
		x = 0 ;
		while ( (x < nStrSize2) && (cStr1[nPos+x] == cStr2[x] ) ) {
			x++ ;
		}
		if ( x == nStrSize2 ) {
			return cStr1+nPos ;
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
	if ( (cStr3==NULL) || (cStr4==NULL) ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	for ( x = 0 ; x <= nStrSize1 ; x++ ) {
		cStr3[x] = cStr1[x] ;
	}
	for ( x = 0 ; x <= nStrSize2 ; x++ ) {
		cStr4[x] = cStr2[x] ;
	}
	ring_string_lower2(cStr3,nStrSize1);
	ring_string_lower2(cStr4,nStrSize2);
	pOutput = NULL ;
	while ( nPos <= (nStrSize1 - nStrSize2) ) {
		x = 0 ;
		while ( (x < nStrSize2) && (cStr3[nPos+x] == cStr4[x] ) ) {
			x++ ;
		}
		if ( x == nStrSize2 ) {
			pOutput = cStr1+nPos ;
			break ;
		}
		nPos++ ;
	}
	/* Free Memory */
	ring_state_free(pState,cStr3);
	ring_state_free(pState,cStr4);
	return pOutput ;
}

RING_API char * ring_strdup ( void *pState,const char *cStr )
{
	char *cString  ;
	int x,nSize  ;
	nSize = strlen(cStr) ;
	cString = (char *) ring_state_malloc(pState,nSize+1);
	if ( cString == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
	for ( x = 0 ; x < nSize ; x++ ) {
		cString[x] = cStr[x] ;
	}
	cString[nSize] = '\0' ;
	return cString ;
}

void ring_string_test ( void )
{
	#define nMaxValue 10
	String *mystr[nMaxValue]  ;
	int x  ;
	String *pString  ;
	for ( x = 0 ; x < nMaxValue ; x++ ) {
		mystr[x] = ring_string_new("Wow Really i like the c language so much");
		ring_string_print(mystr[x]);
	}
	for ( x = 0 ; x < nMaxValue ; x++ ) {
		mystr[x] = ring_string_delete(mystr[x]);
	}
	/* Test String Add */
	pString = ring_string_new("Hello ");
	ring_string_add(pString,"World");
	printf( "\nTest String Add , Output = %s\n",ring_string_get(pString) ) ;
	ring_string_add(pString," Welcome to the C programming language");
	printf( "\nTest String Add , Output = %s\n",ring_string_get(pString) ) ;
	ring_string_delete(pString);
	/* Test String to Lower */
	pString = ring_string_new("Welcome to my StrinG");
	printf( "Test string to lower \n" ) ;
	printf( "%s\n",ring_string_tolower(pString) ) ;
	ring_string_delete(pString);
}
/* Functions without state pointer */

RING_API String * ring_string_new2 ( const char *str,int nStrSize )
{
	return ring_string_new2_gc(NULL,str,nStrSize) ;
}

RING_API String * ring_string_new ( const char *str )
{
	return ring_string_new_gc(NULL,str) ;
}

RING_API void ring_string_add ( String *pString,const char *str )
{
	ring_string_add_gc(NULL,pString,str);
}

RING_API void ring_string_add2 ( String *pString,const char *str,int nStrSize )
{
	ring_string_add2_gc(NULL,pString,str,nStrSize);
}

RING_API void ring_string_set ( String *pString,const char *str )
{
	ring_string_set_gc(NULL,pString,str);
}

RING_API void ring_string_set2 ( String *pString,const char *str,int nStrSize )
{
	ring_string_set2_gc(NULL,pString,str,nStrSize);
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

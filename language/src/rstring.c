/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
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
    pString->cStr = (char *) ring_state_malloc(pState,nStrSize+1);
    /* if str is NULL then the caller wants to adjust the preallocated memory */
    if ( str ) {
        /* Copy String */
        RING_MEMCPY(pString->cStr, str, nStrSize);
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
    if ( pString->cStr == str ) {
        /* Setting the string by itself - Do nothing! */
        return ;
    }
    x = strlen( str ) ;
    ring_string_set2_gc(pState,pString,str,x);
}

RING_API void ring_string_set2_gc ( void *pState,String *pString,const char *str,int nStrSize )
{
    int x  ;
    assert(pString != NULL);
    assert(pString->cStr != NULL);
    if ( (pString->nSize == nStrSize) && (pString->cStr == str) ) {
        /* Setting the string by itself - Do nothing! */
        return ;
    }
    /* Allocate new buffer only if the new size is different from the current size */
    if ( pString->nSize != nStrSize ) {
        ring_state_free(pState,pString->cStr);
        pString->cStr = (char *) ring_state_malloc(pState,nStrSize+1);
    }
    /* if str is NULL then the caller wants to adjust the preallocated memory */
    if ( str ) {
        /* Copy String */
        RING_MEMCPY(pString->cStr, str, nStrSize);
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
    int x,x2,nOriginalSize  ;
    char *cStr  ;
    assert(pString != NULL);
    if ( nStrSize == 0 ) {
        /* Adding empty string ---> Do Nothing! */
        return ;
    }
    nOriginalSize = ring_string_size(pString) ;
    x2 = nStrSize+nOriginalSize ;
    pString->cStr = (char *) ring_state_realloc(pState,pString->cStr,nOriginalSize+1,x2+1);
    /* Copy String */
    RING_MEMCPY(pString->cStr + nOriginalSize, str, nStrSize);
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

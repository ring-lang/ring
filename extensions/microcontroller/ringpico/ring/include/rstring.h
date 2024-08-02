/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_string_h
	#define ring_string_h
	#define RING_LOOP_THRESHOLD 16
	#if RING_LOWMEM
		#define RING_STRING_ARRAYSIZE 8
	#else
		#define RING_STRING_ARRAYSIZE 32
	#endif
	typedef struct String {
		char *cStr  ;
		unsigned int nSize  ;
		/* Note : nSize is (Allocation Size - 1) */
		char cStrArray[RING_STRING_ARRAYSIZE]  ;
	} String ;
	#define ring_string_tolower(pString) ring_string_lower(pString->cStr)
	#define ring_string_toupper(pString) ring_string_upper(pString->cStr)
	#define ring_string_get(pString) (pString->cStr)
	#define RING_MEMCPY(cStrDest,cStrSrc,nSize) do { if ( (nSize) < RING_LOOP_THRESHOLD ) { for ( x = 0 ; x < (nSize) ; x++ ) { (cStrDest)[x] = (cStrSrc)[x] ; } } else { memcpy ((cStrDest), (cStrSrc), (nSize)); } } while (0)

	RING_API String * ring_string_new_gc ( void *pState,const char *cStr ) ;

	RING_API String * ring_string_new2_gc ( void *pState,const char *cStr,int nStrSize ) ;

	RING_API String * ring_string_delete_gc ( void *pState,String *pString ) ;

	RING_API int ring_string_size ( String *pString ) ;

	RING_API void ring_string_set_gc ( void *pState,String *pString,const char *cStr ) ;

	RING_API void ring_string_set2_gc ( void *pState,String *pString,const char *cStr,int nStrSize ) ;

	RING_API void ring_string_add_gc ( void *pState,String *pString,const char *cStr ) ;

	RING_API void ring_string_add2_gc ( void *pState,String *pString,const char *cStr,int nStrSize ) ;

	RING_API void ring_string_print ( String *pString ) ;

	RING_API void ring_string_setfromint_gc ( void *pState,String *pString,int x ) ;

	RING_API char * ring_string_lower ( char *cStr ) ;

	RING_API char * ring_string_upper ( char *cStr ) ;

	RING_API char * ring_string_lower2 ( char *cStr,int nStrSize ) ;

	RING_API char * ring_string_upper2 ( char *cStr,int nStrSize ) ;

	RING_API char * ring_string_find_gc ( void *pState,char *cStr1,char *cStr2 ) ;

	RING_API char * ring_string_find2_gc ( void *pState,char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 ) ;

	RING_API char * ring_string_find3_gc ( void *pState,char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 ) ;

	RING_API char * ring_string_strdup ( void *pState,const char *cStr ) ;

	RING_API int ring_string_looksempty ( const char *cStr,int nSize ) ;

	RING_API char * ring_string_alloc_gc ( void *pState,String *pString,int nSize ) ;

	RING_API void * ring_string_free_gc ( void *pState,String *pString,char *cStr ) ;

	RING_API char * ring_string_realloc_gc ( void *pState,String *pString,int nOldSize,int nNewSize ) ;

	RING_API String * ring_string_new2 ( const char *cStr,int nStrSize ) ;

	RING_API String * ring_string_new ( const char *cStr ) ;

	RING_API void ring_string_add ( String *pString,const char *cStr ) ;

	RING_API void ring_string_add2 ( String *pString,const char *cStr,int nStrSize ) ;

	RING_API void ring_string_set ( String *pString,const char *cStr ) ;

	RING_API void ring_string_set2 ( String *pString,const char *cStr,int nStrSize ) ;

	RING_API char * ring_string_find ( char *cStr1,char *cStr2 ) ;

	RING_API char * ring_string_find2 ( char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 ) ;

	RING_API char * ring_string_find3 ( char *cStr1,int nStrSize1,char *cStr2,int nStrSize2 ) ;

	RING_API String * ring_string_delete ( String *pString ) ;

	RING_API void ring_string_setfromint ( String *pString,int x ) ;

	RING_API void ring_string_word ( const char *cStr,int nIndex,char *cOutput ) ;

	RING_API void ring_string_swaptwostrings ( String *pString1,String *pString2 ) ;
#endif

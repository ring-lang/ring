
#define _WINDOWS 1

#include "inet/inet.h"
#include "osapp/osmain.h"
#include "osgui/osgui.h"
#include "nappgui.h"

#define String RingString
#include "ring.h"


RING_FUNC(ring_unicode_convers)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_convers((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t"),* (const unicode_t  *) RING_API_GETCPOINTER(4,"const unicode_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
}


RING_FUNC(ring_unicode_convers_n)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_convers_n((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t"),* (const unicode_t  *) RING_API_GETCPOINTER(4,"const unicode_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(6,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"uint32_t"));
}


RING_FUNC(ring_unicode_convers_nbytes)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_convers_nbytes((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t"),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
}


RING_FUNC(ring_unicode_nbytes)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_nbytes((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_nchars)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_nchars((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_to_u32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_to_u32((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_to_u32b)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_to_u32b((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_to_char)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(unicode_to_char(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
}


RING_FUNC(ring_unicode_valid_str)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_valid_str((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_valid_str_n)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_valid_str_n((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const unicode_t  *) RING_API_GETCPOINTER(3,"const unicode_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"unicode_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_valid)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_valid(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_next)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(unicode_next((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_back)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(unicode_back((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const unicode_t  *) RING_API_GETCPOINTER(2,"const unicode_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"unicode_t"));
}


RING_FUNC(ring_unicode_isascii)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isascii(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isalnum)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isalnum(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isalpha)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isalpha(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_iscntrl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_iscntrl(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isdigit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isdigit(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isgraph)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isgraph(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isprint)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isprint(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_ispunct)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_ispunct(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isspace)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isspace(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isxdigit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isxdigit(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_islower)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_islower(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_isupper)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = unicode_isupper(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_unicode_tolower)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(unicode_tolower(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_unicode_toupper)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(unicode_toupper(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_min_u32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(min_u32(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_min_r32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = min_r32(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_min_r64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = min_r64(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_max_u32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(max_u32(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_max_r32)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = max_r32(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_max_r64)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = max_r64(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_abs_r32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = abs_r32(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_to_u8)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(to_u8(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_sewer_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	sewer_start();
}


RING_FUNC(ring_sewer_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	sewer_finish();
}


RING_FUNC(ring_sewer_nappgui_major)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(sewer_nappgui_major());
}


RING_FUNC(ring_sewer_nappgui_minor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(sewer_nappgui_minor());
}


RING_FUNC(ring_sewer_nappgui_patch)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(sewer_nappgui_patch());
}


RING_FUNC(ring_sewer_nappgui_build)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(sewer_nappgui_build());
}


RING_FUNC(ring_sewer_nappgui_version)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(sewer_nappgui_version(* (const bool_t  *) RING_API_GETCPOINTER(1,"const bool_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
}


RING_FUNC(ring_ptr_dget_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ptr_dget_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void")),"void");
}


RING_FUNC(ring_ptr_dget_no_null_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ptr_dget_no_null_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void")),"void");
}


RING_FUNC(ring_ptr_destopt_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ptr_destopt_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(2,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_destroy"));
}


RING_FUNC(ring_ptr_copyopt_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ptr_copyopt_imp((void *) RING_API_GETCPOINTER(1,"void"),* (FPtr_copy  *) RING_API_GETCPOINTER(2,"FPtr_copy")),"void");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_copy"));
}


RING_FUNC(ring_cassert_set_func)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_set_func((void *) RING_API_GETCPOINTER(1,"void"),* (FPtr_assert  *) RING_API_GETCPOINTER(2,"FPtr_assert"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"FPtr_assert"));
}


RING_FUNC(ring_cassert_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_imp(* (bool_t  *) RING_API_GETCPOINTER(1,"bool_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_cassert_fatal_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_fatal_imp(* (bool_t  *) RING_API_GETCPOINTER(1,"bool_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_cassert_no_null_imp)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_no_null_imp((void *) RING_API_GETCPOINTER(1,"void"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_cassert_default_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cassert_default_imp((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bstd_vsprintf)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_vsprintf((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (va_list  *) RING_API_GETCPOINTER(4,"va_list")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"va_list"));
}


RING_FUNC(ring_bstd_writef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_writef((char_t *) RING_API_GETCPOINTER(1,"char_t")));
}


RING_FUNC(ring_bstd_ewritef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bstd_ewritef((char_t *) RING_API_GETCPOINTER(1,"char_t")));
}


RING_FUNC(ring_bstd_read)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bstd_read((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bstd_write)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bstd_write((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bstd_ewrite)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bstd_ewrite((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmem_aligned_malloc)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETCPOINTER(bmem_aligned_malloc(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"byte_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bmem_aligned_realloc)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bmem_aligned_realloc((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t")),"byte_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_bmem_free)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_free((byte_t *) RING_API_GETCPOINTER(1,"byte_t"));
}


RING_FUNC(ring_bmem_set1)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set1((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const byte_t  *) RING_API_GETCPOINTER(3,"const byte_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"byte_t"));
}


RING_FUNC(ring_bmem_set4)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set4((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(byte_t *) RING_API_GETCPOINTER(3,"byte_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bmem_set8)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set8((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(byte_t *) RING_API_GETCPOINTER(3,"byte_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bmem_set16)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set16((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(byte_t *) RING_API_GETCPOINTER(3,"byte_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bmem_cmp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmem_cmp((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bmem_is_zero)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bmem_is_zero((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmem_set_zero)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_set_zero((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bmem_copy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_copy((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bmem_move)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_move((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bmem_overlaps)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bmem_overlaps((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmem_rev)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bmem_rev2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev2((byte_t *) RING_API_GETCPOINTER(1,"byte_t"));
}


RING_FUNC(ring_bmem_rev4)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev4((byte_t *) RING_API_GETCPOINTER(1,"byte_t"));
}


RING_FUNC(ring_bmem_rev8)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev8((byte_t *) RING_API_GETCPOINTER(1,"byte_t"));
}


RING_FUNC(ring_bmem_revcopy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_revcopy((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bmem_rev_elems_imp)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_rev_elems_imp((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bmem_swap)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_swap((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bmem_shuffle)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmem_shuffle((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bmath_cosf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_cosf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_cosd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_cosd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_sinf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_sinf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_sind)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_sind(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_tanf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_tanf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_tand)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_tand(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_acosf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_acosf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_acosd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_acosd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_asinf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_asinf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_asind)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_asind(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_atan2f)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_atan2f(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_atan2d)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_atan2d(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_norm_anglef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_norm_anglef(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_norm_angled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_norm_angled(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_sqrtf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_sqrtf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_sqrtd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_sqrtd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_isqrtf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_isqrtf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_isqrtd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_isqrtd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_logf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_logf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_logd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_logd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_log10f)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_log10f(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_log10d)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_log10d(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_expf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_expf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_expd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_expd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_powf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_powf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_powd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_powd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_absf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_absf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_absd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_absd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_maxf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_maxf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_maxd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_maxd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_minf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_minf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_mind)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_mind(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_clampf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_clampf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_clampd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_clampd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(3,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_modf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_modf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_modd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_modd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_modff)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_modff(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_modfd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_modfd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),(real64_t *) RING_API_GETCPOINTER(2,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_precf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(bmath_precf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
}


RING_FUNC(ring_bmath_precd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(bmath_precd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
}


RING_FUNC(ring_bmath_roundf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_roundf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_roundd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_roundd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_round_stepf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_round_stepf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_round_stepd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_round_stepd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_floorf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_floorf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_floord)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_floord(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_ceilf)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_ceilf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_ceild)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_ceild(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_rand_seed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	bmath_rand_seed(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_bmath_randf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_randf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_randd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_randd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_randi)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(bmath_randi(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bmath_rand_env)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(bmath_rand_env(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"REnv");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_bmath_rand_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmath_rand_destroy((REnv **) RING_API_GETCPOINTER2POINTER(1,"REnv"));
}


RING_FUNC(ring_bmath_rand_mtf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = bmath_rand_mtf((REnv *) RING_API_GETCPOINTER(1,"REnv"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_rand_mtd)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = bmath_rand_mtd((REnv *) RING_API_GETCPOINTER(1,"REnv"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(3,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bmath_rand_mti)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bmath_rand_mti((REnv *) RING_API_GETCPOINTER(1,"REnv"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}

RING_LIBINIT
{
	RING_API_REGISTER("unicode_convers",ring_unicode_convers);
	RING_API_REGISTER("unicode_convers_n",ring_unicode_convers_n);
	RING_API_REGISTER("unicode_convers_nbytes",ring_unicode_convers_nbytes);
	RING_API_REGISTER("unicode_nbytes",ring_unicode_nbytes);
	RING_API_REGISTER("unicode_nchars",ring_unicode_nchars);
	RING_API_REGISTER("unicode_to_u32",ring_unicode_to_u32);
	RING_API_REGISTER("unicode_to_u32b",ring_unicode_to_u32b);
	RING_API_REGISTER("unicode_to_char",ring_unicode_to_char);
	RING_API_REGISTER("unicode_valid_str",ring_unicode_valid_str);
	RING_API_REGISTER("unicode_valid_str_n",ring_unicode_valid_str_n);
	RING_API_REGISTER("unicode_valid",ring_unicode_valid);
	RING_API_REGISTER("unicode_next",ring_unicode_next);
	RING_API_REGISTER("unicode_back",ring_unicode_back);
	RING_API_REGISTER("unicode_isascii",ring_unicode_isascii);
	RING_API_REGISTER("unicode_isalnum",ring_unicode_isalnum);
	RING_API_REGISTER("unicode_isalpha",ring_unicode_isalpha);
	RING_API_REGISTER("unicode_iscntrl",ring_unicode_iscntrl);
	RING_API_REGISTER("unicode_isdigit",ring_unicode_isdigit);
	RING_API_REGISTER("unicode_isgraph",ring_unicode_isgraph);
	RING_API_REGISTER("unicode_isprint",ring_unicode_isprint);
	RING_API_REGISTER("unicode_ispunct",ring_unicode_ispunct);
	RING_API_REGISTER("unicode_isspace",ring_unicode_isspace);
	RING_API_REGISTER("unicode_isxdigit",ring_unicode_isxdigit);
	RING_API_REGISTER("unicode_islower",ring_unicode_islower);
	RING_API_REGISTER("unicode_isupper",ring_unicode_isupper);
	RING_API_REGISTER("unicode_tolower",ring_unicode_tolower);
	RING_API_REGISTER("unicode_toupper",ring_unicode_toupper);
	RING_API_REGISTER("min_u32",ring_min_u32);
	RING_API_REGISTER("min_r32",ring_min_r32);
	RING_API_REGISTER("min_r64",ring_min_r64);
	RING_API_REGISTER("max_u32",ring_max_u32);
	RING_API_REGISTER("max_r32",ring_max_r32);
	RING_API_REGISTER("max_r64",ring_max_r64);
	RING_API_REGISTER("abs_r32",ring_abs_r32);
	RING_API_REGISTER("to_u8",ring_to_u8);
	RING_API_REGISTER("sewer_start",ring_sewer_start);
	RING_API_REGISTER("sewer_finish",ring_sewer_finish);
	RING_API_REGISTER("sewer_nappgui_major",ring_sewer_nappgui_major);
	RING_API_REGISTER("sewer_nappgui_minor",ring_sewer_nappgui_minor);
	RING_API_REGISTER("sewer_nappgui_patch",ring_sewer_nappgui_patch);
	RING_API_REGISTER("sewer_nappgui_build",ring_sewer_nappgui_build);
	RING_API_REGISTER("sewer_nappgui_version",ring_sewer_nappgui_version);
	RING_API_REGISTER("ptr_dget_imp",ring_ptr_dget_imp);
	RING_API_REGISTER("ptr_dget_no_null_imp",ring_ptr_dget_no_null_imp);
	RING_API_REGISTER("ptr_destopt_imp",ring_ptr_destopt_imp);
	RING_API_REGISTER("ptr_copyopt_imp",ring_ptr_copyopt_imp);
	RING_API_REGISTER("cassert_set_func",ring_cassert_set_func);
	RING_API_REGISTER("cassert_imp",ring_cassert_imp);
	RING_API_REGISTER("cassert_fatal_imp",ring_cassert_fatal_imp);
	RING_API_REGISTER("cassert_no_null_imp",ring_cassert_no_null_imp);
	RING_API_REGISTER("cassert_default_imp",ring_cassert_default_imp);
	RING_API_REGISTER("bstd_vsprintf",ring_bstd_vsprintf);
	RING_API_REGISTER("bstd_writef",ring_bstd_writef);
	RING_API_REGISTER("bstd_ewritef",ring_bstd_ewritef);
	RING_API_REGISTER("bstd_read",ring_bstd_read);
	RING_API_REGISTER("bstd_write",ring_bstd_write);
	RING_API_REGISTER("bstd_ewrite",ring_bstd_ewrite);
	RING_API_REGISTER("bmem_aligned_malloc",ring_bmem_aligned_malloc);
	RING_API_REGISTER("bmem_aligned_realloc",ring_bmem_aligned_realloc);
	RING_API_REGISTER("bmem_free",ring_bmem_free);
	RING_API_REGISTER("bmem_set1",ring_bmem_set1);
	RING_API_REGISTER("bmem_set4",ring_bmem_set4);
	RING_API_REGISTER("bmem_set8",ring_bmem_set8);
	RING_API_REGISTER("bmem_set16",ring_bmem_set16);
	RING_API_REGISTER("bmem_cmp",ring_bmem_cmp);
	RING_API_REGISTER("bmem_is_zero",ring_bmem_is_zero);
	RING_API_REGISTER("bmem_set_zero",ring_bmem_set_zero);
	RING_API_REGISTER("bmem_copy",ring_bmem_copy);
	RING_API_REGISTER("bmem_move",ring_bmem_move);
	RING_API_REGISTER("bmem_overlaps",ring_bmem_overlaps);
	RING_API_REGISTER("bmem_rev",ring_bmem_rev);
	RING_API_REGISTER("bmem_rev2",ring_bmem_rev2);
	RING_API_REGISTER("bmem_rev4",ring_bmem_rev4);
	RING_API_REGISTER("bmem_rev8",ring_bmem_rev8);
	RING_API_REGISTER("bmem_revcopy",ring_bmem_revcopy);
	RING_API_REGISTER("bmem_rev_elems_imp",ring_bmem_rev_elems_imp);
	RING_API_REGISTER("bmem_swap",ring_bmem_swap);
	RING_API_REGISTER("bmem_shuffle",ring_bmem_shuffle);
	RING_API_REGISTER("bmath_cosf",ring_bmath_cosf);
	RING_API_REGISTER("bmath_cosd",ring_bmath_cosd);
	RING_API_REGISTER("bmath_sinf",ring_bmath_sinf);
	RING_API_REGISTER("bmath_sind",ring_bmath_sind);
	RING_API_REGISTER("bmath_tanf",ring_bmath_tanf);
	RING_API_REGISTER("bmath_tand",ring_bmath_tand);
	RING_API_REGISTER("bmath_acosf",ring_bmath_acosf);
	RING_API_REGISTER("bmath_acosd",ring_bmath_acosd);
	RING_API_REGISTER("bmath_asinf",ring_bmath_asinf);
	RING_API_REGISTER("bmath_asind",ring_bmath_asind);
	RING_API_REGISTER("bmath_atan2f",ring_bmath_atan2f);
	RING_API_REGISTER("bmath_atan2d",ring_bmath_atan2d);
	RING_API_REGISTER("bmath_norm_anglef",ring_bmath_norm_anglef);
	RING_API_REGISTER("bmath_norm_angled",ring_bmath_norm_angled);
	RING_API_REGISTER("bmath_sqrtf",ring_bmath_sqrtf);
	RING_API_REGISTER("bmath_sqrtd",ring_bmath_sqrtd);
	RING_API_REGISTER("bmath_isqrtf",ring_bmath_isqrtf);
	RING_API_REGISTER("bmath_isqrtd",ring_bmath_isqrtd);
	RING_API_REGISTER("bmath_logf",ring_bmath_logf);
	RING_API_REGISTER("bmath_logd",ring_bmath_logd);
	RING_API_REGISTER("bmath_log10f",ring_bmath_log10f);
	RING_API_REGISTER("bmath_log10d",ring_bmath_log10d);
	RING_API_REGISTER("bmath_expf",ring_bmath_expf);
	RING_API_REGISTER("bmath_expd",ring_bmath_expd);
	RING_API_REGISTER("bmath_powf",ring_bmath_powf);
	RING_API_REGISTER("bmath_powd",ring_bmath_powd);
	RING_API_REGISTER("bmath_absf",ring_bmath_absf);
	RING_API_REGISTER("bmath_absd",ring_bmath_absd);
	RING_API_REGISTER("bmath_maxf",ring_bmath_maxf);
	RING_API_REGISTER("bmath_maxd",ring_bmath_maxd);
	RING_API_REGISTER("bmath_minf",ring_bmath_minf);
	RING_API_REGISTER("bmath_mind",ring_bmath_mind);
	RING_API_REGISTER("bmath_clampf",ring_bmath_clampf);
	RING_API_REGISTER("bmath_clampd",ring_bmath_clampd);
	RING_API_REGISTER("bmath_modf",ring_bmath_modf);
	RING_API_REGISTER("bmath_modd",ring_bmath_modd);
	RING_API_REGISTER("bmath_modff",ring_bmath_modff);
	RING_API_REGISTER("bmath_modfd",ring_bmath_modfd);
	RING_API_REGISTER("bmath_precf",ring_bmath_precf);
	RING_API_REGISTER("bmath_precd",ring_bmath_precd);
	RING_API_REGISTER("bmath_roundf",ring_bmath_roundf);
	RING_API_REGISTER("bmath_roundd",ring_bmath_roundd);
	RING_API_REGISTER("bmath_round_stepf",ring_bmath_round_stepf);
	RING_API_REGISTER("bmath_round_stepd",ring_bmath_round_stepd);
	RING_API_REGISTER("bmath_floorf",ring_bmath_floorf);
	RING_API_REGISTER("bmath_floord",ring_bmath_floord);
	RING_API_REGISTER("bmath_ceilf",ring_bmath_ceilf);
	RING_API_REGISTER("bmath_ceild",ring_bmath_ceild);
	RING_API_REGISTER("bmath_rand_seed",ring_bmath_rand_seed);
	RING_API_REGISTER("bmath_randf",ring_bmath_randf);
	RING_API_REGISTER("bmath_randd",ring_bmath_randd);
	RING_API_REGISTER("bmath_randi",ring_bmath_randi);
	RING_API_REGISTER("bmath_rand_env",ring_bmath_rand_env);
	RING_API_REGISTER("bmath_rand_destroy",ring_bmath_rand_destroy);
	RING_API_REGISTER("bmath_rand_mtf",ring_bmath_rand_mtf);
	RING_API_REGISTER("bmath_rand_mtd",ring_bmath_rand_mtd);
	RING_API_REGISTER("bmath_rand_mti",ring_bmath_rand_mti);
}

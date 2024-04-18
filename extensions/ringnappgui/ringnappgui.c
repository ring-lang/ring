
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


RING_FUNC(ring_blib_strlen)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strlen((char_t *) RING_API_GETCPOINTER(1,"char_t")));
}


RING_FUNC(ring_blib_strstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETCPOINTER(blib_strstr((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t")),"char_t");
}


RING_FUNC(ring_blib_strcpy)
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
	blib_strcpy((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_blib_strncpy)
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
	blib_strncpy((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_blib_strcat)
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
	blib_strcat((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_blib_strcmp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(blib_strcmp((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t")));
}


RING_FUNC(ring_blib_strncmp)
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
	RING_API_RETNUMBER(blib_strncmp((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_blib_strftime)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETNUMBER(blib_strftime((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (const int16_t  *) RING_API_GETCPOINTER(4,"const int16_t"),* (const uint8_t  *) RING_API_GETCPOINTER(5,"const uint8_t"),* (const uint8_t  *) RING_API_GETCPOINTER(6,"const uint8_t"),* (const uint8_t  *) RING_API_GETCPOINTER(7,"const uint8_t"),* (const uint8_t  *) RING_API_GETCPOINTER(8,"const uint8_t"),* (const uint8_t  *) RING_API_GETCPOINTER(9,"const uint8_t"),* (const uint8_t  *) RING_API_GETCPOINTER(10,"const uint8_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"int16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint8_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"uint8_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"uint8_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(8))
		RING_API_FREE(RING_API_GETCPOINTER(8,"uint8_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(9))
		RING_API_FREE(RING_API_GETCPOINTER(9,"uint8_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(10))
		RING_API_FREE(RING_API_GETCPOINTER(10,"uint8_t"));
}


RING_FUNC(ring_blib_strtol)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strtol((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"), (uint32_t ) RING_API_GETNUMBER(3),(bool_t *) RING_API_GETCPOINTER(4,"bool_t")));
}


RING_FUNC(ring_blib_strtoul)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(blib_strtoul((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"), (uint32_t ) RING_API_GETNUMBER(3),(bool_t *) RING_API_GETCPOINTER(4,"bool_t")));
}


RING_FUNC(ring_blib_strtof)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = blib_strtof((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"),(bool_t *) RING_API_GETCPOINTER(3,"bool_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_blib_strtod)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = blib_strtod((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"),(bool_t *) RING_API_GETCPOINTER(3,"bool_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_blib_qsort)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_qsort((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (FPtr_compare  *) RING_API_GETCPOINTER(4,"FPtr_compare"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_compare"));
}


RING_FUNC(ring_blib_qsort_ex)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_qsort_ex((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (FPtr_compare_ex  *) RING_API_GETCPOINTER(4,"FPtr_compare_ex"),(byte_t *) RING_API_GETCPOINTER(5,"byte_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_compare_ex"));
}


RING_FUNC(ring_blib_bsearch)
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = blib_bsearch((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (FPtr_compare  *) RING_API_GETCPOINTER(5,"FPtr_compare"),(uint32_t *) RING_API_GETCPOINTER(6,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"FPtr_compare"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_blib_bsearch_ex)
{
	if ( RING_API_PARACOUNT != 7 ) {
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = blib_bsearch_ex((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (FPtr_compare_ex  *) RING_API_GETCPOINTER(5,"FPtr_compare_ex"),(byte_t *) RING_API_GETCPOINTER(6,"byte_t"),(uint32_t *) RING_API_GETCPOINTER(7,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"FPtr_compare_ex"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_blib_getenv)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(blib_getenv((char_t *) RING_API_GETCPOINTER(1,"char_t")),"char_t");
}


RING_FUNC(ring_blib_abort)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	blib_abort();
}


RING_FUNC(ring_blib_exit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	blib_exit( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_blib_debug_break)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	blib_debug_break();
}


RING_FUNC(ring_oswindow_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(oswindow_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSWindow");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_oswindow_managed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oswindow_managed((void *) RING_API_GETCPOINTER(1,"void")),"OSWindow");
}


RING_FUNC(ring_oswindow_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_destroy((OSWindow **) RING_API_GETCPOINTER2POINTER(1,"OSWindow"));
}


RING_FUNC(ring_oswindow_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_OnMoved((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oswindow_OnResize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_OnResize((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oswindow_OnClose)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_OnClose((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oswindow_title)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_title((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_oswindow_edited)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_edited((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oswindow_movable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_movable((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oswindow_z_order)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_z_order((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_alpha)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_alpha((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_oswindow_enable_mouse_events)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_enable_mouse_events((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oswindow_hotkey)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_hotkey((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(Listener *) RING_API_GETCPOINTER(4,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_oswindow_taborder)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_taborder((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
}


RING_FUNC(ring_oswindow_tabcycle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_tabcycle((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oswindow_tabstop)
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
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = oswindow_tabstop((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_oswindow_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = oswindow_focus((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_oswindow_get_focus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oswindow_get_focus((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow")),"OSControl");
}


RING_FUNC(ring_oswindow_info_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
		gui_tab_t *pValue ; 
		pValue = (gui_tab_t *) RING_API_MALLOC(sizeof(gui_tab_t)) ;
		*pValue = oswindow_info_focus((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_tab_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_oswindow_attach_panel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_attach_panel((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oswindow_detach_panel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_detach_panel((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oswindow_attach_window)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_attach_window((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_detach_window)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_detach_window((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_launch)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_launch((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_hide)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_hide((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_oswindow_launch_modal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(oswindow_launch_modal((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow")));
}


RING_FUNC(ring_oswindow_stop_modal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_stop_modal((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_oswindow_get_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_get_origin((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oswindow_origin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_origin((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oswindow_get_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_get_size((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oswindow_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oswindow_size((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oswindow_set_default_pushbutton)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_set_default_pushbutton((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(OSButton *) RING_API_GETCPOINTER(2,"OSButton"));
}


RING_FUNC(ring_oswindow_set_cursor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	oswindow_set_cursor((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(Cursor *) RING_API_GETCPOINTER(2,"Cursor"));
}


RING_FUNC(ring_oswindow_property)
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
	oswindow_property((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),* (const gui_prop_t  *) RING_API_GETCPOINTER(2,"const gui_prop_t"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_prop_t"));
}


RING_FUNC(ring_osview_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osview_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSView");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osview_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_destroy((OSView **) RING_API_GETCPOINTER2POINTER(1,"OSView"));
}


RING_FUNC(ring_osview_OnDraw)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnDraw((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnOverlay)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnOverlay((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnEnter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnEnter((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnExit)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnExit((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnMoved((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnDown((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnUp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnUp((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnClick((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnDrag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnDrag((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnWheel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnWheel((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnKeyDown)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnKeyDown((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnKeyUp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnKeyUp((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnFocus((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnResignFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnResignFocus((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnAcceptFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnAcceptFocus((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_OnScroll)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_OnScroll((OSView *) RING_API_GETCPOINTER(1,"OSView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osview_scroll)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroll((OSView *) RING_API_GETCPOINTER(1,"OSView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_scroll_get)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroll_get((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_scroller_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroller_size((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_scroller_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_scroller_visible((OSView *) RING_API_GETCPOINTER(1,"OSView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_osview_content_size)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_content_size((OSView *) RING_API_GETCPOINTER(1,"OSView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osview_scale_factor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = osview_scale_factor((OSView *) RING_API_GETCPOINTER(1,"OSView"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osview_set_need_display)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_set_need_display((OSView *) RING_API_GETCPOINTER(1,"OSView"));
}


RING_FUNC(ring_osview_get_native_view)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osview_get_native_view((OSView *) RING_API_GETCPOINTER(1,"OSView")),"void");
}


RING_FUNC(ring_osview_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_attach((OSView *) RING_API_GETCPOINTER(1,"OSView"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osview_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osview_detach((OSView *) RING_API_GETCPOINTER(1,"OSView"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osview_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_visible((OSView *) RING_API_GETCPOINTER(1,"OSView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osview_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_enabled((OSView *) RING_API_GETCPOINTER(1,"OSView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osview_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_size((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_origin((OSView *) RING_API_GETCPOINTER(1,"OSView"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osview_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osview_frame((OSView *) RING_API_GETCPOINTER(1,"OSView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osupdown_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osupdown_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSUpDown");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osupdown_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_destroy((OSUpDown **) RING_API_GETCPOINTER2POINTER(1,"OSUpDown"));
}


RING_FUNC(ring_osupdown_OnClick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osupdown_OnClick((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osupdown_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osupdown_tooltip((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_osupdown_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osupdown_attach((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osupdown_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osupdown_detach((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osupdown_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_visible((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osupdown_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_enabled((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osupdown_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_size((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osupdown_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_origin((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osupdown_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osupdown_frame((OSUpDown *) RING_API_GETCPOINTER(1,"OSUpDown"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_ostext_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(ostext_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSText");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_ostext_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_destroy((OSText **) RING_API_GETCPOINTER2POINTER(1,"OSText"));
}


RING_FUNC(ring_ostext_OnFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ostext_OnFilter((OSText *) RING_API_GETCPOINTER(1,"OSText"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ostext_OnFocus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ostext_OnFocus((OSText *) RING_API_GETCPOINTER(1,"OSText"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ostext_insert_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ostext_insert_text((OSText *) RING_API_GETCPOINTER(1,"OSText"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_ostext_set_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ostext_set_text((OSText *) RING_API_GETCPOINTER(1,"OSText"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_ostext_set_rtf)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ostext_set_rtf((OSText *) RING_API_GETCPOINTER(1,"OSText"),(Stream *) RING_API_GETCPOINTER(2,"Stream"));
}


RING_FUNC(ring_ostext_property)
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
	ostext_property((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const gui_text_t  *) RING_API_GETCPOINTER(2,"const gui_text_t"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_text_t"));
}


RING_FUNC(ring_ostext_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_editable((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ostext_get_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(ostext_get_text((OSText *) RING_API_GETCPOINTER(1,"OSText")),"char_t");
}


RING_FUNC(ring_ostext_scroller_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_scroller_visible((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_ostext_set_need_display)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_set_need_display((OSText *) RING_API_GETCPOINTER(1,"OSText"));
}


RING_FUNC(ring_ostext_clipboard)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_clipboard((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const clipboard_t  *) RING_API_GETCPOINTER(2,"const clipboard_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"clipboard_t"));
}


RING_FUNC(ring_ostext_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ostext_attach((OSText *) RING_API_GETCPOINTER(1,"OSText"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ostext_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ostext_detach((OSText *) RING_API_GETCPOINTER(1,"OSText"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ostext_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_visible((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ostext_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_enabled((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ostext_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_size((OSText *) RING_API_GETCPOINTER(1,"OSText"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ostext_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_origin((OSText *) RING_API_GETCPOINTER(1,"OSText"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ostext_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ostext_frame((OSText *) RING_API_GETCPOINTER(1,"OSText"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_ossplit_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(ossplit_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSSplit");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_ossplit_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_destroy((OSSplit **) RING_API_GETCPOINTER2POINTER(1,"OSSplit"));
}


RING_FUNC(ring_ossplit_attach_control)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ossplit_attach_control((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
}


RING_FUNC(ring_ossplit_detach_control)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ossplit_detach_control((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSControl *) RING_API_GETCPOINTER(2,"OSControl"));
}


RING_FUNC(ring_ossplit_OnDrag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ossplit_OnDrag((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ossplit_track_area)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_track_area((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_ossplit_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ossplit_attach((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ossplit_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ossplit_detach((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ossplit_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_visible((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ossplit_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_enabled((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ossplit_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_size((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ossplit_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_origin((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ossplit_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ossplit_frame((OSSplit *) RING_API_GETCPOINTER(1,"OSSplit"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osslider_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osslider_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSSlider");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osslider_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_destroy((OSSlider **) RING_API_GETCPOINTER2POINTER(1,"OSSlider"));
}


RING_FUNC(ring_osslider_OnMoved)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osslider_OnMoved((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osslider_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osslider_tooltip((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_osslider_tickmarks)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_tickmarks((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_osslider_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_position((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_osslider_get_position)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = osslider_get_position((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osslider_bounds)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_bounds((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const gui_size_t  *) RING_API_GETCPOINTER(3,"const gui_size_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"gui_size_t"));
}


RING_FUNC(ring_osslider_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osslider_attach((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osslider_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osslider_detach((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osslider_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_visible((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osslider_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_enabled((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osslider_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_size((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osslider_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_origin((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osslider_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osslider_frame((OSSlider *) RING_API_GETCPOINTER(1,"OSSlider"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osprogress_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osprogress_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSProgress");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osprogress_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_destroy((OSProgress **) RING_API_GETCPOINTER2POINTER(1,"OSProgress"));
}


RING_FUNC(ring_osprogress_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_position((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_osprogress_thickness)
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
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = osprogress_thickness((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),* (const gui_size_t  *) RING_API_GETCPOINTER(2,"const gui_size_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_size_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osprogress_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osprogress_attach((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osprogress_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	osprogress_detach((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osprogress_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_visible((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osprogress_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_enabled((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osprogress_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_size((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osprogress_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_origin((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osprogress_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osprogress_frame((OSProgress *) RING_API_GETCPOINTER(1,"OSProgress"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_ospopup_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(ospopup_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSPopUp");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_ospopup_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_destroy((OSPopUp **) RING_API_GETCPOINTER2POINTER(1,"OSPopUp"));
}


RING_FUNC(ring_ospopup_OnSelect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ospopup_OnSelect((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_ospopup_elem)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_elem((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),* (const ctrl_op_t  *) RING_API_GETCPOINTER(2,"const ctrl_op_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t"),(Image *) RING_API_GETCPOINTER(5,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ctrl_op_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_ospopup_tooltip)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ospopup_tooltip((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_ospopup_font)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ospopup_font((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_ospopup_list_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_list_height((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_ospopup_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_selected((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_ospopup_get_selected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(ospopup_get_selected((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp")));
}


RING_FUNC(ring_ospopup_bounds)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_bounds((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_ospopup_attach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ospopup_attach((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospopup_detach)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	ospopup_detach((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospopup_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_visible((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ospopup_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_enabled((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ospopup_size)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_size((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospopup_origin)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_origin((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospopup_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospopup_frame((OSPopUp *) RING_API_GETCPOINTER(1,"OSPopUp"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
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
	RING_API_REGISTER("blib_strlen",ring_blib_strlen);
	RING_API_REGISTER("blib_strstr",ring_blib_strstr);
	RING_API_REGISTER("blib_strcpy",ring_blib_strcpy);
	RING_API_REGISTER("blib_strncpy",ring_blib_strncpy);
	RING_API_REGISTER("blib_strcat",ring_blib_strcat);
	RING_API_REGISTER("blib_strcmp",ring_blib_strcmp);
	RING_API_REGISTER("blib_strncmp",ring_blib_strncmp);
	RING_API_REGISTER("blib_strftime",ring_blib_strftime);
	RING_API_REGISTER("blib_strtol",ring_blib_strtol);
	RING_API_REGISTER("blib_strtoul",ring_blib_strtoul);
	RING_API_REGISTER("blib_strtof",ring_blib_strtof);
	RING_API_REGISTER("blib_strtod",ring_blib_strtod);
	RING_API_REGISTER("blib_qsort",ring_blib_qsort);
	RING_API_REGISTER("blib_qsort_ex",ring_blib_qsort_ex);
	RING_API_REGISTER("blib_bsearch",ring_blib_bsearch);
	RING_API_REGISTER("blib_bsearch_ex",ring_blib_bsearch_ex);
	RING_API_REGISTER("blib_getenv",ring_blib_getenv);
	RING_API_REGISTER("blib_abort",ring_blib_abort);
	RING_API_REGISTER("blib_exit",ring_blib_exit);
	RING_API_REGISTER("blib_debug_break",ring_blib_debug_break);
	RING_API_REGISTER("oswindow_create",ring_oswindow_create);
	RING_API_REGISTER("oswindow_managed",ring_oswindow_managed);
	RING_API_REGISTER("oswindow_destroy",ring_oswindow_destroy);
	RING_API_REGISTER("oswindow_onmoved",ring_oswindow_OnMoved);
	RING_API_REGISTER("oswindow_onresize",ring_oswindow_OnResize);
	RING_API_REGISTER("oswindow_onclose",ring_oswindow_OnClose);
	RING_API_REGISTER("oswindow_title",ring_oswindow_title);
	RING_API_REGISTER("oswindow_edited",ring_oswindow_edited);
	RING_API_REGISTER("oswindow_movable",ring_oswindow_movable);
	RING_API_REGISTER("oswindow_z_order",ring_oswindow_z_order);
	RING_API_REGISTER("oswindow_alpha",ring_oswindow_alpha);
	RING_API_REGISTER("oswindow_enable_mouse_events",ring_oswindow_enable_mouse_events);
	RING_API_REGISTER("oswindow_hotkey",ring_oswindow_hotkey);
	RING_API_REGISTER("oswindow_taborder",ring_oswindow_taborder);
	RING_API_REGISTER("oswindow_tabcycle",ring_oswindow_tabcycle);
	RING_API_REGISTER("oswindow_tabstop",ring_oswindow_tabstop);
	RING_API_REGISTER("oswindow_focus",ring_oswindow_focus);
	RING_API_REGISTER("oswindow_get_focus",ring_oswindow_get_focus);
	RING_API_REGISTER("oswindow_info_focus",ring_oswindow_info_focus);
	RING_API_REGISTER("oswindow_attach_panel",ring_oswindow_attach_panel);
	RING_API_REGISTER("oswindow_detach_panel",ring_oswindow_detach_panel);
	RING_API_REGISTER("oswindow_attach_window",ring_oswindow_attach_window);
	RING_API_REGISTER("oswindow_detach_window",ring_oswindow_detach_window);
	RING_API_REGISTER("oswindow_launch",ring_oswindow_launch);
	RING_API_REGISTER("oswindow_hide",ring_oswindow_hide);
	RING_API_REGISTER("oswindow_launch_modal",ring_oswindow_launch_modal);
	RING_API_REGISTER("oswindow_stop_modal",ring_oswindow_stop_modal);
	RING_API_REGISTER("oswindow_get_origin",ring_oswindow_get_origin);
	RING_API_REGISTER("oswindow_origin",ring_oswindow_origin);
	RING_API_REGISTER("oswindow_get_size",ring_oswindow_get_size);
	RING_API_REGISTER("oswindow_size",ring_oswindow_size);
	RING_API_REGISTER("oswindow_set_default_pushbutton",ring_oswindow_set_default_pushbutton);
	RING_API_REGISTER("oswindow_set_cursor",ring_oswindow_set_cursor);
	RING_API_REGISTER("oswindow_property",ring_oswindow_property);
	RING_API_REGISTER("osview_create",ring_osview_create);
	RING_API_REGISTER("osview_destroy",ring_osview_destroy);
	RING_API_REGISTER("osview_ondraw",ring_osview_OnDraw);
	RING_API_REGISTER("osview_onoverlay",ring_osview_OnOverlay);
	RING_API_REGISTER("osview_onenter",ring_osview_OnEnter);
	RING_API_REGISTER("osview_onexit",ring_osview_OnExit);
	RING_API_REGISTER("osview_onmoved",ring_osview_OnMoved);
	RING_API_REGISTER("osview_ondown",ring_osview_OnDown);
	RING_API_REGISTER("osview_onup",ring_osview_OnUp);
	RING_API_REGISTER("osview_onclick",ring_osview_OnClick);
	RING_API_REGISTER("osview_ondrag",ring_osview_OnDrag);
	RING_API_REGISTER("osview_onwheel",ring_osview_OnWheel);
	RING_API_REGISTER("osview_onkeydown",ring_osview_OnKeyDown);
	RING_API_REGISTER("osview_onkeyup",ring_osview_OnKeyUp);
	RING_API_REGISTER("osview_onfocus",ring_osview_OnFocus);
	RING_API_REGISTER("osview_onresignfocus",ring_osview_OnResignFocus);
	RING_API_REGISTER("osview_onacceptfocus",ring_osview_OnAcceptFocus);
	RING_API_REGISTER("osview_onscroll",ring_osview_OnScroll);
	RING_API_REGISTER("osview_scroll",ring_osview_scroll);
	RING_API_REGISTER("osview_scroll_get",ring_osview_scroll_get);
	RING_API_REGISTER("osview_scroller_size",ring_osview_scroller_size);
	RING_API_REGISTER("osview_scroller_visible",ring_osview_scroller_visible);
	RING_API_REGISTER("osview_content_size",ring_osview_content_size);
	RING_API_REGISTER("osview_scale_factor",ring_osview_scale_factor);
	RING_API_REGISTER("osview_set_need_display",ring_osview_set_need_display);
	RING_API_REGISTER("osview_get_native_view",ring_osview_get_native_view);
	RING_API_REGISTER("osview_attach",ring_osview_attach);
	RING_API_REGISTER("osview_detach",ring_osview_detach);
	RING_API_REGISTER("osview_visible",ring_osview_visible);
	RING_API_REGISTER("osview_enabled",ring_osview_enabled);
	RING_API_REGISTER("osview_size",ring_osview_size);
	RING_API_REGISTER("osview_origin",ring_osview_origin);
	RING_API_REGISTER("osview_frame",ring_osview_frame);
	RING_API_REGISTER("osupdown_create",ring_osupdown_create);
	RING_API_REGISTER("osupdown_destroy",ring_osupdown_destroy);
	RING_API_REGISTER("osupdown_onclick",ring_osupdown_OnClick);
	RING_API_REGISTER("osupdown_tooltip",ring_osupdown_tooltip);
	RING_API_REGISTER("osupdown_attach",ring_osupdown_attach);
	RING_API_REGISTER("osupdown_detach",ring_osupdown_detach);
	RING_API_REGISTER("osupdown_visible",ring_osupdown_visible);
	RING_API_REGISTER("osupdown_enabled",ring_osupdown_enabled);
	RING_API_REGISTER("osupdown_size",ring_osupdown_size);
	RING_API_REGISTER("osupdown_origin",ring_osupdown_origin);
	RING_API_REGISTER("osupdown_frame",ring_osupdown_frame);
	RING_API_REGISTER("ostext_create",ring_ostext_create);
	RING_API_REGISTER("ostext_destroy",ring_ostext_destroy);
	RING_API_REGISTER("ostext_onfilter",ring_ostext_OnFilter);
	RING_API_REGISTER("ostext_onfocus",ring_ostext_OnFocus);
	RING_API_REGISTER("ostext_insert_text",ring_ostext_insert_text);
	RING_API_REGISTER("ostext_set_text",ring_ostext_set_text);
	RING_API_REGISTER("ostext_set_rtf",ring_ostext_set_rtf);
	RING_API_REGISTER("ostext_property",ring_ostext_property);
	RING_API_REGISTER("ostext_editable",ring_ostext_editable);
	RING_API_REGISTER("ostext_get_text",ring_ostext_get_text);
	RING_API_REGISTER("ostext_scroller_visible",ring_ostext_scroller_visible);
	RING_API_REGISTER("ostext_set_need_display",ring_ostext_set_need_display);
	RING_API_REGISTER("ostext_clipboard",ring_ostext_clipboard);
	RING_API_REGISTER("ostext_attach",ring_ostext_attach);
	RING_API_REGISTER("ostext_detach",ring_ostext_detach);
	RING_API_REGISTER("ostext_visible",ring_ostext_visible);
	RING_API_REGISTER("ostext_enabled",ring_ostext_enabled);
	RING_API_REGISTER("ostext_size",ring_ostext_size);
	RING_API_REGISTER("ostext_origin",ring_ostext_origin);
	RING_API_REGISTER("ostext_frame",ring_ostext_frame);
	RING_API_REGISTER("ossplit_create",ring_ossplit_create);
	RING_API_REGISTER("ossplit_destroy",ring_ossplit_destroy);
	RING_API_REGISTER("ossplit_attach_control",ring_ossplit_attach_control);
	RING_API_REGISTER("ossplit_detach_control",ring_ossplit_detach_control);
	RING_API_REGISTER("ossplit_ondrag",ring_ossplit_OnDrag);
	RING_API_REGISTER("ossplit_track_area",ring_ossplit_track_area);
	RING_API_REGISTER("ossplit_attach",ring_ossplit_attach);
	RING_API_REGISTER("ossplit_detach",ring_ossplit_detach);
	RING_API_REGISTER("ossplit_visible",ring_ossplit_visible);
	RING_API_REGISTER("ossplit_enabled",ring_ossplit_enabled);
	RING_API_REGISTER("ossplit_size",ring_ossplit_size);
	RING_API_REGISTER("ossplit_origin",ring_ossplit_origin);
	RING_API_REGISTER("ossplit_frame",ring_ossplit_frame);
	RING_API_REGISTER("osslider_create",ring_osslider_create);
	RING_API_REGISTER("osslider_destroy",ring_osslider_destroy);
	RING_API_REGISTER("osslider_onmoved",ring_osslider_OnMoved);
	RING_API_REGISTER("osslider_tooltip",ring_osslider_tooltip);
	RING_API_REGISTER("osslider_tickmarks",ring_osslider_tickmarks);
	RING_API_REGISTER("osslider_position",ring_osslider_position);
	RING_API_REGISTER("osslider_get_position",ring_osslider_get_position);
	RING_API_REGISTER("osslider_bounds",ring_osslider_bounds);
	RING_API_REGISTER("osslider_attach",ring_osslider_attach);
	RING_API_REGISTER("osslider_detach",ring_osslider_detach);
	RING_API_REGISTER("osslider_visible",ring_osslider_visible);
	RING_API_REGISTER("osslider_enabled",ring_osslider_enabled);
	RING_API_REGISTER("osslider_size",ring_osslider_size);
	RING_API_REGISTER("osslider_origin",ring_osslider_origin);
	RING_API_REGISTER("osslider_frame",ring_osslider_frame);
	RING_API_REGISTER("osprogress_create",ring_osprogress_create);
	RING_API_REGISTER("osprogress_destroy",ring_osprogress_destroy);
	RING_API_REGISTER("osprogress_position",ring_osprogress_position);
	RING_API_REGISTER("osprogress_thickness",ring_osprogress_thickness);
	RING_API_REGISTER("osprogress_attach",ring_osprogress_attach);
	RING_API_REGISTER("osprogress_detach",ring_osprogress_detach);
	RING_API_REGISTER("osprogress_visible",ring_osprogress_visible);
	RING_API_REGISTER("osprogress_enabled",ring_osprogress_enabled);
	RING_API_REGISTER("osprogress_size",ring_osprogress_size);
	RING_API_REGISTER("osprogress_origin",ring_osprogress_origin);
	RING_API_REGISTER("osprogress_frame",ring_osprogress_frame);
	RING_API_REGISTER("ospopup_create",ring_ospopup_create);
	RING_API_REGISTER("ospopup_destroy",ring_ospopup_destroy);
	RING_API_REGISTER("ospopup_onselect",ring_ospopup_OnSelect);
	RING_API_REGISTER("ospopup_elem",ring_ospopup_elem);
	RING_API_REGISTER("ospopup_tooltip",ring_ospopup_tooltip);
	RING_API_REGISTER("ospopup_font",ring_ospopup_font);
	RING_API_REGISTER("ospopup_list_height",ring_ospopup_list_height);
	RING_API_REGISTER("ospopup_selected",ring_ospopup_selected);
	RING_API_REGISTER("ospopup_get_selected",ring_ospopup_get_selected);
	RING_API_REGISTER("ospopup_bounds",ring_ospopup_bounds);
	RING_API_REGISTER("ospopup_attach",ring_ospopup_attach);
	RING_API_REGISTER("ospopup_detach",ring_ospopup_detach);
	RING_API_REGISTER("ospopup_visible",ring_ospopup_visible);
	RING_API_REGISTER("ospopup_enabled",ring_ospopup_enabled);
	RING_API_REGISTER("ospopup_size",ring_ospopup_size);
	RING_API_REGISTER("ospopup_origin",ring_ospopup_origin);
	RING_API_REGISTER("ospopup_frame",ring_ospopup_frame);
}

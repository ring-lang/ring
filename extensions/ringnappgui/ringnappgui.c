
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


RING_FUNC(ring_ospanel_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(ospanel_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSPanel");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_ospanel_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_destroy((OSPanel **) RING_API_GETCPOINTER2POINTER(1,"OSPanel"));
}


RING_FUNC(ring_ospanel_area)
{
	if ( RING_API_PARACOUNT != 8 ) {
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
	ospanel_area((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(void *) RING_API_GETCPOINTER(2,"void"),* (const color_t  *) RING_API_GETCPOINTER(3,"const color_t"),* (const color_t  *) RING_API_GETCPOINTER(4,"const color_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(6,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(7,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(8,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(8))
		RING_API_FREE(RING_API_GETCPOINTER(8,"real32_t"));
}


RING_FUNC(ring_ospanel_scroller_size)
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
	ospanel_scroller_size((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospanel_content_size)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_content_size((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_ospanel_display)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_display((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"));
}


RING_FUNC(ring_ospanel_attach)
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
	ospanel_attach((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospanel_detach)
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
	ospanel_detach((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_ospanel_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_visible((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ospanel_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_enabled((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_ospanel_size)
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
	ospanel_size((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospanel_origin)
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
	ospanel_origin((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_ospanel_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ospanel_frame((OSPanel *) RING_API_GETCPOINTER(1,"OSPanel"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osmenuitem_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osmenuitem_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSMenuItem");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osmenuitem_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_destroy((OSMenuItem **) RING_API_GETCPOINTER2POINTER(1,"OSMenuItem"));
}


RING_FUNC(ring_osmenuitem_OnClick)
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
	osmenuitem_OnClick((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osmenuitem_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_enabled((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osmenuitem_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_visible((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osmenuitem_text)
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
	osmenuitem_text((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_osmenuitem_image)
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
	osmenuitem_image((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_osmenuitem_key)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_key((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_osmenuitem_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenuitem_state((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_osmenuitem_submenu)
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
	osmenuitem_submenu((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(OSMenu *) RING_API_GETCPOINTER(2,"OSMenu"));
}


RING_FUNC(ring_osmenuitem_unset_submenu)
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
	osmenuitem_unset_submenu((OSMenuItem *) RING_API_GETCPOINTER(1,"OSMenuItem"),(OSMenu *) RING_API_GETCPOINTER(2,"OSMenu"));
}


RING_FUNC(ring_osmenu_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osmenu_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSMenu");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osmenu_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenu_destroy((OSMenu **) RING_API_GETCPOINTER2POINTER(1,"OSMenu"));
}


RING_FUNC(ring_osmenu_add_item)
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
	osmenu_add_item((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSMenuItem *) RING_API_GETCPOINTER(2,"OSMenuItem"));
}


RING_FUNC(ring_osmenu_delete_item)
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
	osmenu_delete_item((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSMenuItem *) RING_API_GETCPOINTER(2,"OSMenuItem"));
}


RING_FUNC(ring_osmenu_launch)
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
	osmenu_launch((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_osmenu_hide)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osmenu_hide((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"));
}


RING_FUNC(ring_oslabel_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(oslabel_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSLabel");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_oslabel_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_destroy((OSLabel **) RING_API_GETCPOINTER2POINTER(1,"OSLabel"));
}


RING_FUNC(ring_oslabel_OnClick)
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
	oslabel_OnClick((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oslabel_OnEnter)
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
	oslabel_OnEnter((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oslabel_OnExit)
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
	oslabel_OnExit((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oslabel_text)
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
	oslabel_text((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_oslabel_font)
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
	oslabel_font((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_oslabel_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_align((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_oslabel_ellipsis)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_ellipsis((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const ellipsis_t  *) RING_API_GETCPOINTER(2,"const ellipsis_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ellipsis_t"));
}


RING_FUNC(ring_oslabel_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_color((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oslabel_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_bgcolor((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oslabel_bounds)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_bounds((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oslabel_attach)
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
	oslabel_attach((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oslabel_detach)
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
	oslabel_detach((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oslabel_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_visible((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oslabel_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_enabled((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oslabel_size)
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
	oslabel_size((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oslabel_origin)
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
	oslabel_origin((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oslabel_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oslabel_frame((OSLabel *) RING_API_GETCPOINTER(1,"OSLabel"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osguictx)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(osguictx(),"GuiCtx");
}


RING_FUNC(ring_osgui_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osgui_start();
}


RING_FUNC(ring_osgui_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osgui_finish();
}


RING_FUNC(ring_osgui_set_menubar)
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
	osgui_set_menubar((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_osgui_unset_menubar)
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
	osgui_unset_menubar((OSMenu *) RING_API_GETCPOINTER(1,"OSMenu"),(OSWindow *) RING_API_GETCPOINTER(2,"OSWindow"));
}


RING_FUNC(ring_osgui_redraw_menubar)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osgui_redraw_menubar();
}


RING_FUNC(ring_osgui_message_loop)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osgui_message_loop();
}


RING_FUNC(ring_osgui_is_initialized)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = osgui_is_initialized();
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osgui_initialize)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osgui_initialize();
}


RING_FUNC(ring_osgui_terminate)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osgui_terminate();
}


RING_FUNC(ring_osgui_set_app)
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
	osgui_set_app((void *) RING_API_GETCPOINTER(1,"void"),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_osglobals_device)
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
		device_t *pValue ; 
		pValue = (device_t *) RING_API_MALLOC(sizeof(device_t)) ;
		*pValue = osglobals_device((void *) RING_API_GETCPOINTER(1,"void"));
		RING_API_RETMANAGEDCPOINTER(pValue,"device_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osglobals_color)
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
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = osglobals_color((syscolor_t *) RING_API_GETCPOINTER(1,"syscolor_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osglobals_resolution)
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
	osglobals_resolution((void *) RING_API_GETCPOINTER(1,"void"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osglobals_mouse_position)
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
	osglobals_mouse_position((void *) RING_API_GETCPOINTER(1,"void"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osglobals_cursor)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osglobals_cursor(* (const gui_cursor_t  *) RING_API_GETCPOINTER(1,"const gui_cursor_t"),(Image *) RING_API_GETCPOINTER(2,"Image"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t")),"Cursor");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"gui_cursor_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_osglobals_cursor_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_cursor_destroy((Cursor **) RING_API_GETCPOINTER2POINTER(1,"Cursor"));
}


RING_FUNC(ring_osglobals_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_value(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osglobals_transitions)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osglobals_transitions((void *) RING_API_GETCPOINTER(1,"void"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(3,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real64_t"));
}


RING_FUNC(ring_osglobals_OnIdle)
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
	osglobals_OnIdle((void *) RING_API_GETCPOINTER(1,"void"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osedit_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSEdit");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osedit_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_destroy((OSEdit **) RING_API_GETCPOINTER2POINTER(1,"OSEdit"));
}


RING_FUNC(ring_osedit_OnFilter)
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
	osedit_OnFilter((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_OnChange)
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
	osedit_OnChange((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_OnFocus)
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
	osedit_OnFocus((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osedit_text)
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
	osedit_text((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_osedit_tooltip)
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
	osedit_tooltip((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_osedit_font)
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
	osedit_font((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_osedit_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_align((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_osedit_passmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_passmode((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osedit_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_editable((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osedit_autoselect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_autoselect((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osedit_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_select((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
}


RING_FUNC(ring_osedit_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_color((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_osedit_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_bgcolor((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_osedit_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_vpadding((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_osedit_bounds)
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
	osedit_bounds((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_osedit_clipboard)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_clipboard((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const clipboard_t  *) RING_API_GETCPOINTER(2,"const clipboard_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"clipboard_t"));
}


RING_FUNC(ring_osedit_attach)
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
	osedit_attach((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osedit_detach)
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
	osedit_detach((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osedit_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_visible((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osedit_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_enabled((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osedit_size)
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
	osedit_size((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osedit_origin)
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
	osedit_origin((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osedit_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osedit_frame((OSEdit *) RING_API_GETCPOINTER(1,"OSEdit"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osdrawctrl_font)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(osdrawctrl_font((DCtx *) RING_API_GETCPOINTER(1,"DCtx")),"Font");
}


RING_FUNC(ring_osdrawctrl_row_padding)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osdrawctrl_row_padding((DCtx *) RING_API_GETCPOINTER(1,"DCtx")));
}


RING_FUNC(ring_osdrawctrl_check_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osdrawctrl_check_width((DCtx *) RING_API_GETCPOINTER(1,"DCtx")));
}


RING_FUNC(ring_osdrawctrl_check_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(osdrawctrl_check_height((DCtx *) RING_API_GETCPOINTER(1,"DCtx")));
}


RING_FUNC(ring_osdrawctrl_multisel)
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
		ctrl_msel_t *pValue ; 
		pValue = (ctrl_msel_t *) RING_API_MALLOC(sizeof(ctrl_msel_t)) ;
		*pValue = osdrawctrl_multisel((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ctrl_msel_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osdrawctrl_clear)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_clear((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const enum_t  *) RING_API_GETCPOINTER(6,"const enum_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"enum_t"));
}


RING_FUNC(ring_osdrawctrl_header)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_header((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_indicator)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_indicator((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const indicator_t  *) RING_API_GETCPOINTER(6,"const indicator_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"indicator_t"));
}


RING_FUNC(ring_osdrawctrl_fill)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_fill((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_focus)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_focus((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_line)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_line((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(4,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(5,"const int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"int32_t"));
}


RING_FUNC(ring_osdrawctrl_text)
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
	osdrawctrl_text((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(4,"const int32_t"),* (const ctrl_state_t  *) RING_API_GETCPOINTER(5,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_image)
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
	osdrawctrl_image((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),(Image *) RING_API_GETCPOINTER(2,"Image"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(4,"const int32_t"),* (const ctrl_state_t  *) RING_API_GETCPOINTER(5,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_checkbox)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_checkbox((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_osdrawctrl_uncheckbox)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osdrawctrl_uncheckbox((DCtx *) RING_API_GETCPOINTER(1,"DCtx"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(5,"const uint32_t"),* (const ctrl_state_t  *) RING_API_GETCPOINTER(6,"const ctrl_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ctrl_state_t"));
}


RING_FUNC(ring_oscomwin_file)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(oscomwin_file((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t"),* (const bool_t  *) RING_API_GETCPOINTER(5,"const bool_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"bool_t"));
}


RING_FUNC(ring_oscomwin_color)
{
	if ( RING_API_PARACOUNT != 10 ) {
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
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscomwin_color((OSWindow *) RING_API_GETCPOINTER(1,"OSWindow"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const align_t  *) RING_API_GETCPOINTER(5,"const align_t"),* (const align_t  *) RING_API_GETCPOINTER(6,"const align_t"),* (const color_t  *) RING_API_GETCPOINTER(7,"const color_t"),(color_t *) RING_API_GETCPOINTER(8,"color_t"),* (const uint32_t  *) RING_API_GETCPOINTER(9,"const uint32_t"),(Listener *) RING_API_GETCPOINTER(10,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(9))
		RING_API_FREE(RING_API_GETCPOINTER(9,"uint32_t"));
}


RING_FUNC(ring_oscombo_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(oscombo_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSCombo");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_oscombo_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_destroy((OSCombo **) RING_API_GETCPOINTER2POINTER(1,"OSCombo"));
}


RING_FUNC(ring_oscombo_OnFilter)
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
	oscombo_OnFilter((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_OnChange)
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
	oscombo_OnChange((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_OnFocus)
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
	oscombo_OnFocus((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_OnSelect)
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
	oscombo_OnSelect((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_oscombo_text)
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
	oscombo_text((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_oscombo_tooltip)
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
	oscombo_tooltip((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_oscombo_font)
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
	oscombo_font((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_oscombo_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_align((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_oscombo_passmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_passmode((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oscombo_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_color((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oscombo_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_bgcolor((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_oscombo_elem)
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
	oscombo_elem((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const ctrl_op_t  *) RING_API_GETCPOINTER(2,"const ctrl_op_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t"),(Image *) RING_API_GETCPOINTER(5,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ctrl_op_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_oscombo_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_selected((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_oscombo_get_selected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(oscombo_get_selected((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo")));
}


RING_FUNC(ring_oscombo_bounds)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_bounds((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"),(real32_t *) RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_oscombo_attach)
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
	oscombo_attach((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oscombo_detach)
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
	oscombo_detach((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_oscombo_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_visible((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oscombo_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_enabled((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_oscombo_size)
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
	oscombo_size((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oscombo_origin)
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
	oscombo_origin((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_oscombo_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	oscombo_frame((OSCombo *) RING_API_GETCPOINTER(1,"OSCombo"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osbutton_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(osbutton_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"OSButton");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_osbutton_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_destroy((OSButton **) RING_API_GETCPOINTER2POINTER(1,"OSButton"));
}


RING_FUNC(ring_osbutton_OnClick)
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
	osbutton_OnClick((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_osbutton_text)
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
	osbutton_text((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_osbutton_tooltip)
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
	osbutton_tooltip((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_osbutton_font)
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
	osbutton_font((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_osbutton_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_align((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_osbutton_image)
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
	osbutton_image((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_osbutton_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_state((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_osbutton_get_state)
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
		gui_state_t *pValue ; 
		pValue = (gui_state_t *) RING_API_MALLOC(sizeof(gui_state_t)) ;
		*pValue = osbutton_get_state((OSButton *) RING_API_GETCPOINTER(1,"OSButton"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_state_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osbutton_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_vpadding((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_osbutton_bounds)
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_bounds((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"),(real32_t *) RING_API_GETCPOINTER(6,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_osbutton_attach)
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
	osbutton_attach((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osbutton_detach)
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
	osbutton_detach((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(OSPanel *) RING_API_GETCPOINTER(2,"OSPanel"));
}


RING_FUNC(ring_osbutton_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_visible((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osbutton_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_enabled((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_osbutton_size)
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
	osbutton_size((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osbutton_origin)
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
	osbutton_origin((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_osbutton_frame)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osbutton_frame((OSButton *) RING_API_GETCPOINTER(1,"OSButton"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_osbs_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osbs_start();
}


RING_FUNC(ring_osbs_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osbs_finish();
}


RING_FUNC(ring_osbs_platform)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		platform_t *pValue ; 
		pValue = (platform_t *) RING_API_MALLOC(sizeof(platform_t)) ;
		*pValue = osbs_platform();
		RING_API_RETMANAGEDCPOINTER(pValue,"platform_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osbs_windows)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		win_t *pValue ; 
		pValue = (win_t *) RING_API_MALLOC(sizeof(win_t)) ;
		*pValue = osbs_windows();
		RING_API_RETMANAGEDCPOINTER(pValue,"win_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osbs_endian)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		endian_t *pValue ; 
		pValue = (endian_t *) RING_API_MALLOC(sizeof(endian_t)) ;
		*pValue = osbs_endian();
		RING_API_RETMANAGEDCPOINTER(pValue,"endian_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_log_output)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	log_output(* (const bool_t  *) RING_API_GETCPOINTER(1,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_log_file)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	log_file((char_t *) RING_API_GETCPOINTER(1,"char_t"));
}


RING_FUNC(ring_log_get_file)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(log_get_file(),"char_t");
}


RING_FUNC(ring_dlib_open)
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
	RING_API_RETCPOINTER(dlib_open((char_t *) RING_API_GETCPOINTER(1,"char_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t")),"DLib");
}


RING_FUNC(ring_dlib_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	dlib_close((DLib **) RING_API_GETCPOINTER2POINTER(1,"DLib"));
}


RING_FUNC(ring_dlib_proc_imp)
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
		FPtr_libproc *pValue ; 
		pValue = (FPtr_libproc *) RING_API_MALLOC(sizeof(FPtr_libproc)) ;
		*pValue = dlib_proc_imp((DLib *) RING_API_GETCPOINTER(1,"DLib"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"FPtr_libproc",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_dlib_var_imp)
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
	RING_API_RETCPOINTER(dlib_var_imp((DLib *) RING_API_GETCPOINTER(1,"DLib"),(char_t *) RING_API_GETCPOINTER(2,"char_t")),"void");
}


RING_FUNC(ring_btime_now)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(btime_now());
}


RING_FUNC(ring_btime_date)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	btime_date((Date *) RING_API_GETCPOINTER(1,"Date"));
}


RING_FUNC(ring_btime_to_micro)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(btime_to_micro((Date *) RING_API_GETCPOINTER(1,"Date")));
}


RING_FUNC(ring_btime_to_date)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	btime_to_date(* (const uint64_t  *) RING_API_GETCPOINTER(1,"const uint64_t"),(Date *) RING_API_GETCPOINTER(2,"Date"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint64_t"));
}


RING_FUNC(ring_bthread_create_imp)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bthread_create_imp(* (FPtr_thread_main  *) RING_API_GETCPOINTER(1,"FPtr_thread_main"),(void *) RING_API_GETCPOINTER(2,"void")),"Thread");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"FPtr_thread_main"));
}


RING_FUNC(ring_bthread_current_id)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(bthread_current_id());
}


RING_FUNC(ring_bthread_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bthread_close((Thread **) RING_API_GETCPOINTER2POINTER(1,"Thread"));
}


RING_FUNC(ring_bthread_cancel)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bthread_cancel((Thread *) RING_API_GETCPOINTER(1,"Thread"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bthread_wait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bthread_wait((Thread *) RING_API_GETCPOINTER(1,"Thread")));
}


RING_FUNC(ring_bthread_finish)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bthread_finish((Thread *) RING_API_GETCPOINTER(1,"Thread"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bthread_sleep)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	bthread_sleep(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_bsocket_connect)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_connect(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),* (const uint16_t  *) RING_API_GETCPOINTER(2,"const uint16_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(serror_t *) RING_API_GETCPOINTER(4,"serror_t")),"Socket");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bsocket_server)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_server(* (const uint16_t  *) RING_API_GETCPOINTER(1,"const uint16_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(serror_t *) RING_API_GETCPOINTER(3,"serror_t")),"Socket");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bsocket_accept)
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
	RING_API_RETCPOINTER(bsocket_accept((Socket *) RING_API_GETCPOINTER(1,"Socket"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(serror_t *) RING_API_GETCPOINTER(3,"serror_t")),"Socket");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bsocket_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_close((Socket **) RING_API_GETCPOINTER2POINTER(1,"Socket"));
}


RING_FUNC(ring_bsocket_local_ip)
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
	bsocket_local_ip((Socket *) RING_API_GETCPOINTER(1,"Socket"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),(uint16_t *) RING_API_GETCPOINTER(3,"uint16_t"));
}


RING_FUNC(ring_bsocket_remote_ip)
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
	bsocket_remote_ip((Socket *) RING_API_GETCPOINTER(1,"Socket"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),(uint16_t *) RING_API_GETCPOINTER(3,"uint16_t"));
}


RING_FUNC(ring_bsocket_read_timeout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_read_timeout((Socket *) RING_API_GETCPOINTER(1,"Socket"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bsocket_write_timeout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bsocket_write_timeout((Socket *) RING_API_GETCPOINTER(1,"Socket"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bsocket_read)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bsocket_read((Socket *) RING_API_GETCPOINTER(1,"Socket"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(serror_t *) RING_API_GETCPOINTER(5,"serror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bsocket_write)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bsocket_write((Socket *) RING_API_GETCPOINTER(1,"Socket"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(serror_t *) RING_API_GETCPOINTER(5,"serror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bsocket_url_ip)
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
	RING_API_RETNUMBER(bsocket_url_ip((char_t *) RING_API_GETCPOINTER(1,"char_t"),(serror_t *) RING_API_GETCPOINTER(2,"serror_t")));
}


RING_FUNC(ring_bsocket_str_ip)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bsocket_str_ip((char_t *) RING_API_GETCPOINTER(1,"char_t")));
}


RING_FUNC(ring_bsocket_host_name)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_host_name((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bsocket_host_name_ip)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_host_name_ip(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_bsocket_ip_str)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(bsocket_ip_str(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_bsocket_hton2)
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
	bsocket_hton2((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"));
}


RING_FUNC(ring_bsocket_hton4)
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
	bsocket_hton4((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"));
}


RING_FUNC(ring_bsocket_hton8)
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
	bsocket_hton8((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"));
}


RING_FUNC(ring_bsocket_ntoh2)
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
	bsocket_ntoh2((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"));
}


RING_FUNC(ring_bsocket_ntoh4)
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
	bsocket_ntoh4((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"));
}


RING_FUNC(ring_bsocket_ntoh8)
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
	bsocket_ntoh8((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"));
}


RING_FUNC(ring_bproc_exec)
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
	RING_API_RETCPOINTER(bproc_exec((char_t *) RING_API_GETCPOINTER(1,"char_t"),(perror_t *) RING_API_GETCPOINTER(2,"perror_t")),"Proc");
}


RING_FUNC(ring_bproc_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bproc_close((Proc **) RING_API_GETCPOINTER2POINTER(1,"Proc"));
}


RING_FUNC(ring_bproc_cancel)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_cancel((Proc *) RING_API_GETCPOINTER(1,"Proc"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_wait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bproc_wait((Proc *) RING_API_GETCPOINTER(1,"Proc")));
}


RING_FUNC(ring_bproc_finish)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_finish((Proc *) RING_API_GETCPOINTER(1,"Proc"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_read)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_read((Proc *) RING_API_GETCPOINTER(1,"Proc"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(perror_t *) RING_API_GETCPOINTER(5,"perror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_eread)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_eread((Proc *) RING_API_GETCPOINTER(1,"Proc"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(perror_t *) RING_API_GETCPOINTER(5,"perror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_write)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_write((Proc *) RING_API_GETCPOINTER(1,"Proc"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(perror_t *) RING_API_GETCPOINTER(5,"perror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_read_close)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_read_close((Proc *) RING_API_GETCPOINTER(1,"Proc"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_eread_close)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_eread_close((Proc *) RING_API_GETCPOINTER(1,"Proc"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_write_close)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bproc_write_close((Proc *) RING_API_GETCPOINTER(1,"Proc"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bproc_exit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	bproc_exit(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_bmutex_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(bmutex_create(),"Mutex");
}


RING_FUNC(ring_bmutex_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmutex_close((Mutex **) RING_API_GETCPOINTER2POINTER(1,"Mutex"));
}


RING_FUNC(ring_bmutex_lock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmutex_lock((Mutex *) RING_API_GETCPOINTER(1,"Mutex"));
}


RING_FUNC(ring_bmutex_unlock)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bmutex_unlock((Mutex *) RING_API_GETCPOINTER(1,"Mutex"));
}


RING_FUNC(ring_bfile_dir_work)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_work((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bfile_dir_set_work)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_dir_set_work((char_t *) RING_API_GETCPOINTER(1,"char_t"),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_dir_home)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_home((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bfile_dir_data)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_data((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bfile_dir_exec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_dir_exec((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_bfile_dir_create)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_dir_create((char_t *) RING_API_GETCPOINTER(1,"char_t"),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_dir_open)
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
	RING_API_RETCPOINTER(bfile_dir_open((char_t *) RING_API_GETCPOINTER(1,"char_t"),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"Dir");
}


RING_FUNC(ring_bfile_dir_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bfile_dir_close((Dir **) RING_API_GETCPOINTER2POINTER(1,"Dir"));
}


RING_FUNC(ring_bfile_dir_get)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
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
		*pValue = bfile_dir_get((Dir *) RING_API_GETCPOINTER(1,"Dir"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(file_type_t *) RING_API_GETCPOINTER(4,"file_type_t"),(uint64_t *) RING_API_GETCPOINTER(5,"uint64_t"),(Date *) RING_API_GETCPOINTER(6,"Date"),(ferror_t *) RING_API_GETCPOINTER(7,"ferror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_dir_delete)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_dir_delete((char_t *) RING_API_GETCPOINTER(1,"char_t"),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_create)
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
	RING_API_RETCPOINTER(bfile_create((char_t *) RING_API_GETCPOINTER(1,"char_t"),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t")),"File");
}


RING_FUNC(ring_bfile_open)
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
	RING_API_RETCPOINTER(bfile_open((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const file_mode_t  *) RING_API_GETCPOINTER(2,"const file_mode_t"),(ferror_t *) RING_API_GETCPOINTER(3,"ferror_t")),"File");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"file_mode_t"));
}


RING_FUNC(ring_bfile_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	bfile_close((File **) RING_API_GETCPOINTER2POINTER(1,"File"));
}


RING_FUNC(ring_bfile_lstat)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_lstat((char_t *) RING_API_GETCPOINTER(1,"char_t"),(file_type_t *) RING_API_GETCPOINTER(2,"file_type_t"),(uint64_t *) RING_API_GETCPOINTER(3,"uint64_t"),(Date *) RING_API_GETCPOINTER(4,"Date"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_fstat)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_fstat((File *) RING_API_GETCPOINTER(1,"File"),(file_type_t *) RING_API_GETCPOINTER(2,"file_type_t"),(uint64_t *) RING_API_GETCPOINTER(3,"uint64_t"),(Date *) RING_API_GETCPOINTER(4,"Date"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_read)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_read((File *) RING_API_GETCPOINTER(1,"File"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_write)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_write((File *) RING_API_GETCPOINTER(1,"File"),(byte_t *) RING_API_GETCPOINTER(2,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(uint32_t *) RING_API_GETCPOINTER(4,"uint32_t"),(ferror_t *) RING_API_GETCPOINTER(5,"ferror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_seek)
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
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_seek((File *) RING_API_GETCPOINTER(1,"File"),* (const int64_t  *) RING_API_GETCPOINTER(2,"const int64_t"),* (const file_seek_t  *) RING_API_GETCPOINTER(3,"const file_seek_t"),(ferror_t *) RING_API_GETCPOINTER(4,"ferror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"file_seek_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_bfile_pos)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(bfile_pos((File *) RING_API_GETCPOINTER(1,"File")));
}


RING_FUNC(ring_bfile_delete)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = bfile_delete((char_t *) RING_API_GETCPOINTER(1,"char_t"),(ferror_t *) RING_API_GETCPOINTER(2,"ferror_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_osapp_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	osapp_finish();
}


RING_FUNC(ring_osapp_task_imp)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osapp_task_imp((void *) RING_API_GETCPOINTER(1,"void"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (FPtr_task_main  *) RING_API_GETCPOINTER(3,"FPtr_task_main"),* (FPtr_task_update  *) RING_API_GETCPOINTER(4,"FPtr_task_update"),* (FPtr_task_end  *) RING_API_GETCPOINTER(5,"FPtr_task_end"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_task_main"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"FPtr_task_update"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"FPtr_task_end"));
}


RING_FUNC(ring_osapp_menubar)
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
	osapp_menubar((Menu *) RING_API_GETCPOINTER(1,"Menu"),(Window *) RING_API_GETCPOINTER(2,"Window"));
}


RING_FUNC(ring_osapp_open_url)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	osapp_open_url((char_t *) RING_API_GETCPOINTER(1,"char_t"));
}


RING_FUNC(ring_url_parse)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_parse((char_t *) RING_API_GETCPOINTER(1,"char_t")),"Url");
}


RING_FUNC(ring_url_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	url_destroy((Url **) RING_API_GETCPOINTER2POINTER(1,"Url"));
}


RING_FUNC(ring_url_scheme)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_scheme((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_user)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_user((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_pass)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_pass((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_host)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_host((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_path)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_path((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_params)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_params((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_query)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_query((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_fragment)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_fragment((Url *) RING_API_GETCPOINTER(1,"Url")),"char_t");
}


RING_FUNC(ring_url_resource)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(url_resource((Url *) RING_API_GETCPOINTER(1,"Url")),"String");
}


RING_FUNC(ring_url_port)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(url_port((Url *) RING_API_GETCPOINTER(1,"Url")));
}


RING_FUNC(ring_json_read_imp)
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
	RING_API_RETCPOINTER(json_read_imp((Stream *) RING_API_GETCPOINTER(1,"Stream"),(JsonOpts *) RING_API_GETCPOINTER(2,"JsonOpts"),(char_t *) RING_API_GETCPOINTER(3,"char_t")),"void");
}


RING_FUNC(ring_json_write_imp)
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
	json_write_imp((Stream *) RING_API_GETCPOINTER(1,"Stream"),(void *) RING_API_GETCPOINTER(2,"void"),(JsonOpts *) RING_API_GETCPOINTER(3,"JsonOpts"),(char_t *) RING_API_GETCPOINTER(4,"char_t"));
}


RING_FUNC(ring_json_destroy_imp)
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
	json_destroy_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_json_destopt_imp)
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
	json_destopt_imp((void **) RING_API_GETCPOINTER2POINTER(1,"void"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_inet_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	inet_start();
}


RING_FUNC(ring_inet_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	inet_finish();
}


RING_FUNC(ring_http_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_create((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(2,"const uint16_t")),"Http");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint16_t"));
}


RING_FUNC(ring_http_secure)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_secure((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(2,"const uint16_t")),"Http");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint16_t"));
}


RING_FUNC(ring_http_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	http_destroy((Http **) RING_API_GETCPOINTER2POINTER(1,"Http"));
}


RING_FUNC(ring_http_clear_headers)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	http_clear_headers((Http *) RING_API_GETCPOINTER(1,"Http"));
}


RING_FUNC(ring_http_add_header)
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
	http_add_header((Http *) RING_API_GETCPOINTER(1,"Http"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"));
}


RING_FUNC(ring_http_get)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = http_get((Http *) RING_API_GETCPOINTER(1,"Http"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(byte_t *) RING_API_GETCPOINTER(3,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),(ierror_t *) RING_API_GETCPOINTER(5,"ierror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_http_post)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = http_post((Http *) RING_API_GETCPOINTER(1,"Http"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(byte_t *) RING_API_GETCPOINTER(3,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),(ierror_t *) RING_API_GETCPOINTER(5,"ierror_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_http_response_status)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_response_status((Http *) RING_API_GETCPOINTER(1,"Http")));
}


RING_FUNC(ring_http_response_protocol)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_response_protocol((Http *) RING_API_GETCPOINTER(1,"Http")),"char_t");
}


RING_FUNC(ring_http_response_message)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_response_message((Http *) RING_API_GETCPOINTER(1,"Http")),"char_t");
}


RING_FUNC(ring_http_response_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(http_response_size((Http *) RING_API_GETCPOINTER(1,"Http")));
}


RING_FUNC(ring_http_response_name)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_response_name((Http *) RING_API_GETCPOINTER(1,"Http"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_http_response_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(http_response_value((Http *) RING_API_GETCPOINTER(1,"Http"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_http_response_header)
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
	RING_API_RETCPOINTER(http_response_header((Http *) RING_API_GETCPOINTER(1,"Http"),(char_t *) RING_API_GETCPOINTER(2,"char_t")),"char_t");
}


RING_FUNC(ring_http_response_body)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = http_response_body((Http *) RING_API_GETCPOINTER(1,"Http"),(Stream *) RING_API_GETCPOINTER(2,"Stream"),(ierror_t *) RING_API_GETCPOINTER(3,"ierror_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_http_dget)
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
	RING_API_RETCPOINTER(http_dget((char_t *) RING_API_GETCPOINTER(1,"char_t"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),(ierror_t *) RING_API_GETCPOINTER(3,"ierror_t")),"Stream");
}


RING_FUNC(ring_http_exists)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = http_exists((char_t *) RING_API_GETCPOINTER(1,"char_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_b64_encoded_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(b64_encoded_size(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_b64_decoded_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(b64_decoded_size(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_b64_encode)
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
	RING_API_RETNUMBER(b64_encode((byte_t *) RING_API_GETCPOINTER(1,"byte_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_b64_decode)
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
	RING_API_RETNUMBER(b64_decode((char_t *) RING_API_GETCPOINTER(1,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(byte_t *) RING_API_GETCPOINTER(3,"byte_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_window_create)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(window_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t")),"Window");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
}


RING_FUNC(ring_window_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_destroy((Window **) RING_API_GETCPOINTER2POINTER(1,"Window"));
}


RING_FUNC(ring_window_panel)
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
	window_panel((Window *) RING_API_GETCPOINTER(1,"Window"),(Panel *) RING_API_GETCPOINTER(2,"Panel"));
}


RING_FUNC(ring_window_OnClose)
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
	window_OnClose((Window *) RING_API_GETCPOINTER(1,"Window"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_window_OnMoved)
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
	window_OnMoved((Window *) RING_API_GETCPOINTER(1,"Window"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_window_OnResize)
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
	window_OnResize((Window *) RING_API_GETCPOINTER(1,"Window"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_window_title)
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
	window_title((Window *) RING_API_GETCPOINTER(1,"Window"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_window_show)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_show((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_hide)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_hide((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_overlay)
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
	window_overlay((Window *) RING_API_GETCPOINTER(1,"Window"),(Window *) RING_API_GETCPOINTER(2,"Window"));
}


RING_FUNC(ring_window_modal)
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
	RING_API_RETNUMBER(window_modal((Window *) RING_API_GETCPOINTER(1,"Window"),(Window *) RING_API_GETCPOINTER(2,"Window")));
}


RING_FUNC(ring_window_stop_modal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_stop_modal((Window *) RING_API_GETCPOINTER(1,"Window"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_window_hotkey)
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
	window_hotkey((Window *) RING_API_GETCPOINTER(1,"Window"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(Listener *) RING_API_GETCPOINTER(4,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_window_clear_hotkeys)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_clear_hotkeys((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_cycle_tabstop)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_cycle_tabstop((Window *) RING_API_GETCPOINTER(1,"Window"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_window_next_tabstop)
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
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = window_next_tabstop((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_previous_tabstop)
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
		gui_focus_t *pValue ; 
		pValue = (gui_focus_t *) RING_API_MALLOC(sizeof(gui_focus_t)) ;
		*pValue = window_previous_tabstop((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_focus)
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
		*pValue = window_focus((Window *) RING_API_GETCPOINTER(1,"Window"),(GuiControl *) RING_API_GETCPOINTER(2,"GuiControl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_focus_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_get_focus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(window_get_focus((Window *) RING_API_GETCPOINTER(1,"Window")),"GuiControl");
}


RING_FUNC(ring_window_focus_info)
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
	window_focus_info((Window *) RING_API_GETCPOINTER(1,"Window"),(FocusInfo *) RING_API_GETCPOINTER(2,"FocusInfo"));
}


RING_FUNC(ring_window_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_update((Window *) RING_API_GETCPOINTER(1,"Window"));
}


RING_FUNC(ring_window_origin)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_origin((Window *) RING_API_GETCPOINTER(1,"Window"),* (const V2Df  *) RING_API_GETCPOINTER(2,"const V2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"V2Df"));
}


RING_FUNC(ring_window_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	window_size((Window *) RING_API_GETCPOINTER(1,"Window"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_window_get_origin)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = window_get_origin((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_get_size)
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
		S2Df *pValue ; 
		pValue = (S2Df *) RING_API_MALLOC(sizeof(S2Df)) ;
		*pValue = window_get_size((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"S2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_get_client_size)
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
		S2Df *pValue ; 
		pValue = (S2Df *) RING_API_MALLOC(sizeof(S2Df)) ;
		*pValue = window_get_client_size((Window *) RING_API_GETCPOINTER(1,"Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"S2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_control_frame)
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
		R2Df *pValue ; 
		pValue = (R2Df *) RING_API_MALLOC(sizeof(R2Df)) ;
		*pValue = window_control_frame((Window *) RING_API_GETCPOINTER(1,"Window"),(GuiControl *) RING_API_GETCPOINTER(2,"GuiControl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"R2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_client_to_screen)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = window_client_to_screen((Window *) RING_API_GETCPOINTER(1,"Window"),* (const V2Df  *) RING_API_GETCPOINTER(2,"const V2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_window_defbutton)
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
	window_defbutton((Window *) RING_API_GETCPOINTER(1,"Window"),(Button *) RING_API_GETCPOINTER(2,"Button"));
}


RING_FUNC(ring_window_cursor)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	window_cursor((Window *) RING_API_GETCPOINTER(1,"Window"),* (const gui_cursor_t  *) RING_API_GETCPOINTER(2,"const gui_cursor_t"),(Image *) RING_API_GETCPOINTER(3,"Image"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_cursor_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_window_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(window_imp((Window *) RING_API_GETCPOINTER(1,"Window")),"void");
}


RING_FUNC(ring_view_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(view_create(),"View");
}


RING_FUNC(ring_view_scroll)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(view_scroll(),"View");
}


RING_FUNC(ring_view_custom)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETCPOINTER(view_custom(* (const bool_t  *) RING_API_GETCPOINTER(1,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t")),"View");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_view_data_imp)
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
	view_data_imp((View *) RING_API_GETCPOINTER(1,"View"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_view_get_data_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(view_get_data_imp((View *) RING_API_GETCPOINTER(1,"View")),"void");
}


RING_FUNC(ring_view_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_size((View *) RING_API_GETCPOINTER(1,"View"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_view_OnDraw)
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
	view_OnDraw((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnOverlay)
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
	view_OnOverlay((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnSize)
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
	view_OnSize((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnEnter)
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
	view_OnEnter((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnExit)
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
	view_OnExit((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnMove)
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
	view_OnMove((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnDown)
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
	view_OnDown((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnUp)
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
	view_OnUp((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnClick)
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
	view_OnClick((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnDrag)
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
	view_OnDrag((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnWheel)
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
	view_OnWheel((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnKeyDown)
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
	view_OnKeyDown((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnKeyUp)
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
	view_OnKeyUp((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnFocus)
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
	view_OnFocus((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnResignFocus)
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
	view_OnResignFocus((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnAcceptFocus)
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
	view_OnAcceptFocus((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_OnScroll)
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
	view_OnScroll((View *) RING_API_GETCPOINTER(1,"View"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_view_keybuf)
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
	view_keybuf((View *) RING_API_GETCPOINTER(1,"View"),(KeyBuf *) RING_API_GETCPOINTER(2,"KeyBuf"));
}


RING_FUNC(ring_view_get_size)
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
	view_get_size((View *) RING_API_GETCPOINTER(1,"View"),(S2Df *) RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_view_content_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_content_size((View *) RING_API_GETCPOINTER(1,"View"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"),* (const S2Df  *) RING_API_GETCPOINTER(3,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"S2Df"));
}


RING_FUNC(ring_view_scroll_x)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_scroll_x((View *) RING_API_GETCPOINTER(1,"View"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_view_scroll_y)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_scroll_y((View *) RING_API_GETCPOINTER(1,"View"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_view_scroll_size)
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
	view_scroll_size((View *) RING_API_GETCPOINTER(1,"View"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_view_scroll_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_scroll_visible((View *) RING_API_GETCPOINTER(1,"View"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_view_viewport)
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
	view_viewport((View *) RING_API_GETCPOINTER(1,"View"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(S2Df *) RING_API_GETCPOINTER(3,"S2Df"));
}


RING_FUNC(ring_view_point_scale)
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
	view_point_scale((View *) RING_API_GETCPOINTER(1,"View"),(real32_t *) RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_view_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	view_update((View *) RING_API_GETCPOINTER(1,"View"));
}


RING_FUNC(ring_view_native)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(view_native((View *) RING_API_GETCPOINTER(1,"View")),"void");
}


RING_FUNC(ring_updown_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(updown_create(),"UpDown");
}


RING_FUNC(ring_updown_OnClick)
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
	updown_OnClick((UpDown *) RING_API_GETCPOINTER(1,"UpDown"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_updown_tooltip)
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
	updown_tooltip((UpDown *) RING_API_GETCPOINTER(1,"UpDown"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_textview_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(textview_create(),"TextView");
}


RING_FUNC(ring_textview_OnFilter)
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
	textview_OnFilter((TextView *) RING_API_GETCPOINTER(1,"TextView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_textview_OnFocus)
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
	textview_OnFocus((TextView *) RING_API_GETCPOINTER(1,"TextView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_textview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_size((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_textview_clear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_clear((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_writef)
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
	textview_writef((TextView *) RING_API_GETCPOINTER(1,"TextView"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_textview_rtf)
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
	textview_rtf((TextView *) RING_API_GETCPOINTER(1,"TextView"),(Stream *) RING_API_GETCPOINTER(2,"Stream"));
}


RING_FUNC(ring_textview_units)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_units((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_textview_family)
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
	textview_family((TextView *) RING_API_GETCPOINTER(1,"TextView"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_textview_fsize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_fsize((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_textview_fstyle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_fstyle((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_textview_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_color((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_textview_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_bgcolor((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_textview_pgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_pgcolor((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_textview_halign)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_halign((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_textview_lspacing)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_lspacing((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_textview_bfspace)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_bfspace((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_textview_afspace)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_afspace((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_textview_scroll_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_scroll_visible((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_textview_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_editable((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_textview_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_select((TextView *) RING_API_GETCPOINTER(1,"TextView"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
}


RING_FUNC(ring_textview_scroll_caret)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_scroll_caret((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_get_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(textview_get_text((TextView *) RING_API_GETCPOINTER(1,"TextView")),"char_t");
}


RING_FUNC(ring_textview_copy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_copy((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_cut)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_cut((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_textview_paste)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	textview_paste((TextView *) RING_API_GETCPOINTER(1,"TextView"));
}


RING_FUNC(ring_tableview_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(tableview_create(),"TableView");
}


RING_FUNC(ring_tableview_OnData)
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
	tableview_OnData((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_OnSelect)
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
	tableview_OnSelect((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_OnRowClick)
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
	tableview_OnRowClick((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_OnHeaderClick)
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
	tableview_OnHeaderClick((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_tableview_font)
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
	tableview_font((TableView *) RING_API_GETCPOINTER(1,"TableView"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_tableview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_size((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (S2Df  *) RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_tableview_new_column_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tableview_new_column_text((TableView *) RING_API_GETCPOINTER(1,"TableView")));
}


RING_FUNC(ring_tableview_column_width)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_width((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_tableview_column_limits)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_limits((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_tableview_column_resizable)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_resizable((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_tableview_column_freeze)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_column_freeze((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_tableview_header_title)
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
	tableview_header_title((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_tableview_header_align)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_align((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const align_t  *) RING_API_GETCPOINTER(3,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"align_t"));
}


RING_FUNC(ring_tableview_header_indicator)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_indicator((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_tableview_header_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_visible((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_tableview_header_clickable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_clickable((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_tableview_header_resizable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_resizable((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_tableview_header_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_header_height((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_tableview_row_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_row_height((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_tableview_hkey_scroll)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_hkey_scroll((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_tableview_multisel)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_multisel((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_tableview_grid)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_grid((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_tableview_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_update((TableView *) RING_API_GETCPOINTER(1,"TableView"));
}


RING_FUNC(ring_tableview_select)
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
	tableview_select((TableView *) RING_API_GETCPOINTER(1,"TableView"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_tableview_deselect)
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
	tableview_deselect((TableView *) RING_API_GETCPOINTER(1,"TableView"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_tableview_deselect_all)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_deselect_all((TableView *) RING_API_GETCPOINTER(1,"TableView"));
}


RING_FUNC(ring_tableview_focus_row)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_focus_row((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const align_t  *) RING_API_GETCPOINTER(3,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"align_t"));
}


RING_FUNC(ring_tableview_get_focus_row)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(tableview_get_focus_row((TableView *) RING_API_GETCPOINTER(1,"TableView")));
}


RING_FUNC(ring_tableview_scroll_visible)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	tableview_scroll_visible((TableView *) RING_API_GETCPOINTER(1,"TableView"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_splitview_horizontal)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(splitview_horizontal(),"SplitView");
}


RING_FUNC(ring_splitview_vertical)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(splitview_vertical(),"SplitView");
}


RING_FUNC(ring_splitview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_size((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_splitview_view)
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
	splitview_view((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(View *) RING_API_GETCPOINTER(2,"View"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_splitview_text)
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
	splitview_text((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(TextView *) RING_API_GETCPOINTER(2,"TextView"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_splitview_split)
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
	splitview_split((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(SplitView *) RING_API_GETCPOINTER(2,"SplitView"));
}


RING_FUNC(ring_splitview_panel)
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
	splitview_panel((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),(Panel *) RING_API_GETCPOINTER(2,"Panel"));
}


RING_FUNC(ring_splitview_pos)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	splitview_pos((SplitView *) RING_API_GETCPOINTER(1,"SplitView"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_slider_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(slider_create(),"Slider");
}


RING_FUNC(ring_slider_vertical)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(slider_vertical(),"Slider");
}


RING_FUNC(ring_slider_OnMoved)
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
	slider_OnMoved((Slider *) RING_API_GETCPOINTER(1,"Slider"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_slider_tooltip)
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
	slider_tooltip((Slider *) RING_API_GETCPOINTER(1,"Slider"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_slider_steps)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	slider_steps((Slider *) RING_API_GETCPOINTER(1,"Slider"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_slider_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	slider_value((Slider *) RING_API_GETCPOINTER(1,"Slider"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_slider_get_value)
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
		*pValue = slider_get_value((Slider *) RING_API_GETCPOINTER(1,"Slider"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_res_gui_respack)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(res_gui_respack((char_t *) RING_API_GETCPOINTER(1,"char_t")),"ResPack");
}


RING_FUNC(ring_progress_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(progress_create(),"Progress");
}


RING_FUNC(ring_progress_undefined)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	progress_undefined((Progress *) RING_API_GETCPOINTER(1,"Progress"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_progress_value)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	progress_value((Progress *) RING_API_GETCPOINTER(1,"Progress"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_popup_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(popup_create(),"PopUp");
}


RING_FUNC(ring_popup_OnSelect)
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
	popup_OnSelect((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_popup_tooltip)
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
	popup_tooltip((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_popup_add_elem)
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
	popup_add_elem((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(Image *) RING_API_GETCPOINTER(3,"Image"));
}


RING_FUNC(ring_popup_set_elem)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_set_elem((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),(Image *) RING_API_GETCPOINTER(4,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_popup_clear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_clear((PopUp *) RING_API_GETCPOINTER(1,"PopUp"));
}


RING_FUNC(ring_popup_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(popup_count((PopUp *) RING_API_GETCPOINTER(1,"PopUp")));
}


RING_FUNC(ring_popup_list_height)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_list_height((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_popup_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	popup_selected((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_popup_get_selected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(popup_get_selected((PopUp *) RING_API_GETCPOINTER(1,"PopUp")));
}


RING_FUNC(ring_popup_get_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(popup_get_text((PopUp *) RING_API_GETCPOINTER(1,"PopUp"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_panel_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(panel_create(),"Panel");
}


RING_FUNC(ring_panel_scroll)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETCPOINTER(panel_scroll(* (const bool_t  *) RING_API_GETCPOINTER(1,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t")),"Panel");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_panel_custom)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_RETCPOINTER(panel_custom(* (const bool_t  *) RING_API_GETCPOINTER(1,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t")),"Panel");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_panel_data_imp)
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
	panel_data_imp((Panel *) RING_API_GETCPOINTER(1,"Panel"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"),* (FPtr_destroy  *) RING_API_GETCPOINTER(3,"FPtr_destroy"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"FPtr_destroy"));
}


RING_FUNC(ring_panel_get_data_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(panel_get_data_imp((Panel *) RING_API_GETCPOINTER(1,"Panel")),"void");
}


RING_FUNC(ring_panel_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	panel_size((Panel *) RING_API_GETCPOINTER(1,"Panel"),* (const S2Df  *) RING_API_GETCPOINTER(2,"const S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_panel_layout)
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
	RING_API_RETNUMBER(panel_layout((Panel *) RING_API_GETCPOINTER(1,"Panel"),(Layout *) RING_API_GETCPOINTER(2,"Layout")));
}


RING_FUNC(ring_panel_get_layout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(panel_get_layout((Panel *) RING_API_GETCPOINTER(1,"Panel"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"Layout");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_panel_visible_layout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	panel_visible_layout((Panel *) RING_API_GETCPOINTER(1,"Panel"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_panel_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	panel_update((Panel *) RING_API_GETCPOINTER(1,"Panel"));
}


RING_FUNC(ring_panel_scroll_width)
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
		*pValue = panel_scroll_width((Panel *) RING_API_GETCPOINTER(1,"Panel"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_panel_scroll_height)
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
		*pValue = panel_scroll_height((Panel *) RING_API_GETCPOINTER(1,"Panel"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_menuitem_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(menuitem_create(),"MenuItem");
}


RING_FUNC(ring_menuitem_separator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(menuitem_separator(),"MenuItem");
}


RING_FUNC(ring_menuitem_OnClick)
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
	menuitem_OnClick((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_menuitem_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_enabled((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_menuitem_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_visible((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_menuitem_text)
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
	menuitem_text((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_menuitem_image)
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
	menuitem_image((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_menuitem_key)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_key((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),* (const vkey_t  *) RING_API_GETCPOINTER(2,"const vkey_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"vkey_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_menuitem_submenu)
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
	menuitem_submenu((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),(Menu **) RING_API_GETCPOINTER2POINTER(2,"Menu"));
}


RING_FUNC(ring_menuitem_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menuitem_state((MenuItem *) RING_API_GETCPOINTER(1,"MenuItem"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_menu_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(menu_create(),"Menu");
}


RING_FUNC(ring_menu_destroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_destroy((Menu **) RING_API_GETCPOINTER2POINTER(1,"Menu"));
}


RING_FUNC(ring_menu_item)
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
	menu_item((Menu *) RING_API_GETCPOINTER(1,"Menu"),(MenuItem *) RING_API_GETCPOINTER(2,"MenuItem"));
}


RING_FUNC(ring_menu_launch)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_launch((Menu *) RING_API_GETCPOINTER(1,"Menu"),* (const V2Df  *) RING_API_GETCPOINTER(2,"const V2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"V2Df"));
}


RING_FUNC(ring_menu_hide)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_hide((Menu *) RING_API_GETCPOINTER(1,"Menu"));
}


RING_FUNC(ring_menu_off_items)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	menu_off_items((Menu *) RING_API_GETCPOINTER(1,"Menu"));
}


RING_FUNC(ring_menu_get_item)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(menu_get_item((Menu *) RING_API_GETCPOINTER(1,"Menu"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"MenuItem");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_menu_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(menu_size((Menu *) RING_API_GETCPOINTER(1,"Menu")));
}


RING_FUNC(ring_menu_imp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(menu_imp((Menu *) RING_API_GETCPOINTER(1,"Menu")),"void");
}


RING_FUNC(ring_listbox_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(listbox_create(),"ListBox");
}


RING_FUNC(ring_listbox_OnDown)
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
	listbox_OnDown((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_listbox_OnSelect)
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
	listbox_OnSelect((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_listbox_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_size((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (S2Df  *) RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_listbox_checkbox)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_checkbox((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_listbox_multisel)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_multisel((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_listbox_add_elem)
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
	listbox_add_elem((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(Image *) RING_API_GETCPOINTER(3,"Image"));
}


RING_FUNC(ring_listbox_set_elem)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_set_elem((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),(Image *) RING_API_GETCPOINTER(4,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_listbox_clear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_clear((ListBox *) RING_API_GETCPOINTER(1,"ListBox"));
}


RING_FUNC(ring_listbox_color)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_color((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const color_t  *) RING_API_GETCPOINTER(3,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"color_t"));
}


RING_FUNC(ring_listbox_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_select((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_listbox_check)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	listbox_check((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_listbox_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(listbox_count((ListBox *) RING_API_GETCPOINTER(1,"ListBox")));
}


RING_FUNC(ring_listbox_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(listbox_text((ListBox *) RING_API_GETCPOINTER(1,"ListBox"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_listbox_selected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = listbox_selected((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_listbox_checked)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = listbox_checked((ListBox *) RING_API_GETCPOINTER(1,"ListBox"), (uint32_t ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_layout_create)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETCPOINTER(layout_create(* (const uint32_t  *) RING_API_GETCPOINTER(1,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"Layout");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_layout_cell)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_cell((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Cell");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_control)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_control((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"GuiControl");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_label)
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
	layout_label((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Label *) RING_API_GETCPOINTER(2,"Label"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_button)
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
	layout_button((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Button *) RING_API_GETCPOINTER(2,"Button"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_popup)
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
	layout_popup((Layout *) RING_API_GETCPOINTER(1,"Layout"),(PopUp *) RING_API_GETCPOINTER(2,"PopUp"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_edit)
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
	layout_edit((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Edit *) RING_API_GETCPOINTER(2,"Edit"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_combo)
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
	layout_combo((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Combo *) RING_API_GETCPOINTER(2,"Combo"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_listbox)
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
	layout_listbox((Layout *) RING_API_GETCPOINTER(1,"Layout"),(ListBox *) RING_API_GETCPOINTER(2,"ListBox"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_updown)
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
	layout_updown((Layout *) RING_API_GETCPOINTER(1,"Layout"),(UpDown *) RING_API_GETCPOINTER(2,"UpDown"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_slider)
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
	layout_slider((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Slider *) RING_API_GETCPOINTER(2,"Slider"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_progress)
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
	layout_progress((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Progress *) RING_API_GETCPOINTER(2,"Progress"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_view)
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
	layout_view((Layout *) RING_API_GETCPOINTER(1,"Layout"),(View *) RING_API_GETCPOINTER(2,"View"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_textview)
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
	layout_textview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(TextView *) RING_API_GETCPOINTER(2,"TextView"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_imageview)
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
	layout_imageview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(ImageView *) RING_API_GETCPOINTER(2,"ImageView"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_tableview)
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
	layout_tableview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(TableView *) RING_API_GETCPOINTER(2,"TableView"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_splitview)
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
	layout_splitview((Layout *) RING_API_GETCPOINTER(1,"Layout"),(SplitView *) RING_API_GETCPOINTER(2,"SplitView"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_panel)
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
	layout_panel((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Panel *) RING_API_GETCPOINTER(2,"Panel"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_panel_replace)
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
	layout_panel_replace((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Panel *) RING_API_GETCPOINTER(2,"Panel"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_layout)
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
	layout_layout((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Layout *) RING_API_GETCPOINTER(2,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
}


RING_FUNC(ring_layout_get_label)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_label((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Label");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_button)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_button((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Button");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_popup)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_popup((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"PopUp");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_edit)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_edit((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Edit");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_combo)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_combo((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Combo");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_listbox)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_listbox((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"ListBox");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_updown)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_updown((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"UpDown");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_slider)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_slider((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Slider");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_progress)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_progress((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Progress");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_view)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_view((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"View");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_textview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_textview((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"TextView");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_imageview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_imageview((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"ImageView");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_tableview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_tableview((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"TableView");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_splitview)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_splitview((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"SplitView");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_panel)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_panel((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Panel");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_get_layout)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(layout_get_layout((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t")),"Layout");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_layout_ncols)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(layout_ncols((Layout *) RING_API_GETCPOINTER(1,"Layout")));
}


RING_FUNC(ring_layout_nrows)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(layout_nrows((Layout *) RING_API_GETCPOINTER(1,"Layout")));
}


RING_FUNC(ring_layout_insert_col)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_insert_col((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_layout_insert_row)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_insert_row((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_layout_remove_col)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_remove_col((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_layout_remove_row)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_remove_row((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_layout_taborder)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_taborder((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const gui_orient_t  *) RING_API_GETCPOINTER(2,"const gui_orient_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_orient_t"));
}


RING_FUNC(ring_layout_tabstop)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_tabstop((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const bool_t  *) RING_API_GETCPOINTER(4,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"bool_t"));
}


RING_FUNC(ring_layout_hsize)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hsize((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_layout_vsize)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vsize((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_layout_hmargin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hmargin((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_layout_vmargin)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vmargin((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_layout_hexpand)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hexpand((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_layout_hexpand2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hexpand2((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_layout_hexpand3)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_hexpand3((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(6,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"real32_t"));
}


RING_FUNC(ring_layout_vexpand)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vexpand((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_layout_vexpand2)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vexpand2((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
}


RING_FUNC(ring_layout_vexpand3)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_vexpand3((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(4,"const uint32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(6,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"real32_t"));
}


RING_FUNC(ring_layout_halign)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_halign((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const align_t  *) RING_API_GETCPOINTER(4,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"align_t"));
}


RING_FUNC(ring_layout_valign)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_valign((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),* (const align_t  *) RING_API_GETCPOINTER(4,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"align_t"));
}


RING_FUNC(ring_layout_show_col)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_show_col((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_layout_show_row)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_show_row((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),* (const bool_t  *) RING_API_GETCPOINTER(3,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"bool_t"));
}


RING_FUNC(ring_layout_margin)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_margin((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_layout_margin2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_margin2((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_layout_margin4)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_margin4((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_layout_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_bgcolor((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_layout_skcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_skcolor((Layout *) RING_API_GETCPOINTER(1,"Layout"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_layout_update)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_update((Layout *) RING_API_GETCPOINTER(1,"Layout"));
}


RING_FUNC(ring_layout_dbind_imp)
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
	layout_dbind_imp((Layout *) RING_API_GETCPOINTER(1,"Layout"),(Listener *) RING_API_GETCPOINTER(2,"Listener"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(4,"const uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"uint16_t"));
}


RING_FUNC(ring_layout_dbind_obj_imp)
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
	layout_dbind_obj_imp((Layout *) RING_API_GETCPOINTER(1,"Layout"),(void *) RING_API_GETCPOINTER(2,"void"),(char_t *) RING_API_GETCPOINTER(3,"char_t"));
}


RING_FUNC(ring_layout_dbind_update_imp)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	layout_dbind_update_imp((Layout *) RING_API_GETCPOINTER(1,"Layout"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(3,"const uint16_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t"),(char_t *) RING_API_GETCPOINTER(5,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(6,"const uint16_t"),* (const uint16_t  *) RING_API_GETCPOINTER(7,"const uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"uint16_t"));
}


RING_FUNC(ring_label_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(label_create(),"Label");
}


RING_FUNC(ring_label_multiline)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(label_multiline(),"Label");
}


RING_FUNC(ring_label_OnClick)
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
	label_OnClick((Label *) RING_API_GETCPOINTER(1,"Label"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_label_text)
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
	label_text((Label *) RING_API_GETCPOINTER(1,"Label"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_label_size_text)
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
	label_size_text((Label *) RING_API_GETCPOINTER(1,"Label"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_label_font)
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
	label_font((Label *) RING_API_GETCPOINTER(1,"Label"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_label_style_over)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_style_over((Label *) RING_API_GETCPOINTER(1,"Label"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_label_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_align((Label *) RING_API_GETCPOINTER(1,"Label"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_label_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_color((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_label_color_over)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_color_over((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_label_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_bgcolor((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_label_bgcolor_over)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	label_bgcolor_over((Label *) RING_API_GETCPOINTER(1,"Label"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_imageview_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(imageview_create(),"ImageView");
}


RING_FUNC(ring_imageview_size)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	imageview_size((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),* (S2Df  *) RING_API_GETCPOINTER(2,"S2Df"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"S2Df"));
}


RING_FUNC(ring_imageview_scale)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	imageview_scale((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),* (const gui_scale_t  *) RING_API_GETCPOINTER(2,"const gui_scale_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_scale_t"));
}


RING_FUNC(ring_imageview_image)
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
	imageview_image((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_imageview_OnClick)
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
	imageview_OnClick((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_imageview_OnOverDraw)
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
	imageview_OnOverDraw((ImageView *) RING_API_GETCPOINTER(1,"ImageView"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_guicontrol_label)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_label((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Label");
}


RING_FUNC(ring_guicontrol_button)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_button((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Button");
}


RING_FUNC(ring_guicontrol_popup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_popup((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"PopUp");
}


RING_FUNC(ring_guicontrol_edit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_edit((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Edit");
}


RING_FUNC(ring_guicontrol_combo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_combo((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Combo");
}


RING_FUNC(ring_guicontrol_listbox)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_listbox((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"ListBox");
}


RING_FUNC(ring_guicontrol_updown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_updown((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"UpDown");
}


RING_FUNC(ring_guicontrol_slider)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_slider((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Slider");
}


RING_FUNC(ring_guicontrol_progress)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_progress((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Progress");
}


RING_FUNC(ring_guicontrol_view)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_view((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"View");
}


RING_FUNC(ring_guicontrol_textview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_textview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"TextView");
}


RING_FUNC(ring_guicontrol_imageview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_imageview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"ImageView");
}


RING_FUNC(ring_guicontrol_tableview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_tableview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"TableView");
}


RING_FUNC(ring_guicontrol_splitview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_splitview((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"SplitView");
}


RING_FUNC(ring_guicontrol_panel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(guicontrol_panel((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")),"Panel");
}


RING_FUNC(ring_guicontrol_tag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	guicontrol_tag((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_guicontrol_get_tag)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(guicontrol_get_tag((GuiControl *) RING_API_GETCPOINTER(1,"GuiControl")));
}


RING_FUNC(ring_gui_start)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	gui_start();
}


RING_FUNC(ring_gui_finish)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	gui_finish();
}


RING_FUNC(ring_gui_respack)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	gui_respack(* (FPtr_respack  *) RING_API_GETCPOINTER(1,"FPtr_respack"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"FPtr_respack"));
}


RING_FUNC(ring_gui_language)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_language((char_t *) RING_API_GETCPOINTER(1,"char_t"));
}


RING_FUNC(ring_gui_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(gui_text(* (const ResId  *) RING_API_GETCPOINTER(1,"const ResId")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ResId"));
}


RING_FUNC(ring_gui_image)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(gui_image(* (const ResId  *) RING_API_GETCPOINTER(1,"const ResId")),"Image");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ResId"));
}


RING_FUNC(ring_gui_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(gui_file(* (const ResId  *) RING_API_GETCPOINTER(1,"const ResId"),(uint32_t *) RING_API_GETCPOINTER(2,"uint32_t")),"byte_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ResId"));
}


RING_FUNC(ring_gui_dark_mode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = gui_dark_mode();
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_alt_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_alt_color(* (const color_t  *) RING_API_GETCPOINTER(1,"const color_t"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_label_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_label_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_view_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_view_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_line_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_line_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_link_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_link_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_border_color)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		color_t *pValue ; 
		pValue = (color_t *) RING_API_MALLOC(sizeof(color_t)) ;
		*pValue = gui_border_color();
		RING_API_RETMANAGEDCPOINTER(pValue,"color_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_resolution)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		S2Df *pValue ; 
		pValue = (S2Df *) RING_API_MALLOC(sizeof(S2Df)) ;
		*pValue = gui_resolution();
		RING_API_RETMANAGEDCPOINTER(pValue,"S2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_mouse_pos)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = gui_mouse_pos();
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_gui_update)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	gui_update();
}


RING_FUNC(ring_gui_OnThemeChanged)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_OnThemeChanged((Listener *) RING_API_GETCPOINTER(1,"Listener"));
}


RING_FUNC(ring_gui_update_transitions)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	gui_update_transitions(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
}


RING_FUNC(ring_gui_OnNotification)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_OnNotification((Listener *) RING_API_GETCPOINTER(1,"Listener"));
}


RING_FUNC(ring_gui_OnIdle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	gui_OnIdle((Listener *) RING_API_GETCPOINTER(1,"Listener"));
}


RING_FUNC(ring_gui_info_window)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(gui_info_window(* (const bool_t  *) RING_API_GETCPOINTER(1,"const bool_t"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t"),(char_t *) RING_API_GETCPOINTER(5,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(6,"const uint32_t"),(ArrPt(String) *) RING_API_GETCPOINTER(7,"ArrPt(String)"),* (const uint32_t  *) RING_API_GETCPOINTER(8,"const uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(8))
		RING_API_FREE(RING_API_GETCPOINTER(8,"uint32_t"));
}


RING_FUNC(ring_evbind_object_imp)
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
	RING_API_RETCPOINTER(evbind_object_imp((Event *) RING_API_GETCPOINTER(1,"Event"),(char_t *) RING_API_GETCPOINTER(2,"char_t")),"void");
}


RING_FUNC(ring_evbind_modify_imp)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = evbind_modify_imp((Event *) RING_API_GETCPOINTER(1,"Event"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(3,"const uint16_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t"),(char_t *) RING_API_GETCPOINTER(5,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(6,"const uint16_t"),* (const uint16_t  *) RING_API_GETCPOINTER(7,"const uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"uint16_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_globals_device)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		device_t *pValue ; 
		pValue = (device_t *) RING_API_MALLOC(sizeof(device_t)) ;
		*pValue = globals_device();
		RING_API_RETMANAGEDCPOINTER(pValue,"device_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_globals_resolution)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	globals_resolution((S2Df *) RING_API_GETCPOINTER(1,"S2Df"));
}


RING_FUNC(ring_globals_mouse_position)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = globals_mouse_position();
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_edit_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(edit_create(),"Edit");
}


RING_FUNC(ring_edit_multiline)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(edit_multiline(),"Edit");
}


RING_FUNC(ring_edit_OnFilter)
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
	edit_OnFilter((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_edit_OnChange)
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
	edit_OnChange((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_edit_OnFocus)
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
	edit_OnFocus((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_edit_text)
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
	edit_text((Edit *) RING_API_GETCPOINTER(1,"Edit"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_edit_font)
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
	edit_font((Edit *) RING_API_GETCPOINTER(1,"Edit"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_edit_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_align((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_edit_passmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_passmode((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_edit_editable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_editable((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_edit_autoselect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_autoselect((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_edit_select)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_select((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const int32_t  *) RING_API_GETCPOINTER(2,"const int32_t"),* (const int32_t  *) RING_API_GETCPOINTER(3,"const int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"int32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"int32_t"));
}


RING_FUNC(ring_edit_tooltip)
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
	edit_tooltip((Edit *) RING_API_GETCPOINTER(1,"Edit"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_edit_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_color((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_color_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_color_focus((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_bgcolor((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_bgcolor_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_bgcolor_focus((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_phtext)
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
	edit_phtext((Edit *) RING_API_GETCPOINTER(1,"Edit"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_edit_phcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_phcolor((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_edit_phstyle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_phstyle((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_edit_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_vpadding((Edit *) RING_API_GETCPOINTER(1,"Edit"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_edit_get_text)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(edit_get_text((Edit *) RING_API_GETCPOINTER(1,"Edit")),"char_t");
}


RING_FUNC(ring_edit_get_height)
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
		*pValue = edit_get_height((Edit *) RING_API_GETCPOINTER(1,"Edit"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_edit_copy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_copy((Edit *) RING_API_GETCPOINTER(1,"Edit"));
}


RING_FUNC(ring_edit_cut)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_cut((Edit *) RING_API_GETCPOINTER(1,"Edit"));
}


RING_FUNC(ring_edit_paste)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	edit_paste((Edit *) RING_API_GETCPOINTER(1,"Edit"));
}


RING_FUNC(ring_comwin_open_file)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(comwin_open_file((Window *) RING_API_GETCPOINTER(1,"Window"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_comwin_save_file)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(comwin_save_file((Window *) RING_API_GETCPOINTER(1,"Window"),(char_t **) RING_API_GETCPOINTER2POINTER(2,"char_t"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_comwin_color)
{
	if ( RING_API_PARACOUNT != 10 ) {
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
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	comwin_color((Window *) RING_API_GETCPOINTER(1,"Window"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const align_t  *) RING_API_GETCPOINTER(5,"const align_t"),* (const align_t  *) RING_API_GETCPOINTER(6,"const align_t"),* (const color_t  *) RING_API_GETCPOINTER(7,"const color_t"),(color_t *) RING_API_GETCPOINTER(8,"color_t"),* (const uint32_t  *) RING_API_GETCPOINTER(9,"const uint32_t"),(Listener *) RING_API_GETCPOINTER(10,"Listener"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(9))
		RING_API_FREE(RING_API_GETCPOINTER(9,"uint32_t"));
}


RING_FUNC(ring_combo_create)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(combo_create(),"Combo");
}


RING_FUNC(ring_combo_OnFilter)
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
	combo_OnFilter((Combo *) RING_API_GETCPOINTER(1,"Combo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_combo_OnChange)
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
	combo_OnChange((Combo *) RING_API_GETCPOINTER(1,"Combo"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_combo_text)
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
	combo_text((Combo *) RING_API_GETCPOINTER(1,"Combo"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_combo_align)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_align((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const align_t  *) RING_API_GETCPOINTER(2,"const align_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"align_t"));
}


RING_FUNC(ring_combo_tooltip)
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
	combo_tooltip((Combo *) RING_API_GETCPOINTER(1,"Combo"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_combo_color)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_color((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_color_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_color_focus((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_bgcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_bgcolor((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_bgcolor_focus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_bgcolor_focus((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_phtext)
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
	combo_phtext((Combo *) RING_API_GETCPOINTER(1,"Combo"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_combo_phcolor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_phcolor((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const color_t  *) RING_API_GETCPOINTER(2,"const color_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"color_t"));
}


RING_FUNC(ring_combo_phstyle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_phstyle((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_combo_get_text)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(combo_get_text((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t")),"char_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_combo_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(combo_count((Combo *) RING_API_GETCPOINTER(1,"Combo")));
}


RING_FUNC(ring_combo_add_elem)
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
	combo_add_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),(Image *) RING_API_GETCPOINTER(3,"Image"));
}


RING_FUNC(ring_combo_set_elem)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_set_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),(Image *) RING_API_GETCPOINTER(4,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_combo_ins_elem)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_ins_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"),(char_t *) RING_API_GETCPOINTER(3,"char_t"),(Image *) RING_API_GETCPOINTER(4,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_combo_del_elem)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_del_elem((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_combo_duplicates)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	combo_duplicates((Combo *) RING_API_GETCPOINTER(1,"Combo"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_cell_empty)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = cell_empty((Cell *) RING_API_GETCPOINTER(1,"Cell"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_cell_control)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_control((Cell *) RING_API_GETCPOINTER(1,"Cell")),"GuiControl");
}


RING_FUNC(ring_cell_label)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_label((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Label");
}


RING_FUNC(ring_cell_button)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_button((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Button");
}


RING_FUNC(ring_cell_popup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_popup((Cell *) RING_API_GETCPOINTER(1,"Cell")),"PopUp");
}


RING_FUNC(ring_cell_edit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_edit((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Edit");
}


RING_FUNC(ring_cell_combo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_combo((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Combo");
}


RING_FUNC(ring_cell_listbox)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_listbox((Cell *) RING_API_GETCPOINTER(1,"Cell")),"ListBox");
}


RING_FUNC(ring_cell_updown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_updown((Cell *) RING_API_GETCPOINTER(1,"Cell")),"UpDown");
}


RING_FUNC(ring_cell_slider)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_slider((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Slider");
}


RING_FUNC(ring_cell_progress)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_progress((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Progress");
}


RING_FUNC(ring_cell_view)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_view((Cell *) RING_API_GETCPOINTER(1,"Cell")),"View");
}


RING_FUNC(ring_cell_textview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_textview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"TextView");
}


RING_FUNC(ring_cell_imageview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_imageview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"ImageView");
}


RING_FUNC(ring_cell_tableview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_tableview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"TableView");
}


RING_FUNC(ring_cell_splitview)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_splitview((Cell *) RING_API_GETCPOINTER(1,"Cell")),"SplitView");
}


RING_FUNC(ring_cell_panel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_panel((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Panel");
}


RING_FUNC(ring_cell_layout)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cell_layout((Cell *) RING_API_GETCPOINTER(1,"Cell")),"Layout");
}


RING_FUNC(ring_cell_enabled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_enabled((Cell *) RING_API_GETCPOINTER(1,"Cell"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_cell_visible)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_visible((Cell *) RING_API_GETCPOINTER(1,"Cell"),* (const bool_t  *) RING_API_GETCPOINTER(2,"const bool_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"bool_t"));
}


RING_FUNC(ring_cell_padding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_padding((Cell *) RING_API_GETCPOINTER(1,"Cell"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_cell_padding2)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_padding2((Cell *) RING_API_GETCPOINTER(1,"Cell"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
}


RING_FUNC(ring_cell_padding4)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_padding4((Cell *) RING_API_GETCPOINTER(1,"Cell"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
}


RING_FUNC(ring_cell_dbind_imp)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cell_dbind_imp((Cell *) RING_API_GETCPOINTER(1,"Cell"),(char_t *) RING_API_GETCPOINTER(2,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(3,"const uint16_t"),(char_t *) RING_API_GETCPOINTER(4,"char_t"),(char_t *) RING_API_GETCPOINTER(5,"char_t"),* (const uint16_t  *) RING_API_GETCPOINTER(6,"const uint16_t"),* (const uint16_t  *) RING_API_GETCPOINTER(7,"const uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"uint16_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"uint16_t"));
}


RING_FUNC(ring_button_push)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(button_push(),"Button");
}


RING_FUNC(ring_button_check)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(button_check(),"Button");
}


RING_FUNC(ring_button_check3)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(button_check3(),"Button");
}


RING_FUNC(ring_button_radio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(button_radio(),"Button");
}


RING_FUNC(ring_button_flat)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(button_flat(),"Button");
}


RING_FUNC(ring_button_flatgle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(button_flatgle(),"Button");
}


RING_FUNC(ring_button_OnClick)
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
	button_OnClick((Button *) RING_API_GETCPOINTER(1,"Button"),(Listener *) RING_API_GETCPOINTER(2,"Listener"));
}


RING_FUNC(ring_button_text)
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
	button_text((Button *) RING_API_GETCPOINTER(1,"Button"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_button_text_alt)
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
	button_text_alt((Button *) RING_API_GETCPOINTER(1,"Button"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_button_tooltip)
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
	button_tooltip((Button *) RING_API_GETCPOINTER(1,"Button"),(char_t *) RING_API_GETCPOINTER(2,"char_t"));
}


RING_FUNC(ring_button_font)
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
	button_font((Button *) RING_API_GETCPOINTER(1,"Button"),(Font *) RING_API_GETCPOINTER(2,"Font"));
}


RING_FUNC(ring_button_image)
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
	button_image((Button *) RING_API_GETCPOINTER(1,"Button"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_button_image_alt)
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
	button_image_alt((Button *) RING_API_GETCPOINTER(1,"Button"),(Image *) RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_button_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_state((Button *) RING_API_GETCPOINTER(1,"Button"),* (const gui_state_t  *) RING_API_GETCPOINTER(2,"const gui_state_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"gui_state_t"));
}


RING_FUNC(ring_button_tag)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_tag((Button *) RING_API_GETCPOINTER(1,"Button"),* (const uint32_t  *) RING_API_GETCPOINTER(2,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"uint32_t"));
}


RING_FUNC(ring_button_vpadding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	button_vpadding((Button *) RING_API_GETCPOINTER(1,"Button"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_button_get_state)
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
		gui_state_t *pValue ; 
		pValue = (gui_state_t *) RING_API_MALLOC(sizeof(gui_state_t)) ;
		*pValue = button_get_state((Button *) RING_API_GETCPOINTER(1,"Button"));
		RING_API_RETMANAGEDCPOINTER(pValue,"gui_state_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_button_get_tag)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(button_get_tag((Button *) RING_API_GETCPOINTER(1,"Button")));
}


RING_FUNC(ring_button_get_height)
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
		*pValue = button_get_height((Button *) RING_API_GETCPOINTER(1,"Button"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2df)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2df(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2dd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2dd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_tof)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_tof((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_tod)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_tod((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_tofn)
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
	v2d_tofn((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_v2d_todn)
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
	v2d_todn((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),* (const uint32_t  *) RING_API_GETCPOINTER(3,"const uint32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"uint32_t"));
}


RING_FUNC(ring_v2d_addf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_addf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_addd)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_addd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_subf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_subf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_subd)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_subd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_mulf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_mulf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_muld)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_muld((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_fromf)
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
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_fromf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_fromd)
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
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_fromd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),* (const real64_t  *) RING_API_GETCPOINTER(3,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_midf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_midf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_midd)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_midd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unitf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_unitf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(real32_t *) RING_API_GETCPOINTER(3,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unitd)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_unitd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(real64_t *) RING_API_GETCPOINTER(3,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unit_xyf)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_unit_xyf(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),(real32_t *) RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_unit_xyd)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_unit_xyd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(3,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(4,"const real64_t"),(real64_t *) RING_API_GETCPOINTER(5,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_posf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_perp_posf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_posd)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_perp_posd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_negf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_perp_negf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_perp_negd)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_perp_negd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_from_anglef)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = v2d_from_anglef(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_from_angled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = v2d_from_angled(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_normf)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = v2d_normf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_normd)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = v2d_normd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_lengthf)
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
		*pValue = v2d_lengthf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_lengthd)
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
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = v2d_lengthd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_sqlengthf)
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
		*pValue = v2d_sqlengthf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_sqlengthd)
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
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = v2d_sqlengthd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_dotf)
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
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = v2d_dotf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_dotd)
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
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = v2d_dotd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_distf)
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
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = v2d_distf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_distd)
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
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = v2d_distd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_sqdistf)
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
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = v2d_sqdistf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_sqdistd)
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
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = v2d_sqdistd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_anglef)
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
		real32_t *pValue ; 
		pValue = (real32_t *) RING_API_MALLOC(sizeof(real32_t)) ;
		*pValue = v2d_anglef((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_angled)
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
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = v2d_angled((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_v2d_rotatef)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	v2d_rotatef((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
}


RING_FUNC(ring_v2d_rotated)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	v2d_rotated((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
}


RING_FUNC(ring_tri2df)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Tri2Df *pValue ; 
		pValue = (Tri2Df *) RING_API_MALLOC(sizeof(Tri2Df)) ;
		*pValue = tri2df(* (const real32_t  *) RING_API_GETCPOINTER(1,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(2,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(3,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(4,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(5,"const real32_t"),* (const real32_t  *) RING_API_GETCPOINTER(6,"const real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real32_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"real32_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2dd)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Tri2Dd *pValue ; 
		pValue = (Tri2Dd *) RING_API_MALLOC(sizeof(Tri2Dd)) ;
		*pValue = tri2dd(* (const real64_t  *) RING_API_GETCPOINTER(1,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(2,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(3,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(4,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(5,"const real64_t"),* (const real64_t  *) RING_API_GETCPOINTER(6,"const real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"real64_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"real64_t"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_vf)
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
		Tri2Df *pValue ; 
		pValue = (Tri2Df *) RING_API_MALLOC(sizeof(Tri2Df)) ;
		*pValue = tri2d_vf((V2Df *) RING_API_GETCPOINTER(1,"V2Df"),(V2Df *) RING_API_GETCPOINTER(2,"V2Df"),(V2Df *) RING_API_GETCPOINTER(3,"V2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_vd)
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
		Tri2Dd *pValue ; 
		pValue = (Tri2Dd *) RING_API_MALLOC(sizeof(Tri2Dd)) ;
		*pValue = tri2d_vd((V2Dd *) RING_API_GETCPOINTER(1,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(2,"V2Dd"),(V2Dd *) RING_API_GETCPOINTER(3,"V2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Tri2Dd",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_transformf)
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
	tri2d_transformf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"),(T2Df *) RING_API_GETCPOINTER(2,"T2Df"));
}


RING_FUNC(ring_tri2d_transformd)
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
	tri2d_transformd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"),(T2Dd *) RING_API_GETCPOINTER(2,"T2Dd"));
}


RING_FUNC(ring_tri2d_areaf)
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
		*pValue = tri2d_areaf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real32_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_aread)
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
		real64_t *pValue ; 
		pValue = (real64_t *) RING_API_MALLOC(sizeof(real64_t)) ;
		*pValue = tri2d_aread((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"real64_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_ccwf)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = tri2d_ccwf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_ccwd)
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
		bool_t *pValue ; 
		pValue = (bool_t *) RING_API_MALLOC(sizeof(bool_t)) ;
		*pValue = tri2d_ccwd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"bool_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_centroidf)
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
		V2Df *pValue ; 
		pValue = (V2Df *) RING_API_MALLOC(sizeof(V2Df)) ;
		*pValue = tri2d_centroidf((Tri2Df *) RING_API_GETCPOINTER(1,"Tri2Df"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Df",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_tri2d_centroidd)
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
		V2Dd *pValue ; 
		pValue = (V2Dd *) RING_API_MALLOC(sizeof(V2Dd)) ;
		*pValue = tri2d_centroidd((Tri2Dd *) RING_API_GETCPOINTER(1,"Tri2Dd"));
		RING_API_RETMANAGEDCPOINTER(pValue,"V2Dd",RING_API_FREEFUNC);
	}
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
	RING_API_REGISTER("ospanel_create",ring_ospanel_create);
	RING_API_REGISTER("ospanel_destroy",ring_ospanel_destroy);
	RING_API_REGISTER("ospanel_area",ring_ospanel_area);
	RING_API_REGISTER("ospanel_scroller_size",ring_ospanel_scroller_size);
	RING_API_REGISTER("ospanel_content_size",ring_ospanel_content_size);
	RING_API_REGISTER("ospanel_display",ring_ospanel_display);
	RING_API_REGISTER("ospanel_attach",ring_ospanel_attach);
	RING_API_REGISTER("ospanel_detach",ring_ospanel_detach);
	RING_API_REGISTER("ospanel_visible",ring_ospanel_visible);
	RING_API_REGISTER("ospanel_enabled",ring_ospanel_enabled);
	RING_API_REGISTER("ospanel_size",ring_ospanel_size);
	RING_API_REGISTER("ospanel_origin",ring_ospanel_origin);
	RING_API_REGISTER("ospanel_frame",ring_ospanel_frame);
	RING_API_REGISTER("osmenuitem_create",ring_osmenuitem_create);
	RING_API_REGISTER("osmenuitem_destroy",ring_osmenuitem_destroy);
	RING_API_REGISTER("osmenuitem_onclick",ring_osmenuitem_OnClick);
	RING_API_REGISTER("osmenuitem_enabled",ring_osmenuitem_enabled);
	RING_API_REGISTER("osmenuitem_visible",ring_osmenuitem_visible);
	RING_API_REGISTER("osmenuitem_text",ring_osmenuitem_text);
	RING_API_REGISTER("osmenuitem_image",ring_osmenuitem_image);
	RING_API_REGISTER("osmenuitem_key",ring_osmenuitem_key);
	RING_API_REGISTER("osmenuitem_state",ring_osmenuitem_state);
	RING_API_REGISTER("osmenuitem_submenu",ring_osmenuitem_submenu);
	RING_API_REGISTER("osmenuitem_unset_submenu",ring_osmenuitem_unset_submenu);
	RING_API_REGISTER("osmenu_create",ring_osmenu_create);
	RING_API_REGISTER("osmenu_destroy",ring_osmenu_destroy);
	RING_API_REGISTER("osmenu_add_item",ring_osmenu_add_item);
	RING_API_REGISTER("osmenu_delete_item",ring_osmenu_delete_item);
	RING_API_REGISTER("osmenu_launch",ring_osmenu_launch);
	RING_API_REGISTER("osmenu_hide",ring_osmenu_hide);
	RING_API_REGISTER("oslabel_create",ring_oslabel_create);
	RING_API_REGISTER("oslabel_destroy",ring_oslabel_destroy);
	RING_API_REGISTER("oslabel_onclick",ring_oslabel_OnClick);
	RING_API_REGISTER("oslabel_onenter",ring_oslabel_OnEnter);
	RING_API_REGISTER("oslabel_onexit",ring_oslabel_OnExit);
	RING_API_REGISTER("oslabel_text",ring_oslabel_text);
	RING_API_REGISTER("oslabel_font",ring_oslabel_font);
	RING_API_REGISTER("oslabel_align",ring_oslabel_align);
	RING_API_REGISTER("oslabel_ellipsis",ring_oslabel_ellipsis);
	RING_API_REGISTER("oslabel_color",ring_oslabel_color);
	RING_API_REGISTER("oslabel_bgcolor",ring_oslabel_bgcolor);
	RING_API_REGISTER("oslabel_bounds",ring_oslabel_bounds);
	RING_API_REGISTER("oslabel_attach",ring_oslabel_attach);
	RING_API_REGISTER("oslabel_detach",ring_oslabel_detach);
	RING_API_REGISTER("oslabel_visible",ring_oslabel_visible);
	RING_API_REGISTER("oslabel_enabled",ring_oslabel_enabled);
	RING_API_REGISTER("oslabel_size",ring_oslabel_size);
	RING_API_REGISTER("oslabel_origin",ring_oslabel_origin);
	RING_API_REGISTER("oslabel_frame",ring_oslabel_frame);
	RING_API_REGISTER("osguictx",ring_osguictx);
	RING_API_REGISTER("osgui_start",ring_osgui_start);
	RING_API_REGISTER("osgui_finish",ring_osgui_finish);
	RING_API_REGISTER("osgui_set_menubar",ring_osgui_set_menubar);
	RING_API_REGISTER("osgui_unset_menubar",ring_osgui_unset_menubar);
	RING_API_REGISTER("osgui_redraw_menubar",ring_osgui_redraw_menubar);
	RING_API_REGISTER("osgui_message_loop",ring_osgui_message_loop);
	RING_API_REGISTER("osgui_is_initialized",ring_osgui_is_initialized);
	RING_API_REGISTER("osgui_initialize",ring_osgui_initialize);
	RING_API_REGISTER("osgui_terminate",ring_osgui_terminate);
	RING_API_REGISTER("osgui_set_app",ring_osgui_set_app);
	RING_API_REGISTER("osglobals_device",ring_osglobals_device);
	RING_API_REGISTER("osglobals_color",ring_osglobals_color);
	RING_API_REGISTER("osglobals_resolution",ring_osglobals_resolution);
	RING_API_REGISTER("osglobals_mouse_position",ring_osglobals_mouse_position);
	RING_API_REGISTER("osglobals_cursor",ring_osglobals_cursor);
	RING_API_REGISTER("osglobals_cursor_destroy",ring_osglobals_cursor_destroy);
	RING_API_REGISTER("osglobals_value",ring_osglobals_value);
	RING_API_REGISTER("osglobals_transitions",ring_osglobals_transitions);
	RING_API_REGISTER("osglobals_onidle",ring_osglobals_OnIdle);
	RING_API_REGISTER("osedit_create",ring_osedit_create);
	RING_API_REGISTER("osedit_destroy",ring_osedit_destroy);
	RING_API_REGISTER("osedit_onfilter",ring_osedit_OnFilter);
	RING_API_REGISTER("osedit_onchange",ring_osedit_OnChange);
	RING_API_REGISTER("osedit_onfocus",ring_osedit_OnFocus);
	RING_API_REGISTER("osedit_text",ring_osedit_text);
	RING_API_REGISTER("osedit_tooltip",ring_osedit_tooltip);
	RING_API_REGISTER("osedit_font",ring_osedit_font);
	RING_API_REGISTER("osedit_align",ring_osedit_align);
	RING_API_REGISTER("osedit_passmode",ring_osedit_passmode);
	RING_API_REGISTER("osedit_editable",ring_osedit_editable);
	RING_API_REGISTER("osedit_autoselect",ring_osedit_autoselect);
	RING_API_REGISTER("osedit_select",ring_osedit_select);
	RING_API_REGISTER("osedit_color",ring_osedit_color);
	RING_API_REGISTER("osedit_bgcolor",ring_osedit_bgcolor);
	RING_API_REGISTER("osedit_vpadding",ring_osedit_vpadding);
	RING_API_REGISTER("osedit_bounds",ring_osedit_bounds);
	RING_API_REGISTER("osedit_clipboard",ring_osedit_clipboard);
	RING_API_REGISTER("osedit_attach",ring_osedit_attach);
	RING_API_REGISTER("osedit_detach",ring_osedit_detach);
	RING_API_REGISTER("osedit_visible",ring_osedit_visible);
	RING_API_REGISTER("osedit_enabled",ring_osedit_enabled);
	RING_API_REGISTER("osedit_size",ring_osedit_size);
	RING_API_REGISTER("osedit_origin",ring_osedit_origin);
	RING_API_REGISTER("osedit_frame",ring_osedit_frame);
	RING_API_REGISTER("osdrawctrl_font",ring_osdrawctrl_font);
	RING_API_REGISTER("osdrawctrl_row_padding",ring_osdrawctrl_row_padding);
	RING_API_REGISTER("osdrawctrl_check_width",ring_osdrawctrl_check_width);
	RING_API_REGISTER("osdrawctrl_check_height",ring_osdrawctrl_check_height);
	RING_API_REGISTER("osdrawctrl_multisel",ring_osdrawctrl_multisel);
	RING_API_REGISTER("osdrawctrl_clear",ring_osdrawctrl_clear);
	RING_API_REGISTER("osdrawctrl_header",ring_osdrawctrl_header);
	RING_API_REGISTER("osdrawctrl_indicator",ring_osdrawctrl_indicator);
	RING_API_REGISTER("osdrawctrl_fill",ring_osdrawctrl_fill);
	RING_API_REGISTER("osdrawctrl_focus",ring_osdrawctrl_focus);
	RING_API_REGISTER("osdrawctrl_line",ring_osdrawctrl_line);
	RING_API_REGISTER("osdrawctrl_text",ring_osdrawctrl_text);
	RING_API_REGISTER("osdrawctrl_image",ring_osdrawctrl_image);
	RING_API_REGISTER("osdrawctrl_checkbox",ring_osdrawctrl_checkbox);
	RING_API_REGISTER("osdrawctrl_uncheckbox",ring_osdrawctrl_uncheckbox);
	RING_API_REGISTER("oscomwin_file",ring_oscomwin_file);
	RING_API_REGISTER("oscomwin_color",ring_oscomwin_color);
	RING_API_REGISTER("oscombo_create",ring_oscombo_create);
	RING_API_REGISTER("oscombo_destroy",ring_oscombo_destroy);
	RING_API_REGISTER("oscombo_onfilter",ring_oscombo_OnFilter);
	RING_API_REGISTER("oscombo_onchange",ring_oscombo_OnChange);
	RING_API_REGISTER("oscombo_onfocus",ring_oscombo_OnFocus);
	RING_API_REGISTER("oscombo_onselect",ring_oscombo_OnSelect);
	RING_API_REGISTER("oscombo_text",ring_oscombo_text);
	RING_API_REGISTER("oscombo_tooltip",ring_oscombo_tooltip);
	RING_API_REGISTER("oscombo_font",ring_oscombo_font);
	RING_API_REGISTER("oscombo_align",ring_oscombo_align);
	RING_API_REGISTER("oscombo_passmode",ring_oscombo_passmode);
	RING_API_REGISTER("oscombo_color",ring_oscombo_color);
	RING_API_REGISTER("oscombo_bgcolor",ring_oscombo_bgcolor);
	RING_API_REGISTER("oscombo_elem",ring_oscombo_elem);
	RING_API_REGISTER("oscombo_selected",ring_oscombo_selected);
	RING_API_REGISTER("oscombo_get_selected",ring_oscombo_get_selected);
	RING_API_REGISTER("oscombo_bounds",ring_oscombo_bounds);
	RING_API_REGISTER("oscombo_attach",ring_oscombo_attach);
	RING_API_REGISTER("oscombo_detach",ring_oscombo_detach);
	RING_API_REGISTER("oscombo_visible",ring_oscombo_visible);
	RING_API_REGISTER("oscombo_enabled",ring_oscombo_enabled);
	RING_API_REGISTER("oscombo_size",ring_oscombo_size);
	RING_API_REGISTER("oscombo_origin",ring_oscombo_origin);
	RING_API_REGISTER("oscombo_frame",ring_oscombo_frame);
	RING_API_REGISTER("osbutton_create",ring_osbutton_create);
	RING_API_REGISTER("osbutton_destroy",ring_osbutton_destroy);
	RING_API_REGISTER("osbutton_onclick",ring_osbutton_OnClick);
	RING_API_REGISTER("osbutton_text",ring_osbutton_text);
	RING_API_REGISTER("osbutton_tooltip",ring_osbutton_tooltip);
	RING_API_REGISTER("osbutton_font",ring_osbutton_font);
	RING_API_REGISTER("osbutton_align",ring_osbutton_align);
	RING_API_REGISTER("osbutton_image",ring_osbutton_image);
	RING_API_REGISTER("osbutton_state",ring_osbutton_state);
	RING_API_REGISTER("osbutton_get_state",ring_osbutton_get_state);
	RING_API_REGISTER("osbutton_vpadding",ring_osbutton_vpadding);
	RING_API_REGISTER("osbutton_bounds",ring_osbutton_bounds);
	RING_API_REGISTER("osbutton_attach",ring_osbutton_attach);
	RING_API_REGISTER("osbutton_detach",ring_osbutton_detach);
	RING_API_REGISTER("osbutton_visible",ring_osbutton_visible);
	RING_API_REGISTER("osbutton_enabled",ring_osbutton_enabled);
	RING_API_REGISTER("osbutton_size",ring_osbutton_size);
	RING_API_REGISTER("osbutton_origin",ring_osbutton_origin);
	RING_API_REGISTER("osbutton_frame",ring_osbutton_frame);
	RING_API_REGISTER("osbs_start",ring_osbs_start);
	RING_API_REGISTER("osbs_finish",ring_osbs_finish);
	RING_API_REGISTER("osbs_platform",ring_osbs_platform);
	RING_API_REGISTER("osbs_windows",ring_osbs_windows);
	RING_API_REGISTER("osbs_endian",ring_osbs_endian);
	RING_API_REGISTER("log_output",ring_log_output);
	RING_API_REGISTER("log_file",ring_log_file);
	RING_API_REGISTER("log_get_file",ring_log_get_file);
	RING_API_REGISTER("dlib_open",ring_dlib_open);
	RING_API_REGISTER("dlib_close",ring_dlib_close);
	RING_API_REGISTER("dlib_proc_imp",ring_dlib_proc_imp);
	RING_API_REGISTER("dlib_var_imp",ring_dlib_var_imp);
	RING_API_REGISTER("btime_now",ring_btime_now);
	RING_API_REGISTER("btime_date",ring_btime_date);
	RING_API_REGISTER("btime_to_micro",ring_btime_to_micro);
	RING_API_REGISTER("btime_to_date",ring_btime_to_date);
	RING_API_REGISTER("bthread_create_imp",ring_bthread_create_imp);
	RING_API_REGISTER("bthread_current_id",ring_bthread_current_id);
	RING_API_REGISTER("bthread_close",ring_bthread_close);
	RING_API_REGISTER("bthread_cancel",ring_bthread_cancel);
	RING_API_REGISTER("bthread_wait",ring_bthread_wait);
	RING_API_REGISTER("bthread_finish",ring_bthread_finish);
	RING_API_REGISTER("bthread_sleep",ring_bthread_sleep);
	RING_API_REGISTER("bsocket_connect",ring_bsocket_connect);
	RING_API_REGISTER("bsocket_server",ring_bsocket_server);
	RING_API_REGISTER("bsocket_accept",ring_bsocket_accept);
	RING_API_REGISTER("bsocket_close",ring_bsocket_close);
	RING_API_REGISTER("bsocket_local_ip",ring_bsocket_local_ip);
	RING_API_REGISTER("bsocket_remote_ip",ring_bsocket_remote_ip);
	RING_API_REGISTER("bsocket_read_timeout",ring_bsocket_read_timeout);
	RING_API_REGISTER("bsocket_write_timeout",ring_bsocket_write_timeout);
	RING_API_REGISTER("bsocket_read",ring_bsocket_read);
	RING_API_REGISTER("bsocket_write",ring_bsocket_write);
	RING_API_REGISTER("bsocket_url_ip",ring_bsocket_url_ip);
	RING_API_REGISTER("bsocket_str_ip",ring_bsocket_str_ip);
	RING_API_REGISTER("bsocket_host_name",ring_bsocket_host_name);
	RING_API_REGISTER("bsocket_host_name_ip",ring_bsocket_host_name_ip);
	RING_API_REGISTER("bsocket_ip_str",ring_bsocket_ip_str);
	RING_API_REGISTER("bsocket_hton2",ring_bsocket_hton2);
	RING_API_REGISTER("bsocket_hton4",ring_bsocket_hton4);
	RING_API_REGISTER("bsocket_hton8",ring_bsocket_hton8);
	RING_API_REGISTER("bsocket_ntoh2",ring_bsocket_ntoh2);
	RING_API_REGISTER("bsocket_ntoh4",ring_bsocket_ntoh4);
	RING_API_REGISTER("bsocket_ntoh8",ring_bsocket_ntoh8);
	RING_API_REGISTER("bproc_exec",ring_bproc_exec);
	RING_API_REGISTER("bproc_close",ring_bproc_close);
	RING_API_REGISTER("bproc_cancel",ring_bproc_cancel);
	RING_API_REGISTER("bproc_wait",ring_bproc_wait);
	RING_API_REGISTER("bproc_finish",ring_bproc_finish);
	RING_API_REGISTER("bproc_read",ring_bproc_read);
	RING_API_REGISTER("bproc_eread",ring_bproc_eread);
	RING_API_REGISTER("bproc_write",ring_bproc_write);
	RING_API_REGISTER("bproc_read_close",ring_bproc_read_close);
	RING_API_REGISTER("bproc_eread_close",ring_bproc_eread_close);
	RING_API_REGISTER("bproc_write_close",ring_bproc_write_close);
	RING_API_REGISTER("bproc_exit",ring_bproc_exit);
	RING_API_REGISTER("bmutex_create",ring_bmutex_create);
	RING_API_REGISTER("bmutex_close",ring_bmutex_close);
	RING_API_REGISTER("bmutex_lock",ring_bmutex_lock);
	RING_API_REGISTER("bmutex_unlock",ring_bmutex_unlock);
	RING_API_REGISTER("bfile_dir_work",ring_bfile_dir_work);
	RING_API_REGISTER("bfile_dir_set_work",ring_bfile_dir_set_work);
	RING_API_REGISTER("bfile_dir_home",ring_bfile_dir_home);
	RING_API_REGISTER("bfile_dir_data",ring_bfile_dir_data);
	RING_API_REGISTER("bfile_dir_exec",ring_bfile_dir_exec);
	RING_API_REGISTER("bfile_dir_create",ring_bfile_dir_create);
	RING_API_REGISTER("bfile_dir_open",ring_bfile_dir_open);
	RING_API_REGISTER("bfile_dir_close",ring_bfile_dir_close);
	RING_API_REGISTER("bfile_dir_get",ring_bfile_dir_get);
	RING_API_REGISTER("bfile_dir_delete",ring_bfile_dir_delete);
	RING_API_REGISTER("bfile_create",ring_bfile_create);
	RING_API_REGISTER("bfile_open",ring_bfile_open);
	RING_API_REGISTER("bfile_close",ring_bfile_close);
	RING_API_REGISTER("bfile_lstat",ring_bfile_lstat);
	RING_API_REGISTER("bfile_fstat",ring_bfile_fstat);
	RING_API_REGISTER("bfile_read",ring_bfile_read);
	RING_API_REGISTER("bfile_write",ring_bfile_write);
	RING_API_REGISTER("bfile_seek",ring_bfile_seek);
	RING_API_REGISTER("bfile_pos",ring_bfile_pos);
	RING_API_REGISTER("bfile_delete",ring_bfile_delete);
	RING_API_REGISTER("osapp_finish",ring_osapp_finish);
	RING_API_REGISTER("osapp_task_imp",ring_osapp_task_imp);
	RING_API_REGISTER("osapp_menubar",ring_osapp_menubar);
	RING_API_REGISTER("osapp_open_url",ring_osapp_open_url);
	RING_API_REGISTER("url_parse",ring_url_parse);
	RING_API_REGISTER("url_destroy",ring_url_destroy);
	RING_API_REGISTER("url_scheme",ring_url_scheme);
	RING_API_REGISTER("url_user",ring_url_user);
	RING_API_REGISTER("url_pass",ring_url_pass);
	RING_API_REGISTER("url_host",ring_url_host);
	RING_API_REGISTER("url_path",ring_url_path);
	RING_API_REGISTER("url_params",ring_url_params);
	RING_API_REGISTER("url_query",ring_url_query);
	RING_API_REGISTER("url_fragment",ring_url_fragment);
	RING_API_REGISTER("url_resource",ring_url_resource);
	RING_API_REGISTER("url_port",ring_url_port);
	RING_API_REGISTER("json_read_imp",ring_json_read_imp);
	RING_API_REGISTER("json_write_imp",ring_json_write_imp);
	RING_API_REGISTER("json_destroy_imp",ring_json_destroy_imp);
	RING_API_REGISTER("json_destopt_imp",ring_json_destopt_imp);
	RING_API_REGISTER("inet_start",ring_inet_start);
	RING_API_REGISTER("inet_finish",ring_inet_finish);
	RING_API_REGISTER("http_create",ring_http_create);
	RING_API_REGISTER("http_secure",ring_http_secure);
	RING_API_REGISTER("http_destroy",ring_http_destroy);
	RING_API_REGISTER("http_clear_headers",ring_http_clear_headers);
	RING_API_REGISTER("http_add_header",ring_http_add_header);
	RING_API_REGISTER("http_get",ring_http_get);
	RING_API_REGISTER("http_post",ring_http_post);
	RING_API_REGISTER("http_response_status",ring_http_response_status);
	RING_API_REGISTER("http_response_protocol",ring_http_response_protocol);
	RING_API_REGISTER("http_response_message",ring_http_response_message);
	RING_API_REGISTER("http_response_size",ring_http_response_size);
	RING_API_REGISTER("http_response_name",ring_http_response_name);
	RING_API_REGISTER("http_response_value",ring_http_response_value);
	RING_API_REGISTER("http_response_header",ring_http_response_header);
	RING_API_REGISTER("http_response_body",ring_http_response_body);
	RING_API_REGISTER("http_dget",ring_http_dget);
	RING_API_REGISTER("http_exists",ring_http_exists);
	RING_API_REGISTER("b64_encoded_size",ring_b64_encoded_size);
	RING_API_REGISTER("b64_decoded_size",ring_b64_decoded_size);
	RING_API_REGISTER("b64_encode",ring_b64_encode);
	RING_API_REGISTER("b64_decode",ring_b64_decode);
	RING_API_REGISTER("window_create",ring_window_create);
	RING_API_REGISTER("window_destroy",ring_window_destroy);
	RING_API_REGISTER("window_panel",ring_window_panel);
	RING_API_REGISTER("window_onclose",ring_window_OnClose);
	RING_API_REGISTER("window_onmoved",ring_window_OnMoved);
	RING_API_REGISTER("window_onresize",ring_window_OnResize);
	RING_API_REGISTER("window_title",ring_window_title);
	RING_API_REGISTER("window_show",ring_window_show);
	RING_API_REGISTER("window_hide",ring_window_hide);
	RING_API_REGISTER("window_overlay",ring_window_overlay);
	RING_API_REGISTER("window_modal",ring_window_modal);
	RING_API_REGISTER("window_stop_modal",ring_window_stop_modal);
	RING_API_REGISTER("window_hotkey",ring_window_hotkey);
	RING_API_REGISTER("window_clear_hotkeys",ring_window_clear_hotkeys);
	RING_API_REGISTER("window_cycle_tabstop",ring_window_cycle_tabstop);
	RING_API_REGISTER("window_next_tabstop",ring_window_next_tabstop);
	RING_API_REGISTER("window_previous_tabstop",ring_window_previous_tabstop);
	RING_API_REGISTER("window_focus",ring_window_focus);
	RING_API_REGISTER("window_get_focus",ring_window_get_focus);
	RING_API_REGISTER("window_focus_info",ring_window_focus_info);
	RING_API_REGISTER("window_update",ring_window_update);
	RING_API_REGISTER("window_origin",ring_window_origin);
	RING_API_REGISTER("window_size",ring_window_size);
	RING_API_REGISTER("window_get_origin",ring_window_get_origin);
	RING_API_REGISTER("window_get_size",ring_window_get_size);
	RING_API_REGISTER("window_get_client_size",ring_window_get_client_size);
	RING_API_REGISTER("window_control_frame",ring_window_control_frame);
	RING_API_REGISTER("window_client_to_screen",ring_window_client_to_screen);
	RING_API_REGISTER("window_defbutton",ring_window_defbutton);
	RING_API_REGISTER("window_cursor",ring_window_cursor);
	RING_API_REGISTER("window_imp",ring_window_imp);
	RING_API_REGISTER("view_create",ring_view_create);
	RING_API_REGISTER("view_scroll",ring_view_scroll);
	RING_API_REGISTER("view_custom",ring_view_custom);
	RING_API_REGISTER("view_data_imp",ring_view_data_imp);
	RING_API_REGISTER("view_get_data_imp",ring_view_get_data_imp);
	RING_API_REGISTER("view_size",ring_view_size);
	RING_API_REGISTER("view_ondraw",ring_view_OnDraw);
	RING_API_REGISTER("view_onoverlay",ring_view_OnOverlay);
	RING_API_REGISTER("view_onsize",ring_view_OnSize);
	RING_API_REGISTER("view_onenter",ring_view_OnEnter);
	RING_API_REGISTER("view_onexit",ring_view_OnExit);
	RING_API_REGISTER("view_onmove",ring_view_OnMove);
	RING_API_REGISTER("view_ondown",ring_view_OnDown);
	RING_API_REGISTER("view_onup",ring_view_OnUp);
	RING_API_REGISTER("view_onclick",ring_view_OnClick);
	RING_API_REGISTER("view_ondrag",ring_view_OnDrag);
	RING_API_REGISTER("view_onwheel",ring_view_OnWheel);
	RING_API_REGISTER("view_onkeydown",ring_view_OnKeyDown);
	RING_API_REGISTER("view_onkeyup",ring_view_OnKeyUp);
	RING_API_REGISTER("view_onfocus",ring_view_OnFocus);
	RING_API_REGISTER("view_onresignfocus",ring_view_OnResignFocus);
	RING_API_REGISTER("view_onacceptfocus",ring_view_OnAcceptFocus);
	RING_API_REGISTER("view_onscroll",ring_view_OnScroll);
	RING_API_REGISTER("view_keybuf",ring_view_keybuf);
	RING_API_REGISTER("view_get_size",ring_view_get_size);
	RING_API_REGISTER("view_content_size",ring_view_content_size);
	RING_API_REGISTER("view_scroll_x",ring_view_scroll_x);
	RING_API_REGISTER("view_scroll_y",ring_view_scroll_y);
	RING_API_REGISTER("view_scroll_size",ring_view_scroll_size);
	RING_API_REGISTER("view_scroll_visible",ring_view_scroll_visible);
	RING_API_REGISTER("view_viewport",ring_view_viewport);
	RING_API_REGISTER("view_point_scale",ring_view_point_scale);
	RING_API_REGISTER("view_update",ring_view_update);
	RING_API_REGISTER("view_native",ring_view_native);
	RING_API_REGISTER("updown_create",ring_updown_create);
	RING_API_REGISTER("updown_onclick",ring_updown_OnClick);
	RING_API_REGISTER("updown_tooltip",ring_updown_tooltip);
	RING_API_REGISTER("textview_create",ring_textview_create);
	RING_API_REGISTER("textview_onfilter",ring_textview_OnFilter);
	RING_API_REGISTER("textview_onfocus",ring_textview_OnFocus);
	RING_API_REGISTER("textview_size",ring_textview_size);
	RING_API_REGISTER("textview_clear",ring_textview_clear);
	RING_API_REGISTER("textview_writef",ring_textview_writef);
	RING_API_REGISTER("textview_rtf",ring_textview_rtf);
	RING_API_REGISTER("textview_units",ring_textview_units);
	RING_API_REGISTER("textview_family",ring_textview_family);
	RING_API_REGISTER("textview_fsize",ring_textview_fsize);
	RING_API_REGISTER("textview_fstyle",ring_textview_fstyle);
	RING_API_REGISTER("textview_color",ring_textview_color);
	RING_API_REGISTER("textview_bgcolor",ring_textview_bgcolor);
	RING_API_REGISTER("textview_pgcolor",ring_textview_pgcolor);
	RING_API_REGISTER("textview_halign",ring_textview_halign);
	RING_API_REGISTER("textview_lspacing",ring_textview_lspacing);
	RING_API_REGISTER("textview_bfspace",ring_textview_bfspace);
	RING_API_REGISTER("textview_afspace",ring_textview_afspace);
	RING_API_REGISTER("textview_scroll_visible",ring_textview_scroll_visible);
	RING_API_REGISTER("textview_editable",ring_textview_editable);
	RING_API_REGISTER("textview_select",ring_textview_select);
	RING_API_REGISTER("textview_scroll_caret",ring_textview_scroll_caret);
	RING_API_REGISTER("textview_get_text",ring_textview_get_text);
	RING_API_REGISTER("textview_copy",ring_textview_copy);
	RING_API_REGISTER("textview_cut",ring_textview_cut);
	RING_API_REGISTER("textview_paste",ring_textview_paste);
	RING_API_REGISTER("tableview_create",ring_tableview_create);
	RING_API_REGISTER("tableview_ondata",ring_tableview_OnData);
	RING_API_REGISTER("tableview_onselect",ring_tableview_OnSelect);
	RING_API_REGISTER("tableview_onrowclick",ring_tableview_OnRowClick);
	RING_API_REGISTER("tableview_onheaderclick",ring_tableview_OnHeaderClick);
	RING_API_REGISTER("tableview_font",ring_tableview_font);
	RING_API_REGISTER("tableview_size",ring_tableview_size);
	RING_API_REGISTER("tableview_new_column_text",ring_tableview_new_column_text);
	RING_API_REGISTER("tableview_column_width",ring_tableview_column_width);
	RING_API_REGISTER("tableview_column_limits",ring_tableview_column_limits);
	RING_API_REGISTER("tableview_column_resizable",ring_tableview_column_resizable);
	RING_API_REGISTER("tableview_column_freeze",ring_tableview_column_freeze);
	RING_API_REGISTER("tableview_header_title",ring_tableview_header_title);
	RING_API_REGISTER("tableview_header_align",ring_tableview_header_align);
	RING_API_REGISTER("tableview_header_indicator",ring_tableview_header_indicator);
	RING_API_REGISTER("tableview_header_visible",ring_tableview_header_visible);
	RING_API_REGISTER("tableview_header_clickable",ring_tableview_header_clickable);
	RING_API_REGISTER("tableview_header_resizable",ring_tableview_header_resizable);
	RING_API_REGISTER("tableview_header_height",ring_tableview_header_height);
	RING_API_REGISTER("tableview_row_height",ring_tableview_row_height);
	RING_API_REGISTER("tableview_hkey_scroll",ring_tableview_hkey_scroll);
	RING_API_REGISTER("tableview_multisel",ring_tableview_multisel);
	RING_API_REGISTER("tableview_grid",ring_tableview_grid);
	RING_API_REGISTER("tableview_update",ring_tableview_update);
	RING_API_REGISTER("tableview_select",ring_tableview_select);
	RING_API_REGISTER("tableview_deselect",ring_tableview_deselect);
	RING_API_REGISTER("tableview_deselect_all",ring_tableview_deselect_all);
	RING_API_REGISTER("tableview_focus_row",ring_tableview_focus_row);
	RING_API_REGISTER("tableview_get_focus_row",ring_tableview_get_focus_row);
	RING_API_REGISTER("tableview_scroll_visible",ring_tableview_scroll_visible);
	RING_API_REGISTER("splitview_horizontal",ring_splitview_horizontal);
	RING_API_REGISTER("splitview_vertical",ring_splitview_vertical);
	RING_API_REGISTER("splitview_size",ring_splitview_size);
	RING_API_REGISTER("splitview_view",ring_splitview_view);
	RING_API_REGISTER("splitview_text",ring_splitview_text);
	RING_API_REGISTER("splitview_split",ring_splitview_split);
	RING_API_REGISTER("splitview_panel",ring_splitview_panel);
	RING_API_REGISTER("splitview_pos",ring_splitview_pos);
	RING_API_REGISTER("slider_create",ring_slider_create);
	RING_API_REGISTER("slider_vertical",ring_slider_vertical);
	RING_API_REGISTER("slider_onmoved",ring_slider_OnMoved);
	RING_API_REGISTER("slider_tooltip",ring_slider_tooltip);
	RING_API_REGISTER("slider_steps",ring_slider_steps);
	RING_API_REGISTER("slider_value",ring_slider_value);
	RING_API_REGISTER("slider_get_value",ring_slider_get_value);
	RING_API_REGISTER("res_gui_respack",ring_res_gui_respack);
	RING_API_REGISTER("progress_create",ring_progress_create);
	RING_API_REGISTER("progress_undefined",ring_progress_undefined);
	RING_API_REGISTER("progress_value",ring_progress_value);
	RING_API_REGISTER("popup_create",ring_popup_create);
	RING_API_REGISTER("popup_onselect",ring_popup_OnSelect);
	RING_API_REGISTER("popup_tooltip",ring_popup_tooltip);
	RING_API_REGISTER("popup_add_elem",ring_popup_add_elem);
	RING_API_REGISTER("popup_set_elem",ring_popup_set_elem);
	RING_API_REGISTER("popup_clear",ring_popup_clear);
	RING_API_REGISTER("popup_count",ring_popup_count);
	RING_API_REGISTER("popup_list_height",ring_popup_list_height);
	RING_API_REGISTER("popup_selected",ring_popup_selected);
	RING_API_REGISTER("popup_get_selected",ring_popup_get_selected);
	RING_API_REGISTER("popup_get_text",ring_popup_get_text);
	RING_API_REGISTER("panel_create",ring_panel_create);
	RING_API_REGISTER("panel_scroll",ring_panel_scroll);
	RING_API_REGISTER("panel_custom",ring_panel_custom);
	RING_API_REGISTER("panel_data_imp",ring_panel_data_imp);
	RING_API_REGISTER("panel_get_data_imp",ring_panel_get_data_imp);
	RING_API_REGISTER("panel_size",ring_panel_size);
	RING_API_REGISTER("panel_layout",ring_panel_layout);
	RING_API_REGISTER("panel_get_layout",ring_panel_get_layout);
	RING_API_REGISTER("panel_visible_layout",ring_panel_visible_layout);
	RING_API_REGISTER("panel_update",ring_panel_update);
	RING_API_REGISTER("panel_scroll_width",ring_panel_scroll_width);
	RING_API_REGISTER("panel_scroll_height",ring_panel_scroll_height);
	RING_API_REGISTER("menuitem_create",ring_menuitem_create);
	RING_API_REGISTER("menuitem_separator",ring_menuitem_separator);
	RING_API_REGISTER("menuitem_onclick",ring_menuitem_OnClick);
	RING_API_REGISTER("menuitem_enabled",ring_menuitem_enabled);
	RING_API_REGISTER("menuitem_visible",ring_menuitem_visible);
	RING_API_REGISTER("menuitem_text",ring_menuitem_text);
	RING_API_REGISTER("menuitem_image",ring_menuitem_image);
	RING_API_REGISTER("menuitem_key",ring_menuitem_key);
	RING_API_REGISTER("menuitem_submenu",ring_menuitem_submenu);
	RING_API_REGISTER("menuitem_state",ring_menuitem_state);
	RING_API_REGISTER("menu_create",ring_menu_create);
	RING_API_REGISTER("menu_destroy",ring_menu_destroy);
	RING_API_REGISTER("menu_item",ring_menu_item);
	RING_API_REGISTER("menu_launch",ring_menu_launch);
	RING_API_REGISTER("menu_hide",ring_menu_hide);
	RING_API_REGISTER("menu_off_items",ring_menu_off_items);
	RING_API_REGISTER("menu_get_item",ring_menu_get_item);
	RING_API_REGISTER("menu_size",ring_menu_size);
	RING_API_REGISTER("menu_imp",ring_menu_imp);
	RING_API_REGISTER("listbox_create",ring_listbox_create);
	RING_API_REGISTER("listbox_ondown",ring_listbox_OnDown);
	RING_API_REGISTER("listbox_onselect",ring_listbox_OnSelect);
	RING_API_REGISTER("listbox_size",ring_listbox_size);
	RING_API_REGISTER("listbox_checkbox",ring_listbox_checkbox);
	RING_API_REGISTER("listbox_multisel",ring_listbox_multisel);
	RING_API_REGISTER("listbox_add_elem",ring_listbox_add_elem);
	RING_API_REGISTER("listbox_set_elem",ring_listbox_set_elem);
	RING_API_REGISTER("listbox_clear",ring_listbox_clear);
	RING_API_REGISTER("listbox_color",ring_listbox_color);
	RING_API_REGISTER("listbox_select",ring_listbox_select);
	RING_API_REGISTER("listbox_check",ring_listbox_check);
	RING_API_REGISTER("listbox_count",ring_listbox_count);
	RING_API_REGISTER("listbox_text",ring_listbox_text);
	RING_API_REGISTER("listbox_selected",ring_listbox_selected);
	RING_API_REGISTER("listbox_checked",ring_listbox_checked);
	RING_API_REGISTER("layout_create",ring_layout_create);
	RING_API_REGISTER("layout_cell",ring_layout_cell);
	RING_API_REGISTER("layout_control",ring_layout_control);
	RING_API_REGISTER("layout_label",ring_layout_label);
	RING_API_REGISTER("layout_button",ring_layout_button);
	RING_API_REGISTER("layout_popup",ring_layout_popup);
	RING_API_REGISTER("layout_edit",ring_layout_edit);
	RING_API_REGISTER("layout_combo",ring_layout_combo);
	RING_API_REGISTER("layout_listbox",ring_layout_listbox);
	RING_API_REGISTER("layout_updown",ring_layout_updown);
	RING_API_REGISTER("layout_slider",ring_layout_slider);
	RING_API_REGISTER("layout_progress",ring_layout_progress);
	RING_API_REGISTER("layout_view",ring_layout_view);
	RING_API_REGISTER("layout_textview",ring_layout_textview);
	RING_API_REGISTER("layout_imageview",ring_layout_imageview);
	RING_API_REGISTER("layout_tableview",ring_layout_tableview);
	RING_API_REGISTER("layout_splitview",ring_layout_splitview);
	RING_API_REGISTER("layout_panel",ring_layout_panel);
	RING_API_REGISTER("layout_panel_replace",ring_layout_panel_replace);
	RING_API_REGISTER("layout_layout",ring_layout_layout);
	RING_API_REGISTER("layout_get_label",ring_layout_get_label);
	RING_API_REGISTER("layout_get_button",ring_layout_get_button);
	RING_API_REGISTER("layout_get_popup",ring_layout_get_popup);
	RING_API_REGISTER("layout_get_edit",ring_layout_get_edit);
	RING_API_REGISTER("layout_get_combo",ring_layout_get_combo);
	RING_API_REGISTER("layout_get_listbox",ring_layout_get_listbox);
	RING_API_REGISTER("layout_get_updown",ring_layout_get_updown);
	RING_API_REGISTER("layout_get_slider",ring_layout_get_slider);
	RING_API_REGISTER("layout_get_progress",ring_layout_get_progress);
	RING_API_REGISTER("layout_get_view",ring_layout_get_view);
	RING_API_REGISTER("layout_get_textview",ring_layout_get_textview);
	RING_API_REGISTER("layout_get_imageview",ring_layout_get_imageview);
	RING_API_REGISTER("layout_get_tableview",ring_layout_get_tableview);
	RING_API_REGISTER("layout_get_splitview",ring_layout_get_splitview);
	RING_API_REGISTER("layout_get_panel",ring_layout_get_panel);
	RING_API_REGISTER("layout_get_layout",ring_layout_get_layout);
	RING_API_REGISTER("layout_ncols",ring_layout_ncols);
	RING_API_REGISTER("layout_nrows",ring_layout_nrows);
	RING_API_REGISTER("layout_insert_col",ring_layout_insert_col);
	RING_API_REGISTER("layout_insert_row",ring_layout_insert_row);
	RING_API_REGISTER("layout_remove_col",ring_layout_remove_col);
	RING_API_REGISTER("layout_remove_row",ring_layout_remove_row);
	RING_API_REGISTER("layout_taborder",ring_layout_taborder);
	RING_API_REGISTER("layout_tabstop",ring_layout_tabstop);
	RING_API_REGISTER("layout_hsize",ring_layout_hsize);
	RING_API_REGISTER("layout_vsize",ring_layout_vsize);
	RING_API_REGISTER("layout_hmargin",ring_layout_hmargin);
	RING_API_REGISTER("layout_vmargin",ring_layout_vmargin);
	RING_API_REGISTER("layout_hexpand",ring_layout_hexpand);
	RING_API_REGISTER("layout_hexpand2",ring_layout_hexpand2);
	RING_API_REGISTER("layout_hexpand3",ring_layout_hexpand3);
	RING_API_REGISTER("layout_vexpand",ring_layout_vexpand);
	RING_API_REGISTER("layout_vexpand2",ring_layout_vexpand2);
	RING_API_REGISTER("layout_vexpand3",ring_layout_vexpand3);
	RING_API_REGISTER("layout_halign",ring_layout_halign);
	RING_API_REGISTER("layout_valign",ring_layout_valign);
	RING_API_REGISTER("layout_show_col",ring_layout_show_col);
	RING_API_REGISTER("layout_show_row",ring_layout_show_row);
	RING_API_REGISTER("layout_margin",ring_layout_margin);
	RING_API_REGISTER("layout_margin2",ring_layout_margin2);
	RING_API_REGISTER("layout_margin4",ring_layout_margin4);
	RING_API_REGISTER("layout_bgcolor",ring_layout_bgcolor);
	RING_API_REGISTER("layout_skcolor",ring_layout_skcolor);
	RING_API_REGISTER("layout_update",ring_layout_update);
	RING_API_REGISTER("layout_dbind_imp",ring_layout_dbind_imp);
	RING_API_REGISTER("layout_dbind_obj_imp",ring_layout_dbind_obj_imp);
	RING_API_REGISTER("layout_dbind_update_imp",ring_layout_dbind_update_imp);
	RING_API_REGISTER("label_create",ring_label_create);
	RING_API_REGISTER("label_multiline",ring_label_multiline);
	RING_API_REGISTER("label_onclick",ring_label_OnClick);
	RING_API_REGISTER("label_text",ring_label_text);
	RING_API_REGISTER("label_size_text",ring_label_size_text);
	RING_API_REGISTER("label_font",ring_label_font);
	RING_API_REGISTER("label_style_over",ring_label_style_over);
	RING_API_REGISTER("label_align",ring_label_align);
	RING_API_REGISTER("label_color",ring_label_color);
	RING_API_REGISTER("label_color_over",ring_label_color_over);
	RING_API_REGISTER("label_bgcolor",ring_label_bgcolor);
	RING_API_REGISTER("label_bgcolor_over",ring_label_bgcolor_over);
	RING_API_REGISTER("imageview_create",ring_imageview_create);
	RING_API_REGISTER("imageview_size",ring_imageview_size);
	RING_API_REGISTER("imageview_scale",ring_imageview_scale);
	RING_API_REGISTER("imageview_image",ring_imageview_image);
	RING_API_REGISTER("imageview_onclick",ring_imageview_OnClick);
	RING_API_REGISTER("imageview_onoverdraw",ring_imageview_OnOverDraw);
	RING_API_REGISTER("guicontrol_label",ring_guicontrol_label);
	RING_API_REGISTER("guicontrol_button",ring_guicontrol_button);
	RING_API_REGISTER("guicontrol_popup",ring_guicontrol_popup);
	RING_API_REGISTER("guicontrol_edit",ring_guicontrol_edit);
	RING_API_REGISTER("guicontrol_combo",ring_guicontrol_combo);
	RING_API_REGISTER("guicontrol_listbox",ring_guicontrol_listbox);
	RING_API_REGISTER("guicontrol_updown",ring_guicontrol_updown);
	RING_API_REGISTER("guicontrol_slider",ring_guicontrol_slider);
	RING_API_REGISTER("guicontrol_progress",ring_guicontrol_progress);
	RING_API_REGISTER("guicontrol_view",ring_guicontrol_view);
	RING_API_REGISTER("guicontrol_textview",ring_guicontrol_textview);
	RING_API_REGISTER("guicontrol_imageview",ring_guicontrol_imageview);
	RING_API_REGISTER("guicontrol_tableview",ring_guicontrol_tableview);
	RING_API_REGISTER("guicontrol_splitview",ring_guicontrol_splitview);
	RING_API_REGISTER("guicontrol_panel",ring_guicontrol_panel);
	RING_API_REGISTER("guicontrol_tag",ring_guicontrol_tag);
	RING_API_REGISTER("guicontrol_get_tag",ring_guicontrol_get_tag);
	RING_API_REGISTER("gui_start",ring_gui_start);
	RING_API_REGISTER("gui_finish",ring_gui_finish);
	RING_API_REGISTER("gui_respack",ring_gui_respack);
	RING_API_REGISTER("gui_language",ring_gui_language);
	RING_API_REGISTER("gui_text",ring_gui_text);
	RING_API_REGISTER("gui_image",ring_gui_image);
	RING_API_REGISTER("gui_file",ring_gui_file);
	RING_API_REGISTER("gui_dark_mode",ring_gui_dark_mode);
	RING_API_REGISTER("gui_alt_color",ring_gui_alt_color);
	RING_API_REGISTER("gui_label_color",ring_gui_label_color);
	RING_API_REGISTER("gui_view_color",ring_gui_view_color);
	RING_API_REGISTER("gui_line_color",ring_gui_line_color);
	RING_API_REGISTER("gui_link_color",ring_gui_link_color);
	RING_API_REGISTER("gui_border_color",ring_gui_border_color);
	RING_API_REGISTER("gui_resolution",ring_gui_resolution);
	RING_API_REGISTER("gui_mouse_pos",ring_gui_mouse_pos);
	RING_API_REGISTER("gui_update",ring_gui_update);
	RING_API_REGISTER("gui_onthemechanged",ring_gui_OnThemeChanged);
	RING_API_REGISTER("gui_update_transitions",ring_gui_update_transitions);
	RING_API_REGISTER("gui_onnotification",ring_gui_OnNotification);
	RING_API_REGISTER("gui_onidle",ring_gui_OnIdle);
	RING_API_REGISTER("gui_info_window",ring_gui_info_window);
	RING_API_REGISTER("evbind_object_imp",ring_evbind_object_imp);
	RING_API_REGISTER("evbind_modify_imp",ring_evbind_modify_imp);
	RING_API_REGISTER("globals_device",ring_globals_device);
	RING_API_REGISTER("globals_resolution",ring_globals_resolution);
	RING_API_REGISTER("globals_mouse_position",ring_globals_mouse_position);
	RING_API_REGISTER("edit_create",ring_edit_create);
	RING_API_REGISTER("edit_multiline",ring_edit_multiline);
	RING_API_REGISTER("edit_onfilter",ring_edit_OnFilter);
	RING_API_REGISTER("edit_onchange",ring_edit_OnChange);
	RING_API_REGISTER("edit_onfocus",ring_edit_OnFocus);
	RING_API_REGISTER("edit_text",ring_edit_text);
	RING_API_REGISTER("edit_font",ring_edit_font);
	RING_API_REGISTER("edit_align",ring_edit_align);
	RING_API_REGISTER("edit_passmode",ring_edit_passmode);
	RING_API_REGISTER("edit_editable",ring_edit_editable);
	RING_API_REGISTER("edit_autoselect",ring_edit_autoselect);
	RING_API_REGISTER("edit_select",ring_edit_select);
	RING_API_REGISTER("edit_tooltip",ring_edit_tooltip);
	RING_API_REGISTER("edit_color",ring_edit_color);
	RING_API_REGISTER("edit_color_focus",ring_edit_color_focus);
	RING_API_REGISTER("edit_bgcolor",ring_edit_bgcolor);
	RING_API_REGISTER("edit_bgcolor_focus",ring_edit_bgcolor_focus);
	RING_API_REGISTER("edit_phtext",ring_edit_phtext);
	RING_API_REGISTER("edit_phcolor",ring_edit_phcolor);
	RING_API_REGISTER("edit_phstyle",ring_edit_phstyle);
	RING_API_REGISTER("edit_vpadding",ring_edit_vpadding);
	RING_API_REGISTER("edit_get_text",ring_edit_get_text);
	RING_API_REGISTER("edit_get_height",ring_edit_get_height);
	RING_API_REGISTER("edit_copy",ring_edit_copy);
	RING_API_REGISTER("edit_cut",ring_edit_cut);
	RING_API_REGISTER("edit_paste",ring_edit_paste);
	RING_API_REGISTER("comwin_open_file",ring_comwin_open_file);
	RING_API_REGISTER("comwin_save_file",ring_comwin_save_file);
	RING_API_REGISTER("comwin_color",ring_comwin_color);
	RING_API_REGISTER("combo_create",ring_combo_create);
	RING_API_REGISTER("combo_onfilter",ring_combo_OnFilter);
	RING_API_REGISTER("combo_onchange",ring_combo_OnChange);
	RING_API_REGISTER("combo_text",ring_combo_text);
	RING_API_REGISTER("combo_align",ring_combo_align);
	RING_API_REGISTER("combo_tooltip",ring_combo_tooltip);
	RING_API_REGISTER("combo_color",ring_combo_color);
	RING_API_REGISTER("combo_color_focus",ring_combo_color_focus);
	RING_API_REGISTER("combo_bgcolor",ring_combo_bgcolor);
	RING_API_REGISTER("combo_bgcolor_focus",ring_combo_bgcolor_focus);
	RING_API_REGISTER("combo_phtext",ring_combo_phtext);
	RING_API_REGISTER("combo_phcolor",ring_combo_phcolor);
	RING_API_REGISTER("combo_phstyle",ring_combo_phstyle);
	RING_API_REGISTER("combo_get_text",ring_combo_get_text);
	RING_API_REGISTER("combo_count",ring_combo_count);
	RING_API_REGISTER("combo_add_elem",ring_combo_add_elem);
	RING_API_REGISTER("combo_set_elem",ring_combo_set_elem);
	RING_API_REGISTER("combo_ins_elem",ring_combo_ins_elem);
	RING_API_REGISTER("combo_del_elem",ring_combo_del_elem);
	RING_API_REGISTER("combo_duplicates",ring_combo_duplicates);
	RING_API_REGISTER("cell_empty",ring_cell_empty);
	RING_API_REGISTER("cell_control",ring_cell_control);
	RING_API_REGISTER("cell_label",ring_cell_label);
	RING_API_REGISTER("cell_button",ring_cell_button);
	RING_API_REGISTER("cell_popup",ring_cell_popup);
	RING_API_REGISTER("cell_edit",ring_cell_edit);
	RING_API_REGISTER("cell_combo",ring_cell_combo);
	RING_API_REGISTER("cell_listbox",ring_cell_listbox);
	RING_API_REGISTER("cell_updown",ring_cell_updown);
	RING_API_REGISTER("cell_slider",ring_cell_slider);
	RING_API_REGISTER("cell_progress",ring_cell_progress);
	RING_API_REGISTER("cell_view",ring_cell_view);
	RING_API_REGISTER("cell_textview",ring_cell_textview);
	RING_API_REGISTER("cell_imageview",ring_cell_imageview);
	RING_API_REGISTER("cell_tableview",ring_cell_tableview);
	RING_API_REGISTER("cell_splitview",ring_cell_splitview);
	RING_API_REGISTER("cell_panel",ring_cell_panel);
	RING_API_REGISTER("cell_layout",ring_cell_layout);
	RING_API_REGISTER("cell_enabled",ring_cell_enabled);
	RING_API_REGISTER("cell_visible",ring_cell_visible);
	RING_API_REGISTER("cell_padding",ring_cell_padding);
	RING_API_REGISTER("cell_padding2",ring_cell_padding2);
	RING_API_REGISTER("cell_padding4",ring_cell_padding4);
	RING_API_REGISTER("cell_dbind_imp",ring_cell_dbind_imp);
	RING_API_REGISTER("button_push",ring_button_push);
	RING_API_REGISTER("button_check",ring_button_check);
	RING_API_REGISTER("button_check3",ring_button_check3);
	RING_API_REGISTER("button_radio",ring_button_radio);
	RING_API_REGISTER("button_flat",ring_button_flat);
	RING_API_REGISTER("button_flatgle",ring_button_flatgle);
	RING_API_REGISTER("button_onclick",ring_button_OnClick);
	RING_API_REGISTER("button_text",ring_button_text);
	RING_API_REGISTER("button_text_alt",ring_button_text_alt);
	RING_API_REGISTER("button_tooltip",ring_button_tooltip);
	RING_API_REGISTER("button_font",ring_button_font);
	RING_API_REGISTER("button_image",ring_button_image);
	RING_API_REGISTER("button_image_alt",ring_button_image_alt);
	RING_API_REGISTER("button_state",ring_button_state);
	RING_API_REGISTER("button_tag",ring_button_tag);
	RING_API_REGISTER("button_vpadding",ring_button_vpadding);
	RING_API_REGISTER("button_get_state",ring_button_get_state);
	RING_API_REGISTER("button_get_tag",ring_button_get_tag);
	RING_API_REGISTER("button_get_height",ring_button_get_height);
	RING_API_REGISTER("v2df",ring_v2df);
	RING_API_REGISTER("v2dd",ring_v2dd);
	RING_API_REGISTER("v2d_tof",ring_v2d_tof);
	RING_API_REGISTER("v2d_tod",ring_v2d_tod);
	RING_API_REGISTER("v2d_tofn",ring_v2d_tofn);
	RING_API_REGISTER("v2d_todn",ring_v2d_todn);
	RING_API_REGISTER("v2d_addf",ring_v2d_addf);
	RING_API_REGISTER("v2d_addd",ring_v2d_addd);
	RING_API_REGISTER("v2d_subf",ring_v2d_subf);
	RING_API_REGISTER("v2d_subd",ring_v2d_subd);
	RING_API_REGISTER("v2d_mulf",ring_v2d_mulf);
	RING_API_REGISTER("v2d_muld",ring_v2d_muld);
	RING_API_REGISTER("v2d_fromf",ring_v2d_fromf);
	RING_API_REGISTER("v2d_fromd",ring_v2d_fromd);
	RING_API_REGISTER("v2d_midf",ring_v2d_midf);
	RING_API_REGISTER("v2d_midd",ring_v2d_midd);
	RING_API_REGISTER("v2d_unitf",ring_v2d_unitf);
	RING_API_REGISTER("v2d_unitd",ring_v2d_unitd);
	RING_API_REGISTER("v2d_unit_xyf",ring_v2d_unit_xyf);
	RING_API_REGISTER("v2d_unit_xyd",ring_v2d_unit_xyd);
	RING_API_REGISTER("v2d_perp_posf",ring_v2d_perp_posf);
	RING_API_REGISTER("v2d_perp_posd",ring_v2d_perp_posd);
	RING_API_REGISTER("v2d_perp_negf",ring_v2d_perp_negf);
	RING_API_REGISTER("v2d_perp_negd",ring_v2d_perp_negd);
	RING_API_REGISTER("v2d_from_anglef",ring_v2d_from_anglef);
	RING_API_REGISTER("v2d_from_angled",ring_v2d_from_angled);
	RING_API_REGISTER("v2d_normf",ring_v2d_normf);
	RING_API_REGISTER("v2d_normd",ring_v2d_normd);
	RING_API_REGISTER("v2d_lengthf",ring_v2d_lengthf);
	RING_API_REGISTER("v2d_lengthd",ring_v2d_lengthd);
	RING_API_REGISTER("v2d_sqlengthf",ring_v2d_sqlengthf);
	RING_API_REGISTER("v2d_sqlengthd",ring_v2d_sqlengthd);
	RING_API_REGISTER("v2d_dotf",ring_v2d_dotf);
	RING_API_REGISTER("v2d_dotd",ring_v2d_dotd);
	RING_API_REGISTER("v2d_distf",ring_v2d_distf);
	RING_API_REGISTER("v2d_distd",ring_v2d_distd);
	RING_API_REGISTER("v2d_sqdistf",ring_v2d_sqdistf);
	RING_API_REGISTER("v2d_sqdistd",ring_v2d_sqdistd);
	RING_API_REGISTER("v2d_anglef",ring_v2d_anglef);
	RING_API_REGISTER("v2d_angled",ring_v2d_angled);
	RING_API_REGISTER("v2d_rotatef",ring_v2d_rotatef);
	RING_API_REGISTER("v2d_rotated",ring_v2d_rotated);
	RING_API_REGISTER("tri2df",ring_tri2df);
	RING_API_REGISTER("tri2dd",ring_tri2dd);
	RING_API_REGISTER("tri2d_vf",ring_tri2d_vf);
	RING_API_REGISTER("tri2d_vd",ring_tri2d_vd);
	RING_API_REGISTER("tri2d_transformf",ring_tri2d_transformf);
	RING_API_REGISTER("tri2d_transformd",ring_tri2d_transformd);
	RING_API_REGISTER("tri2d_areaf",ring_tri2d_areaf);
	RING_API_REGISTER("tri2d_aread",ring_tri2d_aread);
	RING_API_REGISTER("tri2d_ccwf",ring_tri2d_ccwf);
	RING_API_REGISTER("tri2d_ccwd",ring_tri2d_ccwd);
	RING_API_REGISTER("tri2d_centroidf",ring_tri2d_centroidf);
	RING_API_REGISTER("tri2d_centroidd",ring_tri2d_centroidd);
}

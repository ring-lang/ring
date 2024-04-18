
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
}

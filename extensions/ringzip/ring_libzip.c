#include "ring.h"

/*
**  Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com>
*/

#include <zip.c>
typedef struct zip_t ZIP_T ;

RING_FUNC(ring_zip_open)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(zip_open(RING_API_GETSTRING(1), (int) RING_API_GETNUMBER(2),* (char *) RING_API_GETCPOINTER(3,"char")),"ZIP_T");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		free(RING_API_GETCPOINTER(3,"char"));
}


RING_FUNC(ring_zip_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	zip_close((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"));
}


RING_FUNC(ring_zip_entry_open)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_open((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_zip_entry_write)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_write((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T"),RING_API_GETSTRING(2), (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_zip_entry_close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(zip_entry_close((ZIP_T *) RING_API_GETCPOINTER(1,"ZIP_T")));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("zip_open",ring_zip_open);
	ring_vm_funcregister("zip_close",ring_zip_close);
	ring_vm_funcregister("zip_entry_open",ring_zip_entry_open);
	ring_vm_funcregister("zip_entry_write",ring_zip_entry_write);
	ring_vm_funcregister("zip_entry_close",ring_zip_entry_close);
}

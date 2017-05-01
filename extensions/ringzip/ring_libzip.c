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

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("zip_open",ring_zip_open);
}

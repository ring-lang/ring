#include "ring.h"

/* Copyright (c) 2018 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "libpq-fe.h"


RING_FUNC(ring_PQconnectdbParams)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQconnectdbParams((char *) RING_API_GETCPOINTER(1,"char"),(char *) RING_API_GETCPOINTER(2,"char"), (int ) RING_API_GETNUMBER(3)),"PGconn");
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("pqconnectdbparams",ring_PQconnectdbParams);
}

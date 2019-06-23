/* Copyright (c) 2019 Mahmoud Fayed <msfclipper@yahoo.com> */

#define RING_EXTENSION	// Don't call : windows.h (Avoid conflict with raylib.h)
#include <ring.h>

#include <raylib.h>


RING_FUNC(ring_InitWindow)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	InitWindow( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("initwindow",ring_InitWindow);
}

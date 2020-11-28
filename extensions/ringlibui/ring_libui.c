#include "ring.h"

/* Copyright (c) 2020 Mahmoud Fayed <msfclipper@yahoo.com> */

#include <ui.h>
#include <windows.h>
#include <ui_windows.h>

RING_FUNC(ring_get_uipi)
{
	RING_API_RETNUMBER(uiPi);
}


RING_FUNC(ring_uiInit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiInit((uiInitOptions *) RING_API_GETCPOINTER(1,"uiInitOptions")));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("uiinit",ring_uiInit);
	ring_vm_funcregister("get_uipi",ring_get_uipi);
}

#include "ring.h"

/* Copyright (c) 2020 Mahmoud Fayed <msfclipper@yahoo.com> */

#include <ui.h>
#include <ui_windows.h>

RING_FUNC(ring_get_uipi)
{
	RING_API_RETNUMBER(uiPi);
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("get_uipi",ring_get_uipi);
}

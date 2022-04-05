#include "ring.h"

#include "windows.h"
#include "winuser.h"

RING_FUNC(ring_mouse_event)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	mouse_event( (DWORD ) RING_API_GETNUMBER(1), (DWORD ) RING_API_GETNUMBER(2), (DWORD ) RING_API_GETNUMBER(3), (DWORD ) RING_API_GETNUMBER(4), (ULONG_PTR ) RING_API_GETNUMBER(5));
}

RING_API void ringlib_init(RingState *pRingState)
{
	RING_API_REGISTER("mouse_event",ring_mouse_event);
}

#include "ring.h"

#include "windows.h"
#include "winuser.h"

RING_FUNC(ring_get_gwl_exstyle)
{
	RING_API_RETNUMBER(GWL_EXSTYLE);
}

RING_FUNC(ring_get_ws_ex_layoutrtl)
{
	RING_API_RETNUMBER(WS_EX_LAYOUTRTL);
}

RING_FUNC(ring_get_ws_ex_noinheritlayout)
{
	RING_API_RETNUMBER(WS_EX_NOINHERITLAYOUT);
}


RING_FUNC(ring_GetWindowLong)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(GetWindowLong( (int ) RING_API_GETNUMBER(1), (long ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SetWindowLong)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetWindowLong( (int ) RING_API_GETNUMBER(1), (long ) RING_API_GETNUMBER(2), (long ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_righttoleft) {
	long hWnd = (long) RING_API_GETNUMBER(1);
	long extendedStyle = GetWindowLong(hWnd, GWL_EXSTYLE);
	SetWindowLong(hWnd, GWL_EXSTYLE, extendedStyle | WS_EX_LAYOUTRTL | WS_EX_NOINHERITLAYOUT);
}

RING_LIBINIT
{
	RING_API_REGISTER("getwindowlong",ring_GetWindowLong);
	RING_API_REGISTER("setwindowlong",ring_SetWindowLong);
	RING_API_REGISTER("righttoleft",ring_righttoleft);
	RING_API_REGISTER("get_gwl_exstyle",ring_get_gwl_exstyle);
	RING_API_REGISTER("get_ws_ex_layoutrtl",ring_get_ws_ex_layoutrtl);
	RING_API_REGISTER("get_ws_ex_noinheritlayout",ring_get_ws_ex_noinheritlayout);
}

#include "ring.h"

#include "windows.h"

RING_FUNC(ring_Beep)
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
	RING_API_RETNUMBER(Beep( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}

RING_LIBINIT
{
	RING_API_REGISTER("beep",ring_Beep);
}

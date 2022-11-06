#include "ring.h"
#include "stdlib.h"

void changeValue(int *var)
{
	*var = (*var) + 1;
}

RING_FUNC(ring_changevalue)
{

	if (RING_API_PARACOUNT != 1)
	{
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return;
	}

	if (!RING_API_ISSTRING(1))
	{
		RING_API_ERROR(RING_API_BADPARATYPE);
		return;
	}

	int *p1 = RING_API_GETINTPOINTER(1);
	changeValue(p1);
	RING_API_ACCEPTINTVALUE(1);

}

RING_LIBINIT
{
	RING_API_REGISTER("changevalue",ring_changevalue);
}


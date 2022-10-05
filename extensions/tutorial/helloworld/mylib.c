#include "ring.h"

#include "stdlib.h"

RING_FUNC(ring_myfunction)
{
	printf("Hello, World!");
}

RING_LIBINIT
{
	RING_API_REGISTER("myfunction",ring_myfunction);
}

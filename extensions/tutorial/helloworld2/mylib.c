#include "ring.h"

#include "stdlib.h"

RING_FUNC(ring_myfunction)
{
	printf("Hello, World!");
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("myfunction",ring_myfunction);
}

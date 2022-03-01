/* Copyright (c) 2022 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "httplib.h"
using namespace httplib;

extern "C" {
	#include "ring.h"
	RING_API void ringlib_init(RingState *pRingState);
}
RING_API void ringlib_init(RingState *pRingState)
{
}

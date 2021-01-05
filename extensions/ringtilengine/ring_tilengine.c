#include "ring.h"

/* Copyright (c) 2021 Mahmoud Fayed <msfclipper@yahoo.com> */

#include <tilengine.h>
RING_FUNC(ring_get_tilengine_ver_maj)
{
	RING_API_RETNUMBER(TILENGINE_VER_MAJ);
}

RING_FUNC(ring_get_tilengine_ver_min)
{
	RING_API_RETNUMBER(TILENGINE_VER_MIN);
}

RING_FUNC(ring_get_tilengine_ver_rev)
{
	RING_API_RETNUMBER(TILENGINE_VER_REV);
}

RING_FUNC(ring_get_tilengine_header_version)
{
	RING_API_RETNUMBER(TILENGINE_HEADER_VERSION);
}

RING_FUNC(ring_get_flag_none)
{
	RING_API_RETNUMBER(FLAG_NONE);
}

RING_FUNC(ring_get_flag_flipx)
{
	RING_API_RETNUMBER(FLAG_FLIPX);
}

RING_FUNC(ring_get_flag_flipy)
{
	RING_API_RETNUMBER(FLAG_FLIPY);
}

RING_FUNC(ring_get_flag_rotate)
{
	RING_API_RETNUMBER(FLAG_ROTATE);
}

RING_FUNC(ring_get_flag_priority)
{
	RING_API_RETNUMBER(FLAG_PRIORITY);
}

RING_FUNC(ring_get_flag_masked)
{
	RING_API_RETNUMBER(FLAG_MASKED);
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("get_tilengine_ver_maj",ring_get_tilengine_ver_maj);
	ring_vm_funcregister("get_tilengine_ver_min",ring_get_tilengine_ver_min);
	ring_vm_funcregister("get_tilengine_ver_rev",ring_get_tilengine_ver_rev);
	ring_vm_funcregister("get_tilengine_header_version",ring_get_tilengine_header_version);
	ring_vm_funcregister("get_flag_none",ring_get_flag_none);
	ring_vm_funcregister("get_flag_flipx",ring_get_flag_flipx);
	ring_vm_funcregister("get_flag_flipy",ring_get_flag_flipy);
	ring_vm_funcregister("get_flag_rotate",ring_get_flag_rotate);
	ring_vm_funcregister("get_flag_priority",ring_get_flag_priority);
	ring_vm_funcregister("get_flag_masked",ring_get_flag_masked);
}

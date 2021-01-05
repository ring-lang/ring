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

RING_FUNC(ring_get_blend_none)
{
	RING_API_RETNUMBER(BLEND_NONE);
}

RING_FUNC(ring_get_blend_mix25)
{
	RING_API_RETNUMBER(BLEND_MIX25);
}

RING_FUNC(ring_get_blend_mix50)
{
	RING_API_RETNUMBER(BLEND_MIX50);
}

RING_FUNC(ring_get_blend_mix75)
{
	RING_API_RETNUMBER(BLEND_MIX75);
}

RING_FUNC(ring_get_blend_add)
{
	RING_API_RETNUMBER(BLEND_ADD);
}

RING_FUNC(ring_get_blend_sub)
{
	RING_API_RETNUMBER(BLEND_SUB);
}

RING_FUNC(ring_get_blend_mod)
{
	RING_API_RETNUMBER(BLEND_MOD);
}

RING_FUNC(ring_get_blend_custom)
{
	RING_API_RETNUMBER(BLEND_CUSTOM);
}

RING_FUNC(ring_get_max_blend)
{
	RING_API_RETNUMBER(MAX_BLEND);
}

RING_FUNC(ring_get_blend_mix)
{
	RING_API_RETNUMBER(BLEND_MIX);
}

RING_FUNC(ring_new_tln_affine)
{
	TLN_Affine *pMyPointer ;
	pMyPointer = (TLN_Affine *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Affine)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_Affine");
}

RING_FUNC(ring_new_managed_tln_affine)
{
	TLN_Affine *pMyPointer ;
	pMyPointer = (TLN_Affine *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Affine)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_Affine",ring_state_free);
}

RING_FUNC(ring_destroy_tln_affine)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_affine_angle)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	RING_API_RETNUMBER(pMyPointer->angle);
}

RING_FUNC(ring_set_tln_affine_angle)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	pMyPointer->angle = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_affine_dx)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	RING_API_RETNUMBER(pMyPointer->dx);
}

RING_FUNC(ring_set_tln_affine_dx)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	pMyPointer->dx = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_affine_dy)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	RING_API_RETNUMBER(pMyPointer->dy);
}

RING_FUNC(ring_set_tln_affine_dy)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	pMyPointer->dy = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_affine_sx)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	RING_API_RETNUMBER(pMyPointer->sx);
}

RING_FUNC(ring_set_tln_affine_sx)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	pMyPointer->sx = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_affine_sy)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	RING_API_RETNUMBER(pMyPointer->sy);
}

RING_FUNC(ring_set_tln_affine_sy)
{
	TLN_Affine *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Affine");
	pMyPointer->sy = RING_API_GETNUMBER(2);
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
	ring_vm_funcregister("get_blend_none",ring_get_blend_none);
	ring_vm_funcregister("get_blend_mix25",ring_get_blend_mix25);
	ring_vm_funcregister("get_blend_mix50",ring_get_blend_mix50);
	ring_vm_funcregister("get_blend_mix75",ring_get_blend_mix75);
	ring_vm_funcregister("get_blend_add",ring_get_blend_add);
	ring_vm_funcregister("get_blend_sub",ring_get_blend_sub);
	ring_vm_funcregister("get_blend_mod",ring_get_blend_mod);
	ring_vm_funcregister("get_blend_custom",ring_get_blend_custom);
	ring_vm_funcregister("get_max_blend",ring_get_max_blend);
	ring_vm_funcregister("get_blend_mix",ring_get_blend_mix);
	ring_vm_funcregister("new_tln_affine",ring_new_tln_affine);
	ring_vm_funcregister("new_managed_tln_affine",ring_new_managed_tln_affine);
	ring_vm_funcregister("destroy_tln_affine",ring_destroy_tln_affine);
	ring_vm_funcregister("get_tln_affine_angle",ring_get_tln_affine_angle);
	ring_vm_funcregister("set_tln_affine_angle",ring_set_tln_affine_angle);
	ring_vm_funcregister("get_tln_affine_dx",ring_get_tln_affine_dx);
	ring_vm_funcregister("set_tln_affine_dx",ring_set_tln_affine_dx);
	ring_vm_funcregister("get_tln_affine_dy",ring_get_tln_affine_dy);
	ring_vm_funcregister("set_tln_affine_dy",ring_set_tln_affine_dy);
	ring_vm_funcregister("get_tln_affine_sx",ring_get_tln_affine_sx);
	ring_vm_funcregister("set_tln_affine_sx",ring_set_tln_affine_sx);
	ring_vm_funcregister("get_tln_affine_sy",ring_get_tln_affine_sy);
	ring_vm_funcregister("set_tln_affine_sy",ring_set_tln_affine_sy);
}

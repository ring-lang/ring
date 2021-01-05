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

RING_FUNC(ring_get_tln_overlay_none)
{
	RING_API_RETNUMBER(TLN_OVERLAY_NONE);
}

RING_FUNC(ring_get_tln_overlay_shadowmask)
{
	RING_API_RETNUMBER(TLN_OVERLAY_SHADOWMASK);
}

RING_FUNC(ring_get_tln_overlay_aperture)
{
	RING_API_RETNUMBER(TLN_OVERLAY_APERTURE);
}

RING_FUNC(ring_get_tln_overlay_scanlines)
{
	RING_API_RETNUMBER(TLN_OVERLAY_SCANLINES);
}

RING_FUNC(ring_get_tln_overlay_custom)
{
	RING_API_RETNUMBER(TLN_OVERLAY_CUSTOM);
}

RING_FUNC(ring_get_tln_max_overlay)
{
	RING_API_RETNUMBER(TLN_MAX_OVERLAY);
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

RING_FUNC(ring_new_tile)
{
	Tile *pMyPointer ;
	pMyPointer = (Tile *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Tile)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Tile");
}

RING_FUNC(ring_new_managed_tile)
{
	Tile *pMyPointer ;
	pMyPointer = (Tile *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Tile)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Tile",ring_state_free);
}

RING_FUNC(ring_destroy_tile)
{
	Tile *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Tile");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tile_value)
{
	Tile *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Tile");
	RING_API_RETNUMBER(pMyPointer->value);
}

RING_FUNC(ring_set_tile_value)
{
	Tile *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"Tile");
	pMyPointer->value = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tile_index)
{
	Tile *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Tile");
	RING_API_RETNUMBER(pMyPointer->index);
}

RING_FUNC(ring_set_tile_index)
{
	Tile *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"Tile");
	pMyPointer->index = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tile_flags)
{
	Tile *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"Tile");
	RING_API_RETNUMBER(pMyPointer->flags);
}

RING_FUNC(ring_set_tile_flags)
{
	Tile *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"Tile");
	pMyPointer->flags = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_sequenceframe)
{
	TLN_SequenceFrame *pMyPointer ;
	pMyPointer = (TLN_SequenceFrame *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SequenceFrame)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_SequenceFrame");
}

RING_FUNC(ring_new_managed_tln_sequenceframe)
{
	TLN_SequenceFrame *pMyPointer ;
	pMyPointer = (TLN_SequenceFrame *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SequenceFrame)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_SequenceFrame",ring_state_free);
}

RING_FUNC(ring_destroy_tln_sequenceframe)
{
	TLN_SequenceFrame *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceFrame");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_sequenceframe_index)
{
	TLN_SequenceFrame *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceFrame");
	RING_API_RETNUMBER(pMyPointer->index);
}

RING_FUNC(ring_set_tln_sequenceframe_index)
{
	TLN_SequenceFrame *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceFrame");
	pMyPointer->index = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_sequenceframe_delay)
{
	TLN_SequenceFrame *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceFrame");
	RING_API_RETNUMBER(pMyPointer->delay);
}

RING_FUNC(ring_set_tln_sequenceframe_delay)
{
	TLN_SequenceFrame *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceFrame");
	pMyPointer->delay = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_colorstrip)
{
	TLN_ColorStrip *pMyPointer ;
	pMyPointer = (TLN_ColorStrip *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_ColorStrip)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_ColorStrip");
}

RING_FUNC(ring_new_managed_tln_colorstrip)
{
	TLN_ColorStrip *pMyPointer ;
	pMyPointer = (TLN_ColorStrip *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_ColorStrip)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_ColorStrip",ring_state_free);
}

RING_FUNC(ring_destroy_tln_colorstrip)
{
	TLN_ColorStrip *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_colorstrip_delay)
{
	TLN_ColorStrip *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	RING_API_RETNUMBER(pMyPointer->delay);
}

RING_FUNC(ring_set_tln_colorstrip_delay)
{
	TLN_ColorStrip *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	pMyPointer->delay = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_colorstrip_first)
{
	TLN_ColorStrip *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	RING_API_RETNUMBER(pMyPointer->first);
}

RING_FUNC(ring_set_tln_colorstrip_first)
{
	TLN_ColorStrip *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	pMyPointer->first = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_colorstrip_count)
{
	TLN_ColorStrip *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	RING_API_RETNUMBER(pMyPointer->count);
}

RING_FUNC(ring_set_tln_colorstrip_count)
{
	TLN_ColorStrip *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	pMyPointer->count = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_colorstrip_dir)
{
	TLN_ColorStrip *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	RING_API_RETNUMBER(pMyPointer->dir);
}

RING_FUNC(ring_set_tln_colorstrip_dir)
{
	TLN_ColorStrip *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ColorStrip");
	pMyPointer->dir = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_sequenceinfo)
{
	TLN_SequenceInfo *pMyPointer ;
	pMyPointer = (TLN_SequenceInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SequenceInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_SequenceInfo");
}

RING_FUNC(ring_new_managed_tln_sequenceinfo)
{
	TLN_SequenceInfo *pMyPointer ;
	pMyPointer = (TLN_SequenceInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SequenceInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_SequenceInfo",ring_state_free);
}

RING_FUNC(ring_destroy_tln_sequenceinfo)
{
	TLN_SequenceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_sequenceinfo_num_frames)
{
	TLN_SequenceInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceInfo");
	RING_API_RETNUMBER(pMyPointer->num_frames);
}

RING_FUNC(ring_set_tln_sequenceinfo_num_frames)
{
	TLN_SequenceInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SequenceInfo");
	pMyPointer->num_frames = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_spritedata)
{
	TLN_SpriteData *pMyPointer ;
	pMyPointer = (TLN_SpriteData *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SpriteData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_SpriteData");
}

RING_FUNC(ring_new_managed_tln_spritedata)
{
	TLN_SpriteData *pMyPointer ;
	pMyPointer = (TLN_SpriteData *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SpriteData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_SpriteData",ring_state_free);
}

RING_FUNC(ring_destroy_tln_spritedata)
{
	TLN_SpriteData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_spritedata_x)
{
	TLN_SpriteData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_set_tln_spritedata_x)
{
	TLN_SpriteData *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritedata_y)
{
	TLN_SpriteData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_set_tln_spritedata_y)
{
	TLN_SpriteData *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritedata_w)
{
	TLN_SpriteData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	RING_API_RETNUMBER(pMyPointer->w);
}

RING_FUNC(ring_set_tln_spritedata_w)
{
	TLN_SpriteData *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	pMyPointer->w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritedata_h)
{
	TLN_SpriteData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	RING_API_RETNUMBER(pMyPointer->h);
}

RING_FUNC(ring_set_tln_spritedata_h)
{
	TLN_SpriteData *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteData");
	pMyPointer->h = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_spriteinfo)
{
	TLN_SpriteInfo *pMyPointer ;
	pMyPointer = (TLN_SpriteInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SpriteInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_SpriteInfo");
}

RING_FUNC(ring_new_managed_tln_spriteinfo)
{
	TLN_SpriteInfo *pMyPointer ;
	pMyPointer = (TLN_SpriteInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SpriteInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_SpriteInfo",ring_state_free);
}

RING_FUNC(ring_destroy_tln_spriteinfo)
{
	TLN_SpriteInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_spriteinfo_w)
{
	TLN_SpriteInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteInfo");
	RING_API_RETNUMBER(pMyPointer->w);
}

RING_FUNC(ring_set_tln_spriteinfo_w)
{
	TLN_SpriteInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteInfo");
	pMyPointer->w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spriteinfo_h)
{
	TLN_SpriteInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteInfo");
	RING_API_RETNUMBER(pMyPointer->h);
}

RING_FUNC(ring_set_tln_spriteinfo_h)
{
	TLN_SpriteInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteInfo");
	pMyPointer->h = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_tileinfo)
{
	TLN_TileInfo *pMyPointer ;
	pMyPointer = (TLN_TileInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_TileInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_TileInfo");
}

RING_FUNC(ring_new_managed_tln_tileinfo)
{
	TLN_TileInfo *pMyPointer ;
	pMyPointer = (TLN_TileInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_TileInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_TileInfo",ring_state_free);
}

RING_FUNC(ring_destroy_tln_tileinfo)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_tileinfo_index)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->index);
}

RING_FUNC(ring_set_tln_tileinfo_index)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->index = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_flags)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->flags);
}

RING_FUNC(ring_set_tln_tileinfo_flags)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->flags = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_row)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->row);
}

RING_FUNC(ring_set_tln_tileinfo_row)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->row = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_col)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->col);
}

RING_FUNC(ring_set_tln_tileinfo_col)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->col = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_xoffset)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->xoffset);
}

RING_FUNC(ring_set_tln_tileinfo_xoffset)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->xoffset = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_yoffset)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->yoffset);
}

RING_FUNC(ring_set_tln_tileinfo_yoffset)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->yoffset = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_color)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->color);
}

RING_FUNC(ring_set_tln_tileinfo_color)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->color = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_type)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_set_tln_tileinfo_type)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileinfo_empty)
{
	TLN_TileInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	RING_API_RETNUMBER(pMyPointer->empty);
}

RING_FUNC(ring_set_tln_tileinfo_empty)
{
	TLN_TileInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileInfo");
	pMyPointer->empty = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_objectinfo)
{
	TLN_ObjectInfo *pMyPointer ;
	pMyPointer = (TLN_ObjectInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_ObjectInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_ObjectInfo");
}

RING_FUNC(ring_new_managed_tln_objectinfo)
{
	TLN_ObjectInfo *pMyPointer ;
	pMyPointer = (TLN_ObjectInfo *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_ObjectInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_ObjectInfo",ring_state_free);
}

RING_FUNC(ring_destroy_tln_objectinfo)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_objectinfo_id)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->id);
}

RING_FUNC(ring_set_tln_objectinfo_id)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_gid)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->gid);
}

RING_FUNC(ring_set_tln_objectinfo_gid)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->gid = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_flags)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->flags);
}

RING_FUNC(ring_set_tln_objectinfo_flags)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->flags = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_x)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_set_tln_objectinfo_x)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_y)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_set_tln_objectinfo_y)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_width)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->width);
}

RING_FUNC(ring_set_tln_objectinfo_width)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_height)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->height);
}

RING_FUNC(ring_set_tln_objectinfo_height)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->height = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_type)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_set_tln_objectinfo_type)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_objectinfo_visible)
{
	TLN_ObjectInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	RING_API_RETNUMBER(pMyPointer->visible);
}

RING_FUNC(ring_set_tln_objectinfo_visible)
{
	TLN_ObjectInfo *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_ObjectInfo");
	pMyPointer->visible = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_tileattributes)
{
	TLN_TileAttributes *pMyPointer ;
	pMyPointer = (TLN_TileAttributes *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_TileAttributes)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_TileAttributes");
}

RING_FUNC(ring_new_managed_tln_tileattributes)
{
	TLN_TileAttributes *pMyPointer ;
	pMyPointer = (TLN_TileAttributes *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_TileAttributes)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_TileAttributes",ring_state_free);
}

RING_FUNC(ring_destroy_tln_tileattributes)
{
	TLN_TileAttributes *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileAttributes");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_tileattributes_type)
{
	TLN_TileAttributes *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileAttributes");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_set_tln_tileattributes_type)
{
	TLN_TileAttributes *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileAttributes");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileattributes_priority)
{
	TLN_TileAttributes *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileAttributes");
	RING_API_RETNUMBER(pMyPointer->priority);
}

RING_FUNC(ring_set_tln_tileattributes_priority)
{
	TLN_TileAttributes *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileAttributes");
	pMyPointer->priority = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_pixelmap)
{
	TLN_PixelMap *pMyPointer ;
	pMyPointer = (TLN_PixelMap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_PixelMap)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_PixelMap");
}

RING_FUNC(ring_new_managed_tln_pixelmap)
{
	TLN_PixelMap *pMyPointer ;
	pMyPointer = (TLN_PixelMap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_PixelMap)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_PixelMap",ring_state_free);
}

RING_FUNC(ring_destroy_tln_pixelmap)
{
	TLN_PixelMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_PixelMap");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_pixelmap_dx)
{
	TLN_PixelMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_PixelMap");
	RING_API_RETNUMBER(pMyPointer->dx);
}

RING_FUNC(ring_set_tln_pixelmap_dx)
{
	TLN_PixelMap *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_PixelMap");
	pMyPointer->dx = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_pixelmap_dy)
{
	TLN_PixelMap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_PixelMap");
	RING_API_RETNUMBER(pMyPointer->dy);
}

RING_FUNC(ring_set_tln_pixelmap_dy)
{
	TLN_PixelMap *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_PixelMap");
	pMyPointer->dy = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_tileimage)
{
	TLN_TileImage *pMyPointer ;
	pMyPointer = (TLN_TileImage *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_TileImage)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_TileImage");
}

RING_FUNC(ring_new_managed_tln_tileimage)
{
	TLN_TileImage *pMyPointer ;
	pMyPointer = (TLN_TileImage *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_TileImage)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_TileImage",ring_state_free);
}

RING_FUNC(ring_destroy_tln_tileimage)
{
	TLN_TileImage *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileImage");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_tileimage_id)
{
	TLN_TileImage *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileImage");
	RING_API_RETNUMBER(pMyPointer->id);
}

RING_FUNC(ring_set_tln_tileimage_id)
{
	TLN_TileImage *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileImage");
	pMyPointer->id = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_tileimage_type)
{
	TLN_TileImage *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileImage");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_set_tln_tileimage_type)
{
	TLN_TileImage *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_TileImage");
	pMyPointer->type = RING_API_GETNUMBER(2);
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
	ring_vm_funcregister("get_tln_overlay_none",ring_get_tln_overlay_none);
	ring_vm_funcregister("get_tln_overlay_shadowmask",ring_get_tln_overlay_shadowmask);
	ring_vm_funcregister("get_tln_overlay_aperture",ring_get_tln_overlay_aperture);
	ring_vm_funcregister("get_tln_overlay_scanlines",ring_get_tln_overlay_scanlines);
	ring_vm_funcregister("get_tln_overlay_custom",ring_get_tln_overlay_custom);
	ring_vm_funcregister("get_tln_max_overlay",ring_get_tln_max_overlay);
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
	ring_vm_funcregister("new_tile",ring_new_tile);
	ring_vm_funcregister("new_managed_tile",ring_new_managed_tile);
	ring_vm_funcregister("destroy_tile",ring_destroy_tile);
	ring_vm_funcregister("get_tile_value",ring_get_tile_value);
	ring_vm_funcregister("set_tile_value",ring_set_tile_value);
	ring_vm_funcregister("get_tile_index",ring_get_tile_index);
	ring_vm_funcregister("set_tile_index",ring_set_tile_index);
	ring_vm_funcregister("get_tile_flags",ring_get_tile_flags);
	ring_vm_funcregister("set_tile_flags",ring_set_tile_flags);
	ring_vm_funcregister("new_tln_sequenceframe",ring_new_tln_sequenceframe);
	ring_vm_funcregister("new_managed_tln_sequenceframe",ring_new_managed_tln_sequenceframe);
	ring_vm_funcregister("destroy_tln_sequenceframe",ring_destroy_tln_sequenceframe);
	ring_vm_funcregister("get_tln_sequenceframe_index",ring_get_tln_sequenceframe_index);
	ring_vm_funcregister("set_tln_sequenceframe_index",ring_set_tln_sequenceframe_index);
	ring_vm_funcregister("get_tln_sequenceframe_delay",ring_get_tln_sequenceframe_delay);
	ring_vm_funcregister("set_tln_sequenceframe_delay",ring_set_tln_sequenceframe_delay);
	ring_vm_funcregister("new_tln_colorstrip",ring_new_tln_colorstrip);
	ring_vm_funcregister("new_managed_tln_colorstrip",ring_new_managed_tln_colorstrip);
	ring_vm_funcregister("destroy_tln_colorstrip",ring_destroy_tln_colorstrip);
	ring_vm_funcregister("get_tln_colorstrip_delay",ring_get_tln_colorstrip_delay);
	ring_vm_funcregister("set_tln_colorstrip_delay",ring_set_tln_colorstrip_delay);
	ring_vm_funcregister("get_tln_colorstrip_first",ring_get_tln_colorstrip_first);
	ring_vm_funcregister("set_tln_colorstrip_first",ring_set_tln_colorstrip_first);
	ring_vm_funcregister("get_tln_colorstrip_count",ring_get_tln_colorstrip_count);
	ring_vm_funcregister("set_tln_colorstrip_count",ring_set_tln_colorstrip_count);
	ring_vm_funcregister("get_tln_colorstrip_dir",ring_get_tln_colorstrip_dir);
	ring_vm_funcregister("set_tln_colorstrip_dir",ring_set_tln_colorstrip_dir);
	ring_vm_funcregister("new_tln_sequenceinfo",ring_new_tln_sequenceinfo);
	ring_vm_funcregister("new_managed_tln_sequenceinfo",ring_new_managed_tln_sequenceinfo);
	ring_vm_funcregister("destroy_tln_sequenceinfo",ring_destroy_tln_sequenceinfo);
	ring_vm_funcregister("get_tln_sequenceinfo_num_frames",ring_get_tln_sequenceinfo_num_frames);
	ring_vm_funcregister("set_tln_sequenceinfo_num_frames",ring_set_tln_sequenceinfo_num_frames);
	ring_vm_funcregister("new_tln_spritedata",ring_new_tln_spritedata);
	ring_vm_funcregister("new_managed_tln_spritedata",ring_new_managed_tln_spritedata);
	ring_vm_funcregister("destroy_tln_spritedata",ring_destroy_tln_spritedata);
	ring_vm_funcregister("get_tln_spritedata_x",ring_get_tln_spritedata_x);
	ring_vm_funcregister("set_tln_spritedata_x",ring_set_tln_spritedata_x);
	ring_vm_funcregister("get_tln_spritedata_y",ring_get_tln_spritedata_y);
	ring_vm_funcregister("set_tln_spritedata_y",ring_set_tln_spritedata_y);
	ring_vm_funcregister("get_tln_spritedata_w",ring_get_tln_spritedata_w);
	ring_vm_funcregister("set_tln_spritedata_w",ring_set_tln_spritedata_w);
	ring_vm_funcregister("get_tln_spritedata_h",ring_get_tln_spritedata_h);
	ring_vm_funcregister("set_tln_spritedata_h",ring_set_tln_spritedata_h);
	ring_vm_funcregister("new_tln_spriteinfo",ring_new_tln_spriteinfo);
	ring_vm_funcregister("new_managed_tln_spriteinfo",ring_new_managed_tln_spriteinfo);
	ring_vm_funcregister("destroy_tln_spriteinfo",ring_destroy_tln_spriteinfo);
	ring_vm_funcregister("get_tln_spriteinfo_w",ring_get_tln_spriteinfo_w);
	ring_vm_funcregister("set_tln_spriteinfo_w",ring_set_tln_spriteinfo_w);
	ring_vm_funcregister("get_tln_spriteinfo_h",ring_get_tln_spriteinfo_h);
	ring_vm_funcregister("set_tln_spriteinfo_h",ring_set_tln_spriteinfo_h);
	ring_vm_funcregister("new_tln_tileinfo",ring_new_tln_tileinfo);
	ring_vm_funcregister("new_managed_tln_tileinfo",ring_new_managed_tln_tileinfo);
	ring_vm_funcregister("destroy_tln_tileinfo",ring_destroy_tln_tileinfo);
	ring_vm_funcregister("get_tln_tileinfo_index",ring_get_tln_tileinfo_index);
	ring_vm_funcregister("set_tln_tileinfo_index",ring_set_tln_tileinfo_index);
	ring_vm_funcregister("get_tln_tileinfo_flags",ring_get_tln_tileinfo_flags);
	ring_vm_funcregister("set_tln_tileinfo_flags",ring_set_tln_tileinfo_flags);
	ring_vm_funcregister("get_tln_tileinfo_row",ring_get_tln_tileinfo_row);
	ring_vm_funcregister("set_tln_tileinfo_row",ring_set_tln_tileinfo_row);
	ring_vm_funcregister("get_tln_tileinfo_col",ring_get_tln_tileinfo_col);
	ring_vm_funcregister("set_tln_tileinfo_col",ring_set_tln_tileinfo_col);
	ring_vm_funcregister("get_tln_tileinfo_xoffset",ring_get_tln_tileinfo_xoffset);
	ring_vm_funcregister("set_tln_tileinfo_xoffset",ring_set_tln_tileinfo_xoffset);
	ring_vm_funcregister("get_tln_tileinfo_yoffset",ring_get_tln_tileinfo_yoffset);
	ring_vm_funcregister("set_tln_tileinfo_yoffset",ring_set_tln_tileinfo_yoffset);
	ring_vm_funcregister("get_tln_tileinfo_color",ring_get_tln_tileinfo_color);
	ring_vm_funcregister("set_tln_tileinfo_color",ring_set_tln_tileinfo_color);
	ring_vm_funcregister("get_tln_tileinfo_type",ring_get_tln_tileinfo_type);
	ring_vm_funcregister("set_tln_tileinfo_type",ring_set_tln_tileinfo_type);
	ring_vm_funcregister("get_tln_tileinfo_empty",ring_get_tln_tileinfo_empty);
	ring_vm_funcregister("set_tln_tileinfo_empty",ring_set_tln_tileinfo_empty);
	ring_vm_funcregister("new_tln_objectinfo",ring_new_tln_objectinfo);
	ring_vm_funcregister("new_managed_tln_objectinfo",ring_new_managed_tln_objectinfo);
	ring_vm_funcregister("destroy_tln_objectinfo",ring_destroy_tln_objectinfo);
	ring_vm_funcregister("get_tln_objectinfo_id",ring_get_tln_objectinfo_id);
	ring_vm_funcregister("set_tln_objectinfo_id",ring_set_tln_objectinfo_id);
	ring_vm_funcregister("get_tln_objectinfo_gid",ring_get_tln_objectinfo_gid);
	ring_vm_funcregister("set_tln_objectinfo_gid",ring_set_tln_objectinfo_gid);
	ring_vm_funcregister("get_tln_objectinfo_flags",ring_get_tln_objectinfo_flags);
	ring_vm_funcregister("set_tln_objectinfo_flags",ring_set_tln_objectinfo_flags);
	ring_vm_funcregister("get_tln_objectinfo_x",ring_get_tln_objectinfo_x);
	ring_vm_funcregister("set_tln_objectinfo_x",ring_set_tln_objectinfo_x);
	ring_vm_funcregister("get_tln_objectinfo_y",ring_get_tln_objectinfo_y);
	ring_vm_funcregister("set_tln_objectinfo_y",ring_set_tln_objectinfo_y);
	ring_vm_funcregister("get_tln_objectinfo_width",ring_get_tln_objectinfo_width);
	ring_vm_funcregister("set_tln_objectinfo_width",ring_set_tln_objectinfo_width);
	ring_vm_funcregister("get_tln_objectinfo_height",ring_get_tln_objectinfo_height);
	ring_vm_funcregister("set_tln_objectinfo_height",ring_set_tln_objectinfo_height);
	ring_vm_funcregister("get_tln_objectinfo_type",ring_get_tln_objectinfo_type);
	ring_vm_funcregister("set_tln_objectinfo_type",ring_set_tln_objectinfo_type);
	ring_vm_funcregister("get_tln_objectinfo_visible",ring_get_tln_objectinfo_visible);
	ring_vm_funcregister("set_tln_objectinfo_visible",ring_set_tln_objectinfo_visible);
	ring_vm_funcregister("new_tln_tileattributes",ring_new_tln_tileattributes);
	ring_vm_funcregister("new_managed_tln_tileattributes",ring_new_managed_tln_tileattributes);
	ring_vm_funcregister("destroy_tln_tileattributes",ring_destroy_tln_tileattributes);
	ring_vm_funcregister("get_tln_tileattributes_type",ring_get_tln_tileattributes_type);
	ring_vm_funcregister("set_tln_tileattributes_type",ring_set_tln_tileattributes_type);
	ring_vm_funcregister("get_tln_tileattributes_priority",ring_get_tln_tileattributes_priority);
	ring_vm_funcregister("set_tln_tileattributes_priority",ring_set_tln_tileattributes_priority);
	ring_vm_funcregister("new_tln_pixelmap",ring_new_tln_pixelmap);
	ring_vm_funcregister("new_managed_tln_pixelmap",ring_new_managed_tln_pixelmap);
	ring_vm_funcregister("destroy_tln_pixelmap",ring_destroy_tln_pixelmap);
	ring_vm_funcregister("get_tln_pixelmap_dx",ring_get_tln_pixelmap_dx);
	ring_vm_funcregister("set_tln_pixelmap_dx",ring_set_tln_pixelmap_dx);
	ring_vm_funcregister("get_tln_pixelmap_dy",ring_get_tln_pixelmap_dy);
	ring_vm_funcregister("set_tln_pixelmap_dy",ring_set_tln_pixelmap_dy);
	ring_vm_funcregister("new_tln_tileimage",ring_new_tln_tileimage);
	ring_vm_funcregister("new_managed_tln_tileimage",ring_new_managed_tln_tileimage);
	ring_vm_funcregister("destroy_tln_tileimage",ring_destroy_tln_tileimage);
	ring_vm_funcregister("get_tln_tileimage_id",ring_get_tln_tileimage_id);
	ring_vm_funcregister("set_tln_tileimage_id",ring_set_tln_tileimage_id);
	ring_vm_funcregister("get_tln_tileimage_type",ring_get_tln_tileimage_type);
	ring_vm_funcregister("set_tln_tileimage_type",ring_set_tln_tileimage_type);
}

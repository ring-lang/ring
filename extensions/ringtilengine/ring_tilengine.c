#include "ring.h"

/* Copyright(c) 2021 Mahmoud Fayed <msfclipper@yahoo.com> */

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

RING_FUNC(ring_get_player1)
{
	RING_API_RETNUMBER(PLAYER1);
}

RING_FUNC(ring_get_player2)
{
	RING_API_RETNUMBER(PLAYER2);
}

RING_FUNC(ring_get_player3)
{
	RING_API_RETNUMBER(PLAYER3);
}

RING_FUNC(ring_get_player4)
{
	RING_API_RETNUMBER(PLAYER4);
}

RING_FUNC(ring_get_input_none)
{
	RING_API_RETNUMBER(INPUT_NONE);
}

RING_FUNC(ring_get_input_up)
{
	RING_API_RETNUMBER(INPUT_UP);
}

RING_FUNC(ring_get_input_down)
{
	RING_API_RETNUMBER(INPUT_DOWN);
}

RING_FUNC(ring_get_input_left)
{
	RING_API_RETNUMBER(INPUT_LEFT);
}

RING_FUNC(ring_get_input_right)
{
	RING_API_RETNUMBER(INPUT_RIGHT);
}

RING_FUNC(ring_get_input_button1)
{
	RING_API_RETNUMBER(INPUT_BUTTON1);
}

RING_FUNC(ring_get_input_button2)
{
	RING_API_RETNUMBER(INPUT_BUTTON2);
}

RING_FUNC(ring_get_input_button3)
{
	RING_API_RETNUMBER(INPUT_BUTTON3);
}

RING_FUNC(ring_get_input_button4)
{
	RING_API_RETNUMBER(INPUT_BUTTON4);
}

RING_FUNC(ring_get_input_button5)
{
	RING_API_RETNUMBER(INPUT_BUTTON5);
}

RING_FUNC(ring_get_input_button6)
{
	RING_API_RETNUMBER(INPUT_BUTTON6);
}

RING_FUNC(ring_get_input_start)
{
	RING_API_RETNUMBER(INPUT_START);
}

RING_FUNC(ring_get_input_quit)
{
	RING_API_RETNUMBER(INPUT_QUIT);
}

RING_FUNC(ring_get_input_crt)
{
	RING_API_RETNUMBER(INPUT_CRT);
}

RING_FUNC(ring_get_input_p1)
{
	RING_API_RETNUMBER(INPUT_P1);
}

RING_FUNC(ring_get_input_p2)
{
	RING_API_RETNUMBER(INPUT_P2);
}

RING_FUNC(ring_get_input_p3)
{
	RING_API_RETNUMBER(INPUT_P3);
}

RING_FUNC(ring_get_input_p4)
{
	RING_API_RETNUMBER(INPUT_P4);
}

RING_FUNC(ring_get_input_a)
{
	RING_API_RETNUMBER(INPUT_A);
}

RING_FUNC(ring_get_input_b)
{
	RING_API_RETNUMBER(INPUT_B);
}

RING_FUNC(ring_get_input_c)
{
	RING_API_RETNUMBER(INPUT_C);
}

RING_FUNC(ring_get_input_d)
{
	RING_API_RETNUMBER(INPUT_D);
}

RING_FUNC(ring_get_input_e)
{
	RING_API_RETNUMBER(INPUT_E);
}

RING_FUNC(ring_get_input_f)
{
	RING_API_RETNUMBER(INPUT_F);
}

RING_FUNC(ring_get_cwf_fullscreen)
{
	RING_API_RETNUMBER(CWF_FULLSCREEN);
}

RING_FUNC(ring_get_cwf_vsync)
{
	RING_API_RETNUMBER(CWF_VSYNC);
}

RING_FUNC(ring_get_cwf_s1)
{
	RING_API_RETNUMBER(CWF_S1);
}

RING_FUNC(ring_get_cwf_s2)
{
	RING_API_RETNUMBER(CWF_S2);
}

RING_FUNC(ring_get_cwf_s3)
{
	RING_API_RETNUMBER(CWF_S3);
}

RING_FUNC(ring_get_cwf_s4)
{
	RING_API_RETNUMBER(CWF_S4);
}

RING_FUNC(ring_get_cwf_s5)
{
	RING_API_RETNUMBER(CWF_S5);
}

RING_FUNC(ring_get_tln_err_ok)
{
	RING_API_RETNUMBER(TLN_ERR_OK);
}

RING_FUNC(ring_get_tln_err_out_of_memory)
{
	RING_API_RETNUMBER(TLN_ERR_OUT_OF_MEMORY);
}

RING_FUNC(ring_get_tln_err_idx_layer)
{
	RING_API_RETNUMBER(TLN_ERR_IDX_LAYER);
}

RING_FUNC(ring_get_tln_err_idx_sprite)
{
	RING_API_RETNUMBER(TLN_ERR_IDX_SPRITE);
}

RING_FUNC(ring_get_tln_err_idx_animation)
{
	RING_API_RETNUMBER(TLN_ERR_IDX_ANIMATION);
}

RING_FUNC(ring_get_tln_err_idx_picture)
{
	RING_API_RETNUMBER(TLN_ERR_IDX_PICTURE);
}

RING_FUNC(ring_get_tln_err_ref_tileset)
{
	RING_API_RETNUMBER(TLN_ERR_REF_TILESET);
}

RING_FUNC(ring_get_tln_err_ref_tilemap)
{
	RING_API_RETNUMBER(TLN_ERR_REF_TILEMAP);
}

RING_FUNC(ring_get_tln_err_ref_spriteset)
{
	RING_API_RETNUMBER(TLN_ERR_REF_SPRITESET);
}

RING_FUNC(ring_get_tln_err_ref_palette)
{
	RING_API_RETNUMBER(TLN_ERR_REF_PALETTE);
}

RING_FUNC(ring_get_tln_err_ref_sequence)
{
	RING_API_RETNUMBER(TLN_ERR_REF_SEQUENCE);
}

RING_FUNC(ring_get_tln_err_ref_seqpack)
{
	RING_API_RETNUMBER(TLN_ERR_REF_SEQPACK);
}

RING_FUNC(ring_get_tln_err_ref_bitmap)
{
	RING_API_RETNUMBER(TLN_ERR_REF_BITMAP);
}

RING_FUNC(ring_get_tln_err_null_pointer)
{
	RING_API_RETNUMBER(TLN_ERR_NULL_POINTER);
}

RING_FUNC(ring_get_tln_err_file_not_found)
{
	RING_API_RETNUMBER(TLN_ERR_FILE_NOT_FOUND);
}

RING_FUNC(ring_get_tln_err_wrong_format)
{
	RING_API_RETNUMBER(TLN_ERR_WRONG_FORMAT);
}

RING_FUNC(ring_get_tln_err_wrong_size)
{
	RING_API_RETNUMBER(TLN_ERR_WRONG_SIZE);
}

RING_FUNC(ring_get_tln_err_unsupported)
{
	RING_API_RETNUMBER(TLN_ERR_UNSUPPORTED);
}

RING_FUNC(ring_get_tln_err_ref_list)
{
	RING_API_RETNUMBER(TLN_ERR_REF_LIST);
}

RING_FUNC(ring_get_tln_max_err)
{
	RING_API_RETNUMBER(TLN_MAX_ERR);
}

RING_FUNC(ring_get_tln_log_none)
{
	RING_API_RETNUMBER(TLN_LOG_NONE);
}

RING_FUNC(ring_get_tln_log_errors)
{
	RING_API_RETNUMBER(TLN_LOG_ERRORS);
}

RING_FUNC(ring_get_tln_log_verbose)
{
	RING_API_RETNUMBER(TLN_LOG_VERBOSE);
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

RING_FUNC(ring_new_tln_spritestate)
{
	TLN_SpriteState *pMyPointer ;
	pMyPointer = (TLN_SpriteState *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SpriteState)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_SpriteState");
}

RING_FUNC(ring_new_managed_tln_spritestate)
{
	TLN_SpriteState *pMyPointer ;
	pMyPointer = (TLN_SpriteState *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SpriteState)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_SpriteState",ring_state_free);
}

RING_FUNC(ring_destroy_tln_spritestate)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_tln_spritestate_x)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_set_tln_spritestate_x)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritestate_y)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_set_tln_spritestate_y)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritestate_w)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->w);
}

RING_FUNC(ring_set_tln_spritestate_w)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritestate_h)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->h);
}

RING_FUNC(ring_set_tln_spritestate_h)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->h = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritestate_flags)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->flags);
}

RING_FUNC(ring_set_tln_spritestate_flags)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->flags = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritestate_index)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->index);
}

RING_FUNC(ring_set_tln_spritestate_index)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->index = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritestate_enabled)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->enabled);
}

RING_FUNC(ring_set_tln_spritestate_enabled)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->enabled = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_tln_spritestate_collision)
{
	TLN_SpriteState *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	RING_API_RETNUMBER(pMyPointer->collision);
}

RING_FUNC(ring_set_tln_spritestate_collision)
{
	TLN_SpriteState *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_SpriteState");
	pMyPointer->collision = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_tln_tilemap)
{
	TLN_Tilemap *pMyPointer ;
	pMyPointer = (TLN_Tilemap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tilemap)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TLN_Tilemap");
}

RING_FUNC(ring_new_managed_tln_tilemap)
{
	TLN_Tilemap *pMyPointer ;
	pMyPointer = (TLN_Tilemap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tilemap)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TLN_Tilemap",ring_state_free);
}

RING_FUNC(ring_destroy_tln_tilemap)
{
	TLN_Tilemap *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"TLN_Tilemap");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_TLN_Init)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	{
		TLN_Engine *pValue ; 
		pValue = (TLN_Engine *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Engine)) ;
		*pValue = TLN_Init( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Engine",ring_state_free);
	}
}


RING_FUNC(ring_TLN_Deinit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_Deinit();
}


RING_FUNC(ring_TLN_DeleteContext)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteContext(* (TLN_Engine  *) RING_API_GETCPOINTER(1,"TLN_Engine")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Engine"));
}


RING_FUNC(ring_TLN_SetContext)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_SetContext(* (TLN_Engine  *) RING_API_GETCPOINTER(1,"TLN_Engine")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Engine"));
}


RING_FUNC(ring_TLN_GetContext)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Engine *pValue ; 
		pValue = (TLN_Engine *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Engine)) ;
		*pValue = TLN_GetContext();
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Engine",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetWidth)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetWidth());
}


RING_FUNC(ring_TLN_GetHeight)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetHeight());
}


RING_FUNC(ring_TLN_GetNumObjects)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetNumObjects());
}


RING_FUNC(ring_TLN_GetUsedMemory)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetUsedMemory());
}


RING_FUNC(ring_TLN_GetVersion)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetVersion());
}


RING_FUNC(ring_TLN_GetNumLayers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetNumLayers());
}


RING_FUNC(ring_TLN_GetNumSprites)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetNumSprites());
}


RING_FUNC(ring_TLN_SetBGColor)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	TLN_SetBGColor( (uint8_t ) RING_API_GETNUMBER(1), (uint8_t ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_TLN_SetBGColorFromTilemap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_SetBGColorFromTilemap(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
}


RING_FUNC(ring_TLN_DisableBGColor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_DisableBGColor();
}


RING_FUNC(ring_TLN_SetBGBitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_SetBGBitmap(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_SetBGPalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_SetBGPalette(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
}


RING_FUNC(ring_TLN_SetRasterCallback)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_SetRasterCallback(* (TLN_VideoCallback *) RING_API_GETCPOINTER(1,"TLN_VideoCallback"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_VideoCallback"));
}


RING_FUNC(ring_TLN_SetFrameCallback)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_SetFrameCallback(* (TLN_VideoCallback *) RING_API_GETCPOINTER(1,"TLN_VideoCallback"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_VideoCallback"));
}


RING_FUNC(ring_TLN_SetRenderTarget)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_SetRenderTarget((uint8_t *) RING_API_GETCPOINTER(1,"uint8_t"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TLN_UpdateFrame)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_UpdateFrame( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_TLN_SetLoadPath)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_SetLoadPath(RING_API_GETSTRING(1));
}


RING_FUNC(ring_TLN_SetCustomBlendFunction)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_SetCustomBlendFunction(* (TLN_BlendFunction *) RING_API_GETCPOINTER(1,"TLN_BlendFunction"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_BlendFunction"));
}


RING_FUNC(ring_TLN_SetLogLevel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_SetLogLevel( (TLN_LogLevel )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_TLN_OpenResourcePack)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_OpenResourcePack(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_TLN_CloseResourcePack)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_CloseResourcePack();
}


RING_FUNC(ring_TLN_SetLastError)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_SetLastError( (TLN_Error )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_TLN_GetLastError)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetLastError());
}


RING_FUNC(ring_TLN_GetErrorString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TLN_GetErrorString( (TLN_Error )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_CreateWindow)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_CreateWindow(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_CreateWindowThread)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_CreateWindowThread(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_SetWindowTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_SetWindowTitle(RING_API_GETSTRING(1));
}


RING_FUNC(ring_TLN_ProcessWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_ProcessWindow());
}


RING_FUNC(ring_TLN_IsWindowActive)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_IsWindowActive());
}


RING_FUNC(ring_TLN_GetInput)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetInput( (TLN_Input )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_EnableInput)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_EnableInput( (TLN_Player )  (int) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TLN_AssignInputJoystick)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_AssignInputJoystick( (TLN_Player )  (int) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TLN_DefineInputKey)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	TLN_DefineInputKey( (TLN_Player )  (int) RING_API_GETNUMBER(1), (TLN_Input )  (int) RING_API_GETNUMBER(2), (uint32_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_TLN_DefineInputButton)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	TLN_DefineInputButton( (TLN_Player )  (int) RING_API_GETNUMBER(1), (TLN_Input )  (int) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_TLN_DrawFrame)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_DrawFrame( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_TLN_WaitRedraw)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_WaitRedraw();
}


RING_FUNC(ring_TLN_DeleteWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_DeleteWindow();
}


RING_FUNC(ring_TLN_EnableBlur)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_EnableBlur( (bool ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_TLN_EnableCRTEffect)
{
	if ( RING_API_PARACOUNT != 9 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_EnableCRTEffect( (TLN_Overlay )  (int) RING_API_GETNUMBER(1), (uint8_t ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3), (uint8_t ) RING_API_GETNUMBER(4), (uint8_t ) RING_API_GETNUMBER(5), (uint8_t ) RING_API_GETNUMBER(6), (uint8_t ) RING_API_GETNUMBER(7), (bool ) RING_API_GETNUMBER(8), (uint8_t ) RING_API_GETNUMBER(9));
}


RING_FUNC(ring_TLN_DisableCRTEffect)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_DisableCRTEffect();
}


RING_FUNC(ring_TLN_SetSDLCallback)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	TLN_SetSDLCallback(* (TLN_SDLCallback *) RING_API_GETCPOINTER(1,"TLN_SDLCallback"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_SDLCallback"));
}


RING_FUNC(ring_TLN_Delay)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_Delay( (uint32_t ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_TLN_GetTicks)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetTicks());
}


RING_FUNC(ring_TLN_GetWindowWidth)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetWindowWidth());
}


RING_FUNC(ring_TLN_GetWindowHeight)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetWindowHeight());
}


RING_FUNC(ring_TLN_CreateSpriteset)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Spriteset *pValue ; 
		pValue = (TLN_Spriteset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Spriteset)) ;
		*pValue = TLN_CreateSpriteset(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap"),(TLN_SpriteData *) RING_API_GETCPOINTER(2,"TLN_SpriteData"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Spriteset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_LoadSpriteset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Spriteset *pValue ; 
		pValue = (TLN_Spriteset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Spriteset)) ;
		*pValue = TLN_LoadSpriteset(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Spriteset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CloneSpriteset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Spriteset *pValue ; 
		pValue = (TLN_Spriteset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Spriteset)) ;
		*pValue = TLN_CloneSpriteset(* (TLN_Spriteset  *) RING_API_GETCPOINTER(1,"TLN_Spriteset"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Spriteset"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Spriteset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetSpriteInfo)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetSpriteInfo(* (TLN_Spriteset  *) RING_API_GETCPOINTER(1,"TLN_Spriteset"), (int ) RING_API_GETNUMBER(2),(TLN_SpriteInfo *) RING_API_GETCPOINTER(3,"TLN_SpriteInfo")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Spriteset"));
}


RING_FUNC(ring_TLN_GetSpritesetPalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_GetSpritesetPalette(* (TLN_Spriteset  *) RING_API_GETCPOINTER(1,"TLN_Spriteset"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Spriteset"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_FindSpritesetSprite)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_FindSpritesetSprite(* (TLN_Spriteset  *) RING_API_GETCPOINTER(1,"TLN_Spriteset"),RING_API_GETSTRING(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Spriteset"));
}


RING_FUNC(ring_TLN_SetSpritesetData)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetSpritesetData(* (TLN_Spriteset  *) RING_API_GETCPOINTER(1,"TLN_Spriteset"), (int ) RING_API_GETNUMBER(2),(TLN_SpriteData *) RING_API_GETCPOINTER(3,"TLN_SpriteData"),(void *) RING_API_GETCPOINTER(4,"void"), (int ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Spriteset"));
}


RING_FUNC(ring_TLN_DeleteSpriteset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteSpriteset(* (TLN_Spriteset  *) RING_API_GETCPOINTER(1,"TLN_Spriteset")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Spriteset"));
}


RING_FUNC(ring_TLN_CreateTileset)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Tileset *pValue ; 
		pValue = (TLN_Tileset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tileset)) ;
		*pValue = TLN_CreateTileset( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (TLN_Palette  *) RING_API_GETCPOINTER(4,"TLN_Palette"),* (TLN_SequencePack  *) RING_API_GETCPOINTER(5,"TLN_SequencePack"),(TLN_TileAttributes *) RING_API_GETCPOINTER(6,"TLN_TileAttributes"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"TLN_Palette"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"TLN_SequencePack"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tileset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CreateImageTileset)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Tileset *pValue ; 
		pValue = (TLN_Tileset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tileset)) ;
		*pValue = TLN_CreateImageTileset( (int ) RING_API_GETNUMBER(1),(TLN_TileImage *) RING_API_GETCPOINTER(2,"TLN_TileImage"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tileset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_LoadTileset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Tileset *pValue ; 
		pValue = (TLN_Tileset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tileset)) ;
		*pValue = TLN_LoadTileset(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tileset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CloneTileset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Tileset *pValue ; 
		pValue = (TLN_Tileset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tileset)) ;
		*pValue = TLN_CloneTileset(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tileset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_SetTilesetPixels)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetTilesetPixels(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset"), (int ) RING_API_GETNUMBER(2),(uint8_t *) RING_API_GETCPOINTER(3,"uint8_t"), (int ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
}


RING_FUNC(ring_TLN_GetTileWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetTileWidth(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
}


RING_FUNC(ring_TLN_GetTileHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetTileHeight(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
}


RING_FUNC(ring_TLN_GetTilesetNumTiles)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetTilesetNumTiles(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
}


RING_FUNC(ring_TLN_GetTilesetPalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_GetTilesetPalette(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetTilesetSequencePack)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_SequencePack *pValue ; 
		pValue = (TLN_SequencePack *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SequencePack)) ;
		*pValue = TLN_GetTilesetSequencePack(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_SequencePack",ring_state_free);
	}
}


RING_FUNC(ring_TLN_DeleteTileset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteTileset(* (TLN_Tileset  *) RING_API_GETCPOINTER(1,"TLN_Tileset")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tileset"));
}


RING_FUNC(ring_TLN_CreateTilemap)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Tilemap *pValue ; 
		pValue = (TLN_Tilemap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tilemap)) ;
		*pValue = TLN_CreateTilemap( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (TLN_Tile  *) RING_API_GETCPOINTER(3,"TLN_Tile"), (uint32_t ) RING_API_GETNUMBER(4),* (TLN_Tileset  *) RING_API_GETCPOINTER(5,"TLN_Tileset"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"TLN_Tile"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"TLN_Tileset"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tilemap",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CloneTilemap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Tilemap *pValue ; 
		pValue = (TLN_Tilemap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tilemap)) ;
		*pValue = TLN_CloneTilemap(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tilemap",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetTilemapRows)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetTilemapRows(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
}


RING_FUNC(ring_TLN_GetTilemapCols)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetTilemapCols(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
}


RING_FUNC(ring_TLN_GetTilemapTileset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Tileset *pValue ; 
		pValue = (TLN_Tileset *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tileset)) ;
		*pValue = TLN_GetTilemapTileset(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tileset",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetTilemapTile)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetTilemapTile(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (TLN_Tile  *) RING_API_GETCPOINTER(4,"TLN_Tile")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"TLN_Tile"));
}


RING_FUNC(ring_TLN_SetTilemapTile)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetTilemapTile(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (TLN_Tile  *) RING_API_GETCPOINTER(4,"TLN_Tile")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"TLN_Tile"));
}


RING_FUNC(ring_TLN_CopyTiles)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_CopyTiles(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (TLN_Tilemap  *) RING_API_GETCPOINTER(6,"TLN_Tilemap"), (int ) RING_API_GETNUMBER(7), (int ) RING_API_GETNUMBER(8)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"TLN_Tilemap"));
}


RING_FUNC(ring_TLN_DeleteTilemap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteTilemap(* (TLN_Tilemap  *) RING_API_GETCPOINTER(1,"TLN_Tilemap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Tilemap"));
}

RING_FUNC(ring_TLN_LoadTilemap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Tilemap *pValue ;
		pValue = (TLN_Tilemap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Tilemap)) ;
		if ( strcmp(RING_API_GETSTRING(2),"") == 0 )
			*pValue = TLN_LoadTilemap(RING_API_GETSTRING(1),NULL);
		else
			*pValue = TLN_LoadTilemap(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Tilemap",ring_state_free);
	}
}

RING_FUNC(ring_TLN_CreatePalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_CreatePalette( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_LoadPalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_LoadPalette(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_ClonePalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_ClonePalette(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_SetPaletteColor)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetPaletteColor(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette"), (int ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3), (uint8_t ) RING_API_GETNUMBER(4), (uint8_t ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
}


RING_FUNC(ring_TLN_MixPalettes)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_MixPalettes(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette"),* (TLN_Palette  *) RING_API_GETCPOINTER(2,"TLN_Palette"),* (TLN_Palette  *) RING_API_GETCPOINTER(3,"TLN_Palette"), (uint8_t ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Palette"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"TLN_Palette"));
}


RING_FUNC(ring_TLN_AddPaletteColor)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_AddPaletteColor(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette"), (uint8_t ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3), (uint8_t ) RING_API_GETNUMBER(4), (uint8_t ) RING_API_GETNUMBER(5), (uint8_t ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
}


RING_FUNC(ring_TLN_SubPaletteColor)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SubPaletteColor(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette"), (uint8_t ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3), (uint8_t ) RING_API_GETNUMBER(4), (uint8_t ) RING_API_GETNUMBER(5), (uint8_t ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
}


RING_FUNC(ring_TLN_ModPaletteColor)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_ModPaletteColor(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette"), (uint8_t ) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3), (uint8_t ) RING_API_GETNUMBER(4), (uint8_t ) RING_API_GETNUMBER(5), (uint8_t ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
}


RING_FUNC(ring_TLN_GetPaletteData)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(TLN_GetPaletteData(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette"), (int ) RING_API_GETNUMBER(2)),"uint8_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
}


RING_FUNC(ring_TLN_DeletePalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeletePalette(* (TLN_Palette  *) RING_API_GETCPOINTER(1,"TLN_Palette")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Palette"));
}


RING_FUNC(ring_TLN_CreateBitmap)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	{
		TLN_Bitmap *pValue ; 
		pValue = (TLN_Bitmap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Bitmap)) ;
		*pValue = TLN_CreateBitmap( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Bitmap",ring_state_free);
	}
}


RING_FUNC(ring_TLN_LoadBitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Bitmap *pValue ; 
		pValue = (TLN_Bitmap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Bitmap)) ;
		*pValue = TLN_LoadBitmap(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Bitmap",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CloneBitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Bitmap *pValue ; 
		pValue = (TLN_Bitmap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Bitmap)) ;
		*pValue = TLN_CloneBitmap(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Bitmap",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetBitmapPtr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(TLN_GetBitmapPtr(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"uint8_t");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_GetBitmapWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetBitmapWidth(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_GetBitmapHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetBitmapHeight(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_GetBitmapDepth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetBitmapDepth(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_GetBitmapPitch)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetBitmapPitch(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_GetBitmapPalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_GetBitmapPalette(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_SetBitmapPalette)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_SetBitmapPalette(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap"),* (TLN_Palette  *) RING_API_GETCPOINTER(2,"TLN_Palette")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Palette"));
}


RING_FUNC(ring_TLN_DeleteBitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteBitmap(* (TLN_Bitmap  *) RING_API_GETCPOINTER(1,"TLN_Bitmap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_CreateObjectList)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_ObjectList *pValue ; 
		pValue = (TLN_ObjectList *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_ObjectList)) ;
		*pValue = TLN_CreateObjectList();
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_ObjectList",ring_state_free);
	}
}


RING_FUNC(ring_TLN_AddTileObjectToList)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_AddTileObjectToList(* (TLN_ObjectList  *) RING_API_GETCPOINTER(1,"TLN_ObjectList"), (uint16_t ) RING_API_GETNUMBER(2), (uint16_t ) RING_API_GETNUMBER(3), (uint16_t ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_ObjectList"));
}


RING_FUNC(ring_TLN_CloneObjectList)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_ObjectList *pValue ; 
		pValue = (TLN_ObjectList *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_ObjectList)) ;
		*pValue = TLN_CloneObjectList(* (TLN_ObjectList  *) RING_API_GETCPOINTER(1,"TLN_ObjectList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_ObjectList"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_ObjectList",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetListNumObjects)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetListNumObjects(* (TLN_ObjectList  *) RING_API_GETCPOINTER(1,"TLN_ObjectList")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_ObjectList"));
}


RING_FUNC(ring_TLN_GetListObject)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetListObject(* (TLN_ObjectList  *) RING_API_GETCPOINTER(1,"TLN_ObjectList"),(TLN_ObjectInfo *) RING_API_GETCPOINTER(2,"TLN_ObjectInfo")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_ObjectList"));
}


RING_FUNC(ring_TLN_DeleteObjectList)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteObjectList(* (TLN_ObjectList  *) RING_API_GETCPOINTER(1,"TLN_ObjectList")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_ObjectList"));
}

RING_FUNC(ring_TLN_LoadObjectList)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_ObjectList *pValue ;
		pValue = (TLN_ObjectList *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_ObjectList)) ;
		if (strcmp(RING_API_GETSTRING(2),"")==0)
			*pValue = TLN_LoadObjectList(RING_API_GETSTRING(1),NULL);
		else
			*pValue = TLN_LoadObjectList(RING_API_GETSTRING(1),RING_API_GETSTRING(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_ObjectList",ring_state_free);
	}
}

RING_FUNC(ring_TLN_SetLayerTilemap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerTilemap( (int ) RING_API_GETNUMBER(1),* (TLN_Tilemap  *) RING_API_GETCPOINTER(2,"TLN_Tilemap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Tilemap"));
}


RING_FUNC(ring_TLN_SetLayerBitmap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerBitmap( (int ) RING_API_GETNUMBER(1),* (TLN_Bitmap  *) RING_API_GETCPOINTER(2,"TLN_Bitmap")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Bitmap"));
}


RING_FUNC(ring_TLN_SetLayerPalette)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerPalette( (int ) RING_API_GETNUMBER(1),* (TLN_Palette  *) RING_API_GETCPOINTER(2,"TLN_Palette")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Palette"));
}


RING_FUNC(ring_TLN_SetLayerPosition)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetLayerPosition( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_SetLayerScaling)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetLayerScaling( (int ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_SetLayerAffineTransform)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerAffineTransform( (int ) RING_API_GETNUMBER(1),(TLN_Affine *) RING_API_GETCPOINTER(2,"TLN_Affine")));
}


RING_FUNC(ring_TLN_SetLayerTransform)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerTransform( (int ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6)));
}


RING_FUNC(ring_TLN_SetLayerPixelMapping)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerPixelMapping( (int ) RING_API_GETNUMBER(1),(TLN_PixelMap *) RING_API_GETCPOINTER(2,"TLN_PixelMap")));
}


RING_FUNC(ring_TLN_SetLayerBlendMode)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetLayerBlendMode( (int ) RING_API_GETNUMBER(1), (TLN_Blend )  (int) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_SetLayerColumnOffset)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerColumnOffset( (int ) RING_API_GETNUMBER(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_TLN_SetLayerClip)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetLayerClip( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_TLN_DisableLayerClip)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_DisableLayerClip( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_SetLayerMosaic)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetLayerMosaic( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_DisableLayerMosaic)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_DisableLayerMosaic( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_ResetLayerMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_ResetLayerMode( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_SetLayerPriority)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerPriority( (int ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_SetLayerParent)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetLayerParent( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_DisableLayerParent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_DisableLayerParent( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_DisableLayer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_DisableLayer( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_GetLayerPalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_GetLayerPalette( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetLayerTile)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetLayerTile( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),(TLN_TileInfo *) RING_API_GETCPOINTER(4,"TLN_TileInfo")));
}


RING_FUNC(ring_TLN_GetLayerWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetLayerWidth( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_GetLayerHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetLayerHeight( (int ) RING_API_GETNUMBER(1)));
}

RING_FUNC(ring_TLN_SetLayer)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

	if (RING_API_GETCPOINTER(2,"TLN_Tileset") == NULL) {
		RING_API_RETNUMBER(TLN_SetLayer( (int ) RING_API_GETNUMBER(1),NULL,* (TLN_Tilemap  *) RING_API_GETCPOINTER(3,"TLN_Tilemap")));
	} else {
		RING_API_RETNUMBER(TLN_SetLayer( (int ) RING_API_GETNUMBER(1),* (TLN_Tileset  *) RING_API_GETCPOINTER(2,"TLN_Tileset"),* (TLN_Tilemap  *) RING_API_GETCPOINTER(3,"TLN_Tilemap")));
	}
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Tileset"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"TLN_Tilemap"));

}

RING_FUNC(ring_TLN_SetLayerObjects)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( RING_API_GETCPOINTER(3,"TLN_Tileset") == NULL ) {
		RING_API_RETNUMBER(TLN_SetLayerObjects( (int ) RING_API_GETNUMBER(1),* (TLN_ObjectList  *) RING_API_GETCPOINTER(2,"TLN_ObjectList"), NULL ));
	} else {
		RING_API_RETNUMBER(TLN_SetLayerObjects( (int ) RING_API_GETNUMBER(1),* (TLN_ObjectList  *) RING_API_GETCPOINTER(2,"TLN_ObjectList"),* (TLN_Tileset  *) RING_API_GETCPOINTER(3,"TLN_Tileset")));
	}
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_ObjectList"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"TLN_Tileset"));
}


RING_FUNC(ring_TLN_ConfigSprite)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_ConfigSprite( (int ) RING_API_GETNUMBER(1),* (TLN_Spriteset  *) RING_API_GETCPOINTER(2,"TLN_Spriteset"), (uint32_t ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Spriteset"));
}


RING_FUNC(ring_TLN_SetSpriteSet)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetSpriteSet( (int ) RING_API_GETNUMBER(1),* (TLN_Spriteset  *) RING_API_GETCPOINTER(2,"TLN_Spriteset")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Spriteset"));
}


RING_FUNC(ring_TLN_SetSpriteFlags)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetSpriteFlags( (int ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_EnableSpriteFlag)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_EnableSpriteFlag( (int ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_SetSpritePosition)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetSpritePosition( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_SetSpritePicture)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetSpritePicture( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_SetSpritePalette)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetSpritePalette( (int ) RING_API_GETNUMBER(1),* (TLN_Palette  *) RING_API_GETCPOINTER(2,"TLN_Palette")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Palette"));
}


RING_FUNC(ring_TLN_SetSpriteBlendMode)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetSpriteBlendMode( (int ) RING_API_GETNUMBER(1), (TLN_Blend )  (int) RING_API_GETNUMBER(2), (uint8_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_SetSpriteScaling)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetSpriteScaling( (int ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_ResetSpriteScaling)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_ResetSpriteScaling( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_GetSpritePicture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetSpritePicture( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_GetAvailableSprite)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetAvailableSprite());
}


RING_FUNC(ring_TLN_EnableSpriteCollision)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_EnableSpriteCollision( (int ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_GetSpriteCollision)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetSpriteCollision( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_GetSpriteState)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetSpriteState( (int ) RING_API_GETNUMBER(1),(TLN_SpriteState *) RING_API_GETCPOINTER(2,"TLN_SpriteState")));
}


RING_FUNC(ring_TLN_SetFirstSprite)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetFirstSprite( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_SetNextSprite)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetNextSprite( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_EnableSpriteMasking)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_EnableSpriteMasking( (int ) RING_API_GETNUMBER(1), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TLN_SetSpritesMaskRegion)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TLN_SetSpritesMaskRegion( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TLN_SetSpriteAnimation)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetSpriteAnimation( (int ) RING_API_GETNUMBER(1),* (TLN_Sequence  *) RING_API_GETCPOINTER(2,"TLN_Sequence"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Sequence"));
}


RING_FUNC(ring_TLN_DisableSpriteAnimation)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_DisableSpriteAnimation( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_DisableSprite)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_DisableSprite( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_GetSpritePalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Palette *pValue ; 
		pValue = (TLN_Palette *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Palette)) ;
		*pValue = TLN_GetSpritePalette( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Palette",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CreateSequence)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Sequence *pValue ; 
		pValue = (TLN_Sequence *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Sequence)) ;
		*pValue = TLN_CreateSequence(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),(TLN_SequenceFrame *) RING_API_GETCPOINTER(4,"TLN_SequenceFrame"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Sequence",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CreateCycle)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Sequence *pValue ; 
		pValue = (TLN_Sequence *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Sequence)) ;
		*pValue = TLN_CreateCycle(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),(TLN_ColorStrip *) RING_API_GETCPOINTER(3,"TLN_ColorStrip"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Sequence",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CreateSpriteSequence)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Sequence *pValue ; 
		pValue = (TLN_Sequence *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Sequence)) ;
		*pValue = TLN_CreateSpriteSequence(RING_API_GETSTRING(1),* (TLN_Spriteset  *) RING_API_GETCPOINTER(2,"TLN_Spriteset"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Spriteset"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Sequence",ring_state_free);
	}
}


RING_FUNC(ring_TLN_CloneSequence)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_Sequence *pValue ; 
		pValue = (TLN_Sequence *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Sequence)) ;
		*pValue = TLN_CloneSequence(* (TLN_Sequence  *) RING_API_GETCPOINTER(1,"TLN_Sequence"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Sequence"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Sequence",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetSequenceInfo)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetSequenceInfo(* (TLN_Sequence  *) RING_API_GETCPOINTER(1,"TLN_Sequence"),(TLN_SequenceInfo *) RING_API_GETCPOINTER(2,"TLN_SequenceInfo")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Sequence"));
}


RING_FUNC(ring_TLN_DeleteSequence)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteSequence(* (TLN_Sequence  *) RING_API_GETCPOINTER(1,"TLN_Sequence")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_Sequence"));
}


RING_FUNC(ring_TLN_CreateSequencePack)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	{
		TLN_SequencePack *pValue ; 
		pValue = (TLN_SequencePack *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SequencePack)) ;
		*pValue = TLN_CreateSequencePack();
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_SequencePack",ring_state_free);
	}
}


RING_FUNC(ring_TLN_LoadSequencePack)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_SequencePack *pValue ; 
		pValue = (TLN_SequencePack *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_SequencePack)) ;
		*pValue = TLN_LoadSequencePack(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_SequencePack",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetSequence)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Sequence *pValue ; 
		pValue = (TLN_Sequence *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Sequence)) ;
		*pValue = TLN_GetSequence(* (TLN_SequencePack  *) RING_API_GETCPOINTER(1,"TLN_SequencePack"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_SequencePack"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Sequence",ring_state_free);
	}
}


RING_FUNC(ring_TLN_FindSequence)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TLN_Sequence *pValue ; 
		pValue = (TLN_Sequence *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TLN_Sequence)) ;
		*pValue = TLN_FindSequence(* (TLN_SequencePack  *) RING_API_GETCPOINTER(1,"TLN_SequencePack"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_SequencePack"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TLN_Sequence",ring_state_free);
	}
}


RING_FUNC(ring_TLN_GetSequencePackCount)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetSequencePackCount(* (TLN_SequencePack  *) RING_API_GETCPOINTER(1,"TLN_SequencePack")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_SequencePack"));
}


RING_FUNC(ring_TLN_AddSequenceToPack)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_AddSequenceToPack(* (TLN_SequencePack  *) RING_API_GETCPOINTER(1,"TLN_SequencePack"),* (TLN_Sequence  *) RING_API_GETCPOINTER(2,"TLN_Sequence")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_SequencePack"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Sequence"));
}


RING_FUNC(ring_TLN_DeleteSequencePack)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_DeleteSequencePack(* (TLN_SequencePack  *) RING_API_GETCPOINTER(1,"TLN_SequencePack")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TLN_SequencePack"));
}


RING_FUNC(ring_TLN_SetPaletteAnimation)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetPaletteAnimation( (int ) RING_API_GETNUMBER(1),* (TLN_Palette  *) RING_API_GETCPOINTER(2,"TLN_Palette"),* (TLN_Sequence  *) RING_API_GETCPOINTER(3,"TLN_Sequence"), (bool ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Palette"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"TLN_Sequence"));
}


RING_FUNC(ring_TLN_SetPaletteAnimationSource)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_SetPaletteAnimationSource( (int ) RING_API_GETNUMBER(1),* (TLN_Palette *) RING_API_GETCPOINTER(2,"TLN_Palette")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"TLN_Palette"));
}


RING_FUNC(ring_TLN_GetAnimationState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_GetAnimationState( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_TLN_SetAnimationDelay)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETNUMBER(TLN_SetAnimationDelay( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_TLN_GetAvailableAnimation)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETNUMBER(TLN_GetAvailableAnimation());
}


RING_FUNC(ring_TLN_DisablePaletteAnimation)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TLN_DisablePaletteAnimation( (int ) RING_API_GETNUMBER(1)));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("tln_init",ring_TLN_Init);
	ring_vm_funcregister("tln_deinit",ring_TLN_Deinit);
	ring_vm_funcregister("tln_deletecontext",ring_TLN_DeleteContext);
	ring_vm_funcregister("tln_setcontext",ring_TLN_SetContext);
	ring_vm_funcregister("tln_getcontext",ring_TLN_GetContext);
	ring_vm_funcregister("tln_getwidth",ring_TLN_GetWidth);
	ring_vm_funcregister("tln_getheight",ring_TLN_GetHeight);
	ring_vm_funcregister("tln_getnumobjects",ring_TLN_GetNumObjects);
	ring_vm_funcregister("tln_getusedmemory",ring_TLN_GetUsedMemory);
	ring_vm_funcregister("tln_getversion",ring_TLN_GetVersion);
	ring_vm_funcregister("tln_getnumlayers",ring_TLN_GetNumLayers);
	ring_vm_funcregister("tln_getnumsprites",ring_TLN_GetNumSprites);
	ring_vm_funcregister("tln_setbgcolor",ring_TLN_SetBGColor);
	ring_vm_funcregister("tln_setbgcolorfromtilemap",ring_TLN_SetBGColorFromTilemap);
	ring_vm_funcregister("tln_disablebgcolor",ring_TLN_DisableBGColor);
	ring_vm_funcregister("tln_setbgbitmap",ring_TLN_SetBGBitmap);
	ring_vm_funcregister("tln_setbgpalette",ring_TLN_SetBGPalette);
	ring_vm_funcregister("tln_setrastercallback",ring_TLN_SetRasterCallback);
	ring_vm_funcregister("tln_setframecallback",ring_TLN_SetFrameCallback);
	ring_vm_funcregister("tln_setrendertarget",ring_TLN_SetRenderTarget);
	ring_vm_funcregister("tln_updateframe",ring_TLN_UpdateFrame);
	ring_vm_funcregister("tln_setloadpath",ring_TLN_SetLoadPath);
	ring_vm_funcregister("tln_setcustomblendfunction",ring_TLN_SetCustomBlendFunction);
	ring_vm_funcregister("tln_setloglevel",ring_TLN_SetLogLevel);
	ring_vm_funcregister("tln_openresourcepack",ring_TLN_OpenResourcePack);
	ring_vm_funcregister("tln_closeresourcepack",ring_TLN_CloseResourcePack);
	ring_vm_funcregister("tln_setlasterror",ring_TLN_SetLastError);
	ring_vm_funcregister("tln_getlasterror",ring_TLN_GetLastError);
	ring_vm_funcregister("tln_geterrorstring",ring_TLN_GetErrorString);
	ring_vm_funcregister("tln_createwindow",ring_TLN_CreateWindow);
	ring_vm_funcregister("tln_createwindowthread",ring_TLN_CreateWindowThread);
	ring_vm_funcregister("tln_setwindowtitle",ring_TLN_SetWindowTitle);
	ring_vm_funcregister("tln_processwindow",ring_TLN_ProcessWindow);
	ring_vm_funcregister("tln_iswindowactive",ring_TLN_IsWindowActive);
	ring_vm_funcregister("tln_getinput",ring_TLN_GetInput);
	ring_vm_funcregister("tln_enableinput",ring_TLN_EnableInput);
	ring_vm_funcregister("tln_assigninputjoystick",ring_TLN_AssignInputJoystick);
	ring_vm_funcregister("tln_defineinputkey",ring_TLN_DefineInputKey);
	ring_vm_funcregister("tln_defineinputbutton",ring_TLN_DefineInputButton);
	ring_vm_funcregister("tln_drawframe",ring_TLN_DrawFrame);
	ring_vm_funcregister("tln_waitredraw",ring_TLN_WaitRedraw);
	ring_vm_funcregister("tln_deletewindow",ring_TLN_DeleteWindow);
	ring_vm_funcregister("tln_enableblur",ring_TLN_EnableBlur);
	ring_vm_funcregister("tln_enablecrteffect",ring_TLN_EnableCRTEffect);
	ring_vm_funcregister("tln_disablecrteffect",ring_TLN_DisableCRTEffect);
	ring_vm_funcregister("tln_setsdlcallback",ring_TLN_SetSDLCallback);
	ring_vm_funcregister("tln_delay",ring_TLN_Delay);
	ring_vm_funcregister("tln_getticks",ring_TLN_GetTicks);
	ring_vm_funcregister("tln_getwindowwidth",ring_TLN_GetWindowWidth);
	ring_vm_funcregister("tln_getwindowheight",ring_TLN_GetWindowHeight);
	ring_vm_funcregister("tln_createspriteset",ring_TLN_CreateSpriteset);
	ring_vm_funcregister("tln_loadspriteset",ring_TLN_LoadSpriteset);
	ring_vm_funcregister("tln_clonespriteset",ring_TLN_CloneSpriteset);
	ring_vm_funcregister("tln_getspriteinfo",ring_TLN_GetSpriteInfo);
	ring_vm_funcregister("tln_getspritesetpalette",ring_TLN_GetSpritesetPalette);
	ring_vm_funcregister("tln_findspritesetsprite",ring_TLN_FindSpritesetSprite);
	ring_vm_funcregister("tln_setspritesetdata",ring_TLN_SetSpritesetData);
	ring_vm_funcregister("tln_deletespriteset",ring_TLN_DeleteSpriteset);
	ring_vm_funcregister("tln_createtileset",ring_TLN_CreateTileset);
	ring_vm_funcregister("tln_createimagetileset",ring_TLN_CreateImageTileset);
	ring_vm_funcregister("tln_loadtileset",ring_TLN_LoadTileset);
	ring_vm_funcregister("tln_clonetileset",ring_TLN_CloneTileset);
	ring_vm_funcregister("tln_settilesetpixels",ring_TLN_SetTilesetPixels);
	ring_vm_funcregister("tln_gettilewidth",ring_TLN_GetTileWidth);
	ring_vm_funcregister("tln_gettileheight",ring_TLN_GetTileHeight);
	ring_vm_funcregister("tln_gettilesetnumtiles",ring_TLN_GetTilesetNumTiles);
	ring_vm_funcregister("tln_gettilesetpalette",ring_TLN_GetTilesetPalette);
	ring_vm_funcregister("tln_gettilesetsequencepack",ring_TLN_GetTilesetSequencePack);
	ring_vm_funcregister("tln_deletetileset",ring_TLN_DeleteTileset);
	ring_vm_funcregister("tln_createtilemap",ring_TLN_CreateTilemap);
	ring_vm_funcregister("tln_loadtilemap",ring_TLN_LoadTilemap);
	ring_vm_funcregister("tln_clonetilemap",ring_TLN_CloneTilemap);
	ring_vm_funcregister("tln_gettilemaprows",ring_TLN_GetTilemapRows);
	ring_vm_funcregister("tln_gettilemapcols",ring_TLN_GetTilemapCols);
	ring_vm_funcregister("tln_gettilemaptileset",ring_TLN_GetTilemapTileset);
	ring_vm_funcregister("tln_gettilemaptile",ring_TLN_GetTilemapTile);
	ring_vm_funcregister("tln_settilemaptile",ring_TLN_SetTilemapTile);
	ring_vm_funcregister("tln_copytiles",ring_TLN_CopyTiles);
	ring_vm_funcregister("tln_deletetilemap",ring_TLN_DeleteTilemap);
	ring_vm_funcregister("tln_createpalette",ring_TLN_CreatePalette);
	ring_vm_funcregister("tln_loadpalette",ring_TLN_LoadPalette);
	ring_vm_funcregister("tln_clonepalette",ring_TLN_ClonePalette);
	ring_vm_funcregister("tln_setpalettecolor",ring_TLN_SetPaletteColor);
	ring_vm_funcregister("tln_mixpalettes",ring_TLN_MixPalettes);
	ring_vm_funcregister("tln_addpalettecolor",ring_TLN_AddPaletteColor);
	ring_vm_funcregister("tln_subpalettecolor",ring_TLN_SubPaletteColor);
	ring_vm_funcregister("tln_modpalettecolor",ring_TLN_ModPaletteColor);
	ring_vm_funcregister("tln_getpalettedata",ring_TLN_GetPaletteData);
	ring_vm_funcregister("tln_deletepalette",ring_TLN_DeletePalette);
	ring_vm_funcregister("tln_createbitmap",ring_TLN_CreateBitmap);
	ring_vm_funcregister("tln_loadbitmap",ring_TLN_LoadBitmap);
	ring_vm_funcregister("tln_clonebitmap",ring_TLN_CloneBitmap);
	ring_vm_funcregister("tln_getbitmapptr",ring_TLN_GetBitmapPtr);
	ring_vm_funcregister("tln_getbitmapwidth",ring_TLN_GetBitmapWidth);
	ring_vm_funcregister("tln_getbitmapheight",ring_TLN_GetBitmapHeight);
	ring_vm_funcregister("tln_getbitmapdepth",ring_TLN_GetBitmapDepth);
	ring_vm_funcregister("tln_getbitmappitch",ring_TLN_GetBitmapPitch);
	ring_vm_funcregister("tln_getbitmappalette",ring_TLN_GetBitmapPalette);
	ring_vm_funcregister("tln_setbitmappalette",ring_TLN_SetBitmapPalette);
	ring_vm_funcregister("tln_deletebitmap",ring_TLN_DeleteBitmap);
	ring_vm_funcregister("tln_createobjectlist",ring_TLN_CreateObjectList);
	ring_vm_funcregister("tln_addtileobjecttolist",ring_TLN_AddTileObjectToList);
	ring_vm_funcregister("tln_loadobjectlist",ring_TLN_LoadObjectList);
	ring_vm_funcregister("tln_cloneobjectlist",ring_TLN_CloneObjectList);
	ring_vm_funcregister("tln_getlistnumobjects",ring_TLN_GetListNumObjects);
	ring_vm_funcregister("tln_getlistobject",ring_TLN_GetListObject);
	ring_vm_funcregister("tln_deleteobjectlist",ring_TLN_DeleteObjectList);
	ring_vm_funcregister("tln_setlayer",ring_TLN_SetLayer);
	ring_vm_funcregister("tln_setlayertilemap",ring_TLN_SetLayerTilemap);
	ring_vm_funcregister("tln_setlayerbitmap",ring_TLN_SetLayerBitmap);
	ring_vm_funcregister("tln_setlayerpalette",ring_TLN_SetLayerPalette);
	ring_vm_funcregister("tln_setlayerposition",ring_TLN_SetLayerPosition);
	ring_vm_funcregister("tln_setlayerscaling",ring_TLN_SetLayerScaling);
	ring_vm_funcregister("tln_setlayeraffinetransform",ring_TLN_SetLayerAffineTransform);
	ring_vm_funcregister("tln_setlayertransform",ring_TLN_SetLayerTransform);
	ring_vm_funcregister("tln_setlayerpixelmapping",ring_TLN_SetLayerPixelMapping);
	ring_vm_funcregister("tln_setlayerblendmode",ring_TLN_SetLayerBlendMode);
	ring_vm_funcregister("tln_setlayercolumnoffset",ring_TLN_SetLayerColumnOffset);
	ring_vm_funcregister("tln_setlayerclip",ring_TLN_SetLayerClip);
	ring_vm_funcregister("tln_disablelayerclip",ring_TLN_DisableLayerClip);
	ring_vm_funcregister("tln_setlayermosaic",ring_TLN_SetLayerMosaic);
	ring_vm_funcregister("tln_disablelayermosaic",ring_TLN_DisableLayerMosaic);
	ring_vm_funcregister("tln_resetlayermode",ring_TLN_ResetLayerMode);
	ring_vm_funcregister("tln_setlayerobjects",ring_TLN_SetLayerObjects);
	ring_vm_funcregister("tln_setlayerpriority",ring_TLN_SetLayerPriority);
	ring_vm_funcregister("tln_setlayerparent",ring_TLN_SetLayerParent);
	ring_vm_funcregister("tln_disablelayerparent",ring_TLN_DisableLayerParent);
	ring_vm_funcregister("tln_disablelayer",ring_TLN_DisableLayer);
	ring_vm_funcregister("tln_getlayerpalette",ring_TLN_GetLayerPalette);
	ring_vm_funcregister("tln_getlayertile",ring_TLN_GetLayerTile);
	ring_vm_funcregister("tln_getlayerwidth",ring_TLN_GetLayerWidth);
	ring_vm_funcregister("tln_getlayerheight",ring_TLN_GetLayerHeight);
	ring_vm_funcregister("tln_configsprite",ring_TLN_ConfigSprite);
	ring_vm_funcregister("tln_setspriteset",ring_TLN_SetSpriteSet);
	ring_vm_funcregister("tln_setspriteflags",ring_TLN_SetSpriteFlags);
	ring_vm_funcregister("tln_enablespriteflag",ring_TLN_EnableSpriteFlag);
	ring_vm_funcregister("tln_setspriteposition",ring_TLN_SetSpritePosition);
	ring_vm_funcregister("tln_setspritepicture",ring_TLN_SetSpritePicture);
	ring_vm_funcregister("tln_setspritepalette",ring_TLN_SetSpritePalette);
	ring_vm_funcregister("tln_setspriteblendmode",ring_TLN_SetSpriteBlendMode);
	ring_vm_funcregister("tln_setspritescaling",ring_TLN_SetSpriteScaling);
	ring_vm_funcregister("tln_resetspritescaling",ring_TLN_ResetSpriteScaling);
	ring_vm_funcregister("tln_getspritepicture",ring_TLN_GetSpritePicture);
	ring_vm_funcregister("tln_getavailablesprite",ring_TLN_GetAvailableSprite);
	ring_vm_funcregister("tln_enablespritecollision",ring_TLN_EnableSpriteCollision);
	ring_vm_funcregister("tln_getspritecollision",ring_TLN_GetSpriteCollision);
	ring_vm_funcregister("tln_getspritestate",ring_TLN_GetSpriteState);
	ring_vm_funcregister("tln_setfirstsprite",ring_TLN_SetFirstSprite);
	ring_vm_funcregister("tln_setnextsprite",ring_TLN_SetNextSprite);
	ring_vm_funcregister("tln_enablespritemasking",ring_TLN_EnableSpriteMasking);
	ring_vm_funcregister("tln_setspritesmaskregion",ring_TLN_SetSpritesMaskRegion);
	ring_vm_funcregister("tln_setspriteanimation",ring_TLN_SetSpriteAnimation);
	ring_vm_funcregister("tln_disablespriteanimation",ring_TLN_DisableSpriteAnimation);
	ring_vm_funcregister("tln_disablesprite",ring_TLN_DisableSprite);
	ring_vm_funcregister("tln_getspritepalette",ring_TLN_GetSpritePalette);
	ring_vm_funcregister("tln_createsequence",ring_TLN_CreateSequence);
	ring_vm_funcregister("tln_createcycle",ring_TLN_CreateCycle);
	ring_vm_funcregister("tln_createspritesequence",ring_TLN_CreateSpriteSequence);
	ring_vm_funcregister("tln_clonesequence",ring_TLN_CloneSequence);
	ring_vm_funcregister("tln_getsequenceinfo",ring_TLN_GetSequenceInfo);
	ring_vm_funcregister("tln_deletesequence",ring_TLN_DeleteSequence);
	ring_vm_funcregister("tln_createsequencepack",ring_TLN_CreateSequencePack);
	ring_vm_funcregister("tln_loadsequencepack",ring_TLN_LoadSequencePack);
	ring_vm_funcregister("tln_getsequence",ring_TLN_GetSequence);
	ring_vm_funcregister("tln_findsequence",ring_TLN_FindSequence);
	ring_vm_funcregister("tln_getsequencepackcount",ring_TLN_GetSequencePackCount);
	ring_vm_funcregister("tln_addsequencetopack",ring_TLN_AddSequenceToPack);
	ring_vm_funcregister("tln_deletesequencepack",ring_TLN_DeleteSequencePack);
	ring_vm_funcregister("tln_setpaletteanimation",ring_TLN_SetPaletteAnimation);
	ring_vm_funcregister("tln_setpaletteanimationsource",ring_TLN_SetPaletteAnimationSource);
	ring_vm_funcregister("tln_getanimationstate",ring_TLN_GetAnimationState);
	ring_vm_funcregister("tln_setanimationdelay",ring_TLN_SetAnimationDelay);
	ring_vm_funcregister("tln_getavailableanimation",ring_TLN_GetAvailableAnimation);
	ring_vm_funcregister("tln_disablepaletteanimation",ring_TLN_DisablePaletteAnimation);
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
	ring_vm_funcregister("get_player1",ring_get_player1);
	ring_vm_funcregister("get_player2",ring_get_player2);
	ring_vm_funcregister("get_player3",ring_get_player3);
	ring_vm_funcregister("get_player4",ring_get_player4);
	ring_vm_funcregister("get_input_none",ring_get_input_none);
	ring_vm_funcregister("get_input_up",ring_get_input_up);
	ring_vm_funcregister("get_input_down",ring_get_input_down);
	ring_vm_funcregister("get_input_left",ring_get_input_left);
	ring_vm_funcregister("get_input_right",ring_get_input_right);
	ring_vm_funcregister("get_input_button1",ring_get_input_button1);
	ring_vm_funcregister("get_input_button2",ring_get_input_button2);
	ring_vm_funcregister("get_input_button3",ring_get_input_button3);
	ring_vm_funcregister("get_input_button4",ring_get_input_button4);
	ring_vm_funcregister("get_input_button5",ring_get_input_button5);
	ring_vm_funcregister("get_input_button6",ring_get_input_button6);
	ring_vm_funcregister("get_input_start",ring_get_input_start);
	ring_vm_funcregister("get_input_quit",ring_get_input_quit);
	ring_vm_funcregister("get_input_crt",ring_get_input_crt);
	ring_vm_funcregister("get_input_p1",ring_get_input_p1);
	ring_vm_funcregister("get_input_p2",ring_get_input_p2);
	ring_vm_funcregister("get_input_p3",ring_get_input_p3);
	ring_vm_funcregister("get_input_p4",ring_get_input_p4);
	ring_vm_funcregister("get_input_a",ring_get_input_a);
	ring_vm_funcregister("get_input_b",ring_get_input_b);
	ring_vm_funcregister("get_input_c",ring_get_input_c);
	ring_vm_funcregister("get_input_d",ring_get_input_d);
	ring_vm_funcregister("get_input_e",ring_get_input_e);
	ring_vm_funcregister("get_input_f",ring_get_input_f);
	ring_vm_funcregister("get_cwf_fullscreen",ring_get_cwf_fullscreen);
	ring_vm_funcregister("get_cwf_vsync",ring_get_cwf_vsync);
	ring_vm_funcregister("get_cwf_s1",ring_get_cwf_s1);
	ring_vm_funcregister("get_cwf_s2",ring_get_cwf_s2);
	ring_vm_funcregister("get_cwf_s3",ring_get_cwf_s3);
	ring_vm_funcregister("get_cwf_s4",ring_get_cwf_s4);
	ring_vm_funcregister("get_cwf_s5",ring_get_cwf_s5);
	ring_vm_funcregister("get_tln_err_ok",ring_get_tln_err_ok);
	ring_vm_funcregister("get_tln_err_out_of_memory",ring_get_tln_err_out_of_memory);
	ring_vm_funcregister("get_tln_err_idx_layer",ring_get_tln_err_idx_layer);
	ring_vm_funcregister("get_tln_err_idx_sprite",ring_get_tln_err_idx_sprite);
	ring_vm_funcregister("get_tln_err_idx_animation",ring_get_tln_err_idx_animation);
	ring_vm_funcregister("get_tln_err_idx_picture",ring_get_tln_err_idx_picture);
	ring_vm_funcregister("get_tln_err_ref_tileset",ring_get_tln_err_ref_tileset);
	ring_vm_funcregister("get_tln_err_ref_tilemap",ring_get_tln_err_ref_tilemap);
	ring_vm_funcregister("get_tln_err_ref_spriteset",ring_get_tln_err_ref_spriteset);
	ring_vm_funcregister("get_tln_err_ref_palette",ring_get_tln_err_ref_palette);
	ring_vm_funcregister("get_tln_err_ref_sequence",ring_get_tln_err_ref_sequence);
	ring_vm_funcregister("get_tln_err_ref_seqpack",ring_get_tln_err_ref_seqpack);
	ring_vm_funcregister("get_tln_err_ref_bitmap",ring_get_tln_err_ref_bitmap);
	ring_vm_funcregister("get_tln_err_null_pointer",ring_get_tln_err_null_pointer);
	ring_vm_funcregister("get_tln_err_file_not_found",ring_get_tln_err_file_not_found);
	ring_vm_funcregister("get_tln_err_wrong_format",ring_get_tln_err_wrong_format);
	ring_vm_funcregister("get_tln_err_wrong_size",ring_get_tln_err_wrong_size);
	ring_vm_funcregister("get_tln_err_unsupported",ring_get_tln_err_unsupported);
	ring_vm_funcregister("get_tln_err_ref_list",ring_get_tln_err_ref_list);
	ring_vm_funcregister("get_tln_max_err",ring_get_tln_max_err);
	ring_vm_funcregister("get_tln_log_none",ring_get_tln_log_none);
	ring_vm_funcregister("get_tln_log_errors",ring_get_tln_log_errors);
	ring_vm_funcregister("get_tln_log_verbose",ring_get_tln_log_verbose);
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
	ring_vm_funcregister("new_tln_spritestate",ring_new_tln_spritestate);
	ring_vm_funcregister("new_managed_tln_spritestate",ring_new_managed_tln_spritestate);
	ring_vm_funcregister("destroy_tln_spritestate",ring_destroy_tln_spritestate);
	ring_vm_funcregister("get_tln_spritestate_x",ring_get_tln_spritestate_x);
	ring_vm_funcregister("set_tln_spritestate_x",ring_set_tln_spritestate_x);
	ring_vm_funcregister("get_tln_spritestate_y",ring_get_tln_spritestate_y);
	ring_vm_funcregister("set_tln_spritestate_y",ring_set_tln_spritestate_y);
	ring_vm_funcregister("get_tln_spritestate_w",ring_get_tln_spritestate_w);
	ring_vm_funcregister("set_tln_spritestate_w",ring_set_tln_spritestate_w);
	ring_vm_funcregister("get_tln_spritestate_h",ring_get_tln_spritestate_h);
	ring_vm_funcregister("set_tln_spritestate_h",ring_set_tln_spritestate_h);
	ring_vm_funcregister("get_tln_spritestate_flags",ring_get_tln_spritestate_flags);
	ring_vm_funcregister("set_tln_spritestate_flags",ring_set_tln_spritestate_flags);
	ring_vm_funcregister("get_tln_spritestate_index",ring_get_tln_spritestate_index);
	ring_vm_funcregister("set_tln_spritestate_index",ring_set_tln_spritestate_index);
	ring_vm_funcregister("get_tln_spritestate_enabled",ring_get_tln_spritestate_enabled);
	ring_vm_funcregister("set_tln_spritestate_enabled",ring_set_tln_spritestate_enabled);
	ring_vm_funcregister("get_tln_spritestate_collision",ring_get_tln_spritestate_collision);
	ring_vm_funcregister("set_tln_spritestate_collision",ring_set_tln_spritestate_collision);
	ring_vm_funcregister("new_tln_tilemap",ring_new_tln_tilemap);
	ring_vm_funcregister("new_managed_tln_tilemap",ring_new_managed_tln_tilemap);
	ring_vm_funcregister("destroy_tln_tilemap",ring_destroy_tln_tilemap);
}

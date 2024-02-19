#include "ring.h"

/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */

#define ALLEGRO_NO_MAGIC_MAIN

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_opengl.h>
#include <allegro5/allegro_direct3d.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_memfile.h>
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_physfs.h>
#include <allegro5/allegro_primitives.h>
RING_FUNC(ring_al_new_allegro_event)
{
	ALLEGRO_EVENT *pMyPointer ;
	pMyPointer = (ALLEGRO_EVENT *) RING_API_MALLOC(sizeof(ALLEGRO_EVENT)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"ALLEGRO_EVENT");
}

RING_FUNC(ring_al_new_managed_allegro_event)
{
	ALLEGRO_EVENT *pMyPointer ;
	pMyPointer = (ALLEGRO_EVENT *) RING_API_MALLOC(sizeof(ALLEGRO_EVENT)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"ALLEGRO_EVENT",RING_API_FREEFUNC);
}

RING_FUNC(ring_al_destroy_allegro_event)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (ALLEGRO_EVENT*) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_al_get_allegro_event_type)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_al_set_allegro_event_type)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_get_allegro_event_keyboard_keycode)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->keyboard.keycode);
}

RING_FUNC(ring_al_set_allegro_event_keyboard_keycode)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->keyboard.keycode = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_get_allegro_event_mouse_x)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->mouse.x);
}

RING_FUNC(ring_al_set_allegro_event_mouse_x)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->mouse.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_get_allegro_event_mouse_y)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->mouse.y);
}

RING_FUNC(ring_al_set_allegro_event_mouse_y)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->mouse.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_get_allegro_event_timer_source)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETCPOINTER(pMyPointer->timer.source,"ALLEGRO_TIMER");
}

RING_FUNC(ring_al_set_allegro_event_timer_source)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->timer.source = (ALLEGRO_TIMER *) RING_API_GETCPOINTER(2,"ALLEGRO_TIMER");
}

RING_FUNC(ring_al_get_allegro_event_joystick_id)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETCPOINTER(pMyPointer->joystick.id,"ALLEGRO_JOYSTICK");
}

RING_FUNC(ring_al_set_allegro_event_joystick_id)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->joystick.id = (ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(2,"ALLEGRO_JOYSTICK");
}

RING_FUNC(ring_al_get_allegro_event_joystick_stick)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->joystick.stick);
}

RING_FUNC(ring_al_set_allegro_event_joystick_stick)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->joystick.stick = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_get_allegro_event_joystick_axis)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->joystick.axis);
}

RING_FUNC(ring_al_set_allegro_event_joystick_axis)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->joystick.axis = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_get_allegro_event_joystick_pos)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->joystick.pos);
}

RING_FUNC(ring_al_set_allegro_event_joystick_pos)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->joystick.pos = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_get_allegro_event_joystick_button)
{
	ALLEGRO_EVENT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	RING_API_RETNUMBER(pMyPointer->joystick.button);
}

RING_FUNC(ring_al_set_allegro_event_joystick_button)
{
	ALLEGRO_EVENT *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"ALLEGRO_EVENT");
	pMyPointer->joystick.button = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_al_new_allegro_timeout)
{
	ALLEGRO_TIMEOUT *pMyPointer ;
	pMyPointer = (ALLEGRO_TIMEOUT *) RING_API_MALLOC(sizeof(ALLEGRO_TIMEOUT)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"ALLEGRO_TIMEOUT");
}

RING_FUNC(ring_al_new_managed_allegro_timeout)
{
	ALLEGRO_TIMEOUT *pMyPointer ;
	pMyPointer = (ALLEGRO_TIMEOUT *) RING_API_MALLOC(sizeof(ALLEGRO_TIMEOUT)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"ALLEGRO_TIMEOUT",RING_API_FREEFUNC);
}

RING_FUNC(ring_al_destroy_allegro_timeout)
{
	ALLEGRO_TIMEOUT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (ALLEGRO_TIMEOUT*) RING_API_GETCPOINTER(1,"ALLEGRO_TIMEOUT");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_al_new_allegro_sample_id)
{
	ALLEGRO_SAMPLE_ID *pMyPointer ;
	pMyPointer = (ALLEGRO_SAMPLE_ID *) RING_API_MALLOC(sizeof(ALLEGRO_SAMPLE_ID)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"ALLEGRO_SAMPLE_ID");
}

RING_FUNC(ring_al_new_managed_allegro_sample_id)
{
	ALLEGRO_SAMPLE_ID *pMyPointer ;
	pMyPointer = (ALLEGRO_SAMPLE_ID *) RING_API_MALLOC(sizeof(ALLEGRO_SAMPLE_ID)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"ALLEGRO_SAMPLE_ID",RING_API_FREEFUNC);
}

RING_FUNC(ring_al_destroy_allegro_sample_id)
{
	ALLEGRO_SAMPLE_ID *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (ALLEGRO_SAMPLE_ID*) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_ID");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_al_new_allegro_color)
{
	ALLEGRO_COLOR *pMyPointer ;
	pMyPointer = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"ALLEGRO_COLOR");
}

RING_FUNC(ring_al_new_managed_allegro_color)
{
	ALLEGRO_COLOR *pMyPointer ;
	pMyPointer = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"ALLEGRO_COLOR",RING_API_FREEFUNC);
}

RING_FUNC(ring_al_destroy_allegro_color)
{
	ALLEGRO_COLOR *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (ALLEGRO_COLOR*) RING_API_GETCPOINTER(1,"ALLEGRO_COLOR");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_al_new_allegro_joystick_state)
{
	ALLEGRO_JOYSTICK_STATE *pMyPointer ;
	pMyPointer = (ALLEGRO_JOYSTICK_STATE *) RING_API_MALLOC(sizeof(ALLEGRO_JOYSTICK_STATE)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"ALLEGRO_JOYSTICK_STATE");
}

RING_FUNC(ring_al_new_managed_allegro_joystick_state)
{
	ALLEGRO_JOYSTICK_STATE *pMyPointer ;
	pMyPointer = (ALLEGRO_JOYSTICK_STATE *) RING_API_MALLOC(sizeof(ALLEGRO_JOYSTICK_STATE)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"ALLEGRO_JOYSTICK_STATE",RING_API_FREEFUNC);
}

RING_FUNC(ring_al_destroy_allegro_joystick_state)
{
	ALLEGRO_JOYSTICK_STATE *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (ALLEGRO_JOYSTICK_STATE*) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK_STATE");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_al_exit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	exit(0);
}

VM *globalVM ;

int al_usr_main(int argc, char **argv)
{
	ring_vm_runcode(globalVM,"al_game_start()");	
	exit(0);
	return 0;
}

RING_FUNC(ring_al_run_main)
{
	globalVM = (VM *) pPointer ;
	al_run_main(globalVM->pRingState->nArgc,globalVM->pRingState->pArgv,al_usr_main);	
}

RING_FUNC(ring_al_init)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_init());
}


RING_FUNC(ring_al_create_config)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_config(),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_destroy_config)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_config((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"));
}


RING_FUNC(ring_al_load_config_file)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_config_file(RING_API_GETSTRING(1)),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_load_config_file_f)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_config_file_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_save_config_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_config_file(RING_API_GETSTRING(1),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG")));
}


RING_FUNC(ring_al_save_config_file_f)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_config_file_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG")));
}


RING_FUNC(ring_al_add_config_section)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_add_config_section((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_al_add_config_comment)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_add_config_comment((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_al_get_config_value)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_config_value((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_set_config_value)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_config_value((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_al_get_first_config_section)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_first_config_section((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),(ALLEGRO_CONFIG_SECTION **) RING_API_GETCPOINTER2POINTER(2,"ALLEGRO_CONFIG_SECTION")));
}


RING_FUNC(ring_al_get_next_config_section)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_next_config_section((ALLEGRO_CONFIG_SECTION **) RING_API_GETCPOINTER2POINTER(1,"ALLEGRO_CONFIG_SECTION")));
}


RING_FUNC(ring_al_get_first_config_entry)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_first_config_entry((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),RING_API_GETSTRING(2),(ALLEGRO_CONFIG_ENTRY **) RING_API_GETCPOINTER2POINTER(3,"ALLEGRO_CONFIG_ENTRY")));
}


RING_FUNC(ring_al_get_next_config_entry)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_next_config_entry((ALLEGRO_CONFIG_ENTRY **) RING_API_GETCPOINTER2POINTER(1,"ALLEGRO_CONFIG_ENTRY")));
}


RING_FUNC(ring_al_merge_config)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_merge_config((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG")),"ALLEGRO_CONFIG");
}


RING_FUNC(ring_al_merge_config_into)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_merge_config_into((ALLEGRO_CONFIG *) RING_API_GETCPOINTER(1,"ALLEGRO_CONFIG"),(ALLEGRO_CONFIG *) RING_API_GETCPOINTER(2,"ALLEGRO_CONFIG"));
}


RING_FUNC(ring_al_create_display)
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
	RING_API_RETCPOINTER(al_create_display( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)),"ALLEGRO_DISPLAY");
}


RING_FUNC(ring_al_destroy_display)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_display((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"));
}


RING_FUNC(ring_al_get_new_display_flags)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_new_display_flags());
}


RING_FUNC(ring_al_set_new_display_flags)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_new_display_flags( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_get_new_display_option)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_new_display_option( (int ) RING_API_GETNUMBER(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_al_set_new_display_option)
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
	al_set_new_display_option( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_al_reset_new_display_options)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_reset_new_display_options();
}


RING_FUNC(ring_al_get_new_window_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_new_window_position(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_al_set_new_window_position)
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
	al_set_new_window_position( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_get_new_display_refresh_rate)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_new_display_refresh_rate());
}


RING_FUNC(ring_al_set_new_display_refresh_rate)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_new_display_refresh_rate( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_get_display_event_source)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_display_event_source((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")),"ALLEGRO_EVENT_SOURCE");
}


RING_FUNC(ring_al_get_backbuffer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_backbuffer((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_flip_display)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_flip_display();
}


RING_FUNC(ring_al_update_display_region)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_update_display_region( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_al_wait_for_vsync)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_wait_for_vsync());
}


RING_FUNC(ring_al_get_display_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_display_width((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_get_display_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_display_height((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_resize_display)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_resize_display((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_acknowledge_resize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_acknowledge_resize((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_get_window_position)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_window_position((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_al_set_window_position)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_window_position((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_al_get_display_flags)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_display_flags((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_set_display_flag)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_display_flag((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2), (bool ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_get_display_option)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_get_display_option((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_display_format)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_display_format((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_get_display_refresh_rate)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_display_refresh_rate((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_set_window_title)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_window_title((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_al_set_display_icon)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_display_icon((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),(ALLEGRO_BITMAP *) RING_API_GETCPOINTER(2,"ALLEGRO_BITMAP"));
}


RING_FUNC(ring_al_set_display_icons)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_display_icons((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2),(ALLEGRO_BITMAP **) RING_API_GETCPOINTER2POINTER(3,"ALLEGRO_BITMAP"));
}


RING_FUNC(ring_al_inhibit_screensaver)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_inhibit_screensaver( (bool ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_acknowledge_drawing_halt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_acknowledge_drawing_halt((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"));
}


RING_FUNC(ring_al_acknowledge_drawing_resume)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_acknowledge_drawing_resume((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"));
}


RING_FUNC(ring_al_get_display_orientation)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_display_orientation((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_set_display_option)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_display_option((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_al_get_window_constraints)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_window_constraints((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5)));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
}


RING_FUNC(ring_al_set_window_constraints)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETNUMBER(al_set_window_constraints((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_al_create_event_queue)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_event_queue(),"ALLEGRO_EVENT_QUEUE");
}


RING_FUNC(ring_al_destroy_event_queue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_event_queue((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"));
}


RING_FUNC(ring_al_register_event_source)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_register_event_source((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"),(ALLEGRO_EVENT_SOURCE *) RING_API_GETCPOINTER(2,"ALLEGRO_EVENT_SOURCE"));
}


RING_FUNC(ring_al_unregister_event_source)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_unregister_event_source((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"),(ALLEGRO_EVENT_SOURCE *) RING_API_GETCPOINTER(2,"ALLEGRO_EVENT_SOURCE"));
}


RING_FUNC(ring_al_is_event_queue_empty)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_is_event_queue_empty((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE")));
}


RING_FUNC(ring_al_get_next_event)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_next_event((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"),(ALLEGRO_EVENT *) RING_API_GETCPOINTER(2,"ALLEGRO_EVENT")));
}


RING_FUNC(ring_al_peek_next_event)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_peek_next_event((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"),(ALLEGRO_EVENT *) RING_API_GETCPOINTER(2,"ALLEGRO_EVENT")));
}


RING_FUNC(ring_al_drop_next_event)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_drop_next_event((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE")));
}


RING_FUNC(ring_al_flush_event_queue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_flush_event_queue((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"));
}


RING_FUNC(ring_al_wait_for_event)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_wait_for_event((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"),(ALLEGRO_EVENT *) RING_API_GETCPOINTER(2,"ALLEGRO_EVENT"));
}


RING_FUNC(ring_al_wait_for_event_timed)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_wait_for_event_timed((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"),(ALLEGRO_EVENT *) RING_API_GETCPOINTER(2,"ALLEGRO_EVENT"), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_wait_for_event_until)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_wait_for_event_until((ALLEGRO_EVENT_QUEUE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_QUEUE"),(ALLEGRO_EVENT *) RING_API_GETCPOINTER(2,"ALLEGRO_EVENT"),(ALLEGRO_TIMEOUT *) RING_API_GETCPOINTER(3,"ALLEGRO_TIMEOUT")));
}


RING_FUNC(ring_al_init_user_event_source)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_init_user_event_source((ALLEGRO_EVENT_SOURCE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_SOURCE"));
}


RING_FUNC(ring_al_destroy_user_event_source)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_user_event_source((ALLEGRO_EVENT_SOURCE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_SOURCE"));
}


RING_FUNC(ring_al_unref_user_event)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_unref_user_event((ALLEGRO_USER_EVENT *) RING_API_GETCPOINTER(1,"ALLEGRO_USER_EVENT"));
}


RING_FUNC(ring_al_get_event_source_data)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		intptr_t *pValue ; 
		pValue = (intptr_t *) RING_API_MALLOC(sizeof(intptr_t)) ;
		*pValue = al_get_event_source_data((ALLEGRO_EVENT_SOURCE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_SOURCE"));
		RING_API_RETMANAGEDCPOINTER(pValue,"intptr_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_set_event_source_data)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_event_source_data((ALLEGRO_EVENT_SOURCE *) RING_API_GETCPOINTER(1,"ALLEGRO_EVENT_SOURCE"),* (intptr_t  *) RING_API_GETCPOINTER(2,"intptr_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"intptr_t"));
}


RING_FUNC(ring_al_fopen)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_fopen(RING_API_GETSTRING(1),RING_API_GETSTRING(2)),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_fopen_interface)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_fopen_interface((ALLEGRO_FILE_INTERFACE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE_INTERFACE"),RING_API_GETSTRING(2),RING_API_GETSTRING(3)),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_fopen_slice)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_fopen_slice((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (size_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_fclose)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_fclose((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"));
}


RING_FUNC(ring_al_fread)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fread((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),(void *) RING_API_GETCPOINTER(2,"void"), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_fwrite)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fwrite((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),(void *) RING_API_GETCPOINTER(2,"void"), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_fflush)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fflush((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_ftell)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ftell((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fseek)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fseek((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (int64_t ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_feof)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_feof((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_ferror)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ferror((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fclearerr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_fclearerr((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"));
}


RING_FUNC(ring_al_fungetc)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_fungetc((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fsize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fsize((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fgetc)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fgetc((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fputc)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_fputc((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fread16le)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fread16le((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fread16be)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fread16be((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fwrite16le)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_fwrite16le((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (int16_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fwrite16be)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_fwrite16be((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (int16_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fread32le)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fread32le((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fread32be)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fread32be((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")));
}


RING_FUNC(ring_al_fwrite32le)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_fwrite32le((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (int32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fwrite32be)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_fwrite32be((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"), (int32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fgets)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_fgets((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),* (char * const  *) RING_API_GETCPOINTER(2,"char * const"), (size_t ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"char"));
}


RING_FUNC(ring_al_fget_ustr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_fget_ustr((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_fputs)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fputs((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_al_fopen_fd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_fopen_fd( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2)),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_make_temp_file)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_make_temp_file(RING_API_GETSTRING(1),(ALLEGRO_PATH **) RING_API_GETCPOINTER2POINTER(2,"ALLEGRO_PATH")),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_set_new_file_interface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_new_file_interface((ALLEGRO_FILE_INTERFACE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE_INTERFACE"));
}


RING_FUNC(ring_al_set_standard_file_interface)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_set_standard_file_interface();
}


RING_FUNC(ring_al_get_new_file_interface)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_new_file_interface(),"ALLEGRO_FILE_INTERFACE");
}


RING_FUNC(ring_al_create_file_handle)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_file_handle((ALLEGRO_FILE_INTERFACE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE_INTERFACE"),(void *) RING_API_GETCPOINTER(2,"void")),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_get_file_userdata)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_file_userdata((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE")),"void");
}


RING_FUNC(ring_al_create_fs_entry)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_fs_entry(RING_API_GETSTRING(1)),"ALLEGRO_FS_ENTRY");
}


RING_FUNC(ring_al_destroy_fs_entry)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_fs_entry((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY"));
}


RING_FUNC(ring_al_get_fs_entry_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_fs_entry_name((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")));
}


RING_FUNC(ring_al_update_fs_entry)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_update_fs_entry((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")));
}


RING_FUNC(ring_al_get_fs_entry_mode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_fs_entry_mode((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")));
}


RING_FUNC(ring_al_get_fs_entry_atime)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		time_t *pValue ; 
		pValue = (time_t *) RING_API_MALLOC(sizeof(time_t)) ;
		*pValue = al_get_fs_entry_atime((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY"));
		RING_API_RETMANAGEDCPOINTER(pValue,"time_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_get_fs_entry_ctime)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		time_t *pValue ; 
		pValue = (time_t *) RING_API_MALLOC(sizeof(time_t)) ;
		*pValue = al_get_fs_entry_ctime((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY"));
		RING_API_RETMANAGEDCPOINTER(pValue,"time_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_get_fs_entry_mtime)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		time_t *pValue ; 
		pValue = (time_t *) RING_API_MALLOC(sizeof(time_t)) ;
		*pValue = al_get_fs_entry_mtime((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY"));
		RING_API_RETMANAGEDCPOINTER(pValue,"time_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_get_fs_entry_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		off_t *pValue ; 
		pValue = (off_t *) RING_API_MALLOC(sizeof(off_t)) ;
		*pValue = al_get_fs_entry_size((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY"));
		RING_API_RETMANAGEDCPOINTER(pValue,"off_t",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_fs_entry_exists)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fs_entry_exists((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")));
}


RING_FUNC(ring_al_remove_fs_entry)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_remove_fs_entry((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")));
}


RING_FUNC(ring_al_filename_exists)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_filename_exists(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_al_remove_filename)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_remove_filename(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_al_open_directory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_open_directory((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")));
}


RING_FUNC(ring_al_read_directory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_read_directory((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")),"ALLEGRO_FS_ENTRY");
}


RING_FUNC(ring_al_close_directory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_close_directory((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY")));
}


RING_FUNC(ring_al_get_current_directory)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(al_get_current_directory());
}


RING_FUNC(ring_al_change_directory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_change_directory(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_al_make_directory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_make_directory(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_al_open_fs_entry)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_open_fs_entry((ALLEGRO_FS_ENTRY *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_ENTRY"),RING_API_GETSTRING(2)),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_set_fs_interface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_fs_interface((ALLEGRO_FS_INTERFACE *) RING_API_GETCPOINTER(1,"ALLEGRO_FS_INTERFACE"));
}


RING_FUNC(ring_al_set_standard_fs_interface)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_set_standard_fs_interface();
}


RING_FUNC(ring_al_get_fs_interface)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_fs_interface(),"ALLEGRO_FS_INTERFACE");
}


RING_FUNC(ring_al_itofix)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_itofix( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixtoi)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixtoi( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixfloor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixfloor( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixceil)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixceil( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_ftofix)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ftofix( (double ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixtof)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixtof( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixmul)
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
	RING_API_RETNUMBER(al_fixmul( (al_fixed ) RING_API_GETNUMBER(1), (al_fixed ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fixdiv)
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
	RING_API_RETNUMBER(al_fixdiv( (al_fixed ) RING_API_GETNUMBER(1), (al_fixed ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fixadd)
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
	RING_API_RETNUMBER(al_fixadd( (al_fixed ) RING_API_GETNUMBER(1), (al_fixed ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fixsub)
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
	RING_API_RETNUMBER(al_fixsub( (al_fixed ) RING_API_GETNUMBER(1), (al_fixed ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fixsin)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixsin( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixcos)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixcos( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixtan)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixtan( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixasin)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixasin( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixacos)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixacos( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixatan)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixatan( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixatan2)
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
	RING_API_RETNUMBER(al_fixatan2( (al_fixed ) RING_API_GETNUMBER(1), (al_fixed ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_fixsqrt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_fixsqrt( (al_fixed ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_fixhypot)
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
	RING_API_RETNUMBER(al_fixhypot( (al_fixed ) RING_API_GETNUMBER(1), (al_fixed ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_display_mode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_display_mode( (int ) RING_API_GETNUMBER(1),(ALLEGRO_DISPLAY_MODE *) RING_API_GETCPOINTER(2,"ALLEGRO_DISPLAY_MODE")),"ALLEGRO_DISPLAY_MODE");
}


RING_FUNC(ring_al_get_num_display_modes)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_num_display_modes());
}


RING_FUNC(ring_al_map_rgb)
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
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_map_rgb( (unsigned char ) RING_API_GETNUMBER(1), (unsigned char ) RING_API_GETNUMBER(2), (unsigned char ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_map_rgb_f)
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
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_map_rgb_f( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_map_rgba)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_map_rgba( (unsigned char ) RING_API_GETNUMBER(1), (unsigned char ) RING_API_GETNUMBER(2), (unsigned char ) RING_API_GETNUMBER(3), (unsigned char ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_map_rgba_f)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_map_rgba_f( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_unmap_rgb)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	al_unmap_rgb(* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"),(unsigned char *) RING_API_GETCPOINTER(2,"unsigned char"),(unsigned char *) RING_API_GETCPOINTER(3,"unsigned char"),(unsigned char *) RING_API_GETCPOINTER(4,"unsigned char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_unmap_rgb_f)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	al_unmap_rgb_f(* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"),(float *) RING_API_GETCPOINTER(2,"float"),(float *) RING_API_GETCPOINTER(3,"float"),(float *) RING_API_GETCPOINTER(4,"float"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_unmap_rgba)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_unmap_rgba(* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"),(unsigned char *) RING_API_GETCPOINTER(2,"unsigned char"),(unsigned char *) RING_API_GETCPOINTER(3,"unsigned char"),(unsigned char *) RING_API_GETCPOINTER(4,"unsigned char"),(unsigned char *) RING_API_GETCPOINTER(5,"unsigned char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_unmap_rgba_f)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_unmap_rgba_f(* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"),(float *) RING_API_GETCPOINTER(2,"float"),(float *) RING_API_GETCPOINTER(3,"float"),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_get_pixel_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_pixel_size( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_get_pixel_format_bits)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_pixel_format_bits( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_lock_bitmap)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_lock_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"ALLEGRO_LOCKED_REGION");
}


RING_FUNC(ring_al_lock_bitmap_region)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETCPOINTER(al_lock_bitmap_region((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7)),"ALLEGRO_LOCKED_REGION");
}


RING_FUNC(ring_al_unlock_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_unlock_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"));
}


RING_FUNC(ring_al_create_bitmap)
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
	RING_API_RETCPOINTER(al_create_bitmap( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_create_sub_bitmap)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETCPOINTER(al_create_sub_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_clone_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_clone_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_destroy_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"));
}


RING_FUNC(ring_al_get_new_bitmap_flags)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_new_bitmap_flags());
}


RING_FUNC(ring_al_get_new_bitmap_format)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_new_bitmap_format());
}


RING_FUNC(ring_al_set_new_bitmap_flags)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_new_bitmap_flags( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_add_new_bitmap_flag)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_add_new_bitmap_flag( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_set_new_bitmap_format)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_new_bitmap_format( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_get_bitmap_flags)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_bitmap_flags((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_get_bitmap_format)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_bitmap_format((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_get_bitmap_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_bitmap_height((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_get_bitmap_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_bitmap_width((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_get_pixel)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_get_pixel((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_is_bitmap_locked)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_is_bitmap_locked((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_is_compatible_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_is_compatible_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_is_sub_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_is_sub_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_get_parent_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_parent_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_clear_to_color)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	al_clear_to_color(* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_bitmap)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_al_draw_tinted_bitmap)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	al_draw_tinted_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_bitmap_region)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_draw_bitmap_region((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (int ) RING_API_GETNUMBER(8));
}


RING_FUNC(ring_al_draw_tinted_bitmap_region)
{
	if ( RING_API_PARACOUNT != 9 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	al_draw_tinted_bitmap_region((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (int ) RING_API_GETNUMBER(9));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_pixel)
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
	al_draw_pixel( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_rotated_bitmap)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_draw_rotated_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7));
}


RING_FUNC(ring_al_draw_tinted_rotated_bitmap)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	al_draw_tinted_rotated_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (int ) RING_API_GETNUMBER(8));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_scaled_rotated_bitmap)
{
	if ( RING_API_PARACOUNT != 9 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_draw_scaled_rotated_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (int ) RING_API_GETNUMBER(9));
}


RING_FUNC(ring_al_draw_tinted_scaled_rotated_bitmap)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_tinted_scaled_rotated_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (int ) RING_API_GETNUMBER(10));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_tinted_scaled_rotated_bitmap_region)
{
	if ( RING_API_PARACOUNT != 14 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(11) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(12) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(13) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(14) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_tinted_scaled_rotated_bitmap_region((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (float ) RING_API_GETNUMBER(10), (float ) RING_API_GETNUMBER(11), (float ) RING_API_GETNUMBER(12), (float ) RING_API_GETNUMBER(13), (int ) RING_API_GETNUMBER(14));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_scaled_bitmap)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_scaled_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (int ) RING_API_GETNUMBER(10));
}


RING_FUNC(ring_al_draw_tinted_scaled_bitmap)
{
	if ( RING_API_PARACOUNT != 11 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(11) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_tinted_scaled_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (float ) RING_API_GETNUMBER(10), (int ) RING_API_GETNUMBER(11));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_get_target_bitmap)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_target_bitmap(),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_put_pixel)
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
	al_put_pixel( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_put_blended_pixel)
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
	al_put_blended_pixel( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_set_target_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_target_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"));
}


RING_FUNC(ring_al_set_target_backbuffer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_target_backbuffer((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"));
}


RING_FUNC(ring_al_get_current_display)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_current_display(),"ALLEGRO_DISPLAY");
}


RING_FUNC(ring_al_get_blender)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_blender(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_al_get_separate_blender)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_separate_blender(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5),RING_API_GETINTPOINTER(6));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
	RING_API_ACCEPTINTVALUE(6) ;
}


RING_FUNC(ring_al_set_blender)
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
	al_set_blender( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_al_set_separate_blender)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_set_separate_blender( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_al_get_clipping_rectangle)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_clipping_rectangle(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_al_set_clipping_rectangle)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_clipping_rectangle( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_al_reset_clipping_rectangle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_reset_clipping_rectangle();
}


RING_FUNC(ring_al_convert_mask_to_alpha)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_convert_mask_to_alpha((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_hold_bitmap_drawing)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_hold_bitmap_drawing( (bool ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_is_bitmap_drawing_held)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_is_bitmap_drawing_held());
}


RING_FUNC(ring_al_load_bitmap)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_bitmap(RING_API_GETSTRING(1)),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_load_bitmap_f)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_bitmap_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2)),"ALLEGRO_BITMAP");
}


RING_FUNC(ring_al_save_bitmap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_bitmap(RING_API_GETSTRING(1),(ALLEGRO_BITMAP *) RING_API_GETCPOINTER(2,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_save_bitmap_f)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_bitmap_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2),(ALLEGRO_BITMAP *) RING_API_GETCPOINTER(3,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_install_joystick)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_install_joystick());
}


RING_FUNC(ring_al_uninstall_joystick)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_uninstall_joystick();
}


RING_FUNC(ring_al_is_joystick_installed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_is_joystick_installed());
}


RING_FUNC(ring_al_reconfigure_joysticks)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_reconfigure_joysticks());
}


RING_FUNC(ring_al_get_num_joysticks)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_num_joysticks());
}


RING_FUNC(ring_al_get_joystick)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_joystick( (int ) RING_API_GETNUMBER(1)),"ALLEGRO_JOYSTICK");
}


RING_FUNC(ring_al_release_joystick)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_release_joystick((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK"));
}


RING_FUNC(ring_al_get_joystick_active)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_joystick_active((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK")));
}


RING_FUNC(ring_al_get_joystick_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_joystick_name((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK")));
}


RING_FUNC(ring_al_get_joystick_stick_name)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETSTRING(al_get_joystick_stick_name((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_joystick_axis_name)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_joystick_axis_name((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_get_joystick_button_name)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETSTRING(al_get_joystick_button_name((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_joystick_stick_flags)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_get_joystick_stick_flags((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_joystick_num_sticks)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_joystick_num_sticks((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK")));
}


RING_FUNC(ring_al_get_joystick_num_axes)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_get_joystick_num_axes((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_joystick_num_buttons)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_joystick_num_buttons((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK")));
}


RING_FUNC(ring_al_get_joystick_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_joystick_state((ALLEGRO_JOYSTICK *) RING_API_GETCPOINTER(1,"ALLEGRO_JOYSTICK"),(ALLEGRO_JOYSTICK_STATE *) RING_API_GETCPOINTER(2,"ALLEGRO_JOYSTICK_STATE"));
}


RING_FUNC(ring_al_get_joystick_event_source)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_joystick_event_source(),"ALLEGRO_EVENT_SOURCE");
}


RING_FUNC(ring_al_install_keyboard)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_install_keyboard());
}


RING_FUNC(ring_al_is_keyboard_installed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_is_keyboard_installed());
}


RING_FUNC(ring_al_uninstall_keyboard)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_uninstall_keyboard();
}


RING_FUNC(ring_al_get_keyboard_state)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_keyboard_state((ALLEGRO_KEYBOARD_STATE *) RING_API_GETCPOINTER(1,"ALLEGRO_KEYBOARD_STATE"));
}


RING_FUNC(ring_al_key_down)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_key_down((ALLEGRO_KEYBOARD_STATE *) RING_API_GETCPOINTER(1,"ALLEGRO_KEYBOARD_STATE"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_keycode_to_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_keycode_to_name( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_set_keyboard_leds)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_keyboard_leds( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_get_keyboard_event_source)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_keyboard_event_source(),"ALLEGRO_EVENT_SOURCE");
}


RING_FUNC(ring_al_malloc_with_context)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_malloc_with_context( (size_t ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4)),"void");
}


RING_FUNC(ring_al_free_with_context)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_free_with_context((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_al_realloc_with_context)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_realloc_with_context((void *) RING_API_GETCPOINTER(1,"void"), (size_t ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5)),"void");
}


RING_FUNC(ring_al_calloc_with_context)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_calloc_with_context( (size_t ) RING_API_GETNUMBER(1), (size_t ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5)),"void");
}


RING_FUNC(ring_al_set_memory_interface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_memory_interface((ALLEGRO_MEMORY_INTERFACE *) RING_API_GETCPOINTER(1,"ALLEGRO_MEMORY_INTERFACE"));
}


RING_FUNC(ring_al_get_new_display_adapter)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_new_display_adapter());
}


RING_FUNC(ring_al_set_new_display_adapter)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_new_display_adapter( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_get_monitor_info)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_monitor_info( (int ) RING_API_GETNUMBER(1),(ALLEGRO_MONITOR_INFO *) RING_API_GETCPOINTER(2,"ALLEGRO_MONITOR_INFO")));
}


RING_FUNC(ring_al_get_num_video_adapters)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_num_video_adapters());
}


RING_FUNC(ring_al_install_mouse)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_install_mouse());
}


RING_FUNC(ring_al_is_mouse_installed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_is_mouse_installed());
}


RING_FUNC(ring_al_uninstall_mouse)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_uninstall_mouse();
}


RING_FUNC(ring_al_get_mouse_num_axes)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_mouse_num_axes());
}


RING_FUNC(ring_al_get_mouse_num_buttons)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_mouse_num_buttons());
}


RING_FUNC(ring_al_get_mouse_state)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_mouse_state((ALLEGRO_MOUSE_STATE *) RING_API_GETCPOINTER(1,"ALLEGRO_MOUSE_STATE"));
}


RING_FUNC(ring_al_get_mouse_state_axis)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_get_mouse_state_axis((ALLEGRO_MOUSE_STATE *) RING_API_GETCPOINTER(1,"ALLEGRO_MOUSE_STATE"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_mouse_button_down)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_mouse_button_down((ALLEGRO_MOUSE_STATE *) RING_API_GETCPOINTER(1,"ALLEGRO_MOUSE_STATE"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_set_mouse_xy)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_mouse_xy((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_set_mouse_z)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_mouse_z( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_set_mouse_w)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_mouse_w( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_set_mouse_axis)
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
	RING_API_RETNUMBER(al_set_mouse_axis( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_mouse_event_source)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_mouse_event_source(),"ALLEGRO_EVENT_SOURCE");
}


RING_FUNC(ring_al_create_mouse_cursor)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_mouse_cursor((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"ALLEGRO_MOUSE_CURSOR");
}


RING_FUNC(ring_al_destroy_mouse_cursor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_mouse_cursor((ALLEGRO_MOUSE_CURSOR *) RING_API_GETCPOINTER(1,"ALLEGRO_MOUSE_CURSOR"));
}


RING_FUNC(ring_al_set_mouse_cursor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_mouse_cursor((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),(ALLEGRO_MOUSE_CURSOR *) RING_API_GETCPOINTER(2,"ALLEGRO_MOUSE_CURSOR")));
}


RING_FUNC(ring_al_set_system_mouse_cursor)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_system_mouse_cursor((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),* (ALLEGRO_SYSTEM_MOUSE_CURSOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_SYSTEM_MOUSE_CURSOR")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_SYSTEM_MOUSE_CURSOR"));
}


RING_FUNC(ring_al_get_mouse_cursor_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_mouse_cursor_position(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_al_hide_mouse_cursor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_hide_mouse_cursor((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_show_mouse_cursor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_show_mouse_cursor((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_grab_mouse)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_grab_mouse((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_ungrab_mouse)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_ungrab_mouse());
}


RING_FUNC(ring_al_create_path)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_path(RING_API_GETSTRING(1)),"ALLEGRO_PATH");
}


RING_FUNC(ring_al_create_path_for_directory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_path_for_directory(RING_API_GETSTRING(1)),"ALLEGRO_PATH");
}


RING_FUNC(ring_al_destroy_path)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_path((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"));
}


RING_FUNC(ring_al_clone_path)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_clone_path((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")),"ALLEGRO_PATH");
}


RING_FUNC(ring_al_join_paths)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_join_paths((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"),(ALLEGRO_PATH *) RING_API_GETCPOINTER(2,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_rebase_path)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_rebase_path((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"),(ALLEGRO_PATH *) RING_API_GETCPOINTER(2,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_get_path_drive)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_path_drive((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_get_path_num_components)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_path_num_components((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_get_path_component)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETSTRING(al_get_path_component((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_path_tail)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_path_tail((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_get_path_filename)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_path_filename((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_get_path_basename)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_path_basename((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_get_path_extension)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_path_extension((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_set_path_drive)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_path_drive((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_al_append_path_component)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_append_path_component((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_al_insert_path_component)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_insert_path_component((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_al_replace_path_component)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_replace_path_component((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_al_remove_path_component)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	al_remove_path_component((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_drop_path_tail)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_drop_path_tail((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"));
}


RING_FUNC(ring_al_set_path_filename)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_path_filename((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_al_set_path_extension)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_path_extension((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_al_path_cstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETSTRING(al_path_cstr((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH"), (char ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_make_path_canonical)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_make_path_canonical((ALLEGRO_PATH *) RING_API_GETCPOINTER(1,"ALLEGRO_PATH")));
}


RING_FUNC(ring_al_restore_state)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_restore_state((ALLEGRO_STATE *) RING_API_GETCPOINTER(1,"ALLEGRO_STATE"));
}


RING_FUNC(ring_al_store_state)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	al_store_state((ALLEGRO_STATE *) RING_API_GETCPOINTER(1,"ALLEGRO_STATE"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_get_errno)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_errno());
}


RING_FUNC(ring_al_set_errno)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_errno( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_uninstall_system)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_uninstall_system();
}


RING_FUNC(ring_al_is_system_installed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_is_system_installed());
}


RING_FUNC(ring_al_get_allegro_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_version());
}


RING_FUNC(ring_al_get_standard_path)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_standard_path( (int ) RING_API_GETNUMBER(1)),"ALLEGRO_PATH");
}


RING_FUNC(ring_al_set_exe_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_exe_name(RING_API_GETSTRING(1));
}


RING_FUNC(ring_al_set_app_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_app_name(RING_API_GETSTRING(1));
}


RING_FUNC(ring_al_set_org_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_org_name(RING_API_GETSTRING(1));
}


RING_FUNC(ring_al_get_app_name)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(al_get_app_name());
}


RING_FUNC(ring_al_get_org_name)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(al_get_org_name());
}


RING_FUNC(ring_al_get_system_config)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_system_config(),"ALLEGRO_CONFIG");
}

void *al_func_thread(ALLEGRO_THREAD *thread, void *pPointer)
{
	List *pList;
	VM *pVM;
	const char *cStr;
	pList = (List *) pPointer ;
	pVM = (VM *) ring_list_getpointer(pList,2);
	cStr = ring_list_getstring(pList,1);
	ring_vm_runcodefromthread(pVM,cStr);	
	ring_list_delete(pList);
	return NULL;
}

void *al_func_detached_thread(void *pPointer)
{
	return al_func_thread(NULL,pPointer);
}

RING_FUNC(ring_al_create_thread)
{
	ALLEGRO_THREAD *pThread;
	List *pList;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}	
	pList = ring_list_new(0);
	ring_list_addstring(pList,RING_API_GETSTRING(1));
	ring_list_addpointer(pList,pPointer);
	ring_vm_mutexfunctions((VM *) pPointer,al_create_mutex,al_lock_mutex,al_unlock_mutex,al_destroy_mutex);
	pThread = al_create_thread(al_func_thread, pList);
	al_start_thread(pThread);
	RING_API_RETCPOINTER(pThread,"ALLEGRO_THREAD");	
}

RING_FUNC(ring_al_run_detached_thread)
{
	List *pList;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}	
	pList = ring_list_new(0);
	ring_list_addstring(pList,RING_API_GETSTRING(1));
	ring_list_addpointer(pList,pPointer);
	ring_vm_mutexfunctions((VM *) pPointer,al_create_mutex,al_lock_mutex,al_unlock_mutex,al_destroy_mutex);
	al_run_detached_thread(al_func_detached_thread, pList);
}

RING_FUNC(ring_al_start_thread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_start_thread((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"));
}


RING_FUNC(ring_al_join_thread)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_join_thread((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"),(void **) RING_API_GETCPOINTER2POINTER(2,"void"));
}


RING_FUNC(ring_al_set_thread_should_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_thread_should_stop((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"));
}


RING_FUNC(ring_al_get_thread_should_stop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_thread_should_stop((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD")));
}


RING_FUNC(ring_al_destroy_thread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_thread((ALLEGRO_THREAD *) RING_API_GETCPOINTER(1,"ALLEGRO_THREAD"));
}


RING_FUNC(ring_al_create_mutex)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_mutex(),"ALLEGRO_MUTEX");
}


RING_FUNC(ring_al_create_mutex_recursive)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_mutex_recursive(),"ALLEGRO_MUTEX");
}


RING_FUNC(ring_al_lock_mutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_lock_mutex((ALLEGRO_MUTEX *) RING_API_GETCPOINTER(1,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_unlock_mutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_unlock_mutex((ALLEGRO_MUTEX *) RING_API_GETCPOINTER(1,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_destroy_mutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_mutex((ALLEGRO_MUTEX *) RING_API_GETCPOINTER(1,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_create_cond)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_cond(),"ALLEGRO_COND");
}


RING_FUNC(ring_al_destroy_cond)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"));
}


RING_FUNC(ring_al_wait_cond)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_wait_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"),(ALLEGRO_MUTEX *) RING_API_GETCPOINTER(2,"ALLEGRO_MUTEX"));
}


RING_FUNC(ring_al_wait_cond_until)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_wait_cond_until((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"),(ALLEGRO_MUTEX *) RING_API_GETCPOINTER(2,"ALLEGRO_MUTEX"),(ALLEGRO_TIMEOUT *) RING_API_GETCPOINTER(3,"ALLEGRO_TIMEOUT")));
}


RING_FUNC(ring_al_broadcast_cond)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_broadcast_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"));
}


RING_FUNC(ring_al_signal_cond)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_signal_cond((ALLEGRO_COND *) RING_API_GETCPOINTER(1,"ALLEGRO_COND"));
}


RING_FUNC(ring_al_get_time)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_time());
}


RING_FUNC(ring_al_init_timeout)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	al_init_timeout((ALLEGRO_TIMEOUT *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMEOUT"), (double ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_rest)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_rest( (double ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_al_create_timer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_timer( (double ) RING_API_GETNUMBER(1)),"ALLEGRO_TIMER");
}


RING_FUNC(ring_al_start_timer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_start_timer((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER"));
}


RING_FUNC(ring_al_stop_timer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_stop_timer((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER"));
}


RING_FUNC(ring_al_get_timer_started)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_timer_started((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER")));
}


RING_FUNC(ring_al_destroy_timer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_timer((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER"));
}


RING_FUNC(ring_al_get_timer_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_timer_count((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER")));
}


RING_FUNC(ring_al_set_timer_count)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	al_set_timer_count((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER"), (int64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_add_timer_count)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	al_add_timer_count((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER"), (int64_t ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_get_timer_speed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_timer_speed((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER")));
}


RING_FUNC(ring_al_set_timer_speed)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	al_set_timer_speed((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER"), (double ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_get_timer_event_source)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_timer_event_source((ALLEGRO_TIMER *) RING_API_GETCPOINTER(1,"ALLEGRO_TIMER")),"ALLEGRO_EVENT_SOURCE");
}


RING_FUNC(ring_al_copy_transform)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_copy_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"),(ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(2,"ALLEGRO_TRANSFORM"));
}


RING_FUNC(ring_al_use_transform)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_use_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"));
}


RING_FUNC(ring_al_get_current_transform)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_current_transform(),"ALLEGRO_TRANSFORM");
}


RING_FUNC(ring_al_invert_transform)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_invert_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"));
}


RING_FUNC(ring_al_check_inverse)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_check_inverse((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_identity_transform)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_identity_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"));
}


RING_FUNC(ring_al_build_transform)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_build_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_al_translate_transform)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_translate_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_al_rotate_transform)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	al_rotate_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_al_scale_transform)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_scale_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_al_transform_coordinates)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_transform_coordinates((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"),(float *) RING_API_GETCPOINTER(2,"float"),(float *) RING_API_GETCPOINTER(3,"float"));
}


RING_FUNC(ring_al_compose_transform)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_compose_transform((ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(1,"ALLEGRO_TRANSFORM"),(ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(2,"ALLEGRO_TRANSFORM"));
}


RING_FUNC(ring_al_ustr_new)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_ustr_new(RING_API_GETSTRING(1)),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ustr_new_from_buffer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_ustr_new_from_buffer(RING_API_GETSTRING(1), (size_t ) RING_API_GETNUMBER(2)),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ustr_free)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_ustr_free((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"));
}


RING_FUNC(ring_al_cstr)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_to_buffer)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_ustr_to_buffer((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_al_cstr_dup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_cstr_dup((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_dup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_ustr_dup((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ustr_dup_substr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_ustr_dup_substr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ustr_empty_string)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_ustr_empty_string(),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ref_cstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_ref_cstr((ALLEGRO_USTR_INFO *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR_INFO"),RING_API_GETSTRING(2)),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ref_buffer)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_ref_buffer((ALLEGRO_USTR_INFO *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR_INFO"),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ref_ustr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETCPOINTER(al_ref_ustr((ALLEGRO_USTR_INFO *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR_INFO"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ustr_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_size((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_length)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_length((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_offset)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_ustr_offset((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_ustr_next)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_next((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_al_ustr_prev)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_prev((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_al_ustr_get)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_ustr_get((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_ustr_get_next)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_get_next((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_al_ustr_prev_get)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_prev_get((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_al_ustr_insert)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_insert((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),(ALLEGRO_USTR *) RING_API_GETCPOINTER(3,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_insert_cstr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_insert_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_ustr_insert_chr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_insert_chr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2), (int32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_ustr_append)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_append((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_append_cstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_append_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_al_ustr_append_chr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_ustr_append_chr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_ustr_vappendf)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_vappendf((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETSTRING(2),* (va_list  *) RING_API_GETCPOINTER(3,"va_list")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"va_list"));
}


RING_FUNC(ring_al_ustr_remove_chr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_ustr_remove_chr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_ustr_remove_range)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_remove_range((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_ustr_truncate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_ustr_truncate((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_ustr_ltrim_ws)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_ltrim_ws((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_rtrim_ws)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_rtrim_ws((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_trim_ws)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_trim_ws((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_assign)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_assign((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_assign_substr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(al_ustr_assign_substr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_al_ustr_assign_cstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_assign_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_al_ustr_set_chr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_set_chr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2), (int32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_ustr_replace_range)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_replace_range((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),(ALLEGRO_USTR *) RING_API_GETCPOINTER(4,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_find_chr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_chr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2), (int32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_ustr_rfind_chr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_rfind_chr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2), (int32_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_ustr_find_set)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_set((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),(ALLEGRO_USTR *) RING_API_GETCPOINTER(3,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_find_set_cstr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_set_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_ustr_find_cset)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_cset((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),(ALLEGRO_USTR *) RING_API_GETCPOINTER(3,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_find_cset_cstr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_cset_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_ustr_find_str)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_str((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),(ALLEGRO_USTR *) RING_API_GETCPOINTER(3,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_find_cstr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_ustr_rfind_str)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_rfind_str((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),(ALLEGRO_USTR *) RING_API_GETCPOINTER(3,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_rfind_cstr)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_rfind_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_ustr_find_replace)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_replace((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),(ALLEGRO_USTR *) RING_API_GETCPOINTER(3,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(4,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_find_replace_cstr)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_find_replace_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4)));
}


RING_FUNC(ring_al_ustr_compare)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_compare((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_ncompare)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_ncompare((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_ustr_equal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_equal((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_has_prefix)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_has_prefix((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_has_prefix_cstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_has_prefix_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_al_ustr_has_suffix)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_has_suffix((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_has_suffix_cstr)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_has_suffix_cstr((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_al_ustr_new_from_utf16)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_ustr_new_from_utf16((uint16_t *) RING_API_GETCPOINTER(1,"uint16_t")),"ALLEGRO_USTR");
}


RING_FUNC(ring_al_ustr_size_utf16)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_size_utf16((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_ustr_encode_utf16)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_ustr_encode_utf16((ALLEGRO_USTR *) RING_API_GETCPOINTER(1,"ALLEGRO_USTR"),(uint16_t *) RING_API_GETCPOINTER(2,"uint16_t"), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_utf8_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_utf8_width( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_utf8_encode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_utf8_encode(RING_API_GETSTRING(1), (int32_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_utf16_width)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_utf16_width( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_get_d3d_device)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		LPDIRECT3DDEVICE9 *pValue ; 
		pValue = (LPDIRECT3DDEVICE9 *) RING_API_MALLOC(sizeof(LPDIRECT3DDEVICE9)) ;
		*pValue = al_get_d3d_device((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"));
		RING_API_RETMANAGEDCPOINTER(pValue,"LPDIRECT3DDEVICE9",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_get_d3d_system_texture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		LPDIRECT3DTEXTURE9 *pValue ; 
		pValue = (LPDIRECT3DTEXTURE9 *) RING_API_MALLOC(sizeof(LPDIRECT3DTEXTURE9)) ;
		*pValue = al_get_d3d_system_texture((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"));
		RING_API_RETMANAGEDCPOINTER(pValue,"LPDIRECT3DTEXTURE9",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_get_d3d_video_texture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		LPDIRECT3DTEXTURE9 *pValue ; 
		pValue = (LPDIRECT3DTEXTURE9 *) RING_API_MALLOC(sizeof(LPDIRECT3DTEXTURE9)) ;
		*pValue = al_get_d3d_video_texture((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"));
		RING_API_RETMANAGEDCPOINTER(pValue,"LPDIRECT3DTEXTURE9",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_have_d3d_non_pow2_texture_support)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_have_d3d_non_pow2_texture_support());
}


RING_FUNC(ring_al_have_d3d_non_square_texture_support)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_have_d3d_non_square_texture_support());
}


RING_FUNC(ring_al_get_d3d_texture_position)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_d3d_texture_position((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_al_is_d3d_device_lost)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_is_d3d_device_lost((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY")));
}


RING_FUNC(ring_al_get_opengl_extension_list)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_opengl_extension_list(),"ALLEGRO_OGL_EXT_LIST");
}


RING_FUNC(ring_al_get_opengl_proc_address)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_opengl_proc_address(RING_API_GETSTRING(1)),"void");
}


RING_FUNC(ring_al_get_opengl_texture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_opengl_texture((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_get_opengl_texture_size)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_opengl_texture_size((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_al_get_opengl_texture_position)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_opengl_texture_position((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_al_get_opengl_fbo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_opengl_fbo((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP")));
}


RING_FUNC(ring_al_remove_opengl_fbo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_remove_opengl_fbo((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"));
}


RING_FUNC(ring_al_have_opengl_extension)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_have_opengl_extension(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_al_get_opengl_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_opengl_version());
}


RING_FUNC(ring_al_get_opengl_variant)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_opengl_variant());
}


RING_FUNC(ring_al_set_current_opengl_context)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_set_current_opengl_context((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"));
}


RING_FUNC(ring_al_install_audio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_install_audio());
}


RING_FUNC(ring_al_uninstall_audio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_uninstall_audio();
}


RING_FUNC(ring_al_is_audio_installed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_is_audio_installed());
}


RING_FUNC(ring_al_reserve_samples)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_reserve_samples( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_get_allegro_audio_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_audio_version());
}


RING_FUNC(ring_al_get_audio_depth_size)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_depth_size( (ALLEGRO_AUDIO_DEPTH )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_get_channel_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_channel_count( (ALLEGRO_CHANNEL_CONF )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_al_create_voice)
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
	RING_API_RETCPOINTER(al_create_voice( (unsigned int ) RING_API_GETNUMBER(1), (ALLEGRO_AUDIO_DEPTH )  (int) RING_API_GETNUMBER(2), (ALLEGRO_CHANNEL_CONF )  (int) RING_API_GETNUMBER(3)),"ALLEGRO_VOICE");
}


RING_FUNC(ring_al_destroy_voice)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_voice((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE"));
}


RING_FUNC(ring_al_detach_voice)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_detach_voice((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE"));
}


RING_FUNC(ring_al_attach_audio_stream_to_voice)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_audio_stream_to_voice((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"),(ALLEGRO_VOICE *) RING_API_GETCPOINTER(2,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_attach_mixer_to_voice)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_mixer_to_voice((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"),(ALLEGRO_VOICE *) RING_API_GETCPOINTER(2,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_attach_sample_instance_to_voice)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_sample_instance_to_voice((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"),(ALLEGRO_VOICE *) RING_API_GETCPOINTER(2,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_get_voice_frequency)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_voice_frequency((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_get_voice_channels)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_voice_channels((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_get_voice_depth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_voice_depth((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_get_voice_playing)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_voice_playing((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_set_voice_playing)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_voice_playing((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE"), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_voice_position)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_voice_position((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE")));
}


RING_FUNC(ring_al_set_voice_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_voice_position((ALLEGRO_VOICE *) RING_API_GETCPOINTER(1,"ALLEGRO_VOICE"), (unsigned int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_create_sample)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETCPOINTER(al_create_sample((void *) RING_API_GETCPOINTER(1,"void"), (unsigned int ) RING_API_GETNUMBER(2), (unsigned int ) RING_API_GETNUMBER(3), (ALLEGRO_AUDIO_DEPTH )  (int) RING_API_GETNUMBER(4), (ALLEGRO_CHANNEL_CONF )  (int) RING_API_GETNUMBER(5), (bool ) RING_API_GETNUMBER(6)),"ALLEGRO_SAMPLE");
}


RING_FUNC(ring_al_destroy_sample)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_sample((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE"));
}


RING_FUNC(ring_al_play_sample)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_play_sample((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),(ALLEGRO_SAMPLE_ID *) RING_API_GETCPOINTER(6,"ALLEGRO_SAMPLE_ID")));
}


RING_FUNC(ring_al_stop_sample)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_stop_sample((ALLEGRO_SAMPLE_ID *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_ID"));
}


RING_FUNC(ring_al_stop_samples)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_stop_samples();
}


RING_FUNC(ring_al_get_sample_channels)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_channels((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE")));
}


RING_FUNC(ring_al_get_sample_depth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_depth((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE")));
}


RING_FUNC(ring_al_get_sample_frequency)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_frequency((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE")));
}


RING_FUNC(ring_al_get_sample_length)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_length((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE")));
}


RING_FUNC(ring_al_get_sample_data)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_sample_data((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE")),"void");
}


RING_FUNC(ring_al_create_sample_instance)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_sample_instance((ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE")),"ALLEGRO_SAMPLE_INSTANCE");
}


RING_FUNC(ring_al_destroy_sample_instance)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_sample_instance((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"));
}


RING_FUNC(ring_al_play_sample_instance)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_play_sample_instance((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_stop_sample_instance)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_stop_sample_instance((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_get_sample_instance_channels)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_channels((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_get_sample_instance_depth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_depth((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_get_sample_instance_frequency)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_frequency((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_get_sample_instance_length)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_length((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_set_sample_instance_length)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_sample_instance_length((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"), (unsigned int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_sample_instance_position)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_position((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_set_sample_instance_position)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_sample_instance_position((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"), (unsigned int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_sample_instance_speed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_speed((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_set_sample_instance_speed)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_sample_instance_speed((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_sample_instance_gain)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_gain((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_set_sample_instance_gain)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_sample_instance_gain((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_sample_instance_pan)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_pan((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_set_sample_instance_pan)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_sample_instance_pan((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_sample_instance_time)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_time((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_get_sample_instance_playmode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_PLAYMODE *pValue ; 
		pValue = (ALLEGRO_PLAYMODE *) RING_API_MALLOC(sizeof(ALLEGRO_PLAYMODE)) ;
		*pValue = al_get_sample_instance_playmode((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_PLAYMODE",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_set_sample_instance_playmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_sample_instance_playmode((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"),* (ALLEGRO_PLAYMODE  *) RING_API_GETCPOINTER(2,"ALLEGRO_PLAYMODE")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_PLAYMODE"));
}


RING_FUNC(ring_al_get_sample_instance_playing)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_playing((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_set_sample_instance_playing)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_sample_instance_playing((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_sample_instance_attached)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_sample_instance_attached((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_detach_sample_instance)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_detach_sample_instance((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")));
}


RING_FUNC(ring_al_get_sample)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_sample((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE")),"ALLEGRO_SAMPLE");
}


RING_FUNC(ring_al_set_sample)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_sample((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"),(ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(2,"ALLEGRO_SAMPLE")));
}


RING_FUNC(ring_al_create_mixer)
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
	RING_API_RETCPOINTER(al_create_mixer( (unsigned int ) RING_API_GETNUMBER(1), (ALLEGRO_AUDIO_DEPTH )  (int) RING_API_GETNUMBER(2), (ALLEGRO_CHANNEL_CONF )  (int) RING_API_GETNUMBER(3)),"ALLEGRO_MIXER");
}


RING_FUNC(ring_al_destroy_mixer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_mixer((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"));
}


RING_FUNC(ring_al_get_default_mixer)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_get_default_mixer(),"ALLEGRO_MIXER");
}


RING_FUNC(ring_al_set_default_mixer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_default_mixer((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_restore_default_mixer)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_restore_default_mixer());
}


RING_FUNC(ring_al_attach_mixer_to_mixer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_mixer_to_mixer((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"),(ALLEGRO_MIXER *) RING_API_GETCPOINTER(2,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_attach_sample_instance_to_mixer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_sample_instance_to_mixer((ALLEGRO_SAMPLE_INSTANCE *) RING_API_GETCPOINTER(1,"ALLEGRO_SAMPLE_INSTANCE"),(ALLEGRO_MIXER *) RING_API_GETCPOINTER(2,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_attach_audio_stream_to_mixer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_audio_stream_to_mixer((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"),(ALLEGRO_MIXER *) RING_API_GETCPOINTER(2,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_get_mixer_frequency)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_mixer_frequency((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_set_mixer_frequency)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_mixer_frequency((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"), (unsigned int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_mixer_channels)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_mixer_channels((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_get_mixer_depth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_mixer_depth((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_get_mixer_gain)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_mixer_gain((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_set_mixer_gain)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_mixer_gain((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_mixer_quality)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_MIXER_QUALITY *pValue ; 
		pValue = (ALLEGRO_MIXER_QUALITY *) RING_API_MALLOC(sizeof(ALLEGRO_MIXER_QUALITY)) ;
		*pValue = al_get_mixer_quality((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_MIXER_QUALITY",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_set_mixer_quality)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_mixer_quality((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"),* (ALLEGRO_MIXER_QUALITY  *) RING_API_GETCPOINTER(2,"ALLEGRO_MIXER_QUALITY")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_MIXER_QUALITY"));
}


RING_FUNC(ring_al_get_mixer_playing)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_mixer_playing((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_set_mixer_playing)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_mixer_playing((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER"), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_mixer_attached)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_mixer_attached((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_detach_mixer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_detach_mixer((ALLEGRO_MIXER *) RING_API_GETCPOINTER(1,"ALLEGRO_MIXER")));
}


RING_FUNC(ring_al_create_audio_stream)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_audio_stream( (size_t ) RING_API_GETNUMBER(1), (unsigned int ) RING_API_GETNUMBER(2), (unsigned int ) RING_API_GETNUMBER(3), (ALLEGRO_AUDIO_DEPTH )  (int) RING_API_GETNUMBER(4), (ALLEGRO_CHANNEL_CONF )  (int) RING_API_GETNUMBER(5)),"ALLEGRO_AUDIO_STREAM");
}


RING_FUNC(ring_al_destroy_audio_stream)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_audio_stream((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"));
}


RING_FUNC(ring_al_get_audio_stream_event_source)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_audio_stream_event_source((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")),"ALLEGRO_EVENT_SOURCE");
}


RING_FUNC(ring_al_drain_audio_stream)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_drain_audio_stream((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"));
}


RING_FUNC(ring_al_rewind_audio_stream)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_rewind_audio_stream((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_audio_stream_frequency)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_frequency((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_audio_stream_channels)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_channels((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_audio_stream_depth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_depth((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_audio_stream_length)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_length((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_audio_stream_speed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_speed((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_set_audio_stream_speed)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_audio_stream_speed((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_audio_stream_gain)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_gain((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_set_audio_stream_gain)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_audio_stream_gain((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_audio_stream_pan)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_pan((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_set_audio_stream_pan)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_audio_stream_pan((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_audio_stream_playing)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_playing((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_set_audio_stream_playing)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_set_audio_stream_playing((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_audio_stream_playmode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_PLAYMODE *pValue ; 
		pValue = (ALLEGRO_PLAYMODE *) RING_API_MALLOC(sizeof(ALLEGRO_PLAYMODE)) ;
		*pValue = al_get_audio_stream_playmode((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_PLAYMODE",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_set_audio_stream_playmode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_audio_stream_playmode((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"),* (ALLEGRO_PLAYMODE  *) RING_API_GETCPOINTER(2,"ALLEGRO_PLAYMODE")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_PLAYMODE"));
}


RING_FUNC(ring_al_get_audio_stream_attached)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_attached((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_detach_audio_stream)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_detach_audio_stream((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_audio_stream_fragment)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_audio_stream_fragment((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")),"void");
}


RING_FUNC(ring_al_set_audio_stream_fragment)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_audio_stream_fragment((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"),(void *) RING_API_GETCPOINTER(2,"void")));
}


RING_FUNC(ring_al_get_audio_stream_fragments)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_fragments((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_available_audio_stream_fragments)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_available_audio_stream_fragments((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_seek_audio_stream_secs)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(al_seek_audio_stream_secs((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"), (double ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_get_audio_stream_position_secs)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_position_secs((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_get_audio_stream_length_secs)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_audio_stream_length_secs((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM")));
}


RING_FUNC(ring_al_set_audio_stream_loop_secs)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_audio_stream_loop_secs((ALLEGRO_AUDIO_STREAM *) RING_API_GETCPOINTER(1,"ALLEGRO_AUDIO_STREAM"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_load_sample)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_sample(RING_API_GETSTRING(1)),"ALLEGRO_SAMPLE");
}


RING_FUNC(ring_al_load_sample_f)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_sample_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2)),"ALLEGRO_SAMPLE");
}


RING_FUNC(ring_al_load_audio_stream)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
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
	RING_API_RETCPOINTER(al_load_audio_stream(RING_API_GETSTRING(1), (size_t ) RING_API_GETNUMBER(2), (unsigned int ) RING_API_GETNUMBER(3)),"ALLEGRO_AUDIO_STREAM");
}


RING_FUNC(ring_al_load_audio_stream_f)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETCPOINTER(al_load_audio_stream_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3), (unsigned int ) RING_API_GETNUMBER(4)),"ALLEGRO_AUDIO_STREAM");
}


RING_FUNC(ring_al_save_sample)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_sample(RING_API_GETSTRING(1),(ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(2,"ALLEGRO_SAMPLE")));
}


RING_FUNC(ring_al_save_sample_f)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_save_sample_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2),(ALLEGRO_SAMPLE *) RING_API_GETCPOINTER(3,"ALLEGRO_SAMPLE")));
}


RING_FUNC(ring_al_init_acodec_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_init_acodec_addon());
}


RING_FUNC(ring_al_get_allegro_acodec_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_acodec_version());
}


RING_FUNC(ring_al_color_cmyk)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_color_cmyk( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_color_cmyk_to_rgb)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_cmyk_to_rgb( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"),(float *) RING_API_GETCPOINTER(7,"float"));
}


RING_FUNC(ring_al_color_hsl)
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
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_color_hsl( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_color_hsl_to_rgb)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_hsl_to_rgb( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"));
}


RING_FUNC(ring_al_color_hsv)
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
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_color_hsv( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_color_hsv_to_rgb)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_hsv_to_rgb( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"));
}


RING_FUNC(ring_al_color_html)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_color_html(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_color_html_to_rgb)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	al_color_html_to_rgb(RING_API_GETSTRING(1),(float *) RING_API_GETCPOINTER(2,"float"),(float *) RING_API_GETCPOINTER(3,"float"),(float *) RING_API_GETCPOINTER(4,"float"));
}


RING_FUNC(ring_al_color_rgb_to_html)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_rgb_to_html( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4));
}


RING_FUNC(ring_al_color_name)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_color_name(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_color_name_to_rgb)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	RING_API_RETNUMBER(al_color_name_to_rgb(RING_API_GETSTRING(1),(float *) RING_API_GETCPOINTER(2,"float"),(float *) RING_API_GETCPOINTER(3,"float"),(float *) RING_API_GETCPOINTER(4,"float")));
}


RING_FUNC(ring_al_color_rgb_to_cmyk)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_rgb_to_cmyk( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"),(float *) RING_API_GETCPOINTER(7,"float"));
}


RING_FUNC(ring_al_color_rgb_to_hsl)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_rgb_to_hsl( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"));
}


RING_FUNC(ring_al_color_rgb_to_hsv)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_rgb_to_hsv( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"));
}


RING_FUNC(ring_al_color_rgb_to_name)
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
	RING_API_RETSTRING(al_color_rgb_to_name( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_color_rgb_to_yuv)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_rgb_to_yuv( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"));
}


RING_FUNC(ring_al_color_yuv)
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
	{
		ALLEGRO_COLOR *pValue ; 
		pValue = (ALLEGRO_COLOR *) RING_API_MALLOC(sizeof(ALLEGRO_COLOR)) ;
		*pValue = al_color_yuv( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"ALLEGRO_COLOR",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_al_color_yuv_to_rgb)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_color_yuv_to_rgb( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),(float *) RING_API_GETCPOINTER(4,"float"),(float *) RING_API_GETCPOINTER(5,"float"),(float *) RING_API_GETCPOINTER(6,"float"));
}


RING_FUNC(ring_al_get_allegro_color_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_color_version());
}


RING_FUNC(ring_al_init_font_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_init_font_addon();
}


RING_FUNC(ring_al_shutdown_font_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_shutdown_font_addon();
}


RING_FUNC(ring_al_load_font)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
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
	RING_API_RETCPOINTER(al_load_font(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"ALLEGRO_FONT");
}


RING_FUNC(ring_al_destroy_font)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_font((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"));
}


RING_FUNC(ring_al_get_font_line_height)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_font_line_height((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT")));
}


RING_FUNC(ring_al_get_font_ascent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_font_ascent((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT")));
}


RING_FUNC(ring_al_get_font_descent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_font_descent((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT")));
}


RING_FUNC(ring_al_get_text_width)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_text_width((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_al_get_ustr_width)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_ustr_width((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR")));
}


RING_FUNC(ring_al_draw_text)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_text((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),RING_API_GETSTRING(6));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_ustr)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_ustr((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),(ALLEGRO_USTR *) RING_API_GETCPOINTER(6,"ALLEGRO_USTR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_justified_text)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISSTRING(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_justified_text((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7),RING_API_GETSTRING(8));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_justified_ustr)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_justified_ustr((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7),(ALLEGRO_USTR *) RING_API_GETCPOINTER(8,"ALLEGRO_USTR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_get_text_dimensions)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_text_dimensions((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),RING_API_GETSTRING(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5),RING_API_GETINTPOINTER(6));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
	RING_API_ACCEPTINTVALUE(6) ;
}


RING_FUNC(ring_al_get_ustr_dimensions)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_get_ustr_dimensions((ALLEGRO_FONT *) RING_API_GETCPOINTER(1,"ALLEGRO_FONT"),(ALLEGRO_USTR *) RING_API_GETCPOINTER(2,"ALLEGRO_USTR"),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5),RING_API_GETINTPOINTER(6));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
	RING_API_ACCEPTINTVALUE(6) ;
}


RING_FUNC(ring_al_get_allegro_font_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_font_version());
}


RING_FUNC(ring_al_grab_font_from_bitmap)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_grab_font_from_bitmap((ALLEGRO_BITMAP *) RING_API_GETCPOINTER(1,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3)),"ALLEGRO_FONT");
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_al_load_bitmap_font)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_bitmap_font(RING_API_GETSTRING(1)),"ALLEGRO_FONT");
}


RING_FUNC(ring_al_create_builtin_font)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(al_create_builtin_font(),"ALLEGRO_FONT");
}


RING_FUNC(ring_al_init_ttf_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_init_ttf_addon());
}


RING_FUNC(ring_al_shutdown_ttf_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_shutdown_ttf_addon();
}


RING_FUNC(ring_al_load_ttf_font)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
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
	RING_API_RETCPOINTER(al_load_ttf_font(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"ALLEGRO_FONT");
}


RING_FUNC(ring_al_load_ttf_font_f)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETCPOINTER(al_load_ttf_font_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)),"ALLEGRO_FONT");
}


RING_FUNC(ring_al_load_ttf_font_stretch)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_load_ttf_font_stretch(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)),"ALLEGRO_FONT");
}


RING_FUNC(ring_al_load_ttf_font_stretch_f)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETCPOINTER(al_load_ttf_font_stretch_f((ALLEGRO_FILE *) RING_API_GETCPOINTER(1,"ALLEGRO_FILE"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)),"ALLEGRO_FONT");
}


RING_FUNC(ring_al_get_allegro_ttf_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_ttf_version());
}


RING_FUNC(ring_al_init_image_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_init_image_addon());
}


RING_FUNC(ring_al_shutdown_image_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_shutdown_image_addon();
}


RING_FUNC(ring_al_get_allegro_image_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_image_version());
}


RING_FUNC(ring_al_open_memfile)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_open_memfile((void *) RING_API_GETCPOINTER(1,"void"), (int64_t ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)),"ALLEGRO_FILE");
}


RING_FUNC(ring_al_get_allegro_memfile_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_memfile_version());
}


RING_FUNC(ring_al_init_native_dialog_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_init_native_dialog_addon());
}


RING_FUNC(ring_al_shutdown_native_dialog_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_shutdown_native_dialog_addon();
}


RING_FUNC(ring_al_create_native_file_dialog)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
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
	RING_API_RETCPOINTER(al_create_native_file_dialog(RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4)),"ALLEGRO_FILECHOOSER");
}


RING_FUNC(ring_al_show_native_file_dialog)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_show_native_file_dialog((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),(ALLEGRO_FILECHOOSER *) RING_API_GETCPOINTER(2,"ALLEGRO_FILECHOOSER")));
}


RING_FUNC(ring_al_get_native_file_dialog_count)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_native_file_dialog_count((ALLEGRO_FILECHOOSER *) RING_API_GETCPOINTER(1,"ALLEGRO_FILECHOOSER")));
}


RING_FUNC(ring_al_get_native_file_dialog_path)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETSTRING(al_get_native_file_dialog_path((ALLEGRO_FILECHOOSER *) RING_API_GETCPOINTER(1,"ALLEGRO_FILECHOOSER"), (size_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_destroy_native_file_dialog)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_native_file_dialog((ALLEGRO_FILECHOOSER *) RING_API_GETCPOINTER(1,"ALLEGRO_FILECHOOSER"));
}


RING_FUNC(ring_al_show_native_message_box)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_show_native_message_box((ALLEGRO_DISPLAY *) RING_API_GETCPOINTER(1,"ALLEGRO_DISPLAY"),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5), (int ) RING_API_GETNUMBER(6)));
}


RING_FUNC(ring_al_open_native_text_log)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_open_native_text_log(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)),"ALLEGRO_TEXTLOG");
}


RING_FUNC(ring_al_close_native_text_log)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_close_native_text_log((ALLEGRO_TEXTLOG *) RING_API_GETCPOINTER(1,"ALLEGRO_TEXTLOG"));
}


RING_FUNC(ring_al_get_native_text_log_event_source)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_get_native_text_log_event_source((ALLEGRO_TEXTLOG *) RING_API_GETCPOINTER(1,"ALLEGRO_TEXTLOG")),"ALLEGRO_EVENT_SOURCE");
}


RING_FUNC(ring_al_get_allegro_native_dialog_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_native_dialog_version());
}


RING_FUNC(ring_al_set_physfs_file_interface)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_set_physfs_file_interface();
}


RING_FUNC(ring_al_get_allegro_physfs_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_physfs_version());
}


RING_FUNC(ring_al_get_allegro_primitives_version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_get_allegro_primitives_version());
}


RING_FUNC(ring_al_init_primitives_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(al_init_primitives_addon());
}


RING_FUNC(ring_al_shutdown_primitives_addon)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	al_shutdown_primitives_addon();
}


RING_FUNC(ring_al_draw_line)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_line( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(6));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_triangle)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_triangle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(8));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_filled_triangle)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_draw_filled_triangle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_rectangle)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_rectangle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(6));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_filled_rectangle)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_filled_rectangle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_rounded_rectangle)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_rounded_rectangle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(8));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_filled_rounded_rectangle)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_draw_filled_rounded_rectangle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_calculate_arc)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(10) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_calculate_arc((float *) RING_API_GETCPOINTER(1,"float"), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6), (float ) RING_API_GETNUMBER(7), (float ) RING_API_GETNUMBER(8), (float ) RING_API_GETNUMBER(9), (int ) RING_API_GETNUMBER(10));
}


RING_FUNC(ring_al_draw_pieslice)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_draw_pieslice( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(7));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_filled_pieslice)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_filled_pieslice( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_ellipse)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_ellipse( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(6));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_filled_ellipse)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_filled_ellipse( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_circle)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_circle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(4,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_filled_circle)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	al_draw_filled_circle( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(4,"ALLEGRO_COLOR"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_arc)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	al_draw_arc( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(7));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		RING_API_FREE(RING_API_GETCPOINTER(6,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_elliptical_arc)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_elliptical_arc( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(8));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_calculate_ribbon)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
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
	al_calculate_ribbon((float *) RING_API_GETCPOINTER(1,"float"), (int ) RING_API_GETNUMBER(2),(float *) RING_API_GETCPOINTER(3,"float"), (int ) RING_API_GETNUMBER(4), (float ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_al_draw_ribbon)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_draw_ribbon((float *) RING_API_GETCPOINTER(1,"float"), (int ) RING_API_GETNUMBER(2),* (ALLEGRO_COLOR  *) RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"), (float ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"ALLEGRO_COLOR"));
}


RING_FUNC(ring_al_draw_prim)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_draw_prim((void *) RING_API_GETCPOINTER(1,"void"),(ALLEGRO_VERTEX_DECL *) RING_API_GETCPOINTER(2,"ALLEGRO_VERTEX_DECL"),(ALLEGRO_BITMAP *) RING_API_GETCPOINTER(3,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6)));
}


RING_FUNC(ring_al_draw_indexed_prim)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
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
	RING_API_RETNUMBER(al_draw_indexed_prim((void *) RING_API_GETCPOINTER(1,"void"),(ALLEGRO_VERTEX_DECL *) RING_API_GETCPOINTER(2,"ALLEGRO_VERTEX_DECL"),(ALLEGRO_BITMAP *) RING_API_GETCPOINTER(3,"ALLEGRO_BITMAP"),RING_API_GETINTPOINTER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6)));
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_al_create_vertex_decl)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETCPOINTER(al_create_vertex_decl((ALLEGRO_VERTEX_ELEMENT *) RING_API_GETCPOINTER(1,"ALLEGRO_VERTEX_ELEMENT"), (int ) RING_API_GETNUMBER(2)),"ALLEGRO_VERTEX_DECL");
}


RING_FUNC(ring_al_destroy_vertex_decl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_vertex_decl((ALLEGRO_VERTEX_DECL *) RING_API_GETCPOINTER(1,"ALLEGRO_VERTEX_DECL"));
}


RING_FUNC(ring_al_create_shader)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(al_create_shader( (ALLEGRO_SHADER_PLATFORM )  (int) RING_API_GETNUMBER(1)),"ALLEGRO_SHADER");
}


RING_FUNC(ring_al_attach_shader_source)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_shader_source((ALLEGRO_SHADER *) RING_API_GETCPOINTER(1,"ALLEGRO_SHADER"), (ALLEGRO_SHADER_TYPE )  (int) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_attach_shader_source_file)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_attach_shader_source_file((ALLEGRO_SHADER *) RING_API_GETCPOINTER(1,"ALLEGRO_SHADER"), (ALLEGRO_SHADER_TYPE )  (int) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)));
}


RING_FUNC(ring_al_build_shader)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_build_shader((ALLEGRO_SHADER *) RING_API_GETCPOINTER(1,"ALLEGRO_SHADER")));
}


RING_FUNC(ring_al_get_shader_log)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(al_get_shader_log((ALLEGRO_SHADER *) RING_API_GETCPOINTER(1,"ALLEGRO_SHADER")));
}


RING_FUNC(ring_al_get_shader_platform)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_get_shader_platform((ALLEGRO_SHADER *) RING_API_GETCPOINTER(1,"ALLEGRO_SHADER")));
}


RING_FUNC(ring_al_use_shader)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_use_shader((ALLEGRO_SHADER *) RING_API_GETCPOINTER(1,"ALLEGRO_SHADER")));
}


RING_FUNC(ring_al_destroy_shader)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	al_destroy_shader((ALLEGRO_SHADER *) RING_API_GETCPOINTER(1,"ALLEGRO_SHADER"));
}


RING_FUNC(ring_al_set_shader_sampler)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_shader_sampler(RING_API_GETSTRING(1),(ALLEGRO_BITMAP *) RING_API_GETCPOINTER(2,"ALLEGRO_BITMAP"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_al_set_shader_matrix)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_shader_matrix(RING_API_GETSTRING(1),(ALLEGRO_TRANSFORM *) RING_API_GETCPOINTER(2,"ALLEGRO_TRANSFORM")));
}


RING_FUNC(ring_al_set_shader_int)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_shader_int(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_set_shader_float)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_shader_float(RING_API_GETSTRING(1), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_set_shader_bool)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_shader_bool(RING_API_GETSTRING(1), (bool ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_al_set_shader_int_vector)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
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
	RING_API_RETNUMBER(al_set_shader_int_vector(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3), (int ) RING_API_GETNUMBER(4)));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_al_set_shader_float_vector)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(al_set_shader_float_vector(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),(float *) RING_API_GETCPOINTER(3,"float"), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_al_get_default_shader_source)
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
	RING_API_RETSTRING(al_get_default_shader_source( (ALLEGRO_SHADER_PLATFORM )  (int) RING_API_GETNUMBER(1), (ALLEGRO_SHADER_TYPE )  (int) RING_API_GETNUMBER(2)));
}

RING_LIBINIT
{
	RING_API_REGISTER("al_exit",ring_al_exit);
	RING_API_REGISTER("al_run_main",ring_al_run_main);
	RING_API_REGISTER("al_init",ring_al_init);
	RING_API_REGISTER("al_create_config",ring_al_create_config);
	RING_API_REGISTER("al_destroy_config",ring_al_destroy_config);
	RING_API_REGISTER("al_load_config_file",ring_al_load_config_file);
	RING_API_REGISTER("al_load_config_file_f",ring_al_load_config_file_f);
	RING_API_REGISTER("al_save_config_file",ring_al_save_config_file);
	RING_API_REGISTER("al_save_config_file_f",ring_al_save_config_file_f);
	RING_API_REGISTER("al_add_config_section",ring_al_add_config_section);
	RING_API_REGISTER("al_add_config_comment",ring_al_add_config_comment);
	RING_API_REGISTER("al_get_config_value",ring_al_get_config_value);
	RING_API_REGISTER("al_set_config_value",ring_al_set_config_value);
	RING_API_REGISTER("al_get_first_config_section",ring_al_get_first_config_section);
	RING_API_REGISTER("al_get_next_config_section",ring_al_get_next_config_section);
	RING_API_REGISTER("al_get_first_config_entry",ring_al_get_first_config_entry);
	RING_API_REGISTER("al_get_next_config_entry",ring_al_get_next_config_entry);
	RING_API_REGISTER("al_merge_config",ring_al_merge_config);
	RING_API_REGISTER("al_merge_config_into",ring_al_merge_config_into);
	RING_API_REGISTER("al_create_display",ring_al_create_display);
	RING_API_REGISTER("al_destroy_display",ring_al_destroy_display);
	RING_API_REGISTER("al_get_new_display_flags",ring_al_get_new_display_flags);
	RING_API_REGISTER("al_set_new_display_flags",ring_al_set_new_display_flags);
	RING_API_REGISTER("al_get_new_display_option",ring_al_get_new_display_option);
	RING_API_REGISTER("al_set_new_display_option",ring_al_set_new_display_option);
	RING_API_REGISTER("al_reset_new_display_options",ring_al_reset_new_display_options);
	RING_API_REGISTER("al_get_new_window_position",ring_al_get_new_window_position);
	RING_API_REGISTER("al_set_new_window_position",ring_al_set_new_window_position);
	RING_API_REGISTER("al_get_new_display_refresh_rate",ring_al_get_new_display_refresh_rate);
	RING_API_REGISTER("al_set_new_display_refresh_rate",ring_al_set_new_display_refresh_rate);
	RING_API_REGISTER("al_get_display_event_source",ring_al_get_display_event_source);
	RING_API_REGISTER("al_get_backbuffer",ring_al_get_backbuffer);
	RING_API_REGISTER("al_flip_display",ring_al_flip_display);
	RING_API_REGISTER("al_update_display_region",ring_al_update_display_region);
	RING_API_REGISTER("al_wait_for_vsync",ring_al_wait_for_vsync);
	RING_API_REGISTER("al_get_display_width",ring_al_get_display_width);
	RING_API_REGISTER("al_get_display_height",ring_al_get_display_height);
	RING_API_REGISTER("al_resize_display",ring_al_resize_display);
	RING_API_REGISTER("al_acknowledge_resize",ring_al_acknowledge_resize);
	RING_API_REGISTER("al_get_window_position",ring_al_get_window_position);
	RING_API_REGISTER("al_set_window_position",ring_al_set_window_position);
	RING_API_REGISTER("al_get_display_flags",ring_al_get_display_flags);
	RING_API_REGISTER("al_set_display_flag",ring_al_set_display_flag);
	RING_API_REGISTER("al_get_display_option",ring_al_get_display_option);
	RING_API_REGISTER("al_get_display_format",ring_al_get_display_format);
	RING_API_REGISTER("al_get_display_refresh_rate",ring_al_get_display_refresh_rate);
	RING_API_REGISTER("al_set_window_title",ring_al_set_window_title);
	RING_API_REGISTER("al_set_display_icon",ring_al_set_display_icon);
	RING_API_REGISTER("al_set_display_icons",ring_al_set_display_icons);
	RING_API_REGISTER("al_inhibit_screensaver",ring_al_inhibit_screensaver);
	RING_API_REGISTER("al_acknowledge_drawing_halt",ring_al_acknowledge_drawing_halt);
	RING_API_REGISTER("al_acknowledge_drawing_resume",ring_al_acknowledge_drawing_resume);
	RING_API_REGISTER("al_get_display_orientation",ring_al_get_display_orientation);
	RING_API_REGISTER("al_set_display_option",ring_al_set_display_option);
	RING_API_REGISTER("al_get_window_constraints",ring_al_get_window_constraints);
	RING_API_REGISTER("al_set_window_constraints",ring_al_set_window_constraints);
	RING_API_REGISTER("al_create_event_queue",ring_al_create_event_queue);
	RING_API_REGISTER("al_destroy_event_queue",ring_al_destroy_event_queue);
	RING_API_REGISTER("al_register_event_source",ring_al_register_event_source);
	RING_API_REGISTER("al_unregister_event_source",ring_al_unregister_event_source);
	RING_API_REGISTER("al_is_event_queue_empty",ring_al_is_event_queue_empty);
	RING_API_REGISTER("al_get_next_event",ring_al_get_next_event);
	RING_API_REGISTER("al_peek_next_event",ring_al_peek_next_event);
	RING_API_REGISTER("al_drop_next_event",ring_al_drop_next_event);
	RING_API_REGISTER("al_flush_event_queue",ring_al_flush_event_queue);
	RING_API_REGISTER("al_wait_for_event",ring_al_wait_for_event);
	RING_API_REGISTER("al_wait_for_event_timed",ring_al_wait_for_event_timed);
	RING_API_REGISTER("al_wait_for_event_until",ring_al_wait_for_event_until);
	RING_API_REGISTER("al_init_user_event_source",ring_al_init_user_event_source);
	RING_API_REGISTER("al_destroy_user_event_source",ring_al_destroy_user_event_source);
	RING_API_REGISTER("al_unref_user_event",ring_al_unref_user_event);
	RING_API_REGISTER("al_get_event_source_data",ring_al_get_event_source_data);
	RING_API_REGISTER("al_set_event_source_data",ring_al_set_event_source_data);
	RING_API_REGISTER("al_fopen",ring_al_fopen);
	RING_API_REGISTER("al_fopen_interface",ring_al_fopen_interface);
	RING_API_REGISTER("al_fopen_slice",ring_al_fopen_slice);
	RING_API_REGISTER("al_fclose",ring_al_fclose);
	RING_API_REGISTER("al_fread",ring_al_fread);
	RING_API_REGISTER("al_fwrite",ring_al_fwrite);
	RING_API_REGISTER("al_fflush",ring_al_fflush);
	RING_API_REGISTER("al_ftell",ring_al_ftell);
	RING_API_REGISTER("al_fseek",ring_al_fseek);
	RING_API_REGISTER("al_feof",ring_al_feof);
	RING_API_REGISTER("al_ferror",ring_al_ferror);
	RING_API_REGISTER("al_fclearerr",ring_al_fclearerr);
	RING_API_REGISTER("al_fungetc",ring_al_fungetc);
	RING_API_REGISTER("al_fsize",ring_al_fsize);
	RING_API_REGISTER("al_fgetc",ring_al_fgetc);
	RING_API_REGISTER("al_fputc",ring_al_fputc);
	RING_API_REGISTER("al_fread16le",ring_al_fread16le);
	RING_API_REGISTER("al_fread16be",ring_al_fread16be);
	RING_API_REGISTER("al_fwrite16le",ring_al_fwrite16le);
	RING_API_REGISTER("al_fwrite16be",ring_al_fwrite16be);
	RING_API_REGISTER("al_fread32le",ring_al_fread32le);
	RING_API_REGISTER("al_fread32be",ring_al_fread32be);
	RING_API_REGISTER("al_fwrite32le",ring_al_fwrite32le);
	RING_API_REGISTER("al_fwrite32be",ring_al_fwrite32be);
	RING_API_REGISTER("al_fgets",ring_al_fgets);
	RING_API_REGISTER("al_fget_ustr",ring_al_fget_ustr);
	RING_API_REGISTER("al_fputs",ring_al_fputs);
	RING_API_REGISTER("al_fopen_fd",ring_al_fopen_fd);
	RING_API_REGISTER("al_make_temp_file",ring_al_make_temp_file);
	RING_API_REGISTER("al_set_new_file_interface",ring_al_set_new_file_interface);
	RING_API_REGISTER("al_set_standard_file_interface",ring_al_set_standard_file_interface);
	RING_API_REGISTER("al_get_new_file_interface",ring_al_get_new_file_interface);
	RING_API_REGISTER("al_create_file_handle",ring_al_create_file_handle);
	RING_API_REGISTER("al_get_file_userdata",ring_al_get_file_userdata);
	RING_API_REGISTER("al_create_fs_entry",ring_al_create_fs_entry);
	RING_API_REGISTER("al_destroy_fs_entry",ring_al_destroy_fs_entry);
	RING_API_REGISTER("al_get_fs_entry_name",ring_al_get_fs_entry_name);
	RING_API_REGISTER("al_update_fs_entry",ring_al_update_fs_entry);
	RING_API_REGISTER("al_get_fs_entry_mode",ring_al_get_fs_entry_mode);
	RING_API_REGISTER("al_get_fs_entry_atime",ring_al_get_fs_entry_atime);
	RING_API_REGISTER("al_get_fs_entry_ctime",ring_al_get_fs_entry_ctime);
	RING_API_REGISTER("al_get_fs_entry_mtime",ring_al_get_fs_entry_mtime);
	RING_API_REGISTER("al_get_fs_entry_size",ring_al_get_fs_entry_size);
	RING_API_REGISTER("al_fs_entry_exists",ring_al_fs_entry_exists);
	RING_API_REGISTER("al_remove_fs_entry",ring_al_remove_fs_entry);
	RING_API_REGISTER("al_filename_exists",ring_al_filename_exists);
	RING_API_REGISTER("al_remove_filename",ring_al_remove_filename);
	RING_API_REGISTER("al_open_directory",ring_al_open_directory);
	RING_API_REGISTER("al_read_directory",ring_al_read_directory);
	RING_API_REGISTER("al_close_directory",ring_al_close_directory);
	RING_API_REGISTER("al_get_current_directory",ring_al_get_current_directory);
	RING_API_REGISTER("al_change_directory",ring_al_change_directory);
	RING_API_REGISTER("al_make_directory",ring_al_make_directory);
	RING_API_REGISTER("al_open_fs_entry",ring_al_open_fs_entry);
	RING_API_REGISTER("al_set_fs_interface",ring_al_set_fs_interface);
	RING_API_REGISTER("al_set_standard_fs_interface",ring_al_set_standard_fs_interface);
	RING_API_REGISTER("al_get_fs_interface",ring_al_get_fs_interface);
	RING_API_REGISTER("al_itofix",ring_al_itofix);
	RING_API_REGISTER("al_fixtoi",ring_al_fixtoi);
	RING_API_REGISTER("al_fixfloor",ring_al_fixfloor);
	RING_API_REGISTER("al_fixceil",ring_al_fixceil);
	RING_API_REGISTER("al_ftofix",ring_al_ftofix);
	RING_API_REGISTER("al_fixtof",ring_al_fixtof);
	RING_API_REGISTER("al_fixmul",ring_al_fixmul);
	RING_API_REGISTER("al_fixdiv",ring_al_fixdiv);
	RING_API_REGISTER("al_fixadd",ring_al_fixadd);
	RING_API_REGISTER("al_fixsub",ring_al_fixsub);
	RING_API_REGISTER("al_fixsin",ring_al_fixsin);
	RING_API_REGISTER("al_fixcos",ring_al_fixcos);
	RING_API_REGISTER("al_fixtan",ring_al_fixtan);
	RING_API_REGISTER("al_fixasin",ring_al_fixasin);
	RING_API_REGISTER("al_fixacos",ring_al_fixacos);
	RING_API_REGISTER("al_fixatan",ring_al_fixatan);
	RING_API_REGISTER("al_fixatan2",ring_al_fixatan2);
	RING_API_REGISTER("al_fixsqrt",ring_al_fixsqrt);
	RING_API_REGISTER("al_fixhypot",ring_al_fixhypot);
	RING_API_REGISTER("al_get_display_mode",ring_al_get_display_mode);
	RING_API_REGISTER("al_get_num_display_modes",ring_al_get_num_display_modes);
	RING_API_REGISTER("al_map_rgb",ring_al_map_rgb);
	RING_API_REGISTER("al_map_rgb_f",ring_al_map_rgb_f);
	RING_API_REGISTER("al_map_rgba",ring_al_map_rgba);
	RING_API_REGISTER("al_map_rgba_f",ring_al_map_rgba_f);
	RING_API_REGISTER("al_unmap_rgb",ring_al_unmap_rgb);
	RING_API_REGISTER("al_unmap_rgb_f",ring_al_unmap_rgb_f);
	RING_API_REGISTER("al_unmap_rgba",ring_al_unmap_rgba);
	RING_API_REGISTER("al_unmap_rgba_f",ring_al_unmap_rgba_f);
	RING_API_REGISTER("al_get_pixel_size",ring_al_get_pixel_size);
	RING_API_REGISTER("al_get_pixel_format_bits",ring_al_get_pixel_format_bits);
	RING_API_REGISTER("al_lock_bitmap",ring_al_lock_bitmap);
	RING_API_REGISTER("al_lock_bitmap_region",ring_al_lock_bitmap_region);
	RING_API_REGISTER("al_unlock_bitmap",ring_al_unlock_bitmap);
	RING_API_REGISTER("al_create_bitmap",ring_al_create_bitmap);
	RING_API_REGISTER("al_create_sub_bitmap",ring_al_create_sub_bitmap);
	RING_API_REGISTER("al_clone_bitmap",ring_al_clone_bitmap);
	RING_API_REGISTER("al_destroy_bitmap",ring_al_destroy_bitmap);
	RING_API_REGISTER("al_get_new_bitmap_flags",ring_al_get_new_bitmap_flags);
	RING_API_REGISTER("al_get_new_bitmap_format",ring_al_get_new_bitmap_format);
	RING_API_REGISTER("al_set_new_bitmap_flags",ring_al_set_new_bitmap_flags);
	RING_API_REGISTER("al_add_new_bitmap_flag",ring_al_add_new_bitmap_flag);
	RING_API_REGISTER("al_set_new_bitmap_format",ring_al_set_new_bitmap_format);
	RING_API_REGISTER("al_get_bitmap_flags",ring_al_get_bitmap_flags);
	RING_API_REGISTER("al_get_bitmap_format",ring_al_get_bitmap_format);
	RING_API_REGISTER("al_get_bitmap_height",ring_al_get_bitmap_height);
	RING_API_REGISTER("al_get_bitmap_width",ring_al_get_bitmap_width);
	RING_API_REGISTER("al_get_pixel",ring_al_get_pixel);
	RING_API_REGISTER("al_is_bitmap_locked",ring_al_is_bitmap_locked);
	RING_API_REGISTER("al_is_compatible_bitmap",ring_al_is_compatible_bitmap);
	RING_API_REGISTER("al_is_sub_bitmap",ring_al_is_sub_bitmap);
	RING_API_REGISTER("al_get_parent_bitmap",ring_al_get_parent_bitmap);
	RING_API_REGISTER("al_clear_to_color",ring_al_clear_to_color);
	RING_API_REGISTER("al_draw_bitmap",ring_al_draw_bitmap);
	RING_API_REGISTER("al_draw_tinted_bitmap",ring_al_draw_tinted_bitmap);
	RING_API_REGISTER("al_draw_bitmap_region",ring_al_draw_bitmap_region);
	RING_API_REGISTER("al_draw_tinted_bitmap_region",ring_al_draw_tinted_bitmap_region);
	RING_API_REGISTER("al_draw_pixel",ring_al_draw_pixel);
	RING_API_REGISTER("al_draw_rotated_bitmap",ring_al_draw_rotated_bitmap);
	RING_API_REGISTER("al_draw_tinted_rotated_bitmap",ring_al_draw_tinted_rotated_bitmap);
	RING_API_REGISTER("al_draw_scaled_rotated_bitmap",ring_al_draw_scaled_rotated_bitmap);
	RING_API_REGISTER("al_draw_tinted_scaled_rotated_bitmap",ring_al_draw_tinted_scaled_rotated_bitmap);
	RING_API_REGISTER("al_draw_tinted_scaled_rotated_bitmap_region",ring_al_draw_tinted_scaled_rotated_bitmap_region);
	RING_API_REGISTER("al_draw_scaled_bitmap",ring_al_draw_scaled_bitmap);
	RING_API_REGISTER("al_draw_tinted_scaled_bitmap",ring_al_draw_tinted_scaled_bitmap);
	RING_API_REGISTER("al_get_target_bitmap",ring_al_get_target_bitmap);
	RING_API_REGISTER("al_put_pixel",ring_al_put_pixel);
	RING_API_REGISTER("al_put_blended_pixel",ring_al_put_blended_pixel);
	RING_API_REGISTER("al_set_target_bitmap",ring_al_set_target_bitmap);
	RING_API_REGISTER("al_set_target_backbuffer",ring_al_set_target_backbuffer);
	RING_API_REGISTER("al_get_current_display",ring_al_get_current_display);
	RING_API_REGISTER("al_get_blender",ring_al_get_blender);
	RING_API_REGISTER("al_get_separate_blender",ring_al_get_separate_blender);
	RING_API_REGISTER("al_set_blender",ring_al_set_blender);
	RING_API_REGISTER("al_set_separate_blender",ring_al_set_separate_blender);
	RING_API_REGISTER("al_get_clipping_rectangle",ring_al_get_clipping_rectangle);
	RING_API_REGISTER("al_set_clipping_rectangle",ring_al_set_clipping_rectangle);
	RING_API_REGISTER("al_reset_clipping_rectangle",ring_al_reset_clipping_rectangle);
	RING_API_REGISTER("al_convert_mask_to_alpha",ring_al_convert_mask_to_alpha);
	RING_API_REGISTER("al_hold_bitmap_drawing",ring_al_hold_bitmap_drawing);
	RING_API_REGISTER("al_is_bitmap_drawing_held",ring_al_is_bitmap_drawing_held);
	RING_API_REGISTER("al_load_bitmap",ring_al_load_bitmap);
	RING_API_REGISTER("al_load_bitmap_f",ring_al_load_bitmap_f);
	RING_API_REGISTER("al_save_bitmap",ring_al_save_bitmap);
	RING_API_REGISTER("al_save_bitmap_f",ring_al_save_bitmap_f);
	RING_API_REGISTER("al_install_joystick",ring_al_install_joystick);
	RING_API_REGISTER("al_uninstall_joystick",ring_al_uninstall_joystick);
	RING_API_REGISTER("al_is_joystick_installed",ring_al_is_joystick_installed);
	RING_API_REGISTER("al_reconfigure_joysticks",ring_al_reconfigure_joysticks);
	RING_API_REGISTER("al_get_num_joysticks",ring_al_get_num_joysticks);
	RING_API_REGISTER("al_get_joystick",ring_al_get_joystick);
	RING_API_REGISTER("al_release_joystick",ring_al_release_joystick);
	RING_API_REGISTER("al_get_joystick_active",ring_al_get_joystick_active);
	RING_API_REGISTER("al_get_joystick_name",ring_al_get_joystick_name);
	RING_API_REGISTER("al_get_joystick_stick_name",ring_al_get_joystick_stick_name);
	RING_API_REGISTER("al_get_joystick_axis_name",ring_al_get_joystick_axis_name);
	RING_API_REGISTER("al_get_joystick_button_name",ring_al_get_joystick_button_name);
	RING_API_REGISTER("al_get_joystick_stick_flags",ring_al_get_joystick_stick_flags);
	RING_API_REGISTER("al_get_joystick_num_sticks",ring_al_get_joystick_num_sticks);
	RING_API_REGISTER("al_get_joystick_num_axes",ring_al_get_joystick_num_axes);
	RING_API_REGISTER("al_get_joystick_num_buttons",ring_al_get_joystick_num_buttons);
	RING_API_REGISTER("al_get_joystick_state",ring_al_get_joystick_state);
	RING_API_REGISTER("al_get_joystick_event_source",ring_al_get_joystick_event_source);
	RING_API_REGISTER("al_install_keyboard",ring_al_install_keyboard);
	RING_API_REGISTER("al_is_keyboard_installed",ring_al_is_keyboard_installed);
	RING_API_REGISTER("al_uninstall_keyboard",ring_al_uninstall_keyboard);
	RING_API_REGISTER("al_get_keyboard_state",ring_al_get_keyboard_state);
	RING_API_REGISTER("al_key_down",ring_al_key_down);
	RING_API_REGISTER("al_keycode_to_name",ring_al_keycode_to_name);
	RING_API_REGISTER("al_set_keyboard_leds",ring_al_set_keyboard_leds);
	RING_API_REGISTER("al_get_keyboard_event_source",ring_al_get_keyboard_event_source);
	RING_API_REGISTER("al_malloc_with_context",ring_al_malloc_with_context);
	RING_API_REGISTER("al_free_with_context",ring_al_free_with_context);
	RING_API_REGISTER("al_realloc_with_context",ring_al_realloc_with_context);
	RING_API_REGISTER("al_calloc_with_context",ring_al_calloc_with_context);
	RING_API_REGISTER("al_set_memory_interface",ring_al_set_memory_interface);
	RING_API_REGISTER("al_get_new_display_adapter",ring_al_get_new_display_adapter);
	RING_API_REGISTER("al_set_new_display_adapter",ring_al_set_new_display_adapter);
	RING_API_REGISTER("al_get_monitor_info",ring_al_get_monitor_info);
	RING_API_REGISTER("al_get_num_video_adapters",ring_al_get_num_video_adapters);
	RING_API_REGISTER("al_install_mouse",ring_al_install_mouse);
	RING_API_REGISTER("al_is_mouse_installed",ring_al_is_mouse_installed);
	RING_API_REGISTER("al_uninstall_mouse",ring_al_uninstall_mouse);
	RING_API_REGISTER("al_get_mouse_num_axes",ring_al_get_mouse_num_axes);
	RING_API_REGISTER("al_get_mouse_num_buttons",ring_al_get_mouse_num_buttons);
	RING_API_REGISTER("al_get_mouse_state",ring_al_get_mouse_state);
	RING_API_REGISTER("al_get_mouse_state_axis",ring_al_get_mouse_state_axis);
	RING_API_REGISTER("al_mouse_button_down",ring_al_mouse_button_down);
	RING_API_REGISTER("al_set_mouse_xy",ring_al_set_mouse_xy);
	RING_API_REGISTER("al_set_mouse_z",ring_al_set_mouse_z);
	RING_API_REGISTER("al_set_mouse_w",ring_al_set_mouse_w);
	RING_API_REGISTER("al_set_mouse_axis",ring_al_set_mouse_axis);
	RING_API_REGISTER("al_get_mouse_event_source",ring_al_get_mouse_event_source);
	RING_API_REGISTER("al_create_mouse_cursor",ring_al_create_mouse_cursor);
	RING_API_REGISTER("al_destroy_mouse_cursor",ring_al_destroy_mouse_cursor);
	RING_API_REGISTER("al_set_mouse_cursor",ring_al_set_mouse_cursor);
	RING_API_REGISTER("al_set_system_mouse_cursor",ring_al_set_system_mouse_cursor);
	RING_API_REGISTER("al_get_mouse_cursor_position",ring_al_get_mouse_cursor_position);
	RING_API_REGISTER("al_hide_mouse_cursor",ring_al_hide_mouse_cursor);
	RING_API_REGISTER("al_show_mouse_cursor",ring_al_show_mouse_cursor);
	RING_API_REGISTER("al_grab_mouse",ring_al_grab_mouse);
	RING_API_REGISTER("al_ungrab_mouse",ring_al_ungrab_mouse);
	RING_API_REGISTER("al_create_path",ring_al_create_path);
	RING_API_REGISTER("al_create_path_for_directory",ring_al_create_path_for_directory);
	RING_API_REGISTER("al_destroy_path",ring_al_destroy_path);
	RING_API_REGISTER("al_clone_path",ring_al_clone_path);
	RING_API_REGISTER("al_join_paths",ring_al_join_paths);
	RING_API_REGISTER("al_rebase_path",ring_al_rebase_path);
	RING_API_REGISTER("al_get_path_drive",ring_al_get_path_drive);
	RING_API_REGISTER("al_get_path_num_components",ring_al_get_path_num_components);
	RING_API_REGISTER("al_get_path_component",ring_al_get_path_component);
	RING_API_REGISTER("al_get_path_tail",ring_al_get_path_tail);
	RING_API_REGISTER("al_get_path_filename",ring_al_get_path_filename);
	RING_API_REGISTER("al_get_path_basename",ring_al_get_path_basename);
	RING_API_REGISTER("al_get_path_extension",ring_al_get_path_extension);
	RING_API_REGISTER("al_set_path_drive",ring_al_set_path_drive);
	RING_API_REGISTER("al_append_path_component",ring_al_append_path_component);
	RING_API_REGISTER("al_insert_path_component",ring_al_insert_path_component);
	RING_API_REGISTER("al_replace_path_component",ring_al_replace_path_component);
	RING_API_REGISTER("al_remove_path_component",ring_al_remove_path_component);
	RING_API_REGISTER("al_drop_path_tail",ring_al_drop_path_tail);
	RING_API_REGISTER("al_set_path_filename",ring_al_set_path_filename);
	RING_API_REGISTER("al_set_path_extension",ring_al_set_path_extension);
	RING_API_REGISTER("al_path_cstr",ring_al_path_cstr);
	RING_API_REGISTER("al_make_path_canonical",ring_al_make_path_canonical);
	RING_API_REGISTER("al_restore_state",ring_al_restore_state);
	RING_API_REGISTER("al_store_state",ring_al_store_state);
	RING_API_REGISTER("al_get_errno",ring_al_get_errno);
	RING_API_REGISTER("al_set_errno",ring_al_set_errno);
	RING_API_REGISTER("al_uninstall_system",ring_al_uninstall_system);
	RING_API_REGISTER("al_is_system_installed",ring_al_is_system_installed);
	RING_API_REGISTER("al_get_allegro_version",ring_al_get_allegro_version);
	RING_API_REGISTER("al_get_standard_path",ring_al_get_standard_path);
	RING_API_REGISTER("al_set_exe_name",ring_al_set_exe_name);
	RING_API_REGISTER("al_set_app_name",ring_al_set_app_name);
	RING_API_REGISTER("al_set_org_name",ring_al_set_org_name);
	RING_API_REGISTER("al_get_app_name",ring_al_get_app_name);
	RING_API_REGISTER("al_get_org_name",ring_al_get_org_name);
	RING_API_REGISTER("al_get_system_config",ring_al_get_system_config);
	RING_API_REGISTER("al_create_thread",ring_al_create_thread);
	RING_API_REGISTER("al_run_detached_thread",ring_al_run_detached_thread);
	RING_API_REGISTER("al_start_thread",ring_al_start_thread);
	RING_API_REGISTER("al_join_thread",ring_al_join_thread);
	RING_API_REGISTER("al_set_thread_should_stop",ring_al_set_thread_should_stop);
	RING_API_REGISTER("al_get_thread_should_stop",ring_al_get_thread_should_stop);
	RING_API_REGISTER("al_destroy_thread",ring_al_destroy_thread);
	RING_API_REGISTER("al_create_mutex",ring_al_create_mutex);
	RING_API_REGISTER("al_create_mutex_recursive",ring_al_create_mutex_recursive);
	RING_API_REGISTER("al_lock_mutex",ring_al_lock_mutex);
	RING_API_REGISTER("al_unlock_mutex",ring_al_unlock_mutex);
	RING_API_REGISTER("al_destroy_mutex",ring_al_destroy_mutex);
	RING_API_REGISTER("al_create_cond",ring_al_create_cond);
	RING_API_REGISTER("al_destroy_cond",ring_al_destroy_cond);
	RING_API_REGISTER("al_wait_cond",ring_al_wait_cond);
	RING_API_REGISTER("al_wait_cond_until",ring_al_wait_cond_until);
	RING_API_REGISTER("al_broadcast_cond",ring_al_broadcast_cond);
	RING_API_REGISTER("al_signal_cond",ring_al_signal_cond);
	RING_API_REGISTER("al_get_time",ring_al_get_time);
	RING_API_REGISTER("al_init_timeout",ring_al_init_timeout);
	RING_API_REGISTER("al_rest",ring_al_rest);
	RING_API_REGISTER("al_create_timer",ring_al_create_timer);
	RING_API_REGISTER("al_start_timer",ring_al_start_timer);
	RING_API_REGISTER("al_stop_timer",ring_al_stop_timer);
	RING_API_REGISTER("al_get_timer_started",ring_al_get_timer_started);
	RING_API_REGISTER("al_destroy_timer",ring_al_destroy_timer);
	RING_API_REGISTER("al_get_timer_count",ring_al_get_timer_count);
	RING_API_REGISTER("al_set_timer_count",ring_al_set_timer_count);
	RING_API_REGISTER("al_add_timer_count",ring_al_add_timer_count);
	RING_API_REGISTER("al_get_timer_speed",ring_al_get_timer_speed);
	RING_API_REGISTER("al_set_timer_speed",ring_al_set_timer_speed);
	RING_API_REGISTER("al_get_timer_event_source",ring_al_get_timer_event_source);
	RING_API_REGISTER("al_copy_transform",ring_al_copy_transform);
	RING_API_REGISTER("al_use_transform",ring_al_use_transform);
	RING_API_REGISTER("al_get_current_transform",ring_al_get_current_transform);
	RING_API_REGISTER("al_invert_transform",ring_al_invert_transform);
	RING_API_REGISTER("al_check_inverse",ring_al_check_inverse);
	RING_API_REGISTER("al_identity_transform",ring_al_identity_transform);
	RING_API_REGISTER("al_build_transform",ring_al_build_transform);
	RING_API_REGISTER("al_translate_transform",ring_al_translate_transform);
	RING_API_REGISTER("al_rotate_transform",ring_al_rotate_transform);
	RING_API_REGISTER("al_scale_transform",ring_al_scale_transform);
	RING_API_REGISTER("al_transform_coordinates",ring_al_transform_coordinates);
	RING_API_REGISTER("al_compose_transform",ring_al_compose_transform);
	RING_API_REGISTER("al_ustr_new",ring_al_ustr_new);
	RING_API_REGISTER("al_ustr_new_from_buffer",ring_al_ustr_new_from_buffer);
	RING_API_REGISTER("al_ustr_free",ring_al_ustr_free);
	RING_API_REGISTER("al_cstr",ring_al_cstr);
	RING_API_REGISTER("al_ustr_to_buffer",ring_al_ustr_to_buffer);
	RING_API_REGISTER("al_cstr_dup",ring_al_cstr_dup);
	RING_API_REGISTER("al_ustr_dup",ring_al_ustr_dup);
	RING_API_REGISTER("al_ustr_dup_substr",ring_al_ustr_dup_substr);
	RING_API_REGISTER("al_ustr_empty_string",ring_al_ustr_empty_string);
	RING_API_REGISTER("al_ref_cstr",ring_al_ref_cstr);
	RING_API_REGISTER("al_ref_buffer",ring_al_ref_buffer);
	RING_API_REGISTER("al_ref_ustr",ring_al_ref_ustr);
	RING_API_REGISTER("al_ustr_size",ring_al_ustr_size);
	RING_API_REGISTER("al_ustr_length",ring_al_ustr_length);
	RING_API_REGISTER("al_ustr_offset",ring_al_ustr_offset);
	RING_API_REGISTER("al_ustr_next",ring_al_ustr_next);
	RING_API_REGISTER("al_ustr_prev",ring_al_ustr_prev);
	RING_API_REGISTER("al_ustr_get",ring_al_ustr_get);
	RING_API_REGISTER("al_ustr_get_next",ring_al_ustr_get_next);
	RING_API_REGISTER("al_ustr_prev_get",ring_al_ustr_prev_get);
	RING_API_REGISTER("al_ustr_insert",ring_al_ustr_insert);
	RING_API_REGISTER("al_ustr_insert_cstr",ring_al_ustr_insert_cstr);
	RING_API_REGISTER("al_ustr_insert_chr",ring_al_ustr_insert_chr);
	RING_API_REGISTER("al_ustr_append",ring_al_ustr_append);
	RING_API_REGISTER("al_ustr_append_cstr",ring_al_ustr_append_cstr);
	RING_API_REGISTER("al_ustr_append_chr",ring_al_ustr_append_chr);
	RING_API_REGISTER("al_ustr_vappendf",ring_al_ustr_vappendf);
	RING_API_REGISTER("al_ustr_remove_chr",ring_al_ustr_remove_chr);
	RING_API_REGISTER("al_ustr_remove_range",ring_al_ustr_remove_range);
	RING_API_REGISTER("al_ustr_truncate",ring_al_ustr_truncate);
	RING_API_REGISTER("al_ustr_ltrim_ws",ring_al_ustr_ltrim_ws);
	RING_API_REGISTER("al_ustr_rtrim_ws",ring_al_ustr_rtrim_ws);
	RING_API_REGISTER("al_ustr_trim_ws",ring_al_ustr_trim_ws);
	RING_API_REGISTER("al_ustr_assign",ring_al_ustr_assign);
	RING_API_REGISTER("al_ustr_assign_substr",ring_al_ustr_assign_substr);
	RING_API_REGISTER("al_ustr_assign_cstr",ring_al_ustr_assign_cstr);
	RING_API_REGISTER("al_ustr_set_chr",ring_al_ustr_set_chr);
	RING_API_REGISTER("al_ustr_replace_range",ring_al_ustr_replace_range);
	RING_API_REGISTER("al_ustr_find_chr",ring_al_ustr_find_chr);
	RING_API_REGISTER("al_ustr_rfind_chr",ring_al_ustr_rfind_chr);
	RING_API_REGISTER("al_ustr_find_set",ring_al_ustr_find_set);
	RING_API_REGISTER("al_ustr_find_set_cstr",ring_al_ustr_find_set_cstr);
	RING_API_REGISTER("al_ustr_find_cset",ring_al_ustr_find_cset);
	RING_API_REGISTER("al_ustr_find_cset_cstr",ring_al_ustr_find_cset_cstr);
	RING_API_REGISTER("al_ustr_find_str",ring_al_ustr_find_str);
	RING_API_REGISTER("al_ustr_find_cstr",ring_al_ustr_find_cstr);
	RING_API_REGISTER("al_ustr_rfind_str",ring_al_ustr_rfind_str);
	RING_API_REGISTER("al_ustr_rfind_cstr",ring_al_ustr_rfind_cstr);
	RING_API_REGISTER("al_ustr_find_replace",ring_al_ustr_find_replace);
	RING_API_REGISTER("al_ustr_find_replace_cstr",ring_al_ustr_find_replace_cstr);
	RING_API_REGISTER("al_ustr_compare",ring_al_ustr_compare);
	RING_API_REGISTER("al_ustr_ncompare",ring_al_ustr_ncompare);
	RING_API_REGISTER("al_ustr_equal",ring_al_ustr_equal);
	RING_API_REGISTER("al_ustr_has_prefix",ring_al_ustr_has_prefix);
	RING_API_REGISTER("al_ustr_has_prefix_cstr",ring_al_ustr_has_prefix_cstr);
	RING_API_REGISTER("al_ustr_has_suffix",ring_al_ustr_has_suffix);
	RING_API_REGISTER("al_ustr_has_suffix_cstr",ring_al_ustr_has_suffix_cstr);
	RING_API_REGISTER("al_ustr_new_from_utf16",ring_al_ustr_new_from_utf16);
	RING_API_REGISTER("al_ustr_size_utf16",ring_al_ustr_size_utf16);
	RING_API_REGISTER("al_ustr_encode_utf16",ring_al_ustr_encode_utf16);
	RING_API_REGISTER("al_utf8_width",ring_al_utf8_width);
	RING_API_REGISTER("al_utf8_encode",ring_al_utf8_encode);
	RING_API_REGISTER("al_utf16_width",ring_al_utf16_width);
	RING_API_REGISTER("al_get_d3d_device",ring_al_get_d3d_device);
	RING_API_REGISTER("al_get_d3d_system_texture",ring_al_get_d3d_system_texture);
	RING_API_REGISTER("al_get_d3d_video_texture",ring_al_get_d3d_video_texture);
	RING_API_REGISTER("al_have_d3d_non_pow2_texture_support",ring_al_have_d3d_non_pow2_texture_support);
	RING_API_REGISTER("al_have_d3d_non_square_texture_support",ring_al_have_d3d_non_square_texture_support);
	RING_API_REGISTER("al_get_d3d_texture_position",ring_al_get_d3d_texture_position);
	RING_API_REGISTER("al_is_d3d_device_lost",ring_al_is_d3d_device_lost);
	RING_API_REGISTER("al_get_opengl_extension_list",ring_al_get_opengl_extension_list);
	RING_API_REGISTER("al_get_opengl_proc_address",ring_al_get_opengl_proc_address);
	RING_API_REGISTER("al_get_opengl_texture",ring_al_get_opengl_texture);
	RING_API_REGISTER("al_get_opengl_texture_size",ring_al_get_opengl_texture_size);
	RING_API_REGISTER("al_get_opengl_texture_position",ring_al_get_opengl_texture_position);
	RING_API_REGISTER("al_get_opengl_fbo",ring_al_get_opengl_fbo);
	RING_API_REGISTER("al_remove_opengl_fbo",ring_al_remove_opengl_fbo);
	RING_API_REGISTER("al_have_opengl_extension",ring_al_have_opengl_extension);
	RING_API_REGISTER("al_get_opengl_version",ring_al_get_opengl_version);
	RING_API_REGISTER("al_get_opengl_variant",ring_al_get_opengl_variant);
	RING_API_REGISTER("al_set_current_opengl_context",ring_al_set_current_opengl_context);
	RING_API_REGISTER("al_install_audio",ring_al_install_audio);
	RING_API_REGISTER("al_uninstall_audio",ring_al_uninstall_audio);
	RING_API_REGISTER("al_is_audio_installed",ring_al_is_audio_installed);
	RING_API_REGISTER("al_reserve_samples",ring_al_reserve_samples);
	RING_API_REGISTER("al_get_allegro_audio_version",ring_al_get_allegro_audio_version);
	RING_API_REGISTER("al_get_audio_depth_size",ring_al_get_audio_depth_size);
	RING_API_REGISTER("al_get_channel_count",ring_al_get_channel_count);
	RING_API_REGISTER("al_create_voice",ring_al_create_voice);
	RING_API_REGISTER("al_destroy_voice",ring_al_destroy_voice);
	RING_API_REGISTER("al_detach_voice",ring_al_detach_voice);
	RING_API_REGISTER("al_attach_audio_stream_to_voice",ring_al_attach_audio_stream_to_voice);
	RING_API_REGISTER("al_attach_mixer_to_voice",ring_al_attach_mixer_to_voice);
	RING_API_REGISTER("al_attach_sample_instance_to_voice",ring_al_attach_sample_instance_to_voice);
	RING_API_REGISTER("al_get_voice_frequency",ring_al_get_voice_frequency);
	RING_API_REGISTER("al_get_voice_channels",ring_al_get_voice_channels);
	RING_API_REGISTER("al_get_voice_depth",ring_al_get_voice_depth);
	RING_API_REGISTER("al_get_voice_playing",ring_al_get_voice_playing);
	RING_API_REGISTER("al_set_voice_playing",ring_al_set_voice_playing);
	RING_API_REGISTER("al_get_voice_position",ring_al_get_voice_position);
	RING_API_REGISTER("al_set_voice_position",ring_al_set_voice_position);
	RING_API_REGISTER("al_create_sample",ring_al_create_sample);
	RING_API_REGISTER("al_destroy_sample",ring_al_destroy_sample);
	RING_API_REGISTER("al_play_sample",ring_al_play_sample);
	RING_API_REGISTER("al_stop_sample",ring_al_stop_sample);
	RING_API_REGISTER("al_stop_samples",ring_al_stop_samples);
	RING_API_REGISTER("al_get_sample_channels",ring_al_get_sample_channels);
	RING_API_REGISTER("al_get_sample_depth",ring_al_get_sample_depth);
	RING_API_REGISTER("al_get_sample_frequency",ring_al_get_sample_frequency);
	RING_API_REGISTER("al_get_sample_length",ring_al_get_sample_length);
	RING_API_REGISTER("al_get_sample_data",ring_al_get_sample_data);
	RING_API_REGISTER("al_create_sample_instance",ring_al_create_sample_instance);
	RING_API_REGISTER("al_destroy_sample_instance",ring_al_destroy_sample_instance);
	RING_API_REGISTER("al_play_sample_instance",ring_al_play_sample_instance);
	RING_API_REGISTER("al_stop_sample_instance",ring_al_stop_sample_instance);
	RING_API_REGISTER("al_get_sample_instance_channels",ring_al_get_sample_instance_channels);
	RING_API_REGISTER("al_get_sample_instance_depth",ring_al_get_sample_instance_depth);
	RING_API_REGISTER("al_get_sample_instance_frequency",ring_al_get_sample_instance_frequency);
	RING_API_REGISTER("al_get_sample_instance_length",ring_al_get_sample_instance_length);
	RING_API_REGISTER("al_set_sample_instance_length",ring_al_set_sample_instance_length);
	RING_API_REGISTER("al_get_sample_instance_position",ring_al_get_sample_instance_position);
	RING_API_REGISTER("al_set_sample_instance_position",ring_al_set_sample_instance_position);
	RING_API_REGISTER("al_get_sample_instance_speed",ring_al_get_sample_instance_speed);
	RING_API_REGISTER("al_set_sample_instance_speed",ring_al_set_sample_instance_speed);
	RING_API_REGISTER("al_get_sample_instance_gain",ring_al_get_sample_instance_gain);
	RING_API_REGISTER("al_set_sample_instance_gain",ring_al_set_sample_instance_gain);
	RING_API_REGISTER("al_get_sample_instance_pan",ring_al_get_sample_instance_pan);
	RING_API_REGISTER("al_set_sample_instance_pan",ring_al_set_sample_instance_pan);
	RING_API_REGISTER("al_get_sample_instance_time",ring_al_get_sample_instance_time);
	RING_API_REGISTER("al_get_sample_instance_playmode",ring_al_get_sample_instance_playmode);
	RING_API_REGISTER("al_set_sample_instance_playmode",ring_al_set_sample_instance_playmode);
	RING_API_REGISTER("al_get_sample_instance_playing",ring_al_get_sample_instance_playing);
	RING_API_REGISTER("al_set_sample_instance_playing",ring_al_set_sample_instance_playing);
	RING_API_REGISTER("al_get_sample_instance_attached",ring_al_get_sample_instance_attached);
	RING_API_REGISTER("al_detach_sample_instance",ring_al_detach_sample_instance);
	RING_API_REGISTER("al_get_sample",ring_al_get_sample);
	RING_API_REGISTER("al_set_sample",ring_al_set_sample);
	RING_API_REGISTER("al_create_mixer",ring_al_create_mixer);
	RING_API_REGISTER("al_destroy_mixer",ring_al_destroy_mixer);
	RING_API_REGISTER("al_get_default_mixer",ring_al_get_default_mixer);
	RING_API_REGISTER("al_set_default_mixer",ring_al_set_default_mixer);
	RING_API_REGISTER("al_restore_default_mixer",ring_al_restore_default_mixer);
	RING_API_REGISTER("al_attach_mixer_to_mixer",ring_al_attach_mixer_to_mixer);
	RING_API_REGISTER("al_attach_sample_instance_to_mixer",ring_al_attach_sample_instance_to_mixer);
	RING_API_REGISTER("al_attach_audio_stream_to_mixer",ring_al_attach_audio_stream_to_mixer);
	RING_API_REGISTER("al_get_mixer_frequency",ring_al_get_mixer_frequency);
	RING_API_REGISTER("al_set_mixer_frequency",ring_al_set_mixer_frequency);
	RING_API_REGISTER("al_get_mixer_channels",ring_al_get_mixer_channels);
	RING_API_REGISTER("al_get_mixer_depth",ring_al_get_mixer_depth);
	RING_API_REGISTER("al_get_mixer_gain",ring_al_get_mixer_gain);
	RING_API_REGISTER("al_set_mixer_gain",ring_al_set_mixer_gain);
	RING_API_REGISTER("al_get_mixer_quality",ring_al_get_mixer_quality);
	RING_API_REGISTER("al_set_mixer_quality",ring_al_set_mixer_quality);
	RING_API_REGISTER("al_get_mixer_playing",ring_al_get_mixer_playing);
	RING_API_REGISTER("al_set_mixer_playing",ring_al_set_mixer_playing);
	RING_API_REGISTER("al_get_mixer_attached",ring_al_get_mixer_attached);
	RING_API_REGISTER("al_detach_mixer",ring_al_detach_mixer);
	RING_API_REGISTER("al_create_audio_stream",ring_al_create_audio_stream);
	RING_API_REGISTER("al_destroy_audio_stream",ring_al_destroy_audio_stream);
	RING_API_REGISTER("al_get_audio_stream_event_source",ring_al_get_audio_stream_event_source);
	RING_API_REGISTER("al_drain_audio_stream",ring_al_drain_audio_stream);
	RING_API_REGISTER("al_rewind_audio_stream",ring_al_rewind_audio_stream);
	RING_API_REGISTER("al_get_audio_stream_frequency",ring_al_get_audio_stream_frequency);
	RING_API_REGISTER("al_get_audio_stream_channels",ring_al_get_audio_stream_channels);
	RING_API_REGISTER("al_get_audio_stream_depth",ring_al_get_audio_stream_depth);
	RING_API_REGISTER("al_get_audio_stream_length",ring_al_get_audio_stream_length);
	RING_API_REGISTER("al_get_audio_stream_speed",ring_al_get_audio_stream_speed);
	RING_API_REGISTER("al_set_audio_stream_speed",ring_al_set_audio_stream_speed);
	RING_API_REGISTER("al_get_audio_stream_gain",ring_al_get_audio_stream_gain);
	RING_API_REGISTER("al_set_audio_stream_gain",ring_al_set_audio_stream_gain);
	RING_API_REGISTER("al_get_audio_stream_pan",ring_al_get_audio_stream_pan);
	RING_API_REGISTER("al_set_audio_stream_pan",ring_al_set_audio_stream_pan);
	RING_API_REGISTER("al_get_audio_stream_playing",ring_al_get_audio_stream_playing);
	RING_API_REGISTER("al_set_audio_stream_playing",ring_al_set_audio_stream_playing);
	RING_API_REGISTER("al_get_audio_stream_playmode",ring_al_get_audio_stream_playmode);
	RING_API_REGISTER("al_set_audio_stream_playmode",ring_al_set_audio_stream_playmode);
	RING_API_REGISTER("al_get_audio_stream_attached",ring_al_get_audio_stream_attached);
	RING_API_REGISTER("al_detach_audio_stream",ring_al_detach_audio_stream);
	RING_API_REGISTER("al_get_audio_stream_fragment",ring_al_get_audio_stream_fragment);
	RING_API_REGISTER("al_set_audio_stream_fragment",ring_al_set_audio_stream_fragment);
	RING_API_REGISTER("al_get_audio_stream_fragments",ring_al_get_audio_stream_fragments);
	RING_API_REGISTER("al_get_available_audio_stream_fragments",ring_al_get_available_audio_stream_fragments);
	RING_API_REGISTER("al_seek_audio_stream_secs",ring_al_seek_audio_stream_secs);
	RING_API_REGISTER("al_get_audio_stream_position_secs",ring_al_get_audio_stream_position_secs);
	RING_API_REGISTER("al_get_audio_stream_length_secs",ring_al_get_audio_stream_length_secs);
	RING_API_REGISTER("al_set_audio_stream_loop_secs",ring_al_set_audio_stream_loop_secs);
	RING_API_REGISTER("al_load_sample",ring_al_load_sample);
	RING_API_REGISTER("al_load_sample_f",ring_al_load_sample_f);
	RING_API_REGISTER("al_load_audio_stream",ring_al_load_audio_stream);
	RING_API_REGISTER("al_load_audio_stream_f",ring_al_load_audio_stream_f);
	RING_API_REGISTER("al_save_sample",ring_al_save_sample);
	RING_API_REGISTER("al_save_sample_f",ring_al_save_sample_f);
	RING_API_REGISTER("al_init_acodec_addon",ring_al_init_acodec_addon);
	RING_API_REGISTER("al_get_allegro_acodec_version",ring_al_get_allegro_acodec_version);
	RING_API_REGISTER("al_color_cmyk",ring_al_color_cmyk);
	RING_API_REGISTER("al_color_cmyk_to_rgb",ring_al_color_cmyk_to_rgb);
	RING_API_REGISTER("al_color_hsl",ring_al_color_hsl);
	RING_API_REGISTER("al_color_hsl_to_rgb",ring_al_color_hsl_to_rgb);
	RING_API_REGISTER("al_color_hsv",ring_al_color_hsv);
	RING_API_REGISTER("al_color_hsv_to_rgb",ring_al_color_hsv_to_rgb);
	RING_API_REGISTER("al_color_html",ring_al_color_html);
	RING_API_REGISTER("al_color_html_to_rgb",ring_al_color_html_to_rgb);
	RING_API_REGISTER("al_color_rgb_to_html",ring_al_color_rgb_to_html);
	RING_API_REGISTER("al_color_name",ring_al_color_name);
	RING_API_REGISTER("al_color_name_to_rgb",ring_al_color_name_to_rgb);
	RING_API_REGISTER("al_color_rgb_to_cmyk",ring_al_color_rgb_to_cmyk);
	RING_API_REGISTER("al_color_rgb_to_hsl",ring_al_color_rgb_to_hsl);
	RING_API_REGISTER("al_color_rgb_to_hsv",ring_al_color_rgb_to_hsv);
	RING_API_REGISTER("al_color_rgb_to_name",ring_al_color_rgb_to_name);
	RING_API_REGISTER("al_color_rgb_to_yuv",ring_al_color_rgb_to_yuv);
	RING_API_REGISTER("al_color_yuv",ring_al_color_yuv);
	RING_API_REGISTER("al_color_yuv_to_rgb",ring_al_color_yuv_to_rgb);
	RING_API_REGISTER("al_get_allegro_color_version",ring_al_get_allegro_color_version);
	RING_API_REGISTER("al_init_font_addon",ring_al_init_font_addon);
	RING_API_REGISTER("al_shutdown_font_addon",ring_al_shutdown_font_addon);
	RING_API_REGISTER("al_load_font",ring_al_load_font);
	RING_API_REGISTER("al_destroy_font",ring_al_destroy_font);
	RING_API_REGISTER("al_get_font_line_height",ring_al_get_font_line_height);
	RING_API_REGISTER("al_get_font_ascent",ring_al_get_font_ascent);
	RING_API_REGISTER("al_get_font_descent",ring_al_get_font_descent);
	RING_API_REGISTER("al_get_text_width",ring_al_get_text_width);
	RING_API_REGISTER("al_get_ustr_width",ring_al_get_ustr_width);
	RING_API_REGISTER("al_draw_text",ring_al_draw_text);
	RING_API_REGISTER("al_draw_ustr",ring_al_draw_ustr);
	RING_API_REGISTER("al_draw_justified_text",ring_al_draw_justified_text);
	RING_API_REGISTER("al_draw_justified_ustr",ring_al_draw_justified_ustr);
	RING_API_REGISTER("al_get_text_dimensions",ring_al_get_text_dimensions);
	RING_API_REGISTER("al_get_ustr_dimensions",ring_al_get_ustr_dimensions);
	RING_API_REGISTER("al_get_allegro_font_version",ring_al_get_allegro_font_version);
	RING_API_REGISTER("al_grab_font_from_bitmap",ring_al_grab_font_from_bitmap);
	RING_API_REGISTER("al_load_bitmap_font",ring_al_load_bitmap_font);
	RING_API_REGISTER("al_create_builtin_font",ring_al_create_builtin_font);
	RING_API_REGISTER("al_init_ttf_addon",ring_al_init_ttf_addon);
	RING_API_REGISTER("al_shutdown_ttf_addon",ring_al_shutdown_ttf_addon);
	RING_API_REGISTER("al_load_ttf_font",ring_al_load_ttf_font);
	RING_API_REGISTER("al_load_ttf_font_f",ring_al_load_ttf_font_f);
	RING_API_REGISTER("al_load_ttf_font_stretch",ring_al_load_ttf_font_stretch);
	RING_API_REGISTER("al_load_ttf_font_stretch_f",ring_al_load_ttf_font_stretch_f);
	RING_API_REGISTER("al_get_allegro_ttf_version",ring_al_get_allegro_ttf_version);
	RING_API_REGISTER("al_init_image_addon",ring_al_init_image_addon);
	RING_API_REGISTER("al_shutdown_image_addon",ring_al_shutdown_image_addon);
	RING_API_REGISTER("al_get_allegro_image_version",ring_al_get_allegro_image_version);
	RING_API_REGISTER("al_open_memfile",ring_al_open_memfile);
	RING_API_REGISTER("al_get_allegro_memfile_version",ring_al_get_allegro_memfile_version);
	RING_API_REGISTER("al_init_native_dialog_addon",ring_al_init_native_dialog_addon);
	RING_API_REGISTER("al_shutdown_native_dialog_addon",ring_al_shutdown_native_dialog_addon);
	RING_API_REGISTER("al_create_native_file_dialog",ring_al_create_native_file_dialog);
	RING_API_REGISTER("al_show_native_file_dialog",ring_al_show_native_file_dialog);
	RING_API_REGISTER("al_get_native_file_dialog_count",ring_al_get_native_file_dialog_count);
	RING_API_REGISTER("al_get_native_file_dialog_path",ring_al_get_native_file_dialog_path);
	RING_API_REGISTER("al_destroy_native_file_dialog",ring_al_destroy_native_file_dialog);
	RING_API_REGISTER("al_show_native_message_box",ring_al_show_native_message_box);
	RING_API_REGISTER("al_open_native_text_log",ring_al_open_native_text_log);
	RING_API_REGISTER("al_close_native_text_log",ring_al_close_native_text_log);
	RING_API_REGISTER("al_get_native_text_log_event_source",ring_al_get_native_text_log_event_source);
	RING_API_REGISTER("al_get_allegro_native_dialog_version",ring_al_get_allegro_native_dialog_version);
	RING_API_REGISTER("al_set_physfs_file_interface",ring_al_set_physfs_file_interface);
	RING_API_REGISTER("al_get_allegro_physfs_version",ring_al_get_allegro_physfs_version);
	RING_API_REGISTER("al_get_allegro_primitives_version",ring_al_get_allegro_primitives_version);
	RING_API_REGISTER("al_init_primitives_addon",ring_al_init_primitives_addon);
	RING_API_REGISTER("al_shutdown_primitives_addon",ring_al_shutdown_primitives_addon);
	RING_API_REGISTER("al_draw_line",ring_al_draw_line);
	RING_API_REGISTER("al_draw_triangle",ring_al_draw_triangle);
	RING_API_REGISTER("al_draw_filled_triangle",ring_al_draw_filled_triangle);
	RING_API_REGISTER("al_draw_rectangle",ring_al_draw_rectangle);
	RING_API_REGISTER("al_draw_filled_rectangle",ring_al_draw_filled_rectangle);
	RING_API_REGISTER("al_draw_rounded_rectangle",ring_al_draw_rounded_rectangle);
	RING_API_REGISTER("al_draw_filled_rounded_rectangle",ring_al_draw_filled_rounded_rectangle);
	RING_API_REGISTER("al_calculate_arc",ring_al_calculate_arc);
	RING_API_REGISTER("al_draw_pieslice",ring_al_draw_pieslice);
	RING_API_REGISTER("al_draw_filled_pieslice",ring_al_draw_filled_pieslice);
	RING_API_REGISTER("al_draw_ellipse",ring_al_draw_ellipse);
	RING_API_REGISTER("al_draw_filled_ellipse",ring_al_draw_filled_ellipse);
	RING_API_REGISTER("al_draw_circle",ring_al_draw_circle);
	RING_API_REGISTER("al_draw_filled_circle",ring_al_draw_filled_circle);
	RING_API_REGISTER("al_draw_arc",ring_al_draw_arc);
	RING_API_REGISTER("al_draw_elliptical_arc",ring_al_draw_elliptical_arc);
	RING_API_REGISTER("al_calculate_ribbon",ring_al_calculate_ribbon);
	RING_API_REGISTER("al_draw_ribbon",ring_al_draw_ribbon);
	RING_API_REGISTER("al_draw_prim",ring_al_draw_prim);
	RING_API_REGISTER("al_draw_indexed_prim",ring_al_draw_indexed_prim);
	RING_API_REGISTER("al_create_vertex_decl",ring_al_create_vertex_decl);
	RING_API_REGISTER("al_destroy_vertex_decl",ring_al_destroy_vertex_decl);
	RING_API_REGISTER("al_create_shader",ring_al_create_shader);
	RING_API_REGISTER("al_attach_shader_source",ring_al_attach_shader_source);
	RING_API_REGISTER("al_attach_shader_source_file",ring_al_attach_shader_source_file);
	RING_API_REGISTER("al_build_shader",ring_al_build_shader);
	RING_API_REGISTER("al_get_shader_log",ring_al_get_shader_log);
	RING_API_REGISTER("al_get_shader_platform",ring_al_get_shader_platform);
	RING_API_REGISTER("al_use_shader",ring_al_use_shader);
	RING_API_REGISTER("al_destroy_shader",ring_al_destroy_shader);
	RING_API_REGISTER("al_set_shader_sampler",ring_al_set_shader_sampler);
	RING_API_REGISTER("al_set_shader_matrix",ring_al_set_shader_matrix);
	RING_API_REGISTER("al_set_shader_int",ring_al_set_shader_int);
	RING_API_REGISTER("al_set_shader_float",ring_al_set_shader_float);
	RING_API_REGISTER("al_set_shader_bool",ring_al_set_shader_bool);
	RING_API_REGISTER("al_set_shader_int_vector",ring_al_set_shader_int_vector);
	RING_API_REGISTER("al_set_shader_float_vector",ring_al_set_shader_float_vector);
	RING_API_REGISTER("al_get_default_shader_source",ring_al_get_default_shader_source);
	RING_API_REGISTER("al_new_allegro_event",ring_al_new_allegro_event);
	RING_API_REGISTER("al_new_managed_allegro_event",ring_al_new_managed_allegro_event);
	RING_API_REGISTER("al_destroy_allegro_event",ring_al_destroy_allegro_event);
	RING_API_REGISTER("al_get_allegro_event_type",ring_al_get_allegro_event_type);
	RING_API_REGISTER("al_set_allegro_event_type",ring_al_set_allegro_event_type);
	RING_API_REGISTER("al_get_allegro_event_keyboard_keycode",ring_al_get_allegro_event_keyboard_keycode);
	RING_API_REGISTER("al_set_allegro_event_keyboard_keycode",ring_al_set_allegro_event_keyboard_keycode);
	RING_API_REGISTER("al_get_allegro_event_mouse_x",ring_al_get_allegro_event_mouse_x);
	RING_API_REGISTER("al_set_allegro_event_mouse_x",ring_al_set_allegro_event_mouse_x);
	RING_API_REGISTER("al_get_allegro_event_mouse_y",ring_al_get_allegro_event_mouse_y);
	RING_API_REGISTER("al_set_allegro_event_mouse_y",ring_al_set_allegro_event_mouse_y);
	RING_API_REGISTER("al_get_allegro_event_timer_source",ring_al_get_allegro_event_timer_source);
	RING_API_REGISTER("al_set_allegro_event_timer_source",ring_al_set_allegro_event_timer_source);
	RING_API_REGISTER("al_get_allegro_event_joystick_id",ring_al_get_allegro_event_joystick_id);
	RING_API_REGISTER("al_set_allegro_event_joystick_id",ring_al_set_allegro_event_joystick_id);
	RING_API_REGISTER("al_get_allegro_event_joystick_stick",ring_al_get_allegro_event_joystick_stick);
	RING_API_REGISTER("al_set_allegro_event_joystick_stick",ring_al_set_allegro_event_joystick_stick);
	RING_API_REGISTER("al_get_allegro_event_joystick_axis",ring_al_get_allegro_event_joystick_axis);
	RING_API_REGISTER("al_set_allegro_event_joystick_axis",ring_al_set_allegro_event_joystick_axis);
	RING_API_REGISTER("al_get_allegro_event_joystick_pos",ring_al_get_allegro_event_joystick_pos);
	RING_API_REGISTER("al_set_allegro_event_joystick_pos",ring_al_set_allegro_event_joystick_pos);
	RING_API_REGISTER("al_get_allegro_event_joystick_button",ring_al_get_allegro_event_joystick_button);
	RING_API_REGISTER("al_set_allegro_event_joystick_button",ring_al_set_allegro_event_joystick_button);
	RING_API_REGISTER("al_new_allegro_timeout",ring_al_new_allegro_timeout);
	RING_API_REGISTER("al_new_managed_allegro_timeout",ring_al_new_managed_allegro_timeout);
	RING_API_REGISTER("al_destroy_allegro_timeout",ring_al_destroy_allegro_timeout);
	RING_API_REGISTER("al_new_allegro_sample_id",ring_al_new_allegro_sample_id);
	RING_API_REGISTER("al_new_managed_allegro_sample_id",ring_al_new_managed_allegro_sample_id);
	RING_API_REGISTER("al_destroy_allegro_sample_id",ring_al_destroy_allegro_sample_id);
	RING_API_REGISTER("al_new_allegro_color",ring_al_new_allegro_color);
	RING_API_REGISTER("al_new_managed_allegro_color",ring_al_new_managed_allegro_color);
	RING_API_REGISTER("al_destroy_allegro_color",ring_al_destroy_allegro_color);
	RING_API_REGISTER("al_new_allegro_joystick_state",ring_al_new_allegro_joystick_state);
	RING_API_REGISTER("al_new_managed_allegro_joystick_state",ring_al_new_managed_allegro_joystick_state);
	RING_API_REGISTER("al_destroy_allegro_joystick_state",ring_al_destroy_allegro_joystick_state);
}

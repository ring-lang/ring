#include "ring.h"

/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_net.h"
#include "SDL2_gfx/SDL2_gfxPrimitives.h"
#include "SDL2_gfx/SDL2_gfxPrimitives.c"
#include "SDL2_gfx/SDL2_rotozoom.c"
#include "SDL_syswm.h"
RING_FUNC(ring_sdl_new_sdl_syswminfo)
{
	SDL_SysWMinfo *pMyPointer ;
	pMyPointer = (SDL_SysWMinfo *) RING_API_MALLOC(sizeof(SDL_SysWMinfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_SysWMinfo");
}

RING_FUNC(ring_sdl_new_managed_sdl_syswminfo)
{
	SDL_SysWMinfo *pMyPointer ;
	pMyPointer = (SDL_SysWMinfo *) RING_API_MALLOC(sizeof(SDL_SysWMinfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_SysWMinfo",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_syswminfo)
{
	SDL_SysWMinfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_SysWMinfo*) RING_API_GETCPOINTER(1,"SDL_SysWMinfo");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_syswmmsg)
{
	SDL_SysWMmsg *pMyPointer ;
	pMyPointer = (SDL_SysWMmsg *) RING_API_MALLOC(sizeof(SDL_SysWMmsg)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_SysWMmsg");
}

RING_FUNC(ring_sdl_new_managed_sdl_syswmmsg)
{
	SDL_SysWMmsg *pMyPointer ;
	pMyPointer = (SDL_SysWMmsg *) RING_API_MALLOC(sizeof(SDL_SysWMmsg)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_SysWMmsg",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_syswmmsg)
{
	SDL_SysWMmsg *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_SysWMmsg*) RING_API_GETCPOINTER(1,"SDL_SysWMmsg");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_syswmevent)
{
	SDL_SysWMEvent *pMyPointer ;
	pMyPointer = (SDL_SysWMEvent *) RING_API_MALLOC(sizeof(SDL_SysWMEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_SysWMEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_syswmevent)
{
	SDL_SysWMEvent *pMyPointer ;
	pMyPointer = (SDL_SysWMEvent *) RING_API_MALLOC(sizeof(SDL_SysWMEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_SysWMEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_syswmevent)
{
	SDL_SysWMEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_SysWMEvent*) RING_API_GETCPOINTER(1,"SDL_SysWMEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_syswmevent)
{
	RING_API_RETNUMBER(SDL_SYSWMEVENT);
}

RING_FUNC(ring_sdl_new_sdl_assert_data)
{
	SDL_assert_data *pMyPointer ;
	pMyPointer = (SDL_assert_data *) RING_API_MALLOC(sizeof(SDL_assert_data)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_assert_data");
}

RING_FUNC(ring_sdl_new_managed_sdl_assert_data)
{
	SDL_assert_data *pMyPointer ;
	pMyPointer = (SDL_assert_data *) RING_API_MALLOC(sizeof(SDL_assert_data)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_assert_data",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_assert_data)
{
	SDL_assert_data *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_assert_data*) RING_API_GETCPOINTER(1,"SDL_assert_data");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_version)
{
	SDL_version *pMyPointer ;
	pMyPointer = (SDL_version *) RING_API_MALLOC(sizeof(SDL_version)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_version");
}

RING_FUNC(ring_sdl_new_managed_sdl_version)
{
	SDL_version *pMyPointer ;
	pMyPointer = (SDL_version *) RING_API_MALLOC(sizeof(SDL_version)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_version",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_version)
{
	SDL_version *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_version*) RING_API_GETCPOINTER(1,"SDL_version");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_version_major)
{
	SDL_version *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_version");
	RING_API_RETNUMBER(pMyPointer->major);
}

RING_FUNC(ring_sdl_set_sdl_version_major)
{
	SDL_version *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_version");
	pMyPointer->major = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_version_minor)
{
	SDL_version *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_version");
	RING_API_RETNUMBER(pMyPointer->minor);
}

RING_FUNC(ring_sdl_set_sdl_version_minor)
{
	SDL_version *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_version");
	pMyPointer->minor = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_version_patch)
{
	SDL_version *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_version");
	RING_API_RETNUMBER(pMyPointer->patch);
}

RING_FUNC(ring_sdl_set_sdl_version_patch)
{
	SDL_version *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_version");
	pMyPointer->patch = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_displaymode)
{
	SDL_DisplayMode *pMyPointer ;
	pMyPointer = (SDL_DisplayMode *) RING_API_MALLOC(sizeof(SDL_DisplayMode)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_DisplayMode");
}

RING_FUNC(ring_sdl_new_managed_sdl_displaymode)
{
	SDL_DisplayMode *pMyPointer ;
	pMyPointer = (SDL_DisplayMode *) RING_API_MALLOC(sizeof(SDL_DisplayMode)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_DisplayMode",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_displaymode)
{
	SDL_DisplayMode *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_DisplayMode*) RING_API_GETCPOINTER(1,"SDL_DisplayMode");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_messageboxbuttondata)
{
	SDL_MessageBoxButtonData *pMyPointer ;
	pMyPointer = (SDL_MessageBoxButtonData *) RING_API_MALLOC(sizeof(SDL_MessageBoxButtonData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxButtonData");
}

RING_FUNC(ring_sdl_new_managed_sdl_messageboxbuttondata)
{
	SDL_MessageBoxButtonData *pMyPointer ;
	pMyPointer = (SDL_MessageBoxButtonData *) RING_API_MALLOC(sizeof(SDL_MessageBoxButtonData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MessageBoxButtonData",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxbuttondata)
{
	SDL_MessageBoxButtonData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MessageBoxButtonData*) RING_API_GETCPOINTER(1,"SDL_MessageBoxButtonData");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_messageboxcolor)
{
	SDL_MessageBoxColor *pMyPointer ;
	pMyPointer = (SDL_MessageBoxColor *) RING_API_MALLOC(sizeof(SDL_MessageBoxColor)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxColor");
}

RING_FUNC(ring_sdl_new_managed_sdl_messageboxcolor)
{
	SDL_MessageBoxColor *pMyPointer ;
	pMyPointer = (SDL_MessageBoxColor *) RING_API_MALLOC(sizeof(SDL_MessageBoxColor)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MessageBoxColor",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxcolor)
{
	SDL_MessageBoxColor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MessageBoxColor*) RING_API_GETCPOINTER(1,"SDL_MessageBoxColor");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_messageboxcolorscheme)
{
	SDL_MessageBoxColorScheme *pMyPointer ;
	pMyPointer = (SDL_MessageBoxColorScheme *) RING_API_MALLOC(sizeof(SDL_MessageBoxColorScheme)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxColorScheme");
}

RING_FUNC(ring_sdl_new_managed_sdl_messageboxcolorscheme)
{
	SDL_MessageBoxColorScheme *pMyPointer ;
	pMyPointer = (SDL_MessageBoxColorScheme *) RING_API_MALLOC(sizeof(SDL_MessageBoxColorScheme)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MessageBoxColorScheme",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxcolorscheme)
{
	SDL_MessageBoxColorScheme *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MessageBoxColorScheme*) RING_API_GETCPOINTER(1,"SDL_MessageBoxColorScheme");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_messageboxdata)
{
	SDL_MessageBoxData *pMyPointer ;
	pMyPointer = (SDL_MessageBoxData *) RING_API_MALLOC(sizeof(SDL_MessageBoxData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxData");
}

RING_FUNC(ring_sdl_new_managed_sdl_messageboxdata)
{
	SDL_MessageBoxData *pMyPointer ;
	pMyPointer = (SDL_MessageBoxData *) RING_API_MALLOC(sizeof(SDL_MessageBoxData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MessageBoxData",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxdata)
{
	SDL_MessageBoxData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MessageBoxData*) RING_API_GETCPOINTER(1,"SDL_MessageBoxData");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_rendererinfo)
{
	SDL_RendererInfo *pMyPointer ;
	pMyPointer = (SDL_RendererInfo *) RING_API_MALLOC(sizeof(SDL_RendererInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_RendererInfo");
}

RING_FUNC(ring_sdl_new_managed_sdl_rendererinfo)
{
	SDL_RendererInfo *pMyPointer ;
	pMyPointer = (SDL_RendererInfo *) RING_API_MALLOC(sizeof(SDL_RendererInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_RendererInfo",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_rendererinfo)
{
	SDL_RendererInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_RendererInfo*) RING_API_GETCPOINTER(1,"SDL_RendererInfo");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_color)
{
	SDL_Color *pMyPointer ;
	pMyPointer = (SDL_Color *) RING_API_MALLOC(sizeof(SDL_Color)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Color");
}

RING_FUNC(ring_sdl_new_managed_sdl_color)
{
	SDL_Color *pMyPointer ;
	pMyPointer = (SDL_Color *) RING_API_MALLOC(sizeof(SDL_Color)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Color",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_color)
{
	SDL_Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Color*) RING_API_GETCPOINTER(1,"SDL_Color");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_color_r)
{
	SDL_Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Color");
	RING_API_RETNUMBER(pMyPointer->r);
}

RING_FUNC(ring_sdl_set_sdl_color_r)
{
	SDL_Color *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Color");
	pMyPointer->r = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_color_g)
{
	SDL_Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Color");
	RING_API_RETNUMBER(pMyPointer->g);
}

RING_FUNC(ring_sdl_set_sdl_color_g)
{
	SDL_Color *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Color");
	pMyPointer->g = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_color_b)
{
	SDL_Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Color");
	RING_API_RETNUMBER(pMyPointer->b);
}

RING_FUNC(ring_sdl_set_sdl_color_b)
{
	SDL_Color *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Color");
	pMyPointer->b = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_palette)
{
	SDL_Palette *pMyPointer ;
	pMyPointer = (SDL_Palette *) RING_API_MALLOC(sizeof(SDL_Palette)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Palette");
}

RING_FUNC(ring_sdl_new_managed_sdl_palette)
{
	SDL_Palette *pMyPointer ;
	pMyPointer = (SDL_Palette *) RING_API_MALLOC(sizeof(SDL_Palette)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Palette",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_palette)
{
	SDL_Palette *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Palette*) RING_API_GETCPOINTER(1,"SDL_Palette");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_pixelformat)
{
	SDL_PixelFormat *pMyPointer ;
	pMyPointer = (SDL_PixelFormat *) RING_API_MALLOC(sizeof(SDL_PixelFormat)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_PixelFormat");
}

RING_FUNC(ring_sdl_new_managed_sdl_pixelformat)
{
	SDL_PixelFormat *pMyPointer ;
	pMyPointer = (SDL_PixelFormat *) RING_API_MALLOC(sizeof(SDL_PixelFormat)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_PixelFormat",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_pixelformat)
{
	SDL_PixelFormat *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_PixelFormat*) RING_API_GETCPOINTER(1,"SDL_PixelFormat");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_point)
{
	SDL_Point *pMyPointer ;
	pMyPointer = (SDL_Point *) RING_API_MALLOC(sizeof(SDL_Point)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Point");
}

RING_FUNC(ring_sdl_new_managed_sdl_point)
{
	SDL_Point *pMyPointer ;
	pMyPointer = (SDL_Point *) RING_API_MALLOC(sizeof(SDL_Point)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Point",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_point)
{
	SDL_Point *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Point*) RING_API_GETCPOINTER(1,"SDL_Point");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_point_x)
{
	SDL_Point *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Point");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_sdl_set_sdl_point_x)
{
	SDL_Point *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Point");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_point_y)
{
	SDL_Point *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Point");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_sdl_set_sdl_point_y)
{
	SDL_Point *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Point");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_rect)
{
	SDL_Rect *pMyPointer ;
	pMyPointer = (SDL_Rect *) RING_API_MALLOC(sizeof(SDL_Rect)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Rect");
}

RING_FUNC(ring_sdl_new_managed_sdl_rect)
{
	SDL_Rect *pMyPointer ;
	pMyPointer = (SDL_Rect *) RING_API_MALLOC(sizeof(SDL_Rect)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Rect",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_rect)
{
	SDL_Rect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Rect*) RING_API_GETCPOINTER(1,"SDL_Rect");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_rect_x)
{
	SDL_Rect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_sdl_set_sdl_rect_x)
{
	SDL_Rect *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_rect_y)
{
	SDL_Rect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_sdl_set_sdl_rect_y)
{
	SDL_Rect *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_rect_w)
{
	SDL_Rect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	RING_API_RETNUMBER(pMyPointer->w);
}

RING_FUNC(ring_sdl_set_sdl_rect_w)
{
	SDL_Rect *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	pMyPointer->w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_rect_h)
{
	SDL_Rect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	RING_API_RETNUMBER(pMyPointer->h);
}

RING_FUNC(ring_sdl_set_sdl_rect_h)
{
	SDL_Rect *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	pMyPointer->h = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_surface)
{
	SDL_Surface *pMyPointer ;
	pMyPointer = (SDL_Surface *) RING_API_MALLOC(sizeof(SDL_Surface)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Surface");
}

RING_FUNC(ring_sdl_new_managed_sdl_surface)
{
	SDL_Surface *pMyPointer ;
	pMyPointer = (SDL_Surface *) RING_API_MALLOC(sizeof(SDL_Surface)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Surface",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_surface)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Surface*) RING_API_GETCPOINTER(1,"SDL_Surface");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_surface_flags)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETNUMBER(pMyPointer->flags);
}

RING_FUNC(ring_sdl_set_sdl_surface_flags)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->flags = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_surface_format)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETCPOINTER(pMyPointer->format,"SDL_PixelFormat");
}

RING_FUNC(ring_sdl_set_sdl_surface_format)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->format = (SDL_PixelFormat *) RING_API_GETCPOINTER(2,"SDL_PixelFormat");
}

RING_FUNC(ring_sdl_get_sdl_surface_w)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETNUMBER(pMyPointer->w);
}

RING_FUNC(ring_sdl_set_sdl_surface_w)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->w = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_surface_h)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETNUMBER(pMyPointer->h);
}

RING_FUNC(ring_sdl_set_sdl_surface_h)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->h = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_surface_pitch)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETNUMBER(pMyPointer->pitch);
}

RING_FUNC(ring_sdl_set_sdl_surface_pitch)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->pitch = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_surface_pixels)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETCPOINTER(pMyPointer->pixels,"void");
}

RING_FUNC(ring_sdl_set_sdl_surface_pixels)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->pixels = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_sdl_get_sdl_surface_userdata)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETCPOINTER(pMyPointer->userdata,"void");
}

RING_FUNC(ring_sdl_set_sdl_surface_userdata)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->userdata = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_sdl_get_sdl_surface_locked)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	RING_API_RETNUMBER(pMyPointer->locked);
}

RING_FUNC(ring_sdl_set_sdl_surface_locked)
{
	SDL_Surface *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	pMyPointer->locked = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_controlleraxisevent)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	pMyPointer = (SDL_ControllerAxisEvent *) RING_API_MALLOC(sizeof(SDL_ControllerAxisEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_ControllerAxisEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_controlleraxisevent)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	pMyPointer = (SDL_ControllerAxisEvent *) RING_API_MALLOC(sizeof(SDL_ControllerAxisEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_ControllerAxisEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_controlleraxisevent)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_ControllerAxisEvent*) RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_controlleraxisevent_type)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_controlleraxisevent_type)
{
	SDL_ControllerAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_controlleraxisevent_timestamp)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_controlleraxisevent_timestamp)
{
	SDL_ControllerAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_controlleraxisevent_which)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	RING_API_RETNUMBER(pMyPointer->which);
}

RING_FUNC(ring_sdl_set_sdl_controlleraxisevent_which)
{
	SDL_ControllerAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	pMyPointer->which = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_controlleraxisevent_axis)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	RING_API_RETNUMBER(pMyPointer->axis);
}

RING_FUNC(ring_sdl_set_sdl_controlleraxisevent_axis)
{
	SDL_ControllerAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	pMyPointer->axis = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_controlleraxisevent_value)
{
	SDL_ControllerAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	RING_API_RETNUMBER(pMyPointer->value);
}

RING_FUNC(ring_sdl_set_sdl_controlleraxisevent_value)
{
	SDL_ControllerAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_ControllerAxisEvent");
	pMyPointer->value = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_controllerbuttonevent)
{
	SDL_ControllerButtonEvent *pMyPointer ;
	pMyPointer = (SDL_ControllerButtonEvent *) RING_API_MALLOC(sizeof(SDL_ControllerButtonEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_ControllerButtonEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_controllerbuttonevent)
{
	SDL_ControllerButtonEvent *pMyPointer ;
	pMyPointer = (SDL_ControllerButtonEvent *) RING_API_MALLOC(sizeof(SDL_ControllerButtonEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_ControllerButtonEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_controllerbuttonevent)
{
	SDL_ControllerButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_ControllerButtonEvent*) RING_API_GETCPOINTER(1,"SDL_ControllerButtonEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_controllerdeviceevent)
{
	SDL_ControllerDeviceEvent *pMyPointer ;
	pMyPointer = (SDL_ControllerDeviceEvent *) RING_API_MALLOC(sizeof(SDL_ControllerDeviceEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_ControllerDeviceEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_controllerdeviceevent)
{
	SDL_ControllerDeviceEvent *pMyPointer ;
	pMyPointer = (SDL_ControllerDeviceEvent *) RING_API_MALLOC(sizeof(SDL_ControllerDeviceEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_ControllerDeviceEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_controllerdeviceevent)
{
	SDL_ControllerDeviceEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_ControllerDeviceEvent*) RING_API_GETCPOINTER(1,"SDL_ControllerDeviceEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_dollargestureevent)
{
	SDL_DollarGestureEvent *pMyPointer ;
	pMyPointer = (SDL_DollarGestureEvent *) RING_API_MALLOC(sizeof(SDL_DollarGestureEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_DollarGestureEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_dollargestureevent)
{
	SDL_DollarGestureEvent *pMyPointer ;
	pMyPointer = (SDL_DollarGestureEvent *) RING_API_MALLOC(sizeof(SDL_DollarGestureEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_DollarGestureEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_dollargestureevent)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_DollarGestureEvent*) RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_type)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_type)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_timestamp)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_timestamp)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_touchId)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->touchId);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_touchId)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->touchId = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_gestureId)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->gestureId);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_gestureId)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->gestureId = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_numFingers)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->numFingers);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_numFingers)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->numFingers = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_error)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->error);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_error)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->error = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_x)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_x)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dollargestureevent_y)
{
	SDL_DollarGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_sdl_set_sdl_dollargestureevent_y)
{
	SDL_DollarGestureEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DollarGestureEvent");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_dropevent)
{
	SDL_DropEvent *pMyPointer ;
	pMyPointer = (SDL_DropEvent *) RING_API_MALLOC(sizeof(SDL_DropEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_DropEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_dropevent)
{
	SDL_DropEvent *pMyPointer ;
	pMyPointer = (SDL_DropEvent *) RING_API_MALLOC(sizeof(SDL_DropEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_DropEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_dropevent)
{
	SDL_DropEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_DropEvent*) RING_API_GETCPOINTER(1,"SDL_DropEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_dropevent_type)
{
	SDL_DropEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DropEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_dropevent_type)
{
	SDL_DropEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DropEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dropevent_timestamp)
{
	SDL_DropEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DropEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_dropevent_timestamp)
{
	SDL_DropEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DropEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_dropevent_file)
{
	SDL_DropEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DropEvent");
	RING_API_RETCPOINTER(pMyPointer->file,"char");
}

RING_FUNC(ring_sdl_set_sdl_dropevent_file)
{
	SDL_DropEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DropEvent");
	pMyPointer->file = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_sdl_new_sdl_event)
{
	SDL_Event *pMyPointer ;
	pMyPointer = (SDL_Event *) RING_API_MALLOC(sizeof(SDL_Event)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Event");
}

RING_FUNC(ring_sdl_new_managed_sdl_event)
{
	SDL_Event *pMyPointer ;
	pMyPointer = (SDL_Event *) RING_API_MALLOC(sizeof(SDL_Event)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Event",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_event)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Event*) RING_API_GETCPOINTER(1,"SDL_Event");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_event_type)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_event_type)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_key_keysym_sym)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->key.keysym.sym);
}

RING_FUNC(ring_sdl_set_sdl_event_key_keysym_sym)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->key.keysym.sym = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_button_type)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->button.type);
}

RING_FUNC(ring_sdl_set_sdl_event_button_type)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->button.type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_button_state)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->button.state);
}

RING_FUNC(ring_sdl_set_sdl_event_button_state)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->button.state = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_button_x)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->button.x);
}

RING_FUNC(ring_sdl_set_sdl_event_button_x)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->button.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_button_y)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->button.y);
}

RING_FUNC(ring_sdl_set_sdl_event_button_y)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->button.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_button_button)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->button.button);
}

RING_FUNC(ring_sdl_set_sdl_event_button_button)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->button.button = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_motion_type)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->motion.type);
}

RING_FUNC(ring_sdl_set_sdl_event_motion_type)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->motion.type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_motion_state)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->motion.state);
}

RING_FUNC(ring_sdl_set_sdl_event_motion_state)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->motion.state = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_motion_x)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->motion.x);
}

RING_FUNC(ring_sdl_set_sdl_event_motion_x)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->motion.x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_motion_y)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->motion.y);
}

RING_FUNC(ring_sdl_set_sdl_event_motion_y)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->motion.y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_motion_xrel)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->motion.xrel);
}

RING_FUNC(ring_sdl_set_sdl_event_motion_xrel)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->motion.xrel = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_event_motion_yrel)
{
	SDL_Event *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	RING_API_RETNUMBER(pMyPointer->motion.yrel);
}

RING_FUNC(ring_sdl_set_sdl_event_motion_yrel)
{
	SDL_Event *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Event");
	pMyPointer->motion.yrel = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_touchfingerevent)
{
	SDL_TouchFingerEvent *pMyPointer ;
	pMyPointer = (SDL_TouchFingerEvent *) RING_API_MALLOC(sizeof(SDL_TouchFingerEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_TouchFingerEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_touchfingerevent)
{
	SDL_TouchFingerEvent *pMyPointer ;
	pMyPointer = (SDL_TouchFingerEvent *) RING_API_MALLOC(sizeof(SDL_TouchFingerEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_TouchFingerEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_touchfingerevent)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_TouchFingerEvent*) RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_type)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_type)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_timestamp)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_timestamp)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_touchId)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->touchId);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_touchId)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->touchId = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_fingerId)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->fingerId);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_fingerId)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->fingerId = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_x)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_x)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_y)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_y)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_dx)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->dx);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_dx)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->dx = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_dy)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->dy);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_dy)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->dy = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_touchfingerevent_pressure)
{
	SDL_TouchFingerEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	RING_API_RETNUMBER(pMyPointer->pressure);
}

RING_FUNC(ring_sdl_set_sdl_touchfingerevent_pressure)
{
	SDL_TouchFingerEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TouchFingerEvent");
	pMyPointer->pressure = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_finger)
{
	SDL_Finger *pMyPointer ;
	pMyPointer = (SDL_Finger *) RING_API_MALLOC(sizeof(SDL_Finger)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Finger");
}

RING_FUNC(ring_sdl_new_managed_sdl_finger)
{
	SDL_Finger *pMyPointer ;
	pMyPointer = (SDL_Finger *) RING_API_MALLOC(sizeof(SDL_Finger)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Finger",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_finger)
{
	SDL_Finger *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Finger*) RING_API_GETCPOINTER(1,"SDL_Finger");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_joyaxisevent)
{
	SDL_JoyAxisEvent *pMyPointer ;
	pMyPointer = (SDL_JoyAxisEvent *) RING_API_MALLOC(sizeof(SDL_JoyAxisEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_JoyAxisEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_joyaxisevent)
{
	SDL_JoyAxisEvent *pMyPointer ;
	pMyPointer = (SDL_JoyAxisEvent *) RING_API_MALLOC(sizeof(SDL_JoyAxisEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_JoyAxisEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_joyaxisevent)
{
	SDL_JoyAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_JoyAxisEvent*) RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_joyaxisevent_type)
{
	SDL_JoyAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_joyaxisevent_type)
{
	SDL_JoyAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_joyaxisevent_timestamp)
{
	SDL_JoyAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_joyaxisevent_timestamp)
{
	SDL_JoyAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_joyaxisevent_which)
{
	SDL_JoyAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	RING_API_RETNUMBER(pMyPointer->which);
}

RING_FUNC(ring_sdl_set_sdl_joyaxisevent_which)
{
	SDL_JoyAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	pMyPointer->which = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_joyaxisevent_axis)
{
	SDL_JoyAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	RING_API_RETNUMBER(pMyPointer->axis);
}

RING_FUNC(ring_sdl_set_sdl_joyaxisevent_axis)
{
	SDL_JoyAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	pMyPointer->axis = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_joyaxisevent_value)
{
	SDL_JoyAxisEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	RING_API_RETNUMBER(pMyPointer->value);
}

RING_FUNC(ring_sdl_set_sdl_joyaxisevent_value)
{
	SDL_JoyAxisEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_JoyAxisEvent");
	pMyPointer->value = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_joyballevent)
{
	SDL_JoyBallEvent *pMyPointer ;
	pMyPointer = (SDL_JoyBallEvent *) RING_API_MALLOC(sizeof(SDL_JoyBallEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_JoyBallEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_joyballevent)
{
	SDL_JoyBallEvent *pMyPointer ;
	pMyPointer = (SDL_JoyBallEvent *) RING_API_MALLOC(sizeof(SDL_JoyBallEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_JoyBallEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_joyballevent)
{
	SDL_JoyBallEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_JoyBallEvent*) RING_API_GETCPOINTER(1,"SDL_JoyBallEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_joybuttonevent)
{
	SDL_JoyButtonEvent *pMyPointer ;
	pMyPointer = (SDL_JoyButtonEvent *) RING_API_MALLOC(sizeof(SDL_JoyButtonEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_JoyButtonEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_joybuttonevent)
{
	SDL_JoyButtonEvent *pMyPointer ;
	pMyPointer = (SDL_JoyButtonEvent *) RING_API_MALLOC(sizeof(SDL_JoyButtonEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_JoyButtonEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_joybuttonevent)
{
	SDL_JoyButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_JoyButtonEvent*) RING_API_GETCPOINTER(1,"SDL_JoyButtonEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_joydeviceevent)
{
	SDL_JoyDeviceEvent *pMyPointer ;
	pMyPointer = (SDL_JoyDeviceEvent *) RING_API_MALLOC(sizeof(SDL_JoyDeviceEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_JoyDeviceEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_joydeviceevent)
{
	SDL_JoyDeviceEvent *pMyPointer ;
	pMyPointer = (SDL_JoyDeviceEvent *) RING_API_MALLOC(sizeof(SDL_JoyDeviceEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_JoyDeviceEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_joydeviceevent)
{
	SDL_JoyDeviceEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_JoyDeviceEvent*) RING_API_GETCPOINTER(1,"SDL_JoyDeviceEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_joyhatevent)
{
	SDL_JoyHatEvent *pMyPointer ;
	pMyPointer = (SDL_JoyHatEvent *) RING_API_MALLOC(sizeof(SDL_JoyHatEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_JoyHatEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_joyhatevent)
{
	SDL_JoyHatEvent *pMyPointer ;
	pMyPointer = (SDL_JoyHatEvent *) RING_API_MALLOC(sizeof(SDL_JoyHatEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_JoyHatEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_joyhatevent)
{
	SDL_JoyHatEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_JoyHatEvent*) RING_API_GETCPOINTER(1,"SDL_JoyHatEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_keyboardevent)
{
	SDL_KeyboardEvent *pMyPointer ;
	pMyPointer = (SDL_KeyboardEvent *) RING_API_MALLOC(sizeof(SDL_KeyboardEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_KeyboardEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_keyboardevent)
{
	SDL_KeyboardEvent *pMyPointer ;
	pMyPointer = (SDL_KeyboardEvent *) RING_API_MALLOC(sizeof(SDL_KeyboardEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_KeyboardEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_keyboardevent)
{
	SDL_KeyboardEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_KeyboardEvent*) RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_keyboardevent_type)
{
	SDL_KeyboardEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_keyboardevent_type)
{
	SDL_KeyboardEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_keyboardevent_timestamp)
{
	SDL_KeyboardEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_keyboardevent_timestamp)
{
	SDL_KeyboardEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_keyboardevent_windowID)
{
	SDL_KeyboardEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_keyboardevent_windowID)
{
	SDL_KeyboardEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_keyboardevent_state)
{
	SDL_KeyboardEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	RING_API_RETNUMBER(pMyPointer->state);
}

RING_FUNC(ring_sdl_set_sdl_keyboardevent_state)
{
	SDL_KeyboardEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	pMyPointer->state = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_keyboardevent_repeat)
{
	SDL_KeyboardEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	RING_API_RETNUMBER(pMyPointer->repeat);
}

RING_FUNC(ring_sdl_set_sdl_keyboardevent_repeat)
{
	SDL_KeyboardEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_KeyboardEvent");
	pMyPointer->repeat = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_mousebuttonevent)
{
	SDL_MouseButtonEvent *pMyPointer ;
	pMyPointer = (SDL_MouseButtonEvent *) RING_API_MALLOC(sizeof(SDL_MouseButtonEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MouseButtonEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_mousebuttonevent)
{
	SDL_MouseButtonEvent *pMyPointer ;
	pMyPointer = (SDL_MouseButtonEvent *) RING_API_MALLOC(sizeof(SDL_MouseButtonEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MouseButtonEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_mousebuttonevent)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MouseButtonEvent*) RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_type)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_type)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_timestamp)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_timestamp)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_windowID)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_windowID)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_which)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->which);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_which)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->which = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_button)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->button);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_button)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->button = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_state)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->state);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_state)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->state = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_clicks)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->clicks);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_clicks)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->clicks = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_x)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_x)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonevent_y)
{
	SDL_MouseButtonEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_sdl_set_sdl_mousebuttonevent_y)
{
	SDL_MouseButtonEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseButtonEvent");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_mousemotionevent)
{
	SDL_MouseMotionEvent *pMyPointer ;
	pMyPointer = (SDL_MouseMotionEvent *) RING_API_MALLOC(sizeof(SDL_MouseMotionEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MouseMotionEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_mousemotionevent)
{
	SDL_MouseMotionEvent *pMyPointer ;
	pMyPointer = (SDL_MouseMotionEvent *) RING_API_MALLOC(sizeof(SDL_MouseMotionEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MouseMotionEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_mousemotionevent)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MouseMotionEvent*) RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_type)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_type)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_timestamp)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_timestamp)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_windowID)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_windowID)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_which)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->which);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_which)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->which = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_state)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->state);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_state)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->state = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_x)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_x)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_y)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_y)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_xrel)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->xrel);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_xrel)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->xrel = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousemotionevent_yrel)
{
	SDL_MouseMotionEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	RING_API_RETNUMBER(pMyPointer->yrel);
}

RING_FUNC(ring_sdl_set_sdl_mousemotionevent_yrel)
{
	SDL_MouseMotionEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseMotionEvent");
	pMyPointer->yrel = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_mousewheelevent)
{
	SDL_MouseWheelEvent *pMyPointer ;
	pMyPointer = (SDL_MouseWheelEvent *) RING_API_MALLOC(sizeof(SDL_MouseWheelEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MouseWheelEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_mousewheelevent)
{
	SDL_MouseWheelEvent *pMyPointer ;
	pMyPointer = (SDL_MouseWheelEvent *) RING_API_MALLOC(sizeof(SDL_MouseWheelEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MouseWheelEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_mousewheelevent)
{
	SDL_MouseWheelEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MouseWheelEvent*) RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_mousewheelevent_type)
{
	SDL_MouseWheelEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_mousewheelevent_type)
{
	SDL_MouseWheelEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousewheelevent_timestamp)
{
	SDL_MouseWheelEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_mousewheelevent_timestamp)
{
	SDL_MouseWheelEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousewheelevent_windowID)
{
	SDL_MouseWheelEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_mousewheelevent_windowID)
{
	SDL_MouseWheelEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousewheelevent_which)
{
	SDL_MouseWheelEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	RING_API_RETNUMBER(pMyPointer->which);
}

RING_FUNC(ring_sdl_set_sdl_mousewheelevent_which)
{
	SDL_MouseWheelEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	pMyPointer->which = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousewheelevent_x)
{
	SDL_MouseWheelEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	RING_API_RETNUMBER(pMyPointer->x);
}

RING_FUNC(ring_sdl_set_sdl_mousewheelevent_x)
{
	SDL_MouseWheelEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	pMyPointer->x = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_mousewheelevent_y)
{
	SDL_MouseWheelEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	RING_API_RETNUMBER(pMyPointer->y);
}

RING_FUNC(ring_sdl_set_sdl_mousewheelevent_y)
{
	SDL_MouseWheelEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MouseWheelEvent");
	pMyPointer->y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_multigestureevent)
{
	SDL_MultiGestureEvent *pMyPointer ;
	pMyPointer = (SDL_MultiGestureEvent *) RING_API_MALLOC(sizeof(SDL_MultiGestureEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MultiGestureEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_multigestureevent)
{
	SDL_MultiGestureEvent *pMyPointer ;
	pMyPointer = (SDL_MultiGestureEvent *) RING_API_MALLOC(sizeof(SDL_MultiGestureEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_MultiGestureEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_multigestureevent)
{
	SDL_MultiGestureEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_MultiGestureEvent*) RING_API_GETCPOINTER(1,"SDL_MultiGestureEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_quitevent)
{
	SDL_QuitEvent *pMyPointer ;
	pMyPointer = (SDL_QuitEvent *) RING_API_MALLOC(sizeof(SDL_QuitEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_QuitEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_quitevent)
{
	SDL_QuitEvent *pMyPointer ;
	pMyPointer = (SDL_QuitEvent *) RING_API_MALLOC(sizeof(SDL_QuitEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_QuitEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_quitevent)
{
	SDL_QuitEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_QuitEvent*) RING_API_GETCPOINTER(1,"SDL_QuitEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_texteditingevent)
{
	SDL_TextEditingEvent *pMyPointer ;
	pMyPointer = (SDL_TextEditingEvent *) RING_API_MALLOC(sizeof(SDL_TextEditingEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_TextEditingEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_texteditingevent)
{
	SDL_TextEditingEvent *pMyPointer ;
	pMyPointer = (SDL_TextEditingEvent *) RING_API_MALLOC(sizeof(SDL_TextEditingEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_TextEditingEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_texteditingevent)
{
	SDL_TextEditingEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_TextEditingEvent*) RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_texteditingevent_type)
{
	SDL_TextEditingEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_texteditingevent_type)
{
	SDL_TextEditingEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_texteditingevent_timestamp)
{
	SDL_TextEditingEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_texteditingevent_timestamp)
{
	SDL_TextEditingEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_texteditingevent_windowID)
{
	SDL_TextEditingEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_texteditingevent_windowID)
{
	SDL_TextEditingEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_texteditingevent_start)
{
	SDL_TextEditingEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	RING_API_RETNUMBER(pMyPointer->start);
}

RING_FUNC(ring_sdl_set_sdl_texteditingevent_start)
{
	SDL_TextEditingEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	pMyPointer->start = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_texteditingevent_length)
{
	SDL_TextEditingEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	RING_API_RETNUMBER(pMyPointer->length);
}

RING_FUNC(ring_sdl_set_sdl_texteditingevent_length)
{
	SDL_TextEditingEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextEditingEvent");
	pMyPointer->length = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_textinputevent)
{
	SDL_TextInputEvent *pMyPointer ;
	pMyPointer = (SDL_TextInputEvent *) RING_API_MALLOC(sizeof(SDL_TextInputEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_TextInputEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_textinputevent)
{
	SDL_TextInputEvent *pMyPointer ;
	pMyPointer = (SDL_TextInputEvent *) RING_API_MALLOC(sizeof(SDL_TextInputEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_TextInputEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_textinputevent)
{
	SDL_TextInputEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_TextInputEvent*) RING_API_GETCPOINTER(1,"SDL_TextInputEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_textinputevent_type)
{
	SDL_TextInputEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextInputEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_textinputevent_type)
{
	SDL_TextInputEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextInputEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_textinputevent_timestamp)
{
	SDL_TextInputEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextInputEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_textinputevent_timestamp)
{
	SDL_TextInputEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextInputEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_textinputevent_windowID)
{
	SDL_TextInputEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextInputEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_textinputevent_windowID)
{
	SDL_TextInputEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_TextInputEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_userevent)
{
	SDL_UserEvent *pMyPointer ;
	pMyPointer = (SDL_UserEvent *) RING_API_MALLOC(sizeof(SDL_UserEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_UserEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_userevent)
{
	SDL_UserEvent *pMyPointer ;
	pMyPointer = (SDL_UserEvent *) RING_API_MALLOC(sizeof(SDL_UserEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_UserEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_userevent)
{
	SDL_UserEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_UserEvent*) RING_API_GETCPOINTER(1,"SDL_UserEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_userevent_type)
{
	SDL_UserEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_userevent_type)
{
	SDL_UserEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_userevent_timestamp)
{
	SDL_UserEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_userevent_timestamp)
{
	SDL_UserEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_userevent_windowID)
{
	SDL_UserEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_userevent_windowID)
{
	SDL_UserEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_userevent_code)
{
	SDL_UserEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	RING_API_RETNUMBER(pMyPointer->code);
}

RING_FUNC(ring_sdl_set_sdl_userevent_code)
{
	SDL_UserEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	pMyPointer->code = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_userevent_data1)
{
	SDL_UserEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	RING_API_RETCPOINTER(pMyPointer->data1,"void");
}

RING_FUNC(ring_sdl_set_sdl_userevent_data1)
{
	SDL_UserEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	pMyPointer->data1 = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_sdl_get_sdl_userevent_data2)
{
	SDL_UserEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	RING_API_RETCPOINTER(pMyPointer->data2,"void");
}

RING_FUNC(ring_sdl_set_sdl_userevent_data2)
{
	SDL_UserEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_UserEvent");
	pMyPointer->data2 = (void *) RING_API_GETCPOINTER(2,"void");
}

RING_FUNC(ring_sdl_new_sdl_windowevent)
{
	SDL_WindowEvent *pMyPointer ;
	pMyPointer = (SDL_WindowEvent *) RING_API_MALLOC(sizeof(SDL_WindowEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_WindowEvent");
}

RING_FUNC(ring_sdl_new_managed_sdl_windowevent)
{
	SDL_WindowEvent *pMyPointer ;
	pMyPointer = (SDL_WindowEvent *) RING_API_MALLOC(sizeof(SDL_WindowEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_WindowEvent",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_windowevent)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_WindowEvent*) RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_sdl_windowevent_type)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	RING_API_RETNUMBER(pMyPointer->type);
}

RING_FUNC(ring_sdl_set_sdl_windowevent_type)
{
	SDL_WindowEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	pMyPointer->type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_windowevent_timestamp)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	RING_API_RETNUMBER(pMyPointer->timestamp);
}

RING_FUNC(ring_sdl_set_sdl_windowevent_timestamp)
{
	SDL_WindowEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	pMyPointer->timestamp = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_windowevent_windowID)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	RING_API_RETNUMBER(pMyPointer->windowID);
}

RING_FUNC(ring_sdl_set_sdl_windowevent_windowID)
{
	SDL_WindowEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	pMyPointer->windowID = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_windowevent_event)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	RING_API_RETNUMBER(pMyPointer->event);
}

RING_FUNC(ring_sdl_set_sdl_windowevent_event)
{
	SDL_WindowEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	pMyPointer->event = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_windowevent_data1)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	RING_API_RETNUMBER(pMyPointer->data1);
}

RING_FUNC(ring_sdl_set_sdl_windowevent_data1)
{
	SDL_WindowEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	pMyPointer->data1 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_sdl_windowevent_data2)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	RING_API_RETNUMBER(pMyPointer->data2);
}

RING_FUNC(ring_sdl_set_sdl_windowevent_data2)
{
	SDL_WindowEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	pMyPointer->data2 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdl_keysym)
{
	SDL_Keysym *pMyPointer ;
	pMyPointer = (SDL_Keysym *) RING_API_MALLOC(sizeof(SDL_Keysym)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Keysym");
}

RING_FUNC(ring_sdl_new_managed_sdl_keysym)
{
	SDL_Keysym *pMyPointer ;
	pMyPointer = (SDL_Keysym *) RING_API_MALLOC(sizeof(SDL_Keysym)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_Keysym",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_keysym)
{
	SDL_Keysym *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_Keysym*) RING_API_GETCPOINTER(1,"SDL_Keysym");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticcondition)
{
	SDL_HapticCondition *pMyPointer ;
	pMyPointer = (SDL_HapticCondition *) RING_API_MALLOC(sizeof(SDL_HapticCondition)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticCondition");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticcondition)
{
	SDL_HapticCondition *pMyPointer ;
	pMyPointer = (SDL_HapticCondition *) RING_API_MALLOC(sizeof(SDL_HapticCondition)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticCondition",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticcondition)
{
	SDL_HapticCondition *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticCondition*) RING_API_GETCPOINTER(1,"SDL_HapticCondition");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticconstant)
{
	SDL_HapticConstant *pMyPointer ;
	pMyPointer = (SDL_HapticConstant *) RING_API_MALLOC(sizeof(SDL_HapticConstant)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticConstant");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticconstant)
{
	SDL_HapticConstant *pMyPointer ;
	pMyPointer = (SDL_HapticConstant *) RING_API_MALLOC(sizeof(SDL_HapticConstant)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticConstant",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticconstant)
{
	SDL_HapticConstant *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticConstant*) RING_API_GETCPOINTER(1,"SDL_HapticConstant");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticcustom)
{
	SDL_HapticCustom *pMyPointer ;
	pMyPointer = (SDL_HapticCustom *) RING_API_MALLOC(sizeof(SDL_HapticCustom)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticCustom");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticcustom)
{
	SDL_HapticCustom *pMyPointer ;
	pMyPointer = (SDL_HapticCustom *) RING_API_MALLOC(sizeof(SDL_HapticCustom)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticCustom",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticcustom)
{
	SDL_HapticCustom *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticCustom*) RING_API_GETCPOINTER(1,"SDL_HapticCustom");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticdirection)
{
	SDL_HapticDirection *pMyPointer ;
	pMyPointer = (SDL_HapticDirection *) RING_API_MALLOC(sizeof(SDL_HapticDirection)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticDirection");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticdirection)
{
	SDL_HapticDirection *pMyPointer ;
	pMyPointer = (SDL_HapticDirection *) RING_API_MALLOC(sizeof(SDL_HapticDirection)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticDirection",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticdirection)
{
	SDL_HapticDirection *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticDirection*) RING_API_GETCPOINTER(1,"SDL_HapticDirection");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticeffect)
{
	SDL_HapticEffect *pMyPointer ;
	pMyPointer = (SDL_HapticEffect *) RING_API_MALLOC(sizeof(SDL_HapticEffect)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticEffect");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticeffect)
{
	SDL_HapticEffect *pMyPointer ;
	pMyPointer = (SDL_HapticEffect *) RING_API_MALLOC(sizeof(SDL_HapticEffect)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticEffect",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticeffect)
{
	SDL_HapticEffect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticEffect*) RING_API_GETCPOINTER(1,"SDL_HapticEffect");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticleftright)
{
	SDL_HapticLeftRight *pMyPointer ;
	pMyPointer = (SDL_HapticLeftRight *) RING_API_MALLOC(sizeof(SDL_HapticLeftRight)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticLeftRight");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticleftright)
{
	SDL_HapticLeftRight *pMyPointer ;
	pMyPointer = (SDL_HapticLeftRight *) RING_API_MALLOC(sizeof(SDL_HapticLeftRight)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticLeftRight",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticleftright)
{
	SDL_HapticLeftRight *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticLeftRight*) RING_API_GETCPOINTER(1,"SDL_HapticLeftRight");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticperiodic)
{
	SDL_HapticPeriodic *pMyPointer ;
	pMyPointer = (SDL_HapticPeriodic *) RING_API_MALLOC(sizeof(SDL_HapticPeriodic)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticPeriodic");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticperiodic)
{
	SDL_HapticPeriodic *pMyPointer ;
	pMyPointer = (SDL_HapticPeriodic *) RING_API_MALLOC(sizeof(SDL_HapticPeriodic)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticPeriodic",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticperiodic)
{
	SDL_HapticPeriodic *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticPeriodic*) RING_API_GETCPOINTER(1,"SDL_HapticPeriodic");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_hapticramp)
{
	SDL_HapticRamp *pMyPointer ;
	pMyPointer = (SDL_HapticRamp *) RING_API_MALLOC(sizeof(SDL_HapticRamp)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_HapticRamp");
}

RING_FUNC(ring_sdl_new_managed_sdl_hapticramp)
{
	SDL_HapticRamp *pMyPointer ;
	pMyPointer = (SDL_HapticRamp *) RING_API_MALLOC(sizeof(SDL_HapticRamp)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_HapticRamp",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_hapticramp)
{
	SDL_HapticRamp *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_HapticRamp*) RING_API_GETCPOINTER(1,"SDL_HapticRamp");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_audiocvt)
{
	SDL_AudioCVT *pMyPointer ;
	pMyPointer = (SDL_AudioCVT *) RING_API_MALLOC(sizeof(SDL_AudioCVT)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_AudioCVT");
}

RING_FUNC(ring_sdl_new_managed_sdl_audiocvt)
{
	SDL_AudioCVT *pMyPointer ;
	pMyPointer = (SDL_AudioCVT *) RING_API_MALLOC(sizeof(SDL_AudioCVT)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_AudioCVT",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_audiocvt)
{
	SDL_AudioCVT *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_AudioCVT*) RING_API_GETCPOINTER(1,"SDL_AudioCVT");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_audiospec)
{
	SDL_AudioSpec *pMyPointer ;
	pMyPointer = (SDL_AudioSpec *) RING_API_MALLOC(sizeof(SDL_AudioSpec)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_AudioSpec");
}

RING_FUNC(ring_sdl_new_managed_sdl_audiospec)
{
	SDL_AudioSpec *pMyPointer ;
	pMyPointer = (SDL_AudioSpec *) RING_API_MALLOC(sizeof(SDL_AudioSpec)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_AudioSpec",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_audiospec)
{
	SDL_AudioSpec *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_AudioSpec*) RING_API_GETCPOINTER(1,"SDL_AudioSpec");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdl_rwops)
{
	SDL_RWops *pMyPointer ;
	pMyPointer = (SDL_RWops *) RING_API_MALLOC(sizeof(SDL_RWops)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_RWops");
}

RING_FUNC(ring_sdl_new_managed_sdl_rwops)
{
	SDL_RWops *pMyPointer ;
	pMyPointer = (SDL_RWops *) RING_API_MALLOC(sizeof(SDL_RWops)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDL_RWops",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdl_rwops)
{
	SDL_RWops *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDL_RWops*) RING_API_GETCPOINTER(1,"SDL_RWops");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_mix_chunk)
{
	Mix_Chunk *pMyPointer ;
	pMyPointer = (Mix_Chunk *) RING_API_MALLOC(sizeof(Mix_Chunk)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Mix_Chunk");
}

RING_FUNC(ring_sdl_new_managed_mix_chunk)
{
	Mix_Chunk *pMyPointer ;
	pMyPointer = (Mix_Chunk *) RING_API_MALLOC(sizeof(Mix_Chunk)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Mix_Chunk",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_mix_chunk)
{
	Mix_Chunk *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Mix_Chunk*) RING_API_GETCPOINTER(1,"Mix_Chunk");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_mix_musictype)
{
	Mix_MusicType *pMyPointer ;
	pMyPointer = (Mix_MusicType *) RING_API_MALLOC(sizeof(Mix_MusicType)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Mix_MusicType");
}

RING_FUNC(ring_sdl_new_managed_mix_musictype)
{
	Mix_MusicType *pMyPointer ;
	pMyPointer = (Mix_MusicType *) RING_API_MALLOC(sizeof(Mix_MusicType)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Mix_MusicType",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_mix_musictype)
{
	Mix_MusicType *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Mix_MusicType*) RING_API_GETCPOINTER(1,"Mix_MusicType");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_mix_fading)
{
	Mix_Fading *pMyPointer ;
	pMyPointer = (Mix_Fading *) RING_API_MALLOC(sizeof(Mix_Fading)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"Mix_Fading");
}

RING_FUNC(ring_sdl_new_managed_mix_fading)
{
	Mix_Fading *pMyPointer ;
	pMyPointer = (Mix_Fading *) RING_API_MALLOC(sizeof(Mix_Fading)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"Mix_Fading",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_mix_fading)
{
	Mix_Fading *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (Mix_Fading*) RING_API_GETCPOINTER(1,"Mix_Fading");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_ipaddress)
{
	IPaddress *pMyPointer ;
	pMyPointer = (IPaddress *) RING_API_MALLOC(sizeof(IPaddress)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"IPaddress");
}

RING_FUNC(ring_sdl_new_managed_ipaddress)
{
	IPaddress *pMyPointer ;
	pMyPointer = (IPaddress *) RING_API_MALLOC(sizeof(IPaddress)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"IPaddress",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_ipaddress)
{
	IPaddress *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (IPaddress*) RING_API_GETCPOINTER(1,"IPaddress");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_ipaddress_host)
{
	IPaddress *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"IPaddress");
	RING_API_RETNUMBER(pMyPointer->host);
}

RING_FUNC(ring_sdl_set_ipaddress_host)
{
	IPaddress *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"IPaddress");
	pMyPointer->host = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_ipaddress_port)
{
	IPaddress *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"IPaddress");
	RING_API_RETNUMBER(pMyPointer->port);
}

RING_FUNC(ring_sdl_set_ipaddress_port)
{
	IPaddress *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"IPaddress");
	pMyPointer->port = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_tcpsocket)
{
	TCPsocket *pMyPointer ;
	pMyPointer = (TCPsocket *) RING_API_MALLOC(sizeof(TCPsocket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"TCPsocket");
}

RING_FUNC(ring_sdl_new_managed_tcpsocket)
{
	TCPsocket *pMyPointer ;
	pMyPointer = (TCPsocket *) RING_API_MALLOC(sizeof(TCPsocket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"TCPsocket",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_tcpsocket)
{
	TCPsocket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (TCPsocket*) RING_API_GETCPOINTER(1,"TCPsocket");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_udpsocket)
{
	UDPsocket *pMyPointer ;
	pMyPointer = (UDPsocket *) RING_API_MALLOC(sizeof(UDPsocket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"UDPsocket");
}

RING_FUNC(ring_sdl_new_managed_udpsocket)
{
	UDPsocket *pMyPointer ;
	pMyPointer = (UDPsocket *) RING_API_MALLOC(sizeof(UDPsocket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"UDPsocket",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_udpsocket)
{
	UDPsocket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (UDPsocket*) RING_API_GETCPOINTER(1,"UDPsocket");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_udppacket)
{
	UDPpacket *pMyPointer ;
	pMyPointer = (UDPpacket *) RING_API_MALLOC(sizeof(UDPpacket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"UDPpacket");
}

RING_FUNC(ring_sdl_new_managed_udppacket)
{
	UDPpacket *pMyPointer ;
	pMyPointer = (UDPpacket *) RING_API_MALLOC(sizeof(UDPpacket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"UDPpacket",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_udppacket)
{
	UDPpacket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (UDPpacket*) RING_API_GETCPOINTER(1,"UDPpacket");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_udppacket_channel)
{
	UDPpacket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	RING_API_RETNUMBER(pMyPointer->channel);
}

RING_FUNC(ring_sdl_set_udppacket_channel)
{
	UDPpacket *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	pMyPointer->channel = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_udppacket_data)
{
	UDPpacket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	RING_API_RETCPOINTER(pMyPointer->data,"Uint8");
}

RING_FUNC(ring_sdl_set_udppacket_data)
{
	UDPpacket *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	pMyPointer->data = (Uint8 *) RING_API_GETCPOINTER(2,"Uint8");
}

RING_FUNC(ring_sdl_get_udppacket_len)
{
	UDPpacket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	RING_API_RETNUMBER(pMyPointer->len);
}

RING_FUNC(ring_sdl_set_udppacket_len)
{
	UDPpacket *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	pMyPointer->len = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_udppacket_maxlen)
{
	UDPpacket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	RING_API_RETNUMBER(pMyPointer->maxlen);
}

RING_FUNC(ring_sdl_set_udppacket_maxlen)
{
	UDPpacket *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	pMyPointer->maxlen = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_get_udppacket_status)
{
	UDPpacket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	RING_API_RETNUMBER(pMyPointer->status);
}

RING_FUNC(ring_sdl_set_udppacket_status)
{
	UDPpacket *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"UDPpacket");
	pMyPointer->status = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_sdl_new_sdlnet_socketset)
{
	SDLNet_SocketSet *pMyPointer ;
	pMyPointer = (SDLNet_SocketSet *) RING_API_MALLOC(sizeof(SDLNet_SocketSet)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDLNet_SocketSet");
}

RING_FUNC(ring_sdl_new_managed_sdlnet_socketset)
{
	SDLNet_SocketSet *pMyPointer ;
	pMyPointer = (SDLNet_SocketSet *) RING_API_MALLOC(sizeof(SDLNet_SocketSet)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDLNet_SocketSet",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdlnet_socketset)
{
	SDLNet_SocketSet *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDLNet_SocketSet*) RING_API_GETCPOINTER(1,"SDLNet_SocketSet");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_new_sdlnet_genericsocket)
{
	SDLNet_GenericSocket *pMyPointer ;
	pMyPointer = (SDLNet_GenericSocket *) RING_API_MALLOC(sizeof(SDLNet_GenericSocket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDLNet_GenericSocket");
}

RING_FUNC(ring_sdl_new_managed_sdlnet_genericsocket)
{
	SDLNet_GenericSocket *pMyPointer ;
	pMyPointer = (SDLNet_GenericSocket *) RING_API_MALLOC(sizeof(SDLNet_GenericSocket)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"SDLNet_GenericSocket",RING_API_FREEFUNC);
}

RING_FUNC(ring_sdl_destroy_sdlnet_genericsocket)
{
	SDLNet_GenericSocket *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (SDLNet_GenericSocket*) RING_API_GETCPOINTER(1,"SDLNet_GenericSocket");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_sdl_get_mix_default_format)
{
	RING_API_RETNUMBER(MIX_DEFAULT_FORMAT);
}

RING_FUNC(ring_sdl_get_sdl_quit)
{
	RING_API_RETNUMBER(SDL_QUIT);
}

RING_FUNC(ring_sdl_get_sdl_button_left)
{
	RING_API_RETNUMBER(SDL_BUTTON_LEFT);
}

RING_FUNC(ring_sdl_get_sdl_button_middle)
{
	RING_API_RETNUMBER(SDL_BUTTON_MIDDLE);
}

RING_FUNC(ring_sdl_get_sdl_button_right)
{
	RING_API_RETNUMBER(SDL_BUTTON_RIGHT);
}

RING_FUNC(ring_sdl_get_sdl_pressed)
{
	RING_API_RETNUMBER(SDL_PRESSED);
}

RING_FUNC(ring_sdl_get_sdl_released)
{
	RING_API_RETNUMBER(SDL_RELEASED);
}

RING_FUNC(ring_sdl_get_sdl_app_terminating)
{
	RING_API_RETNUMBER(SDL_APP_TERMINATING);
}

RING_FUNC(ring_sdl_get_sdl_app_lowmemory)
{
	RING_API_RETNUMBER(SDL_APP_LOWMEMORY);
}

RING_FUNC(ring_sdl_get_sdl_app_willenterbackground)
{
	RING_API_RETNUMBER(SDL_APP_WILLENTERBACKGROUND);
}

RING_FUNC(ring_sdl_get_sdl_app_didenterbackground)
{
	RING_API_RETNUMBER(SDL_APP_DIDENTERBACKGROUND);
}

RING_FUNC(ring_sdl_get_sdl_app_willenterforeground)
{
	RING_API_RETNUMBER(SDL_APP_WILLENTERFOREGROUND);
}

RING_FUNC(ring_sdl_get_sdl_app_didenterforeground)
{
	RING_API_RETNUMBER(SDL_APP_DIDENTERFOREGROUND);
}

RING_FUNC(ring_sdl_get_sdl_windowevent)
{
	RING_API_RETNUMBER(SDL_WINDOWEVENT);
}

RING_FUNC(ring_sdl_get_sdl_keydown)
{
	RING_API_RETNUMBER(SDL_KEYDOWN);
}

RING_FUNC(ring_sdl_get_sdl_keyup)
{
	RING_API_RETNUMBER(SDL_KEYUP);
}

RING_FUNC(ring_sdl_get_sdl_textediting)
{
	RING_API_RETNUMBER(SDL_TEXTEDITING);
}

RING_FUNC(ring_sdl_get_sdl_textinput)
{
	RING_API_RETNUMBER(SDL_TEXTINPUT);
}

RING_FUNC(ring_sdl_get_sdl_mousemotion)
{
	RING_API_RETNUMBER(SDL_MOUSEMOTION);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttondown)
{
	RING_API_RETNUMBER(SDL_MOUSEBUTTONDOWN);
}

RING_FUNC(ring_sdl_get_sdl_mousebuttonup)
{
	RING_API_RETNUMBER(SDL_MOUSEBUTTONUP);
}

RING_FUNC(ring_sdl_get_sdl_mousewheel)
{
	RING_API_RETNUMBER(SDL_MOUSEWHEEL);
}

RING_FUNC(ring_sdl_get_sdl_joyaxismotion)
{
	RING_API_RETNUMBER(SDL_JOYAXISMOTION);
}

RING_FUNC(ring_sdl_get_sdl_joyballmotion)
{
	RING_API_RETNUMBER(SDL_JOYBALLMOTION);
}

RING_FUNC(ring_sdl_get_sdl_joyhatmotion)
{
	RING_API_RETNUMBER(SDL_JOYHATMOTION);
}

RING_FUNC(ring_sdl_get_sdl_joybuttondown)
{
	RING_API_RETNUMBER(SDL_JOYBUTTONDOWN);
}

RING_FUNC(ring_sdl_get_sdl_joybuttonup)
{
	RING_API_RETNUMBER(SDL_JOYBUTTONUP);
}

RING_FUNC(ring_sdl_get_sdl_joydeviceadded)
{
	RING_API_RETNUMBER(SDL_JOYDEVICEADDED);
}

RING_FUNC(ring_sdl_get_sdl_joydeviceremoved)
{
	RING_API_RETNUMBER(SDL_JOYDEVICEREMOVED);
}

RING_FUNC(ring_sdl_get_sdl_controlleraxismotion)
{
	RING_API_RETNUMBER(SDL_CONTROLLERAXISMOTION);
}

RING_FUNC(ring_sdl_get_sdl_controllerbuttondown)
{
	RING_API_RETNUMBER(SDL_CONTROLLERBUTTONDOWN);
}

RING_FUNC(ring_sdl_get_sdl_controllerbuttonup)
{
	RING_API_RETNUMBER(SDL_CONTROLLERBUTTONUP);
}

RING_FUNC(ring_sdl_get_sdl_controllerdeviceadded)
{
	RING_API_RETNUMBER(SDL_CONTROLLERDEVICEADDED);
}

RING_FUNC(ring_sdl_get_sdl_controllerdeviceremoved)
{
	RING_API_RETNUMBER(SDL_CONTROLLERDEVICEREMOVED);
}

RING_FUNC(ring_sdl_get_sdl_controllerdeviceremapped)
{
	RING_API_RETNUMBER(SDL_CONTROLLERDEVICEREMAPPED);
}

RING_FUNC(ring_sdl_get_sdl_fingerdown)
{
	RING_API_RETNUMBER(SDL_FINGERDOWN);
}

RING_FUNC(ring_sdl_get_sdl_fingerup)
{
	RING_API_RETNUMBER(SDL_FINGERUP);
}

RING_FUNC(ring_sdl_get_sdl_fingermotion)
{
	RING_API_RETNUMBER(SDL_FINGERMOTION);
}

RING_FUNC(ring_sdl_get_sdl_dollargesture)
{
	RING_API_RETNUMBER(SDL_DOLLARGESTURE);
}

RING_FUNC(ring_sdl_get_sdl_dollarrecord)
{
	RING_API_RETNUMBER(SDL_DOLLARRECORD);
}

RING_FUNC(ring_sdl_get_sdl_multigesture)
{
	RING_API_RETNUMBER(SDL_MULTIGESTURE);
}

RING_FUNC(ring_sdl_get_sdl_clipboardupdate)
{
	RING_API_RETNUMBER(SDL_CLIPBOARDUPDATE);
}

RING_FUNC(ring_sdl_get_sdl_dropfile)
{
	RING_API_RETNUMBER(SDL_DROPFILE);
}

RING_FUNC(ring_sdl_get_sdl_render_targets_reset)
{
	RING_API_RETNUMBER(SDL_RENDER_TARGETS_RESET);
}

RING_FUNC(ring_sdl_get_sdl_userevent)
{
	RING_API_RETNUMBER(SDL_USEREVENT);
}

RING_FUNC(ring_sdl_get_sdl_lastevent)
{
	RING_API_RETNUMBER(SDL_LASTEVENT);
}

RING_FUNC(ring_sdl_get_sdl_net_major_version)
{
	RING_API_RETNUMBER(SDL_NET_MAJOR_VERSION);
}

RING_FUNC(ring_sdl_get_sdl_net_minor_version)
{
	RING_API_RETNUMBER(SDL_NET_MINOR_VERSION);
}

RING_FUNC(ring_sdl_get_sdl_net_patchlevel)
{
	RING_API_RETNUMBER(SDL_NET_PATCHLEVEL);
}

RING_FUNC(ring_sdl_get_inaddr_any)
{
	RING_API_RETNUMBER(INADDR_ANY);
}

RING_FUNC(ring_sdl_get_inaddr_none)
{
	RING_API_RETNUMBER(INADDR_NONE);
}

RING_FUNC(ring_sdl_get_inaddr_broadcast)
{
	RING_API_RETNUMBER(INADDR_BROADCAST);
}

RING_FUNC(ring_sdl_get_sdlnet_max_udpchannels)
{
	RING_API_RETNUMBER(SDLNET_MAX_UDPCHANNELS);
}

RING_FUNC(ring_sdl_get_sdlnet_max_udpaddresses)
{
	RING_API_RETNUMBER(SDLNET_MAX_UDPADDRESSES);
}

RING_FUNC(ring_sdl_get_sdlk_0)
{
	RING_API_RETNUMBER(SDLK_0);
}

RING_FUNC(ring_sdl_get_sdlk_1)
{
	RING_API_RETNUMBER(SDLK_1);
}

RING_FUNC(ring_sdl_get_sdlk_2)
{
	RING_API_RETNUMBER(SDLK_2);
}

RING_FUNC(ring_sdl_get_sdlk_3)
{
	RING_API_RETNUMBER(SDLK_3);
}

RING_FUNC(ring_sdl_get_sdlk_4)
{
	RING_API_RETNUMBER(SDLK_4);
}

RING_FUNC(ring_sdl_get_sdlk_5)
{
	RING_API_RETNUMBER(SDLK_5);
}

RING_FUNC(ring_sdl_get_sdlk_6)
{
	RING_API_RETNUMBER(SDLK_6);
}

RING_FUNC(ring_sdl_get_sdlk_7)
{
	RING_API_RETNUMBER(SDLK_7);
}

RING_FUNC(ring_sdl_get_sdlk_8)
{
	RING_API_RETNUMBER(SDLK_8);
}

RING_FUNC(ring_sdl_get_sdlk_9)
{
	RING_API_RETNUMBER(SDLK_9);
}

RING_FUNC(ring_sdl_get_sdlk_a)
{
	RING_API_RETNUMBER(SDLK_a);
}

RING_FUNC(ring_sdl_get_sdlk_ac_back)
{
	RING_API_RETNUMBER(SDLK_AC_BACK);
}

RING_FUNC(ring_sdl_get_sdlk_ac_bookmarks)
{
	RING_API_RETNUMBER(SDLK_AC_BOOKMARKS);
}

RING_FUNC(ring_sdl_get_sdlk_ac_forward)
{
	RING_API_RETNUMBER(SDLK_AC_FORWARD);
}

RING_FUNC(ring_sdl_get_sdlk_ac_home)
{
	RING_API_RETNUMBER(SDLK_AC_HOME);
}

RING_FUNC(ring_sdl_get_sdlk_ac_refresh)
{
	RING_API_RETNUMBER(SDLK_AC_REFRESH);
}

RING_FUNC(ring_sdl_get_sdlk_ac_search)
{
	RING_API_RETNUMBER(SDLK_AC_SEARCH);
}

RING_FUNC(ring_sdl_get_sdlk_ac_stop)
{
	RING_API_RETNUMBER(SDLK_AC_STOP);
}

RING_FUNC(ring_sdl_get_sdlk_again)
{
	RING_API_RETNUMBER(SDLK_AGAIN);
}

RING_FUNC(ring_sdl_get_sdlk_alterase)
{
	RING_API_RETNUMBER(SDLK_ALTERASE);
}

RING_FUNC(ring_sdl_get_sdlk_quote)
{
	RING_API_RETNUMBER(SDLK_QUOTE);
}

RING_FUNC(ring_sdl_get_sdlk_application)
{
	RING_API_RETNUMBER(SDLK_APPLICATION);
}

RING_FUNC(ring_sdl_get_sdlk_audiomute)
{
	RING_API_RETNUMBER(SDLK_AUDIOMUTE);
}

RING_FUNC(ring_sdl_get_sdlk_audionext)
{
	RING_API_RETNUMBER(SDLK_AUDIONEXT);
}

RING_FUNC(ring_sdl_get_sdlk_audioplay)
{
	RING_API_RETNUMBER(SDLK_AUDIOPLAY);
}

RING_FUNC(ring_sdl_get_sdlk_audioprev)
{
	RING_API_RETNUMBER(SDLK_AUDIOPREV);
}

RING_FUNC(ring_sdl_get_sdlk_brightnessdown)
{
	RING_API_RETNUMBER(SDLK_BRIGHTNESSDOWN);
}

RING_FUNC(ring_sdl_get_sdlk_brightnessup)
{
	RING_API_RETNUMBER(SDLK_BRIGHTNESSUP);
}

RING_FUNC(ring_sdl_get_sdlk_c)
{
	RING_API_RETNUMBER(SDLK_c);
}

RING_FUNC(ring_sdl_get_sdlk_calculator)
{
	RING_API_RETNUMBER(SDLK_CALCULATOR);
}

RING_FUNC(ring_sdl_get_sdlk_cancel)
{
	RING_API_RETNUMBER(SDLK_CANCEL);
}

RING_FUNC(ring_sdl_get_sdlk_capslock)
{
	RING_API_RETNUMBER(SDLK_CAPSLOCK);
}

RING_FUNC(ring_sdl_get_sdlk_clear)
{
	RING_API_RETNUMBER(SDLK_CLEAR);
}

RING_FUNC(ring_sdl_get_sdlk_clearagain)
{
	RING_API_RETNUMBER(SDLK_CLEARAGAIN);
}

RING_FUNC(ring_sdl_get_sdlk_comma)
{
	RING_API_RETNUMBER(SDLK_COMMA);
}

RING_FUNC(ring_sdl_get_sdlk_computer)
{
	RING_API_RETNUMBER(SDLK_COMPUTER);
}

RING_FUNC(ring_sdl_get_sdlk_copy)
{
	RING_API_RETNUMBER(SDLK_COPY);
}

RING_FUNC(ring_sdl_get_sdlk_crsel)
{
	RING_API_RETNUMBER(SDLK_CRSEL);
}

RING_FUNC(ring_sdl_get_sdlk_currencysubunit)
{
	RING_API_RETNUMBER(SDLK_CURRENCYSUBUNIT);
}

RING_FUNC(ring_sdl_get_sdlk_currencyunit)
{
	RING_API_RETNUMBER(SDLK_CURRENCYUNIT);
}

RING_FUNC(ring_sdl_get_sdlk_cut)
{
	RING_API_RETNUMBER(SDLK_CUT);
}

RING_FUNC(ring_sdl_get_sdlk_d)
{
	RING_API_RETNUMBER(SDLK_d);
}

RING_FUNC(ring_sdl_get_sdlk_decimalseparator)
{
	RING_API_RETNUMBER(SDLK_DECIMALSEPARATOR);
}

RING_FUNC(ring_sdl_get_sdlk_delete)
{
	RING_API_RETNUMBER(SDLK_DELETE);
}

RING_FUNC(ring_sdl_get_sdlk_displayswitch)
{
	RING_API_RETNUMBER(SDLK_DISPLAYSWITCH);
}

RING_FUNC(ring_sdl_get_sdlk_down)
{
	RING_API_RETNUMBER(SDLK_DOWN);
}

RING_FUNC(ring_sdl_get_sdlk_e)
{
	RING_API_RETNUMBER(SDLK_e);
}

RING_FUNC(ring_sdl_get_sdlk_eject)
{
	RING_API_RETNUMBER(SDLK_EJECT);
}

RING_FUNC(ring_sdl_get_sdlk_end)
{
	RING_API_RETNUMBER(SDLK_END);
}

RING_FUNC(ring_sdl_get_sdlk_equals)
{
	RING_API_RETNUMBER(SDLK_EQUALS);
}

RING_FUNC(ring_sdl_get_sdlk_escape)
{
	RING_API_RETNUMBER(SDLK_ESCAPE);
}

RING_FUNC(ring_sdl_get_sdlk_execute)
{
	RING_API_RETNUMBER(SDLK_EXECUTE);
}

RING_FUNC(ring_sdl_get_sdlk_exsel)
{
	RING_API_RETNUMBER(SDLK_EXSEL);
}

RING_FUNC(ring_sdl_get_sdlk_f)
{
	RING_API_RETNUMBER(SDLK_f);
}

RING_FUNC(ring_sdl_get_sdlk_f1)
{
	RING_API_RETNUMBER(SDLK_F1);
}

RING_FUNC(ring_sdl_get_sdlk_f10)
{
	RING_API_RETNUMBER(SDLK_F10);
}

RING_FUNC(ring_sdl_get_sdlk_f11)
{
	RING_API_RETNUMBER(SDLK_F11);
}

RING_FUNC(ring_sdl_get_sdlk_f12)
{
	RING_API_RETNUMBER(SDLK_F12);
}

RING_FUNC(ring_sdl_get_sdlk_f13)
{
	RING_API_RETNUMBER(SDLK_F13);
}

RING_FUNC(ring_sdl_get_sdlk_f14)
{
	RING_API_RETNUMBER(SDLK_F14);
}

RING_FUNC(ring_sdl_get_sdlk_f15)
{
	RING_API_RETNUMBER(SDLK_F15);
}

RING_FUNC(ring_sdl_get_sdlk_f16)
{
	RING_API_RETNUMBER(SDLK_F16);
}

RING_FUNC(ring_sdl_get_sdlk_f17)
{
	RING_API_RETNUMBER(SDLK_F17);
}

RING_FUNC(ring_sdl_get_sdlk_f18)
{
	RING_API_RETNUMBER(SDLK_F18);
}

RING_FUNC(ring_sdl_get_sdlk_f19)
{
	RING_API_RETNUMBER(SDLK_F19);
}

RING_FUNC(ring_sdl_get_sdlk_f2)
{
	RING_API_RETNUMBER(SDLK_F2);
}

RING_FUNC(ring_sdl_get_sdlk_f20)
{
	RING_API_RETNUMBER(SDLK_F20);
}

RING_FUNC(ring_sdl_get_sdlk_f21)
{
	RING_API_RETNUMBER(SDLK_F21);
}

RING_FUNC(ring_sdl_get_sdlk_f22)
{
	RING_API_RETNUMBER(SDLK_F22);
}

RING_FUNC(ring_sdl_get_sdlk_f23)
{
	RING_API_RETNUMBER(SDLK_F23);
}

RING_FUNC(ring_sdl_get_sdlk_f24)
{
	RING_API_RETNUMBER(SDLK_F24);
}

RING_FUNC(ring_sdl_get_sdlk_f3)
{
	RING_API_RETNUMBER(SDLK_F3);
}

RING_FUNC(ring_sdl_get_sdlk_f4)
{
	RING_API_RETNUMBER(SDLK_F4);
}

RING_FUNC(ring_sdl_get_sdlk_f5)
{
	RING_API_RETNUMBER(SDLK_F5);
}

RING_FUNC(ring_sdl_get_sdlk_f6)
{
	RING_API_RETNUMBER(SDLK_F6);
}

RING_FUNC(ring_sdl_get_sdlk_f7)
{
	RING_API_RETNUMBER(SDLK_F7);
}

RING_FUNC(ring_sdl_get_sdlk_f8)
{
	RING_API_RETNUMBER(SDLK_F8);
}

RING_FUNC(ring_sdl_get_sdlk_f9)
{
	RING_API_RETNUMBER(SDLK_F9);
}

RING_FUNC(ring_sdl_get_sdlk_find)
{
	RING_API_RETNUMBER(SDLK_FIND);
}

RING_FUNC(ring_sdl_get_sdlk_g)
{
	RING_API_RETNUMBER(SDLK_g);
}

RING_FUNC(ring_sdl_get_sdlk_backquote)
{
	RING_API_RETNUMBER(SDLK_BACKQUOTE);
}

RING_FUNC(ring_sdl_get_sdlk_h)
{
	RING_API_RETNUMBER(SDLK_h);
}

RING_FUNC(ring_sdl_get_sdlk_help)
{
	RING_API_RETNUMBER(SDLK_HELP);
}

RING_FUNC(ring_sdl_get_sdlk_home)
{
	RING_API_RETNUMBER(SDLK_HOME);
}

RING_FUNC(ring_sdl_get_sdlk_i)
{
	RING_API_RETNUMBER(SDLK_i);
}

RING_FUNC(ring_sdl_get_sdlk_insert)
{
	RING_API_RETNUMBER(SDLK_INSERT);
}

RING_FUNC(ring_sdl_get_sdlk_j)
{
	RING_API_RETNUMBER(SDLK_j);
}

RING_FUNC(ring_sdl_get_sdlk_k)
{
	RING_API_RETNUMBER(SDLK_k);
}

RING_FUNC(ring_sdl_get_sdlk_kbdillumdown)
{
	RING_API_RETNUMBER(SDLK_KBDILLUMDOWN);
}

RING_FUNC(ring_sdl_get_sdlk_kbdillumtoggle)
{
	RING_API_RETNUMBER(SDLK_KBDILLUMTOGGLE);
}

RING_FUNC(ring_sdl_get_sdlk_kbdillumup)
{
	RING_API_RETNUMBER(SDLK_KBDILLUMUP);
}

RING_FUNC(ring_sdl_get_sdlk_kp_0)
{
	RING_API_RETNUMBER(SDLK_KP_0);
}

RING_FUNC(ring_sdl_get_sdlk_kp_00)
{
	RING_API_RETNUMBER(SDLK_KP_00);
}

RING_FUNC(ring_sdl_get_sdlk_kp_000)
{
	RING_API_RETNUMBER(SDLK_KP_000);
}

RING_FUNC(ring_sdl_get_sdlk_kp_1)
{
	RING_API_RETNUMBER(SDLK_KP_1);
}

RING_FUNC(ring_sdl_get_sdlk_kp_2)
{
	RING_API_RETNUMBER(SDLK_KP_2);
}

RING_FUNC(ring_sdl_get_sdlk_kp_3)
{
	RING_API_RETNUMBER(SDLK_KP_3);
}

RING_FUNC(ring_sdl_get_sdlk_kp_4)
{
	RING_API_RETNUMBER(SDLK_KP_4);
}

RING_FUNC(ring_sdl_get_sdlk_kp_5)
{
	RING_API_RETNUMBER(SDLK_KP_5);
}

RING_FUNC(ring_sdl_get_sdlk_kp_6)
{
	RING_API_RETNUMBER(SDLK_KP_6);
}

RING_FUNC(ring_sdl_get_sdlk_kp_7)
{
	RING_API_RETNUMBER(SDLK_KP_7);
}

RING_FUNC(ring_sdl_get_sdlk_kp_8)
{
	RING_API_RETNUMBER(SDLK_KP_8);
}

RING_FUNC(ring_sdl_get_sdlk_kp_9)
{
	RING_API_RETNUMBER(SDLK_KP_9);
}

RING_FUNC(ring_sdl_get_sdlk_kp_a)
{
	RING_API_RETNUMBER(SDLK_KP_A);
}

RING_FUNC(ring_sdl_get_sdlk_kp_ampersand)
{
	RING_API_RETNUMBER(SDLK_KP_AMPERSAND);
}

RING_FUNC(ring_sdl_get_sdlk_kp_at)
{
	RING_API_RETNUMBER(SDLK_KP_AT);
}

RING_FUNC(ring_sdl_get_sdlk_kp_b)
{
	RING_API_RETNUMBER(SDLK_KP_B);
}

RING_FUNC(ring_sdl_get_sdlk_kp_backspace)
{
	RING_API_RETNUMBER(SDLK_KP_BACKSPACE);
}

RING_FUNC(ring_sdl_get_sdlk_kp_binary)
{
	RING_API_RETNUMBER(SDLK_KP_BINARY);
}

RING_FUNC(ring_sdl_get_sdlk_kp_c)
{
	RING_API_RETNUMBER(SDLK_KP_C);
}

RING_FUNC(ring_sdl_get_sdlk_kp_clear)
{
	RING_API_RETNUMBER(SDLK_KP_CLEAR);
}

RING_FUNC(ring_sdl_get_sdlk_kp_clearentry)
{
	RING_API_RETNUMBER(SDLK_KP_CLEARENTRY);
}

RING_FUNC(ring_sdl_get_sdlk_kp_colon)
{
	RING_API_RETNUMBER(SDLK_KP_COLON);
}

RING_FUNC(ring_sdl_get_sdlk_kp_comma)
{
	RING_API_RETNUMBER(SDLK_KP_COMMA);
}

RING_FUNC(ring_sdl_get_sdlk_kp_d)
{
	RING_API_RETNUMBER(SDLK_KP_D);
}

RING_FUNC(ring_sdl_get_sdlk_kp_dblampersand)
{
	RING_API_RETNUMBER(SDLK_KP_DBLAMPERSAND);
}

RING_FUNC(ring_sdl_get_sdlk_kp_dblverticalbar)
{
	RING_API_RETNUMBER(SDLK_KP_DBLVERTICALBAR);
}

RING_FUNC(ring_sdl_get_sdlk_kp_decimal)
{
	RING_API_RETNUMBER(SDLK_KP_DECIMAL);
}

RING_FUNC(ring_sdl_get_sdlk_kp_divide)
{
	RING_API_RETNUMBER(SDLK_KP_DIVIDE);
}

RING_FUNC(ring_sdl_get_sdlk_kp_e)
{
	RING_API_RETNUMBER(SDLK_KP_E);
}

RING_FUNC(ring_sdl_get_sdlk_kp_enter)
{
	RING_API_RETNUMBER(SDLK_KP_ENTER);
}

RING_FUNC(ring_sdl_get_sdlk_kp_equals)
{
	RING_API_RETNUMBER(SDLK_KP_EQUALS);
}

RING_FUNC(ring_sdl_get_sdlk_kp_equalsas400)
{
	RING_API_RETNUMBER(SDLK_KP_EQUALSAS400);
}

RING_FUNC(ring_sdl_get_sdlk_kp_exclam)
{
	RING_API_RETNUMBER(SDLK_KP_EXCLAM);
}

RING_FUNC(ring_sdl_get_sdlk_kp_f)
{
	RING_API_RETNUMBER(SDLK_KP_F);
}

RING_FUNC(ring_sdl_get_sdlk_kp_greater)
{
	RING_API_RETNUMBER(SDLK_KP_GREATER);
}

RING_FUNC(ring_sdl_get_sdlk_kp_hash)
{
	RING_API_RETNUMBER(SDLK_KP_HASH);
}

RING_FUNC(ring_sdl_get_sdlk_kp_hexadecimal)
{
	RING_API_RETNUMBER(SDLK_KP_HEXADECIMAL);
}

RING_FUNC(ring_sdl_get_sdlk_kp_leftbrace)
{
	RING_API_RETNUMBER(SDLK_KP_LEFTBRACE);
}

RING_FUNC(ring_sdl_get_sdlk_kp_leftparen)
{
	RING_API_RETNUMBER(SDLK_KP_LEFTPAREN);
}

RING_FUNC(ring_sdl_get_sdlk_kp_less)
{
	RING_API_RETNUMBER(SDLK_KP_LESS);
}

RING_FUNC(ring_sdl_get_sdlk_kp_memadd)
{
	RING_API_RETNUMBER(SDLK_KP_MEMADD);
}

RING_FUNC(ring_sdl_get_sdlk_kp_memclear)
{
	RING_API_RETNUMBER(SDLK_KP_MEMCLEAR);
}

RING_FUNC(ring_sdl_get_sdlk_kp_memdivide)
{
	RING_API_RETNUMBER(SDLK_KP_MEMDIVIDE);
}

RING_FUNC(ring_sdl_get_sdlk_kp_memmultiply)
{
	RING_API_RETNUMBER(SDLK_KP_MEMMULTIPLY);
}

RING_FUNC(ring_sdl_get_sdlk_kp_memrecall)
{
	RING_API_RETNUMBER(SDLK_KP_MEMRECALL);
}

RING_FUNC(ring_sdl_get_sdlk_kp_memstore)
{
	RING_API_RETNUMBER(SDLK_KP_MEMSTORE);
}

RING_FUNC(ring_sdl_get_sdlk_kp_memsubtract)
{
	RING_API_RETNUMBER(SDLK_KP_MEMSUBTRACT);
}

RING_FUNC(ring_sdl_get_sdlk_kp_minus)
{
	RING_API_RETNUMBER(SDLK_KP_MINUS);
}

RING_FUNC(ring_sdl_get_sdlk_kp_multiply)
{
	RING_API_RETNUMBER(SDLK_KP_MULTIPLY);
}

RING_FUNC(ring_sdl_get_sdlk_kp_octal)
{
	RING_API_RETNUMBER(SDLK_KP_OCTAL);
}

RING_FUNC(ring_sdl_get_sdlk_kp_percent)
{
	RING_API_RETNUMBER(SDLK_KP_PERCENT);
}

RING_FUNC(ring_sdl_get_sdlk_kp_period)
{
	RING_API_RETNUMBER(SDLK_KP_PERIOD);
}

RING_FUNC(ring_sdl_get_sdlk_kp_plus)
{
	RING_API_RETNUMBER(SDLK_KP_PLUS);
}

RING_FUNC(ring_sdl_get_sdlk_kp_plusminus)
{
	RING_API_RETNUMBER(SDLK_KP_PLUSMINUS);
}

RING_FUNC(ring_sdl_get_sdlk_kp_power)
{
	RING_API_RETNUMBER(SDLK_KP_POWER);
}

RING_FUNC(ring_sdl_get_sdlk_kp_rightbrace)
{
	RING_API_RETNUMBER(SDLK_KP_RIGHTBRACE);
}

RING_FUNC(ring_sdl_get_sdlk_kp_rightparen)
{
	RING_API_RETNUMBER(SDLK_KP_RIGHTPAREN);
}

RING_FUNC(ring_sdl_get_sdlk_kp_space)
{
	RING_API_RETNUMBER(SDLK_KP_SPACE);
}

RING_FUNC(ring_sdl_get_sdlk_kp_tab)
{
	RING_API_RETNUMBER(SDLK_KP_TAB);
}

RING_FUNC(ring_sdl_get_sdlk_kp_verticalbar)
{
	RING_API_RETNUMBER(SDLK_KP_VERTICALBAR);
}

RING_FUNC(ring_sdl_get_sdlk_kp_xor)
{
	RING_API_RETNUMBER(SDLK_KP_XOR);
}

RING_FUNC(ring_sdl_get_sdlk_l)
{
	RING_API_RETNUMBER(SDLK_l);
}

RING_FUNC(ring_sdl_get_sdlk_lalt)
{
	RING_API_RETNUMBER(SDLK_LALT);
}

RING_FUNC(ring_sdl_get_sdlk_lctrl)
{
	RING_API_RETNUMBER(SDLK_LCTRL);
}

RING_FUNC(ring_sdl_get_sdlk_left)
{
	RING_API_RETNUMBER(SDLK_LEFT);
}

RING_FUNC(ring_sdl_get_sdlk_leftbracket)
{
	RING_API_RETNUMBER(SDLK_LEFTBRACKET);
}

RING_FUNC(ring_sdl_get_sdlk_lgui)
{
	RING_API_RETNUMBER(SDLK_LGUI);
}

RING_FUNC(ring_sdl_get_sdlk_lshift)
{
	RING_API_RETNUMBER(SDLK_LSHIFT);
}

RING_FUNC(ring_sdl_get_sdlk_m)
{
	RING_API_RETNUMBER(SDLK_m);
}

RING_FUNC(ring_sdl_get_sdlk_mail)
{
	RING_API_RETNUMBER(SDLK_MAIL);
}

RING_FUNC(ring_sdl_get_sdlk_mediaselect)
{
	RING_API_RETNUMBER(SDLK_MEDIASELECT);
}

RING_FUNC(ring_sdl_get_sdlk_menu)
{
	RING_API_RETNUMBER(SDLK_MENU);
}

RING_FUNC(ring_sdl_get_sdlk_minus)
{
	RING_API_RETNUMBER(SDLK_MINUS);
}

RING_FUNC(ring_sdl_get_sdlk_mode)
{
	RING_API_RETNUMBER(SDLK_MODE);
}

RING_FUNC(ring_sdl_get_sdlk_mute)
{
	RING_API_RETNUMBER(SDLK_MUTE);
}

RING_FUNC(ring_sdl_get_sdlk_n)
{
	RING_API_RETNUMBER(SDLK_n);
}

RING_FUNC(ring_sdl_get_sdlk_numlockclear)
{
	RING_API_RETNUMBER(SDLK_NUMLOCKCLEAR);
}

RING_FUNC(ring_sdl_get_sdlk_o)
{
	RING_API_RETNUMBER(SDLK_o);
}

RING_FUNC(ring_sdl_get_sdlk_oper)
{
	RING_API_RETNUMBER(SDLK_OPER);
}

RING_FUNC(ring_sdl_get_sdlk_out)
{
	RING_API_RETNUMBER(SDLK_OUT);
}

RING_FUNC(ring_sdl_get_sdlk_p)
{
	RING_API_RETNUMBER(SDLK_p);
}

RING_FUNC(ring_sdl_get_sdlk_pagedown)
{
	RING_API_RETNUMBER(SDLK_PAGEDOWN);
}

RING_FUNC(ring_sdl_get_sdlk_pageup)
{
	RING_API_RETNUMBER(SDLK_PAGEUP);
}

RING_FUNC(ring_sdl_get_sdlk_paste)
{
	RING_API_RETNUMBER(SDLK_PASTE);
}

RING_FUNC(ring_sdl_get_sdlk_pause)
{
	RING_API_RETNUMBER(SDLK_PAUSE);
}

RING_FUNC(ring_sdl_get_sdlk_period)
{
	RING_API_RETNUMBER(SDLK_PERIOD);
}

RING_FUNC(ring_sdl_get_sdlk_power)
{
	RING_API_RETNUMBER(SDLK_POWER);
}

RING_FUNC(ring_sdl_get_sdlk_printscreen)
{
	RING_API_RETNUMBER(SDLK_PRINTSCREEN);
}

RING_FUNC(ring_sdl_get_sdlk_prior)
{
	RING_API_RETNUMBER(SDLK_PRIOR);
}

RING_FUNC(ring_sdl_get_sdlk_q)
{
	RING_API_RETNUMBER(SDLK_q);
}

RING_FUNC(ring_sdl_get_sdlk_r)
{
	RING_API_RETNUMBER(SDLK_r);
}

RING_FUNC(ring_sdl_get_sdlk_ralt)
{
	RING_API_RETNUMBER(SDLK_RALT);
}

RING_FUNC(ring_sdl_get_sdlk_rctrl)
{
	RING_API_RETNUMBER(SDLK_RCTRL);
}

RING_FUNC(ring_sdl_get_sdlk_return)
{
	RING_API_RETNUMBER(SDLK_RETURN);
}

RING_FUNC(ring_sdl_get_sdlk_return2)
{
	RING_API_RETNUMBER(SDLK_RETURN2);
}

RING_FUNC(ring_sdl_get_sdlk_rgui)
{
	RING_API_RETNUMBER(SDLK_RGUI);
}

RING_FUNC(ring_sdl_get_sdlk_right)
{
	RING_API_RETNUMBER(SDLK_RIGHT);
}

RING_FUNC(ring_sdl_get_sdlk_rightbracket)
{
	RING_API_RETNUMBER(SDLK_RIGHTBRACKET);
}

RING_FUNC(ring_sdl_get_sdlk_rshift)
{
	RING_API_RETNUMBER(SDLK_RSHIFT);
}

RING_FUNC(ring_sdl_get_sdlk_s)
{
	RING_API_RETNUMBER(SDLK_s);
}

RING_FUNC(ring_sdl_get_sdlk_scrolllock)
{
	RING_API_RETNUMBER(SDLK_SCROLLLOCK);
}

RING_FUNC(ring_sdl_get_sdlk_select)
{
	RING_API_RETNUMBER(SDLK_SELECT);
}

RING_FUNC(ring_sdl_get_sdlk_semicolon)
{
	RING_API_RETNUMBER(SDLK_SEMICOLON);
}

RING_FUNC(ring_sdl_get_sdlk_separator)
{
	RING_API_RETNUMBER(SDLK_SEPARATOR);
}

RING_FUNC(ring_sdl_get_sdlk_slash)
{
	RING_API_RETNUMBER(SDLK_SLASH);
}

RING_FUNC(ring_sdl_get_sdlk_sleep)
{
	RING_API_RETNUMBER(SDLK_SLEEP);
}

RING_FUNC(ring_sdl_get_sdlk_space)
{
	RING_API_RETNUMBER(SDLK_SPACE);
}

RING_FUNC(ring_sdl_get_sdlk_stop)
{
	RING_API_RETNUMBER(SDLK_STOP);
}

RING_FUNC(ring_sdl_get_sdlk_sysreq)
{
	RING_API_RETNUMBER(SDLK_SYSREQ);
}

RING_FUNC(ring_sdl_get_sdlk_t)
{
	RING_API_RETNUMBER(SDLK_t);
}

RING_FUNC(ring_sdl_get_sdlk_tab)
{
	RING_API_RETNUMBER(SDLK_TAB);
}

RING_FUNC(ring_sdl_get_sdlk_thousandsseparator)
{
	RING_API_RETNUMBER(SDLK_THOUSANDSSEPARATOR);
}

RING_FUNC(ring_sdl_get_sdlk_u)
{
	RING_API_RETNUMBER(SDLK_u);
}

RING_FUNC(ring_sdl_get_sdlk_undo)
{
	RING_API_RETNUMBER(SDLK_UNDO);
}

RING_FUNC(ring_sdl_get_sdlk_unknown)
{
	RING_API_RETNUMBER(SDLK_UNKNOWN);
}

RING_FUNC(ring_sdl_get_sdlk_up)
{
	RING_API_RETNUMBER(SDLK_UP);
}

RING_FUNC(ring_sdl_get_sdlk_v)
{
	RING_API_RETNUMBER(SDLK_v);
}

RING_FUNC(ring_sdl_get_sdlk_volumedown)
{
	RING_API_RETNUMBER(SDLK_VOLUMEDOWN);
}

RING_FUNC(ring_sdl_get_sdlk_volumeup)
{
	RING_API_RETNUMBER(SDLK_VOLUMEUP);
}

RING_FUNC(ring_sdl_get_sdlk_w)
{
	RING_API_RETNUMBER(SDLK_w);
}

RING_FUNC(ring_sdl_get_sdlk_www)
{
	RING_API_RETNUMBER(SDLK_WWW);
}

RING_FUNC(ring_sdl_get_sdlk_x)
{
	RING_API_RETNUMBER(SDLK_x);
}

RING_FUNC(ring_sdl_get_sdlk_y)
{
	RING_API_RETNUMBER(SDLK_y);
}

RING_FUNC(ring_sdl_get_sdlk_z)
{
	RING_API_RETNUMBER(SDLK_z);
}

RING_FUNC(ring_sdl_get_sdlk_ampersand)
{
	RING_API_RETNUMBER(SDLK_AMPERSAND);
}

RING_FUNC(ring_sdl_get_sdlk_asterisk)
{
	RING_API_RETNUMBER(SDLK_ASTERISK);
}

RING_FUNC(ring_sdl_get_sdlk_at)
{
	RING_API_RETNUMBER(SDLK_AT);
}

RING_FUNC(ring_sdl_get_sdlk_caret)
{
	RING_API_RETNUMBER(SDLK_CARET);
}

RING_FUNC(ring_sdl_get_sdlk_colon)
{
	RING_API_RETNUMBER(SDLK_COLON);
}

RING_FUNC(ring_sdl_get_sdlk_dollar)
{
	RING_API_RETNUMBER(SDLK_DOLLAR);
}

RING_FUNC(ring_sdl_get_sdlk_exclaim)
{
	RING_API_RETNUMBER(SDLK_EXCLAIM);
}

RING_FUNC(ring_sdl_get_sdlk_greater)
{
	RING_API_RETNUMBER(SDLK_GREATER);
}

RING_FUNC(ring_sdl_get_sdlk_hash)
{
	RING_API_RETNUMBER(SDLK_HASH);
}

RING_FUNC(ring_sdl_get_sdlk_leftparen)
{
	RING_API_RETNUMBER(SDLK_LEFTPAREN);
}

RING_FUNC(ring_sdl_get_sdlk_less)
{
	RING_API_RETNUMBER(SDLK_LESS);
}

RING_FUNC(ring_sdl_get_sdlk_percent)
{
	RING_API_RETNUMBER(SDLK_PERCENT);
}

RING_FUNC(ring_sdl_get_sdlk_plus)
{
	RING_API_RETNUMBER(SDLK_PLUS);
}

RING_FUNC(ring_sdl_get_sdlk_question)
{
	RING_API_RETNUMBER(SDLK_QUESTION);
}

RING_FUNC(ring_sdl_get_sdlk_quotedbl)
{
	RING_API_RETNUMBER(SDLK_QUOTEDBL);
}

RING_FUNC(ring_sdl_get_sdlk_rightparen)
{
	RING_API_RETNUMBER(SDLK_RIGHTPAREN);
}

RING_FUNC(ring_sdl_get_sdlk_underscore)
{
	RING_API_RETNUMBER(SDLK_UNDERSCORE);
}

RING_FUNC(ring_sdl_get_sdl_thread_priority_low)
{
	RING_API_RETNUMBER(SDL_THREAD_PRIORITY_LOW);
}

RING_FUNC(ring_sdl_get_sdl_thread_priority_normal)
{
	RING_API_RETNUMBER(SDL_THREAD_PRIORITY_NORMAL);
}

RING_FUNC(ring_sdl_get_sdl_thread_priority_high)
{
	RING_API_RETNUMBER(SDL_THREAD_PRIORITY_HIGH);
}

RING_FUNC(ring_SDL_RenderCopy2)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_RenderCopy((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Texture *) RING_API_GETCPOINTER(2,"SDL_Texture"),NULL,NULL);
}

RING_FUNC(ring_SDL_Delay)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_Delay( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_Init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_Init( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_InitSubSystem)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_InitSubSystem( (Uint32 ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_Quit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_Quit();
}


RING_FUNC(ring_SDL_QuitSubSystem)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_QuitSubSystem( (Uint32 ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_SetMainReady)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_SetMainReady();
}


RING_FUNC(ring_SDL_WasInit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_WasInit( (Uint32 ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_ClearHints)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_ClearHints();
}


RING_FUNC(ring_SDL_GetHint)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetHint(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_SetHint)
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
	RING_API_RETNUMBER(SDL_SetHint(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_SDL_SetHintWithPriority)
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SetHintWithPriority(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (SDL_HintPriority )  (int) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_ClearError)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_ClearError();
}


RING_FUNC(ring_SDL_GetError)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDL_GetError());
}


RING_FUNC(ring_SDL_LogGetPriority)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LogGetPriority( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_LogResetPriorities)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_LogResetPriorities();
}


RING_FUNC(ring_SDL_LogSetAllPriority)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_LogSetAllPriority( (SDL_LogPriority )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_LogSetPriority)
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
	SDL_LogSetPriority( (int ) RING_API_GETNUMBER(1), (SDL_LogPriority )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SDL_GetAssertionReport)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetAssertionReport(),"SDL_AssertData");
}


RING_FUNC(ring_SDL_GetDefaultAssertionHandler)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		SDL_AssertionHandler *pValue ; 
		pValue = (SDL_AssertionHandler *) RING_API_MALLOC(sizeof(SDL_AssertionHandler)) ;
		*pValue = SDL_GetDefaultAssertionHandler();
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_AssertionHandler",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_ResetAssertionReport)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_ResetAssertionReport();
}


RING_FUNC(ring_SDL_SetAssertionHandler)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_SetAssertionHandler(* (SDL_AssertionHandler  *) RING_API_GETCPOINTER(1,"SDL_AssertionHandler"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_AssertionHandler"));
}


RING_FUNC(ring_SDL_TriggerBreakpoint)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_TriggerBreakpoint();
}


RING_FUNC(ring_SDL_assert)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_assert( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_assert_paranoid)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_assert_paranoid( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_assert_release)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_assert_release( (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_GetRevision)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDL_GetRevision());
}


RING_FUNC(ring_SDL_GetRevisionNumber)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetRevisionNumber());
}


RING_FUNC(ring_SDL_GetVersion)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_GetVersion((SDL_version *) RING_API_GETCPOINTER(1,"SDL_version"));
}


RING_FUNC(ring_SDL_CreateWindow)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_CreateWindow(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (Uint32 ) RING_API_GETNUMBER(6)),"SDL_Window");
}


RING_FUNC(ring_SDL_CreateWindowFrom)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_CreateWindowFrom((void *) RING_API_GETCPOINTER(1,"void")),"SDL_Window");
}


RING_FUNC(ring_SDL_DestroyWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DestroyWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_DisableScreenSaver)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_DisableScreenSaver();
}


RING_FUNC(ring_SDL_EnableScreenSaver)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_EnableScreenSaver();
}


RING_FUNC(ring_SDL_GL_CreateContext)
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
		SDL_GLContext *pValue ; 
		pValue = (SDL_GLContext *) RING_API_MALLOC(sizeof(SDL_GLContext)) ;
		*pValue = SDL_GL_CreateContext((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_GLContext",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_GL_DeleteContext)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SDL_GL_DeleteContext(* (SDL_GLContext  *) RING_API_GETCPOINTER(1,"SDL_GLContext"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_GLContext"));
}


RING_FUNC(ring_SDL_GL_ExtensionSupported)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GL_ExtensionSupported(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GL_GetAttribute)
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
	RING_API_RETNUMBER(SDL_GL_GetAttribute( (SDL_GLattr )  (int) RING_API_GETNUMBER(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_SDL_GL_GetCurrentContext)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		SDL_GLContext *pValue ; 
		pValue = (SDL_GLContext *) RING_API_MALLOC(sizeof(SDL_GLContext)) ;
		*pValue = SDL_GL_GetCurrentContext();
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_GLContext",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_GL_GetCurrentWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GL_GetCurrentWindow(),"SDL_Window");
}


RING_FUNC(ring_SDL_GL_GetDrawableSize)
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
	SDL_GL_GetDrawableSize((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_SDL_GL_GetProcAddress)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GL_GetProcAddress(RING_API_GETSTRING(1)),"void");
}


RING_FUNC(ring_SDL_GL_GetSwapInterval)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GL_GetSwapInterval());
}


RING_FUNC(ring_SDL_GL_LoadLibrary)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GL_LoadLibrary(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GL_MakeCurrent)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GL_MakeCurrent((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),* (SDL_GLContext  *) RING_API_GETCPOINTER(2,"SDL_GLContext")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"SDL_GLContext"));
}


RING_FUNC(ring_SDL_GL_ResetAttributes)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_GL_ResetAttributes();
}


RING_FUNC(ring_SDL_GL_SetAttribute)
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
	RING_API_RETNUMBER(SDL_GL_SetAttribute( (SDL_GLattr )  (int) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_GL_SetSwapInterval)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GL_SetSwapInterval( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GL_SwapWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_GL_SwapWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_GL_UnloadLibrary)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_GL_UnloadLibrary();
}


RING_FUNC(ring_SDL_GetClosestDisplayMode)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetClosestDisplayMode( (int ) RING_API_GETNUMBER(1),(SDL_DisplayMode *) RING_API_GETCPOINTER(2,"SDL_DisplayMode"),(SDL_DisplayMode *) RING_API_GETCPOINTER(3,"SDL_DisplayMode")),"SDL_DisplayMode");
}


RING_FUNC(ring_SDL_GetCurrentDisplayMode)
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
	RING_API_RETNUMBER(SDL_GetCurrentDisplayMode( (int ) RING_API_GETNUMBER(1),(SDL_DisplayMode *) RING_API_GETCPOINTER(2,"SDL_DisplayMode")));
}


RING_FUNC(ring_SDL_GetCurrentVideoDriver)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDL_GetCurrentVideoDriver());
}


RING_FUNC(ring_SDL_GetDesktopDisplayMode)
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
	RING_API_RETNUMBER(SDL_GetDesktopDisplayMode( (int ) RING_API_GETNUMBER(1),(SDL_DisplayMode *) RING_API_GETCPOINTER(2,"SDL_DisplayMode")));
}


RING_FUNC(ring_SDL_GetDisplayBounds)
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
	RING_API_RETNUMBER(SDL_GetDisplayBounds( (int ) RING_API_GETNUMBER(1),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_GetNumDisplayModes)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumDisplayModes( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetNumVideoDisplays)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumVideoDisplays());
}


RING_FUNC(ring_SDL_GetNumVideoDrivers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumVideoDrivers());
}


RING_FUNC(ring_SDL_GetVideoDriver)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetVideoDriver( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetWindowBrightness)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetWindowBrightness((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_GetWindowData)
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
	RING_API_RETCPOINTER(SDL_GetWindowData((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_SDL_GetWindowDisplayIndex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetWindowDisplayIndex((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_GetWindowDisplayMode)
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
	RING_API_RETNUMBER(SDL_GetWindowDisplayMode((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),(SDL_DisplayMode *) RING_API_GETCPOINTER(2,"SDL_DisplayMode")));
}


RING_FUNC(ring_SDL_GetWindowFlags)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetWindowFlags((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_GetWindowFromID)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetWindowFromID( (Uint32 ) RING_API_GETNUMBER(1)),"SDL_Window");
}


RING_FUNC(ring_SDL_GetWindowGammaRamp)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetWindowGammaRamp((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"),(Uint16 *) RING_API_GETCPOINTER(3,"Uint16"),(Uint16 *) RING_API_GETCPOINTER(4,"Uint16")));
}


RING_FUNC(ring_SDL_GetWindowGrab)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetWindowGrab((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_GetWindowID)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetWindowID((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_GetWindowMaximumSize)
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
	SDL_GetWindowMaximumSize((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_SDL_GetWindowMinimumSize)
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
	SDL_GetWindowMinimumSize((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_SDL_GetWindowPixelFormat)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetWindowPixelFormat((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_GetWindowPosition)
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
	SDL_GetWindowPosition((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_SDL_GetWindowSize)
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
	SDL_GetWindowSize((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_SDL_GetWindowSurface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetWindowSurface((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")),"SDL_Surface");
}


RING_FUNC(ring_SDL_GetWindowTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetWindowTitle((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_HideWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_HideWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_IsScreenSaverEnabled)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_IsScreenSaverEnabled());
}


RING_FUNC(ring_SDL_MaximizeWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_MaximizeWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_MinimizeWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_MinimizeWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_RaiseWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_RaiseWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_RestoreWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_RestoreWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_SetWindowBordered)
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
	SDL_SetWindowBordered((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (SDL_bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SDL_SetWindowBrightness)
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
	RING_API_RETNUMBER(SDL_SetWindowBrightness((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (float ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_SetWindowData)
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
	RING_API_RETCPOINTER(SDL_SetWindowData((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETSTRING(2),(void *) RING_API_GETCPOINTER(3,"void")),"void");
}


RING_FUNC(ring_SDL_SetWindowDisplayMode)
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
	RING_API_RETNUMBER(SDL_SetWindowDisplayMode((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),(SDL_DisplayMode *) RING_API_GETCPOINTER(2,"SDL_DisplayMode")));
}


RING_FUNC(ring_SDL_SetWindowFullscreen)
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
	RING_API_RETNUMBER(SDL_SetWindowFullscreen((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (Uint32 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_SetWindowGammaRamp)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SetWindowGammaRamp((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"),(Uint16 *) RING_API_GETCPOINTER(3,"Uint16"),(Uint16 *) RING_API_GETCPOINTER(4,"Uint16")));
}


RING_FUNC(ring_SDL_SetWindowGrab)
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
	SDL_SetWindowGrab((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (SDL_bool ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SDL_SetWindowIcon)
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
	SDL_SetWindowIcon((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),(SDL_Surface *) RING_API_GETCPOINTER(2,"SDL_Surface"));
}


RING_FUNC(ring_SDL_SetWindowMaximumSize)
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
	SDL_SetWindowMaximumSize((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_SDL_SetWindowMinimumSize)
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
	SDL_SetWindowMinimumSize((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_SDL_SetWindowPosition)
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
	SDL_SetWindowPosition((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_SDL_SetWindowSize)
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
	SDL_SetWindowSize((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_SDL_SetWindowTitle)
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
	SDL_SetWindowTitle((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_SDL_ShowMessageBox)
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
	RING_API_RETNUMBER(SDL_ShowMessageBox((SDL_MessageBoxData *) RING_API_GETCPOINTER(1,"SDL_MessageBoxData"),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_SDL_ShowSimpleMessageBox)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ShowSimpleMessageBox( (Uint32 ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3),(SDL_Window *) RING_API_GETCPOINTER(4,"SDL_Window")));
}


RING_FUNC(ring_SDL_ShowWindow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_ShowWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
}


RING_FUNC(ring_SDL_UpdateWindowSurface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_UpdateWindowSurface((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_UpdateWindowSurfaceRects)
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
	RING_API_RETNUMBER(SDL_UpdateWindowSurfaceRects((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_VideoInit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_VideoInit(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_VideoQuit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_VideoQuit();
}


RING_FUNC(ring_SDL_CreateRenderer)
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
	RING_API_RETCPOINTER(SDL_CreateRenderer((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (int ) RING_API_GETNUMBER(2), (Uint32 ) RING_API_GETNUMBER(3)),"SDL_Renderer");
}


RING_FUNC(ring_SDL_CreateSoftwareRenderer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_CreateSoftwareRenderer((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface")),"SDL_Renderer");
}


RING_FUNC(ring_SDL_CreateTexture)
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
	RING_API_RETCPOINTER(SDL_CreateTexture((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (Uint32 ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)),"SDL_Texture");
}


RING_FUNC(ring_SDL_CreateTextureFromSurface)
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
	RING_API_RETCPOINTER(SDL_CreateTextureFromSurface((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Surface *) RING_API_GETCPOINTER(2,"SDL_Surface")),"SDL_Texture");
}


RING_FUNC(ring_SDL_DestroyRenderer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DestroyRenderer((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"));
}


RING_FUNC(ring_SDL_DestroyTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DestroyTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"));
}


RING_FUNC(ring_SDL_GL_BindTexture)
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
	RING_API_RETNUMBER(SDL_GL_BindTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(float *) RING_API_GETCPOINTER(2,"float"),(float *) RING_API_GETCPOINTER(3,"float")));
}


RING_FUNC(ring_SDL_GL_UnbindTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GL_UnbindTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture")));
}


RING_FUNC(ring_SDL_GetNumRenderDrivers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumRenderDrivers());
}


RING_FUNC(ring_SDL_GetRenderDrawBlendMode)
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
	RING_API_RETNUMBER(SDL_GetRenderDrawBlendMode((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_BlendMode *) RING_API_GETCPOINTER(2,"SDL_BlendMode")));
}


RING_FUNC(ring_SDL_GetRenderDrawColor)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetRenderDrawColor((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(3,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(4,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(5,"Uint8")));
}


RING_FUNC(ring_SDL_GetRenderDriverInfo)
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
	RING_API_RETNUMBER(SDL_GetRenderDriverInfo( (int ) RING_API_GETNUMBER(1),(SDL_RendererInfo *) RING_API_GETCPOINTER(2,"SDL_RendererInfo")));
}


RING_FUNC(ring_SDL_GetRenderTarget)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetRenderTarget((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer")),"SDL_Texture");
}


RING_FUNC(ring_SDL_GetRenderer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetRenderer((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")),"SDL_Renderer");
}


RING_FUNC(ring_SDL_GetRendererInfo)
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
	RING_API_RETNUMBER(SDL_GetRendererInfo((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_RendererInfo *) RING_API_GETCPOINTER(2,"SDL_RendererInfo")));
}


RING_FUNC(ring_SDL_GetRendererOutputSize)
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
	RING_API_RETNUMBER(SDL_GetRendererOutputSize((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_SDL_GetTextureAlphaMod)
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
	RING_API_RETNUMBER(SDL_GetTextureAlphaMod((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8")));
}


RING_FUNC(ring_SDL_GetTextureBlendMode)
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
	RING_API_RETNUMBER(SDL_GetTextureBlendMode((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(SDL_BlendMode *) RING_API_GETCPOINTER(2,"SDL_BlendMode")));
}


RING_FUNC(ring_SDL_GetTextureColorMod)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetTextureColorMod((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(3,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(4,"Uint8")));
}


RING_FUNC(ring_SDL_LockTexture)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LockTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(void **) RING_API_GETCPOINTER2POINTER(3,"void"),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_SDL_QueryTexture)
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
	RING_API_RETNUMBER(SDL_QueryTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5)));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
}


RING_FUNC(ring_SDL_RenderClear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RenderClear((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer")));
}


RING_FUNC(ring_SDL_RenderCopy)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RenderCopy((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Texture *) RING_API_GETCPOINTER(2,"SDL_Texture"),(SDL_Rect *) RING_API_GETCPOINTER(3,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect")));
}


RING_FUNC(ring_SDL_RenderCopyEx)
{
	if ( RING_API_PARACOUNT != 7 ) {
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RenderCopyEx((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Texture *) RING_API_GETCPOINTER(2,"SDL_Texture"),(SDL_Rect *) RING_API_GETCPOINTER(3,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect"),* (const double  *) RING_API_GETCPOINTER(5,"const double"),(SDL_Point *) RING_API_GETCPOINTER(6,"SDL_Point"),* (const SDL_RendererFlip  *) RING_API_GETCPOINTER(7,"const SDL_RendererFlip")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		RING_API_FREE(RING_API_GETCPOINTER(5,"double"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		RING_API_FREE(RING_API_GETCPOINTER(7,"SDL_RendererFlip"));
}


RING_FUNC(ring_SDL_RenderDrawLine)
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
	RING_API_RETNUMBER(SDL_RenderDrawLine((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_SDL_RenderDrawLines)
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
	RING_API_RETNUMBER(SDL_RenderDrawLines((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Point *) RING_API_GETCPOINTER(2,"SDL_Point"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_RenderDrawPoint)
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
	RING_API_RETNUMBER(SDL_RenderDrawPoint((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_RenderDrawPoints)
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
	RING_API_RETNUMBER(SDL_RenderDrawPoints((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Point *) RING_API_GETCPOINTER(2,"SDL_Point"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_RenderDrawRect)
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
	RING_API_RETNUMBER(SDL_RenderDrawRect((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_RenderDrawRects)
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
	RING_API_RETNUMBER(SDL_RenderDrawRects((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_RenderFillRect)
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
	RING_API_RETNUMBER(SDL_RenderFillRect((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_RenderFillRects)
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
	RING_API_RETNUMBER(SDL_RenderFillRects((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_RenderGetClipRect)
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
	SDL_RenderGetClipRect((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"));
}


RING_FUNC(ring_SDL_RenderGetLogicalSize)
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
	SDL_RenderGetLogicalSize((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_SDL_RenderGetScale)
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
	SDL_RenderGetScale((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(float *) RING_API_GETCPOINTER(2,"float"),(float *) RING_API_GETCPOINTER(3,"float"));
}


RING_FUNC(ring_SDL_RenderGetViewport)
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
	SDL_RenderGetViewport((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"));
}


RING_FUNC(ring_SDL_RenderPresent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_RenderPresent((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"));
}


RING_FUNC(ring_SDL_RenderReadPixels)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	if ( ! RING_API_ISNUMBER(3) ) {
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
	RING_API_RETNUMBER(SDL_RenderReadPixels((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"), (Uint32 ) RING_API_GETNUMBER(3),(void *) RING_API_GETCPOINTER(4,"void"), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_SDL_RenderSetClipRect)
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
	RING_API_RETNUMBER(SDL_RenderSetClipRect((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_RenderSetLogicalSize)
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
	RING_API_RETNUMBER(SDL_RenderSetLogicalSize((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_RenderSetScale)
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
	RING_API_RETNUMBER(SDL_RenderSetScale((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_RenderSetViewport)
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
	RING_API_RETNUMBER(SDL_RenderSetViewport((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_RenderTargetSupported)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RenderTargetSupported((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer")));
}


RING_FUNC(ring_SDL_SetRenderDrawBlendMode)
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
	RING_API_RETNUMBER(SDL_SetRenderDrawBlendMode((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (SDL_BlendMode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_SetRenderDrawColor)
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
	RING_API_RETNUMBER(SDL_SetRenderDrawColor((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (Uint8 ) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3), (Uint8 ) RING_API_GETNUMBER(4), (Uint8 ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_SDL_SetRenderTarget)
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
	RING_API_RETNUMBER(SDL_SetRenderTarget((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Texture *) RING_API_GETCPOINTER(2,"SDL_Texture")));
}


RING_FUNC(ring_SDL_SetTextureAlphaMod)
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
	RING_API_RETNUMBER(SDL_SetTextureAlphaMod((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"), (Uint8 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_SetTextureBlendMode)
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
	RING_API_RETNUMBER(SDL_SetTextureBlendMode((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"), (SDL_BlendMode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_SetTextureColorMod)
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
	RING_API_RETNUMBER(SDL_SetTextureColorMod((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"), (Uint8 ) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3), (Uint8 ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_UnlockTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_UnlockTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"));
}


RING_FUNC(ring_SDL_UpdateTexture)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_UpdateTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(void *) RING_API_GETCPOINTER(3,"void"), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_UpdateYUVTexture)
{
	if ( RING_API_PARACOUNT != 8 ) {
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_UpdateYUVTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(Uint8 *) RING_API_GETCPOINTER(3,"Uint8"), (int ) RING_API_GETNUMBER(4),(Uint8 *) RING_API_GETCPOINTER(5,"Uint8"), (int ) RING_API_GETNUMBER(6),(Uint8 *) RING_API_GETCPOINTER(7,"Uint8"), (int ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_SDL_AllocFormat)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_AllocFormat( (Uint32 ) RING_API_GETNUMBER(1)),"SDL_PixelFormat");
}


RING_FUNC(ring_SDL_AllocPalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_AllocPalette( (int ) RING_API_GETNUMBER(1)),"SDL_Palette");
}


RING_FUNC(ring_SDL_CalculateGammaRamp)
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
	SDL_CalculateGammaRamp( (float ) RING_API_GETNUMBER(1),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"));
}


RING_FUNC(ring_SDL_FreeFormat)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FreeFormat((SDL_PixelFormat *) RING_API_GETCPOINTER(1,"SDL_PixelFormat"));
}


RING_FUNC(ring_SDL_FreePalette)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FreePalette((SDL_Palette *) RING_API_GETCPOINTER(1,"SDL_Palette"));
}


RING_FUNC(ring_SDL_GetPixelFormatName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetPixelFormatName( (Uint32 ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetRGB)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	SDL_GetRGB( (Uint32 ) RING_API_GETNUMBER(1),(SDL_PixelFormat *) RING_API_GETCPOINTER(2,"SDL_PixelFormat"),(Uint8 *) RING_API_GETCPOINTER(3,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(4,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(5,"Uint8"));
}


RING_FUNC(ring_SDL_GetRGBA)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_GetRGBA( (Uint32 ) RING_API_GETNUMBER(1),(SDL_PixelFormat *) RING_API_GETCPOINTER(2,"SDL_PixelFormat"),(Uint8 *) RING_API_GETCPOINTER(3,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(4,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(5,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(6,"Uint8"));
}


RING_FUNC(ring_SDL_MapRGB)
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
	RING_API_RETNUMBER(SDL_MapRGB((SDL_PixelFormat *) RING_API_GETCPOINTER(1,"SDL_PixelFormat"), (Uint8 ) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3), (Uint8 ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_MapRGBA)
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
	RING_API_RETNUMBER(SDL_MapRGBA((SDL_PixelFormat *) RING_API_GETCPOINTER(1,"SDL_PixelFormat"), (Uint8 ) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3), (Uint8 ) RING_API_GETNUMBER(4), (Uint8 ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_SDL_MasksToPixelFormatEnum)
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
	RING_API_RETNUMBER(SDL_MasksToPixelFormatEnum( (int ) RING_API_GETNUMBER(1), (Uint32 ) RING_API_GETNUMBER(2), (Uint32 ) RING_API_GETNUMBER(3), (Uint32 ) RING_API_GETNUMBER(4), (Uint32 ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_SDL_PixelFormatEnumToMasks)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_PixelFormatEnumToMasks( (Uint32 ) RING_API_GETNUMBER(1),RING_API_GETINTPOINTER(2),(Uint32 *) RING_API_GETCPOINTER(3,"Uint32"),(Uint32 *) RING_API_GETCPOINTER(4,"Uint32"),(Uint32 *) RING_API_GETCPOINTER(5,"Uint32"),(Uint32 *) RING_API_GETCPOINTER(6,"Uint32")));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_SDL_SetPaletteColors)
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
	RING_API_RETNUMBER(SDL_SetPaletteColors((SDL_Palette *) RING_API_GETCPOINTER(1,"SDL_Palette"),(SDL_Color *) RING_API_GETCPOINTER(2,"SDL_Color"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_SetPixelFormatPalette)
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
	RING_API_RETNUMBER(SDL_SetPixelFormatPalette((SDL_PixelFormat *) RING_API_GETCPOINTER(1,"SDL_PixelFormat"),(SDL_Palette *) RING_API_GETCPOINTER(2,"SDL_Palette")));
}


RING_FUNC(ring_SDL_EnclosePoints)
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
	RING_API_RETNUMBER(SDL_EnclosePoints((SDL_Point *) RING_API_GETCPOINTER(1,"SDL_Point"), (int ) RING_API_GETNUMBER(2),(SDL_Rect *) RING_API_GETCPOINTER(3,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect")));
}


RING_FUNC(ring_SDL_HasIntersection)
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
	RING_API_RETNUMBER(SDL_HasIntersection((SDL_Rect *) RING_API_GETCPOINTER(1,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_IntersectRect)
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
	RING_API_RETNUMBER(SDL_IntersectRect((SDL_Rect *) RING_API_GETCPOINTER(1,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(3,"SDL_Rect")));
}


RING_FUNC(ring_SDL_IntersectRectAndLine)
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
	RING_API_RETNUMBER(SDL_IntersectRectAndLine((SDL_Rect *) RING_API_GETCPOINTER(1,"SDL_Rect"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5)));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
}


RING_FUNC(ring_SDL_RectEmpty)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RectEmpty((SDL_Rect *) RING_API_GETCPOINTER(1,"SDL_Rect")));
}


RING_FUNC(ring_SDL_RectEquals)
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
	RING_API_RETNUMBER(SDL_RectEquals((SDL_Rect *) RING_API_GETCPOINTER(1,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_UnionRect)
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
	SDL_UnionRect((SDL_Rect *) RING_API_GETCPOINTER(1,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(3,"SDL_Rect"));
}


RING_FUNC(ring_SDL_BlitScaled)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_BlitScaled((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(SDL_Surface *) RING_API_GETCPOINTER(3,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect")));
}


RING_FUNC(ring_SDL_BlitSurface)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_BlitSurface((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(SDL_Surface *) RING_API_GETCPOINTER(3,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect")));
}


RING_FUNC(ring_SDL_ConvertPixels)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
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
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ConvertPixels( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (Uint32 ) RING_API_GETNUMBER(3),(void *) RING_API_GETCPOINTER(4,"void"), (int ) RING_API_GETNUMBER(5), (Uint32 ) RING_API_GETNUMBER(6),(void *) RING_API_GETCPOINTER(7,"void"), (int ) RING_API_GETNUMBER(8)));
}


RING_FUNC(ring_SDL_ConvertSurface)
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
	RING_API_RETCPOINTER(SDL_ConvertSurface((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_PixelFormat *) RING_API_GETCPOINTER(2,"SDL_PixelFormat"), (Uint32 ) RING_API_GETNUMBER(3)),"SDL_Surface");
}


RING_FUNC(ring_SDL_ConvertSurfaceFormat)
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
	RING_API_RETCPOINTER(SDL_ConvertSurfaceFormat((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"), (Uint32 ) RING_API_GETNUMBER(2), (Uint32 ) RING_API_GETNUMBER(3)),"SDL_Surface");
}


RING_FUNC(ring_SDL_CreateRGBSurface)
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
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_CreateRGBSurface( (Uint32 ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (Uint32 ) RING_API_GETNUMBER(5), (Uint32 ) RING_API_GETNUMBER(6), (Uint32 ) RING_API_GETNUMBER(7), (Uint32 ) RING_API_GETNUMBER(8)),"SDL_Surface");
}


RING_FUNC(ring_SDL_CreateRGBSurfaceFrom)
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
	RING_API_RETCPOINTER(SDL_CreateRGBSurfaceFrom((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (Uint32 ) RING_API_GETNUMBER(6), (Uint32 ) RING_API_GETNUMBER(7), (Uint32 ) RING_API_GETNUMBER(8), (Uint32 ) RING_API_GETNUMBER(9)),"SDL_Surface");
}


RING_FUNC(ring_SDL_FillRect)
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
	RING_API_RETNUMBER(SDL_FillRect((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"), (Uint32 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_FillRects)
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
	RING_API_RETNUMBER(SDL_FillRects((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"), (int ) RING_API_GETNUMBER(3), (Uint32 ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_FreeSurface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FreeSurface((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"));
}


RING_FUNC(ring_SDL_GetClipRect)
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
	SDL_GetClipRect((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"));
}


RING_FUNC(ring_SDL_GetColorKey)
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
	RING_API_RETNUMBER(SDL_GetColorKey((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(Uint32 *) RING_API_GETCPOINTER(2,"Uint32")));
}


RING_FUNC(ring_SDL_GetSurfaceAlphaMod)
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
	RING_API_RETNUMBER(SDL_GetSurfaceAlphaMod((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8")));
}


RING_FUNC(ring_SDL_GetSurfaceBlendMode)
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
	RING_API_RETNUMBER(SDL_GetSurfaceBlendMode((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_BlendMode *) RING_API_GETCPOINTER(2,"SDL_BlendMode")));
}


RING_FUNC(ring_SDL_GetSurfaceColorMod)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetSurfaceColorMod((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(3,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(4,"Uint8")));
}


RING_FUNC(ring_SDL_LoadBMP)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_LoadBMP(RING_API_GETSTRING(1)),"SDL_Surface");
}


RING_FUNC(ring_SDL_LoadBMP_RW)
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
	RING_API_RETCPOINTER(SDL_LoadBMP_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2)),"SDL_Surface");
}


RING_FUNC(ring_SDL_LockSurface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LockSurface((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface")));
}


RING_FUNC(ring_SDL_LowerBlit)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LowerBlit((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(SDL_Surface *) RING_API_GETCPOINTER(3,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect")));
}


RING_FUNC(ring_SDL_LowerBlitScaled)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LowerBlitScaled((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(SDL_Surface *) RING_API_GETCPOINTER(3,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect")));
}


RING_FUNC(ring_SDL_MUSTLOCK)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_MUSTLOCK((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface")));
}


RING_FUNC(ring_SDL_SaveBMP)
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
	RING_API_RETNUMBER(SDL_SaveBMP((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_SDL_SaveBMP_RW)
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
	RING_API_RETNUMBER(SDL_SaveBMP_RW((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_RWops *) RING_API_GETCPOINTER(2,"SDL_RWops"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_SetClipRect)
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
	RING_API_RETNUMBER(SDL_SetClipRect((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect")));
}


RING_FUNC(ring_SDL_SetColorKey)
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
	RING_API_RETNUMBER(SDL_SetColorKey((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"), (int ) RING_API_GETNUMBER(2), (Uint32 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_SetSurfaceAlphaMod)
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
	RING_API_RETNUMBER(SDL_SetSurfaceAlphaMod((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"), (Uint8 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_SetSurfaceBlendMode)
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
	RING_API_RETNUMBER(SDL_SetSurfaceBlendMode((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"), (SDL_BlendMode )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_SetSurfaceColorMod)
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
	RING_API_RETNUMBER(SDL_SetSurfaceColorMod((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"), (Uint8 ) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3), (Uint8 ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_SetSurfacePalette)
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
	RING_API_RETNUMBER(SDL_SetSurfacePalette((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"),(SDL_Palette *) RING_API_GETCPOINTER(2,"SDL_Palette")));
}


RING_FUNC(ring_SDL_SetSurfaceRLE)
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
	RING_API_RETNUMBER(SDL_SetSurfaceRLE((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_UnlockSurface)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_UnlockSurface((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"));
}


RING_FUNC(ring_SDL_GetWindowWMInfo)
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
	RING_API_RETNUMBER(SDL_GetWindowWMInfo((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),(SDL_SysWMinfo *) RING_API_GETCPOINTER(2,"SDL_SysWMinfo")));
}


RING_FUNC(ring_SDL_GetClipboardText)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDL_GetClipboardText());
}


RING_FUNC(ring_SDL_HasClipboardText)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasClipboardText());
}


RING_FUNC(ring_SDL_SetClipboardText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SetClipboardText(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_AddEventWatch)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_AddEventWatch(* (SDL_EventFilter  *) RING_API_GETCPOINTER(1,"SDL_EventFilter"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_EventFilter"));
}


RING_FUNC(ring_SDL_DelEventWatch)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DelEventWatch(* (SDL_EventFilter  *) RING_API_GETCPOINTER(1,"SDL_EventFilter"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_EventFilter"));
}


RING_FUNC(ring_SDL_EventState)
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
	RING_API_RETNUMBER(SDL_EventState( (Uint32 ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_FilterEvents)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FilterEvents(* (SDL_EventFilter  *) RING_API_GETCPOINTER(1,"SDL_EventFilter"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_EventFilter"));
}


RING_FUNC(ring_SDL_FlushEvent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FlushEvent( (Uint32 ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_FlushEvents)
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
	SDL_FlushEvents( (Uint32 ) RING_API_GETNUMBER(1), (Uint32 ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SDL_GetEventFilter)
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
	RING_API_RETNUMBER(SDL_GetEventFilter((SDL_EventFilter *) RING_API_GETCPOINTER(1,"SDL_EventFilter"),(void **) RING_API_GETCPOINTER2POINTER(2,"void")));
}


RING_FUNC(ring_SDL_GetEventState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetEventState( (Uint32 ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetNumTouchDevices)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumTouchDevices());
}


RING_FUNC(ring_SDL_GetNumTouchFingers)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumTouchFingers(* (SDL_TouchID  *) RING_API_GETCPOINTER(1,"SDL_TouchID")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_TouchID"));
}


RING_FUNC(ring_SDL_GetTouchDevice)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		SDL_TouchID *pValue ; 
		pValue = (SDL_TouchID *) RING_API_MALLOC(sizeof(SDL_TouchID)) ;
		*pValue = SDL_GetTouchDevice( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_TouchID",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_GetTouchFinger)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetTouchFinger(* (SDL_TouchID  *) RING_API_GETCPOINTER(1,"SDL_TouchID"), (int ) RING_API_GETNUMBER(2)),"SDL_Finger");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_TouchID"));
}


RING_FUNC(ring_SDL_HasEvent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasEvent( (Uint32 ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_HasEvents)
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
	RING_API_RETNUMBER(SDL_HasEvents( (Uint32 ) RING_API_GETNUMBER(1), (Uint32 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_LoadDollarTemplates)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LoadDollarTemplates(* (SDL_TouchID  *) RING_API_GETCPOINTER(1,"SDL_TouchID"),(SDL_RWops *) RING_API_GETCPOINTER(2,"SDL_RWops")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_TouchID"));
}


RING_FUNC(ring_SDL_PeepEvents)
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
	RING_API_RETNUMBER(SDL_PeepEvents((SDL_Event *) RING_API_GETCPOINTER(1,"SDL_Event"), (int ) RING_API_GETNUMBER(2),* (SDL_eventaction  *) RING_API_GETCPOINTER(3,"SDL_eventaction"), (Uint32 ) RING_API_GETNUMBER(4), (Uint32 ) RING_API_GETNUMBER(5)));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_eventaction"));
}


RING_FUNC(ring_SDL_PollEvent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_PollEvent((SDL_Event *) RING_API_GETCPOINTER(1,"SDL_Event")));
}


RING_FUNC(ring_SDL_PumpEvents)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_PumpEvents();
}


RING_FUNC(ring_SDL_PushEvent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_PushEvent((SDL_Event *) RING_API_GETCPOINTER(1,"SDL_Event")));
}


RING_FUNC(ring_SDL_QuitRequested)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_QuitRequested());
}


RING_FUNC(ring_SDL_RecordGesture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(SDL_RecordGesture(* (SDL_TouchID  *) RING_API_GETCPOINTER(1,"SDL_TouchID")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_TouchID"));
}


RING_FUNC(ring_SDL_RegisterEvents)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RegisterEvents( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_SaveAllDollarTemplates)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SaveAllDollarTemplates((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_SaveDollarTemplate)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SaveDollarTemplate(* (SDL_GestureID  *) RING_API_GETCPOINTER(1,"SDL_GestureID"),(SDL_RWops *) RING_API_GETCPOINTER(2,"SDL_RWops")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_GestureID"));
}


RING_FUNC(ring_SDL_SetEventFilter)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_SetEventFilter(* (SDL_EventFilter  *) RING_API_GETCPOINTER(1,"SDL_EventFilter"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_EventFilter"));
}


RING_FUNC(ring_SDL_WaitEvent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_WaitEvent((SDL_Event *) RING_API_GETCPOINTER(1,"SDL_Event")));
}


RING_FUNC(ring_SDL_WaitEventTimeout)
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
	RING_API_RETNUMBER(SDL_WaitEventTimeout((SDL_Event *) RING_API_GETCPOINTER(1,"SDL_Event"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_GetKeyFromName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetKeyFromName(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GetKeyFromScancode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetKeyFromScancode( (SDL_Scancode )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetKeyName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetKeyName( (SDL_Keycode )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetKeyboardFocus)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetKeyboardFocus(),"SDL_Window");
}


RING_FUNC(ring_SDL_GetKeyboardState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetKeyboardState(RING_API_GETINTPOINTER(1)),"Uint8");
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_SDL_GetModState)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetModState());
}


RING_FUNC(ring_SDL_GetScancodeFromKey)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetScancodeFromKey( (SDL_Keycode )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetScancodeFromName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetScancodeFromName(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GetScancodeName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetScancodeName( (SDL_Scancode )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_HasScreenKeyboardSupport)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasScreenKeyboardSupport());
}


RING_FUNC(ring_SDL_IsScreenKeyboardShown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_IsScreenKeyboardShown((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window")));
}


RING_FUNC(ring_SDL_IsTextInputActive)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_IsTextInputActive());
}


RING_FUNC(ring_SDL_SetModState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_SetModState( (SDL_Keymod )  (int) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_SetTextInputRect)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_SetTextInputRect((SDL_Rect *) RING_API_GETCPOINTER(1,"SDL_Rect"));
}


RING_FUNC(ring_SDL_StartTextInput)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_StartTextInput();
}


RING_FUNC(ring_SDL_StopTextInput)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_StopTextInput();
}


RING_FUNC(ring_SDL_CreateColorCursor)
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
	RING_API_RETCPOINTER(SDL_CreateColorCursor((SDL_Surface *) RING_API_GETCPOINTER(1,"SDL_Surface"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"SDL_Cursor");
}


RING_FUNC(ring_SDL_CreateCursor)
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
	RING_API_RETCPOINTER(SDL_CreateCursor((Uint8 *) RING_API_GETCPOINTER(1,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6)),"SDL_Cursor");
}


RING_FUNC(ring_SDL_FreeCursor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FreeCursor((SDL_Cursor *) RING_API_GETCPOINTER(1,"SDL_Cursor"));
}


RING_FUNC(ring_SDL_GetCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetCursor(),"SDL_Cursor");
}


RING_FUNC(ring_SDL_GetDefaultCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetDefaultCursor(),"SDL_Cursor");
}


RING_FUNC(ring_SDL_GetMouseFocus)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GetMouseFocus(),"SDL_Window");
}


RING_FUNC(ring_SDL_GetMouseState)
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
	RING_API_RETNUMBER(SDL_GetMouseState(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_SDL_GetRelativeMouseMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetRelativeMouseMode());
}


RING_FUNC(ring_SDL_GetRelativeMouseState)
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
	RING_API_RETNUMBER(SDL_GetRelativeMouseState(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_SDL_SetCursor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_SetCursor((SDL_Cursor *) RING_API_GETCPOINTER(1,"SDL_Cursor"));
}


RING_FUNC(ring_SDL_SetRelativeMouseMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SetRelativeMouseMode( (SDL_bool ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_ShowCursor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ShowCursor( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_WarpMouseInWindow)
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
	SDL_WarpMouseInWindow((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_SDL_JoystickClose)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_JoystickClose((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick"));
}


RING_FUNC(ring_SDL_JoystickEventState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_JoystickEventState( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_JoystickGetAttached)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_JoystickGetAttached((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")));
}


RING_FUNC(ring_SDL_JoystickGetAxis)
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
	RING_API_RETNUMBER(SDL_JoystickGetAxis((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_JoystickGetBall)
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
	RING_API_RETNUMBER(SDL_JoystickGetBall((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick"), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_SDL_JoystickGetButton)
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
	RING_API_RETNUMBER(SDL_JoystickGetButton((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_JoystickGetDeviceGUID)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		SDL_JoystickGUID *pValue ; 
		pValue = (SDL_JoystickGUID *) RING_API_MALLOC(sizeof(SDL_JoystickGUID)) ;
		*pValue = SDL_JoystickGetDeviceGUID( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_JoystickGUID",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_JoystickGetGUID)
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
		SDL_JoystickGUID *pValue ; 
		pValue = (SDL_JoystickGUID *) RING_API_MALLOC(sizeof(SDL_JoystickGUID)) ;
		*pValue = SDL_JoystickGetGUID((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick"));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_JoystickGUID",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_JoystickGetGUIDFromString)
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
		SDL_JoystickGUID *pValue ; 
		pValue = (SDL_JoystickGUID *) RING_API_MALLOC(sizeof(SDL_JoystickGUID)) ;
		*pValue = SDL_JoystickGetGUIDFromString(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_JoystickGUID",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_JoystickGetGUIDString)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	SDL_JoystickGetGUIDString(* (SDL_JoystickGUID  *) RING_API_GETCPOINTER(1,"SDL_JoystickGUID"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_JoystickGUID"));
}


RING_FUNC(ring_SDL_JoystickGetHat)
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
	RING_API_RETNUMBER(SDL_JoystickGetHat((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_JoystickInstanceID)
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
		SDL_JoystickID *pValue ; 
		pValue = (SDL_JoystickID *) RING_API_MALLOC(sizeof(SDL_JoystickID)) ;
		*pValue = SDL_JoystickInstanceID((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick"));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_JoystickID",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_JoystickName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_JoystickName((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")));
}


RING_FUNC(ring_SDL_JoystickNameForIndex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_JoystickNameForIndex( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_JoystickNumAxes)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_JoystickNumAxes((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")));
}


RING_FUNC(ring_SDL_JoystickNumBalls)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_JoystickNumBalls((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")));
}


RING_FUNC(ring_SDL_JoystickNumButtons)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_JoystickNumButtons((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")));
}


RING_FUNC(ring_SDL_JoystickNumHats)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_JoystickNumHats((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")));
}


RING_FUNC(ring_SDL_JoystickOpen)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_JoystickOpen( (int ) RING_API_GETNUMBER(1)),"SDL_Joystick");
}


RING_FUNC(ring_SDL_JoystickUpdate)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_JoystickUpdate();
}


RING_FUNC(ring_SDL_NumJoysticks)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_NumJoysticks());
}


RING_FUNC(ring_SDL_GameControllerAddMapping)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GameControllerAddMapping(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GameControllerAddMappingsFromFile)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GameControllerAddMappingsFromFile(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GameControllerAddMappingsFromRW)
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
	RING_API_RETNUMBER(SDL_GameControllerAddMappingsFromRW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_GameControllerClose)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_GameControllerClose((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController"));
}


RING_FUNC(ring_SDL_GameControllerEventState)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GameControllerEventState( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GameControllerGetAttached)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GameControllerGetAttached((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController")));
}


RING_FUNC(ring_SDL_GameControllerGetAxis)
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
	RING_API_RETNUMBER(SDL_GameControllerGetAxis((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController"), (SDL_GameControllerAxis )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_GameControllerGetAxisFromString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GameControllerGetAxisFromString(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GameControllerGetBindForAxis)
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
	{
		SDL_GameControllerButtonBind *pValue ; 
		pValue = (SDL_GameControllerButtonBind *) RING_API_MALLOC(sizeof(SDL_GameControllerButtonBind)) ;
		*pValue = SDL_GameControllerGetBindForAxis((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController"), (SDL_GameControllerAxis )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_GameControllerButtonBind",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_GameControllerGetBindForButton)
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
	{
		SDL_GameControllerButtonBind *pValue ; 
		pValue = (SDL_GameControllerButtonBind *) RING_API_MALLOC(sizeof(SDL_GameControllerButtonBind)) ;
		*pValue = SDL_GameControllerGetBindForButton((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController"), (SDL_GameControllerButton )  (int) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_GameControllerButtonBind",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_GameControllerGetButton)
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
	RING_API_RETNUMBER(SDL_GameControllerGetButton((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController"), (SDL_GameControllerButton )  (int) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_GameControllerGetButtonFromString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GameControllerGetButtonFromString(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_GameControllerGetJoystick)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GameControllerGetJoystick((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController")),"SDL_Joystick");
}


RING_FUNC(ring_SDL_GameControllerGetStringForAxis)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GameControllerGetStringForAxis( (SDL_GameControllerAxis )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GameControllerGetStringForButton)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GameControllerGetStringForButton( (SDL_GameControllerButton )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GameControllerMapping)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GameControllerMapping((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController")));
}


RING_FUNC(ring_SDL_GameControllerMappingForGUID)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETSTRING(SDL_GameControllerMappingForGUID(* (SDL_JoystickGUID  *) RING_API_GETCPOINTER(1,"SDL_JoystickGUID")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_JoystickGUID"));
}


RING_FUNC(ring_SDL_GameControllerName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GameControllerName((SDL_GameController *) RING_API_GETCPOINTER(1,"SDL_GameController")));
}


RING_FUNC(ring_SDL_GameControllerNameForIndex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GameControllerNameForIndex( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GameControllerOpen)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_GameControllerOpen( (int ) RING_API_GETNUMBER(1)),"SDL_GameController");
}


RING_FUNC(ring_SDL_GameControllerUpdate)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_GameControllerUpdate();
}


RING_FUNC(ring_SDL_IsGameController)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_IsGameController( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_HapticClose)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_HapticClose((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"));
}


RING_FUNC(ring_SDL_HapticDestroyEffect)
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
	SDL_HapticDestroyEffect((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SDL_HapticEffectSupported)
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
	RING_API_RETNUMBER(SDL_HapticEffectSupported((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"),(SDL_HapticEffect *) RING_API_GETCPOINTER(2,"SDL_HapticEffect")));
}


RING_FUNC(ring_SDL_HapticGetEffectStatus)
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
	RING_API_RETNUMBER(SDL_HapticGetEffectStatus((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_HapticIndex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticIndex((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_HapticName( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_HapticNewEffect)
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
	RING_API_RETNUMBER(SDL_HapticNewEffect((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"),(SDL_HapticEffect *) RING_API_GETCPOINTER(2,"SDL_HapticEffect")));
}


RING_FUNC(ring_SDL_HapticNumAxes)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticNumAxes((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticNumEffects)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticNumEffects((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticNumEffectsPlaying)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticNumEffectsPlaying((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticOpen)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_HapticOpen( (int ) RING_API_GETNUMBER(1)),"SDL_Haptic");
}


RING_FUNC(ring_SDL_HapticOpenFromJoystick)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_HapticOpenFromJoystick((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")),"SDL_Haptic");
}


RING_FUNC(ring_SDL_HapticOpenFromMouse)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_HapticOpenFromMouse(),"SDL_Haptic");
}


RING_FUNC(ring_SDL_HapticOpened)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticOpened( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_HapticPause)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticPause((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticQuery)
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
		unsigned int *pValue ; 
		pValue = (unsigned int *) RING_API_MALLOC(sizeof(unsigned int)) ;
		*pValue = SDL_HapticQuery((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"));
		RING_API_RETMANAGEDCPOINTER(pValue,"unsigned int",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_HapticRumbleInit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticRumbleInit((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticRumblePlay)
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
	RING_API_RETNUMBER(SDL_HapticRumblePlay((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (float ) RING_API_GETNUMBER(2), (Uint32 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_HapticRumbleStop)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticRumbleStop((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticRumbleSupported)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticRumbleSupported((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticRunEffect)
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
	RING_API_RETNUMBER(SDL_HapticRunEffect((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (int ) RING_API_GETNUMBER(2), (Uint32 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_HapticSetAutocenter)
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
	RING_API_RETNUMBER(SDL_HapticSetAutocenter((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_HapticSetGain)
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
	RING_API_RETNUMBER(SDL_HapticSetGain((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_HapticStopAll)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticStopAll((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticStopEffect)
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
	RING_API_RETNUMBER(SDL_HapticStopEffect((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_HapticUnpause)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_HapticUnpause((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic")));
}


RING_FUNC(ring_SDL_HapticUpdateEffect)
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
	RING_API_RETNUMBER(SDL_HapticUpdateEffect((SDL_Haptic *) RING_API_GETCPOINTER(1,"SDL_Haptic"), (int ) RING_API_GETNUMBER(2),(SDL_HapticEffect *) RING_API_GETCPOINTER(3,"SDL_HapticEffect")));
}


RING_FUNC(ring_SDL_JoystickIsHaptic)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_JoystickIsHaptic((SDL_Joystick *) RING_API_GETCPOINTER(1,"SDL_Joystick")));
}


RING_FUNC(ring_SDL_MouseIsHaptic)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_MouseIsHaptic());
}


RING_FUNC(ring_SDL_NumHaptics)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_NumHaptics());
}


RING_FUNC(ring_SDL_AudioInit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_AudioInit(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_AudioQuit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_AudioQuit();
}


RING_FUNC(ring_SDL_BuildAudioCVT)
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
	RING_API_RETNUMBER(SDL_BuildAudioCVT((SDL_AudioCVT *) RING_API_GETCPOINTER(1,"SDL_AudioCVT"), (SDL_AudioFormat )  (int) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (SDL_AudioFormat )  (int) RING_API_GETNUMBER(5), (Uint8 ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7)));
}


RING_FUNC(ring_SDL_CloseAudio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_CloseAudio();
}


RING_FUNC(ring_SDL_CloseAudioDevice)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SDL_CloseAudioDevice(* (SDL_AudioDeviceID  *) RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
}


RING_FUNC(ring_SDL_ConvertAudio)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ConvertAudio((SDL_AudioCVT *) RING_API_GETCPOINTER(1,"SDL_AudioCVT")));
}


RING_FUNC(ring_SDL_FreeWAV)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FreeWAV((Uint8 *) RING_API_GETCPOINTER(1,"Uint8"));
}


RING_FUNC(ring_SDL_GetAudioDeviceName)
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
	RING_API_RETSTRING(SDL_GetAudioDeviceName( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_GetAudioDeviceStatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetAudioDeviceStatus(* (SDL_AudioDeviceID  *) RING_API_GETCPOINTER(1,"SDL_AudioDeviceID")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
}


RING_FUNC(ring_SDL_GetAudioDriver)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetAudioDriver( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetAudioStatus)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetAudioStatus());
}


RING_FUNC(ring_SDL_GetCurrentAudioDriver)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDL_GetCurrentAudioDriver());
}


RING_FUNC(ring_SDL_GetNumAudioDevices)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumAudioDevices( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_GetNumAudioDrivers)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetNumAudioDrivers());
}


RING_FUNC(ring_SDL_LoadWAV)
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
	RING_API_RETCPOINTER(SDL_LoadWAV(RING_API_GETSTRING(1),(SDL_AudioSpec *) RING_API_GETCPOINTER(2,"SDL_AudioSpec"),(Uint8 **) RING_API_GETCPOINTER2POINTER(3,"Uint8"),(Uint32 *) RING_API_GETCPOINTER(4,"Uint32")),"SDL_AudioSpec");
}


RING_FUNC(ring_SDL_LoadWAV_RW)
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
	RING_API_RETCPOINTER(SDL_LoadWAV_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2),(SDL_AudioSpec *) RING_API_GETCPOINTER(3,"SDL_AudioSpec"),(Uint8 **) RING_API_GETCPOINTER2POINTER(4,"Uint8"),(Uint32 *) RING_API_GETCPOINTER(5,"Uint32")),"SDL_AudioSpec");
}


RING_FUNC(ring_SDL_LockAudio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_LockAudio();
}


RING_FUNC(ring_SDL_LockAudioDevice)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SDL_LockAudioDevice(* (SDL_AudioDeviceID  *) RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
}


RING_FUNC(ring_SDL_MixAudio)
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
	SDL_MixAudio((Uint8 *) RING_API_GETCPOINTER(1,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8"), (Uint32 ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_SDL_MixAudioFormat)
{
	if ( RING_API_PARACOUNT != 5 ) {
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
	SDL_MixAudioFormat((Uint8 *) RING_API_GETCPOINTER(1,"Uint8"),(Uint8 *) RING_API_GETCPOINTER(2,"Uint8"), (SDL_AudioFormat )  (int) RING_API_GETNUMBER(3), (Uint32 ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_SDL_OpenAudio)
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
	RING_API_RETNUMBER(SDL_OpenAudio((SDL_AudioSpec *) RING_API_GETCPOINTER(1,"SDL_AudioSpec"),(SDL_AudioSpec *) RING_API_GETCPOINTER(2,"SDL_AudioSpec")));
}


RING_FUNC(ring_SDL_OpenAudioDevice)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		SDL_AudioDeviceID *pValue ; 
		pValue = (SDL_AudioDeviceID *) RING_API_MALLOC(sizeof(SDL_AudioDeviceID)) ;
		*pValue = SDL_OpenAudioDevice(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),(SDL_AudioSpec *) RING_API_GETCPOINTER(3,"SDL_AudioSpec"),(SDL_AudioSpec *) RING_API_GETCPOINTER(4,"SDL_AudioSpec"), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDL_AudioDeviceID",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_PauseAudio)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_PauseAudio( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SDL_PauseAudioDevice)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_PauseAudioDevice(* (SDL_AudioDeviceID  *) RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
}


RING_FUNC(ring_SDL_UnlockAudio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_UnlockAudio();
}


RING_FUNC(ring_SDL_UnlockAudioDevice)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SDL_UnlockAudioDevice(* (SDL_AudioDeviceID  *) RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDL_AudioDeviceID"));
}


RING_FUNC(ring_SDL_GetBasePath)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDL_GetBasePath());
}


RING_FUNC(ring_SDL_GetPrefPath)
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
	RING_API_RETSTRING(SDL_GetPrefPath(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_SDL_AllocRW)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_AllocRW(),"SDL_RWops");
}


RING_FUNC(ring_SDL_FreeRW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_FreeRW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"));
}


RING_FUNC(ring_SDL_RWFromConstMem)
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
	RING_API_RETCPOINTER(SDL_RWFromConstMem((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2)),"SDL_RWops");
}


RING_FUNC(ring_SDL_RWFromFP)
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
	RING_API_RETCPOINTER(SDL_RWFromFP((void *) RING_API_GETCPOINTER(1,"void"), (SDL_bool ) RING_API_GETNUMBER(2)),"SDL_RWops");
}


RING_FUNC(ring_SDL_RWFromFile)
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
	RING_API_RETCPOINTER(SDL_RWFromFile(RING_API_GETSTRING(1),RING_API_GETSTRING(2)),"SDL_RWops");
}


RING_FUNC(ring_SDL_RWFromMem)
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
	RING_API_RETCPOINTER(SDL_RWFromMem((void *) RING_API_GETCPOINTER(1,"void"), (int   ) RING_API_GETNUMBER(2)),"SDL_RWops");
}


RING_FUNC(ring_SDL_RWclose)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RWclose((struct SDL_RWops *) RING_API_GETCPOINTER(1,"struct SDL_RWops")));
}


RING_FUNC(ring_SDL_RWread)
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
	RING_API_RETNUMBER(SDL_RWread((struct SDL_RWops *) RING_API_GETCPOINTER(1,"struct SDL_RWops"),(void *) RING_API_GETCPOINTER(2,"void"), (size_t ) RING_API_GETNUMBER(3), (size_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_RWseek)
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
	{
		Sint64 *pValue ; 
		pValue = (Sint64 *) RING_API_MALLOC(sizeof(Sint64)) ;
		*pValue = SDL_RWseek((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"),* (Sint64  *) RING_API_GETCPOINTER(2,"Sint64"), (int ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Sint64"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Sint64",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_RWsize)
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
		Sint64 *pValue ; 
		pValue = (Sint64 *) RING_API_MALLOC(sizeof(Sint64)) ;
		*pValue = SDL_RWsize((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Sint64",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_RWtell)
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
		Sint64 *pValue ; 
		pValue = (Sint64 *) RING_API_MALLOC(sizeof(Sint64)) ;
		*pValue = SDL_RWtell((struct SDL_RWops *) RING_API_GETCPOINTER(1,"struct SDL_RWops"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Sint64",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDL_RWwrite)
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
	RING_API_RETNUMBER(SDL_RWwrite((struct SDL_RWops *) RING_API_GETCPOINTER(1,"struct SDL_RWops"),(void *) RING_API_GETCPOINTER(2,"void"), (size_t ) RING_API_GETNUMBER(3), (size_t ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_SDL_ReadBE16)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ReadBE16((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_ReadBE32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ReadBE32((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_ReadBE64)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ReadBE64((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_ReadLE16)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ReadLE16((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_ReadLE32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ReadLE32((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_ReadLE64)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ReadLE64((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_ReadU8)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_ReadU8((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_SDL_WriteBE16)
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
	RING_API_RETNUMBER(SDL_WriteBE16((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (Uint16 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_WriteBE32)
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
	RING_API_RETNUMBER(SDL_WriteBE32((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (Uint32 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_WriteBE64)
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
	RING_API_RETNUMBER(SDL_WriteBE64((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (Uint64 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_WriteLE16)
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
	RING_API_RETNUMBER(SDL_WriteLE16((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (Uint16 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_WriteLE32)
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
	RING_API_RETNUMBER(SDL_WriteLE32((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (Uint32 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_WriteLE64)
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
	RING_API_RETNUMBER(SDL_WriteLE64((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (Uint64 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_WriteU8)
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
	RING_API_RETNUMBER(SDL_WriteU8((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (Uint8 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_LoadFunction)
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
	RING_API_RETCPOINTER(SDL_LoadFunction((void *) RING_API_GETCPOINTER(1,"void"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_SDL_LoadObject)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_LoadObject(RING_API_GETSTRING(1)),"void");
}


RING_FUNC(ring_SDL_UnloadObject)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_UnloadObject((void *) RING_API_GETCPOINTER(1,"void"));
}


RING_FUNC(ring_SDL_GetPlatform)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDL_GetPlatform());
}


RING_FUNC(ring_SDL_GetCPUCacheLineSize)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetCPUCacheLineSize());
}


RING_FUNC(ring_SDL_GetCPUCount)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetCPUCount());
}


RING_FUNC(ring_SDL_GetSystemRAM)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetSystemRAM());
}


RING_FUNC(ring_SDL_Has3DNow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_Has3DNow());
}


RING_FUNC(ring_SDL_HasAVX)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasAVX());
}


RING_FUNC(ring_SDL_HasAltiVec)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasAltiVec());
}


RING_FUNC(ring_SDL_HasMMX)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasMMX());
}


RING_FUNC(ring_SDL_HasRDTSC)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasRDTSC());
}


RING_FUNC(ring_SDL_HasSSE)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasSSE());
}


RING_FUNC(ring_SDL_HasSSE2)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasSSE2());
}


RING_FUNC(ring_SDL_HasSSE3)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasSSE3());
}


RING_FUNC(ring_SDL_HasSSE41)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasSSE41());
}


RING_FUNC(ring_SDL_HasSSE42)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_HasSSE42());
}


RING_FUNC(ring_SDL_GetPowerInfo)
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
	RING_API_RETNUMBER(SDL_GetPowerInfo(RING_API_GETINTPOINTER(1),RING_API_GETINTPOINTER(2)));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_SDL_acos)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_acos( (double ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IMG_Init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_Init( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IMG_Quit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	IMG_Quit();
}


RING_FUNC(ring_IMG_Load)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_Load(RING_API_GETSTRING(1)),"SDL_Surface");
}


RING_FUNC(ring_IMG_Load_RW)
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
	RING_API_RETCPOINTER(IMG_Load_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2)),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadTyped_RW)
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
	RING_API_RETCPOINTER(IMG_LoadTyped_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3)),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadCUR_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadCUR_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadBMP_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadBMP_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadPNM_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadPNM_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadXPM_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadXPM_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadXCF_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadXCF_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadPCX_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadPCX_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadGIF_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadGIF_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadJPG_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadJPG_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadTIF_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadTIF_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadPNG_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadPNG_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadTGA_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadTGA_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadLBM_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadLBM_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_LoadXV_RW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_LoadXV_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")),"SDL_Surface");
}


RING_FUNC(ring_IMG_ReadXPMFromArray)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(IMG_ReadXPMFromArray((char **) RING_API_GETCPOINTER2POINTER(1,"char")),"SDL_Surface");
}


RING_FUNC(ring_IMG_isCUR)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isCUR((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isICO)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isICO((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isBMP)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isBMP((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isPNM)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isPNM((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isXPM)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isXPM((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isXCF)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isXCF((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isPCX)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isPCX((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isGIF)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isGIF((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isJPG)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isJPG((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isTIF)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isTIF((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isPNG)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isPNG((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isLBM)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isLBM((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_IMG_isXV)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IMG_isXV((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops")));
}


RING_FUNC(ring_TTF_Init)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(TTF_Init());
}


RING_FUNC(ring_TTF_WasInit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(TTF_WasInit());
}


RING_FUNC(ring_TTF_Quit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	TTF_Quit();
}


RING_FUNC(ring_TTF_OpenFont)
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
	RING_API_RETCPOINTER(TTF_OpenFont(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2)),"TTF_Font");
}


RING_FUNC(ring_TTF_OpenFontRW)
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
	RING_API_RETCPOINTER(TTF_OpenFontRW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"TTF_Font");
}


RING_FUNC(ring_TTF_OpenFontIndex)
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
	RING_API_RETCPOINTER(TTF_OpenFontIndex(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),* (long  *) RING_API_GETCPOINTER(3,"long")),"TTF_Font");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"long"));
}


RING_FUNC(ring_TTF_OpenFontIndexRW)
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
	RING_API_RETCPOINTER(TTF_OpenFontIndexRW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (long  *) RING_API_GETCPOINTER(4,"long")),"TTF_Font");
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"long"));
}


RING_FUNC(ring_TTF_CloseFont)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TTF_CloseFont((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"));
}


RING_FUNC(ring_TTF_ByteSwappedUNICODE)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TTF_ByteSwappedUNICODE( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_TTF_GetFontStyle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_GetFontStyle((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_SetFontStyle)
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
	TTF_SetFontStyle((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TTF_GetFontOutline)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_GetFontOutline((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_SetFontOutline)
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
	TTF_SetFontOutline((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TTF_GetFontHinting)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_GetFontHinting((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_SetFontHinting)
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
	TTF_SetFontHinting((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TTF_GetFontKerning)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_GetFontKerning((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_SetFontKerning)
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
	TTF_SetFontKerning((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_TTF_FontHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_FontHeight((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_FontAscent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_FontAscent((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_FontDescent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_FontDescent((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_FontLineSkip)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_FontLineSkip((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_FontFaces)
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
		long *pValue ; 
		pValue = (long *) RING_API_MALLOC(sizeof(long)) ;
		*pValue = TTF_FontFaces((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"));
		RING_API_RETMANAGEDCPOINTER(pValue,"long",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_TTF_FontFaceIsFixedWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_FontFaceIsFixedWidth((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_FontFaceFamilyName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TTF_FontFaceFamilyName((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_FontFaceStyleName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(TTF_FontFaceStyleName((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font")));
}


RING_FUNC(ring_TTF_GlyphIsProvided)
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
	RING_API_RETNUMBER(TTF_GlyphIsProvided((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (Uint16 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_TTF_GlyphMetrics)
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
	if ( ! RING_API_ISSTRING(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_GlyphMetrics((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (Uint16 ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5),RING_API_GETINTPOINTER(6),RING_API_GETINTPOINTER(7)));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
	RING_API_ACCEPTINTVALUE(5) ;
	RING_API_ACCEPTINTVALUE(6) ;
	RING_API_ACCEPTINTVALUE(7) ;
}


RING_FUNC(ring_TTF_SizeText)
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
	RING_API_RETNUMBER(TTF_SizeText((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_TTF_SizeUTF8)
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
	RING_API_RETNUMBER(TTF_SizeUTF8((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_TTF_SizeUNICODE)
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(TTF_SizeUNICODE((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_TTF_RenderText_Solid)
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
	RING_API_RETCPOINTER(TTF_RenderText_Solid((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderUTF8_Solid)
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
	RING_API_RETCPOINTER(TTF_RenderUTF8_Solid((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderUNICODE_Solid)
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
	RING_API_RETCPOINTER(TTF_RenderUNICODE_Solid((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderGlyph_Solid)
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
	RING_API_RETCPOINTER(TTF_RenderGlyph_Solid((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (Uint16 ) RING_API_GETNUMBER(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderText_Shaded)
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
	RING_API_RETCPOINTER(TTF_RenderText_Shaded((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color"),* (SDL_Color  *) RING_API_GETCPOINTER(4,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderUTF8_Shaded)
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
	RING_API_RETCPOINTER(TTF_RenderUTF8_Shaded((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color"),* (SDL_Color  *) RING_API_GETCPOINTER(4,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderUNICODE_Shaded)
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
	RING_API_RETCPOINTER(TTF_RenderUNICODE_Shaded((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color"),* (SDL_Color  *) RING_API_GETCPOINTER(4,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderGlyph_Shaded)
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
	RING_API_RETCPOINTER(TTF_RenderGlyph_Shaded((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (Uint16 ) RING_API_GETNUMBER(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color"),* (SDL_Color  *) RING_API_GETCPOINTER(4,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		RING_API_FREE(RING_API_GETCPOINTER(4,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderText_Blended)
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
	RING_API_RETCPOINTER(TTF_RenderText_Blended((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderUTF8_Blended)
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
	RING_API_RETCPOINTER(TTF_RenderUTF8_Blended((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),RING_API_GETSTRING(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderUNICODE_Blended)
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
	RING_API_RETCPOINTER(TTF_RenderUNICODE_Blended((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_TTF_RenderGlyph_Blended)
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
	RING_API_RETCPOINTER(TTF_RenderGlyph_Blended((TTF_Font *) RING_API_GETCPOINTER(1,"TTF_Font"), (Uint16 ) RING_API_GETNUMBER(2),* (SDL_Color  *) RING_API_GETCPOINTER(3,"SDL_Color")),"SDL_Surface");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"SDL_Color"));
}


RING_FUNC(ring_Mix_Init)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_Init( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_Quit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	Mix_Quit();
}


RING_FUNC(ring_Mix_OpenAudio)
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
	RING_API_RETNUMBER(Mix_OpenAudio( (int ) RING_API_GETNUMBER(1), (Uint16 ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_Mix_CloseAudio)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	Mix_CloseAudio();
}


RING_FUNC(ring_Mix_GetError)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(Mix_GetError());
}


RING_FUNC(ring_Mix_QuerySpec)
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_QuerySpec(RING_API_GETINTPOINTER(1),(Uint16 *) RING_API_GETCPOINTER(2,"Uint16"),RING_API_GETINTPOINTER(3)));
	RING_API_ACCEPTINTVALUE(1) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_Mix_GetNumChunkDecoders)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(Mix_GetNumChunkDecoders());
}


RING_FUNC(ring_Mix_GetChunkDecoder)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(Mix_GetChunkDecoder( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_LoadWAV)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(Mix_LoadWAV(RING_API_GETSTRING(1)),"Mix_Chunk");
}


RING_FUNC(ring_Mix_LoadWAV_RW)
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
	RING_API_RETCPOINTER(Mix_LoadWAV_RW((SDL_RWops *) RING_API_GETCPOINTER(1,"SDL_RWops"), (int ) RING_API_GETNUMBER(2)),"Mix_Chunk");
}


RING_FUNC(ring_Mix_QuickLoad_WAV)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(Mix_QuickLoad_WAV((Uint8 *) RING_API_GETCPOINTER(1,"Uint8")),"Mix_Chunk");
}


RING_FUNC(ring_Mix_VolumeChunk)
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
	RING_API_RETNUMBER(Mix_VolumeChunk((Mix_Chunk *) RING_API_GETCPOINTER(1,"Mix_Chunk"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_FreeChunk)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	Mix_FreeChunk((Mix_Chunk *) RING_API_GETCPOINTER(1,"Mix_Chunk"));
}


RING_FUNC(ring_Mix_AllocateChannels)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_AllocateChannels( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_Volume)
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
	RING_API_RETNUMBER(Mix_Volume( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_PlayChannel)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_PlayChannel( (int ) RING_API_GETNUMBER(1),(Mix_Chunk *) RING_API_GETCPOINTER(2,"Mix_Chunk"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Mix_PlayChannelTimed)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_PlayChannelTimed( (int ) RING_API_GETNUMBER(1),(Mix_Chunk *) RING_API_GETCPOINTER(2,"Mix_Chunk"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_Mix_FadeInChannel)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_FadeInChannel( (int ) RING_API_GETNUMBER(1),(Mix_Chunk *) RING_API_GETCPOINTER(2,"Mix_Chunk"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_Mix_FadeInChannelTimed)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETNUMBER(Mix_FadeInChannelTimed( (int ) RING_API_GETNUMBER(1),(Mix_Chunk *) RING_API_GETCPOINTER(2,"Mix_Chunk"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_Mix_Pause)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	Mix_Pause( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_Mix_Resume)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	Mix_Resume( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_Mix_HaltChannel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_HaltChannel( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_ExpireChannel)
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
	RING_API_RETNUMBER(Mix_ExpireChannel( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_FadeOutChannel)
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
	RING_API_RETNUMBER(Mix_FadeOutChannel( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_Playing)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_Playing( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_Paused)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_Paused( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_FadingChannel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Mix_Fading *pValue ; 
		pValue = (Mix_Fading *) RING_API_MALLOC(sizeof(Mix_Fading)) ;
		*pValue = Mix_FadingChannel( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mix_Fading",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Mix_GetChunk)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(Mix_GetChunk( (int ) RING_API_GETNUMBER(1)),"Mix_Chunk");
}


RING_FUNC(ring_Mix_ReserveChannels)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_ReserveChannels( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_GroupChannel)
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
	RING_API_RETNUMBER(Mix_GroupChannel( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_GroupChannels)
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
	RING_API_RETNUMBER(Mix_GroupChannels( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Mix_GroupCount)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_GroupCount( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_GroupAvailable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_GroupAvailable( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_GroupOldest)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_GroupOldest( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_GroupNewer)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_GroupNewer( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_FadeOutGroup)
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
	RING_API_RETNUMBER(Mix_FadeOutGroup( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_HaltGroup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_HaltGroup( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_GetNumMusicDecoders)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(Mix_GetNumMusicDecoders());
}


RING_FUNC(ring_Mix_GetMusicDecoder)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(Mix_GetMusicDecoder( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_LoadMUS)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(Mix_LoadMUS(RING_API_GETSTRING(1)),"Mix_Music");
}


RING_FUNC(ring_Mix_FreeMusic)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	Mix_FreeMusic((Mix_Music *) RING_API_GETCPOINTER(1,"Mix_Music"));
}


RING_FUNC(ring_Mix_PlayMusic)
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
	RING_API_RETNUMBER(Mix_PlayMusic((Mix_Music *) RING_API_GETCPOINTER(1,"Mix_Music"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_FadeInMusic)
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
	RING_API_RETNUMBER(Mix_FadeInMusic((Mix_Music *) RING_API_GETCPOINTER(1,"Mix_Music"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Mix_FadeInMusicPos)
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
	RING_API_RETNUMBER(Mix_FadeInMusicPos((Mix_Music *) RING_API_GETCPOINTER(1,"Mix_Music"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4)));
}


RING_FUNC(ring_Mix_GetMusicType)
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
		Mix_MusicType *pValue ; 
		pValue = (Mix_MusicType *) RING_API_MALLOC(sizeof(Mix_MusicType)) ;
		*pValue = Mix_GetMusicType((Mix_Music *) RING_API_GETCPOINTER(1,"Mix_Music"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Mix_MusicType",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Mix_PlayingMusic)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(Mix_PlayingMusic());
}


RING_FUNC(ring_Mix_PausedMusic)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(Mix_PausedMusic());
}


RING_FUNC(ring_Mix_FadingMusic)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Mix_Fading *pValue ; 
		pValue = (Mix_Fading *) RING_API_MALLOC(sizeof(Mix_Fading)) ;
		*pValue = Mix_FadingMusic();
		RING_API_RETMANAGEDCPOINTER(pValue,"Mix_Fading",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_Mix_GetMusicHookData)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(Mix_GetMusicHookData(),"void");
}


RING_FUNC(ring_Mix_RegisterEffect)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_RegisterEffect( (int ) RING_API_GETNUMBER(1),* (Mix_EffectFunc_t  *) RING_API_GETCPOINTER(2,"Mix_EffectFunc_t"),* (Mix_EffectDone_t  *) RING_API_GETCPOINTER(3,"Mix_EffectDone_t"),(void *) RING_API_GETCPOINTER(4,"void")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Mix_EffectFunc_t"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		RING_API_FREE(RING_API_GETCPOINTER(3,"Mix_EffectDone_t"));
}


RING_FUNC(ring_Mix_UnregisterEffect)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_UnregisterEffect( (int ) RING_API_GETNUMBER(1),* (Mix_EffectFunc_t  *) RING_API_GETCPOINTER(2,"Mix_EffectFunc_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"Mix_EffectFunc_t"));
}


RING_FUNC(ring_Mix_UnregisterAllEffects)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(Mix_UnregisterAllEffects( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_Mix_SetPanning)
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
	RING_API_RETNUMBER(Mix_SetPanning( (int ) RING_API_GETNUMBER(1), (Uint8 ) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Mix_SetDistance)
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
	RING_API_RETNUMBER(Mix_SetDistance( (int ) RING_API_GETNUMBER(1), (Uint8 ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_Mix_SetPosition)
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
	RING_API_RETNUMBER(Mix_SetPosition( (int ) RING_API_GETNUMBER(1), (Sint16 ) RING_API_GETNUMBER(2), (Uint8 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_Mix_SetReverseStereo)
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
	RING_API_RETNUMBER(Mix_SetReverseStereo( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDLNet_Init)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_Init());
}


RING_FUNC(ring_SDLNet_Quit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDLNet_Quit();
}


RING_FUNC(ring_SDLNet_GetError)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(SDLNet_GetError());
}


RING_FUNC(ring_SDLNet_Write16)
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
	SDLNet_Write16( (Uint16 ) RING_API_GETNUMBER(1),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_SDLNet_Write32)
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
	SDLNet_Write32( (Uint32 ) RING_API_GETNUMBER(1),(void *) RING_API_GETCPOINTER(2,"void"));
}


RING_FUNC(ring_SDLNet_Read16)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_Read16((void *) RING_API_GETCPOINTER(1,"void")));
}


RING_FUNC(ring_SDLNet_Read32)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_Read32((void *) RING_API_GETCPOINTER(1,"void")));
}


RING_FUNC(ring_SDLNet_ResolveHost)
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
	RING_API_RETNUMBER(SDLNet_ResolveHost((IPaddress *) RING_API_GETCPOINTER(1,"IPaddress"),RING_API_GETSTRING(2), (Uint16 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDLNet_ResolveIP)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDLNet_ResolveIP((IPaddress *) RING_API_GETCPOINTER(1,"IPaddress")));
}


RING_FUNC(ring_SDLNet_TCP_Open)
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
		TCPsocket *pValue ; 
		pValue = (TCPsocket *) RING_API_MALLOC(sizeof(TCPsocket)) ;
		*pValue = SDLNet_TCP_Open((IPaddress *) RING_API_GETCPOINTER(1,"IPaddress"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TCPsocket",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDLNet_TCP_Close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SDLNet_TCP_Close(* (TCPsocket  *) RING_API_GETCPOINTER(1,"TCPsocket"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"TCPsocket"));
}

RING_FUNC(ring_SDLNet_TCP_Accept)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		TCPsocket *pValue ;
		TCPsocket aValue;
		aValue = SDLNet_TCP_Accept(* (TCPsocket  *) RING_API_GETCPOINTER(1,"TCPsocket"));

		if (! aValue ) {
			RING_API_RETCPOINTER(NULL,"TCPsocket");
		} else {
			pValue = (TCPsocket *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TCPsocket)) ;
			*pValue = aValue;
			RING_API_RETCPOINTER(pValue,"TCPsocket");
		}

		if (RING_API_ISCPOINTERNOTASSIGNED(1))
			ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TCPsocket"));

	}
}

RING_FUNC(ring_SDLNet_TCP_GetPeerAddress)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(SDLNet_TCP_GetPeerAddress(* (TCPsocket  *) RING_API_GETCPOINTER(1,"TCPsocket")),"IPaddress");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"TCPsocket"));
}


RING_FUNC(ring_SDLNet_TCP_Send)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(SDLNet_TCP_Send(* (TCPsocket  *) RING_API_GETCPOINTER(1,"TCPsocket"),(void *) RING_API_GETCPOINTER(2,"void"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"TCPsocket"));
}


RING_FUNC(ring_SDLNet_TCP_Recv)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(SDLNet_TCP_Recv(* (TCPsocket  *) RING_API_GETCPOINTER(1,"TCPsocket"),(void *) RING_API_GETCPOINTER(2,"void"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"TCPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_Open)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		UDPsocket *pValue ; 
		pValue = (UDPsocket *) RING_API_MALLOC(sizeof(UDPsocket)) ;
		*pValue = SDLNet_UDP_Open( (Uint16 ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"UDPsocket",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDLNet_UDP_Close)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SDLNet_UDP_Close(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_Bind)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(SDLNet_UDP_Bind(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"), (int ) RING_API_GETNUMBER(2),(IPaddress *) RING_API_GETCPOINTER(3,"IPaddress")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_Unbind)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDLNet_UDP_Unbind(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_GetPeerAddress)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDLNet_UDP_GetPeerAddress(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"), (int ) RING_API_GETNUMBER(2)),"IPaddress");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_Send)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(SDLNet_UDP_Send(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"), (int ) RING_API_GETNUMBER(2),(UDPpacket *) RING_API_GETCPOINTER(3,"UDPpacket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_Recv)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_UDP_Recv(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"),(UDPpacket *) RING_API_GETCPOINTER(2,"UDPpacket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_SendV)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(SDLNet_UDP_SendV(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"),(UDPpacket **) RING_API_GETCPOINTER2POINTER(2,"UDPpacket"), (int ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_RecvV)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_UDP_RecvV(* (UDPsocket  *) RING_API_GETCPOINTER(1,"UDPsocket"),(UDPpacket **) RING_API_GETCPOINTER2POINTER(2,"UDPpacket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_AllocPacket)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDLNet_AllocPacket( (int ) RING_API_GETNUMBER(1)),"UDPpacket");
}


RING_FUNC(ring_SDLNet_ResizePacket)
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
	RING_API_RETNUMBER(SDLNet_ResizePacket((UDPpacket *) RING_API_GETCPOINTER(1,"UDPpacket"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDLNet_FreePacket)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDLNet_FreePacket((UDPpacket *) RING_API_GETCPOINTER(1,"UDPpacket"));
}


RING_FUNC(ring_SDLNet_AllocPacketV)
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
	RING_API_RETCPOINTER(SDLNet_AllocPacketV( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)),"UDPpacket");
}


RING_FUNC(ring_SDLNet_FreePacketV)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDLNet_FreePacketV((UDPpacket **) RING_API_GETCPOINTER2POINTER(1,"UDPpacket"));
}


RING_FUNC(ring_SDLNet_AllocSocketSet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		SDLNet_SocketSet *pValue ; 
		pValue = (SDLNet_SocketSet *) RING_API_MALLOC(sizeof(SDLNet_SocketSet)) ;
		*pValue = SDLNet_AllocSocketSet( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"SDLNet_SocketSet",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_SDLNet_FreeSocketSet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SDLNet_FreeSocketSet(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
}


RING_FUNC(ring_SDLNet_AddSocket)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_AddSocket(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"),* (SDLNet_GenericSocket  *) RING_API_GETCPOINTER(2,"SDLNet_GenericSocket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"SDLNet_GenericSocket"));
}


RING_FUNC(ring_SDLNet_TCP_AddSocket)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_TCP_AddSocket(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"),* (TCPsocket  *) RING_API_GETCPOINTER(2,"TCPsocket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"TCPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_AddSocket)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_UDP_AddSocket(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"),* (UDPsocket  *) RING_API_GETCPOINTER(2,"UDPsocket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_DelSocket)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_DelSocket(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"),* (SDLNet_GenericSocket  *) RING_API_GETCPOINTER(2,"SDLNet_GenericSocket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"SDLNet_GenericSocket"));
}


RING_FUNC(ring_SDLNet_TCP_DelSocket)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_TCP_DelSocket(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"),* (TCPsocket  *) RING_API_GETCPOINTER(2,"TCPsocket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"TCPsocket"));
}


RING_FUNC(ring_SDLNet_UDP_DelSocket)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_UDP_DelSocket(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"),* (UDPsocket  *) RING_API_GETCPOINTER(2,"UDPsocket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"UDPsocket"));
}


RING_FUNC(ring_SDLNet_CheckSockets)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_CheckSockets(* (SDLNet_SocketSet  *) RING_API_GETCPOINTER(1,"SDLNet_SocketSet"), (Uint32 ) RING_API_GETNUMBER(2)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"SDLNet_SocketSet"));
}


RING_FUNC(ring_SDLNet_SocketReady)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(SDLNet_SocketReady(* (TCPsocket  *) RING_API_GETCPOINTER(1,"TCPsocket")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		RING_API_FREE(RING_API_GETCPOINTER(1,"TCPsocket"));
}


RING_FUNC(ring_circleRGBA)
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
	RING_API_RETNUMBER(circleRGBA((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (Sint16 ) RING_API_GETNUMBER(2), (Sint16 ) RING_API_GETNUMBER(3), (Sint16 ) RING_API_GETNUMBER(4), (Uint8 ) RING_API_GETNUMBER(5), (Uint8 ) RING_API_GETNUMBER(6), (Uint8 ) RING_API_GETNUMBER(7), (Uint8 ) RING_API_GETNUMBER(8)));
}


int SDL_Thread_Function(void *pPointer) {
	VM *pVM;
	List *pList;
	pList = (List *) pPointer;
	pVM = ring_list_getpointer(pList,1);
	ring_vm_runcodefromthread(pVM,ring_list_getstring(pList,2));
	ring_list_delete(pList);	
	return 1;
}

RING_FUNC(ring_SDL_CreateThread) {
	List *pList;
	if ( RING_API_PARACOUNT != 2 ) {
RING_API_ERROR(RING_API_MISS2PARA);
return ;
}
if ( ! RING_API_ISSTRING(1) || ! RING_API_ISSTRING(2) ) {
RING_API_ERROR(RING_API_BADPARATYPE);
return ;
}
	pList = ring_list_new(0) ;
	ring_list_addpointer(pList,pPointer);
	ring_list_addstring(pList,RING_API_GETSTRING(1));
	ring_vm_mutexfunctions((VM *) pPointer,SDL_CreateMutex,
SDL_LockMutex,SDL_UnlockMutex,SDL_DestroyMutex);
	SDL_CreateThread(SDL_Thread_Function, RING_API_GETSTRING(2), (void *) pList);
	
}

RING_FUNC(ring_SDL_DetachThread)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DetachThread((SDL_Thread *) RING_API_GETCPOINTER(1,"SDL_Thread"));
}


RING_FUNC(ring_SDL_GetThreadID)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GetThreadID((SDL_Thread *) RING_API_GETCPOINTER(1,"SDL_Thread")));
}


RING_FUNC(ring_SDL_GetThreadName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetThreadName((SDL_Thread *) RING_API_GETCPOINTER(1,"SDL_Thread")));
}


RING_FUNC(ring_SDL_SetThreadPriority)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SetThreadPriority( (SDL_ThreadPriority )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_SDL_TLSCreate)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_TLSCreate());
}


RING_FUNC(ring_SDL_TLSGet)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_TLSGet( (SDL_TLSID ) RING_API_GETNUMBER(1)),"void");
}


RING_FUNC(ring_SDL_TLSSet)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_TLSSet( (SDL_TLSID   ) RING_API_GETNUMBER(1),(void *) RING_API_GETCPOINTER(2,"void"),(void *) RING_API_GETCPOINTER(3,"void")));
}


RING_FUNC(ring_SDL_ThreadID)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(SDL_ThreadID());
}


RING_FUNC(ring_SDL_WaitThread)
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
	SDL_WaitThread((SDL_Thread *) RING_API_GETCPOINTER(1,"SDL_Thread"),RING_API_GETINTPOINTER(2));
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_SDL_CondBroadcast)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_CondBroadcast((SDL_cond *) RING_API_GETCPOINTER(1,"SDL_cond")));
}


RING_FUNC(ring_SDL_CondSignal)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_CondSignal((SDL_cond *) RING_API_GETCPOINTER(1,"SDL_cond")));
}


RING_FUNC(ring_SDL_CondWait)
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
	RING_API_RETNUMBER(SDL_CondWait((SDL_cond *) RING_API_GETCPOINTER(1,"SDL_cond"),(SDL_mutex *) RING_API_GETCPOINTER(2,"SDL_mutex")));
}


RING_FUNC(ring_SDL_CondWaitTimeout)
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
	RING_API_RETNUMBER(SDL_CondWaitTimeout((SDL_cond *) RING_API_GETCPOINTER(1,"SDL_cond"),(SDL_mutex *) RING_API_GETCPOINTER(2,"SDL_mutex"), (Uint32 ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_SDL_CreateCond)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_CreateCond(),"SDL_cond");
}


RING_FUNC(ring_SDL_CreateMutex)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(SDL_CreateMutex(),"SDL_mutex");
}


RING_FUNC(ring_SDL_CreateSemaphore)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(SDL_CreateSemaphore( (Uint32 ) RING_API_GETNUMBER(1)),"SDL_sem");
}


RING_FUNC(ring_SDL_DestroyCond)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DestroyCond((SDL_cond *) RING_API_GETCPOINTER(1,"SDL_cond"));
}


RING_FUNC(ring_SDL_DestroyMutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DestroyMutex((SDL_mutex *) RING_API_GETCPOINTER(1,"SDL_mutex"));
}


RING_FUNC(ring_SDL_DestroySemaphore)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_DestroySemaphore((SDL_sem *) RING_API_GETCPOINTER(1,"SDL_sem"));
}


RING_FUNC(ring_SDL_LockMutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LockMutex((SDL_mutex *) RING_API_GETCPOINTER(1,"SDL_mutex")));
}


RING_FUNC(ring_SDL_SemPost)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SemPost((SDL_sem *) RING_API_GETCPOINTER(1,"SDL_sem")));
}


RING_FUNC(ring_SDL_SemTryWait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SemTryWait((SDL_sem *) RING_API_GETCPOINTER(1,"SDL_sem")));
}


RING_FUNC(ring_SDL_SemValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SemValue((SDL_sem *) RING_API_GETCPOINTER(1,"SDL_sem")));
}


RING_FUNC(ring_SDL_SemWait)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SemWait((SDL_sem *) RING_API_GETCPOINTER(1,"SDL_sem")));
}


RING_FUNC(ring_SDL_SemWaitTimeout)
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
	RING_API_RETNUMBER(SDL_SemWaitTimeout((SDL_sem *) RING_API_GETCPOINTER(1,"SDL_sem"), (Uint32   ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_SDL_TryLockMutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_TryLockMutex((SDL_mutex *) RING_API_GETCPOINTER(1,"SDL_mutex")));
}


RING_FUNC(ring_SDL_UnlockMutex)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_UnlockMutex((SDL_mutex *) RING_API_GETCPOINTER(1,"SDL_mutex")));
}

RING_LIBINIT
{
	RING_API_REGISTER("sdl_rendercopy2",ring_SDL_RenderCopy2);
	RING_API_REGISTER("sdl_delay",ring_SDL_Delay);
	RING_API_REGISTER("sdl_init",ring_SDL_Init);
	RING_API_REGISTER("sdl_initsubsystem",ring_SDL_InitSubSystem);
	RING_API_REGISTER("sdl_quit",ring_SDL_Quit);
	RING_API_REGISTER("sdl_quitsubsystem",ring_SDL_QuitSubSystem);
	RING_API_REGISTER("sdl_setmainready",ring_SDL_SetMainReady);
	RING_API_REGISTER("sdl_wasinit",ring_SDL_WasInit);
	RING_API_REGISTER("sdl_clearhints",ring_SDL_ClearHints);
	RING_API_REGISTER("sdl_gethint",ring_SDL_GetHint);
	RING_API_REGISTER("sdl_sethint",ring_SDL_SetHint);
	RING_API_REGISTER("sdl_sethintwithpriority",ring_SDL_SetHintWithPriority);
	RING_API_REGISTER("sdl_clearerror",ring_SDL_ClearError);
	RING_API_REGISTER("sdl_geterror",ring_SDL_GetError);
	RING_API_REGISTER("sdl_loggetpriority",ring_SDL_LogGetPriority);
	RING_API_REGISTER("sdl_logresetpriorities",ring_SDL_LogResetPriorities);
	RING_API_REGISTER("sdl_logsetallpriority",ring_SDL_LogSetAllPriority);
	RING_API_REGISTER("sdl_logsetpriority",ring_SDL_LogSetPriority);
	RING_API_REGISTER("sdl_getassertionreport",ring_SDL_GetAssertionReport);
	RING_API_REGISTER("sdl_getdefaultassertionhandler",ring_SDL_GetDefaultAssertionHandler);
	RING_API_REGISTER("sdl_resetassertionreport",ring_SDL_ResetAssertionReport);
	RING_API_REGISTER("sdl_setassertionhandler",ring_SDL_SetAssertionHandler);
	RING_API_REGISTER("sdl_triggerbreakpoint",ring_SDL_TriggerBreakpoint);
	RING_API_REGISTER("sdl_assert",ring_SDL_assert);
	RING_API_REGISTER("sdl_assert_paranoid",ring_SDL_assert_paranoid);
	RING_API_REGISTER("sdl_assert_release",ring_SDL_assert_release);
	RING_API_REGISTER("sdl_getrevision",ring_SDL_GetRevision);
	RING_API_REGISTER("sdl_getrevisionnumber",ring_SDL_GetRevisionNumber);
	RING_API_REGISTER("sdl_getversion",ring_SDL_GetVersion);
	RING_API_REGISTER("sdl_createwindow",ring_SDL_CreateWindow);
	RING_API_REGISTER("sdl_createwindowfrom",ring_SDL_CreateWindowFrom);
	RING_API_REGISTER("sdl_destroywindow",ring_SDL_DestroyWindow);
	RING_API_REGISTER("sdl_disablescreensaver",ring_SDL_DisableScreenSaver);
	RING_API_REGISTER("sdl_enablescreensaver",ring_SDL_EnableScreenSaver);
	RING_API_REGISTER("sdl_gl_createcontext",ring_SDL_GL_CreateContext);
	RING_API_REGISTER("sdl_gl_deletecontext",ring_SDL_GL_DeleteContext);
	RING_API_REGISTER("sdl_gl_extensionsupported",ring_SDL_GL_ExtensionSupported);
	RING_API_REGISTER("sdl_gl_getattribute",ring_SDL_GL_GetAttribute);
	RING_API_REGISTER("sdl_gl_getcurrentcontext",ring_SDL_GL_GetCurrentContext);
	RING_API_REGISTER("sdl_gl_getcurrentwindow",ring_SDL_GL_GetCurrentWindow);
	RING_API_REGISTER("sdl_gl_getdrawablesize",ring_SDL_GL_GetDrawableSize);
	RING_API_REGISTER("sdl_gl_getprocaddress",ring_SDL_GL_GetProcAddress);
	RING_API_REGISTER("sdl_gl_getswapinterval",ring_SDL_GL_GetSwapInterval);
	RING_API_REGISTER("sdl_gl_loadlibrary",ring_SDL_GL_LoadLibrary);
	RING_API_REGISTER("sdl_gl_makecurrent",ring_SDL_GL_MakeCurrent);
	RING_API_REGISTER("sdl_gl_resetattributes",ring_SDL_GL_ResetAttributes);
	RING_API_REGISTER("sdl_gl_setattribute",ring_SDL_GL_SetAttribute);
	RING_API_REGISTER("sdl_gl_setswapinterval",ring_SDL_GL_SetSwapInterval);
	RING_API_REGISTER("sdl_gl_swapwindow",ring_SDL_GL_SwapWindow);
	RING_API_REGISTER("sdl_gl_unloadlibrary",ring_SDL_GL_UnloadLibrary);
	RING_API_REGISTER("sdl_getclosestdisplaymode",ring_SDL_GetClosestDisplayMode);
	RING_API_REGISTER("sdl_getcurrentdisplaymode",ring_SDL_GetCurrentDisplayMode);
	RING_API_REGISTER("sdl_getcurrentvideodriver",ring_SDL_GetCurrentVideoDriver);
	RING_API_REGISTER("sdl_getdesktopdisplaymode",ring_SDL_GetDesktopDisplayMode);
	RING_API_REGISTER("sdl_getdisplaybounds",ring_SDL_GetDisplayBounds);
	RING_API_REGISTER("sdl_getnumdisplaymodes",ring_SDL_GetNumDisplayModes);
	RING_API_REGISTER("sdl_getnumvideodisplays",ring_SDL_GetNumVideoDisplays);
	RING_API_REGISTER("sdl_getnumvideodrivers",ring_SDL_GetNumVideoDrivers);
	RING_API_REGISTER("sdl_getvideodriver",ring_SDL_GetVideoDriver);
	RING_API_REGISTER("sdl_getwindowbrightness",ring_SDL_GetWindowBrightness);
	RING_API_REGISTER("sdl_getwindowdata",ring_SDL_GetWindowData);
	RING_API_REGISTER("sdl_getwindowdisplayindex",ring_SDL_GetWindowDisplayIndex);
	RING_API_REGISTER("sdl_getwindowdisplaymode",ring_SDL_GetWindowDisplayMode);
	RING_API_REGISTER("sdl_getwindowflags",ring_SDL_GetWindowFlags);
	RING_API_REGISTER("sdl_getwindowfromid",ring_SDL_GetWindowFromID);
	RING_API_REGISTER("sdl_getwindowgammaramp",ring_SDL_GetWindowGammaRamp);
	RING_API_REGISTER("sdl_getwindowgrab",ring_SDL_GetWindowGrab);
	RING_API_REGISTER("sdl_getwindowid",ring_SDL_GetWindowID);
	RING_API_REGISTER("sdl_getwindowmaximumsize",ring_SDL_GetWindowMaximumSize);
	RING_API_REGISTER("sdl_getwindowminimumsize",ring_SDL_GetWindowMinimumSize);
	RING_API_REGISTER("sdl_getwindowpixelformat",ring_SDL_GetWindowPixelFormat);
	RING_API_REGISTER("sdl_getwindowposition",ring_SDL_GetWindowPosition);
	RING_API_REGISTER("sdl_getwindowsize",ring_SDL_GetWindowSize);
	RING_API_REGISTER("sdl_getwindowsurface",ring_SDL_GetWindowSurface);
	RING_API_REGISTER("sdl_getwindowtitle",ring_SDL_GetWindowTitle);
	RING_API_REGISTER("sdl_hidewindow",ring_SDL_HideWindow);
	RING_API_REGISTER("sdl_isscreensaverenabled",ring_SDL_IsScreenSaverEnabled);
	RING_API_REGISTER("sdl_maximizewindow",ring_SDL_MaximizeWindow);
	RING_API_REGISTER("sdl_minimizewindow",ring_SDL_MinimizeWindow);
	RING_API_REGISTER("sdl_raisewindow",ring_SDL_RaiseWindow);
	RING_API_REGISTER("sdl_restorewindow",ring_SDL_RestoreWindow);
	RING_API_REGISTER("sdl_setwindowbordered",ring_SDL_SetWindowBordered);
	RING_API_REGISTER("sdl_setwindowbrightness",ring_SDL_SetWindowBrightness);
	RING_API_REGISTER("sdl_setwindowdata",ring_SDL_SetWindowData);
	RING_API_REGISTER("sdl_setwindowdisplaymode",ring_SDL_SetWindowDisplayMode);
	RING_API_REGISTER("sdl_setwindowfullscreen",ring_SDL_SetWindowFullscreen);
	RING_API_REGISTER("sdl_setwindowgammaramp",ring_SDL_SetWindowGammaRamp);
	RING_API_REGISTER("sdl_setwindowgrab",ring_SDL_SetWindowGrab);
	RING_API_REGISTER("sdl_setwindowicon",ring_SDL_SetWindowIcon);
	RING_API_REGISTER("sdl_setwindowmaximumsize",ring_SDL_SetWindowMaximumSize);
	RING_API_REGISTER("sdl_setwindowminimumsize",ring_SDL_SetWindowMinimumSize);
	RING_API_REGISTER("sdl_setwindowposition",ring_SDL_SetWindowPosition);
	RING_API_REGISTER("sdl_setwindowsize",ring_SDL_SetWindowSize);
	RING_API_REGISTER("sdl_setwindowtitle",ring_SDL_SetWindowTitle);
	RING_API_REGISTER("sdl_showmessagebox",ring_SDL_ShowMessageBox);
	RING_API_REGISTER("sdl_showsimplemessagebox",ring_SDL_ShowSimpleMessageBox);
	RING_API_REGISTER("sdl_showwindow",ring_SDL_ShowWindow);
	RING_API_REGISTER("sdl_updatewindowsurface",ring_SDL_UpdateWindowSurface);
	RING_API_REGISTER("sdl_updatewindowsurfacerects",ring_SDL_UpdateWindowSurfaceRects);
	RING_API_REGISTER("sdl_videoinit",ring_SDL_VideoInit);
	RING_API_REGISTER("sdl_videoquit",ring_SDL_VideoQuit);
	RING_API_REGISTER("sdl_createrenderer",ring_SDL_CreateRenderer);
	RING_API_REGISTER("sdl_createsoftwarerenderer",ring_SDL_CreateSoftwareRenderer);
	RING_API_REGISTER("sdl_createtexture",ring_SDL_CreateTexture);
	RING_API_REGISTER("sdl_createtexturefromsurface",ring_SDL_CreateTextureFromSurface);
	RING_API_REGISTER("sdl_destroyrenderer",ring_SDL_DestroyRenderer);
	RING_API_REGISTER("sdl_destroytexture",ring_SDL_DestroyTexture);
	RING_API_REGISTER("sdl_gl_bindtexture",ring_SDL_GL_BindTexture);
	RING_API_REGISTER("sdl_gl_unbindtexture",ring_SDL_GL_UnbindTexture);
	RING_API_REGISTER("sdl_getnumrenderdrivers",ring_SDL_GetNumRenderDrivers);
	RING_API_REGISTER("sdl_getrenderdrawblendmode",ring_SDL_GetRenderDrawBlendMode);
	RING_API_REGISTER("sdl_getrenderdrawcolor",ring_SDL_GetRenderDrawColor);
	RING_API_REGISTER("sdl_getrenderdriverinfo",ring_SDL_GetRenderDriverInfo);
	RING_API_REGISTER("sdl_getrendertarget",ring_SDL_GetRenderTarget);
	RING_API_REGISTER("sdl_getrenderer",ring_SDL_GetRenderer);
	RING_API_REGISTER("sdl_getrendererinfo",ring_SDL_GetRendererInfo);
	RING_API_REGISTER("sdl_getrendereroutputsize",ring_SDL_GetRendererOutputSize);
	RING_API_REGISTER("sdl_gettexturealphamod",ring_SDL_GetTextureAlphaMod);
	RING_API_REGISTER("sdl_gettextureblendmode",ring_SDL_GetTextureBlendMode);
	RING_API_REGISTER("sdl_gettexturecolormod",ring_SDL_GetTextureColorMod);
	RING_API_REGISTER("sdl_locktexture",ring_SDL_LockTexture);
	RING_API_REGISTER("sdl_querytexture",ring_SDL_QueryTexture);
	RING_API_REGISTER("sdl_renderclear",ring_SDL_RenderClear);
	RING_API_REGISTER("sdl_rendercopy",ring_SDL_RenderCopy);
	RING_API_REGISTER("sdl_rendercopyex",ring_SDL_RenderCopyEx);
	RING_API_REGISTER("sdl_renderdrawline",ring_SDL_RenderDrawLine);
	RING_API_REGISTER("sdl_renderdrawlines",ring_SDL_RenderDrawLines);
	RING_API_REGISTER("sdl_renderdrawpoint",ring_SDL_RenderDrawPoint);
	RING_API_REGISTER("sdl_renderdrawpoints",ring_SDL_RenderDrawPoints);
	RING_API_REGISTER("sdl_renderdrawrect",ring_SDL_RenderDrawRect);
	RING_API_REGISTER("sdl_renderdrawrects",ring_SDL_RenderDrawRects);
	RING_API_REGISTER("sdl_renderfillrect",ring_SDL_RenderFillRect);
	RING_API_REGISTER("sdl_renderfillrects",ring_SDL_RenderFillRects);
	RING_API_REGISTER("sdl_rendergetcliprect",ring_SDL_RenderGetClipRect);
	RING_API_REGISTER("sdl_rendergetlogicalsize",ring_SDL_RenderGetLogicalSize);
	RING_API_REGISTER("sdl_rendergetscale",ring_SDL_RenderGetScale);
	RING_API_REGISTER("sdl_rendergetviewport",ring_SDL_RenderGetViewport);
	RING_API_REGISTER("sdl_renderpresent",ring_SDL_RenderPresent);
	RING_API_REGISTER("sdl_renderreadpixels",ring_SDL_RenderReadPixels);
	RING_API_REGISTER("sdl_rendersetcliprect",ring_SDL_RenderSetClipRect);
	RING_API_REGISTER("sdl_rendersetlogicalsize",ring_SDL_RenderSetLogicalSize);
	RING_API_REGISTER("sdl_rendersetscale",ring_SDL_RenderSetScale);
	RING_API_REGISTER("sdl_rendersetviewport",ring_SDL_RenderSetViewport);
	RING_API_REGISTER("sdl_rendertargetsupported",ring_SDL_RenderTargetSupported);
	RING_API_REGISTER("sdl_setrenderdrawblendmode",ring_SDL_SetRenderDrawBlendMode);
	RING_API_REGISTER("sdl_setrenderdrawcolor",ring_SDL_SetRenderDrawColor);
	RING_API_REGISTER("sdl_setrendertarget",ring_SDL_SetRenderTarget);
	RING_API_REGISTER("sdl_settexturealphamod",ring_SDL_SetTextureAlphaMod);
	RING_API_REGISTER("sdl_settextureblendmode",ring_SDL_SetTextureBlendMode);
	RING_API_REGISTER("sdl_settexturecolormod",ring_SDL_SetTextureColorMod);
	RING_API_REGISTER("sdl_unlocktexture",ring_SDL_UnlockTexture);
	RING_API_REGISTER("sdl_updatetexture",ring_SDL_UpdateTexture);
	RING_API_REGISTER("sdl_updateyuvtexture",ring_SDL_UpdateYUVTexture);
	RING_API_REGISTER("sdl_allocformat",ring_SDL_AllocFormat);
	RING_API_REGISTER("sdl_allocpalette",ring_SDL_AllocPalette);
	RING_API_REGISTER("sdl_calculategammaramp",ring_SDL_CalculateGammaRamp);
	RING_API_REGISTER("sdl_freeformat",ring_SDL_FreeFormat);
	RING_API_REGISTER("sdl_freepalette",ring_SDL_FreePalette);
	RING_API_REGISTER("sdl_getpixelformatname",ring_SDL_GetPixelFormatName);
	RING_API_REGISTER("sdl_getrgb",ring_SDL_GetRGB);
	RING_API_REGISTER("sdl_getrgba",ring_SDL_GetRGBA);
	RING_API_REGISTER("sdl_maprgb",ring_SDL_MapRGB);
	RING_API_REGISTER("sdl_maprgba",ring_SDL_MapRGBA);
	RING_API_REGISTER("sdl_maskstopixelformatenum",ring_SDL_MasksToPixelFormatEnum);
	RING_API_REGISTER("sdl_pixelformatenumtomasks",ring_SDL_PixelFormatEnumToMasks);
	RING_API_REGISTER("sdl_setpalettecolors",ring_SDL_SetPaletteColors);
	RING_API_REGISTER("sdl_setpixelformatpalette",ring_SDL_SetPixelFormatPalette);
	RING_API_REGISTER("sdl_enclosepoints",ring_SDL_EnclosePoints);
	RING_API_REGISTER("sdl_hasintersection",ring_SDL_HasIntersection);
	RING_API_REGISTER("sdl_intersectrect",ring_SDL_IntersectRect);
	RING_API_REGISTER("sdl_intersectrectandline",ring_SDL_IntersectRectAndLine);
	RING_API_REGISTER("sdl_rectempty",ring_SDL_RectEmpty);
	RING_API_REGISTER("sdl_rectequals",ring_SDL_RectEquals);
	RING_API_REGISTER("sdl_unionrect",ring_SDL_UnionRect);
	RING_API_REGISTER("sdl_blitscaled",ring_SDL_BlitScaled);
	RING_API_REGISTER("sdl_blitsurface",ring_SDL_BlitSurface);
	RING_API_REGISTER("sdl_convertpixels",ring_SDL_ConvertPixels);
	RING_API_REGISTER("sdl_convertsurface",ring_SDL_ConvertSurface);
	RING_API_REGISTER("sdl_convertsurfaceformat",ring_SDL_ConvertSurfaceFormat);
	RING_API_REGISTER("sdl_creatergbsurface",ring_SDL_CreateRGBSurface);
	RING_API_REGISTER("sdl_creatergbsurfacefrom",ring_SDL_CreateRGBSurfaceFrom);
	RING_API_REGISTER("sdl_fillrect",ring_SDL_FillRect);
	RING_API_REGISTER("sdl_fillrects",ring_SDL_FillRects);
	RING_API_REGISTER("sdl_freesurface",ring_SDL_FreeSurface);
	RING_API_REGISTER("sdl_getcliprect",ring_SDL_GetClipRect);
	RING_API_REGISTER("sdl_getcolorkey",ring_SDL_GetColorKey);
	RING_API_REGISTER("sdl_getsurfacealphamod",ring_SDL_GetSurfaceAlphaMod);
	RING_API_REGISTER("sdl_getsurfaceblendmode",ring_SDL_GetSurfaceBlendMode);
	RING_API_REGISTER("sdl_getsurfacecolormod",ring_SDL_GetSurfaceColorMod);
	RING_API_REGISTER("sdl_loadbmp",ring_SDL_LoadBMP);
	RING_API_REGISTER("sdl_loadbmp_rw",ring_SDL_LoadBMP_RW);
	RING_API_REGISTER("sdl_locksurface",ring_SDL_LockSurface);
	RING_API_REGISTER("sdl_lowerblit",ring_SDL_LowerBlit);
	RING_API_REGISTER("sdl_lowerblitscaled",ring_SDL_LowerBlitScaled);
	RING_API_REGISTER("sdl_mustlock",ring_SDL_MUSTLOCK);
	RING_API_REGISTER("sdl_savebmp",ring_SDL_SaveBMP);
	RING_API_REGISTER("sdl_savebmp_rw",ring_SDL_SaveBMP_RW);
	RING_API_REGISTER("sdl_setcliprect",ring_SDL_SetClipRect);
	RING_API_REGISTER("sdl_setcolorkey",ring_SDL_SetColorKey);
	RING_API_REGISTER("sdl_setsurfacealphamod",ring_SDL_SetSurfaceAlphaMod);
	RING_API_REGISTER("sdl_setsurfaceblendmode",ring_SDL_SetSurfaceBlendMode);
	RING_API_REGISTER("sdl_setsurfacecolormod",ring_SDL_SetSurfaceColorMod);
	RING_API_REGISTER("sdl_setsurfacepalette",ring_SDL_SetSurfacePalette);
	RING_API_REGISTER("sdl_setsurfacerle",ring_SDL_SetSurfaceRLE);
	RING_API_REGISTER("sdl_unlocksurface",ring_SDL_UnlockSurface);
	RING_API_REGISTER("sdl_getwindowwminfo",ring_SDL_GetWindowWMInfo);
	RING_API_REGISTER("sdl_getclipboardtext",ring_SDL_GetClipboardText);
	RING_API_REGISTER("sdl_hasclipboardtext",ring_SDL_HasClipboardText);
	RING_API_REGISTER("sdl_setclipboardtext",ring_SDL_SetClipboardText);
	RING_API_REGISTER("sdl_addeventwatch",ring_SDL_AddEventWatch);
	RING_API_REGISTER("sdl_deleventwatch",ring_SDL_DelEventWatch);
	RING_API_REGISTER("sdl_eventstate",ring_SDL_EventState);
	RING_API_REGISTER("sdl_filterevents",ring_SDL_FilterEvents);
	RING_API_REGISTER("sdl_flushevent",ring_SDL_FlushEvent);
	RING_API_REGISTER("sdl_flushevents",ring_SDL_FlushEvents);
	RING_API_REGISTER("sdl_geteventfilter",ring_SDL_GetEventFilter);
	RING_API_REGISTER("sdl_geteventstate",ring_SDL_GetEventState);
	RING_API_REGISTER("sdl_getnumtouchdevices",ring_SDL_GetNumTouchDevices);
	RING_API_REGISTER("sdl_getnumtouchfingers",ring_SDL_GetNumTouchFingers);
	RING_API_REGISTER("sdl_gettouchdevice",ring_SDL_GetTouchDevice);
	RING_API_REGISTER("sdl_gettouchfinger",ring_SDL_GetTouchFinger);
	RING_API_REGISTER("sdl_hasevent",ring_SDL_HasEvent);
	RING_API_REGISTER("sdl_hasevents",ring_SDL_HasEvents);
	RING_API_REGISTER("sdl_loaddollartemplates",ring_SDL_LoadDollarTemplates);
	RING_API_REGISTER("sdl_peepevents",ring_SDL_PeepEvents);
	RING_API_REGISTER("sdl_pollevent",ring_SDL_PollEvent);
	RING_API_REGISTER("sdl_pumpevents",ring_SDL_PumpEvents);
	RING_API_REGISTER("sdl_pushevent",ring_SDL_PushEvent);
	RING_API_REGISTER("sdl_quitrequested",ring_SDL_QuitRequested);
	RING_API_REGISTER("sdl_recordgesture",ring_SDL_RecordGesture);
	RING_API_REGISTER("sdl_registerevents",ring_SDL_RegisterEvents);
	RING_API_REGISTER("sdl_savealldollartemplates",ring_SDL_SaveAllDollarTemplates);
	RING_API_REGISTER("sdl_savedollartemplate",ring_SDL_SaveDollarTemplate);
	RING_API_REGISTER("sdl_seteventfilter",ring_SDL_SetEventFilter);
	RING_API_REGISTER("sdl_waitevent",ring_SDL_WaitEvent);
	RING_API_REGISTER("sdl_waiteventtimeout",ring_SDL_WaitEventTimeout);
	RING_API_REGISTER("sdl_getkeyfromname",ring_SDL_GetKeyFromName);
	RING_API_REGISTER("sdl_getkeyfromscancode",ring_SDL_GetKeyFromScancode);
	RING_API_REGISTER("sdl_getkeyname",ring_SDL_GetKeyName);
	RING_API_REGISTER("sdl_getkeyboardfocus",ring_SDL_GetKeyboardFocus);
	RING_API_REGISTER("sdl_getkeyboardstate",ring_SDL_GetKeyboardState);
	RING_API_REGISTER("sdl_getmodstate",ring_SDL_GetModState);
	RING_API_REGISTER("sdl_getscancodefromkey",ring_SDL_GetScancodeFromKey);
	RING_API_REGISTER("sdl_getscancodefromname",ring_SDL_GetScancodeFromName);
	RING_API_REGISTER("sdl_getscancodename",ring_SDL_GetScancodeName);
	RING_API_REGISTER("sdl_hasscreenkeyboardsupport",ring_SDL_HasScreenKeyboardSupport);
	RING_API_REGISTER("sdl_isscreenkeyboardshown",ring_SDL_IsScreenKeyboardShown);
	RING_API_REGISTER("sdl_istextinputactive",ring_SDL_IsTextInputActive);
	RING_API_REGISTER("sdl_setmodstate",ring_SDL_SetModState);
	RING_API_REGISTER("sdl_settextinputrect",ring_SDL_SetTextInputRect);
	RING_API_REGISTER("sdl_starttextinput",ring_SDL_StartTextInput);
	RING_API_REGISTER("sdl_stoptextinput",ring_SDL_StopTextInput);
	RING_API_REGISTER("sdl_createcolorcursor",ring_SDL_CreateColorCursor);
	RING_API_REGISTER("sdl_createcursor",ring_SDL_CreateCursor);
	RING_API_REGISTER("sdl_freecursor",ring_SDL_FreeCursor);
	RING_API_REGISTER("sdl_getcursor",ring_SDL_GetCursor);
	RING_API_REGISTER("sdl_getdefaultcursor",ring_SDL_GetDefaultCursor);
	RING_API_REGISTER("sdl_getmousefocus",ring_SDL_GetMouseFocus);
	RING_API_REGISTER("sdl_getmousestate",ring_SDL_GetMouseState);
	RING_API_REGISTER("sdl_getrelativemousemode",ring_SDL_GetRelativeMouseMode);
	RING_API_REGISTER("sdl_getrelativemousestate",ring_SDL_GetRelativeMouseState);
	RING_API_REGISTER("sdl_setcursor",ring_SDL_SetCursor);
	RING_API_REGISTER("sdl_setrelativemousemode",ring_SDL_SetRelativeMouseMode);
	RING_API_REGISTER("sdl_showcursor",ring_SDL_ShowCursor);
	RING_API_REGISTER("sdl_warpmouseinwindow",ring_SDL_WarpMouseInWindow);
	RING_API_REGISTER("sdl_joystickclose",ring_SDL_JoystickClose);
	RING_API_REGISTER("sdl_joystickeventstate",ring_SDL_JoystickEventState);
	RING_API_REGISTER("sdl_joystickgetattached",ring_SDL_JoystickGetAttached);
	RING_API_REGISTER("sdl_joystickgetaxis",ring_SDL_JoystickGetAxis);
	RING_API_REGISTER("sdl_joystickgetball",ring_SDL_JoystickGetBall);
	RING_API_REGISTER("sdl_joystickgetbutton",ring_SDL_JoystickGetButton);
	RING_API_REGISTER("sdl_joystickgetdeviceguid",ring_SDL_JoystickGetDeviceGUID);
	RING_API_REGISTER("sdl_joystickgetguid",ring_SDL_JoystickGetGUID);
	RING_API_REGISTER("sdl_joystickgetguidfromstring",ring_SDL_JoystickGetGUIDFromString);
	RING_API_REGISTER("sdl_joystickgetguidstring",ring_SDL_JoystickGetGUIDString);
	RING_API_REGISTER("sdl_joystickgethat",ring_SDL_JoystickGetHat);
	RING_API_REGISTER("sdl_joystickinstanceid",ring_SDL_JoystickInstanceID);
	RING_API_REGISTER("sdl_joystickname",ring_SDL_JoystickName);
	RING_API_REGISTER("sdl_joysticknameforindex",ring_SDL_JoystickNameForIndex);
	RING_API_REGISTER("sdl_joysticknumaxes",ring_SDL_JoystickNumAxes);
	RING_API_REGISTER("sdl_joysticknumballs",ring_SDL_JoystickNumBalls);
	RING_API_REGISTER("sdl_joysticknumbuttons",ring_SDL_JoystickNumButtons);
	RING_API_REGISTER("sdl_joysticknumhats",ring_SDL_JoystickNumHats);
	RING_API_REGISTER("sdl_joystickopen",ring_SDL_JoystickOpen);
	RING_API_REGISTER("sdl_joystickupdate",ring_SDL_JoystickUpdate);
	RING_API_REGISTER("sdl_numjoysticks",ring_SDL_NumJoysticks);
	RING_API_REGISTER("sdl_gamecontrolleraddmapping",ring_SDL_GameControllerAddMapping);
	RING_API_REGISTER("sdl_gamecontrolleraddmappingsfromfile",ring_SDL_GameControllerAddMappingsFromFile);
	RING_API_REGISTER("sdl_gamecontrolleraddmappingsfromrw",ring_SDL_GameControllerAddMappingsFromRW);
	RING_API_REGISTER("sdl_gamecontrollerclose",ring_SDL_GameControllerClose);
	RING_API_REGISTER("sdl_gamecontrollereventstate",ring_SDL_GameControllerEventState);
	RING_API_REGISTER("sdl_gamecontrollergetattached",ring_SDL_GameControllerGetAttached);
	RING_API_REGISTER("sdl_gamecontrollergetaxis",ring_SDL_GameControllerGetAxis);
	RING_API_REGISTER("sdl_gamecontrollergetaxisfromstring",ring_SDL_GameControllerGetAxisFromString);
	RING_API_REGISTER("sdl_gamecontrollergetbindforaxis",ring_SDL_GameControllerGetBindForAxis);
	RING_API_REGISTER("sdl_gamecontrollergetbindforbutton",ring_SDL_GameControllerGetBindForButton);
	RING_API_REGISTER("sdl_gamecontrollergetbutton",ring_SDL_GameControllerGetButton);
	RING_API_REGISTER("sdl_gamecontrollergetbuttonfromstring",ring_SDL_GameControllerGetButtonFromString);
	RING_API_REGISTER("sdl_gamecontrollergetjoystick",ring_SDL_GameControllerGetJoystick);
	RING_API_REGISTER("sdl_gamecontrollergetstringforaxis",ring_SDL_GameControllerGetStringForAxis);
	RING_API_REGISTER("sdl_gamecontrollergetstringforbutton",ring_SDL_GameControllerGetStringForButton);
	RING_API_REGISTER("sdl_gamecontrollermapping",ring_SDL_GameControllerMapping);
	RING_API_REGISTER("sdl_gamecontrollermappingforguid",ring_SDL_GameControllerMappingForGUID);
	RING_API_REGISTER("sdl_gamecontrollername",ring_SDL_GameControllerName);
	RING_API_REGISTER("sdl_gamecontrollernameforindex",ring_SDL_GameControllerNameForIndex);
	RING_API_REGISTER("sdl_gamecontrolleropen",ring_SDL_GameControllerOpen);
	RING_API_REGISTER("sdl_gamecontrollerupdate",ring_SDL_GameControllerUpdate);
	RING_API_REGISTER("sdl_isgamecontroller",ring_SDL_IsGameController);
	RING_API_REGISTER("sdl_hapticclose",ring_SDL_HapticClose);
	RING_API_REGISTER("sdl_hapticdestroyeffect",ring_SDL_HapticDestroyEffect);
	RING_API_REGISTER("sdl_hapticeffectsupported",ring_SDL_HapticEffectSupported);
	RING_API_REGISTER("sdl_hapticgeteffectstatus",ring_SDL_HapticGetEffectStatus);
	RING_API_REGISTER("sdl_hapticindex",ring_SDL_HapticIndex);
	RING_API_REGISTER("sdl_hapticname",ring_SDL_HapticName);
	RING_API_REGISTER("sdl_hapticneweffect",ring_SDL_HapticNewEffect);
	RING_API_REGISTER("sdl_hapticnumaxes",ring_SDL_HapticNumAxes);
	RING_API_REGISTER("sdl_hapticnumeffects",ring_SDL_HapticNumEffects);
	RING_API_REGISTER("sdl_hapticnumeffectsplaying",ring_SDL_HapticNumEffectsPlaying);
	RING_API_REGISTER("sdl_hapticopen",ring_SDL_HapticOpen);
	RING_API_REGISTER("sdl_hapticopenfromjoystick",ring_SDL_HapticOpenFromJoystick);
	RING_API_REGISTER("sdl_hapticopenfrommouse",ring_SDL_HapticOpenFromMouse);
	RING_API_REGISTER("sdl_hapticopened",ring_SDL_HapticOpened);
	RING_API_REGISTER("sdl_hapticpause",ring_SDL_HapticPause);
	RING_API_REGISTER("sdl_hapticquery",ring_SDL_HapticQuery);
	RING_API_REGISTER("sdl_hapticrumbleinit",ring_SDL_HapticRumbleInit);
	RING_API_REGISTER("sdl_hapticrumbleplay",ring_SDL_HapticRumblePlay);
	RING_API_REGISTER("sdl_hapticrumblestop",ring_SDL_HapticRumbleStop);
	RING_API_REGISTER("sdl_hapticrumblesupported",ring_SDL_HapticRumbleSupported);
	RING_API_REGISTER("sdl_hapticruneffect",ring_SDL_HapticRunEffect);
	RING_API_REGISTER("sdl_hapticsetautocenter",ring_SDL_HapticSetAutocenter);
	RING_API_REGISTER("sdl_hapticsetgain",ring_SDL_HapticSetGain);
	RING_API_REGISTER("sdl_hapticstopall",ring_SDL_HapticStopAll);
	RING_API_REGISTER("sdl_hapticstopeffect",ring_SDL_HapticStopEffect);
	RING_API_REGISTER("sdl_hapticunpause",ring_SDL_HapticUnpause);
	RING_API_REGISTER("sdl_hapticupdateeffect",ring_SDL_HapticUpdateEffect);
	RING_API_REGISTER("sdl_joystickishaptic",ring_SDL_JoystickIsHaptic);
	RING_API_REGISTER("sdl_mouseishaptic",ring_SDL_MouseIsHaptic);
	RING_API_REGISTER("sdl_numhaptics",ring_SDL_NumHaptics);
	RING_API_REGISTER("sdl_audioinit",ring_SDL_AudioInit);
	RING_API_REGISTER("sdl_audioquit",ring_SDL_AudioQuit);
	RING_API_REGISTER("sdl_buildaudiocvt",ring_SDL_BuildAudioCVT);
	RING_API_REGISTER("sdl_closeaudio",ring_SDL_CloseAudio);
	RING_API_REGISTER("sdl_closeaudiodevice",ring_SDL_CloseAudioDevice);
	RING_API_REGISTER("sdl_convertaudio",ring_SDL_ConvertAudio);
	RING_API_REGISTER("sdl_freewav",ring_SDL_FreeWAV);
	RING_API_REGISTER("sdl_getaudiodevicename",ring_SDL_GetAudioDeviceName);
	RING_API_REGISTER("sdl_getaudiodevicestatus",ring_SDL_GetAudioDeviceStatus);
	RING_API_REGISTER("sdl_getaudiodriver",ring_SDL_GetAudioDriver);
	RING_API_REGISTER("sdl_getaudiostatus",ring_SDL_GetAudioStatus);
	RING_API_REGISTER("sdl_getcurrentaudiodriver",ring_SDL_GetCurrentAudioDriver);
	RING_API_REGISTER("sdl_getnumaudiodevices",ring_SDL_GetNumAudioDevices);
	RING_API_REGISTER("sdl_getnumaudiodrivers",ring_SDL_GetNumAudioDrivers);
	RING_API_REGISTER("sdl_loadwav",ring_SDL_LoadWAV);
	RING_API_REGISTER("sdl_loadwav_rw",ring_SDL_LoadWAV_RW);
	RING_API_REGISTER("sdl_lockaudio",ring_SDL_LockAudio);
	RING_API_REGISTER("sdl_lockaudiodevice",ring_SDL_LockAudioDevice);
	RING_API_REGISTER("sdl_mixaudio",ring_SDL_MixAudio);
	RING_API_REGISTER("sdl_mixaudioformat",ring_SDL_MixAudioFormat);
	RING_API_REGISTER("sdl_openaudio",ring_SDL_OpenAudio);
	RING_API_REGISTER("sdl_openaudiodevice",ring_SDL_OpenAudioDevice);
	RING_API_REGISTER("sdl_pauseaudio",ring_SDL_PauseAudio);
	RING_API_REGISTER("sdl_pauseaudiodevice",ring_SDL_PauseAudioDevice);
	RING_API_REGISTER("sdl_unlockaudio",ring_SDL_UnlockAudio);
	RING_API_REGISTER("sdl_unlockaudiodevice",ring_SDL_UnlockAudioDevice);
	RING_API_REGISTER("sdl_getbasepath",ring_SDL_GetBasePath);
	RING_API_REGISTER("sdl_getprefpath",ring_SDL_GetPrefPath);
	RING_API_REGISTER("sdl_allocrw",ring_SDL_AllocRW);
	RING_API_REGISTER("sdl_freerw",ring_SDL_FreeRW);
	RING_API_REGISTER("sdl_rwfromconstmem",ring_SDL_RWFromConstMem);
	RING_API_REGISTER("sdl_rwfromfp",ring_SDL_RWFromFP);
	RING_API_REGISTER("sdl_rwfromfile",ring_SDL_RWFromFile);
	RING_API_REGISTER("sdl_rwfrommem",ring_SDL_RWFromMem);
	RING_API_REGISTER("sdl_rwclose",ring_SDL_RWclose);
	RING_API_REGISTER("sdl_rwread",ring_SDL_RWread);
	RING_API_REGISTER("sdl_rwseek",ring_SDL_RWseek);
	RING_API_REGISTER("sdl_rwsize",ring_SDL_RWsize);
	RING_API_REGISTER("sdl_rwtell",ring_SDL_RWtell);
	RING_API_REGISTER("sdl_rwwrite",ring_SDL_RWwrite);
	RING_API_REGISTER("sdl_readbe16",ring_SDL_ReadBE16);
	RING_API_REGISTER("sdl_readbe32",ring_SDL_ReadBE32);
	RING_API_REGISTER("sdl_readbe64",ring_SDL_ReadBE64);
	RING_API_REGISTER("sdl_readle16",ring_SDL_ReadLE16);
	RING_API_REGISTER("sdl_readle32",ring_SDL_ReadLE32);
	RING_API_REGISTER("sdl_readle64",ring_SDL_ReadLE64);
	RING_API_REGISTER("sdl_readu8",ring_SDL_ReadU8);
	RING_API_REGISTER("sdl_writebe16",ring_SDL_WriteBE16);
	RING_API_REGISTER("sdl_writebe32",ring_SDL_WriteBE32);
	RING_API_REGISTER("sdl_writebe64",ring_SDL_WriteBE64);
	RING_API_REGISTER("sdl_writele16",ring_SDL_WriteLE16);
	RING_API_REGISTER("sdl_writele32",ring_SDL_WriteLE32);
	RING_API_REGISTER("sdl_writele64",ring_SDL_WriteLE64);
	RING_API_REGISTER("sdl_writeu8",ring_SDL_WriteU8);
	RING_API_REGISTER("sdl_loadfunction",ring_SDL_LoadFunction);
	RING_API_REGISTER("sdl_loadobject",ring_SDL_LoadObject);
	RING_API_REGISTER("sdl_unloadobject",ring_SDL_UnloadObject);
	RING_API_REGISTER("sdl_getplatform",ring_SDL_GetPlatform);
	RING_API_REGISTER("sdl_getcpucachelinesize",ring_SDL_GetCPUCacheLineSize);
	RING_API_REGISTER("sdl_getcpucount",ring_SDL_GetCPUCount);
	RING_API_REGISTER("sdl_getsystemram",ring_SDL_GetSystemRAM);
	RING_API_REGISTER("sdl_has3dnow",ring_SDL_Has3DNow);
	RING_API_REGISTER("sdl_hasavx",ring_SDL_HasAVX);
	RING_API_REGISTER("sdl_hasaltivec",ring_SDL_HasAltiVec);
	RING_API_REGISTER("sdl_hasmmx",ring_SDL_HasMMX);
	RING_API_REGISTER("sdl_hasrdtsc",ring_SDL_HasRDTSC);
	RING_API_REGISTER("sdl_hassse",ring_SDL_HasSSE);
	RING_API_REGISTER("sdl_hassse2",ring_SDL_HasSSE2);
	RING_API_REGISTER("sdl_hassse3",ring_SDL_HasSSE3);
	RING_API_REGISTER("sdl_hassse41",ring_SDL_HasSSE41);
	RING_API_REGISTER("sdl_hassse42",ring_SDL_HasSSE42);
	RING_API_REGISTER("sdl_getpowerinfo",ring_SDL_GetPowerInfo);
	RING_API_REGISTER("sdl_acos",ring_SDL_acos);
	RING_API_REGISTER("img_init",ring_IMG_Init);
	RING_API_REGISTER("img_quit",ring_IMG_Quit);
	RING_API_REGISTER("img_load",ring_IMG_Load);
	RING_API_REGISTER("img_load_rw",ring_IMG_Load_RW);
	RING_API_REGISTER("img_loadtyped_rw",ring_IMG_LoadTyped_RW);
	RING_API_REGISTER("img_loadcur_rw",ring_IMG_LoadCUR_RW);
	RING_API_REGISTER("img_loadbmp_rw",ring_IMG_LoadBMP_RW);
	RING_API_REGISTER("img_loadpnm_rw",ring_IMG_LoadPNM_RW);
	RING_API_REGISTER("img_loadxpm_rw",ring_IMG_LoadXPM_RW);
	RING_API_REGISTER("img_loadxcf_rw",ring_IMG_LoadXCF_RW);
	RING_API_REGISTER("img_loadpcx_rw",ring_IMG_LoadPCX_RW);
	RING_API_REGISTER("img_loadgif_rw",ring_IMG_LoadGIF_RW);
	RING_API_REGISTER("img_loadjpg_rw",ring_IMG_LoadJPG_RW);
	RING_API_REGISTER("img_loadtif_rw",ring_IMG_LoadTIF_RW);
	RING_API_REGISTER("img_loadpng_rw",ring_IMG_LoadPNG_RW);
	RING_API_REGISTER("img_loadtga_rw",ring_IMG_LoadTGA_RW);
	RING_API_REGISTER("img_loadlbm_rw",ring_IMG_LoadLBM_RW);
	RING_API_REGISTER("img_loadxv_rw",ring_IMG_LoadXV_RW);
	RING_API_REGISTER("img_readxpmfromarray",ring_IMG_ReadXPMFromArray);
	RING_API_REGISTER("img_iscur",ring_IMG_isCUR);
	RING_API_REGISTER("img_isico",ring_IMG_isICO);
	RING_API_REGISTER("img_isbmp",ring_IMG_isBMP);
	RING_API_REGISTER("img_ispnm",ring_IMG_isPNM);
	RING_API_REGISTER("img_isxpm",ring_IMG_isXPM);
	RING_API_REGISTER("img_isxcf",ring_IMG_isXCF);
	RING_API_REGISTER("img_ispcx",ring_IMG_isPCX);
	RING_API_REGISTER("img_isgif",ring_IMG_isGIF);
	RING_API_REGISTER("img_isjpg",ring_IMG_isJPG);
	RING_API_REGISTER("img_istif",ring_IMG_isTIF);
	RING_API_REGISTER("img_ispng",ring_IMG_isPNG);
	RING_API_REGISTER("img_islbm",ring_IMG_isLBM);
	RING_API_REGISTER("img_isxv",ring_IMG_isXV);
	RING_API_REGISTER("ttf_init",ring_TTF_Init);
	RING_API_REGISTER("ttf_wasinit",ring_TTF_WasInit);
	RING_API_REGISTER("ttf_quit",ring_TTF_Quit);
	RING_API_REGISTER("ttf_openfont",ring_TTF_OpenFont);
	RING_API_REGISTER("ttf_openfontrw",ring_TTF_OpenFontRW);
	RING_API_REGISTER("ttf_openfontindex",ring_TTF_OpenFontIndex);
	RING_API_REGISTER("ttf_openfontindexrw",ring_TTF_OpenFontIndexRW);
	RING_API_REGISTER("ttf_closefont",ring_TTF_CloseFont);
	RING_API_REGISTER("ttf_byteswappedunicode",ring_TTF_ByteSwappedUNICODE);
	RING_API_REGISTER("ttf_getfontstyle",ring_TTF_GetFontStyle);
	RING_API_REGISTER("ttf_setfontstyle",ring_TTF_SetFontStyle);
	RING_API_REGISTER("ttf_getfontoutline",ring_TTF_GetFontOutline);
	RING_API_REGISTER("ttf_setfontoutline",ring_TTF_SetFontOutline);
	RING_API_REGISTER("ttf_getfonthinting",ring_TTF_GetFontHinting);
	RING_API_REGISTER("ttf_setfonthinting",ring_TTF_SetFontHinting);
	RING_API_REGISTER("ttf_getfontkerning",ring_TTF_GetFontKerning);
	RING_API_REGISTER("ttf_setfontkerning",ring_TTF_SetFontKerning);
	RING_API_REGISTER("ttf_fontheight",ring_TTF_FontHeight);
	RING_API_REGISTER("ttf_fontascent",ring_TTF_FontAscent);
	RING_API_REGISTER("ttf_fontdescent",ring_TTF_FontDescent);
	RING_API_REGISTER("ttf_fontlineskip",ring_TTF_FontLineSkip);
	RING_API_REGISTER("ttf_fontfaces",ring_TTF_FontFaces);
	RING_API_REGISTER("ttf_fontfaceisfixedwidth",ring_TTF_FontFaceIsFixedWidth);
	RING_API_REGISTER("ttf_fontfacefamilyname",ring_TTF_FontFaceFamilyName);
	RING_API_REGISTER("ttf_fontfacestylename",ring_TTF_FontFaceStyleName);
	RING_API_REGISTER("ttf_glyphisprovided",ring_TTF_GlyphIsProvided);
	RING_API_REGISTER("ttf_glyphmetrics",ring_TTF_GlyphMetrics);
	RING_API_REGISTER("ttf_sizetext",ring_TTF_SizeText);
	RING_API_REGISTER("ttf_sizeutf8",ring_TTF_SizeUTF8);
	RING_API_REGISTER("ttf_sizeunicode",ring_TTF_SizeUNICODE);
	RING_API_REGISTER("ttf_rendertext_solid",ring_TTF_RenderText_Solid);
	RING_API_REGISTER("ttf_renderutf8_solid",ring_TTF_RenderUTF8_Solid);
	RING_API_REGISTER("ttf_renderunicode_solid",ring_TTF_RenderUNICODE_Solid);
	RING_API_REGISTER("ttf_renderglyph_solid",ring_TTF_RenderGlyph_Solid);
	RING_API_REGISTER("ttf_rendertext_shaded",ring_TTF_RenderText_Shaded);
	RING_API_REGISTER("ttf_renderutf8_shaded",ring_TTF_RenderUTF8_Shaded);
	RING_API_REGISTER("ttf_renderunicode_shaded",ring_TTF_RenderUNICODE_Shaded);
	RING_API_REGISTER("ttf_renderglyph_shaded",ring_TTF_RenderGlyph_Shaded);
	RING_API_REGISTER("ttf_rendertext_blended",ring_TTF_RenderText_Blended);
	RING_API_REGISTER("ttf_renderutf8_blended",ring_TTF_RenderUTF8_Blended);
	RING_API_REGISTER("ttf_renderunicode_blended",ring_TTF_RenderUNICODE_Blended);
	RING_API_REGISTER("ttf_renderglyph_blended",ring_TTF_RenderGlyph_Blended);
	RING_API_REGISTER("mix_init",ring_Mix_Init);
	RING_API_REGISTER("mix_quit",ring_Mix_Quit);
	RING_API_REGISTER("mix_openaudio",ring_Mix_OpenAudio);
	RING_API_REGISTER("mix_closeaudio",ring_Mix_CloseAudio);
	RING_API_REGISTER("mix_geterror",ring_Mix_GetError);
	RING_API_REGISTER("mix_queryspec",ring_Mix_QuerySpec);
	RING_API_REGISTER("mix_getnumchunkdecoders",ring_Mix_GetNumChunkDecoders);
	RING_API_REGISTER("mix_getchunkdecoder",ring_Mix_GetChunkDecoder);
	RING_API_REGISTER("mix_loadwav",ring_Mix_LoadWAV);
	RING_API_REGISTER("mix_loadwav_rw",ring_Mix_LoadWAV_RW);
	RING_API_REGISTER("mix_quickload_wav",ring_Mix_QuickLoad_WAV);
	RING_API_REGISTER("mix_volumechunk",ring_Mix_VolumeChunk);
	RING_API_REGISTER("mix_freechunk",ring_Mix_FreeChunk);
	RING_API_REGISTER("mix_allocatechannels",ring_Mix_AllocateChannels);
	RING_API_REGISTER("mix_volume",ring_Mix_Volume);
	RING_API_REGISTER("mix_playchannel",ring_Mix_PlayChannel);
	RING_API_REGISTER("mix_playchanneltimed",ring_Mix_PlayChannelTimed);
	RING_API_REGISTER("mix_fadeinchannel",ring_Mix_FadeInChannel);
	RING_API_REGISTER("mix_fadeinchanneltimed",ring_Mix_FadeInChannelTimed);
	RING_API_REGISTER("mix_pause",ring_Mix_Pause);
	RING_API_REGISTER("mix_resume",ring_Mix_Resume);
	RING_API_REGISTER("mix_haltchannel",ring_Mix_HaltChannel);
	RING_API_REGISTER("mix_expirechannel",ring_Mix_ExpireChannel);
	RING_API_REGISTER("mix_fadeoutchannel",ring_Mix_FadeOutChannel);
	RING_API_REGISTER("mix_playing",ring_Mix_Playing);
	RING_API_REGISTER("mix_paused",ring_Mix_Paused);
	RING_API_REGISTER("mix_fadingchannel",ring_Mix_FadingChannel);
	RING_API_REGISTER("mix_getchunk",ring_Mix_GetChunk);
	RING_API_REGISTER("mix_reservechannels",ring_Mix_ReserveChannels);
	RING_API_REGISTER("mix_groupchannel",ring_Mix_GroupChannel);
	RING_API_REGISTER("mix_groupchannels",ring_Mix_GroupChannels);
	RING_API_REGISTER("mix_groupcount",ring_Mix_GroupCount);
	RING_API_REGISTER("mix_groupavailable",ring_Mix_GroupAvailable);
	RING_API_REGISTER("mix_groupoldest",ring_Mix_GroupOldest);
	RING_API_REGISTER("mix_groupnewer",ring_Mix_GroupNewer);
	RING_API_REGISTER("mix_fadeoutgroup",ring_Mix_FadeOutGroup);
	RING_API_REGISTER("mix_haltgroup",ring_Mix_HaltGroup);
	RING_API_REGISTER("mix_getnummusicdecoders",ring_Mix_GetNumMusicDecoders);
	RING_API_REGISTER("mix_getmusicdecoder",ring_Mix_GetMusicDecoder);
	RING_API_REGISTER("mix_loadmus",ring_Mix_LoadMUS);
	RING_API_REGISTER("mix_freemusic",ring_Mix_FreeMusic);
	RING_API_REGISTER("mix_playmusic",ring_Mix_PlayMusic);
	RING_API_REGISTER("mix_fadeinmusic",ring_Mix_FadeInMusic);
	RING_API_REGISTER("mix_fadeinmusicpos",ring_Mix_FadeInMusicPos);
	RING_API_REGISTER("mix_getmusictype",ring_Mix_GetMusicType);
	RING_API_REGISTER("mix_playingmusic",ring_Mix_PlayingMusic);
	RING_API_REGISTER("mix_pausedmusic",ring_Mix_PausedMusic);
	RING_API_REGISTER("mix_fadingmusic",ring_Mix_FadingMusic);
	RING_API_REGISTER("mix_getmusichookdata",ring_Mix_GetMusicHookData);
	RING_API_REGISTER("mix_registereffect",ring_Mix_RegisterEffect);
	RING_API_REGISTER("mix_unregistereffect",ring_Mix_UnregisterEffect);
	RING_API_REGISTER("mix_unregisteralleffects",ring_Mix_UnregisterAllEffects);
	RING_API_REGISTER("mix_setpanning",ring_Mix_SetPanning);
	RING_API_REGISTER("mix_setdistance",ring_Mix_SetDistance);
	RING_API_REGISTER("mix_setposition",ring_Mix_SetPosition);
	RING_API_REGISTER("mix_setreversestereo",ring_Mix_SetReverseStereo);
	RING_API_REGISTER("sdlnet_init",ring_SDLNet_Init);
	RING_API_REGISTER("sdlnet_quit",ring_SDLNet_Quit);
	RING_API_REGISTER("sdlnet_geterror",ring_SDLNet_GetError);
	RING_API_REGISTER("sdlnet_write16",ring_SDLNet_Write16);
	RING_API_REGISTER("sdlnet_write32",ring_SDLNet_Write32);
	RING_API_REGISTER("sdlnet_read16",ring_SDLNet_Read16);
	RING_API_REGISTER("sdlnet_read32",ring_SDLNet_Read32);
	RING_API_REGISTER("sdlnet_resolvehost",ring_SDLNet_ResolveHost);
	RING_API_REGISTER("sdlnet_resolveip",ring_SDLNet_ResolveIP);
	RING_API_REGISTER("sdlnet_tcp_open",ring_SDLNet_TCP_Open);
	RING_API_REGISTER("sdlnet_tcp_close",ring_SDLNet_TCP_Close);
	RING_API_REGISTER("sdlnet_tcp_accept",ring_SDLNet_TCP_Accept);
	RING_API_REGISTER("sdlnet_tcp_getpeeraddress",ring_SDLNet_TCP_GetPeerAddress);
	RING_API_REGISTER("sdlnet_tcp_send",ring_SDLNet_TCP_Send);
	RING_API_REGISTER("sdlnet_tcp_recv",ring_SDLNet_TCP_Recv);
	RING_API_REGISTER("sdlnet_udp_open",ring_SDLNet_UDP_Open);
	RING_API_REGISTER("sdlnet_udp_close",ring_SDLNet_UDP_Close);
	RING_API_REGISTER("sdlnet_udp_bind",ring_SDLNet_UDP_Bind);
	RING_API_REGISTER("sdlnet_udp_unbind",ring_SDLNet_UDP_Unbind);
	RING_API_REGISTER("sdlnet_udp_getpeeraddress",ring_SDLNet_UDP_GetPeerAddress);
	RING_API_REGISTER("sdlnet_udp_send",ring_SDLNet_UDP_Send);
	RING_API_REGISTER("sdlnet_udp_recv",ring_SDLNet_UDP_Recv);
	RING_API_REGISTER("sdlnet_udp_sendv",ring_SDLNet_UDP_SendV);
	RING_API_REGISTER("sdlnet_udp_recvv",ring_SDLNet_UDP_RecvV);
	RING_API_REGISTER("sdlnet_allocpacket",ring_SDLNet_AllocPacket);
	RING_API_REGISTER("sdlnet_resizepacket",ring_SDLNet_ResizePacket);
	RING_API_REGISTER("sdlnet_freepacket",ring_SDLNet_FreePacket);
	RING_API_REGISTER("sdlnet_allocpacketv",ring_SDLNet_AllocPacketV);
	RING_API_REGISTER("sdlnet_freepacketv",ring_SDLNet_FreePacketV);
	RING_API_REGISTER("sdlnet_allocsocketset",ring_SDLNet_AllocSocketSet);
	RING_API_REGISTER("sdlnet_freesocketset",ring_SDLNet_FreeSocketSet);
	RING_API_REGISTER("sdlnet_addsocket",ring_SDLNet_AddSocket);
	RING_API_REGISTER("sdlnet_tcp_addsocket",ring_SDLNet_TCP_AddSocket);
	RING_API_REGISTER("sdlnet_udp_addsocket",ring_SDLNet_UDP_AddSocket);
	RING_API_REGISTER("sdlnet_delsocket",ring_SDLNet_DelSocket);
	RING_API_REGISTER("sdlnet_tcp_delsocket",ring_SDLNet_TCP_DelSocket);
	RING_API_REGISTER("sdlnet_udp_delsocket",ring_SDLNet_UDP_DelSocket);
	RING_API_REGISTER("sdlnet_checksockets",ring_SDLNet_CheckSockets);
	RING_API_REGISTER("sdlnet_socketready",ring_SDLNet_SocketReady);
	RING_API_REGISTER("circlergba",ring_circleRGBA);
	RING_API_REGISTER("sdl_createthread",ring_SDL_CreateThread);
	RING_API_REGISTER("sdl_detachthread",ring_SDL_DetachThread);
	RING_API_REGISTER("sdl_getthreadid",ring_SDL_GetThreadID);
	RING_API_REGISTER("sdl_getthreadname",ring_SDL_GetThreadName);
	RING_API_REGISTER("sdl_setthreadpriority",ring_SDL_SetThreadPriority);
	RING_API_REGISTER("sdl_tlscreate",ring_SDL_TLSCreate);
	RING_API_REGISTER("sdl_tlsget",ring_SDL_TLSGet);
	RING_API_REGISTER("sdl_tlsset",ring_SDL_TLSSet);
	RING_API_REGISTER("sdl_threadid",ring_SDL_ThreadID);
	RING_API_REGISTER("sdl_waitthread",ring_SDL_WaitThread);
	RING_API_REGISTER("sdl_condbroadcast",ring_SDL_CondBroadcast);
	RING_API_REGISTER("sdl_condsignal",ring_SDL_CondSignal);
	RING_API_REGISTER("sdl_condwait",ring_SDL_CondWait);
	RING_API_REGISTER("sdl_condwaittimeout",ring_SDL_CondWaitTimeout);
	RING_API_REGISTER("sdl_createcond",ring_SDL_CreateCond);
	RING_API_REGISTER("sdl_createmutex",ring_SDL_CreateMutex);
	RING_API_REGISTER("sdl_createsemaphore",ring_SDL_CreateSemaphore);
	RING_API_REGISTER("sdl_destroycond",ring_SDL_DestroyCond);
	RING_API_REGISTER("sdl_destroymutex",ring_SDL_DestroyMutex);
	RING_API_REGISTER("sdl_destroysemaphore",ring_SDL_DestroySemaphore);
	RING_API_REGISTER("sdl_lockmutex",ring_SDL_LockMutex);
	RING_API_REGISTER("sdl_sempost",ring_SDL_SemPost);
	RING_API_REGISTER("sdl_semtrywait",ring_SDL_SemTryWait);
	RING_API_REGISTER("sdl_semvalue",ring_SDL_SemValue);
	RING_API_REGISTER("sdl_semwait",ring_SDL_SemWait);
	RING_API_REGISTER("sdl_semwaittimeout",ring_SDL_SemWaitTimeout);
	RING_API_REGISTER("sdl_trylockmutex",ring_SDL_TryLockMutex);
	RING_API_REGISTER("sdl_unlockmutex",ring_SDL_UnlockMutex);
	RING_API_REGISTER("sdl_new_sdl_syswminfo",ring_sdl_new_sdl_syswminfo);
	RING_API_REGISTER("sdl_new_managed_sdl_syswminfo",ring_sdl_new_managed_sdl_syswminfo);
	RING_API_REGISTER("sdl_destroy_sdl_syswminfo",ring_sdl_destroy_sdl_syswminfo);
	RING_API_REGISTER("sdl_new_sdl_syswmmsg",ring_sdl_new_sdl_syswmmsg);
	RING_API_REGISTER("sdl_new_managed_sdl_syswmmsg",ring_sdl_new_managed_sdl_syswmmsg);
	RING_API_REGISTER("sdl_destroy_sdl_syswmmsg",ring_sdl_destroy_sdl_syswmmsg);
	RING_API_REGISTER("sdl_new_sdl_syswmevent",ring_sdl_new_sdl_syswmevent);
	RING_API_REGISTER("sdl_new_managed_sdl_syswmevent",ring_sdl_new_managed_sdl_syswmevent);
	RING_API_REGISTER("sdl_destroy_sdl_syswmevent",ring_sdl_destroy_sdl_syswmevent);
	RING_API_REGISTER("sdl_get_sdl_syswmevent",ring_sdl_get_sdl_syswmevent);
	RING_API_REGISTER("sdl_new_sdl_assert_data",ring_sdl_new_sdl_assert_data);
	RING_API_REGISTER("sdl_new_managed_sdl_assert_data",ring_sdl_new_managed_sdl_assert_data);
	RING_API_REGISTER("sdl_destroy_sdl_assert_data",ring_sdl_destroy_sdl_assert_data);
	RING_API_REGISTER("sdl_new_sdl_version",ring_sdl_new_sdl_version);
	RING_API_REGISTER("sdl_new_managed_sdl_version",ring_sdl_new_managed_sdl_version);
	RING_API_REGISTER("sdl_destroy_sdl_version",ring_sdl_destroy_sdl_version);
	RING_API_REGISTER("sdl_get_sdl_version_major",ring_sdl_get_sdl_version_major);
	RING_API_REGISTER("sdl_set_sdl_version_major",ring_sdl_set_sdl_version_major);
	RING_API_REGISTER("sdl_get_sdl_version_minor",ring_sdl_get_sdl_version_minor);
	RING_API_REGISTER("sdl_set_sdl_version_minor",ring_sdl_set_sdl_version_minor);
	RING_API_REGISTER("sdl_get_sdl_version_patch",ring_sdl_get_sdl_version_patch);
	RING_API_REGISTER("sdl_set_sdl_version_patch",ring_sdl_set_sdl_version_patch);
	RING_API_REGISTER("sdl_new_sdl_displaymode",ring_sdl_new_sdl_displaymode);
	RING_API_REGISTER("sdl_new_managed_sdl_displaymode",ring_sdl_new_managed_sdl_displaymode);
	RING_API_REGISTER("sdl_destroy_sdl_displaymode",ring_sdl_destroy_sdl_displaymode);
	RING_API_REGISTER("sdl_new_sdl_messageboxbuttondata",ring_sdl_new_sdl_messageboxbuttondata);
	RING_API_REGISTER("sdl_new_managed_sdl_messageboxbuttondata",ring_sdl_new_managed_sdl_messageboxbuttondata);
	RING_API_REGISTER("sdl_destroy_sdl_messageboxbuttondata",ring_sdl_destroy_sdl_messageboxbuttondata);
	RING_API_REGISTER("sdl_new_sdl_messageboxcolor",ring_sdl_new_sdl_messageboxcolor);
	RING_API_REGISTER("sdl_new_managed_sdl_messageboxcolor",ring_sdl_new_managed_sdl_messageboxcolor);
	RING_API_REGISTER("sdl_destroy_sdl_messageboxcolor",ring_sdl_destroy_sdl_messageboxcolor);
	RING_API_REGISTER("sdl_new_sdl_messageboxcolorscheme",ring_sdl_new_sdl_messageboxcolorscheme);
	RING_API_REGISTER("sdl_new_managed_sdl_messageboxcolorscheme",ring_sdl_new_managed_sdl_messageboxcolorscheme);
	RING_API_REGISTER("sdl_destroy_sdl_messageboxcolorscheme",ring_sdl_destroy_sdl_messageboxcolorscheme);
	RING_API_REGISTER("sdl_new_sdl_messageboxdata",ring_sdl_new_sdl_messageboxdata);
	RING_API_REGISTER("sdl_new_managed_sdl_messageboxdata",ring_sdl_new_managed_sdl_messageboxdata);
	RING_API_REGISTER("sdl_destroy_sdl_messageboxdata",ring_sdl_destroy_sdl_messageboxdata);
	RING_API_REGISTER("sdl_new_sdl_rendererinfo",ring_sdl_new_sdl_rendererinfo);
	RING_API_REGISTER("sdl_new_managed_sdl_rendererinfo",ring_sdl_new_managed_sdl_rendererinfo);
	RING_API_REGISTER("sdl_destroy_sdl_rendererinfo",ring_sdl_destroy_sdl_rendererinfo);
	RING_API_REGISTER("sdl_new_sdl_color",ring_sdl_new_sdl_color);
	RING_API_REGISTER("sdl_new_managed_sdl_color",ring_sdl_new_managed_sdl_color);
	RING_API_REGISTER("sdl_destroy_sdl_color",ring_sdl_destroy_sdl_color);
	RING_API_REGISTER("sdl_get_sdl_color_r",ring_sdl_get_sdl_color_r);
	RING_API_REGISTER("sdl_set_sdl_color_r",ring_sdl_set_sdl_color_r);
	RING_API_REGISTER("sdl_get_sdl_color_g",ring_sdl_get_sdl_color_g);
	RING_API_REGISTER("sdl_set_sdl_color_g",ring_sdl_set_sdl_color_g);
	RING_API_REGISTER("sdl_get_sdl_color_b",ring_sdl_get_sdl_color_b);
	RING_API_REGISTER("sdl_set_sdl_color_b",ring_sdl_set_sdl_color_b);
	RING_API_REGISTER("sdl_new_sdl_palette",ring_sdl_new_sdl_palette);
	RING_API_REGISTER("sdl_new_managed_sdl_palette",ring_sdl_new_managed_sdl_palette);
	RING_API_REGISTER("sdl_destroy_sdl_palette",ring_sdl_destroy_sdl_palette);
	RING_API_REGISTER("sdl_new_sdl_pixelformat",ring_sdl_new_sdl_pixelformat);
	RING_API_REGISTER("sdl_new_managed_sdl_pixelformat",ring_sdl_new_managed_sdl_pixelformat);
	RING_API_REGISTER("sdl_destroy_sdl_pixelformat",ring_sdl_destroy_sdl_pixelformat);
	RING_API_REGISTER("sdl_new_sdl_point",ring_sdl_new_sdl_point);
	RING_API_REGISTER("sdl_new_managed_sdl_point",ring_sdl_new_managed_sdl_point);
	RING_API_REGISTER("sdl_destroy_sdl_point",ring_sdl_destroy_sdl_point);
	RING_API_REGISTER("sdl_get_sdl_point_x",ring_sdl_get_sdl_point_x);
	RING_API_REGISTER("sdl_set_sdl_point_x",ring_sdl_set_sdl_point_x);
	RING_API_REGISTER("sdl_get_sdl_point_y",ring_sdl_get_sdl_point_y);
	RING_API_REGISTER("sdl_set_sdl_point_y",ring_sdl_set_sdl_point_y);
	RING_API_REGISTER("sdl_new_sdl_rect",ring_sdl_new_sdl_rect);
	RING_API_REGISTER("sdl_new_managed_sdl_rect",ring_sdl_new_managed_sdl_rect);
	RING_API_REGISTER("sdl_destroy_sdl_rect",ring_sdl_destroy_sdl_rect);
	RING_API_REGISTER("sdl_get_sdl_rect_x",ring_sdl_get_sdl_rect_x);
	RING_API_REGISTER("sdl_set_sdl_rect_x",ring_sdl_set_sdl_rect_x);
	RING_API_REGISTER("sdl_get_sdl_rect_y",ring_sdl_get_sdl_rect_y);
	RING_API_REGISTER("sdl_set_sdl_rect_y",ring_sdl_set_sdl_rect_y);
	RING_API_REGISTER("sdl_get_sdl_rect_w",ring_sdl_get_sdl_rect_w);
	RING_API_REGISTER("sdl_set_sdl_rect_w",ring_sdl_set_sdl_rect_w);
	RING_API_REGISTER("sdl_get_sdl_rect_h",ring_sdl_get_sdl_rect_h);
	RING_API_REGISTER("sdl_set_sdl_rect_h",ring_sdl_set_sdl_rect_h);
	RING_API_REGISTER("sdl_new_sdl_surface",ring_sdl_new_sdl_surface);
	RING_API_REGISTER("sdl_new_managed_sdl_surface",ring_sdl_new_managed_sdl_surface);
	RING_API_REGISTER("sdl_destroy_sdl_surface",ring_sdl_destroy_sdl_surface);
	RING_API_REGISTER("sdl_get_sdl_surface_flags",ring_sdl_get_sdl_surface_flags);
	RING_API_REGISTER("sdl_set_sdl_surface_flags",ring_sdl_set_sdl_surface_flags);
	RING_API_REGISTER("sdl_get_sdl_surface_format",ring_sdl_get_sdl_surface_format);
	RING_API_REGISTER("sdl_set_sdl_surface_format",ring_sdl_set_sdl_surface_format);
	RING_API_REGISTER("sdl_get_sdl_surface_w",ring_sdl_get_sdl_surface_w);
	RING_API_REGISTER("sdl_set_sdl_surface_w",ring_sdl_set_sdl_surface_w);
	RING_API_REGISTER("sdl_get_sdl_surface_h",ring_sdl_get_sdl_surface_h);
	RING_API_REGISTER("sdl_set_sdl_surface_h",ring_sdl_set_sdl_surface_h);
	RING_API_REGISTER("sdl_get_sdl_surface_pitch",ring_sdl_get_sdl_surface_pitch);
	RING_API_REGISTER("sdl_set_sdl_surface_pitch",ring_sdl_set_sdl_surface_pitch);
	RING_API_REGISTER("sdl_get_sdl_surface_pixels",ring_sdl_get_sdl_surface_pixels);
	RING_API_REGISTER("sdl_set_sdl_surface_pixels",ring_sdl_set_sdl_surface_pixels);
	RING_API_REGISTER("sdl_get_sdl_surface_userdata",ring_sdl_get_sdl_surface_userdata);
	RING_API_REGISTER("sdl_set_sdl_surface_userdata",ring_sdl_set_sdl_surface_userdata);
	RING_API_REGISTER("sdl_get_sdl_surface_locked",ring_sdl_get_sdl_surface_locked);
	RING_API_REGISTER("sdl_set_sdl_surface_locked",ring_sdl_set_sdl_surface_locked);
	RING_API_REGISTER("sdl_new_sdl_controlleraxisevent",ring_sdl_new_sdl_controlleraxisevent);
	RING_API_REGISTER("sdl_new_managed_sdl_controlleraxisevent",ring_sdl_new_managed_sdl_controlleraxisevent);
	RING_API_REGISTER("sdl_destroy_sdl_controlleraxisevent",ring_sdl_destroy_sdl_controlleraxisevent);
	RING_API_REGISTER("sdl_get_sdl_controlleraxisevent_type",ring_sdl_get_sdl_controlleraxisevent_type);
	RING_API_REGISTER("sdl_set_sdl_controlleraxisevent_type",ring_sdl_set_sdl_controlleraxisevent_type);
	RING_API_REGISTER("sdl_get_sdl_controlleraxisevent_timestamp",ring_sdl_get_sdl_controlleraxisevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_controlleraxisevent_timestamp",ring_sdl_set_sdl_controlleraxisevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_controlleraxisevent_which",ring_sdl_get_sdl_controlleraxisevent_which);
	RING_API_REGISTER("sdl_set_sdl_controlleraxisevent_which",ring_sdl_set_sdl_controlleraxisevent_which);
	RING_API_REGISTER("sdl_get_sdl_controlleraxisevent_axis",ring_sdl_get_sdl_controlleraxisevent_axis);
	RING_API_REGISTER("sdl_set_sdl_controlleraxisevent_axis",ring_sdl_set_sdl_controlleraxisevent_axis);
	RING_API_REGISTER("sdl_get_sdl_controlleraxisevent_value",ring_sdl_get_sdl_controlleraxisevent_value);
	RING_API_REGISTER("sdl_set_sdl_controlleraxisevent_value",ring_sdl_set_sdl_controlleraxisevent_value);
	RING_API_REGISTER("sdl_new_sdl_controllerbuttonevent",ring_sdl_new_sdl_controllerbuttonevent);
	RING_API_REGISTER("sdl_new_managed_sdl_controllerbuttonevent",ring_sdl_new_managed_sdl_controllerbuttonevent);
	RING_API_REGISTER("sdl_destroy_sdl_controllerbuttonevent",ring_sdl_destroy_sdl_controllerbuttonevent);
	RING_API_REGISTER("sdl_new_sdl_controllerdeviceevent",ring_sdl_new_sdl_controllerdeviceevent);
	RING_API_REGISTER("sdl_new_managed_sdl_controllerdeviceevent",ring_sdl_new_managed_sdl_controllerdeviceevent);
	RING_API_REGISTER("sdl_destroy_sdl_controllerdeviceevent",ring_sdl_destroy_sdl_controllerdeviceevent);
	RING_API_REGISTER("sdl_new_sdl_dollargestureevent",ring_sdl_new_sdl_dollargestureevent);
	RING_API_REGISTER("sdl_new_managed_sdl_dollargestureevent",ring_sdl_new_managed_sdl_dollargestureevent);
	RING_API_REGISTER("sdl_destroy_sdl_dollargestureevent",ring_sdl_destroy_sdl_dollargestureevent);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_type",ring_sdl_get_sdl_dollargestureevent_type);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_type",ring_sdl_set_sdl_dollargestureevent_type);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_timestamp",ring_sdl_get_sdl_dollargestureevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_timestamp",ring_sdl_set_sdl_dollargestureevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_touchid",ring_sdl_get_sdl_dollargestureevent_touchId);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_touchid",ring_sdl_set_sdl_dollargestureevent_touchId);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_gestureid",ring_sdl_get_sdl_dollargestureevent_gestureId);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_gestureid",ring_sdl_set_sdl_dollargestureevent_gestureId);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_numfingers",ring_sdl_get_sdl_dollargestureevent_numFingers);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_numfingers",ring_sdl_set_sdl_dollargestureevent_numFingers);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_error",ring_sdl_get_sdl_dollargestureevent_error);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_error",ring_sdl_set_sdl_dollargestureevent_error);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_x",ring_sdl_get_sdl_dollargestureevent_x);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_x",ring_sdl_set_sdl_dollargestureevent_x);
	RING_API_REGISTER("sdl_get_sdl_dollargestureevent_y",ring_sdl_get_sdl_dollargestureevent_y);
	RING_API_REGISTER("sdl_set_sdl_dollargestureevent_y",ring_sdl_set_sdl_dollargestureevent_y);
	RING_API_REGISTER("sdl_new_sdl_dropevent",ring_sdl_new_sdl_dropevent);
	RING_API_REGISTER("sdl_new_managed_sdl_dropevent",ring_sdl_new_managed_sdl_dropevent);
	RING_API_REGISTER("sdl_destroy_sdl_dropevent",ring_sdl_destroy_sdl_dropevent);
	RING_API_REGISTER("sdl_get_sdl_dropevent_type",ring_sdl_get_sdl_dropevent_type);
	RING_API_REGISTER("sdl_set_sdl_dropevent_type",ring_sdl_set_sdl_dropevent_type);
	RING_API_REGISTER("sdl_get_sdl_dropevent_timestamp",ring_sdl_get_sdl_dropevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_dropevent_timestamp",ring_sdl_set_sdl_dropevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_dropevent_file",ring_sdl_get_sdl_dropevent_file);
	RING_API_REGISTER("sdl_set_sdl_dropevent_file",ring_sdl_set_sdl_dropevent_file);
	RING_API_REGISTER("sdl_new_sdl_event",ring_sdl_new_sdl_event);
	RING_API_REGISTER("sdl_new_managed_sdl_event",ring_sdl_new_managed_sdl_event);
	RING_API_REGISTER("sdl_destroy_sdl_event",ring_sdl_destroy_sdl_event);
	RING_API_REGISTER("sdl_get_sdl_event_type",ring_sdl_get_sdl_event_type);
	RING_API_REGISTER("sdl_set_sdl_event_type",ring_sdl_set_sdl_event_type);
	RING_API_REGISTER("sdl_get_sdl_event_key_keysym_sym",ring_sdl_get_sdl_event_key_keysym_sym);
	RING_API_REGISTER("sdl_set_sdl_event_key_keysym_sym",ring_sdl_set_sdl_event_key_keysym_sym);
	RING_API_REGISTER("sdl_get_sdl_event_button_type",ring_sdl_get_sdl_event_button_type);
	RING_API_REGISTER("sdl_set_sdl_event_button_type",ring_sdl_set_sdl_event_button_type);
	RING_API_REGISTER("sdl_get_sdl_event_button_state",ring_sdl_get_sdl_event_button_state);
	RING_API_REGISTER("sdl_set_sdl_event_button_state",ring_sdl_set_sdl_event_button_state);
	RING_API_REGISTER("sdl_get_sdl_event_button_x",ring_sdl_get_sdl_event_button_x);
	RING_API_REGISTER("sdl_set_sdl_event_button_x",ring_sdl_set_sdl_event_button_x);
	RING_API_REGISTER("sdl_get_sdl_event_button_y",ring_sdl_get_sdl_event_button_y);
	RING_API_REGISTER("sdl_set_sdl_event_button_y",ring_sdl_set_sdl_event_button_y);
	RING_API_REGISTER("sdl_get_sdl_event_button_button",ring_sdl_get_sdl_event_button_button);
	RING_API_REGISTER("sdl_set_sdl_event_button_button",ring_sdl_set_sdl_event_button_button);
	RING_API_REGISTER("sdl_get_sdl_event_motion_type",ring_sdl_get_sdl_event_motion_type);
	RING_API_REGISTER("sdl_set_sdl_event_motion_type",ring_sdl_set_sdl_event_motion_type);
	RING_API_REGISTER("sdl_get_sdl_event_motion_state",ring_sdl_get_sdl_event_motion_state);
	RING_API_REGISTER("sdl_set_sdl_event_motion_state",ring_sdl_set_sdl_event_motion_state);
	RING_API_REGISTER("sdl_get_sdl_event_motion_x",ring_sdl_get_sdl_event_motion_x);
	RING_API_REGISTER("sdl_set_sdl_event_motion_x",ring_sdl_set_sdl_event_motion_x);
	RING_API_REGISTER("sdl_get_sdl_event_motion_y",ring_sdl_get_sdl_event_motion_y);
	RING_API_REGISTER("sdl_set_sdl_event_motion_y",ring_sdl_set_sdl_event_motion_y);
	RING_API_REGISTER("sdl_get_sdl_event_motion_xrel",ring_sdl_get_sdl_event_motion_xrel);
	RING_API_REGISTER("sdl_set_sdl_event_motion_xrel",ring_sdl_set_sdl_event_motion_xrel);
	RING_API_REGISTER("sdl_get_sdl_event_motion_yrel",ring_sdl_get_sdl_event_motion_yrel);
	RING_API_REGISTER("sdl_set_sdl_event_motion_yrel",ring_sdl_set_sdl_event_motion_yrel);
	RING_API_REGISTER("sdl_new_sdl_touchfingerevent",ring_sdl_new_sdl_touchfingerevent);
	RING_API_REGISTER("sdl_new_managed_sdl_touchfingerevent",ring_sdl_new_managed_sdl_touchfingerevent);
	RING_API_REGISTER("sdl_destroy_sdl_touchfingerevent",ring_sdl_destroy_sdl_touchfingerevent);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_type",ring_sdl_get_sdl_touchfingerevent_type);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_type",ring_sdl_set_sdl_touchfingerevent_type);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_timestamp",ring_sdl_get_sdl_touchfingerevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_timestamp",ring_sdl_set_sdl_touchfingerevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_touchid",ring_sdl_get_sdl_touchfingerevent_touchId);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_touchid",ring_sdl_set_sdl_touchfingerevent_touchId);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_fingerid",ring_sdl_get_sdl_touchfingerevent_fingerId);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_fingerid",ring_sdl_set_sdl_touchfingerevent_fingerId);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_x",ring_sdl_get_sdl_touchfingerevent_x);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_x",ring_sdl_set_sdl_touchfingerevent_x);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_y",ring_sdl_get_sdl_touchfingerevent_y);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_y",ring_sdl_set_sdl_touchfingerevent_y);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_dx",ring_sdl_get_sdl_touchfingerevent_dx);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_dx",ring_sdl_set_sdl_touchfingerevent_dx);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_dy",ring_sdl_get_sdl_touchfingerevent_dy);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_dy",ring_sdl_set_sdl_touchfingerevent_dy);
	RING_API_REGISTER("sdl_get_sdl_touchfingerevent_pressure",ring_sdl_get_sdl_touchfingerevent_pressure);
	RING_API_REGISTER("sdl_set_sdl_touchfingerevent_pressure",ring_sdl_set_sdl_touchfingerevent_pressure);
	RING_API_REGISTER("sdl_new_sdl_finger",ring_sdl_new_sdl_finger);
	RING_API_REGISTER("sdl_new_managed_sdl_finger",ring_sdl_new_managed_sdl_finger);
	RING_API_REGISTER("sdl_destroy_sdl_finger",ring_sdl_destroy_sdl_finger);
	RING_API_REGISTER("sdl_new_sdl_joyaxisevent",ring_sdl_new_sdl_joyaxisevent);
	RING_API_REGISTER("sdl_new_managed_sdl_joyaxisevent",ring_sdl_new_managed_sdl_joyaxisevent);
	RING_API_REGISTER("sdl_destroy_sdl_joyaxisevent",ring_sdl_destroy_sdl_joyaxisevent);
	RING_API_REGISTER("sdl_get_sdl_joyaxisevent_type",ring_sdl_get_sdl_joyaxisevent_type);
	RING_API_REGISTER("sdl_set_sdl_joyaxisevent_type",ring_sdl_set_sdl_joyaxisevent_type);
	RING_API_REGISTER("sdl_get_sdl_joyaxisevent_timestamp",ring_sdl_get_sdl_joyaxisevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_joyaxisevent_timestamp",ring_sdl_set_sdl_joyaxisevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_joyaxisevent_which",ring_sdl_get_sdl_joyaxisevent_which);
	RING_API_REGISTER("sdl_set_sdl_joyaxisevent_which",ring_sdl_set_sdl_joyaxisevent_which);
	RING_API_REGISTER("sdl_get_sdl_joyaxisevent_axis",ring_sdl_get_sdl_joyaxisevent_axis);
	RING_API_REGISTER("sdl_set_sdl_joyaxisevent_axis",ring_sdl_set_sdl_joyaxisevent_axis);
	RING_API_REGISTER("sdl_get_sdl_joyaxisevent_value",ring_sdl_get_sdl_joyaxisevent_value);
	RING_API_REGISTER("sdl_set_sdl_joyaxisevent_value",ring_sdl_set_sdl_joyaxisevent_value);
	RING_API_REGISTER("sdl_new_sdl_joyballevent",ring_sdl_new_sdl_joyballevent);
	RING_API_REGISTER("sdl_new_managed_sdl_joyballevent",ring_sdl_new_managed_sdl_joyballevent);
	RING_API_REGISTER("sdl_destroy_sdl_joyballevent",ring_sdl_destroy_sdl_joyballevent);
	RING_API_REGISTER("sdl_new_sdl_joybuttonevent",ring_sdl_new_sdl_joybuttonevent);
	RING_API_REGISTER("sdl_new_managed_sdl_joybuttonevent",ring_sdl_new_managed_sdl_joybuttonevent);
	RING_API_REGISTER("sdl_destroy_sdl_joybuttonevent",ring_sdl_destroy_sdl_joybuttonevent);
	RING_API_REGISTER("sdl_new_sdl_joydeviceevent",ring_sdl_new_sdl_joydeviceevent);
	RING_API_REGISTER("sdl_new_managed_sdl_joydeviceevent",ring_sdl_new_managed_sdl_joydeviceevent);
	RING_API_REGISTER("sdl_destroy_sdl_joydeviceevent",ring_sdl_destroy_sdl_joydeviceevent);
	RING_API_REGISTER("sdl_new_sdl_joyhatevent",ring_sdl_new_sdl_joyhatevent);
	RING_API_REGISTER("sdl_new_managed_sdl_joyhatevent",ring_sdl_new_managed_sdl_joyhatevent);
	RING_API_REGISTER("sdl_destroy_sdl_joyhatevent",ring_sdl_destroy_sdl_joyhatevent);
	RING_API_REGISTER("sdl_new_sdl_keyboardevent",ring_sdl_new_sdl_keyboardevent);
	RING_API_REGISTER("sdl_new_managed_sdl_keyboardevent",ring_sdl_new_managed_sdl_keyboardevent);
	RING_API_REGISTER("sdl_destroy_sdl_keyboardevent",ring_sdl_destroy_sdl_keyboardevent);
	RING_API_REGISTER("sdl_get_sdl_keyboardevent_type",ring_sdl_get_sdl_keyboardevent_type);
	RING_API_REGISTER("sdl_set_sdl_keyboardevent_type",ring_sdl_set_sdl_keyboardevent_type);
	RING_API_REGISTER("sdl_get_sdl_keyboardevent_timestamp",ring_sdl_get_sdl_keyboardevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_keyboardevent_timestamp",ring_sdl_set_sdl_keyboardevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_keyboardevent_windowid",ring_sdl_get_sdl_keyboardevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_keyboardevent_windowid",ring_sdl_set_sdl_keyboardevent_windowID);
	RING_API_REGISTER("sdl_get_sdl_keyboardevent_state",ring_sdl_get_sdl_keyboardevent_state);
	RING_API_REGISTER("sdl_set_sdl_keyboardevent_state",ring_sdl_set_sdl_keyboardevent_state);
	RING_API_REGISTER("sdl_get_sdl_keyboardevent_repeat",ring_sdl_get_sdl_keyboardevent_repeat);
	RING_API_REGISTER("sdl_set_sdl_keyboardevent_repeat",ring_sdl_set_sdl_keyboardevent_repeat);
	RING_API_REGISTER("sdl_new_sdl_mousebuttonevent",ring_sdl_new_sdl_mousebuttonevent);
	RING_API_REGISTER("sdl_new_managed_sdl_mousebuttonevent",ring_sdl_new_managed_sdl_mousebuttonevent);
	RING_API_REGISTER("sdl_destroy_sdl_mousebuttonevent",ring_sdl_destroy_sdl_mousebuttonevent);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_type",ring_sdl_get_sdl_mousebuttonevent_type);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_type",ring_sdl_set_sdl_mousebuttonevent_type);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_timestamp",ring_sdl_get_sdl_mousebuttonevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_timestamp",ring_sdl_set_sdl_mousebuttonevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_windowid",ring_sdl_get_sdl_mousebuttonevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_windowid",ring_sdl_set_sdl_mousebuttonevent_windowID);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_which",ring_sdl_get_sdl_mousebuttonevent_which);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_which",ring_sdl_set_sdl_mousebuttonevent_which);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_button",ring_sdl_get_sdl_mousebuttonevent_button);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_button",ring_sdl_set_sdl_mousebuttonevent_button);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_state",ring_sdl_get_sdl_mousebuttonevent_state);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_state",ring_sdl_set_sdl_mousebuttonevent_state);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_clicks",ring_sdl_get_sdl_mousebuttonevent_clicks);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_clicks",ring_sdl_set_sdl_mousebuttonevent_clicks);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_x",ring_sdl_get_sdl_mousebuttonevent_x);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_x",ring_sdl_set_sdl_mousebuttonevent_x);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonevent_y",ring_sdl_get_sdl_mousebuttonevent_y);
	RING_API_REGISTER("sdl_set_sdl_mousebuttonevent_y",ring_sdl_set_sdl_mousebuttonevent_y);
	RING_API_REGISTER("sdl_new_sdl_mousemotionevent",ring_sdl_new_sdl_mousemotionevent);
	RING_API_REGISTER("sdl_new_managed_sdl_mousemotionevent",ring_sdl_new_managed_sdl_mousemotionevent);
	RING_API_REGISTER("sdl_destroy_sdl_mousemotionevent",ring_sdl_destroy_sdl_mousemotionevent);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_type",ring_sdl_get_sdl_mousemotionevent_type);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_type",ring_sdl_set_sdl_mousemotionevent_type);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_timestamp",ring_sdl_get_sdl_mousemotionevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_timestamp",ring_sdl_set_sdl_mousemotionevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_windowid",ring_sdl_get_sdl_mousemotionevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_windowid",ring_sdl_set_sdl_mousemotionevent_windowID);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_which",ring_sdl_get_sdl_mousemotionevent_which);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_which",ring_sdl_set_sdl_mousemotionevent_which);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_state",ring_sdl_get_sdl_mousemotionevent_state);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_state",ring_sdl_set_sdl_mousemotionevent_state);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_x",ring_sdl_get_sdl_mousemotionevent_x);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_x",ring_sdl_set_sdl_mousemotionevent_x);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_y",ring_sdl_get_sdl_mousemotionevent_y);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_y",ring_sdl_set_sdl_mousemotionevent_y);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_xrel",ring_sdl_get_sdl_mousemotionevent_xrel);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_xrel",ring_sdl_set_sdl_mousemotionevent_xrel);
	RING_API_REGISTER("sdl_get_sdl_mousemotionevent_yrel",ring_sdl_get_sdl_mousemotionevent_yrel);
	RING_API_REGISTER("sdl_set_sdl_mousemotionevent_yrel",ring_sdl_set_sdl_mousemotionevent_yrel);
	RING_API_REGISTER("sdl_new_sdl_mousewheelevent",ring_sdl_new_sdl_mousewheelevent);
	RING_API_REGISTER("sdl_new_managed_sdl_mousewheelevent",ring_sdl_new_managed_sdl_mousewheelevent);
	RING_API_REGISTER("sdl_destroy_sdl_mousewheelevent",ring_sdl_destroy_sdl_mousewheelevent);
	RING_API_REGISTER("sdl_get_sdl_mousewheelevent_type",ring_sdl_get_sdl_mousewheelevent_type);
	RING_API_REGISTER("sdl_set_sdl_mousewheelevent_type",ring_sdl_set_sdl_mousewheelevent_type);
	RING_API_REGISTER("sdl_get_sdl_mousewheelevent_timestamp",ring_sdl_get_sdl_mousewheelevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_mousewheelevent_timestamp",ring_sdl_set_sdl_mousewheelevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_mousewheelevent_windowid",ring_sdl_get_sdl_mousewheelevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_mousewheelevent_windowid",ring_sdl_set_sdl_mousewheelevent_windowID);
	RING_API_REGISTER("sdl_get_sdl_mousewheelevent_which",ring_sdl_get_sdl_mousewheelevent_which);
	RING_API_REGISTER("sdl_set_sdl_mousewheelevent_which",ring_sdl_set_sdl_mousewheelevent_which);
	RING_API_REGISTER("sdl_get_sdl_mousewheelevent_x",ring_sdl_get_sdl_mousewheelevent_x);
	RING_API_REGISTER("sdl_set_sdl_mousewheelevent_x",ring_sdl_set_sdl_mousewheelevent_x);
	RING_API_REGISTER("sdl_get_sdl_mousewheelevent_y",ring_sdl_get_sdl_mousewheelevent_y);
	RING_API_REGISTER("sdl_set_sdl_mousewheelevent_y",ring_sdl_set_sdl_mousewheelevent_y);
	RING_API_REGISTER("sdl_new_sdl_multigestureevent",ring_sdl_new_sdl_multigestureevent);
	RING_API_REGISTER("sdl_new_managed_sdl_multigestureevent",ring_sdl_new_managed_sdl_multigestureevent);
	RING_API_REGISTER("sdl_destroy_sdl_multigestureevent",ring_sdl_destroy_sdl_multigestureevent);
	RING_API_REGISTER("sdl_new_sdl_quitevent",ring_sdl_new_sdl_quitevent);
	RING_API_REGISTER("sdl_new_managed_sdl_quitevent",ring_sdl_new_managed_sdl_quitevent);
	RING_API_REGISTER("sdl_destroy_sdl_quitevent",ring_sdl_destroy_sdl_quitevent);
	RING_API_REGISTER("sdl_new_sdl_texteditingevent",ring_sdl_new_sdl_texteditingevent);
	RING_API_REGISTER("sdl_new_managed_sdl_texteditingevent",ring_sdl_new_managed_sdl_texteditingevent);
	RING_API_REGISTER("sdl_destroy_sdl_texteditingevent",ring_sdl_destroy_sdl_texteditingevent);
	RING_API_REGISTER("sdl_get_sdl_texteditingevent_type",ring_sdl_get_sdl_texteditingevent_type);
	RING_API_REGISTER("sdl_set_sdl_texteditingevent_type",ring_sdl_set_sdl_texteditingevent_type);
	RING_API_REGISTER("sdl_get_sdl_texteditingevent_timestamp",ring_sdl_get_sdl_texteditingevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_texteditingevent_timestamp",ring_sdl_set_sdl_texteditingevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_texteditingevent_windowid",ring_sdl_get_sdl_texteditingevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_texteditingevent_windowid",ring_sdl_set_sdl_texteditingevent_windowID);
	RING_API_REGISTER("sdl_get_sdl_texteditingevent_start",ring_sdl_get_sdl_texteditingevent_start);
	RING_API_REGISTER("sdl_set_sdl_texteditingevent_start",ring_sdl_set_sdl_texteditingevent_start);
	RING_API_REGISTER("sdl_get_sdl_texteditingevent_length",ring_sdl_get_sdl_texteditingevent_length);
	RING_API_REGISTER("sdl_set_sdl_texteditingevent_length",ring_sdl_set_sdl_texteditingevent_length);
	RING_API_REGISTER("sdl_new_sdl_textinputevent",ring_sdl_new_sdl_textinputevent);
	RING_API_REGISTER("sdl_new_managed_sdl_textinputevent",ring_sdl_new_managed_sdl_textinputevent);
	RING_API_REGISTER("sdl_destroy_sdl_textinputevent",ring_sdl_destroy_sdl_textinputevent);
	RING_API_REGISTER("sdl_get_sdl_textinputevent_type",ring_sdl_get_sdl_textinputevent_type);
	RING_API_REGISTER("sdl_set_sdl_textinputevent_type",ring_sdl_set_sdl_textinputevent_type);
	RING_API_REGISTER("sdl_get_sdl_textinputevent_timestamp",ring_sdl_get_sdl_textinputevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_textinputevent_timestamp",ring_sdl_set_sdl_textinputevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_textinputevent_windowid",ring_sdl_get_sdl_textinputevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_textinputevent_windowid",ring_sdl_set_sdl_textinputevent_windowID);
	RING_API_REGISTER("sdl_new_sdl_userevent",ring_sdl_new_sdl_userevent);
	RING_API_REGISTER("sdl_new_managed_sdl_userevent",ring_sdl_new_managed_sdl_userevent);
	RING_API_REGISTER("sdl_destroy_sdl_userevent",ring_sdl_destroy_sdl_userevent);
	RING_API_REGISTER("sdl_get_sdl_userevent_type",ring_sdl_get_sdl_userevent_type);
	RING_API_REGISTER("sdl_set_sdl_userevent_type",ring_sdl_set_sdl_userevent_type);
	RING_API_REGISTER("sdl_get_sdl_userevent_timestamp",ring_sdl_get_sdl_userevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_userevent_timestamp",ring_sdl_set_sdl_userevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_userevent_windowid",ring_sdl_get_sdl_userevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_userevent_windowid",ring_sdl_set_sdl_userevent_windowID);
	RING_API_REGISTER("sdl_get_sdl_userevent_code",ring_sdl_get_sdl_userevent_code);
	RING_API_REGISTER("sdl_set_sdl_userevent_code",ring_sdl_set_sdl_userevent_code);
	RING_API_REGISTER("sdl_get_sdl_userevent_data1",ring_sdl_get_sdl_userevent_data1);
	RING_API_REGISTER("sdl_set_sdl_userevent_data1",ring_sdl_set_sdl_userevent_data1);
	RING_API_REGISTER("sdl_get_sdl_userevent_data2",ring_sdl_get_sdl_userevent_data2);
	RING_API_REGISTER("sdl_set_sdl_userevent_data2",ring_sdl_set_sdl_userevent_data2);
	RING_API_REGISTER("sdl_new_sdl_windowevent",ring_sdl_new_sdl_windowevent);
	RING_API_REGISTER("sdl_new_managed_sdl_windowevent",ring_sdl_new_managed_sdl_windowevent);
	RING_API_REGISTER("sdl_destroy_sdl_windowevent",ring_sdl_destroy_sdl_windowevent);
	RING_API_REGISTER("sdl_get_sdl_windowevent_type",ring_sdl_get_sdl_windowevent_type);
	RING_API_REGISTER("sdl_set_sdl_windowevent_type",ring_sdl_set_sdl_windowevent_type);
	RING_API_REGISTER("sdl_get_sdl_windowevent_timestamp",ring_sdl_get_sdl_windowevent_timestamp);
	RING_API_REGISTER("sdl_set_sdl_windowevent_timestamp",ring_sdl_set_sdl_windowevent_timestamp);
	RING_API_REGISTER("sdl_get_sdl_windowevent_windowid",ring_sdl_get_sdl_windowevent_windowID);
	RING_API_REGISTER("sdl_set_sdl_windowevent_windowid",ring_sdl_set_sdl_windowevent_windowID);
	RING_API_REGISTER("sdl_get_sdl_windowevent_event",ring_sdl_get_sdl_windowevent_event);
	RING_API_REGISTER("sdl_set_sdl_windowevent_event",ring_sdl_set_sdl_windowevent_event);
	RING_API_REGISTER("sdl_get_sdl_windowevent_data1",ring_sdl_get_sdl_windowevent_data1);
	RING_API_REGISTER("sdl_set_sdl_windowevent_data1",ring_sdl_set_sdl_windowevent_data1);
	RING_API_REGISTER("sdl_get_sdl_windowevent_data2",ring_sdl_get_sdl_windowevent_data2);
	RING_API_REGISTER("sdl_set_sdl_windowevent_data2",ring_sdl_set_sdl_windowevent_data2);
	RING_API_REGISTER("sdl_new_sdl_keysym",ring_sdl_new_sdl_keysym);
	RING_API_REGISTER("sdl_new_managed_sdl_keysym",ring_sdl_new_managed_sdl_keysym);
	RING_API_REGISTER("sdl_destroy_sdl_keysym",ring_sdl_destroy_sdl_keysym);
	RING_API_REGISTER("sdl_new_sdl_hapticcondition",ring_sdl_new_sdl_hapticcondition);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticcondition",ring_sdl_new_managed_sdl_hapticcondition);
	RING_API_REGISTER("sdl_destroy_sdl_hapticcondition",ring_sdl_destroy_sdl_hapticcondition);
	RING_API_REGISTER("sdl_new_sdl_hapticconstant",ring_sdl_new_sdl_hapticconstant);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticconstant",ring_sdl_new_managed_sdl_hapticconstant);
	RING_API_REGISTER("sdl_destroy_sdl_hapticconstant",ring_sdl_destroy_sdl_hapticconstant);
	RING_API_REGISTER("sdl_new_sdl_hapticcustom",ring_sdl_new_sdl_hapticcustom);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticcustom",ring_sdl_new_managed_sdl_hapticcustom);
	RING_API_REGISTER("sdl_destroy_sdl_hapticcustom",ring_sdl_destroy_sdl_hapticcustom);
	RING_API_REGISTER("sdl_new_sdl_hapticdirection",ring_sdl_new_sdl_hapticdirection);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticdirection",ring_sdl_new_managed_sdl_hapticdirection);
	RING_API_REGISTER("sdl_destroy_sdl_hapticdirection",ring_sdl_destroy_sdl_hapticdirection);
	RING_API_REGISTER("sdl_new_sdl_hapticeffect",ring_sdl_new_sdl_hapticeffect);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticeffect",ring_sdl_new_managed_sdl_hapticeffect);
	RING_API_REGISTER("sdl_destroy_sdl_hapticeffect",ring_sdl_destroy_sdl_hapticeffect);
	RING_API_REGISTER("sdl_new_sdl_hapticleftright",ring_sdl_new_sdl_hapticleftright);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticleftright",ring_sdl_new_managed_sdl_hapticleftright);
	RING_API_REGISTER("sdl_destroy_sdl_hapticleftright",ring_sdl_destroy_sdl_hapticleftright);
	RING_API_REGISTER("sdl_new_sdl_hapticperiodic",ring_sdl_new_sdl_hapticperiodic);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticperiodic",ring_sdl_new_managed_sdl_hapticperiodic);
	RING_API_REGISTER("sdl_destroy_sdl_hapticperiodic",ring_sdl_destroy_sdl_hapticperiodic);
	RING_API_REGISTER("sdl_new_sdl_hapticramp",ring_sdl_new_sdl_hapticramp);
	RING_API_REGISTER("sdl_new_managed_sdl_hapticramp",ring_sdl_new_managed_sdl_hapticramp);
	RING_API_REGISTER("sdl_destroy_sdl_hapticramp",ring_sdl_destroy_sdl_hapticramp);
	RING_API_REGISTER("sdl_new_sdl_audiocvt",ring_sdl_new_sdl_audiocvt);
	RING_API_REGISTER("sdl_new_managed_sdl_audiocvt",ring_sdl_new_managed_sdl_audiocvt);
	RING_API_REGISTER("sdl_destroy_sdl_audiocvt",ring_sdl_destroy_sdl_audiocvt);
	RING_API_REGISTER("sdl_new_sdl_audiospec",ring_sdl_new_sdl_audiospec);
	RING_API_REGISTER("sdl_new_managed_sdl_audiospec",ring_sdl_new_managed_sdl_audiospec);
	RING_API_REGISTER("sdl_destroy_sdl_audiospec",ring_sdl_destroy_sdl_audiospec);
	RING_API_REGISTER("sdl_new_sdl_rwops",ring_sdl_new_sdl_rwops);
	RING_API_REGISTER("sdl_new_managed_sdl_rwops",ring_sdl_new_managed_sdl_rwops);
	RING_API_REGISTER("sdl_destroy_sdl_rwops",ring_sdl_destroy_sdl_rwops);
	RING_API_REGISTER("sdl_new_mix_chunk",ring_sdl_new_mix_chunk);
	RING_API_REGISTER("sdl_new_managed_mix_chunk",ring_sdl_new_managed_mix_chunk);
	RING_API_REGISTER("sdl_destroy_mix_chunk",ring_sdl_destroy_mix_chunk);
	RING_API_REGISTER("sdl_new_mix_musictype",ring_sdl_new_mix_musictype);
	RING_API_REGISTER("sdl_new_managed_mix_musictype",ring_sdl_new_managed_mix_musictype);
	RING_API_REGISTER("sdl_destroy_mix_musictype",ring_sdl_destroy_mix_musictype);
	RING_API_REGISTER("sdl_new_mix_fading",ring_sdl_new_mix_fading);
	RING_API_REGISTER("sdl_new_managed_mix_fading",ring_sdl_new_managed_mix_fading);
	RING_API_REGISTER("sdl_destroy_mix_fading",ring_sdl_destroy_mix_fading);
	RING_API_REGISTER("sdl_new_ipaddress",ring_sdl_new_ipaddress);
	RING_API_REGISTER("sdl_new_managed_ipaddress",ring_sdl_new_managed_ipaddress);
	RING_API_REGISTER("sdl_destroy_ipaddress",ring_sdl_destroy_ipaddress);
	RING_API_REGISTER("sdl_get_ipaddress_host",ring_sdl_get_ipaddress_host);
	RING_API_REGISTER("sdl_set_ipaddress_host",ring_sdl_set_ipaddress_host);
	RING_API_REGISTER("sdl_get_ipaddress_port",ring_sdl_get_ipaddress_port);
	RING_API_REGISTER("sdl_set_ipaddress_port",ring_sdl_set_ipaddress_port);
	RING_API_REGISTER("sdl_new_tcpsocket",ring_sdl_new_tcpsocket);
	RING_API_REGISTER("sdl_new_managed_tcpsocket",ring_sdl_new_managed_tcpsocket);
	RING_API_REGISTER("sdl_destroy_tcpsocket",ring_sdl_destroy_tcpsocket);
	RING_API_REGISTER("sdl_new_udpsocket",ring_sdl_new_udpsocket);
	RING_API_REGISTER("sdl_new_managed_udpsocket",ring_sdl_new_managed_udpsocket);
	RING_API_REGISTER("sdl_destroy_udpsocket",ring_sdl_destroy_udpsocket);
	RING_API_REGISTER("sdl_new_udppacket",ring_sdl_new_udppacket);
	RING_API_REGISTER("sdl_new_managed_udppacket",ring_sdl_new_managed_udppacket);
	RING_API_REGISTER("sdl_destroy_udppacket",ring_sdl_destroy_udppacket);
	RING_API_REGISTER("sdl_get_udppacket_channel",ring_sdl_get_udppacket_channel);
	RING_API_REGISTER("sdl_set_udppacket_channel",ring_sdl_set_udppacket_channel);
	RING_API_REGISTER("sdl_get_udppacket_data",ring_sdl_get_udppacket_data);
	RING_API_REGISTER("sdl_set_udppacket_data",ring_sdl_set_udppacket_data);
	RING_API_REGISTER("sdl_get_udppacket_len",ring_sdl_get_udppacket_len);
	RING_API_REGISTER("sdl_set_udppacket_len",ring_sdl_set_udppacket_len);
	RING_API_REGISTER("sdl_get_udppacket_maxlen",ring_sdl_get_udppacket_maxlen);
	RING_API_REGISTER("sdl_set_udppacket_maxlen",ring_sdl_set_udppacket_maxlen);
	RING_API_REGISTER("sdl_get_udppacket_status",ring_sdl_get_udppacket_status);
	RING_API_REGISTER("sdl_set_udppacket_status",ring_sdl_set_udppacket_status);
	RING_API_REGISTER("sdl_new_sdlnet_socketset",ring_sdl_new_sdlnet_socketset);
	RING_API_REGISTER("sdl_new_managed_sdlnet_socketset",ring_sdl_new_managed_sdlnet_socketset);
	RING_API_REGISTER("sdl_destroy_sdlnet_socketset",ring_sdl_destroy_sdlnet_socketset);
	RING_API_REGISTER("sdl_new_sdlnet_genericsocket",ring_sdl_new_sdlnet_genericsocket);
	RING_API_REGISTER("sdl_new_managed_sdlnet_genericsocket",ring_sdl_new_managed_sdlnet_genericsocket);
	RING_API_REGISTER("sdl_destroy_sdlnet_genericsocket",ring_sdl_destroy_sdlnet_genericsocket);
	RING_API_REGISTER("sdl_get_mix_default_format",ring_sdl_get_mix_default_format);
	RING_API_REGISTER("sdl_get_sdl_quit",ring_sdl_get_sdl_quit);
	RING_API_REGISTER("sdl_get_sdl_button_left",ring_sdl_get_sdl_button_left);
	RING_API_REGISTER("sdl_get_sdl_button_middle",ring_sdl_get_sdl_button_middle);
	RING_API_REGISTER("sdl_get_sdl_button_right",ring_sdl_get_sdl_button_right);
	RING_API_REGISTER("sdl_get_sdl_pressed",ring_sdl_get_sdl_pressed);
	RING_API_REGISTER("sdl_get_sdl_released",ring_sdl_get_sdl_released);
	RING_API_REGISTER("sdl_get_sdl_app_terminating",ring_sdl_get_sdl_app_terminating);
	RING_API_REGISTER("sdl_get_sdl_app_lowmemory",ring_sdl_get_sdl_app_lowmemory);
	RING_API_REGISTER("sdl_get_sdl_app_willenterbackground",ring_sdl_get_sdl_app_willenterbackground);
	RING_API_REGISTER("sdl_get_sdl_app_didenterbackground",ring_sdl_get_sdl_app_didenterbackground);
	RING_API_REGISTER("sdl_get_sdl_app_willenterforeground",ring_sdl_get_sdl_app_willenterforeground);
	RING_API_REGISTER("sdl_get_sdl_app_didenterforeground",ring_sdl_get_sdl_app_didenterforeground);
	RING_API_REGISTER("sdl_get_sdl_windowevent",ring_sdl_get_sdl_windowevent);
	RING_API_REGISTER("sdl_get_sdl_keydown",ring_sdl_get_sdl_keydown);
	RING_API_REGISTER("sdl_get_sdl_keyup",ring_sdl_get_sdl_keyup);
	RING_API_REGISTER("sdl_get_sdl_textediting",ring_sdl_get_sdl_textediting);
	RING_API_REGISTER("sdl_get_sdl_textinput",ring_sdl_get_sdl_textinput);
	RING_API_REGISTER("sdl_get_sdl_mousemotion",ring_sdl_get_sdl_mousemotion);
	RING_API_REGISTER("sdl_get_sdl_mousebuttondown",ring_sdl_get_sdl_mousebuttondown);
	RING_API_REGISTER("sdl_get_sdl_mousebuttonup",ring_sdl_get_sdl_mousebuttonup);
	RING_API_REGISTER("sdl_get_sdl_mousewheel",ring_sdl_get_sdl_mousewheel);
	RING_API_REGISTER("sdl_get_sdl_joyaxismotion",ring_sdl_get_sdl_joyaxismotion);
	RING_API_REGISTER("sdl_get_sdl_joyballmotion",ring_sdl_get_sdl_joyballmotion);
	RING_API_REGISTER("sdl_get_sdl_joyhatmotion",ring_sdl_get_sdl_joyhatmotion);
	RING_API_REGISTER("sdl_get_sdl_joybuttondown",ring_sdl_get_sdl_joybuttondown);
	RING_API_REGISTER("sdl_get_sdl_joybuttonup",ring_sdl_get_sdl_joybuttonup);
	RING_API_REGISTER("sdl_get_sdl_joydeviceadded",ring_sdl_get_sdl_joydeviceadded);
	RING_API_REGISTER("sdl_get_sdl_joydeviceremoved",ring_sdl_get_sdl_joydeviceremoved);
	RING_API_REGISTER("sdl_get_sdl_controlleraxismotion",ring_sdl_get_sdl_controlleraxismotion);
	RING_API_REGISTER("sdl_get_sdl_controllerbuttondown",ring_sdl_get_sdl_controllerbuttondown);
	RING_API_REGISTER("sdl_get_sdl_controllerbuttonup",ring_sdl_get_sdl_controllerbuttonup);
	RING_API_REGISTER("sdl_get_sdl_controllerdeviceadded",ring_sdl_get_sdl_controllerdeviceadded);
	RING_API_REGISTER("sdl_get_sdl_controllerdeviceremoved",ring_sdl_get_sdl_controllerdeviceremoved);
	RING_API_REGISTER("sdl_get_sdl_controllerdeviceremapped",ring_sdl_get_sdl_controllerdeviceremapped);
	RING_API_REGISTER("sdl_get_sdl_fingerdown",ring_sdl_get_sdl_fingerdown);
	RING_API_REGISTER("sdl_get_sdl_fingerup",ring_sdl_get_sdl_fingerup);
	RING_API_REGISTER("sdl_get_sdl_fingermotion",ring_sdl_get_sdl_fingermotion);
	RING_API_REGISTER("sdl_get_sdl_dollargesture",ring_sdl_get_sdl_dollargesture);
	RING_API_REGISTER("sdl_get_sdl_dollarrecord",ring_sdl_get_sdl_dollarrecord);
	RING_API_REGISTER("sdl_get_sdl_multigesture",ring_sdl_get_sdl_multigesture);
	RING_API_REGISTER("sdl_get_sdl_clipboardupdate",ring_sdl_get_sdl_clipboardupdate);
	RING_API_REGISTER("sdl_get_sdl_dropfile",ring_sdl_get_sdl_dropfile);
	RING_API_REGISTER("sdl_get_sdl_render_targets_reset",ring_sdl_get_sdl_render_targets_reset);
	RING_API_REGISTER("sdl_get_sdl_userevent",ring_sdl_get_sdl_userevent);
	RING_API_REGISTER("sdl_get_sdl_lastevent",ring_sdl_get_sdl_lastevent);
	RING_API_REGISTER("sdl_get_sdl_net_major_version",ring_sdl_get_sdl_net_major_version);
	RING_API_REGISTER("sdl_get_sdl_net_minor_version",ring_sdl_get_sdl_net_minor_version);
	RING_API_REGISTER("sdl_get_sdl_net_patchlevel",ring_sdl_get_sdl_net_patchlevel);
	RING_API_REGISTER("sdl_get_inaddr_any",ring_sdl_get_inaddr_any);
	RING_API_REGISTER("sdl_get_inaddr_none",ring_sdl_get_inaddr_none);
	RING_API_REGISTER("sdl_get_inaddr_broadcast",ring_sdl_get_inaddr_broadcast);
	RING_API_REGISTER("sdl_get_sdlnet_max_udpchannels",ring_sdl_get_sdlnet_max_udpchannels);
	RING_API_REGISTER("sdl_get_sdlnet_max_udpaddresses",ring_sdl_get_sdlnet_max_udpaddresses);
	RING_API_REGISTER("sdl_get_sdlk_0",ring_sdl_get_sdlk_0);
	RING_API_REGISTER("sdl_get_sdlk_1",ring_sdl_get_sdlk_1);
	RING_API_REGISTER("sdl_get_sdlk_2",ring_sdl_get_sdlk_2);
	RING_API_REGISTER("sdl_get_sdlk_3",ring_sdl_get_sdlk_3);
	RING_API_REGISTER("sdl_get_sdlk_4",ring_sdl_get_sdlk_4);
	RING_API_REGISTER("sdl_get_sdlk_5",ring_sdl_get_sdlk_5);
	RING_API_REGISTER("sdl_get_sdlk_6",ring_sdl_get_sdlk_6);
	RING_API_REGISTER("sdl_get_sdlk_7",ring_sdl_get_sdlk_7);
	RING_API_REGISTER("sdl_get_sdlk_8",ring_sdl_get_sdlk_8);
	RING_API_REGISTER("sdl_get_sdlk_9",ring_sdl_get_sdlk_9);
	RING_API_REGISTER("sdl_get_sdlk_a",ring_sdl_get_sdlk_a);
	RING_API_REGISTER("sdl_get_sdlk_ac_back",ring_sdl_get_sdlk_ac_back);
	RING_API_REGISTER("sdl_get_sdlk_ac_bookmarks",ring_sdl_get_sdlk_ac_bookmarks);
	RING_API_REGISTER("sdl_get_sdlk_ac_forward",ring_sdl_get_sdlk_ac_forward);
	RING_API_REGISTER("sdl_get_sdlk_ac_home",ring_sdl_get_sdlk_ac_home);
	RING_API_REGISTER("sdl_get_sdlk_ac_refresh",ring_sdl_get_sdlk_ac_refresh);
	RING_API_REGISTER("sdl_get_sdlk_ac_search",ring_sdl_get_sdlk_ac_search);
	RING_API_REGISTER("sdl_get_sdlk_ac_stop",ring_sdl_get_sdlk_ac_stop);
	RING_API_REGISTER("sdl_get_sdlk_again",ring_sdl_get_sdlk_again);
	RING_API_REGISTER("sdl_get_sdlk_alterase",ring_sdl_get_sdlk_alterase);
	RING_API_REGISTER("sdl_get_sdlk_quote",ring_sdl_get_sdlk_quote);
	RING_API_REGISTER("sdl_get_sdlk_application",ring_sdl_get_sdlk_application);
	RING_API_REGISTER("sdl_get_sdlk_audiomute",ring_sdl_get_sdlk_audiomute);
	RING_API_REGISTER("sdl_get_sdlk_audionext",ring_sdl_get_sdlk_audionext);
	RING_API_REGISTER("sdl_get_sdlk_audioplay",ring_sdl_get_sdlk_audioplay);
	RING_API_REGISTER("sdl_get_sdlk_audioprev",ring_sdl_get_sdlk_audioprev);
	RING_API_REGISTER("sdl_get_sdlk_brightnessdown",ring_sdl_get_sdlk_brightnessdown);
	RING_API_REGISTER("sdl_get_sdlk_brightnessup",ring_sdl_get_sdlk_brightnessup);
	RING_API_REGISTER("sdl_get_sdlk_c",ring_sdl_get_sdlk_c);
	RING_API_REGISTER("sdl_get_sdlk_calculator",ring_sdl_get_sdlk_calculator);
	RING_API_REGISTER("sdl_get_sdlk_cancel",ring_sdl_get_sdlk_cancel);
	RING_API_REGISTER("sdl_get_sdlk_capslock",ring_sdl_get_sdlk_capslock);
	RING_API_REGISTER("sdl_get_sdlk_clear",ring_sdl_get_sdlk_clear);
	RING_API_REGISTER("sdl_get_sdlk_clearagain",ring_sdl_get_sdlk_clearagain);
	RING_API_REGISTER("sdl_get_sdlk_comma",ring_sdl_get_sdlk_comma);
	RING_API_REGISTER("sdl_get_sdlk_computer",ring_sdl_get_sdlk_computer);
	RING_API_REGISTER("sdl_get_sdlk_copy",ring_sdl_get_sdlk_copy);
	RING_API_REGISTER("sdl_get_sdlk_crsel",ring_sdl_get_sdlk_crsel);
	RING_API_REGISTER("sdl_get_sdlk_currencysubunit",ring_sdl_get_sdlk_currencysubunit);
	RING_API_REGISTER("sdl_get_sdlk_currencyunit",ring_sdl_get_sdlk_currencyunit);
	RING_API_REGISTER("sdl_get_sdlk_cut",ring_sdl_get_sdlk_cut);
	RING_API_REGISTER("sdl_get_sdlk_d",ring_sdl_get_sdlk_d);
	RING_API_REGISTER("sdl_get_sdlk_decimalseparator",ring_sdl_get_sdlk_decimalseparator);
	RING_API_REGISTER("sdl_get_sdlk_delete",ring_sdl_get_sdlk_delete);
	RING_API_REGISTER("sdl_get_sdlk_displayswitch",ring_sdl_get_sdlk_displayswitch);
	RING_API_REGISTER("sdl_get_sdlk_down",ring_sdl_get_sdlk_down);
	RING_API_REGISTER("sdl_get_sdlk_e",ring_sdl_get_sdlk_e);
	RING_API_REGISTER("sdl_get_sdlk_eject",ring_sdl_get_sdlk_eject);
	RING_API_REGISTER("sdl_get_sdlk_end",ring_sdl_get_sdlk_end);
	RING_API_REGISTER("sdl_get_sdlk_equals",ring_sdl_get_sdlk_equals);
	RING_API_REGISTER("sdl_get_sdlk_escape",ring_sdl_get_sdlk_escape);
	RING_API_REGISTER("sdl_get_sdlk_execute",ring_sdl_get_sdlk_execute);
	RING_API_REGISTER("sdl_get_sdlk_exsel",ring_sdl_get_sdlk_exsel);
	RING_API_REGISTER("sdl_get_sdlk_f",ring_sdl_get_sdlk_f);
	RING_API_REGISTER("sdl_get_sdlk_f1",ring_sdl_get_sdlk_f1);
	RING_API_REGISTER("sdl_get_sdlk_f10",ring_sdl_get_sdlk_f10);
	RING_API_REGISTER("sdl_get_sdlk_f11",ring_sdl_get_sdlk_f11);
	RING_API_REGISTER("sdl_get_sdlk_f12",ring_sdl_get_sdlk_f12);
	RING_API_REGISTER("sdl_get_sdlk_f13",ring_sdl_get_sdlk_f13);
	RING_API_REGISTER("sdl_get_sdlk_f14",ring_sdl_get_sdlk_f14);
	RING_API_REGISTER("sdl_get_sdlk_f15",ring_sdl_get_sdlk_f15);
	RING_API_REGISTER("sdl_get_sdlk_f16",ring_sdl_get_sdlk_f16);
	RING_API_REGISTER("sdl_get_sdlk_f17",ring_sdl_get_sdlk_f17);
	RING_API_REGISTER("sdl_get_sdlk_f18",ring_sdl_get_sdlk_f18);
	RING_API_REGISTER("sdl_get_sdlk_f19",ring_sdl_get_sdlk_f19);
	RING_API_REGISTER("sdl_get_sdlk_f2",ring_sdl_get_sdlk_f2);
	RING_API_REGISTER("sdl_get_sdlk_f20",ring_sdl_get_sdlk_f20);
	RING_API_REGISTER("sdl_get_sdlk_f21",ring_sdl_get_sdlk_f21);
	RING_API_REGISTER("sdl_get_sdlk_f22",ring_sdl_get_sdlk_f22);
	RING_API_REGISTER("sdl_get_sdlk_f23",ring_sdl_get_sdlk_f23);
	RING_API_REGISTER("sdl_get_sdlk_f24",ring_sdl_get_sdlk_f24);
	RING_API_REGISTER("sdl_get_sdlk_f3",ring_sdl_get_sdlk_f3);
	RING_API_REGISTER("sdl_get_sdlk_f4",ring_sdl_get_sdlk_f4);
	RING_API_REGISTER("sdl_get_sdlk_f5",ring_sdl_get_sdlk_f5);
	RING_API_REGISTER("sdl_get_sdlk_f6",ring_sdl_get_sdlk_f6);
	RING_API_REGISTER("sdl_get_sdlk_f7",ring_sdl_get_sdlk_f7);
	RING_API_REGISTER("sdl_get_sdlk_f8",ring_sdl_get_sdlk_f8);
	RING_API_REGISTER("sdl_get_sdlk_f9",ring_sdl_get_sdlk_f9);
	RING_API_REGISTER("sdl_get_sdlk_find",ring_sdl_get_sdlk_find);
	RING_API_REGISTER("sdl_get_sdlk_g",ring_sdl_get_sdlk_g);
	RING_API_REGISTER("sdl_get_sdlk_backquote",ring_sdl_get_sdlk_backquote);
	RING_API_REGISTER("sdl_get_sdlk_h",ring_sdl_get_sdlk_h);
	RING_API_REGISTER("sdl_get_sdlk_help",ring_sdl_get_sdlk_help);
	RING_API_REGISTER("sdl_get_sdlk_home",ring_sdl_get_sdlk_home);
	RING_API_REGISTER("sdl_get_sdlk_i",ring_sdl_get_sdlk_i);
	RING_API_REGISTER("sdl_get_sdlk_insert",ring_sdl_get_sdlk_insert);
	RING_API_REGISTER("sdl_get_sdlk_j",ring_sdl_get_sdlk_j);
	RING_API_REGISTER("sdl_get_sdlk_k",ring_sdl_get_sdlk_k);
	RING_API_REGISTER("sdl_get_sdlk_kbdillumdown",ring_sdl_get_sdlk_kbdillumdown);
	RING_API_REGISTER("sdl_get_sdlk_kbdillumtoggle",ring_sdl_get_sdlk_kbdillumtoggle);
	RING_API_REGISTER("sdl_get_sdlk_kbdillumup",ring_sdl_get_sdlk_kbdillumup);
	RING_API_REGISTER("sdl_get_sdlk_kp_0",ring_sdl_get_sdlk_kp_0);
	RING_API_REGISTER("sdl_get_sdlk_kp_00",ring_sdl_get_sdlk_kp_00);
	RING_API_REGISTER("sdl_get_sdlk_kp_000",ring_sdl_get_sdlk_kp_000);
	RING_API_REGISTER("sdl_get_sdlk_kp_1",ring_sdl_get_sdlk_kp_1);
	RING_API_REGISTER("sdl_get_sdlk_kp_2",ring_sdl_get_sdlk_kp_2);
	RING_API_REGISTER("sdl_get_sdlk_kp_3",ring_sdl_get_sdlk_kp_3);
	RING_API_REGISTER("sdl_get_sdlk_kp_4",ring_sdl_get_sdlk_kp_4);
	RING_API_REGISTER("sdl_get_sdlk_kp_5",ring_sdl_get_sdlk_kp_5);
	RING_API_REGISTER("sdl_get_sdlk_kp_6",ring_sdl_get_sdlk_kp_6);
	RING_API_REGISTER("sdl_get_sdlk_kp_7",ring_sdl_get_sdlk_kp_7);
	RING_API_REGISTER("sdl_get_sdlk_kp_8",ring_sdl_get_sdlk_kp_8);
	RING_API_REGISTER("sdl_get_sdlk_kp_9",ring_sdl_get_sdlk_kp_9);
	RING_API_REGISTER("sdl_get_sdlk_kp_a",ring_sdl_get_sdlk_kp_a);
	RING_API_REGISTER("sdl_get_sdlk_kp_ampersand",ring_sdl_get_sdlk_kp_ampersand);
	RING_API_REGISTER("sdl_get_sdlk_kp_at",ring_sdl_get_sdlk_kp_at);
	RING_API_REGISTER("sdl_get_sdlk_kp_b",ring_sdl_get_sdlk_kp_b);
	RING_API_REGISTER("sdl_get_sdlk_kp_backspace",ring_sdl_get_sdlk_kp_backspace);
	RING_API_REGISTER("sdl_get_sdlk_kp_binary",ring_sdl_get_sdlk_kp_binary);
	RING_API_REGISTER("sdl_get_sdlk_kp_c",ring_sdl_get_sdlk_kp_c);
	RING_API_REGISTER("sdl_get_sdlk_kp_clear",ring_sdl_get_sdlk_kp_clear);
	RING_API_REGISTER("sdl_get_sdlk_kp_clearentry",ring_sdl_get_sdlk_kp_clearentry);
	RING_API_REGISTER("sdl_get_sdlk_kp_colon",ring_sdl_get_sdlk_kp_colon);
	RING_API_REGISTER("sdl_get_sdlk_kp_comma",ring_sdl_get_sdlk_kp_comma);
	RING_API_REGISTER("sdl_get_sdlk_kp_d",ring_sdl_get_sdlk_kp_d);
	RING_API_REGISTER("sdl_get_sdlk_kp_dblampersand",ring_sdl_get_sdlk_kp_dblampersand);
	RING_API_REGISTER("sdl_get_sdlk_kp_dblverticalbar",ring_sdl_get_sdlk_kp_dblverticalbar);
	RING_API_REGISTER("sdl_get_sdlk_kp_decimal",ring_sdl_get_sdlk_kp_decimal);
	RING_API_REGISTER("sdl_get_sdlk_kp_divide",ring_sdl_get_sdlk_kp_divide);
	RING_API_REGISTER("sdl_get_sdlk_kp_e",ring_sdl_get_sdlk_kp_e);
	RING_API_REGISTER("sdl_get_sdlk_kp_enter",ring_sdl_get_sdlk_kp_enter);
	RING_API_REGISTER("sdl_get_sdlk_kp_equals",ring_sdl_get_sdlk_kp_equals);
	RING_API_REGISTER("sdl_get_sdlk_kp_equalsas400",ring_sdl_get_sdlk_kp_equalsas400);
	RING_API_REGISTER("sdl_get_sdlk_kp_exclam",ring_sdl_get_sdlk_kp_exclam);
	RING_API_REGISTER("sdl_get_sdlk_kp_f",ring_sdl_get_sdlk_kp_f);
	RING_API_REGISTER("sdl_get_sdlk_kp_greater",ring_sdl_get_sdlk_kp_greater);
	RING_API_REGISTER("sdl_get_sdlk_kp_hash",ring_sdl_get_sdlk_kp_hash);
	RING_API_REGISTER("sdl_get_sdlk_kp_hexadecimal",ring_sdl_get_sdlk_kp_hexadecimal);
	RING_API_REGISTER("sdl_get_sdlk_kp_leftbrace",ring_sdl_get_sdlk_kp_leftbrace);
	RING_API_REGISTER("sdl_get_sdlk_kp_leftparen",ring_sdl_get_sdlk_kp_leftparen);
	RING_API_REGISTER("sdl_get_sdlk_kp_less",ring_sdl_get_sdlk_kp_less);
	RING_API_REGISTER("sdl_get_sdlk_kp_memadd",ring_sdl_get_sdlk_kp_memadd);
	RING_API_REGISTER("sdl_get_sdlk_kp_memclear",ring_sdl_get_sdlk_kp_memclear);
	RING_API_REGISTER("sdl_get_sdlk_kp_memdivide",ring_sdl_get_sdlk_kp_memdivide);
	RING_API_REGISTER("sdl_get_sdlk_kp_memmultiply",ring_sdl_get_sdlk_kp_memmultiply);
	RING_API_REGISTER("sdl_get_sdlk_kp_memrecall",ring_sdl_get_sdlk_kp_memrecall);
	RING_API_REGISTER("sdl_get_sdlk_kp_memstore",ring_sdl_get_sdlk_kp_memstore);
	RING_API_REGISTER("sdl_get_sdlk_kp_memsubtract",ring_sdl_get_sdlk_kp_memsubtract);
	RING_API_REGISTER("sdl_get_sdlk_kp_minus",ring_sdl_get_sdlk_kp_minus);
	RING_API_REGISTER("sdl_get_sdlk_kp_multiply",ring_sdl_get_sdlk_kp_multiply);
	RING_API_REGISTER("sdl_get_sdlk_kp_octal",ring_sdl_get_sdlk_kp_octal);
	RING_API_REGISTER("sdl_get_sdlk_kp_percent",ring_sdl_get_sdlk_kp_percent);
	RING_API_REGISTER("sdl_get_sdlk_kp_period",ring_sdl_get_sdlk_kp_period);
	RING_API_REGISTER("sdl_get_sdlk_kp_plus",ring_sdl_get_sdlk_kp_plus);
	RING_API_REGISTER("sdl_get_sdlk_kp_plusminus",ring_sdl_get_sdlk_kp_plusminus);
	RING_API_REGISTER("sdl_get_sdlk_kp_power",ring_sdl_get_sdlk_kp_power);
	RING_API_REGISTER("sdl_get_sdlk_kp_rightbrace",ring_sdl_get_sdlk_kp_rightbrace);
	RING_API_REGISTER("sdl_get_sdlk_kp_rightparen",ring_sdl_get_sdlk_kp_rightparen);
	RING_API_REGISTER("sdl_get_sdlk_kp_space",ring_sdl_get_sdlk_kp_space);
	RING_API_REGISTER("sdl_get_sdlk_kp_tab",ring_sdl_get_sdlk_kp_tab);
	RING_API_REGISTER("sdl_get_sdlk_kp_verticalbar",ring_sdl_get_sdlk_kp_verticalbar);
	RING_API_REGISTER("sdl_get_sdlk_kp_xor",ring_sdl_get_sdlk_kp_xor);
	RING_API_REGISTER("sdl_get_sdlk_l",ring_sdl_get_sdlk_l);
	RING_API_REGISTER("sdl_get_sdlk_lalt",ring_sdl_get_sdlk_lalt);
	RING_API_REGISTER("sdl_get_sdlk_lctrl",ring_sdl_get_sdlk_lctrl);
	RING_API_REGISTER("sdl_get_sdlk_left",ring_sdl_get_sdlk_left);
	RING_API_REGISTER("sdl_get_sdlk_leftbracket",ring_sdl_get_sdlk_leftbracket);
	RING_API_REGISTER("sdl_get_sdlk_lgui",ring_sdl_get_sdlk_lgui);
	RING_API_REGISTER("sdl_get_sdlk_lshift",ring_sdl_get_sdlk_lshift);
	RING_API_REGISTER("sdl_get_sdlk_m",ring_sdl_get_sdlk_m);
	RING_API_REGISTER("sdl_get_sdlk_mail",ring_sdl_get_sdlk_mail);
	RING_API_REGISTER("sdl_get_sdlk_mediaselect",ring_sdl_get_sdlk_mediaselect);
	RING_API_REGISTER("sdl_get_sdlk_menu",ring_sdl_get_sdlk_menu);
	RING_API_REGISTER("sdl_get_sdlk_minus",ring_sdl_get_sdlk_minus);
	RING_API_REGISTER("sdl_get_sdlk_mode",ring_sdl_get_sdlk_mode);
	RING_API_REGISTER("sdl_get_sdlk_mute",ring_sdl_get_sdlk_mute);
	RING_API_REGISTER("sdl_get_sdlk_n",ring_sdl_get_sdlk_n);
	RING_API_REGISTER("sdl_get_sdlk_numlockclear",ring_sdl_get_sdlk_numlockclear);
	RING_API_REGISTER("sdl_get_sdlk_o",ring_sdl_get_sdlk_o);
	RING_API_REGISTER("sdl_get_sdlk_oper",ring_sdl_get_sdlk_oper);
	RING_API_REGISTER("sdl_get_sdlk_out",ring_sdl_get_sdlk_out);
	RING_API_REGISTER("sdl_get_sdlk_p",ring_sdl_get_sdlk_p);
	RING_API_REGISTER("sdl_get_sdlk_pagedown",ring_sdl_get_sdlk_pagedown);
	RING_API_REGISTER("sdl_get_sdlk_pageup",ring_sdl_get_sdlk_pageup);
	RING_API_REGISTER("sdl_get_sdlk_paste",ring_sdl_get_sdlk_paste);
	RING_API_REGISTER("sdl_get_sdlk_pause",ring_sdl_get_sdlk_pause);
	RING_API_REGISTER("sdl_get_sdlk_period",ring_sdl_get_sdlk_period);
	RING_API_REGISTER("sdl_get_sdlk_power",ring_sdl_get_sdlk_power);
	RING_API_REGISTER("sdl_get_sdlk_printscreen",ring_sdl_get_sdlk_printscreen);
	RING_API_REGISTER("sdl_get_sdlk_prior",ring_sdl_get_sdlk_prior);
	RING_API_REGISTER("sdl_get_sdlk_q",ring_sdl_get_sdlk_q);
	RING_API_REGISTER("sdl_get_sdlk_r",ring_sdl_get_sdlk_r);
	RING_API_REGISTER("sdl_get_sdlk_ralt",ring_sdl_get_sdlk_ralt);
	RING_API_REGISTER("sdl_get_sdlk_rctrl",ring_sdl_get_sdlk_rctrl);
	RING_API_REGISTER("sdl_get_sdlk_return",ring_sdl_get_sdlk_return);
	RING_API_REGISTER("sdl_get_sdlk_return2",ring_sdl_get_sdlk_return2);
	RING_API_REGISTER("sdl_get_sdlk_rgui",ring_sdl_get_sdlk_rgui);
	RING_API_REGISTER("sdl_get_sdlk_right",ring_sdl_get_sdlk_right);
	RING_API_REGISTER("sdl_get_sdlk_rightbracket",ring_sdl_get_sdlk_rightbracket);
	RING_API_REGISTER("sdl_get_sdlk_rshift",ring_sdl_get_sdlk_rshift);
	RING_API_REGISTER("sdl_get_sdlk_s",ring_sdl_get_sdlk_s);
	RING_API_REGISTER("sdl_get_sdlk_scrolllock",ring_sdl_get_sdlk_scrolllock);
	RING_API_REGISTER("sdl_get_sdlk_select",ring_sdl_get_sdlk_select);
	RING_API_REGISTER("sdl_get_sdlk_semicolon",ring_sdl_get_sdlk_semicolon);
	RING_API_REGISTER("sdl_get_sdlk_separator",ring_sdl_get_sdlk_separator);
	RING_API_REGISTER("sdl_get_sdlk_slash",ring_sdl_get_sdlk_slash);
	RING_API_REGISTER("sdl_get_sdlk_sleep",ring_sdl_get_sdlk_sleep);
	RING_API_REGISTER("sdl_get_sdlk_space",ring_sdl_get_sdlk_space);
	RING_API_REGISTER("sdl_get_sdlk_stop",ring_sdl_get_sdlk_stop);
	RING_API_REGISTER("sdl_get_sdlk_sysreq",ring_sdl_get_sdlk_sysreq);
	RING_API_REGISTER("sdl_get_sdlk_t",ring_sdl_get_sdlk_t);
	RING_API_REGISTER("sdl_get_sdlk_tab",ring_sdl_get_sdlk_tab);
	RING_API_REGISTER("sdl_get_sdlk_thousandsseparator",ring_sdl_get_sdlk_thousandsseparator);
	RING_API_REGISTER("sdl_get_sdlk_u",ring_sdl_get_sdlk_u);
	RING_API_REGISTER("sdl_get_sdlk_undo",ring_sdl_get_sdlk_undo);
	RING_API_REGISTER("sdl_get_sdlk_unknown",ring_sdl_get_sdlk_unknown);
	RING_API_REGISTER("sdl_get_sdlk_up",ring_sdl_get_sdlk_up);
	RING_API_REGISTER("sdl_get_sdlk_v",ring_sdl_get_sdlk_v);
	RING_API_REGISTER("sdl_get_sdlk_volumedown",ring_sdl_get_sdlk_volumedown);
	RING_API_REGISTER("sdl_get_sdlk_volumeup",ring_sdl_get_sdlk_volumeup);
	RING_API_REGISTER("sdl_get_sdlk_w",ring_sdl_get_sdlk_w);
	RING_API_REGISTER("sdl_get_sdlk_www",ring_sdl_get_sdlk_www);
	RING_API_REGISTER("sdl_get_sdlk_x",ring_sdl_get_sdlk_x);
	RING_API_REGISTER("sdl_get_sdlk_y",ring_sdl_get_sdlk_y);
	RING_API_REGISTER("sdl_get_sdlk_z",ring_sdl_get_sdlk_z);
	RING_API_REGISTER("sdl_get_sdlk_ampersand",ring_sdl_get_sdlk_ampersand);
	RING_API_REGISTER("sdl_get_sdlk_asterisk",ring_sdl_get_sdlk_asterisk);
	RING_API_REGISTER("sdl_get_sdlk_at",ring_sdl_get_sdlk_at);
	RING_API_REGISTER("sdl_get_sdlk_caret",ring_sdl_get_sdlk_caret);
	RING_API_REGISTER("sdl_get_sdlk_colon",ring_sdl_get_sdlk_colon);
	RING_API_REGISTER("sdl_get_sdlk_dollar",ring_sdl_get_sdlk_dollar);
	RING_API_REGISTER("sdl_get_sdlk_exclaim",ring_sdl_get_sdlk_exclaim);
	RING_API_REGISTER("sdl_get_sdlk_greater",ring_sdl_get_sdlk_greater);
	RING_API_REGISTER("sdl_get_sdlk_hash",ring_sdl_get_sdlk_hash);
	RING_API_REGISTER("sdl_get_sdlk_leftparen",ring_sdl_get_sdlk_leftparen);
	RING_API_REGISTER("sdl_get_sdlk_less",ring_sdl_get_sdlk_less);
	RING_API_REGISTER("sdl_get_sdlk_percent",ring_sdl_get_sdlk_percent);
	RING_API_REGISTER("sdl_get_sdlk_plus",ring_sdl_get_sdlk_plus);
	RING_API_REGISTER("sdl_get_sdlk_question",ring_sdl_get_sdlk_question);
	RING_API_REGISTER("sdl_get_sdlk_quotedbl",ring_sdl_get_sdlk_quotedbl);
	RING_API_REGISTER("sdl_get_sdlk_rightparen",ring_sdl_get_sdlk_rightparen);
	RING_API_REGISTER("sdl_get_sdlk_underscore",ring_sdl_get_sdlk_underscore);
	RING_API_REGISTER("sdl_get_sdl_thread_priority_low",ring_sdl_get_sdl_thread_priority_low);
	RING_API_REGISTER("sdl_get_sdl_thread_priority_normal",ring_sdl_get_sdl_thread_priority_normal);
	RING_API_REGISTER("sdl_get_sdl_thread_priority_high",ring_sdl_get_sdl_thread_priority_high);
}

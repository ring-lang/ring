#include "ring.h"

#ifdef _WIN32
#define RING_DLL __declspec(dllexport)
#else
#define RING_DLL extern
#endif

/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "SDL.h"
#include "SDL_syswm.h"
RING_FUNC(ring_sdl_new_sdl_assert_data)
{
	SDL_assert_data *pMyPointer ;
	pMyPointer = (SDL_assert_data *) malloc(sizeof(SDL_assert_data)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_assert_data");
}

RING_FUNC(ring_sdl_destroy_sdl_assert_data)
{
	SDL_assert_data *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_assert_data");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_version)
{
	SDL_version *pMyPointer ;
	pMyPointer = (SDL_version *) malloc(sizeof(SDL_version)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_version");
}

RING_FUNC(ring_sdl_destroy_sdl_version)
{
	SDL_version *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_version");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_get_sdl_version_major)
{
	SDL_version *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	pMyPointer = (SDL_DisplayMode *) malloc(sizeof(SDL_DisplayMode)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_DisplayMode");
}

RING_FUNC(ring_sdl_destroy_sdl_displaymode)
{
	SDL_DisplayMode *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_DisplayMode");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_messageboxbuttondata)
{
	SDL_MessageBoxButtonData *pMyPointer ;
	pMyPointer = (SDL_MessageBoxButtonData *) malloc(sizeof(SDL_MessageBoxButtonData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxButtonData");
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxbuttondata)
{
	SDL_MessageBoxButtonData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MessageBoxButtonData");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_messageboxcolor)
{
	SDL_MessageBoxColor *pMyPointer ;
	pMyPointer = (SDL_MessageBoxColor *) malloc(sizeof(SDL_MessageBoxColor)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxColor");
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxcolor)
{
	SDL_MessageBoxColor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MessageBoxColor");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_messageboxcolorscheme)
{
	SDL_MessageBoxColorScheme *pMyPointer ;
	pMyPointer = (SDL_MessageBoxColorScheme *) malloc(sizeof(SDL_MessageBoxColorScheme)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxColorScheme");
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxcolorscheme)
{
	SDL_MessageBoxColorScheme *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MessageBoxColorScheme");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_messageboxdata)
{
	SDL_MessageBoxData *pMyPointer ;
	pMyPointer = (SDL_MessageBoxData *) malloc(sizeof(SDL_MessageBoxData)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_MessageBoxData");
}

RING_FUNC(ring_sdl_destroy_sdl_messageboxdata)
{
	SDL_MessageBoxData *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_MessageBoxData");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_windowevent)
{
	SDL_WindowEvent *pMyPointer ;
	pMyPointer = (SDL_WindowEvent *) malloc(sizeof(SDL_WindowEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_WindowEvent");
}

RING_FUNC(ring_sdl_destroy_sdl_windowevent)
{
	SDL_WindowEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_WindowEvent");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_rendererinfo)
{
	SDL_RendererInfo *pMyPointer ;
	pMyPointer = (SDL_RendererInfo *) malloc(sizeof(SDL_RendererInfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_RendererInfo");
}

RING_FUNC(ring_sdl_destroy_sdl_rendererinfo)
{
	SDL_RendererInfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_RendererInfo");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_color)
{
	SDL_Color *pMyPointer ;
	pMyPointer = (SDL_Color *) malloc(sizeof(SDL_Color)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Color");
}

RING_FUNC(ring_sdl_destroy_sdl_color)
{
	SDL_Color *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Color");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_palette)
{
	SDL_Palette *pMyPointer ;
	pMyPointer = (SDL_Palette *) malloc(sizeof(SDL_Palette)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Palette");
}

RING_FUNC(ring_sdl_destroy_sdl_palette)
{
	SDL_Palette *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Palette");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_pixelformat)
{
	SDL_PixelFormat *pMyPointer ;
	pMyPointer = (SDL_PixelFormat *) malloc(sizeof(SDL_PixelFormat)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_PixelFormat");
}

RING_FUNC(ring_sdl_destroy_sdl_pixelformat)
{
	SDL_PixelFormat *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_PixelFormat");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_point)
{
	SDL_Point *pMyPointer ;
	pMyPointer = (SDL_Point *) malloc(sizeof(SDL_Point)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Point");
}

RING_FUNC(ring_sdl_destroy_sdl_point)
{
	SDL_Point *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Point");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_get_sdl_point_x)
{
	SDL_Point *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	pMyPointer = (SDL_Rect *) malloc(sizeof(SDL_Rect)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Rect");
}

RING_FUNC(ring_sdl_destroy_sdl_rect)
{
	SDL_Rect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Rect");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_get_sdl_rect_x)
{
	SDL_Rect *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	pMyPointer = (SDL_Surface *) malloc(sizeof(SDL_Surface)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_Surface");
}

RING_FUNC(ring_sdl_destroy_sdl_surface)
{
	SDL_Surface *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_Surface");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_syswminfo)
{
	SDL_SysWMinfo *pMyPointer ;
	pMyPointer = (SDL_SysWMinfo *) malloc(sizeof(SDL_SysWMinfo)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_SysWMinfo");
}

RING_FUNC(ring_sdl_destroy_sdl_syswminfo)
{
	SDL_SysWMinfo *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_SysWMinfo");
	free(pMyPointer) ;
}

RING_FUNC(ring_sdl_new_sdl_syswmmsg)
{
	SDL_SysWMmsg *pMyPointer ;
	pMyPointer = (SDL_SysWMmsg *) malloc(sizeof(SDL_SysWMmsg)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"SDL_SysWMmsg");
}

RING_FUNC(ring_sdl_destroy_sdl_syswmmsg)
{
	SDL_SysWMmsg *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"SDL_SysWMmsg");
	free(pMyPointer) ;
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(SDL_GetHint((char *) RING_API_GETCPOINTER(1,"char")));
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


RING_FUNC(ring_SDL_SetError)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_SetError(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_SDL_Log)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_Log(RING_API_GETSTRING(1));
}


RING_FUNC(ring_SDL_LogCritical)
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
	SDL_LogCritical( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_SDL_LogDebug)
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
	SDL_LogDebug( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_SDL_LogError)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_LogError( (int ) RING_API_GETNUMBER(1),(char *) RING_API_GETCPOINTER(2,"char"));
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


RING_FUNC(ring_SDL_LogInfo)
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
	SDL_LogInfo( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_SDL_LogMessage)
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
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_LogMessage( (int ) RING_API_GETNUMBER(1), (SDL_LogPriority )  (int) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
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


RING_FUNC(ring_SDL_LogVerbose)
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
	SDL_LogVerbose( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_SDL_LogWarn)
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
	SDL_LogWarn( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
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
		pValue = (SDL_AssertionHandler *) malloc(sizeof(SDL_AssertionHandler)) ;
		*pValue = SDL_GetDefaultAssertionHandler();
		RING_API_RETCPOINTER(pValue,"SDL_AssertionHandler");
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
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SDL_SetAssertionHandler(* (SDL_AssertionHandler  *) RING_API_GETCPOINTER(1,"SDL_AssertionHandler"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		free(RING_API_GETCPOINTER(1,"SDL_AssertionHandler"));
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
	RING_API_RETCPOINTER(SDL_GetRevision(),"char");
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	RING_API_RETCPOINTER(SDL_CreateWindow((char *) RING_API_GETCPOINTER(1,"char"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (Uint32 ) RING_API_GETNUMBER(6)),"SDL_Window");
}


RING_FUNC(ring_SDL_CreateWindowFrom)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		SDL_GLContext *pValue ; 
		pValue = (SDL_GLContext *) malloc(sizeof(SDL_GLContext)) ;
		*pValue = SDL_GL_CreateContext((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"));
		RING_API_RETCPOINTER(pValue,"SDL_GLContext");
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
		free(RING_API_GETCPOINTER(1,"SDL_GLContext"));
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
		pValue = (SDL_GLContext *) malloc(sizeof(SDL_GLContext)) ;
		*pValue = SDL_GL_GetCurrentContext();
		RING_API_RETCPOINTER(pValue,"SDL_GLContext");
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_GL_MakeCurrent((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"),* (SDL_GLContext  *) RING_API_GETCPOINTER(2,"SDL_GLContext")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		free(RING_API_GETCPOINTER(2,"SDL_GLContext"));
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
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
	RING_API_RETCPOINTER(SDL_GetVideoDriver( (int ) RING_API_GETNUMBER(1)),"char");
}


RING_FUNC(ring_SDL_GetWindowBrightness)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_LockTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(SDL_Rect *) RING_API_GETCPOINTER(2,"SDL_Rect"),(void *) RING_API_GETCPOINTER(3,"void"),RING_API_GETINTPOINTER(4)));
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_SDL_QueryTexture)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETNUMBER(SDL_QueryTexture((SDL_Texture *) RING_API_GETCPOINTER(1,"SDL_Texture"),(Uint32 *) RING_API_GETCPOINTER(2,"Uint32"),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4),RING_API_GETINTPOINTER(5)));
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(SDL_RenderCopyEx((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Texture *) RING_API_GETCPOINTER(2,"SDL_Texture"),(SDL_Rect *) RING_API_GETCPOINTER(3,"SDL_Rect"),(SDL_Rect *) RING_API_GETCPOINTER(4,"SDL_Rect"),* (const double  *) RING_API_GETCPOINTER(5,"const double"),(SDL_Point *) RING_API_GETCPOINTER(6,"SDL_Point"),* (const SDL_RendererFlip  *) RING_API_GETCPOINTER(7,"const SDL_RendererFlip")));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		free(RING_API_GETCPOINTER(5,"double"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		free(RING_API_GETCPOINTER(7,"SDL_RendererFlip"));
}


RING_FUNC(ring_SDL_RenderDrawLine)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(7) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
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
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(6) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(6) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(7) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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

RING_DLL void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("sdl_rendercopy2",ring_SDL_RenderCopy2);
	ring_vm_funcregister("sdl_delay",ring_SDL_Delay);
	ring_vm_funcregister("sdl_init",ring_SDL_Init);
	ring_vm_funcregister("sdl_initsubsystem",ring_SDL_InitSubSystem);
	ring_vm_funcregister("sdl_quit",ring_SDL_Quit);
	ring_vm_funcregister("sdl_quitsubsystem",ring_SDL_QuitSubSystem);
	ring_vm_funcregister("sdl_setmainready",ring_SDL_SetMainReady);
	ring_vm_funcregister("sdl_wasinit",ring_SDL_WasInit);
	ring_vm_funcregister("sdl_clearhints",ring_SDL_ClearHints);
	ring_vm_funcregister("sdl_gethint",ring_SDL_GetHint);
	ring_vm_funcregister("sdl_sethint",ring_SDL_SetHint);
	ring_vm_funcregister("sdl_sethintwithpriority",ring_SDL_SetHintWithPriority);
	ring_vm_funcregister("sdl_clearerror",ring_SDL_ClearError);
	ring_vm_funcregister("sdl_geterror",ring_SDL_GetError);
	ring_vm_funcregister("sdl_seterror",ring_SDL_SetError);
	ring_vm_funcregister("sdl_log",ring_SDL_Log);
	ring_vm_funcregister("sdl_logcritical",ring_SDL_LogCritical);
	ring_vm_funcregister("sdl_logdebug",ring_SDL_LogDebug);
	ring_vm_funcregister("sdl_logerror",ring_SDL_LogError);
	ring_vm_funcregister("sdl_loggetpriority",ring_SDL_LogGetPriority);
	ring_vm_funcregister("sdl_loginfo",ring_SDL_LogInfo);
	ring_vm_funcregister("sdl_logmessage",ring_SDL_LogMessage);
	ring_vm_funcregister("sdl_logresetpriorities",ring_SDL_LogResetPriorities);
	ring_vm_funcregister("sdl_logsetallpriority",ring_SDL_LogSetAllPriority);
	ring_vm_funcregister("sdl_logsetpriority",ring_SDL_LogSetPriority);
	ring_vm_funcregister("sdl_logverbose",ring_SDL_LogVerbose);
	ring_vm_funcregister("sdl_logwarn",ring_SDL_LogWarn);
	ring_vm_funcregister("sdl_getassertionreport",ring_SDL_GetAssertionReport);
	ring_vm_funcregister("sdl_getdefaultassertionhandler",ring_SDL_GetDefaultAssertionHandler);
	ring_vm_funcregister("sdl_resetassertionreport",ring_SDL_ResetAssertionReport);
	ring_vm_funcregister("sdl_setassertionhandler",ring_SDL_SetAssertionHandler);
	ring_vm_funcregister("sdl_triggerbreakpoint",ring_SDL_TriggerBreakpoint);
	ring_vm_funcregister("sdl_assert",ring_SDL_assert);
	ring_vm_funcregister("sdl_assert_paranoid",ring_SDL_assert_paranoid);
	ring_vm_funcregister("sdl_assert_release",ring_SDL_assert_release);
	ring_vm_funcregister("sdl_getrevision",ring_SDL_GetRevision);
	ring_vm_funcregister("sdl_getrevisionnumber",ring_SDL_GetRevisionNumber);
	ring_vm_funcregister("sdl_getversion",ring_SDL_GetVersion);
	ring_vm_funcregister("sdl_createwindow",ring_SDL_CreateWindow);
	ring_vm_funcregister("sdl_createwindowfrom",ring_SDL_CreateWindowFrom);
	ring_vm_funcregister("sdl_destroywindow",ring_SDL_DestroyWindow);
	ring_vm_funcregister("sdl_disablescreensaver",ring_SDL_DisableScreenSaver);
	ring_vm_funcregister("sdl_enablescreensaver",ring_SDL_EnableScreenSaver);
	ring_vm_funcregister("sdl_gl_createcontext",ring_SDL_GL_CreateContext);
	ring_vm_funcregister("sdl_gl_deletecontext",ring_SDL_GL_DeleteContext);
	ring_vm_funcregister("sdl_gl_extensionsupported",ring_SDL_GL_ExtensionSupported);
	ring_vm_funcregister("sdl_gl_getattribute",ring_SDL_GL_GetAttribute);
	ring_vm_funcregister("sdl_gl_getcurrentcontext",ring_SDL_GL_GetCurrentContext);
	ring_vm_funcregister("sdl_gl_getcurrentwindow",ring_SDL_GL_GetCurrentWindow);
	ring_vm_funcregister("sdl_gl_getdrawablesize",ring_SDL_GL_GetDrawableSize);
	ring_vm_funcregister("sdl_gl_getprocaddress",ring_SDL_GL_GetProcAddress);
	ring_vm_funcregister("sdl_gl_getswapinterval",ring_SDL_GL_GetSwapInterval);
	ring_vm_funcregister("sdl_gl_loadlibrary",ring_SDL_GL_LoadLibrary);
	ring_vm_funcregister("sdl_gl_makecurrent",ring_SDL_GL_MakeCurrent);
	ring_vm_funcregister("sdl_gl_resetattributes",ring_SDL_GL_ResetAttributes);
	ring_vm_funcregister("sdl_gl_setattribute",ring_SDL_GL_SetAttribute);
	ring_vm_funcregister("sdl_gl_setswapinterval",ring_SDL_GL_SetSwapInterval);
	ring_vm_funcregister("sdl_gl_swapwindow",ring_SDL_GL_SwapWindow);
	ring_vm_funcregister("sdl_gl_unloadlibrary",ring_SDL_GL_UnloadLibrary);
	ring_vm_funcregister("sdl_getclosestdisplaymode",ring_SDL_GetClosestDisplayMode);
	ring_vm_funcregister("sdl_getcurrentdisplaymode",ring_SDL_GetCurrentDisplayMode);
	ring_vm_funcregister("sdl_getcurrentvideodriver",ring_SDL_GetCurrentVideoDriver);
	ring_vm_funcregister("sdl_getdesktopdisplaymode",ring_SDL_GetDesktopDisplayMode);
	ring_vm_funcregister("sdl_getdisplaybounds",ring_SDL_GetDisplayBounds);
	ring_vm_funcregister("sdl_getnumdisplaymodes",ring_SDL_GetNumDisplayModes);
	ring_vm_funcregister("sdl_getnumvideodisplays",ring_SDL_GetNumVideoDisplays);
	ring_vm_funcregister("sdl_getnumvideodrivers",ring_SDL_GetNumVideoDrivers);
	ring_vm_funcregister("sdl_getvideodriver",ring_SDL_GetVideoDriver);
	ring_vm_funcregister("sdl_getwindowbrightness",ring_SDL_GetWindowBrightness);
	ring_vm_funcregister("sdl_getwindowdata",ring_SDL_GetWindowData);
	ring_vm_funcregister("sdl_getwindowdisplayindex",ring_SDL_GetWindowDisplayIndex);
	ring_vm_funcregister("sdl_getwindowdisplaymode",ring_SDL_GetWindowDisplayMode);
	ring_vm_funcregister("sdl_getwindowflags",ring_SDL_GetWindowFlags);
	ring_vm_funcregister("sdl_getwindowfromid",ring_SDL_GetWindowFromID);
	ring_vm_funcregister("sdl_getwindowgammaramp",ring_SDL_GetWindowGammaRamp);
	ring_vm_funcregister("sdl_getwindowgrab",ring_SDL_GetWindowGrab);
	ring_vm_funcregister("sdl_getwindowid",ring_SDL_GetWindowID);
	ring_vm_funcregister("sdl_getwindowmaximumsize",ring_SDL_GetWindowMaximumSize);
	ring_vm_funcregister("sdl_getwindowminimumsize",ring_SDL_GetWindowMinimumSize);
	ring_vm_funcregister("sdl_getwindowpixelformat",ring_SDL_GetWindowPixelFormat);
	ring_vm_funcregister("sdl_getwindowposition",ring_SDL_GetWindowPosition);
	ring_vm_funcregister("sdl_getwindowsize",ring_SDL_GetWindowSize);
	ring_vm_funcregister("sdl_getwindowsurface",ring_SDL_GetWindowSurface);
	ring_vm_funcregister("sdl_getwindowtitle",ring_SDL_GetWindowTitle);
	ring_vm_funcregister("sdl_hidewindow",ring_SDL_HideWindow);
	ring_vm_funcregister("sdl_isscreensaverenabled",ring_SDL_IsScreenSaverEnabled);
	ring_vm_funcregister("sdl_maximizewindow",ring_SDL_MaximizeWindow);
	ring_vm_funcregister("sdl_minimizewindow",ring_SDL_MinimizeWindow);
	ring_vm_funcregister("sdl_raisewindow",ring_SDL_RaiseWindow);
	ring_vm_funcregister("sdl_restorewindow",ring_SDL_RestoreWindow);
	ring_vm_funcregister("sdl_setwindowbordered",ring_SDL_SetWindowBordered);
	ring_vm_funcregister("sdl_setwindowbrightness",ring_SDL_SetWindowBrightness);
	ring_vm_funcregister("sdl_setwindowdata",ring_SDL_SetWindowData);
	ring_vm_funcregister("sdl_setwindowdisplaymode",ring_SDL_SetWindowDisplayMode);
	ring_vm_funcregister("sdl_setwindowfullscreen",ring_SDL_SetWindowFullscreen);
	ring_vm_funcregister("sdl_setwindowgammaramp",ring_SDL_SetWindowGammaRamp);
	ring_vm_funcregister("sdl_setwindowgrab",ring_SDL_SetWindowGrab);
	ring_vm_funcregister("sdl_setwindowicon",ring_SDL_SetWindowIcon);
	ring_vm_funcregister("sdl_setwindowmaximumsize",ring_SDL_SetWindowMaximumSize);
	ring_vm_funcregister("sdl_setwindowminimumsize",ring_SDL_SetWindowMinimumSize);
	ring_vm_funcregister("sdl_setwindowposition",ring_SDL_SetWindowPosition);
	ring_vm_funcregister("sdl_setwindowsize",ring_SDL_SetWindowSize);
	ring_vm_funcregister("sdl_setwindowtitle",ring_SDL_SetWindowTitle);
	ring_vm_funcregister("sdl_showmessagebox",ring_SDL_ShowMessageBox);
	ring_vm_funcregister("sdl_showsimplemessagebox",ring_SDL_ShowSimpleMessageBox);
	ring_vm_funcregister("sdl_showwindow",ring_SDL_ShowWindow);
	ring_vm_funcregister("sdl_updatewindowsurface",ring_SDL_UpdateWindowSurface);
	ring_vm_funcregister("sdl_updatewindowsurfacerects",ring_SDL_UpdateWindowSurfaceRects);
	ring_vm_funcregister("sdl_videoinit",ring_SDL_VideoInit);
	ring_vm_funcregister("sdl_videoquit",ring_SDL_VideoQuit);
	ring_vm_funcregister("sdl_createrenderer",ring_SDL_CreateRenderer);
	ring_vm_funcregister("sdl_createsoftwarerenderer",ring_SDL_CreateSoftwareRenderer);
	ring_vm_funcregister("sdl_createtexture",ring_SDL_CreateTexture);
	ring_vm_funcregister("sdl_createtexturefromsurface",ring_SDL_CreateTextureFromSurface);
	ring_vm_funcregister("sdl_destroyrenderer",ring_SDL_DestroyRenderer);
	ring_vm_funcregister("sdl_destroytexture",ring_SDL_DestroyTexture);
	ring_vm_funcregister("sdl_gl_bindtexture",ring_SDL_GL_BindTexture);
	ring_vm_funcregister("sdl_gl_unbindtexture",ring_SDL_GL_UnbindTexture);
	ring_vm_funcregister("sdl_getnumrenderdrivers",ring_SDL_GetNumRenderDrivers);
	ring_vm_funcregister("sdl_getrenderdrawblendmode",ring_SDL_GetRenderDrawBlendMode);
	ring_vm_funcregister("sdl_getrenderdrawcolor",ring_SDL_GetRenderDrawColor);
	ring_vm_funcregister("sdl_getrenderdriverinfo",ring_SDL_GetRenderDriverInfo);
	ring_vm_funcregister("sdl_getrendertarget",ring_SDL_GetRenderTarget);
	ring_vm_funcregister("sdl_getrenderer",ring_SDL_GetRenderer);
	ring_vm_funcregister("sdl_getrendererinfo",ring_SDL_GetRendererInfo);
	ring_vm_funcregister("sdl_getrendereroutputsize",ring_SDL_GetRendererOutputSize);
	ring_vm_funcregister("sdl_gettexturealphamod",ring_SDL_GetTextureAlphaMod);
	ring_vm_funcregister("sdl_gettextureblendmode",ring_SDL_GetTextureBlendMode);
	ring_vm_funcregister("sdl_gettexturecolormod",ring_SDL_GetTextureColorMod);
	ring_vm_funcregister("sdl_locktexture",ring_SDL_LockTexture);
	ring_vm_funcregister("sdl_querytexture",ring_SDL_QueryTexture);
	ring_vm_funcregister("sdl_renderclear",ring_SDL_RenderClear);
	ring_vm_funcregister("sdl_rendercopy",ring_SDL_RenderCopy);
	ring_vm_funcregister("sdl_rendercopyex",ring_SDL_RenderCopyEx);
	ring_vm_funcregister("sdl_renderdrawline",ring_SDL_RenderDrawLine);
	ring_vm_funcregister("sdl_renderdrawlines",ring_SDL_RenderDrawLines);
	ring_vm_funcregister("sdl_renderdrawpoint",ring_SDL_RenderDrawPoint);
	ring_vm_funcregister("sdl_renderdrawpoints",ring_SDL_RenderDrawPoints);
	ring_vm_funcregister("sdl_renderdrawrect",ring_SDL_RenderDrawRect);
	ring_vm_funcregister("sdl_renderdrawrects",ring_SDL_RenderDrawRects);
	ring_vm_funcregister("sdl_renderfillrect",ring_SDL_RenderFillRect);
	ring_vm_funcregister("sdl_renderfillrects",ring_SDL_RenderFillRects);
	ring_vm_funcregister("sdl_rendergetcliprect",ring_SDL_RenderGetClipRect);
	ring_vm_funcregister("sdl_rendergetlogicalsize",ring_SDL_RenderGetLogicalSize);
	ring_vm_funcregister("sdl_rendergetscale",ring_SDL_RenderGetScale);
	ring_vm_funcregister("sdl_rendergetviewport",ring_SDL_RenderGetViewport);
	ring_vm_funcregister("sdl_renderpresent",ring_SDL_RenderPresent);
	ring_vm_funcregister("sdl_renderreadpixels",ring_SDL_RenderReadPixels);
	ring_vm_funcregister("sdl_rendersetcliprect",ring_SDL_RenderSetClipRect);
	ring_vm_funcregister("sdl_rendersetlogicalsize",ring_SDL_RenderSetLogicalSize);
	ring_vm_funcregister("sdl_rendersetscale",ring_SDL_RenderSetScale);
	ring_vm_funcregister("sdl_rendersetviewport",ring_SDL_RenderSetViewport);
	ring_vm_funcregister("sdl_rendertargetsupported",ring_SDL_RenderTargetSupported);
	ring_vm_funcregister("sdl_setrenderdrawblendmode",ring_SDL_SetRenderDrawBlendMode);
	ring_vm_funcregister("sdl_setrenderdrawcolor",ring_SDL_SetRenderDrawColor);
	ring_vm_funcregister("sdl_setrendertarget",ring_SDL_SetRenderTarget);
	ring_vm_funcregister("sdl_settexturealphamod",ring_SDL_SetTextureAlphaMod);
	ring_vm_funcregister("sdl_settextureblendmode",ring_SDL_SetTextureBlendMode);
	ring_vm_funcregister("sdl_settexturecolormod",ring_SDL_SetTextureColorMod);
	ring_vm_funcregister("sdl_unlocktexture",ring_SDL_UnlockTexture);
	ring_vm_funcregister("sdl_updatetexture",ring_SDL_UpdateTexture);
	ring_vm_funcregister("sdl_updateyuvtexture",ring_SDL_UpdateYUVTexture);
	ring_vm_funcregister("sdl_allocformat",ring_SDL_AllocFormat);
	ring_vm_funcregister("sdl_allocpalette",ring_SDL_AllocPalette);
	ring_vm_funcregister("sdl_calculategammaramp",ring_SDL_CalculateGammaRamp);
	ring_vm_funcregister("sdl_freeformat",ring_SDL_FreeFormat);
	ring_vm_funcregister("sdl_freepalette",ring_SDL_FreePalette);
	ring_vm_funcregister("sdl_getpixelformatname",ring_SDL_GetPixelFormatName);
	ring_vm_funcregister("sdl_getrgb",ring_SDL_GetRGB);
	ring_vm_funcregister("sdl_getrgba",ring_SDL_GetRGBA);
	ring_vm_funcregister("sdl_maprgb",ring_SDL_MapRGB);
	ring_vm_funcregister("sdl_maprgba",ring_SDL_MapRGBA);
	ring_vm_funcregister("sdl_maskstopixelformatenum",ring_SDL_MasksToPixelFormatEnum);
	ring_vm_funcregister("sdl_pixelformatenumtomasks",ring_SDL_PixelFormatEnumToMasks);
	ring_vm_funcregister("sdl_setpalettecolors",ring_SDL_SetPaletteColors);
	ring_vm_funcregister("sdl_setpixelformatpalette",ring_SDL_SetPixelFormatPalette);
	ring_vm_funcregister("sdl_enclosepoints",ring_SDL_EnclosePoints);
	ring_vm_funcregister("sdl_hasintersection",ring_SDL_HasIntersection);
	ring_vm_funcregister("sdl_intersectrect",ring_SDL_IntersectRect);
	ring_vm_funcregister("sdl_intersectrectandline",ring_SDL_IntersectRectAndLine);
	ring_vm_funcregister("sdl_rectempty",ring_SDL_RectEmpty);
	ring_vm_funcregister("sdl_rectequals",ring_SDL_RectEquals);
	ring_vm_funcregister("sdl_unionrect",ring_SDL_UnionRect);
	ring_vm_funcregister("sdl_blitscaled",ring_SDL_BlitScaled);
	ring_vm_funcregister("sdl_blitsurface",ring_SDL_BlitSurface);
	ring_vm_funcregister("sdl_convertpixels",ring_SDL_ConvertPixels);
	ring_vm_funcregister("sdl_convertsurface",ring_SDL_ConvertSurface);
	ring_vm_funcregister("sdl_convertsurfaceformat",ring_SDL_ConvertSurfaceFormat);
	ring_vm_funcregister("sdl_creatergbsurface",ring_SDL_CreateRGBSurface);
	ring_vm_funcregister("sdl_creatergbsurfacefrom",ring_SDL_CreateRGBSurfaceFrom);
	ring_vm_funcregister("sdl_fillrect",ring_SDL_FillRect);
	ring_vm_funcregister("sdl_fillrects",ring_SDL_FillRects);
	ring_vm_funcregister("sdl_freesurface",ring_SDL_FreeSurface);
	ring_vm_funcregister("sdl_getcliprect",ring_SDL_GetClipRect);
	ring_vm_funcregister("sdl_getcolorkey",ring_SDL_GetColorKey);
	ring_vm_funcregister("sdl_getsurfacealphamod",ring_SDL_GetSurfaceAlphaMod);
	ring_vm_funcregister("sdl_getsurfaceblendmode",ring_SDL_GetSurfaceBlendMode);
	ring_vm_funcregister("sdl_getsurfacecolormod",ring_SDL_GetSurfaceColorMod);
	ring_vm_funcregister("sdl_loadbmp",ring_SDL_LoadBMP);
	ring_vm_funcregister("sdl_loadbmp_rw",ring_SDL_LoadBMP_RW);
	ring_vm_funcregister("sdl_locksurface",ring_SDL_LockSurface);
	ring_vm_funcregister("sdl_lowerblit",ring_SDL_LowerBlit);
	ring_vm_funcregister("sdl_lowerblitscaled",ring_SDL_LowerBlitScaled);
	ring_vm_funcregister("sdl_mustlock",ring_SDL_MUSTLOCK);
	ring_vm_funcregister("sdl_savebmp",ring_SDL_SaveBMP);
	ring_vm_funcregister("sdl_savebmp_rw",ring_SDL_SaveBMP_RW);
	ring_vm_funcregister("sdl_setcliprect",ring_SDL_SetClipRect);
	ring_vm_funcregister("sdl_setcolorkey",ring_SDL_SetColorKey);
	ring_vm_funcregister("sdl_setsurfacealphamod",ring_SDL_SetSurfaceAlphaMod);
	ring_vm_funcregister("sdl_setsurfaceblendmode",ring_SDL_SetSurfaceBlendMode);
	ring_vm_funcregister("sdl_setsurfacecolormod",ring_SDL_SetSurfaceColorMod);
	ring_vm_funcregister("sdl_setsurfacepalette",ring_SDL_SetSurfacePalette);
	ring_vm_funcregister("sdl_setsurfacerle",ring_SDL_SetSurfaceRLE);
	ring_vm_funcregister("sdl_unlocksurface",ring_SDL_UnlockSurface);
	ring_vm_funcregister("sdl_getwindowwminfo",ring_SDL_GetWindowWMInfo);
	ring_vm_funcregister("sdl_getclipboardtext",ring_SDL_GetClipboardText);
	ring_vm_funcregister("sdl_hasclipboardtext",ring_SDL_HasClipboardText);
	ring_vm_funcregister("sdl_setclipboardtext",ring_SDL_SetClipboardText);
	ring_vm_funcregister("sdl_new_sdl_assert_data",ring_sdl_new_sdl_assert_data);
	ring_vm_funcregister("sdl_destroy_sdl_assert_data",ring_sdl_destroy_sdl_assert_data);
	ring_vm_funcregister("sdl_new_sdl_version",ring_sdl_new_sdl_version);
	ring_vm_funcregister("sdl_destroy_sdl_version",ring_sdl_destroy_sdl_version);
	ring_vm_funcregister("sdl_get_sdl_version_major",ring_sdl_get_sdl_version_major);
	ring_vm_funcregister("sdl_set_sdl_version_major",ring_sdl_set_sdl_version_major);
	ring_vm_funcregister("sdl_get_sdl_version_minor",ring_sdl_get_sdl_version_minor);
	ring_vm_funcregister("sdl_set_sdl_version_minor",ring_sdl_set_sdl_version_minor);
	ring_vm_funcregister("sdl_get_sdl_version_patch",ring_sdl_get_sdl_version_patch);
	ring_vm_funcregister("sdl_set_sdl_version_patch",ring_sdl_set_sdl_version_patch);
	ring_vm_funcregister("sdl_new_sdl_displaymode",ring_sdl_new_sdl_displaymode);
	ring_vm_funcregister("sdl_destroy_sdl_displaymode",ring_sdl_destroy_sdl_displaymode);
	ring_vm_funcregister("sdl_new_sdl_messageboxbuttondata",ring_sdl_new_sdl_messageboxbuttondata);
	ring_vm_funcregister("sdl_destroy_sdl_messageboxbuttondata",ring_sdl_destroy_sdl_messageboxbuttondata);
	ring_vm_funcregister("sdl_new_sdl_messageboxcolor",ring_sdl_new_sdl_messageboxcolor);
	ring_vm_funcregister("sdl_destroy_sdl_messageboxcolor",ring_sdl_destroy_sdl_messageboxcolor);
	ring_vm_funcregister("sdl_new_sdl_messageboxcolorscheme",ring_sdl_new_sdl_messageboxcolorscheme);
	ring_vm_funcregister("sdl_destroy_sdl_messageboxcolorscheme",ring_sdl_destroy_sdl_messageboxcolorscheme);
	ring_vm_funcregister("sdl_new_sdl_messageboxdata",ring_sdl_new_sdl_messageboxdata);
	ring_vm_funcregister("sdl_destroy_sdl_messageboxdata",ring_sdl_destroy_sdl_messageboxdata);
	ring_vm_funcregister("sdl_new_sdl_windowevent",ring_sdl_new_sdl_windowevent);
	ring_vm_funcregister("sdl_destroy_sdl_windowevent",ring_sdl_destroy_sdl_windowevent);
	ring_vm_funcregister("sdl_new_sdl_rendererinfo",ring_sdl_new_sdl_rendererinfo);
	ring_vm_funcregister("sdl_destroy_sdl_rendererinfo",ring_sdl_destroy_sdl_rendererinfo);
	ring_vm_funcregister("sdl_new_sdl_color",ring_sdl_new_sdl_color);
	ring_vm_funcregister("sdl_destroy_sdl_color",ring_sdl_destroy_sdl_color);
	ring_vm_funcregister("sdl_new_sdl_palette",ring_sdl_new_sdl_palette);
	ring_vm_funcregister("sdl_destroy_sdl_palette",ring_sdl_destroy_sdl_palette);
	ring_vm_funcregister("sdl_new_sdl_pixelformat",ring_sdl_new_sdl_pixelformat);
	ring_vm_funcregister("sdl_destroy_sdl_pixelformat",ring_sdl_destroy_sdl_pixelformat);
	ring_vm_funcregister("sdl_new_sdl_point",ring_sdl_new_sdl_point);
	ring_vm_funcregister("sdl_destroy_sdl_point",ring_sdl_destroy_sdl_point);
	ring_vm_funcregister("sdl_get_sdl_point_x",ring_sdl_get_sdl_point_x);
	ring_vm_funcregister("sdl_set_sdl_point_x",ring_sdl_set_sdl_point_x);
	ring_vm_funcregister("sdl_get_sdl_point_y",ring_sdl_get_sdl_point_y);
	ring_vm_funcregister("sdl_set_sdl_point_y",ring_sdl_set_sdl_point_y);
	ring_vm_funcregister("sdl_new_sdl_rect",ring_sdl_new_sdl_rect);
	ring_vm_funcregister("sdl_destroy_sdl_rect",ring_sdl_destroy_sdl_rect);
	ring_vm_funcregister("sdl_get_sdl_rect_x",ring_sdl_get_sdl_rect_x);
	ring_vm_funcregister("sdl_set_sdl_rect_x",ring_sdl_set_sdl_rect_x);
	ring_vm_funcregister("sdl_get_sdl_rect_y",ring_sdl_get_sdl_rect_y);
	ring_vm_funcregister("sdl_set_sdl_rect_y",ring_sdl_set_sdl_rect_y);
	ring_vm_funcregister("sdl_get_sdl_rect_w",ring_sdl_get_sdl_rect_w);
	ring_vm_funcregister("sdl_set_sdl_rect_w",ring_sdl_set_sdl_rect_w);
	ring_vm_funcregister("sdl_get_sdl_rect_h",ring_sdl_get_sdl_rect_h);
	ring_vm_funcregister("sdl_set_sdl_rect_h",ring_sdl_set_sdl_rect_h);
	ring_vm_funcregister("sdl_new_sdl_surface",ring_sdl_new_sdl_surface);
	ring_vm_funcregister("sdl_destroy_sdl_surface",ring_sdl_destroy_sdl_surface);
	ring_vm_funcregister("sdl_new_sdl_syswminfo",ring_sdl_new_sdl_syswminfo);
	ring_vm_funcregister("sdl_destroy_sdl_syswminfo",ring_sdl_destroy_sdl_syswminfo);
	ring_vm_funcregister("sdl_new_sdl_syswmmsg",ring_sdl_new_sdl_syswmmsg);
	ring_vm_funcregister("sdl_destroy_sdl_syswmmsg",ring_sdl_destroy_sdl_syswmmsg);
}

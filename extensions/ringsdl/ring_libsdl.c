#include "ring.h"

#ifdef _WIN32
#define RING_DLL __declspec(dllexport)
#else
#define RING_DLL extern
#endif

/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "SDL.h"
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
	RING_API_RETCPOINTER(SDL_CreateWindow(RING_API_GETSTRING(1), (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3), (int) RING_API_GETNUMBER(4), (int) RING_API_GETNUMBER(5), (int) RING_API_GETNUMBER(6)),"SDL_Window");
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
	RING_API_RETCPOINTER(SDL_CreateRenderer((SDL_Window *) RING_API_GETCPOINTER(1,"SDL_Window"), (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3)),"SDL_Renderer");
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
	SDL_RenderClear((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"));
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
	SDL_RenderCopy((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"),(SDL_Texture *) RING_API_GETCPOINTER(2,"SDL_Texture"),(void *) RING_API_GETCPOINTER(3,"void"),(void *) RING_API_GETCPOINTER(4,"void"));
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


RING_FUNC(ring_SDL_Quit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	SDL_Quit();
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

RING_DLL void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("sdl_rendercopy2",ring_SDL_RenderCopy2);
	ring_vm_funcregister("sdl_init",ring_SDL_Init);
	ring_vm_funcregister("sdl_createwindow",ring_SDL_CreateWindow);
	ring_vm_funcregister("sdl_createrenderer",ring_SDL_CreateRenderer);
	ring_vm_funcregister("sdl_loadbmp",ring_SDL_LoadBMP);
	ring_vm_funcregister("sdl_createtexturefromsurface",ring_SDL_CreateTextureFromSurface);
	ring_vm_funcregister("sdl_freesurface",ring_SDL_FreeSurface);
	ring_vm_funcregister("sdl_renderclear",ring_SDL_RenderClear);
	ring_vm_funcregister("sdl_rendercopy",ring_SDL_RenderCopy);
	ring_vm_funcregister("sdl_renderpresent",ring_SDL_RenderPresent);
	ring_vm_funcregister("sdl_delay",ring_SDL_Delay);
	ring_vm_funcregister("sdl_destroytexture",ring_SDL_DestroyTexture);
	ring_vm_funcregister("sdl_destroyrenderer",ring_SDL_DestroyRenderer);
	ring_vm_funcregister("sdl_destroywindow",ring_SDL_DestroyWindow);
	ring_vm_funcregister("sdl_quit",ring_SDL_Quit);
	ring_vm_funcregister("sdl_renderdrawrect",ring_SDL_RenderDrawRect);
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
}

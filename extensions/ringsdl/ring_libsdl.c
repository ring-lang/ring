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
	RING_API_RETNUMBER(SDL_SetRenderDrawColor((SDL_Renderer *) RING_API_GETCPOINTER(1,"SDL_Renderer"), (int) RING_API_GETNUMBER(2), (int) RING_API_GETNUMBER(3), (int) RING_API_GETNUMBER(4), (int) RING_API_GETNUMBER(5)));
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

RING_DLL void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("sdl_rendercopy2",ring_SDL_RenderCopy2);
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
	ring_vm_funcregister("sdl_renderdrawrect",ring_SDL_RenderDrawRect);
	ring_vm_funcregister("sdl_setrenderdrawcolor",ring_SDL_SetRenderDrawColor);
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

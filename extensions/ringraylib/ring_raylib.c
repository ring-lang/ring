/* Copyright (c) 2019 Mahmoud Fayed <msfclipper@yahoo.com> */

#define RING_EXTENSION	// Don't call : windows.h (Avoid conflict with raylib.h)
#include <ring.h>

#include <raylib.h>


RING_FUNC(ring_InitWindow)
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
	InitWindow( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_WindowShouldClose)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(WindowShouldClose());
}


RING_FUNC(ring_CloseWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	CloseWindow();
}


RING_FUNC(ring_IsWindowReady)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowReady());
}


RING_FUNC(ring_IsWindowMinimized)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowMinimized());
}


RING_FUNC(ring_IsWindowResized)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowResized());
}


RING_FUNC(ring_IsWindowHidden)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsWindowHidden());
}


RING_FUNC(ring_ToggleFullscreen)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ToggleFullscreen();
}


RING_FUNC(ring_UnhideWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	UnhideWindow();
}


RING_FUNC(ring_HideWindow)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	HideWindow();
}


RING_FUNC(ring_SetWindowIcon)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetWindowIcon(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_SetWindowTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetWindowTitle(RING_API_GETSTRING(1));
}


RING_FUNC(ring_SetWindowPosition)
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
	SetWindowPosition( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetWindowMonitor)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetWindowMonitor( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetWindowMinSize)
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
	SetWindowMinSize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetWindowSize)
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
	SetWindowSize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_GetWindowHandle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(GetWindowHandle(),"void");
}


RING_FUNC(ring_GetScreenWidth)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetScreenWidth());
}


RING_FUNC(ring_GetScreenHeight)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetScreenHeight());
}


RING_FUNC(ring_GetMonitorCount)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorCount());
}


RING_FUNC(ring_GetMonitorWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorWidth( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorHeight( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorPhysicalWidth)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorPhysicalWidth( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorPhysicalHeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetMonitorPhysicalHeight( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMonitorName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetMonitorName( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetClipboardText)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(GetClipboardText());
}


RING_FUNC(ring_SetClipboardText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetClipboardText(RING_API_GETSTRING(1));
}


RING_FUNC(ring_ShowCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ShowCursor();
}


RING_FUNC(ring_HideCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	HideCursor();
}


RING_FUNC(ring_IsCursorHidden)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsCursorHidden());
}


RING_FUNC(ring_EnableCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EnableCursor();
}


RING_FUNC(ring_DisableCursor)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	DisableCursor();
}


RING_FUNC(ring_ClearBackground)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	ClearBackground(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
}


RING_FUNC(ring_BeginDrawing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	BeginDrawing();
}


RING_FUNC(ring_EndDrawing)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndDrawing();
}


RING_FUNC(ring_BeginMode2D)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	BeginMode2D(* (Camera2D  *) RING_API_GETCPOINTER(1,"Camera2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera2D"));
}


RING_FUNC(ring_EndMode2D)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndMode2D();
}


RING_FUNC(ring_BeginMode3D)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	BeginMode3D(* (Camera3D  *) RING_API_GETCPOINTER(1,"Camera3D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera3D"));
}


RING_FUNC(ring_EndMode3D)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndMode3D();
}


RING_FUNC(ring_BeginTextureMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	BeginTextureMode(* (RenderTexture2D  *) RING_API_GETCPOINTER(1,"RenderTexture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"RenderTexture2D"));
}


RING_FUNC(ring_EndTextureMode)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	EndTextureMode();
}


RING_FUNC(ring_GetMouseRay)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Ray *pValue ; 
		pValue = (Ray *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Ray)) ;
		*pValue = GetMouseRay(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Camera  *) RING_API_GETCPOINTER(2,"Camera"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Camera"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Ray",ring_state_free);
	}
}


RING_FUNC(ring_GetWorldToScreen)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetWorldToScreen(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"),* (Camera  *) RING_API_GETCPOINTER(2,"Camera"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Camera"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
	}
}


RING_FUNC(ring_GetCameraMatrix)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Matrix *pValue ; 
		pValue = (Matrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Matrix)) ;
		*pValue = GetCameraMatrix(* (Camera  *) RING_API_GETCPOINTER(1,"Camera"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Matrix",ring_state_free);
	}
}


RING_FUNC(ring_SetTargetFPS)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTargetFPS( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_GetFPS)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetFPS());
}


RING_FUNC(ring_GetFrameTime)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetFrameTime());
}


RING_FUNC(ring_GetTime)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTime());
}


RING_FUNC(ring_ColorToInt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETNUMBER(ColorToInt(* (Color  *) RING_API_GETCPOINTER(1,"Color")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
}


RING_FUNC(ring_ColorNormalize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector4 *pValue ; 
		pValue = (Vector4 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector4)) ;
		*pValue = ColorNormalize(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector4",ring_state_free);
	}
}


RING_FUNC(ring_ColorToHSV)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Vector3 *pValue ; 
		pValue = (Vector3 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector3)) ;
		*pValue = ColorToHSV(* (Color  *) RING_API_GETCPOINTER(1,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector3",ring_state_free);
	}
}


RING_FUNC(ring_ColorFromHSV)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Color *pValue ; 
		pValue = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
		*pValue = ColorFromHSV(* (Vector3  *) RING_API_GETCPOINTER(1,"Vector3"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector3"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",ring_state_free);
	}
}


RING_FUNC(ring_GetColor)
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
		Color *pValue ; 
		pValue = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
		*pValue = GetColor( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",ring_state_free);
	}
}


RING_FUNC(ring_Fade)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Color *pValue ; 
		pValue = (Color *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Color)) ;
		*pValue = Fade(* (Color  *) RING_API_GETCPOINTER(1,"Color"), (float ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Color",ring_state_free);
	}
}


RING_FUNC(ring_SetConfigFlags)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetConfigFlags( (unsigned char ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetTraceLogLevel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTraceLogLevel( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetTraceLogExit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetTraceLogExit( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetTraceLogCallback)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	SetTraceLogCallback(* (TraceLogCallback  *) RING_API_GETCPOINTER(1,"TraceLogCallback"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"TraceLogCallback"));
}


RING_FUNC(ring_TraceLog)
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
	TraceLog( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2));
}


RING_FUNC(ring_TakeScreenshot)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	TakeScreenshot(RING_API_GETSTRING(1));
}


RING_FUNC(ring_GetRandomValue)
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
	RING_API_RETNUMBER(GetRandomValue( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_FileExists)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(FileExists(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_IsFileExtension)
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
	RING_API_RETNUMBER(IsFileExtension(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_GetExtension)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetExtension(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetFileName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetFileName(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetFileNameWithoutExt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetFileNameWithoutExt(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetDirectoryPath)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetDirectoryPath(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_GetWorkingDirectory)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETSTRING(GetWorkingDirectory());
}


RING_FUNC(ring_GetDirectoryFiles)
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
	RING_API_RETCPOINTER(GetDirectoryFiles(RING_API_GETSTRING(1),RING_API_GETINTPOINTER(2)),"char");
	RING_API_ACCEPTINTVALUE(2) ;
}


RING_FUNC(ring_ClearDirectoryFiles)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ClearDirectoryFiles();
}


RING_FUNC(ring_ChangeDirectory)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(ChangeDirectory(RING_API_GETSTRING(1)));
}


RING_FUNC(ring_IsFileDropped)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(IsFileDropped());
}


RING_FUNC(ring_GetDroppedFiles)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(GetDroppedFiles(RING_API_GETINTPOINTER(1)),"char");
	RING_API_ACCEPTINTVALUE(1) ;
}


RING_FUNC(ring_ClearDroppedFiles)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	ClearDroppedFiles();
}


RING_FUNC(ring_GetFileModTime)
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
		long *pValue ; 
		pValue = (long *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(long)) ;
		*pValue = GetFileModTime(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"long",ring_state_free);
	}
}


RING_FUNC(ring_StorageSaveValue)
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
	StorageSaveValue( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_StorageLoadValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(StorageLoadValue( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_OpenURL)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	OpenURL(RING_API_GETSTRING(1));
}


RING_FUNC(ring_IsKeyPressed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyPressed( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsKeyDown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyDown( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsKeyReleased)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyReleased( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsKeyUp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsKeyUp( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetKeyPressed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetKeyPressed());
}


RING_FUNC(ring_SetExitKey)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetExitKey( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_IsGamepadAvailable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsGamepadAvailable( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsGamepadName)
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
	RING_API_RETNUMBER(IsGamepadName( (int ) RING_API_GETNUMBER(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_GetGamepadName)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(GetGamepadName( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsGamepadButtonPressed)
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
	RING_API_RETNUMBER(IsGamepadButtonPressed( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsGamepadButtonDown)
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
	RING_API_RETNUMBER(IsGamepadButtonDown( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsGamepadButtonReleased)
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
	RING_API_RETNUMBER(IsGamepadButtonReleased( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsGamepadButtonUp)
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
	RING_API_RETNUMBER(IsGamepadButtonUp( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_GetGamepadButtonPressed)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGamepadButtonPressed());
}


RING_FUNC(ring_GetGamepadAxisCount)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(GetGamepadAxisCount( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetGamepadAxisMovement)
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
	RING_API_RETNUMBER(GetGamepadAxisMovement( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_IsMouseButtonPressed)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonPressed( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsMouseButtonDown)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonDown( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsMouseButtonReleased)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonReleased( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_IsMouseButtonUp)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsMouseButtonUp( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetMouseX)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMouseX());
}


RING_FUNC(ring_GetMouseY)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMouseY());
}


RING_FUNC(ring_GetMousePosition)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetMousePosition();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
	}
}


RING_FUNC(ring_SetMousePosition)
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
	SetMousePosition( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetMouseOffset)
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
	SetMouseOffset( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_SetMouseScale)
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
	SetMouseScale( (float ) RING_API_GETNUMBER(1), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_GetMouseWheelMove)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetMouseWheelMove());
}


RING_FUNC(ring_GetTouchX)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTouchX());
}


RING_FUNC(ring_GetTouchY)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTouchY());
}


RING_FUNC(ring_GetTouchPosition)
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
		Vector2 *pValue ; 
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetTouchPosition( (int ) RING_API_GETNUMBER(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
	}
}


RING_FUNC(ring_SetGesturesEnabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetGesturesEnabled( (unsigned int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_IsGestureDetected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(IsGestureDetected( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_GetGestureDetected)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGestureDetected());
}


RING_FUNC(ring_GetTouchPointsCount)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetTouchPointsCount());
}


RING_FUNC(ring_GetGestureHoldDuration)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGestureHoldDuration());
}


RING_FUNC(ring_GetGestureDragVector)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetGestureDragVector();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
	}
}


RING_FUNC(ring_GetGestureDragAngle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGestureDragAngle());
}


RING_FUNC(ring_GetGesturePinchVector)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Vector2 *pValue ; 
		pValue = (Vector2 *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Vector2)) ;
		*pValue = GetGesturePinchVector();
		RING_API_RETMANAGEDCPOINTER(pValue,"Vector2",ring_state_free);
	}
}


RING_FUNC(ring_GetGesturePinchAngle)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(GetGesturePinchAngle());
}


RING_FUNC(ring_SetCameraMode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraMode(* (Camera  *) RING_API_GETCPOINTER(1,"Camera"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Camera"));
}


RING_FUNC(ring_UpdateCamera)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateCamera((Camera *) RING_API_GETCPOINTER(1,"Camera"));
}


RING_FUNC(ring_SetCameraPanControl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraPanControl( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetCameraAltControl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraAltControl( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetCameraSmoothZoomControl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	SetCameraSmoothZoomControl( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_SetCameraMoveControls)
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
	SetCameraMoveControls( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_DrawPixel)
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
	DrawPixel( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawPixelV)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawPixelV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_DrawLine)
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
	DrawLine( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawLineV)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawLineV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawLineEx)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawLineEx(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawLineBezier)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawLineBezier(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawLineStrip)
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
	DrawLineStrip((Vector2 *) RING_API_GETCPOINTER(1,"Vector2"), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawCircle)
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
	DrawCircle( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawCircleSector)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCircleSector(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawCircleSectorLines)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawCircleSectorLines(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawCircleGradient)
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
	DrawCircleGradient( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawCircleV)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawCircleV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawCircleLines)
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
	DrawCircleLines( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawRing)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawRing(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
}


RING_FUNC(ring_DrawRingLines)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawRingLines(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
}


RING_FUNC(ring_DrawRectangle)
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
	DrawRectangle( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawRectangleV)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	DrawRectangleV(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawRectangleRec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	DrawRectangleRec(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_DrawRectanglePro)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawRectanglePro(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawRectangleGradientV)
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
	DrawRectangleGradientV( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawRectangleGradientH)
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
	DrawRectangleGradientH( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_DrawRectangleGradientEx)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	DrawRectangleGradientEx(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(2,"Color"),* (Color  *) RING_API_GETCPOINTER(3,"Color"),* (Color  *) RING_API_GETCPOINTER(4,"Color"),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawRectangleLines)
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
	DrawRectangleLines( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawRectangleLinesEx)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	DrawRectangleLinesEx(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawRectangleRounded)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	DrawRectangleRounded(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawRectangleRoundedLines)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawRectangleRoundedLines(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"), (float ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_DrawTriangle)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTriangle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTriangleLines)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	DrawTriangleLines(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_DrawTriangleFan)
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
	DrawTriangleFan((Vector2 *) RING_API_GETCPOINTER(1,"Vector2"), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_DrawPoly)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	DrawPoly(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (int ) RING_API_GETNUMBER(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_SetShapesTexture)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	SetShapesTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_CheckCollisionRecs)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionRecs(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_CheckCollisionCircles)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
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
	RING_API_RETNUMBER(CheckCollisionCircles(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"), (float ) RING_API_GETNUMBER(4)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
}


RING_FUNC(ring_CheckCollisionCircleRec)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionCircleRec(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"), (float ) RING_API_GETNUMBER(2),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
}


RING_FUNC(ring_GetCollisionRec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	{
		Rectangle *pValue ; 
		pValue = (Rectangle *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Rectangle)) ;
		*pValue = GetCollisionRec(* (Rectangle  *) RING_API_GETCPOINTER(1,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Rectangle",ring_state_free);
	}
}


RING_FUNC(ring_CheckCollisionPointRec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionPointRec(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_CheckCollisionPointCircle)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionPointCircle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"), (float ) RING_API_GETNUMBER(3)));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
}


RING_FUNC(ring_CheckCollisionPointTriangle)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_RETNUMBER(CheckCollisionPointTriangle(* (Vector2  *) RING_API_GETCPOINTER(1,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(3,"Vector2"),* (Vector2  *) RING_API_GETCPOINTER(4,"Vector2")));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Vector2"));
}


RING_FUNC(ring_LoadImage)
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
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImage(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_LoadImageEx)
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
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImageEx((Color *) RING_API_GETCPOINTER(1,"Color"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_LoadImagePro)
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
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImagePro((void *) RING_API_GETCPOINTER(1,"void"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_LoadImageRaw)
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
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = LoadImageRaw(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_ExportImage)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ExportImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ExportImageAsCode)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ExportImageAsCode(* (Image  *) RING_API_GETCPOINTER(1,"Image"),RING_API_GETSTRING(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_LoadTexture)
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
		Texture2D *pValue ; 
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = LoadTexture(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
	}
}


RING_FUNC(ring_LoadTextureFromImage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Texture2D *pValue ; 
		pValue = (Texture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Texture2D)) ;
		*pValue = LoadTextureFromImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Texture2D",ring_state_free);
	}
}


RING_FUNC(ring_LoadTextureCubemap)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		TextureCubemap *pValue ; 
		pValue = (TextureCubemap *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(TextureCubemap)) ;
		*pValue = LoadTextureCubemap(* (Image  *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"TextureCubemap",ring_state_free);
	}
}


RING_FUNC(ring_LoadRenderTexture)
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
	{
		RenderTexture2D *pValue ; 
		pValue = (RenderTexture2D *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(RenderTexture2D)) ;
		*pValue = LoadRenderTexture( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"RenderTexture2D",ring_state_free);
	}
}


RING_FUNC(ring_UnloadImage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadImage(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_UnloadTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_UnloadRenderTexture)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	UnloadRenderTexture(* (RenderTexture2D  *) RING_API_GETCPOINTER(1,"RenderTexture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"RenderTexture2D"));
}


RING_FUNC(ring_GetImageData)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(GetImageData(* (Image  *) RING_API_GETCPOINTER(1,"Image")),"Color");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_GetImageDataNormalized)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(GetImageDataNormalized(* (Image  *) RING_API_GETCPOINTER(1,"Image")),"Vector4");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_GetPixelDataSize)
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
	RING_API_RETNUMBER(GetPixelDataSize( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_GetTextureData)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GetTextureData(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_GetScreenData)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = GetScreenData();
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_UpdateTexture)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	UpdateTexture(* (Texture2D  *) RING_API_GETCPOINTER(1,"Texture2D"),(void *) RING_API_GETCPOINTER(2,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Texture2D"));
}


RING_FUNC(ring_ImageCopy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = ImageCopy(* (Image  *) RING_API_GETCPOINTER(1,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_ImageToPOT)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageToPOT((Image *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_ImageFormat)
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
	ImageFormat((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ImageAlphaMask)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageAlphaMask((Image *) RING_API_GETCPOINTER(1,"Image"),* (Image  *) RING_API_GETCPOINTER(2,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Image"));
}


RING_FUNC(ring_ImageAlphaClear)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageAlphaClear((Image *) RING_API_GETCPOINTER(1,"Image"),* (Color  *) RING_API_GETCPOINTER(2,"Color"), (float ) RING_API_GETNUMBER(3));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Color"));
}


RING_FUNC(ring_ImageAlphaCrop)
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
	ImageAlphaCrop((Image *) RING_API_GETCPOINTER(1,"Image"), (float ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_ImageAlphaPremultiply)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageAlphaPremultiply((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageCrop)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageCrop((Image *) RING_API_GETCPOINTER(1,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
}


RING_FUNC(ring_ImageResize)
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
	ImageResize((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_ImageResizeNN)
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
	ImageResizeNN((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_ImageResizeCanvas)
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
	ImageResizeCanvas((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),* (Color  *) RING_API_GETCPOINTER(6,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(6))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(6,"Color"));
}


RING_FUNC(ring_ImageMipmaps)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageMipmaps((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageDither)
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
	ImageDither((Image *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_ImageExtractPalette)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETCPOINTER(ImageExtractPalette(* (Image  *) RING_API_GETCPOINTER(1,"Image"), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3)),"Color");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Image"));
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_ImageText)
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
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = ImageText(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_ImageTextEx)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	{
		Image *pValue ; 
		pValue = (Image *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Image)) ;
		*pValue = ImageTextEx(* (Font  *) RING_API_GETCPOINTER(1,"Font"),RING_API_GETSTRING(2), (float ) RING_API_GETNUMBER(3), (float ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Image",ring_state_free);
	}
}


RING_FUNC(ring_ImageDraw)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageDraw((Image *) RING_API_GETCPOINTER(1,"Image"),* (Image  *) RING_API_GETCPOINTER(2,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(3,"Rectangle"),* (Rectangle  *) RING_API_GETCPOINTER(4,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Image"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Rectangle"));
}


RING_FUNC(ring_ImageDrawRectangle)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageDrawRectangle((Image *) RING_API_GETCPOINTER(1,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"),* (Color  *) RING_API_GETCPOINTER(3,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Color"));
}


RING_FUNC(ring_ImageDrawRectangleLines)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageDrawRectangleLines((Image *) RING_API_GETCPOINTER(1,"Image"),* (Rectangle  *) RING_API_GETCPOINTER(2,"Rectangle"), (int ) RING_API_GETNUMBER(3),* (Color  *) RING_API_GETCPOINTER(4,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Rectangle"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"Color"));
}


RING_FUNC(ring_ImageDrawText)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	ImageDrawText((Image *) RING_API_GETCPOINTER(1,"Image"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),* (Color  *) RING_API_GETCPOINTER(5,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"Color"));
}


RING_FUNC(ring_ImageDrawTextEx)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	ImageDrawTextEx((Image *) RING_API_GETCPOINTER(1,"Image"),* (Vector2  *) RING_API_GETCPOINTER(2,"Vector2"),* (Font  *) RING_API_GETCPOINTER(3,"Font"),RING_API_GETSTRING(4), (float ) RING_API_GETNUMBER(5), (float ) RING_API_GETNUMBER(6),* (Color  *) RING_API_GETCPOINTER(7,"Color"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"Vector2"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"Font"));
	if (RING_API_ISCPOINTERNOTASSIGNED(7))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(7,"Color"));
}


RING_FUNC(ring_ImageFlipVertical)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageFlipVertical((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageFlipHorizontal)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageFlipHorizontal((Image *) RING_API_GETCPOINTER(1,"Image"));
}


RING_FUNC(ring_ImageRotateCW)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	ImageRotateCW((Image *) RING_API_GETCPOINTER(1,"Image"));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("initwindow",ring_InitWindow);
	ring_vm_funcregister("windowshouldclose",ring_WindowShouldClose);
	ring_vm_funcregister("closewindow",ring_CloseWindow);
	ring_vm_funcregister("iswindowready",ring_IsWindowReady);
	ring_vm_funcregister("iswindowminimized",ring_IsWindowMinimized);
	ring_vm_funcregister("iswindowresized",ring_IsWindowResized);
	ring_vm_funcregister("iswindowhidden",ring_IsWindowHidden);
	ring_vm_funcregister("togglefullscreen",ring_ToggleFullscreen);
	ring_vm_funcregister("unhidewindow",ring_UnhideWindow);
	ring_vm_funcregister("hidewindow",ring_HideWindow);
	ring_vm_funcregister("setwindowicon",ring_SetWindowIcon);
	ring_vm_funcregister("setwindowtitle",ring_SetWindowTitle);
	ring_vm_funcregister("setwindowposition",ring_SetWindowPosition);
	ring_vm_funcregister("setwindowmonitor",ring_SetWindowMonitor);
	ring_vm_funcregister("setwindowminsize",ring_SetWindowMinSize);
	ring_vm_funcregister("setwindowsize",ring_SetWindowSize);
	ring_vm_funcregister("getwindowhandle",ring_GetWindowHandle);
	ring_vm_funcregister("getscreenwidth",ring_GetScreenWidth);
	ring_vm_funcregister("getscreenheight",ring_GetScreenHeight);
	ring_vm_funcregister("getmonitorcount",ring_GetMonitorCount);
	ring_vm_funcregister("getmonitorwidth",ring_GetMonitorWidth);
	ring_vm_funcregister("getmonitorheight",ring_GetMonitorHeight);
	ring_vm_funcregister("getmonitorphysicalwidth",ring_GetMonitorPhysicalWidth);
	ring_vm_funcregister("getmonitorphysicalheight",ring_GetMonitorPhysicalHeight);
	ring_vm_funcregister("getmonitorname",ring_GetMonitorName);
	ring_vm_funcregister("getclipboardtext",ring_GetClipboardText);
	ring_vm_funcregister("setclipboardtext",ring_SetClipboardText);
	ring_vm_funcregister("showcursor",ring_ShowCursor);
	ring_vm_funcregister("hidecursor",ring_HideCursor);
	ring_vm_funcregister("iscursorhidden",ring_IsCursorHidden);
	ring_vm_funcregister("enablecursor",ring_EnableCursor);
	ring_vm_funcregister("disablecursor",ring_DisableCursor);
	ring_vm_funcregister("clearbackground",ring_ClearBackground);
	ring_vm_funcregister("begindrawing",ring_BeginDrawing);
	ring_vm_funcregister("enddrawing",ring_EndDrawing);
	ring_vm_funcregister("beginmode2d",ring_BeginMode2D);
	ring_vm_funcregister("endmode2d",ring_EndMode2D);
	ring_vm_funcregister("beginmode3d",ring_BeginMode3D);
	ring_vm_funcregister("endmode3d",ring_EndMode3D);
	ring_vm_funcregister("begintexturemode",ring_BeginTextureMode);
	ring_vm_funcregister("endtexturemode",ring_EndTextureMode);
	ring_vm_funcregister("getmouseray",ring_GetMouseRay);
	ring_vm_funcregister("getworldtoscreen",ring_GetWorldToScreen);
	ring_vm_funcregister("getcameramatrix",ring_GetCameraMatrix);
	ring_vm_funcregister("settargetfps",ring_SetTargetFPS);
	ring_vm_funcregister("getfps",ring_GetFPS);
	ring_vm_funcregister("getframetime",ring_GetFrameTime);
	ring_vm_funcregister("gettime",ring_GetTime);
	ring_vm_funcregister("colortoint",ring_ColorToInt);
	ring_vm_funcregister("colornormalize",ring_ColorNormalize);
	ring_vm_funcregister("colortohsv",ring_ColorToHSV);
	ring_vm_funcregister("colorfromhsv",ring_ColorFromHSV);
	ring_vm_funcregister("getcolor",ring_GetColor);
	ring_vm_funcregister("fade",ring_Fade);
	ring_vm_funcregister("setconfigflags",ring_SetConfigFlags);
	ring_vm_funcregister("settraceloglevel",ring_SetTraceLogLevel);
	ring_vm_funcregister("settracelogexit",ring_SetTraceLogExit);
	ring_vm_funcregister("settracelogcallback",ring_SetTraceLogCallback);
	ring_vm_funcregister("tracelog",ring_TraceLog);
	ring_vm_funcregister("takescreenshot",ring_TakeScreenshot);
	ring_vm_funcregister("getrandomvalue",ring_GetRandomValue);
	ring_vm_funcregister("fileexists",ring_FileExists);
	ring_vm_funcregister("isfileextension",ring_IsFileExtension);
	ring_vm_funcregister("getextension",ring_GetExtension);
	ring_vm_funcregister("getfilename",ring_GetFileName);
	ring_vm_funcregister("getfilenamewithoutext",ring_GetFileNameWithoutExt);
	ring_vm_funcregister("getdirectorypath",ring_GetDirectoryPath);
	ring_vm_funcregister("getworkingdirectory",ring_GetWorkingDirectory);
	ring_vm_funcregister("getdirectoryfiles",ring_GetDirectoryFiles);
	ring_vm_funcregister("cleardirectoryfiles",ring_ClearDirectoryFiles);
	ring_vm_funcregister("changedirectory",ring_ChangeDirectory);
	ring_vm_funcregister("isfiledropped",ring_IsFileDropped);
	ring_vm_funcregister("getdroppedfiles",ring_GetDroppedFiles);
	ring_vm_funcregister("cleardroppedfiles",ring_ClearDroppedFiles);
	ring_vm_funcregister("getfilemodtime",ring_GetFileModTime);
	ring_vm_funcregister("storagesavevalue",ring_StorageSaveValue);
	ring_vm_funcregister("storageloadvalue",ring_StorageLoadValue);
	ring_vm_funcregister("openurl",ring_OpenURL);
	ring_vm_funcregister("iskeypressed",ring_IsKeyPressed);
	ring_vm_funcregister("iskeydown",ring_IsKeyDown);
	ring_vm_funcregister("iskeyreleased",ring_IsKeyReleased);
	ring_vm_funcregister("iskeyup",ring_IsKeyUp);
	ring_vm_funcregister("getkeypressed",ring_GetKeyPressed);
	ring_vm_funcregister("setexitkey",ring_SetExitKey);
	ring_vm_funcregister("isgamepadavailable",ring_IsGamepadAvailable);
	ring_vm_funcregister("isgamepadname",ring_IsGamepadName);
	ring_vm_funcregister("getgamepadname",ring_GetGamepadName);
	ring_vm_funcregister("isgamepadbuttonpressed",ring_IsGamepadButtonPressed);
	ring_vm_funcregister("isgamepadbuttondown",ring_IsGamepadButtonDown);
	ring_vm_funcregister("isgamepadbuttonreleased",ring_IsGamepadButtonReleased);
	ring_vm_funcregister("isgamepadbuttonup",ring_IsGamepadButtonUp);
	ring_vm_funcregister("getgamepadbuttonpressed",ring_GetGamepadButtonPressed);
	ring_vm_funcregister("getgamepadaxiscount",ring_GetGamepadAxisCount);
	ring_vm_funcregister("getgamepadaxismovement",ring_GetGamepadAxisMovement);
	ring_vm_funcregister("ismousebuttonpressed",ring_IsMouseButtonPressed);
	ring_vm_funcregister("ismousebuttondown",ring_IsMouseButtonDown);
	ring_vm_funcregister("ismousebuttonreleased",ring_IsMouseButtonReleased);
	ring_vm_funcregister("ismousebuttonup",ring_IsMouseButtonUp);
	ring_vm_funcregister("getmousex",ring_GetMouseX);
	ring_vm_funcregister("getmousey",ring_GetMouseY);
	ring_vm_funcregister("getmouseposition",ring_GetMousePosition);
	ring_vm_funcregister("setmouseposition",ring_SetMousePosition);
	ring_vm_funcregister("setmouseoffset",ring_SetMouseOffset);
	ring_vm_funcregister("setmousescale",ring_SetMouseScale);
	ring_vm_funcregister("getmousewheelmove",ring_GetMouseWheelMove);
	ring_vm_funcregister("gettouchx",ring_GetTouchX);
	ring_vm_funcregister("gettouchy",ring_GetTouchY);
	ring_vm_funcregister("gettouchposition",ring_GetTouchPosition);
	ring_vm_funcregister("setgesturesenabled",ring_SetGesturesEnabled);
	ring_vm_funcregister("isgesturedetected",ring_IsGestureDetected);
	ring_vm_funcregister("getgesturedetected",ring_GetGestureDetected);
	ring_vm_funcregister("gettouchpointscount",ring_GetTouchPointsCount);
	ring_vm_funcregister("getgestureholdduration",ring_GetGestureHoldDuration);
	ring_vm_funcregister("getgesturedragvector",ring_GetGestureDragVector);
	ring_vm_funcregister("getgesturedragangle",ring_GetGestureDragAngle);
	ring_vm_funcregister("getgesturepinchvector",ring_GetGesturePinchVector);
	ring_vm_funcregister("getgesturepinchangle",ring_GetGesturePinchAngle);
	ring_vm_funcregister("setcameramode",ring_SetCameraMode);
	ring_vm_funcregister("updatecamera",ring_UpdateCamera);
	ring_vm_funcregister("setcamerapancontrol",ring_SetCameraPanControl);
	ring_vm_funcregister("setcameraaltcontrol",ring_SetCameraAltControl);
	ring_vm_funcregister("setcamerasmoothzoomcontrol",ring_SetCameraSmoothZoomControl);
	ring_vm_funcregister("setcameramovecontrols",ring_SetCameraMoveControls);
	ring_vm_funcregister("drawpixel",ring_DrawPixel);
	ring_vm_funcregister("drawpixelv",ring_DrawPixelV);
	ring_vm_funcregister("drawline",ring_DrawLine);
	ring_vm_funcregister("drawlinev",ring_DrawLineV);
	ring_vm_funcregister("drawlineex",ring_DrawLineEx);
	ring_vm_funcregister("drawlinebezier",ring_DrawLineBezier);
	ring_vm_funcregister("drawlinestrip",ring_DrawLineStrip);
	ring_vm_funcregister("drawcircle",ring_DrawCircle);
	ring_vm_funcregister("drawcirclesector",ring_DrawCircleSector);
	ring_vm_funcregister("drawcirclesectorlines",ring_DrawCircleSectorLines);
	ring_vm_funcregister("drawcirclegradient",ring_DrawCircleGradient);
	ring_vm_funcregister("drawcirclev",ring_DrawCircleV);
	ring_vm_funcregister("drawcirclelines",ring_DrawCircleLines);
	ring_vm_funcregister("drawring",ring_DrawRing);
	ring_vm_funcregister("drawringlines",ring_DrawRingLines);
	ring_vm_funcregister("drawrectangle",ring_DrawRectangle);
	ring_vm_funcregister("drawrectanglev",ring_DrawRectangleV);
	ring_vm_funcregister("drawrectanglerec",ring_DrawRectangleRec);
	ring_vm_funcregister("drawrectanglepro",ring_DrawRectanglePro);
	ring_vm_funcregister("drawrectanglegradientv",ring_DrawRectangleGradientV);
	ring_vm_funcregister("drawrectanglegradienth",ring_DrawRectangleGradientH);
	ring_vm_funcregister("drawrectanglegradientex",ring_DrawRectangleGradientEx);
	ring_vm_funcregister("drawrectanglelines",ring_DrawRectangleLines);
	ring_vm_funcregister("drawrectanglelinesex",ring_DrawRectangleLinesEx);
	ring_vm_funcregister("drawrectanglerounded",ring_DrawRectangleRounded);
	ring_vm_funcregister("drawrectangleroundedlines",ring_DrawRectangleRoundedLines);
	ring_vm_funcregister("drawtriangle",ring_DrawTriangle);
	ring_vm_funcregister("drawtrianglelines",ring_DrawTriangleLines);
	ring_vm_funcregister("drawtrianglefan",ring_DrawTriangleFan);
	ring_vm_funcregister("drawpoly",ring_DrawPoly);
	ring_vm_funcregister("setshapestexture",ring_SetShapesTexture);
	ring_vm_funcregister("checkcollisionrecs",ring_CheckCollisionRecs);
	ring_vm_funcregister("checkcollisioncircles",ring_CheckCollisionCircles);
	ring_vm_funcregister("checkcollisioncirclerec",ring_CheckCollisionCircleRec);
	ring_vm_funcregister("getcollisionrec",ring_GetCollisionRec);
	ring_vm_funcregister("checkcollisionpointrec",ring_CheckCollisionPointRec);
	ring_vm_funcregister("checkcollisionpointcircle",ring_CheckCollisionPointCircle);
	ring_vm_funcregister("checkcollisionpointtriangle",ring_CheckCollisionPointTriangle);
	ring_vm_funcregister("loadimage",ring_LoadImage);
	ring_vm_funcregister("loadimageex",ring_LoadImageEx);
	ring_vm_funcregister("loadimagepro",ring_LoadImagePro);
	ring_vm_funcregister("loadimageraw",ring_LoadImageRaw);
	ring_vm_funcregister("exportimage",ring_ExportImage);
	ring_vm_funcregister("exportimageascode",ring_ExportImageAsCode);
	ring_vm_funcregister("loadtexture",ring_LoadTexture);
	ring_vm_funcregister("loadtexturefromimage",ring_LoadTextureFromImage);
	ring_vm_funcregister("loadtexturecubemap",ring_LoadTextureCubemap);
	ring_vm_funcregister("loadrendertexture",ring_LoadRenderTexture);
	ring_vm_funcregister("unloadimage",ring_UnloadImage);
	ring_vm_funcregister("unloadtexture",ring_UnloadTexture);
	ring_vm_funcregister("unloadrendertexture",ring_UnloadRenderTexture);
	ring_vm_funcregister("getimagedata",ring_GetImageData);
	ring_vm_funcregister("getimagedatanormalized",ring_GetImageDataNormalized);
	ring_vm_funcregister("getpixeldatasize",ring_GetPixelDataSize);
	ring_vm_funcregister("gettexturedata",ring_GetTextureData);
	ring_vm_funcregister("getscreendata",ring_GetScreenData);
	ring_vm_funcregister("updatetexture",ring_UpdateTexture);
	ring_vm_funcregister("imagecopy",ring_ImageCopy);
	ring_vm_funcregister("imagetopot",ring_ImageToPOT);
	ring_vm_funcregister("imageformat",ring_ImageFormat);
	ring_vm_funcregister("imagealphamask",ring_ImageAlphaMask);
	ring_vm_funcregister("imagealphaclear",ring_ImageAlphaClear);
	ring_vm_funcregister("imagealphacrop",ring_ImageAlphaCrop);
	ring_vm_funcregister("imagealphapremultiply",ring_ImageAlphaPremultiply);
	ring_vm_funcregister("imagecrop",ring_ImageCrop);
	ring_vm_funcregister("imageresize",ring_ImageResize);
	ring_vm_funcregister("imageresizenn",ring_ImageResizeNN);
	ring_vm_funcregister("imageresizecanvas",ring_ImageResizeCanvas);
	ring_vm_funcregister("imagemipmaps",ring_ImageMipmaps);
	ring_vm_funcregister("imagedither",ring_ImageDither);
	ring_vm_funcregister("imageextractpalette",ring_ImageExtractPalette);
	ring_vm_funcregister("imagetext",ring_ImageText);
	ring_vm_funcregister("imagetextex",ring_ImageTextEx);
	ring_vm_funcregister("imagedraw",ring_ImageDraw);
	ring_vm_funcregister("imagedrawrectangle",ring_ImageDrawRectangle);
	ring_vm_funcregister("imagedrawrectanglelines",ring_ImageDrawRectangleLines);
	ring_vm_funcregister("imagedrawtext",ring_ImageDrawText);
	ring_vm_funcregister("imagedrawtextex",ring_ImageDrawTextEx);
	ring_vm_funcregister("imageflipvertical",ring_ImageFlipVertical);
	ring_vm_funcregister("imagefliphorizontal",ring_ImageFlipHorizontal);
	ring_vm_funcregister("imagerotatecw",ring_ImageRotateCW);
}

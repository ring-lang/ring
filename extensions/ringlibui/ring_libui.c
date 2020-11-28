#include "ring.h"

/* Copyright (c) 2020 Mahmoud Fayed <msfclipper@yahoo.com> */

#include <ui.h>
#include <windows.h>
#include <ui_windows.h>

RING_FUNC(ring_get_uipi)
{
	RING_API_RETNUMBER(uiPi);
}

RING_FUNC(ring_get_uiforeachcontinue)
{
	RING_API_RETNUMBER(uiForEachContinue);
}

RING_FUNC(ring_get_uiforeachstop)
{
	RING_API_RETNUMBER(uiForEachStop);
}

RING_FUNC(ring_new_uiinitoptions)
{
	uiInitOptions *pMyPointer ;
	pMyPointer = (uiInitOptions *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiInitOptions)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiInitOptions");
}

RING_FUNC(ring_new_managed_uiinitoptions)
{
	uiInitOptions *pMyPointer ;
	pMyPointer = (uiInitOptions *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiInitOptions)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiInitOptions",ring_state_free);
}

RING_FUNC(ring_destroy_uiinitoptions)
{
	uiInitOptions *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiInitOptions");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}


RING_FUNC(ring_uiInit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiInit((uiInitOptions *) RING_API_GETCPOINTER(1,"uiInitOptions")));
}


RING_FUNC(ring_uiUninit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	uiUninit();
}


RING_FUNC(ring_uiFreeInitError)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeInitError(RING_API_GETSTRING(1));
}


RING_FUNC(ring_uiMain)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	uiMain();
}


RING_FUNC(ring_uiMainSteps)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	uiMainSteps();
}


RING_FUNC(ring_uiMainStep)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiMainStep( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_uiQuit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	uiQuit();
}


RING_FUNC(ring_uiControlDestroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiControlDestroy((uiControl *) RING_API_GETCPOINTER(1,"uiControl"));
}


RING_FUNC(ring_uiControlParent)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiControlParent((uiControl *) RING_API_GETCPOINTER(1,"uiControl")),"uiControl");
}


RING_FUNC(ring_uiControlSetParent)
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
	uiControlSetParent((uiControl *) RING_API_GETCPOINTER(1,"uiControl"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"));
}


RING_FUNC(ring_uiControlToplevel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiControlToplevel((uiControl *) RING_API_GETCPOINTER(1,"uiControl")));
}


RING_FUNC(ring_uiControlVisible)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiControlVisible((uiControl *) RING_API_GETCPOINTER(1,"uiControl")));
}


RING_FUNC(ring_uiControlShow)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiControlShow((uiControl *) RING_API_GETCPOINTER(1,"uiControl"));
}


RING_FUNC(ring_uiControlHide)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiControlHide((uiControl *) RING_API_GETCPOINTER(1,"uiControl"));
}


RING_FUNC(ring_uiControlEnabled)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiControlEnabled((uiControl *) RING_API_GETCPOINTER(1,"uiControl")));
}


RING_FUNC(ring_uiControlEnable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiControlEnable((uiControl *) RING_API_GETCPOINTER(1,"uiControl"));
}


RING_FUNC(ring_uiControlDisable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiControlDisable((uiControl *) RING_API_GETCPOINTER(1,"uiControl"));
}


RING_FUNC(ring_uiAllocControl)
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
	RING_API_RETCPOINTER(uiAllocControl( (size_t ) RING_API_GETNUMBER(1), (uint32_t ) RING_API_GETNUMBER(2), (uint32_t ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4)),"uiControl");
}


RING_FUNC(ring_uiFreeControl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeControl((uiControl *) RING_API_GETCPOINTER(1,"uiControl"));
}


RING_FUNC(ring_uiControlVerifySetParent)
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
	uiControlVerifySetParent((uiControl *) RING_API_GETCPOINTER(1,"uiControl"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"));
}


RING_FUNC(ring_uiControlEnabledToUser)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiControlEnabledToUser((uiControl *) RING_API_GETCPOINTER(1,"uiControl")));
}


RING_FUNC(ring_uiUserBugCannotSetParentOnToplevel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiUserBugCannotSetParentOnToplevel(RING_API_GETSTRING(1));
}


RING_FUNC(ring_uiWindowTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiWindowTitle((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow")));
}


RING_FUNC(ring_uiWindowSetTitle)
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
	uiWindowSetTitle((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiWindowContentSize)
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
	uiWindowContentSize((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"),RING_API_GETINTPOINTER(2),RING_API_GETINTPOINTER(3));
	RING_API_ACCEPTINTVALUE(2) ;
	RING_API_ACCEPTINTVALUE(3) ;
}


RING_FUNC(ring_uiWindowSetContentSize)
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
	uiWindowSetContentSize((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiWindowFullscreen)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiWindowFullscreen((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow")));
}


RING_FUNC(ring_uiWindowSetFullscreen)
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
	uiWindowSetFullscreen((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiWindowBorderless)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiWindowBorderless((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow")));
}


RING_FUNC(ring_uiWindowSetBorderless)
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
	uiWindowSetBorderless((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiWindowSetChild)
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
	uiWindowSetChild((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"));
}


RING_FUNC(ring_uiWindowMargined)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiWindowMargined((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow")));
}


RING_FUNC(ring_uiWindowSetMargined)
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
	uiWindowSetMargined((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewWindow)
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
	RING_API_RETCPOINTER(uiNewWindow(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)),"uiWindow");
}


RING_FUNC(ring_uiButtonText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiButtonText((uiButton *) RING_API_GETCPOINTER(1,"uiButton")));
}


RING_FUNC(ring_uiButtonSetText)
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
	uiButtonSetText((uiButton *) RING_API_GETCPOINTER(1,"uiButton"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiNewButton)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewButton(RING_API_GETSTRING(1)),"uiButton");
}


RING_FUNC(ring_uiBoxAppend)
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
	uiBoxAppend((uiBox *) RING_API_GETCPOINTER(1,"uiBox"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiBoxDelete)
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
	uiBoxDelete((uiBox *) RING_API_GETCPOINTER(1,"uiBox"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiBoxPadded)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiBoxPadded((uiBox *) RING_API_GETCPOINTER(1,"uiBox")));
}


RING_FUNC(ring_uiBoxSetPadded)
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
	uiBoxSetPadded((uiBox *) RING_API_GETCPOINTER(1,"uiBox"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewHorizontalBox)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewHorizontalBox(),"uiBox");
}


RING_FUNC(ring_uiNewVerticalBox)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewVerticalBox(),"uiBox");
}


RING_FUNC(ring_uiCheckboxText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiCheckboxText((uiCheckbox *) RING_API_GETCPOINTER(1,"uiCheckbox")));
}


RING_FUNC(ring_uiCheckboxSetText)
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
	uiCheckboxSetText((uiCheckbox *) RING_API_GETCPOINTER(1,"uiCheckbox"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiCheckboxChecked)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiCheckboxChecked((uiCheckbox *) RING_API_GETCPOINTER(1,"uiCheckbox")));
}


RING_FUNC(ring_uiCheckboxSetChecked)
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
	uiCheckboxSetChecked((uiCheckbox *) RING_API_GETCPOINTER(1,"uiCheckbox"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewCheckbox)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewCheckbox(RING_API_GETSTRING(1)),"uiCheckbox");
}


RING_FUNC(ring_uiEntryText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiEntryText((uiEntry *) RING_API_GETCPOINTER(1,"uiEntry")));
}


RING_FUNC(ring_uiEntrySetText)
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
	uiEntrySetText((uiEntry *) RING_API_GETCPOINTER(1,"uiEntry"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiEntryReadOnly)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiEntryReadOnly((uiEntry *) RING_API_GETCPOINTER(1,"uiEntry")));
}


RING_FUNC(ring_uiEntrySetReadOnly)
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
	uiEntrySetReadOnly((uiEntry *) RING_API_GETCPOINTER(1,"uiEntry"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewEntry(),"uiEntry");
}


RING_FUNC(ring_uiNewPasswordEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewPasswordEntry(),"uiEntry");
}


RING_FUNC(ring_uiNewSearchEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewSearchEntry(),"uiEntry");
}


RING_FUNC(ring_uiLabelText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiLabelText((uiLabel *) RING_API_GETCPOINTER(1,"uiLabel")));
}


RING_FUNC(ring_uiLabelSetText)
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
	uiLabelSetText((uiLabel *) RING_API_GETCPOINTER(1,"uiLabel"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiNewLabel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewLabel(RING_API_GETSTRING(1)),"uiLabel");
}


RING_FUNC(ring_uiTabAppend)
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
	uiTabAppend((uiTab *) RING_API_GETCPOINTER(1,"uiTab"),RING_API_GETSTRING(2),(uiControl *) RING_API_GETCPOINTER(3,"uiControl"));
}


RING_FUNC(ring_uiTabInsertAt)
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiTabInsertAt((uiTab *) RING_API_GETCPOINTER(1,"uiTab"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),(uiControl *) RING_API_GETCPOINTER(4,"uiControl"));
}


RING_FUNC(ring_uiTabDelete)
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
	uiTabDelete((uiTab *) RING_API_GETCPOINTER(1,"uiTab"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiTabNumPages)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiTabNumPages((uiTab *) RING_API_GETCPOINTER(1,"uiTab")));
}


RING_FUNC(ring_uiTabMargined)
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
	RING_API_RETNUMBER(uiTabMargined((uiTab *) RING_API_GETCPOINTER(1,"uiTab"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uiTabSetMargined)
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
	uiTabSetMargined((uiTab *) RING_API_GETCPOINTER(1,"uiTab"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiNewTab)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewTab(),"uiTab");
}


RING_FUNC(ring_uiGroupTitle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiGroupTitle((uiGroup *) RING_API_GETCPOINTER(1,"uiGroup")));
}


RING_FUNC(ring_uiGroupSetTitle)
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
	uiGroupSetTitle((uiGroup *) RING_API_GETCPOINTER(1,"uiGroup"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiGroupSetChild)
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
	uiGroupSetChild((uiGroup *) RING_API_GETCPOINTER(1,"uiGroup"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"));
}


RING_FUNC(ring_uiGroupMargined)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiGroupMargined((uiGroup *) RING_API_GETCPOINTER(1,"uiGroup")));
}


RING_FUNC(ring_uiGroupSetMargined)
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
	uiGroupSetMargined((uiGroup *) RING_API_GETCPOINTER(1,"uiGroup"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewGroup)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewGroup(RING_API_GETSTRING(1)),"uiGroup");
}


RING_FUNC(ring_uiSpinboxValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiSpinboxValue((uiSpinbox *) RING_API_GETCPOINTER(1,"uiSpinbox")));
}


RING_FUNC(ring_uiSpinboxSetValue)
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
	uiSpinboxSetValue((uiSpinbox *) RING_API_GETCPOINTER(1,"uiSpinbox"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewSpinbox)
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
	RING_API_RETCPOINTER(uiNewSpinbox( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)),"uiSpinbox");
}


RING_FUNC(ring_uiSliderValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiSliderValue((uiSlider *) RING_API_GETCPOINTER(1,"uiSlider")));
}


RING_FUNC(ring_uiSliderSetValue)
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
	uiSliderSetValue((uiSlider *) RING_API_GETCPOINTER(1,"uiSlider"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewSlider)
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
	RING_API_RETCPOINTER(uiNewSlider( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2)),"uiSlider");
}


RING_FUNC(ring_uiProgressBarValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiProgressBarValue((uiProgressBar *) RING_API_GETCPOINTER(1,"uiProgressBar")));
}


RING_FUNC(ring_uiProgressBarSetValue)
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
	uiProgressBarSetValue((uiProgressBar *) RING_API_GETCPOINTER(1,"uiProgressBar"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewProgressBar)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewProgressBar(),"uiProgressBar");
}


RING_FUNC(ring_uiNewHorizontalSeparator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewHorizontalSeparator(),"uiSeparator");
}


RING_FUNC(ring_uiNewVerticalSeparator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewVerticalSeparator(),"uiSeparator");
}


RING_FUNC(ring_uiComboboxAppend)
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
	uiComboboxAppend((uiCombobox *) RING_API_GETCPOINTER(1,"uiCombobox"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiComboboxSelected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiComboboxSelected((uiCombobox *) RING_API_GETCPOINTER(1,"uiCombobox")));
}


RING_FUNC(ring_uiComboboxSetSelected)
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
	uiComboboxSetSelected((uiCombobox *) RING_API_GETCPOINTER(1,"uiCombobox"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewCombobox)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewCombobox(),"uiCombobox");
}


RING_FUNC(ring_uiEditableComboboxAppend)
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
	uiEditableComboboxAppend((uiEditableCombobox *) RING_API_GETCPOINTER(1,"uiEditableCombobox"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiEditableComboboxText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiEditableComboboxText((uiEditableCombobox *) RING_API_GETCPOINTER(1,"uiEditableCombobox")));
}


RING_FUNC(ring_uiEditableComboboxSetText)
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
	uiEditableComboboxSetText((uiEditableCombobox *) RING_API_GETCPOINTER(1,"uiEditableCombobox"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiNewEditableCombobox)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewEditableCombobox(),"uiEditableCombobox");
}


RING_FUNC(ring_uiRadioButtonsAppend)
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
	uiRadioButtonsAppend((uiRadioButtons *) RING_API_GETCPOINTER(1,"uiRadioButtons"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiRadioButtonsSelected)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiRadioButtonsSelected((uiRadioButtons *) RING_API_GETCPOINTER(1,"uiRadioButtons")));
}


RING_FUNC(ring_uiRadioButtonsSetSelected)
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
	uiRadioButtonsSetSelected((uiRadioButtons *) RING_API_GETCPOINTER(1,"uiRadioButtons"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewRadioButtons)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewRadioButtons(),"uiRadioButtons");
}


RING_FUNC(ring_uiDateTimePickerTime)
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
	uiDateTimePickerTime((uiDateTimePicker *) RING_API_GETCPOINTER(1,"uiDateTimePicker"),(struct tm *) RING_API_GETCPOINTER(2,"struct tm"));
}


RING_FUNC(ring_uiDateTimePickerSetTime)
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
	uiDateTimePickerSetTime((uiDateTimePicker *) RING_API_GETCPOINTER(1,"uiDateTimePicker"),(struct tm *) RING_API_GETCPOINTER(2,"struct tm"));
}


RING_FUNC(ring_uiNewDateTimePicker)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewDateTimePicker(),"uiDateTimePicker");
}


RING_FUNC(ring_uiNewDatePicker)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewDatePicker(),"uiDateTimePicker");
}


RING_FUNC(ring_uiNewTimePicker)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewTimePicker(),"uiDateTimePicker");
}


RING_FUNC(ring_uiMultilineEntryText)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiMultilineEntryText((uiMultilineEntry *) RING_API_GETCPOINTER(1,"uiMultilineEntry")));
}


RING_FUNC(ring_uiMultilineEntrySetText)
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
	uiMultilineEntrySetText((uiMultilineEntry *) RING_API_GETCPOINTER(1,"uiMultilineEntry"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiMultilineEntryAppend)
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
	uiMultilineEntryAppend((uiMultilineEntry *) RING_API_GETCPOINTER(1,"uiMultilineEntry"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiMultilineEntryReadOnly)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiMultilineEntryReadOnly((uiMultilineEntry *) RING_API_GETCPOINTER(1,"uiMultilineEntry")));
}


RING_FUNC(ring_uiMultilineEntrySetReadOnly)
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
	uiMultilineEntrySetReadOnly((uiMultilineEntry *) RING_API_GETCPOINTER(1,"uiMultilineEntry"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewMultilineEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewMultilineEntry(),"uiMultilineEntry");
}


RING_FUNC(ring_uiNewNonWrappingMultilineEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewNonWrappingMultilineEntry(),"uiMultilineEntry");
}


RING_FUNC(ring_uiMenuItemEnable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiMenuItemEnable((uiMenuItem *) RING_API_GETCPOINTER(1,"uiMenuItem"));
}


RING_FUNC(ring_uiMenuItemDisable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiMenuItemDisable((uiMenuItem *) RING_API_GETCPOINTER(1,"uiMenuItem"));
}


RING_FUNC(ring_uiMenuItemChecked)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiMenuItemChecked((uiMenuItem *) RING_API_GETCPOINTER(1,"uiMenuItem")));
}


RING_FUNC(ring_uiMenuItemSetChecked)
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
	uiMenuItemSetChecked((uiMenuItem *) RING_API_GETCPOINTER(1,"uiMenuItem"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiMenuAppendItem)
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
	RING_API_RETCPOINTER(uiMenuAppendItem((uiMenu *) RING_API_GETCPOINTER(1,"uiMenu"),RING_API_GETSTRING(2)),"uiMenuItem");
}


RING_FUNC(ring_uiMenuAppendCheckItem)
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
	RING_API_RETCPOINTER(uiMenuAppendCheckItem((uiMenu *) RING_API_GETCPOINTER(1,"uiMenu"),RING_API_GETSTRING(2)),"uiMenuItem");
}


RING_FUNC(ring_uiMenuAppendQuitItem)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiMenuAppendQuitItem((uiMenu *) RING_API_GETCPOINTER(1,"uiMenu")),"uiMenuItem");
}


RING_FUNC(ring_uiMenuAppendPreferencesItem)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiMenuAppendPreferencesItem((uiMenu *) RING_API_GETCPOINTER(1,"uiMenu")),"uiMenuItem");
}


RING_FUNC(ring_uiMenuAppendAboutItem)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiMenuAppendAboutItem((uiMenu *) RING_API_GETCPOINTER(1,"uiMenu")),"uiMenuItem");
}


RING_FUNC(ring_uiMenuAppendSeparator)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiMenuAppendSeparator((uiMenu *) RING_API_GETCPOINTER(1,"uiMenu"));
}


RING_FUNC(ring_uiNewMenu)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewMenu(RING_API_GETSTRING(1)),"uiMenu");
}


RING_FUNC(ring_uiOpenFile)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiOpenFile((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow")));
}


RING_FUNC(ring_uiSaveFile)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiSaveFile((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow")));
}


RING_FUNC(ring_uiMsgBox)
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
	uiMsgBox((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"),RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_uiMsgBoxError)
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
	uiMsgBoxError((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"),RING_API_GETSTRING(2),RING_API_GETSTRING(3));
}


RING_FUNC(ring_uiAreaQueueRedrawAll)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiAreaQueueRedrawAll((uiArea *) RING_API_GETCPOINTER(1,"uiArea"));
}


RING_FUNC(ring_uiAreaScrollTo)
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
	uiAreaScrollTo((uiArea *) RING_API_GETCPOINTER(1,"uiArea"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_uiAreaBeginUserWindowMove)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiAreaBeginUserWindowMove((uiArea *) RING_API_GETCPOINTER(1,"uiArea"));
}


RING_FUNC(ring_uiAreaBeginUserWindowResize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiAreaBeginUserWindowResize((uiArea *) RING_API_GETCPOINTER(1,"uiArea"),* (uiWindowResizeEdge  *) RING_API_GETCPOINTER(2,"uiWindowResizeEdge"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uiWindowResizeEdge"));
}


RING_FUNC(ring_uiNewArea)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewArea((uiAreaHandler *) RING_API_GETCPOINTER(1,"uiAreaHandler")),"uiArea");
}


RING_FUNC(ring_uiNewScrollingArea)
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
	RING_API_RETCPOINTER(uiNewScrollingArea((uiAreaHandler *) RING_API_GETCPOINTER(1,"uiAreaHandler"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)),"uiArea");
}


RING_FUNC(ring_uiDrawNewPath)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(uiDrawNewPath(* (uiDrawFillMode  *) RING_API_GETCPOINTER(1,"uiDrawFillMode")),"uiDrawPath");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uiDrawFillMode"));
}


RING_FUNC(ring_uiDrawFreePath)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiDrawFreePath((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"));
}


RING_FUNC(ring_uiDrawPathNewFigure)
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
	uiDrawPathNewFigure((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiDrawPathNewFigureWithArc)
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
	uiDrawPathNewFigureWithArc((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5), (double ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7));
}


RING_FUNC(ring_uiDrawPathLineTo)
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
	uiDrawPathLineTo((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiDrawPathArcTo)
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
	uiDrawPathArcTo((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5), (double ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7));
}


RING_FUNC(ring_uiDrawPathBezierTo)
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
	uiDrawPathBezierTo((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5), (double ) RING_API_GETNUMBER(6), (double ) RING_API_GETNUMBER(7));
}


RING_FUNC(ring_uiDrawPathCloseFigure)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiDrawPathCloseFigure((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"));
}


RING_FUNC(ring_uiDrawPathAddRectangle)
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
	uiDrawPathAddRectangle((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_uiDrawPathEnd)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiDrawPathEnd((uiDrawPath *) RING_API_GETCPOINTER(1,"uiDrawPath"));
}


RING_FUNC(ring_uiDrawStroke)
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
	uiDrawStroke((uiDrawContext *) RING_API_GETCPOINTER(1,"uiDrawContext"),(uiDrawPath *) RING_API_GETCPOINTER(2,"uiDrawPath"),(uiDrawBrush *) RING_API_GETCPOINTER(3,"uiDrawBrush"),(uiDrawStrokeParams *) RING_API_GETCPOINTER(4,"uiDrawStrokeParams"));
}


RING_FUNC(ring_uiDrawFill)
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
	uiDrawFill((uiDrawContext *) RING_API_GETCPOINTER(1,"uiDrawContext"),(uiDrawPath *) RING_API_GETCPOINTER(2,"uiDrawPath"),(uiDrawBrush *) RING_API_GETCPOINTER(3,"uiDrawBrush"));
}


RING_FUNC(ring_uiDrawMatrixSetIdentity)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiDrawMatrixSetIdentity((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"));
}


RING_FUNC(ring_uiDrawMatrixTranslate)
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
	uiDrawMatrixTranslate((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiDrawMatrixScale)
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
	uiDrawMatrixScale((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_uiDrawMatrixRotate)
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
	uiDrawMatrixRotate((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_uiDrawMatrixSkew)
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
	uiDrawMatrixSkew((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_uiDrawMatrixMultiply)
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
	uiDrawMatrixMultiply((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"),(uiDrawMatrix *) RING_API_GETCPOINTER(2,"uiDrawMatrix"));
}


RING_FUNC(ring_uiDrawMatrixInvertible)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiDrawMatrixInvertible((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix")));
}


RING_FUNC(ring_uiDrawMatrixInvert)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiDrawMatrixInvert((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix")));
}


RING_FUNC(ring_uiDrawMatrixTransformPoint)
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
	uiDrawMatrixTransformPoint((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"),RING_API_GETDOUBLEPOINTER(2),RING_API_GETDOUBLEPOINTER(3));
}


RING_FUNC(ring_uiDrawMatrixTransformSize)
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
	uiDrawMatrixTransformSize((uiDrawMatrix *) RING_API_GETCPOINTER(1,"uiDrawMatrix"),RING_API_GETDOUBLEPOINTER(2),RING_API_GETDOUBLEPOINTER(3));
}


RING_FUNC(ring_uiDrawTransform)
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
	uiDrawTransform((uiDrawContext *) RING_API_GETCPOINTER(1,"uiDrawContext"),(uiDrawMatrix *) RING_API_GETCPOINTER(2,"uiDrawMatrix"));
}


RING_FUNC(ring_uiDrawClip)
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
	uiDrawClip((uiDrawContext *) RING_API_GETCPOINTER(1,"uiDrawContext"),(uiDrawPath *) RING_API_GETCPOINTER(2,"uiDrawPath"));
}


RING_FUNC(ring_uiDrawSave)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiDrawSave((uiDrawContext *) RING_API_GETCPOINTER(1,"uiDrawContext"));
}


RING_FUNC(ring_uiDrawRestore)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiDrawRestore((uiDrawContext *) RING_API_GETCPOINTER(1,"uiDrawContext"));
}


RING_FUNC(ring_uiAttributeGetType)
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
		uiAttributeType *pValue ; 
		pValue = (uiAttributeType *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiAttributeType)) ;
		*pValue = uiAttributeGetType((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute"));
		RING_API_RETMANAGEDCPOINTER(pValue,"uiAttributeType",ring_state_free);
	}
}


RING_FUNC(ring_uiNewFamilyAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewFamilyAttribute(RING_API_GETSTRING(1)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeFamily)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiAttributeFamily((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")));
}


RING_FUNC(ring_uiNewSizeAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewSizeAttribute( (double ) RING_API_GETNUMBER(1)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeSize)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributeSize((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")));
}


RING_FUNC(ring_uiNewStretchAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(uiNewStretchAttribute(* (uiTextStretch  *) RING_API_GETCPOINTER(1,"uiTextStretch")),"uiAttribute");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uiTextStretch"));
}


RING_FUNC(ring_uiAttributeStretch)
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
		uiTextStretch *pValue ; 
		pValue = (uiTextStretch *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTextStretch)) ;
		*pValue = uiAttributeStretch((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute"));
		RING_API_RETMANAGEDCPOINTER(pValue,"uiTextStretch",ring_state_free);
	}
}


RING_FUNC(ring_uiNewColorAttribute)
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
	RING_API_RETCPOINTER(uiNewColorAttribute( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeColor)
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
	uiAttributeColor((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute"),RING_API_GETDOUBLEPOINTER(2),RING_API_GETDOUBLEPOINTER(3),RING_API_GETDOUBLEPOINTER(4),RING_API_GETDOUBLEPOINTER(5));
}


RING_FUNC(ring_uiNewBackgroundAttribute)
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
	RING_API_RETCPOINTER(uiNewBackgroundAttribute( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4)),"uiAttribute");
}


RING_FUNC(ring_uiNewUnderlineAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(uiNewUnderlineAttribute(* (uiUnderline  *) RING_API_GETCPOINTER(1,"uiUnderline")),"uiAttribute");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uiUnderline"));
}


RING_FUNC(ring_uiAttributeUnderline)
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
		uiUnderline *pValue ; 
		pValue = (uiUnderline *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiUnderline)) ;
		*pValue = uiAttributeUnderline((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute"));
		RING_API_RETMANAGEDCPOINTER(pValue,"uiUnderline",ring_state_free);
	}
}


RING_FUNC(ring_uiNewUnderlineColorAttribute)
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewUnderlineColorAttribute(* (uiUnderlineColor  *) RING_API_GETCPOINTER(1,"uiUnderlineColor"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5)),"uiAttribute");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uiUnderlineColor"));
}


RING_FUNC(ring_uiAttributeUnderlineColor)
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
	uiAttributeUnderlineColor((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute"),(uiUnderlineColor *) RING_API_GETCPOINTER(2,"uiUnderlineColor"),RING_API_GETDOUBLEPOINTER(3),RING_API_GETDOUBLEPOINTER(4),RING_API_GETDOUBLEPOINTER(5),RING_API_GETDOUBLEPOINTER(6));
}


RING_FUNC(ring_uiNewOpenTypeFeatures)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewOpenTypeFeatures(),"uiOpenTypeFeatures");
}


RING_FUNC(ring_uiFreeOpenTypeFeatures)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeOpenTypeFeatures((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"));
}


RING_FUNC(ring_uiOpenTypeFeaturesClone)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiOpenTypeFeaturesClone((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures")),"uiOpenTypeFeatures");
}


RING_FUNC(ring_uiOpenTypeFeaturesAdd)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiOpenTypeFeaturesAdd((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"),* (char  *) RING_API_GETCPOINTER(2,"char"),* (char  *) RING_API_GETCPOINTER(3,"char"),* (char  *) RING_API_GETCPOINTER(4,"char"),* (char  *) RING_API_GETCPOINTER(5,"char"), (uint32_t ) RING_API_GETNUMBER(6));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"char"));
}


RING_FUNC(ring_uiOpenTypeFeaturesRemove)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiOpenTypeFeaturesRemove((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"),* (char  *) RING_API_GETCPOINTER(2,"char"),* (char  *) RING_API_GETCPOINTER(3,"char"),* (char  *) RING_API_GETCPOINTER(4,"char"),* (char  *) RING_API_GETCPOINTER(5,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"char"));
}


RING_FUNC(ring_uiOpenTypeFeaturesGet)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiOpenTypeFeaturesGet((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"),* (char  *) RING_API_GETCPOINTER(2,"char"),* (char  *) RING_API_GETCPOINTER(3,"char"),* (char  *) RING_API_GETCPOINTER(4,"char"),* (char  *) RING_API_GETCPOINTER(5,"char"),(uint32_t *) RING_API_GETCPOINTER(6,"uint32_t")));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"char"));
	if (RING_API_ISCPOINTERNOTASSIGNED(5))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(5,"char"));
}


RING_FUNC(ring_uiOpenTypeFeaturesForEach)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiOpenTypeFeaturesForEach((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"),* (uiOpenTypeFeaturesForEachFunc  *) RING_API_GETCPOINTER(2,"uiOpenTypeFeaturesForEachFunc"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uiOpenTypeFeaturesForEachFunc"));
}


RING_FUNC(ring_uiNewFeaturesAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewFeaturesAttribute((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures")),"uiAttribute");
}


RING_FUNC(ring_uiAttributeFeatures)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiAttributeFeatures((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")),"uiOpenTypeFeatures");
}


RING_FUNC(ring_uiNewAttributedString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewAttributedString(RING_API_GETSTRING(1)),"uiAttributedString");
}


RING_FUNC(ring_uiFreeAttributedString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeAttributedString((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"));
}


RING_FUNC(ring_uiAttributedStringString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiAttributedStringString((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString")));
}


RING_FUNC(ring_uiAttributedStringLen)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributedStringLen((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString")));
}


RING_FUNC(ring_uiAttributedStringAppendUnattributed)
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
	uiAttributedStringAppendUnattributed((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiAttributedStringInsertAtUnattributed)
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
	uiAttributedStringInsertAtUnattributed((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiAttributedStringDelete)
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
	uiAttributedStringDelete((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"), (size_t ) RING_API_GETNUMBER(2), (size_t ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiAttributedStringSetAttribute)
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
	uiAttributedStringSetAttribute((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"),(uiAttribute *) RING_API_GETCPOINTER(2,"uiAttribute"), (size_t ) RING_API_GETNUMBER(3), (size_t ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_uiAttributedStringForEachAttribute)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiAttributedStringForEachAttribute((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"),* (uiAttributedStringForEachAttributeFunc  *) RING_API_GETCPOINTER(2,"uiAttributedStringForEachAttributeFunc"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"uiAttributedStringForEachAttributeFunc"));
}


RING_FUNC(ring_uiAttributedStringNumGraphemes)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributedStringNumGraphemes((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString")));
}


RING_FUNC(ring_uiAttributedStringByteIndexToGrapheme)
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
	RING_API_RETNUMBER(uiAttributedStringByteIndexToGrapheme((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"), (size_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uiAttributedStringGraphemeToByteIndex)
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
	RING_API_RETNUMBER(uiAttributedStringGraphemeToByteIndex((uiAttributedString *) RING_API_GETCPOINTER(1,"uiAttributedString"), (size_t ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_uiDrawNewTextLayout)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiDrawNewTextLayout((uiDrawTextLayoutParams *) RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams")),"uiDrawTextLayout");
}


RING_FUNC(ring_uiDrawFreeTextLayout)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiDrawFreeTextLayout((uiDrawTextLayout *) RING_API_GETCPOINTER(1,"uiDrawTextLayout"));
}


RING_FUNC(ring_uiDrawText)
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
	uiDrawText((uiDrawContext *) RING_API_GETCPOINTER(1,"uiDrawContext"),(uiDrawTextLayout *) RING_API_GETCPOINTER(2,"uiDrawTextLayout"), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_uiDrawTextLayoutExtents)
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
	uiDrawTextLayoutExtents((uiDrawTextLayout *) RING_API_GETCPOINTER(1,"uiDrawTextLayout"),RING_API_GETDOUBLEPOINTER(2),RING_API_GETDOUBLEPOINTER(3));
}


RING_FUNC(ring_uiFontButtonFont)
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
	uiFontButtonFont((uiFontButton *) RING_API_GETCPOINTER(1,"uiFontButton"),(uiFontDescriptor *) RING_API_GETCPOINTER(2,"uiFontDescriptor"));
}


RING_FUNC(ring_uiNewFontButton)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewFontButton(),"uiFontButton");
}


RING_FUNC(ring_uiFreeFontButtonFont)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeFontButtonFont((uiFontDescriptor *) RING_API_GETCPOINTER(1,"uiFontDescriptor"));
}


RING_FUNC(ring_uiColorButtonColor)
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
	uiColorButtonColor((uiColorButton *) RING_API_GETCPOINTER(1,"uiColorButton"),RING_API_GETDOUBLEPOINTER(2),RING_API_GETDOUBLEPOINTER(3),RING_API_GETDOUBLEPOINTER(4),RING_API_GETDOUBLEPOINTER(5));
}


RING_FUNC(ring_uiColorButtonSetColor)
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
	uiColorButtonSetColor((uiColorButton *) RING_API_GETCPOINTER(1,"uiColorButton"), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_uiNewColorButton)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewColorButton(),"uiColorButton");
}


RING_FUNC(ring_uiFormAppend)
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
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFormAppend((uiForm *) RING_API_GETCPOINTER(1,"uiForm"),RING_API_GETSTRING(2),(uiControl *) RING_API_GETCPOINTER(3,"uiControl"), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_uiFormDelete)
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
	uiFormDelete((uiForm *) RING_API_GETCPOINTER(1,"uiForm"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiFormPadded)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiFormPadded((uiForm *) RING_API_GETCPOINTER(1,"uiForm")));
}


RING_FUNC(ring_uiFormSetPadded)
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
	uiFormSetPadded((uiForm *) RING_API_GETCPOINTER(1,"uiForm"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewForm)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewForm(),"uiForm");
}


RING_FUNC(ring_uiGridAppend)
{
	if ( RING_API_PARACOUNT != 10 ) {
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
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiGridAppend((uiGrid *) RING_API_GETCPOINTER(1,"uiGrid"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7),* (uiAlign  *) RING_API_GETCPOINTER(8,"uiAlign"), (int ) RING_API_GETNUMBER(9),* (uiAlign  *) RING_API_GETCPOINTER(10,"uiAlign"));
	if (RING_API_ISCPOINTERNOTASSIGNED(8))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(8,"uiAlign"));
	if (RING_API_ISCPOINTERNOTASSIGNED(10))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(10,"uiAlign"));
}


RING_FUNC(ring_uiGridInsertAt)
{
	if ( RING_API_PARACOUNT != 10 ) {
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
	if ( ! RING_API_ISNUMBER(9) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiGridInsertAt((uiGrid *) RING_API_GETCPOINTER(1,"uiGrid"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"),(uiControl *) RING_API_GETCPOINTER(3,"uiControl"),* (uiAt  *) RING_API_GETCPOINTER(4,"uiAt"), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7),* (uiAlign  *) RING_API_GETCPOINTER(8,"uiAlign"), (int ) RING_API_GETNUMBER(9),* (uiAlign  *) RING_API_GETCPOINTER(10,"uiAlign"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"uiAt"));
	if (RING_API_ISCPOINTERNOTASSIGNED(8))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(8,"uiAlign"));
	if (RING_API_ISCPOINTERNOTASSIGNED(10))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(10,"uiAlign"));
}


RING_FUNC(ring_uiGridPadded)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiGridPadded((uiGrid *) RING_API_GETCPOINTER(1,"uiGrid")));
}


RING_FUNC(ring_uiGridSetPadded)
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
	uiGridSetPadded((uiGrid *) RING_API_GETCPOINTER(1,"uiGrid"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewGrid)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(uiNewGrid(),"uiGrid");
}


RING_FUNC(ring_uiTableValueGetType)
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
		uiTableValueType *pValue ; 
		pValue = (uiTableValueType *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTableValueType)) ;
		*pValue = uiTableValueGetType((uiTableValue *) RING_API_GETCPOINTER(1,"uiTableValue"));
		RING_API_RETMANAGEDCPOINTER(pValue,"uiTableValueType",ring_state_free);
	}
}


RING_FUNC(ring_uiNewTableValueString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewTableValueString(RING_API_GETSTRING(1)),"uiTableValue");
}


RING_FUNC(ring_uiTableValueString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiTableValueString((uiTableValue *) RING_API_GETCPOINTER(1,"uiTableValue")));
}


RING_FUNC(ring_uiNewTableValueImage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewTableValueImage((uiImage *) RING_API_GETCPOINTER(1,"uiImage")),"uiTableValue");
}


RING_FUNC(ring_uiTableValueImage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiTableValueImage((uiTableValue *) RING_API_GETCPOINTER(1,"uiTableValue")),"uiImage");
}


RING_FUNC(ring_uiNewTableValueInt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewTableValueInt( (int ) RING_API_GETNUMBER(1)),"uiTableValue");
}


RING_FUNC(ring_uiTableValueInt)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiTableValueInt((uiTableValue *) RING_API_GETCPOINTER(1,"uiTableValue")));
}


RING_FUNC(ring_uiNewTableValueColor)
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
	RING_API_RETCPOINTER(uiNewTableValueColor( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4)),"uiTableValue");
}


RING_FUNC(ring_uiTableValueColor)
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
	uiTableValueColor((uiTableValue *) RING_API_GETCPOINTER(1,"uiTableValue"),RING_API_GETDOUBLEPOINTER(2),RING_API_GETDOUBLEPOINTER(3),RING_API_GETDOUBLEPOINTER(4),RING_API_GETDOUBLEPOINTER(5));
}


RING_FUNC(ring_uiNewImage)
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
	RING_API_RETCPOINTER(uiNewImage( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2)),"uiImage");
}


RING_FUNC(ring_uiFreeImage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeImage((uiImage *) RING_API_GETCPOINTER(1,"uiImage"));
}


RING_FUNC(ring_uiImageAppend)
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
	uiImageAppend((uiImage *) RING_API_GETCPOINTER(1,"uiImage"),(void *) RING_API_GETCPOINTER(2,"void"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_uiFreeTableValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeTableValue((uiTableValue *) RING_API_GETCPOINTER(1,"uiTableValue"));
}


RING_FUNC(ring_uiNewTableModel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewTableModel((uiTableModelHandler *) RING_API_GETCPOINTER(1,"uiTableModelHandler")),"uiTableModel");
}


RING_FUNC(ring_uiFreeTableModel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeTableModel((uiTableModel *) RING_API_GETCPOINTER(1,"uiTableModel"));
}


RING_FUNC(ring_uiTableModelRowInserted)
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
	uiTableModelRowInserted((uiTableModel *) RING_API_GETCPOINTER(1,"uiTableModel"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiTableModelRowChanged)
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
	uiTableModelRowChanged((uiTableModel *) RING_API_GETCPOINTER(1,"uiTableModel"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiTableModelRowDeleted)
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
	uiTableModelRowDeleted((uiTableModel *) RING_API_GETCPOINTER(1,"uiTableModel"), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewWeightAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewWeightAttribute( (uiTextWeight )  (int) RING_API_GETNUMBER(1)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeWeight)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributeWeight((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")));
}


RING_FUNC(ring_uiNewItalicAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_RETCPOINTER(uiNewItalicAttribute(* (uiTextItalic  *) RING_API_GETCPOINTER(1,"uiTextItalic")),"uiAttribute");
	if (RING_API_ISCPOINTERNOTASSIGNED(1))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(1,"uiTextItalic"));
}


RING_FUNC(ring_uiAttributeItalic)
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
		uiTextItalic *pValue ; 
		pValue = (uiTextItalic *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTextItalic)) ;
		*pValue = uiAttributeItalic((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute"));
		RING_API_RETMANAGEDCPOINTER(pValue,"uiTextItalic",ring_state_free);
	}
}


RING_FUNC(ring_uiFreeAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiFreeAttribute((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute"));
}


RING_FUNC(ring_uiTableAppendTextColumn)
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiTableAppendTextColumn((uiTable *) RING_API_GETCPOINTER(1,"uiTable"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4),(uiTableTextColumnOptionalParams *) RING_API_GETCPOINTER(5,"uiTableTextColumnOptionalParams"));
}


RING_FUNC(ring_uiTableAppendImageColumn)
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
	uiTableAppendImageColumn((uiTable *) RING_API_GETCPOINTER(1,"uiTable"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiTableAppendImageTextColumn)
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
	uiTableAppendImageTextColumn((uiTable *) RING_API_GETCPOINTER(1,"uiTable"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5),(uiTableTextColumnOptionalParams *) RING_API_GETCPOINTER(6,"uiTableTextColumnOptionalParams"));
}


RING_FUNC(ring_uiTableAppendCheckboxColumn)
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
	uiTableAppendCheckboxColumn((uiTable *) RING_API_GETCPOINTER(1,"uiTable"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_uiTableAppendCheckboxTextColumn)
{
	if ( RING_API_PARACOUNT != 7 ) {
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
	if ( ! RING_API_ISNUMBER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiTableAppendCheckboxTextColumn((uiTable *) RING_API_GETCPOINTER(1,"uiTable"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6),(uiTableTextColumnOptionalParams *) RING_API_GETCPOINTER(7,"uiTableTextColumnOptionalParams"));
}


RING_FUNC(ring_uiTableAppendProgressBarColumn)
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
	uiTableAppendProgressBarColumn((uiTable *) RING_API_GETCPOINTER(1,"uiTable"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiTableAppendButtonColumn)
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
	uiTableAppendButtonColumn((uiTable *) RING_API_GETCPOINTER(1,"uiTable"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4));
}


RING_FUNC(ring_uiNewTable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewTable((uiTableParams *) RING_API_GETCPOINTER(1,"uiTableParams")),"uiTable");
}


RING_FUNC(ring_uiAreaSetSize)
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
	uiAreaSetSize((uiArea *) RING_API_GETCPOINTER(1,"uiArea"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("uiinit",ring_uiInit);
	ring_vm_funcregister("uiuninit",ring_uiUninit);
	ring_vm_funcregister("uifreeiniterror",ring_uiFreeInitError);
	ring_vm_funcregister("uimain",ring_uiMain);
	ring_vm_funcregister("uimainsteps",ring_uiMainSteps);
	ring_vm_funcregister("uimainstep",ring_uiMainStep);
	ring_vm_funcregister("uiquit",ring_uiQuit);
	ring_vm_funcregister("uicontroldestroy",ring_uiControlDestroy);
	ring_vm_funcregister("uicontrolparent",ring_uiControlParent);
	ring_vm_funcregister("uicontrolsetparent",ring_uiControlSetParent);
	ring_vm_funcregister("uicontroltoplevel",ring_uiControlToplevel);
	ring_vm_funcregister("uicontrolvisible",ring_uiControlVisible);
	ring_vm_funcregister("uicontrolshow",ring_uiControlShow);
	ring_vm_funcregister("uicontrolhide",ring_uiControlHide);
	ring_vm_funcregister("uicontrolenabled",ring_uiControlEnabled);
	ring_vm_funcregister("uicontrolenable",ring_uiControlEnable);
	ring_vm_funcregister("uicontroldisable",ring_uiControlDisable);
	ring_vm_funcregister("uialloccontrol",ring_uiAllocControl);
	ring_vm_funcregister("uifreecontrol",ring_uiFreeControl);
	ring_vm_funcregister("uicontrolverifysetparent",ring_uiControlVerifySetParent);
	ring_vm_funcregister("uicontrolenabledtouser",ring_uiControlEnabledToUser);
	ring_vm_funcregister("uiuserbugcannotsetparentontoplevel",ring_uiUserBugCannotSetParentOnToplevel);
	ring_vm_funcregister("uiwindowtitle",ring_uiWindowTitle);
	ring_vm_funcregister("uiwindowsettitle",ring_uiWindowSetTitle);
	ring_vm_funcregister("uiwindowcontentsize",ring_uiWindowContentSize);
	ring_vm_funcregister("uiwindowsetcontentsize",ring_uiWindowSetContentSize);
	ring_vm_funcregister("uiwindowfullscreen",ring_uiWindowFullscreen);
	ring_vm_funcregister("uiwindowsetfullscreen",ring_uiWindowSetFullscreen);
	ring_vm_funcregister("uiwindowborderless",ring_uiWindowBorderless);
	ring_vm_funcregister("uiwindowsetborderless",ring_uiWindowSetBorderless);
	ring_vm_funcregister("uiwindowsetchild",ring_uiWindowSetChild);
	ring_vm_funcregister("uiwindowmargined",ring_uiWindowMargined);
	ring_vm_funcregister("uiwindowsetmargined",ring_uiWindowSetMargined);
	ring_vm_funcregister("uinewwindow",ring_uiNewWindow);
	ring_vm_funcregister("uibuttontext",ring_uiButtonText);
	ring_vm_funcregister("uibuttonsettext",ring_uiButtonSetText);
	ring_vm_funcregister("uinewbutton",ring_uiNewButton);
	ring_vm_funcregister("uiboxappend",ring_uiBoxAppend);
	ring_vm_funcregister("uiboxdelete",ring_uiBoxDelete);
	ring_vm_funcregister("uiboxpadded",ring_uiBoxPadded);
	ring_vm_funcregister("uiboxsetpadded",ring_uiBoxSetPadded);
	ring_vm_funcregister("uinewhorizontalbox",ring_uiNewHorizontalBox);
	ring_vm_funcregister("uinewverticalbox",ring_uiNewVerticalBox);
	ring_vm_funcregister("uicheckboxtext",ring_uiCheckboxText);
	ring_vm_funcregister("uicheckboxsettext",ring_uiCheckboxSetText);
	ring_vm_funcregister("uicheckboxchecked",ring_uiCheckboxChecked);
	ring_vm_funcregister("uicheckboxsetchecked",ring_uiCheckboxSetChecked);
	ring_vm_funcregister("uinewcheckbox",ring_uiNewCheckbox);
	ring_vm_funcregister("uientrytext",ring_uiEntryText);
	ring_vm_funcregister("uientrysettext",ring_uiEntrySetText);
	ring_vm_funcregister("uientryreadonly",ring_uiEntryReadOnly);
	ring_vm_funcregister("uientrysetreadonly",ring_uiEntrySetReadOnly);
	ring_vm_funcregister("uinewentry",ring_uiNewEntry);
	ring_vm_funcregister("uinewpasswordentry",ring_uiNewPasswordEntry);
	ring_vm_funcregister("uinewsearchentry",ring_uiNewSearchEntry);
	ring_vm_funcregister("uilabeltext",ring_uiLabelText);
	ring_vm_funcregister("uilabelsettext",ring_uiLabelSetText);
	ring_vm_funcregister("uinewlabel",ring_uiNewLabel);
	ring_vm_funcregister("uitabappend",ring_uiTabAppend);
	ring_vm_funcregister("uitabinsertat",ring_uiTabInsertAt);
	ring_vm_funcregister("uitabdelete",ring_uiTabDelete);
	ring_vm_funcregister("uitabnumpages",ring_uiTabNumPages);
	ring_vm_funcregister("uitabmargined",ring_uiTabMargined);
	ring_vm_funcregister("uitabsetmargined",ring_uiTabSetMargined);
	ring_vm_funcregister("uinewtab",ring_uiNewTab);
	ring_vm_funcregister("uigrouptitle",ring_uiGroupTitle);
	ring_vm_funcregister("uigroupsettitle",ring_uiGroupSetTitle);
	ring_vm_funcregister("uigroupsetchild",ring_uiGroupSetChild);
	ring_vm_funcregister("uigroupmargined",ring_uiGroupMargined);
	ring_vm_funcregister("uigroupsetmargined",ring_uiGroupSetMargined);
	ring_vm_funcregister("uinewgroup",ring_uiNewGroup);
	ring_vm_funcregister("uispinboxvalue",ring_uiSpinboxValue);
	ring_vm_funcregister("uispinboxsetvalue",ring_uiSpinboxSetValue);
	ring_vm_funcregister("uinewspinbox",ring_uiNewSpinbox);
	ring_vm_funcregister("uislidervalue",ring_uiSliderValue);
	ring_vm_funcregister("uislidersetvalue",ring_uiSliderSetValue);
	ring_vm_funcregister("uinewslider",ring_uiNewSlider);
	ring_vm_funcregister("uiprogressbarvalue",ring_uiProgressBarValue);
	ring_vm_funcregister("uiprogressbarsetvalue",ring_uiProgressBarSetValue);
	ring_vm_funcregister("uinewprogressbar",ring_uiNewProgressBar);
	ring_vm_funcregister("uinewhorizontalseparator",ring_uiNewHorizontalSeparator);
	ring_vm_funcregister("uinewverticalseparator",ring_uiNewVerticalSeparator);
	ring_vm_funcregister("uicomboboxappend",ring_uiComboboxAppend);
	ring_vm_funcregister("uicomboboxselected",ring_uiComboboxSelected);
	ring_vm_funcregister("uicomboboxsetselected",ring_uiComboboxSetSelected);
	ring_vm_funcregister("uinewcombobox",ring_uiNewCombobox);
	ring_vm_funcregister("uieditablecomboboxappend",ring_uiEditableComboboxAppend);
	ring_vm_funcregister("uieditablecomboboxtext",ring_uiEditableComboboxText);
	ring_vm_funcregister("uieditablecomboboxsettext",ring_uiEditableComboboxSetText);
	ring_vm_funcregister("uineweditablecombobox",ring_uiNewEditableCombobox);
	ring_vm_funcregister("uiradiobuttonsappend",ring_uiRadioButtonsAppend);
	ring_vm_funcregister("uiradiobuttonsselected",ring_uiRadioButtonsSelected);
	ring_vm_funcregister("uiradiobuttonssetselected",ring_uiRadioButtonsSetSelected);
	ring_vm_funcregister("uinewradiobuttons",ring_uiNewRadioButtons);
	ring_vm_funcregister("uidatetimepickertime",ring_uiDateTimePickerTime);
	ring_vm_funcregister("uidatetimepickersettime",ring_uiDateTimePickerSetTime);
	ring_vm_funcregister("uinewdatetimepicker",ring_uiNewDateTimePicker);
	ring_vm_funcregister("uinewdatepicker",ring_uiNewDatePicker);
	ring_vm_funcregister("uinewtimepicker",ring_uiNewTimePicker);
	ring_vm_funcregister("uimultilineentrytext",ring_uiMultilineEntryText);
	ring_vm_funcregister("uimultilineentrysettext",ring_uiMultilineEntrySetText);
	ring_vm_funcregister("uimultilineentryappend",ring_uiMultilineEntryAppend);
	ring_vm_funcregister("uimultilineentryreadonly",ring_uiMultilineEntryReadOnly);
	ring_vm_funcregister("uimultilineentrysetreadonly",ring_uiMultilineEntrySetReadOnly);
	ring_vm_funcregister("uinewmultilineentry",ring_uiNewMultilineEntry);
	ring_vm_funcregister("uinewnonwrappingmultilineentry",ring_uiNewNonWrappingMultilineEntry);
	ring_vm_funcregister("uimenuitemenable",ring_uiMenuItemEnable);
	ring_vm_funcregister("uimenuitemdisable",ring_uiMenuItemDisable);
	ring_vm_funcregister("uimenuitemchecked",ring_uiMenuItemChecked);
	ring_vm_funcregister("uimenuitemsetchecked",ring_uiMenuItemSetChecked);
	ring_vm_funcregister("uimenuappenditem",ring_uiMenuAppendItem);
	ring_vm_funcregister("uimenuappendcheckitem",ring_uiMenuAppendCheckItem);
	ring_vm_funcregister("uimenuappendquititem",ring_uiMenuAppendQuitItem);
	ring_vm_funcregister("uimenuappendpreferencesitem",ring_uiMenuAppendPreferencesItem);
	ring_vm_funcregister("uimenuappendaboutitem",ring_uiMenuAppendAboutItem);
	ring_vm_funcregister("uimenuappendseparator",ring_uiMenuAppendSeparator);
	ring_vm_funcregister("uinewmenu",ring_uiNewMenu);
	ring_vm_funcregister("uiopenfile",ring_uiOpenFile);
	ring_vm_funcregister("uisavefile",ring_uiSaveFile);
	ring_vm_funcregister("uimsgbox",ring_uiMsgBox);
	ring_vm_funcregister("uimsgboxerror",ring_uiMsgBoxError);
	ring_vm_funcregister("uiareaqueueredrawall",ring_uiAreaQueueRedrawAll);
	ring_vm_funcregister("uiareascrollto",ring_uiAreaScrollTo);
	ring_vm_funcregister("uiareabeginuserwindowmove",ring_uiAreaBeginUserWindowMove);
	ring_vm_funcregister("uiareabeginuserwindowresize",ring_uiAreaBeginUserWindowResize);
	ring_vm_funcregister("uinewarea",ring_uiNewArea);
	ring_vm_funcregister("uinewscrollingarea",ring_uiNewScrollingArea);
	ring_vm_funcregister("uidrawnewpath",ring_uiDrawNewPath);
	ring_vm_funcregister("uidrawfreepath",ring_uiDrawFreePath);
	ring_vm_funcregister("uidrawpathnewfigure",ring_uiDrawPathNewFigure);
	ring_vm_funcregister("uidrawpathnewfigurewitharc",ring_uiDrawPathNewFigureWithArc);
	ring_vm_funcregister("uidrawpathlineto",ring_uiDrawPathLineTo);
	ring_vm_funcregister("uidrawpatharcto",ring_uiDrawPathArcTo);
	ring_vm_funcregister("uidrawpathbezierto",ring_uiDrawPathBezierTo);
	ring_vm_funcregister("uidrawpathclosefigure",ring_uiDrawPathCloseFigure);
	ring_vm_funcregister("uidrawpathaddrectangle",ring_uiDrawPathAddRectangle);
	ring_vm_funcregister("uidrawpathend",ring_uiDrawPathEnd);
	ring_vm_funcregister("uidrawstroke",ring_uiDrawStroke);
	ring_vm_funcregister("uidrawfill",ring_uiDrawFill);
	ring_vm_funcregister("uidrawmatrixsetidentity",ring_uiDrawMatrixSetIdentity);
	ring_vm_funcregister("uidrawmatrixtranslate",ring_uiDrawMatrixTranslate);
	ring_vm_funcregister("uidrawmatrixscale",ring_uiDrawMatrixScale);
	ring_vm_funcregister("uidrawmatrixrotate",ring_uiDrawMatrixRotate);
	ring_vm_funcregister("uidrawmatrixskew",ring_uiDrawMatrixSkew);
	ring_vm_funcregister("uidrawmatrixmultiply",ring_uiDrawMatrixMultiply);
	ring_vm_funcregister("uidrawmatrixinvertible",ring_uiDrawMatrixInvertible);
	ring_vm_funcregister("uidrawmatrixinvert",ring_uiDrawMatrixInvert);
	ring_vm_funcregister("uidrawmatrixtransformpoint",ring_uiDrawMatrixTransformPoint);
	ring_vm_funcregister("uidrawmatrixtransformsize",ring_uiDrawMatrixTransformSize);
	ring_vm_funcregister("uidrawtransform",ring_uiDrawTransform);
	ring_vm_funcregister("uidrawclip",ring_uiDrawClip);
	ring_vm_funcregister("uidrawsave",ring_uiDrawSave);
	ring_vm_funcregister("uidrawrestore",ring_uiDrawRestore);
	ring_vm_funcregister("uiattributegettype",ring_uiAttributeGetType);
	ring_vm_funcregister("uinewfamilyattribute",ring_uiNewFamilyAttribute);
	ring_vm_funcregister("uiattributefamily",ring_uiAttributeFamily);
	ring_vm_funcregister("uinewsizeattribute",ring_uiNewSizeAttribute);
	ring_vm_funcregister("uiattributesize",ring_uiAttributeSize);
	ring_vm_funcregister("uinewstretchattribute",ring_uiNewStretchAttribute);
	ring_vm_funcregister("uiattributestretch",ring_uiAttributeStretch);
	ring_vm_funcregister("uinewcolorattribute",ring_uiNewColorAttribute);
	ring_vm_funcregister("uiattributecolor",ring_uiAttributeColor);
	ring_vm_funcregister("uinewbackgroundattribute",ring_uiNewBackgroundAttribute);
	ring_vm_funcregister("uinewunderlineattribute",ring_uiNewUnderlineAttribute);
	ring_vm_funcregister("uiattributeunderline",ring_uiAttributeUnderline);
	ring_vm_funcregister("uinewunderlinecolorattribute",ring_uiNewUnderlineColorAttribute);
	ring_vm_funcregister("uiattributeunderlinecolor",ring_uiAttributeUnderlineColor);
	ring_vm_funcregister("uinewopentypefeatures",ring_uiNewOpenTypeFeatures);
	ring_vm_funcregister("uifreeopentypefeatures",ring_uiFreeOpenTypeFeatures);
	ring_vm_funcregister("uiopentypefeaturesclone",ring_uiOpenTypeFeaturesClone);
	ring_vm_funcregister("uiopentypefeaturesadd",ring_uiOpenTypeFeaturesAdd);
	ring_vm_funcregister("uiopentypefeaturesremove",ring_uiOpenTypeFeaturesRemove);
	ring_vm_funcregister("uiopentypefeaturesget",ring_uiOpenTypeFeaturesGet);
	ring_vm_funcregister("uiopentypefeaturesforeach",ring_uiOpenTypeFeaturesForEach);
	ring_vm_funcregister("uinewfeaturesattribute",ring_uiNewFeaturesAttribute);
	ring_vm_funcregister("uiattributefeatures",ring_uiAttributeFeatures);
	ring_vm_funcregister("uinewattributedstring",ring_uiNewAttributedString);
	ring_vm_funcregister("uifreeattributedstring",ring_uiFreeAttributedString);
	ring_vm_funcregister("uiattributedstringstring",ring_uiAttributedStringString);
	ring_vm_funcregister("uiattributedstringlen",ring_uiAttributedStringLen);
	ring_vm_funcregister("uiattributedstringappendunattributed",ring_uiAttributedStringAppendUnattributed);
	ring_vm_funcregister("uiattributedstringinsertatunattributed",ring_uiAttributedStringInsertAtUnattributed);
	ring_vm_funcregister("uiattributedstringdelete",ring_uiAttributedStringDelete);
	ring_vm_funcregister("uiattributedstringsetattribute",ring_uiAttributedStringSetAttribute);
	ring_vm_funcregister("uiattributedstringforeachattribute",ring_uiAttributedStringForEachAttribute);
	ring_vm_funcregister("uiattributedstringnumgraphemes",ring_uiAttributedStringNumGraphemes);
	ring_vm_funcregister("uiattributedstringbyteindextographeme",ring_uiAttributedStringByteIndexToGrapheme);
	ring_vm_funcregister("uiattributedstringgraphemetobyteindex",ring_uiAttributedStringGraphemeToByteIndex);
	ring_vm_funcregister("uidrawnewtextlayout",ring_uiDrawNewTextLayout);
	ring_vm_funcregister("uidrawfreetextlayout",ring_uiDrawFreeTextLayout);
	ring_vm_funcregister("uidrawtext",ring_uiDrawText);
	ring_vm_funcregister("uidrawtextlayoutextents",ring_uiDrawTextLayoutExtents);
	ring_vm_funcregister("uifontbuttonfont",ring_uiFontButtonFont);
	ring_vm_funcregister("uinewfontbutton",ring_uiNewFontButton);
	ring_vm_funcregister("uifreefontbuttonfont",ring_uiFreeFontButtonFont);
	ring_vm_funcregister("uicolorbuttoncolor",ring_uiColorButtonColor);
	ring_vm_funcregister("uicolorbuttonsetcolor",ring_uiColorButtonSetColor);
	ring_vm_funcregister("uinewcolorbutton",ring_uiNewColorButton);
	ring_vm_funcregister("uiformappend",ring_uiFormAppend);
	ring_vm_funcregister("uiformdelete",ring_uiFormDelete);
	ring_vm_funcregister("uiformpadded",ring_uiFormPadded);
	ring_vm_funcregister("uiformsetpadded",ring_uiFormSetPadded);
	ring_vm_funcregister("uinewform",ring_uiNewForm);
	ring_vm_funcregister("uigridappend",ring_uiGridAppend);
	ring_vm_funcregister("uigridinsertat",ring_uiGridInsertAt);
	ring_vm_funcregister("uigridpadded",ring_uiGridPadded);
	ring_vm_funcregister("uigridsetpadded",ring_uiGridSetPadded);
	ring_vm_funcregister("uinewgrid",ring_uiNewGrid);
	ring_vm_funcregister("uitablevaluegettype",ring_uiTableValueGetType);
	ring_vm_funcregister("uinewtablevaluestring",ring_uiNewTableValueString);
	ring_vm_funcregister("uitablevaluestring",ring_uiTableValueString);
	ring_vm_funcregister("uinewtablevalueimage",ring_uiNewTableValueImage);
	ring_vm_funcregister("uitablevalueimage",ring_uiTableValueImage);
	ring_vm_funcregister("uinewtablevalueint",ring_uiNewTableValueInt);
	ring_vm_funcregister("uitablevalueint",ring_uiTableValueInt);
	ring_vm_funcregister("uinewtablevaluecolor",ring_uiNewTableValueColor);
	ring_vm_funcregister("uitablevaluecolor",ring_uiTableValueColor);
	ring_vm_funcregister("uinewimage",ring_uiNewImage);
	ring_vm_funcregister("uifreeimage",ring_uiFreeImage);
	ring_vm_funcregister("uiimageappend",ring_uiImageAppend);
	ring_vm_funcregister("uifreetablevalue",ring_uiFreeTableValue);
	ring_vm_funcregister("uinewtablemodel",ring_uiNewTableModel);
	ring_vm_funcregister("uifreetablemodel",ring_uiFreeTableModel);
	ring_vm_funcregister("uitablemodelrowinserted",ring_uiTableModelRowInserted);
	ring_vm_funcregister("uitablemodelrowchanged",ring_uiTableModelRowChanged);
	ring_vm_funcregister("uitablemodelrowdeleted",ring_uiTableModelRowDeleted);
	ring_vm_funcregister("uinewweightattribute",ring_uiNewWeightAttribute);
	ring_vm_funcregister("uiattributeweight",ring_uiAttributeWeight);
	ring_vm_funcregister("uinewitalicattribute",ring_uiNewItalicAttribute);
	ring_vm_funcregister("uiattributeitalic",ring_uiAttributeItalic);
	ring_vm_funcregister("uifreeattribute",ring_uiFreeAttribute);
	ring_vm_funcregister("uitableappendtextcolumn",ring_uiTableAppendTextColumn);
	ring_vm_funcregister("uitableappendimagecolumn",ring_uiTableAppendImageColumn);
	ring_vm_funcregister("uitableappendimagetextcolumn",ring_uiTableAppendImageTextColumn);
	ring_vm_funcregister("uitableappendcheckboxcolumn",ring_uiTableAppendCheckboxColumn);
	ring_vm_funcregister("uitableappendcheckboxtextcolumn",ring_uiTableAppendCheckboxTextColumn);
	ring_vm_funcregister("uitableappendprogressbarcolumn",ring_uiTableAppendProgressBarColumn);
	ring_vm_funcregister("uitableappendbuttoncolumn",ring_uiTableAppendButtonColumn);
	ring_vm_funcregister("uinewtable",ring_uiNewTable);
	ring_vm_funcregister("uiareasetsize",ring_uiAreaSetSize);
	ring_vm_funcregister("get_uipi",ring_get_uipi);
	ring_vm_funcregister("get_uiforeachcontinue",ring_get_uiforeachcontinue);
	ring_vm_funcregister("get_uiforeachstop",ring_get_uiforeachstop);
	ring_vm_funcregister("new_uiinitoptions",ring_new_uiinitoptions);
	ring_vm_funcregister("new_managed_uiinitoptions",ring_new_managed_uiinitoptions);
	ring_vm_funcregister("destroy_uiinitoptions",ring_destroy_uiinitoptions);
}

#include "ring.h"

/* Copyright (c) 2020 Mahmoud Fayed <msfclipper@yahoo.com> */

#include <ui.h>
#include <windows.h>
#include <ui_windows.h>

RING_FUNC(ring_get_uipi)
{
	RING_API_RETNUMBER(uiPi);
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
	ring_vm_funcregister("get_uipi",ring_get_uipi);
}

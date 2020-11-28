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
	ring_vm_funcregister("get_uipi",ring_get_uipi);
}

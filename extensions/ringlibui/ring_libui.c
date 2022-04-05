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

RING_FUNC(ring_get_uiwindowresizeedgeleft)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeLeft);
}

RING_FUNC(ring_get_uiwindowresizeedgetop)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeTop);
}

RING_FUNC(ring_get_uiwindowresizeedgeright)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeRight);
}

RING_FUNC(ring_get_uiwindowresizeedgebottom)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeBottom);
}

RING_FUNC(ring_get_uiwindowresizeedgetopleft)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeTopLeft);
}

RING_FUNC(ring_get_uiwindowresizeedgetopright)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeTopRight);
}

RING_FUNC(ring_get_uiwindowresizeedgebottomleft)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeBottomLeft);
}

RING_FUNC(ring_get_uiwindowresizeedgebottomright)
{
	RING_API_RETNUMBER(uiWindowResizeEdgeBottomRight);
}

RING_FUNC(ring_get_uidrawbrushtypesolid)
{
	RING_API_RETNUMBER(uiDrawBrushTypeSolid);
}

RING_FUNC(ring_get_uidrawbrushtypelineargradient)
{
	RING_API_RETNUMBER(uiDrawBrushTypeLinearGradient);
}

RING_FUNC(ring_get_uidrawbrushtyperadialgradient)
{
	RING_API_RETNUMBER(uiDrawBrushTypeRadialGradient);
}

RING_FUNC(ring_get_uidrawbrushtypeimage)
{
	RING_API_RETNUMBER(uiDrawBrushTypeImage);
}

RING_FUNC(ring_get_uidrawdefaultmiterlimit)
{
	RING_API_RETNUMBER(uiDrawDefaultMiterLimit);
}

RING_FUNC(ring_get_uitablemodelcolumnnevereditable)
{
	RING_API_RETNUMBER(uiTableModelColumnNeverEditable);
}

RING_FUNC(ring_get_uitablemodelcolumnalwayseditable)
{
	RING_API_RETNUMBER(uiTableModelColumnAlwaysEditable);
}

RING_FUNC(ring_get_uidrawlinecapflat)
{
	RING_API_RETNUMBER(uiDrawLineCapFlat);
}

RING_FUNC(ring_get_uidrawlinecapround)
{
	RING_API_RETNUMBER(uiDrawLineCapRound);
}

RING_FUNC(ring_get_uidrawlinecapsquare)
{
	RING_API_RETNUMBER(uiDrawLineCapSquare);
}

RING_FUNC(ring_get_uidrawlinejoinmiter)
{
	RING_API_RETNUMBER(uiDrawLineJoinMiter);
}

RING_FUNC(ring_get_uidrawlinejoinround)
{
	RING_API_RETNUMBER(uiDrawLineJoinRound);
}

RING_FUNC(ring_get_uidrawlinejoinbevel)
{
	RING_API_RETNUMBER(uiDrawLineJoinBevel);
}

RING_FUNC(ring_get_uidrawfillmodewinding)
{
	RING_API_RETNUMBER(uiDrawFillModeWinding);
}

RING_FUNC(ring_get_uidrawfillmodealternate)
{
	RING_API_RETNUMBER(uiDrawFillModeAlternate);
}

RING_FUNC(ring_get_uiattributetypefamily)
{
	RING_API_RETNUMBER(uiAttributeTypeFamily);
}

RING_FUNC(ring_get_uiattributetypesize)
{
	RING_API_RETNUMBER(uiAttributeTypeSize);
}

RING_FUNC(ring_get_uiattributetypeweight)
{
	RING_API_RETNUMBER(uiAttributeTypeWeight);
}

RING_FUNC(ring_get_uiattributetypeitalic)
{
	RING_API_RETNUMBER(uiAttributeTypeItalic);
}

RING_FUNC(ring_get_uiattributetypestretch)
{
	RING_API_RETNUMBER(uiAttributeTypeStretch);
}

RING_FUNC(ring_get_uiattributetypecolor)
{
	RING_API_RETNUMBER(uiAttributeTypeColor);
}

RING_FUNC(ring_get_uiattributetypebackground)
{
	RING_API_RETNUMBER(uiAttributeTypeBackground);
}

RING_FUNC(ring_get_uiattributetypeunderline)
{
	RING_API_RETNUMBER(uiAttributeTypeUnderline);
}

RING_FUNC(ring_get_uiattributetypeunderlinecolor)
{
	RING_API_RETNUMBER(uiAttributeTypeUnderlineColor);
}

RING_FUNC(ring_get_uiattributetypefeatures)
{
	RING_API_RETNUMBER(uiAttributeTypeFeatures);
}

RING_FUNC(ring_get_uitextweightminimum)
{
	RING_API_RETNUMBER(uiTextWeightMinimum);
}

RING_FUNC(ring_get_uitextweightthin)
{
	RING_API_RETNUMBER(uiTextWeightThin);
}

RING_FUNC(ring_get_uitextweightultralight)
{
	RING_API_RETNUMBER(uiTextWeightUltraLight);
}

RING_FUNC(ring_get_uitextweightlight)
{
	RING_API_RETNUMBER(uiTextWeightLight);
}

RING_FUNC(ring_get_uitextweightbook)
{
	RING_API_RETNUMBER(uiTextWeightBook);
}

RING_FUNC(ring_get_uitextweightnormal)
{
	RING_API_RETNUMBER(uiTextWeightNormal);
}

RING_FUNC(ring_get_uitextweightmedium)
{
	RING_API_RETNUMBER(uiTextWeightMedium);
}

RING_FUNC(ring_get_uitextweightsemibold)
{
	RING_API_RETNUMBER(uiTextWeightSemiBold);
}

RING_FUNC(ring_get_uitextweightbold)
{
	RING_API_RETNUMBER(uiTextWeightBold);
}

RING_FUNC(ring_get_uitextweightultrabold)
{
	RING_API_RETNUMBER(uiTextWeightUltraBold);
}

RING_FUNC(ring_get_uitextweightheavy)
{
	RING_API_RETNUMBER(uiTextWeightHeavy);
}

RING_FUNC(ring_get_uitextweightultraheavy)
{
	RING_API_RETNUMBER(uiTextWeightUltraHeavy);
}

RING_FUNC(ring_get_uitextweightmaximum)
{
	RING_API_RETNUMBER(uiTextWeightMaximum);
}

RING_FUNC(ring_get_uitextstretchultracondensed)
{
	RING_API_RETNUMBER(uiTextStretchUltraCondensed);
}

RING_FUNC(ring_get_uitextstretchextracondensed)
{
	RING_API_RETNUMBER(uiTextStretchExtraCondensed);
}

RING_FUNC(ring_get_uitextstretchcondensed)
{
	RING_API_RETNUMBER(uiTextStretchCondensed);
}

RING_FUNC(ring_get_uitextstretchsemicondensed)
{
	RING_API_RETNUMBER(uiTextStretchSemiCondensed);
}

RING_FUNC(ring_get_uitextstretchnormal)
{
	RING_API_RETNUMBER(uiTextStretchNormal);
}

RING_FUNC(ring_get_uitextstretchsemiexpanded)
{
	RING_API_RETNUMBER(uiTextStretchSemiExpanded);
}

RING_FUNC(ring_get_uitextstretchexpanded)
{
	RING_API_RETNUMBER(uiTextStretchExpanded);
}

RING_FUNC(ring_get_uitextstretchextraexpanded)
{
	RING_API_RETNUMBER(uiTextStretchExtraExpanded);
}

RING_FUNC(ring_get_uitextstretchultraexpanded)
{
	RING_API_RETNUMBER(uiTextStretchUltraExpanded);
}

RING_FUNC(ring_get_uitextitalicnormal)
{
	RING_API_RETNUMBER(uiTextItalicNormal);
}

RING_FUNC(ring_get_uitextitalicoblique)
{
	RING_API_RETNUMBER(uiTextItalicOblique);
}

RING_FUNC(ring_get_uitextitalicitalic)
{
	RING_API_RETNUMBER(uiTextItalicItalic);
}

RING_FUNC(ring_get_uiunderlinenone)
{
	RING_API_RETNUMBER(uiUnderlineNone);
}

RING_FUNC(ring_get_uiunderlinesingle)
{
	RING_API_RETNUMBER(uiUnderlineSingle);
}

RING_FUNC(ring_get_uiunderlinedouble)
{
	RING_API_RETNUMBER(uiUnderlineDouble);
}

RING_FUNC(ring_get_uiunderlinesuggestion)
{
	RING_API_RETNUMBER(uiUnderlineSuggestion);
}

RING_FUNC(ring_get_uiunderlinecolorcustom)
{
	RING_API_RETNUMBER(uiUnderlineColorCustom);
}

RING_FUNC(ring_get_uiunderlinecolorspelling)
{
	RING_API_RETNUMBER(uiUnderlineColorSpelling);
}

RING_FUNC(ring_get_uiunderlinecolorgrammar)
{
	RING_API_RETNUMBER(uiUnderlineColorGrammar);
}

RING_FUNC(ring_get_uiunderlinecolorauxiliary)
{
	RING_API_RETNUMBER(uiUnderlineColorAuxiliary);
}

RING_FUNC(ring_get_uidrawtextalignleft)
{
	RING_API_RETNUMBER(uiDrawTextAlignLeft);
}

RING_FUNC(ring_get_uidrawtextaligncenter)
{
	RING_API_RETNUMBER(uiDrawTextAlignCenter);
}

RING_FUNC(ring_get_uidrawtextalignright)
{
	RING_API_RETNUMBER(uiDrawTextAlignRight);
}

RING_FUNC(ring_get_uimodifierctrl)
{
	RING_API_RETNUMBER(uiModifierCtrl);
}

RING_FUNC(ring_get_uimodifieralt)
{
	RING_API_RETNUMBER(uiModifierAlt);
}

RING_FUNC(ring_get_uimodifiershift)
{
	RING_API_RETNUMBER(uiModifierShift);
}

RING_FUNC(ring_get_uimodifiersuper)
{
	RING_API_RETNUMBER(uiModifierSuper);
}

RING_FUNC(ring_get_uiextkeyescape)
{
	RING_API_RETNUMBER(uiExtKeyEscape);
}

RING_FUNC(ring_get_uiextkeyinsert)
{
	RING_API_RETNUMBER(uiExtKeyInsert);
}

RING_FUNC(ring_get_uiextkeydelete)
{
	RING_API_RETNUMBER(uiExtKeyDelete);
}

RING_FUNC(ring_get_uiextkeyhome)
{
	RING_API_RETNUMBER(uiExtKeyHome);
}

RING_FUNC(ring_get_uiextkeyend)
{
	RING_API_RETNUMBER(uiExtKeyEnd);
}

RING_FUNC(ring_get_uiextkeypageup)
{
	RING_API_RETNUMBER(uiExtKeyPageUp);
}

RING_FUNC(ring_get_uiextkeypagedown)
{
	RING_API_RETNUMBER(uiExtKeyPageDown);
}

RING_FUNC(ring_get_uiextkeyup)
{
	RING_API_RETNUMBER(uiExtKeyUp);
}

RING_FUNC(ring_get_uiextkeydown)
{
	RING_API_RETNUMBER(uiExtKeyDown);
}

RING_FUNC(ring_get_uiextkeyleft)
{
	RING_API_RETNUMBER(uiExtKeyLeft);
}

RING_FUNC(ring_get_uiextkeyright)
{
	RING_API_RETNUMBER(uiExtKeyRight);
}

RING_FUNC(ring_get_uiextkeyf1)
{
	RING_API_RETNUMBER(uiExtKeyF1);
}

RING_FUNC(ring_get_uiextkeyf2)
{
	RING_API_RETNUMBER(uiExtKeyF2);
}

RING_FUNC(ring_get_uiextkeyf3)
{
	RING_API_RETNUMBER(uiExtKeyF3);
}

RING_FUNC(ring_get_uiextkeyf4)
{
	RING_API_RETNUMBER(uiExtKeyF4);
}

RING_FUNC(ring_get_uiextkeyf5)
{
	RING_API_RETNUMBER(uiExtKeyF5);
}

RING_FUNC(ring_get_uiextkeyf6)
{
	RING_API_RETNUMBER(uiExtKeyF6);
}

RING_FUNC(ring_get_uiextkeyf7)
{
	RING_API_RETNUMBER(uiExtKeyF7);
}

RING_FUNC(ring_get_uiextkeyf8)
{
	RING_API_RETNUMBER(uiExtKeyF8);
}

RING_FUNC(ring_get_uiextkeyf9)
{
	RING_API_RETNUMBER(uiExtKeyF9);
}

RING_FUNC(ring_get_uiextkeyf10)
{
	RING_API_RETNUMBER(uiExtKeyF10);
}

RING_FUNC(ring_get_uiextkeyf11)
{
	RING_API_RETNUMBER(uiExtKeyF11);
}

RING_FUNC(ring_get_uiextkeyf12)
{
	RING_API_RETNUMBER(uiExtKeyF12);
}

RING_FUNC(ring_get_uiextkeyn0)
{
	RING_API_RETNUMBER(uiExtKeyN0);
}

RING_FUNC(ring_get_uiextkeyn1)
{
	RING_API_RETNUMBER(uiExtKeyN1);
}

RING_FUNC(ring_get_uiextkeyn2)
{
	RING_API_RETNUMBER(uiExtKeyN2);
}

RING_FUNC(ring_get_uiextkeyn3)
{
	RING_API_RETNUMBER(uiExtKeyN3);
}

RING_FUNC(ring_get_uiextkeyn4)
{
	RING_API_RETNUMBER(uiExtKeyN4);
}

RING_FUNC(ring_get_uiextkeyn5)
{
	RING_API_RETNUMBER(uiExtKeyN5);
}

RING_FUNC(ring_get_uiextkeyn6)
{
	RING_API_RETNUMBER(uiExtKeyN6);
}

RING_FUNC(ring_get_uiextkeyn7)
{
	RING_API_RETNUMBER(uiExtKeyN7);
}

RING_FUNC(ring_get_uiextkeyn8)
{
	RING_API_RETNUMBER(uiExtKeyN8);
}

RING_FUNC(ring_get_uiextkeyn9)
{
	RING_API_RETNUMBER(uiExtKeyN9);
}

RING_FUNC(ring_get_uiextkeyndot)
{
	RING_API_RETNUMBER(uiExtKeyNDot);
}

RING_FUNC(ring_get_uiextkeynenter)
{
	RING_API_RETNUMBER(uiExtKeyNEnter);
}

RING_FUNC(ring_get_uiextkeynadd)
{
	RING_API_RETNUMBER(uiExtKeyNAdd);
}

RING_FUNC(ring_get_uiextkeynsubtract)
{
	RING_API_RETNUMBER(uiExtKeyNSubtract);
}

RING_FUNC(ring_get_uiextkeynmultiply)
{
	RING_API_RETNUMBER(uiExtKeyNMultiply);
}

RING_FUNC(ring_get_uiextkeyndivide)
{
	RING_API_RETNUMBER(uiExtKeyNDivide);
}

RING_FUNC(ring_get_uialignfill)
{
	RING_API_RETNUMBER(uiAlignFill);
}

RING_FUNC(ring_get_uialignstart)
{
	RING_API_RETNUMBER(uiAlignStart);
}

RING_FUNC(ring_get_uialigncenter)
{
	RING_API_RETNUMBER(uiAlignCenter);
}

RING_FUNC(ring_get_uialignend)
{
	RING_API_RETNUMBER(uiAlignEnd);
}

RING_FUNC(ring_get_uiatleading)
{
	RING_API_RETNUMBER(uiAtLeading);
}

RING_FUNC(ring_get_uiattop)
{
	RING_API_RETNUMBER(uiAtTop);
}

RING_FUNC(ring_get_uiattrailing)
{
	RING_API_RETNUMBER(uiAtTrailing);
}

RING_FUNC(ring_get_uiatbottom)
{
	RING_API_RETNUMBER(uiAtBottom);
}

RING_FUNC(ring_get_uitablevaluetypestring)
{
	RING_API_RETNUMBER(uiTableValueTypeString);
}

RING_FUNC(ring_get_uitablevaluetypeimage)
{
	RING_API_RETNUMBER(uiTableValueTypeImage);
}

RING_FUNC(ring_get_uitablevaluetypeint)
{
	RING_API_RETNUMBER(uiTableValueTypeInt);
}

RING_FUNC(ring_get_uitablevaluetypecolor)
{
	RING_API_RETNUMBER(uiTableValueTypeColor);
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
	pMyPointer = (uiInitOptions*) RING_API_GETCPOINTER(1,"uiInitOptions");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uicontrol)
{
	uiControl *pMyPointer ;
	pMyPointer = (uiControl *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiControl)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiControl");
}

RING_FUNC(ring_new_managed_uicontrol)
{
	uiControl *pMyPointer ;
	pMyPointer = (uiControl *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiControl)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiControl",ring_state_free);
}

RING_FUNC(ring_destroy_uicontrol)
{
	uiControl *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiControl*) RING_API_GETCPOINTER(1,"uiControl");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uicontrol_Signature)
{
	uiControl *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiControl");
	RING_API_RETNUMBER(pMyPointer->Signature);
}

RING_FUNC(ring_set_uicontrol_Signature)
{
	uiControl *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiControl");
	pMyPointer->Signature = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uicontrol_OSSignature)
{
	uiControl *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiControl");
	RING_API_RETNUMBER(pMyPointer->OSSignature);
}

RING_FUNC(ring_set_uicontrol_OSSignature)
{
	uiControl *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiControl");
	pMyPointer->OSSignature = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uicontrol_TypeSignature)
{
	uiControl *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiControl");
	RING_API_RETNUMBER(pMyPointer->TypeSignature);
}

RING_FUNC(ring_set_uicontrol_TypeSignature)
{
	uiControl *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiControl");
	pMyPointer->TypeSignature = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uiareadrawparams)
{
	uiAreaDrawParams *pMyPointer ;
	pMyPointer = (uiAreaDrawParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiAreaDrawParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiAreaDrawParams");
}

RING_FUNC(ring_new_managed_uiareadrawparams)
{
	uiAreaDrawParams *pMyPointer ;
	pMyPointer = (uiAreaDrawParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiAreaDrawParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiAreaDrawParams",ring_state_free);
}

RING_FUNC(ring_destroy_uiareadrawparams)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiAreaDrawParams*) RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uiareadrawparams_Context)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	RING_API_RETCPOINTER(pMyPointer->Context,"uiDrawContext");
}

RING_FUNC(ring_set_uiareadrawparams_Context)
{
	uiAreaDrawParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	pMyPointer->Context = (uiDrawContext *) RING_API_GETCPOINTER(2,"uiDrawContext");
}

RING_FUNC(ring_get_uiareadrawparams_AreaWidth)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	RING_API_RETNUMBER(pMyPointer->AreaWidth);
}

RING_FUNC(ring_set_uiareadrawparams_AreaWidth)
{
	uiAreaDrawParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	pMyPointer->AreaWidth = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareadrawparams_AreaHeight)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	RING_API_RETNUMBER(pMyPointer->AreaHeight);
}

RING_FUNC(ring_set_uiareadrawparams_AreaHeight)
{
	uiAreaDrawParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	pMyPointer->AreaHeight = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareadrawparams_ClipX)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	RING_API_RETNUMBER(pMyPointer->ClipX);
}

RING_FUNC(ring_set_uiareadrawparams_ClipX)
{
	uiAreaDrawParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	pMyPointer->ClipX = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareadrawparams_ClipY)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	RING_API_RETNUMBER(pMyPointer->ClipY);
}

RING_FUNC(ring_set_uiareadrawparams_ClipY)
{
	uiAreaDrawParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	pMyPointer->ClipY = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareadrawparams_ClipWidth)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	RING_API_RETNUMBER(pMyPointer->ClipWidth);
}

RING_FUNC(ring_set_uiareadrawparams_ClipWidth)
{
	uiAreaDrawParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	pMyPointer->ClipWidth = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareadrawparams_ClipHeight)
{
	uiAreaDrawParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	RING_API_RETNUMBER(pMyPointer->ClipHeight);
}

RING_FUNC(ring_set_uiareadrawparams_ClipHeight)
{
	uiAreaDrawParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaDrawParams");
	pMyPointer->ClipHeight = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uidrawmatrix)
{
	uiDrawMatrix *pMyPointer ;
	pMyPointer = (uiDrawMatrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawMatrix)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiDrawMatrix");
}

RING_FUNC(ring_new_managed_uidrawmatrix)
{
	uiDrawMatrix *pMyPointer ;
	pMyPointer = (uiDrawMatrix *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawMatrix)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiDrawMatrix",ring_state_free);
}

RING_FUNC(ring_destroy_uidrawmatrix)
{
	uiDrawMatrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiDrawMatrix*) RING_API_GETCPOINTER(1,"uiDrawMatrix");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uidrawmatrix_M11)
{
	uiDrawMatrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	RING_API_RETNUMBER(pMyPointer->M11);
}

RING_FUNC(ring_set_uidrawmatrix_M11)
{
	uiDrawMatrix *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	pMyPointer->M11 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawmatrix_M12)
{
	uiDrawMatrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	RING_API_RETNUMBER(pMyPointer->M12);
}

RING_FUNC(ring_set_uidrawmatrix_M12)
{
	uiDrawMatrix *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	pMyPointer->M12 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawmatrix_M21)
{
	uiDrawMatrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	RING_API_RETNUMBER(pMyPointer->M21);
}

RING_FUNC(ring_set_uidrawmatrix_M21)
{
	uiDrawMatrix *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	pMyPointer->M21 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawmatrix_M22)
{
	uiDrawMatrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	RING_API_RETNUMBER(pMyPointer->M22);
}

RING_FUNC(ring_set_uidrawmatrix_M22)
{
	uiDrawMatrix *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	pMyPointer->M22 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawmatrix_M31)
{
	uiDrawMatrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	RING_API_RETNUMBER(pMyPointer->M31);
}

RING_FUNC(ring_set_uidrawmatrix_M31)
{
	uiDrawMatrix *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	pMyPointer->M31 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawmatrix_M32)
{
	uiDrawMatrix *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	RING_API_RETNUMBER(pMyPointer->M32);
}

RING_FUNC(ring_set_uidrawmatrix_M32)
{
	uiDrawMatrix *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawMatrix");
	pMyPointer->M32 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uitabletextcolumnoptionalparams)
{
	uiTableTextColumnOptionalParams *pMyPointer ;
	pMyPointer = (uiTableTextColumnOptionalParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTableTextColumnOptionalParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiTableTextColumnOptionalParams");
}

RING_FUNC(ring_new_managed_uitabletextcolumnoptionalparams)
{
	uiTableTextColumnOptionalParams *pMyPointer ;
	pMyPointer = (uiTableTextColumnOptionalParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTableTextColumnOptionalParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiTableTextColumnOptionalParams",ring_state_free);
}

RING_FUNC(ring_destroy_uitabletextcolumnoptionalparams)
{
	uiTableTextColumnOptionalParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiTableTextColumnOptionalParams*) RING_API_GETCPOINTER(1,"uiTableTextColumnOptionalParams");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uitabletextcolumnoptionalparams_ColorModelColumn)
{
	uiTableTextColumnOptionalParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiTableTextColumnOptionalParams");
	RING_API_RETNUMBER(pMyPointer->ColorModelColumn);
}

RING_FUNC(ring_set_uitabletextcolumnoptionalparams_ColorModelColumn)
{
	uiTableTextColumnOptionalParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiTableTextColumnOptionalParams");
	pMyPointer->ColorModelColumn = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uidrawbrush)
{
	uiDrawBrush *pMyPointer ;
	pMyPointer = (uiDrawBrush *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawBrush)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiDrawBrush");
}

RING_FUNC(ring_new_managed_uidrawbrush)
{
	uiDrawBrush *pMyPointer ;
	pMyPointer = (uiDrawBrush *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawBrush)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiDrawBrush",ring_state_free);
}

RING_FUNC(ring_destroy_uidrawbrush)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiDrawBrush*) RING_API_GETCPOINTER(1,"uiDrawBrush");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uidrawbrush_Type)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->Type);
}

RING_FUNC(ring_set_uidrawbrush_Type)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->Type = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_R)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->R);
}

RING_FUNC(ring_set_uidrawbrush_R)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->R = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_G)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->G);
}

RING_FUNC(ring_set_uidrawbrush_G)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->G = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_B)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->B);
}

RING_FUNC(ring_set_uidrawbrush_B)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->B = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_A)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->A);
}

RING_FUNC(ring_set_uidrawbrush_A)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->A = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_X0)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->X0);
}

RING_FUNC(ring_set_uidrawbrush_X0)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->X0 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_Y0)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->Y0);
}

RING_FUNC(ring_set_uidrawbrush_Y0)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->Y0 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_X1)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->X1);
}

RING_FUNC(ring_set_uidrawbrush_X1)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->X1 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_Y1)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->Y1);
}

RING_FUNC(ring_set_uidrawbrush_Y1)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->Y1 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_OuterRadius)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->OuterRadius);
}

RING_FUNC(ring_set_uidrawbrush_OuterRadius)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->OuterRadius = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrush_NumStops)
{
	uiDrawBrush *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	RING_API_RETNUMBER(pMyPointer->NumStops);
}

RING_FUNC(ring_set_uidrawbrush_NumStops)
{
	uiDrawBrush *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrush");
	pMyPointer->NumStops = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uidrawbrushgradientstop)
{
	uiDrawBrushGradientStop *pMyPointer ;
	pMyPointer = (uiDrawBrushGradientStop *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawBrushGradientStop)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiDrawBrushGradientStop");
}

RING_FUNC(ring_new_managed_uidrawbrushgradientstop)
{
	uiDrawBrushGradientStop *pMyPointer ;
	pMyPointer = (uiDrawBrushGradientStop *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawBrushGradientStop)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiDrawBrushGradientStop",ring_state_free);
}

RING_FUNC(ring_destroy_uidrawbrushgradientstop)
{
	uiDrawBrushGradientStop *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiDrawBrushGradientStop*) RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uidrawbrushgradientstop_Pos)
{
	uiDrawBrushGradientStop *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	RING_API_RETNUMBER(pMyPointer->Pos);
}

RING_FUNC(ring_set_uidrawbrushgradientstop_Pos)
{
	uiDrawBrushGradientStop *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	pMyPointer->Pos = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrushgradientstop_R)
{
	uiDrawBrushGradientStop *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	RING_API_RETNUMBER(pMyPointer->R);
}

RING_FUNC(ring_set_uidrawbrushgradientstop_R)
{
	uiDrawBrushGradientStop *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	pMyPointer->R = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrushgradientstop_G)
{
	uiDrawBrushGradientStop *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	RING_API_RETNUMBER(pMyPointer->G);
}

RING_FUNC(ring_set_uidrawbrushgradientstop_G)
{
	uiDrawBrushGradientStop *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	pMyPointer->G = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrushgradientstop_B)
{
	uiDrawBrushGradientStop *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	RING_API_RETNUMBER(pMyPointer->B);
}

RING_FUNC(ring_set_uidrawbrushgradientstop_B)
{
	uiDrawBrushGradientStop *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	pMyPointer->B = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawbrushgradientstop_A)
{
	uiDrawBrushGradientStop *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	RING_API_RETNUMBER(pMyPointer->A);
}

RING_FUNC(ring_set_uidrawbrushgradientstop_A)
{
	uiDrawBrushGradientStop *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawBrushGradientStop");
	pMyPointer->A = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uidrawstrokeparams)
{
	uiDrawStrokeParams *pMyPointer ;
	pMyPointer = (uiDrawStrokeParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawStrokeParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiDrawStrokeParams");
}

RING_FUNC(ring_new_managed_uidrawstrokeparams)
{
	uiDrawStrokeParams *pMyPointer ;
	pMyPointer = (uiDrawStrokeParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawStrokeParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiDrawStrokeParams",ring_state_free);
}

RING_FUNC(ring_destroy_uidrawstrokeparams)
{
	uiDrawStrokeParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiDrawStrokeParams*) RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uidrawstrokeparams_Cap)
{
	uiDrawStrokeParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	RING_API_RETNUMBER(pMyPointer->Cap);
}

RING_FUNC(ring_set_uidrawstrokeparams_Cap)
{
	uiDrawStrokeParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	pMyPointer->Cap = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawstrokeparams_Join)
{
	uiDrawStrokeParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	RING_API_RETNUMBER(pMyPointer->Join);
}

RING_FUNC(ring_set_uidrawstrokeparams_Join)
{
	uiDrawStrokeParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	pMyPointer->Join = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawstrokeparams_Thickness)
{
	uiDrawStrokeParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	RING_API_RETNUMBER(pMyPointer->Thickness);
}

RING_FUNC(ring_set_uidrawstrokeparams_Thickness)
{
	uiDrawStrokeParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	pMyPointer->Thickness = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawstrokeparams_MiterLimit)
{
	uiDrawStrokeParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	RING_API_RETNUMBER(pMyPointer->MiterLimit);
}

RING_FUNC(ring_set_uidrawstrokeparams_MiterLimit)
{
	uiDrawStrokeParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	pMyPointer->MiterLimit = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawstrokeparams_NumDashes)
{
	uiDrawStrokeParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	RING_API_RETNUMBER(pMyPointer->NumDashes);
}

RING_FUNC(ring_set_uidrawstrokeparams_NumDashes)
{
	uiDrawStrokeParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	pMyPointer->NumDashes = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawstrokeparams_DashPhase)
{
	uiDrawStrokeParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	RING_API_RETNUMBER(pMyPointer->DashPhase);
}

RING_FUNC(ring_set_uidrawstrokeparams_DashPhase)
{
	uiDrawStrokeParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawStrokeParams");
	pMyPointer->DashPhase = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uitablemodelhandler)
{
	uiTableModelHandler *pMyPointer ;
	pMyPointer = (uiTableModelHandler *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTableModelHandler)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiTableModelHandler");
}

RING_FUNC(ring_new_managed_uitablemodelhandler)
{
	uiTableModelHandler *pMyPointer ;
	pMyPointer = (uiTableModelHandler *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTableModelHandler)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiTableModelHandler",ring_state_free);
}

RING_FUNC(ring_destroy_uitablemodelhandler)
{
	uiTableModelHandler *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiTableModelHandler*) RING_API_GETCPOINTER(1,"uiTableModelHandler");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_new_uiareakeyevent)
{
	uiAreaKeyEvent *pMyPointer ;
	pMyPointer = (uiAreaKeyEvent *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiAreaKeyEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiAreaKeyEvent");
}

RING_FUNC(ring_new_managed_uiareakeyevent)
{
	uiAreaKeyEvent *pMyPointer ;
	pMyPointer = (uiAreaKeyEvent *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiAreaKeyEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiAreaKeyEvent",ring_state_free);
}

RING_FUNC(ring_destroy_uiareakeyevent)
{
	uiAreaKeyEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiAreaKeyEvent*) RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uiareakeyevent_Key)
{
	uiAreaKeyEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	RING_API_RETNUMBER(pMyPointer->Key);
}

RING_FUNC(ring_set_uiareakeyevent_Key)
{
	uiAreaKeyEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	pMyPointer->Key = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareakeyevent_ExtKey)
{
	uiAreaKeyEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	RING_API_RETNUMBER(pMyPointer->ExtKey);
}

RING_FUNC(ring_set_uiareakeyevent_ExtKey)
{
	uiAreaKeyEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	pMyPointer->ExtKey = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareakeyevent_Modifier)
{
	uiAreaKeyEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	RING_API_RETNUMBER(pMyPointer->Modifier);
}

RING_FUNC(ring_set_uiareakeyevent_Modifier)
{
	uiAreaKeyEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	pMyPointer->Modifier = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareakeyevent_Modifiers)
{
	uiAreaKeyEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	RING_API_RETNUMBER(pMyPointer->Modifiers);
}

RING_FUNC(ring_set_uiareakeyevent_Modifiers)
{
	uiAreaKeyEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	pMyPointer->Modifiers = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareakeyevent_Up)
{
	uiAreaKeyEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	RING_API_RETNUMBER(pMyPointer->Up);
}

RING_FUNC(ring_set_uiareakeyevent_Up)
{
	uiAreaKeyEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaKeyEvent");
	pMyPointer->Up = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uitableparams)
{
	uiTableParams *pMyPointer ;
	pMyPointer = (uiTableParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTableParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiTableParams");
}

RING_FUNC(ring_new_managed_uitableparams)
{
	uiTableParams *pMyPointer ;
	pMyPointer = (uiTableParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiTableParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiTableParams",ring_state_free);
}

RING_FUNC(ring_destroy_uitableparams)
{
	uiTableParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiTableParams*) RING_API_GETCPOINTER(1,"uiTableParams");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uitableparams_Model)
{
	uiTableParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiTableParams");
	RING_API_RETCPOINTER(pMyPointer->Model,"uiTableModel");
}

RING_FUNC(ring_set_uitableparams_Model)
{
	uiTableParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiTableParams");
	pMyPointer->Model = (uiTableModel *) RING_API_GETCPOINTER(2,"uiTableModel");
}

RING_FUNC(ring_get_uitableparams_RowBackgroundColorModelColumn)
{
	uiTableParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiTableParams");
	RING_API_RETNUMBER(pMyPointer->RowBackgroundColorModelColumn);
}

RING_FUNC(ring_set_uitableparams_RowBackgroundColorModelColumn)
{
	uiTableParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiTableParams");
	pMyPointer->RowBackgroundColorModelColumn = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uiareamouseevent)
{
	uiAreaMouseEvent *pMyPointer ;
	pMyPointer = (uiAreaMouseEvent *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiAreaMouseEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiAreaMouseEvent");
}

RING_FUNC(ring_new_managed_uiareamouseevent)
{
	uiAreaMouseEvent *pMyPointer ;
	pMyPointer = (uiAreaMouseEvent *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiAreaMouseEvent)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiAreaMouseEvent",ring_state_free);
}

RING_FUNC(ring_destroy_uiareamouseevent)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiAreaMouseEvent*) RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uiareamouseevent_X)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->X);
}

RING_FUNC(ring_set_uiareamouseevent_X)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->X = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_Y)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->Y);
}

RING_FUNC(ring_set_uiareamouseevent_Y)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->Y = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_AreaWidth)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->AreaWidth);
}

RING_FUNC(ring_set_uiareamouseevent_AreaWidth)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->AreaWidth = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_AreaHeight)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->AreaHeight);
}

RING_FUNC(ring_set_uiareamouseevent_AreaHeight)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->AreaHeight = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_Down)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->Down);
}

RING_FUNC(ring_set_uiareamouseevent_Down)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->Down = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_Up)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->Up);
}

RING_FUNC(ring_set_uiareamouseevent_Up)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->Up = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_Count)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->Count);
}

RING_FUNC(ring_set_uiareamouseevent_Count)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->Count = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_Modifiers)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->Modifiers);
}

RING_FUNC(ring_set_uiareamouseevent_Modifiers)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->Modifiers = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uiareamouseevent_Held1To64)
{
	uiAreaMouseEvent *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	RING_API_RETNUMBER(pMyPointer->Held1To64);
}

RING_FUNC(ring_set_uiareamouseevent_Held1To64)
{
	uiAreaMouseEvent *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiAreaMouseEvent");
	pMyPointer->Held1To64 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uidrawtextlayoutparams)
{
	uiDrawTextLayoutParams *pMyPointer ;
	pMyPointer = (uiDrawTextLayoutParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawTextLayoutParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiDrawTextLayoutParams");
}

RING_FUNC(ring_new_managed_uidrawtextlayoutparams)
{
	uiDrawTextLayoutParams *pMyPointer ;
	pMyPointer = (uiDrawTextLayoutParams *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiDrawTextLayoutParams)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiDrawTextLayoutParams",ring_state_free);
}

RING_FUNC(ring_destroy_uidrawtextlayoutparams)
{
	uiDrawTextLayoutParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiDrawTextLayoutParams*) RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uidrawtextlayoutparams_String)
{
	uiDrawTextLayoutParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	RING_API_RETCPOINTER(pMyPointer->String,"uiAttributedString");
}

RING_FUNC(ring_set_uidrawtextlayoutparams_String)
{
	uiDrawTextLayoutParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	pMyPointer->String = (uiAttributedString *) RING_API_GETCPOINTER(2,"uiAttributedString");
}

RING_FUNC(ring_get_uidrawtextlayoutparams_DefaultFont)
{
	uiDrawTextLayoutParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	RING_API_RETCPOINTER(pMyPointer->DefaultFont,"uiFontDescriptor");
}

RING_FUNC(ring_set_uidrawtextlayoutparams_DefaultFont)
{
	uiDrawTextLayoutParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	pMyPointer->DefaultFont = (uiFontDescriptor *) RING_API_GETCPOINTER(2,"uiFontDescriptor");
}

RING_FUNC(ring_get_uidrawtextlayoutparams_Width)
{
	uiDrawTextLayoutParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	RING_API_RETNUMBER(pMyPointer->Width);
}

RING_FUNC(ring_set_uidrawtextlayoutparams_Width)
{
	uiDrawTextLayoutParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	pMyPointer->Width = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uidrawtextlayoutparams_Align)
{
	uiDrawTextLayoutParams *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	RING_API_RETNUMBER(pMyPointer->Align);
}

RING_FUNC(ring_set_uidrawtextlayoutparams_Align)
{
	uiDrawTextLayoutParams *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiDrawTextLayoutParams");
	pMyPointer->Align = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_new_uifontdescriptor)
{
	uiFontDescriptor *pMyPointer ;
	pMyPointer = (uiFontDescriptor *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiFontDescriptor)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"uiFontDescriptor");
}

RING_FUNC(ring_new_managed_uifontdescriptor)
{
	uiFontDescriptor *pMyPointer ;
	pMyPointer = (uiFontDescriptor *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uiFontDescriptor)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"uiFontDescriptor",ring_state_free);
}

RING_FUNC(ring_destroy_uifontdescriptor)
{
	uiFontDescriptor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (uiFontDescriptor*) RING_API_GETCPOINTER(1,"uiFontDescriptor");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_uifontdescriptor_Family)
{
	uiFontDescriptor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	RING_API_RETCPOINTER(pMyPointer->Family,"char");
}

RING_FUNC(ring_set_uifontdescriptor_Family)
{
	uiFontDescriptor *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	pMyPointer->Family = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_uifontdescriptor_Size)
{
	uiFontDescriptor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	RING_API_RETNUMBER(pMyPointer->Size);
}

RING_FUNC(ring_set_uifontdescriptor_Size)
{
	uiFontDescriptor *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	pMyPointer->Size = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uifontdescriptor_Weight)
{
	uiFontDescriptor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	RING_API_RETNUMBER(pMyPointer->Weight);
}

RING_FUNC(ring_set_uifontdescriptor_Weight)
{
	uiFontDescriptor *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	pMyPointer->Weight = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uifontdescriptor_Italic)
{
	uiFontDescriptor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	RING_API_RETNUMBER(pMyPointer->Italic);
}

RING_FUNC(ring_set_uifontdescriptor_Italic)
{
	uiFontDescriptor *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	pMyPointer->Italic = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_uifontdescriptor_Stretch)
{
	uiFontDescriptor *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	RING_API_RETNUMBER(pMyPointer->Stretch);
}

RING_FUNC(ring_set_uifontdescriptor_Stretch)
{
	uiFontDescriptor *pMyPointer ;
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
	pMyPointer = RING_API_GETCPOINTER(1,"uiFontDescriptor");
	pMyPointer->Stretch = RING_API_GETNUMBER(2);
}


RING_FUNC(ring_uiInit_2)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(uiInit((uiInitOptions *) RING_API_GETCPOINTER(1,"uiInitOptions")));
}


VM *pVMLibUI = NULL;

List *aLibUIEvents ;

uiWindow *activeWindow ;
uiButton *activeButton ;
uiCheckbox *activeCheckbox;
uiEntry *activeEntry;
uiSpinbox *activeSpinbox;
uiSlider *activeSlider;
uiCombobox *activeCombobox;
uiEditableCombobox *activeEditableCombobox;
uiRadioButtons *activeRadioButtons;
uiDateTimePicker *activeDateTimePicker;
uiMultilineEntry *activeMultilineEntry;
uiMenuItem *activeMenuItem;
uiWindow *activeMenuItemWindow;
uiFontButton *activeFontButton;
uiColorButton *activeColorButton;
uiAreaHandler *activeAreaHandler;
uiArea *activeArea;
uiAreaDrawParams *activeAreaDrawParams;
uiAreaKeyEvent *activeAreaKeyEvent;
uiAreaMouseEvent *activeAreaMouseEvent;
int activeLeft;

typedef struct customAreaHandler {
	uiAreaHandler ah;
	char cDraw[256];
	char cMouseEvent[256];
	char cMouseCrossed[256];
	char cDragBroken[256];
	char cKeyEvent[256];
} customAreaHandler;


static void handlerDraw(uiAreaHandler *a, uiArea *area, uiAreaDrawParams *p)
{
	customAreaHandler *oHandler;
	activeAreaHandler = a;
	activeArea = area;
	activeAreaDrawParams = p;
	oHandler = (customAreaHandler *) a;
	if ( oHandler->cDraw[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) oHandler->cDraw);
}

static void handlerMouseEvent(uiAreaHandler *a, uiArea *area, uiAreaMouseEvent *e)
{
	customAreaHandler *oHandler;
	activeAreaHandler = a;
	activeArea = area;
	activeAreaMouseEvent = e;
	oHandler = (customAreaHandler *) a;
	if ( oHandler->cMouseEvent[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) oHandler->cMouseEvent);
}

static void handlerMouseCrossed(uiAreaHandler *ah, uiArea *a, int left)
{
	customAreaHandler *oHandler;
	activeAreaHandler = ah;
	activeArea = a;
	activeLeft = left;
	oHandler = (customAreaHandler *) ah;
	if ( oHandler->cMouseCrossed[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) oHandler->cMouseCrossed);
}

static void handlerDragBroken(uiAreaHandler *ah, uiArea *a)
{
	customAreaHandler *oHandler;
	activeAreaHandler = ah;
	activeArea = a;
	oHandler = (customAreaHandler *) ah;
	if ( oHandler->cDragBroken[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) oHandler->cDragBroken);
}

static int handlerKeyEvent(uiAreaHandler *ah, uiArea *a, uiAreaKeyEvent *e)
{
	customAreaHandler *oHandler;
	activeAreaHandler = ah;
	activeArea = a;
	activeAreaKeyEvent = e;
	oHandler = (customAreaHandler *) ah;
	if ( oHandler->cKeyEvent[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) oHandler->cKeyEvent);
	return 0;
}

RING_FUNC(ring_uiNewAreaHandler)
{

	customAreaHandler *oHandler;

	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR("The function expect 5 parameters") ;
		return ;
	}

	if ( ( ! RING_API_ISSTRING(1) ) ||
			 ( ! RING_API_ISSTRING(2) ) ||
			 ( ! RING_API_ISSTRING(3) ) ||
			 ( ! RING_API_ISSTRING(4) ) ||
			 ( ! RING_API_ISSTRING(5) )  ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}

	if ( ( strlen( RING_API_GETSTRING(1) ) > 255 ) ||
			 ( strlen( RING_API_GETSTRING(2) ) > 255 ) ||
			 ( strlen( RING_API_GETSTRING(3) ) > 255 ) ||
			 ( strlen( RING_API_GETSTRING(4) ) > 255 ) ||
			 ( strlen( RING_API_GETSTRING(5) ) > 255 )  ) {
		RING_API_ERROR("The Event String size is greater than 255 characters!");
		return ;
	}

	oHandler = (customAreaHandler *) calloc(1,sizeof(customAreaHandler)) ;

	oHandler->ah.Draw = handlerDraw ;
	oHandler->ah.MouseEvent = handlerMouseEvent ;
	oHandler->ah.MouseCrossed = handlerMouseCrossed ;
	oHandler->ah.DragBroken = handlerDragBroken ;
	oHandler->ah.KeyEvent =  handlerKeyEvent ;

	strcpy(oHandler->cDraw,RING_API_GETSTRING(1));
	strcpy(oHandler->cMouseEvent,RING_API_GETSTRING(2));
	strcpy(oHandler->cMouseCrossed,RING_API_GETSTRING(3));
	strcpy(oHandler->cDragBroken,RING_API_GETSTRING(4));
	strcpy(oHandler->cKeyEvent,RING_API_GETSTRING(5));

	RING_API_RETCPOINTER(oHandler,"uiAreaHandler");

}

static void setSolidBrush(uiDrawBrush *brush, uint32_t color, double alpha)
{
	uint8_t component;

	brush->Type = uiDrawBrushTypeSolid;
	component = (uint8_t) ((color >> 16) & 0xFF);
	brush->R = ((double) component) / 255;
	component = (uint8_t) ((color >> 8) & 0xFF);
	brush->G = ((double) component) / 255;
	component = (uint8_t) (color & 0xFF);
	brush->B = ((double) component) / 255;
	brush->A = alpha;
}


RING_FUNC(ring_uiInit)
{
	uiInitOptions o;
	const char *err;
	memset(&o, 0, sizeof (uiInitOptions));
	err = uiInit(&o);
	if (err != NULL) {
		RING_API_ERROR("error initializing libui");
		uiFreeInitError(err);
	}
	pVMLibUI = (VM *) pPointer;
	aLibUIEvents = ring_list_new(0);
	activeWindow = NULL;
	activeButton = NULL;
	activeCheckbox = NULL;
	activeEntry = NULL;
	activeSpinbox = NULL;
	activeSlider = NULL;
	activeCombobox = NULL;
	activeEditableCombobox = NULL;
	activeRadioButtons = NULL;
	activeDateTimePicker = NULL;
	activeMultilineEntry = NULL;
	activeMenuItem = NULL;
	activeMenuItemWindow = NULL;
	activeFontButton = NULL;
	activeColorButton = NULL;
}

RING_FUNC(ring_uiUninit)
{
	aLibUIEvents = ring_list_delete(aLibUIEvents);
	// Calling uiUninit() lead to CRASH (A bug in libui itself)
	// Also it's not necessary to call it before closing the application
	// uiUninit();
}

int libui_event(void *data)
{
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
	return 1;
}

void libui_event2(void *data)
{
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

int libui_windowevent(uiWindow *obj,void *data)
{
	activeWindow = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
	return 0;
}

void libui_buttonevent(uiButton *obj,void *data)
{
	activeButton = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_checkboxevent(uiCheckbox *obj,void *data)
{
	activeCheckbox = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_entryevent(uiEntry *obj,void *data)
{
	activeEntry = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_spinboxevent(uiSpinbox *obj,void *data)
{
	activeSpinbox = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_sliderevent(uiSlider *obj,void *data)
{
	activeSlider = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_comboboxevent(uiCombobox *obj,void *data)
{
	activeCombobox = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_editablecomboboxevent(uiEditableCombobox *obj,void *data)
{
	activeEditableCombobox = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_radiobuttonsevent(uiRadioButtons *obj,void *data)
{
	activeRadioButtons = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_datetimepickerevent(uiDateTimePicker *obj,void *data)
{
	activeDateTimePicker = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_multilineentryevent(uiMultilineEntry *obj,void *data)
{
	activeMultilineEntry = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_menuitemevent(uiMenuItem *obj,uiWindow *obj2,void *data)
{
	activeMenuItem = obj;
	activeMenuItemWindow = obj2;
	ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_fontbuttonevent(uiFontButton *obj,void *data)
{
	activeFontButton = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}

void libui_colorbuttonevent(uiColorButton *obj,void *data)
{
	activeColorButton = obj;
	if ( ((const char *) data)[0] != '\0')
		ring_vm_runcode(pVMLibUI,(const char *) data);
}


void *RegisterEvent(const char *cEvent)
{
	ring_list_addstring(aLibUIEvents,cEvent);
	return (void *) ring_list_getstring(aLibUIEvents,ring_list_getsize(aLibUIEvents));
}

RING_FUNC(ring_uiOnShouldQuit)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiOnShouldQuit(libui_event,RegisterEvent(RING_API_GETSTRING(1)));
}

RING_FUNC(ring_uiWindowOnClosing)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiWindowOnClosing(RING_API_GETCPOINTER(1,"uiWindow"),
		libui_windowevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiButtonOnClicked)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiButtonOnClicked(RING_API_GETCPOINTER(1,"uiButton"),
		libui_buttonevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiQueueMain)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiQueueMain(libui_event2,RegisterEvent(RING_API_GETSTRING(1)));
}

RING_FUNC(ring_uiTimer)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiTimer(RING_API_GETNUMBER(1),libui_event,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiWindowOnContentSizeChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiWindowOnContentSizeChanged(RING_API_GETCPOINTER(1,"uiWindow"),
		libui_windowevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiCheckboxOnToggled)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiCheckboxOnToggled(RING_API_GETCPOINTER(1,"uiCheckbox"),
		libui_checkboxevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiEntryOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiEntryOnChanged(RING_API_GETCPOINTER(1,"uiEntry"),
		libui_entryevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiSpinboxOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiSpinboxOnChanged(RING_API_GETCPOINTER(1,"uiSpinbox"),
		libui_spinboxevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiSliderOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiSliderOnChanged(RING_API_GETCPOINTER(1,"uiSlider"),
		libui_sliderevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiComboboxOnSelected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiComboboxOnSelected(RING_API_GETCPOINTER(1,"uiCombobox"),
		libui_comboboxevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiEditableComboboxOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiEditableComboboxOnChanged(RING_API_GETCPOINTER(1,"uiEditableCombobox"),
		libui_editablecomboboxevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiRadioButtonsOnSelected)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiRadioButtonsOnSelected(RING_API_GETCPOINTER(1,"uiRadioButtons"),
		libui_radiobuttonsevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiDateTimePickerOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiDateTimePickerOnChanged(RING_API_GETCPOINTER(1,"uiDateTimePicker"),
		libui_datetimepickerevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiMultilineEntryOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiMultilineEntryOnChanged(RING_API_GETCPOINTER(1,"uiMultilineEntry"),
		libui_multilineentryevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiMenuItemOnClicked)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiMenuItemOnClicked(RING_API_GETCPOINTER(1,"uiMenuItem"),
		libui_menuitemevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiFontButtonOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiFontButtonOnChanged(RING_API_GETCPOINTER(1,"uiFontButton"),
		libui_fontbuttonevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiColorButtonOnChanged)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
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
	uiColorButtonOnChanged(RING_API_GETCPOINTER(1,"uiColorButton"),
		libui_colorbuttonevent,RegisterEvent(RING_API_GETSTRING(2)));
}

RING_FUNC(ring_uiEventWindow)
{
	RING_API_RETCPOINTER(activeWindow,"uiWindow");
}

RING_FUNC(ring_uiEventButton)
{
	RING_API_RETCPOINTER(activeButton,"uiButton");
}

RING_FUNC(ring_uiEventCheckbox)
{
	RING_API_RETCPOINTER(activeCheckbox,"uiCheckbox");
}

RING_FUNC(ring_uiEventEntry)
{
	RING_API_RETCPOINTER(activeEntry,"uiEntry");
}

RING_FUNC(ring_uiEventSpinbox)
{
	RING_API_RETCPOINTER(activeSpinbox,"uiSpinbox");
}

RING_FUNC(ring_uiEventSlider)
{
	RING_API_RETCPOINTER(activeSlider,"uiSlider");
}

RING_FUNC(ring_uiEventCombobox)
{
	RING_API_RETCPOINTER(activeCombobox,"uiCombox");
}

RING_FUNC(ring_uiEventEditableCombobox)
{
	RING_API_RETCPOINTER(activeEditableCombobox,"uiCombobox");
}

RING_FUNC(ring_uiEventRadioButtons)
{
	RING_API_RETCPOINTER(activeRadioButtons,"uiRadioButtons");
}

RING_FUNC(ring_uiEventDateTimePicker)
{
	RING_API_RETCPOINTER(activeDateTimePicker,"uiDateTimePicker");
}

RING_FUNC(ring_uiEventMultilineEntry)
{
	RING_API_RETCPOINTER(activeMultilineEntry,"uiMultilineEntry");
}

RING_FUNC(ring_uiEventMenuItem)
{
	RING_API_RETCPOINTER(activeMenuItem,"uiMenuItem");
}

RING_FUNC(ring_uiEventMenuItemWindow)
{
	RING_API_RETCPOINTER(activeMenuItemWindow,"uiWindow");
}

RING_FUNC(ring_uiEventFontButton)
{
	RING_API_RETCPOINTER(activeFontButton,"uiFontButton");
}

RING_FUNC(ring_uiEventColorButton)
{
	RING_API_RETCPOINTER(activeColorButton,"uiColorButton");
}

RING_FUNC(ring_uiEventAreaHandler)
{
	RING_API_RETCPOINTER(activeAreaHandler,"uiAreaHandler");
}

RING_FUNC(ring_uiEventArea)
{
	RING_API_RETCPOINTER(activeArea,"uiArea");
}

RING_FUNC(ring_uiEventAreaDrawParams)
{
	RING_API_RETCPOINTER(activeAreaDrawParams,"uiAreaDrawParams");
}

RING_FUNC(ring_uiEventAreaKeyEvent)
{
	RING_API_RETCPOINTER(activeAreaKeyEvent,"uiAreaKeyEvent");
}

RING_FUNC(ring_uiEventAreaMouseEvent)
{
	RING_API_RETCPOINTER(activeAreaMouseEvent,"uiAreaMouseEvent");
}

RING_FUNC(ring_uiEventLeft)
{
	RING_API_RETNUMBER(activeLeft);
}



RING_FUNC(ring_setSolidBrush)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	setSolidBrush((uiDrawBrush *) RING_API_GETCPOINTER(1,"uiDrawBrush"), (uint32_t ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3));
}


RING_FUNC(ring_uiFreeInitError)
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
	uiFreeInitError(RING_API_GETSTRING(1));
}


RING_FUNC(ring_uiMain)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	uiMain();
}


RING_FUNC(ring_uiMainSteps)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	uiMainSteps();
}


RING_FUNC(ring_uiMainStep)
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
	RING_API_RETNUMBER(uiMainStep( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_uiQuit)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	uiQuit();
}


RING_FUNC(ring_uiControlDestroy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiUserBugCannotSetParentOnToplevel(RING_API_GETSTRING(1));
}


RING_FUNC(ring_uiWindowSetTitle)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewWindow(RING_API_GETSTRING(1), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4)),"uiWindow");
}


RING_FUNC(ring_uiButtonSetText)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewHorizontalBox(),"uiBox");
}


RING_FUNC(ring_uiNewVerticalBox)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewVerticalBox(),"uiBox");
}


RING_FUNC(ring_uiCheckboxSetText)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewCheckbox(RING_API_GETSTRING(1)),"uiCheckbox");
}


RING_FUNC(ring_uiEntrySetText)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewEntry(),"uiEntry");
}


RING_FUNC(ring_uiNewPasswordEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewPasswordEntry(),"uiEntry");
}


RING_FUNC(ring_uiNewSearchEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewSearchEntry(),"uiEntry");
}


RING_FUNC(ring_uiLabelSetText)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewTab(),"uiTab");
}


RING_FUNC(ring_uiGroupSetTitle)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewProgressBar(),"uiProgressBar");
}


RING_FUNC(ring_uiNewHorizontalSeparator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewHorizontalSeparator(),"uiSeparator");
}


RING_FUNC(ring_uiNewVerticalSeparator)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewVerticalSeparator(),"uiSeparator");
}


RING_FUNC(ring_uiComboboxAppend)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewCombobox(),"uiCombobox");
}


RING_FUNC(ring_uiEditableComboboxAppend)
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
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiEditableComboboxAppend((uiEditableCombobox *) RING_API_GETCPOINTER(1,"uiEditableCombobox"),RING_API_GETSTRING(2));
}


RING_FUNC(ring_uiEditableComboboxSetText)
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewEditableCombobox(),"uiEditableCombobox");
}


RING_FUNC(ring_uiRadioButtonsAppend)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewRadioButtons(),"uiRadioButtons");
}


RING_FUNC(ring_uiDateTimePickerTime)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewDateTimePicker(),"uiDateTimePicker");
}


RING_FUNC(ring_uiNewDatePicker)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewDatePicker(),"uiDateTimePicker");
}


RING_FUNC(ring_uiNewTimePicker)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewTimePicker(),"uiDateTimePicker");
}


RING_FUNC(ring_uiMultilineEntrySetText)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewMultilineEntry(),"uiMultilineEntry");
}


RING_FUNC(ring_uiNewNonWrappingMultilineEntry)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewNonWrappingMultilineEntry(),"uiMultilineEntry");
}


RING_FUNC(ring_uiMenuItemEnable)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewMenu(RING_API_GETSTRING(1)),"uiMenu");
}


RING_FUNC(ring_uiMsgBox)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	uiAreaBeginUserWindowResize((uiArea *) RING_API_GETCPOINTER(1,"uiArea"), (uiWindowResizeEdge )  (int) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_uiNewArea)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiDrawNewPath( (uiDrawFillMode )  (int) RING_API_GETNUMBER(1)),"uiDrawPath");
}


RING_FUNC(ring_uiDrawFreePath)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributeGetType((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")));
}


RING_FUNC(ring_uiNewFamilyAttribute)
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
	RING_API_RETCPOINTER(uiNewFamilyAttribute(RING_API_GETSTRING(1)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeFamily)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewStretchAttribute( (uiTextStretch )  (int) RING_API_GETNUMBER(1)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeStretch)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributeStretch((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")));
}


RING_FUNC(ring_uiNewColorAttribute)
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETCPOINTER(uiNewBackgroundAttribute( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4)),"uiAttribute");
}


RING_FUNC(ring_uiNewUnderlineAttribute)
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
	RING_API_RETCPOINTER(uiNewUnderlineAttribute( (uiUnderline )  (int) RING_API_GETNUMBER(1)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeUnderline)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributeUnderline((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")));
}


RING_FUNC(ring_uiNewUnderlineColorAttribute)
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
	RING_API_RETCPOINTER(uiNewUnderlineColorAttribute( (uiUnderlineColor )  (int) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4), (double ) RING_API_GETNUMBER(5)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeUnderlineColor)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewOpenTypeFeatures(),"uiOpenTypeFeatures");
}


RING_FUNC(ring_uiFreeOpenTypeFeatures)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	uiOpenTypeFeaturesAdd((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"), (char ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (char ) RING_API_GETNUMBER(4), (char ) RING_API_GETNUMBER(5), (uint32_t ) RING_API_GETNUMBER(6));
}


RING_FUNC(ring_uiOpenTypeFeaturesRemove)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	uiOpenTypeFeaturesRemove((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"), (char ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (char ) RING_API_GETNUMBER(4), (char ) RING_API_GETNUMBER(5));
}


RING_FUNC(ring_uiOpenTypeFeaturesGet)
{
	if ( RING_API_PARACOUNT != 6 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
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
	RING_API_RETNUMBER(uiOpenTypeFeaturesGet((uiOpenTypeFeatures *) RING_API_GETCPOINTER(1,"uiOpenTypeFeatures"), (char ) RING_API_GETNUMBER(2), (char ) RING_API_GETNUMBER(3), (char ) RING_API_GETNUMBER(4), (char ) RING_API_GETNUMBER(5),(uint32_t *) RING_API_GETCPOINTER(6,"uint32_t")));
}


RING_FUNC(ring_uiOpenTypeFeaturesForEach)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewFontButton(),"uiFontButton");
}


RING_FUNC(ring_uiFreeFontButtonFont)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewColorButton(),"uiColorButton");
}


RING_FUNC(ring_uiFormAppend)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewForm(),"uiForm");
}


RING_FUNC(ring_uiGridAppend)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	uiGridAppend((uiGrid *) RING_API_GETCPOINTER(1,"uiGrid"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"), (int ) RING_API_GETNUMBER(3), (int ) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7), (uiAlign )  (int) RING_API_GETNUMBER(8), (int ) RING_API_GETNUMBER(9), (uiAlign )  (int) RING_API_GETNUMBER(10));
}


RING_FUNC(ring_uiGridInsertAt)
{
	if ( RING_API_PARACOUNT != 10 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	uiGridInsertAt((uiGrid *) RING_API_GETCPOINTER(1,"uiGrid"),(uiControl *) RING_API_GETCPOINTER(2,"uiControl"),(uiControl *) RING_API_GETCPOINTER(3,"uiControl"), (uiAt )  (int) RING_API_GETNUMBER(4), (int ) RING_API_GETNUMBER(5), (int ) RING_API_GETNUMBER(6), (int ) RING_API_GETNUMBER(7), (uiAlign )  (int) RING_API_GETNUMBER(8), (int ) RING_API_GETNUMBER(9), (uiAlign )  (int) RING_API_GETNUMBER(10));
}


RING_FUNC(ring_uiGridPadded)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETCPOINTER(uiNewGrid(),"uiGrid");
}


RING_FUNC(ring_uiTableValueGetType)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiTableValueGetType((uiTableValue *) RING_API_GETCPOINTER(1,"uiTableValue")));
}


RING_FUNC(ring_uiNewTableValueString)
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
	RING_API_RETCPOINTER(uiNewTableValueString(RING_API_GETSTRING(1)),"uiTableValue");
}


RING_FUNC(ring_uiTableValueString)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_RETCPOINTER(uiNewTableValueColor( (double ) RING_API_GETNUMBER(1), (double ) RING_API_GETNUMBER(2), (double ) RING_API_GETNUMBER(3), (double ) RING_API_GETNUMBER(4)),"uiTableValue");
}


RING_FUNC(ring_uiTableValueColor)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(uiNewItalicAttribute( (uiTextItalic )  (int) RING_API_GETNUMBER(1)),"uiAttribute");
}


RING_FUNC(ring_uiAttributeItalic)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(uiAttributeItalic((uiAttribute *) RING_API_GETCPOINTER(1,"uiAttribute")));
}


RING_FUNC(ring_uiFreeAttribute)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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
	RING_API_IGNORECPOINTERTYPE ;
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


RING_FUNC(ring_uiControlHandle)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		uintptr_t *pValue ; 
		pValue = (uintptr_t *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(uintptr_t)) ;
		*pValue = uiControlHandle((uiControl *) RING_API_GETCPOINTER(1,"uiControl"));
		RING_API_RETMANAGEDCPOINTER(pValue,"uintptr_t",ring_state_free);
	}
}

RING_FUNC(ring_uiWindowTitle)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiWindowTitle((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiButtonText)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiButtonText((uiButton *) RING_API_GETCPOINTER(1,"uiButton"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiCheckboxText)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiCheckboxText((uiCheckbox *) RING_API_GETCPOINTER(1,"uiCheckbox"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiEntryText)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiEntryText((uiEntry *) RING_API_GETCPOINTER(1,"uiEntry"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiMultilineEntryText)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiMultilineEntryText((uiMultilineEntry *) RING_API_GETCPOINTER(1,"uiMultilineEntry"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiLabelText)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiLabelText((uiLabel *) RING_API_GETCPOINTER(1,"uiLabel"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiGroupTitle)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiGroupTitle((uiGroup *) RING_API_GETCPOINTER(1,"uiGroup"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiEditableComboboxText)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiEditableComboboxText((uiEditableCombobox *) RING_API_GETCPOINTER(1,"uiEditableCombobox"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiOpenFile)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiOpenFile((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}

RING_FUNC(ring_uiSaveFile)
{
	char *cOut;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cOut = uiSaveFile((uiWindow *) RING_API_GETCPOINTER(1,"uiWindow"));
	if (cOut == NULL) {
		RING_API_RETSTRING("");
	} else {
		RING_API_RETSTRING(cOut);
		uiFreeText(cOut);
	}
}
RING_API void ringlib_init(RingState *pRingState)
{
	RING_API_REGISTER("uiinit_2",ring_uiInit_2);
	RING_API_REGISTER("uiinit",ring_uiInit);
	RING_API_REGISTER("uiuninit",ring_uiUninit);
	RING_API_REGISTER("uionshouldquit",ring_uiOnShouldQuit);
	RING_API_REGISTER("uiwindowonclosing",ring_uiWindowOnClosing);
	RING_API_REGISTER("uibuttononclicked",ring_uiButtonOnClicked);
	RING_API_REGISTER("uiqueuemain",ring_uiQueueMain);
	RING_API_REGISTER("uitimer",ring_uiTimer);
	RING_API_REGISTER("uiwindowoncontentsizechanged",ring_uiWindowOnContentSizeChanged);
	RING_API_REGISTER("uicheckboxontoggled",ring_uiCheckboxOnToggled);
	RING_API_REGISTER("uientryonchanged",ring_uiEntryOnChanged);
	RING_API_REGISTER("uispinboxonchanged",ring_uiSpinboxOnChanged);
	RING_API_REGISTER("uislideronchanged",ring_uiSliderOnChanged);
	RING_API_REGISTER("uicomboboxonselected",ring_uiComboboxOnSelected);
	RING_API_REGISTER("uieditablecomboboxonchanged",ring_uiEditableComboboxOnChanged);
	RING_API_REGISTER("uiradiobuttonsonselected",ring_uiRadioButtonsOnSelected);
	RING_API_REGISTER("uidatetimepickeronchanged",ring_uiDateTimePickerOnChanged);
	RING_API_REGISTER("uimultilineentryonchanged",ring_uiMultilineEntryOnChanged);
	RING_API_REGISTER("uimenuitemonclicked",ring_uiMenuItemOnClicked);
	RING_API_REGISTER("uifontbuttononchanged",ring_uiFontButtonOnChanged);
	RING_API_REGISTER("uicolorbuttononchanged",ring_uiColorButtonOnChanged);
	RING_API_REGISTER("uieventwindow",ring_uiEventWindow);
	RING_API_REGISTER("uieventbutton",ring_uiEventButton);
	RING_API_REGISTER("uieventcheckbox",ring_uiEventCheckbox);
	RING_API_REGISTER("uievententry",ring_uiEventEntry);
	RING_API_REGISTER("uieventspinbox",ring_uiEventSpinbox);
	RING_API_REGISTER("uieventslider",ring_uiEventSlider);
	RING_API_REGISTER("uieventcombobox",ring_uiEventCombobox);
	RING_API_REGISTER("uieventeditablecombobox",ring_uiEventEditableCombobox);
	RING_API_REGISTER("uieventradiobuttons",ring_uiEventRadioButtons);
	RING_API_REGISTER("uieventdatetimepicker",ring_uiEventDateTimePicker);
	RING_API_REGISTER("uieventmultilineentry",ring_uiEventMultilineEntry);
	RING_API_REGISTER("uieventmenuitem",ring_uiEventMenuItem);
	RING_API_REGISTER("uieventmenuitemwindow",ring_uiEventMenuItemWindow);
	RING_API_REGISTER("uieventfontbutton",ring_uiEventFontButton);
	RING_API_REGISTER("uieventcolorbutton",ring_uiEventColorButton);
	RING_API_REGISTER("uinewareahandler",ring_uiNewAreaHandler);
	RING_API_REGISTER("uieventareahandler",ring_uiEventAreaHandler);
	RING_API_REGISTER("uieventarea",ring_uiEventArea);
	RING_API_REGISTER("uieventareadrawparams",ring_uiEventAreaDrawParams);
	RING_API_REGISTER("uieventareakeyevent",ring_uiEventAreaKeyEvent);
	RING_API_REGISTER("uieventareamouseevent",ring_uiEventAreaMouseEvent);
	RING_API_REGISTER("uieventleft",ring_uiEventLeft);
	RING_API_REGISTER("setsolidbrush",ring_setSolidBrush);
	RING_API_REGISTER("uifreeiniterror",ring_uiFreeInitError);
	RING_API_REGISTER("uimain",ring_uiMain);
	RING_API_REGISTER("uimainsteps",ring_uiMainSteps);
	RING_API_REGISTER("uimainstep",ring_uiMainStep);
	RING_API_REGISTER("uiquit",ring_uiQuit);
	RING_API_REGISTER("uicontroldestroy",ring_uiControlDestroy);
	RING_API_REGISTER("uicontrolparent",ring_uiControlParent);
	RING_API_REGISTER("uicontrolsetparent",ring_uiControlSetParent);
	RING_API_REGISTER("uicontroltoplevel",ring_uiControlToplevel);
	RING_API_REGISTER("uicontrolvisible",ring_uiControlVisible);
	RING_API_REGISTER("uicontrolshow",ring_uiControlShow);
	RING_API_REGISTER("uicontrolhide",ring_uiControlHide);
	RING_API_REGISTER("uicontrolenabled",ring_uiControlEnabled);
	RING_API_REGISTER("uicontrolenable",ring_uiControlEnable);
	RING_API_REGISTER("uicontroldisable",ring_uiControlDisable);
	RING_API_REGISTER("uialloccontrol",ring_uiAllocControl);
	RING_API_REGISTER("uifreecontrol",ring_uiFreeControl);
	RING_API_REGISTER("uicontrolverifysetparent",ring_uiControlVerifySetParent);
	RING_API_REGISTER("uicontrolenabledtouser",ring_uiControlEnabledToUser);
	RING_API_REGISTER("uiuserbugcannotsetparentontoplevel",ring_uiUserBugCannotSetParentOnToplevel);
	RING_API_REGISTER("uiwindowsettitle",ring_uiWindowSetTitle);
	RING_API_REGISTER("uiwindowcontentsize",ring_uiWindowContentSize);
	RING_API_REGISTER("uiwindowsetcontentsize",ring_uiWindowSetContentSize);
	RING_API_REGISTER("uiwindowfullscreen",ring_uiWindowFullscreen);
	RING_API_REGISTER("uiwindowsetfullscreen",ring_uiWindowSetFullscreen);
	RING_API_REGISTER("uiwindowborderless",ring_uiWindowBorderless);
	RING_API_REGISTER("uiwindowsetborderless",ring_uiWindowSetBorderless);
	RING_API_REGISTER("uiwindowsetchild",ring_uiWindowSetChild);
	RING_API_REGISTER("uiwindowmargined",ring_uiWindowMargined);
	RING_API_REGISTER("uiwindowsetmargined",ring_uiWindowSetMargined);
	RING_API_REGISTER("uinewwindow",ring_uiNewWindow);
	RING_API_REGISTER("uibuttonsettext",ring_uiButtonSetText);
	RING_API_REGISTER("uinewbutton",ring_uiNewButton);
	RING_API_REGISTER("uiboxappend",ring_uiBoxAppend);
	RING_API_REGISTER("uiboxdelete",ring_uiBoxDelete);
	RING_API_REGISTER("uiboxpadded",ring_uiBoxPadded);
	RING_API_REGISTER("uiboxsetpadded",ring_uiBoxSetPadded);
	RING_API_REGISTER("uinewhorizontalbox",ring_uiNewHorizontalBox);
	RING_API_REGISTER("uinewverticalbox",ring_uiNewVerticalBox);
	RING_API_REGISTER("uicheckboxsettext",ring_uiCheckboxSetText);
	RING_API_REGISTER("uicheckboxchecked",ring_uiCheckboxChecked);
	RING_API_REGISTER("uicheckboxsetchecked",ring_uiCheckboxSetChecked);
	RING_API_REGISTER("uinewcheckbox",ring_uiNewCheckbox);
	RING_API_REGISTER("uientrysettext",ring_uiEntrySetText);
	RING_API_REGISTER("uientryreadonly",ring_uiEntryReadOnly);
	RING_API_REGISTER("uientrysetreadonly",ring_uiEntrySetReadOnly);
	RING_API_REGISTER("uinewentry",ring_uiNewEntry);
	RING_API_REGISTER("uinewpasswordentry",ring_uiNewPasswordEntry);
	RING_API_REGISTER("uinewsearchentry",ring_uiNewSearchEntry);
	RING_API_REGISTER("uilabelsettext",ring_uiLabelSetText);
	RING_API_REGISTER("uinewlabel",ring_uiNewLabel);
	RING_API_REGISTER("uitabappend",ring_uiTabAppend);
	RING_API_REGISTER("uitabinsertat",ring_uiTabInsertAt);
	RING_API_REGISTER("uitabdelete",ring_uiTabDelete);
	RING_API_REGISTER("uitabnumpages",ring_uiTabNumPages);
	RING_API_REGISTER("uitabmargined",ring_uiTabMargined);
	RING_API_REGISTER("uitabsetmargined",ring_uiTabSetMargined);
	RING_API_REGISTER("uinewtab",ring_uiNewTab);
	RING_API_REGISTER("uigroupsettitle",ring_uiGroupSetTitle);
	RING_API_REGISTER("uigroupsetchild",ring_uiGroupSetChild);
	RING_API_REGISTER("uigroupmargined",ring_uiGroupMargined);
	RING_API_REGISTER("uigroupsetmargined",ring_uiGroupSetMargined);
	RING_API_REGISTER("uinewgroup",ring_uiNewGroup);
	RING_API_REGISTER("uispinboxvalue",ring_uiSpinboxValue);
	RING_API_REGISTER("uispinboxsetvalue",ring_uiSpinboxSetValue);
	RING_API_REGISTER("uinewspinbox",ring_uiNewSpinbox);
	RING_API_REGISTER("uislidervalue",ring_uiSliderValue);
	RING_API_REGISTER("uislidersetvalue",ring_uiSliderSetValue);
	RING_API_REGISTER("uinewslider",ring_uiNewSlider);
	RING_API_REGISTER("uiprogressbarvalue",ring_uiProgressBarValue);
	RING_API_REGISTER("uiprogressbarsetvalue",ring_uiProgressBarSetValue);
	RING_API_REGISTER("uinewprogressbar",ring_uiNewProgressBar);
	RING_API_REGISTER("uinewhorizontalseparator",ring_uiNewHorizontalSeparator);
	RING_API_REGISTER("uinewverticalseparator",ring_uiNewVerticalSeparator);
	RING_API_REGISTER("uicomboboxappend",ring_uiComboboxAppend);
	RING_API_REGISTER("uicomboboxselected",ring_uiComboboxSelected);
	RING_API_REGISTER("uicomboboxsetselected",ring_uiComboboxSetSelected);
	RING_API_REGISTER("uinewcombobox",ring_uiNewCombobox);
	RING_API_REGISTER("uieditablecomboboxappend",ring_uiEditableComboboxAppend);
	RING_API_REGISTER("uieditablecomboboxsettext",ring_uiEditableComboboxSetText);
	RING_API_REGISTER("uineweditablecombobox",ring_uiNewEditableCombobox);
	RING_API_REGISTER("uiradiobuttonsappend",ring_uiRadioButtonsAppend);
	RING_API_REGISTER("uiradiobuttonsselected",ring_uiRadioButtonsSelected);
	RING_API_REGISTER("uiradiobuttonssetselected",ring_uiRadioButtonsSetSelected);
	RING_API_REGISTER("uinewradiobuttons",ring_uiNewRadioButtons);
	RING_API_REGISTER("uidatetimepickertime",ring_uiDateTimePickerTime);
	RING_API_REGISTER("uidatetimepickersettime",ring_uiDateTimePickerSetTime);
	RING_API_REGISTER("uinewdatetimepicker",ring_uiNewDateTimePicker);
	RING_API_REGISTER("uinewdatepicker",ring_uiNewDatePicker);
	RING_API_REGISTER("uinewtimepicker",ring_uiNewTimePicker);
	RING_API_REGISTER("uimultilineentrysettext",ring_uiMultilineEntrySetText);
	RING_API_REGISTER("uimultilineentryappend",ring_uiMultilineEntryAppend);
	RING_API_REGISTER("uimultilineentryreadonly",ring_uiMultilineEntryReadOnly);
	RING_API_REGISTER("uimultilineentrysetreadonly",ring_uiMultilineEntrySetReadOnly);
	RING_API_REGISTER("uinewmultilineentry",ring_uiNewMultilineEntry);
	RING_API_REGISTER("uinewnonwrappingmultilineentry",ring_uiNewNonWrappingMultilineEntry);
	RING_API_REGISTER("uimenuitemenable",ring_uiMenuItemEnable);
	RING_API_REGISTER("uimenuitemdisable",ring_uiMenuItemDisable);
	RING_API_REGISTER("uimenuitemchecked",ring_uiMenuItemChecked);
	RING_API_REGISTER("uimenuitemsetchecked",ring_uiMenuItemSetChecked);
	RING_API_REGISTER("uimenuappenditem",ring_uiMenuAppendItem);
	RING_API_REGISTER("uimenuappendcheckitem",ring_uiMenuAppendCheckItem);
	RING_API_REGISTER("uimenuappendquititem",ring_uiMenuAppendQuitItem);
	RING_API_REGISTER("uimenuappendpreferencesitem",ring_uiMenuAppendPreferencesItem);
	RING_API_REGISTER("uimenuappendaboutitem",ring_uiMenuAppendAboutItem);
	RING_API_REGISTER("uimenuappendseparator",ring_uiMenuAppendSeparator);
	RING_API_REGISTER("uinewmenu",ring_uiNewMenu);
	RING_API_REGISTER("uimsgbox",ring_uiMsgBox);
	RING_API_REGISTER("uimsgboxerror",ring_uiMsgBoxError);
	RING_API_REGISTER("uiareaqueueredrawall",ring_uiAreaQueueRedrawAll);
	RING_API_REGISTER("uiareascrollto",ring_uiAreaScrollTo);
	RING_API_REGISTER("uiareabeginuserwindowmove",ring_uiAreaBeginUserWindowMove);
	RING_API_REGISTER("uiareabeginuserwindowresize",ring_uiAreaBeginUserWindowResize);
	RING_API_REGISTER("uinewarea",ring_uiNewArea);
	RING_API_REGISTER("uinewscrollingarea",ring_uiNewScrollingArea);
	RING_API_REGISTER("uidrawnewpath",ring_uiDrawNewPath);
	RING_API_REGISTER("uidrawfreepath",ring_uiDrawFreePath);
	RING_API_REGISTER("uidrawpathnewfigure",ring_uiDrawPathNewFigure);
	RING_API_REGISTER("uidrawpathnewfigurewitharc",ring_uiDrawPathNewFigureWithArc);
	RING_API_REGISTER("uidrawpathlineto",ring_uiDrawPathLineTo);
	RING_API_REGISTER("uidrawpatharcto",ring_uiDrawPathArcTo);
	RING_API_REGISTER("uidrawpathbezierto",ring_uiDrawPathBezierTo);
	RING_API_REGISTER("uidrawpathclosefigure",ring_uiDrawPathCloseFigure);
	RING_API_REGISTER("uidrawpathaddrectangle",ring_uiDrawPathAddRectangle);
	RING_API_REGISTER("uidrawpathend",ring_uiDrawPathEnd);
	RING_API_REGISTER("uidrawstroke",ring_uiDrawStroke);
	RING_API_REGISTER("uidrawfill",ring_uiDrawFill);
	RING_API_REGISTER("uidrawmatrixsetidentity",ring_uiDrawMatrixSetIdentity);
	RING_API_REGISTER("uidrawmatrixtranslate",ring_uiDrawMatrixTranslate);
	RING_API_REGISTER("uidrawmatrixscale",ring_uiDrawMatrixScale);
	RING_API_REGISTER("uidrawmatrixrotate",ring_uiDrawMatrixRotate);
	RING_API_REGISTER("uidrawmatrixskew",ring_uiDrawMatrixSkew);
	RING_API_REGISTER("uidrawmatrixmultiply",ring_uiDrawMatrixMultiply);
	RING_API_REGISTER("uidrawmatrixinvertible",ring_uiDrawMatrixInvertible);
	RING_API_REGISTER("uidrawmatrixinvert",ring_uiDrawMatrixInvert);
	RING_API_REGISTER("uidrawmatrixtransformpoint",ring_uiDrawMatrixTransformPoint);
	RING_API_REGISTER("uidrawmatrixtransformsize",ring_uiDrawMatrixTransformSize);
	RING_API_REGISTER("uidrawtransform",ring_uiDrawTransform);
	RING_API_REGISTER("uidrawclip",ring_uiDrawClip);
	RING_API_REGISTER("uidrawsave",ring_uiDrawSave);
	RING_API_REGISTER("uidrawrestore",ring_uiDrawRestore);
	RING_API_REGISTER("uiattributegettype",ring_uiAttributeGetType);
	RING_API_REGISTER("uinewfamilyattribute",ring_uiNewFamilyAttribute);
	RING_API_REGISTER("uiattributefamily",ring_uiAttributeFamily);
	RING_API_REGISTER("uinewsizeattribute",ring_uiNewSizeAttribute);
	RING_API_REGISTER("uiattributesize",ring_uiAttributeSize);
	RING_API_REGISTER("uinewstretchattribute",ring_uiNewStretchAttribute);
	RING_API_REGISTER("uiattributestretch",ring_uiAttributeStretch);
	RING_API_REGISTER("uinewcolorattribute",ring_uiNewColorAttribute);
	RING_API_REGISTER("uiattributecolor",ring_uiAttributeColor);
	RING_API_REGISTER("uinewbackgroundattribute",ring_uiNewBackgroundAttribute);
	RING_API_REGISTER("uinewunderlineattribute",ring_uiNewUnderlineAttribute);
	RING_API_REGISTER("uiattributeunderline",ring_uiAttributeUnderline);
	RING_API_REGISTER("uinewunderlinecolorattribute",ring_uiNewUnderlineColorAttribute);
	RING_API_REGISTER("uiattributeunderlinecolor",ring_uiAttributeUnderlineColor);
	RING_API_REGISTER("uinewopentypefeatures",ring_uiNewOpenTypeFeatures);
	RING_API_REGISTER("uifreeopentypefeatures",ring_uiFreeOpenTypeFeatures);
	RING_API_REGISTER("uiopentypefeaturesclone",ring_uiOpenTypeFeaturesClone);
	RING_API_REGISTER("uiopentypefeaturesadd",ring_uiOpenTypeFeaturesAdd);
	RING_API_REGISTER("uiopentypefeaturesremove",ring_uiOpenTypeFeaturesRemove);
	RING_API_REGISTER("uiopentypefeaturesget",ring_uiOpenTypeFeaturesGet);
	RING_API_REGISTER("uiopentypefeaturesforeach",ring_uiOpenTypeFeaturesForEach);
	RING_API_REGISTER("uinewfeaturesattribute",ring_uiNewFeaturesAttribute);
	RING_API_REGISTER("uiattributefeatures",ring_uiAttributeFeatures);
	RING_API_REGISTER("uinewattributedstring",ring_uiNewAttributedString);
	RING_API_REGISTER("uifreeattributedstring",ring_uiFreeAttributedString);
	RING_API_REGISTER("uiattributedstringstring",ring_uiAttributedStringString);
	RING_API_REGISTER("uiattributedstringlen",ring_uiAttributedStringLen);
	RING_API_REGISTER("uiattributedstringappendunattributed",ring_uiAttributedStringAppendUnattributed);
	RING_API_REGISTER("uiattributedstringinsertatunattributed",ring_uiAttributedStringInsertAtUnattributed);
	RING_API_REGISTER("uiattributedstringdelete",ring_uiAttributedStringDelete);
	RING_API_REGISTER("uiattributedstringsetattribute",ring_uiAttributedStringSetAttribute);
	RING_API_REGISTER("uiattributedstringforeachattribute",ring_uiAttributedStringForEachAttribute);
	RING_API_REGISTER("uiattributedstringnumgraphemes",ring_uiAttributedStringNumGraphemes);
	RING_API_REGISTER("uiattributedstringbyteindextographeme",ring_uiAttributedStringByteIndexToGrapheme);
	RING_API_REGISTER("uiattributedstringgraphemetobyteindex",ring_uiAttributedStringGraphemeToByteIndex);
	RING_API_REGISTER("uidrawnewtextlayout",ring_uiDrawNewTextLayout);
	RING_API_REGISTER("uidrawfreetextlayout",ring_uiDrawFreeTextLayout);
	RING_API_REGISTER("uidrawtext",ring_uiDrawText);
	RING_API_REGISTER("uidrawtextlayoutextents",ring_uiDrawTextLayoutExtents);
	RING_API_REGISTER("uifontbuttonfont",ring_uiFontButtonFont);
	RING_API_REGISTER("uinewfontbutton",ring_uiNewFontButton);
	RING_API_REGISTER("uifreefontbuttonfont",ring_uiFreeFontButtonFont);
	RING_API_REGISTER("uicolorbuttoncolor",ring_uiColorButtonColor);
	RING_API_REGISTER("uicolorbuttonsetcolor",ring_uiColorButtonSetColor);
	RING_API_REGISTER("uinewcolorbutton",ring_uiNewColorButton);
	RING_API_REGISTER("uiformappend",ring_uiFormAppend);
	RING_API_REGISTER("uiformdelete",ring_uiFormDelete);
	RING_API_REGISTER("uiformpadded",ring_uiFormPadded);
	RING_API_REGISTER("uiformsetpadded",ring_uiFormSetPadded);
	RING_API_REGISTER("uinewform",ring_uiNewForm);
	RING_API_REGISTER("uigridappend",ring_uiGridAppend);
	RING_API_REGISTER("uigridinsertat",ring_uiGridInsertAt);
	RING_API_REGISTER("uigridpadded",ring_uiGridPadded);
	RING_API_REGISTER("uigridsetpadded",ring_uiGridSetPadded);
	RING_API_REGISTER("uinewgrid",ring_uiNewGrid);
	RING_API_REGISTER("uitablevaluegettype",ring_uiTableValueGetType);
	RING_API_REGISTER("uinewtablevaluestring",ring_uiNewTableValueString);
	RING_API_REGISTER("uitablevaluestring",ring_uiTableValueString);
	RING_API_REGISTER("uinewtablevalueimage",ring_uiNewTableValueImage);
	RING_API_REGISTER("uitablevalueimage",ring_uiTableValueImage);
	RING_API_REGISTER("uinewtablevalueint",ring_uiNewTableValueInt);
	RING_API_REGISTER("uitablevalueint",ring_uiTableValueInt);
	RING_API_REGISTER("uinewtablevaluecolor",ring_uiNewTableValueColor);
	RING_API_REGISTER("uitablevaluecolor",ring_uiTableValueColor);
	RING_API_REGISTER("uinewimage",ring_uiNewImage);
	RING_API_REGISTER("uifreeimage",ring_uiFreeImage);
	RING_API_REGISTER("uiimageappend",ring_uiImageAppend);
	RING_API_REGISTER("uifreetablevalue",ring_uiFreeTableValue);
	RING_API_REGISTER("uinewtablemodel",ring_uiNewTableModel);
	RING_API_REGISTER("uifreetablemodel",ring_uiFreeTableModel);
	RING_API_REGISTER("uitablemodelrowinserted",ring_uiTableModelRowInserted);
	RING_API_REGISTER("uitablemodelrowchanged",ring_uiTableModelRowChanged);
	RING_API_REGISTER("uitablemodelrowdeleted",ring_uiTableModelRowDeleted);
	RING_API_REGISTER("uinewweightattribute",ring_uiNewWeightAttribute);
	RING_API_REGISTER("uiattributeweight",ring_uiAttributeWeight);
	RING_API_REGISTER("uinewitalicattribute",ring_uiNewItalicAttribute);
	RING_API_REGISTER("uiattributeitalic",ring_uiAttributeItalic);
	RING_API_REGISTER("uifreeattribute",ring_uiFreeAttribute);
	RING_API_REGISTER("uitableappendtextcolumn",ring_uiTableAppendTextColumn);
	RING_API_REGISTER("uitableappendimagecolumn",ring_uiTableAppendImageColumn);
	RING_API_REGISTER("uitableappendimagetextcolumn",ring_uiTableAppendImageTextColumn);
	RING_API_REGISTER("uitableappendcheckboxcolumn",ring_uiTableAppendCheckboxColumn);
	RING_API_REGISTER("uitableappendcheckboxtextcolumn",ring_uiTableAppendCheckboxTextColumn);
	RING_API_REGISTER("uitableappendprogressbarcolumn",ring_uiTableAppendProgressBarColumn);
	RING_API_REGISTER("uitableappendbuttoncolumn",ring_uiTableAppendButtonColumn);
	RING_API_REGISTER("uinewtable",ring_uiNewTable);
	RING_API_REGISTER("uiareasetsize",ring_uiAreaSetSize);
	RING_API_REGISTER("uicontrolhandle",ring_uiControlHandle);
	RING_API_REGISTER("uiwindowtitle",ring_uiWindowTitle);
	RING_API_REGISTER("uibuttontext",ring_uiButtonText);
	RING_API_REGISTER("uicheckboxtext",ring_uiCheckboxText);
	RING_API_REGISTER("uientrytext",ring_uiEntryText);
	RING_API_REGISTER("uimultilineentrytext",ring_uiMultilineEntryText);
	RING_API_REGISTER("uilabeltext",ring_uiLabelText);
	RING_API_REGISTER("uigrouptitle",ring_uiGroupTitle);
	RING_API_REGISTER("uieditablecomboboxtext",ring_uiEditableComboboxText);
	RING_API_REGISTER("uiopenfile",ring_uiOpenFile);
	RING_API_REGISTER("uisavefile",ring_uiSaveFile);
	RING_API_REGISTER("get_uipi",ring_get_uipi);
	RING_API_REGISTER("get_uiforeachcontinue",ring_get_uiforeachcontinue);
	RING_API_REGISTER("get_uiforeachstop",ring_get_uiforeachstop);
	RING_API_REGISTER("get_uiwindowresizeedgeleft",ring_get_uiwindowresizeedgeleft);
	RING_API_REGISTER("get_uiwindowresizeedgetop",ring_get_uiwindowresizeedgetop);
	RING_API_REGISTER("get_uiwindowresizeedgeright",ring_get_uiwindowresizeedgeright);
	RING_API_REGISTER("get_uiwindowresizeedgebottom",ring_get_uiwindowresizeedgebottom);
	RING_API_REGISTER("get_uiwindowresizeedgetopleft",ring_get_uiwindowresizeedgetopleft);
	RING_API_REGISTER("get_uiwindowresizeedgetopright",ring_get_uiwindowresizeedgetopright);
	RING_API_REGISTER("get_uiwindowresizeedgebottomleft",ring_get_uiwindowresizeedgebottomleft);
	RING_API_REGISTER("get_uiwindowresizeedgebottomright",ring_get_uiwindowresizeedgebottomright);
	RING_API_REGISTER("get_uidrawbrushtypesolid",ring_get_uidrawbrushtypesolid);
	RING_API_REGISTER("get_uidrawbrushtypelineargradient",ring_get_uidrawbrushtypelineargradient);
	RING_API_REGISTER("get_uidrawbrushtyperadialgradient",ring_get_uidrawbrushtyperadialgradient);
	RING_API_REGISTER("get_uidrawbrushtypeimage",ring_get_uidrawbrushtypeimage);
	RING_API_REGISTER("get_uidrawdefaultmiterlimit",ring_get_uidrawdefaultmiterlimit);
	RING_API_REGISTER("get_uitablemodelcolumnnevereditable",ring_get_uitablemodelcolumnnevereditable);
	RING_API_REGISTER("get_uitablemodelcolumnalwayseditable",ring_get_uitablemodelcolumnalwayseditable);
	RING_API_REGISTER("get_uidrawlinecapflat",ring_get_uidrawlinecapflat);
	RING_API_REGISTER("get_uidrawlinecapround",ring_get_uidrawlinecapround);
	RING_API_REGISTER("get_uidrawlinecapsquare",ring_get_uidrawlinecapsquare);
	RING_API_REGISTER("get_uidrawlinejoinmiter",ring_get_uidrawlinejoinmiter);
	RING_API_REGISTER("get_uidrawlinejoinround",ring_get_uidrawlinejoinround);
	RING_API_REGISTER("get_uidrawlinejoinbevel",ring_get_uidrawlinejoinbevel);
	RING_API_REGISTER("get_uidrawfillmodewinding",ring_get_uidrawfillmodewinding);
	RING_API_REGISTER("get_uidrawfillmodealternate",ring_get_uidrawfillmodealternate);
	RING_API_REGISTER("get_uiattributetypefamily",ring_get_uiattributetypefamily);
	RING_API_REGISTER("get_uiattributetypesize",ring_get_uiattributetypesize);
	RING_API_REGISTER("get_uiattributetypeweight",ring_get_uiattributetypeweight);
	RING_API_REGISTER("get_uiattributetypeitalic",ring_get_uiattributetypeitalic);
	RING_API_REGISTER("get_uiattributetypestretch",ring_get_uiattributetypestretch);
	RING_API_REGISTER("get_uiattributetypecolor",ring_get_uiattributetypecolor);
	RING_API_REGISTER("get_uiattributetypebackground",ring_get_uiattributetypebackground);
	RING_API_REGISTER("get_uiattributetypeunderline",ring_get_uiattributetypeunderline);
	RING_API_REGISTER("get_uiattributetypeunderlinecolor",ring_get_uiattributetypeunderlinecolor);
	RING_API_REGISTER("get_uiattributetypefeatures",ring_get_uiattributetypefeatures);
	RING_API_REGISTER("get_uitextweightminimum",ring_get_uitextweightminimum);
	RING_API_REGISTER("get_uitextweightthin",ring_get_uitextweightthin);
	RING_API_REGISTER("get_uitextweightultralight",ring_get_uitextweightultralight);
	RING_API_REGISTER("get_uitextweightlight",ring_get_uitextweightlight);
	RING_API_REGISTER("get_uitextweightbook",ring_get_uitextweightbook);
	RING_API_REGISTER("get_uitextweightnormal",ring_get_uitextweightnormal);
	RING_API_REGISTER("get_uitextweightmedium",ring_get_uitextweightmedium);
	RING_API_REGISTER("get_uitextweightsemibold",ring_get_uitextweightsemibold);
	RING_API_REGISTER("get_uitextweightbold",ring_get_uitextweightbold);
	RING_API_REGISTER("get_uitextweightultrabold",ring_get_uitextweightultrabold);
	RING_API_REGISTER("get_uitextweightheavy",ring_get_uitextweightheavy);
	RING_API_REGISTER("get_uitextweightultraheavy",ring_get_uitextweightultraheavy);
	RING_API_REGISTER("get_uitextweightmaximum",ring_get_uitextweightmaximum);
	RING_API_REGISTER("get_uitextstretchultracondensed",ring_get_uitextstretchultracondensed);
	RING_API_REGISTER("get_uitextstretchextracondensed",ring_get_uitextstretchextracondensed);
	RING_API_REGISTER("get_uitextstretchcondensed",ring_get_uitextstretchcondensed);
	RING_API_REGISTER("get_uitextstretchsemicondensed",ring_get_uitextstretchsemicondensed);
	RING_API_REGISTER("get_uitextstretchnormal",ring_get_uitextstretchnormal);
	RING_API_REGISTER("get_uitextstretchsemiexpanded",ring_get_uitextstretchsemiexpanded);
	RING_API_REGISTER("get_uitextstretchexpanded",ring_get_uitextstretchexpanded);
	RING_API_REGISTER("get_uitextstretchextraexpanded",ring_get_uitextstretchextraexpanded);
	RING_API_REGISTER("get_uitextstretchultraexpanded",ring_get_uitextstretchultraexpanded);
	RING_API_REGISTER("get_uitextitalicnormal",ring_get_uitextitalicnormal);
	RING_API_REGISTER("get_uitextitalicoblique",ring_get_uitextitalicoblique);
	RING_API_REGISTER("get_uitextitalicitalic",ring_get_uitextitalicitalic);
	RING_API_REGISTER("get_uiunderlinenone",ring_get_uiunderlinenone);
	RING_API_REGISTER("get_uiunderlinesingle",ring_get_uiunderlinesingle);
	RING_API_REGISTER("get_uiunderlinedouble",ring_get_uiunderlinedouble);
	RING_API_REGISTER("get_uiunderlinesuggestion",ring_get_uiunderlinesuggestion);
	RING_API_REGISTER("get_uiunderlinecolorcustom",ring_get_uiunderlinecolorcustom);
	RING_API_REGISTER("get_uiunderlinecolorspelling",ring_get_uiunderlinecolorspelling);
	RING_API_REGISTER("get_uiunderlinecolorgrammar",ring_get_uiunderlinecolorgrammar);
	RING_API_REGISTER("get_uiunderlinecolorauxiliary",ring_get_uiunderlinecolorauxiliary);
	RING_API_REGISTER("get_uidrawtextalignleft",ring_get_uidrawtextalignleft);
	RING_API_REGISTER("get_uidrawtextaligncenter",ring_get_uidrawtextaligncenter);
	RING_API_REGISTER("get_uidrawtextalignright",ring_get_uidrawtextalignright);
	RING_API_REGISTER("get_uimodifierctrl",ring_get_uimodifierctrl);
	RING_API_REGISTER("get_uimodifieralt",ring_get_uimodifieralt);
	RING_API_REGISTER("get_uimodifiershift",ring_get_uimodifiershift);
	RING_API_REGISTER("get_uimodifiersuper",ring_get_uimodifiersuper);
	RING_API_REGISTER("get_uiextkeyescape",ring_get_uiextkeyescape);
	RING_API_REGISTER("get_uiextkeyinsert",ring_get_uiextkeyinsert);
	RING_API_REGISTER("get_uiextkeydelete",ring_get_uiextkeydelete);
	RING_API_REGISTER("get_uiextkeyhome",ring_get_uiextkeyhome);
	RING_API_REGISTER("get_uiextkeyend",ring_get_uiextkeyend);
	RING_API_REGISTER("get_uiextkeypageup",ring_get_uiextkeypageup);
	RING_API_REGISTER("get_uiextkeypagedown",ring_get_uiextkeypagedown);
	RING_API_REGISTER("get_uiextkeyup",ring_get_uiextkeyup);
	RING_API_REGISTER("get_uiextkeydown",ring_get_uiextkeydown);
	RING_API_REGISTER("get_uiextkeyleft",ring_get_uiextkeyleft);
	RING_API_REGISTER("get_uiextkeyright",ring_get_uiextkeyright);
	RING_API_REGISTER("get_uiextkeyf1",ring_get_uiextkeyf1);
	RING_API_REGISTER("get_uiextkeyf2",ring_get_uiextkeyf2);
	RING_API_REGISTER("get_uiextkeyf3",ring_get_uiextkeyf3);
	RING_API_REGISTER("get_uiextkeyf4",ring_get_uiextkeyf4);
	RING_API_REGISTER("get_uiextkeyf5",ring_get_uiextkeyf5);
	RING_API_REGISTER("get_uiextkeyf6",ring_get_uiextkeyf6);
	RING_API_REGISTER("get_uiextkeyf7",ring_get_uiextkeyf7);
	RING_API_REGISTER("get_uiextkeyf8",ring_get_uiextkeyf8);
	RING_API_REGISTER("get_uiextkeyf9",ring_get_uiextkeyf9);
	RING_API_REGISTER("get_uiextkeyf10",ring_get_uiextkeyf10);
	RING_API_REGISTER("get_uiextkeyf11",ring_get_uiextkeyf11);
	RING_API_REGISTER("get_uiextkeyf12",ring_get_uiextkeyf12);
	RING_API_REGISTER("get_uiextkeyn0",ring_get_uiextkeyn0);
	RING_API_REGISTER("get_uiextkeyn1",ring_get_uiextkeyn1);
	RING_API_REGISTER("get_uiextkeyn2",ring_get_uiextkeyn2);
	RING_API_REGISTER("get_uiextkeyn3",ring_get_uiextkeyn3);
	RING_API_REGISTER("get_uiextkeyn4",ring_get_uiextkeyn4);
	RING_API_REGISTER("get_uiextkeyn5",ring_get_uiextkeyn5);
	RING_API_REGISTER("get_uiextkeyn6",ring_get_uiextkeyn6);
	RING_API_REGISTER("get_uiextkeyn7",ring_get_uiextkeyn7);
	RING_API_REGISTER("get_uiextkeyn8",ring_get_uiextkeyn8);
	RING_API_REGISTER("get_uiextkeyn9",ring_get_uiextkeyn9);
	RING_API_REGISTER("get_uiextkeyndot",ring_get_uiextkeyndot);
	RING_API_REGISTER("get_uiextkeynenter",ring_get_uiextkeynenter);
	RING_API_REGISTER("get_uiextkeynadd",ring_get_uiextkeynadd);
	RING_API_REGISTER("get_uiextkeynsubtract",ring_get_uiextkeynsubtract);
	RING_API_REGISTER("get_uiextkeynmultiply",ring_get_uiextkeynmultiply);
	RING_API_REGISTER("get_uiextkeyndivide",ring_get_uiextkeyndivide);
	RING_API_REGISTER("get_uialignfill",ring_get_uialignfill);
	RING_API_REGISTER("get_uialignstart",ring_get_uialignstart);
	RING_API_REGISTER("get_uialigncenter",ring_get_uialigncenter);
	RING_API_REGISTER("get_uialignend",ring_get_uialignend);
	RING_API_REGISTER("get_uiatleading",ring_get_uiatleading);
	RING_API_REGISTER("get_uiattop",ring_get_uiattop);
	RING_API_REGISTER("get_uiattrailing",ring_get_uiattrailing);
	RING_API_REGISTER("get_uiatbottom",ring_get_uiatbottom);
	RING_API_REGISTER("get_uitablevaluetypestring",ring_get_uitablevaluetypestring);
	RING_API_REGISTER("get_uitablevaluetypeimage",ring_get_uitablevaluetypeimage);
	RING_API_REGISTER("get_uitablevaluetypeint",ring_get_uitablevaluetypeint);
	RING_API_REGISTER("get_uitablevaluetypecolor",ring_get_uitablevaluetypecolor);
	RING_API_REGISTER("new_uiinitoptions",ring_new_uiinitoptions);
	RING_API_REGISTER("new_managed_uiinitoptions",ring_new_managed_uiinitoptions);
	RING_API_REGISTER("destroy_uiinitoptions",ring_destroy_uiinitoptions);
	RING_API_REGISTER("new_uicontrol",ring_new_uicontrol);
	RING_API_REGISTER("new_managed_uicontrol",ring_new_managed_uicontrol);
	RING_API_REGISTER("destroy_uicontrol",ring_destroy_uicontrol);
	RING_API_REGISTER("get_uicontrol_signature",ring_get_uicontrol_Signature);
	RING_API_REGISTER("set_uicontrol_signature",ring_set_uicontrol_Signature);
	RING_API_REGISTER("get_uicontrol_ossignature",ring_get_uicontrol_OSSignature);
	RING_API_REGISTER("set_uicontrol_ossignature",ring_set_uicontrol_OSSignature);
	RING_API_REGISTER("get_uicontrol_typesignature",ring_get_uicontrol_TypeSignature);
	RING_API_REGISTER("set_uicontrol_typesignature",ring_set_uicontrol_TypeSignature);
	RING_API_REGISTER("new_uiareadrawparams",ring_new_uiareadrawparams);
	RING_API_REGISTER("new_managed_uiareadrawparams",ring_new_managed_uiareadrawparams);
	RING_API_REGISTER("destroy_uiareadrawparams",ring_destroy_uiareadrawparams);
	RING_API_REGISTER("get_uiareadrawparams_context",ring_get_uiareadrawparams_Context);
	RING_API_REGISTER("set_uiareadrawparams_context",ring_set_uiareadrawparams_Context);
	RING_API_REGISTER("get_uiareadrawparams_areawidth",ring_get_uiareadrawparams_AreaWidth);
	RING_API_REGISTER("set_uiareadrawparams_areawidth",ring_set_uiareadrawparams_AreaWidth);
	RING_API_REGISTER("get_uiareadrawparams_areaheight",ring_get_uiareadrawparams_AreaHeight);
	RING_API_REGISTER("set_uiareadrawparams_areaheight",ring_set_uiareadrawparams_AreaHeight);
	RING_API_REGISTER("get_uiareadrawparams_clipx",ring_get_uiareadrawparams_ClipX);
	RING_API_REGISTER("set_uiareadrawparams_clipx",ring_set_uiareadrawparams_ClipX);
	RING_API_REGISTER("get_uiareadrawparams_clipy",ring_get_uiareadrawparams_ClipY);
	RING_API_REGISTER("set_uiareadrawparams_clipy",ring_set_uiareadrawparams_ClipY);
	RING_API_REGISTER("get_uiareadrawparams_clipwidth",ring_get_uiareadrawparams_ClipWidth);
	RING_API_REGISTER("set_uiareadrawparams_clipwidth",ring_set_uiareadrawparams_ClipWidth);
	RING_API_REGISTER("get_uiareadrawparams_clipheight",ring_get_uiareadrawparams_ClipHeight);
	RING_API_REGISTER("set_uiareadrawparams_clipheight",ring_set_uiareadrawparams_ClipHeight);
	RING_API_REGISTER("new_uidrawmatrix",ring_new_uidrawmatrix);
	RING_API_REGISTER("new_managed_uidrawmatrix",ring_new_managed_uidrawmatrix);
	RING_API_REGISTER("destroy_uidrawmatrix",ring_destroy_uidrawmatrix);
	RING_API_REGISTER("get_uidrawmatrix_m11",ring_get_uidrawmatrix_M11);
	RING_API_REGISTER("set_uidrawmatrix_m11",ring_set_uidrawmatrix_M11);
	RING_API_REGISTER("get_uidrawmatrix_m12",ring_get_uidrawmatrix_M12);
	RING_API_REGISTER("set_uidrawmatrix_m12",ring_set_uidrawmatrix_M12);
	RING_API_REGISTER("get_uidrawmatrix_m21",ring_get_uidrawmatrix_M21);
	RING_API_REGISTER("set_uidrawmatrix_m21",ring_set_uidrawmatrix_M21);
	RING_API_REGISTER("get_uidrawmatrix_m22",ring_get_uidrawmatrix_M22);
	RING_API_REGISTER("set_uidrawmatrix_m22",ring_set_uidrawmatrix_M22);
	RING_API_REGISTER("get_uidrawmatrix_m31",ring_get_uidrawmatrix_M31);
	RING_API_REGISTER("set_uidrawmatrix_m31",ring_set_uidrawmatrix_M31);
	RING_API_REGISTER("get_uidrawmatrix_m32",ring_get_uidrawmatrix_M32);
	RING_API_REGISTER("set_uidrawmatrix_m32",ring_set_uidrawmatrix_M32);
	RING_API_REGISTER("new_uitabletextcolumnoptionalparams",ring_new_uitabletextcolumnoptionalparams);
	RING_API_REGISTER("new_managed_uitabletextcolumnoptionalparams",ring_new_managed_uitabletextcolumnoptionalparams);
	RING_API_REGISTER("destroy_uitabletextcolumnoptionalparams",ring_destroy_uitabletextcolumnoptionalparams);
	RING_API_REGISTER("get_uitabletextcolumnoptionalparams_colormodelcolumn",ring_get_uitabletextcolumnoptionalparams_ColorModelColumn);
	RING_API_REGISTER("set_uitabletextcolumnoptionalparams_colormodelcolumn",ring_set_uitabletextcolumnoptionalparams_ColorModelColumn);
	RING_API_REGISTER("new_uidrawbrush",ring_new_uidrawbrush);
	RING_API_REGISTER("new_managed_uidrawbrush",ring_new_managed_uidrawbrush);
	RING_API_REGISTER("destroy_uidrawbrush",ring_destroy_uidrawbrush);
	RING_API_REGISTER("get_uidrawbrush_type",ring_get_uidrawbrush_Type);
	RING_API_REGISTER("set_uidrawbrush_type",ring_set_uidrawbrush_Type);
	RING_API_REGISTER("get_uidrawbrush_r",ring_get_uidrawbrush_R);
	RING_API_REGISTER("set_uidrawbrush_r",ring_set_uidrawbrush_R);
	RING_API_REGISTER("get_uidrawbrush_g",ring_get_uidrawbrush_G);
	RING_API_REGISTER("set_uidrawbrush_g",ring_set_uidrawbrush_G);
	RING_API_REGISTER("get_uidrawbrush_b",ring_get_uidrawbrush_B);
	RING_API_REGISTER("set_uidrawbrush_b",ring_set_uidrawbrush_B);
	RING_API_REGISTER("get_uidrawbrush_a",ring_get_uidrawbrush_A);
	RING_API_REGISTER("set_uidrawbrush_a",ring_set_uidrawbrush_A);
	RING_API_REGISTER("get_uidrawbrush_x0",ring_get_uidrawbrush_X0);
	RING_API_REGISTER("set_uidrawbrush_x0",ring_set_uidrawbrush_X0);
	RING_API_REGISTER("get_uidrawbrush_y0",ring_get_uidrawbrush_Y0);
	RING_API_REGISTER("set_uidrawbrush_y0",ring_set_uidrawbrush_Y0);
	RING_API_REGISTER("get_uidrawbrush_x1",ring_get_uidrawbrush_X1);
	RING_API_REGISTER("set_uidrawbrush_x1",ring_set_uidrawbrush_X1);
	RING_API_REGISTER("get_uidrawbrush_y1",ring_get_uidrawbrush_Y1);
	RING_API_REGISTER("set_uidrawbrush_y1",ring_set_uidrawbrush_Y1);
	RING_API_REGISTER("get_uidrawbrush_outerradius",ring_get_uidrawbrush_OuterRadius);
	RING_API_REGISTER("set_uidrawbrush_outerradius",ring_set_uidrawbrush_OuterRadius);
	RING_API_REGISTER("get_uidrawbrush_numstops",ring_get_uidrawbrush_NumStops);
	RING_API_REGISTER("set_uidrawbrush_numstops",ring_set_uidrawbrush_NumStops);
	RING_API_REGISTER("new_uidrawbrushgradientstop",ring_new_uidrawbrushgradientstop);
	RING_API_REGISTER("new_managed_uidrawbrushgradientstop",ring_new_managed_uidrawbrushgradientstop);
	RING_API_REGISTER("destroy_uidrawbrushgradientstop",ring_destroy_uidrawbrushgradientstop);
	RING_API_REGISTER("get_uidrawbrushgradientstop_pos",ring_get_uidrawbrushgradientstop_Pos);
	RING_API_REGISTER("set_uidrawbrushgradientstop_pos",ring_set_uidrawbrushgradientstop_Pos);
	RING_API_REGISTER("get_uidrawbrushgradientstop_r",ring_get_uidrawbrushgradientstop_R);
	RING_API_REGISTER("set_uidrawbrushgradientstop_r",ring_set_uidrawbrushgradientstop_R);
	RING_API_REGISTER("get_uidrawbrushgradientstop_g",ring_get_uidrawbrushgradientstop_G);
	RING_API_REGISTER("set_uidrawbrushgradientstop_g",ring_set_uidrawbrushgradientstop_G);
	RING_API_REGISTER("get_uidrawbrushgradientstop_b",ring_get_uidrawbrushgradientstop_B);
	RING_API_REGISTER("set_uidrawbrushgradientstop_b",ring_set_uidrawbrushgradientstop_B);
	RING_API_REGISTER("get_uidrawbrushgradientstop_a",ring_get_uidrawbrushgradientstop_A);
	RING_API_REGISTER("set_uidrawbrushgradientstop_a",ring_set_uidrawbrushgradientstop_A);
	RING_API_REGISTER("new_uidrawstrokeparams",ring_new_uidrawstrokeparams);
	RING_API_REGISTER("new_managed_uidrawstrokeparams",ring_new_managed_uidrawstrokeparams);
	RING_API_REGISTER("destroy_uidrawstrokeparams",ring_destroy_uidrawstrokeparams);
	RING_API_REGISTER("get_uidrawstrokeparams_cap",ring_get_uidrawstrokeparams_Cap);
	RING_API_REGISTER("set_uidrawstrokeparams_cap",ring_set_uidrawstrokeparams_Cap);
	RING_API_REGISTER("get_uidrawstrokeparams_join",ring_get_uidrawstrokeparams_Join);
	RING_API_REGISTER("set_uidrawstrokeparams_join",ring_set_uidrawstrokeparams_Join);
	RING_API_REGISTER("get_uidrawstrokeparams_thickness",ring_get_uidrawstrokeparams_Thickness);
	RING_API_REGISTER("set_uidrawstrokeparams_thickness",ring_set_uidrawstrokeparams_Thickness);
	RING_API_REGISTER("get_uidrawstrokeparams_miterlimit",ring_get_uidrawstrokeparams_MiterLimit);
	RING_API_REGISTER("set_uidrawstrokeparams_miterlimit",ring_set_uidrawstrokeparams_MiterLimit);
	RING_API_REGISTER("get_uidrawstrokeparams_numdashes",ring_get_uidrawstrokeparams_NumDashes);
	RING_API_REGISTER("set_uidrawstrokeparams_numdashes",ring_set_uidrawstrokeparams_NumDashes);
	RING_API_REGISTER("get_uidrawstrokeparams_dashphase",ring_get_uidrawstrokeparams_DashPhase);
	RING_API_REGISTER("set_uidrawstrokeparams_dashphase",ring_set_uidrawstrokeparams_DashPhase);
	RING_API_REGISTER("new_uitablemodelhandler",ring_new_uitablemodelhandler);
	RING_API_REGISTER("new_managed_uitablemodelhandler",ring_new_managed_uitablemodelhandler);
	RING_API_REGISTER("destroy_uitablemodelhandler",ring_destroy_uitablemodelhandler);
	RING_API_REGISTER("new_uiareakeyevent",ring_new_uiareakeyevent);
	RING_API_REGISTER("new_managed_uiareakeyevent",ring_new_managed_uiareakeyevent);
	RING_API_REGISTER("destroy_uiareakeyevent",ring_destroy_uiareakeyevent);
	RING_API_REGISTER("get_uiareakeyevent_key",ring_get_uiareakeyevent_Key);
	RING_API_REGISTER("set_uiareakeyevent_key",ring_set_uiareakeyevent_Key);
	RING_API_REGISTER("get_uiareakeyevent_extkey",ring_get_uiareakeyevent_ExtKey);
	RING_API_REGISTER("set_uiareakeyevent_extkey",ring_set_uiareakeyevent_ExtKey);
	RING_API_REGISTER("get_uiareakeyevent_modifier",ring_get_uiareakeyevent_Modifier);
	RING_API_REGISTER("set_uiareakeyevent_modifier",ring_set_uiareakeyevent_Modifier);
	RING_API_REGISTER("get_uiareakeyevent_modifiers",ring_get_uiareakeyevent_Modifiers);
	RING_API_REGISTER("set_uiareakeyevent_modifiers",ring_set_uiareakeyevent_Modifiers);
	RING_API_REGISTER("get_uiareakeyevent_up",ring_get_uiareakeyevent_Up);
	RING_API_REGISTER("set_uiareakeyevent_up",ring_set_uiareakeyevent_Up);
	RING_API_REGISTER("new_uitableparams",ring_new_uitableparams);
	RING_API_REGISTER("new_managed_uitableparams",ring_new_managed_uitableparams);
	RING_API_REGISTER("destroy_uitableparams",ring_destroy_uitableparams);
	RING_API_REGISTER("get_uitableparams_model",ring_get_uitableparams_Model);
	RING_API_REGISTER("set_uitableparams_model",ring_set_uitableparams_Model);
	RING_API_REGISTER("get_uitableparams_rowbackgroundcolormodelcolumn",ring_get_uitableparams_RowBackgroundColorModelColumn);
	RING_API_REGISTER("set_uitableparams_rowbackgroundcolormodelcolumn",ring_set_uitableparams_RowBackgroundColorModelColumn);
	RING_API_REGISTER("new_uiareamouseevent",ring_new_uiareamouseevent);
	RING_API_REGISTER("new_managed_uiareamouseevent",ring_new_managed_uiareamouseevent);
	RING_API_REGISTER("destroy_uiareamouseevent",ring_destroy_uiareamouseevent);
	RING_API_REGISTER("get_uiareamouseevent_x",ring_get_uiareamouseevent_X);
	RING_API_REGISTER("set_uiareamouseevent_x",ring_set_uiareamouseevent_X);
	RING_API_REGISTER("get_uiareamouseevent_y",ring_get_uiareamouseevent_Y);
	RING_API_REGISTER("set_uiareamouseevent_y",ring_set_uiareamouseevent_Y);
	RING_API_REGISTER("get_uiareamouseevent_areawidth",ring_get_uiareamouseevent_AreaWidth);
	RING_API_REGISTER("set_uiareamouseevent_areawidth",ring_set_uiareamouseevent_AreaWidth);
	RING_API_REGISTER("get_uiareamouseevent_areaheight",ring_get_uiareamouseevent_AreaHeight);
	RING_API_REGISTER("set_uiareamouseevent_areaheight",ring_set_uiareamouseevent_AreaHeight);
	RING_API_REGISTER("get_uiareamouseevent_down",ring_get_uiareamouseevent_Down);
	RING_API_REGISTER("set_uiareamouseevent_down",ring_set_uiareamouseevent_Down);
	RING_API_REGISTER("get_uiareamouseevent_up",ring_get_uiareamouseevent_Up);
	RING_API_REGISTER("set_uiareamouseevent_up",ring_set_uiareamouseevent_Up);
	RING_API_REGISTER("get_uiareamouseevent_count",ring_get_uiareamouseevent_Count);
	RING_API_REGISTER("set_uiareamouseevent_count",ring_set_uiareamouseevent_Count);
	RING_API_REGISTER("get_uiareamouseevent_modifiers",ring_get_uiareamouseevent_Modifiers);
	RING_API_REGISTER("set_uiareamouseevent_modifiers",ring_set_uiareamouseevent_Modifiers);
	RING_API_REGISTER("get_uiareamouseevent_held1to64",ring_get_uiareamouseevent_Held1To64);
	RING_API_REGISTER("set_uiareamouseevent_held1to64",ring_set_uiareamouseevent_Held1To64);
	RING_API_REGISTER("new_uidrawtextlayoutparams",ring_new_uidrawtextlayoutparams);
	RING_API_REGISTER("new_managed_uidrawtextlayoutparams",ring_new_managed_uidrawtextlayoutparams);
	RING_API_REGISTER("destroy_uidrawtextlayoutparams",ring_destroy_uidrawtextlayoutparams);
	RING_API_REGISTER("get_uidrawtextlayoutparams_string",ring_get_uidrawtextlayoutparams_String);
	RING_API_REGISTER("set_uidrawtextlayoutparams_string",ring_set_uidrawtextlayoutparams_String);
	RING_API_REGISTER("get_uidrawtextlayoutparams_defaultfont",ring_get_uidrawtextlayoutparams_DefaultFont);
	RING_API_REGISTER("set_uidrawtextlayoutparams_defaultfont",ring_set_uidrawtextlayoutparams_DefaultFont);
	RING_API_REGISTER("get_uidrawtextlayoutparams_width",ring_get_uidrawtextlayoutparams_Width);
	RING_API_REGISTER("set_uidrawtextlayoutparams_width",ring_set_uidrawtextlayoutparams_Width);
	RING_API_REGISTER("get_uidrawtextlayoutparams_align",ring_get_uidrawtextlayoutparams_Align);
	RING_API_REGISTER("set_uidrawtextlayoutparams_align",ring_set_uidrawtextlayoutparams_Align);
	RING_API_REGISTER("new_uifontdescriptor",ring_new_uifontdescriptor);
	RING_API_REGISTER("new_managed_uifontdescriptor",ring_new_managed_uifontdescriptor);
	RING_API_REGISTER("destroy_uifontdescriptor",ring_destroy_uifontdescriptor);
	RING_API_REGISTER("get_uifontdescriptor_family",ring_get_uifontdescriptor_Family);
	RING_API_REGISTER("set_uifontdescriptor_family",ring_set_uifontdescriptor_Family);
	RING_API_REGISTER("get_uifontdescriptor_size",ring_get_uifontdescriptor_Size);
	RING_API_REGISTER("set_uifontdescriptor_size",ring_set_uifontdescriptor_Size);
	RING_API_REGISTER("get_uifontdescriptor_weight",ring_get_uifontdescriptor_Weight);
	RING_API_REGISTER("set_uifontdescriptor_weight",ring_set_uifontdescriptor_Weight);
	RING_API_REGISTER("get_uifontdescriptor_italic",ring_get_uifontdescriptor_Italic);
	RING_API_REGISTER("set_uifontdescriptor_italic",ring_set_uifontdescriptor_Italic);
	RING_API_REGISTER("get_uifontdescriptor_stretch",ring_get_uifontdescriptor_Stretch);
	RING_API_REGISTER("set_uifontdescriptor_stretch",ring_set_uifontdescriptor_Stretch);
}

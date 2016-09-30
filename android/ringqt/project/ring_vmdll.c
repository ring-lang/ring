/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
#include "ring_vmdll.h"
/* Functions */

void ring_vm_dll_loadfunctions ( RingState *pRingState )
{
	ring_vm_funcregister("loadlib",ring_vm_dll_loadlib);
	ring_vm_funcregister("closelib",ring_vm_dll_closelib);
}

void ring_vm_dll_loadlib ( void *pPointer )
{
	LpHandleType handle  ;
	const char *cDLL  ;
	loadlibfuncptr pFunc  ;
	VM *pVM  ;
	RingState *pRingState  ;
	pVM = (VM *) pPointer ;
	pRingState = pVM->pRingState ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISSTRING(1) ) {
		cDLL = RING_API_GETSTRING(1);
		handle = LoadDLL(cDLL);
		if ( handle == NULL ) {
			RING_API_ERROR("Runtime Error in loading the dynamic library!");
			return ;
		}
		pFunc = (loadlibfuncptr) GetDLLFunc(handle, "ringlib_init") ;
		if ( pFunc == NULL ) {
			RING_API_ERROR("The dynamic library doesn't contain the ringlib_init() function!");
			return ;
		}
		ring_list_deletearray(pRingState->pRingCFunctions);
		(*pFunc)(pRingState) ;
		ring_list_genarray(pRingState->pRingCFunctions);
		ring_list_genhashtable2(pRingState->pRingCFunctions);
		RING_API_RETCPOINTER(handle,"DLL");
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_dll_closelib ( void *pPointer )
{
	LpHandleType handle  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		handle = RING_API_GETCPOINTER(1,"DLL") ;
		CloseDLL(handle);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

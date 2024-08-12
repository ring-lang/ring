/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_dll_loadfunctions ( RingState *pRingState )
{
	RING_API_REGISTER("loadlib",ring_vm_dll_loadlib);
	RING_API_REGISTER("closelib",ring_vm_dll_closelib);
}

void ring_vm_dll_loadlib ( void *pPointer )
{
	LpHandleType pHandle  ;
	const char *cDLL  ;
	loadlibfuncptr pFunc  ;
	VM *pVM  ;
	RingState *pRingState  ;
	unsigned int lRegister  ;
	pVM = (VM *) pPointer ;
	pRingState = pVM->pRingState ;
	lRegister = RING_TRUE ;
	if ( (RING_API_PARACOUNT < 1) || (RING_API_PARACOUNT > 2) ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_PARACOUNT == 2 ) {
		if ( RING_API_ISNUMBER(2) ) {
			lRegister = (unsigned int) RING_API_GETNUMBER(2) ;
		}
		else {
			RING_API_ERROR(RING_API_BADPARATYPE);
		}
	}
	if ( RING_API_ISSTRING(1) ) {
		cDLL = RING_API_GETSTRING(1);
		pHandle = LoadDLL(cDLL);
		if ( pHandle == NULL ) {
			printf( "\n%s%s",RING_DLL_LIBFILEMSG,RING_API_GETSTRING(1) ) ;
			RING_API_ERROR(RING_VM_ERROR_LIBLOADERROR);
			return ;
		}
		pFunc = (loadlibfuncptr) GetDLLFunc(pHandle, RING_DLL_INITFUNC) ;
		if ( pFunc == NULL ) {
			printf( "\n%s%s",RING_DLL_LIBFILEMSG,RING_API_GETSTRING(1) ) ;
			RING_API_ERROR(RING_VM_ERROR_NORINGLIBINIT);
			return ;
		}
		(*pFunc)(pRingState) ;
		if ( lRegister ) {
			ring_list_addpointer_gc(pRingState,pVM->pCLibraries,pHandle);
		}
		RING_API_RETCPOINTER(pHandle,RING_VM_POINTER_DLL);
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_dll_closelib ( void *pPointer )
{
	LpHandleType pHandle  ;
	int nIndex  ;
	VM *pVM  ;
	pVM = (VM *) pPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pHandle = RING_API_GETCPOINTER(1,RING_VM_POINTER_DLL) ;
		CloseDLL(pHandle);
		RING_API_SETNULLPOINTER(1);
		/* Remove the pointer */
		nIndex = ring_list_findpointer(pVM->pCLibraries,pHandle);
		if ( nIndex ) {
			ring_list_deleteitem_gc(pVM->pRingState,pVM->pCLibraries,nIndex);
		}
	}
	else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_dll_closealllibs ( VM *pVM )
{
	int x  ;
	LpHandleType pHandle  ;
	for ( x = 1 ; x <= ring_list_getsize(pVM->pCLibraries) ; x++ ) {
		pHandle = ring_list_getpointer(pVM->pCLibraries,x);
		CloseDLL(pHandle);
	}
	ring_list_deleteallitems_gc(pVM->pRingState,pVM->pCLibraries);
}

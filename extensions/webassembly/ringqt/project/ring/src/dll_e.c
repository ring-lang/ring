/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Functions */

void ring_vm_dll_loadfunctions ( RingState *pRingState )
{
    RING_API_REGISTER("loadlib",ring_vm_dll_loadlib);
    RING_API_REGISTER("closelib",ring_vm_dll_closelib);
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
            printf( "\nLibrary File : %s",RING_API_GETSTRING(1) ) ;
            RING_API_ERROR(RING_VM_ERROR_LIBLOADERROR);
            return ;
        }
        pFunc = (loadlibfuncptr) GetDLLFunc(handle, "ringlib_init") ;
        if ( pFunc == NULL ) {
            printf( "\nLibrary File : %s",RING_API_GETSTRING(1) ) ;
            RING_API_ERROR("The dynamic library doesn't contain the ringlib_init() function!");
            return ;
        }
        ring_list_deletearray_gc(pRingState,pRingState->pRingCFunctions);
        (*pFunc)(pRingState) ;
        /* Generate Hash Table */
        ring_list_genarray(pRingState->pRingCFunctions);
        ring_list_genhashtable2(pRingState->pRingCFunctions);
        ring_list_addpointer_gc(pRingState,pVM->pCLibraries,handle);
        RING_API_RETCPOINTER(handle,"DLL");
    }
    else {
        RING_API_ERROR(RING_API_BADPARATYPE);
    }
}

void ring_vm_dll_closelib ( void *pPointer )
{
    LpHandleType handle  ;
    int nIndex  ;
    VM *pVM  ;
    pVM = (VM *) pPointer ;
    if ( RING_API_PARACOUNT != 1 ) {
        RING_API_ERROR(RING_API_MISS1PARA);
        return ;
    }
    if ( RING_API_ISPOINTER(1) ) {
        handle = RING_API_GETCPOINTER(1,"DLL") ;
        CloseDLL(handle);
        RING_API_SETNULLPOINTER(1);
        /* Remove the pointer */
        nIndex = ring_list_findpointer(pVM->pCLibraries,handle);
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
    LpHandleType handle  ;
    for ( x = 1 ; x <= ring_list_getsize(pVM->pCLibraries) ; x++ ) {
        handle = ring_list_getpointer(pVM->pCLibraries,x);
        CloseDLL(handle);
    }
    ring_list_deleteallitems_gc(pVM->pRingState,pVM->pCLibraries);
}

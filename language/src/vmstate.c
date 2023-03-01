/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Save/Restore State - Used by Try/Catch/Done & Loop/Exit */

void ring_vm_savestate ( VM *pVM,List *pList )
{
    List *pThis  ;
    VMState *pVMState  ;
    Item *pItem  ;
    /* Using VMState */
    pVMState = (VMState *) ring_state_malloc(pVM->pRingState,sizeof(VMState));
    /* Save the state as Managed C Pointer */
    ring_list_addringpointer_gc(pVM->pRingState,pList,pVMState);
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    /* Save the data */
    pVMState->aNumbers[0] = ring_list_getsize(pVM->pMem) ;
    pVMState->aNumbers[1] = ring_list_getsize(pVM->pFuncCallList) ;
    pVMState->aNumbers[2] = pVM->nFuncExecute ;
    pVMState->aNumbers[3] = pVM->nSP ;
    pVMState->aNumbers[4] = pVM->nFuncSP ;
    pVMState->aNumbers[5] = ring_list_getsize(pVM->pObjState) ;
    pVMState->aNumbers[6] = ring_list_getsize(pVM->aBraceObjects) ;
    pVMState->aNumbers[7] = ring_list_getsize(pVM->aPCBlockFlag) ;
    pVMState->aNumbers[8] = pVM->nBlockFlag ;
    pVMState->aNumbers[9] = ring_list_getsize(pVM->aScopeNewObj) ;
    pVMState->aNumbers[10] = ring_list_getsize(pVM->aActivePackage) ;
    pVMState->aNumbers[11] = ring_list_getsize(pVM->aScopeID) ;
    pVMState->aNumbers[12] = pVM->nActiveScopeID ;
    pVMState->aNumbers[13] = ring_list_getsize(pVM->pExitMark) ;
    pVMState->aNumbers[14] = ring_list_getsize(pVM->pLoopMark) ;
    pVMState->aNumbers[15] = ring_list_getsize(pVM->pTry) ;
    pVMState->aNumbers[16] = pVM->nListStart ;
    pVMState->aNumbers[17] = pVM->nInsideBraceFlag ;
    pVMState->aNumbers[18] = ring_list_getsize(pVM->aForStep) ;
    pVMState->aNumbers[19] = ring_list_getsize(pVM->aBeforeObjState) ;
    pVMState->aNumbers[20] = RING_VM_IR_GETLINENUMBER ;
    pVMState->aNumbers[21] = pVM->nInClassRegion ;
    pVMState->aNumbers[22] = pVM->nPrivateFlag ;
    pVMState->aNumbers[23] = pVM->nGetSetProperty ;
    pVMState->aNumbers[24] = pVM->nGetSetObjType ;
    pVMState->aNumbers[25] = pVM->nBeforeEqual ;
    pVMState->aNumbers[26] = pVM->nNOAssignment ;
    pVMState->aNumbers[27] = pVM->nFuncExecute2 ;
    pVMState->aNumbers[28] = pVM->nCallClassInit ;
    pVMState->aNumbers[29] = ring_list_getsize(pVM->aAddressScope) ;
    pVMState->aNumbers[30] = ring_list_getint(pThis,RING_VAR_PVALUETYPE) ;
    pVMState->aNumbers[31] = pVM->nCurrentGlobalScope ;
    pVMState->aNumbers[32] = pVM->lNoSetterMethod ;
    pVMState->aPointers[0] = pVM->pBraceObject ;
    pVMState->aPointers[1] = pVM->cFileName ;
    pVMState->aPointers[2] = pVM->pActiveMem ;
    pVMState->aPointers[3] = pVM->pNestedLists ;
    pVMState->aPointers[4] = pVM->aPCBlockFlag ;
    pVMState->aPointers[5] = pVM->pGetSetObject ;
    pVMState->aPointers[6] = pVM->pAssignment ;
    pVMState->aPointers[7] = ring_list_getpointer(pThis,RING_VAR_VALUE) ;
}

void ring_vm_restorestate ( VM *pVM,List *pList,int nPos,int nFlag )
{
    List *pThis,*pFuncList,*pNewObj  ;
    VMState *pVMState, *pVMStateForFunc, *pVMStateForObj  ;
    int x  ;
    List *aListsToDelete, *pListPointer  ;
    pList = ring_list_getlist(pList,nPos);
    /* Using VMState */
    pVMState = (VMState *) ring_list_getpointer(pList,1);
    aListsToDelete = ring_list_new_gc(pVM->pRingState,0);
    /*
    **  Set Scope 
    **  Delete Scopes using the correct function 
    **  We need to delete each scope using ring_vm_deletescope() - so don't use ring_vm_backstate 
    **  We also avoid doing this in the Class Region (After class name) 
    **  Because in the class region we don't use pVM->pMEM 
    */
    pVM->nInClassRegion = pVMState->aNumbers[21] ;
    if ( ! pVM->nInClassRegion ) {
        /*
        **  In the loop condition we use pVMState->aPointers[2] instead of pVM->pActiveMem 
        **  Because ring_vm_deletescope() update the pVM->pActiveMem value 
        */
        while ( ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)) != (List *) pVMState->aPointers[2] ) {
            ring_vm_deletescope(pVM);
        }
    }
    pVM->pActiveMem = (List *) pVMState->aPointers[2] ;
    /* Stack & Executing Functions */
    pVM->nFuncExecute = pVMState->aNumbers[2] ;
    pVM->nSP = pVMState->aNumbers[3] ;
    pVM->nFuncSP = pVMState->aNumbers[4] ;
    /* We also return to the Active Object */
    ring_vm_backstate(pVM,pVMState->aNumbers[5],pVM->pObjState);
    ring_vm_backstate(pVM,pVMState->aNumbers[6] ,pVM->aBraceObjects);
    pVM->pBraceObject = (List *) pVMState->aPointers[0] ;
    /* FileName & Packages */
    pVM->cFileName = (char *) pVMState->aPointers[1] ;
    /* aPCBlockFlag, aScopeNewObj , aActivePackage & aScopeID */
    if ( ((List *) pVMState->aPointers[4]) != pVM->aPCBlockFlag ) {
        pListPointer = pVM->aPCBlockFlag ;
        if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
            ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
        }
        pVM->aPCBlockFlag = (List *) pVMState->aPointers[4] ;
    }
    ring_vm_backstate(pVM,pVMState->aNumbers[7],pVM->aPCBlockFlag);
    pVM->nBlockFlag = pVMState->aNumbers[8] ;
    ring_vm_backstate(pVM,pVMState->aNumbers[10],pVM->aActivePackage);
    ring_vm_backstate(pVM,pVMState->aNumbers[11],pVM->aScopeID);
    pVM->nActiveScopeID = pVMState->aNumbers[12] ;
    /* We also return to the function call list */
    if ( nFlag == RING_STATE_TRYCATCH ) {
        /*
        **  Since Try/Catch can terminate many function when error happens 
        **  We need to clean memory and remove pNestedLists, aPCBlockFlag & aSetProperty 
        **  Clean memory used for function calls 
        */
        for ( x = pVMState->aNumbers[1]+1 ; x <= ring_list_getsize(pVM->pFuncCallList) ; x++ ) {
            pFuncList = ring_list_getlist(pVM->pFuncCallList,x) ;
            /* Delete pNestedLists */
            pListPointer = (List *) ring_list_getpointer(pFuncList,RING_FUNCCL_NESTEDLISTS) ;
            if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
                /* Remove protection from opened lists */
                ring_vm_removelistprotection(pVM,pListPointer);
                ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
            }
            if ( ring_list_getsize(pFuncList) >= RING_FUNCCL_STATE ) {
                pFuncList = ring_list_getlist(pFuncList,RING_FUNCCL_STATE);
                pVMStateForFunc = (VMState *) ring_list_getpointer(pFuncList,1);
                /* Delete aPCBlockFlag */
                pListPointer = (List *) pVMStateForFunc->aPointers[2] ;
                if ( pListPointer != pVM->aPCBlockFlag ) {
                    if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
                        ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
                    }
                }
                /* Delete aSetProperty */
                pListPointer = (List *) pVMStateForFunc->aPointers[6] ;
                if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
                    ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
                }
            }
        }
        /*
        **  Clean memory used for new objects (class region) 
        **  If we have error in the class region while try catch is used outside it 
        **  Then we clean the memory used by the new object 
        **  Like pNestedLists, aPCBlocFlag & aSetProperty 
        */
        for ( x = pVMState->aNumbers[9]+1 ; x <= ring_list_getsize(pVM->aScopeNewObj) ; x++ ) {
            pNewObj = ring_list_getlist(pVM->aScopeNewObj,x) ;
            pVMStateForObj = (VMState *) ring_list_getpointer(pNewObj,1);
            /* Delete pNestedLists */
            pListPointer = (List *) pVMStateForObj->aPointers[1] ;
            if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
                /* Remove protection from opened lists */
                ring_vm_removelistprotection(pVM,pListPointer);
                ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
            }
            /* Delete aPCBlockFlag */
            pListPointer = (List *) pVMStateForObj->aPointers[7] ;
            if ( pListPointer != pVM->aPCBlockFlag ) {
                if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
                    ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
                }
            }
            /* Delete aSetProperty */
            pListPointer = (List *) pVMStateForObj->aPointers[8] ;
            if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
                ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
            }
        }
    }
    ring_vm_backstate(pVM,pVMState->aNumbers[9],pVM->aScopeNewObj);
    ring_vm_backstate(pVM,pVMState->aNumbers[1],pVM->pFuncCallList);
    /* Loop/Exit Mark */
    if ( nFlag != RING_STATE_EXIT ) {
        ring_vm_backstate(pVM,pVMState->aNumbers[13],pVM->pExitMark);
        ring_vm_backstate(pVM,pVMState->aNumbers[14],pVM->pLoopMark);
        /* For Step */
        ring_vm_backstate(pVM,pVMState->aNumbers[18],pVM->aForStep);
    }
    /* Try/Catch/Done */
    if ( nFlag != RING_STATE_TRYCATCH ) {
        ring_vm_backstate(pVM,pVMState->aNumbers[15],pVM->pTry);
    }
    /* List Status */
    pVM->nListStart = pVMState->aNumbers[16] ;
    pListPointer = pVM->pNestedLists ;
    if ( ! ring_list_findpointer(aListsToDelete,pListPointer) ) {
        /* Remove protection from opened lists */
        ring_vm_removelistprotection(pVM,pListPointer);
        ring_list_addpointer_gc(pVM->pRingState,aListsToDelete,pListPointer);
    }
    pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,0);
    pVM->nInsideBraceFlag = pVMState->aNumbers[17] ;
    ring_vm_backstate(pVM,pVMState->aNumbers[19],pVM->aBeforeObjState);
    RING_VM_IR_SETLINENUMBER(pVMState->aNumbers[20]);
    pVM->nPrivateFlag = pVMState->aNumbers[22] ;
    pVM->nGetSetProperty = pVMState->aNumbers[23] ;
    pVM->pGetSetObject = (void *) pVMState->aPointers[5] ;
    pVM->nGetSetObjType = pVMState->aNumbers[24] ;
    pVM->pAssignment = (void *) pVMState->aPointers[6] ;
    pVM->nBeforeEqual = pVMState->aNumbers[25] ;
    pVM->nNOAssignment = pVMState->aNumbers[26] ;
    pVM->nFuncExecute2 = pVMState->aNumbers[27] ;
    pVM->nCallClassInit = pVMState->aNumbers[28] ;
    /* We restore the global scope before the This variable, because This use global scope */
    pVM->nCurrentGlobalScope = pVMState->aNumbers[31] ;
    pVM->lNoSetterMethod = pVMState->aNumbers[32] ;
    /* Restore This variable */
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,pVMState->aPointers[7]);
    ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,pVMState->aNumbers[30]);
    ring_vm_backstate(pVM,pVMState->aNumbers[29],pVM->aAddressScope);
    /* Process aListsToDelete */
    for ( x = 1 ; x <= ring_list_getsize(aListsToDelete) ; x++ ) {
        pListPointer = (List *) ring_list_getpointer(aListsToDelete, x);
        ring_list_delete_gc(pVM->pRingState,pListPointer);
    }
    ring_list_delete_gc(pVM->pRingState,aListsToDelete);
}
/* Save/Restore State 2 - Used by Function Call & Return */

void ring_vm_savestateforfunctions ( VM *pVM,List *pList )
{
    List *pThis  ;
    VMState *pVMState  ;
    Item *pItem  ;
    /* Using VMState */
    pVMState = (VMState *) ring_state_malloc(pVM->pRingState,sizeof(VMState));
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    /* Save the state as Managed C Pointer */
    ring_list_addringpointer_gc(pVM->pRingState,pList,pVMState);
    /* Save the Data */
    pVMState->aNumbers[0] = ring_list_getsize(pVM->pExitMark) ;
    pVMState->aNumbers[1] = ring_list_getsize(pVM->pLoopMark) ;
    pVMState->aNumbers[2] = ring_list_getsize(pVM->pTry) ;
    pVMState->aNumbers[3] = ring_list_getsize(pVM->aBraceObjects) ;
    pVMState->aNumbers[4] = ring_list_getsize(pVM->pObjState) ;
    pVMState->aNumbers[5] = pVM->nInsideBraceFlag ;
    pVMState->aNumbers[6] = ring_list_getsize(pVM->aForStep) ;
    pVMState->aNumbers[7] = pVM->nFuncExecute2 ;
    pVMState->aNumbers[8] = pVM->nBlockFlag ;
    pVMState->aNumbers[9] = pVM->nPrivateFlag ;
    pVMState->aNumbers[10] = pVM->nCallClassInit ;
    pVMState->aNumbers[11] = pVM->nFuncExecute ;
    pVMState->aNumbers[12] = pVM->nInClassRegion ;
    pVMState->aNumbers[13] = pVM->nActiveScopeID ;
    pVMState->aNumbers[14] = ring_list_getsize(pVM->aScopeNewObj) ;
    pVMState->aNumbers[15] = ring_list_getsize(pVM->aScopeID) ;
    pVMState->aNumbers[16] = RING_VM_IR_GETLINENUMBER ;
    pVMState->aNumbers[17] = pVM->nBeforeEqual ;
    pVMState->aNumbers[18] = pVM->nNOAssignment ;
    pVMState->aNumbers[19] = pVM->nGetSetProperty ;
    pVMState->aNumbers[20] = pVM->nGetSetObjType ;
    pVMState->aNumbers[21] = ring_list_getsize(pVM->aAddressScope) ;
    pVMState->aNumbers[22] = ring_list_getint(pThis,RING_VAR_PVALUETYPE) ;
    pVMState->aNumbers[23] = pVM->nCurrentGlobalScope ;
    pVMState->aNumbers[24] = pVM->lNoSetterMethod ;
    pVMState->aPointers[0] = pVM->pBraceObject ;
    pVMState->aPointers[1] = pVM->pActiveMem ;
    pVMState->aPointers[2] = pVM->aPCBlockFlag ;
    pVMState->aPointers[3] = pVM->pAssignment ;
    pVMState->aPointers[4] = pVM->pGetSetObject ;
    pVMState->aPointers[5] = ring_list_getpointer(pThis,RING_VAR_VALUE) ;
    pVMState->aPointers[6] = pVM->aSetProperty ;
    pVM->aSetProperty = ring_list_new_gc(pVM->pRingState,0);
    /* Save State */
    pVM->nInsideBraceFlag = 0 ;
    /* Save BlockFlag */
    pVM->nBlockFlag = 0 ;
    pVM->aPCBlockFlag = ring_list_new_gc(pVM->pRingState,0);
    /* Save nPrivateFlag, set it to 0 (public not private) */
    pVM->nPrivateFlag = 0 ;
    /* Save nCallClassInit */
    pVM->nCallClassInit = 0 ;
    pVM->nInClassRegion = 0 ;
    pVM->pAssignment = NULL ;
    pVM->nNOAssignment = 0 ;
    pVM->pBraceObject = NULL ;
    pVM->nBeforeEqual = 0 ;
    pVM->nFuncExecute = 0 ;
    pVM->nFuncExecute2 = 0 ;
    pVM->nGetSetProperty = 0 ;
    pVM->pGetSetObject = NULL ;
    pVM->nGetSetObjType = 0 ;
    pVM->lNoSetterMethod = 0 ;
}

void ring_vm_restorestateforfunctions ( VM *pVM,List *pList,int x )
{
    List *pThis  ;
    VMState *pVMState  ;
    /* Using VMState */
    pList = ring_list_getlist(pList,x);
    pVMState = (VMState *) ring_list_getpointer(pList,1);
    /* Restore State */
    ring_vm_backstate(pVM,pVMState->aNumbers[0],pVM->pExitMark);
    ring_vm_backstate(pVM,pVMState->aNumbers[1],pVM->pLoopMark);
    ring_vm_backstate(pVM,pVMState->aNumbers[2],pVM->pTry);
    ring_vm_backstate(pVM,pVMState->aNumbers[3],pVM->aBraceObjects);
    pVM->pBraceObject = (List *) pVMState->aPointers[0] ;
    ring_vm_backstate(pVM,pVMState->aNumbers[4],pVM->pObjState);
    pVM->nInsideBraceFlag = pVMState->aNumbers[5] ;
    ring_vm_backstate(pVM,pVMState->aNumbers[6],pVM->aForStep);
    pVM->pActiveMem = (List *) pVMState->aPointers[1] ;
    pVM->nFuncExecute2 = pVMState->aNumbers[7] ;
    /* Restore BlockFLag */
    pVM->aPCBlockFlag = ring_list_delete_gc(pVM->pRingState,pVM->aPCBlockFlag);
    pVM->nBlockFlag = pVMState->aNumbers[8] ;
    pVM->aPCBlockFlag = (List *) pVMState->aPointers[2] ;
    /* Restore nPrivateFlag */
    pVM->nPrivateFlag = pVMState->aNumbers[9] ;
    /* Restore nCallClassInit */
    pVM->nCallClassInit = pVMState->aNumbers[10] ;
    pVM->nFuncExecute = pVMState->aNumbers[11] ;
    pVM->pAssignment = (void *) pVMState->aPointers[3] ;
    pVM->nInClassRegion = pVMState->aNumbers[12] ;
    pVM->nActiveScopeID = pVMState->aNumbers[13] ;
    ring_vm_backstate(pVM,pVMState->aNumbers[14],pVM->aScopeNewObj);
    ring_vm_backstate(pVM,pVMState->aNumbers[15],pVM->aScopeID);
    RING_VM_IR_SETLINENUMBER(pVMState->aNumbers[16]);
    pVM->nBeforeEqual = pVMState->aNumbers[17] ;
    pVM->nNOAssignment = pVMState->aNumbers[18] ;
    pVM->nGetSetProperty = pVMState->aNumbers[19] ;
    pVM->nGetSetObjType = pVMState->aNumbers[20] ;
    pVM->pGetSetObject = (void *) pVMState->aPointers[4] ;
    /* Restore global scope, Must be before this because this depend on it */
    pVM->nCurrentGlobalScope = pVMState->aNumbers[23] ;
    pVM->lNoSetterMethod = pVMState->aNumbers[24] ;
    /* Restore This variable */
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,pVMState->aPointers[5]);
    ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,pVMState->aNumbers[22]);
    ring_vm_backstate(pVM,pVMState->aNumbers[21],pVM->aAddressScope);
    /* Restore aSetProperty */
    pVM->aSetProperty = ring_list_delete_gc(pVM->pRingState,pVM->aSetProperty);
    pVM->aSetProperty = (List *)  pVMState->aPointers[6] ;
}
/* Save/Restore State 3 - Used by (ICO_NEWOBJ) and (ICO_SETSCOPE) */

void ring_vm_savestatefornewobjects ( VM *pVM )
{
    List *pList, *pThis  ;
    VMState *pVMState  ;
    Item *pItem  ;
    /* Using VMState */
    pVMState = (VMState *) ring_state_malloc(pVM->pRingState,sizeof(VMState));
    /* Save the state as Managed C Pointer */
    ring_list_addringpointer_gc(pVM->pRingState,pVM->aScopeNewObj,pVMState);
    /*
    **  Save the Data 
    **  Save the Active Memory 
    */
    pVMState->aPointers[0] = pVM->pActiveMem ;
    /* Store List information to allow calling function from list item and creating lists from that funct */
    pVMState->aNumbers[0] = pVM->nListStart ;
    pVMState->aPointers[1] = pVM->pNestedLists ;
    pVM->nListStart = 0 ;
    pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,0);
    /* Save Stack Information */
    pVMState->aNumbers[1] = pVM->nSP ;
    /* Save FuncExecute */
    pVMState->aNumbers[2] = pVM->nFuncExecute ;
    pVM->nFuncExecute = 0 ;
    /* Save Private Flag Status */
    pVMState->aNumbers[3] = pVM->nPrivateFlag ;
    /* Save InsideBrace Flag */
    pVMState->aNumbers[4] = pVM->nInsideBraceFlag ;
    pVM->nInsideBraceFlag = 0 ;
    pVMState->aPointers[2] = pVM->pBraceObject ;
    pVM->pBraceObject = NULL ;
    /* Save nCallClassInit */
    pVMState->aNumbers[5] = pVM->nCallClassInit ;
    pVM->nCallClassInit = 0 ;
    /* Save Line Number */
    pVMState->aNumbers[6] = RING_VM_IR_GETLINENUMBER ;
    /* Save Function Stack */
    pVMState->aNumbers[7] = pVM->nFuncSP ;
    /* Save Assignment Pointer */
    pVMState->aPointers[3] = pVM->pAssignment ;
    pVM->pAssignment = NULL ;
    /* Save the Object Pointer and Type */
    pVMState->aPointers[4] = RING_VM_STACK_READP ;
    pVMState->aNumbers[8] = RING_VM_STACK_OBJTYPE ;
    /* Save Current Global Scope */
    pVMState->aNumbers[9] = pVM->nCurrentGlobalScope ;
    /* Save the This object */
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    pVMState->aPointers[5] = ring_list_getpointer(pThis,RING_VAR_VALUE) ;
    pVMState->aNumbers[10] = ring_list_getint(pThis,RING_VAR_PVALUETYPE) ;
    /* Save FuncExecute2 */
    pVMState->aNumbers[11] = pVM->nFuncExecute2 ;
    pVM->nFuncExecute2 = 0 ;
    /* Save nNoAssignment */
    pVMState->aNumbers[12] = pVM->nNOAssignment ;
    pVM->nNOAssignment = 0 ;
    /* Save ExitMark */
    pVMState->aNumbers[13] = ring_list_getsize(pVM->pExitMark) ;
    /* Save LoopMark */
    pVMState->aNumbers[14] = ring_list_getsize(pVM->pLoopMark) ;
    /* Save pTry */
    pVMState->aNumbers[15] = ring_list_getsize(pVM->pTry) ;
    /* Save aBraceObjects */
    pVMState->aNumbers[16] = ring_list_getsize(pVM->aBraceObjects) ;
    /* Save aForStep */
    pVMState->aNumbers[17] = ring_list_getsize(pVM->aForStep) ;
    /* Save nActiveScopeID */
    pVMState->aNumbers[18] = pVM->nActiveScopeID ;
    /* Save nBeforeEqual */
    pVMState->aNumbers[19] = pVM->nBeforeEqual ;
    pVM->nBeforeEqual = 0 ;
    /* Save nGetSetProperty */
    pVMState->aNumbers[20] = pVM->nGetSetProperty ;
    pVM->nGetSetProperty = 0 ;
    /* Save nGetSetObject */
    pVMState->aNumbers[21] = pVM->nGetSetObjType ;
    pVM->nGetSetObjType = 0 ;
    /* Save pGetSetObject */
    pVMState->aPointers[6] = pVM->pGetSetObject ;
    pVM->pGetSetObject = NULL ;
    /* Save aScopeID */
    pVMState->aNumbers[22] = ring_list_getsize(pVM->aScopeID) ;
    /* Save lNoSetterMethod */
    pVMState->aNumbers[23] = pVM->lNoSetterMethod ;
    pVM->lNoSetterMethod = 0 ;
    /* Save the BlockFlag */
    pVMState->aNumbers[24] = pVM->nBlockFlag ;
    pVMState->aPointers[7] = pVM->aPCBlockFlag ;
    pVM->nBlockFlag = 0 ;
    pVM->aPCBlockFlag = ring_list_new_gc(pVM->pRingState,0);
    /* Save aAddressScope */
    pVMState->aNumbers[25] = ring_list_getsize(pVM->aAddressScope) ;
    /* Save nInClassRegion */
    pVMState->aNumbers[26] = pVM->nInClassRegion ;
    pVM->nInClassRegion = 0 ;
    /* Save aBeforeObjState */
    pVMState->aNumbers[27] = ring_list_getsize(pVM->aBeforeObjState) ;
    /* Save pFuncClassList */
    pVMState->aNumbers[28] = ring_list_getsize(pVM->pFuncCallList) ;
    /* Save aSetProperty */
    pVMState->aPointers[8] = pVM->aSetProperty ;
    pVM->aSetProperty = ring_list_new_gc(pVM->pRingState,0);
    /* Save pObjState */
    pVMState->aNumbers[29] = ring_list_getsize(pVM->pObjState) ;
}

void ring_vm_restorestatefornewobjects ( VM *pVM )
{
    List *pList, *pThis  ;
    VMState *pVMState  ;
    pList = ring_list_getlist(pVM->aScopeNewObj,ring_list_getsize(pVM->aScopeNewObj)) ;
    /* Using VMState */
    pVMState = (VMState *) ring_list_getpointer(pList,1);
    /*
    **  Restore State 
    **  Restore the scope (before creating the object using new) 
    */
    pVM->pActiveMem = (List *) pVMState->aPointers[0] ;
    /*
    **  Restore List Status 
    **  Remove protection from opened lists 
    */
    ring_vm_removelistprotection(pVM,pVM->pNestedLists);
    pVM->nListStart = pVMState->aNumbers[0] ;
    pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState,pVM->pNestedLists);
    pVM->pNestedLists = (List *) pVMState->aPointers[1] ;
    /* Remove protection from opened lists */
    ring_vm_removelistprotection(pVM,pVM->pNestedLists);
    /* Restore Stack Information */
    pVM->nSP = pVMState->aNumbers[1] ;
    /* Restore FuncExecute */
    pVM->nFuncExecute = pVMState->aNumbers[2] ;
    /* Restore Private Flag */
    pVM->nPrivateFlag = pVMState->aNumbers[3] ;
    /* Restore InsideBrace Flag */
    pVM->nInsideBraceFlag = pVMState->aNumbers[4] ;
    pVM->pBraceObject = (List *) pVMState->aPointers[2] ;
    /* Restore nCallClassInit */
    pVM->nCallClassInit = pVMState->aNumbers[5] ;
    /* Restore nLineNumber */
    RING_VM_IR_SETLINENUMBER(pVMState->aNumbers[6]);
    /* Restore Function Stack */
    pVM->nFuncSP = pVMState->aNumbers[7] ;
    /* Restore Assignment Pointer */
    pVM->pAssignment = (List *) pVMState->aPointers[3] ;
    /* Restore the Object Pointer and The Object Type */
    RING_VM_STACK_SETPVALUE(pVMState->aPointers[4]);
    RING_VM_STACK_OBJTYPE = pVMState->aNumbers[8] ;
    /* Restore current Global Scope */
    pVM->nCurrentGlobalScope = pVMState->aNumbers[9] ;
    /* Restore the This object */
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,pVMState->aPointers[5]);
    ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,pVMState->aNumbers[10]);
    /* Restore FuncExecute2 */
    pVM->nFuncExecute2 = pVMState->aNumbers[11] ;
    /* Restore nNoAssignment */
    pVM->nNOAssignment = pVMState->aNumbers[12] ;
    /* Restore ExitMark */
    ring_vm_backstate(pVM,pVMState->aNumbers[13],pVM->pExitMark);
    /* Restore LoopMark */
    ring_vm_backstate(pVM,pVMState->aNumbers[14],pVM->pLoopMark);
    /* Restore pTry */
    ring_vm_backstate(pVM,pVMState->aNumbers[15],pVM->pTry);
    /* Restore aBraceObjects */
    ring_vm_backstate(pVM,pVMState->aNumbers[16],pVM->aBraceObjects);
    /* Restore aForStep */
    ring_vm_backstate(pVM,pVMState->aNumbers[17],pVM->aForStep);
    /* Restore nActiveScopeID */
    pVM->nActiveScopeID = pVMState->aNumbers[18] ;
    /* Restore nBeforeEqual */
    pVM->nBeforeEqual = pVMState->aNumbers[19] ;
    /* Restore nGetSetProperty */
    pVM->nGetSetProperty = pVMState->aNumbers[20] ;
    /* Restore nGetSetObjType */
    pVM->nGetSetObjType = pVMState->aNumbers[21] ;
    /* Restore pGetSetObject */
    pVM->pGetSetObject = (List *) pVMState->aPointers[6] ;
    /* Restore aScopeID */
    ring_vm_backstate(pVM,pVMState->aNumbers[22],pVM->aScopeID);
    /* Restore lNoSetterMethod */
    pVM->lNoSetterMethod = pVMState->aNumbers[23] ;
    /* Restore the BlockFlag */
    pVM->nBlockFlag = pVMState->aNumbers[24] ;
    pVM->aPCBlockFlag = ring_list_delete_gc(pVM->pRingState,pVM->aPCBlockFlag);
    pVM->aPCBlockFlag = (List *)  pVMState->aPointers[7] ;
    /* Restore aAddressScope */
    ring_vm_backstate(pVM,pVMState->aNumbers[25],pVM->aAddressScope);
    /* Restore nInClassRegion */
    pVM->nInClassRegion = pVMState->aNumbers[26] ;
    /* Restore aBeforeObjState */
    ring_vm_backstate(pVM,pVMState->aNumbers[27],pVM->aBeforeObjState);
    /* Restore pFuncCallList */
    ring_vm_backstate(pVM,pVMState->aNumbers[28],pVM->pFuncCallList);
    /* Restore aSetProperty */
    pVM->aSetProperty = ring_list_delete_gc(pVM->pRingState,pVM->aSetProperty);
    pVM->aSetProperty = (List *)  pVMState->aPointers[8] ;
    /* Restore pObjState */
    ring_vm_backstate(pVM,pVMState->aNumbers[29],pVM->pObjState);
    ring_list_deleteitem_gc(pVM->pRingState,pVM->aScopeNewObj,ring_list_getsize(pVM->aScopeNewObj));
}

int ring_vm_newobjectstackpointer ( VM *pVM )
{
    List *pList  ;
    VMState *pVMState  ;
    pList = ring_list_getlist(pVM->aScopeNewObj,ring_list_getsize(pVM->aScopeNewObj));
    pVMState = (VMState *) ring_list_getpointer(pList,1);
    return pVMState->aNumbers[RING_ASCOPENEWOBJ_SP] ;
}
/* Save/Restore State 4 - Used by BraceStart & BraceEnd */

void ring_vm_savestateforbraces ( VM *pVM,List *pObjState )
{
    List *pList, *pClass,*aSetProperty  ;
    /*
    **  Prepare to Access Object State 
    **  Store Pointer to Object State 
    */
    ring_list_addpointer_gc(pVM->pRingState,pObjState,ring_list_getlist(pVM->pBraceObject,2));
    /* Store Object Class Methods */
    pClass = (List *) ring_list_getpointer(pVM->pBraceObject,1) ;
    ring_list_addpointer_gc(pVM->pRingState,pObjState,ring_list_getlist(pClass,4));
    /* Store Class Pointer */
    ring_list_addpointer_gc(pVM->pRingState,pObjState,pClass);
    /* Add Brace Object & Stack Pointer to List */
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->aBraceObjects);
    ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pBraceObject);
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nSP);
    /* Store List information to allow using braces from list item and creating lists from that brace */
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nListStart);
    ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pNestedLists);
    pVM->nListStart = 0 ;
    pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,0);
    /* Enable function for memory management */
    ring_vm_gc_listpointerismine(pList,RING_ABRACEOBJECTS_PNESTEDLISTS);
    /* Store nFuncExec */
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nFuncExecute);
    pVM->nFuncExecute = 0 ;
    /* Store GetSet Object */
    aSetProperty = ring_list_newlist_gc(pVM->pRingState,pList);
    ring_list_copy_gc(pVM->pRingState,aSetProperty,pVM->aSetProperty);
    ring_list_deleteallitems_gc(pVM->pRingState,pVM->aSetProperty);
    /* Store nLoadAddressScope */
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nLoadAddressScope);
    pVM->pBraceObject = NULL ;
    pVM->nInsideBraceFlag = 1 ;
}

void ring_vm_restorestateforbraces ( VM *pVM,List *pList )
{
    /*
    **  Restore List Status 
    **  Remove protection from opened lists 
    */
    ring_vm_removelistprotection(pVM,pVM->pNestedLists);
    pVM->nListStart = ring_list_getint(pList,RING_ABRACEOBJECTS_NLISTSTART) ;
    pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState,pVM->pNestedLists);
    pVM->pNestedLists = (List *) ring_list_getpointer(pList,RING_ABRACEOBJECTS_PNESTEDLISTS) ;
    /* Remove protection from opened lists */
    ring_vm_removelistprotection(pVM,pVM->pNestedLists);
    /* Disable function for memory management */
    ring_vm_gc_listpointerisnotmine(pList,RING_ABRACEOBJECTS_PNESTEDLISTS);
    /* Restore nFuncExec */
    pVM->nFuncExecute = ring_list_getint(pList,RING_ABRACEOBJECTS_NFUNCEXEC ) ;
    /* Restore Stack Status */
    pVM->nSP = ring_list_getint(pList,RING_ABRACEOBJECTS_NSP) ;
    /* Restore GetSet Object */
    ring_list_deleteallitems_gc(pVM->pRingState,pVM->aSetProperty);
    ring_list_copy_gc(pVM->pRingState,pVM->aSetProperty,(List *) ring_list_getpointer(pList,RING_ABRACEOBJECTS_ASETPROPERTY ));
    /* Restore nLoadAddressScope */
    pVM->nLoadAddressScope = ring_list_getint(pList,RING_ABRACEOBJECTS_NLOADASCOPE) ;
    ring_list_deleteitem_gc(pVM->pRingState,pVM->aBraceObjects,ring_list_getsize(pVM->aBraceObjects));
    ring_list_deleteitem_gc(pVM->pRingState,pVM->pObjState,ring_list_getsize(pVM->pObjState));
    pVM->nInsideBraceFlag = ( ring_list_getsize(pVM->aBraceObjects) > 0 ) ;
}
/* Return to a Specific position in the array, delete all items after that position */

void ring_vm_backstate ( VM *pVM,int x,List *pList )
{
    int nLimit,y  ;
    if ( x < ring_list_getsize(pList) ) {
        nLimit = ring_list_getsize(pList) ;
        for ( y = x + 1 ; y <= nLimit ; y++ ) {
            ring_list_deleteitem_gc(pVM->pRingState,pList,ring_list_getsize(pList));
        }
    }
}
/* Save/Restore Stack */

List * ring_vm_savestack ( VM *pVM )
{
    int nSP  ;
    List *pList, *pList2  ;
    nSP = pVM->nSP ;
    /* Create List */
    pList = ring_list_new_gc(pVM->pRingState,0);
    while ( pVM->nSP  != 0 ) {
        if ( RING_VM_STACK_ISSTRING ) {
            ring_list_addstring2_gc(pVM->pRingState,pList,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
        }
        else if ( RING_VM_STACK_ISNUMBER ) {
            ring_list_adddouble_gc(pVM->pRingState,pList,RING_VM_STACK_READN);
        }
        else if ( RING_VM_STACK_ISPOINTER ) {
            pList2 = ring_list_newlist_gc(pVM->pRingState,pList);
            ring_list_addpointer_gc(pVM->pRingState,pList2,RING_VM_STACK_READP);
            ring_list_addint_gc(pVM->pRingState,pList2,RING_VM_STACK_OBJTYPE);
        }
        RING_VM_STACK_POP ;
    }
    pVM->nSP = nSP ;
    return pList ;
}

void ring_vm_restorestack ( VM *pVM,List *pList )
{
    int x  ;
    List *pList2  ;
    if ( ring_list_getsize(pList) == 0 ) {
        return ;
    }
    pVM->nSP = 0 ;
    for ( x = ring_list_getsize(pList) ; x >= 1 ; x-- ) {
        if ( ring_list_isstring(pList,x) ) {
            RING_VM_STACK_PUSHCVALUE2(ring_list_getstring(pList,x),ring_list_getstringsize(pList,x));
        }
        else if ( ring_list_isnumber(pList,x) ) {
            RING_VM_STACK_PUSHNVALUE(ring_list_getdouble(pList,x));
        }
        else if ( ring_list_islist(pList,x) ) {
            pList2 = ring_list_getlist(pList,x);
            RING_VM_STACK_PUSHPVALUE(ring_list_getpointer(pList2,1));
            RING_VM_STACK_OBJTYPE = ring_list_getint(pList2,2) ;
        }
    }
}

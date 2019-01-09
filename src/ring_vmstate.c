/* Copyright (c) 2013-2019 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Save/Restore State - Used by Try/Catch/Done & Loop/Exit */

void ring_vm_savestate ( VM *pVM,List *pList )
{
	List *pThis  ;
	pList = ring_list_newlist_gc(pVM->pRingState,pList);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pMem));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pFuncCallList));
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nFuncExecute);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nSP);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nFuncSP);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pObjState));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aBraceObjects));
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pBraceObject);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->cFileName);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aPCBlockFlag));
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nBlockFlag);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aScopeNewObj));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aActivePackage));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aScopeID));
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nActiveScopeID);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pExitMark));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pLoopMark));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pTry));
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pActiveMem);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nListStart);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pNestedLists);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nInsideBraceFlag);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aForStep));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aBeforeObjState));
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->aPCBlockFlag);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nLineNumber);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nInClassRegion);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nPrivateFlag);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nGetSetProperty);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pGetSetObject);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nGetSetObjType);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pAssignment);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nBeforeEqual);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nNOAssignment);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nFuncExecute2);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nCallClassInit);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->aLoadAddressScope);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pLoadAddressScope));
	/* Save This variable */
	pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
	ring_list_addpointer_gc(pVM->pRingState,pList,ring_list_getpointer(pThis,RING_VAR_VALUE));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getint(pThis,RING_VAR_PVALUETYPE));
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nCurrentGlobalScope);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->lNoSetterMethod);
}

void ring_vm_restorestate ( VM *pVM,List *pList,int nPos,int nFlag )
{
	List *pThis  ;
	pList = ring_list_getlist(pList,nPos);
	/* Set Scope */
	pVM->pActiveMem = (List *) ring_list_getpointer(pList,19) ;
	/*
	**  Delete Scopes using the correct function 
	**  We need to delete each scope using ring_vm_deletescope() - so don't use ring_vm_backstate 
	**  We also avoid doing this in the Class Region (After class name) 
	**  Because in the class region we don't use pVM->pMEM 
	*/
	if ( ! pVM->nInClassRegion ) {
		while ( ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)) != pVM->pActiveMem ) {
			ring_vm_deletescope(pVM);
		}
	}
	/* We also return to the function call list */
	ring_vm_backstate(pVM,ring_list_getint(pList,2),pVM->pFuncCallList);
	/* Stack & Executing Functions */
	pVM->nFuncExecute = ring_list_getint(pList,3) ;
	pVM->nSP = ring_list_getint(pList,4) ;
	pVM->nFuncSP = ring_list_getint(pList,5) ;
	/* We also return to the Active Object */
	ring_vm_backstate(pVM,ring_list_getint(pList,6),pVM->pObjState);
	ring_vm_backstate(pVM,ring_list_getint(pList,7),pVM->aBraceObjects);
	pVM->pBraceObject = (List *) ring_list_getpointer(pList,8) ;
	/* FileName & Packages */
	pVM->cFileName = (char *) ring_list_getpointer(pList,9) ;
	/* aPCBlockFlag, aScopeNewObj , aActivePackage & aScopeID */
	if ( ((List *) ring_list_getpointer(pList,25)) != pVM->aPCBlockFlag ) {
		pVM->aPCBlockFlag = ring_list_delete_gc(pVM->pRingState,pVM->aPCBlockFlag);
		pVM->aPCBlockFlag = (List *) ring_list_getpointer(pList,25) ;
	}
	ring_vm_backstate(pVM,ring_list_getint(pList,10),pVM->aPCBlockFlag);
	pVM->nBlockFlag = ring_list_getint(pList,11) ;
	ring_vm_backstate(pVM,ring_list_getint(pList,12),pVM->aScopeNewObj);
	ring_vm_backstate(pVM,ring_list_getint(pList,13),pVM->aActivePackage);
	ring_vm_backstate(pVM,ring_list_getint(pList,14),pVM->aScopeID);
	pVM->nActiveScopeID = ring_list_getint(pList,15) ;
	/* Loop/Exit Mark */
	if ( nFlag != RING_STATE_EXIT ) {
		ring_vm_backstate(pVM,ring_list_getint(pList,16),pVM->pExitMark);
		ring_vm_backstate(pVM,ring_list_getint(pList,17),pVM->pLoopMark);
		/* For Step */
		ring_vm_backstate(pVM,ring_list_getint(pList,23),pVM->aForStep);
	}
	/* Try/Catch/Done */
	if ( nFlag != RING_STATE_TRYCATCH ) {
		ring_vm_backstate(pVM,ring_list_getint(pList,18),pVM->pTry);
	}
	/* List Status */
	pVM->nListStart = ring_list_getint(pList,20) ;
	if ( ring_list_getpointer(pList,21) != pVM->pNestedLists ) {
		pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState,pVM->pNestedLists);
		pVM->pNestedLists = (List *) ring_list_getpointer(pList,21) ;
	}
	pVM->nInsideBraceFlag = ring_list_getint(pList,22) ;
	ring_vm_backstate(pVM,ring_list_getint(pList,24),pVM->aBeforeObjState);
	pVM->nLineNumber = ring_list_getint(pList,26) ;
	pVM->nInClassRegion = ring_list_getint(pList,27) ;
	pVM->nPrivateFlag = ring_list_getint(pList,28) ;
	pVM->nGetSetProperty = ring_list_getint(pList,29) ;
	pVM->pGetSetObject = (void *) ring_list_getpointer(pList,30) ;
	pVM->nGetSetObjType = ring_list_getint(pList,31) ;
	pVM->pAssignment = (void *) ring_list_getpointer(pList,32) ;
	pVM->nBeforeEqual = ring_list_getint(pList,33) ;
	pVM->nNOAssignment = ring_list_getint(pList,34) ;
	pVM->nFuncExecute2 = ring_list_getint(pList,35) ;
	pVM->nCallClassInit = ring_list_getint(pList,36) ;
	pVM->aLoadAddressScope = (List *) ring_list_getpointer(pList,37) ;
	ring_vm_backstate(pVM,ring_list_getint(pList,38),pVM->pLoadAddressScope);
	/* We restore the global scope befor the This variable, because This use global scope */
	pVM->nCurrentGlobalScope = ring_list_getint(pList,41) ;
	pVM->lNoSetterMethod = ring_list_getint(pList,42) ;
	/* Restore This variable */
	pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
	ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,ring_list_getpointer(pList,39));
	ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,ring_list_getint(pList,40));
}
/* Save/Restore State 2 - Used by Function Call & Return */

void ring_vm_savestate2 ( VM *pVM,List *pList )
{
	List *pThis  ;
	/* Save State */
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pExitMark));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pLoopMark));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pTry));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aBraceObjects));
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pBraceObject);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pObjState));
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nInsideBraceFlag);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aForStep));
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pActiveMem);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nFuncExecute2);
	pVM->nInsideBraceFlag = 0 ;
	/* Save BlockFlag */
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nBlockFlag);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->aPCBlockFlag);
	pVM->nBlockFlag = 0 ;
	pVM->aPCBlockFlag = ring_list_new_gc(pVM->pRingState,0);
	/* Save nPrivateFlag, set it to 0 (public not private) */
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nPrivateFlag);
	pVM->nPrivateFlag = 0 ;
	/* Save nCallClassInit */
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nCallClassInit);
	pVM->nCallClassInit = 0 ;
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nFuncExecute);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pAssignment);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nInClassRegion);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nActiveScopeID);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aScopeNewObj));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->aScopeID));
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nLineNumber);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nBeforeEqual);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nNOAssignment);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nGetSetProperty);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nGetSetObjType);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pGetSetObject);
	ring_list_addpointer_gc(pVM->pRingState,pList,pVM->aLoadAddressScope);
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getsize(pVM->pLoadAddressScope));
	/* Save This variable */
	pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
	ring_list_addpointer_gc(pVM->pRingState,pList,ring_list_getpointer(pThis,RING_VAR_VALUE));
	ring_list_addint_gc(pVM->pRingState,pList,ring_list_getint(pThis,RING_VAR_PVALUETYPE));
	ring_list_addint_gc(pVM->pRingState,pList,pVM->nCurrentGlobalScope);
	ring_list_addint_gc(pVM->pRingState,pList,pVM->lNoSetterMethod);
	pVM->nInClassRegion = 0 ;
	pVM->pAssignment = NULL ;
	pVM->nNOAssignment = 0 ;
}

void ring_vm_restorestate2 ( VM *pVM,List *pList,int x )
{
	List *pThis  ;
	/* Restore State */
	ring_vm_backstate(pVM,ring_list_getint(pList,x),pVM->pExitMark);
	ring_vm_backstate(pVM,ring_list_getint(pList,x+1),pVM->pLoopMark);
	ring_vm_backstate(pVM,ring_list_getint(pList,x+2),pVM->pTry);
	ring_vm_backstate(pVM,ring_list_getint(pList,x+3),pVM->aBraceObjects);
	pVM->pBraceObject = (List *) ring_list_getpointer(pList,x+4) ;
	ring_vm_backstate(pVM,ring_list_getint(pList,x+5),pVM->pObjState);
	pVM->nInsideBraceFlag = ring_list_getint(pList,x+6) ;
	ring_vm_backstate(pVM,ring_list_getint(pList,x+7),pVM->aForStep);
	pVM->pActiveMem = (List *) ring_list_getpointer(pList,x+8) ;
	pVM->nFuncExecute2 = ring_list_getint(pList,x+9) ;
	/* Restore BlockFLag */
	pVM->aPCBlockFlag = ring_list_delete_gc(pVM->pRingState,pVM->aPCBlockFlag);
	pVM->nBlockFlag = ring_list_getint(pList,x+10) ;
	pVM->aPCBlockFlag = (List *) ring_list_getpointer(pList,x+11) ;
	/* Restore nPrivateFlag */
	pVM->nPrivateFlag = ring_list_getint(pList,x+12) ;
	/* Restore nCallClassInit */
	pVM->nCallClassInit = ring_list_getint(pList,x+13) ;
	pVM->nFuncExecute = ring_list_getint(pList,x+14) ;
	pVM->pAssignment = (void *) ring_list_getpointer(pList,x+15) ;
	pVM->nInClassRegion = ring_list_getint(pList,x+16) ;
	pVM->nActiveScopeID = ring_list_getint(pList,x+17) ;
	ring_vm_backstate(pVM,ring_list_getint(pList,x+18),pVM->aScopeNewObj);
	ring_vm_backstate(pVM,ring_list_getint(pList,x+19),pVM->aScopeID);
	pVM->nLineNumber = ring_list_getint(pList,x+20) ;
	pVM->nBeforeEqual = ring_list_getint(pList,x+21) ;
	pVM->nNOAssignment = ring_list_getint(pList,x+22) ;
	pVM->nGetSetProperty = ring_list_getint(pList,x+23) ;
	pVM->nGetSetObjType = ring_list_getint(pList,x+24) ;
	pVM->pGetSetObject = (void *) ring_list_getpointer(pList,x+25) ;
	pVM->aLoadAddressScope = (List *) ring_list_getpointer(pList,x+26) ;
	ring_vm_backstate(pVM,ring_list_getint(pList,x+27),pVM->pLoadAddressScope);
	/* Restore global scope, Must be before this because this depend on it */
	pVM->nCurrentGlobalScope = ring_list_getint(pList,x+30) ;
	pVM->lNoSetterMethod = ring_list_getint(pList,x+31) ;
	/* Restore This variable */
	pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
	ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,ring_list_getpointer(pList,x+28));
	ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,ring_list_getint(pList,x+29));
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
			ring_list_addstring_gc(pVM->pRingState,pList,RING_VM_STACK_READC);
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
	pVM->nSP = 0 ;
	if ( ring_list_getsize(pList) == 0 ) {
		return ;
	}
	for ( x = ring_list_getsize(pList) ; x >= 1 ; x-- ) {
		if ( ring_list_isstring(pList,x) ) {
			RING_VM_STACK_PUSHCVALUE(ring_list_getstring(pList,x));
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

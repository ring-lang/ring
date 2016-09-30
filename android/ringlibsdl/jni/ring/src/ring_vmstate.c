/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Save/Restore State - Used by Try/Catch/Done & Loop/Exit */

void ring_vm_savestate ( VM *pVM,List *pList )
{
	pList = ring_list_newlist(pList);
	ring_list_addint(pList,ring_list_getsize(pVM->pMem));
	ring_list_addint(pList,ring_list_getsize(pVM->pFuncCallList));
	ring_list_addint(pList,pVM->nFuncExecute);
	ring_list_addint(pList,pVM->nSP);
	ring_list_addint(pList,pVM->nFuncSP);
	ring_list_addint(pList,ring_list_getsize(pVM->pObjState));
	ring_list_addint(pList,ring_list_getsize(pVM->aBraceObjects));
	ring_list_addpointer(pList,pVM->pBraceObject);
	ring_list_addpointer(pList,pVM->cFileName);
	ring_list_addint(pList,ring_list_getsize(pVM->aPCBlockFlag));
	ring_list_addint(pList,pVM->nBlockFlag);
	ring_list_addint(pList,ring_list_getsize(pVM->aScopeNewObj));
	ring_list_addint(pList,ring_list_getsize(pVM->aActivePackage));
	ring_list_addint(pList,ring_list_getsize(pVM->aScopeID));
	ring_list_addint(pList,pVM->nActiveScopeID);
	ring_list_addint(pList,ring_list_getsize(pVM->pExitMark));
	ring_list_addint(pList,ring_list_getsize(pVM->pLoopMark));
	ring_list_addint(pList,ring_list_getsize(pVM->pTry));
	ring_list_addpointer(pList,pVM->pActiveMem);
	ring_list_addint(pList,pVM->nListStart);
	ring_list_addpointer(pList,pVM->pNestedLists);
	ring_list_addint(pList,pVM->nInsideBraceFlag);
	ring_list_addint(pList,ring_list_getsize(pVM->aForStep));
	ring_list_addint(pList,ring_list_getsize(pVM->aBeforeObjState));
	ring_list_addpointer(pList,pVM->aPCBlockFlag);
}

void ring_vm_restorestate ( VM *pVM,List *pList,int nPos,int nFlag )
{
	pList = ring_list_getlist(pList,nPos);
	/* Set Scope */
	pVM->pActiveMem = (List *) ring_list_getpointer(pList,19) ;
	ring_vm_backstate(ring_list_getint(pList,1),pVM->pMem);
	/* We also return to the function call list */
	ring_vm_backstate(ring_list_getint(pList,2),pVM->pFuncCallList);
	/* Stack & Executing Functions */
	pVM->nFuncExecute = ring_list_getint(pList,3) ;
	pVM->nSP = ring_list_getint(pList,4) ;
	pVM->nFuncSP = ring_list_getint(pList,5) ;
	/* We also return to the Active Object */
	ring_vm_backstate(ring_list_getint(pList,6),pVM->pObjState);
	ring_vm_backstate(ring_list_getint(pList,7),pVM->aBraceObjects);
	pVM->pBraceObject = (List *) ring_list_getpointer(pList,8) ;
	/* FileName & Packages */
	pVM->cFileName = (char *) ring_list_getpointer(pList,9) ;
	/* aPCBlockFlag, aScopeNewObj , aActivePackage & aScopeID */
	if ( ((List *) ring_list_getpointer(pList,25)) != pVM->aPCBlockFlag ) {
		pVM->aPCBlockFlag = ring_list_delete(pVM->aPCBlockFlag);
		pVM->aPCBlockFlag = (List *) ring_list_getpointer(pList,25) ;
	}
	ring_vm_backstate(ring_list_getint(pList,10),pVM->aPCBlockFlag);
	pVM->nBlockFlag = ring_list_getint(pList,11) ;
	ring_vm_backstate(ring_list_getint(pList,12),pVM->aScopeNewObj);
	ring_vm_backstate(ring_list_getint(pList,13),pVM->aActivePackage);
	ring_vm_backstate(ring_list_getint(pList,14),pVM->aScopeID);
	pVM->nActiveScopeID = ring_list_getint(pList,15) ;
	/* Loop/Exit Mark */
	if ( nFlag != RING_STATE_EXIT ) {
		ring_vm_backstate(ring_list_getint(pList,16),pVM->pExitMark);
		ring_vm_backstate(ring_list_getint(pList,17),pVM->pLoopMark);
		/* For Step */
		ring_vm_backstate(ring_list_getint(pList,23),pVM->aForStep);
	}
	/* Try/Catch/Done */
	if ( nFlag != RING_STATE_TRYCATCH ) {
		ring_vm_backstate(ring_list_getint(pList,18),pVM->pTry);
	}
	/* List Status */
	pVM->nListStart = ring_list_getint(pList,20) ;
	if ( ring_list_getpointer(pList,21) != pVM->pNestedLists ) {
		pVM->pNestedLists = ring_list_delete(pVM->pNestedLists);
		pVM->pNestedLists = (List *) ring_list_getpointer(pList,21) ;
	}
	pVM->nInsideBraceFlag = ring_list_getint(pList,22) ;
	ring_vm_backstate(ring_list_getint(pList,24),pVM->aBeforeObjState);
}
/* Save/Restore State 2 - Used by Function Call & Return */

void ring_vm_savestate2 ( VM *pVM,List *pList )
{
	/* Save State */
	ring_list_addint(pList,ring_list_getsize(pVM->pExitMark));
	ring_list_addint(pList,ring_list_getsize(pVM->pLoopMark));
	ring_list_addint(pList,ring_list_getsize(pVM->pTry));
	ring_list_addint(pList,ring_list_getsize(pVM->aBraceObjects));
	ring_list_addpointer(pList,pVM->pBraceObject);
	ring_list_addint(pList,ring_list_getsize(pVM->pObjState));
	ring_list_addint(pList,pVM->nInsideBraceFlag);
	ring_list_addint(pList,ring_list_getsize(pVM->aForStep));
	ring_list_addpointer(pList,pVM->pActiveMem);
	ring_list_addint(pList,pVM->nFuncExecute2);
	pVM->nInsideBraceFlag = 0 ;
	/* Save BlockFlag */
	ring_list_addint(pList,pVM->nBlockFlag);
	ring_list_addpointer(pList,pVM->aPCBlockFlag);
	pVM->nBlockFlag = 0 ;
	pVM->aPCBlockFlag = ring_list_new(0);
	/* Save nPrivateFlag, set it to 0 (public not private) */
	ring_list_addint(pList,pVM->nPrivateFlag);
	pVM->nPrivateFlag = 0 ;
	/* Save nCallClassInit */
	ring_list_addint(pList,pVM->nCallClassInit);
	pVM->nCallClassInit = 0 ;
}

void ring_vm_restorestate2 ( VM *pVM,List *pList,int x )
{
	/* Restore State */
	ring_vm_backstate(ring_list_getint(pList,x),pVM->pExitMark);
	ring_vm_backstate(ring_list_getint(pList,x+1),pVM->pLoopMark);
	ring_vm_backstate(ring_list_getint(pList,x+2),pVM->pTry);
	ring_vm_backstate(ring_list_getint(pList,x+3),pVM->aBraceObjects);
	pVM->pBraceObject = (List *) ring_list_getpointer(pList,x+4) ;
	ring_vm_backstate(ring_list_getint(pList,x+5),pVM->pObjState);
	pVM->nInsideBraceFlag = ring_list_getint(pList,x+6) ;
	ring_vm_backstate(ring_list_getint(pList,x+7),pVM->aForStep);
	pVM->pActiveMem = (List *) ring_list_getpointer(pList,x+8) ;
	pVM->nFuncExecute2 = ring_list_getint(pList,x+9) ;
	/* Restore BlockFLag */
	pVM->aPCBlockFlag = ring_list_delete(pVM->aPCBlockFlag);
	pVM->nBlockFlag = ring_list_getint(pList,x+10) ;
	pVM->aPCBlockFlag = (List *) ring_list_getpointer(pList,x+11) ;
	/* Restore nPrivateFlag */
	pVM->nPrivateFlag = ring_list_getint(pList,x+12) ;
	/* Restore nCallClassInit */
	pVM->nCallClassInit = ring_list_getint(pList,x+13) ;
}
/* Return to a Specific position in the array, delete all items after that position */

void ring_vm_backstate ( int x,List *pList )
{
	int nLimit,y  ;
	if ( x < ring_list_getsize(pList) ) {
		nLimit = ring_list_getsize(pList) ;
		for ( y = x + 1 ; y <= nLimit ; y++ ) {
			ring_list_deleteitem(pList,ring_list_getsize(pList));
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
	pList = ring_list_new(0);
	while ( pVM->nSP  != 0 ) {
		if ( RING_VM_STACK_ISSTRING ) {
			ring_list_addstring(pList,RING_VM_STACK_READC);
		}
		else if ( RING_VM_STACK_ISNUMBER ) {
			ring_list_adddouble(pList,RING_VM_STACK_READN);
		}
		else if ( RING_VM_STACK_ISPOINTER ) {
			pList2 = ring_list_newlist(pList);
			ring_list_addpointer(pList2,RING_VM_STACK_READP);
			ring_list_addint(pList2,RING_VM_STACK_OBJTYPE);
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
	ring_list_delete(pList);
}

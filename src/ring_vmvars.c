/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Variables 
**  Memory is a List and each item inside the list is another List (Represent Scope) 
**  The Variable is a List contains ( Name , Type , Value , [Pointer Type] ) 
**  When we find varaible or create new varaible we push variable pointer to the stack 
*/

void ring_vm_newscope ( VM *pVM )
{
	pVM->pActiveMem = ring_list_newlist(pVM->pMem);
	/* Save Local Scope Information */
	pVM->nScopeID++ ;
	ring_list_addint(pVM->aScopeID,pVM->nScopeID);
	pVM->nActiveScopeID = pVM->nScopeID ;
}

int ring_vm_findvar ( VM *pVM,const char *cStr )
{
	int x,nPos,nMax1  ;
	List *pList,*pList2  ;
	assert(pVM->pMem);
	nMax1 = ring_list_getsize(pVM->pMem);
	/* The scope of the search result */
	pVM->nVarScope = RING_VARSCOPE_NOTHING ;
	if ( nMax1 > 0 ) {
		/* Loop to search in each Scope */
		for ( x = 1 ; x <= 3 ; x++ ) {
			/* 1 = last scope (function) , 2 = Object State , 3 = global scope */
			if ( x == 1 ) {
				pList = pVM->pActiveMem ;
			}
			else if ( x == 2 ) {
				if ( ring_list_getsize(pVM->pObjState) == 0 ) {
					continue ;
				}
				/* Search in Object State */
				pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)) ;
				pList = (List *) ring_list_getpointer(pList,RING_OBJSTATE_SCOPE) ;
				if ( pList == NULL ) {
					continue ;
				}
				/* Pass Braces for Class Init() method */
				if ( (ring_list_getsize(pVM->pObjState) > 1) && (pVM->nCallClassInit) ) {
					pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)-1) ;
					pList = (List *) ring_list_getpointer(pList,RING_OBJSTATE_SCOPE) ;
					if ( pList == NULL ) {
						continue ;
					}
				}
			} else {
				pList = ring_list_getlist(pVM->pMem,RING_MEMORY_GLOBALSCOPE);
			}
			if ( ring_list_getsize(pList) < 10 ) {
				/* Search Using Linear Search */
				nPos = ring_list_findstring(pList,cStr,1);
				if ( nPos != 0 ) {
					pList2 = ring_list_getlist(pList,nPos);
					return ring_vm_findvar2(pVM,x,pList2,cStr) ;
				}
			}
			else {
				/* Search Using the HashTable */
				if ( pList->pHashTable == NULL ) {
					ring_list_genhashtable2(pList);
				}
				pList2 = (List *) ring_hashtable_findpointer(pList->pHashTable,cStr);
				if ( pList2 != NULL ) {
					return ring_vm_findvar2(pVM,x,pList2,cStr) ;
				}
			}
		}
	}
	return 0 ;
}

int ring_vm_findvar2 ( VM *pVM,int x,List *pList2,const char *cStr )
{
	int nPC,nType  ;
	Item *pItem  ;
	List *pList  ;
	/*
	**  Now We have the variable List 
	**  The Scope of the search result 
	*/
	if ( ( x == 1 ) && (pVM->pActiveMem == ring_list_getlist(pVM->pMem,RING_MEMORY_GLOBALSCOPE)) ) {
		x = RING_VARSCOPE_GLOBAL ;
	}
	else if ( (x == 1) && (pVM->pActiveMem != ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem))) ) {
		x = RING_VARSCOPE_NEWOBJSTATE ;
	}
	pVM->nVarScope = x ;
	pVM->nSP++ ;
	if ( ring_list_getint(pList2,RING_VAR_TYPE) == RING_VM_POINTER ) {
		if ( pVM->nFirstAddress  == 1 ) {
			RING_VM_STACK_SETPVALUE(pList2);
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
			return 1 ;
		}
		RING_VM_STACK_SETPVALUE(ring_list_getpointer(pList2,RING_VAR_VALUE ));
		RING_VM_STACK_OBJTYPE = ring_list_getint(pList2,RING_VAR_PVALUETYPE) ;
		/*
		**  Here we don't know the correct scope of the result 
		**  becauase a global variable may be a reference to local variable 
		**  And this case happens with setter/getter of the attributes using eval() 
		*/
		pVM->nVarScope = RING_VARSCOPE_NOTHING ;
	} else {
		/* Check Private Attributes */
		if ( ring_list_getint(pList2,RING_VAR_PRIVATEFLAG) == 1 ) {
			if ( pVM->nVarScope != RING_VARSCOPE_OBJSTATE ) {
				if ( ring_vm_oop_callmethodinsideclass(pVM) == 0 ) {
					ring_vm_error2(pVM,RING_VM_ERROR_USINGPRIVATEATTRIBUTE,cStr);
					return 0 ;
				}
			}
		}
		RING_VM_STACK_SETPVALUE(pList2);
		RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
		/* Check Setter/Getter for Public Attributes */
		if ( pVM->nGetSetProperty == 1 ) {
			ring_vm_oop_setget(pVM,pList2);
		}
		else if ( ( x == RING_VARSCOPE_OBJSTATE ) && ( ring_vm_oop_callmethodinsideclass(pVM) == 0 ) ) {
			/* Accessing Object Attribute Using { } */
			if ( ring_list_getsize(pVM->aBraceObjects) > 0 ) {
				pList = ring_list_getlist(pVM->aBraceObjects,ring_list_getsize(pVM->aBraceObjects));
				/* Get Object List */
				pList = (List *) ring_list_getpointer(pList,RING_ABRACEOBJECTS_BRACEOBJECT);
				nType = ring_vm_oop_objtypefromobjlist(pList);
				/* Set Object Pointer & Type */
				if ( nType == RING_OBJTYPE_VARIABLE ) {
					pList = ring_vm_oop_objvarfromobjlist(pList);
					pVM->pGetSetObject = pList ;
				}
				else if ( nType == RING_OBJTYPE_LISTITEM ) {
					pItem = ring_vm_oop_objitemfromobjlist(pList);
					pVM->pGetSetObject = pItem ;
				}
				pVM->nGetSetObjType = nType ;
				/* Change Assignment Instruction to SetProperty */
				if ( RING_VM_IR_PARACOUNT >= 4 ) {
					if ( RING_VM_IR_READIVALUE(3) != 0 ) {
						nPC = pVM->nPC ;
						pVM->nPC = RING_VM_IR_READIVALUE(3) ;
						RING_VM_IR_LOAD ;
						RING_VM_IR_OPCODE = ICO_SETPROPERTY ;
						pVM->nPC = nPC ;
						RING_VM_IR_UNLOAD ;
						/* Avoid AssignmentPointer , we don't have assignment */
						pVM->nNOAssignment = 1 ;
					}
				}
				ring_vm_oop_setget(pVM,pList2);
			}
		}
	}
	return 1 ;
}

void ring_vm_newvar ( VM *pVM,const char *cStr )
{
	List *pList  ;
	assert(pVM->pActiveMem);
	pList = ring_vm_newvar2(cStr,pVM->pActiveMem);
	pVM->nSP++ ;
	RING_VM_STACK_SETPVALUE(pList);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
	/* Set the scope of the new variable */
	if ( (ring_list_getsize(pVM->pMem) == 1) && (pVM->pActiveMem == ring_list_getlist(pVM->pMem,RING_MEMORY_GLOBALSCOPE)) ) {
		pVM->nVarScope = RING_VARSCOPE_GLOBAL ;
	}
	else if ( pVM->pActiveMem == ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)) ) {
		pVM->nVarScope = RING_VARSCOPE_LOCAL ;
	} else {
		pVM->nVarScope = RING_VARSCOPE_NOTHING ;
	}
	/* Add Scope to aLoadAddressScope */
	ring_list_addint(pVM->aLoadAddressScope,pVM->nVarScope);
}

List * ring_vm_newvar2 ( const char *cStr,List *pParent )
{
	List *pList  ;
	/* This function is called by all of the other functions that create new varaibles */
	pList = ring_list_newlist(pParent);
	ring_list_addstring(pList,cStr);
	ring_list_addint(pList,RING_VM_NULL);
	ring_list_addstring(pList,"NULL");
	/* Pointer Type */
	ring_list_addint(pList,0);
	/* Private Flag */
	ring_list_addint(pList,0);
	/* Add Pointer to the HashTable */
	if ( pParent->pHashTable == NULL ) {
		pParent->pHashTable = ring_hashtable_new();
	}
	ring_hashtable_newpointer(pParent->pHashTable,cStr,pList);
	return pList ;
}

void ring_vm_addnewnumbervar ( VM *pVM,const char *cStr,double x )
{
	List *pList  ;
	pList = ring_vm_newvar2(cStr,pVM->pActiveMem);
	ring_list_setint(pList,RING_VAR_TYPE,RING_VM_NUMBER);
	ring_list_setdouble(pList,RING_VAR_VALUE,x);
}

void ring_vm_addnewstringvar ( VM *pVM,const char *cStr,const char *cStr2 )
{
	List *pList  ;
	pList = ring_vm_newvar2(cStr,pVM->pActiveMem);
	ring_list_setint(pList,RING_VAR_TYPE,RING_VM_STRING);
	ring_list_setstring(pList,RING_VAR_VALUE,cStr2);
}

void ring_vm_addnewstringvar2 ( VM *pVM,const char *cStr,const char *cStr2,int nStrSize )
{
	List *pList  ;
	pList = ring_vm_newvar2(cStr,pVM->pActiveMem);
	ring_list_setint(pList,RING_VAR_TYPE,RING_VM_STRING);
	ring_list_setstring2(pList,RING_VAR_VALUE,cStr2,nStrSize);
}

void ring_vm_addnewpointervar ( VM *pVM,const char *cStr,void *x,int y )
{
	List *pList  ;
	pList = ring_vm_newvar2(cStr,pVM->pActiveMem);
	ring_list_setint(pList,RING_VAR_TYPE,RING_VM_POINTER);
	ring_list_setpointer(pList,RING_VAR_VALUE,x);
	ring_list_setint(pList,RING_VAR_PVALUETYPE,y);
	/* Reference Counting */
	ring_vm_gc_checknewreference(x,y);
}

void ring_vm_newtempvar ( VM *pVM,const char *cStr, List *TempList )
{
	List *pList  ;
	pList = ring_vm_newvar2(cStr,TempList);
	pVM->nSP++ ;
	RING_VM_STACK_SETPVALUE(pList);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
}

List * ring_vm_newtempvar2 ( VM *pVM,const char *cStr,List *pList3 )
{
	List *pList,*pList2  ;
	pList = ring_vm_newvar2(cStr,pVM->pTempMem);
	ring_list_setint(pList,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist(pList,RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList,RING_VAR_VALUE);
	ring_list_deleteallitems(pList2);
	ring_list_copy(pList2,pList3);
	return pList ;
}

void ring_vm_addnewcpointervar ( VM *pVM,const char *cStr,void *pPointer,const char *cStr2 )
{
	List *pList, *pList2  ;
	pList = ring_vm_newvar2(cStr,pVM->pActiveMem);
	ring_list_setint(pList,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist(pList,RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList,RING_VAR_VALUE);
	/* Add Pointer */
	ring_list_addpointer(pList2,pPointer);
	/* Add Type */
	ring_list_addstring(pList2,cStr2);
	/* Add Status Number */
	ring_list_addint(pList2,RING_CPOINTERSTATUS_NOTCOPIED);
}

void ring_vm_deletescope ( VM *pVM )
{
	if ( ring_list_getsize(pVM->pMem) < 2 ) {
		puts("Internal Error - Deleting scope while no scope! ");
		exit(0);
	}
	/* Check References */
	ring_vm_gc_checkreferences(pVM);
	ring_list_deleteitem(pVM->pMem,ring_list_getsize(pVM->pMem));
	pVM->pActiveMem = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem));
	/* Delete Local Scope information */
	ring_list_deleteitem(pVM->aScopeID,ring_list_getsize(pVM->aScopeID));
	pVM->nActiveScopeID = ring_list_getint(pVM->aScopeID,ring_list_getsize(pVM->aScopeID)) ;
}

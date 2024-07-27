/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

void ring_vm_addglobalvariables ( VM *pVM )
{
	List *pList  ;
	int x  ;
	/*
	**  Add Variables 
	**  We write variable name in lower case because Identifiers is converted to lower by Compiler(Scanner) 
	*/
	ring_vm_addnewnumbervar(pVM,RING_CSTR_TRUEVAR,RING_TRUE);
	ring_vm_addnewnumbervar(pVM,RING_CSTR_FALSEVAR,RING_FALSE);
	ring_vm_addnewstringvar(pVM,RING_CSTR_NLVAR,RING_CSTR_NL);
	ring_vm_addnewstringvar(pVM,RING_CSTR_NULLVAR,RING_CSTR_EMPTY);
	ring_vm_addnewpointervar(pVM,RING_CSTR_GETTEMPVAR,NULL,RING_OBJTYPE_NOTYPE);
	ring_vm_addnewstringvar(pVM,RING_CSTR_CATCHERROR,RING_CSTR_NULL);
	ring_vm_addnewpointervar(pVM,RING_CSTR_SETTEMPVAR,NULL,RING_OBJTYPE_NOTYPE);
	ring_vm_addnewcpointervar(pVM,RING_CSTR_STDINVAR,stdin,RING_CSTR_FILE);
	ring_vm_addnewcpointervar(pVM,RING_CSTR_STDOUTVAR,stdout,RING_CSTR_FILE);
	ring_vm_addnewcpointervar(pVM,RING_CSTR_STDERRVAR,stderr,RING_CSTR_FILE);
	ring_vm_addnewpointervar(pVM,RING_CSTR_THISVAR,NULL,RING_OBJTYPE_NOTYPE);
	ring_vm_addnewstringvar(pVM,RING_CSTR_TABVAR,RING_CSTR_TAB);
	ring_vm_addnewstringvar(pVM,RING_CSTR_CRVAR,RING_CSTR_CR);
	/* Add Command Line Parameters */
	pList = ring_vm_addnewlistvar(pVM,RING_CSTR_SYSARGV);
	pList = ring_list_getlist(pList,RING_VAR_VALUE);
	for ( x = 0 ; x < pVM->pRingState->nArgc ; x++ ) {
		ring_list_addstring_gc(pVM->pRingState,pList,pVM->pRingState->pArgv[x]);
	}
}
/*
**  Memory is a List and each item inside the list is another List (Represent Scope) 
**  The Variable is a List contains ( Name , Type , Value , [Pointer Type] , [Private Flag] ) 
**  When we find variable or create new variable we push variable pointer to the stack 
*/

void ring_vm_newscope ( VM *pVM )
{
	/* Check scopes count */
	if ( RING_VM_FUNCCALLSCOUNT >= RING_VM_STACK_CHECKOVERFLOW ) {
		ring_vm_error(pVM,RING_VM_ERROR_STACKOVERFLOW);
		exit(RING_EXIT_FAIL);
	}
	pVM->pActiveMem = RING_VM_NEWSCOPE ;
}

int ring_vm_findvar ( VM *pVM,const char *cStr )
{
	int x,nPos,nMax1  ;
	List *pList,*pList2  ;
	pVM->lSelfLoadA = 0 ;
	nMax1 = RING_VM_SCOPESCOUNT ;
	/* The scope of the search result */
	pVM->nVarScope = RING_VARSCOPE_NOTHING ;
	if ( nMax1 > 0 ) {
		/* Loop to search in each Scope */
		for ( x = 1 ; x <= 4 ; x++ ) {
			/* 1 = last scope (function) , 2 = Object State , 3 - Defined Globals , 4 = Global scope */
			if ( x == 1 ) {
				pList = pVM->pActiveMem ;
			}
			else if ( x == 2 ) {
				/*
				**  Check to avoid the Object Scope 
				**  IF obj.attribute - we did the search in local scope - pass others 
				**  Also if we don't have object scope using { } we will pass 
				**  Also If we are using ICO_LOADAFIRST (Used by For In) - we don't check object scope 
				*/
				if ( (pVM->lGetSetProperty == 1) || (ring_list_getsize(pVM->pObjState) == 0) || pVM->lFirstAddress ) {
					continue ;
				}
				/* Search in Object State */
				pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)) ;
				pList = (List *) ring_list_getpointer(pList,RING_OBJSTATE_SCOPE) ;
				if ( pList == NULL ) {
					continue ;
				}
				/* Pass Braces for Class Init() method */
				if ( (ring_list_getsize(pVM->pObjState) > pVM->nCallClassInit) && (pVM->nCallClassInit) ) {
					pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)-pVM->nCallClassInit) ;
					pList = (List *) ring_list_getpointer(pList,RING_OBJSTATE_SCOPE) ;
					if ( pList == NULL ) {
						continue ;
					}
				}
			}
			else {
				/*
				**  Check to Avoid the global scope 
				**  If we are using ICO_LOADAFIRST (Used by For In) - we don't check global scope 
				**  Also IF obj.attribute - we did the search in local scope - pass others 
				*/
				if ( (pVM->lGetSetProperty == 1) || pVM->lFirstAddress ) {
					continue ;
				}
				if ( x == 3 ) {
					pList = pVM->pDefinedGlobals ;
				}
				else {
					pList = ring_vm_getglobalscope(pVM);
				}
			}
			if ( ring_list_getsize(pList) < RING_VARSCOPE_SIZETOUSEHASHTABLE ) {
				/* Search Using Linear Search */
				nPos = ring_list_findstring(pList,cStr,RING_VAR_NAME);
				if ( nPos != 0 ) {
					if ( ring_list_islist(pList,nPos) ) {
						pList2 = ring_list_getlist(pList,nPos);
						return ring_vm_findvar2(pVM,x,pList2,cStr) ;
					}
				}
			}
			else {
				/* Search Using the HashTable */
				if ( pList->pHashTable == NULL ) {
					ring_list_genhashtable2_gc(pVM->pRingState,pList);
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

int ring_vm_findvar2 ( VM *pVM,int nLevel,List *pList2,const char *cStr )
{
	int nPC,nType,lPrivateError,nAssignmentPos  ;
	Item *pItem  ;
	List *pList, *pThis  ;
	/*
	**  Now We have the variable List 
	**  The Scope of the search result 
	*/
	if ( nLevel == RING_VARSCOPE_LOCAL ) {
		if ( pVM->pActiveMem == ring_vm_getglobalscope(pVM) ) {
			nLevel = RING_VARSCOPE_GLOBAL ;
		}
		else if ( pVM->pActiveMem != RING_VM_GETLASTSCOPE ) {
			nLevel = RING_VARSCOPE_NEWOBJSTATE ;
		}
	}
	pVM->nVarScope = nLevel ;
	RING_VM_SP_INC ;
	if ( ring_list_getint(pList2,RING_VAR_TYPE) == RING_VM_POINTER ) {
		if ( pVM->lFirstAddress  == 1 ) {
			RING_VM_STACK_SETPVALUE(pList2);
			RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
			return 1 ;
		}
		RING_VM_STACK_SETPVALUE(ring_list_getpointer(pList2,RING_VAR_VALUE ));
		RING_VM_STACK_OBJTYPE = ring_list_getint(pList2,RING_VAR_PVALUETYPE) ;
		/*
		**  Here we don't know the correct scope of the result 
		**  because a global variable may be a reference to local variable 
		**  And this case happens with setter/getter of the attributes using eval() 
		**  Here we avoid this change if the variable name is RING_CSTR_SELF|RING_CSTR_THIS to return self|this by reference 
		*/
		if ( (strcmp(cStr,RING_CSTR_SELF) != 0) && (strcmp(cStr,RING_CSTR_THIS) != 0) ) {
			pVM->nVarScope = RING_VARSCOPE_NOTHING ;
		}
		else {
			pVM->lSelfLoadA = 1 ;
		}
	}
	else {
		/* Check Private Attributes */
		if ( ring_vm_var_getprivateflag(pVM,pList2) == 1 ) {
			/* We check that we are not in the class region too (defining the private attribute then reusing it) */
			if ( ! ( (pVM->nVarScope == RING_VARSCOPE_NEWOBJSTATE) &&  (pVM->nInClassRegion == 1) ) ) {
				if ( ring_vm_oop_callmethodinsideclass(pVM) == 0 ) {
					lPrivateError = 1 ;
					/* Pass Braces for Class Init() to be sure we are inside a method or not */
					if ( (ring_list_getsize(pVM->pObjState) > pVM->nCallClassInit) && (pVM->nCallClassInit) ) {
						pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState) - pVM->nCallClassInit) ;
						if ( (ring_list_getsize(pList) == 4) && (pVM->lCallMethod == 0) ) {
							/* Here we have a method, So we avoid the private attribute error! */
							lPrivateError = 0 ;
						}
					}
					if ( lPrivateError ) {
						ring_vm_error2(pVM,RING_VM_ERROR_USINGPRIVATEATTRIBUTE,cStr);
						return 0 ;
					}
				}
			}
		}
		RING_VM_STACK_SETPVALUE(pList2);
		RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
		/* Check Setter/Getter for Public Attributes */
		if ( pVM->lGetSetProperty == 1 ) {
			/* Avoid executing Setter/Getter when we use self.attribute and this.attribute */
			pThis = ring_list_getlist(pVM->pDefinedGlobals,RING_GLOBALVARPOS_THIS) ;
			if ( pThis != NULL ) {
				if ( ring_list_getpointer(pThis,RING_VAR_VALUE ) == pVM->pGetSetObject ) {
					return 1 ;
				}
			}
			ring_vm_oop_setget(pVM,pList2);
		}
		else if ( ( nLevel == RING_VARSCOPE_OBJSTATE ) && ( ring_vm_oop_callmethodinsideclass(pVM) == 0 ) ) {
			/* Accessing Object Attribute Using { } */
			if ( ring_list_getsize(pVM->pBraceObjects) > 0 ) {
				pList = ring_list_getlist(pVM->pBraceObjects,ring_list_getsize(pVM->pBraceObjects));
				/* Pass braces { } for class init() method */
				if ( pVM->nCallClassInit ) {
					/*
					**  Here ring_vm_oop_callmethodinsideclass(pVM) will return 0 because of class init() calling 
					**  This check can be done here or in ring_vm_oop_callmethodinsideclass() 
					*/
					return 1 ;
				}
				/* Get Object List */
				pList = (List *) ring_list_getpointer(pList,RING_BRACEOBJECTS_BRACEOBJECT);
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
				/*
				**  Change Assignment Instruction to SetProperty 
				**  Get Assignment Instruction Position (From the ICO_ASSIGNMENTPOINTER instruction) 
				*/
				nPC = pVM->nPC ;
				RING_VM_IR_LOAD ;
				nAssignmentPos = RING_ZERO ;
				if ( RING_VM_IR_OPCODE == ICO_ASSIGNMENTPOINTER ) {
					nAssignmentPos = RING_VM_IR_READIVALUE(RING_VM_IR_REG2) ;
				}
				RING_VM_IR_UNLOAD ;
				if ( nAssignmentPos != 0 ) {
					pVM->nPC = nAssignmentPos ;
					RING_VM_IR_LOAD ;
					RING_VM_IR_OPCODE = ICO_SETPROPERTY ;
					pVM->nPC = nPC ;
					RING_VM_IR_UNLOAD ;
					/* Avoid AssignmentPointer , we don't have assignment */
					pVM->lNoAssignment = 1 ;
				}
				ring_vm_oop_setget(pVM,pList2);
			}
		}
		/* Check lNewRef Flag */
		ring_list_resetlnewref(pList2);
	}
	return 1 ;
}

void ring_vm_newvar ( VM *pVM,const char *cStr )
{
	List *pList  ;
	pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
	RING_VM_SP_INC ;
	RING_VM_STACK_SETPVALUE(pList);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
	/* Set the scope of the new variable */
	if ( (RING_VM_SCOPESCOUNT == 1) && (pVM->pActiveMem == RING_VM_GETSCOPE(RING_MEMORY_GLOBALSCOPE)) ) {
		pVM->nVarScope = RING_VARSCOPE_GLOBAL ;
	}
	else if ( pVM->pActiveMem == RING_VM_GETLASTSCOPE ) {
		pVM->nVarScope = RING_VARSCOPE_LOCAL ;
	}
	else {
		pVM->nVarScope = RING_VARSCOPE_NOTHING ;
	}
	/* Save Scope Information */
	if ( pVM->nLoadAddressScope  == RING_VARSCOPE_NOTHING ) {
		pVM->nLoadAddressScope = pVM->nVarScope ;
	}
}

List * ring_vm_newvar2 ( VM *pVM,const char *cStr,List *pParent )
{
	List *pList  ;
	/*
	**  This function is called by all of the other functions that create new variables 
	**  Get/Create the parent list 
	*/
	if ( pParent != NULL ) {
		pList = ring_list_newlist_gc(pVM->pRingState,pParent);
	}
	else {
		pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
	}
	ring_list_addstring_gc(pVM->pRingState,pList,cStr);
	/* Determine Type based on Region */
	if ( pVM->nInClassRegion ) {
		ring_list_addint_gc(pVM->pRingState,pList,RING_VM_STRING);
	}
	else {
		ring_list_addint_gc(pVM->pRingState,pList,RING_VM_NULL);
	}
	ring_list_addstring_gc(pVM->pRingState,pList,RING_CSTR_NULL);
	/* Pointer Type */
	ring_list_addint_gc(pVM->pRingState,pList,RING_OBJTYPE_NOTYPE);
	/* HashTable */
	if ( pParent != NULL ) {
		/* Add Pointer to the HashTable */
		if ( pParent->pHashTable != NULL ) {
			ring_hashtable_newpointer_gc(pVM->pRingState,pParent->pHashTable,cStr,pList);
		}
	}
	return pList ;
}

void ring_vm_addnewnumbervar ( VM *pVM,const char *cStr,double nNumber )
{
	List *pList  ;
	pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_NUMBER);
	ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,nNumber);
}

void ring_vm_addnewstringvar ( VM *pVM,const char *cStr,const char *cStr2 )
{
	List *pList  ;
	pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_STRING);
	ring_list_setstring_gc(pVM->pRingState,pList,RING_VAR_VALUE,cStr2);
}

void ring_vm_addnewstringvar2 ( VM *pVM,const char *cStr,const char *cStr2,int nStrSize )
{
	List *pList  ;
	pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_STRING);
	ring_list_setstring2_gc(pVM->pRingState,pList,RING_VAR_VALUE,cStr2,nStrSize);
}

void ring_vm_addnewpointervar ( VM *pVM,const char *cStr,void *pPointer,int nType )
{
	List *pList  ;
	pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_POINTER);
	ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE,pPointer);
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE,nType);
	/* Reference Counting */
	ring_vm_gc_checknewreference(pVM,pPointer,nType,pList,RING_VAR_VALUE);
}

List * ring_vm_addnewlistvar ( VM *pVM,const char *cStr )
{
	List *pList  ;
	pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist_gc(pVM->pRingState,pList,RING_VAR_VALUE);
	return pList ;
}

void ring_vm_newtempvar ( VM *pVM,const char *cStr, List *pTempList )
{
	List *pList  ;
	pList = ring_vm_newvar2(pVM,cStr,pTempList);
	RING_VM_SP_INC ;
	RING_VM_STACK_SETPVALUE(pList);
	RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
}

void ring_vm_addnewcpointervar ( VM *pVM,const char *cStr,void *pPointer,const char *cStr2 )
{
	List *pList, *pList2  ;
	pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
	ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_LIST);
	ring_list_setlist_gc(pVM->pRingState,pList,RING_VAR_VALUE);
	pList2 = ring_list_getlist(pList,RING_VAR_VALUE);
	/* Add Pointer */
	ring_list_addpointer_gc(pVM->pRingState,pList2,pPointer);
	/* Add Type */
	ring_list_addstring_gc(pVM->pRingState,pList2,cStr2);
	/* Add Status Number */
	ring_list_addint_gc(pVM->pRingState,pList2,RING_CPOINTERSTATUS_NOTCOPIED);
}

void ring_vm_deletescope ( VM *pVM )
{
	List *pList  ;
	ListBlocks *pArg  ;
	int x  ;
	if ( RING_VM_SCOPESCOUNT < 2 ) {
		printf( RING_NOSCOPE ) ;
		exit(RING_EXIT_FAIL);
	}
	/* Process Lists */
	for ( x = ring_list_getsize(pVM->pActiveMem) ; x >= 1 ; x-- ) {
		if ( ring_list_islist(pVM->pActiveMem,x) ) {
			pList = ring_list_getlist(pVM->pActiveMem,x);
			/* Check adding numeric arguments to the cache */
			if ( ring_list_isargcache(pList) ) {
				/*
				**  Reset flag that (For-In) could set when using var name similar to argument name 
				**  If we don't do that here, the tracking flag could be True 
				**  And calling ring_vm_deleteargcache() will try to delete the list 
				**  The delete operation will check this flag and if it's true it will call ring_vm_gc_removetrack 
				**  And this function assume pVM->pTrackedList exist 
				**  But it's deleted before calling ring_vm_deleteargcache inside ring_vm_delete 
				*/
				ring_vm_gc_removetrack(pVM->pRingState,pList);
				/* Clean Memory */
				ring_vm_gc_checkupdatereference(pVM,pList);
				ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,RING_ZEROF);
				pVM->pArgCache[pVM->nArgCacheCount++] = pList ;
				continue ;
			}
		}
	}
	RING_VM_DELETELASTSCOPE ;
	pVM->pActiveMem = RING_VM_GETLASTSCOPE ;
}

void ring_vm_var_setprivateflag ( VM *pVM,List *pVar,int nFlag )
{
	if ( ring_list_getsize(pVar) == RING_VAR_PRIVATEFLAG - 1 ) {
		ring_list_addint_gc(pVM->pRingState,pVar,nFlag);
	}
	else if ( ring_list_getsize(pVar) == RING_VAR_PRIVATEFLAG ) {
		ring_list_setint_gc(pVM->pRingState,pVar,RING_VAR_PRIVATEFLAG,nFlag);
	}
}

int ring_vm_var_getprivateflag ( VM *pVM,List *pVar )
{
	if ( ring_list_getsize(pVar) >= RING_VAR_PRIVATEFLAG ) {
		return ring_list_getint(pVar,RING_VAR_PRIVATEFLAG) ;
	}
	return 0 ;
}

void ring_vm_copyscopestolist ( VM *pVM,List *pList )
{
	List *pNewList  ;
	int x  ;
	for ( x = 1 ; x <= RING_VM_SCOPESCOUNT ; x++ ) {
		pNewList = ring_list_newlist_gc(pVM->pRingState,pList);
		ring_list_copy_gc(pVM->pRingState,pNewList,RING_VM_GETSCOPE(x));
	}
}

void ring_vm_newargcache ( VM *pVM )
{
	int x  ;
	List *pList  ;
	pVM->nArgCacheCount = 0 ;
	for ( x = 1 ; x <= RING_VM_ARGCACHE_SIZE ; x++ ) {
		/* Create the Argument List */
		pList = ring_list_new_gc(pVM->pRingState,RING_ZERO);
		ring_list_addstring_gc(pVM->pRingState,pList,RING_CSTR_EMPTY);
		ring_list_addint_gc(pVM->pRingState,pList,RING_VM_NUMBER);
		ring_list_adddouble_gc(pVM->pRingState,pList,RING_ZEROF);
		ring_list_addint_gc(pVM->pRingState,pList,RING_ZERO);
		ring_list_genarray_gc(pVM->pRingState,pList);
		ring_list_enableargcache(pList);
		ring_list_setlisttype(pList,RING_VM_NUMBER);
		ring_list_enabledontdelete(pList);
		pVM->pArgCache[pVM->nArgCacheCount++] = pList ;
	}
}

void ring_vm_deleteargcache ( VM *pVM )
{
	int x  ;
	for ( x = 0 ; x < RING_VM_ARGCACHE_SIZE ; x++ ) {
		ring_list_disabledontdelete(pVM->pArgCache[x]);
		pVM->pArgCache[x] = ring_list_delete_gc(pVM->pRingState,pVM->pArgCache[x]);
	}
}

List * ring_vm_addstringarg ( VM *pVM,const char *cVar,const char  *cStr,int nStrSize )
{
	List *pList, *pParent  ;
	pParent = pVM->pActiveMem ;
	if ( ! pVM->nArgCacheCount ) {
		pList = ring_list_newlist_gc(pVM->pRingState,pParent);
		ring_list_addstring_gc(pVM->pRingState,pList,cVar);
		ring_list_addint_gc(pVM->pRingState,pList,RING_VM_STRING);
		ring_list_addstring2_gc(pVM->pRingState,pList,cStr,nStrSize);
	}
	else {
		pList = ring_list_newlistbyptr_gc(pVM->pRingState,pParent,pVM->pArgCache[--(pVM->nArgCacheCount)]);
		ring_list_setstring_gc(pVM->pRingState,pList,RING_VAR_NAME,cVar);
		ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_STRING);
		ring_list_setstring2_gc(pVM->pRingState,pList,RING_VAR_VALUE,cStr,nStrSize);
	}
	ring_list_setlisttype(pList,RING_VM_STRING);
	/* Add Pointer to the HashTable */
	if ( pParent->pHashTable != NULL ) {
		ring_hashtable_newpointer_gc(pVM->pRingState,pParent->pHashTable,cVar,pList);
	}
	return pList ;
}

List * ring_vm_addnumberarg ( VM *pVM,const char *cVar,double nNumber )
{
	List *pList, *pParent  ;
	pParent = pVM->pActiveMem ;
	if ( ! pVM->nArgCacheCount ) {
		pList = ring_list_newlist_gc(pVM->pRingState,pParent);
		ring_list_addstring_gc(pVM->pRingState,pList,cVar);
		ring_list_addint_gc(pVM->pRingState,pList,RING_VM_NUMBER);
		ring_list_adddouble_gc(pVM->pRingState,pList,nNumber);
	}
	else {
		pList = ring_list_newlistbyptr_gc(pVM->pRingState,pParent,pVM->pArgCache[--(pVM->nArgCacheCount)]);
		ring_list_setstring_gc(pVM->pRingState,pList,RING_VAR_NAME,cVar);
		ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_NUMBER);
		ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,nNumber);
	}
	ring_list_setlisttype(pList,RING_VM_NUMBER);
	/* Add Pointer to the HashTable */
	if ( pParent->pHashTable != NULL ) {
		ring_hashtable_newpointer_gc(pVM->pRingState,pParent->pHashTable,cVar,pList);
	}
	return pList ;
}

List * ring_vm_addpointerarg ( VM *pVM,const char *cVar,void *pPointer,int nType )
{
	List *pList, *pParent  ;
	pParent = pVM->pActiveMem ;
	if ( ! pVM->nArgCacheCount ) {
		pList = ring_list_newlist_gc(pVM->pRingState,pParent);
		ring_list_addstring_gc(pVM->pRingState,pList,cVar);
		ring_list_addint_gc(pVM->pRingState,pList,RING_VM_POINTER);
		ring_list_addpointer_gc(pVM->pRingState,pList,pPointer);
		ring_list_addint_gc(pVM->pRingState,pList,nType);
	}
	else {
		pList = ring_list_newlistbyptr_gc(pVM->pRingState,pParent,pVM->pArgCache[--(pVM->nArgCacheCount)]);
		ring_list_setstring_gc(pVM->pRingState,pList,RING_VAR_NAME,cVar);
		ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_POINTER);
		ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE,pPointer);
		ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE,nType);
	}
	ring_list_setlisttype(pList,RING_VM_POINTER);
	/* Reference Counting */
	ring_vm_gc_checknewreference(pVM,pPointer,nType,pList,RING_VAR_VALUE);
	/* Add Pointer to the HashTable */
	if ( pParent->pHashTable != NULL ) {
		ring_hashtable_newpointer_gc(pVM->pRingState,pParent->pHashTable,cVar,pList);
	}
	return pList ;
}

List * ring_vm_addlistarg ( VM *pVM,const char *cVar )
{
	List *pList, *pParent  ;
	FuncCall *pFuncCall  ;
	pFuncCall = RING_VM_LASTFUNCCALL ;
	if ( pFuncCall->nType == RING_FUNCTYPE_C ) {
		pParent = pFuncCall->pTempMem ;
	}
	else {
		pParent = pVM->pActiveMem ;
	}
	if ( (! pVM->nArgCacheCount) || (pFuncCall->nType == RING_FUNCTYPE_SCRIPT) ) {
		pList = ring_list_newlist_gc(pVM->pRingState,pParent);
		ring_list_addstring_gc(pVM->pRingState,pList,cVar);
		ring_list_addint_gc(pVM->pRingState,pList,RING_VM_LIST);
		ring_list_newlist_gc(pVM->pRingState,pList);
	}
	else {
		pList = ring_list_newlistbyptr_gc(pVM->pRingState,pParent,pVM->pArgCache[--(pVM->nArgCacheCount)]);
		ring_list_setstring_gc(pVM->pRingState,pList,RING_VAR_NAME,cVar);
		ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_LIST);
		ring_list_setlist_gc(pVM->pRingState,pList,RING_VAR_VALUE);
	}
	ring_list_setlisttype(pList,RING_VM_LIST);
	/* Add Pointer to the HashTable */
	if ( pParent->pHashTable != NULL ) {
		ring_hashtable_newpointer_gc(pVM->pRingState,pParent->pHashTable,cVar,pList);
	}
	return pList ;
}

void ring_vm_newglobalscope ( VM *pVM )
{
	pVM->pActiveMem = ring_list_newlist_gc(pVM->pRingState,pVM->pGlobalScopes);
	ring_list_addpointer_gc(pVM->pRingState,pVM->pActiveGlobalScopes,pVM->pActiveMem);
}

void ring_vm_endglobalscope ( VM *pVM )
{
	ring_list_deletelastitem_gc(pVM->pRingState,pVM->pActiveGlobalScopes);
	if ( ring_list_getsize(pVM->pActiveGlobalScopes) == 0 ) {
		pVM->pActiveMem = RING_VM_GETSCOPE(RING_MEMORY_GLOBALSCOPE) ;
	}
	else {
		pVM->pActiveMem = (List *) ring_list_getpointer(pVM->pActiveGlobalScopes,ring_list_getsize(pVM->pActiveGlobalScopes));
	}
}

void ring_vm_setglobalscope ( VM *pVM )
{
	pVM->nCurrentGlobalScope = RING_VM_IR_READI ;
}

List * ring_vm_getglobalscope ( VM *pVM )
{
	List *pList  ;
	if ( pVM->nCurrentGlobalScope == 0 ) {
		pList = RING_VM_GETSCOPE(RING_MEMORY_GLOBALSCOPE) ;
	}
	else {
		pList = ring_list_getlist(pVM->pGlobalScopes,pVM->nCurrentGlobalScope);
	}
	return pList ;
}

/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/* Global Variables */

void ring_vm_addglobalvariables ( VM *pVM )
{
    List *pList  ;
    int x  ;
    pVM->nLoadAddressScope = RING_VARSCOPE_GLOBAL ;
    /*
    **  Add Variables 
    **  We write variable name in lower case because Identifiers is converted to lower by Compiler(Scanner) 
    */
    ring_vm_addnewnumbervar(pVM,"true",1);
    ring_vm_addnewnumbervar(pVM,"false",0);
    ring_vm_addnewstringvar(pVM,"nl","\n");
    ring_vm_addnewstringvar(pVM,"null","");
    ring_vm_addnewpointervar(pVM,"ring_gettemp_var",NULL,0);
    ring_vm_addnewstringvar(pVM,"ccatcherror","NULL");
    ring_vm_addnewpointervar(pVM,"ring_settemp_var",NULL,0);
    ring_vm_addnewnumbervar(pVM,"ring_tempflag_var",0);
    ring_vm_addnewcpointervar(pVM,"stdin",stdin,"file");
    ring_vm_addnewcpointervar(pVM,"stdout",stdout,"file");
    ring_vm_addnewcpointervar(pVM,"stderr",stderr,"file");
    ring_vm_addnewpointervar(pVM,"this",NULL,0);
    ring_vm_addnewstringvar(pVM,"tab","\t");
    ring_vm_addnewstringvar(pVM,"cr","\r");
    /* Add Command Line Parameters */
    pList = ring_vm_newvar2(pVM,"sysargv",pVM->pActiveMem);
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_LIST);
    ring_list_setlist_gc(pVM->pRingState,pList,RING_VAR_VALUE);
    pList = ring_list_getlist(pList,RING_VAR_VALUE);
    for ( x = 0 ; x < pVM->pRingState->argc ; x++ ) {
        ring_list_addstring_gc(pVM->pRingState,pList,pVM->pRingState->argv[x]);
    }
    pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
}
/*
**  Variables 
**  Memory is a List and each item inside the list is another List (Represent Scope) 
**  The Variable is a List contains ( Name , Type , Value , [Pointer Type] , [Private Flag] ) 
**  When we find variable or create new variable we push variable pointer to the stack 
*/

void ring_vm_newscope ( VM *pVM )
{
    /* Check scopes count */
    if ( ring_list_getsize(pVM->pMem) >= RING_VM_STACK_CHECKOVERFLOW ) {
        ring_vm_error(pVM,RING_VM_ERROR_STACKOVERFLOW);
        exit(1);
    }
    pVM->pActiveMem = ring_list_newlist_gc(pVM->pRingState,pVM->pMem);
}

int ring_vm_findvar ( VM *pVM,const char *cStr )
{
    int x,nPos,nMax1  ;
    List *pList,*pList2  ;
    pVM->lSelfLoadA = 0 ;
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
                /*
                **  Check to avoid the Object Scope 
                **  IF obj.attribute - we did the search in local scope - pass others 
                **  Also if we don't have object scope using { } we will pass 
                **  Also If we are using ICO_LOADAFIRST (Used by For In) - we don't check object scope 
                */
                if ( (pVM->nGetSetProperty == 1) || (ring_list_getsize(pVM->pObjState) == 0) || pVM->nFirstAddress ) {
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
                if ( (pVM->nGetSetProperty == 1) || pVM->nFirstAddress ) {
                    continue ;
                }
                pList = ring_vm_getglobalscope(pVM);
            }
            if ( ring_list_getsize(pList) < 10 ) {
                /* Search Using Linear Search */
                nPos = ring_list_findstring(pList,cStr,1);
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
    int nPC,nType,lPrivateError  ;
    Item *pItem  ;
    List *pList, *pThis  ;
    /*
    **  Now We have the variable List 
    **  The Scope of the search result 
    */
    if ( ( x == 1 ) && (pVM->pActiveMem == ring_vm_getglobalscope(pVM)) ) {
        x = RING_VARSCOPE_GLOBAL ;
    }
    else if ( (x == 1) && (pVM->pActiveMem != ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem))) ) {
        x = RING_VARSCOPE_NEWOBJSTATE ;
    }
    pVM->nVarScope = x ;
    RING_VM_SP_INC ;
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
        **  because a global variable may be a reference to local variable 
        **  And this case happens with setter/getter of the attributes using eval() 
        **  Here we avoid this change if the variable name is "Self" to return self by reference 
        */
        if ( strcmp(cStr,"self") != 0 ) {
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
                        if ( (ring_list_getsize(pList) == 4) && (pVM->nCallMethod == 0) ) {
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
        if ( pVM->nGetSetProperty == 1 ) {
            /* Avoid executing Setter/Getter when we use self.attribute and this.attribute */
            pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
            if ( pThis != NULL ) {
                if ( ring_list_getpointer(pThis,RING_VAR_VALUE ) == pVM->pGetSetObject ) {
                    return 1 ;
                }
            }
            ring_vm_oop_setget(pVM,pList2);
        }
        else if ( ( x == RING_VARSCOPE_OBJSTATE ) && ( ring_vm_oop_callmethodinsideclass(pVM) == 0 ) ) {
            /* Accessing Object Attribute Using { } */
            if ( ring_list_getsize(pVM->aBraceObjects) > 0 ) {
                pList = ring_list_getlist(pVM->aBraceObjects,ring_list_getsize(pVM->aBraceObjects));
                /* Pass braces { } for class init() method */
                if ( pVM->nCallClassInit ) {
                    /*
                    **  Here ring_vm_oop_callmethodinsideclass(pVM) will return 0 because of class init() calling 
                    **  This check can be done here or in ring_vm_oop_callmethodinsideclass() 
                    */
                    return 1 ;
                }
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
    if ( (ring_list_getsize(pVM->pMem) == 1) && (pVM->pActiveMem == ring_list_getlist(pVM->pMem,RING_MEMORY_GLOBALSCOPE)) ) {
        pVM->nVarScope = RING_VARSCOPE_GLOBAL ;
    }
    else if ( pVM->pActiveMem == ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem)) ) {
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
        pList = ring_list_new_gc(pVM->pRingState,0);
    }
    ring_list_addstring_gc(pVM->pRingState,pList,cStr);
    /* Determine Type based on Region */
    if ( pVM->nInClassRegion ) {
        ring_list_addint_gc(pVM->pRingState,pList,RING_VM_STRING);
    }
    else {
        ring_list_addint_gc(pVM->pRingState,pList,RING_VM_NULL);
    }
    ring_list_addstring_gc(pVM->pRingState,pList,"NULL");
    /* Pointer Type */
    ring_list_addint_gc(pVM->pRingState,pList,0);
    /* HashTable & Array */
    if ( pParent != NULL ) {
        /* Add Pointer to the HashTable */
        if ( pParent->pHashTable == NULL ) {
            pParent->pHashTable = ring_hashtable_new_gc(pVM->pRingState);
        }
        ring_hashtable_newpointer_gc(pVM->pRingState,pParent->pHashTable,cStr,pList);
    }
    return pList ;
}

void ring_vm_addnewnumbervar ( VM *pVM,const char *cStr,double x )
{
    List *pList  ;
    pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_NUMBER);
    ring_list_setdouble_gc(pVM->pRingState,pList,RING_VAR_VALUE,x);
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

void ring_vm_addnewpointervar ( VM *pVM,const char *cStr,void *x,int y )
{
    List *pList  ;
    pList = ring_vm_newvar2(pVM,cStr,pVM->pActiveMem);
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_POINTER);
    ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE,x);
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE,y);
    /* Reference Counting */
    ring_vm_gc_checknewreference(x,y,pList,RING_VAR_VALUE);
}

void ring_vm_newtempvar ( VM *pVM,const char *cStr, List *TempList )
{
    List *pList  ;
    pList = ring_vm_newvar2(pVM,cStr,TempList);
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
    if ( ring_list_getsize(pVM->pMem) < 2 ) {
        printf( RING_NOSCOPE ) ;
        exit(1);
    }
    ring_list_deleteitem_gc(pVM->pRingState,pVM->pMem,ring_list_getsize(pVM->pMem));
    pVM->pActiveMem = ring_list_getlist(pVM->pMem,ring_list_getsize(pVM->pMem));
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

void ring_vm_addstringpara ( VM *pVM,const char *cVar,const char  *cStr,int nStrSize )
{
    List *pList  ;
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->pActiveMem);
    ring_list_addstring_gc(pVM->pRingState,pList,cVar);
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_STRING);
    ring_list_addstring2_gc(pVM->pRingState,pList,cStr,nStrSize);
    ring_list_addint_gc(pVM->pRingState,pList,0);
    /* Add Pointer to the HashTable */
    if ( pVM->pActiveMem->pHashTable == NULL ) {
        pVM->pActiveMem->pHashTable = ring_hashtable_new_gc(pVM->pRingState);
    }
    ring_hashtable_newpointer_gc(pVM->pRingState,pVM->pActiveMem->pHashTable,cVar,pList);
}

void ring_vm_addnumberpara ( VM *pVM,const char *cVar,double nNumber )
{
    List *pList  ;
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->pActiveMem);
    ring_list_addstring_gc(pVM->pRingState,pList,cVar);
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_NUMBER);
    ring_list_adddouble_gc(pVM->pRingState,pList,nNumber);
    ring_list_addint_gc(pVM->pRingState,pList,0);
    /* Add Pointer to the HashTable */
    if ( pVM->pActiveMem->pHashTable == NULL ) {
        pVM->pActiveMem->pHashTable = ring_hashtable_new_gc(pVM->pRingState);
    }
    ring_hashtable_newpointer_gc(pVM->pRingState,pVM->pActiveMem->pHashTable,cVar,pList);
}

void ring_vm_addpointerpara ( VM *pVM,const char *cVar,void *pPointer,int nType )
{
    List *pList  ;
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->pActiveMem);
    ring_list_addstring_gc(pVM->pRingState,pList,cVar);
    ring_list_addint_gc(pVM->pRingState,pList,RING_VM_POINTER);
    ring_list_addpointer_gc(pVM->pRingState,pList,pPointer);
    ring_list_addint_gc(pVM->pRingState,pList,nType);
    /* Reference Counting */
    ring_vm_gc_checknewreference(pPointer,nType,pList,RING_VAR_VALUE);
    /* Add Pointer to the HashTable */
    if ( pVM->pActiveMem->pHashTable == NULL ) {
        pVM->pActiveMem->pHashTable = ring_hashtable_new_gc(pVM->pRingState);
    }
    ring_hashtable_newpointer_gc(pVM->pRingState,pVM->pActiveMem->pHashTable,cVar,pList);
}
/* Custom Global Scope */

void ring_vm_newglobalscope ( VM *pVM )
{
    pVM->pActiveMem = ring_list_newlist_gc(pVM->pRingState,pVM->aGlobalScopes);
    ring_list_addpointer_gc(pVM->pRingState,pVM->aActiveGlobalScopes,pVM->pActiveMem);
    ring_vm_addglobalvariables(pVM);
}

void ring_vm_endglobalscope ( VM *pVM )
{
    ring_list_deletelastitem_gc(pVM->pRingState,pVM->aActiveGlobalScopes);
    if ( ring_list_getsize(pVM->aActiveGlobalScopes) == 0 ) {
        pVM->pActiveMem = ring_list_getlist(pVM->pMem,1);
    }
    else {
        pVM->pActiveMem = (List *) ring_list_getpointer(pVM->aActiveGlobalScopes,ring_list_getsize(pVM->aActiveGlobalScopes));
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
        pList = ring_list_getlist(pVM->pMem,1);
    }
    else {
        pList = ring_list_getlist(pVM->aGlobalScopes,pVM->nCurrentGlobalScope);
    }
    return pList ;
}

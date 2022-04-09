/*
**  Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> 
**  pClassesMap ( cClass Name ,  iPC , cParentClass, aMethodsList , nFlagIsParentClassInformation 
**  pClassesMap ( cClass Name, Pointer to List that represent class inside a Package, Pointer to File 
**  pFunctionsMap ( Name, PC, FileName, Private Flag ) 
**  Packages List ( Package Name , Classes List ) 
**  Object ( is a list of two items , (1) Class Pointer  (2) Object Data  ) 
**  pVM->aScopeNewObj : (1) Previous scope (2) nListStart (3) pNestedLists (4) nSP 
**  pVM->pObjState  (  [ Pointer to Scope, Pointer to Methods , Pointer to Class, Optional True) 
**  The optional True used with LoadMethod so we can Know that we are inside class method during RT 
**  We don't check the True value, we just check that the size of the list is 4 
**  used in ring_vmfuncs , function ring_vm_loadfunc2() 
**  used in ring_vmvars , function ring_vm_findvar2() 
**  pBraceObject : The list that represent the object directly (not variable/list item) 
**  aBraceObjects ( pBraceObject, nSP, nListStart, pNestedLists) 
**  aSetProperty ( Object Pointer , Type (Variable/ListItem)  , Property Name, Property Variable , nBeforeEqual) 
*/
#include "ring.h"
/* Functions */

void ring_vm_oop_newobj ( VM *pVM )
{
    const char *cClassName,*cClassName2  ;
    int x,nLimit,nClassPC,nType,nCont  ;
    List *pList,*pList2,*pList3,*pList4,*pList5,*pVar,*pSelf, *pThis  ;
    Item *pItem  ;
    pList2 = NULL ;
    pVar = NULL ;
    pItem = NULL ;
    cClassName = RING_VM_IR_READC ;
    nLimit = ring_vm_oop_visibleclassescount(pVM);
    if ( nLimit > 0 ) {
        for ( x = 1 ; x <= nLimit ; x++ ) {
            pList = ring_vm_oop_visibleclassitem(pVM,x);
            cClassName2 = ring_list_getstring(pList,1);
            pList = ring_vm_oop_checkpointertoclassinpackage(pVM,pList);
            if ( pList == NULL ) {
                continue ;
            }
            nClassPC = ring_list_getint(pList,2);
            if ( strcmp(cClassName,cClassName2) == 0 ) {
                /* Check Assignment */
                nCont = 1 ;
                if ( RING_VM_STACK_ISPOINTER ) {
                    if ( pVM->pAssignment == RING_VM_STACK_READP ) {
                        nCont = 0 ;
                        /* Clear the Assignment Pointer */
                        pVM->pAssignment = NULL ;
                        ring_vm_cleansetpropertylist(pVM);
                    }
                }
                if ( pVM->nFuncExecute > 0 ) {
                    nCont = 1 ;
                    ring_vm_cleansetpropertylist(pVM);
                }
                if ( nCont == 1 ) {
                    /* Create the Temp Variable */
                    ring_vm_createtemplist(pVM);
                    pVar = (List *) RING_VM_STACK_READP ;
                    nType = RING_VM_STACK_OBJTYPE ;
                    ring_list_setint_gc(pVM->pRingState,pVar,RING_VAR_TYPE,RING_VM_LIST);
                    ring_list_setlist_gc(pVM->pRingState,pVar,RING_VAR_VALUE);
                    pList2 = ring_list_getlist(pVar,RING_VAR_VALUE);
                }
                else {
                    /* Prepare Object List */
                    if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
                        pVar = (List *) RING_VM_STACK_READP ;
                        ring_list_setint_gc(pVM->pRingState,pVar,RING_VAR_TYPE,RING_VM_LIST);
                        ring_list_setlist_gc(pVM->pRingState,pVar,RING_VAR_VALUE);
                        pList2 = ring_list_getlist(pVar,RING_VAR_VALUE);
                    }
                    else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
                        pItem = (Item *) RING_VM_STACK_READP ;
                        ring_item_settype_gc(pVM->pRingState,pItem,ITEMTYPE_LIST);
                        pVar = ring_item_getlist(pItem);
                        pList2 = pVar ;
                    }
                    nType = RING_VM_STACK_OBJTYPE ;
                }
                ring_list_deleteallitems_gc(pVM->pRingState,pList2);
                /* Push Class Package */
                ring_vm_oop_pushclasspackage(pVM,pList);
                /* Store the Class Pointer in the Object Data */
                ring_list_addpointer_gc(pVM->pRingState,pList2,pList);
                /* Create List for the Object State */
                pList3 = ring_list_newlist_gc(pVM->pRingState,pList2);
                /* Create Self variable in the state list */
                pSelf = ring_vm_newvar2(pVM,"self",pList3);
                ring_list_setint_gc(pVM->pRingState,pSelf,RING_VAR_TYPE,RING_VM_POINTER);
                if ( nType == RING_OBJTYPE_VARIABLE ) {
                    ring_list_setpointer_gc(pVM->pRingState,pSelf,RING_VAR_VALUE,pVar);
                }
                else if ( nType == RING_OBJTYPE_LISTITEM ) {
                    ring_list_setpointer_gc(pVM->pRingState,pSelf,RING_VAR_VALUE,pItem);
                }
                ring_list_setint_gc(pVM->pRingState,pSelf,RING_VAR_PVALUETYPE ,nType);
                /* Save the State */
                ring_vm_savestate3(pVM);
                /* Jump to Class INIT Method */
                ring_vm_blockflag2(pVM,pVM->nPC);
                /* Execute Parent Classes Init first */
                if ( strcmp(ring_list_getstring(pList,3),"") != 0 ) {
                    ring_vm_blockflag2(pVM,nClassPC);
                    ring_vm_oop_parentinit(pVM,pList);
                }
                else {
                    pVM->nPC = nClassPC ;
                }
                /* Set Object State as the Current Scope */
                pVM->pActiveMem = pList3 ;
                /* Prepare to Make Object State & Methods visible while executing the INIT method */
                pList5 = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
                ring_list_addpointer_gc(pVM->pRingState,pList5,pList3);
                ring_list_addpointer_gc(pVM->pRingState,pList5,NULL);
                ring_list_addpointer_gc(pVM->pRingState,pList5,pList);
                /* Create the Super Virtual Object */
                ring_vm_oop_newsuperobj(pVM,pList3,pList);
                /* Enable NULL variables (To be class attributes) */
                pVM->nInClassRegion++ ;
                /* Support using Braces to access the object state */
                pVM->pBraceObject = pList2 ;
                return ;
            }
        }
    }
    ring_vm_error2(pVM,RING_VM_ERROR_CLASSNOTFOUND,cClassName);
}

void ring_vm_oop_parentinit ( VM *pVM,List *pList )
{
    const char *cClassName,*cClassName2  ;
    int x,x2,nFound,nMark  ;
    List *pList2, *pClassesList  ;
    String *pString  ;
    /* Get the parent class name from the Class List Pointer */
    cClassName = ring_list_getstring(pList,3) ;
    /* Create List for Classes Pointers */
    pClassesList = ring_list_new_gc(pVM->pRingState,0);
    ring_list_addpointer_gc(pVM->pRingState,pClassesList,pList);
    while ( strcmp(cClassName,"") != 0 ) {
        /* Mark Packages Count */
        nMark = ring_list_getsize(pVM->aActivePackage);
        nFound = 0 ;
        for ( x = 1 ; x <= ring_vm_oop_visibleclassescount(pVM) ; x++ ) {
            pList2 = ring_vm_oop_visibleclassitem(pVM,x);
            cClassName2 = ring_list_getstring(pList2,1) ;
            pList2 = ring_vm_oop_checkpointertoclassinpackage(pVM,pList2);
            if ( pList2 == NULL ) {
                continue ;
            }
            if ( strcmp(cClassName,cClassName2) == 0 ) {
                /* Check that the parent class is not one of the subclasses */
                for ( x2 = 1 ; x2  <= ring_list_getsize(pClassesList) ; x2++ ) {
                    if ( ((List *) ring_list_getpointer(pClassesList,x2)) == pList2 ) {
                        pString = ring_string_new_gc(pVM->pRingState,"When creating class ");
                        ring_string_add_gc(pVM->pRingState,pString,ring_list_getstring(pList,1));
                        ring_string_add_gc(pVM->pRingState,pString," from class ");
                        ring_string_add_gc(pVM->pRingState,pString,cClassName);
                        ring_vm_error2(pVM,RING_VM_ERROR_PARENTCLASSLIKESUBCLASS,ring_string_get(pString));
                        ring_string_delete_gc(pVM->pRingState,pString);
                        /* Delete Classes Pointers List */
                        ring_list_delete_gc(pVM->pRingState,pClassesList);
                        return ;
                    }
                }
                ring_list_addpointer_gc(pVM->pRingState,pClassesList,pList2);
                /* Push Class Package */
                ring_vm_oop_pushclasspackage(pVM,pList2);
                cClassName = ring_list_getstring(pList2,3) ;
                if ( strcmp(cClassName,"") != 0 ) {
                    /* Add Class Init Method to be called */
                    ring_vm_blockflag2(pVM,ring_list_getint(pList2,2));
                }
                else {
                    pVM->nPC = ring_list_getint(pList2,2) ;
                }
                nFound = 1 ;
                break ;
            }
        }
        if ( nFound == 0 ) {
            /* Error Message */
            ring_vm_error2(pVM,RING_VM_ERROR_PARENTCLASSNOTFOUND,cClassName);
            break ;
        }
        /* Restore Mark */
        ring_vm_oop_deletepackagesafter(pVM,nMark);
        pList = pList2 ;
    }
    /* Delete Classes Pointers List */
    ring_list_delete_gc(pVM->pRingState,pClassesList);
}

void ring_vm_oop_newclass ( VM *pVM )
{
    List *pClass,*pList  ;
    int x  ;
    pClass = (List *) RING_VM_IR_READPVALUE(2) ;
    /* Find the Class Pointer using the Class Name */
    if ( pClass == NULL ) {
        for ( x = 1 ; x <= ring_list_getsize(pVM->pRingState->pRingClassesMap) ; x++ ) {
            pList = ring_list_getlist(pVM->pRingState->pRingClassesMap,x);
            if ( strcmp(ring_list_getstring(pList,1),RING_VM_IR_READCVALUE(1)) == 0 ) {
                if ( ring_list_getsize(pList) == 3 ) {
                    /* Here the class is stored inside a package - we have the class pointer (item 2) */
                    pClass = (List *) ring_list_getpointer(pList,2) ;
                }
                else {
                    pClass = pList ;
                }
                RING_VM_IR_READPVALUE(2) = (void *) pClass ;
                break ;
            }
        }
    }
    pClass = ring_vm_oop_checkpointertoclassinpackage(pVM,pClass);
    /* Make object methods visible while executing the Class Init method */
    pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState));
    ring_list_setpointer_gc(pVM->pRingState,pList,2,ring_list_getlist(pClass,4));
    /* Get Parent Classes Methods */
    ring_vm_oop_parentmethods(pVM,pClass);
    /* Attributes Scope is Public */
    pVM->nPrivateFlag = 0 ;
    /* Support using This in the class region */
    ring_vm_oop_setthethisvariableinclassregion(pVM);
}

void ring_vm_oop_setscope ( VM *pVM )
{
    /*
    **  This function called after creating new object and executing class init 
    **  Restore State 
    */
    ring_vm_restorestate3(pVM);
    /* After init methods */
    ring_vm_oop_aftercallmethod(pVM);
    /* POP Class Package */
    ring_vm_oop_popclasspackage(pVM);
}

int ring_vm_oop_isobject ( List *pList )
{
    if ( pList == NULL ) {
        return 0 ;
    }
    if ( ring_list_getsize(pList) != 2 ) {
        return 0 ;
    }
    if ( ring_list_ispointer(pList,1) == 0 ) {
        return 0 ;
    }
    if ( ring_list_islist(pList,2) == 0 ) {
        return 0 ;
    }
    return 1 ;
}

List * ring_vm_oop_getobj ( VM *pVM )
{
    List *pVar  ;
    Item *pItem  ;
    pVar = NULL ;
    /* Get Object Data */
    if ( ! RING_VM_STACK_ISPOINTER ) {
        ring_vm_error(pVM,RING_VM_ERROR_NOTOBJECT);
        return NULL ;
    }
    if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
        pVar = (List *) RING_VM_STACK_READP ;
        if ( ring_list_getint(pVar,RING_VAR_TYPE) == RING_VM_NULL ) {
            ring_vm_error2(pVM,RING_VM_ERROR_USINGNULLVARIABLE,ring_list_getstring(pVar,RING_VAR_NAME));
            return NULL ;
        }
        if ( ! ring_list_islist(pVar,RING_VAR_VALUE  ) ) {
            ring_vm_error(pVM,RING_VM_ERROR_NOTOBJECT);
            return NULL ;
        }
        pVar = ring_list_getlist(pVar,RING_VAR_VALUE);
    }
    else if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_LISTITEM ) {
        pItem = (Item *) RING_VM_STACK_READP ;
        pVar = ring_item_getlist(pItem);
    }
    if ( ring_vm_oop_isobject(pVar) == 0 ) {
        ring_vm_error(pVM,RING_VM_ERROR_NOTOBJECT);
        return NULL ;
    }
    RING_VM_STACK_POP ;
    return pVar ;
}

void ring_vm_oop_property ( VM *pVM )
{
    List *pVar,*pScope  ;
    /* Get Object Pointer Before being a list by getobj */
    if ( RING_VM_STACK_ISPOINTER ) {
        pVM->pGetSetObject = RING_VM_STACK_READP ;
        pVM->nGetSetObjType = RING_VM_STACK_OBJTYPE ;
    }
    /* Get Object Data */
    pVar = ring_vm_oop_getobj(pVM);
    if ( pVar == NULL ) {
        return ;
    }
    /* Get Object State */
    pScope = pVM->pActiveMem ;
    pVM->pActiveMem = ring_list_getlist(pVar,2);
    pVM->nGetSetProperty = 1 ;
    if ( ring_vm_findvar(pVM, RING_VM_IR_READC ) == 0 ) {
        /* Create the attribute if we are in the class region after the class name */
        if ( pVM->nInClassRegion ) {
            ring_vm_newvar(pVM, RING_VM_IR_READC);
            /* Support for Private Flag */
            ring_list_setint_gc(pVM->pRingState,(List *) RING_VM_STACK_READP,RING_VAR_PRIVATEFLAG,pVM->nPrivateFlag);
            RING_VM_STACK_POP ;
            ring_vm_findvar(pVM, RING_VM_IR_READC);
            pVM->pActiveMem = pScope ;
            pVM->nGetSetProperty = 0 ;
            pVM->pGetSetObject = NULL ;
            return ;
        }
        pVM->pActiveMem = pScope ;
        pVM->nGetSetProperty = 0 ;
        pVM->pGetSetObject = NULL ;
        if ( pVM->nActiveCatch == 0 ) {
            /*
            **  We check nActiveCatch because we may have error "accessing private attribute' 
            **  while we are using ring_vm_findvar 
            **  And we are using try catch done in the code 
            **  In this case we don't add another error message 
            **  So the try catch done can work as expected and avoid the need to another one 
            **  Error Message 
            */
            ring_vm_error2(pVM,RING_VM_ERROR_PROPERTYNOTFOUND,RING_VM_IR_READC);
        }
        return ;
    }
    pVM->pActiveMem = pScope ;
    pVM->nGetSetProperty = 0 ;
    pVM->pGetSetObject = NULL ;
}

void ring_vm_oop_loadmethod ( VM *pVM )
{
    List *pVar,*pList,*pList2,*pList3,*pSuper  ;
    int lResult  ;
    /* Check calling method related to Parent Class */
    pSuper = ring_vm_oop_getsuperobj(pVM);
    if ( pSuper != NULL ) {
        ring_vm_oop_loadsuperobjmethod(pVM,pSuper);
        /* Move list from pObjState to aBeforeObjState */
        ring_vm_oop_movetobeforeobjstate(pVM);
        return ;
    }
    /* Get Object Data */
    pVar = ring_vm_oop_getobj(pVM);
    if ( pVar == NULL ) {
        return ;
    }
    /* Get Object Class */
    pList = (List *) ring_list_getpointer(pVar,1);
    /* Push Class Package */
    ring_vm_oop_pushclasspackage(pVM,pList);
    /* Get Object State */
    pList2 = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
    ring_list_addpointer_gc(pVM->pRingState,pList2,ring_list_getlist(pVar,2));
    /* Get Class Methods */
    pList3 = ring_list_getlist(pList,4);
    ring_list_addpointer_gc(pVM->pRingState,pList2,pList3);
    /* Add Pointer to Class */
    ring_list_addpointer_gc(pVM->pRingState,pList2,pList);
    /* Add Logical Value (True) , That we are inside the class method */
    ring_list_addint_gc(pVM->pRingState,pList2,1);
    /* Get Parent Classes Methods */
    ring_vm_oop_parentmethods(pVM,pList);
    /* Call Method */
    pVar = pVM->pFunctionsMap ;
    pVM->pFunctionsMap = pList3 ;
    pVM->nCallMethod = 1 ;
    lResult = ring_vm_loadfunc(pVM);
    pVM->nCallMethod = 0 ;
    pVM->pFunctionsMap = pVar ;
    /* Move list from pObjState to aBeforeObjState */
    if ( lResult ) {
        ring_vm_oop_movetobeforeobjstate(pVM);
    }
}

void ring_vm_oop_movetobeforeobjstate ( VM *pVM )
{
    List *pList, *pList2  ;
    if ( pVM->nActiveCatch == 1 ) {
        /* Try/Catch restore aObjState and may become empty */
        return ;
    }
    /* Move list from pObjState to aBeforeObjState */
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->aBeforeObjState);
    pList2 = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState));
    ring_list_copy_gc(pVM->pRingState,pList,pList2);
    ring_list_deleteitem_gc(pVM->pRingState,pVM->pObjState,ring_list_getsize(pVM->pObjState));
}

void ring_vm_oop_parentmethods ( VM *pVM,List *pList )
{
    const char *cClassName,*cClassName2  ;
    int x,nFound,nMark  ;
    List *pList3,*pList4  ;
    pList3 = ring_list_getlist(pList,4);
    if ( ring_list_getint(pList,5) == 0 ) {
        ring_list_setint_gc(pVM->pRingState,pList,5,1);
        cClassName = ring_list_getstring(pList,3) ;
        /* Mark Packages Count */
        nMark = ring_list_getsize(pVM->aActivePackage);
        while ( strcmp(cClassName,"") != 0 ) {
            /* Push Class Package */
            ring_vm_oop_pushclasspackage(pVM,pList);
            nFound = 0 ;
            for ( x = 1 ; x <= ring_vm_oop_visibleclassescount(pVM) ; x++ ) {
                pList4 = ring_vm_oop_visibleclassitem(pVM,x);
                cClassName2 = ring_list_getstring(pList4,1) ;
                /* Prev. Step must be before Next. step - We check the name include the package */
                pList4 = ring_vm_oop_checkpointertoclassinpackage(pVM,pList4);
                if ( pList4 == NULL ) {
                    continue ;
                }
                if ( strcmp(cClassName,cClassName2) == 0 ) {
                    /* Push Class Package */
                    ring_vm_oop_pushclasspackage(pVM,pList4);
                    ring_list_copy_gc(pVM->pRingState,pList3,ring_list_getlist(pList4,4));
                    cClassName = ring_list_getstring(pList4,3) ;
                    nFound = 1 ;
                    break ;
                }
            }
            if ( nFound == 0 ) {
                ring_vm_error(pVM,RING_VM_ERROR_PARENTCLASSNOTFOUND);
                break ;
            }
            /* Exit when the parent class already contains it's parent classes data */
            if ( ring_list_getint(pList,5) == 1 ) {
                break ;
            }
        }
        /* Restore Mark */
        ring_vm_oop_deletepackagesafter(pVM,nMark);
    }
}

void ring_vm_oop_aftercallmethod ( VM *pVM )
{
    if ( ring_list_getsize(pVM->pObjState) != 0 ) {
        ring_list_deleteitem_gc(pVM->pRingState,pVM->pObjState,ring_list_getsize(pVM->pObjState));
    }
    /* POP Class Package */
    ring_vm_oop_popclasspackage(pVM);
}

void ring_vm_oop_printobj ( VM *pVM,List *pList )
{
    List *pList2,*pList3  ;
    int x  ;
    char cStr[100]  ;
    pList = ring_list_getlist(pList,2);
    for ( x = 3 ; x <= ring_list_getsize(pList) ; x++ ) {
        pList2 = ring_list_getlist(pList,x);
        printf( "%s: " , ring_list_getstring(pList2,1) ) ;
        if ( ring_list_isstring(pList2,3) ) {
            printf( "%s\n" , ring_list_getstring(pList2,3) ) ;
        }
        else if ( ring_list_isnumber(pList2,3) ) {
            if ( pVM != NULL ) {
                ring_vm_numtostring(pVM,ring_list_getdouble(pList2,3),cStr);
                printf( "%s\n" ,cStr ) ;
            }
            else {
                printf( "%f\n" , ring_list_getdouble(pList2,3) ) ;
            }
        }
        else if ( ring_list_islist(pList2,3) ) {
            pList3 = ring_list_getlist(pList2,3) ;
            if ( ring_vm_oop_isobject(pList3) ) {
                printf( "Object...\n" ) ;
            }
            else {
                printf( "[This Attribute Contains A List]\n" ) ;
            }
        }
    }
}

void ring_vm_oop_setbraceobj ( VM *pVM,List *pList )
{
    /* Support using { } to access object after object name */
    if ( ring_vm_oop_isobject(pList) ) {
        pVM->pBraceObject = pList ;
    }
}

void ring_vm_oop_bracestart ( VM *pVM )
{
    List *pList,*pClass  ;
    /* Check Error */
    if ( pVM->pBraceObject == NULL ) {
        ring_vm_error(pVM,RING_VM_ERROR_BRACEWITHOUTOBJECT);
        return ;
    }
    /* Prepare to Access Object State */
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
    /* Store Pointer to Object State */
    ring_list_addpointer_gc(pVM->pRingState,pList,ring_list_getlist(pVM->pBraceObject,2));
    /* Store Object Class Methods */
    pClass = (List *) ring_list_getpointer(pVM->pBraceObject,1) ;
    ring_list_addpointer_gc(pVM->pRingState,pList,ring_list_getlist(pClass,4));
    /* Store Class Pointer */
    ring_list_addpointer_gc(pVM->pRingState,pList,pClass);
    /* Add Brace Object & Stack Pointer to List */
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->aBraceObjects);
    ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pBraceObject);
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nSP);
    /* Store List information to allow using braces from list item and creating lists from that brace */
    ring_list_addint_gc(pVM->pRingState,pList,pVM->nListStart);
    ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pNestedLists);
    pVM->nListStart = 0 ;
    pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,0);
    pVM->pBraceObject = NULL ;
    pVM->nInsideBraceFlag = 1 ;
}

void ring_vm_oop_braceend ( VM *pVM )
{
    List *pList  ;
    /* Restore List Status */
    pList = ring_list_getlist(pVM->aBraceObjects,ring_list_getsize(pVM->aBraceObjects)) ;
    pVM->nListStart = ring_list_getint(pList,3) ;
    if ( pVM->pNestedLists != ring_list_getpointer(pList,4) ) {
        pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState,pVM->pNestedLists);
        pVM->pNestedLists = (List *) ring_list_getpointer(pList,4) ;
    }
    /* Restore Stack Status */
    pVM->nSP = ring_list_getint(pList,2) ;
    ring_list_deleteitem_gc(pVM->pRingState,pVM->aBraceObjects,ring_list_getsize(pVM->aBraceObjects));
    ring_list_deleteitem_gc(pVM->pRingState,pVM->pObjState,ring_list_getsize(pVM->pObjState));
    if ( ring_list_getsize(pVM->aBraceObjects) > 0 ) {
        pVM->pBraceObject = ring_list_getlist(pVM->aBraceObjects,ring_list_getsize(pVM->aBraceObjects)) ;
        pVM->pBraceObject = (List *) ring_list_getpointer(pVM->pBraceObject,1) ;
        pVM->nInsideBraceFlag = 1 ;
    }
    else {
        pVM->nInsideBraceFlag = 0 ;
    }
}

void ring_vm_oop_bracestack ( VM *pVM )
{
    pVM->nSP = ring_list_getint(ring_list_getlist(pVM->aBraceObjects,ring_list_getsize(pVM->aBraceObjects)),2) ;
    if ( pVM->nFuncSP > pVM->nSP ) {
        /*
        **  This fixes a problem when we use oObject {  eval(code) } return cString 
        **  Where pVM->nSP maybe less than pVM->nFuncSP while we are inside function 
        */
        if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
            pVM->nSP = pVM->nFuncSP ;
        }
    }
}

void ring_vm_oop_newsuperobj ( VM *pVM,List *pState,List *pClass )
{
    List *pSuper,*pSuper2,*pMethods,*pList  ;
    const char *cParentClassName,*cClassName  ;
    int x  ;
    pSuper = ring_vm_newvar2(pVM,"super",pState);
    ring_list_setint_gc(pVM->pRingState,pSuper,RING_VAR_TYPE,RING_VM_LIST);
    ring_list_setlist_gc(pVM->pRingState,pSuper,RING_VAR_VALUE);
    pSuper2 = ring_list_getlist(pSuper,RING_VAR_VALUE);
    pMethods = ring_list_getlist(pClass,4);
    ring_list_addpointer_gc(pVM->pRingState,pSuper2,pMethods);
    cParentClassName = ring_list_getstring(pClass,3) ;
    while ( strcmp(cParentClassName,"") != 0 ) {
        for ( x = 1 ; x <= ring_vm_oop_visibleclassescount(pVM) ; x++ ) {
            pList = ring_vm_oop_visibleclassitem(pVM,x);
            cClassName = ring_list_getstring(pList,1) ;
            pList = ring_vm_oop_checkpointertoclassinpackage(pVM,pList);
            if ( pList == NULL ) {
                continue ;
            }
            if ( strcmp(cClassName,cParentClassName) == 0 ) {
                cParentClassName = ring_list_getstring(pList,3) ;
                pMethods = ring_list_getlist(pList,4);
                ring_list_addpointer_gc(pVM->pRingState,pSuper2,pMethods);
                break ;
            }
        }
    }
}

List * ring_vm_oop_getsuperobj ( VM *pVM )
{
    List *pVar  ;
    if ( ( RING_VM_STACK_ISPOINTER ) && ( ring_list_getsize(pVM->pObjState) != 0    ) ) {
        if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
            pVar = (List *) RING_VM_STACK_READP ;
            if ( (ring_list_islist(pVar,3)) && (strcmp(ring_list_getstring(pVar,1),"super") == 0 ) ) {
                pVar = ring_list_getlist(pVar,3);
                RING_VM_STACK_POP ;
                return pVar ;
            }
        }
    }
    return NULL ;
}

void ring_vm_oop_loadsuperobjmethod ( VM *pVM,List *pSuper )
{
    int x  ;
    List *pState,*pMethods,*pClass,*pVar,*pList  ;
    pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState));
    pState = ring_list_getlist(pList,RING_OBJSTATE_SCOPE);
    pMethods = ring_list_getlist(pList,RING_OBJSTATE_METHODS);
    pClass = ring_list_getlist(pList,RING_OBJSTATE_CLASS);
    for ( x = 1 ; x <= ring_list_getsize(pSuper) ; x++ ) {
        if ( ring_list_getpointer(pSuper,x) == pMethods ) {
            if ( (x+1)  <= ring_list_getsize(pSuper) ) {
                pMethods = (List *) ring_list_getpointer(pSuper,(x+1));
                break ;
            }
            else {
                ring_vm_error(pVM,RING_VM_ERROR_SUPERCLASSNOTFOUND);
                return ;
            }
        }
    }
    pList = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
    ring_list_addpointer_gc(pVM->pRingState,pList,pState);
    ring_list_addpointer_gc(pVM->pRingState,pList,pMethods);
    ring_list_addpointer_gc(pVM->pRingState,pList,pClass);
    /* Call Method */
    pVar = pVM->pFunctionsMap ;
    pVM->pFunctionsMap = pMethods ;
    pVM->nCallMethod = 1 ;
    ring_vm_loadfunc(pVM);
    pVM->nCallMethod = 0 ;
    pVM->pFunctionsMap = pVar ;
}

void ring_vm_oop_import ( VM *pVM )
{
    ring_vm_oop_import2(pVM,RING_VM_IR_READC);
}

void ring_vm_oop_import2 ( VM *pVM,const char *cPackage )
{
    int x  ;
    List *pList,*pList2  ;
    const char *cPackage2  ;
    for ( x = 1 ; x <= ring_list_getsize(pVM->pPackagesMap) ; x++ ) {
        pList = ring_list_getlist(pVM->pPackagesMap,x);
        cPackage2 = ring_list_getstring(pList,1);
        if ( strcmp(cPackage, cPackage2) == 0 ) {
            /* Get Package Classes */
            pList2 = ring_list_getlist(pList,2);
            ring_vm_oop_import3(pVM,pList2);
            /* Set Active Package Name */
            ring_string_set_gc(pVM->pRingState,pVM->pPackageName,cPackage);
            return ;
        }
    }
    /* Error Message */
    ring_vm_error2(pVM,RING_VM_ERROR_PACKAGENOTFOUND,cPackage);
}

void ring_vm_oop_import3 ( VM *pVM,List *pList )
{
    int x  ;
    List *pList2, *pList3  ;
    /* Import Package Classes */
    for ( x = 1 ; x <= ring_list_getsize(pList) ; x++ ) {
        pList2 = ring_list_getlist(pList,x);
        pList3 = ring_list_newlist_gc(pVM->pRingState,pVM->pClassesMap);
        ring_list_addstring_gc(pVM->pRingState,pList3,ring_list_getstring(pList2,1));
        ring_list_addpointer_gc(pVM->pRingState,pList3,pList2);
        ring_list_addpointer_gc(pVM->pRingState,pList3,pVM->cFileName);
    }
}

List * ring_vm_oop_checkpointertoclassinpackage ( VM *pVM,List *pList )
{
    if ( ring_list_getsize(pList) == 3 ) {
        if ( ring_list_getpointer(pList,3) != NULL ) {
            if ( strcmp((char *) ring_list_getpointer(pList,3),pVM->cFileName) != 0 ) {
                return NULL ;
            }
        }
        return (List *) ring_list_getpointer(pList,2) ;
    }
    return pList ;
}

int ring_vm_oop_visibleclassescount ( VM *pVM )
{
    List *pList  ;
    if ( ring_list_getsize(pVM->aActivePackage) > 0 ) {
        pList = (List *) ring_list_getpointer(pVM->aActivePackage,ring_list_getsize(pVM->aActivePackage)) ;
        pList = ring_list_getlist(pList,RING_CLASSESLIST) ;
        return ring_list_getsize(pVM->pClassesMap) + ring_list_getsize(pList) ;
    }
    return ring_list_getsize(pVM->pClassesMap) ;
}

List * ring_vm_oop_visibleclassitem ( VM *pVM,int x )
{
    List *pList  ;
    if ( x <= ring_list_getsize(pVM->pClassesMap) ) {
        return ring_list_getlist(pVM->pClassesMap,x) ;
    }
    pList = (List *) ring_list_getpointer(pVM->aActivePackage,ring_list_getsize(pVM->aActivePackage)) ;
    pList = ring_list_getlist(pList,RING_CLASSESLIST) ;
    pList = ring_list_getlist(pList,x-ring_list_getsize(pVM->pClassesMap)) ;
    return pList ;
}

void ring_vm_oop_pushclasspackage ( VM *pVM,List *pList )
{
    List *pList2  ;
    pList2 = ring_list_getlist(pList,RING_CLASSMAP_POINTERTOPACKAGE) ;
    if ( pList2 != NULL ) {
        ring_list_addpointer_gc(pVM->pRingState,pVM->aActivePackage,pList2);
    }
}

void ring_vm_oop_popclasspackage ( VM *pVM )
{
    if ( ring_list_getsize(pVM->aActivePackage) > 0 ) {
        ring_list_deleteitem_gc(pVM->pRingState,pVM->aActivePackage,ring_list_getsize(pVM->aActivePackage));
    }
}

void ring_vm_oop_deletepackagesafter ( VM *pVM,int x )
{
    int t  ;
    if ( x <= ring_list_getsize(pVM->aActivePackage) ) {
        for ( t = ring_list_getsize(pVM->aActivePackage) ; t > x ; t-- ) {
            ring_list_deleteitem_gc(pVM->pRingState,pVM->aActivePackage,t);
        }
    }
}

int ring_vm_oop_callmethodinsideclass ( VM *pVM )
{
    List *pList, *pList2  ;
    int x  ;
    /*
    **  This function tell us if we are inside Class method during runtime or not 
    **  pObjState is used when we Call Method or We use braces { } to access object 
    **  if the size of pObjState List is 4 , then it's class method execution not brace 
    **  Braces can be used before calling class methods 
    **  Also braces can be used inside class methods to access objects 
    **  Inside class method you can access any object using { } , you can access the self object 
    **  Braces & Methods calls can be nested 
    **  Check Calling from function 
    */
    if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
        for ( x = ring_list_getsize(pVM->pFuncCallList) ; x >= 1 ; x-- ) {
            pList = ring_list_getlist(pVM->pFuncCallList,x);
            /* Be sure that the function is already called using ICO_CALL */
            if ( ring_list_getsize(pList) >= RING_FUNCCL_CALLERPC ) {
                if ( ring_list_getint(pList,RING_FUNCCL_METHODORFUNC) == 0 ) {
                    return 0 ;
                }
                else {
                    break ;
                }
            }
        }
    }
    /*
    **  pObjState can know about method call if it's called using callmethod 
    **  Or it's called from inside { } as function 
    **  Return 1 if last item is a method 
    */
    if ( ring_list_getsize(pVM->pObjState) >= 1 ) {
        pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)) ;
        if ( (ring_list_getsize(pList) == 4) && (pVM->nCallMethod == 0) ) {
            return 1 ;
        }
    }
    /* Check using braces { } to access object from a method in the Class */
    if ( ring_list_getsize(pVM->pObjState) >= 2 ) {
        pList = (List *) ring_list_getpointer(ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)),RING_OBJSTATE_CLASS);
        for ( x = ring_list_getsize(pVM->pObjState) - 1 ; x >= 1 ; x-- ) {
            pList2 = ring_list_getlist(pVM->pObjState,x);
            if ( ring_list_getsize(pList2) == 4 ) {
                pList2 = (List *) ring_list_getpointer(pList2,RING_OBJSTATE_CLASS);
                if ( pList == pList2 ) {
                    return 1 ;
                }
                else {
                    break ;
                }
            }
        }
    }
    return 0 ;
}

void ring_vm_oop_setget ( VM *pVM,List *pVar )
{
    List *pList, *pList2  ;
    Item *pItem, *pItem2  ;
    String *pString, *pString2  ;
    /* Create String */
    pString = ring_string_new_gc(pVM->pRingState,"if ismethod(ring_gettemp_var,'get");
    ring_string_add_gc(pVM->pRingState,pString,ring_list_getstring(pVar,1));
    ring_string_add_gc(pVM->pRingState,pString,"')\nreturn ring_gettemp_var.'get");
    ring_string_add_gc(pVM->pRingState,pString,ring_list_getstring(pVar,1));
    ring_string_add_gc(pVM->pRingState,pString,"'() ok");
    /* Set Variable ring_gettemp_var  , Number 5 in Public Memory */
    pList = ring_list_getlist(ring_vm_getglobalscope(pVM),5) ;
    ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE,pVM->pGetSetObject);
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE ,pVM->nGetSetObjType);
    /* Check Setter & Getter for Public Attributes */
    RING_VM_IR_LOAD ;
    if ( RING_VM_IR_OPCODE != ICO_ASSIGNMENTPOINTER ) {
        RING_VM_IR_UNLOAD ;
        /*
        **  Get Property 
        **  Check to do a Stack POP for the Attribute List 
        */
        pString2 = ring_string_new_gc(pVM->pRingState,"get");
        ring_string_add_gc(pVM->pRingState,pString2,ring_list_getstring(pVar,1));
        /* Check Type */
        pList2 = NULL ;
        if ( pVM->nGetSetObjType == RING_OBJTYPE_VARIABLE ) {
            pList2 = ring_list_getlist((List *) (pVM->pGetSetObject),RING_VAR_VALUE ) ;
        }
        else if ( pVM->nGetSetObjType == RING_OBJTYPE_LISTITEM ) {
            pItem2 = (Item *) pVM->pGetSetObject ;
            pList2 = ring_item_getlist(pItem2) ;
        }
        if ( ring_vm_oop_ismethod(pVM,pList2,ring_string_get(pString2)) ) {
            RING_VM_STACK_POP ;
            if ( pVM->nGetSetProperty == 0 ) {
                /* For Better Performance : Don't Eval() when we call Getter Method from Braces */
                ring_vm_loadfunc2(pVM,ring_string_get(pString2),0);
                ring_vm_call2(pVM);
                /* Prepare the Object State */
                pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)) ;
                pList2 = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
                ring_list_copy_gc(pVM->pRingState,pList2,pList);
                /* Add Logical Value (True) , That we are inside the class method */
                ring_list_addint_gc(pVM->pRingState,pList2,1);
                /* Push Class Package */
                pList = (List *) ring_list_getpointer(pList2,RING_OBJSTATE_CLASS);
                ring_vm_oop_pushclasspackage(pVM,pList);
                ring_string_delete_gc(pVM->pRingState,pString2);
                ring_string_delete_gc(pVM->pRingState,pString);
                return ;
            }
        }
        ring_string_delete_gc(pVM->pRingState,pString2);
        if ( RING_VM_IR_READIVALUE(2)  == 0 ) {
            pItem = RING_VM_IR_ITEM(2) ;
            pVM->nEvalCalledFromRingCode = 0 ;
            if ( pVM->lInsideEval ) {
                pVM->nRetEvalDontDelete = 1 ;
            }
            ring_vm_eval(pVM,ring_string_get(pString));
            /* We don't use RING_VM_IR because Eval reallocation change mem. locations */
            ring_item_setint_gc(pVM->pRingState,pItem,pVM->nPC);
        }
        else {
            ring_vm_blockflag2(pVM,pVM->nPC);
            pVM->nPC = RING_VM_IR_READIVALUE(2) ;
        }
    }
    else {
        RING_VM_IR_UNLOAD ;
        /*
        **  Set Property 
        **  Delete All Items to avoid a memory leak in real time applications 
        */
        ring_list_deleteallitems_gc(pVM->pRingState,pVM->aSetProperty);
        pList = ring_list_newlist_gc(pVM->pRingState,pVM->aSetProperty);
        /* Add object pointer & Type */
        ring_list_addpointer_gc(pVM->pRingState,pList,pVM->pGetSetObject);
        ring_list_addint_gc(pVM->pRingState,pList,pVM->nGetSetObjType);
        /* Add property name */
        ring_list_addstring_gc(pVM->pRingState,pList,ring_list_getstring(pVar,1));
        /* Property Variable */
        ring_list_addpointer_gc(pVM->pRingState,pList,pVar);
        /*
        **  Check if we don't have the Setter Method 
        **  We do this to enable the Assignment Pointer and Disable Set Property for Lists and Objects 
        */
        pString2 = ring_string_new_gc(pVM->pRingState,"set");
        ring_string_add_gc(pVM->pRingState,pString2,ring_list_getstring(pVar,1));
        /* Check Type */
        pList2 = NULL ;
        if ( pVM->nGetSetObjType == RING_OBJTYPE_VARIABLE ) {
            pList2 = ring_list_getlist((List *) (pVM->pGetSetObject),RING_VAR_VALUE ) ;
        }
        else if ( pVM->nGetSetObjType == RING_OBJTYPE_LISTITEM ) {
            pItem2 = (Item *) pVM->pGetSetObject ;
            pList2 = ring_item_getlist(pItem2) ;
        }
        pVM->lNoSetterMethod = 0 ;
        if ( ! ring_vm_oop_ismethod(pVM,pList2,ring_string_get(pString2)) ) {
            pVM->lNoSetterMethod = 1 ;
        }
        ring_string_delete_gc(pVM->pRingState,pString2);
    }
    /* Delete String */
    ring_string_delete_gc(pVM->pRingState,pString);
}

void ring_vm_oop_setproperty ( VM *pVM )
{
    List *pList, *pList2  ;
    Item *pItem,*pItem2  ;
    String *pString  ;
    /* If we don't have a setter method and we have a new list or new object */
    if ( pVM->lNoSetterMethod == 2 ) {
        pVM->lNoSetterMethod = 0 ;
        return ;
    }
    /* To Access Property Data */
    if ( ring_list_getsize(pVM->aSetProperty) < 1 ) {
        /* This case happens when using This.Attribute inside nested braces in a class method */
        ring_vm_assignment(pVM);
        return ;
    }
    pList = ring_list_getlist(pVM->aSetProperty,ring_list_getsize(pVM->aSetProperty));
    /* Add Before Equal Flag */
    if ( ring_list_getsize(pList) == 4 ) {
        ring_list_addint_gc(pVM->pRingState,pList,pVM->nBeforeEqual);
    }
    /* Before (First Time) */
    if ( RING_VM_IR_READIVALUE(1) == 0 ) {
        pItem2 = RING_VM_IR_ITEM(1) ;
        /* Set Variable ring_gettemp_var  , Number 5 in Public Memory */
        pList2 = ring_list_getlist(ring_vm_getglobalscope(pVM),5) ;
        ring_list_setpointer_gc(pVM->pRingState,pList2,RING_VAR_VALUE,ring_list_getpointer(pList,1));
        ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_PVALUETYPE,ring_list_getint(pList,2));
        /* Set Variable ring_settemp_var  , Number 7 in Public Memory */
        pList2 = ring_list_getlist(ring_vm_getglobalscope(pVM),7) ;
        if ( RING_VM_STACK_ISNUMBER ) {
            ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_TYPE,RING_VM_NUMBER);
            ring_list_setdouble_gc(pVM->pRingState,pList2,RING_VAR_VALUE,RING_VM_STACK_READN);
            ring_list_adddouble_gc(pVM->pRingState,pList,RING_VM_STACK_READN);
        }
        else if ( RING_VM_STACK_ISSTRING ) {
            ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_TYPE,RING_VM_STRING);
            ring_list_setstring2_gc(pVM->pRingState,pList2,RING_VAR_VALUE,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
            ring_list_addstring2_gc(pVM->pRingState,pList,RING_VM_STACK_READC,RING_VM_STACK_STRINGSIZE);
        }
        else if ( RING_VM_STACK_ISPOINTER ) {
            ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_TYPE,RING_VM_POINTER);
            ring_list_setpointer_gc(pVM->pRingState,pList2,RING_VAR_VALUE,RING_VM_STACK_READP);
            ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_PVALUETYPE ,RING_VM_STACK_OBJTYPE);
            ring_list_addpointer_gc(pVM->pRingState,pList,RING_VM_STACK_READP);
            ring_list_addint_gc(pVM->pRingState,pList,RING_VM_STACK_OBJTYPE);
        }
        /* Set Variable ring_tempflag_var , Number 8 in Public Memory */
        pList2 = ring_list_getlist(ring_vm_getglobalscope(pVM),8) ;
        ring_list_setdouble_gc(pVM->pRingState,pList2,RING_VAR_VALUE,0.0);
        /* Execute the same instruction again (next time the part "After (Second Time)" will run ) */
        pVM->nPC-- ;
        if ( RING_VM_IR_READIVALUE(2)  == 0 ) {
            /* Create String */
            pString = ring_string_new_gc(pVM->pRingState,"if ismethod(ring_gettemp_var,'set");
            ring_string_add_gc(pVM->pRingState,pString,ring_list_getstring(pList,3));
            ring_string_add_gc(pVM->pRingState,pString,"')\nring_gettemp_var.'set");
            ring_string_add_gc(pVM->pRingState,pString,ring_list_getstring(pList,3));
            ring_string_add_gc(pVM->pRingState,pString,"'(ring_settemp_var)\nring_tempflag_var = 0\nelse\nring_tempflag_var = 1\nok");
            /* Eval the string */
            pItem = RING_VM_IR_ITEM(2) ;
            pVM->nEvalCalledFromRingCode = 0 ;
            if ( pVM->lInsideEval ) {
                pVM->nRetEvalDontDelete = 1 ;
            }
            ring_vm_eval(pVM,ring_string_get(pString));
            /* We don't use RING_VM_IR because Eval reallocation change mem. locations */
            ring_item_setint_gc(pVM->pRingState,pItem,pVM->nPC);
            /* Delete String */
            ring_string_delete_gc(pVM->pRingState,pString);
        }
        else {
            ring_vm_blockflag2(pVM,pVM->nPC);
            pVM->nPC = RING_VM_IR_READIVALUE(2) ;
        }
        /* Set Before/After SetProperty Flag To After */
        ring_item_setint_gc(pVM->pRingState,pItem2,1);
    }
    /* After (Second Time) */
    else {
        /* Set Before/After SetProperty Flag to Before */
        RING_VM_IR_READIVALUE(1) = 0 ;
        /* Get Variable ring_tempflag_var */
        pList2 = ring_list_getlist(ring_vm_getglobalscope(pVM),8) ;
        if ( ring_list_getdouble(pList2,3) == 1.0 ) {
            /*
            **  The set method is not found!, we have to do the assignment operation 
            **  Push Variable Then Push Value then Assignment 
            */
            RING_VM_STACK_PUSHPVALUE(ring_list_getpointer(pList,4));
            RING_VM_STACK_OBJTYPE = RING_OBJTYPE_VARIABLE ;
            /* Restore Before Equal Flag */
            pVM->nBeforeEqual = ring_list_getint(pList,5) ;
            /* Push Value */
            if ( ring_list_isdouble(pList,6) ) {
                RING_VM_STACK_PUSHNVALUE(ring_list_getdouble(pList,6));
            }
            else if ( ring_list_isstring(pList,6) ) {
                RING_VM_STACK_PUSHCVALUE2(ring_list_getstring(pList,6),ring_list_getstringsize(pList,6));
            }
            else if ( ring_list_ispointer(pList,6) ) {
                RING_VM_STACK_PUSHPVALUE(ring_list_getpointer(pList,6));
                RING_VM_STACK_OBJTYPE = ring_list_getint(pList,7) ;
            }
            ring_vm_assignment(pVM);
        }
        ring_list_deleteitem_gc(pVM->pRingState,pVM->aSetProperty,ring_list_getsize(pVM->aSetProperty));
    }
}

List * ring_vm_oop_objvarfromobjlist ( List *pList )
{
    int nType  ;
    Item *pItem  ;
    /* Get Object State List */
    pList = ring_list_getlist(pList,2);
    /* Get Self Attribute List */
    pList = ring_list_getlist(pList,1);
    /* Get Object Pointer from Self Attribute List */
    nType = ring_list_getint(pList,4) ;
    if ( nType == RING_OBJTYPE_VARIABLE ) {
        pList = (List *) ring_list_getpointer(pList,3);
    }
    else if ( nType == RING_OBJTYPE_LISTITEM ) {
        pItem = (Item *) ring_list_getpointer(pList,3);
        pList = (List *) ring_item_getlist(pItem) ;
    }
    return pList ;
}

int ring_vm_oop_objtypefromobjlist ( List *pList )
{
    int nType  ;
    /* Get Object State List */
    pList = ring_list_getlist(pList,2);
    /* Get Self Attribute List */
    pList = ring_list_getlist(pList,1);
    /* Get Object Type from Self Attribute List */
    nType = ring_list_getint(pList,4) ;
    return nType ;
}

Item * ring_vm_oop_objitemfromobjlist ( List *pList )
{
    Item *pItem  ;
    /* Get Object State List */
    pList = ring_list_getlist(pList,2);
    /* Get Self Attribute List */
    pList = ring_list_getlist(pList,1);
    /* Get Object Pointer from Self Attribute List */
    pItem = (Item *) ring_list_getpointer(pList,3);
    return pItem ;
}

void ring_vm_oop_operatoroverloading ( VM *pVM,List *pObj,const char *cStr1,int nType,const char *cStr2,double nNum1,void *pPointer,int nPointerType )
{
    List *pList2  ;
    Item *pItem  ;
    String *pString  ;
    int nObjType  ;
    nObjType = ring_vm_oop_objtypefromobjlist(pObj);
    /* Set Variable ring_gettemp_var  , Number 5 in Public Memory */
    pList2 = ring_list_getlist(ring_vm_getglobalscope(pVM),5) ;
    if ( nObjType == RING_OBJTYPE_VARIABLE ) {
        pObj = ring_vm_oop_objvarfromobjlist(pObj);
        ring_list_setpointer_gc(pVM->pRingState,pList2,RING_VAR_VALUE,pObj);
    }
    else if ( nObjType == RING_OBJTYPE_LISTITEM ) {
        pItem = ring_vm_oop_objitemfromobjlist(pObj);
        ring_list_setpointer_gc(pVM->pRingState,pList2,RING_VAR_VALUE,pItem);
    }
    ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_PVALUETYPE,nObjType);
    /* Set Variable ring_settemp_var  , Number 7 in Public Memory */
    pList2 = ring_list_getlist(ring_vm_getglobalscope(pVM),7) ;
    if ( nType == RING_OOPARA_STRING ) {
        ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_TYPE,RING_VM_STRING);
        ring_list_setstring_gc(pVM->pRingState,pList2,RING_VAR_VALUE,cStr2);
    }
    else if ( nType == RING_OOPARA_NUMBER ) {
        ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_TYPE,RING_VM_NUMBER);
        ring_list_setdouble_gc(pVM->pRingState,pList2,RING_VAR_VALUE,nNum1);
    }
    else if ( nType == RING_OOPARA_POINTER ) {
        ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_TYPE,RING_VM_POINTER);
        ring_list_setpointer_gc(pVM->pRingState,pList2,RING_VAR_VALUE,pPointer);
        ring_list_setint_gc(pVM->pRingState,pList2,RING_VAR_PVALUETYPE,nPointerType);
    }
    if ( RING_VM_IR_READIVALUE(1) == 0 ) {
        /* Create String */
        pString = ring_string_new_gc(pVM->pRingState,"if ismethod(ring_gettemp_var,'operator')\nreturn ring_gettemp_var.operator('");
        ring_string_add_gc(pVM->pRingState,pString,cStr1);
        ring_string_add_gc(pVM->pRingState,pString,"',ring_settemp_var)\nelse\nraise('Object does not support operator overloading')\nok\n");
        /* Eval the string */
        pItem = RING_VM_IR_ITEM(1) ;
        pVM->nEvalCalledFromRingCode = 0 ;
        if ( pVM->lInsideEval ) {
            pVM->nRetEvalDontDelete = 1 ;
        }
        ring_vm_eval(pVM,ring_string_get(pString));
        /* We don't use RING_VM_IR because Eval reallocation change mem. locations */
        ring_item_setint_gc(pVM->pRingState,pItem,pVM->nPC);
        /* Delete String */
        ring_string_delete_gc(pVM->pRingState,pString);
    }
    else {
        ring_vm_blockflag2(pVM,pVM->nPC);
        pVM->nPC = RING_VM_IR_READIVALUE(1) ;
    }
}

void ring_vm_oop_callmethodfrombrace ( VM *pVM )
{
    List *pList,*pList2  ;
    const char *cStr  ;
    /*
    **  We uses AfterCallMethod2 instead of AfterCallMethod to avoid conflict with normal method call 
    **  AfterCallMethod2 is the same instruction as AfterCallMethod 
    **  Change NOOP to After Call Method2 
    */
    RING_VM_IR_LOAD ;
    if ( (RING_VM_IR_OPCODE == ICO_NOOP) || (RING_VM_IR_OPCODE == ICO_AFTERCALLMETHOD2) ) {
        RING_VM_IR_OPCODE = ICO_AFTERCALLMETHOD2 ;
        pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)) ;
        /* Pass Brace when we call class init , using new object() */
        if ( (ring_list_getsize(pVM->pObjState) > 1) && (pVM->nCallClassInit) ) {
            if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
                pList2 = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
                cStr = ring_list_getstring(pList2,RING_FUNCCL_NAME);
                if ( strcmp(cStr,"init") != 0 ) {
                    pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)-1) ;
                }
            }
            else {
                pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState)-1) ;
            }
        }
        pList2 = ring_list_newlist_gc(pVM->pRingState,pVM->pObjState);
        ring_list_copy_gc(pVM->pRingState,pList2,pList);
        /* Add Logical Value (True) , That we are inside the class method */
        ring_list_addint_gc(pVM->pRingState,pList2,1);
        /* Push Class Package */
        pList = (List *) ring_list_getpointer(pList2,RING_OBJSTATE_CLASS);
        ring_vm_oop_pushclasspackage(pVM,pList);
    }
    RING_VM_IR_UNLOAD ;
}

int ring_vm_oop_ismethod ( VM *pVM,List *pList,const char *cStr )
{
    List *pList2,*pList3  ;
    int x  ;
    /* Get Object Class */
    pList = (List *) ring_list_getpointer(pList,1);
    /* Get Class Methods */
    pList2 = ring_list_getlist(pList,4);
    /* Get Parent Classes Methods */
    ring_vm_oop_parentmethods(pVM,pList);
    /* Find the Method */
    if ( ring_list_getsize(pList2) > 0 ) {
        for ( x = 1 ; x <= ring_list_getsize(pList2) ; x++ ) {
            pList3 = ring_list_getlist(pList2,x);
            if ( strcmp(ring_list_getstring(pList3,RING_FUNCMAP_NAME),cStr) == 0 ) {
                if ( ring_list_getint(pList3,RING_FUNCMAP_PRIVATEFLAG) ) {
                    return 2 ;
                }
                return 1 ;
            }
        }
    }
    return 0 ;
}

void ring_vm_oop_updateselfpointer ( VM *pVM,List *pObj,int nType,void *pContainer )
{
    List *pList  ;
    /* Get Object State */
    pList = ring_list_getlist(pObj,RING_OBJECT_OBJECTDATA);
    /* Get Self Attribute */
    pList = ring_list_getlist(pList,RING_OBJECT_SELFATTRIBUTE);
    /* Set Object Pointer */
    ring_list_setpointer_gc(pVM->pRingState,pList,RING_VAR_VALUE, pContainer);
    /* Set Object Type */
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_PVALUETYPE,nType);
}

void ring_vm_oop_setthethisvariable ( VM *pVM )
{
    List *pList, *pThis  ;
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    if ( (ring_list_getsize(pVM->pObjState) < 1) || (ring_vm_oop_callmethodinsideclass(pVM) == 0) ) {
        ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,NULL);
        ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,0);
        return ;
    }
    pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState));
    /* Get Object Scope */
    pList = ring_list_getlist(pList,RING_OBJSTATE_SCOPE);
    if ( pList == NULL ) {
        ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,NULL);
        ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,0);
        return ;
    }
    /* Get Self Attribute List */
    pList = ring_list_getlist(pList,1);
    /* Save this */
    ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,ring_list_getpointer(pList,RING_VAR_VALUE));
    ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,ring_list_getint(pList,RING_VAR_PVALUETYPE));
}

void ring_vm_oop_setthethisvariableinclassregion ( VM *pVM )
{
    List *pList, *pThis  ;
    pThis = ring_list_getlist(ring_vm_getglobalscope(pVM),RING_VM_STATICVAR_THIS) ;
    pList = ring_list_getlist(pVM->pObjState,ring_list_getsize(pVM->pObjState));
    /* Get Object Scope */
    pList = ring_list_getlist(pList,RING_OBJSTATE_SCOPE);
    /* Get Self Attribute List */
    pList = ring_list_getlist(pList,1);
    /* Save this */
    ring_list_setpointer_gc(pVM->pRingState,pThis,RING_VAR_VALUE,ring_list_getpointer(pList,RING_VAR_VALUE));
    /* Create the Temp Variable for the new object */
    ring_list_setint_gc(pVM->pRingState,pThis,RING_VAR_PVALUETYPE,ring_list_getint(pList,RING_VAR_PVALUETYPE));
}

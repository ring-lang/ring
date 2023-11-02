/* Copyright (c) 2013-2023 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Error 
*/

RING_API void ring_vm_error ( VM *pVM,const char *cStr )
{
    List *pList  ;
    /* Check if we have active error */
    if ( pVM->nActiveError ) {
        return ;
    }
    pVM->nActiveError = 1 ;
    /* Check BraceError() */
    if ( pVM->lCheckBraceError  && (ring_list_getsize(pVM->pObjState) > 0) ) {
        fflush(stdout);
        if ( (ring_vm_oop_callmethodinsideclass(pVM) == 0 ) && (pVM->nCallMethod == 0) ) {
            if ( ring_vm_findvar(pVM,"self") ) {
                pList = ring_vm_oop_getobj(pVM);
                RING_VM_STACK_POP ;
                if ( ring_vm_oop_isobject(pList) ) {
                    if ( ring_vm_oop_ismethod(pVM, pList,"braceerror") ) {
                        pVM->nActiveError = 0 ;
                        ring_list_setstring_gc(pVM->pRingState,ring_list_getlist(ring_vm_getglobalscope(pVM),6),3,cStr);
                        ring_vm_eval(pVM,"return braceerror()");
                        return ;
                    }
                }
            }
        }
    }
    pVM->lCheckBraceError = 1 ;
    if ( ring_list_getsize(pVM->pTry) == 0 ) {
        if ( pVM->lHideErrorMsg == 0 ) {
            ring_vm_showerrormessage(pVM,cStr);
        }
        /* Trace */
        pVM->nActiveError = 0 ;
        ring_vm_traceevent(pVM,RING_VM_TRACEEVENT_ERROR);
        if ( pVM->lPassError  == 1 ) {
            pVM->lPassError = 0 ;
            return ;
        }
        pVM->nActiveError = 1 ;
        if ( pVM->pRingState->nRingInsideRing == 0 ) {
            exit(0);
        }
        else {
            ring_vm_bye(pVM);
            return ;
        }
    }
    /*
    **  Check Eval In Scope 
    **  When we have ringvm_evalinscope() We don't support try/catch 
    **  We just display the error message and continue 
    */
    if ( pVM->nEvalInScope ) {
        ring_vm_showerrormessage(pVM,cStr);
        pVM->nActiveError = 0 ;
        ring_vm_freestack(pVM);
        return ;
    }
    ring_vm_catch(pVM,cStr);
    pVM->nActiveError = 0 ;
}

void ring_vm_error2 ( VM *pVM,const char *cStr,const char *cStr2 )
{
    String *pError  ;
    pError = ring_string_new_gc(pVM->pRingState,cStr);
    ring_string_add_gc(pVM->pRingState,pError,": ");
    ring_string_add_gc(pVM->pRingState,pError,cStr2);
    ring_vm_error(pVM,ring_string_get(pError));
    ring_string_delete_gc(pVM->pRingState,pError);
}

RING_API void ring_vm_showerrormessage ( VM *pVM,const char *cStr )
{
    int x,lFunctionCall,nRecursion,nPos  ;
    char *cStr2, *cStr3  ;
    List *pList, *pList2  ;
    const char *cFile, *cFile2  ;
    const char *cOldFile  ;
    FuncCall *pFuncCall, *pFuncCall2  ;
    /* CGI Support */
    ring_state_cgiheader(pVM->pRingState);
    /* Print the Error Message */
    printf( "\nLine %d %s \n",RING_VM_IR_GETLINENUMBER,cStr ) ;
    /* Print Calling Information */
    cOldFile = NULL ;
    lFunctionCall = 0 ;
    nRecursion = 0 ;
    for ( x = ring_list_getsize(pVM->pFuncCallList) ; x >= 1 ; x-- ) {
        pList = ring_list_getlist(pVM->pFuncCallList,x);
        pFuncCall = (FuncCall *) ring_list_getpointer(ring_list_getlist(pList,RING_FUNCCL_STRUCT),RING_CPOINTER_POINTER) ;
        /*
        **  If we have ICO_LOADFUNC but not ICO_CALL then we need to pass 
        **  ICO_LOADFUNC is executed, but still ICO_CALL is not executed! 
        */
        if ( pFuncCall->nCallerPC == 0 ) {
            cOldFile = (const char *) pFuncCall->cFileName ;
            continue ;
        }
        if ( pFuncCall->nType == RING_FUNCTYPE_SCRIPT ) {
            cStr2 = ring_list_getstring(pList,RING_FUNCCL_NAME) ;
            if ( strcmp("",cStr2) == 0 ) {
                break ;
            }
            /* Don't repeat messages in case of recursion */
            if ( x != 1 ) {
                nPos = x-1 ;
                pList2 = ring_list_getlist(pVM->pFuncCallList,x-1);
                pFuncCall2 = (FuncCall *) ring_list_getpointer(ring_list_getlist(pList2,RING_FUNCCL_STRUCT),RING_CPOINTER_POINTER) ;
                while ( pFuncCall2->nType != RING_FUNCTYPE_SCRIPT ) {
                    nPos-- ;
                    if ( nPos > 0 ) {
                        pList2 = ring_list_getlist(pVM->pFuncCallList,nPos);
                        pFuncCall2 = (FuncCall *) ring_list_getpointer(ring_list_getlist(pList2,RING_FUNCCL_STRUCT),RING_CPOINTER_POINTER) ;
                    }
                    else {
                        break ;
                    }
                }
                if ( ring_list_getsize(pList) == ring_list_getsize(pList2) ) {
                    cStr3 = (char *) pFuncCall2->cName ;
                    cFile = (const char *) pFuncCall->cNewFileName ;
                    cFile2 = (const char *) pFuncCall2->cNewFileName ;
                    if ( (cFile == cFile2 ) && (strcmp(cStr2,cStr3) == 0) ) {
                        nRecursion++ ;
                        continue ;
                    }
                }
            }
            /*
            **  Prepare Message 
            **  In 
            */
            printf( "In " ) ;
            /* Method or Function */
            if ( pFuncCall->nMethodOrFunc ) {
                printf( "method " ) ;
            }
            else {
                printf( "function " ) ;
            }
            /* Function Name */
            printf( "%s",cStr2 ) ;
            /* Adding () */
            printf( "() in file " ) ;
            /* File Name */
            if ( lFunctionCall == 1 ) {
                cFile = (const char *) pFuncCall->cNewFileName ;
            }
            else {
                if ( pVM->nInClassRegion ) {
                    cFile = pVM->cFileNameInClassRegion ;
                }
                else {
                    cFile = pVM->cFileName ;
                }
            }
            printf( "%s",cFile ) ;
            /* Called From */
            printf( "\ncalled from line %d  ",pFuncCall->nLineNumber ) ;
        }
        else {
            printf( "In %s() ",pFuncCall->cName ) ;
        }
        lFunctionCall = 1 ;
    }
    if ( lFunctionCall ) {
        printf( "in file %s ",ring_list_getstring(pVM->pRingState->pRingFilesList,1) ) ;
    }
    else {
        if ( pVM->nInClassRegion ) {
            cFile = pVM->cFileNameInClassRegion ;
        }
        else {
            if ( cOldFile == NULL ) {
                cFile = pVM->cFileName ;
            }
            else {
                cFile = cOldFile ;
            }
        }
        printf( "in file %s ",cFile ) ;
    }
    if ( nRecursion != 0 ) {
        printf( "\n---{ Recursion Depth: %d }---\n",nRecursion ) ;
    }
    fflush(stdout);
}

void ring_vm_setfilename ( VM *pVM )
{
    if ( pVM->nInClassRegion ) {
        /*
        **  We are using special attribute for this region to avoid save/restore file name 
        **  If we used pVM->cFileName we could get problem in finding classes and packages 
        */
        pVM->cFileNameInClassRegion = RING_VM_IR_READC ;
        return ;
    }
    pVM->cPrevFileName = pVM->cFileName ;
    pVM->cFileName = RING_VM_IR_READC ;
}
/* Trace */

void ring_vm_traceevent ( VM *pVM,char nEvent )
{
    List *pList  ;
    FuncCall *pFuncCall  ;
    if ( (pVM->lTrace == 1) && (pVM->lTraceActive == 0) ) {
        pVM->lTraceActive = 1 ;
        pVM->nTraceEvent = nEvent ;
        /* Prepare Trace Data */
        ring_list_deleteallitems_gc(pVM->pRingState,pVM->pTraceData);
        /* Add Line Number */
        ring_list_adddouble_gc(pVM->pRingState,pVM->pTraceData,RING_VM_IR_GETLINENUMBER);
        /* Add File Name */
        ring_list_addstring_gc(pVM->pRingState,pVM->pTraceData,pVM->cFileName);
        /* Add Function/Method Name */
        if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
            pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList)) ;
            pFuncCall = (FuncCall *) ring_list_getpointer(ring_list_getlist(pList,RING_FUNCCL_STRUCT),RING_CPOINTER_POINTER) ;
            ring_list_addstring_gc(pVM->pRingState,pVM->pTraceData,pFuncCall->cName);
            /* Method of Function */
            ring_list_adddouble_gc(pVM->pRingState,pVM->pTraceData,pFuncCall->nMethodOrFunc);
        }
        else {
            ring_list_addstring_gc(pVM->pRingState,pVM->pTraceData,"");
            /* Method of Function */
            ring_list_adddouble_gc(pVM->pRingState,pVM->pTraceData,0);
        }
        /* Execute Trace Function */
        ring_vm_runcode(pVM,ring_string_get(pVM->pTrace));
        pVM->lTraceActive = 0 ;
        pVM->nTraceEvent = 0 ;
    }
}

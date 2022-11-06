/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
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
    if ( ring_list_getsize(pVM->pObjState) > 0 ) {
        fflush(stdout);
        if ( (ring_vm_oop_callmethodinsideclass(pVM) == 0 ) && (pVM->nCallMethod == 0) ) {
            if ( ring_vm_findvar(pVM,"self") ) {
                pList = ring_vm_oop_getobj(pVM);
                RING_VM_STACK_POP ;
                if ( ring_vm_oop_isobject(pList) ) {
                    if ( ring_vm_oop_ismethod(pVM, pList,"braceerror") ) {
                        ring_list_setstring_gc(pVM->pRingState,ring_list_getlist(ring_vm_getglobalscope(pVM),6),3,cStr);
                        ring_vm_runcode(pVM,"braceerror()");
                        pVM->nActiveError = 0 ;
                        return ;
                    }
                }
            }
        }
    }
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
    int x,lFunctionCall  ;
    char *cStr2  ;
    List *pList  ;
    const char *cFile  ;
    const char *cOldFile  ;
    /* CGI Support */
    ring_state_cgiheader(pVM->pRingState);
    /* Print the Error Message */
    printf( "\nLine %d %s \n",RING_VM_IR_GETLINENUMBER,cStr ) ;
    /* Print Calling Information */
    cOldFile = NULL ;
    lFunctionCall = 0 ;
    for ( x = ring_list_getsize(pVM->pFuncCallList) ; x >= 1 ; x-- ) {
        pList = ring_list_getlist(pVM->pFuncCallList,x);
        /*
        **  If we have ICO_LOADFUNC but not ICO_CALL then we need to pass 
        **  ICO_LOADFUNC is executed, but still ICO_CALL is not executed! 
        */
        if ( ring_list_getsize(pList) < RING_FUNCCL_CALLERPC ) {
            cOldFile = (const char *) ring_list_getpointer(pList,RING_FUNCCL_FILENAME) ;
            continue ;
        }
        if ( ring_list_getint(pList,RING_FUNCCL_TYPE) == RING_FUNCTYPE_SCRIPT ) {
            cStr2 = ring_list_getstring(pList,RING_FUNCCL_NAME) ;
            if ( strcmp("",cStr2) == 0 ) {
                break ;
            }
            /*
            **  Prepare Message 
            **  In 
            */
            printf( "In " ) ;
            /* Method or Function */
            if ( ring_list_getint(pList,RING_FUNCCL_METHODORFUNC) ) {
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
                cFile = (const char *) ring_list_getpointer(pList,RING_FUNCCL_NEWFILENAME) ;
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
            printf( "\ncalled from line %d  ",ring_list_getint(pList,RING_FUNCCL_LINENUMBER) ) ;
        }
        else {
            printf( "In %s() ",ring_list_getstring(pList,RING_FUNCCL_NAME) ) ;
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
            ring_list_addstring_gc(pVM->pRingState,pVM->pTraceData,ring_list_getstring(pList,RING_FUNCCL_NAME));
            /* Method of Function */
            ring_list_adddouble_gc(pVM->pRingState,pVM->pTraceData,ring_list_getint(pList,RING_FUNCCL_METHODORFUNC));
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

/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Eval 
*/

int ring_vm_eval ( VM *pVM,const char *cStr )
{
    int nPC,nCont,nLastPC,nRunVM,x,nSize  ;
    Scanner *pScanner  ;
    int aPara[3]  ;
    nSize = strlen( cStr ) ;
    if ( nSize == 0 ) {
        return 0 ;
    }
    nPC = pVM->nPC ;
    /* Add virtual file name */
    ring_list_addstring_gc(pVM->pRingState,pVM->pRingState->pRingFilesList,"eval");
    ring_list_addstring_gc(pVM->pRingState,pVM->pRingState->pRingFilesStack,"eval");
    pScanner = ring_scanner_new(pVM->pRingState);
    for ( x = 0 ; x < nSize ; x++ ) {
        ring_scanner_readchar(pScanner,cStr[x]);
    }
    nCont = ring_scanner_checklasttoken(pScanner);
    /* Add Token "End of Line" to the end of any program */
    ring_scanner_endofline(pScanner);
    nLastPC = RING_VM_INSTRUCTIONSCOUNT ;
    /* Get Functions/Classes Size before change by parser */
    aPara[0] = nLastPC ;
    aPara[1] = ring_list_getsize(pVM->pFunctionsMap) ;
    aPara[2] = ring_list_getsize(pVM->pClassesMap) ;
    /* Call Parser */
    if ( nCont == 1 ) {
        pVM->pRingState->lNoLineNumber = 1 ;
        nRunVM = ring_parser_start(pScanner->Tokens,pVM->pRingState);
        pVM->pRingState->lNoLineNumber = 0 ;
    }
    else {
        ring_vm_error(pVM,"Error in eval!");
        ring_scanner_delete(pScanner);
        return 0 ;
    }
    if ( nRunVM == 1 ) {
        /*
        **  Generate Code 
        **  Generate  Hash Table 
        */
        ring_list_genhashtable2(pVM->pFunctionsMap);
        if ( pVM->nEvalCalledFromRingCode ) {
            ring_scanner_addreturn3(pVM->pRingState,aPara);
        }
        else {
            ring_scanner_addreturn2(pVM->pRingState);
        }
        ring_vm_blockflag2(pVM,nPC);
        pVM->pRingState->nInstructionsCount += ring_list_getsize(pVM->pRingState->pRingGenCode) ;
        pVM->nPC = nLastPC+1 ;
        if ( RING_VM_INSTRUCTIONSCOUNT  > pVM->nEvalReallocationSize ) {
            pVM->pByteCode = (ByteCode *) ring_realloc(pVM->pByteCode , sizeof(ByteCode) * RING_VM_INSTRUCTIONSCOUNT);
            if ( pVM->nEvalCalledFromRingCode ) {
                /* Here eval() function is called from .ring files ( not by the VM for setter/getter/operator overloadi */
                pVM->nEvalReallocationFlag = 1 ;
            }
            /* Update the Eval Reallocation Size after Reallocation */
            pVM->nEvalReallocationSize = RING_VM_INSTRUCTIONSCOUNT ;
        }
        else {
            pVM->nEvalReallocationFlag = 0 ;
        }
        /* Load New Code */
        pVM->pRingState->nInstructionsCount -= ring_list_getsize(pVM->pRingState->pRingGenCode) ;
        for ( x = 1 ; x <= RING_VM_INSTRUCTIONSLISTSIZE ; x++ ) {
            ring_vm_tobytecode(pVM,x);
        }
        pVM->pRingState->nInstructionsCount += ring_list_getsize(pVM->pRingState->pRingGenCode) ;
        ring_list_deleteallitems_gc(pVM->pRingState,pVM->pRingState->pRingGenCode);
        /*
        **  The mainloop will be called again 
        **  We do this to execute eval instructions directly 
        **  This is necessary when we have GUI library that takes the event loop 
        **  Then an event uses the eval() function to execute instructions 
        **  We don't call the main loop here we call it from ring_vm_call() 
        **  We do this to execute the eval() instructions in the correct scope 
        **  Because when we call a C Function like eval() we have parameters scope 
        **  Before we call the main loop from ring_vm_call the parameters scope will be deleted 
        **  And the local scope will be restored so we can use it from eval() 
        **  Update ReallocationSize 
        */
        pVM->nEvalReallocationSize = pVM->nEvalReallocationSize - (RING_VM_INSTRUCTIONSCOUNT-nLastPC) ;
    }
    else {
        ring_vm_error(pVM,"Error in eval!");
        ring_scanner_delete(pScanner);
        return 0 ;
    }
    ring_scanner_delete(pScanner);
    ring_list_deletelastitem_gc(pVM->pRingState,pVM->pRingState->pRingFilesList);
    ring_list_deletelastitem_gc(pVM->pRingState,pVM->pRingState->pRingFilesStack);
    return nRunVM ;
}

void ring_vm_returneval ( VM *pVM )
{
    int aPara[3],nExtraSize  ;
    ByteCode *pByteCode  ;
    /* This function will always be called after each eval() execution */
    ring_vm_mutexlock(pVM);
    ring_vm_return(pVM);
    aPara[0] = RING_VM_IR_READIVALUE(1) ;
    aPara[1] = RING_VM_IR_READIVALUE(2) ;
    aPara[2] = RING_VM_IR_READIVALUE(3) ;
    if ( ( pVM->nRetEvalDontDelete == 0 ) && (aPara[1] == ring_list_getsize(pVM->pFunctionsMap)) && (aPara[2] == ring_list_getsize(pVM->pClassesMap)) ) {
        /*
        **  The code interpreted by eval doesn't add new functions or new classes 
        **  This means that the code can be deleted without any problems 
        **  We do that to avoid memory leaks 
        */
        nExtraSize = RING_VM_INSTRUCTIONSCOUNT - aPara[0] ;
        while ( RING_VM_INSTRUCTIONSCOUNT != aPara[0] ) {
            RING_VM_DELETELASTINSTRUCTION ;
        }
        if ( pVM->nEvalReallocationFlag == 1 ) {
            pVM->nEvalReallocationFlag = 0 ;
            pByteCode = (ByteCode *) ring_realloc(pVM->pByteCode , sizeof(ByteCode) * RING_VM_INSTRUCTIONSCOUNT);
            pVM->pByteCode = pByteCode ;
            /* Update the Eval Reallocation Size after Reallocation */
            pVM->nEvalReallocationSize = pVM->nEvalReallocationSize - nExtraSize ;
        }
        else {
            pVM->nEvalReallocationSize = pVM->nEvalReallocationSize + nExtraSize ;
        }
    }
    /*
    **  nEvalReturnPC is checked by the ring_vm_mainloop to end the loop 
    **  if the pVM->nPC becomes <= pVM->nEvalReturnPC the loop will be terminated 
    **  Remember that this is just a sub loop (another main loop) created after using eval() 
    **  If we don't terminate the sub main loop , this is just an extra overhead 
    **  Also terminating the sub main loop is a must when we do GUI programming 
    **  Because in GUI programming, the main loop calls the GUI Main Loop 
    **  During GUI main loop when event happens that calls a ring code 
    **  Eval will be used and a sub main loop will be executed 
    **  If we don't terminate the sub main loop, we can't return to the GUI Main Loop 
    **  It's necessary to return to the GUI main loop 
    **  When the GUI Main Loop Ends, we return to the Ring Main Loop 
    */
    pVM->nEvalReturnPC = aPara[0] ;
    ring_vm_mutexunlock(pVM);
}

void ring_vm_mainloopforeval ( VM *pVM )
{
    int nDontDelete  ;
    pVM->pRingState->lStartPoolManager = 1 ;
    pVM->lInsideEval++ ;
    nDontDelete = pVM->nRetEvalDontDelete ;
    pVM->nRetEvalDontDelete = 0 ;
    #if RING_VMSHOWOPCODE
        /* Preprocessor Allows showing the OPCODE */
        if ( pVM->pRingState->nPrintInstruction ) {
            do {
                ring_vm_fetch2(pVM);
                if ( pVM->nPC <= pVM->nEvalReturnPC ) {
                    pVM->nEvalReturnPC = 0 ;
                    break ;
                }
            } while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT)  ;
        }
        else {
            do {
                ring_vm_fetch(pVM);
                if ( pVM->nPC <= pVM->nEvalReturnPC ) {
                    pVM->nEvalReturnPC = 0 ;
                    break ;
                }
            } while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT)  ;
        }
    #else
        do {
            ring_vm_fetch(pVM);
            if ( pVM->nPC <= pVM->nEvalReturnPC ) {
                pVM->nEvalReturnPC = 0 ;
                break ;
            }
        } while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT)  ;
    #endif
    pVM->lInsideEval-- ;
    pVM->nRetEvalDontDelete = nDontDelete ;
}

RING_API void ring_vm_runcode ( VM *pVM,const char *cStr )
{
    int nEvalReturnPC,nEvalReallocationFlag,nPC,nRunVM,nSP,nFuncSP,nLineNumber  ;
    List *pStackList  ;
    /* Save state to take in mind nested events execution */
    pVM->nRunCode++ ;
    nEvalReturnPC = pVM->nEvalReturnPC ;
    nEvalReallocationFlag = pVM->nEvalReallocationFlag ;
    nPC = pVM->nPC ;
    nSP = pVM->nSP ;
    nFuncSP = pVM->nFuncSP ;
    pStackList = ring_vm_savestack(pVM);
    nLineNumber = RING_VM_IR_GETLINENUMBER ;
    ring_vm_mutexlock(pVM);
    pVM->nEvalCalledFromRingCode = 1 ;
    /* Take in mind nested events */
    if ( pVM->nRunCode != 1 ) {
        pVM->nRetEvalDontDelete = 1 ;
    }
    nRunVM = ring_vm_eval(pVM,cStr);
    pVM->nEvalCalledFromRingCode = 0 ;
    ring_vm_mutexunlock(pVM);
    if ( nRunVM ) {
        pVM->nFuncExecute = 0 ;
        pVM->nFuncExecute2 = 0 ;
        ring_vm_mainloopforeval(pVM);
    }
    /* Restore state to take in mind nested events execution */
    pVM->nRunCode-- ;
    pVM->nEvalReturnPC = nEvalReturnPC ;
    pVM->nEvalReallocationFlag = nEvalReallocationFlag ;
    pVM->nPC = nPC ;
    if ( pVM->nRunCode != 0 ) {
        /* It's a nested event (Here we don't care about the output and we can restore the stack) */
        ring_vm_restorestack(pVM,pStackList);
    }
    /* Here we free the list because, restorestack() don't free it */
    ring_list_delete_gc(pVM->pRingState,pStackList);
    /* Restore Stack to avoid Stack Overflow */
    pVM->nSP = nSP ;
    pVM->nFuncSP = nFuncSP ;
    RING_VM_IR_SETLINENUMBER(nLineNumber);
}
/* Fast Function Call for Extensions (Without Eval) */

RING_API void ring_vm_callfunction ( VM *pVM,char *cFuncName )
{
    /* Lower Case and pass () in the end */
    ring_string_lower(cFuncName);
    /* Prepare (Remove effects of the current function) */
    ring_list_deletelastitem_gc(pVM->pRingState,pVM->pFuncCallList);
    /* Load the function and call it */
    ring_vm_loadfunc2(pVM,cFuncName,0);
    ring_vm_call2(pVM);
    /* Execute the function */
    ring_vm_mainloopforeval(pVM);
    /* Free Stack */
    ring_vm_freestack(pVM);
    /* Avoid normal steps after this function, because we deleted the scope in Prepare */
    pVM->nActiveCatch = 1 ;
}

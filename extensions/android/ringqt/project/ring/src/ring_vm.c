/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Main 
*/

VM * ring_vm_new ( RingState *pRingState )
{
    VM *pVM  ;
    int x  ;
    ring_state_log(pRingState,"function: ring_vm_new - start");
    pVM = (VM *) ring_state_malloc(pRingState,sizeof(VM));
    /* Ring State */
    pVM->pRingState = pRingState ;
    pRingState->pVM = pVM ;
    ring_state_log(pRingState,"function: ring_vm_new - after malloc()");
    pVM->nPC = 1 ;
    pVM->pCode = NULL ;
    pVM->pFunctionsMap = NULL ;
    pVM->nOPCode = 0 ;
    pVM->nSP = 0 ;
    pVM->pMem = ring_list_new_gc(pVM->pRingState,0);
    pVM->pActiveMem = NULL ;
    pVM->pTempMem = ring_list_new_gc(pVM->pRingState,0);
    pVM->nLineNumber = 1 ;
    /* Information to test the lifetime of the local scope */
    pVM->nScopeID = 0 ;
    pVM->aScopeID = ring_list_new_gc(pVM->pRingState,0);
    ring_state_log(pRingState,"function: ring_vm_new - after setting aScopeID");
    ring_vm_newscope(pVM);
    for ( x = 0 ; x < RING_VM_STACK_SIZE ; x++ ) {
        pVM->aStack[x].nType = ITEMTYPE_NOTHING ;
        pVM->aStack[x].nObjectType = 0 ;
        pVM->aStack[x].NumberFlag = ITEM_NUMBERFLAG_NOTHING ;
    }
    /*
    **  Flag ( 0 = check NULL variable in PUSHV  , greater than 0 = Ignore null variable ) 
    **  Class Region (After the Class Name) 
    */
    pVM->nInClassRegion = 0 ;
    ring_state_log(pRingState,"function: ring_vm_new - after class region flag");
    /* Add Variables */
    ring_vm_addglobalvariables(pVM);
    ring_state_log(pRingState,"function: ring_vm_new - after global variables");
    /* Lists */
    pVM->nListStart = 0 ;
    pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,0);
    ring_state_log(pRingState,"function: ring_vm_new - after nested lists");
    /* Support for nested Load Instructions */
    pVM->nBlockFlag = 0 ;
    pVM->aPCBlockFlag = ring_list_new_gc(pVM->pRingState,0);
    /* Calling Functions */
    pVM->pFuncCallList = ring_list_new_gc(pVM->pRingState,0);
    pVM->nFuncSP = 0 ;
    pVM->nFuncExecute = 0 ;
    if ( pRingState->pRingCFunctions == NULL ) {
        pRingState->pRingCFunctions = ring_list_new_gc(pVM->pRingState,0);
    }
    pVM->pCFunctionsList = pRingState->pRingCFunctions ;
    pVM->nCallMainFunction = 0 ;
    /* Support for Exit/Loop Commands inside For/While loops. */
    pVM->pExitMark = ring_list_new_gc(pVM->pRingState,0);
    pVM->pLoopMark = ring_list_new_gc(pVM->pRingState,0);
    ring_state_log(pRingState,"function: ring_vm_new - after exit/loop marks");
    /* Try-Catch-Done */
    pVM->pTry = ring_list_new_gc(pVM->pRingState,0);
    /* Saving scope when creating new objects and calling class init method */
    pVM->aScopeNewObj = ring_list_new_gc(pVM->pRingState,0);
    /* Flag ( 0 = Call Function  1 = Call Method After writing object name using dot ) */
    pVM->nCallMethod = 0 ;
    /* List of Lists used like Stack, list structure [Pointer to State , Pointer to Methods] */
    pVM->pObjState = ring_list_new_gc(pVM->pRingState,0);
    /* Support for using Braces to access object state */
    pVM->pBraceObject = NULL ;
    pVM->aBraceObjects = ring_list_new_gc(pVM->pRingState,0);
    /* Used by BraceStart, BraceEnd & FreeStack */
    pVM->nInsideBraceFlag = 0 ;
    /* Variable scope, where is the variable (when we use findvar) */
    pVM->nVarScope = RING_VARSCOPE_NOTHING ;
    /* Flag used by Try/Catch to tell C-API that catch happens! */
    pVM->nActiveCatch = 0 ;
    pVM->pPackagesMap = NULL ;
    /* Set the main File Name */
    pVM->cFileName = ring_list_getstring(pVM->pRingState->pRingFilesList,1) ;
    pVM->cPrevFileName = ring_list_getstring(pVM->pRingState->pRingFilesList,1) ;
    ring_state_log(pRingState,"function: ring_vm_new - after setting the main file");
    /* We keep information about active package to access its classes directly with new/from */
    pVM->aActivePackage = ring_list_new_gc(pVM->pRingState,0);
    /* Scope of class attribute ( 0 = public 1 = private ) */
    pVM->nPrivateFlag = 0 ;
    /* Set/Get Property */
    pVM->nGetSetProperty = 0 ;
    pVM->pGetSetObject = NULL ;
    pVM->nGetSetObjType = 0 ;
    pVM->aSetProperty = ring_list_new_gc(pVM->pRingState,0);
    /* Assignment Pointer */
    pVM->pAssignment = NULL ;
    /* For Loop - Step List */
    pVM->aForStep = ring_list_new_gc(pVM->pRingState,0);
    /* Flag for LoadA , when = 1 , if it's a pointer we get First Var. not the Pointer */
    pVM->nFirstAddress = 0 ;
    /* Used to know operator before = like += -= *= /= */
    pVM->nBeforeEqual = 0 ;
    /*
    **  NOAssignment used to disable instruction AssignmentPointer 
    **  We uses this when we change assignment to set property 
    **  It's important for ListStart to create Temp List when we use setter 
    **  and try to set attribute value to a list and a function setproperty() will be called 
    **  With this list as parameter stored in temp memory 
    */
    pVM->nNOAssignment = 0 ;
    /* List contains the scope of the result of Load Address */
    pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
    pVM->aAddressScope = ring_list_new_gc(pVM->pRingState,0);
    /* List contains what to add  later to pObjState, prepare by loadmethod, add before call */
    pVM->aBeforeObjState = ring_list_new_gc(pVM->pRingState,0) ;
    /* Another flag like nFuncExec but not used by see command or return command */
    pVM->nFuncExecute2 = 0 ;
    /* Create List for Temp Items (added to ByteCode) inside TempMem */
    pVM->aNewByteCodeItems = ring_list_new_gc(pVM->pRingState,0);
    /* Eval can be called from C code (OOP Set/Get/Operator Overloading) or from ring code using eval() */
    pVM->nEvalCalledFromRingCode = 0 ;
    /* Number of decimals after the point */
    pVM->nDecimals = 2 ;
    /*
    **  Do we need to reallocation for eval() or not ! 
    **  Size of items that we can use without reallocation (double of the original size) 
    */
    pVM->nEvalReallocationSize = 0 ;
    /* Flag ( 1 = we need space over allocated size so we have to do reallocation ) */
    pVM->nEvalReallocationFlag = 0 ;
    /* Parameters Count Passed to C Function */
    pVM->nCFuncParaCount = 0 ;
    /*
    **  Flag to Ignore NULL output after calling C Function 
    **  This flag is used by the len() function when we use len(object) 
    **  So operator overloading can return the result from the method 
    */
    pVM->nIgnoreNULL = 0 ;
    /* If pVM->nPC <= nEvalReturnPC we end the main loop (used by evalreturn) */
    pVM->nEvalReturnPC = 0 ;
    /* Flag to return Item Reference (of object state) */
    pVM->nRetItemRef = 0 ;
    /* Mutex Functions Pointers - for threads/lock/unlock */
    pVM->pFuncMutexLock = NULL ;
    pVM->pFuncMutexUnlock = NULL ;
    pVM->pFuncMutexDestroy = NULL ;
    pVM->pMutex = NULL ;
    /* Ignore C Pointer Type Check in extension functions */
    pVM->nIgnoreCPointerTypeCheck = 0 ;
    /*
    **  Flag when we call class init using new obj() 
    **  Since we call init() using generated braces { } 
    **  setting this flag enable LoadAddress to pass these braces 
    **  To access the class attributes of the caller 
    **  because {} hides the class attributes and we need to avoid that! 
    */
    pVM->nCallClassInit = 0 ;
    /*
    **  Flag to avoid deleting Byte Code using Return From Eval() 
    **  When we use eval() then inside eval we uses eval for setter/getter/operator overloading 
    **  Then deleting byte code will cause a problem in setter/getter/operator overloading 
    **  In this case we set this flag to avoid the delete operation and solve the problem 
    */
    pVM->nRetEvalDontDelete = 0 ;
    /* Counter to know if we are inside ring_vm_runcode() */
    pVM->nRunCode = 0 ;
    /* Flag that we have runtime error to avoid calling the error function again */
    pVM->nActiveError = 0 ;
    /* The active package name (after using import command) */
    pVM->pPackageName = ring_string_new_gc(pVM->pRingState,"");
    /*
    **  Trace Program (After Each Line) 
    **  lTrace = Logical Value (Trace is Active or Not) 
    **  pTrace = String contains the code to be executed (Trace Function) 
    **  lTraceActive = The Trace Function is Active - Don't Call Trace function from Trace Function 
    **  nTraceEvent = The Trace Event (1 = New Line , etc) 
    */
    pVM->lTrace = 0 ;
    pVM->pTrace = ring_string_new_gc(pVM->pRingState,"");
    pVM->lTraceActive = 0 ;
    pVM->nTraceEvent = 0 ;
    pVM->pTraceData = ring_list_new_gc(pVM->pRingState,0) ;
    ring_state_log(pRingState,"function: ring_vm_new - after trace attributes");
    /* Eval In Scope function is Active : ringvm_evalinscope() */
    pVM->nEvalInScope = 0 ;
    /* Pass error in ring_vm_error() from ringvm_passerror() */
    pVM->lPassError = 0 ;
    /* Hide Error message - don't display it in ring_vm_error() */
    pVM->lHideErrorMsg = 0 ;
    /* Custom Global Scopes (using load package) */
    pVM->aGlobalScopes = ring_list_new_gc(pVM->pRingState,0);
    pVM->aActiveGlobalScopes = ring_list_new_gc(pVM->pRingState,0);
    pVM->nCurrentGlobalScope = 0 ;
    /* File name in the class region */
    pVM->cFileNameInClassRegion = NULL ;
    /* Control Performance Instructions */
    pVM->lUsePushPLocal = 0 ;
    /* To know if we are inside eval() or not */
    pVM->lInsideEval = 0 ;
    /* Dynamic Libraries */
    pVM->pCLibraries = ring_list_new_gc(pVM->pRingState,0);
    /* No Setter Method (used by ring_vm_oop_setget() function) */
    pVM->lNoSetterMethod = 0 ;
    /* Check OverFlow after arithmetic operations */
    pVM->lCheckOverFlow = 0 ;
    /* Add Sub Lists to Lists by Move (Very Fast) */
    pVM->lAddSubListsByMove = 0 ;
    /* Add Sub Lists to Lists by Fast Copy */
    pVM->lAddSubListsByFastCopy = 0 ;
    /* A Flag that the Exit command is used to terminate the (For-In) Loop */
    pVM->lExitFlag = 0 ;
    ring_state_log(pRingState,"function: ring_vm_new - end");
    return pVM ;
}

VM * ring_vm_delete ( VM *pVM )
{
    int x  ;
    List *pRecord  ;
    Item *pItem  ;
    assert(pVM);
    pVM->pMem = ring_list_delete_gc(pVM->pRingState,pVM->pMem);
    pVM->pNestedLists = ring_list_delete_gc(pVM->pRingState,pVM->pNestedLists);
    pVM->pFuncCallList = ring_list_delete_gc(pVM->pRingState,pVM->pFuncCallList);
    pVM->aPCBlockFlag = ring_list_delete_gc(pVM->pRingState,pVM->aPCBlockFlag);
    pVM->pTempMem = ring_list_delete_gc(pVM->pRingState,pVM->pTempMem);
    pVM->pExitMark = ring_list_delete_gc(pVM->pRingState,pVM->pExitMark);
    pVM->pLoopMark = ring_list_delete_gc(pVM->pRingState,pVM->pLoopMark);
    pVM->pTry = ring_list_delete_gc(pVM->pRingState,pVM->pTry);
    pVM->aScopeNewObj = ring_list_delete_gc(pVM->pRingState,pVM->aScopeNewObj);
    pVM->pObjState = ring_list_delete_gc(pVM->pRingState,pVM->pObjState);
    pVM->aBraceObjects = ring_list_delete_gc(pVM->pRingState,pVM->aBraceObjects);
    pVM->aScopeID = ring_list_delete_gc(pVM->pRingState,pVM->aScopeID);
    pVM->aActivePackage = ring_list_delete_gc(pVM->pRingState,pVM->aActivePackage);
    pVM->aSetProperty = ring_list_delete_gc(pVM->pRingState,pVM->aSetProperty);
    pVM->aForStep = ring_list_delete_gc(pVM->pRingState,pVM->aForStep);
    pVM->aBeforeObjState = ring_list_delete_gc(pVM->pRingState,pVM->aBeforeObjState);
    pVM->aNewByteCodeItems = ring_list_delete_gc(pVM->pRingState,pVM->aNewByteCodeItems);
    /* Free Stack */
    for ( x = 0 ; x < RING_VM_STACK_SIZE ; x++ ) {
        ring_item_content_delete(&(pVM->aStack[x]));
    }
    ring_state_free(pVM->pRingState,pVM->pByteCode);
    /* Delete Mutex */
    ring_vm_mutexdestroy(pVM);
    pVM->pPackageName = ring_string_delete_gc(pVM->pRingState,pVM->pPackageName);
    pVM->pTrace = ring_string_delete_gc(pVM->pRingState,pVM->pTrace);
    pVM->pTraceData = ring_list_delete_gc(pVM->pRingState,pVM->pTraceData);
    /* Custom Global Scope (using Load Package) */
    pVM->aGlobalScopes = ring_list_delete_gc(pVM->pRingState,pVM->aGlobalScopes);
    pVM->aActiveGlobalScopes = ring_list_delete_gc(pVM->pRingState,pVM->aActiveGlobalScopes);
    /* Dynamic Libraries */
    #if RING_VM_DLL
        ring_vm_dll_closealllibs(pVM);
    #endif
    pVM->pCLibraries = ring_list_delete_gc(pVM->pRingState,pVM->pCLibraries);
    pVM->aAddressScope = ring_list_delete_gc(pVM->pRingState,pVM->aAddressScope);
    pVM->pRingState->pVM = NULL ;
    ring_state_free(pVM->pRingState,pVM);
    pVM = NULL ;
    return pVM ;
}

RING_API void ring_vm_loadcode ( VM *pVM )
{
    int x,nSize  ;
    /*
    **  We may allocation double of the size that we need to avoid reallocation when we use eval() 
    **  eval() will check if there is a need to reallocation or not 
    **  This optimization increase the performance of applications that uses eval() 
    */
    nSize = (RING_MAX(ring_list_getsize(pVM->pCode),RING_VM_MINVMINSTRUCTIONS))*RING_VM_EXTRASIZE ;
    pVM->pByteCode = (ByteCode *) ring_calloc(nSize,sizeof(ByteCode));
    for ( x = 1 ; x <= ring_list_getsize(pVM->pCode) ; x++ ) {
        ring_vm_tobytecode(pVM,x);
    }
    pVM->nEvalReallocationSize = nSize ;
}

void ring_vm_start ( RingState *pRingState,VM *pVM )
{
    pVM->pCode = pRingState->pRingGenCode ;
    pVM->pFunctionsMap = pRingState->pRingFunctionsMap ;
    pVM->pClassesMap = pRingState->pRingClassesMap ;
    pVM->pPackagesMap = pRingState->pRingPackagesMap ;
    ring_state_log(pRingState,"function: ring_vm_start");
    ring_vm_loadcode(pVM);
    ring_state_log(pRingState,"function: ring_vm_start - after loading code");
    ring_vm_loadcfunctions(pRingState);
    ring_state_log(pRingState,"function: ring_vm_start - after loading c functions");
    /* Generate Items Array &  Hash Table */
    ring_list_genarray(pRingState->pRingCFunctions);
    ring_list_genhashtable2(pRingState->pRingCFunctions);
    ring_state_log(pRingState,"function: ring_vm_start - after generating hash tables");
    if ( ring_list_getsize(pVM->pCode) > 0 ) {
        pVM->nPC = 1 ;
        ring_vm_mainloop(pVM);
    }
}

void ring_vm_mainloop ( VM *pVM )
{
    pVM->pRingState->lStartPoolManager = 1 ;
    #if RING_VMSHOWOPCODE
        /* Preprocessor Allows showing the OPCODE */
        if ( pVM->pRingState->nPrintInstruction ) {
            do {
                ring_vm_fetch2(pVM);
            } while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
        }
        else {
            do {
                ring_vm_fetch(pVM);
            } while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
        }
    #else
        do {
            ring_vm_fetch(pVM);
        } while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
    #endif
}

void ring_vm_fetch ( VM *pVM )
{
    pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1 ;
    pVM->nOPCode = RING_VM_IR_OPCODE ;
    pVM->nPC++ ;
    ring_vm_execute(pVM);
    if ( pVM->nSP > RING_VM_STACK_CHECKOVERFLOW ) {
        ring_vm_error(pVM,RING_VM_ERROR_STACKOVERFLOW);
    }
}

void ring_vm_fetch2 ( VM *pVM )
{
    pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1 ;
    pVM->nOPCode = RING_VM_IR_OPCODE ;
    #if RING_VMSHOWOPCODE
        if ( pVM->pRingState->nPrintInstruction ) {
            ring_general_printline();
            printf( "VM Pointer    : %p  " , (void *) pVM ) ;
            printf( "\nOperation     : %s  " , RING_IC_OP[pVM->nOPCode] ) ;
            printf( "\nPC            : %d  " ,pVM->nPC ) ;
            printf( "\nScopes Count  : %d  " ,ring_list_getsize(pVM->pMem) ) ;
            printf( "\nScope Pointer : %p  " ,pVM->pActiveMem ) ;
            printf( "\nFile Name     : %s \nLine Number   : %d\n" ,pVM->cFileName,pVM->nLineNumber ) ;
            if ( (pVM->nOPCode == ICO_PUSHC) || (pVM->nOPCode == ICO_LOADADDRESS) || (pVM->nOPCode == ICO_LOADFUNC) ) {
                printf( "Data          : %s \n",RING_VM_IR_READC ) ;
            }
        }
    #endif
    pVM->nPC++ ;
    ring_vm_execute(pVM);
    #if RING_VMSHOWOPCODE
        if ( pVM->pRingState->nPrintInstruction ) {
            printf( "\nSP (After)    : %d  \nFuncSP        : %d \nLineNumber    : %d \n" , (int) pVM->nSP,pVM->nFuncSP,pVM->nLineNumber ) ;
        }
    #endif
    if ( pVM->nSP > RING_VM_STACK_CHECKOVERFLOW ) {
        ring_vm_error(pVM,RING_VM_ERROR_STACKOVERFLOW);
    }
}

void ring_vm_execute ( VM *pVM )
{
    switch ( pVM->nOPCode ) {
        /* Stack and Variables */
        case ICO_PUSHC :
            RING_VM_STACK_PUSHC ;
            break ;
        case ICO_PUSHN :
            RING_VM_STACK_PUSHN ;
            break ;
        case ICO_PUSHV :
            ring_vm_pushv(pVM);
            break ;
        case ICO_LOADADDRESS :
            ring_vm_loadaddress(pVM);
            break ;
        case ICO_ASSIGNMENT :
            ring_vm_assignment(pVM);
            break ;
        case ICO_INC :
            ring_vm_inc(pVM);
            break ;
        case ICO_LOADAPUSHV :
            ring_vm_loadapushv(pVM);
            break ;
        case ICO_NEWLINE :
            ring_vm_newline(pVM);
            break ;
        case ICO_FREESTACK :
            ring_vm_freestack(pVM);
            break ;
        case ICO_FILENAME :
            ring_vm_setfilename(pVM);
            break ;
        case ICO_FREELOADASCOPE :
            ring_vm_freeloadaddressscope(pVM);
            break ;
        /* Jump */
        case ICO_JUMP :
            ring_vm_jump(pVM);
            break ;
        case ICO_JUMPZERO :
            ring_vm_jumpzero(pVM);
            break ;
        case ICO_JUMPFOR :
            ring_vm_jumpfor(pVM);
            break ;
        case ICO_JUMPONE :
            ring_vm_jumpone(pVM);
            break ;
        case ICO_JUMPZERO2 :
            ring_vm_jumpzero2(pVM);
            break ;
        case ICO_JUMPONE2 :
            ring_vm_jumpone2(pVM);
            break ;
        /* Compare */
        case ICO_LESSEQUAL :
            ring_vm_lessequal(pVM);
            break ;
        case ICO_EQUAL :
            ring_vm_equal(pVM);
            break ;
        case ICO_LESS :
            ring_vm_less(pVM);
            break ;
        case ICO_GREATER :
            ring_vm_greater(pVM);
            break ;
        case ICO_GREATEREQUAL :
            ring_vm_greaterequal(pVM);
            break ;
        case ICO_NOTEQUAL :
            ring_vm_notequal(pVM);
            break ;
        /* Math */
        case ICO_SUM :
            ring_vm_sum(pVM);
            break ;
        case ICO_SUB :
            ring_vm_sub(pVM);
            break ;
        case ICO_MUL :
            ring_vm_mul(pVM);
            break ;
        case ICO_DIV :
            ring_vm_div(pVM);
            break ;
        case ICO_MOD :
            ring_vm_mod(pVM);
            break ;
        case ICO_NEG :
            ring_vm_neg(pVM);
            break ;
        case ICO_PLUSPLUS :
            ring_vm_plusplus(pVM);
            break ;
        case ICO_MINUSMINUS :
            ring_vm_minusminus(pVM);
            break ;
        /* Logic */
        case ICO_AND :
            ring_vm_and(pVM);
            break ;
        case ICO_OR :
            ring_vm_or(pVM);
            break ;
        case ICO_NOT :
            ring_vm_not(pVM);
            break ;
        /* Lists */
        case ICO_LISTSTART :
            ring_vm_liststart(pVM);
            break ;
        case ICO_LISTITEM :
            ring_vm_listitem(pVM);
            break ;
        case ICO_LISTEND :
            ring_vm_listend(pVM);
            break ;
        case ICO_LOADINDEXADDRESS :
            ring_vm_loadindexaddress(pVM);
            break ;
        /* Functions */
        case ICO_LOADFUNC :
            ring_vm_loadfunc(pVM);
            break ;
        case ICO_CALL :
            ring_vm_call(pVM);
            break ;
        case ICO_RETURN :
            ring_vm_return(pVM);
            break ;
        case ICO_RETNULL :
            ring_vm_returnnull(pVM);
            break ;
        case ICO_RETFROMEVAL :
            ring_vm_returneval(pVM);
            break ;
        case ICO_RETITEMREF :
            ring_vm_retitemref(pVM);
            break ;
        case ICO_NEWFUNC :
            ring_vm_newfunc(pVM);
            break ;
        case ICO_BLOCKFLAG :
            ring_vm_blockflag(pVM);
            break ;
        case ICO_FUNCEXE :
            pVM->nFuncExecute++ ;
            break ;
        case ICO_ENDFUNCEXE :
            ring_vm_endfuncexec(pVM);
            break ;
        case ICO_ANONYMOUS :
            ring_vm_anonymous(pVM);
            break ;
        /* User Interface */
        case ICO_PRINT :
            ring_vm_see(pVM);
            break ;
        case ICO_GIVE :
            ring_vm_give(pVM);
            break ;
        /* End Program - Exit from Loop - Loop (Continue) */
        case ICO_BYE :
            ring_vm_bye(pVM);
            break ;
        case ICO_EXITMARK :
            ring_vm_exitmark(pVM);
            break ;
        case ICO_POPEXITMARK :
            ring_vm_popexitmark(pVM);
            break ;
        case ICO_EXIT :
            ring_vm_exit(pVM,RING_COMMANDTYPE_EXIT);
            break ;
        case ICO_LOOP :
            ring_vm_exit(pVM,RING_COMMANDTYPE_LOOP);
            break ;
        /* For Better Performance */
        case ICO_PUSHP :
            ring_vm_pushp(pVM);
            break ;
        case ICO_INCP :
            ring_vm_incp(pVM);
            break ;
        case ICO_PUSHPV :
            ring_vm_pushpv(pVM);
            break ;
        case ICO_INCJUMP :
            ring_vm_incjump(pVM);
            break ;
        case ICO_INCPJUMP :
            ring_vm_incpjump(pVM);
            break ;
        case ICO_JUMPVARLENUM :
            ring_vm_jumpvarlenum(pVM);
            break ;
        case ICO_JUMPVARPLENUM :
            ring_vm_jumpvarplenum(pVM);
            break ;
        case ICO_LOADFUNCP :
            ring_vm_loadfuncp(pVM);
            break ;
        case ICO_PUSHPLOCAL :
            ring_vm_pushplocal(pVM);
            break ;
        case ICO_INCLPJUMP :
            ring_vm_inclpjump(pVM);
            break ;
        case ICO_JUMPVARLPLENUM :
            ring_vm_jumpvarlplenum(pVM);
            break ;
        case ICO_INCPJUMPSTEP1 :
            ring_vm_incpjumpstep1(pVM);
            break ;
        case ICO_JUMPVARPLENUMSTEP1 :
            ring_vm_jumpvarplenumstep1(pVM);
            break ;
        /* Try-Catch-Done */
        case ICO_TRY :
            ring_vm_try(pVM);
            break ;
        case ICO_DONE :
            ring_vm_done(pVM);
            break ;
        /* Duplicate and Range */
        case ICO_DUPLICATE :
            ring_vm_dup(pVM);
            break ;
        case ICO_RANGE :
            ring_vm_range(pVM);
            break ;
        /* OOP */
        case ICO_NEWOBJ :
            ring_vm_oop_newobj(pVM);
            break ;
        case ICO_SETSCOPE :
            ring_vm_oop_setscope(pVM);
            break ;
        case ICO_LOADSUBADDRESS :
            ring_vm_oop_property(pVM);
            break ;
        case ICO_LOADMETHOD :
            ring_vm_oop_loadmethod(pVM);
            break ;
        case ICO_AFTERCALLMETHOD :
            ring_vm_oop_aftercallmethod(pVM);
            break ;
        case ICO_AFTERCALLMETHOD2 :
            ring_vm_oop_aftercallmethod(pVM);
            break ;
        case ICO_NEWCLASS :
            ring_vm_oop_newclass(pVM);
            break ;
        case ICO_BRACESTART :
            ring_vm_oop_bracestart(pVM);
            break ;
        case ICO_BRACEEND :
            ring_vm_oop_braceend(pVM);
            break ;
        case ICO_IMPORT :
            ring_vm_oop_import(pVM);
            break ;
        case ICO_PRIVATE :
            pVM->nPrivateFlag = 1 ;
            break ;
        case ICO_SETPROPERTY :
            ring_vm_oop_setproperty(pVM);
            break ;
        case ICO_CALLCLASSINIT :
            ring_vm_callclassinit(pVM);
            break ;
        /* Other */
        case ICO_SETREFERENCE :
            ring_vm_setreference(pVM);
            break ;
        case ICO_KILLREFERENCE :
            ring_vm_gc_killreference(pVM);
            break ;
        case ICO_ASSIGNMENTPOINTER :
            ring_vm_assignmentpointer(pVM);
            break ;
        case ICO_BEFOREEQUAL :
            pVM->nBeforeEqual = RING_VM_IR_READI ;
            break ;
        /* Bitwise Operators */
        case ICO_BITAND :
            ring_vm_bitand(pVM);
            break ;
        case ICO_BITOR :
            ring_vm_bitor(pVM);
            break ;
        case ICO_BITXOR :
            ring_vm_bitxor(pVM);
            break ;
        case ICO_BITNOT :
            ring_vm_bitnot(pVM);
            break ;
        case ICO_BITSHL :
            ring_vm_bitshl(pVM);
            break ;
        case ICO_BITSHR :
            ring_vm_bitshr(pVM);
            break ;
        /* For Step */
        case ICO_STEPNUMBER :
            ring_vm_stepnumber(pVM);
            break ;
        case ICO_POPSTEP :
            ring_vm_popstep(pVM);
            break ;
        case ICO_LOADAFIRST :
            ring_vm_loadaddressfirst(pVM);
            break ;
        /* Custom Global Scope */
        case ICO_NEWGLOBALSCOPE :
            ring_vm_newglobalscope(pVM);
            break ;
        case ICO_ENDGLOBALSCOPE :
            ring_vm_endglobalscope(pVM);
            break ;
        case ICO_SETGLOBALSCOPE :
            ring_vm_setglobalscope(pVM);
            break ;
        /* Temp Lists */
        case ICO_FREETEMPLISTS :
            ring_vm_freetemplists(pVM);
            break ;
    }
}

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

int ring_vm_eval ( VM *pVM,const char *cStr )
{
    int nPC,nCont,nLastPC,nRunVM,x,nSize  ;
    Scanner *pScanner  ;
    int aPara[3]  ;
    ring_state_log(pVM->pRingState,"function: ring_vm_eval() start");
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
    nLastPC = ring_list_getsize(pVM->pCode);
    /* Get Functions/Classes Size before change by parser */
    aPara[0] = nLastPC ;
    aPara[1] = ring_list_getsize(pVM->pFunctionsMap) ;
    aPara[2] = ring_list_getsize(pVM->pClassesMap) ;
    /* Call Parser */
    if ( nCont == 1 ) {
        ring_state_log(pVM->pRingState,cStr);
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
        pVM->nPC = nLastPC+1 ;
        if ( ring_list_getsize(pVM->pCode)  > pVM->nEvalReallocationSize ) {
            pVM->pByteCode = (ByteCode *) ring_realloc(pVM->pByteCode , sizeof(ByteCode) * ring_list_getsize(pVM->pCode));
            if ( pVM->nEvalCalledFromRingCode ) {
                /* Here eval() function is called from .ring files ( not by the VM for setter/getter/operator overloading) */
                pVM->nEvalReallocationFlag = 1 ;
            }
            /* Update the Eval Reallocation Size after Reallocation */
            pVM->nEvalReallocationSize = ring_list_getsize(pVM->pCode) ;
        }
        else {
            pVM->nEvalReallocationFlag = 0 ;
        }
        /* Load New Code */
        for ( x = pVM->nPC ; x <= ring_list_getsize(pVM->pCode) ; x++ ) {
            ring_vm_tobytecode(pVM,x);
        }
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
        pVM->nEvalReallocationSize = pVM->nEvalReallocationSize - (ring_list_getsize(pVM->pCode)-nLastPC) ;
    }
    else {
        ring_vm_error(pVM,"Error in eval!");
        ring_scanner_delete(pScanner);
        return 0 ;
    }
    ring_scanner_delete(pScanner);
    ring_list_deletelastitem_gc(pVM->pRingState,pVM->pRingState->pRingFilesList);
    ring_list_deletelastitem_gc(pVM->pRingState,pVM->pRingState->pRingFilesStack);
    ring_state_log(pVM->pRingState,"function: ring_vm_eval() end");
    return nRunVM ;
}

void ring_vm_tobytecode ( VM *pVM,int x )
{
    List *pIR  ;
    int x2  ;
    ByteCode *pByteCode  ;
    Item *pItem  ;
    pByteCode = pVM->pByteCode + x - 1 ;
    pIR = ring_list_getlist(pVM->pCode,x);
    pByteCode->nSize = ring_list_getsize(pIR) ;
    #if RING_SHOWICFINAL
        pByteCode->pList = pIR ;
    #endif
    /* Check Instruction Size */
    if ( ring_list_getsize(pIR) > RING_VM_BC_ITEMS_COUNT ) {
        printf( RING_LONGINSTRUCTION ) ;
        printf( "In File : %s  - Byte-Code PC : %d  ",pVM->cFileName,x ) ;
        exit(0);
    }
    for ( x2 = 1 ; x2 <= ring_list_getsize(pIR) ; x2++ ) {
        pItem = ring_list_getitem(pIR,x2) ;
        pByteCode->aData[x2-1] = pItem ;
        /* Avoid Performance Instructions (Happens when called from New Thread) */
        if ( x2 == 1 ) {
            switch ( pItem->data.iNumber ) {
                case ICO_PUSHPLOCAL :
                    pItem->data.iNumber = ICO_LOADADDRESS ;
                    break ;
                case ICO_JUMPVARLPLENUM :
                    pItem->data.iNumber = ICO_JUMPVARLENUM ;
                    break ;
                case ICO_INCLPJUMP :
                    pItem->data.iNumber = ICO_INCJUMP ;
                    break ;
            }
        }
    }
    /* Clear Other Items */
    for ( x2 = ring_list_getsize(pIR)+1 ; x2 <= RING_VM_BC_ITEMS_COUNT ; x2++ ) {
        pByteCode->aData[x2-1] = NULL ;
    }
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
        nExtraSize = ring_list_getsize(pVM->pCode) - aPara[0] ;
        while ( ring_list_getsize(pVM->pCode) != aPara[0] ) {
            ring_list_deletelastitem_gc(pVM->pRingState,pVM->pCode);
        }
        if ( pVM->nEvalReallocationFlag == 1 ) {
            pVM->nEvalReallocationFlag = 0 ;
            pByteCode = (ByteCode *) ring_realloc(pVM->pByteCode , sizeof(ByteCode) * ring_list_getsize(pVM->pCode));
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

void ring_vm_error2 ( VM *pVM,const char *cStr,const char *cStr2 )
{
    String *pError  ;
    pError = ring_string_new_gc(pVM->pRingState,cStr);
    ring_string_add_gc(pVM->pRingState,pError,": ");
    ring_string_add_gc(pVM->pRingState,pError,cStr2);
    ring_vm_error(pVM,ring_string_get(pError));
    ring_string_delete_gc(pVM->pRingState,pError);
}

void ring_vm_newbytecodeitem ( VM *pVM,int x )
{
    Item *pItem  ;
    ring_list_addint_gc(pVM->pRingState,pVM->aNewByteCodeItems,0);
    pItem = ring_list_getitem(pVM->aNewByteCodeItems,ring_list_getsize(pVM->aNewByteCodeItems));
    RING_VM_IR_ITEM(x) = pItem ;
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
    nLineNumber = pVM->nLineNumber ;
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
    pVM->nLineNumber = nLineNumber ;
}

void ring_vm_init ( RingState *pRingState )
{
    Scanner *pScanner  ;
    VM *pVM  ;
    int nRunVM,nFreeFilesList = 0 ;
    /* Check file */
    if ( pRingState->pRingFilesList == NULL ) {
        pRingState->pRingFilesList = ring_list_new_gc(pRingState,0);
        pRingState->pRingFilesStack = ring_list_new_gc(pRingState,0);
        nFreeFilesList = 1 ;
    }
    ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,"Ring_EmbeddedCode");
    ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,"Ring_EmbeddedCode");
    /* Read File */
    pScanner = ring_scanner_new(pRingState);
    /* Add Token "End of Line" to the end of any program */
    ring_scanner_endofline(pScanner);
    /* Call Parser */
    nRunVM = ring_parser_start(pScanner->Tokens,pRingState);
    ring_scanner_delete(pScanner);
    /* Files List */
    ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
    if ( nFreeFilesList ) {
        /* Run the Program */
        if ( nRunVM == 1 ) {
            /* Add return to the end of the program */
            ring_scanner_addreturn(pRingState);
            pVM = ring_vm_new(pRingState);
            ring_vm_start(pRingState,pVM);
            pRingState->pVM = pVM ;
        }
    }
    return ;
}

void ring_vm_retitemref ( VM *pVM )
{
    List *pList  ;
    pVM->nRetItemRef++ ;
    /* We free the stack to avoid effects on nLoadAddressScope which is used by isstackpointertoobjstate */
    ring_vm_freestack(pVM);
    /*
    **  Check if we are in the operator method to increment the counter again 
    **  We do this to avoid another PUSHV on the list item 
    **  The first one after return expression in the operator method 
    **  The second one before return from eval() that is used by operator overloading 
    **  This to avoid using & two times like  &  & 
    */
    if ( ring_list_getsize(pVM->pFuncCallList) > 0 ) {
        pList = ring_list_getlist(pVM->pFuncCallList,ring_list_getsize(pVM->pFuncCallList));
        if ( strcmp(ring_list_getstring(pList,RING_FUNCCL_NAME),"operator") == 0 ) {
            pVM->nRetItemRef++ ;
        }
    }
}

void ring_vm_printstack ( VM *pVM )
{
    int x,nSP  ;
    printf( "\n*****************************************\n" ) ;
    printf( "Stack Size %u \n",pVM->nSP ) ;
    nSP = pVM->nSP ;
    if ( nSP > 0 ) {
        for ( x = 1 ; x <= nSP ; x++ ) {
            /* Print Values */
            if ( RING_VM_STACK_ISSTRING ) {
                printf( "(String) : %s  \n",RING_VM_STACK_READC ) ;
            }
            else if ( RING_VM_STACK_ISNUMBER ) {
                printf( "(Number) : %f  \n",RING_VM_STACK_READN ) ;
            }
            else if ( RING_VM_STACK_ISPOINTER ) {
                printf( "(Pointer) : %p  \n",RING_VM_STACK_READP ) ;
                if ( RING_VM_STACK_OBJTYPE == RING_OBJTYPE_VARIABLE ) {
                    printf( "(Pointer Type) : Variable \n" ) ;
                    ring_list_print2((List *) RING_VM_STACK_READP,pVM->nDecimals);
                }
                else if ( RING_VM_STACK_OBJTYPE ==RING_OBJTYPE_LISTITEM ) {
                    printf( "(Pointer Type) : ListItem \n" ) ;
                    ring_item_print((Item *) RING_VM_STACK_READP);
                }
            }
            RING_VM_STACK_POP ;
            printf( "\n*****************************************\n" ) ;
        }
    }
}

void ring_vm_callclassinit ( VM *pVM )
{
    if ( RING_VM_IR_READIVALUE(1) ) {
        pVM->nCallClassInit++ ;
    }
    else {
        pVM->nCallClassInit-- ;
    }
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
    printf( "\nLine %d %s \n",pVM->nLineNumber,cStr ) ;
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

void ring_vm_loadaddressfirst ( VM *pVM )
{
    pVM->nFirstAddress = 1 ;
    ring_vm_loadaddress(pVM);
    pVM->nFirstAddress = 0 ;
}

void ring_vm_endfuncexec ( VM *pVM )
{
    if ( pVM->nFuncExecute > 0 ) {
        pVM->nFuncExecute-- ;
    }
}

void ring_vm_addglobalvariables ( VM *pVM )
{
    List *pList  ;
    int x  ;
    pVM->nLoadAddressScope = RING_VARSCOPE_GLOBAL ;
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() start");
    /*
    **  Add Variables 
    **  We write variable name in lower case because Identifiers is converted to lower by Compiler(Scanner) 
    */
    ring_vm_addnewnumbervar(pVM,"true",1);
    ring_vm_addnewnumbervar(pVM,"false",0);
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() after logical variables");
    ring_vm_addnewstringvar(pVM,"nl","\n");
    ring_vm_addnewstringvar(pVM,"null","");
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() after nl and null");
    ring_vm_addnewpointervar(pVM,"ring_gettemp_var",NULL,0);
    ring_vm_addnewstringvar(pVM,"ccatcherror","NULL");
    ring_vm_addnewpointervar(pVM,"ring_settemp_var",NULL,0);
    ring_vm_addnewnumbervar(pVM,"ring_tempflag_var",0);
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() before standard files");
    ring_vm_addnewcpointervar(pVM,"stdin",stdin,"file");
    ring_vm_addnewcpointervar(pVM,"stdout",stdout,"file");
    ring_vm_addnewcpointervar(pVM,"stderr",stderr,"file");
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() after standard files");
    ring_vm_addnewpointervar(pVM,"this",NULL,0);
    ring_vm_addnewstringvar(pVM,"tab","\t");
    ring_vm_addnewstringvar(pVM,"cr","\r");
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() after adding variables");
    /* Add Command Line Parameters */
    pList = ring_vm_newvar2(pVM,"sysargv",pVM->pActiveMem);
    ring_list_setint_gc(pVM->pRingState,pList,RING_VAR_TYPE,RING_VM_LIST);
    ring_list_setlist_gc(pVM->pRingState,pList,RING_VAR_VALUE);
    pList = ring_list_getlist(pList,RING_VAR_VALUE);
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() before adding arguments");
    for ( x = 0 ; x < pVM->pRingState->argc ; x++ ) {
        ring_list_addstring_gc(pVM->pRingState,pList,pVM->pRingState->argv[x]);
    }
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() after adding arguments");
    ring_state_log(pVM->pRingState,"function: ring_vm_addglobalvariables() end");
    pVM->nLoadAddressScope = RING_VARSCOPE_NOTHING ;
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
            } while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
        }
        else {
            do {
                ring_vm_fetch(pVM);
                if ( pVM->nPC <= pVM->nEvalReturnPC ) {
                    pVM->nEvalReturnPC = 0 ;
                    break ;
                }
            } while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
        }
    #else
        do {
            ring_vm_fetch(pVM);
            if ( pVM->nPC <= pVM->nEvalReturnPC ) {
                pVM->nEvalReturnPC = 0 ;
                break ;
            }
        } while (pVM->nPC <= ring_list_getsize(pVM->pCode))  ;
    #endif
    pVM->lInsideEval-- ;
    pVM->nRetEvalDontDelete = nDontDelete ;
}
/* Threads */

RING_API void ring_vm_mutexfunctions ( VM *pVM,void *(*pFunc)(void),void (*pFuncLock)(void *),void (*pFuncUnlock)(void *),void (*pFuncDestroy)(void *) )
{
    if ( pVM->pMutex == NULL ) {
        pVM->pMutex = pFunc() ;
        pVM->pFuncMutexLock = pFuncLock ;
        pVM->pFuncMutexUnlock = pFuncUnlock ;
        pVM->pFuncMutexDestroy = pFuncDestroy ;
    }
}

RING_API void ring_vm_mutexlock ( VM *pVM )
{
    if ( pVM->pMutex != NULL ) {
        pVM->pFuncMutexLock(pVM->pMutex);
    }
}

RING_API void ring_vm_mutexunlock ( VM *pVM )
{
    if ( pVM->pMutex != NULL ) {
        pVM->pFuncMutexUnlock(pVM->pMutex);
    }
}

RING_API void ring_vm_mutexdestroy ( VM *pVM )
{
    if ( pVM->pMutex != NULL ) {
        pVM->pFuncMutexDestroy(pVM->pMutex);
        pVM->pMutex = NULL ;
    }
}

RING_API void ring_vm_runcodefromthread ( VM *pVM,const char *cStr )
{
    RingState *pState  ;
    List *pList,*pList2,*pList3,*pList4,*pList5  ;
    Item *pItem  ;
    unsigned int nMemoryBlocksCount, x  ;
    Items *pItems  ;
    /* Create the RingState */
    pState = ring_state_init();
    /*
    **  Flag that we are running from thread 
    **  We check this flag when generating hash tables of lists (for functions or scope) 
    **  In this case we generate the hash table without the memory pool 
    **  Because the memory of the current memory pool of this state will be deleted when deleting the state 
    **  And the lists of the hash table will be needed to be used by the main VM 
    */
    pState->lRunFromThread = 1 ;
    pState->nPrintInstruction = pVM->pRingState->nPrintInstruction ;
    /* Share the same Mutex between VMs */
    ring_vm_mutexlock(pVM);
    pState->pVM->pMutex = pVM->pMutex ;
    pState->pVM->pFuncMutexDestroy = pVM->pFuncMutexDestroy ;
    pState->pVM->pFuncMutexLock = pVM->pFuncMutexLock ;
    pState->pVM->pFuncMutexUnlock = pVM->pFuncMutexUnlock ;
    /* Share the global scope between threads */
    pItem = pState->pVM->pMem->pFirst->pValue ;
    pState->pVM->pMem->pFirst->pValue = pVM->pMem->pFirst->pValue ;
    /* Get Items for the Memory Pool From the Main Thread */
    ring_poolmanager_newblockfromsubthread(pState,100000,pVM->pRingState);
    /* Share Memory Blocks (Could be used for Lists in Global Scope) */
    nMemoryBlocksCount = ring_list_getsize(pVM->pRingState->vPoolManager.aBlocks) ;
    /*
    **  Thread Safe Code instead of ring_list_copy(pState->vPoolManager.aBlocks,pVM->pRingState->vPoolManager.aBlocks) 
    **  Because the List structure contains (Cache) that we update when we access each item 
    **  So we use the next code to avoid using/updating this cache 
    */
    if ( nMemoryBlocksCount > 0 ) {
        pItems = pVM->pRingState->vPoolManager.aBlocks->pFirst ;
        while ( pItems != NULL ) {
            /* Copy the Sub List - Each sub list contains two items [ Pointer, Pointer ] */
            if ( pItems->pValue != NULL ) {
                pList = ring_item_getlist(pItems->pValue) ;
                if ( pList != NULL ) {
                    if ( (pList->pFirst != NULL) && (pList->pLast != NULL) ) {
                        if ( (pList->pFirst->pValue != NULL) && (pList->pLast->pValue != NULL) ) {
                            pList2 = ring_list_newlist(pState->vPoolManager.aBlocks);
                            ring_list_addpointer(pList2,ring_item_getpointer(pList->pFirst->pValue));
                            ring_list_addpointer(pList2,ring_item_getpointer(pList->pLast->pValue));
                        }
                    }
                }
            }
            pItems = pItems->pNext ;
        }
    }
    /* Save the state */
    pList = pState->pVM->pCode ;
    pList2 = pState->pVM->pFunctionsMap ;
    pList3 = pState->pVM->pClassesMap ;
    pList4 = pState->pVM->pPackagesMap ;
    pList5 = pState->pVM->pCFunctionsList ;
    /*
    **  Share the code between the VMs 
    **  Copy Functions/Classes/Packages lists 
    */
    pState->pVM->pFunctionsMap = ring_list_new(0) ;
    pState->pVM->pClassesMap = ring_list_new(0) ;
    pState->pVM->pPackagesMap = ring_list_new(0) ;
    pState->pVM->pCFunctionsList = ring_list_new(0) ;
    ring_list_copy(pState->pVM->pFunctionsMap,pVM->pRingState->pRingFunctionsMap);
    ring_list_copy(pState->pVM->pClassesMap,pVM->pRingState->pRingClassesMap);
    ring_list_copy(pState->pVM->pPackagesMap,pVM->pRingState->pRingPackagesMap);
    ring_list_copy(pState->pVM->pCFunctionsList,pVM->pRingState->pRingCFunctions);
    ring_list_genarray(pState->pVM->pCFunctionsList);
    ring_list_genhashtable2(pState->pVM->pCFunctionsList);
    pState->pRingFunctionsMap = pState->pVM->pFunctionsMap ;
    pState->pRingClassesMap = pState->pVM->pClassesMap ;
    pState->pRingPackagesMap = pState->pVM->pPackagesMap ;
    pState->pRingCFunctions = pState->pVM->pCFunctionsList ;
    /* Get a copy from the byte code List */
    pState->pVM->nScopeID = pVM->nScopeID + 10000 ;
    pState->pVM->pCode = ring_list_new_gc(pState,0) ;
    ring_list_copy(pState->pVM->pCode,pVM->pRingState->pRingGenCode);
    pState->pRingGenCode = pState->pVM->pCode ;
    ring_vm_loadcode(pState->pVM);
    /* Avoid the call to the main function */
    pState->pVM->nCallMainFunction = 1 ;
    ring_vm_mutexunlock(pVM);
    /* Run the code */
    ring_state_runcode(pState,cStr);
    ring_vm_mutexlock(pVM);
    /* Return Memory Pool Items to the Main Thread */
    ring_poolmanager_deleteblockfromsubthread(pState,pVM->pRingState);
    /* Delete Code List */
    ring_list_delete_gc(pState,pState->pVM->pCode);
    ring_list_delete_gc(pState,pState->pVM->pFunctionsMap);
    ring_list_delete_gc(pState,pState->pVM->pClassesMap);
    ring_list_delete_gc(pState,pState->pVM->pPackagesMap);
    ring_list_delete_gc(pState,pState->pVM->pCFunctionsList);
    /* Restore the first scope - global scope */
    pState->pVM->pMem->pFirst->pValue = pItem ;
    /* Avoid deleting the shared lists and the Mutex */
    pState->pVM->pCode = pList ;
    pState->pVM->pFunctionsMap = pList2 ;
    pState->pVM->pClassesMap = pList3 ;
    pState->pVM->pPackagesMap = pList4 ;
    pState->pVM->pCFunctionsList = pList5 ;
    pState->pRingGenCode = pList ;
    pState->pRingFunctionsMap = pList2 ;
    pState->pRingClassesMap = pList3 ;
    pState->pRingPackagesMap = pList4 ;
    pState->pRingCFunctions = pList5 ;
    pState->pVM->pMutex = NULL ;
    pState->pVM->pFuncMutexDestroy = NULL ;
    pState->pVM->pFuncMutexLock = NULL ;
    pState->pVM->pFuncMutexUnlock = NULL ;
    /* Avoid deleting the Shared Memory Blocks */
    if ( nMemoryBlocksCount > 0 ) {
        for ( x = 1 ; x <=nMemoryBlocksCount ; x++ ) {
            ring_list_deleteitem(pState->vPoolManager.aBlocks,1);
        }
    }
    ring_vm_mutexunlock(pVM);
    /* Avoid deleting the Mutex */
    pState->pVM->pMutex = NULL ;
    /* Delete the RingState */
    ring_state_delete(pState);
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
        ring_list_adddouble_gc(pVM->pRingState,pVM->pTraceData,pVM->nLineNumber);
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

/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#include "ring.h"
/*
**  Functions 
**  Main Functions 
*/

VM * ring_vm_new ( RingState *pRingState )
{
    VM *pVM  ;
    int x  ;
    pVM = (VM *) ring_state_malloc(pRingState,sizeof(VM));
    /* Ring State */
    pVM->pRingState = pRingState ;
    pRingState->pVM = pVM ;
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
    /* Add Variables */
    ring_vm_addglobalvariables(pVM);
    /* Lists */
    pVM->nListStart = 0 ;
    pVM->pNestedLists = ring_list_new_gc(pVM->pRingState,0);
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
    return pVM ;
}

VM * ring_vm_delete ( VM *pVM )
{
    int x  ;
    List *pRecord  ;
    Item *pItem  ;
    assert(pVM != NULL);
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
    /* Free Stack */
    for ( x = 0 ; x < RING_VM_STACK_SIZE ; x++ ) {
        ring_item_content_delete(&(pVM->aStack[x]));
    }
    /* Delete the bytecode */
    for ( x = 1 ; x <= RING_VM_INSTRUCTIONSCOUNT ; x++ ) {
        ring_vm_deletebytecode(pVM,x);
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

void ring_vm_start ( RingState *pRingState,VM *pVM )
{
    pVM->pCode = pRingState->pRingGenCode ;
    pVM->pFunctionsMap = pRingState->pRingFunctionsMap ;
    pVM->pClassesMap = pRingState->pRingClassesMap ;
    pVM->pPackagesMap = pRingState->pRingPackagesMap ;
    ring_vm_loadcode(pVM);
    ring_vm_loadcfunctions(pRingState);
    /* Generate Items Array &  Hash Table */
    ring_list_genarray(pRingState->pRingCFunctions);
    ring_list_genhashtable2(pRingState->pRingCFunctions);
    if ( RING_VM_INSTRUCTIONSCOUNT > 0 ) {
        pVM->nPC = 1 ;
        ring_vm_mainloop(pVM);
    }
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
/* ByteCode Functions */

RING_API void ring_vm_loadcode ( VM *pVM )
{
    int x,nSize  ;
    /*
    **  We may allocation double of the size that we need to avoid reallocation when we use eval() 
    **  eval() will check if there is a need to reallocation or not 
    **  This optimization increase the performance of applications that uses eval() 
    */
    #if RING_MSDOS
        nSize = RING_VM_INSTRUCTIONSLISTSIZE ;
    #else
        nSize = (RING_MAX(RING_VM_INSTRUCTIONSLISTSIZE,RING_VM_MINVMINSTRUCTIONS))+RING_VM_EXTRASIZE ;
    #endif
    pVM->pByteCode = (ByteCode *) ring_calloc(nSize,sizeof(ByteCode));
    for ( x = 1 ; x <= RING_VM_INSTRUCTIONSLISTSIZE ; x++ ) {
        ring_vm_tobytecode(pVM,x);
    }
    pVM->nEvalReallocationSize = nSize ;
    pVM->pRingState->nInstructionsCount = ring_list_getsize(pVM->pCode) ;
    ring_list_deleteallitems_gc(pVM->pRingState,pVM->pRingState->pRingGenCode);
}

void ring_vm_tobytecode ( VM *pVM,int nIns )
{
    List *pIR  ;
    int x,nType  ;
    ByteCode *pByteCode  ;
    Item *pItem  ;
    String *pString  ;
    pByteCode = pVM->pByteCode + pVM->pRingState->nInstructionsCount + nIns - 1 ;
    pIR = ring_list_getlist(pVM->pCode,nIns);
    /* Check Instruction Size */
    if ( ring_list_getsize(pIR) > RING_VM_BC_ITEMS_COUNT+1 ) {
        printf( RING_LONGINSTRUCTION ) ;
        printf( "In File : %s  - Byte-Code PC : %d  ",pVM->cFileName,nIns ) ;
        exit(1);
    }
    /* Get the Operation Code */
    pItem = ring_list_getitem(pIR,1) ;
    /* Avoid Performance Instructions (Happens when called from New Thread) */
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
    pByteCode->nOPCode = pItem->data.iNumber ;
    /* Get Instruction Parameters Count */
    pByteCode->nInsSize = ring_list_getsize(pIR) ;
    /* Set the Registers Type */
    pByteCode->nReg1Type = RING_VM_REGTYPE_NOTHING ;
    pByteCode->nReg2Type = RING_VM_REGTYPE_NOTHING ;
    pByteCode->nReg3Type = RING_VM_REGTYPE_NOTHING ;
    for ( x = 2 ; x <= ring_list_getsize(pIR) ; x++ ) {
        pItem = ring_list_getitem(pIR,x) ;
        /* Copy the item data */
        switch ( pItem->nType ) {
            case ITEMTYPE_NUMBER :
                if ( ring_item_isdouble(pItem) ) {
                    pByteCode->aReg[x-2].dNumber = ring_item_getdouble(pItem) ;
                    nType = RING_VM_REGTYPE_DOUBLE ;
                }
                else {
                    pByteCode->aReg[x-2].iNumber = ring_item_getint(pItem) ;
                    nType = RING_VM_REGTYPE_INT ;
                }
                break ;
            case ITEMTYPE_STRING :
                pString = ring_item_getstring(pItem) ;
                pByteCode->aReg[x-2].pString = ring_string_new2_gc(NULL,ring_string_get(pString),ring_string_size(pString)) ;
                nType = RING_VM_REGTYPE_STRING ;
                break ;
            case ITEMTYPE_POINTER :
                pByteCode->aReg[x-2].pPointer = ring_item_getpointer(pItem) ;
                nType = RING_VM_REGTYPE_POINTER ;
                break ;
        }
        /* Set the Register type */
        switch ( x-2 ) {
            case 0 :
                pByteCode->nReg1Type = nType ;
                break ;
            case 1 :
                pByteCode->nReg2Type = nType ;
                break ;
            case 2 :
                pByteCode->nReg3Type = nType ;
                break ;
        }
    }
}

void ring_vm_deletebytecode ( VM *pVM,int nIns )
{
    int x  ;
    ByteCode *pByteCode  ;
    pVM->pByteCodeIR = pVM->pByteCode + nIns - 1 ;
    ring_vm_clearregisterstring(pVM,1);
    ring_vm_clearregisterstring(pVM,2);
    ring_vm_clearregisterstring(pVM,3);
}

void ring_vm_clearregisterstring ( VM *pVM,int nReg )
{
    switch ( nReg ) {
        case 1 :
            if ( pVM->pByteCodeIR->nReg1Type == RING_VM_REGTYPE_STRING ) {
                ring_string_delete_gc(pVM->pRingState,pVM->pByteCodeIR->aReg[0].pString);
                pVM->pByteCodeIR->nReg1Type = RING_VM_REGTYPE_NOTHING ;
            }
            break ;
        case 2 :
            if ( pVM->pByteCodeIR->nReg2Type == RING_VM_REGTYPE_STRING ) {
                ring_string_delete_gc(pVM->pRingState,pVM->pByteCodeIR->aReg[1].pString);
                pVM->pByteCodeIR->nReg2Type = RING_VM_REGTYPE_NOTHING ;
            }
            break ;
        case 3 :
            if ( pVM->pByteCodeIR->nReg3Type == RING_VM_REGTYPE_STRING ) {
                ring_string_delete_gc(pVM->pRingState,pVM->pByteCodeIR->aReg[2].pString);
                pVM->pByteCodeIR->nReg3Type = RING_VM_REGTYPE_NOTHING ;
            }
            break ;
    }
}

void ring_vm_setreg1topointerfromstack ( VM * pVM )
{
    RING_VM_IR_CLEARREG1STRING ;
    RING_VM_IR_ITEMSETPOINTER(RING_VM_IR_ITEM(1),RING_VM_STACK_READP);
    RING_VM_IR_SETREG1TYPE(RING_VM_REGTYPE_POINTER) ;
}

void ring_vm_showbytecode ( VM *pVM )
{
    int x,y,nCount,nCount2,nType  ;
    ByteCode *pByteCode  ;
    /* Print Header */
    printf( "\n\n" ) ;
    ring_general_printline();
    puts(" Byte Code - After Execution by the VM");
    ring_general_printline();
    /* Print the ByteCode */
    nCount = RING_VM_INSTRUCTIONSCOUNT ;
    if ( nCount > 0 ) {
        printf( "\n %6s  %18s  %29s\n", "PC","OPCode","Data" ) ;
        for ( x = 1 ; x <= nCount ; x++ ) {
            /* Get the Instruction */
            pByteCode = pVM->pByteCode + x - 1 ;
            nCount2 = pByteCode->nInsSize - 1 ;
            printf( "\n %6d  %18s  ", x , RING_IC_OP[pByteCode->nOPCode] ) ;
            if ( nCount2 > 0 ) {
                for ( y = 0 ; y < nCount2 ; y++ ) {
                    /* Get The Register Type */
                    if ( y == 0 ) {
                        nType = pByteCode->nReg1Type ;
                    }
                    else if ( y == 1 ) {
                        nType = pByteCode->nReg2Type ;
                    }
                    else {
                        nType = pByteCode->nReg3Type ;
                    }
                    /* Display the Register Value */
                    switch ( nType ) {
                        case RING_VM_REGTYPE_STRING :
                            printf( " %12s ",ring_string_get(pByteCode->aReg[y].pString) ) ;
                            break ;
                        case RING_VM_REGTYPE_INT :
                            printf( " %12d ",pByteCode->aReg[y].iNumber ) ;
                            break ;
                        case RING_VM_REGTYPE_DOUBLE :
                            printf( " %12f",pByteCode->aReg[y].dNumber ) ;
                            break ;
                        case RING_VM_REGTYPE_POINTER :
                            printf( " %12p ",pByteCode->aReg[y].pPointer ) ;
                            break ;
                    }
                }
            }
        }
        printf( "\n" ) ;
    }
    /* Print Footer */
    puts("");
    ring_general_printline();
    puts("");
}
/* Main Loop Functions */

void ring_vm_mainloop ( VM *pVM )
{
    pVM->pRingState->lStartPoolManager = 1 ;
    /* Allows showing the OPCODE */
    if ( pVM->pRingState->nPrintInstruction ) {
        do {
            ring_vm_fetch2(pVM);
        } while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT)  ;
    }
    else {
        do {
            ring_vm_fetch(pVM);
        } while (pVM->nPC <= RING_VM_INSTRUCTIONSCOUNT)  ;
    }
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
    if ( pVM->pRingState->nPrintInstruction ) {
        ring_general_printline();
        printf( "VM Pointer    : %p  " , (void *) pVM ) ;
        printf( "\nVM IR Pointer : %p  " , (void *) pVM->pByteCodeIR ) ;
        printf( "\nOperation     : %s  " , RING_IC_OP[pVM->nOPCode] ) ;
        printf( "\nPC            : %d  " ,pVM->nPC ) ;
        printf( "\nScopes Count  : %d  " ,ring_list_getsize(pVM->pMem) ) ;
        printf( "\nScope Pointer : %p  " ,pVM->pActiveMem ) ;
        printf( "\nFile Name     : %s \nLine Number   : %d\n" ,pVM->cFileName,RING_VM_IR_GETLINENUMBER ) ;
        if ( (pVM->nOPCode == ICO_PUSHC) || (pVM->nOPCode == ICO_LOADADDRESS) || (pVM->nOPCode == ICO_LOADFUNC) ) {
            printf( "Data          : %s \n",RING_VM_IR_READC ) ;
        }
    }
    pVM->nPC++ ;
    ring_vm_execute(pVM);
    if ( pVM->pRingState->nPrintInstruction ) {
        printf( "\nSP (After)    : %d  \nFuncSP        : %d \nLineNumber    : %d \n" , (int) pVM->nSP,pVM->nFuncSP,RING_VM_IR_GETLINENUMBER ) ;
    }
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
            RING_VM_JUMP ;
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
        case ICO_POW :
            ring_vm_pow(pVM);
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
            ring_vm_oop_callclassinit(pVM);
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

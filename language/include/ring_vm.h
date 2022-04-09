/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vm_h
    #define ring_vm_h
    /*
    **  Data 
    **  Stack Size 
    */
    #define RING_VM_STACK_SIZE 256
    #define RING_VM_STACK_CHECKOVERFLOW 253
    #define RING_VM_FREE_STACK_IN_CLASS_REGION_AFTER 100
    #define RING_VM_BC_ITEMS_COUNT 24
    #define RING_VM_STATE_NUMBERS_COUNT 35
    #define RING_VM_STATE_POINTERS_COUNT 10
    #define RING_VM_MAXDIGITSINNUMBER 15
    typedef struct ByteCode {
        Item *aData[RING_VM_BC_ITEMS_COUNT]  ;
        char nSize  ;
        List *pList  ;
    } ByteCode ;
    typedef struct VM {
        int nPC  ;
        List *pCode  ;
        List *pFunctionsMap  ;
        List *pClassesMap  ;
        List *pPackagesMap  ;
        int nOPCode  ;
        Item aStack[RING_VM_STACK_SIZE]  ;
        unsigned char nSP  ;
        List *pMem  ;
        List *pActiveMem  ;
        List *pTempMem  ;
        ByteCode *pByteCode  ;
        ByteCode *pByteCodeIR  ;
        char *cFileName  ;
        int nLineNumber  ;
        int nListStart  ;
        List *pNestedLists  ;
        int nBlockFlag  ;
        List *aPCBlockFlag  ;
        List *pFuncCallList  ;
        int nFuncSP  ;
        int nFuncExecute  ;
        List *pCFunctionsList  ;
        List *pExitMark  ;
        List *pLoopMark  ;
        int nCallMainFunction  ;
        List *pTry  ;
        List *aScopeNewObj  ;
        char nCallMethod  ;
        List *pObjState  ;
        List *pBraceObject  ;
        List *aBraceObjects  ;
        int nVarScope  ;
        int nScopeID  ;
        List *aScopeID  ;
        int nActiveScopeID  ;
        int nActiveCatch  ;
        char nInsideBraceFlag  ;
        char nInClassRegion  ;
        List *aActivePackage  ;
        char nPrivateFlag  ;
        char nGetSetProperty  ;
        void *pGetSetObject  ;
        char nGetSetObjType  ;
        List *aSetProperty  ;
        void *pAssignment  ;
        List *aForStep  ;
        char nFirstAddress  ;
        char nBeforeEqual  ;
        char nNOAssignment  ;
        RingState *pRingState  ;
        int nLoadAddressScope  ;
        List *aBeforeObjState  ;
        List *aAddressScope  ;
        int nFuncExecute2  ;
        List *aNewByteCodeItems  ;
        char nEvalCalledFromRingCode  ;
        char nDecimals  ;
        char nEvalReallocationFlag  ;
        int nEvalReallocationSize  ;
        int nCFuncParaCount  ;
        char nIgnoreNULL  ;
        int nEvalReturnPC  ;
        char nRetItemRef  ;
        void (*pFuncMutexDestroy)(void *) ;
        void (*pFuncMutexLock)(void *) ;
        void (*pFuncMutexUnlock)(void *) ;
        void *pMutex  ;
        char nIgnoreCPointerTypeCheck  ;
        char nCallClassInit  ;
        char nRetEvalDontDelete  ;
        char *cPrevFileName  ;
        char nRunCode  ;
        char nActiveError  ;
        String *pPackageName  ;
        char lTrace  ;
        String *pTrace  ;
        char lTraceActive  ;
        char nTraceEvent  ;
        List *pTraceData  ;
        char nEvalInScope  ;
        char lPassError  ;
        char lHideErrorMsg  ;
        List *aGlobalScopes  ;
        List *aActiveGlobalScopes  ;
        int nCurrentGlobalScope  ;
        char *cFileNameInClassRegion  ;
        char lUsePushPLocal  ;
        char lInsideEval  ;
        List *pCLibraries  ;
        char lNoSetterMethod  ;
        char lCheckOverFlow  ;
        char lAddSubListsByMove  ;
        char lAddSubListsByFastCopy  ;
        char lExitFlag  ;
    } VM ;
    typedef struct VMState {
        int aNumbers[RING_VM_STATE_NUMBERS_COUNT]  ;
        void *aPointers[RING_VM_STATE_POINTERS_COUNT]  ;
    } VMState ;
    /*
    **  Macro 
    **  Stack 
    **  Add 
    */
    #define RING_VM_STACK_PUSHC pVM->nSP++ ; ring_itemarray_setstring2(pVM->aStack, pVM->nSP, ring_string_get(pVM->pByteCodeIR->aData[1]->data.pString), ring_string_size(pVM->pByteCodeIR->aData[1]->data.pString))
    #define RING_VM_STACK_PUSHN pVM->nSP++ ; ring_itemarray_setdouble(pVM->aStack, pVM->nSP , pVM->pByteCodeIR->aData[1]->data.dNumber)
    #define RING_VM_STACK_PUSHP pVM->nSP++ ; ring_itemarray_setpointer(pVM->aStack, pVM->nSP , pVM->pByteCodeIR->aData[1]->data.pPointer )
    /* Note, use RING_VM_STACK_OBJTYPE to read/write the pointer type */
    #define RING_VM_STACK_TRUE ring_itemarray_setdouble(pVM->aStack,pVM->nSP, 1)
    #define RING_VM_STACK_FALSE ring_itemarray_setdouble(pVM->aStack,pVM->nSP, 0)
    #define RING_VM_STACK_PUSHCVAR ring_itemarray_setstring2(pVM->aStack,pVM->nSP,ring_list_getstring(pVar,3),ring_list_getstringsize(pVar,3))
    #define RING_VM_STACK_PUSHNVAR ring_itemarray_setdouble(pVM->aStack,pVM->nSP,ring_list_getdouble(pVar,3))
    #define RING_VM_STACK_PUSHPVALUE(x) pVM->nSP++ ; ring_itemarray_setpointer(pVM->aStack, pVM->nSP , x )
    #define RING_VM_STACK_PUSHCVALUE(x) pVM->nSP++ ; ring_itemarray_setstring(pVM->aStack, pVM->nSP, x)
    #define RING_VM_STACK_PUSHNVALUE(x) pVM->nSP++ ; ring_itemarray_setdouble(pVM->aStack, pVM->nSP , x)
    #define RING_VM_STACK_SETCVALUE(x) ring_itemarray_setstring(pVM->aStack, pVM->nSP, x)
    #define RING_VM_STACK_SETNVALUE(x) ring_itemarray_setdouble(pVM->aStack, pVM->nSP , x)
    #define RING_VM_STACK_SETPVALUE(x) ring_itemarray_setpointer(pVM->aStack, pVM->nSP , x )
    #define RING_VM_STACK_SETCVALUE2(x,y) ring_itemarray_setstring2(pVM->aStack, pVM->nSP, x,y)
    #define RING_VM_STACK_SETCSIZE(x) ring_itemarray_setstring2(pVM->aStack, pVM->nSP, NULL,x)
    #define RING_VM_STACK_PUSHCVALUE2(x,y) pVM->nSP++ ; ring_itemarray_setstring2(pVM->aStack, pVM->nSP, x,y)
    /* Check */
    #define RING_VM_STACK_ISSTRING ring_itemarray_isstring(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_ISNUMBER ring_itemarray_isnumber(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_ISPOINTER ring_itemarray_ispointer(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_ISPOINTERVALUE(x) ring_itemarray_ispointer(pVM->aStack,x)
    /* Read */
    #define RING_VM_STACK_READC ring_itemarray_getstring(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_GETSTRINGRAW ring_itemarray_getstringraw(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_STRINGSIZE ring_itemarray_getstringsize(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_READN ring_itemarray_getdouble(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_READP ring_itemarray_getpointer(pVM->aStack,pVM->nSP)
    #define RING_VM_STACK_OBJTYPE pVM->aStack[pVM->nSP].nObjectType
    #define RING_VM_STACK_PREVOBJTYPE pVM->aStack[pVM->nSP-1].nObjectType
    /* Delete */
    #define RING_VM_STACK_POP pVM->nSP--
    /* Objects/Pointer  - Type */
    #define RING_OBJTYPE_VARIABLE 1
    #define RING_OBJTYPE_LISTITEM 2
    #define RING_OBJTYPE_SUBSTRING 3
    /* Variable Structure */
    #define RING_VAR_NAME 1
    #define RING_VAR_TYPE 2
    #define RING_VAR_VALUE 3
    #define RING_VAR_PVALUETYPE 4
    #define RING_VAR_PRIVATEFLAG 5
    /* Number of global variables defined by the VM like True, False, cErrorMsg */
    #define RING_VM_INTERNALGLOBALSCOUNT 14
    #define RING_VAR_LISTSIZE 5
    /* Variable Type */
    #define RING_VM_NULL 0
    #define RING_VM_STRING 1
    #define RING_VM_NUMBER 2
    #define RING_VM_LIST 3
    #define RING_VM_POINTER 4
    /* IR (Instruction Register) */
    #define RING_VM_JUMP pVM->nPC = pVM->pByteCodeIR->aData[1]->data.iNumber
    #define RING_VM_IR_READC ring_string_get(pVM->pByteCodeIR->aData[1]->data.pString)
    #define RING_VM_IR_READCVALUE(x) ring_string_get(pVM->pByteCodeIR->aData[x]->data.pString)
    #define RING_VM_IR_READP pVM->pByteCodeIR->aData[1]->data.pPointer
    #define RING_VM_IR_READPVALUE(x) pVM->pByteCodeIR->aData[x]->data.pPointer
    #define RING_VM_IR_READI pVM->pByteCodeIR->aData[1]->data.iNumber
    #define RING_VM_IR_READIVALUE(x) pVM->pByteCodeIR->aData[x]->data.iNumber
    #define RING_VM_IR_READD pVM->pByteCodeIR->aData[1]->data.dNumber
    #define RING_VM_IR_READDVALUE(x) pVM->pByteCodeIR->aData[x]->data.dNumber
    #define RING_VM_IR_PARACOUNT pVM->pByteCodeIR->nSize
    #define RING_VM_IR_OPCODE pVM->pByteCodeIR->aData[0]->data.iNumber
    #define RING_VM_IR_SETCVALUE(x,y) ring_string_set_gc(pVM->pRingState,pVM->pByteCodeIR->aData[x]->data.pString,y)
    #define RING_VM_IR_ITEM(x) pVM->pByteCodeIR->aData[x]
    #define RING_VM_IR_LIST pVM->pByteCodeIR->pList
    #define RING_VM_IR_LOAD pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 1
    #define RING_VM_IR_UNLOAD pVM->pByteCodeIR = pVM->pByteCode + pVM->nPC - 2
    #define RING_VM_IR_TEMPITEM (&((pVM->pByteCode + pVM->nPC - 2)->vTempItem))
    /*
    **  Calling Functions 
    **  Note : When you insert items check performance functions for update too! 
    **  pFuncCallList ( Type, Func Name , Position(PC) , Stack Pointer , TempMem, ... 
    **  Types 
    */
    #define RING_FUNCTYPE_SCRIPT 1
    #define RING_FUNCTYPE_C 2
    #define RING_FUNCCL_TYPE 1
    #define RING_FUNCCL_NAME 2
    #define RING_FUNCCL_PC 3
    #define RING_FUNCCL_SP 4
    #define RING_FUNCCL_TEMPMEM 5
    #define RING_FUNCCL_FILENAME 6
    #define RING_FUNCCL_NEWFILENAME 7
    #define RING_FUNCCL_METHODORFUNC 8
    #define RING_FUNCCL_LINENUMBER 9
    #define RING_FUNCCL_LISTSTART 10
    #define RING_FUNCCL_NESTEDLISTS 11
    #define RING_FUNCCL_CALLERPC 12
    #define RING_FUNCCL_FUNCEXE 13
    #define RING_FUNCCL_STATE 14
    #define RING_FUNCCL_TEMPMEMSIZEATSTART 15
    /* pFunctionsMap ( Func Name , Position , File Name, Private Flag) */
    #define RING_FUNCMAP_NAME 1
    #define RING_FUNCMAP_PC 2
    #define RING_FUNCMAP_FILENAME 3
    #define RING_FUNCMAP_PRIVATEFLAG 4
    /* FunctionMap List Size */
    #define RING_FUNCMAP_NORMALSIZE 4
    /* Variable Scope */
    #define RING_VARSCOPE_NOTHING 0
    #define RING_VARSCOPE_LOCAL 1
    #define RING_VARSCOPE_OBJSTATE 2
    #define RING_VARSCOPE_GLOBAL 3
    #define RING_VARSCOPE_NEWOBJSTATE 4
    /*
    **  OOP 
    **  pClassesMap 
    */
    #define RING_CLASSMAP_CLASSNAME 1
    #define RING_CLASSMAP_PC 2
    #define RING_CLASSMAP_PARENTCLASS 3
    #define RING_CLASSMAP_METHODSLIST 4
    #define RING_CLASSMAP_FLAGISPARENTCLASSINFCOLLECTED 5
    #define RING_CLASSMAP_POINTERTOPACKAGE 6
    #define RING_CLASSMAP_POINTERTOLISTOFCLASSINSIDEPACKAGE 2
    #define RING_CLASSMAP_POINTERTOFILENAME 3
    #define RING_CLASSMAP_IMPORTEDCLASSSIZE 3
    /* Packages */
    #define RING_PACKAGENAME 1
    #define RING_CLASSESLIST 2
    /* Object */
    #define RING_OBJECT_CLASSPOINTER 1
    #define RING_OBJECT_OBJECTDATA 2
    #define RING_OBJECT_SELFATTRIBUTE 1
    /* pObjState */
    #define RING_OBJSTATE_SCOPE 1
    #define RING_OBJSTATE_METHODS 2
    #define RING_OBJSTATE_CLASS 3
    /* Operator Overloading */
    #define RING_OOPARA_STRING 1
    #define RING_OOPARA_NUMBER 2
    #define RING_OOPARA_POINTER 3
    /* aBraceObjects */
    #define RING_ABRACEOBJECTS_BRACEOBJECT 1
    /* aScopeNewObj */
    #define RING_ASCOPENEWOBJ_SP 1
    /* State */
    #define RING_STATE_TRYCATCH 1
    #define RING_STATE_EXIT 2
    #define RING_STATE_RETURN 3
    /* Memory */
    #define RING_MEMORY_GLOBALSCOPE 1
    /* Lists & List as Hash */
    #define RING_LISTHASH_KEY 1
    #define RING_LISTHASH_VALUE 2
    #define RING_LISTHASH_SIZE 2
    #define RING_LIST_CHECKOPERATIONONSUBLIST ( ring_vm_isoperationaftersublist(pVM) )
    /* C Pointer List (inside Variable Value) */
    #define RING_CPOINTER_POINTER 1
    #define RING_CPOINTER_TYPE 2
    #define RING_CPOINTER_STATUS 3
    #define RING_CPOINTER_LISTSIZE 3
    /* C Pointer Status */
    #define RING_CPOINTERSTATUS_NOTCOPIED 0
    #define RING_CPOINTERSTATUS_COPIED 1
    #define RING_CPOINTERSTATUS_NOTASSIGNED 2
    /* Temp Object */
    #define RING_TEMP_VARIABLE "ring_sys_temp"
    /* Trace */
    #define RING_VM_TRACEEVENT_NEWLINE 1
    #define RING_VM_TRACEEVENT_NEWFUNC 2
    #define RING_VM_TRACEEVENT_RETURN 3
    #define RING_VM_TRACEEVENT_ERROR 4
    #define RING_VM_TRACEEVENT_BEFORECFUNC 5
    #define RING_VM_TRACEEVENT_AFTERCFUNC 6
    /* Loops */
    #define RING_COMMANDTYPE_EXIT 1
    #define RING_COMMANDTYPE_LOOP 2
    /* Runtime Error Messages */
    #define RING_VM_ERROR_DIVIDEBYZERO "Error (R1) : Can't divide by zero !"
    #define RING_VM_ERROR_INDEXOUTOFRANGE "Error (R2) : Array Access (Index out of range) !"
    #define RING_VM_ERROR_FUNCNOTFOUND "Error (R3) : Calling Function without definition !"
    #define RING_VM_ERROR_STACKOVERFLOW "Error (R4) : Stack Overflow !"
    #define RING_VM_ERROR_OBJECTISNOTLIST "Error (R5) : Can't access the list item, Object is not list !"
    #define RING_VM_ERROR_NOTVARIABLE "Error (R6) : Variable is required"
    #define RING_VM_ERROR_VALUEMORETHANONECHAR "Error (R7) : Can't assign to a string letter more than one character"
    #define RING_VM_ERROR_VARISNOTSTRING "Error (R8) : Variable is not a string "
    #define RING_VM_ERROR_EXITWITHOUTLOOP "Error (R9) : Using exit command outside loops "
    #define RING_VM_ERROR_EXITNUMBEROUTSIDERANGE "Error (R10) : Using exit command with number outside the range "
    #define RING_VM_ERROR_CLASSNOTFOUND "Error (R11) : error in class name, class not found! "
    #define RING_VM_ERROR_PROPERTYNOTFOUND "Error (R12) : error in property name, property not found! "
    #define RING_VM_ERROR_NOTOBJECT "Error (R13) : Object is required"
    #define RING_VM_ERROR_METHODNOTFOUND "Error (R14) : Calling Method without definition !"
    #define RING_VM_ERROR_PARENTCLASSNOTFOUND "Error (R15) : error in parent class name, class not found! "
    #define RING_VM_ERROR_BRACEWITHOUTOBJECT "Error (R16) : Using braces to access unknown object ! "
    #define RING_VM_ERROR_SUPERCLASSNOTFOUND "Error (R17) : error, using 'Super' without parent class! "
    #define RING_VM_ERROR_NUMERICOVERFLOW "Error (R18) : Numeric Overflow! "
    #define RING_VM_ERROR_LESSPARAMETERSCOUNT "Error (R19) : Calling function with less number of parameters!"
    #define RING_VM_ERROR_EXTRAPARAMETERSCOUNT "Error (R20) : Calling function with extra number of parameters!"
    #define RING_VM_ERROR_BADVALUES "Error (R21) : Using operator with values of incorrect type"
    #define RING_VM_ERROR_LOOPWITHOUTLOOP "Error (R22) : Using loop command outside loops "
    #define RING_VM_ERROR_LOOPNUMBEROUTSIDERANGE "Error (R23) : Using loop command with number outside the range "
    #define RING_VM_ERROR_USINGNULLVARIABLE "Error (R24) : Using uninitialized variable "
    #define RING_VM_ERROR_PACKAGENOTFOUND "Error (R25) : Error in package name, Package not found! "
    #define RING_VM_ERROR_CALLINGPRIVATEMETHOD "Error (R26) : Calling private method from outside the class "
    #define RING_VM_ERROR_USINGPRIVATEATTRIBUTE "Error (R27) : Using private attribute from outside the class "
    #define RING_VM_ERROR_FORSTEPDATATYPE "Error (R28) : Using bad data type as step value"
    #define RING_VM_ERROR_FORLOOPDATATYPE "Error (R29) : Using bad data type in for loop"
    #define RING_VM_ERROR_PARENTCLASSLIKESUBCLASS "Error (R30) : parent class name is identical to child class name "
    #define RING_VM_ERROR_TRYINGTOMODIFYTHESELFPOINTER "Error (R31) : Trying to destroy the object using the self reference "
    #define RING_VM_ERROR_BADCALLPARA "Error (R32) : The CALL command expect a variable contains string!"
    #define RING_VM_ERROR_BADDECIMALNUMBER "Error (R33) : Bad decimals number (correct range >= 0 and <= 90)"
    #define RING_VM_ERROR_ASSIGNNOTVARIABLE "Error (R34) : Variable is required for the assignment operation"
    #define RING_VM_ERROR_CANTOPENFILE "Error (R35) : Can't create/open the file!"
    #define RING_VM_ERROR_BADCOLUMNNUMBER "Error (R36) : The column number is not correct! It's greater than the number of columns in the list"
    #define RING_VM_ERROR_BADCOMMAND "Error (R37) : Sorry, The command is not supported in this context"
    #define RING_VM_ERROR_LIBLOADERROR "Error (R38) : Runtime Error in loading the dynamic library!"
    #define RING_VM_ERROR_TEMPFILENAME "Error (R39) : Error occurred creating unique filename."
    #define RING_VM_ERROR_NUMERICUNDERFLOW "Error (R40) : Numeric underflow!"
    #define RING_VM_ERROR_NUMERICINVALID "Error (R41) : Invalid numeric string"
    /* Extra Size (for eval) */
    #define RING_VM_EXTRASIZE 2
    #define RING_VM_MINVMINSTRUCTIONS 100000
    #define RING_MAX(a,b) (((a)>(b))?(a):(b))
    /* Variables Location */
    #define RING_VM_STATICVAR_THIS 12
    /*
    **  Functions 
    **  Main 
    */

    VM * ring_vm_new ( RingState *pRingState ) ;

    VM * ring_vm_delete ( VM *pVM ) ;

    RING_API void ring_vm_loadcode ( VM *pVM ) ;

    void ring_vm_start ( RingState *pRingState,VM *pVM ) ;

    void ring_vm_fetch ( VM *pVM ) ;

    void ring_vm_fetch2 ( VM *pVM ) ;

    void ring_vm_execute ( VM *pVM ) ;

    RING_API void ring_vm_error ( VM *pVM,const char *cStr ) ;

    int ring_vm_eval ( VM *pVM,const char *cStr ) ;

    void ring_vm_tobytecode ( VM *pVM,int x ) ;

    void ring_vm_error2 ( VM *pVM,const char *cStr,const char *cStr2 ) ;

    void ring_vm_newbytecodeitem ( VM *pVM,int x ) ;

    void ring_vm_mainloop ( VM *pVM ) ;

    RING_API void ring_vm_runcode ( VM *pVM,const char *cStr ) ;

    void ring_vm_init ( RingState *pRingState ) ;

    void ring_vm_printstack ( VM *pVM ) ;

    RING_API void ring_vm_showerrormessage ( VM *pVM,const char *cStr ) ;

    void ring_vm_addglobalvariables ( VM *pVM ) ;

    void ring_vm_mainloopforeval ( VM *pVM ) ;
    /* Stack and Variables */

    void ring_vm_pushv ( VM *pVM ) ;

    void ring_vm_loadaddress ( VM *pVM ) ;

    void ring_vm_assignment ( VM *pVM ) ;

    void ring_vm_inc ( VM *pVM ) ;

    void ring_vm_loadapushv ( VM *pVM ) ;

    void ring_vm_newline ( VM *pVM ) ;

    void ring_vm_freestack ( VM *pVM ) ;

    void ring_vm_setreference ( VM *pVM ) ;

    void ring_vm_list_copy ( VM *pVM,List *pNewList, List *pList ) ;

    void ring_vm_list_simpointercopy ( VM *pVM,List *pList ) ;

    void ring_vm_beforeequallist ( VM *pVM,List *pVar,double nNum1 ) ;

    void ring_vm_beforeequalitem ( VM *pVM,Item *pItem,double nNum1 ) ;

    void ring_vm_assignmentpointer ( VM *pVM ) ;

    void ring_vm_freeloadaddressscope ( VM *pVM ) ;

    void ring_vm_setfilename ( VM *pVM ) ;

    void ring_vm_loadaddressfirst ( VM *pVM ) ;

    void ring_vm_endfuncexec ( VM *pVM ) ;

    void ring_vm_varpushv ( VM *pVM ) ;

    int ring_vm_checknull ( VM *pVM ) ;
    /* Compare */

    void ring_vm_equal ( VM *pVM ) ;

    void ring_vm_lessequal ( VM *pVM ) ;

    void ring_vm_less ( VM *pVM ) ;

    void ring_vm_greater ( VM *pVM ) ;

    void ring_vm_greaterequal ( VM *pVM ) ;

    void ring_vm_notequal ( VM *pVM ) ;
    /* Math */

    void ring_vm_sum ( VM *pVM ) ;

    void ring_vm_sub ( VM *pVM ) ;

    void ring_vm_mul ( VM *pVM ) ;

    void ring_vm_div ( VM *pVM ) ;

    void ring_vm_mod ( VM *pVM ) ;

    void ring_vm_neg ( VM *pVM ) ;

    RING_API char * ring_vm_numtostring ( VM *pVM,double nNum1,char *cStr ) ;

    RING_API double ring_vm_stringtonum ( VM *pVM,const char *cStr ) ;

    void ring_vm_expr_ppoo ( VM *pVM,const char *cStr ) ;

    void ring_vm_expr_npoo ( VM *pVM,const char *cStr,double nNum1 ) ;

    void ring_vm_expr_spoo ( VM *pVM,const char *cStr,const char *cStr2,int nSize ) ;

    void ring_vm_plusplus ( VM *pVM ) ;

    void ring_vm_minusminus ( VM *pVM ) ;

    void ring_vm_addlisttolist ( VM *pVM,List *pList,List *pList2 ) ;

    int ring_vm_checkoverflow ( VM *pVM,double nNum1,double nNum2 ) ;
    /* Logic */

    void ring_vm_and ( VM *pVM ) ;

    void ring_vm_or ( VM *pVM ) ;

    void ring_vm_not ( VM *pVM ) ;
    /* Variables */

    void ring_vm_newscope ( VM *pVM ) ;

    int ring_vm_findvar ( VM *pVM,const char *cStr ) ;

    int ring_vm_findvar2 ( VM *pVM,int x,List *pList2,const char *cStr ) ;

    void ring_vm_newvar ( VM *pVM,const char *cStr ) ;

    List * ring_vm_newvar2 ( VM *pVM,const char *cStr,List *pParent ) ;

    void ring_vm_addnewnumbervar ( VM *pVM,const char *cStr,double x ) ;

    void ring_vm_addnewstringvar ( VM *pVM,const char *cStr,const char *cStr2 ) ;

    void ring_vm_deletescope ( VM *pVM ) ;

    void ring_vm_addnewpointervar ( VM *pVM,const char *cStr,void *x,int y ) ;

    void ring_vm_newtempvar ( VM *pVM,const char *cStr, List *TempList ) ;

    void ring_vm_addnewstringvar2 ( VM *pVM,const char *cStr,const char *cStr2,int nStrSize ) ;

    void ring_vm_addnewcpointervar ( VM *pVM,const char *cStr,void *pPointer,const char *cStr2 ) ;
    /* Jump */

    void ring_vm_jump ( VM *pVM ) ;

    void ring_vm_jumpzero ( VM *pVM ) ;

    void ring_vm_jumpfor ( VM *pVM ) ;

    void ring_vm_jumpone ( VM *pVM ) ;

    void ring_vm_jumpzero2 ( VM *pVM ) ;

    void ring_vm_jumpone2 ( VM *pVM ) ;
    /* Lists */

    void ring_vm_liststart ( VM *pVM ) ;

    void ring_vm_listitem ( VM *pVM ) ;

    void ring_vm_listend ( VM *pVM ) ;

    void ring_vm_loadindexaddress ( VM *pVM ) ;

    void ring_vm_listpushv ( VM *pVM ) ;

    void ring_vm_listassignment ( VM *pVM ) ;

    void ring_vm_listgetvalue ( VM *pVM,List *pVar,const char *cStr ) ;

    int ring_vm_strcmpnotcasesensitive ( const char *cStr1,const char *cStr2 ) ;

    void ring_vm_cleansetpropertylist ( VM *pVM ) ;

    int ring_vm_isoperationaftersublist ( VM *pVM ) ;
    /* Functions */

    int ring_vm_loadfunc ( VM *pVM ) ;

    int ring_vm_loadfunc2 ( VM *pVM,const char *cStr,int nPerformance ) ;

    void ring_vm_call ( VM *pVM ) ;

    void ring_vm_call2 ( VM *pVM ) ;

    void ring_vm_return ( VM *pVM ) ;

    void ring_vm_returnnull ( VM *pVM ) ;

    void ring_vm_returneval ( VM *pVM ) ;

    void ring_vm_newfunc ( VM *pVM ) ;

    void ring_vm_blockflag ( VM *pVM ) ;

    void ring_vm_blockflag2 ( VM *pVM,int x ) ;

    void ring_vm_removeblockflag ( VM *pVM ) ;

    void ring_vm_movetoprevscope ( VM *pVM ) ;

    void ring_vm_createtemplist ( VM *pVM ) ;

    void ring_vm_saveloadaddressscope ( VM *pVM ) ;

    void ring_vm_restoreloadaddressscope ( VM *pVM ) ;

    void ring_vm_anonymous ( VM *pVM ) ;

    int ring_vm_isstackpointertoobjstate ( VM *pVM ) ;

    void ring_vm_retitemref ( VM *pVM ) ;

    void ring_vm_callclassinit ( VM *pVM ) ;

    List * ring_vm_prevtempmem ( VM *pVM ) ;
    /* User Interface */

    void ring_vm_see ( VM *pVM ) ;

    void ring_vm_give ( VM *pVM ) ;
    /* String As Array */

    void ring_vm_string_pushv ( VM *pVM ) ;

    void ring_vm_string_assignment ( VM *pVM ) ;

    void ring_vm_string_index ( VM *pVM , String *pString , double x ) ;
    /* Try Catch Done */

    void ring_vm_try ( VM *pVM ) ;

    void ring_vm_catch ( VM *pVM,const char *cError ) ;

    void ring_vm_done ( VM *pVM ) ;
    /* Duplicate and Range */

    void ring_vm_dup ( VM *pVM ) ;

    void ring_vm_range ( VM *pVM ) ;

    List * ring_vm_range_newlist ( VM *pVM ) ;
    /* OOP */

    void ring_vm_oop_newobj ( VM *pVM ) ;

    void ring_vm_oop_property ( VM *pVM ) ;

    int ring_vm_oop_isobject ( List *pList ) ;

    List * ring_vm_oop_getobj ( VM *pVM ) ;

    void ring_vm_oop_loadmethod ( VM *pVM ) ;

    void ring_vm_oop_aftercallmethod ( VM *pVM ) ;

    void ring_vm_oop_setscope ( VM *pVM ) ;

    void ring_vm_oop_printobj ( VM *pVM,List *pList ) ;

    void ring_vm_oop_parentinit ( VM *pVM,List *pList ) ;

    void ring_vm_oop_parentmethods ( VM *pVM,List *pList ) ;

    void ring_vm_oop_newclass ( VM *pVM ) ;

    void ring_vm_oop_setbraceobj ( VM *pVM,List *pList ) ;

    void ring_vm_oop_bracestart ( VM *pVM ) ;

    void ring_vm_oop_braceend ( VM *pVM ) ;

    void ring_vm_oop_bracestack ( VM *pVM ) ;

    void ring_vm_oop_newsuperobj ( VM *pVM,List *pState,List *pClass ) ;

    List * ring_vm_oop_getsuperobj ( VM *pVM ) ;

    void ring_vm_oop_loadsuperobjmethod ( VM *pVM,List *pSuper ) ;

    void ring_vm_oop_import ( VM *pVM ) ;

    List * ring_vm_oop_checkpointertoclassinpackage ( VM *pVM,List *pList ) ;

    void ring_vm_oop_import2 ( VM *pVM,const char *cPackage ) ;

    void ring_vm_oop_import3 ( VM *pVM,List *pList ) ;

    int ring_vm_oop_visibleclassescount ( VM *pVM ) ;

    List * ring_vm_oop_visibleclassitem ( VM *pVM,int x ) ;

    void ring_vm_oop_pushclasspackage ( VM *pVM,List *pList ) ;

    void ring_vm_oop_popclasspackage ( VM *pVM ) ;

    void ring_vm_oop_deletepackagesafter ( VM *pVM,int x ) ;

    int ring_vm_oop_callmethodinsideclass ( VM *pVM ) ;

    void ring_vm_oop_setget ( VM *pVM,List *pVar ) ;

    void ring_vm_oop_setproperty ( VM *pVM ) ;

    void ring_vm_oop_operatoroverloading ( VM *pVM,List *pObj,const char *cStr1,int nType,const char *cStr2,double nNum1,void *pPointer,int nPointerType ) ;

    List * ring_vm_oop_objvarfromobjlist ( List *pList ) ;

    int ring_vm_oop_objtypefromobjlist ( List *pList ) ;

    Item * ring_vm_oop_objitemfromobjlist ( List *pList ) ;

    void ring_vm_oop_callmethodfrombrace ( VM *pVM ) ;

    int ring_vm_oop_ismethod ( VM *pVM,List *pList,const char *cStr ) ;

    void ring_vm_oop_updateselfpointer ( VM *pVM,List *pObj,int nType,void *pContainer ) ;

    void ring_vm_oop_movetobeforeobjstate ( VM *pVM ) ;

    void ring_vm_oop_setthethisvariable ( VM *pVM ) ;

    void ring_vm_oop_setthethisvariableinclassregion ( VM *pVM ) ;
    /* For Better Performance */

    void ring_vm_pushp ( VM *pVM ) ;

    void ring_vm_incp ( VM *pVM ) ;

    void ring_vm_pushpv ( VM *pVM ) ;

    void ring_vm_incjump ( VM *pVM ) ;

    void ring_vm_incpjump ( VM *pVM ) ;

    void ring_vm_jumpvarlenum ( VM *pVM ) ;

    void ring_vm_jumpvarplenum ( VM *pVM ) ;

    void ring_vm_loadfuncp ( VM *pVM ) ;

    void ring_vm_pushplocal ( VM *pVM ) ;

    void ring_vm_inclpjump ( VM *pVM ) ;

    void ring_vm_jumpvarlplenum ( VM *pVM ) ;

    void ring_vm_incpjumpstep1 ( VM *pVM ) ;

    void ring_vm_jumpvarplenumstep1 ( VM *pVM ) ;
    /* End Program / Exit from Loop / Loop (Continue) */

    void ring_vm_bye ( VM *pVM ) ;

    void ring_vm_exitmark ( VM *pVM ) ;

    void ring_vm_popexitmark ( VM *pVM ) ;

    void ring_vm_exit ( VM *pVM,int nType ) ;
    /* State */

    void ring_vm_savestate ( VM *pVM,List *pList ) ;

    void ring_vm_restorestate ( VM *pVM,List *pList,int nPos,int nFlag ) ;

    void ring_vm_backstate ( VM *pVM,int x,List *pList ) ;

    void ring_vm_savestate2 ( VM *pVM,List *pList ) ;

    void ring_vm_restorestate2 ( VM *pVM,List *pList,int x ) ;

    void ring_vm_savestate3 ( VM *pVM ) ;

    void ring_vm_restorestate3 ( VM *pVM ) ;

    int ring_vm_newobjectstackpointer ( VM *pVM ) ;

    List * ring_vm_savestack ( VM *pVM ) ;

    void ring_vm_restorestack ( VM *pVM,List *pList ) ;
    /* Bitwise */

    void ring_vm_bitand ( VM *pVM ) ;

    void ring_vm_bitor ( VM *pVM ) ;

    void ring_vm_bitxor ( VM *pVM ) ;

    void ring_vm_bitnot ( VM *pVM ) ;

    void ring_vm_bitshl ( VM *pVM ) ;

    void ring_vm_bitshr ( VM *pVM ) ;
    /* Step Number */

    void ring_vm_stepnumber ( VM *pVM ) ;

    void ring_vm_popstep ( VM *pVM ) ;
    /* Threads */

    RING_API void ring_vm_mutexfunctions ( VM *pVM,void *(*pFunc)(void),void (*pFuncLock)(void *),void (*pFuncUnlock)(void *),void (*pFuncDestroy)(void *) ) ;

    RING_API void ring_vm_mutexlock ( VM *pVM ) ;

    RING_API void ring_vm_mutexunlock ( VM *pVM ) ;

    RING_API void ring_vm_mutexdestroy ( VM *pVM ) ;

    RING_API void ring_vm_runcodefromthread ( VM *pVM,const char *cStr ) ;
    /* Trace */

    void ring_vm_traceevent ( VM *pVM,char nEvent ) ;
    /* Fast Function Call for Extensions (Without Eval) */

    RING_API void ring_vm_callfunction ( VM *pVM,char *cFuncName ) ;
    /* Custom Global Scope */

    void ring_vm_newglobalscope ( VM *pVM ) ;

    void ring_vm_endglobalscope ( VM *pVM ) ;

    void ring_vm_setglobalscope ( VM *pVM ) ;

    List * ring_vm_getglobalscope ( VM *pVM ) ;
    /* Temp Lists */

    void ring_vm_freetemplists ( VM *pVM ) ;
#endif

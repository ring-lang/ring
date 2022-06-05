/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_codegen_h
    #define ring_codegen_h
    /*
    **  Data 
    **  Intermediate Code 
    */
    typedef enum IC_OPERATIONS {
        /* General */
        ICO_NEWLINE=0 ,
        ICO_FILENAME ,
        ICO_PRINT ,
        ICO_NEWCLASS ,
        ICO_NEWFUNC ,
        ICO_DUPLICATE ,
        ICO_NEWOBJ ,
        ICO_GIVE ,
        ICO_PRIVATE ,
        ICO_NEWLABEL ,
        /* Control Structure */
        ICO_JUMP ,
        ICO_JUMPZERO ,
        ICO_JUMPONE ,
        ICO_JUMPFOR ,
        ICO_JUMPZERO2 ,
        ICO_JUMPONE2 ,
        /* Variables */
        ICO_LOADADDRESS ,
        ICO_ASSIGNMENT ,
        ICO_LOADSUBADDRESS ,
        ICO_LOADINDEXADDRESS ,
        ICO_LOADAPUSHV ,
        /* Comparison operators */
        ICO_EQUAL ,
        ICO_LESS ,
        ICO_GREATER ,
        ICO_NOTEQUAL ,
        ICO_LESSEQUAL ,
        ICO_GREATEREQUAL ,
        /* Data */
        ICO_PUSHC ,
        ICO_PUSHN ,
        ICO_PUSHV ,
        ICO_PUSHP ,
        ICO_PUSHPV ,
        ICO_PUSHPLOCAL ,
        /* Arithmetic */
        ICO_SUM ,
        ICO_SUB ,
        ICO_MUL ,
        ICO_DIV ,
        ICO_MOD ,
        ICO_NEG ,
        ICO_INC ,
        ICO_INCP ,
        /* Functions/Methods */
        ICO_LOADFUNC ,
        ICO_CALL ,
        ICO_RETURN ,
        ICO_RETNULL ,
        ICO_RETFROMEVAL ,
        ICO_RETITEMREF ,
        /* Lists */
        ICO_LISTSTART ,
        ICO_LISTITEM ,
        ICO_LISTEND ,
        /* Logic */
        ICO_AND ,
        ICO_OR ,
        ICO_NOT ,
        /* More */
        ICO_FREESTACK ,
        ICO_BLOCKFLAG ,
        ICO_FUNCEXE ,
        ICO_ENDFUNCEXE ,
        ICO_BYE ,
        ICO_EXITMARK ,
        ICO_POPEXITMARK ,
        ICO_EXIT ,
        ICO_INCJUMP ,
        ICO_INCPJUMP ,
        ICO_JUMPVARLENUM ,
        ICO_JUMPVARPLENUM ,
        ICO_TRY ,
        ICO_DONE ,
        ICO_RANGE ,
        ICO_LOADMETHOD ,
        ICO_SETSCOPE ,
        ICO_AFTERCALLMETHOD ,
        ICO_BRACESTART ,
        ICO_BRACEEND ,
        ICO_LOADFUNCP ,
        ICO_FREELOADASCOPE ,
        /* Loop */
        ICO_LOOP ,
        /* Loop optimization in functions (local scope) */
        ICO_INCLPJUMP ,
        ICO_JUMPVARLPLENUM ,
        /* Packages */
        ICO_PACKAGE ,
        ICO_IMPORT ,
        /* Property */
        ICO_SETPROPERTY ,
        ICO_NOOP ,
        ICO_AFTERCALLMETHOD2 ,
        /* Other */
        ICO_SETREFERENCE ,
        ICO_KILLREFERENCE ,
        ICO_ASSIGNMENTPOINTER ,
        ICO_BEFOREEQUAL ,
        ICO_PLUSPLUS ,
        ICO_MINUSMINUS ,
        /* Bitwise Operators */
        ICO_BITAND ,
        ICO_BITOR ,
        ICO_BITNOT ,
        ICO_BITXOR ,
        ICO_BITSHL ,
        ICO_BITSHR ,
        /* For Loop Step */
        ICO_STEPNUMBER ,
        ICO_POPSTEP ,
        ICO_LOADAFIRST ,
        ICO_INCPJUMPSTEP1 ,
        ICO_JUMPVARPLENUMSTEP1 ,
        /* Anonymous Functions */
        ICO_ANONYMOUS ,
        /* Class Init */
        ICO_CALLCLASSINIT ,
        /* Custom Global Scope */
        ICO_NEWGLOBALSCOPE ,
        ICO_ENDGLOBALSCOPE ,
        ICO_SETGLOBALSCOPE ,
        /* Temp Lists */
        ICO_FREETEMPLISTS 
    } IC_OPERATIONS ;
    /* Operations Text (Array) */
    static const char * RING_IC_OP[] = {"NewLine","FileName","Print","Class","Func","Dup","New","Give","Private","NewLabel", 
    
    "Jump","JumpZ","Jump1","JumpFOR","JZ2","J12","LoadA","Assignment","LoadSA","LoadIA","LoadAPushV","==","<",">","!=","<=",">=", 
    
    "PushC","PushN","PushV","PushP","PushPV","PushPLocal", "SUM","SUB","MUL","DIV","MOD","Negative","Inc","IncP", 
    
    "LoadFunc","Call", "Return","ReturnNull","RetFromEval","RetItemRef","ListStart","ListItem","ListEnd","And","Or","Not","FreeStack", 
    
    "BlockFlag","FuncExE","EndFuncExe","Bye","ExitMark","POPExitMark","Exit","IncJump","IncPJump", 
    
    "JumpVarLENum","JumpVarPLENum","Try","Done","Range","LoadMethod","SetScope","AfterCallMethod", 
    
    "BraceStart","BraceEnd","LoadFuncP","FreeLoadAScope","Loop","IncLPJump","JumpVarLPLENum","Package","Import", 
    
    "SetProperty","NoOperation","AfterCallMethod2","SetReference","KillReference","AssignmentPointer","BeforeEqual","++","--", 
    
    "BITAND","BITOR","BITNOT","BITXOR","BITSHL","BITSHR","StepNumber","POPStep","LoadAFirst", 
    
    "INCPJUMPSTEP1","JUMPVARPLENUMSTEP1","ANONYMOUS","CallClassInit","NewGlobalScope","EndGlobalScope","SetGlobalScope","FreeTempLists"} ;
    /* Macro */
    #define RING_PARSER_ICG_GOTOLASTOP pParser->ActiveGenCodeList = ring_list_getlist(pParser->GenCode,ring_list_getsize(pParser->GenCode))
    #define ring_parser_icg_newlabel(x) ( ring_list_getsize(x->GenCode) + 1 )
    #define ring_parser_icg_getlastoperation(pParser) ring_list_getint(pParser->ActiveGenCodeList,1)
    #define ring_parser_icg_setlastoperation(pParser,x) ring_list_setint_gc(pParser->pRingState,pParser->ActiveGenCodeList,1,x)
    #define ring_parser_icg_instructionscount(pParser) ring_list_getsize(pParser->GenCode)
    #define ring_parser_icg_getoperationlist(pParser,x) ring_list_getlist(pParser->GenCode,x)
    #define RING_PARSER_ICG_OPERATIONCODE 1
    #define ring_parser_icg_getoperationbeforelastoperation(pParser) ring_list_getint(ring_parser_icg_getoperationlist(pParser,ring_parser_icg_instructionscount(pParser)-1),RING_PARSER_ICG_OPERATIONCODE)
    #define ring_parser_icg_getoperationatpos(pParser,x) ring_list_getint(ring_parser_icg_getoperationlist(pParser,x),RING_PARSER_ICG_OPERATIONCODE)
    /*
    **  Functions 
    **  Generate Intermediate Code 
    */

    void ring_parser_icg_newoperation ( Parser *pParser , IC_OPERATIONS opcode ) ;

    void ring_parser_icg_newoperand ( Parser *pParser , const char *cStr ) ;

    void ring_parser_icg_newoperandint ( Parser *pParser , int nValue ) ;

    void ring_parser_icg_newoperanddouble ( Parser *pParser , double nValue ) ;

    void ring_parser_icg_newoperandpointer ( Parser *pParser , void *pValue ) ;

    List * ring_parser_icg_getactiveoperation ( Parser *pParser ) ;

    void ring_parser_icg_addoperand ( Parser *pParser ,List *pList , const char *cStr ) ;

    void ring_parser_icg_addoperandint ( Parser *pParser ,List *pList , int nValue ) ;

    void ring_parser_icg_addoperandpointer ( Parser *pParser ,List *pList , void *pValue ) ;

    void ring_parser_icg_showoutput ( List *pListGenCode,int nStatus ) ;

    Items * ring_parser_icg_getoperationpos ( Parser *pParser ) ;

    void ring_parser_icg_deletelastoperation ( Parser *pParser ) ;

    void ring_parser_icg_duplicate ( Parser *pParser,int nStart,int nEnd ) ;

    int ring_parser_icg_newlabel2 ( Parser *pParser ) ;

    void ring_parser_icg_insertoperation ( Parser *pParser , int nPos , IC_OPERATIONS opcode ) ;
#endif

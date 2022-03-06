/* Copyright (c) 2013-2022 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_state_h
    #define ring_state_h
    /* Data */
    typedef struct RingState {
        /* First use by ring_state_runfile */
        List *pRingFilesList  ;
        List *pRingFilesStack  ;
        /* First use by ring_parser_new */
        List *pRingGenCode  ;
        List *pRingFunctionsMap  ;
        List *pRingClassesMap  ;
        List *pRingPackagesMap  ;
        /* First use by ring_vm_new */
        List *pRingCFunctions  ;
        /* ISCGI is 1 if we are using the language for CGI development */
        unsigned int nISCGI : 1  ;
        /* set to 0 if we need to compile only */
        unsigned int nRun : 1  ;
        /* set to 1 if we need to print byte code before execution */
        unsigned int nPrintIC : 1  ;
        /* set to 1 if we need to print the final byte code after execution */
        unsigned int nPrintICFinal : 1  ;
        /* set to 1 if we need to print the tokens */
        unsigned int nPrintTokens : 1  ;
        /* set to 1 if we need to print the grammar rules */
        unsigned int nPrintRules : 1  ;
        /* set to 1 if we need to print the  current instruction executed */
        unsigned int nPrintInstruction : 1  ;
        /* set to 1 if we need to generate the object file (ringo) */
        unsigned int nGenObj : 1  ;
        unsigned int nGenCObj : 1  ;
        /* set to 1 if we need to display warnings */
        unsigned int nWarning : 1  ;
        /* Set to 1 to tell the scanner to don't delete the VM after execution */
        unsigned int nDontDeleteTheVM : 1  ;
        /* Set to 1 to tell the state that we are running Ring from Ring (to avoid exit() on error) */
        unsigned int nRingInsideRing : 1  ;
        /* Set to 1 to tell the scanner that we need the tokens only */
        unsigned int nOnlyTokens : 1  ;
        List *pRingFileTokens  ;
        /* command line parameters */
        int argc  ;
        char  **argv  ;
        /* Virtual Machine */
        struct VM *pVM  ;
        /* Startup File */
        unsigned int lStartup : 1  ;
        /* Pool Manager */
        PoolManager vPoolManager  ;
        unsigned int lStartPoolManager : 1  ;
        /* Avoid line number ( when we use eval() from VM ) */
        unsigned int lNoLineNumber : 1  ;
        /* Custom Global Scope */
        int nCustomGlobalScopeCounter  ;
        List *aCustomGlobalScopeStack  ;
        /* Flag to know if we are running from thread (Useful for the Pool Manager) */
        unsigned int lRunFromThread : 1  ;
        /* Counter to know if we are using (Load Again) command */
        int nLoadAgain  ;
        /* Log File */
        FILE *pLogFile;
        /* Flag (Not Case Sensitive) */
        unsigned int lNotCaseSensitive : 1  ;
        /* Flag (Comments As Tokens From Scanner) */
        unsigned int lCommentsAsTokens : 1  ;
        /* Scanner Error Code */
        unsigned int nScannerError  ;
    } RingState ;
    /* Constants */
    #define RING_STATE_VERSION "1.17"
    /* MACRO */
    #define RING_STATE_CHECKPRINTRULES if ( pParser->pRingState->nPrintRules )
    /* General Options (Only for ring_state_main()) */
    static int nRingStateDEBUGSEGFAULT  ;
    static int nRingStateCGI  ;
    /* Functions */

    RING_API RingState * ring_state_new ( void ) ;

    RING_API RingState * ring_state_delete ( RingState *pRingState ) ;

    RING_API RingState * ring_state_init ( void ) ;

    RING_API void ring_state_runcode ( RingState *pRingState,const char *cStr ) ;

    RING_API List * ring_state_findvar ( RingState *pRingState,const char *cStr ) ;

    RING_API List * ring_state_newvar ( RingState *pRingState,const char *cStr ) ;

    RING_API void ring_state_main ( int argc, char *argv[] ) ;

    RING_API void ring_state_execute ( char *cFileName, int nISCGI,int nRun,int nPrintIC,int nPrintICFinal,int nTokens,int nRules,int nIns,int nGenObj,int nGenCObj,int nWarn,int argc,char *argv[] ) ;

    RING_API int ring_state_runfile ( RingState *pRingState,char *cFileName ) ;

    RING_API int ring_state_runstring ( RingState *pRingState,char *cString ) ;

    RING_API void ring_state_runobjectfile ( RingState *pRingState,char *cFileName ) ;

    RING_API void ring_state_runobjectstring ( RingState *pRingState,char *cString,const char *cFileName ) ;

    RING_API void ring_state_runprogram ( RingState *pRingState ) ;

    RING_API void ring_state_log ( RingState *pRingState,const char *cStr ) ;

    void ring_state_cgiheader ( RingState *pRingState ) ;

    void ring_state_segfaultaction ( int sig ) ;
#endif

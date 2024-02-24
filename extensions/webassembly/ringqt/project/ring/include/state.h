/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_state_h
	#define ring_state_h
	typedef struct RingState {
		/* Virtual Machine */
		struct VM *pVM  ;
		/* Log File */
		FILE *pLogFile;
		/* Command line parameters */
		char  **pArgv  ;
		/* First use by ring_state_runfile */
		List *pRingFilesList  ;
		List *pRingFilesStack  ;
		/* File Tokens */
		List *pRingFileTokens  ;
		/* First use by ring_parser_new */
		List *pRingGenCode  ;
		List *pRingFunctionsMap  ;
		List *pRingClassesMap  ;
		List *pRingPackagesMap  ;
		/* Custom global scope list */
		List *pCustomGlobalScopeStack  ;
		/* First use by ring_vm_new */
		List *pRingCFunctions  ;
		/* Command line parameters count */
		int nArgc  ;
		/* Scanner Error Code */
		unsigned int nScannerError  ;
		/* Counter to know if we are using (Load Again) command */
		int nLoadAgain  ;
		/* Custom global scope counter */
		int nCustomGlobalScopeCounter  ;
		/* VM Instructions Count */
		int nInstructionsCount  ;
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
		/* ISCGI is 1 if we are using the language for CGI development */
		unsigned int nISCGI : 1  ;
		/* Startup File */
		unsigned int lStartup : 1  ;
		/* Set to 1 to tell the scanner to don't delete the VM after execution */
		unsigned int nDontDeleteTheVM : 1  ;
		/* Set to 1 to tell the state that we are running Ring from Ring (to avoid exit() on error) */
		unsigned int nRingInsideRing : 1  ;
		/* Set to 1 to tell the scanner that we need the tokens only */
		unsigned int nOnlyTokens : 1  ;
		/* Avoid line number ( when we use eval() from VM ) */
		unsigned int lNoLineNumber : 1  ;
		/* Flag to know if we are running from thread (Useful for the Pool Manager) */
		unsigned int lRunFromThread : 1  ;
		/* Flag (Not Case Sensitive) */
		unsigned int lNotCaseSensitive : 1  ;
		/* Flag (Comments As Tokens From Scanner) */
		unsigned int lCommentsAsTokens : 1  ;
		/* Flag to know if we are running from Object File (RINGO file) */
		unsigned int lRunFromObjectFile : 1  ;
		/* Pool Manager Flags */
		unsigned int lStartPoolManager : 1  ;
		unsigned int lDisablePoolManager : 1  ;
		unsigned int lCreateListsUsingBlocks : 1  ;
		unsigned int lDontCheckStateBlocks : 1  ;
		/* Pool Manager */
		PoolManager vPoolManager  ;
	} RingState ;
	#define RING_STATE_VERSION "1.20"
	#define RING_WARNING_UNKNOWNOPTION "Warning (W1): Unrecognized option: "
	#define RING_WARNING_DUPLICATIONINFILENAME "Warning (W2) : Duplication in file name : "
	#define RING_WARNING_CHANGEKEYWORDPARA "Warning (W3) : The Compiler command  ChangeRingKeyword requires two words as parameters"
	#define RING_WARNING_KEYWORDNOTFOUND "Warning (W4) : Compiler command ChangeRingKeyword - Keyword not found!"
	#define RING_WARNING_CHANGEOPERATORPARA "Warning (W5) : The Compiler command  ChangeRingOperator requires two words as parameters"
	#define RING_WARNING_OPERATORNOTFOUND "Warning (W6) : Compiler command ChangeRingOperator - Operator not found!"
	#define RING_WARNING_EXITOUTSIDELOOP "Warning (W7) : Using the EXIT command outside loop!"
	#define RING_WARNING_LOOPOUTSIDELOOP "Warning (W8) : Using the LOOP command outside loop"
	#define RING_STATE_PRINTRULES "Grammar Rules Used by The Parser "
	#define RING_RULE_PROGRAM "Rule : Program --> {Statement}"
	#define RING_CGI_START "Content-Type: text/plain\n\n"
	#define RING_STATE_CHECKPRINTRULES if ( pParser->pRingState->nPrintRules )
	static int nRingStateDEBUGSEGFAULT  ;
	static int nRingStateCGI  ;

	RING_API RingState * ring_state_new ( void ) ;

	RING_API RingState * ring_state_delete ( RingState *pRingState ) ;

	RING_API RingState * ring_state_init ( void ) ;

	RING_API void ring_state_runcode ( RingState *pRingState,const char *cStr ) ;

	RING_API List * ring_state_findvar ( RingState *pRingState,const char *cStr ) ;

	RING_API List * ring_state_newvar ( RingState *pRingState,const char *cStr ) ;

	RING_API void ring_state_main ( int nArgc, char *pArgv[] ) ;

	RING_API void ring_state_execute ( char *cFileName, int nISCGI,int nRun,int nPrintIC,int nPrintICFinal,int nTokens,int nRules,int nIns,int nGenObj,int nGenCObj,int nWarn,int nArgc,char *pArgv[] ) ;

	RING_API int ring_state_runfile ( RingState *pRingState,char *cFileName ) ;

	RING_API int ring_state_runstring ( RingState *pRingState,char *cString ) ;

	RING_API void ring_state_runobjectfile ( RingState *pRingState,char *cFileName ) ;

	RING_API void ring_state_runobjectstring ( RingState *pRingState,char *cString,const char *cFileName ) ;

	RING_API void ring_state_runprogram ( RingState *pRingState ) ;

	RING_API void ring_state_log ( RingState *pRingState,const char *cStr ) ;

	void ring_state_cgiheader ( RingState *pRingState ) ;

	void ring_state_segfaultaction ( int nSig ) ;

	void ring_state_usageinfo ( void ) ;
#endif

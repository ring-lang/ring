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
		unsigned int lRun : 1  ;
		/* set to 1 if we need to print byte code before execution */
		unsigned int lPrintIC : 1  ;
		/* set to 1 if we need to print the final byte code after execution */
		unsigned int lPrintICFinal : 1  ;
		/* set to 1 if we need to print the tokens */
		unsigned int lPrintTokens : 1  ;
		/* set to 1 if we need to print the grammar rules */
		unsigned int lPrintRules : 1  ;
		/* set to 1 if we need to print the  current instruction executed */
		unsigned int lPrintInstruction : 1  ;
		/* set to 1 if we need to generate the object file (ringo) */
		unsigned int lGenObj : 1  ;
		unsigned int lGenCObj : 1  ;
		/* set to 1 if we need to display warnings */
		unsigned int lWarning : 1  ;
		/* ISCGI is 1 if we are using the language for CGI development */
		unsigned int lISCGI : 1  ;
		/* Startup File */
		unsigned int lStartup : 1  ;
		/* Set to 1 to tell the scanner to don't delete the VM after execution */
		unsigned int lDontDeleteTheVM : 1  ;
		/* Set to 1 to tell the state that we are running Ring from Ring (to avoid exit() on error) */
		unsigned int nRingInsideRing : 1  ;
		/* Set to 1 to tell the scanner that we need the tokens only */
		unsigned int lOnlyTokens : 1  ;
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
		/* Pool Manager */
		PoolManager vPoolManager  ;
	} RingState ;
	#define RING_STATE_VERSION "1.22"
	#define RING_STATE_VERSIONANDPATCH (RING_STATE_VERSION ".0")
	#define RING_WARNING_UNKNOWNOPTION "Warning (W1): Unrecognized option: "
	#define RING_WARNING_DUPLICATIONINFILENAME "Warning (W2) : Duplication in file name : "
	#define RING_WARNING_CHANGEKEYWORDPARA "Warning (W3) : The Compiler command  ChangeRingKeyword requires two words as parameters"
	#define RING_WARNING_KEYWORDNOTFOUND "Warning (W4) : Compiler command ChangeRingKeyword - Keyword not found!"
	#define RING_WARNING_CHANGEOPERATORPARA "Warning (W5) : The Compiler command  ChangeRingOperator requires two words as parameters"
	#define RING_WARNING_OPERATORNOTFOUND "Warning (W6) : Compiler command ChangeRingOperator - Operator not found!"
	#define RING_WARNING_EXITOUTSIDELOOP "Warning (W7) : Using the EXIT command outside loop!"
	#define RING_WARNING_LOOPOUTSIDELOOP "Warning (W8) : Using the LOOP command outside loop"
	#define RING_MSG_PRINTRULES "Grammar Rules Used by The Parser "
	#define RING_MSG_PROGRAMRULE "\nRule : Program --> {Statement}\n\nLine 1\n"
	#define RING_CGI_START "Content-Type: text/plain\n\n"
	#define RING_VERYLONGPATH "Very long path! The maximum path size is"
	#define RING_FILES_LOGFILE "ringlog.txt"
	#define RING_FILES_AUTOLOADSRC "ring.ring"
	#define RING_FILES_AUTOLOADOBJ "ring.ringo"
	#define RING_FILES_AUTOLOADSYNTAX "ringsyntax.ring"
	#define RING_FILES_LOADSYNTAXSTR "LOADSYNTAX \"ringsyntax.ring\" \n"
	#define RING_FILES_STARTUP "startup.ring"
	#define RING_FILES_LOADSTARTUPSTR "Load 'startup.ring'"
	#define RING_STATE_CHECKPRINTRULES if ( pParser->pRingState->lPrintRules )
	#define RING_STATE_PRINTRULE(cRule) RING_STATE_CHECKPRINTRULES puts(cRule)
	#define RING_STATE_PRINTTWORULES(cRule1, cRule2) RING_STATE_CHECKPRINTRULES puts(cRule1 "\n" cRule2)
	static int lRingStateDebugSegFault  ;
	static int lRingStateCGI  ;

	RING_API RingState * ring_state_new ( void ) ;

	RING_API RingState * ring_state_delete ( RingState *pRingState ) ;

	RING_API RingState * ring_state_init ( void ) ;

	RING_API void ring_state_runcode ( RingState *pRingState,const char *cStr ) ;

	RING_API List * ring_state_findvar ( RingState *pRingState,const char *cStr ) ;

	RING_API List * ring_state_newvar ( RingState *pRingState,const char *cStr ) ;

	RING_API void ring_state_main ( int nArgc, char *pArgv[] ) ;

	RING_API void ring_state_execute ( char *cFileName, int lISCGI,int lRun,int lPrintIC,int lPrintICFinal,int lTokens,int lRules,int lIns,int lGenObj,int lGenCObj,int lWarn,int nArgc,char *pArgv[] ) ;

	RING_API int ring_state_runfile ( RingState *pRingState,char *cFileName ) ;

	RING_API int ring_state_runstring ( RingState *pRingState,char *cString ) ;

	RING_API void ring_state_runobjectfile ( RingState *pRingState,char *cFileName ) ;

	RING_API void ring_state_runobjectstring ( RingState *pRingState,char *cString,const char *cFileName ) ;

	RING_API void ring_state_runprogram ( RingState *pRingState ) ;

	RING_API void ring_state_newbytecode ( RingState *pRingState,int nSize,int lLiteral ) ;

	RING_API void ring_state_runbytecode ( RingState *pRingState ) ;

	RING_API void ring_state_log ( RingState *pRingState,const char *cStr ) ;

	void ring_state_cgiheader ( RingState *pRingState ) ;

	void ring_state_segfaultaction ( int nSig ) ;

	void ring_state_usageinfo ( void ) ;
#endif

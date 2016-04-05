/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_state_h
#define ring_state_h
/* Data */
typedef struct RingState {
	/* First use by ring_scanner_readfile */
	List *pRingFilesList  ;
	List *pRingFilesStack  ;
	/* First use by ring_parser_new */
	List *pRingGenCode  ;
	List *pRingFunctionsMap  ;
	List *pRingClassesMap  ;
	List *pRingPackagesMap  ;
	/* First use by ring_vm_new */
	List *pRingCFunctions  ;
	/* ISCGI is 1 if we are using the language as for CGI development */
	unsigned int nISCGI : 1  ;
	/* RUN is 0 if we need to compile only */
	unsigned int nRun : 1  ;
	/* PRINTIC is 1 if we need to print byte code before execution */
	unsigned int nPrintIC : 1  ;
	/* set to 1 if we need to print the fine byte code after execution */
	unsigned int nPrintICFinal : 1  ;
	/* set to 1 if we need to print the tokens */
	unsigned int nPrintTokens : 1  ;
	/* set to 1 if we need to print the grammar rules */
	unsigned int nPrintRules : 1  ;
	/* set to 1 if we need to print the  current instruction executed */
	unsigned int nPrintInstruction : 1  ;
	/* command line parameters */
	int argc  ;
	char  **argv  ;
	/* Virtual Machine */
	struct VM *pVM  ;
	/* Startup File */
	char lStartup  ;
} RingState ;
/* Functions */

RING_API RingState * ring_state_new ( void ) ;

RING_API RingState * ring_state_delete ( RingState *pRingState ) ;

void ring_state_cgiheader ( RingState *pRingState ) ;

RING_API void ring_print_line ( void ) ;

RING_API RingState * ring_state_init ( void ) ;

RING_API void ring_state_runcode ( RingState *pRingState,const char *cStr ) ;

RING_API List * ring_state_findvar ( RingState *pRingState,const char *cStr ) ;

RING_API List * ring_state_newvar ( RingState *pRingState,const char *cStr ) ;

RING_API void ring_state_main ( int argc, char *argv[] ) ;

RING_API void ring_state_runfile ( RingState *pRingState,const char *cFileName ) ;
/* MACRO */
#define RING_STATE_CHECKPRINTRULES if ( pParser->pRingState->nPrintRules )
/* General Functions */

int ring_fexists ( const char *cFileName ) ;

int ring_currentdir ( char *cDirPath ) ;

int ring_exefilename ( char *cDirPath ) ;

void ring_chdir ( const char *cDir ) ;

void ring_exefolder ( char *cDirPath ) ;
#endif

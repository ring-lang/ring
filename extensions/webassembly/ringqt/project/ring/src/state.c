/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API RingState * ring_state_new ( void )
{
	RingState *pRingState  ;
	pRingState = (RingState *) ring_malloc(sizeof(RingState));
	pRingState->pRingFilesList = NULL ;
	pRingState->pRingFilesStack = NULL ;
	pRingState->pRingGenCode = NULL ;
	pRingState->pRingFunctionsMap = NULL ;
	pRingState->pRingClassesMap = NULL ;
	pRingState->pRingPackagesMap = NULL ;
	pRingState->pRingCFunctions = NULL ;
	pRingState->nISCGI = 0 ;
	pRingState->nRun = 1 ;
	pRingState->nPrintIC = 0 ;
	pRingState->nPrintICFinal = 0 ;
	pRingState->nPrintTokens = 0 ;
	pRingState->nPrintRules = 0 ;
	pRingState->nPrintInstruction = 0 ;
	pRingState->nGenObj = 0 ;
	pRingState->nGenCObj = 0 ;
	pRingState->nWarning = 0 ;
	pRingState->nArgc = 0 ;
	pRingState->pArgv = NULL ;
	pRingState->pVM = NULL ;
	pRingState->lStartup = 0 ;
	/* Pool Manager */
	ring_poolmanager_new(pRingState);
	pRingState->nDontDeleteTheVM = 0 ;
	pRingState->nRingInsideRing = 0 ;
	pRingState->lNoLineNumber = 0 ;
	pRingState->nCustomGlobalScopeCounter = 0 ;
	pRingState->pCustomGlobalScopeStack = ring_list_new(RING_ZERO) ;
	pRingState->lStartPoolManager = 0 ;
	pRingState->lDisablePoolManager = 0 ;
	pRingState->lCreateListsUsingBlocks = 1 ;
	pRingState->lDontCheckStateBlocks = 0 ;
	pRingState->lRunFromThread = 0 ;
	pRingState->nLoadAgain = 0 ;
	ring_list_addint(pRingState->pCustomGlobalScopeStack,pRingState->nCustomGlobalScopeCounter);
	/* Log File */
	#if RING_LOGFILE
		pRingState->pLogFile = fopen("ringlog.txt" , "w+" );
	#endif
	/* Tokens Only */
	pRingState->nOnlyTokens = 0 ;
	pRingState->pRingFileTokens = NULL ;
	pRingState->lNotCaseSensitive = 1 ;
	pRingState->lCommentsAsTokens = 0 ;
	pRingState->nScannerError = 0 ;
	pRingState->nInstructionsCount = 0 ;
	pRingState->lRunFromObjectFile = 0 ;
	return pRingState ;
}

RING_API RingState * ring_state_delete ( RingState *pRingState )
{
	if ( pRingState->pRingFilesList != NULL ) {
		pRingState->pRingFilesList = ring_list_delete_gc(pRingState,pRingState->pRingFilesList);
		pRingState->pRingFilesStack = ring_list_delete_gc(pRingState,pRingState->pRingFilesStack);
	}
	if ( pRingState->pRingGenCode   != NULL ) {
		pRingState->pRingGenCode = ring_list_delete_gc(pRingState,pRingState->pRingGenCode);
		pRingState->pRingFunctionsMap = ring_list_delete_gc(pRingState,pRingState->pRingFunctionsMap);
		pRingState->pRingClassesMap = ring_list_delete_gc(pRingState,pRingState->pRingClassesMap);
		pRingState->pRingPackagesMap = ring_list_delete_gc(pRingState,pRingState->pRingPackagesMap);
		if ( pRingState->pRingCFunctions != NULL ) {
			/* We check because the execution may end by the compiler error */
			pRingState->pRingCFunctions = ring_list_delete_gc(pRingState,pRingState->pRingCFunctions);
		}
	}
	if ( pRingState->pVM != NULL ) {
		ring_vm_delete(pRingState->pVM);
	}
	pRingState->pCustomGlobalScopeStack = ring_list_delete(pRingState->pCustomGlobalScopeStack);
	/* Log File */
	#if RING_LOGFILE
		fclose( pRingState->pLogFile ) ;
	#endif
	ring_poolmanager_delete(pRingState);
	ring_free(pRingState);
	return NULL ;
}

RING_API RingState * ring_state_init ( void )
{
	RingState *pRingState  ;
	pRingState = ring_state_new();
	ring_vm_init(pRingState);
	return pRingState ;
}

RING_API void ring_state_runcode ( RingState *pRingState,const char *cStr )
{
	ring_vm_runcode(pRingState->pVM,cStr);
}

RING_API List * ring_state_findvar ( RingState *pRingState,const char *cStr )
{
	VM *pVM  ;
	List *pList  ;
	pVM = pRingState->pVM ;
	pList = NULL ;
	if ( ring_vm_findvar(pVM,cStr) ) {
		pList = (List *) RING_VM_STACK_READP ;
		RING_VM_STACK_POP ;
	}
	return pList ;
}

RING_API List * ring_state_newvar ( RingState *pRingState,const char *cStr )
{
	VM *pVM  ;
	List *pList  ;
	pVM = pRingState->pVM ;
	if ( ring_vm_findvar(pVM,cStr) == 0 ) {
		ring_vm_newvar(pVM,cStr);
	}
	pList = (List *) RING_VM_STACK_READP ;
	RING_VM_STACK_POP ;
	return pList ;
}

RING_API void ring_state_main ( int argc, char *argv[] )
{
	int x,nCGI,nRun,nPrintIC,nPrintICFinal,nTokens,nRules,nIns,nPerformance,nSRC,nGenObj,nGenCObj,nWarn  ;
	char *cStr  ;
	/* Init Values */
	nCGI = 0 ;
	nRun = 1 ;
	nPrintIC = 0 ;
	nPrintICFinal = 0 ;
	nTokens = 0 ;
	nRules = 0 ;
	nIns = 0 ;
	nPerformance = 0 ;
	cStr = NULL ;
	nSRC = 0 ;
	nGenObj = 0 ;
	nGenCObj = 0 ;
	nWarn = 0 ;
	nRingStateDEBUGSEGFAULT = 0 ;
	nRingStateCGI = 0 ;
	signal(SIGSEGV,ring_state_segfaultaction);
	if ( argc > 1 ) {
		for ( x = 1 ; x < argc ; x++ ) {
			if ( strcmp(argv[x],"-cgi") == 0 ) {
				nCGI = 1 ;
				nRingStateCGI = 1 ;
			}
			else if ( strcmp(argv[x],"-tokens") == 0 ) {
				nTokens = 1 ;
			}
			else if ( strcmp(argv[x],"-rules") == 0 ) {
				nRules = 1 ;
			}
			else if ( strcmp(argv[x],"-ic") == 0 ) {
				nPrintIC = 1 ;
			}
			else if ( strcmp(argv[x],"-norun") == 0 ) {
				nRun = 0 ;
			}
			else if ( strcmp(argv[x],"-icfinal") == 0 ) {
				nPrintICFinal = 1 ;
			}
			else if ( strcmp(argv[x],"-ins") == 0 ) {
				nIns = 1 ;
			}
			else if ( strcmp(argv[x],"-clock") == 0 ) {
				nPerformance = 1 ;
			}
			else if ( strcmp(argv[x],"-go") == 0 ) {
				nGenObj = 1 ;
			}
			else if ( strcmp(argv[x],"-geo") == 0 ) {
				nGenCObj = 1 ;
			}
			else if ( strcmp(argv[x],"-w") == 0 ) {
				nWarn = 1 ;
				nRingStateDEBUGSEGFAULT = 1 ;
			}
			else if ( ( ring_general_issourcefile(argv[x]) || ring_general_isobjectfile(argv[x])) && nSRC == 0 ) {
				cStr = argv[x] ;
				nSRC = 1 ;
			}
			else {
				if ( nSRC == 0 ) {
					if ( ring_general_fexists(argv[x]) ) {
						cStr = argv[x] ;
						nSRC = 1 ;
					}
					else {
						ring_general_printline();
						printf( "WARNING: Unrecognized option: %s\n",argv[x] ) ;
					}
				}
			}
		}
	}
	if ( nPerformance ) {
		ring_general_showtime();
	}
	srand(time(NULL));
	/* Check Startup ring.ring */
	if ( ring_general_fexists("ring.ring") && argc == 1 ) {
		ring_state_execute((char *) "ring.ring",nCGI,nRun,nPrintIC,nPrintICFinal,nTokens,nRules,nIns,nGenObj,nGenCObj,nWarn,argc,argv);
		exit(0);
	}
	if ( ring_general_fexists("ring.ringo") && argc == 1 ) {
		ring_state_execute((char *) "ring.ringo",nCGI,nRun,nPrintIC,nPrintICFinal,nTokens,nRules,nIns,nGenObj,nGenCObj,nWarn,argc,argv);
		exit(0);
	}
	/* Print Version */
	if ( (argc == 1) || (cStr == NULL) ) {
		ring_general_printline();
		printf( "Ring version %s \n2013-2024, Mahmoud Fayed <msfclipper@yahoo.com>\n",RING_STATE_VERSION ) ;
		puts("Usage : ring filename.ring [Options]");
		ring_general_printline();
		/* Options */
		puts("-tokens   :  Print a list of tokens in the source code file");
		puts("-rules    :  Print grammar rules applied on the tokens");
		puts("-ic       :  Print the intermediate byte code (before execution)");
		puts("-icfinal  :  Print the final byte code (after execution)");
		puts("-cgi      :  Print http response header before error messages");
		puts("-norun    :  Don't run the program after compiling");
		puts("-ins      :  Print instruction operation code before execution");
		puts("-clock    :  Print clock before and after program execution");
		#if RING_MSDOS
		#else
			puts("-go       :  Generate object file");
			puts("-geo      :  Generate embedded object file (C source code)");
		#endif
		puts("-w        :  Display Warnings");
		ring_general_printline();
		exit(0);
	}
	ring_state_execute(cStr,nCGI,nRun,nPrintIC,nPrintICFinal,nTokens,nRules,nIns,nGenObj,nGenCObj,nWarn,argc,argv);
	if ( nPerformance ) {
		ring_general_showtime();
	}
}

RING_API void ring_state_execute ( char *cFileName, int nISCGI,int nRun,int nPrintIC,int nPrintICFinal,int nTokens,int nRules,int nIns,int nGenObj,int nGenCObj,int nWarn,int argc,char *argv[] )
{
	RingState *pRingState  ;
	pRingState = ring_state_new();
	pRingState->nISCGI = nISCGI ;
	pRingState->nRun = nRun ;
	pRingState->nPrintIC = nPrintIC ;
	pRingState->nPrintICFinal = nPrintICFinal ;
	pRingState->nPrintTokens = nTokens ;
	pRingState->nPrintRules = nRules ;
	pRingState->nPrintInstruction = nIns ;
	pRingState->nGenObj = nGenObj ;
	pRingState->nGenCObj = nGenCObj ;
	pRingState->nWarning = nWarn ;
	pRingState->nArgc = argc ;
	pRingState->pArgv = argv ;
	if ( ring_general_isobjectfile(cFileName) ) {
		ring_state_runobjectfile(pRingState,cFileName);
	}
	else {
		ring_state_runfile(pRingState,cFileName);
	}
	ring_state_delete(pRingState);
}

RING_API int ring_state_runfile ( RingState *pRingState,char *cFileName )
{
	RING_FILE fp  ;
	/* Must be signed char to work fine on Android. */
	signed char c  ;
	Scanner *pScanner  ;
	VM *pVM  ;
	int nCont,nRunVM,nFreeFilesList = 0 ;
	char cStartup[32]  ;
	int x,nSize  ;
	char cFileName2[RING_PATHSIZE]  ;
	/* Check Path Size */
	if ( strlen(cFileName) > RING_PATHLIMIT ) {
		printf( "\nVery long path! Can't open %s  The maximum path size is %d \n",cFileName,RING_PATHLIMIT ) ;
		return 0 ;
	}
	/* Check file */
	if ( pRingState->pRingFilesList == NULL ) {
		pRingState->pRingFilesList = ring_list_new_gc(pRingState,RING_ZERO);
		pRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		nFreeFilesList = 1 ;
	}
	else {
		if ( ring_list_findstring(pRingState->pRingFilesList,cFileName,RING_ZERO) == 0 ) {
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		}
		else {
			/* Be Sure that we are not using the (Load Again) command */
			if ( ! pRingState->nLoadAgain ) {
				if ( pRingState->nWarning ) {
					printf( "\nWarning (W1) : Duplication in file name : %s \n",cFileName ) ;
				}
				return 1 ;
			}
			else {
				ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
			}
		}
	}
	/* Switch To File Folder */
	strcpy(cFileName2,cFileName);
	if ( nFreeFilesList == 0 ) {
		fp = ring_custom_fopen(cFileName , "r");
		ring_general_switchtofilefolder(cFileName2);
	}
	else {
		fp = RING_OPENFILE(cFileName , "r");
	}
	/* Read File */
	if ( fp==NULL ) {
		printf( "\nCan't open file %s \n",cFileName ) ;
		ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
		return 0 ;
	}
	RING_READCHAR(fp,c,nSize);
	pScanner = ring_scanner_new(pRingState);
	/* Check Startup file */
	if ( ring_general_fexists("startup.ring") && pScanner->pRingState->lStartup == 0 ) {
		pScanner->pRingState->lStartup = 1 ;
		strcpy(cStartup,"Load 'startup.ring'");
		/* Load "startup.ring" */
		for ( x = 0 ; x < strlen(cStartup) ; x++ ) {
			ring_scanner_readchar(pScanner,cStartup[x]);
		}
		/* Set the line number */
		ring_string_setfromint_gc(pRingState,pScanner->sActiveToken,RING_ONE);
		ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
		pScanner->nLinesCount = 1 ;
	}
	/* Check Syntax File */
	strcpy(cFileName2,cFileName);
	ring_general_justfilename(cFileName2);
	if ( ring_general_fexists("ringsyntax.ring") && ! (strcmp(cFileName2,"ringsyntax.ring") == 0) ) {
		strcpy(cStartup,"LOADSYNTAX \"ringsyntax.ring\" \n");
		/* Load "ringsyntax.ring" */
		for ( x = 0 ; x < strlen(cStartup) ; x++ ) {
			ring_scanner_readchar(pScanner,cStartup[x]);
		}
		ring_string_setfromint_gc(pRingState,pScanner->sActiveToken,RING_ONE);
		ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
		pScanner->nLinesCount = 1 ;
	}
	nSize = 1 ;
	while ( (c != EOF) && (nSize != 0) ) {
		ring_scanner_readchar(pScanner,c);
		RING_READCHAR(fp,c,nSize);
	}
	nCont = ring_scanner_checklasttoken(pScanner);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	RING_CLOSEFILE(fp);
	/* Print Tokens */
	if ( pRingState->nPrintTokens ) {
		ring_scanner_printtokens(pScanner);
	}
	/* Call Parser */
	if ( (nCont == 1) && (pRingState->nOnlyTokens == 0) ) {
		if ( pScanner->pRingState->nPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			puts("Grammar Rules Used by The Parser ");
			ring_general_printline();
			printf( "\nRule : Program --> {Statement}\n\nLine 1\n" ) ;
		}
		nRunVM = ring_parser_start(pScanner->pTokens,pRingState);
		if ( pScanner->pRingState->nPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			printf( "\n" ) ;
		}
	}
	else {
		ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
		/* Check if we need the tokens only */
		if ( pRingState->nOnlyTokens ) {
			pRingState->pRingFileTokens = pScanner->pTokens ;
			pScanner->pTokens = NULL ;
		}
		ring_scanner_delete(pScanner);
		return 0 ;
	}
	ring_scanner_delete(pScanner);
	/* Files List */
	ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
	if ( nFreeFilesList ) {
		/* Generate the Object File */
		if ( pRingState->nGenObj ) {
			ring_objfile_writefile(pRingState);
		}
		if ( pRingState->nGenCObj ) {
			ring_objfile_writeCfile(pRingState);
		}
		/* Run the Program */
		if ( nRunVM == 1 ) {
			ring_state_runprogram(pRingState);
			return 1 ;
		}
	}
	return nRunVM ;
}

RING_API void ring_state_runobjectfile ( RingState *pRingState,char *cFileName )
{
	/* Check Path Size */
	if ( strlen(cFileName) > RING_PATHLIMIT ) {
		printf( "\nVery long path! Can't open %s  The maximum path size is %d \n",cFileName,RING_PATHLIMIT ) ;
		return ;
	}
	/* Files List */
	pRingState->pRingFilesList = ring_list_new_gc(pRingState,RING_ZERO);
	pRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
	if ( ring_objfile_readfile(pRingState,cFileName) ) {
		pRingState->lRunFromObjectFile = 1 ;
		ring_state_runprogram(pRingState);
	}
}

RING_API void ring_state_runobjectstring ( RingState *pRingState,char *cString,const char *cFileName )
{
	/* Files List */
	pRingState->pRingFilesList = ring_list_new_gc(pRingState,RING_ZERO);
	pRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
	ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
	if ( ring_objfile_readstring(pRingState,cString) ) {
		pRingState->lRunFromObjectFile = 1 ;
		ring_state_runprogram(pRingState);
	}
}

RING_API void ring_state_runprogram ( RingState *pRingState )
{
	VM *pVM  ;
	/* Add return to the end of the program */
	ring_scanner_addreturn(pRingState);
	if ( pRingState->nPrintIC ) {
		ring_parser_icg_showoutput(pRingState->pRingGenCode);
	}
	if ( ! pRingState->nRun ) {
		return ;
	}
	pVM = ring_vm_new(pRingState);
	ring_vm_start(pRingState,pVM);
	/* Display Generated Code */
	if ( pRingState->nPrintICFinal ) {
		ring_vm_showbytecode(pVM);
	}
	if ( ! pRingState->nDontDeleteTheVM ) {
		ring_vm_delete(pVM);
	}
}

RING_API void ring_state_log ( RingState *pRingState,const char *cStr )
{
	/* Log File */
	#if RING_LOGFILE
		fprintf( pRingState->pLogFile , "%s\n" , cStr ) ;
		fflush(pRingState->pLogFile);
	#endif
}

void ring_state_cgiheader ( RingState *pRingState )
{
	if ( pRingState->nISCGI == 1 ) {
		printf( "Content-Type: text/plain \n\n" ) ;
	}
}

void ring_state_segfaultaction ( int sig )
{
	if ( nRingStateDEBUGSEGFAULT == 1 ) {
		if ( nRingStateCGI == 1 ) {
			printf( "Content-Type: text/plain\n\n" ) ;
		}
		printf( RING_SEGFAULT ) ;
		printf( " : %d ",sig ) ;
	}
	exit(0);
}

RING_API int ring_state_runstring ( RingState *pRingState,char *cString )
{
	signed char c  ;
	Scanner *pScanner  ;
	VM *pVM  ;
	int nCont,nRunVM,nFreeFilesList = 0 ;
	int x  ;
	const char *cFileName = "runstring" ;
	/* Check file */
	if ( pRingState->pRingFilesList == NULL ) {
		pRingState->pRingFilesList = ring_list_new_gc(pRingState,RING_ZERO);
		pRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		nFreeFilesList = 1 ;
	}
	else {
		if ( ring_list_findstring(pRingState->pRingFilesList,cFileName,RING_ZERO) == 0 ) {
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		}
		else {
			/* Be Sure that we are not using the (Load Again) command */
			if ( ! pRingState->nLoadAgain ) {
				if ( pRingState->nWarning ) {
					printf( "\nWarning (W1) : Duplication in file name : %s \n",cFileName ) ;
				}
				return 1 ;
			}
			else {
				ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
			}
		}
	}
	/* Read String */
	pScanner = ring_scanner_new(pRingState);
	for ( x = 0 ; x < strlen(cString) ; x++ ) {
		c = cString[x] ;
		ring_scanner_readchar(pScanner,c);
	}
	nCont = ring_scanner_checklasttoken(pScanner);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	/* Print Tokens */
	if ( pRingState->nPrintTokens ) {
		ring_scanner_printtokens(pScanner);
	}
	/* Call Parser */
	if ( (nCont == 1) && (pRingState->nOnlyTokens == 0) ) {
		if ( pScanner->pRingState->nPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			puts("Grammar Rules Used by The Parser ");
			ring_general_printline();
			printf( "\nRule : Program --> {Statement}\n\nLine 1\n" ) ;
		}
		nRunVM = ring_parser_start(pScanner->pTokens,pRingState);
		if ( pScanner->pRingState->nPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			printf( "\n" ) ;
		}
	}
	else {
		ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
		/* Check if we need the tokens only */
		if ( pRingState->nOnlyTokens ) {
			pRingState->pRingFileTokens = pScanner->pTokens ;
			pScanner->pTokens = NULL ;
		}
		ring_scanner_delete(pScanner);
		return 0 ;
	}
	ring_scanner_delete(pScanner);
	/* Files List */
	ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
	if ( nFreeFilesList ) {
		/* Generate the Object File */
		if ( pRingState->nGenObj ) {
			ring_objfile_writefile(pRingState);
		}
		if ( pRingState->nGenCObj ) {
			ring_objfile_writeCfile(pRingState);
		}
		/* Run the Program */
		if ( nRunVM == 1 ) {
			ring_state_runprogram(pRingState);
			return 1 ;
		}
	}
	return nRunVM ;
}

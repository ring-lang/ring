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
	pRingState->lISCGI = 0 ;
	pRingState->lRun = 1 ;
	pRingState->lPrintIC = 0 ;
	pRingState->lPrintICFinal = 0 ;
	pRingState->lPrintTokens = 0 ;
	pRingState->lPrintRules = 0 ;
	pRingState->lPrintInstruction = 0 ;
	pRingState->lGenObj = 0 ;
	pRingState->lGenCObj = 0 ;
	pRingState->lWarning = 0 ;
	pRingState->nArgc = 0 ;
	pRingState->pArgv = NULL ;
	pRingState->pVM = NULL ;
	pRingState->lStartup = 0 ;
	/* Pool Manager */
	ring_poolmanager_new(pRingState);
	pRingState->lDontDeleteTheVM = 0 ;
	pRingState->nRingInsideRing = 0 ;
	pRingState->lNoLineNumber = 0 ;
	pRingState->nCustomGlobalScopeCounter = 0 ;
	pRingState->pCustomGlobalScopeStack = ring_list_new(RING_ZERO) ;
	pRingState->lStartPoolManager = 0 ;
	pRingState->lDisablePoolManager = 0 ;
	pRingState->lCreateListsUsingBlocks = 1 ;
	pRingState->lRunFromThread = 0 ;
	pRingState->nLoadAgain = 0 ;
	ring_list_addint(pRingState->pCustomGlobalScopeStack,pRingState->nCustomGlobalScopeCounter);
	/* Log File */
	#if RING_LOGFILE
		pRingState->pLogFile = fopen(RING_FILES_LOGFILE , "w+" );
	#endif
	/* Tokens Only */
	pRingState->lOnlyTokens = 0 ;
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
	pRingState->lDisablePoolManager = 1 ;
	ring_vm_init(pRingState);
	pRingState->lDisablePoolManager = 0 ;
	return pRingState ;
}

RING_API void ring_state_runcode ( RingState *pRingState,const char *cStr )
{
	/* Avoid changing nPC to the start of instructions when we use the Return from Eval */
	pRingState->pVM->nPC = pRingState->nInstructionsCount ;
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

RING_API void ring_state_main ( int nArgc, char *pArgv[] )
{
	int x,lCGI,lRun,lPrintIC,lPrintICFinal,lTokens,lRules,lIns,lPerformance,lSrc,lGenObj,lGenCObj,lWarn  ;
	char *cStr  ;
	/* Init Values */
	lCGI = 0 ;
	lRun = 1 ;
	lPrintIC = 0 ;
	lPrintICFinal = 0 ;
	lTokens = 0 ;
	lRules = 0 ;
	lIns = 0 ;
	lPerformance = 0 ;
	cStr = NULL ;
	lSrc = 0 ;
	lGenObj = 0 ;
	lGenCObj = 0 ;
	lWarn = 0 ;
	lRingStateDebugSegFault = 0 ;
	lRingStateCGI = 0 ;
	signal(SIGSEGV,ring_state_segfaultaction);
	if ( nArgc > 1 ) {
		for ( x = 1 ; x < nArgc ; x++ ) {
			if ( strcmp(pArgv[x],"-cgi") == 0 ) {
				lCGI = 1 ;
				lRingStateCGI = 1 ;
			}
			else if ( strcmp(pArgv[x],"-tokens") == 0 ) {
				lTokens = 1 ;
			}
			else if ( strcmp(pArgv[x],"-rules") == 0 ) {
				lRules = 1 ;
			}
			else if ( strcmp(pArgv[x],"-ic") == 0 ) {
				lPrintIC = 1 ;
			}
			else if ( strcmp(pArgv[x],"-norun") == 0 ) {
				lRun = 0 ;
			}
			else if ( strcmp(pArgv[x],"-icfinal") == 0 ) {
				lPrintICFinal = 1 ;
			}
			else if ( strcmp(pArgv[x],"-ins") == 0 ) {
				lIns = 1 ;
			}
			else if ( strcmp(pArgv[x],"-clock") == 0 ) {
				lPerformance = 1 ;
			}
			else if ( strcmp(pArgv[x],"-go") == 0 ) {
				lGenObj = 1 ;
			}
			else if ( strcmp(pArgv[x],"-geo") == 0 ) {
				lGenCObj = 1 ;
			}
			else if ( strcmp(pArgv[x],"-w") == 0 ) {
				lWarn = 1 ;
				lRingStateDebugSegFault = 1 ;
			}
			else if ( ( ring_general_issourcefile(pArgv[x]) || ring_general_isobjectfile(pArgv[x])) && lSrc == 0 ) {
				cStr = pArgv[x] ;
				lSrc = 1 ;
			}
			else {
				if ( lSrc == 0 ) {
					if ( ring_general_fexists(pArgv[x]) ) {
						cStr = pArgv[x] ;
						lSrc = 1 ;
					}
					else {
						ring_general_printline();
						printf( "%s%s\n",RING_WARNING_UNKNOWNOPTION,pArgv[x] ) ;
					}
				}
			}
		}
	}
	if ( lPerformance ) {
		ring_general_showtime();
	}
	srand(time(NULL));
	/* Check Startup ring.ring */
	if ( ring_general_fexists(RING_FILES_AUTOLOADSRC) && nArgc == 1 ) {
		ring_state_execute((char *) RING_FILES_AUTOLOADSRC,lCGI,lRun,lPrintIC,lPrintICFinal,lTokens,lRules,lIns,lGenObj,lGenCObj,lWarn,nArgc,pArgv);
		exit(RING_EXIT_OK);
	}
	if ( ring_general_fexists(RING_FILES_AUTOLOADOBJ) && nArgc == 1 ) {
		ring_state_execute((char *) RING_FILES_AUTOLOADOBJ,lCGI,lRun,lPrintIC,lPrintICFinal,lTokens,lRules,lIns,lGenObj,lGenCObj,lWarn,nArgc,pArgv);
		exit(RING_EXIT_OK);
	}
	/* Print Version */
	if ( (nArgc == 1) || (cStr == NULL) ) {
		ring_state_usageinfo();
	}
	ring_state_execute(cStr,lCGI,lRun,lPrintIC,lPrintICFinal,lTokens,lRules,lIns,lGenObj,lGenCObj,lWarn,nArgc,pArgv);
	if ( lPerformance ) {
		ring_general_showtime();
	}
}

RING_API void ring_state_execute ( char *cFileName, int lISCGI,int lRun,int lPrintIC,int lPrintICFinal,int lTokens,int lRules,int lIns,int lGenObj,int lGenCObj,int lWarn,int nArgc,char *pArgv[] )
{
	RingState *pRingState  ;
	pRingState = ring_state_new();
	pRingState->lISCGI = lISCGI ;
	pRingState->lRun = lRun ;
	pRingState->lPrintIC = lPrintIC ;
	pRingState->lPrintICFinal = lPrintICFinal ;
	pRingState->lPrintTokens = lTokens ;
	pRingState->lPrintRules = lRules ;
	pRingState->lPrintInstruction = lIns ;
	pRingState->lGenObj = lGenObj ;
	pRingState->lGenCObj = lGenCObj ;
	pRingState->lWarning = lWarn ;
	pRingState->nArgc = nArgc ;
	pRingState->pArgv = pArgv ;
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
	Scanner *pScanner  ;
	VM *pVM  ;
	RING_FILE pFile  ;
	char cStartup[RING_SMALLBUF]  ;
	char cFileName2[RING_PATHSIZE]  ;
	int lCont,lRunVM,lFreeFilesList,x,nSize  ;
	/* Must be signed char to work fine on Android. */
	signed char c  ;
	lFreeFilesList = 0 ;
	/* Check Path Size */
	if ( strlen(cFileName) > RING_PATHLIMIT ) {
		printf( "%s %s %s %d \n",RING_CANTOPENFILE,cFileName,RING_VERYLONGPATH,RING_PATHLIMIT ) ;
		return 0 ;
	}
	/* Check file */
	if ( pRingState->pRingFilesList == NULL ) {
		pRingState->pRingFilesList = ring_list_new_gc(pRingState,RING_ZERO);
		pRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		lFreeFilesList = 1 ;
	}
	else {
		if ( ring_list_findstring(pRingState->pRingFilesList,cFileName,RING_ZERO) == 0 ) {
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		}
		else {
			/* Be Sure that we are not using the (Load Again) command */
			if ( ! pRingState->nLoadAgain ) {
				if ( pRingState->lWarning ) {
					printf( "\n%s%s \n",RING_WARNING_DUPLICATIONINFILENAME,cFileName ) ;
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
	if ( lFreeFilesList == 0 ) {
		pFile = ring_custom_fopen(cFileName , "r");
		ring_general_switchtofilefolder(cFileName2);
	}
	else {
		pFile = RING_OPENFILE(cFileName , "r");
	}
	/* Read File */
	if ( pFile==NULL ) {
		printf( "\n%s %s \n",RING_CANTOPENFILE,cFileName ) ;
		ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
		return 0 ;
	}
	RING_READCHAR(pFile,c,nSize);
	pScanner = ring_scanner_new(pRingState);
	/* Check Startup file */
	if ( ring_general_fexists(RING_FILES_STARTUP) && pScanner->pRingState->lStartup == 0 ) {
		pScanner->pRingState->lStartup = 1 ;
		strcpy(cStartup,RING_FILES_LOADSTARTUPSTR);
		/* Execute Load Startup File */
		for ( x = 0 ; x < strlen(cStartup) ; x++ ) {
			ring_scanner_readchar(pScanner,cStartup[x]);
		}
		/* Set the line number */
		ring_string_setfromint_gc(pRingState,pScanner->pActiveToken,RING_ONE);
		ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
		pScanner->nLinesCount = 1 ;
	}
	/* Check Syntax File */
	strcpy(cFileName2,cFileName);
	ring_general_justfilename(cFileName2);
	if ( ring_general_fexists(RING_FILES_AUTOLOADSYNTAX) && ! (strcmp(cFileName2,RING_FILES_AUTOLOADSYNTAX) == 0) ) {
		strcpy(cStartup,RING_FILES_LOADSYNTAXSTR);
		/* Execute Load Syntax File */
		for ( x = 0 ; x < strlen(cStartup) ; x++ ) {
			ring_scanner_readchar(pScanner,cStartup[x]);
		}
		ring_string_setfromint_gc(pRingState,pScanner->pActiveToken,RING_ONE);
		ring_scanner_addtoken(pScanner,SCANNER_TOKEN_ENDLINE);
		pScanner->nLinesCount = 1 ;
	}
	nSize = 1 ;
	while ( (c != EOF) && (nSize != 0) ) {
		ring_scanner_readchar(pScanner,c);
		RING_READCHAR(pFile,c,nSize);
	}
	lCont = ring_scanner_checklasttoken(pScanner);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	RING_CLOSEFILE(pFile);
	/* Print Tokens */
	if ( pRingState->lPrintTokens ) {
		ring_scanner_printtokens(pScanner);
	}
	/* Call Parser */
	if ( (lCont == 1) && (pRingState->lOnlyTokens == 0) ) {
		if ( pScanner->pRingState->lPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			puts(RING_MSG_PRINTRULES);
			ring_general_printline();
			printf( "%s",RING_MSG_PROGRAMRULE ) ;
		}
		lRunVM = ring_parser_start(pScanner->pTokens,pRingState);
		if ( pScanner->pRingState->lPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			printf( "\n" ) ;
		}
	}
	else {
		ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
		/* Check if we need the tokens only */
		if ( pRingState->lOnlyTokens ) {
			pRingState->pRingFileTokens = pScanner->pTokens ;
			pScanner->pTokens = NULL ;
		}
		ring_scanner_delete(pScanner);
		return 0 ;
	}
	ring_scanner_delete(pScanner);
	/* Files List */
	ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
	if ( lFreeFilesList ) {
		/* Generate the Object File */
		if ( pRingState->lGenObj ) {
			ring_objfile_writefile(pRingState);
		}
		if ( pRingState->lGenCObj ) {
			ring_objfile_writeCfile(pRingState);
		}
		/* Run the Program */
		if ( lRunVM == 1 ) {
			ring_state_runprogram(pRingState);
			return 1 ;
		}
	}
	return lRunVM ;
}

RING_API void ring_state_runobjectfile ( RingState *pRingState,char *cFileName )
{
	/* Check Path Size */
	if ( strlen(cFileName) > RING_PATHLIMIT ) {
		printf( "%s %s %s %d \n",RING_CANTOPENFILE,cFileName,RING_VERYLONGPATH,RING_PATHLIMIT ) ;
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
	if ( pRingState->lPrintIC ) {
		ring_parser_icg_showoutput(pRingState->pRingGenCode);
	}
	if ( ! pRingState->lRun ) {
		return ;
	}
	pVM = ring_vm_new(pRingState);
	ring_vm_start(pRingState,pVM);
	/* Display Generated Code */
	if ( pRingState->lPrintICFinal ) {
		ring_vm_showbytecode(pVM);
	}
	if ( ! pRingState->lDontDeleteTheVM ) {
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

RING_API int ring_state_runstring ( RingState *pRingState,char *cString )
{
	Scanner *pScanner  ;
	VM *pVM  ;
	const char *cFileName = "runstring" ;
	int x,lCont,lRunVM,lFreeFilesList  ;
	signed char c  ;
	lFreeFilesList = 0 ;
	/* Check file */
	if ( pRingState->pRingFilesList == NULL ) {
		pRingState->pRingFilesList = ring_list_new_gc(pRingState,RING_ZERO);
		pRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
		ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		lFreeFilesList = 1 ;
	}
	else {
		if ( ring_list_findstring(pRingState->pRingFilesList,cFileName,RING_ZERO) == 0 ) {
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesList,cFileName);
			ring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,cFileName);
		}
		else {
			/* Be Sure that we are not using the (Load Again) command */
			if ( ! pRingState->nLoadAgain ) {
				if ( pRingState->lWarning ) {
					printf( "\n%s%s \n",RING_WARNING_DUPLICATIONINFILENAME,cFileName ) ;
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
	lCont = ring_scanner_checklasttoken(pScanner);
	/* Add Token "End of Line" to the end of any program */
	ring_scanner_endofline(pScanner);
	/* Print Tokens */
	if ( pRingState->lPrintTokens ) {
		ring_scanner_printtokens(pScanner);
	}
	/* Call Parser */
	if ( (lCont == 1) && (pRingState->lOnlyTokens == 0) ) {
		if ( pScanner->pRingState->lPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			puts(RING_MSG_PRINTRULES);
			ring_general_printline();
			printf( "%s",RING_MSG_PROGRAMRULE ) ;
		}
		lRunVM = ring_parser_start(pScanner->pTokens,pRingState);
		if ( pScanner->pRingState->lPrintRules ) {
			printf( "\n" ) ;
			ring_general_printline();
			printf( "\n" ) ;
		}
	}
	else {
		ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
		/* Check if we need the tokens only */
		if ( pRingState->lOnlyTokens ) {
			pRingState->pRingFileTokens = pScanner->pTokens ;
			pScanner->pTokens = NULL ;
		}
		ring_scanner_delete(pScanner);
		return 0 ;
	}
	ring_scanner_delete(pScanner);
	/* Files List */
	ring_list_deleteitem_gc(pRingState,pRingState->pRingFilesStack,ring_list_getsize(pRingState->pRingFilesStack));
	if ( lFreeFilesList ) {
		/* Generate the Object File */
		if ( pRingState->lGenObj ) {
			ring_objfile_writefile(pRingState);
		}
		if ( pRingState->lGenCObj ) {
			ring_objfile_writeCfile(pRingState);
		}
		/* Run the Program */
		if ( lRunVM == 1 ) {
			ring_state_runprogram(pRingState);
			return 1 ;
		}
	}
	return lRunVM ;
}

void ring_state_cgiheader ( RingState *pRingState )
{
	if ( pRingState->lISCGI == 1 ) {
		printf( RING_CGI_START ) ;
	}
}

void ring_state_segfaultaction ( int nSig )
{
	if ( lRingStateDebugSegFault == 1 ) {
		if ( lRingStateCGI == 1 ) {
			printf( RING_CGI_START ) ;
		}
		printf( RING_SEGFAULT ) ;
		printf( " : %d ",nSig ) ;
	}
	exit(RING_EXIT_OK);
}

void ring_state_usageinfo ( void )
{
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
	exit(RING_EXIT_OK);
}

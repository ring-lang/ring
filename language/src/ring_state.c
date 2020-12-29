/*
**  Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#include <sys/types.h>
#include <sys/stat.h>
#ifdef _WIN32
/* Windows only */
#include <direct.h>
#define GetCurrentDir _getcwd
/* Microsoft Visual Studio doesn't define S_ISREG and S_ISDIR */
#ifdef _MSC_VER
#if !defined(S_ISREG) && defined(_S_IFMT) && defined(_S_IFREG)
  #define S_ISREG(m) (((m) & _S_IFMT) == _S_IFREG)
#endif
#if !defined(S_ISDIR) && defined(_S_IFMT) && defined(_S_IFDIR)
  #define S_ISDIR(m) (((m) & _S_IFMT) == _S_IFDIR)
#endif
#define stat _stat
#endif
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#if __MACH__
/* Mac OS X */
#include <mach-o/dyld.h>
#endif
#endif
/* General Options (Only for ring_state_main()) */
static int nRingStateDEBUGSEGFAULT  ;
static int nRingStateCGI  ;
/* Define Functions */
#if RING_TESTUNITS

static void ring_testallunits ( void ) ;
#endif

static void ring_showtime ( void ) ;

void segfaultaction ( int sig ) ;
/* API Functions */

RING_API RingState * ring_state_new ( void )
{
	RingState *pRingState  ;
	pRingState = (RingState *) ring_malloc(sizeof(RingState));
	if ( pRingState == NULL ) {
		printf( RING_OOM ) ;
		exit(0);
	}
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
	pRingState->argc = 0 ;
	pRingState->argv = NULL ;
	pRingState->pVM = NULL ;
	pRingState->lStartup = 0 ;
	/* Pool Manager */
	ring_poolmanager_new(pRingState);
	pRingState->nDontDeleteTheVM = 0 ;
	pRingState->nRingInsideRing = 0 ;
	pRingState->lNoLineNumber = 0 ;
	pRingState->nCustomGlobalScopeCounter = 0 ;
	pRingState->aCustomGlobalScopeStack = ring_list_new(0) ;
	pRingState->lStartPoolManager = 0 ;
	pRingState->lRunFromThread = 0 ;
	pRingState->nLoadAgain = 0 ;
	ring_list_addint(pRingState->aCustomGlobalScopeStack,pRingState->nCustomGlobalScopeCounter);
	/* Log File */
	#if RING_LOGFILE
	pRingState->pLogFile = fopen("ringlog.txt" , "w+" );
	#endif
	/* Tokens Only */
	pRingState->nOnlyTokens = 0 ;
	pRingState->pRingFileTokens = NULL ;
	pRingState->lNotCaseSensitive = 1 ;
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
	pRingState->aCustomGlobalScopeStack = ring_list_delete(pRingState->aCustomGlobalScopeStack);
	/* Log File */
	#if RING_LOGFILE
	fclose( pRingState->pLogFile ) ;
	#endif
	ring_poolmanager_delete(pRingState);
	ring_free(pRingState);
	return NULL ;
}

void ring_state_cgiheader ( RingState *pRingState )
{
	if ( pRingState->nISCGI == 1 ) {
		printf( "Content-Type: text/plain \n\n" ) ;
	}
}

RING_API void ring_print_line ( void )
{
	puts("===========================================================================");
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
	signal(SIGSEGV,segfaultaction);
	#if RING_TESTUNITS
	ring_testallunits();
	#endif
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
			else if ( ( ring_issourcefile(argv[x]) || ring_isobjectfile(argv[x])) && nSRC == 0 ) {
				cStr = argv[x] ;
				nSRC = 1 ;
			}
		}
	}
	if ( nPerformance ) {
		ring_showtime();
	}
	srand(time(NULL));
	/* Check Startup ring.ring */
	if ( ring_fexists("ring.ring") && argc == 1 ) {
		ring_execute((char *) "ring.ring",nCGI,nRun,nPrintIC,nPrintICFinal,nTokens,nRules,nIns,nGenObj,nGenCObj,nWarn,argc,argv);
		exit(0);
	}
	if ( ring_fexists("ring.ringo") && argc == 1 ) {
		ring_execute((char *) "ring.ringo",nCGI,nRun,nPrintIC,nPrintICFinal,nTokens,nRules,nIns,nGenObj,nGenCObj,nWarn,argc,argv);
		exit(0);
	}
	/* Print Version */
	if ( (argc == 1) || (cStr == NULL) ) {
		ring_print_line();
		printf( "Ring version %s \n2013-2020, Mahmoud Fayed <msfclipper@yahoo.com>\n",RING_VERSION ) ;
		puts("Usage : ring filename.ring [Options]");
		ring_print_line();
		/* Options */
		puts("-tokens   :  Print a list of tokens in the source code file");
		puts("-rules    :  Print grammar rules applied on the tokens");
		puts("-ic       :  Print the intermediate byte code (before execution)");
		puts("-icfinal  :  Print the final byte code (after execution)");
		puts("-cgi      :  Print http response header before error messages");
		puts("-norun    :  Don't run the program after compiling");
		puts("-ins      :  Print instruction operation code before execution");
		puts("-clock    :  Print clock before and after program execution");
		puts("-go       :  Generate object file");
		puts("-geo      :  Generate embedded object file (C source code)");
		puts("-w        :  Display Warnings");
		ring_print_line();
		exit(0);
	}
	ring_execute(cStr,nCGI,nRun,nPrintIC,nPrintICFinal,nTokens,nRules,nIns,nGenObj,nGenCObj,nWarn,argc,argv);
	if ( nPerformance ) {
		ring_showtime();
	}
}

RING_API void ring_state_runfile ( RingState *pRingState,char *cFileName )
{
	ring_scanner_readfile(pRingState,cFileName);
}

RING_API void ring_state_runobjectfile ( RingState *pRingState,char *cFileName )
{
	ring_scanner_runobjfile(pRingState,cFileName);
}

RING_API void ring_state_runobjectstring ( RingState *pRingState,char *cString,const char *cFileName )
{
	ring_scanner_runobjstring(pRingState,cString,cFileName);
}

RING_API void ring_state_log ( RingState *pRingState,const char *cStr )
{
	/* Log File */
	#if RING_LOGFILE
	fprintf( pRingState->pLogFile , "%s\n" , cStr ) ;
	fflush(pRingState->pLogFile);
	#endif
}
#if RING_TESTUNITS

static void ring_testallunits ( void )
{
	/* Test */
	ring_string_test();
	ring_list_test();
	ring_hashtable_test();
	printf( "end of test \n  " ) ;
	getchar();
}
#endif

static void ring_showtime ( void )
{
	time_t timer  ;
	char buffer[50]  ;
	struct tm*tm_info  ;
	clock_t myclock  ;
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer,50,"Date  : %Y/%m/%d Time : %H:%M:%S", tm_info);
	printf( "\n" ) ;
	ring_print_line();
	puts(buffer);
	myclock = clock();
	printf( "Clock : %ld \n", myclock ) ;
	ring_print_line();
}

void segfaultaction ( int sig )
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

int ring_issourcefile ( const char *cStr )
{
	int x  ;
	x = strlen(cStr) - 1 ;
	if ( x >= 5 ) {
		if ( tolower(cStr[x]) == 'g' && tolower(cStr[x-1]) == 'n' && tolower(cStr[x-2]) == 'i' && tolower(cStr[x-3]) == 'r' && cStr[x-4] == '.' ) {
			return 1 ;
		}
	}
	return 0 ;
}

int ring_isobjectfile ( const char *cStr )
{
	int x  ;
	x = strlen(cStr) - 1 ;
	if ( x > 6 ) {
		if ( tolower(cStr[x]) == 'o' && tolower(cStr[x-1]) == 'g' && tolower(cStr[x-2]) == 'n' && tolower(cStr[x-3]) == 'i' && tolower(cStr[x-4]) == 'r' && cStr[x-5] == '.' ) {
			return 1 ;
		}
	}
	return 0 ;
}
/* General Functions */

int ring_fexists ( const char *cFileName )
{
	struct stat sb;
	if (stat(cFileName, &sb) == 0) {
		if ( S_ISREG(sb.st_mode) ) {
			/* path exists and it is a regular file */
			return 1;
		}
	}
	return 0 ;
}

int ring_currentdir ( char *cDirPath )
{
	int nSize  ;
	nSize = RING_PATHSIZE ;
	if ( !GetCurrentDir(cDirPath, nSize) ) {
		return errno ;
	}
	cDirPath[nSize-1] = '\0' ;
	return 0 ;
}

int ring_exefilename ( char *cDirPath )
{
	unsigned int nSize  ;
	nSize = RING_PATHSIZE ;
	#ifdef _WIN32
	/* Windows only */
	GetModuleFileName(NULL,cDirPath,nSize);
	#elif __MACH__
	/* Mac OS X */
	_NSGetExecutablePath(cDirPath,&nSize);
	#elif __linux__
	/* readlink() doesn't null terminate */
	memset(cDirPath,0,nSize);
	if ( ! readlink("/proc/self/exe",cDirPath,nSize) ) {
		return 0 ;
	}
	#endif
	return 1 ;
}

int ring_chdir ( const char *cDir )
{
	#ifdef _WIN32
	/* Windows only */
	#ifdef __BORLANDC__
	/* Borland C/C++ */
	return chdir(cDir) ;
	#else
	/* Modern Compilers Like Visual C/C++ */
	return _chdir(cDir) ;
	#endif
	#else
	return chdir(cDir) ;
	#endif
}

void ring_exefolder ( char *cDirPath )
{
	char cDir[RING_PATHSIZE]  ;
	char cDir2[RING_PATHSIZE]  ;
	int x,x2,nSize  ;
	ring_exefilename(cDir);
	nSize = strlen( cDir ) ;
	strcpy(cDir2,"");
	for ( x = nSize-1 ; x >= 0 ; x-- ) {
		if ( (cDir[x] == '\\') || (cDir[x] == '/') ) {
			for ( x2 = x ; x2 >= 0 ; x2-- ) {
				cDir2[x2] = cDir[x2] ;
			}
			cDir2[x+1] = '\0' ;
			break ;
		}
	}
	strcpy(cDirPath,cDir2);
}

void ring_switchtofilefolder ( char *cFileName )
{
	char cFileName2[RING_PATHSIZE]  ;
	strcpy(cFileName2,cFileName);
	if ( ring_justfilepath(cFileName2) ) {
		ring_chdir(cFileName2);
		/* Remove The Path from the file Name - Keep the File Name Only */
		ring_justfilename(cFileName);
		return ;
	}
}

int ring_justfilepath ( char *cFileName )
{
	int x,nSize  ;
	nSize = strlen( cFileName ) ;
	for ( x = nSize-1 ; x >= 0 ; x-- ) {
		if ( (cFileName[x] == '\\') || (cFileName[x] == '/') ) {
			cFileName[x+1] = '\0' ;
			return 1 ;
		}
	}
	return 0 ;
}

void ring_justfilename ( char *cFileName )
{
	int x,nSize,r  ;
	nSize = strlen( cFileName ) ;
	for ( x = nSize-1 ; x >= 0 ; x-- ) {
		if ( (cFileName[x] == '\\') || (cFileName[x] == '/') ) {
			r = 0 ;
			for ( x = x+1 ; x <= nSize+1 ; x++ ) {
				cFileName[r] = cFileName[x] ;
				r++ ;
			}
			break ;
		}
	}
}

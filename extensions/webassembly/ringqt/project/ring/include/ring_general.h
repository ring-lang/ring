/*
**  Copyright (c) 2013-2021 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#ifdef _WIN32
	/* Windows only */
	#include <direct.h>
	#define GetCurrentDir _getcwd
#else
	#include <unistd.h>
	#define GetCurrentDir getcwd
	#if __MACH__
		/* Mac OS X */
		#include <mach-o/dyld.h>
	#endif
#endif
/* General Functions */

int ring_fexists ( const char *cFileName ) ;

int ring_currentdir ( char *cDirPath ) ;

int ring_exefilename ( char *cDirPath ) ;

int ring_chdir ( const char *cDir ) ;

void ring_exefolder ( char *cDirPath ) ;

void ring_switchtofilefolder ( char *cFileName ) ;

int ring_justfilepath ( char *cFileName ) ;

void ring_justfilename ( char *cFileName ) ;

int ring_issourcefile ( const char *cStr ) ;

int ring_isobjectfile ( const char *cStr ) ;

RING_API void ring_print_line ( void ) ;

void ring_showtime ( void ) ;

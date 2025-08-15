/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"
#ifdef _WIN32
	/* Windows only */
	#include <direct.h>
	#define GetCurrentDir _getcwd
	#ifndef RING_EXTENSION
		#include <windows.h>
	#endif
#else
	#if RING_MSDOS
	#else
		#include <unistd.h>
	#endif
	#define GetCurrentDir getcwd
	#if __MACH__
	/* Mac OS X */
		#include <mach-o/dyld.h>
	#endif
#endif

RING_API RING_FILE ring_general_fopen(const char *filename, const char *mode);

RING_API int ring_general_fexists(const char *cFileName);

RING_API int ring_general_currentdir(char *cDirPath);

RING_API int ring_general_exefilename(char *cDirPath);

RING_API int ring_general_chdir(const char *cDir);

RING_API int ring_general_justfilepath(char *cFileName);

RING_API int ring_general_justfilename(char *cFileName);

RING_API int ring_general_issourcefile(const char *cStr);

RING_API int ring_general_isobjectfile(const char *cStr);

RING_API int ring_general_folderexistinfilename(const char *cFolderName, const char *cFileName);

RING_API void ring_general_exefolder(char *cDirPath);

RING_API void ring_general_switchtofilefolder(char *cFileName);

RING_API void ring_general_addosfileseparator(char *cFileName);

RING_API void ring_general_readline(char *cLine, unsigned int nSize);

RING_API void ring_general_showtime(void);

RING_API void ring_general_printline(void);

RING_API char *ring_general_lower(char *cStr);

RING_API char *ring_general_lower2(char *cStr, unsigned int nStrSize);

RING_API char *ring_general_upper(char *cStr);

RING_API char *ring_general_upper2(char *cStr, unsigned int nStrSize);

RING_API char *ring_general_find(char *cStr1, char *cStr2);

RING_API char *ring_general_find2(char *cStr1, unsigned int nStrSize1, char *cStr2, unsigned int nStrSize2);

RING_API char *ring_general_find3(char *cStr1, unsigned int nStrSize1, char *cStr2, unsigned int nStrSize2);

RING_API char *ring_general_findsubstr(char *cStr1, unsigned int nStrSize1, char *cStr2, unsigned int nStrSize2,
				       int lNotCaseSensitive);

RING_API char *ring_general_numtostring(double nNum1, char *cStr, int nDecimals);

RING_API void ring_general_word(const char *cStr, unsigned int nIndex, char *cOutput);

RING_API int ring_general_looksempty(const char *cStr, unsigned int nSize);

RING_API int ring_general_strcmpnotcasesensitive(const char *cStr1, const char *cStr2);

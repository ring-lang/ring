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

RING_API void ring_general_printline(void);

RING_API char *ring_general_numtostring(double nNum1, char *cStr, int nDecimals);

RING_FILE ring_general_fopen(const char *filename, const char *mode);

int ring_general_fexists(const char *cFileName);

int ring_general_currentdir(char *cDirPath);

int ring_general_exefilename(char *cDirPath);

int ring_general_chdir(const char *cDir);

void ring_general_exefolder(char *cDirPath);

void ring_general_switchtofilefolder(char *cFileName);

int ring_general_justfilepath(char *cFileName);

void ring_general_justfilename(char *cFileName);

int ring_general_issourcefile(const char *cStr);

int ring_general_isobjectfile(const char *cStr);

void ring_general_showtime(void);

void ring_general_addosfileseparator(char *cFileName);

int ring_general_folderexistinfilename(const char *cFolderName, const char *cFileName);

void ring_general_readline(char *cLine, unsigned int nSize);

int ring_general_strcmpnotcasesensitive(const char *cStr1, const char *cStr2);

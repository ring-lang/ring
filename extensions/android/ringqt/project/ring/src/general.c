/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API RING_FILE ring_general_fopen(const char *cFileName, const char *cMode) {
#if defined(_WIN32) && !defined(__TINYC__)
	/* Code For MS-Windows */
	RING_FILE pFile;
	int nLen1, nLen2, nFileNameSize, nModeSize;
	wchar_t cPath[MAX_PATH];
	wchar_t cWMode[MAX_PATH];
	/* Set Variables */
	nFileNameSize = strlen(cFileName);
	nModeSize = strlen(cMode);
	if ((nFileNameSize == RING_ZERO) || (nModeSize == RING_ZERO)) {
		return NULL;
	}
	nLen1 = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, cFileName, nFileNameSize, cPath, MAX_PATH);
	if ((nLen1 == RING_ZERO) || (nLen1 >= MAX_PATH)) {
		return RING_OPENFILE(cFileName, cMode);
	}
	cPath[nLen1] = L'\0';
	nLen2 = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, cMode, nModeSize, cWMode, MAX_PATH);
	if ((nLen2 == RING_ZERO) || (nLen2 >= MAX_PATH)) {
		return RING_OPENFILE(cFileName, cMode);
	}
	cWMode[nLen2] = L'\0';
	pFile = _wfopen(cPath, cWMode);
	return pFile;
#else
	return RING_OPENFILE(cFileName, cMode);
#endif
}

RING_API int ring_general_fexists(const char *cFileName) {
	FILE *pFile;
	pFile = fopen(cFileName, "r");
	if (pFile) {
		fclose(pFile);
		return RING_TRUE;
	}
	return RING_FALSE;
}

RING_API int ring_general_currentdir(char *cDirPath) {
	int nSize;
	nSize = RING_PATHSIZE;
#if RING_CURRENTDIRFUNCTIONS
	if (!GetCurrentDir(cDirPath, nSize)) {
		return errno;
	}
#endif
	cDirPath[nSize - 1] = '\0';
	return RING_FALSE;
}

RING_API int ring_general_exefilename(char *cDirPath) {
	unsigned int nSize;
	nSize = RING_PATHSIZE;
#ifdef _WIN32
	/* Windows only */
	GetModuleFileName(NULL, cDirPath, nSize);
#elif __MACH__
	/* Mac OS X */
	_NSGetExecutablePath(cDirPath, &nSize);
	char *cCorrectPath = realpath(cDirPath, NULL);
	if (cCorrectPath != NULL) {
		strncpy(cDirPath, cCorrectPath, nSize);
		free(cCorrectPath);
	}
#elif __FreeBSD__
	/* FreeBSD */
	int mib[4] = {CTL_KERN, KERN_PROC, KERN_PROC_PATHNAME, -1};
	size_t cb = nSize;
	memset(cDirPath, RING_ZERO, nSize);
	if (sysctl(mib, 4, cDirPath, &cb, NULL, 0) != 0) {
		return RING_FALSE;
	}
#elif __linux__
	/* readlink() doesn't null terminate */
	memset(cDirPath, RING_ZERO, nSize);
	if (!readlink("/proc/self/exe", cDirPath, nSize)) {
		return RING_FALSE;
	}
#endif
	return RING_TRUE;
}

RING_API int ring_general_chdir(const char *cDir) {
#if RING_CURRENTDIRFUNCTIONS
	/* Check OS */
	#ifdef _WIN32
		/* Windows only */
		#ifdef __BORLANDC__
	/* Borland C/C++ */
	return chdir(cDir);
		#else
	/* Modern Compilers Like Visual C/C++ */
	return _chdir(cDir);
		#endif
	#else
	return chdir(cDir);
	#endif
#else
	return RING_ZERO;
#endif
}

RING_API int ring_general_justfilepath(char *cFileName) {
	int x, nSize;
	nSize = strlen(cFileName);
	for (x = nSize - 1; x >= 0; x--) {
		if ((cFileName[x] == '\\') || (cFileName[x] == '/')) {
			cFileName[x + 1] = '\0';
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

RING_API int ring_general_justfilename(char *cFileName) {
	int x, nSize, r;
	nSize = strlen(cFileName);
	for (x = nSize - 1; x >= 0; x--) {
		if ((cFileName[x] == '\\') || (cFileName[x] == '/')) {
			r = 0;
			for (x = x + 1; x <= nSize + 1; x++) {
				cFileName[r] = cFileName[x];
				r++;
			}
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

RING_API int ring_general_issourcefile(const char *cStr) {
	int x;
	x = strlen(cStr) - 1;
	if (x >= 5) {
		if (tolower(cStr[x]) == 'g' && tolower(cStr[x - 1]) == 'n' && tolower(cStr[x - 2]) == 'i' &&
		    tolower(cStr[x - 3]) == 'r' && cStr[x - 4] == '.') {
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

RING_API int ring_general_isobjectfile(const char *cStr) {
	int x;
	x = strlen(cStr) - 1;
	if (x > 6) {
		if (tolower(cStr[x]) == 'o' && tolower(cStr[x - 1]) == 'g' && tolower(cStr[x - 2]) == 'n' &&
		    tolower(cStr[x - 3]) == 'i' && tolower(cStr[x - 4]) == 'r' && cStr[x - 5] == '.') {
			return RING_TRUE;
		}
	}
	return RING_FALSE;
}

RING_API int ring_general_folderexistinfilename(const char *cFolderName, const char *cFileName) {
	unsigned int x, nSize;
	nSize = strlen(cFolderName);
	if (nSize < strlen(cFileName)) {
#ifdef _WIN32
		for (x = 0; x < nSize; x++) {
			if ((tolower(cFolderName[x]) != tolower(cFileName[x]))) {
				return RING_FALSE;
			}
		}
#else
		for (x = 0; x < nSize; x++) {
			if (cFolderName[x] != cFileName[x]) {
				return RING_FALSE;
			}
		}
#endif
		return RING_TRUE;
	}
	return RING_FALSE;
}

RING_API void ring_general_exefolder(char *cDirPath) {
	char cDir[RING_PATHSIZE];
	char cDir2[RING_PATHSIZE];
	int x, x2, nSize;
	ring_general_exefilename(cDir);
	nSize = strlen(cDir);
	strcpy(cDir2, RING_CSTR_EMPTY);
	for (x = nSize - 1; x >= 0; x--) {
		if ((cDir[x] == '\\') || (cDir[x] == '/')) {
			for (x2 = x; x2 >= 0; x2--) {
				cDir2[x2] = cDir[x2];
			}
			cDir2[x + 1] = '\0';
			break;
		}
	}
	strcpy(cDirPath, cDir2);
}

RING_API void ring_general_switchtofilefolder(char *cFileName) {
	char cFileName2[RING_PATHSIZE];
	strcpy(cFileName2, cFileName);
	if (ring_general_justfilepath(cFileName2)) {
		ring_general_chdir(cFileName2);
		/* Remove The Path from the file Name - Keep the File Name Only */
		ring_general_justfilename(cFileName);
		return;
	}
}

RING_API void ring_general_addosfileseparator(char *cFileName) {
#ifdef _WIN32
	strcat(cFileName, "\\");
#else
	strcat(cFileName, "/");
#endif
}

RING_API void ring_general_readline(char *cLine, unsigned int nSize) {
	unsigned int x;
	fgets(cLine, nSize, stdin);
	/* Remove New Line */
	for (x = 0; x < nSize; x++) {
		if (cLine[x] == '\n') {
			cLine[x] = '\0';
			break;
		}
	}
}

RING_API void ring_general_showtime(void) {
	time_t vTimer;
	char cBuffer[RING_MEDIUMBUF];
	struct tm *vTimeInfo;
	clock_t vClock;
	time(&vTimer);
	vTimeInfo = localtime(&vTimer);
	strftime(cBuffer, RING_MEDIUMBUF, "Date  : %Y/%m/%d Time : %H:%M:%S", vTimeInfo);
	printf("\n");
	ring_general_printline();
	puts(cBuffer);
	vClock = clock();
	printf("Clock : %ld \n", (long)vClock);
	ring_general_printline();
}

RING_API void ring_general_printline(void) {
	puts("===========================================================================");
}

RING_API char *ring_general_lower(char *cStr) {
	unsigned int x, nLen;
	nLen = strlen(cStr);
	for (x = RING_ZERO; x < nLen; x++) {
		if (isalpha((unsigned char)cStr[x])) {
			cStr[x] = tolower(cStr[x]);
		}
	}
	return cStr;
}

RING_API char *ring_general_lower2(char *cStr, unsigned int nStrSize) {
	unsigned int x;
	for (x = RING_ZERO; x < nStrSize; x++) {
		if (isalpha((unsigned char)cStr[x])) {
			cStr[x] = tolower(cStr[x]);
		}
	}
	return cStr;
}

RING_API char *ring_general_upper(char *cStr) {
	unsigned int x, nLen;
	nLen = strlen(cStr);
	for (x = RING_ZERO; x < nLen; x++) {
		if (isalpha((unsigned char)cStr[x])) {
			cStr[x] = toupper(cStr[x]);
		}
	}
	return cStr;
}

RING_API char *ring_general_upper2(char *cStr, unsigned int nStrSize) {
	unsigned int x;
	for (x = RING_ZERO; x < nStrSize; x++) {
		if (isalpha((unsigned char)cStr[x])) {
			cStr[x] = toupper(cStr[x]);
		}
	}
	return cStr;
}

RING_API char *ring_general_find(char *cStr1, char *cStr2) {
	return ring_general_find2(cStr1, strlen(cStr1), cStr2, strlen(cStr2));
}

RING_API char *ring_general_find2(char *cStr1, unsigned int nStrSize1, char *cStr2, unsigned int nStrSize2) {
	return ring_general_findsubstr(cStr1, nStrSize1, cStr2, nStrSize2, RING_FALSE);
}

RING_API char *ring_general_find3(char *cStr1, unsigned int nStrSize1, char *cStr2, unsigned int nStrSize2) {
	return ring_general_findsubstr(cStr1, nStrSize1, cStr2, nStrSize2, RING_TRUE);
}

RING_API char *ring_general_findsubstr(char *cStr1, unsigned int nStrSize1, char *cStr2, unsigned int nStrSize2,
				       int lNotCaseSensitive) {
	unsigned int x, nPos;
	nPos = RING_ZERO;
	if (nStrSize1 < nStrSize2) {
		return NULL;
	}
	while (nPos <= (nStrSize1 - nStrSize2)) {
		x = RING_ZERO;
		/* Compare Characters */
		if (lNotCaseSensitive) {
			while ((x < nStrSize2) &&
			       (tolower((unsigned char)cStr1[nPos + x]) == tolower((unsigned char)cStr2[x]))) {
				x++;
			}
		} else {
			while ((x < nStrSize2) && (cStr1[nPos + x] == cStr2[x])) {
				x++;
			}
		}
		if (x == nStrSize2) {
			return cStr1 + nPos;
		}
		nPos++;
	}
	return NULL;
}

RING_API char *ring_general_numtostring(double nNum1, char *cStr, int nDecimals) {
	char cOptions[RING_SMALLBUF];
	int nNum2;
	RING_LONGLONG nVal;
	nVal = (RING_LONGLONG)nNum1;
	if ((nNum1 == nVal) && (nVal >= RING_LONGLONG_LOWVALUE && nVal <= RING_LONGLONG_HIGHVALUE)) {
		sprintf(cStr, RING_LONGLONG_FORMAT, nVal);
	} else {
		sprintf(cOptions, "%s%df", "%.", nDecimals);
#if RING_NOSNPRINTF
		sprintf(cStr, cOptions, nNum1);
#else
		/* Avoid buffer overrun by using snprint() function */
		nNum2 = snprintf(cStr, RING_MEDIUMBUF, cOptions, nNum1);
		if (nNum2 >= RING_MEDIUMBUF) {
			/* Result truncated so print in compact format with a precision of 90 */
			nNum2 = snprintf(cStr, RING_MEDIUMBUF, "%.90e", nNum1);
		}
		if (nNum2 < 0) {
			/* Error */
			cStr[0] = 0;
		}
#endif
	}
	return cStr;
}

RING_API void ring_general_word(const char *cStr, unsigned int nIndex, char *cOutput) {
	unsigned int nStart, nEnd, nSize, nWord, nOutIndex;
	/* This function will return a specific word from a string using the word index */
	nSize = strlen(cStr);
	/* Determine the start of the word */
	nStart = 0;
	if (nIndex != 1) {
		nWord = 1;
		while (nWord != nIndex) {
			if (cStr[++nStart] == ' ') {
				nStart++;
				nWord++;
			}
		}
	}
	/* Determine the End of the word */
	nEnd = nStart;
	nOutIndex = 0;
	while ((cStr[nEnd] != ' ') && (nEnd != nSize)) {
		cOutput[nOutIndex] = cStr[nEnd];
		nEnd++;
		nOutIndex++;
	}
	cOutput[nOutIndex] = '\0';
}

RING_API int ring_general_looksempty(const char *cStr, unsigned int nSize) {
	unsigned int x;
	if (nSize == RING_ZERO) {
		return RING_TRUE;
	}
	for (x = RING_ZERO; x < nSize; x++) {
		if (!((cStr[x] == ' ') || (cStr[x] == '\r') || (cStr[x] == '\n') || (cStr[x] == '\t'))) {
			return RING_FALSE;
		}
	}
	return RING_TRUE;
}

RING_API int ring_general_strcmpnotcasesensitive(const char *cStr1, const char *cStr2) {
	int nNum1;
	while (RING_TRUE) {
		nNum1 = tolower(*cStr1) - tolower(*cStr2);
		if (nNum1 != 0 || !*cStr1 || !*cStr2) {
			return nNum1;
		}
		cStr1++;
		cStr2++;
	}
}

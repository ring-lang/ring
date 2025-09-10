/* Copyright (c) 2013-2025 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "ring.h"

RING_API void ring_objfile_writefile(RingState *pRingState) {
	FILE *fObj;
	char cFileName[RING_HUGEBUF];
	/* Create File */
	sprintf(cFileName, "%so", ring_list_getstring(pRingState->pRingFilesList, RING_ONE));
	fObj = (FILE *)ring_general_fopen(cFileName, "w+b");
	fprintf(fObj, "# Ring Object File\n");
	fprintf(fObj, RING_OBJFILE_VERSION);
	fprintf(fObj, "\n");
	/* Write Functions Lists */
	fprintf(fObj, "# Functions List\n");
	ring_objfile_writelist(pRingState, fObj, pRingState->pRingFunctionsMap);
	/* Write Classes List */
	fprintf(fObj, "# Classes List\n");
	ring_objfile_writelist(pRingState, fObj, pRingState->pRingClassesMap);
	/* Write Packages */
	fprintf(fObj, "# Packages List\n");
	ring_objfile_writelist(pRingState, fObj, pRingState->pRingPackagesMap);
	/* Write Code */
	fprintf(fObj, "# Program Code\n");
	ring_objfile_writelist(pRingState, fObj, pRingState->pRingGenCode);
	/* Write Files List */
	fprintf(fObj, "# Files List\n");
	ring_objfile_writelist(pRingState, fObj, pRingState->pRingFilesList);
	/* Close File */
	fprintf(fObj, "# End of File\n");
	fclose(fObj);
}

RING_API void ring_objfile_writelist(RingState *pRingState, FILE *fObj, List *pList) {
	List *pList2;
	unsigned int x, x2, lCont;
	char *cString;
	char cKey[RING_OBJFILE_KEYSTRSIZE];
	strcpy(cKey, RING_OBJFILE_KEYSTRING);
	fprintf(fObj, "{\n");
	/* Write List Items */
	lCont = 1;
	for (x = 1; x <= ring_list_getsize(pList); x++) {
		if (ring_list_islist(pList, x)) {
			pList2 = ring_list_getlist(pList, x);
		} else {
			/* For the Files List */
			pList2 = pList;
			lCont = 0;
		}
		fprintf(fObj, "[T]\n");
		for (x2 = 1; x2 <= ring_list_getsize(pList2); x2++) {
			if (ring_list_isstring(pList2, x2)) {
				fprintf(fObj, "[S][%d]", ring_list_getstringsize(pList2, x2));
				/* Encrypt String */
				cString = ring_list_getstring(pList2, x2);
				ring_objfile_xorstring(pRingState, cString, ring_list_getstringsize(pList2, x2), cKey,
						       RING_OBJFILE_KEYSIZE);
				fwrite(ring_list_getstring(pList2, x2), 1, ring_list_getstringsize(pList2, x2), fObj);
				/* Decrypt String */
				ring_objfile_xorstring(pRingState, cString, ring_list_getstringsize(pList2, x2), cKey,
						       RING_OBJFILE_KEYSIZE);
				fprintf(fObj, "\n");
			} else if (ring_list_isint(pList2, x2)) {
				fprintf(fObj, "[I]%d\n", ring_list_getint(pList2, x2));
			} else if (ring_list_isdouble(pList2, x2)) {
				fprintf(fObj, "[D]%f\n", ring_list_getdouble(pList2, x2));
			} else if (ring_list_ispointer(pList2, x2)) {
				fprintf(fObj, "[P]%p\n", (void *)ring_list_getpointer(pList2, x2));
			} else if (ring_list_islist(pList2, x2)) {
				fprintf(fObj, "[L]\n");
				ring_objfile_writelist(pRingState, fObj, ring_list_getlist(pList2, x2));
			}
		}
		fprintf(fObj, "[E]\n");
		if (lCont == 0) {
			break;
		}
	}
	fprintf(fObj, "}\n");
}

RING_API int ring_objfile_readfile(RingState *pRingState, char *cFileName) {
	return ring_objfile_readfromsource(pRingState, cFileName, RING_OBJFILE_READFROMFILE);
}

RING_API int ring_objfile_readstring(RingState *pRingState, char *cString) {
	return ring_objfile_readfromsource(pRingState, cString, RING_OBJFILE_READFROMSTRING);
}

RING_API int ring_objfile_readfromsource(RingState *pRingState, char *cSource, int nSource) {
	List *pListFunctions, *pListClasses, *pListPackages, *pListCode, *pListFiles, *pListStack;
	int lFail;
	lFail = RING_FALSE;
	/* Create Lists */
	pListFunctions = ring_list_new_gc(pRingState, RING_ZERO);
	pListClasses = ring_list_new_gc(pRingState, RING_ZERO);
	pListPackages = ring_list_new_gc(pRingState, RING_ZERO);
	pListCode = ring_list_new_gc(pRingState, RING_ZERO);
	pListFiles = ring_list_new_gc(pRingState, RING_ZERO);
	pListStack = ring_list_new_gc(pRingState, RING_ZERO);
	/* Process Content (File or String) */
	if (nSource == RING_OBJFILE_READFROMFILE) {
		if (!ring_objfile_processfile(pRingState, cSource, pListFunctions, pListClasses, pListPackages,
					      pListCode, pListFiles, pListStack)) {
			lFail = RING_TRUE;
		}
	} else if (nSource == RING_OBJFILE_READFROMSTRING) {
		if (!ring_objfile_processstring(pRingState, cSource, pListFunctions, pListClasses, pListPackages,
						pListCode, pListFiles, pListStack)) {
			lFail = RING_TRUE;
		}
	}
	ring_list_delete_gc(pRingState, pListStack);
	if (lFail) {
		/* Delete Lists */
		ring_list_delete_gc(pRingState, pListFunctions);
		ring_list_delete_gc(pRingState, pListClasses);
		ring_list_delete_gc(pRingState, pListPackages);
		ring_list_delete_gc(pRingState, pListCode);
		ring_list_delete_gc(pRingState, pListFiles);
		return RING_FALSE;
	}
	/*
	**  Update Ring State
	**  Update Lists
	*/
	pRingState->pRingFunctionsMap = pListFunctions;
	pRingState->pRingClassesMap = pListClasses;
	pRingState->pRingPackagesMap = pListPackages;
	pRingState->pRingGenCode = pListCode;
	/*
	**  Update the Files List
	**  Delete the old list (Contains only one file - the *.ringo file name)
	*/
	ring_list_deleteallitems_gc(pRingState, pRingState->pRingFilesList);
	/*
	**  Add all source code files (*.ring files) in the project
	**  The List contains sub list - i.e. looks like  [  [ files ] ] - but we need [ files ] only
	**  So we get the first item using ring_list_getlist() function
	*/
	ring_list_copy_gc(pRingState, pRingState->pRingFilesList, ring_list_getlist(pListFiles, RING_ONE));
	/* Delete pListFiles */
	ring_list_delete_gc(pRingState, pListFiles);
	/* Update Classes Pointers */
	ring_objfile_updateclassespointers(pRingState);
	return RING_TRUE;
}

RING_API int ring_objfile_processfile(RingState *pRingState, char *cFileName, List *pListFunctions, List *pListClasses,
				      List *pListPackages, List *pListCode, List *pListFiles, List *pListStack) {
	FILE *fObj;
	signed char c;
	int nActiveList, nValue, nBraceEnd, nOutput;
	double dValue;
	char *cString;
	char cKey[RING_OBJFILE_KEYSTRSIZE];
	char cFileType[RING_MEDIUMBUF];
	List *pList;
	strcpy(cKey, RING_OBJFILE_KEYSTRING);
	/* Set Active List (1=functions 2=classes 3=packages 4=code) */
	nActiveList = 0;
	nBraceEnd = 0;
	pList = NULL;
	/* Open File */
	fObj = (FILE *)ring_general_fopen(cFileName, "rb");
	if (fObj == NULL) {
		printf("%s %s \n", RING_CANTOPENFILE, cFileName);
		return RING_FALSE;
	}
	fread(cFileType, 1, RING_OBJFILE_FILETYPESTRCOUNT, fObj);
	cFileType[RING_OBJFILE_FILETYPESTRCOUNT] = '\0';
	if (strcmp(cFileType, RING_OBJFILE_FILETYPESTR) != 0) {
		printf(RING_OBJFILEWRONGTYPE);
		return RING_FALSE;
	}
	getc(fObj);
	fread(cFileType, 1, RING_OBJFILE_VERSIONSTRINGSIZE, fObj);
	cFileType[RING_OBJFILE_VERSIONSTRINGSIZE] = '\0';
	if (strcmp(cFileType, RING_OBJFILE_VERSION) != 0) {
		printf(RING_OBJFILEWRONGVERSION);
		return RING_FALSE;
	}
	/* Process File */
	c = getc(fObj);
	while ((c == '#') || (c == '{') || (c == '}') || (c == '[') || (c == '\n')) {
		/* Check Char */
		switch (c) {
		case '#':
			/* Read Line */
			while (c != '\n') {
				c = getc(fObj);
			}
			break;
		case '{':
			nActiveList++;
			switch (nActiveList) {
			case 1:
				pList = pListFunctions;
				break;
			case 2:
				pList = pListClasses;
				break;
			case 3:
				pList = pListPackages;
				break;
			case 4:
				pList = pListCode;
				break;
			case 5:
				pList = pListFiles;
				break;
			}
			break;
		case '[':
			c = getc(fObj);
			switch (c) {
			case 'S':
				getc(fObj);
				nOutput = fscanf(fObj, "[%d]", &nValue);
				if (nOutput == 0) {
					printf(RING_FSCANFERROR);
					return RING_FALSE;
				}
				cString = (char *)ring_state_malloc(pRingState, nValue + 1);
				fread(cString, 1, nValue, fObj);
				cString[nValue] = '\0';
				/* Decrypt String */
				ring_objfile_xorstring(pRingState, cString, nValue, cKey, RING_OBJFILE_KEYSIZE);
				ring_list_addstring2_gc(pRingState, pList, cString, nValue);
				ring_state_free(pRingState, cString);
				break;
			case 'I':
				getc(fObj);
				nOutput = fscanf(fObj, "%d", &nValue);
				if (nOutput == 0) {
					printf(RING_FSCANFERROR);
					return RING_FALSE;
				}
				ring_list_addint_gc(pRingState, pList, nValue);
				break;
			case 'D':
				getc(fObj);
				nOutput = fscanf(fObj, "%lf", &dValue);
				if (nOutput == 0) {
					printf(RING_FSCANFERROR);
					return RING_FALSE;
				}
				ring_list_adddouble_gc(pRingState, pList, dValue);
				break;
			case 'P':
				ring_list_addpointer_gc(pRingState, pList, NULL);
				/* Read Line */
				while (c != '\n') {
					c = getc(fObj);
				}
				break;
			case 'T':
				ring_list_addpointer_gc(pRingState, pListStack, pList);
				pList = ring_list_newlist_gc(pRingState, pList);
				/* Read Line */
				while (c != '\n') {
					c = getc(fObj);
				}
				break;
			case 'E':
				pList = (List *)ring_list_getpointer(pListStack, ring_list_getsize(pListStack));
				ring_list_deletelastitem_gc(pRingState, pListStack);
				/* Read Line */
				while (c != '\n') {
					c = getc(fObj);
				}
				break;
			case 'L':
				/* Read Until { */
				while (c != '{') {
					c = getc(fObj);
				}
				ring_list_addpointer_gc(pRingState, pListStack, pList);
				pList = ring_list_newlist_gc(pRingState, pList);
				nBraceEnd++;
				break;
			}
			break;
		case '}':
			if (nBraceEnd) {
				pList = (List *)ring_list_getpointer(pListStack, ring_list_getsize(pListStack));
				ring_list_deletelastitem_gc(pRingState, pListStack);
				nBraceEnd--;
			}
			break;
		}
		c = getc(fObj);
	}
	/* Close File */
	fclose(fObj);
	return RING_TRUE;
}

RING_API int ring_objfile_processstring(RingState *pRingState, char *cContent, List *pListFunctions, List *pListClasses,
					List *pListPackages, List *pListCode, List *pListFiles, List *pListStack) {
	signed char c;
	int nActiveList, nValue, nBraceEnd, nOutput;
	double dValue;
	char *cString, *cData;
	char cKey[RING_OBJFILE_KEYSTRSIZE];
	char cFileType[RING_MEDIUMBUF];
	List *pList;
	strcpy(cKey, RING_OBJFILE_KEYSTRING);
	/* Set Active List (1=functions 2=classes 3=packages 4=code) */
	nActiveList = 0;
	nBraceEnd = 0;
	pList = NULL;
	cData = cContent;
	/* Check Type and Version */
	ring_objfile_readc(pRingState, &cData, cFileType, RING_OBJFILE_FILETYPESTRCOUNT);
	cFileType[RING_OBJFILE_FILETYPESTRCOUNT] = '\0';
	if (strcmp(cFileType, RING_OBJFILE_FILETYPESTR) != 0) {
		printf(RING_OBJFILEWRONGTYPE);
		return RING_FALSE;
	}
	ring_objfile_getc(pRingState, &cData);
	ring_objfile_readc(pRingState, &cData, cFileType, RING_OBJFILE_VERSIONSTRINGSIZE);
	cFileType[RING_OBJFILE_VERSIONSTRINGSIZE] = '\0';
	if (strcmp(cFileType, RING_OBJFILE_VERSION) != 0) {
		printf(RING_OBJFILEWRONGVERSION);
		return RING_FALSE;
	}
	/* Process Content */
	c = ring_objfile_getc(pRingState, &cData);
	while ((c == '#') || (c == '{') || (c == '}') || (c == '[') || (c == '\n')) {
		/* Check Char */
		switch (c) {
		case '#':
			/* Read Line */
			while (c != '\n') {
				c = ring_objfile_getc(pRingState, &cData);
			}
			break;
		case '{':
			nActiveList++;
			switch (nActiveList) {
			case 1:
				pList = pListFunctions;
				break;
			case 2:
				pList = pListClasses;
				break;
			case 3:
				pList = pListPackages;
				break;
			case 4:
				pList = pListCode;
				break;
			case 5:
				pList = pListFiles;
				break;
			}
			break;
		case '[':
			c = ring_objfile_getc(pRingState, &cData);
			switch (c) {
			case 'S':
				ring_objfile_getc(pRingState, &cData);
				nOutput = sscanf(cData, "[%d]", &nValue);
				if (nOutput == EOF) {
					printf(RING_SSCANFERROR);
					return RING_FALSE;
				}
				/* Pass Letters */
				c = ' ';
				while (c != ']') {
					c = ring_objfile_getc(pRingState, &cData);
				}
				cString = (char *)ring_state_malloc(pRingState, nValue + 1);
				ring_objfile_readc(pRingState, &cData, cString, nValue);
				cString[nValue] = '\0';
				/* Decrypt String */
				ring_objfile_xorstring(pRingState, cString, nValue, cKey, RING_OBJFILE_KEYSIZE);
				ring_list_addstring2_gc(pRingState, pList, cString, nValue);
				ring_state_free(pRingState, cString);
				break;
			case 'I':
				ring_objfile_getc(pRingState, &cData);
				nOutput = sscanf(cData, "%d", &nValue);
				if (nOutput == EOF) {
					printf(RING_SSCANFERROR);
					return RING_FALSE;
				}
				/* Pass Letters */
				c = '0';
				while (isdigit(c) || c == '.') {
					c = ring_objfile_getc(pRingState, &cData);
				}
				cData--;
				ring_list_addint_gc(pRingState, pList, nValue);
				break;
			case 'D':
				ring_objfile_getc(pRingState, &cData);
				nOutput = sscanf(cData, "%lf", &dValue);
				if (nOutput == EOF) {
					printf(RING_SSCANFERROR);
					return RING_FALSE;
				}
				/* Pass Letters */
				c = '0';
				while (isdigit(c) || c == '.') {
					c = ring_objfile_getc(pRingState, &cData);
				}
				cData--;
				ring_list_adddouble_gc(pRingState, pList, dValue);
				break;
			case 'P':
				ring_list_addpointer_gc(pRingState, pList, NULL);
				/* Read Line */
				while (c != '\n') {
					c = ring_objfile_getc(pRingState, &cData);
				}
				break;
			case 'T':
				ring_list_addpointer_gc(pRingState, pListStack, pList);
				pList = ring_list_newlist_gc(pRingState, pList);
				/* Read Line */
				while (c != '\n') {
					c = ring_objfile_getc(pRingState, &cData);
				}
				break;
			case 'E':
				pList = (List *)ring_list_getpointer(pListStack, ring_list_getsize(pListStack));
				ring_list_deletelastitem_gc(pRingState, pListStack);
				/* Read Line */
				while (c != '\n') {
					c = ring_objfile_getc(pRingState, &cData);
				}
				break;
			case 'L':
				/* Read Until { */
				while (c != '{') {
					c = ring_objfile_getc(pRingState, &cData);
				}
				ring_list_addpointer_gc(pRingState, pListStack, pList);
				pList = ring_list_newlist_gc(pRingState, pList);
				nBraceEnd++;
				break;
			}
			break;
		case '}':
			if (nBraceEnd) {
				pList = (List *)ring_list_getpointer(pListStack, ring_list_getsize(pListStack));
				ring_list_deletelastitem_gc(pRingState, pListStack);
				nBraceEnd--;
			}
			break;
		}
		c = ring_objfile_getc(pRingState, &cData);
	}
	return RING_TRUE;
}

RING_API void ring_objfile_xorstring(RingState *pRingState, char *cString, int nStringSize, char *cKey, int nKeySize) {
	int x;
	for (x = 1; x <= nStringSize; x++) {
		cString[x - 1] = cString[x - 1] ^ cKey[(x - 1) % nKeySize];
	}
}

RING_API void ring_objfile_readc(RingState *pRingState, char **cSource, char *cDest, int nCount) {
	int x;
	char *cData;
	cData = *cSource;
	for (x = 0; x < nCount; x++) {
		cDest[x] = cData[x];
	}
	*cSource += nCount;
	cDest[nCount] = '\0';
}

RING_API char ring_objfile_getc(RingState *pRingState, char **cSource) {
	char c;
	char *cData;
	cData = *cSource;
	c = cData[0];
	*cSource += 1;
	return c;
}

RING_API void ring_objfile_writeCfile(RingState *pRingState) {
	FILE *fCode, *fCode2;
	char cCodeFileName[RING_HUGEBUF];
	int nSize, x, nFunction;
	/*
	**  Write C file
	**  Set the file name
	*/
	sprintf(cCodeFileName, "%s", ring_list_getstring(pRingState->pRingFilesList, RING_ONE));
	nSize = strlen(cCodeFileName);
	cCodeFileName[nSize - 4] = 'c';
	cCodeFileName[nSize - 3] = '\0';
	fCode = (FILE *)ring_general_fopen(cCodeFileName, "w+b");
	/* write the main function */
	fprintf(fCode, "#include \"ring.h\" \n\n");
	fprintf(fCode, "#include \"ringappcode.h\" \n\n");
	fprintf(fCode, "int main( int argc, char *argv[])\n");
	fprintf(fCode, "{\n");
	/* main function code */
	fprintf(fCode, "\tRingState *pRingState;  \n");
	fprintf(fCode, "\tpRingState = ring_state_new();  \n");
	fprintf(fCode, "\tpRingState->nArgc = argc;  \n");
	fprintf(fCode, "\tpRingState->pArgv = argv;  \n");
	fprintf(fCode, "\tpRingState->pRingFilesList = ring_list_new_gc(pRingState,RING_ZERO);  \n");
	fprintf(fCode, "\tpRingState->pRingFilesStack = ring_list_new_gc(pRingState,RING_ZERO);  \n");
	fprintf(fCode, "\tring_list_addstring_gc(pRingState,pRingState->pRingFilesList,\"%so\");  \n",
		ring_list_getstring(pRingState->pRingFilesList, RING_ONE));
	fprintf(fCode, "\tring_list_addstring_gc(pRingState,pRingState->pRingFilesStack,\"%so\");  \n",
		ring_list_getstring(pRingState->pRingFilesList, RING_ONE));
	fprintf(fCode, "\tloadRingCode(pRingState);  \n");
	fprintf(fCode, "\tring_state_delete(pRingState);  \n");
	fprintf(fCode, "\treturn 0;  \n");
	fprintf(fCode, "}\n\n");
	/* Create ringappcode.c */
	fclose(fCode);
	fCode = (FILE *)ring_general_fopen("ringappcode.c", "w+b");
	fprintf(fCode, "#include \"ringappcode.h\" \n\n");
	fprintf(fCode, "void loadRingCode(RingState *pRingState) {\n");
	fprintf(fCode, "\tList *pList1,*pList2,*pList3,*pList4,*pList5,*pList6 ;\n");
	/* Declare Ring VM */
	fprintf(fCode, "\tVM *pVM ;\n");
	/* Write Data */
	nFunction = ring_objfile_writelistcode(pRingState, fCode, pRingState->pRingFunctionsMap, RING_ONE, RING_TRUE,
					       RING_ZERO, RING_OBJFILE_ITEMSPERFUNCTION2);
	fprintf(fCode, "\tpRingState->pRingFunctionsMap = pList1;\n");
	nFunction = ring_objfile_writelistcode(pRingState, fCode, pRingState->pRingClassesMap, RING_ONE, RING_TRUE,
					       nFunction, RING_OBJFILE_ITEMSPERFUNCTION2);
	fprintf(fCode, "\tpRingState->pRingClassesMap = pList1;\n");
	nFunction = ring_objfile_writelistcode(pRingState, fCode, pRingState->pRingPackagesMap, RING_ONE, RING_TRUE,
					       nFunction, RING_OBJFILE_ITEMSPERFUNCTION2);
	fprintf(fCode, "\tpRingState->pRingPackagesMap = pList1;\n");
	/* Prepare Ring VM */
	fprintf(fCode, "\tring_state_newbytecode(pRingState,%d,RING_TRUE);\n",
		ring_list_getsize(pRingState->pRingGenCode) + 1);
	fprintf(fCode, "\tpVM = pRingState->pVM;\n");
	ring_objfile_writebytecode(pRingState, fCode, pRingState->pRingGenCode);
	fprintf(fCode, "\tring_state_runbytecode(pRingState);  \n");
	fprintf(fCode, "}\n");
	/* Close File */
	fclose(fCode);
	/* Declare functions that load the Ring code */
	fCode2 = (FILE *)ring_general_fopen("ringappcode.h", "w+b");
	fprintf(fCode2, "#include \"ring.h\" \n\n");
	fprintf(fCode2, "void loadRingCode(RingState *pRingState) ;\n\n");
	for (x = 1; x <= nFunction; x++) {
		fprintf(fCode2, "void loadRingCode%d(RingState *pRingState,List *pList1) ;\n\n", x);
	}
	fclose(fCode2);
}

RING_API int ring_objfile_writelistcode(RingState *pRingState, FILE *fCode, List *pList, int nList, int lSeparate,
					int nFunction, int nItemsPerFunction) {
	List *pList2;
	unsigned int x, x2, x3, nMax;
	char cList[RING_SMALLBUF];
	char *cString;
	char cFileName[RING_HUGEBUF];
	sprintf(cList, "pList%d", nList + 1);
	if (nList == 1) {
		fprintf(fCode, "\tpList1 = ring_list_new_gc(pRingState,RING_ZERO) ; \n");
	}
	/* Write List Items */
	for (x = 1; x <= ring_list_getsize(pList); x++) {
		/* Separate Code to different functions */
		if ((lSeparate == 1) && (nList == 1)) {
			if (x % nItemsPerFunction == 0) {
				nFunction++;
				/* Call the new function */
				fprintf(fCode, "\tloadRingCode%d(pRingState,pList1);  \n", nFunction);
				/* End the current function */
				fprintf(fCode, "}\n");
				/*
				**  Start New source file
				**  Close the current file
				*/
				fclose(fCode);
				/* Create another source file */
				sprintf(cFileName, "ringappcode%d.c", nFunction);
				fCode = (FILE *)ring_general_fopen(cFileName, "w+b");
				fprintf(fCode, "#include \"ring.h\" \n\n");
				fprintf(fCode, "#include \"ringappcode.h\" \n\n");
				/* Start New Functions */
				fprintf(fCode, "void loadRingCode%d(RingState *pRingState,List *pList1) {\n",
					nFunction);
				fprintf(fCode, "\tList *pList2,*pList3,*pList4,*pList5,*pList6 ;\n");
			}
		}
		pList2 = ring_list_getlist(pList, x);
		fprintf(fCode, "\tpList%d = ring_list_newlist_gc(pRingState,pList%d);\n", nList + 1, nList);
		for (x2 = 1; x2 <= ring_list_getsize(pList2); x2++) {
			if (ring_list_isstring(pList2, x2)) {
				fprintf(fCode, "\tring_list_addstring_gc(pRingState,%s,\"", cList);
				/* Add the string */
				cString = ring_list_getstring(pList2, x2);
				nMax = ring_list_getstringsize(pList2, x2);
				for (x3 = 0; x3 < nMax; x3++) {
					fprintf(fCode, "\\x%02x", (unsigned char)cString[x3]);
				}
				fprintf(fCode, "\"); \n");
			} else if (ring_list_isint(pList2, x2)) {
				fprintf(fCode, "\tring_list_addint_gc(pRingState,%s,", cList);
				fprintf(fCode, "%d", ring_list_getint(pList2, x2));
				fprintf(fCode, "); \n");
			} else if (ring_list_isdouble(pList2, x2)) {
				fprintf(fCode, "\tring_list_adddouble_gc(pRingState,%s,", cList);
				fprintf(fCode, "%f", ring_list_getdouble(pList2, x2));
				fprintf(fCode, "); \n");
			} else if (ring_list_ispointer(pList2, x2)) {
				fprintf(fCode, "\tring_list_addpointer_gc(pRingState,%s,NULL);\n", cList);
			} else if (ring_list_islist(pList2, x2)) {
				fprintf(fCode, "\tpList%d = ring_list_newlist_gc(pRingState,pList%d);\n", nList + 2,
					nList + 1);
				nFunction =
				    ring_objfile_writelistcode(pRingState, fCode, ring_list_getlist(pList2, x2),
							       nList + 2, lSeparate, nFunction, nItemsPerFunction);
			}
		}
	}
	return nFunction;
}

RING_API void ring_objfile_writebytecode(RingState *pRingState, FILE *fCode, List *pList) {
	unsigned int x, x2, nReg, x3, nMax;
	List *pIns;
	char *cString;
	for (x = 1; x <= ring_list_getsize(pList); x++) {
		pIns = ring_list_getlist(pList, x);
		/* Operation Code */
		fprintf(fCode, "\tpVM->pByteCode[%d].nOPCode = ", x - 1);
		fprintf(fCode, "%d ; \n", ring_list_getint(pIns, 1));
		/* Instruction Regsiters */
		for (x2 = 2; x2 <= ring_list_getsize(pIns); x2++) {
			/* Register Number */
			if (x2 == 2) {
				nReg = RING_VM_IR_REG1;
				fprintf(fCode, "\tpVM->pByteCode[%d].nReg1Type = ", x - 1);
			} else {
				nReg = RING_VM_IR_REG2;
				fprintf(fCode, "\tpVM->pByteCode[%d].nReg2Type = ", x - 1);
			}
			if (ring_list_isstring(pIns, x2)) {
				fprintf(fCode, "RING_VM_REGTYPE_STRING ; \n");
				fprintf(fCode, "\tpVM->pByteCode[%d].aReg[%d].pString = \"", x - 1, nReg);
				/* Add the string */
				cString = ring_list_getstring(pIns, x2);
				nMax = ring_list_getstringsize(pIns, x2);
				for (x3 = 0; x3 < nMax; x3++) {
					fprintf(fCode, "\\x%02x", (unsigned char)cString[x3]);
				}
				fprintf(fCode, "\" ; \n");
			} else if (ring_list_isint(pIns, x2)) {
				fprintf(fCode, "RING_VM_REGTYPE_INT ; \n");
				fprintf(fCode, "\tpVM->pByteCode[%d].aReg[%d].iNumber = %d ; \n", x - 1, nReg,
					ring_list_getint(pIns, x2));
			} else if (ring_list_isdouble(pIns, x2)) {
				fprintf(fCode, "RING_VM_REGTYPE_DOUBLE ; \n");
				fprintf(fCode, "\tpVM->pByteCode[%d].aReg[%d].dNumber = %f ; \n", x - 1, nReg,
					ring_list_getdouble(pIns, x2));
			} else if (ring_list_ispointer(pIns, x2)) {
				fprintf(fCode, "RING_VM_REGTYPE_POINTER ; \n");
				fprintf(fCode, "\tpVM->pByteCode[%d].aReg[%d].pPointer = NULL ; \n", x - 1, nReg);
			}
		}
	}
	fprintf(fCode, "\tpVM->pByteCode[%d].nOPCode = ICO_RETNULL ; \n", ring_list_getsize(pList));
}

RING_API void ring_objfile_updateclassespointers(RingState *pRingState) { ring_vm_updateclassespointers(pRingState); }

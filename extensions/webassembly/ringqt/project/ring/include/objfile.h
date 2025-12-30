/* Copyright (c) 2013-2026 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_objfile_h
#define ring_objfile_h
/*
**  Constants
**  Object File Source
*/
#define RING_OBJFILE_READFROMFILE 1
#define RING_OBJFILE_READFROMSTRING 2
/* Embedded Object */
#define RING_OBJFILE_ITEMSPERFUNCTION 100000
#define RING_OBJFILE_ITEMSPERFUNCTION2 100000
/* Version */
#define RING_OBJFILE_VERSION "# OBJECT 1.25"
#define RING_OBJFILE_VERSIONSTRINGSIZE 13
#define RING_OBJFILE_MINSIZE 60
/* Key */
#define RING_OBJFILE_KEYSIZE 10
#define RING_OBJFILE_KEYSTRSIZE 11
#define RING_OBJFILE_KEYSTRING "ringstring"
/* File Type */
#define RING_OBJFILE_FILETYPESTR "# Ring Object File"
#define RING_OBJFILE_FILETYPESTRCOUNT 18
/* Functions */

RING_API void ring_objfile_writefile(RingState *pRingState);

RING_API void ring_objfile_writecontent(RingState *pRingState, char *cFileName, List *pListFiles, List *pListFunctions,
					List *pListClasses, List *pListPackages, List *pListCode);

RING_API void ring_objfile_writelist(RingState *pRingState, FILE *fObj, List *pList);

RING_API int ring_objfile_readfile(RingState *pRingState, char *cFileName);

RING_API int ring_objfile_readstring(RingState *pRingState, char *cString, unsigned int nSize);

RING_API int ring_objfile_readfromsource(RingState *pRingState, char *cSource, unsigned int nSize, int nSourceType);

RING_API int ring_objfile_processfile(RingState *pRingState, char *cFileName, List *pListFiles, List *pListFunctions,
				      List *pListClasses, List *pListPackages, List *pListCode, List *pListStack);

RING_API int ring_objfile_processstring(RingState *pRingState, char *cContent, unsigned int nSize, List *pListFiles,
					List *pListFunctions, List *pListClasses, List *pListPackages, List *pListCode,
					List *pListStack);

RING_API void ring_objfile_xorstring(RingState *pRingState, char *cString, unsigned int nStringSize, char *cKey,
				     unsigned int nKeySize);

RING_API void ring_objfile_readc(RingState *pRingState, char **cSource, char *cDest, int nCount);

RING_API char ring_objfile_getc(RingState *pRingState, char **cSource);

RING_API void ring_objfile_writeCfile(RingState *pRingState);

RING_API int ring_objfile_writelistcode(RingState *pRingState, FILE *fCode, List *pList, int nList, int lSeparate,
					int nFunction, int nItemsPerFunction);

RING_API void ring_objfile_writebytecode(RingState *pRingState, FILE *fCode, List *pList);

RING_API void ring_objfile_updateclassespointers(RingState *pRingState);
#endif

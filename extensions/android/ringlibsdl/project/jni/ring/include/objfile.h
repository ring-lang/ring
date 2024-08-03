/* Copyright (c) 2013-2024 Mahmoud Fayed <msfclipper@yahoo.com> */

#ifndef ring_objfile_h
	#define ring_objfile_h
	/* Constants */
	/* Object File Source */
	#define RING_OBJFILE_READFROMFILE 1
	#define RING_OBJFILE_READFROMSTRING 2
	/* Embedded Object */
	#define RING_OBJFILE_ITEMSPERFUNCTION 100000
	#define RING_OBJFILE_ITEMSPERFUNCTION2 100000
	/* Version */
	#define RING_OBJFILE_VERSION "# OBJECT 1.21"
	#define RING_OBJFILE_VERSIONSTRINGSIZE 13
	/* Key */
	#define RING_OBJFILE_KEYSIZE 10
	#define RING_OBJFILE_KEYSTRSIZE 11
	#define RING_OBJFILE_KEYSTRING "ringstring"
	/* File Type */
	#define RING_OBJFILE_FILETYPESTR "# Ring Object File"
	#define RING_OBJFILE_FILETYPESTRCOUNT 18
	/* Functions */

	void ring_objfile_writefile ( RingState *pRingState ) ;

	void ring_objfile_writelist ( List *pList,FILE *fObj ) ;

	int ring_objfile_readfile ( RingState *pRingState,char *cFileName ) ;

	int ring_objfile_readstring ( RingState *pRingState,char *cString ) ;

	int ring_objfile_readfromsource ( RingState *pRingState,char *cSource,int nSourceType ) ;

	int ring_objfile_processfile ( RingState *pRingState,char *cFileName,List *pListFunctions,List  *pListClasses,List  *pListPackages,List  *pListCode,List *pListFiles,List  *pListStack ) ;

	int ring_objfile_processstring ( RingState *pRingState,char *cContent,List *pListFunctions,List  *pListClasses,List  *pListPackages,List  *pListCode,List *pListFiles,List  *pListStack ) ;

	RING_API void ring_objfile_updateclassespointers ( RingState *pRingState ) ;

	void ring_objfile_xorstring ( char *cString,int nStringSize,char *cKey,int nKeySize ) ;

	void ring_objfile_readc ( RingState *pRingState,char **cSource,char *cDest,int nCount ) ;

	char ring_objfile_getc ( RingState *pRingState,char **cSource ) ;

	void ring_objfile_writeCfile ( RingState *pRingState ) ;

	int ring_objfile_writelistcode ( List *pList,FILE *fCode,int nList,int lSeparate,int nFunction,int nItemsPerFunction ) ;

	void ring_objfile_writebytecode ( List *pList,FILE *fCode ) ;
#endif

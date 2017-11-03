/* Copyright (c) 2013-2017 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_objfile_h
#define ring_objfile_h
/*
**  Data 
**  Functions 
*/

void ring_objfile_writefile ( RingState *pRingState ) ;

void ring_objfile_writelist ( List *pList,FILE *fObj ) ;

int ring_objfile_readfile ( RingState *pRingState,const char *cFileName ) ;

int ring_objfile_readfilefromsource ( RingState *pRingState,const char *cSource,int nSourceType ) ;

int ring_objfile_processfile ( RingState *pRingState,const char *cFileName,List *pListFunctions,List  *pListClasses,List  *pListPackages,List  *pListCode,List  *pListStack ) ;

void ring_objfile_updateclassespointers ( RingState *pRingState ) ;

void ring_objfile_xorstring ( char *cString,int nStringSize,char *cKey,int nKeySize ) ;
/* MACRO */
/* Object File Source */
#define RING_OBJFILE_READFROMFILE 1
#define RING_OBJFILE_READFROMSTRING 2
#endif

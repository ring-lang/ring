/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmgcdata
#define ring_vmgcdata
typedef struct GCData {
	int nReferenceCount  ;
	void (*pFreeFunc)(void *,void *) ;
} GCData ;
#endif

/* Copyright (c) 2016 Majdi Sobain <MajdiSobain@Gmail.com> */

#ifndef ring_vmrcreg_h
#define ring_vmrcreg_h

#ifdef __cplusplus
extern "C" {
#endif

	/* Functions */
	
RING_API void ringlib_init ( RingState *pRingState ) ;

void ring_vm_creg_cregopenkey ( void *pPointer ) ;

void ring_vm_creg_cregclosekey ( void *pPointer ) ;

void ring_vm_creg_cregdeletekey(void *pPointer) ;

void ring_vm_creg_cregkeyexists( void *pPointer) ;

void ring_vm_creg_cregsubkeyexists( void *pPointer) ;

void ring_vm_creg_cregsetflags( void *pPointer) ;

void ring_vm_creg_cregentriescount( void *pPointer) ;

void ring_vm_creg_creggetflags( void *pPointer) ;

void ring_vm_creg_cregaccess64tree( void *pPointer ) ;

void ring_vm_creg_cregisvirtualized( void *pPointer ) ;

void ring_vm_creg_cregsubkeyscount( void *pPointer ) ;

void ring_vm_creg_creggetsubkeyat( void *pPointer ) ;

void ring_vm_creg_cregrefresh( void *pPointer ) ;

void ring_vm_creg_creggetat( void *pPointer ) ;

void ring_vm_creg_creggetname( void *pPointer ) ;

void ring_vm_creg_cregcopy( void *pPointer ) ;

void ring_vm_creg_cregrename( void *pPointer ) ;

void ring_vm_creg_cregsetvalue( void *pPointer ) ;

void ring_vm_creg_creggetvalue( void *pPointer ) ;

void ring_vm_creg_cregdelete( void *pPointer ) ;

void ring_vm_creg_cregsetmulti( void *pPointer ) ;

void ring_vm_creg_cregmultiremoveat( void *pPointer ) ;

void ring_vm_creg_cregmultisetat( void *pPointer ) ;

void ring_vm_creg_cregmultiadd( void *pPointer ) ;

void ring_vm_creg_cregmultigetat( void *pPointer ) ;

void ring_vm_creg_cregmulticount( void *pPointer ) ;

void ring_vm_creg_cregmulticlear( void *pPointer ) ;

void ring_vm_creg_creggetexpandsz( void *pPointer ) ;

void ring_vm_creg_cregsetexpandsz( void *pPointer ) ;

void ring_vm_creg_creggetexpandedsz( void *pPointer ) ;

void ring_vm_creg_cregsetqword( void *pPointer ) ;

void ring_vm_creg_creggetqword( void *pPointer ) ;

void ring_vm_creg_creggetbinary( void *pPointer ) ;

void ring_vm_creg_cregsetbinary( void *pPointer ) ;

void ring_vm_creg_cregbinarylength( void *pPointer ) ;

void ring_vm_creg_cregisstring( void *pPointer ) ;

void ring_vm_creg_cregisdword( void *pPointer ) ;

void ring_vm_creg_cregismultistring( void *pPointer ) ;

void ring_vm_creg_cregisbinary( void *pPointer ) ;

void ring_vm_creg_cregisexpandsz( void *pPointer ) ;

void ring_vm_creg_cregisqword( void *pPointer ) ;

void ring_vm_creg_cregexists( void *pPointer ) ;

void ring_vm_creg_cregtype( void *pPointer ) ;

BOOL EntryExists(void *pPointer, CRegistry* key, LPTSTR entry) ;
unsigned char isnum(LPCSTR str) ;
LPTSTR GetFormattedMessage(LONG ErrId) ;
LPTSTR GetErrorMsg(LONG ErrorId , LPTSTR pMsg, size_t pMsgsize) ;

#ifdef __cplusplus
}
#endif

#endif
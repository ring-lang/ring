/* Copyright (c) 2013-2016 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_gc_h
#define ring_gc_h
/* Functions */

void ring_vm_gc_checkreferences ( VM *pVM ) ;

void ring_vm_gc_checknewreference ( void *pPointer,int nType ) ;

void ring_vm_gc_checkupdatereference ( List *pList ) ;

void ring_vm_gc_deleteitem ( Item *pItem ) ;

void ring_vm_gc_killreference ( VM *pVM ) ;

void ring_vm_gc_deletetemplists ( VM *pVM ) ;
/* Macro */
#define ring_vm_gc_cleardata(pItem) (pItem->gc.nReferenceCount = 0)
#define GCLog 0
#endif

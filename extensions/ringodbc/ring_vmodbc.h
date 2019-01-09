/* Copyright (c) 2013-2019 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmodbc_h
#define ring_vmodbc_h
/* Functions */

RING_API void ringlib_init ( RingState *pRingState ) ;

void ring_vm_odbc_init ( void *pPointer ) ;

void ring_vm_odbc_drivers ( void *pPointer ) ;

void ring_vm_odbc_datasources ( void *pPointer ) ;

void ring_vm_odbc_close ( void *pPointer ) ;

void ring_vm_odbc_connect ( void *pPointer ) ;

void ring_vm_odbc_disconnect ( void *pPointer ) ;

void ring_vm_odbc_execute ( void *pPointer ) ;

void ring_vm_odbc_colcount ( void *pPointer ) ;

void ring_vm_odbc_fetch ( void *pPointer ) ;

void ring_vm_odbc_getdata ( void *pPointer ) ;

void ring_vm_odbc_tables ( void *pPointer ) ;

void ring_vm_odbc_columns ( void *pPointer ) ;

void ring_vm_odbc_autocommit ( void *pPointer ) ;

void ring_vm_odbc_commit ( void *pPointer ) ;

void ring_vm_odbc_rollback ( void *pPointer ) ;

void ring_vm_odbc_freefunc ( void *pState,void *pPointer ) ;
/* Constants */
#define RING_ODBC_FLAG_ENV 0x01
#define RING_ODBC_FLAG_DBC 0x02
#define RING_ODBC_FLAG_STMT 0x04
#define RING_VM_POINTER_ODBC "odbc"
#endif

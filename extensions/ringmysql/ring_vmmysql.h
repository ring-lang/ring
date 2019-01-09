/* Copyright (c) 2013-2019 Mahmoud Fayed <msfclipper@yahoo.com> */
#ifndef ring_vmmysql_h
#define ring_vmmysql_h
/* Functions */

RING_API void ringlib_init ( RingState *pRingState ) ;

void ring_vm_mysql_get_client_info ( void *pPointer ) ;

void ring_vm_mysql_init ( void *pPointer ) ;

void ring_vm_mysql_error ( void *pPointer ) ;

void ring_vm_mysql_real_connect ( void *pPointer ) ;

void ring_vm_mysql_close ( void *pPointer ) ;

void ring_vm_mysql_query ( void *pPointer ) ;

void ring_vm_mysql_result ( void *pPointer ) ;

void ring_vm_mysql_insert_id ( void *pPointer ) ;

void ring_vm_mysql_columns ( void *pPointer ) ;

void ring_vm_mysql_result2 ( void *pPointer ) ;

void ring_vm_mysql_next_result ( void *pPointer ) ;

void ring_vm_mysql_real_escape_string ( void *pPointer ) ;

void ring_vm_mysql_autocommit ( void *pPointer ) ;

void ring_vm_mysql_commit ( void *pPointer ) ;

void ring_vm_mysql_rollback ( void *pPointer ) ;

void ring_vm_mysql_freefunc ( void *pState,void *pPointer ) ;
/* MACRO */
#define RING_VM_POINTER_MYSQL "mysql"
#endif

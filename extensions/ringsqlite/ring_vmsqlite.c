/*
**  Copyright (c) 2013-2019 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#include "ring.h"
#include "sqlite3.h"
#include "ring_vmsqlite.h"
/* Data */
typedef struct ring_sqlite {
	sqlite3 *db  ;
} ring_sqlite ;
/* Functions */

RING_LIBINIT
{
	RING_API_REGISTER("sqlite_init",ring_vm_sqlite_init);
	RING_API_REGISTER("sqlite_close",ring_vm_sqlite_close);
	RING_API_REGISTER("sqlite_open",ring_vm_sqlite_open);
	RING_API_REGISTER("sqlite_errmsg",ring_vm_sqlite_errmsg);
	RING_API_REGISTER("sqlite_execute",ring_vm_sqlite_execute);
}

void ring_vm_sqlite_init ( void *pPointer )
{
	ring_sqlite *psqlite  ;
	psqlite = (ring_sqlite *) malloc(sizeof(ring_sqlite)) ;
	if ( psqlite == NULL ) {
		RING_API_ERROR(RING_OOM);
		return ;
	}
	psqlite->db = NULL ;
	RING_API_RETMANAGEDCPOINTER(psqlite,RING_VM_POINTER_SQLITE,ring_vm_sqlite_freefunc);
}

void ring_vm_sqlite_close ( void *pPointer )
{
	ring_sqlite *psqlite  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		psqlite = (ring_sqlite *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SQLITE) ;
		if ( psqlite == NULL ) {
			return ;
		}
		if ( psqlite->db ) {
			sqlite3_close(psqlite->db);
		}
		free( psqlite ) ;
		RING_API_SETNULLPOINTER(1);
		RING_API_RETNUMBER(1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_sqlite_open ( void *pPointer )
{
	ring_sqlite *psqlite  ;
	int rc  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		psqlite = (ring_sqlite *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SQLITE) ;
		if ( psqlite == NULL ) {
			return ;
		}
		rc = sqlite3_open(RING_API_GETSTRING(2),&psqlite->db);
		RING_API_RETNUMBER((double) rc);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_sqlite_errmsg ( void *pPointer )
{
	ring_sqlite *psqlite  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		psqlite = (ring_sqlite *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SQLITE) ;
		if ( psqlite == NULL ) {
			return ;
		}
		if ( psqlite->db ) {
			RING_API_RETSTRING(sqlite3_errmsg(psqlite->db));
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

int ring_vm_sqlite_callback ( void *data, int argc, char **argv, char **ColName )
{
	List *pList, *pList2  ;
	int x  ;
	pList = (List *) data ;
	pList = ring_list_newlist(pList);
	for ( x = 0 ; x < argc ; x++ ) {
		pList2 = ring_list_newlist(pList);
		ring_list_addstring(pList2,ColName[x]);
		ring_list_addstring(pList2,argv[x] ? argv[x] : "NULL");
	}
	return 0 ;
}

void ring_vm_sqlite_execute ( void *pPointer )
{
	ring_sqlite *psqlite  ;
	int rc  ;
	List *pList  ;
	char *ErrMsg  ;
	ErrMsg = NULL ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		psqlite = (ring_sqlite *) RING_API_GETCPOINTER(1,RING_VM_POINTER_SQLITE) ;
		if ( psqlite == NULL ) {
			return ;
		}
		if ( psqlite->db ) {
			pList = RING_API_NEWLIST ;
			rc = sqlite3_exec(psqlite->db,RING_API_GETSTRING(2),ring_vm_sqlite_callback,(void *) pList,&ErrMsg);
			RING_API_RETLIST(pList);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_sqlite_freefunc ( void *pState,void *pPointer )
{
	ring_sqlite *psqlite  ;
	psqlite = (ring_sqlite *) pPointer ;
	if ( psqlite->db ) {
		sqlite3_close(psqlite->db);
	}
	free( psqlite ) ;
}

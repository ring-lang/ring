/* Copyright (c) 2013-2020 Mahmoud Fayed <msfclipper@yahoo.com> */
#include <mysql.h>
#include "ring.h"
#include "ring_vmmysql.h"
/* Functions */

RING_LIBINIT
{
	RING_API_REGISTER("mysql_info",ring_vm_mysql_get_client_info);
	RING_API_REGISTER("mysql_init",ring_vm_mysql_init);
	RING_API_REGISTER("mysql_error",ring_vm_mysql_error);
	RING_API_REGISTER("mysql_connect",ring_vm_mysql_real_connect);
	RING_API_REGISTER("mysql_close",ring_vm_mysql_close);
	RING_API_REGISTER("mysql_query",ring_vm_mysql_query);
	RING_API_REGISTER("mysql_result",ring_vm_mysql_result);
	RING_API_REGISTER("mysql_insert_id",ring_vm_mysql_insert_id);
	RING_API_REGISTER("mysql_columns",ring_vm_mysql_columns);
	RING_API_REGISTER("mysql_result2",ring_vm_mysql_result2);
	RING_API_REGISTER("mysql_next_result",ring_vm_mysql_next_result);
	RING_API_REGISTER("mysql_escape_string",ring_vm_mysql_real_escape_string);
	RING_API_REGISTER("mysql_autocommit",ring_vm_mysql_autocommit);
	RING_API_REGISTER("mysql_commit",ring_vm_mysql_commit);
	RING_API_REGISTER("mysql_rollback",ring_vm_mysql_rollback);
}

void ring_vm_mysql_get_client_info ( void *pPointer )
{
	RING_API_RETSTRING(mysql_get_client_info());
}

void ring_vm_mysql_init ( void *pPointer )
{
	MYSQL *con  ;
	con = mysql_init(NULL) ;
	if ( con != NULL ) {
		RING_API_RETMANAGEDCPOINTER(con,RING_VM_POINTER_MYSQL,ring_vm_mysql_freefunc);
	} else {
		RING_API_RETNUMBER(0);
	}
}

void ring_vm_mysql_error ( void *pPointer )
{
	MYSQL *con  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		RING_API_RETSTRING(mysql_error(con));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_real_connect ( void *pPointer )
{
	MYSQL *con  ;
	if ( RING_API_PARACOUNT < 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) && RING_API_ISSTRING(3) && RING_API_ISSTRING(4) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		if ( RING_API_PARACOUNT == 4 ) {
			con = mysql_real_connect(con,RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4), NULL, 0, NULL, CLIENT_MULTI_STATEMENTS);
		}
		else if ( RING_API_PARACOUNT == 5 ) {
			if ( RING_API_ISSTRING(5) ) {
				con = mysql_real_connect(con,RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4), RING_API_GETSTRING(5), 0, NULL, CLIENT_MULTI_STATEMENTS);
			} else {
				RING_API_ERROR(RING_API_BADPARATYPE);
			}
		} else {
			RING_API_ERROR(RING_API_BADPARACOUNT);
			return ;
		}
		if ( con == NULL ) {
			RING_API_RETNUMBER(0);
		} else {
			RING_API_RETNUMBER(1);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_close ( void *pPointer )
{
	MYSQL *con  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		mysql_close(con);
		RING_API_SETNULLPOINTER(1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_query ( void *pPointer )
{
	int nResult  ;
	MYSQL *con  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		nResult = mysql_real_query(con,RING_API_GETSTRING(2),RING_API_GETSTRINGSIZE(2));
		RING_API_RETNUMBER(nResult);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_result ( void *pPointer )
{
	MYSQL *con  ;
	MYSQL_RES *result  ;
	int nColumns,x  ;
	MYSQL_ROW row  ;
	List *pList, *pList2  ;
	unsigned long *lengths  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		result = mysql_store_result(con);
		if ( result == NULL ) {
			RING_API_RETNUMBER(0);
			return ;
		}
		pList = RING_API_NEWLIST ;
		nColumns = mysql_num_fields(result);
		while ( ( row = mysql_fetch_row(result) ) ) {
			lengths = mysql_fetch_lengths(result);
			pList2 = ring_list_newlist_gc(((VM *)pPointer)->pRingState,pList);
			for ( x = 0 ; x < nColumns ; x++ ) {
				ring_list_addstring2(pList2,row[x] ? row[x] : "NULL",lengths[x]);
			}
		}
		mysql_free_result(result);
		RING_API_RETLIST(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_insert_id ( void *pPointer )
{
	MYSQL *con  ;
	int id  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		id = mysql_insert_id(con);
		RING_API_RETNUMBER(id);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_columns ( void *pPointer )
{
	MYSQL *con  ;
	MYSQL_RES *result  ;
	int nColumns,x  ;
	MYSQL_ROW row  ;
	MYSQL_FIELD *field  ;
	List *pList, *pList2  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		result = mysql_store_result(con);
		if ( result == NULL ) {
			RING_API_RETNUMBER(0);
			return ;
		}
		pList = RING_API_NEWLIST ;
		nColumns = mysql_num_fields(result);
		if ( ( row = mysql_fetch_row(result) ) ) {
			while ( ( field = mysql_fetch_field(result) ) ) {
				pList2 = ring_list_newlist_gc(((VM *)pPointer)->pRingState,pList);
				ring_list_addstring(pList2,field->name);
				ring_list_adddouble(pList2,field->length);
				ring_list_adddouble(pList2,field->type);
				ring_list_adddouble(pList2,field->flags);
			}
		}
		mysql_free_result(result);
		RING_API_RETLIST(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_result2 ( void *pPointer )
{
	MYSQL *con  ;
	MYSQL_RES *result  ;
	int nColumns,x  ;
	MYSQL_ROW row  ;
	MYSQL_FIELD *field  ;
	List *pList, *pList2, *pList3  ;
	unsigned long *lengths  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		result = mysql_store_result(con);
		if ( result == NULL ) {
			RING_API_RETNUMBER(0);
			return ;
		}
		pList = RING_API_NEWLIST ;
		pList3 = ring_list_newlist_gc(((VM *)pPointer)->pRingState,pList);
		nColumns = mysql_num_fields(result);
		while ( ( row = mysql_fetch_row(result) ) ) {
			lengths = mysql_fetch_lengths(result);
			pList2 = ring_list_newlist_gc(((VM *)pPointer)->pRingState,pList);
			for ( x = 0 ; x < nColumns ; x++ ) {
				if ( x == 0 ) {
					while ( ( field = mysql_fetch_field(result) ) ) {
						ring_list_addstring(pList3,field->name);
					}
				}
				ring_list_addstring2(pList2,row[x] ? row[x] : "NULL",lengths[x]);
			}
		}
		mysql_free_result(result);
		RING_API_RETLIST(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_next_result ( void *pPointer )
{
	MYSQL *con  ;
	int nResult  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		nResult = mysql_next_result(con);
		RING_API_RETNUMBER(nResult);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_real_escape_string ( void *pPointer )
{
	char *cStr  ;
	int nSize,nSize2,nSize3  ;
	MYSQL *con  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		nSize = RING_API_GETSTRINGSIZE(2) ;
		nSize2 = 2*nSize+1 ;
		cStr = (char *) malloc(nSize2) ;
		if ( cStr == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		nSize3 = mysql_real_escape_string(con,cStr,RING_API_GETSTRING(2),nSize);
		RING_API_RETSTRING2(cStr,nSize3);
		free( cStr ) ;
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_autocommit ( void *pPointer )
{
	MYSQL *con  ;
	int nResult  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		nResult = mysql_autocommit(con,RING_API_GETNUMBER(2));
		RING_API_RETNUMBER(nResult);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_commit ( void *pPointer )
{
	MYSQL *con  ;
	int nResult  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		nResult = mysql_commit(con);
		RING_API_RETNUMBER(nResult);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_rollback ( void *pPointer )
{
	MYSQL *con  ;
	int nResult  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		con = (MYSQL *) RING_API_GETCPOINTER(1,RING_VM_POINTER_MYSQL) ;
		if ( con == NULL ) {
			return ;
		}
		nResult = mysql_rollback(con);
		RING_API_RETNUMBER(nResult);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_mysql_freefunc ( void *pState,void *pPointer )
{
	MYSQL *con  ;
	con = (MYSQL *) pPointer ;
	mysql_close(con);
}

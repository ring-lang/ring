/*
**  Copyright (c) 2013-2019 Mahmoud Fayed <msfclipper@yahoo.com> 
**  Include Files 
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <sql.h>
#include <sqlext.h>
#include "ring.h"
#include "ring_vmodbc.h"
/* Data */
typedef struct ring_odbc {
	SQLHENV env  ;
	SQLHDBC dbc  ;
	SQLHSTMT stmt  ;
	char nFlag  ;
} ring_odbc ;
/* Functions */

RING_API void ringlib_init ( RingState *pRingState )
{
	RING_API_REGISTER("odbc_init",ring_vm_odbc_init);
	RING_API_REGISTER("odbc_drivers",ring_vm_odbc_drivers);
	RING_API_REGISTER("odbc_datasources",ring_vm_odbc_datasources);
	RING_API_REGISTER("odbc_close",ring_vm_odbc_close);
	RING_API_REGISTER("odbc_connect",ring_vm_odbc_connect);
	RING_API_REGISTER("odbc_disconnect",ring_vm_odbc_disconnect);
	RING_API_REGISTER("odbc_execute",ring_vm_odbc_execute);
	RING_API_REGISTER("odbc_colcount",ring_vm_odbc_colcount);
	RING_API_REGISTER("odbc_fetch",ring_vm_odbc_fetch);
	RING_API_REGISTER("odbc_getdata",ring_vm_odbc_getdata);
	RING_API_REGISTER("odbc_tables",ring_vm_odbc_tables);
	RING_API_REGISTER("odbc_columns",ring_vm_odbc_columns);
	RING_API_REGISTER("odbc_autocommit",ring_vm_odbc_autocommit);
	RING_API_REGISTER("odbc_commit",ring_vm_odbc_commit);
	RING_API_REGISTER("odbc_rollback",ring_vm_odbc_rollback);
}

void ring_vm_odbc_init ( void *pPointer )
{
	SQLRETURN ret  ;
	ring_odbc *pODBC  ;
	pODBC = (ring_odbc *) malloc(sizeof(ring_odbc)) ;
	if ( pODBC == NULL ) {
		RING_API_ERROR(RING_OOM);
		return ;
	}
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &pODBC->env);
	pODBC->nFlag = RING_ODBC_FLAG_ENV ;
	ret = SQLSetEnvAttr(pODBC->env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);
	if ( SQL_SUCCEEDED(ret) ) {
		RING_API_RETMANAGEDCPOINTER(pODBC,RING_VM_POINTER_ODBC,ring_vm_odbc_freefunc);
	} else {
		free( pODBC ) ;
		RING_API_RETNUMBER(0);
	}
}

void ring_vm_odbc_drivers ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLCHAR driver[256]  ;
	SQLCHAR attr[256]  ;
	SQLSMALLINT driver_ret  ;
	SQLSMALLINT attr_ret  ;
	SQLUSMALLINT direction  ;
	List *pList  ;
	String *pString  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		pList = RING_API_NEWLIST ;
		direction = SQL_FETCH_FIRST ;
		while ( SQL_SUCCEEDED(SQLDrivers(pODBC->env, direction, driver, sizeof(driver), &driver_ret,attr, sizeof(attr), &attr_ret)) ) {
			direction = SQL_FETCH_NEXT ;
			pString = ring_string_new_gc(((VM *)pPointer)->pRingState,(char *) driver);
			ring_string_add_gc(((VM *)pPointer)->pRingState,pString," - ");
			ring_string_add_gc(((VM *)pPointer)->pRingState,pString, (char *) attr);
			ring_list_addstring_gc(((VM *)pPointer)->pRingState,pList,ring_string_get(pString));
			ring_string_delete_gc(((VM *)pPointer)->pRingState,pString);
		}
		RING_API_RETLIST(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_datasources ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLCHAR dsn[256]  ;
	SQLCHAR desc[256]  ;
	SQLSMALLINT dsn_ret  ;
	SQLSMALLINT desc_ret  ;
	SQLUSMALLINT direction  ;
	List *pList  ;
	String *pString  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		pList = RING_API_NEWLIST ;
		direction = SQL_FETCH_FIRST ;
		while ( SQL_SUCCEEDED(SQLDataSources(pODBC->env, direction, dsn, sizeof(dsn), &dsn_ret,desc, sizeof(desc), &desc_ret)) ) {
			direction = SQL_FETCH_NEXT ;
			pString = ring_string_new_gc(((VM *)pPointer)->pRingState,(char *) dsn);
			ring_string_add_gc(((VM *)pPointer)->pRingState,pString," - ");
			ring_string_add_gc(((VM *)pPointer)->pRingState,pString, (char *) desc);
			ring_list_addstring_gc(((VM *)pPointer)->pRingState,pList,ring_string_get(pString));
			ring_string_delete_gc(((VM *)pPointer)->pRingState,pString);
		}
		RING_API_RETLIST(pList);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_close ( void *pPointer )
{
	ring_odbc *pODBC  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		ring_vm_odbc_freefunc(((VM *) pPointer)->pRingState,pODBC);
		RING_API_SETNULLPOINTER(1);
		RING_API_RETNUMBER(1);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_connect ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLCHAR outstr[1024]  ;
	SQLSMALLINT outstrlen  ;
	SQLRETURN ret  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		if ( pODBC->nFlag & RING_ODBC_FLAG_DBC ) {
			SQLFreeHandle(SQL_HANDLE_DBC,pODBC->dbc);
		}
		SQLAllocHandle(SQL_HANDLE_DBC, pODBC->env , &pODBC->dbc);
		pODBC->nFlag = pODBC->nFlag | RING_ODBC_FLAG_DBC ;
		ret = SQLDriverConnect(pODBC->dbc,NULL,(SQLCHAR *) RING_API_GETSTRING(2),SQL_NTS,outstr, sizeof(outstr),  &outstrlen,SQL_DRIVER_COMPLETE);
		if ( SQL_SUCCEEDED(ret) ) {
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_disconnect ( void *pPointer )
{
	ring_odbc *pODBC  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		if ( pODBC->nFlag & RING_ODBC_FLAG_STMT ) {
			SQLFreeHandle(SQL_HANDLE_STMT,pODBC->stmt);
			pODBC->nFlag = pODBC->nFlag & ( ~ RING_ODBC_FLAG_STMT ) ;
		}
		if ( pODBC->nFlag & RING_ODBC_FLAG_DBC ) {
			pODBC->nFlag = pODBC->nFlag & ( ~ RING_ODBC_FLAG_DBC ) ;
			SQLDisconnect(pODBC->dbc);
			SQLFreeHandle(SQL_HANDLE_DBC,pODBC->dbc);
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_execute ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLRETURN ret  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		if ( pODBC->nFlag & RING_ODBC_FLAG_STMT ) {
			SQLFreeHandle(SQL_HANDLE_STMT,pODBC->stmt);
		}
		SQLAllocHandle(SQL_HANDLE_STMT, pODBC->dbc , &pODBC->stmt);
		ret = SQLExecDirect(pODBC->stmt, (SQLCHAR *) RING_API_GETSTRING(2) , (SQLINTEGER) RING_API_GETSTRINGSIZE(2));
		pODBC->nFlag = pODBC->nFlag | RING_ODBC_FLAG_STMT ;
		if ( SQL_SUCCEEDED(ret) ) {
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_colcount ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLSMALLINT columns  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		SQLNumResultCols(pODBC->stmt, &columns);
		RING_API_RETNUMBER(columns);
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_fetch ( void *pPointer )
{
	ring_odbc *pODBC  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		RING_API_RETNUMBER(SQL_SUCCEEDED(SQLFetch(pODBC->stmt)));
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_getdata ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLLEN indicator  ;
	SQLUSMALLINT i  ;
	SQLRETURN ret  ;
	char *buf, *buf2  ;
	int nSize  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		i = (SQLUSMALLINT) RING_API_GETNUMBER(2) ;
		nSize = 512 ;
		buf = (char *) malloc(nSize) ;
		if ( buf == NULL ) {
			RING_API_ERROR(RING_OOM);
			return ;
		}
		ret = SQLGetData(pODBC->stmt, i, SQL_C_CHAR,buf, nSize, &indicator);
		if ( SQL_SUCCEEDED(ret) ) {
			if ( indicator == SQL_NULL_DATA ) {
				strcpy(buf,"NULL");
				nSize = 4 ;
			} else if ( (ret == SQL_SUCCESS_WITH_INFO) && (indicator > 512) ) {
				nSize = 512+indicator ;
				buf2 = (char *) realloc(buf , nSize);
				if ( buf2 == NULL ) {
					RING_API_ERROR(RING_OOM);
					return ;
				}
				buf = buf2 ;
				SQLGetData(pODBC->stmt, i, SQL_C_CHAR,buf+511, indicator+1, &indicator);
				nSize = 511+indicator ;
			} else {
				nSize = indicator ;
			}
			RING_API_RETSTRING2(buf,nSize);
		} else {
			RING_API_RETNUMBER(0);
		}
		free( buf ) ;
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_tables ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLRETURN ret  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		if ( ! (pODBC->nFlag & RING_ODBC_FLAG_STMT) ) {
			SQLAllocHandle(SQL_HANDLE_STMT, pODBC->dbc , &pODBC->stmt);
			pODBC->nFlag = pODBC->nFlag | RING_ODBC_FLAG_STMT ;
		}
		ret = SQLTables(pODBC->stmt, NULL, 0, NULL, 0, NULL, 0, (SQLCHAR *) "TABLE", SQL_NTS);
		if ( SQL_SUCCEEDED(ret) ) {
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_columns ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLRETURN ret  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISSTRING(2) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		if ( ! (pODBC->nFlag & RING_ODBC_FLAG_STMT) ) {
			SQLAllocHandle(SQL_HANDLE_STMT, pODBC->dbc , &pODBC->stmt);
			pODBC->nFlag = pODBC->nFlag | RING_ODBC_FLAG_STMT ;
		}
		ret = SQLColumns(pODBC->stmt, NULL, 0, NULL, 0, (SQLCHAR *) RING_API_GETSTRING(2), SQL_NTS, NULL, 0);
		if ( SQL_SUCCEEDED(ret) ) {
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_autocommit ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLRETURN ret  ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) && RING_API_ISNUMBER(2) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		if ( RING_API_GETNUMBER(2) == 1 ) {
			ret = SQLSetConnectAttr(pODBC->dbc,SQL_ATTR_AUTOCOMMIT, ( SQLPOINTER ) SQL_AUTOCOMMIT_ON,0);
		} else {
			ret = SQLSetConnectAttr(pODBC->dbc,SQL_ATTR_AUTOCOMMIT, ( SQLPOINTER ) SQL_AUTOCOMMIT_OFF,0);
		}
		if ( SQL_SUCCEEDED(ret) ) {
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_commit ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLRETURN ret  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		ret = SQLEndTran(SQL_HANDLE_DBC,pODBC->dbc,SQL_COMMIT);
		if ( SQL_SUCCEEDED(ret) ) {
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_rollback ( void *pPointer )
{
	ring_odbc *pODBC  ;
	SQLRETURN ret  ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( RING_API_ISPOINTER(1) ) {
		pODBC = (ring_odbc *) RING_API_GETCPOINTER(1,RING_VM_POINTER_ODBC) ;
		if ( pODBC == NULL ) {
			return ;
		}
		ret = SQLEndTran(SQL_HANDLE_DBC,pODBC->dbc,SQL_ROLLBACK);
		if ( SQL_SUCCEEDED(ret) ) {
			RING_API_RETNUMBER(1);
		} else {
			RING_API_RETNUMBER(0);
		}
	} else {
		RING_API_ERROR(RING_API_BADPARATYPE);
	}
}

void ring_vm_odbc_freefunc ( void *pState,void *pPointer )
{
	ring_odbc *pODBC  ;
	pODBC = (ring_odbc *) pPointer ;
	if ( pODBC->nFlag & RING_ODBC_FLAG_STMT ) {
		SQLFreeHandle(SQL_HANDLE_STMT,pODBC->stmt);
	}
	if ( pODBC->nFlag & RING_ODBC_FLAG_DBC ) {
		SQLFreeHandle(SQL_HANDLE_DBC,pODBC->dbc);
	}
	SQLFreeHandle(SQL_HANDLE_ENV,pODBC->env);
	free( pODBC ) ;
}

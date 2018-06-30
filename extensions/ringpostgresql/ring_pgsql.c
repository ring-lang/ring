#include "ring.h"

/* Copyright (c) 2018 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "libpq-fe.h"

RING_FUNC(ring_get_connection_started)
{
	RING_API_RETNUMBER(CONNECTION_STARTED);
}

RING_FUNC(ring_get_connection_made)
{
	RING_API_RETNUMBER(CONNECTION_MADE);
}

RING_FUNC(ring_get_connection_awaiting_response)
{
	RING_API_RETNUMBER(CONNECTION_AWAITING_RESPONSE);
}

RING_FUNC(ring_get_connection_auth_ok)
{
	RING_API_RETNUMBER(CONNECTION_AUTH_OK);
}

RING_FUNC(ring_get_connection_ssl_startup)
{
	RING_API_RETNUMBER(CONNECTION_SSL_STARTUP);
}

RING_FUNC(ring_get_connection_setenv)
{
	RING_API_RETNUMBER(CONNECTION_SETENV);
}

RING_FUNC(ring_get_connection_check_writable)
{
	RING_API_RETNUMBER(CONNECTION_CHECK_WRITABLE);
}

RING_FUNC(ring_get_connection_consume)
{
	RING_API_RETNUMBER(CONNECTION_CONSUME);
}

RING_FUNC(ring_get_pqping_ok)
{
	RING_API_RETNUMBER(PQPING_OK);
}

RING_FUNC(ring_get_pqping_reject)
{
	RING_API_RETNUMBER(PQPING_REJECT);
}

RING_FUNC(ring_get_pqping_no_response)
{
	RING_API_RETNUMBER(PQPING_NO_RESPONSE);
}

RING_FUNC(ring_get_pqping_no_attempt)
{
	RING_API_RETNUMBER(PQPING_NO_ATTEMPT);
}

RING_FUNC(ring_get_pgres_empty_query)
{
	RING_API_RETNUMBER(PGRES_EMPTY_QUERY);
}

RING_FUNC(ring_get_pgres_command_ok)
{
	RING_API_RETNUMBER(PGRES_COMMAND_OK);
}

RING_FUNC(ring_get_pgres_tuples_ok)
{
	RING_API_RETNUMBER(PGRES_TUPLES_OK);
}

RING_FUNC(ring_get_pgres_copy_out)
{
	RING_API_RETNUMBER(PGRES_COPY_OUT);
}

RING_FUNC(ring_get_pgres_copy_in)
{
	RING_API_RETNUMBER(PGRES_COPY_IN);
}

RING_FUNC(ring_get_pgres_bad_response)
{
	RING_API_RETNUMBER(PGRES_BAD_RESPONSE);
}

RING_FUNC(ring_get_pgres_nonfatal_error)
{
	RING_API_RETNUMBER(PGRES_NONFATAL_ERROR);
}

RING_FUNC(ring_get_pgres_fatal_error)
{
	RING_API_RETNUMBER(PGRES_FATAL_ERROR);
}

RING_FUNC(ring_get_pgres_copy_both)
{
	RING_API_RETNUMBER(PGRES_COPY_BOTH);
}

RING_FUNC(ring_get_pgres_single_tuple)
{
	RING_API_RETNUMBER(PGRES_SINGLE_TUPLE);
}

RING_FUNC(ring_new_pqconninfooption)
{
	PQconninfoOption *pMyPointer ;
	pMyPointer = (PQconninfoOption *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(PQconninfoOption)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"PQconninfoOption");
}

RING_FUNC(ring_destroy_pqconninfooption)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_pqconninfooption_keyword)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	RING_API_RETCPOINTER(pMyPointer->keyword,"char");
}

RING_FUNC(ring_set_pqconninfooption_keyword)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->keyword = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqconninfooption_envvar)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	RING_API_RETCPOINTER(pMyPointer->envvar,"char");
}

RING_FUNC(ring_set_pqconninfooption_envvar)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->envvar = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqconninfooption_compiled)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	RING_API_RETCPOINTER(pMyPointer->compiled,"char");
}

RING_FUNC(ring_set_pqconninfooption_compiled)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->compiled = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqconninfooption_val)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	RING_API_RETCPOINTER(pMyPointer->val,"char");
}

RING_FUNC(ring_set_pqconninfooption_val)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->val = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqconninfooption_label)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	RING_API_RETCPOINTER(pMyPointer->label,"char");
}

RING_FUNC(ring_set_pqconninfooption_label)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->label = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqconninfooption_dispchar)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	RING_API_RETCPOINTER(pMyPointer->dispchar,"char");
}

RING_FUNC(ring_set_pqconninfooption_dispchar)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->dispchar = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqconninfooption_dispsize)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	RING_API_RETNUMBER(pMyPointer->dispsize);
}

RING_FUNC(ring_set_pqconninfooption_dispsize)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->dispsize = RING_API_GETNUMBER(2);
}


RING_FUNC(ring_PQconnectdbParams)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQconnectdbParams((char **) RING_API_GETCPOINTER2POINTER(1,"char"),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (int ) RING_API_GETNUMBER(3)),"PGconn");
}


RING_FUNC(ring_PQconnectdb)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQconnectdb(RING_API_GETSTRING(1)),"PGconn");
}


RING_FUNC(ring_PQsetdbLogin)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQsetdbLogin(RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5),RING_API_GETSTRING(6),RING_API_GETSTRING(7)),"PGconn");
}


RING_FUNC(ring_PQsetdb)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQsetdb(RING_API_GETSTRING(1),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4),RING_API_GETSTRING(5)),"PGconn");
}


RING_FUNC(ring_PQconnectStartParams)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQconnectStartParams((char **) RING_API_GETCPOINTER2POINTER(1,"char"),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (int ) RING_API_GETNUMBER(3)),"PGconn");
}


RING_FUNC(ring_PQconnectStart)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQconnectStart(RING_API_GETSTRING(1)),"PGconn");
}


RING_FUNC(ring_PQconnectPoll)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQconnectPoll((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQconndefaults)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETCPOINTER(PQconndefaults(),"PQconninfoOption");
}


RING_FUNC(ring_PQconninfo)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQconninfo((PGconn *) RING_API_GETCPOINTER(1,"PGconn")),"PQconninfoOption");
}


RING_FUNC(ring_PQconninfoParse)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQconninfoParse(RING_API_GETSTRING(1),(char **) RING_API_GETCPOINTER2POINTER(2,"char")),"PQconninfoOption");
}


RING_FUNC(ring_PQfinish)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQfinish((PGconn *) RING_API_GETCPOINTER(1,"PGconn"));
}


RING_FUNC(ring_PQreset)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQreset((PGconn *) RING_API_GETCPOINTER(1,"PGconn"));
}


RING_FUNC(ring_PQresetStart)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQresetStart((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQresetPoll)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQresetPoll((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQpingParams)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		PGPing *pValue ; 
		pValue = (PGPing *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(PGPing)) ;
		*pValue = PQpingParams((char **) RING_API_GETCPOINTER2POINTER(1,"char"),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETCPOINTER(pValue,"PGPing");
	}
}


RING_FUNC(ring_PQping)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		PGPing *pValue ; 
		pValue = (PGPing *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(PGPing)) ;
		*pValue = PQping(RING_API_GETSTRING(1));
		RING_API_RETCPOINTER(pValue,"PGPing");
	}
}


RING_FUNC(ring_PQdb)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQdb((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQuser)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQuser((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQpass)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQpass((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQhost)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQhost((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQport)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQport((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQtty)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQtty((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQoptions)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQoptions((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQstatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQstatus((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQtransactionStatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQtransactionStatus((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQparameterStatus)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQparameterStatus((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQprotocolVersion)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQprotocolVersion((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQserverVersion)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQserverVersion((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQerrorMessage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQerrorMessage((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQsocket)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsocket((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQbackendPID)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQbackendPID((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQconnectionNeedsPassword)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQconnectionNeedsPassword((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQconnectionUsedPassword)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQconnectionUsedPassword((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQsslInUse)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsslInUse((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQsslAttribute)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQsslAttribute((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQsslAttributeNames)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQsslAttributeNames((PGconn *) RING_API_GETCPOINTER(1,"PGconn")),"char");
}


RING_FUNC(ring_PQsslStruct)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQsslStruct((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)),"void");
}


RING_FUNC(ring_PQgetssl)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQgetssl((PGconn *) RING_API_GETCPOINTER(1,"PGconn")),"void");
}


RING_FUNC(ring_PQexec)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQexec((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)),"PGresult");
}


RING_FUNC(ring_PQexecParams)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(8) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQexecParams((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),(Oid *) RING_API_GETCPOINTER(4,"Oid"),(char **) RING_API_GETCPOINTER2POINTER(5,"char"),RING_API_GETINTPOINTER(6),RING_API_GETINTPOINTER(7), (int ) RING_API_GETNUMBER(8)),"PGresult");
	RING_API_ACCEPTINTVALUE(6) ;
	RING_API_ACCEPTINTVALUE(7) ;
}


RING_FUNC(ring_PQprepare)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQprepare((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),(Oid *) RING_API_GETCPOINTER(5,"Oid")),"PGresult");
}


RING_FUNC(ring_PQexecPrepared)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQexecPrepared((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),(char **) RING_API_GETCPOINTER2POINTER(4,"char"),RING_API_GETINTPOINTER(5),RING_API_GETINTPOINTER(6), (int ) RING_API_GETNUMBER(7)),"PGresult");
	RING_API_ACCEPTINTVALUE(5) ;
	RING_API_ACCEPTINTVALUE(6) ;
}


RING_FUNC(ring_PQdescribePrepared)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQdescribePrepared((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)),"PGresult");
}


RING_FUNC(ring_PQdescribePortal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQdescribePortal((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)),"PGresult");
}


RING_FUNC(ring_PQresultStatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQresultStatus((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("pqconnectdbparams",ring_PQconnectdbParams);
	ring_vm_funcregister("pqconnectdb",ring_PQconnectdb);
	ring_vm_funcregister("pqsetdblogin",ring_PQsetdbLogin);
	ring_vm_funcregister("pqsetdb",ring_PQsetdb);
	ring_vm_funcregister("pqconnectstartparams",ring_PQconnectStartParams);
	ring_vm_funcregister("pqconnectstart",ring_PQconnectStart);
	ring_vm_funcregister("pqconnectpoll",ring_PQconnectPoll);
	ring_vm_funcregister("pqconndefaults",ring_PQconndefaults);
	ring_vm_funcregister("pqconninfo",ring_PQconninfo);
	ring_vm_funcregister("pqconninfoparse",ring_PQconninfoParse);
	ring_vm_funcregister("pqfinish",ring_PQfinish);
	ring_vm_funcregister("pqreset",ring_PQreset);
	ring_vm_funcregister("pqresetstart",ring_PQresetStart);
	ring_vm_funcregister("pqresetpoll",ring_PQresetPoll);
	ring_vm_funcregister("pqpingparams",ring_PQpingParams);
	ring_vm_funcregister("pqping",ring_PQping);
	ring_vm_funcregister("pqdb",ring_PQdb);
	ring_vm_funcregister("pquser",ring_PQuser);
	ring_vm_funcregister("pqpass",ring_PQpass);
	ring_vm_funcregister("pqhost",ring_PQhost);
	ring_vm_funcregister("pqport",ring_PQport);
	ring_vm_funcregister("pqtty",ring_PQtty);
	ring_vm_funcregister("pqoptions",ring_PQoptions);
	ring_vm_funcregister("pqstatus",ring_PQstatus);
	ring_vm_funcregister("pqtransactionstatus",ring_PQtransactionStatus);
	ring_vm_funcregister("pqparameterstatus",ring_PQparameterStatus);
	ring_vm_funcregister("pqprotocolversion",ring_PQprotocolVersion);
	ring_vm_funcregister("pqserverversion",ring_PQserverVersion);
	ring_vm_funcregister("pqerrormessage",ring_PQerrorMessage);
	ring_vm_funcregister("pqsocket",ring_PQsocket);
	ring_vm_funcregister("pqbackendpid",ring_PQbackendPID);
	ring_vm_funcregister("pqconnectionneedspassword",ring_PQconnectionNeedsPassword);
	ring_vm_funcregister("pqconnectionusedpassword",ring_PQconnectionUsedPassword);
	ring_vm_funcregister("pqsslinuse",ring_PQsslInUse);
	ring_vm_funcregister("pqsslattribute",ring_PQsslAttribute);
	ring_vm_funcregister("pqsslattributenames",ring_PQsslAttributeNames);
	ring_vm_funcregister("pqsslstruct",ring_PQsslStruct);
	ring_vm_funcregister("pqgetssl",ring_PQgetssl);
	ring_vm_funcregister("pqexec",ring_PQexec);
	ring_vm_funcregister("pqexecparams",ring_PQexecParams);
	ring_vm_funcregister("pqprepare",ring_PQprepare);
	ring_vm_funcregister("pqexecprepared",ring_PQexecPrepared);
	ring_vm_funcregister("pqdescribeprepared",ring_PQdescribePrepared);
	ring_vm_funcregister("pqdescribeportal",ring_PQdescribePortal);
	ring_vm_funcregister("pqresultstatus",ring_PQresultStatus);
	ring_vm_funcregister("get_connection_started",ring_get_connection_started);
	ring_vm_funcregister("get_connection_made",ring_get_connection_made);
	ring_vm_funcregister("get_connection_awaiting_response",ring_get_connection_awaiting_response);
	ring_vm_funcregister("get_connection_auth_ok",ring_get_connection_auth_ok);
	ring_vm_funcregister("get_connection_ssl_startup",ring_get_connection_ssl_startup);
	ring_vm_funcregister("get_connection_setenv",ring_get_connection_setenv);
	ring_vm_funcregister("get_connection_check_writable",ring_get_connection_check_writable);
	ring_vm_funcregister("get_connection_consume",ring_get_connection_consume);
	ring_vm_funcregister("get_pqping_ok",ring_get_pqping_ok);
	ring_vm_funcregister("get_pqping_reject",ring_get_pqping_reject);
	ring_vm_funcregister("get_pqping_no_response",ring_get_pqping_no_response);
	ring_vm_funcregister("get_pqping_no_attempt",ring_get_pqping_no_attempt);
	ring_vm_funcregister("get_pgres_empty_query",ring_get_pgres_empty_query);
	ring_vm_funcregister("get_pgres_command_ok",ring_get_pgres_command_ok);
	ring_vm_funcregister("get_pgres_tuples_ok",ring_get_pgres_tuples_ok);
	ring_vm_funcregister("get_pgres_copy_out",ring_get_pgres_copy_out);
	ring_vm_funcregister("get_pgres_copy_in",ring_get_pgres_copy_in);
	ring_vm_funcregister("get_pgres_bad_response",ring_get_pgres_bad_response);
	ring_vm_funcregister("get_pgres_nonfatal_error",ring_get_pgres_nonfatal_error);
	ring_vm_funcregister("get_pgres_fatal_error",ring_get_pgres_fatal_error);
	ring_vm_funcregister("get_pgres_copy_both",ring_get_pgres_copy_both);
	ring_vm_funcregister("get_pgres_single_tuple",ring_get_pgres_single_tuple);
	ring_vm_funcregister("new_pqconninfooption",ring_new_pqconninfooption);
	ring_vm_funcregister("destroy_pqconninfooption",ring_destroy_pqconninfooption);
	ring_vm_funcregister("get_pqconninfooption_keyword",ring_get_pqconninfooption_keyword);
	ring_vm_funcregister("set_pqconninfooption_keyword",ring_set_pqconninfooption_keyword);
	ring_vm_funcregister("get_pqconninfooption_envvar",ring_get_pqconninfooption_envvar);
	ring_vm_funcregister("set_pqconninfooption_envvar",ring_set_pqconninfooption_envvar);
	ring_vm_funcregister("get_pqconninfooption_compiled",ring_get_pqconninfooption_compiled);
	ring_vm_funcregister("set_pqconninfooption_compiled",ring_set_pqconninfooption_compiled);
	ring_vm_funcregister("get_pqconninfooption_val",ring_get_pqconninfooption_val);
	ring_vm_funcregister("set_pqconninfooption_val",ring_set_pqconninfooption_val);
	ring_vm_funcregister("get_pqconninfooption_label",ring_get_pqconninfooption_label);
	ring_vm_funcregister("set_pqconninfooption_label",ring_set_pqconninfooption_label);
	ring_vm_funcregister("get_pqconninfooption_dispchar",ring_get_pqconninfooption_dispchar);
	ring_vm_funcregister("set_pqconninfooption_dispchar",ring_set_pqconninfooption_dispchar);
	ring_vm_funcregister("get_pqconninfooption_dispsize",ring_get_pqconninfooption_dispsize);
	ring_vm_funcregister("set_pqconninfooption_dispsize",ring_set_pqconninfooption_dispsize);
}

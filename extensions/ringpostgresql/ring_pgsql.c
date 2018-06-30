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
	if ( ! RING_API_ISSTRING(1) ) {
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
	RING_API_RETCPOINTER(PQconnectdbParams(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)),"PGconn");
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
	RING_API_RETCPOINTER(PQconnectStartParams((char *) RING_API_GETCPOINTER(1,"char"),(char *) RING_API_GETCPOINTER(2,"char"), (int ) RING_API_GETNUMBER(3)),"PGconn");
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

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("pqconnectdbparams",ring_PQconnectdbParams);
	ring_vm_funcregister("pqconnectdb",ring_PQconnectdb);
	ring_vm_funcregister("pqsetdblogin",ring_PQsetdbLogin);
	ring_vm_funcregister("pqsetdb",ring_PQsetdb);
	ring_vm_funcregister("pqconnectstartparams",ring_PQconnectStartParams);
	ring_vm_funcregister("pqconnectstart",ring_PQconnectStart);
	ring_vm_funcregister("pqconnectpoll",ring_PQconnectPoll);
	ring_vm_funcregister("pqstatus",ring_PQstatus);
	ring_vm_funcregister("pqconndefaults",ring_PQconndefaults);
	ring_vm_funcregister("pqconninfo",ring_PQconninfo);
	ring_vm_funcregister("pqconninfoparse",ring_PQconninfoParse);
	ring_vm_funcregister("pqfinish",ring_PQfinish);
	ring_vm_funcregister("pqreset",ring_PQreset);
	ring_vm_funcregister("pqresetstart",ring_PQresetStart);
	ring_vm_funcregister("pqresetpoll",ring_PQresetPoll);
	ring_vm_funcregister("get_connection_started",ring_get_connection_started);
	ring_vm_funcregister("get_connection_made",ring_get_connection_made);
	ring_vm_funcregister("get_connection_awaiting_response",ring_get_connection_awaiting_response);
	ring_vm_funcregister("get_connection_auth_ok",ring_get_connection_auth_ok);
	ring_vm_funcregister("get_connection_ssl_startup",ring_get_connection_ssl_startup);
	ring_vm_funcregister("get_connection_setenv",ring_get_connection_setenv);
	ring_vm_funcregister("get_connection_check_writable",ring_get_connection_check_writable);
	ring_vm_funcregister("get_connection_consume",ring_get_connection_consume);
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

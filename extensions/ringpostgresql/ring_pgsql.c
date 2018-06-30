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
	ring_vm_funcregister("get_connection_started",ring_get_connection_started);
	ring_vm_funcregister("get_connection_made",ring_get_connection_made);
	ring_vm_funcregister("get_connection_awaiting_response",ring_get_connection_awaiting_response);
	ring_vm_funcregister("get_connection_auth_ok",ring_get_connection_auth_ok);
	ring_vm_funcregister("get_connection_ssl_startup",ring_get_connection_ssl_startup);
	ring_vm_funcregister("get_connection_setenv",ring_get_connection_setenv);
	ring_vm_funcregister("get_connection_check_writable",ring_get_connection_check_writable);
	ring_vm_funcregister("get_connection_consume",ring_get_connection_consume);
}

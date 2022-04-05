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

RING_FUNC(ring_get_connection_ok)
{
	RING_API_RETNUMBER(CONNECTION_OK);
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

RING_FUNC(ring_get_pg_diag_severity)
{
	RING_API_RETNUMBER(PG_DIAG_SEVERITY);
}

RING_FUNC(ring_get_pg_diag_sqlstate)
{
	RING_API_RETNUMBER(PG_DIAG_SQLSTATE);
}

RING_FUNC(ring_get_pg_diag_message_primary)
{
	RING_API_RETNUMBER(PG_DIAG_MESSAGE_PRIMARY);
}

RING_FUNC(ring_get_pg_diag_message_detail)
{
	RING_API_RETNUMBER(PG_DIAG_MESSAGE_DETAIL);
}

RING_FUNC(ring_get_pg_diag_message_hint)
{
	RING_API_RETNUMBER(PG_DIAG_MESSAGE_HINT);
}

RING_FUNC(ring_get_pg_diag_statement_position)
{
	RING_API_RETNUMBER(PG_DIAG_STATEMENT_POSITION);
}

RING_FUNC(ring_get_pg_diag_internal_position)
{
	RING_API_RETNUMBER(PG_DIAG_INTERNAL_POSITION);
}

RING_FUNC(ring_get_pg_diag_internal_query)
{
	RING_API_RETNUMBER(PG_DIAG_INTERNAL_QUERY);
}

RING_FUNC(ring_get_pg_diag_context)
{
	RING_API_RETNUMBER(PG_DIAG_CONTEXT);
}

RING_FUNC(ring_get_pg_diag_schema_name)
{
	RING_API_RETNUMBER(PG_DIAG_SCHEMA_NAME);
}

RING_FUNC(ring_get_pg_diag_table_name)
{
	RING_API_RETNUMBER(PG_DIAG_TABLE_NAME);
}

RING_FUNC(ring_get_pg_diag_column_name)
{
	RING_API_RETNUMBER(PG_DIAG_COLUMN_NAME);
}

RING_FUNC(ring_get_pg_diag_datatype_name)
{
	RING_API_RETNUMBER(PG_DIAG_DATATYPE_NAME);
}

RING_FUNC(ring_get_pg_diag_constraint_name)
{
	RING_API_RETNUMBER(PG_DIAG_CONSTRAINT_NAME);
}

RING_FUNC(ring_get_pg_diag_source_file)
{
	RING_API_RETNUMBER(PG_DIAG_SOURCE_FILE);
}

RING_FUNC(ring_get_pg_diag_source_line)
{
	RING_API_RETNUMBER(PG_DIAG_SOURCE_LINE);
}

RING_FUNC(ring_get_pg_diag_source_function)
{
	RING_API_RETNUMBER(PG_DIAG_SOURCE_FUNCTION);
}

RING_FUNC(ring_new_pqconninfooption)
{
	PQconninfoOption *pMyPointer ;
	pMyPointer = (PQconninfoOption *) RING_API_MALLOC(sizeof(PQconninfoOption)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"PQconninfoOption");
}

RING_FUNC(ring_new_managed_pqconninfooption)
{
	PQconninfoOption *pMyPointer ;
	pMyPointer = (PQconninfoOption *) RING_API_MALLOC(sizeof(PQconninfoOption)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"PQconninfoOption",RING_API_FREEFUNC);
}

RING_FUNC(ring_destroy_pqconninfooption)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (PQconninfoOption*) RING_API_GETCPOINTER(1,"PQconninfoOption");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->keyword = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqconninfooption_envvar)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->envvar = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqconninfooption_compiled)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->compiled = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqconninfooption_val)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->val = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqconninfooption_label)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->label = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqconninfooption_dispchar)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQconninfoOption");
	pMyPointer->dispchar = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqconninfooption_dispsize)
{
	PQconninfoOption *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
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
	if ( ! RING_API_ISCPOINTER(1) ) { 
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

RING_FUNC(ring_new_pqprintopt)
{
	PQprintOpt *pMyPointer ;
	pMyPointer = (PQprintOpt *) RING_API_MALLOC(sizeof(PQprintOpt)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"PQprintOpt");
}

RING_FUNC(ring_new_managed_pqprintopt)
{
	PQprintOpt *pMyPointer ;
	pMyPointer = (PQprintOpt *) RING_API_MALLOC(sizeof(PQprintOpt)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"PQprintOpt",RING_API_FREEFUNC);
}

RING_FUNC(ring_destroy_pqprintopt)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (PQprintOpt*) RING_API_GETCPOINTER(1,"PQprintOpt");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_pqprintopt_header)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETNUMBER(pMyPointer->header);
}

RING_FUNC(ring_set_pqprintopt_header)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->header = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqprintopt_align)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETNUMBER(pMyPointer->align);
}

RING_FUNC(ring_set_pqprintopt_align)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->align = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqprintopt_standard)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETNUMBER(pMyPointer->standard);
}

RING_FUNC(ring_set_pqprintopt_standard)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->standard = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqprintopt_html3)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETNUMBER(pMyPointer->html3);
}

RING_FUNC(ring_set_pqprintopt_html3)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->html3 = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqprintopt_expanded)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETNUMBER(pMyPointer->expanded);
}

RING_FUNC(ring_set_pqprintopt_expanded)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->expanded = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqprintopt_pager)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETNUMBER(pMyPointer->pager);
}

RING_FUNC(ring_set_pqprintopt_pager)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->pager = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqprintopt_fieldSep)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETCPOINTER(pMyPointer->fieldSep,"char");
}

RING_FUNC(ring_set_pqprintopt_fieldSep)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->fieldSep = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqprintopt_tableOpt)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETCPOINTER(pMyPointer->tableOpt,"char");
}

RING_FUNC(ring_set_pqprintopt_tableOpt)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->tableOpt = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqprintopt_caption)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETCPOINTER(pMyPointer->caption,"char");
}

RING_FUNC(ring_set_pqprintopt_caption)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->caption = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_get_pqprintopt_fieldName)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	RING_API_RETCPOINTER(pMyPointer->fieldName,"char");
}

RING_FUNC(ring_set_pqprintopt_fieldName)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->fieldName = (char *) RING_API_GETCPOINTER(2,"char");
}

RING_FUNC(ring_new_pqargblock)
{
	PQArgBlock *pMyPointer ;
	pMyPointer = (PQArgBlock *) RING_API_MALLOC(sizeof(PQArgBlock)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"PQArgBlock");
}

RING_FUNC(ring_new_managed_pqargblock)
{
	PQArgBlock *pMyPointer ;
	pMyPointer = (PQArgBlock *) RING_API_MALLOC(sizeof(PQArgBlock)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETMANAGEDCPOINTER(pMyPointer,"PQArgBlock",RING_API_FREEFUNC);
}

RING_FUNC(ring_destroy_pqargblock)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = (PQArgBlock*) RING_API_GETCPOINTER(1,"PQArgBlock");
	if (pMyPointer != NULL) {
		RING_API_FREE(pMyPointer) ;
		RING_API_SETNULLPOINTER(1);
	}
}

RING_FUNC(ring_get_pqargblock_len)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	RING_API_RETNUMBER(pMyPointer->len);
}

RING_FUNC(ring_set_pqargblock_len)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	pMyPointer->len = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqargblock_isint)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	RING_API_RETNUMBER(pMyPointer->isint);
}

RING_FUNC(ring_set_pqargblock_isint)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	pMyPointer->isint = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqargblock_u_integer)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	RING_API_RETNUMBER(pMyPointer->u.integer);
}

RING_FUNC(ring_set_pqargblock_u_integer)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	pMyPointer->u.integer = RING_API_GETNUMBER(2);
}

RING_FUNC(ring_get_pqargblock_u_ptr)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	RING_API_RETCPOINTER(pMyPointer->u.ptr,"int");
}

RING_FUNC(ring_set_pqargblock_u_ptr)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA) ;
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	pMyPointer->u.ptr = (int *) RING_API_GETCPOINTER(2,"int");
}


RING_FUNC(ring_PQconnectdbParams)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(2) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		PGPing *pValue ; 
		pValue = (PGPing *) RING_API_MALLOC(sizeof(PGPing)) ;
		*pValue = PQpingParams((char **) RING_API_GETCPOINTER2POINTER(1,"char"),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (int ) RING_API_GETNUMBER(3));
		RING_API_RETMANAGEDCPOINTER(pValue,"PGPing",RING_API_FREEFUNC);
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
		pValue = (PGPing *) RING_API_MALLOC(sizeof(PGPing)) ;
		*pValue = PQping(RING_API_GETSTRING(1));
		RING_API_RETMANAGEDCPOINTER(pValue,"PGPing",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_PQdb)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(5) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(4) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQresultStatus((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQresStatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQresStatus( (ExecStatusType )  (int) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_PQresultErrorMessage)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQresultErrorMessage((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQresultErrorField)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQresultErrorField((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQclear)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQclear((PGresult *) RING_API_GETCPOINTER(1,"PGresult"));
}


RING_FUNC(ring_PQntuples)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQntuples((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQnfields)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQnfields((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQfname)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQfname((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQfnumber)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQfnumber((PGresult *) RING_API_GETCPOINTER(1,"PGresult"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQftable)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Oid *pValue ; 
		pValue = (Oid *) RING_API_MALLOC(sizeof(Oid)) ;
		*pValue = PQftable((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_PQftablecol)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQftablecol((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQfformat)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQfformat((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQftype)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Oid *pValue ; 
		pValue = (Oid *) RING_API_MALLOC(sizeof(Oid)) ;
		*pValue = PQftype((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_PQfmod)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQfmod((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQfsize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQfsize((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQbinaryTuples)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQbinaryTuples((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQgetvalue)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQgetvalue((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQgetisnull)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQgetisnull((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQgetlength)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQgetlength((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQnparams)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQnparams((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQparamtype)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Oid *pValue ; 
		pValue = (Oid *) RING_API_MALLOC(sizeof(Oid)) ;
		*pValue = PQparamtype((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_PQprint)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQprint((FILE *) RING_API_GETCPOINTER(1,"FILE"),(PGresult *) RING_API_GETCPOINTER(2,"PGresult"),(PQprintOpt *) RING_API_GETCPOINTER(3,"PQprintOpt"));
}


RING_FUNC(ring_PQcmdStatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQcmdStatus((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQcmdTuples)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQcmdTuples((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQoidValue)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Oid *pValue ; 
		pValue = (Oid *) RING_API_MALLOC(sizeof(Oid)) ;
		*pValue = PQoidValue((PGresult *) RING_API_GETCPOINTER(1,"PGresult"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_PQoidStatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(PQoidStatus((PGresult *) RING_API_GETCPOINTER(1,"PGresult")));
}


RING_FUNC(ring_PQescapeLiteral)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETSTRING(PQescapeLiteral((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQescapeIdentifier)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETSTRING(PQescapeIdentifier((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQescapeStringConn)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISSTRING(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQescapeStringConn((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (size_t ) RING_API_GETNUMBER(4),RING_API_GETINTPOINTER(5)));
	RING_API_ACCEPTINTVALUE(5) ;
}


RING_FUNC(ring_PQescapeString)
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
	RING_API_RETNUMBER(PQescapeString(RING_API_GETSTRING(1),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQescapeByteaConn)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQescapeByteaConn((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),(unsigned char *) RING_API_GETCPOINTER(2,"unsigned char"), (size_t ) RING_API_GETNUMBER(3),(size_t *) RING_API_GETCPOINTER(4,"size_t")),"unsigned char");
}


RING_FUNC(ring_PQescapeBytea)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQescapeBytea((unsigned char *) RING_API_GETCPOINTER(1,"unsigned char"), (size_t ) RING_API_GETNUMBER(2),(size_t *) RING_API_GETCPOINTER(3,"size_t")),"unsigned char");
}


RING_FUNC(ring_PQunescapeBytea)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQunescapeBytea((unsigned char *) RING_API_GETCPOINTER(1,"unsigned char"),(size_t *) RING_API_GETCPOINTER(2,"size_t")),"unsigned char");
}


RING_FUNC(ring_PQsendQuery)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsendQuery((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQsendQueryParams)
{
	if ( RING_API_PARACOUNT != 8 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(5) ) {
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
	RING_API_RETNUMBER(PQsendQueryParams((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),(Oid *) RING_API_GETCPOINTER(4,"Oid"),(char **) RING_API_GETCPOINTER2POINTER(5,"char"),RING_API_GETINTPOINTER(6),RING_API_GETINTPOINTER(7), (int ) RING_API_GETNUMBER(8)));
	RING_API_ACCEPTINTVALUE(6) ;
	RING_API_ACCEPTINTVALUE(7) ;
}


RING_FUNC(ring_PQsendPrepare)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsendPrepare((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),(Oid *) RING_API_GETCPOINTER(5,"Oid")));
}


RING_FUNC(ring_PQsendQueryPrepared)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	if ( ! RING_API_ISCPOINTER(4) ) {
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
	RING_API_RETNUMBER(PQsendQueryPrepared((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3),(char **) RING_API_GETCPOINTER2POINTER(4,"char"),RING_API_GETINTPOINTER(5),RING_API_GETINTPOINTER(6), (int ) RING_API_GETNUMBER(7)));
	RING_API_ACCEPTINTVALUE(5) ;
	RING_API_ACCEPTINTVALUE(6) ;
}


RING_FUNC(ring_PQsendDescribePrepared)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsendDescribePrepared((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQsendDescribePortal)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsendDescribePortal((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQgetResult)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQgetResult((PGconn *) RING_API_GETCPOINTER(1,"PGconn")),"PGresult");
}


RING_FUNC(ring_PQconsumeInput)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQconsumeInput((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQisBusy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQisBusy((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQsetnonblocking)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsetnonblocking((PGconn *) RING_API_GETCPOINTER(1,"PGconn"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQisnonblocking)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQisnonblocking((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQflush)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQflush((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQsetSingleRowMode)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsetSingleRowMode((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQgetCancel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQgetCancel((PGconn *) RING_API_GETCPOINTER(1,"PGconn")),"PGcancel");
}


RING_FUNC(ring_PQfreeCancel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQfreeCancel((PGcancel *) RING_API_GETCPOINTER(1,"PGcancel"));
}


RING_FUNC(ring_PQcancel)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQcancel((PGcancel *) RING_API_GETCPOINTER(1,"PGcancel"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQrequestCancel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQrequestCancel((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQfn)
{
	if ( RING_API_PARACOUNT != 7 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
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
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(6) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(7) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQfn((PGconn *) RING_API_GETCPOINTER(1,"PGconn"), (int ) RING_API_GETNUMBER(2),RING_API_GETINTPOINTER(3),RING_API_GETINTPOINTER(4), (int ) RING_API_GETNUMBER(5),(PQArgBlock *) RING_API_GETCPOINTER(6,"PQArgBlock"), (int ) RING_API_GETNUMBER(7)),"PGresult");
	RING_API_ACCEPTINTVALUE(3) ;
	RING_API_ACCEPTINTVALUE(4) ;
}


RING_FUNC(ring_PQnotifies)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQnotifies((PGconn *) RING_API_GETCPOINTER(1,"PGconn")),"PGnotify");
}


RING_FUNC(ring_PQputCopyData)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQputCopyData((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQputCopyEnd)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQputCopyEnd((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQgetCopyData)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQgetCopyData((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQgetline)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQgetline((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQgetlineAsync)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQgetlineAsync((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQputline)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQputline((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQputnbytes)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQputnbytes((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQendcopy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQendcopy((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_PQclientEncoding)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQclientEncoding((PGconn *) RING_API_GETCPOINTER(1,"PGconn")));
}


RING_FUNC(ring_pg_encoding_to_char)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(pg_encoding_to_char( (int ) RING_API_GETNUMBER(1)));
}


RING_FUNC(ring_PQsetClientEncoding)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsetClientEncoding((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQtrace)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQtrace((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),(FILE *) RING_API_GETCPOINTER(2,"FILE"));
}


RING_FUNC(ring_PQuntrace)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQuntrace((PGconn *) RING_API_GETCPOINTER(1,"PGconn"));
}


RING_FUNC(ring_PQfreemem)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQfreemem((void *) RING_API_GETCPOINTER(1,"void"));
}


RING_FUNC(ring_PQconninfoFree)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQconninfoFree((PQconninfoOption *) RING_API_GETCPOINTER(1,"PQconninfoOption"));
}


RING_FUNC(ring_PQencryptPasswordConn)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
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
	RING_API_RETSTRING(PQencryptPasswordConn((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2),RING_API_GETSTRING(3),RING_API_GETSTRING(4)));
}


RING_FUNC(ring_PQencryptPassword)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETSTRING(PQencryptPassword(RING_API_GETSTRING(1),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQmakeEmptyPGresult)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQmakeEmptyPGresult((PGconn *) RING_API_GETCPOINTER(1,"PGconn"), (ExecStatusType )  (int) RING_API_GETNUMBER(2)),"PGresult");
}


RING_FUNC(ring_PQfireResultCreateEvents)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQfireResultCreateEvents((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),(PGresult *) RING_API_GETCPOINTER(2,"PGresult")));
}


RING_FUNC(ring_PQcopyResult)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQcopyResult((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)),"PGresult");
}


RING_FUNC(ring_PQsetResultAttrs)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsetResultAttrs((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2),(PGresAttDesc *) RING_API_GETCPOINTER(3,"PGresAttDesc")));
}


RING_FUNC(ring_PQsetvalue)
{
	if ( RING_API_PARACOUNT != 5 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(4) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(5) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETNUMBER(PQsetvalue((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2), (int ) RING_API_GETNUMBER(3),RING_API_GETSTRING(4), (int ) RING_API_GETNUMBER(5)));
}


RING_FUNC(ring_PQresultAlloc)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(PQresultAlloc((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (size_t ) RING_API_GETNUMBER(2)),"void");
}


RING_FUNC(ring_PQlibVersion)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(PQlibVersion());
}


RING_FUNC(ring_PQsetNoticeReceiver)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		PQnoticeReceiver *pValue ; 
		pValue = (PQnoticeReceiver *) RING_API_MALLOC(sizeof(PQnoticeReceiver)) ;
		*pValue = PQsetNoticeReceiver((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),* (PQnoticeReceiver  *) RING_API_GETCPOINTER(2,"PQnoticeReceiver"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"PQnoticeReceiver"));
		RING_API_RETMANAGEDCPOINTER(pValue,"PQnoticeReceiver",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_PQsetNoticeProcessor)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		PQnoticeProcessor *pValue ; 
		pValue = (PQnoticeProcessor *) RING_API_MALLOC(sizeof(PQnoticeProcessor)) ;
		*pValue = PQsetNoticeProcessor((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),* (PQnoticeProcessor  *) RING_API_GETCPOINTER(2,"PQnoticeProcessor"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		RING_API_FREE(RING_API_GETCPOINTER(2,"PQnoticeProcessor"));
		RING_API_RETMANAGEDCPOINTER(pValue,"PQnoticeProcessor",RING_API_FREEFUNC);
	}
}


RING_FUNC(ring_PQinitOpenSSL)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQinitOpenSSL( (int ) RING_API_GETNUMBER(1), (int ) RING_API_GETNUMBER(2));
}


RING_FUNC(ring_PQinitSSL)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISNUMBER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	PQinitSSL( (int ) RING_API_GETNUMBER(1));
}


RING_FUNC(ring_PQisthreadsafe)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_RETNUMBER(PQisthreadsafe());
}

RING_API void ringlib_init(RingState *pRingState)
{
	RING_API_REGISTER("pqconnectdbparams",ring_PQconnectdbParams);
	RING_API_REGISTER("pqconnectdb",ring_PQconnectdb);
	RING_API_REGISTER("pqsetdblogin",ring_PQsetdbLogin);
	RING_API_REGISTER("pqsetdb",ring_PQsetdb);
	RING_API_REGISTER("pqconnectstartparams",ring_PQconnectStartParams);
	RING_API_REGISTER("pqconnectstart",ring_PQconnectStart);
	RING_API_REGISTER("pqconnectpoll",ring_PQconnectPoll);
	RING_API_REGISTER("pqconndefaults",ring_PQconndefaults);
	RING_API_REGISTER("pqconninfo",ring_PQconninfo);
	RING_API_REGISTER("pqconninfoparse",ring_PQconninfoParse);
	RING_API_REGISTER("pqfinish",ring_PQfinish);
	RING_API_REGISTER("pqreset",ring_PQreset);
	RING_API_REGISTER("pqresetstart",ring_PQresetStart);
	RING_API_REGISTER("pqresetpoll",ring_PQresetPoll);
	RING_API_REGISTER("pqpingparams",ring_PQpingParams);
	RING_API_REGISTER("pqping",ring_PQping);
	RING_API_REGISTER("pqdb",ring_PQdb);
	RING_API_REGISTER("pquser",ring_PQuser);
	RING_API_REGISTER("pqpass",ring_PQpass);
	RING_API_REGISTER("pqhost",ring_PQhost);
	RING_API_REGISTER("pqport",ring_PQport);
	RING_API_REGISTER("pqtty",ring_PQtty);
	RING_API_REGISTER("pqoptions",ring_PQoptions);
	RING_API_REGISTER("pqstatus",ring_PQstatus);
	RING_API_REGISTER("pqtransactionstatus",ring_PQtransactionStatus);
	RING_API_REGISTER("pqparameterstatus",ring_PQparameterStatus);
	RING_API_REGISTER("pqprotocolversion",ring_PQprotocolVersion);
	RING_API_REGISTER("pqserverversion",ring_PQserverVersion);
	RING_API_REGISTER("pqerrormessage",ring_PQerrorMessage);
	RING_API_REGISTER("pqsocket",ring_PQsocket);
	RING_API_REGISTER("pqbackendpid",ring_PQbackendPID);
	RING_API_REGISTER("pqconnectionneedspassword",ring_PQconnectionNeedsPassword);
	RING_API_REGISTER("pqconnectionusedpassword",ring_PQconnectionUsedPassword);
	RING_API_REGISTER("pqsslinuse",ring_PQsslInUse);
	RING_API_REGISTER("pqsslattribute",ring_PQsslAttribute);
	RING_API_REGISTER("pqsslattributenames",ring_PQsslAttributeNames);
	RING_API_REGISTER("pqsslstruct",ring_PQsslStruct);
	RING_API_REGISTER("pqgetssl",ring_PQgetssl);
	RING_API_REGISTER("pqexec",ring_PQexec);
	RING_API_REGISTER("pqexecparams",ring_PQexecParams);
	RING_API_REGISTER("pqprepare",ring_PQprepare);
	RING_API_REGISTER("pqexecprepared",ring_PQexecPrepared);
	RING_API_REGISTER("pqdescribeprepared",ring_PQdescribePrepared);
	RING_API_REGISTER("pqdescribeportal",ring_PQdescribePortal);
	RING_API_REGISTER("pqresultstatus",ring_PQresultStatus);
	RING_API_REGISTER("pqresstatus",ring_PQresStatus);
	RING_API_REGISTER("pqresulterrormessage",ring_PQresultErrorMessage);
	RING_API_REGISTER("pqresulterrorfield",ring_PQresultErrorField);
	RING_API_REGISTER("pqclear",ring_PQclear);
	RING_API_REGISTER("pqntuples",ring_PQntuples);
	RING_API_REGISTER("pqnfields",ring_PQnfields);
	RING_API_REGISTER("pqfname",ring_PQfname);
	RING_API_REGISTER("pqfnumber",ring_PQfnumber);
	RING_API_REGISTER("pqftable",ring_PQftable);
	RING_API_REGISTER("pqftablecol",ring_PQftablecol);
	RING_API_REGISTER("pqfformat",ring_PQfformat);
	RING_API_REGISTER("pqftype",ring_PQftype);
	RING_API_REGISTER("pqfmod",ring_PQfmod);
	RING_API_REGISTER("pqfsize",ring_PQfsize);
	RING_API_REGISTER("pqbinarytuples",ring_PQbinaryTuples);
	RING_API_REGISTER("pqgetvalue",ring_PQgetvalue);
	RING_API_REGISTER("pqgetisnull",ring_PQgetisnull);
	RING_API_REGISTER("pqgetlength",ring_PQgetlength);
	RING_API_REGISTER("pqnparams",ring_PQnparams);
	RING_API_REGISTER("pqparamtype",ring_PQparamtype);
	RING_API_REGISTER("pqprint",ring_PQprint);
	RING_API_REGISTER("pqcmdstatus",ring_PQcmdStatus);
	RING_API_REGISTER("pqcmdtuples",ring_PQcmdTuples);
	RING_API_REGISTER("pqoidvalue",ring_PQoidValue);
	RING_API_REGISTER("pqoidstatus",ring_PQoidStatus);
	RING_API_REGISTER("pqescapeliteral",ring_PQescapeLiteral);
	RING_API_REGISTER("pqescapeidentifier",ring_PQescapeIdentifier);
	RING_API_REGISTER("pqescapestringconn",ring_PQescapeStringConn);
	RING_API_REGISTER("pqescapestring",ring_PQescapeString);
	RING_API_REGISTER("pqescapebyteaconn",ring_PQescapeByteaConn);
	RING_API_REGISTER("pqescapebytea",ring_PQescapeBytea);
	RING_API_REGISTER("pqunescapebytea",ring_PQunescapeBytea);
	RING_API_REGISTER("pqsendquery",ring_PQsendQuery);
	RING_API_REGISTER("pqsendqueryparams",ring_PQsendQueryParams);
	RING_API_REGISTER("pqsendprepare",ring_PQsendPrepare);
	RING_API_REGISTER("pqsendqueryprepared",ring_PQsendQueryPrepared);
	RING_API_REGISTER("pqsenddescribeprepared",ring_PQsendDescribePrepared);
	RING_API_REGISTER("pqsenddescribeportal",ring_PQsendDescribePortal);
	RING_API_REGISTER("pqgetresult",ring_PQgetResult);
	RING_API_REGISTER("pqconsumeinput",ring_PQconsumeInput);
	RING_API_REGISTER("pqisbusy",ring_PQisBusy);
	RING_API_REGISTER("pqsetnonblocking",ring_PQsetnonblocking);
	RING_API_REGISTER("pqisnonblocking",ring_PQisnonblocking);
	RING_API_REGISTER("pqflush",ring_PQflush);
	RING_API_REGISTER("pqsetsinglerowmode",ring_PQsetSingleRowMode);
	RING_API_REGISTER("pqgetcancel",ring_PQgetCancel);
	RING_API_REGISTER("pqfreecancel",ring_PQfreeCancel);
	RING_API_REGISTER("pqcancel",ring_PQcancel);
	RING_API_REGISTER("pqrequestcancel",ring_PQrequestCancel);
	RING_API_REGISTER("pqfn",ring_PQfn);
	RING_API_REGISTER("pqnotifies",ring_PQnotifies);
	RING_API_REGISTER("pqputcopydata",ring_PQputCopyData);
	RING_API_REGISTER("pqputcopyend",ring_PQputCopyEnd);
	RING_API_REGISTER("pqgetcopydata",ring_PQgetCopyData);
	RING_API_REGISTER("pqgetline",ring_PQgetline);
	RING_API_REGISTER("pqgetlineasync",ring_PQgetlineAsync);
	RING_API_REGISTER("pqputline",ring_PQputline);
	RING_API_REGISTER("pqputnbytes",ring_PQputnbytes);
	RING_API_REGISTER("pqendcopy",ring_PQendcopy);
	RING_API_REGISTER("pqclientencoding",ring_PQclientEncoding);
	RING_API_REGISTER("pg_encoding_to_char",ring_pg_encoding_to_char);
	RING_API_REGISTER("pqsetclientencoding",ring_PQsetClientEncoding);
	RING_API_REGISTER("pqtrace",ring_PQtrace);
	RING_API_REGISTER("pquntrace",ring_PQuntrace);
	RING_API_REGISTER("pqfreemem",ring_PQfreemem);
	RING_API_REGISTER("pqconninfofree",ring_PQconninfoFree);
	RING_API_REGISTER("pqencryptpasswordconn",ring_PQencryptPasswordConn);
	RING_API_REGISTER("pqencryptpassword",ring_PQencryptPassword);
	RING_API_REGISTER("pqmakeemptypgresult",ring_PQmakeEmptyPGresult);
	RING_API_REGISTER("pqfireresultcreateevents",ring_PQfireResultCreateEvents);
	RING_API_REGISTER("pqcopyresult",ring_PQcopyResult);
	RING_API_REGISTER("pqsetresultattrs",ring_PQsetResultAttrs);
	RING_API_REGISTER("pqsetvalue",ring_PQsetvalue);
	RING_API_REGISTER("pqresultalloc",ring_PQresultAlloc);
	RING_API_REGISTER("pqlibversion",ring_PQlibVersion);
	RING_API_REGISTER("pqsetnoticereceiver",ring_PQsetNoticeReceiver);
	RING_API_REGISTER("pqsetnoticeprocessor",ring_PQsetNoticeProcessor);
	RING_API_REGISTER("pqinitopenssl",ring_PQinitOpenSSL);
	RING_API_REGISTER("pqinitssl",ring_PQinitSSL);
	RING_API_REGISTER("pqisthreadsafe",ring_PQisthreadsafe);
	RING_API_REGISTER("get_connection_started",ring_get_connection_started);
	RING_API_REGISTER("get_connection_made",ring_get_connection_made);
	RING_API_REGISTER("get_connection_awaiting_response",ring_get_connection_awaiting_response);
	RING_API_REGISTER("get_connection_auth_ok",ring_get_connection_auth_ok);
	RING_API_REGISTER("get_connection_ssl_startup",ring_get_connection_ssl_startup);
	RING_API_REGISTER("get_connection_setenv",ring_get_connection_setenv);
	RING_API_REGISTER("get_connection_ok",ring_get_connection_ok);
	RING_API_REGISTER("get_pqping_ok",ring_get_pqping_ok);
	RING_API_REGISTER("get_pqping_reject",ring_get_pqping_reject);
	RING_API_REGISTER("get_pqping_no_response",ring_get_pqping_no_response);
	RING_API_REGISTER("get_pqping_no_attempt",ring_get_pqping_no_attempt);
	RING_API_REGISTER("get_pgres_empty_query",ring_get_pgres_empty_query);
	RING_API_REGISTER("get_pgres_command_ok",ring_get_pgres_command_ok);
	RING_API_REGISTER("get_pgres_tuples_ok",ring_get_pgres_tuples_ok);
	RING_API_REGISTER("get_pgres_copy_out",ring_get_pgres_copy_out);
	RING_API_REGISTER("get_pgres_copy_in",ring_get_pgres_copy_in);
	RING_API_REGISTER("get_pgres_bad_response",ring_get_pgres_bad_response);
	RING_API_REGISTER("get_pgres_nonfatal_error",ring_get_pgres_nonfatal_error);
	RING_API_REGISTER("get_pgres_fatal_error",ring_get_pgres_fatal_error);
	RING_API_REGISTER("get_pgres_copy_both",ring_get_pgres_copy_both);
	RING_API_REGISTER("get_pgres_single_tuple",ring_get_pgres_single_tuple);
	RING_API_REGISTER("get_pg_diag_severity",ring_get_pg_diag_severity);
	RING_API_REGISTER("get_pg_diag_sqlstate",ring_get_pg_diag_sqlstate);
	RING_API_REGISTER("get_pg_diag_message_primary",ring_get_pg_diag_message_primary);
	RING_API_REGISTER("get_pg_diag_message_detail",ring_get_pg_diag_message_detail);
	RING_API_REGISTER("get_pg_diag_message_hint",ring_get_pg_diag_message_hint);
	RING_API_REGISTER("get_pg_diag_statement_position",ring_get_pg_diag_statement_position);
	RING_API_REGISTER("get_pg_diag_internal_position",ring_get_pg_diag_internal_position);
	RING_API_REGISTER("get_pg_diag_internal_query",ring_get_pg_diag_internal_query);
	RING_API_REGISTER("get_pg_diag_context",ring_get_pg_diag_context);
	RING_API_REGISTER("get_pg_diag_schema_name",ring_get_pg_diag_schema_name);
	RING_API_REGISTER("get_pg_diag_table_name",ring_get_pg_diag_table_name);
	RING_API_REGISTER("get_pg_diag_column_name",ring_get_pg_diag_column_name);
	RING_API_REGISTER("get_pg_diag_datatype_name",ring_get_pg_diag_datatype_name);
	RING_API_REGISTER("get_pg_diag_constraint_name",ring_get_pg_diag_constraint_name);
	RING_API_REGISTER("get_pg_diag_source_file",ring_get_pg_diag_source_file);
	RING_API_REGISTER("get_pg_diag_source_line",ring_get_pg_diag_source_line);
	RING_API_REGISTER("get_pg_diag_source_function",ring_get_pg_diag_source_function);
	RING_API_REGISTER("new_pqconninfooption",ring_new_pqconninfooption);
	RING_API_REGISTER("new_managed_pqconninfooption",ring_new_managed_pqconninfooption);
	RING_API_REGISTER("destroy_pqconninfooption",ring_destroy_pqconninfooption);
	RING_API_REGISTER("get_pqconninfooption_keyword",ring_get_pqconninfooption_keyword);
	RING_API_REGISTER("set_pqconninfooption_keyword",ring_set_pqconninfooption_keyword);
	RING_API_REGISTER("get_pqconninfooption_envvar",ring_get_pqconninfooption_envvar);
	RING_API_REGISTER("set_pqconninfooption_envvar",ring_set_pqconninfooption_envvar);
	RING_API_REGISTER("get_pqconninfooption_compiled",ring_get_pqconninfooption_compiled);
	RING_API_REGISTER("set_pqconninfooption_compiled",ring_set_pqconninfooption_compiled);
	RING_API_REGISTER("get_pqconninfooption_val",ring_get_pqconninfooption_val);
	RING_API_REGISTER("set_pqconninfooption_val",ring_set_pqconninfooption_val);
	RING_API_REGISTER("get_pqconninfooption_label",ring_get_pqconninfooption_label);
	RING_API_REGISTER("set_pqconninfooption_label",ring_set_pqconninfooption_label);
	RING_API_REGISTER("get_pqconninfooption_dispchar",ring_get_pqconninfooption_dispchar);
	RING_API_REGISTER("set_pqconninfooption_dispchar",ring_set_pqconninfooption_dispchar);
	RING_API_REGISTER("get_pqconninfooption_dispsize",ring_get_pqconninfooption_dispsize);
	RING_API_REGISTER("set_pqconninfooption_dispsize",ring_set_pqconninfooption_dispsize);
	RING_API_REGISTER("new_pqprintopt",ring_new_pqprintopt);
	RING_API_REGISTER("new_managed_pqprintopt",ring_new_managed_pqprintopt);
	RING_API_REGISTER("destroy_pqprintopt",ring_destroy_pqprintopt);
	RING_API_REGISTER("get_pqprintopt_header",ring_get_pqprintopt_header);
	RING_API_REGISTER("set_pqprintopt_header",ring_set_pqprintopt_header);
	RING_API_REGISTER("get_pqprintopt_align",ring_get_pqprintopt_align);
	RING_API_REGISTER("set_pqprintopt_align",ring_set_pqprintopt_align);
	RING_API_REGISTER("get_pqprintopt_standard",ring_get_pqprintopt_standard);
	RING_API_REGISTER("set_pqprintopt_standard",ring_set_pqprintopt_standard);
	RING_API_REGISTER("get_pqprintopt_html3",ring_get_pqprintopt_html3);
	RING_API_REGISTER("set_pqprintopt_html3",ring_set_pqprintopt_html3);
	RING_API_REGISTER("get_pqprintopt_expanded",ring_get_pqprintopt_expanded);
	RING_API_REGISTER("set_pqprintopt_expanded",ring_set_pqprintopt_expanded);
	RING_API_REGISTER("get_pqprintopt_pager",ring_get_pqprintopt_pager);
	RING_API_REGISTER("set_pqprintopt_pager",ring_set_pqprintopt_pager);
	RING_API_REGISTER("get_pqprintopt_fieldsep",ring_get_pqprintopt_fieldSep);
	RING_API_REGISTER("set_pqprintopt_fieldsep",ring_set_pqprintopt_fieldSep);
	RING_API_REGISTER("get_pqprintopt_tableopt",ring_get_pqprintopt_tableOpt);
	RING_API_REGISTER("set_pqprintopt_tableopt",ring_set_pqprintopt_tableOpt);
	RING_API_REGISTER("get_pqprintopt_caption",ring_get_pqprintopt_caption);
	RING_API_REGISTER("set_pqprintopt_caption",ring_set_pqprintopt_caption);
	RING_API_REGISTER("get_pqprintopt_fieldname",ring_get_pqprintopt_fieldName);
	RING_API_REGISTER("set_pqprintopt_fieldname",ring_set_pqprintopt_fieldName);
	RING_API_REGISTER("new_pqargblock",ring_new_pqargblock);
	RING_API_REGISTER("new_managed_pqargblock",ring_new_managed_pqargblock);
	RING_API_REGISTER("destroy_pqargblock",ring_destroy_pqargblock);
	RING_API_REGISTER("get_pqargblock_len",ring_get_pqargblock_len);
	RING_API_REGISTER("set_pqargblock_len",ring_set_pqargblock_len);
	RING_API_REGISTER("get_pqargblock_isint",ring_get_pqargblock_isint);
	RING_API_REGISTER("set_pqargblock_isint",ring_set_pqargblock_isint);
	RING_API_REGISTER("get_pqargblock_u_integer",ring_get_pqargblock_u_integer);
	RING_API_REGISTER("set_pqargblock_u_integer",ring_set_pqargblock_u_integer);
	RING_API_REGISTER("get_pqargblock_u_ptr",ring_get_pqargblock_u_ptr);
	RING_API_REGISTER("set_pqargblock_u_ptr",ring_set_pqargblock_u_ptr);
}

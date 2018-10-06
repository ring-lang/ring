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

RING_FUNC(ring_new_pqprintopt)
{
	PQprintOpt *pMyPointer ;
	pMyPointer = (PQprintOpt *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(PQprintOpt)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"PQprintOpt");
}

RING_FUNC(ring_destroy_pqprintopt)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->fieldSep = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqprintopt_tableOpt)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->tableOpt = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqprintopt_caption)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->caption = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_get_pqprintopt_fieldName)
{
	PQprintOpt *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQprintOpt");
	pMyPointer->fieldName = (char *) RING_API_GETCPOINTER(2,"char *");
}

RING_FUNC(ring_new_pqargblock)
{
	PQArgBlock *pMyPointer ;
	pMyPointer = (PQArgBlock *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(PQArgBlock)) ;
	if (pMyPointer == NULL) 
	{
		RING_API_ERROR(RING_OOM);
		return ;
	}
	RING_API_RETCPOINTER(pMyPointer,"PQArgBlock");
}

RING_FUNC(ring_destroy_pqargblock)
{
	PQArgBlock *pMyPointer ;
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA) ;
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	if (pMyPointer != NULL) {
		ring_state_free(((VM *) pPointer)->pRingState,pMyPointer) ;
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
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
	if ( ! RING_API_ISPOINTER(1) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) { 
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	pMyPointer = RING_API_GETCPOINTER(1,"PQArgBlock");
	pMyPointer->u.ptr = (int *) RING_API_GETCPOINTER(2,"int *");
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
		RING_API_RETMANAGEDCPOINTER(pValue,"PGPing",ring_state_free);
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
		RING_API_RETMANAGEDCPOINTER(pValue,"PGPing",ring_state_free);
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Oid *pValue ; 
		pValue = (Oid *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Oid)) ;
		*pValue = PQftable((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",ring_state_free);
	}
}


RING_FUNC(ring_PQftablecol)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(PQftablecol((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQfformat)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(PQfformat((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQftype)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	{
		Oid *pValue ; 
		pValue = (Oid *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Oid)) ;
		*pValue = PQftype((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",ring_state_free);
	}
}


RING_FUNC(ring_PQfmod)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(PQfmod((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQfsize)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
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
	RING_API_RETNUMBER(PQfsize((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2)));
}


RING_FUNC(ring_PQbinaryTuples)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Oid *pValue ; 
		pValue = (Oid *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Oid)) ;
		*pValue = PQparamtype((PGresult *) RING_API_GETCPOINTER(1,"PGresult"), (int ) RING_API_GETNUMBER(2));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",ring_state_free);
	}
}


RING_FUNC(ring_PQprint)
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
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		Oid *pValue ; 
		pValue = (Oid *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(Oid)) ;
		*pValue = PQoidValue((PGresult *) RING_API_GETCPOINTER(1,"PGresult"));
		RING_API_RETMANAGEDCPOINTER(pValue,"Oid",ring_state_free);
	}
}


RING_FUNC(ring_PQoidStatus)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	RING_API_RETSTRING(PQescapeLiteral((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQescapeIdentifier)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETSTRING(PQescapeIdentifier((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (size_t ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQescapeStringConn)
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
	if ( ! RING_API_ISPOINTER(4) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQsendPrepare((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2),RING_API_GETSTRING(3), (int ) RING_API_GETNUMBER(4),(Oid *) RING_API_GETCPOINTER(5,"Oid")));
}


RING_FUNC(ring_PQsendQueryPrepared)
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQcancel((PGcancel *) RING_API_GETCPOINTER(1,"PGcancel"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQrequestCancel)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(6) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	RING_API_RETNUMBER(PQputCopyData((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQputCopyEnd)
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
	RING_API_RETNUMBER(PQputCopyEnd((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQgetCopyData)
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
	RING_API_RETNUMBER(PQgetCopyData((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),(char **) RING_API_GETCPOINTER2POINTER(2,"char"), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQgetline)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(PQgetline((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQgetlineAsync)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(PQgetlineAsync((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQputline)
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
	RING_API_RETNUMBER(PQputline((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2)));
}


RING_FUNC(ring_PQputnbytes)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
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
	RING_API_RETNUMBER(PQputnbytes((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),RING_API_GETSTRING(2), (int ) RING_API_GETNUMBER(3)));
}


RING_FUNC(ring_PQendcopy)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(2) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
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
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		PQnoticeReceiver *pValue ; 
		pValue = (PQnoticeReceiver *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(PQnoticeReceiver)) ;
		*pValue = PQsetNoticeReceiver((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),* (PQnoticeReceiver  *) RING_API_GETCPOINTER(2,"PQnoticeReceiver"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"PQnoticeReceiver"));
		RING_API_RETMANAGEDCPOINTER(pValue,"PQnoticeReceiver",ring_state_free);
	}
}


RING_FUNC(ring_PQsetNoticeProcessor)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	if ( ! RING_API_ISPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISPOINTER(3) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		PQnoticeProcessor *pValue ; 
		pValue = (PQnoticeProcessor *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(PQnoticeProcessor)) ;
		*pValue = PQsetNoticeProcessor((PGconn *) RING_API_GETCPOINTER(1,"PGconn"),* (PQnoticeProcessor  *) RING_API_GETCPOINTER(2,"PQnoticeProcessor"),(void *) RING_API_GETCPOINTER(3,"void"));
	if (RING_API_ISCPOINTERNOTASSIGNED(2))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(2,"PQnoticeProcessor"));
		RING_API_RETMANAGEDCPOINTER(pValue,"PQnoticeProcessor",ring_state_free);
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
	ring_vm_funcregister("pqresstatus",ring_PQresStatus);
	ring_vm_funcregister("pqresulterrormessage",ring_PQresultErrorMessage);
	ring_vm_funcregister("pqresulterrorfield",ring_PQresultErrorField);
	ring_vm_funcregister("pqclear",ring_PQclear);
	ring_vm_funcregister("pqntuples",ring_PQntuples);
	ring_vm_funcregister("pqnfields",ring_PQnfields);
	ring_vm_funcregister("pqfname",ring_PQfname);
	ring_vm_funcregister("pqfnumber",ring_PQfnumber);
	ring_vm_funcregister("pqftable",ring_PQftable);
	ring_vm_funcregister("pqftablecol",ring_PQftablecol);
	ring_vm_funcregister("pqfformat",ring_PQfformat);
	ring_vm_funcregister("pqftype",ring_PQftype);
	ring_vm_funcregister("pqfmod",ring_PQfmod);
	ring_vm_funcregister("pqfsize",ring_PQfsize);
	ring_vm_funcregister("pqbinarytuples",ring_PQbinaryTuples);
	ring_vm_funcregister("pqgetvalue",ring_PQgetvalue);
	ring_vm_funcregister("pqgetisnull",ring_PQgetisnull);
	ring_vm_funcregister("pqgetlength",ring_PQgetlength);
	ring_vm_funcregister("pqnparams",ring_PQnparams);
	ring_vm_funcregister("pqparamtype",ring_PQparamtype);
	ring_vm_funcregister("pqprint",ring_PQprint);
	ring_vm_funcregister("pqcmdstatus",ring_PQcmdStatus);
	ring_vm_funcregister("pqcmdtuples",ring_PQcmdTuples);
	ring_vm_funcregister("pqoidvalue",ring_PQoidValue);
	ring_vm_funcregister("pqoidstatus",ring_PQoidStatus);
	ring_vm_funcregister("pqescapeliteral",ring_PQescapeLiteral);
	ring_vm_funcregister("pqescapeidentifier",ring_PQescapeIdentifier);
	ring_vm_funcregister("pqescapestringconn",ring_PQescapeStringConn);
	ring_vm_funcregister("pqescapestring",ring_PQescapeString);
	ring_vm_funcregister("pqescapebyteaconn",ring_PQescapeByteaConn);
	ring_vm_funcregister("pqescapebytea",ring_PQescapeBytea);
	ring_vm_funcregister("pqunescapebytea",ring_PQunescapeBytea);
	ring_vm_funcregister("pqsendquery",ring_PQsendQuery);
	ring_vm_funcregister("pqsendqueryparams",ring_PQsendQueryParams);
	ring_vm_funcregister("pqsendprepare",ring_PQsendPrepare);
	ring_vm_funcregister("pqsendqueryprepared",ring_PQsendQueryPrepared);
	ring_vm_funcregister("pqsenddescribeprepared",ring_PQsendDescribePrepared);
	ring_vm_funcregister("pqsenddescribeportal",ring_PQsendDescribePortal);
	ring_vm_funcregister("pqgetresult",ring_PQgetResult);
	ring_vm_funcregister("pqconsumeinput",ring_PQconsumeInput);
	ring_vm_funcregister("pqisbusy",ring_PQisBusy);
	ring_vm_funcregister("pqsetnonblocking",ring_PQsetnonblocking);
	ring_vm_funcregister("pqisnonblocking",ring_PQisnonblocking);
	ring_vm_funcregister("pqflush",ring_PQflush);
	ring_vm_funcregister("pqsetsinglerowmode",ring_PQsetSingleRowMode);
	ring_vm_funcregister("pqgetcancel",ring_PQgetCancel);
	ring_vm_funcregister("pqfreecancel",ring_PQfreeCancel);
	ring_vm_funcregister("pqcancel",ring_PQcancel);
	ring_vm_funcregister("pqrequestcancel",ring_PQrequestCancel);
	ring_vm_funcregister("pqfn",ring_PQfn);
	ring_vm_funcregister("pqnotifies",ring_PQnotifies);
	ring_vm_funcregister("pqputcopydata",ring_PQputCopyData);
	ring_vm_funcregister("pqputcopyend",ring_PQputCopyEnd);
	ring_vm_funcregister("pqgetcopydata",ring_PQgetCopyData);
	ring_vm_funcregister("pqgetline",ring_PQgetline);
	ring_vm_funcregister("pqgetlineasync",ring_PQgetlineAsync);
	ring_vm_funcregister("pqputline",ring_PQputline);
	ring_vm_funcregister("pqputnbytes",ring_PQputnbytes);
	ring_vm_funcregister("pqendcopy",ring_PQendcopy);
	ring_vm_funcregister("pqclientencoding",ring_PQclientEncoding);
	ring_vm_funcregister("pg_encoding_to_char",ring_pg_encoding_to_char);
	ring_vm_funcregister("pqsetclientencoding",ring_PQsetClientEncoding);
	ring_vm_funcregister("pqtrace",ring_PQtrace);
	ring_vm_funcregister("pquntrace",ring_PQuntrace);
	ring_vm_funcregister("pqfreemem",ring_PQfreemem);
	ring_vm_funcregister("pqconninfofree",ring_PQconninfoFree);
	ring_vm_funcregister("pqencryptpasswordconn",ring_PQencryptPasswordConn);
	ring_vm_funcregister("pqencryptpassword",ring_PQencryptPassword);
	ring_vm_funcregister("pqmakeemptypgresult",ring_PQmakeEmptyPGresult);
	ring_vm_funcregister("pqfireresultcreateevents",ring_PQfireResultCreateEvents);
	ring_vm_funcregister("pqcopyresult",ring_PQcopyResult);
	ring_vm_funcregister("pqsetresultattrs",ring_PQsetResultAttrs);
	ring_vm_funcregister("pqsetvalue",ring_PQsetvalue);
	ring_vm_funcregister("pqresultalloc",ring_PQresultAlloc);
	ring_vm_funcregister("pqlibversion",ring_PQlibVersion);
	ring_vm_funcregister("pqsetnoticereceiver",ring_PQsetNoticeReceiver);
	ring_vm_funcregister("pqsetnoticeprocessor",ring_PQsetNoticeProcessor);
	ring_vm_funcregister("pqinitopenssl",ring_PQinitOpenSSL);
	ring_vm_funcregister("pqinitssl",ring_PQinitSSL);
	ring_vm_funcregister("pqisthreadsafe",ring_PQisthreadsafe);
	ring_vm_funcregister("get_connection_started",ring_get_connection_started);
	ring_vm_funcregister("get_connection_made",ring_get_connection_made);
	ring_vm_funcregister("get_connection_awaiting_response",ring_get_connection_awaiting_response);
	ring_vm_funcregister("get_connection_auth_ok",ring_get_connection_auth_ok);
	ring_vm_funcregister("get_connection_ssl_startup",ring_get_connection_ssl_startup);
	ring_vm_funcregister("get_connection_setenv",ring_get_connection_setenv);
	ring_vm_funcregister("get_connection_ok",ring_get_connection_ok);
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
	ring_vm_funcregister("get_pg_diag_severity",ring_get_pg_diag_severity);
	ring_vm_funcregister("get_pg_diag_sqlstate",ring_get_pg_diag_sqlstate);
	ring_vm_funcregister("get_pg_diag_message_primary",ring_get_pg_diag_message_primary);
	ring_vm_funcregister("get_pg_diag_message_detail",ring_get_pg_diag_message_detail);
	ring_vm_funcregister("get_pg_diag_message_hint",ring_get_pg_diag_message_hint);
	ring_vm_funcregister("get_pg_diag_statement_position",ring_get_pg_diag_statement_position);
	ring_vm_funcregister("get_pg_diag_internal_position",ring_get_pg_diag_internal_position);
	ring_vm_funcregister("get_pg_diag_internal_query",ring_get_pg_diag_internal_query);
	ring_vm_funcregister("get_pg_diag_context",ring_get_pg_diag_context);
	ring_vm_funcregister("get_pg_diag_schema_name",ring_get_pg_diag_schema_name);
	ring_vm_funcregister("get_pg_diag_table_name",ring_get_pg_diag_table_name);
	ring_vm_funcregister("get_pg_diag_column_name",ring_get_pg_diag_column_name);
	ring_vm_funcregister("get_pg_diag_datatype_name",ring_get_pg_diag_datatype_name);
	ring_vm_funcregister("get_pg_diag_constraint_name",ring_get_pg_diag_constraint_name);
	ring_vm_funcregister("get_pg_diag_source_file",ring_get_pg_diag_source_file);
	ring_vm_funcregister("get_pg_diag_source_line",ring_get_pg_diag_source_line);
	ring_vm_funcregister("get_pg_diag_source_function",ring_get_pg_diag_source_function);
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
	ring_vm_funcregister("new_pqprintopt",ring_new_pqprintopt);
	ring_vm_funcregister("destroy_pqprintopt",ring_destroy_pqprintopt);
	ring_vm_funcregister("get_pqprintopt_header",ring_get_pqprintopt_header);
	ring_vm_funcregister("set_pqprintopt_header",ring_set_pqprintopt_header);
	ring_vm_funcregister("get_pqprintopt_align",ring_get_pqprintopt_align);
	ring_vm_funcregister("set_pqprintopt_align",ring_set_pqprintopt_align);
	ring_vm_funcregister("get_pqprintopt_standard",ring_get_pqprintopt_standard);
	ring_vm_funcregister("set_pqprintopt_standard",ring_set_pqprintopt_standard);
	ring_vm_funcregister("get_pqprintopt_html3",ring_get_pqprintopt_html3);
	ring_vm_funcregister("set_pqprintopt_html3",ring_set_pqprintopt_html3);
	ring_vm_funcregister("get_pqprintopt_expanded",ring_get_pqprintopt_expanded);
	ring_vm_funcregister("set_pqprintopt_expanded",ring_set_pqprintopt_expanded);
	ring_vm_funcregister("get_pqprintopt_pager",ring_get_pqprintopt_pager);
	ring_vm_funcregister("set_pqprintopt_pager",ring_set_pqprintopt_pager);
	ring_vm_funcregister("get_pqprintopt_fieldSep",ring_get_pqprintopt_fieldSep);
	ring_vm_funcregister("set_pqprintopt_fieldSep",ring_set_pqprintopt_fieldSep);
	ring_vm_funcregister("get_pqprintopt_tableOpt",ring_get_pqprintopt_tableOpt);
	ring_vm_funcregister("set_pqprintopt_tableOpt",ring_set_pqprintopt_tableOpt);
	ring_vm_funcregister("get_pqprintopt_caption",ring_get_pqprintopt_caption);
	ring_vm_funcregister("set_pqprintopt_caption",ring_set_pqprintopt_caption);
	ring_vm_funcregister("get_pqprintopt_fieldName",ring_get_pqprintopt_fieldName);
	ring_vm_funcregister("set_pqprintopt_fieldName",ring_set_pqprintopt_fieldName);
	ring_vm_funcregister("new_pqargblock",ring_new_pqargblock);
	ring_vm_funcregister("destroy_pqargblock",ring_destroy_pqargblock);
	ring_vm_funcregister("get_pqargblock_len",ring_get_pqargblock_len);
	ring_vm_funcregister("set_pqargblock_len",ring_set_pqargblock_len);
	ring_vm_funcregister("get_pqargblock_isint",ring_get_pqargblock_isint);
	ring_vm_funcregister("set_pqargblock_isint",ring_set_pqargblock_isint);
	ring_vm_funcregister("get_pqargblock_u_integer",ring_get_pqargblock_u_integer);
	ring_vm_funcregister("set_pqargblock_u_integer",ring_set_pqargblock_u_integer);
	ring_vm_funcregister("get_pqargblock_u_ptr",ring_get_pqargblock_u_ptr);
	ring_vm_funcregister("set_pqargblock_u_ptr",ring_set_pqargblock_u_ptr);
}

#include "ring.h"

/* Copyright (c) 2022 Mahmoud Fayed <msfclipper@yahoo.com> */

#include "lib/cJSON.h"
RING_FUNC(ring_get_cjson_version_major)
{
	RING_API_RETNUMBER(CJSON_VERSION_MAJOR);
}

RING_FUNC(ring_get_cjson_version_minor)
{
	RING_API_RETNUMBER(CJSON_VERSION_MINOR);
}

RING_FUNC(ring_get_cjson_version_patch)
{
	RING_API_RETNUMBER(CJSON_VERSION_PATCH);
}

RING_FUNC(ring_get_cjson_invalid)
{
	RING_API_RETNUMBER(cJSON_Invalid);
}

RING_FUNC(ring_get_cjson_false)
{
	RING_API_RETNUMBER(cJSON_False);
}

RING_FUNC(ring_get_cjson_true)
{
	RING_API_RETNUMBER(cJSON_True);
}

RING_FUNC(ring_get_cjson_null)
{
	RING_API_RETNUMBER(cJSON_NULL);
}

RING_FUNC(ring_get_cjson_number)
{
	RING_API_RETNUMBER(cJSON_Number);
}

RING_FUNC(ring_get_cjson_string)
{
	RING_API_RETNUMBER(cJSON_String);
}

RING_FUNC(ring_get_cjson_array)
{
	RING_API_RETNUMBER(cJSON_Array);
}

RING_FUNC(ring_get_cjson_object)
{
	RING_API_RETNUMBER(cJSON_Object);
}

RING_FUNC(ring_get_cjson_raw)
{
	RING_API_RETNUMBER(cJSON_Raw);
}

RING_FUNC(ring_get_cjson_isreference)
{
	RING_API_RETNUMBER(cJSON_IsReference);
}

RING_FUNC(ring_get_cjson_stringisconst)
{
	RING_API_RETNUMBER(cJSON_StringIsConst);
}

RING_FUNC(ring_get_cjson_nesting_limit)
{
	RING_API_RETNUMBER(CJSON_NESTING_LIMIT);
}


RING_FUNC(ring_cJSON_Version)
{
	if ( RING_API_PARACOUNT != 0 ) {
		RING_API_ERROR(RING_API_BADPARACOUNT);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	RING_API_RETSTRING(cJSON_Version());
}


RING_FUNC(ring_cJSON_InitHooks)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_InitHooks((cJSON_Hooks *) RING_API_GETCPOINTER(1,"cJSON_Hooks"));
}


RING_FUNC(ring_cJSON_Parse)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_Parse(RING_API_GETSTRING(1)),"cJSON");
}


RING_FUNC(ring_cJSON_ParseWithLength)
{
	if ( RING_API_PARACOUNT != 2 ) {
		RING_API_ERROR(RING_API_MISS2PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_ParseWithLength(RING_API_GETSTRING(1), (size_t ) RING_API_GETNUMBER(2)),"cJSON");
}


RING_FUNC(ring_cJSON_ParseWithOpts)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISCPOINTER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETCPOINTER(cJSON_ParseWithOpts(RING_API_GETSTRING(1),(char **) RING_API_GETCPOINTER2POINTER(2,"char"),* (cJSON_bool  *) RING_API_GETCPOINTER(3,"cJSON_bool")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"cJSON_bool"));
}


RING_FUNC(ring_cJSON_ParseWithLengthOpts)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISSTRING(1) ) {
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
	RING_API_RETCPOINTER(cJSON_ParseWithLengthOpts(RING_API_GETSTRING(1), (size_t ) RING_API_GETNUMBER(2),(char **) RING_API_GETCPOINTER2POINTER(3,"char"),* (cJSON_bool  *) RING_API_GETCPOINTER(4,"cJSON_bool")),"cJSON");
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"cJSON_bool"));
}


RING_FUNC(ring_cJSON_Print)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(cJSON_Print((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_PrintUnformatted)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(cJSON_PrintUnformatted((cJSON *) RING_API_GETCPOINTER(1,"cJSON")));
}


RING_FUNC(ring_cJSON_PrintBuffered)
{
	if ( RING_API_PARACOUNT != 3 ) {
		RING_API_ERROR(RING_API_MISS3PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISNUMBER(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	RING_API_RETSTRING(cJSON_PrintBuffered((cJSON *) RING_API_GETCPOINTER(1,"cJSON"), (int ) RING_API_GETNUMBER(2),* (cJSON_bool  *) RING_API_GETCPOINTER(3,"cJSON_bool")));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"cJSON_bool"));
}


RING_FUNC(ring_cJSON_PrintPreallocated)
{
	if ( RING_API_PARACOUNT != 4 ) {
		RING_API_ERROR(RING_API_MISS4PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	if ( ! RING_API_ISSTRING(2) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	{
		cJSON_bool *pValue ; 
		pValue = (cJSON_bool *) ring_state_malloc(((VM *) pPointer)->pRingState,sizeof(cJSON_bool)) ;
		*pValue = cJSON_PrintPreallocated((cJSON *) RING_API_GETCPOINTER(1,"cJSON"),RING_API_GETSTRING(2),* (const int  *) RING_API_GETCPOINTER(3,"const int"),* (const cJSON_bool  *) RING_API_GETCPOINTER(4,"const cJSON_bool"));
	if (RING_API_ISCPOINTERNOTASSIGNED(3))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(3,"int"));
	if (RING_API_ISCPOINTERNOTASSIGNED(4))
		ring_state_free(((VM *) pPointer)->pRingState,RING_API_GETCPOINTER(4,"cJSON_bool"));
		RING_API_RETMANAGEDCPOINTER(pValue,"cJSON_bool",ring_state_free);
	}
}


RING_FUNC(ring_cJSON_Delete)
{
	if ( RING_API_PARACOUNT != 1 ) {
		RING_API_ERROR(RING_API_MISS1PARA);
		return ;
	}
	RING_API_IGNORECPOINTERTYPE ;
	if ( ! RING_API_ISCPOINTER(1) ) {
		RING_API_ERROR(RING_API_BADPARATYPE);
		return ;
	}
	cJSON_Delete((cJSON *) RING_API_GETCPOINTER(1,"cJSON"));
}

RING_API void ringlib_init(RingState *pRingState)
{
	ring_vm_funcregister("cjson_version",ring_cJSON_Version);
	ring_vm_funcregister("cjson_inithooks",ring_cJSON_InitHooks);
	ring_vm_funcregister("cjson_parse",ring_cJSON_Parse);
	ring_vm_funcregister("cjson_parsewithlength",ring_cJSON_ParseWithLength);
	ring_vm_funcregister("cjson_parsewithopts",ring_cJSON_ParseWithOpts);
	ring_vm_funcregister("cjson_parsewithlengthopts",ring_cJSON_ParseWithLengthOpts);
	ring_vm_funcregister("cjson_print",ring_cJSON_Print);
	ring_vm_funcregister("cjson_printunformatted",ring_cJSON_PrintUnformatted);
	ring_vm_funcregister("cjson_printbuffered",ring_cJSON_PrintBuffered);
	ring_vm_funcregister("cjson_printpreallocated",ring_cJSON_PrintPreallocated);
	ring_vm_funcregister("cjson_delete",ring_cJSON_Delete);
	ring_vm_funcregister("get_cjson_version_major",ring_get_cjson_version_major);
	ring_vm_funcregister("get_cjson_version_minor",ring_get_cjson_version_minor);
	ring_vm_funcregister("get_cjson_version_patch",ring_get_cjson_version_patch);
	ring_vm_funcregister("get_cjson_invalid",ring_get_cjson_invalid);
	ring_vm_funcregister("get_cjson_false",ring_get_cjson_false);
	ring_vm_funcregister("get_cjson_true",ring_get_cjson_true);
	ring_vm_funcregister("get_cjson_null",ring_get_cjson_null);
	ring_vm_funcregister("get_cjson_number",ring_get_cjson_number);
	ring_vm_funcregister("get_cjson_string",ring_get_cjson_string);
	ring_vm_funcregister("get_cjson_array",ring_get_cjson_array);
	ring_vm_funcregister("get_cjson_object",ring_get_cjson_object);
	ring_vm_funcregister("get_cjson_raw",ring_get_cjson_raw);
	ring_vm_funcregister("get_cjson_isreference",ring_get_cjson_isreference);
	ring_vm_funcregister("get_cjson_stringisconst",ring_get_cjson_stringisconst);
	ring_vm_funcregister("get_cjson_nesting_limit",ring_get_cjson_nesting_limit);
}

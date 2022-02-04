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

RING_API void ringlib_init(RingState *pRingState)
{
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

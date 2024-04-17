/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: coreh.hxx
 *
 */

/* Undocumented (hidden) Core library types */

#ifndef __COREH_HXX__
#define __COREH_HXX__

#include "core.hxx"

typedef enum _dtype_t
{
    ekDTYPE_BOOL,
    ekDTYPE_INT8,
    ekDTYPE_INT16,
    ekDTYPE_INT32,
    ekDTYPE_INT64,
    ekDTYPE_UINT8,
    ekDTYPE_UINT16,
    ekDTYPE_UINT32,
    ekDTYPE_UINT64,
    ekDTYPE_REAL32,
    ekDTYPE_REAL64,
    ekDTYPE_ENUM,
    ekDTYPE_STRING,
    ekDTYPE_STRING_PTR,
    ekDTYPE_ARRAY,
    ekDTYPE_ARRPTR,
    ekDTYPE_OBJECT,
    ekDTYPE_OBJECT_PTR,
    ekDTYPE_OBJECT_OPAQUE,
    ekDTYPE_UNKNOWN
} dtype_t;

typedef struct _dbind_t DBind;
typedef struct _stbind_t StBind;

typedef void *(*FPtr_data)(const byte_t *data, const uint32_t size);
#define FUNC_CHECK_DATA(func, type) \
    (void)((type * (*)(const byte_t *, const uint32_t)) func == func)

typedef Buffer *(*FPtr_buffer)(const void *obj);
#define FUNC_CHECK_BUFFER(func, type) \
    (void)((Buffer * (*)(const type *)) func == func)

typedef void *(*FPtr_create_from_data)(const byte_t *data, const uint32_t size);
#define FUNC_CHECK_CREATE_FROM_DATA(func, type) \
    (void)((type * (*)(const byte_t *, const uint32_t)) func == func)

#endif
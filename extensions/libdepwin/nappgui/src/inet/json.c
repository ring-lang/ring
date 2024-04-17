/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: json.c
 *
 */

/* Json parser */

#include "json.h"
#include "base64.h"
#include <core/arrpt.h>
#include <core/dbind.h>
#include <core/dbindh.h>
#include <core/heap.h>
#include <core/stream.h>
#include <core/strings.h>
#include <osbs/log.h>
#include <sewer/bmath.h>
#include <sewer/bmem.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

typedef enum _jtoken_t
{
    i_ekTRUE,
    i_ekFALSE,
    i_ekNULL,
    i_ekNUMBER,
    i_ekSTRING,
    i_ekOPEN_ARRAY,
    i_ekCLOSE_ARRAY,
    i_ekOPEN_OBJECT,
    i_ekCLOSE_OBJECT,
    i_ekCOMMA,
    i_ekCOLON,
    i_ekUNKNOWN
} jtoken_t;

typedef struct i_parser_t i_Parser;

struct i_parser_t
{
    Stream *stm;
    jtoken_t token;
    bool_t minus;
    uint32_t col;
    uint32_t row;
    uint32_t lexsize;
    const char_t *lexeme;
    char_t number[128];
};

/*---------------------------------------------------------------------------*/

#define obj_member(obj, offset, type) *((type *)((byte_t *)(obj) + (offset)))
static void *i_create_type(i_Parser *parser, const char_t *type);
static bool_t i_jump_value(i_Parser *parser);
static bool_t i_parse_object(i_Parser *parser, const char_t *subtype, void *object);
static bool_t i_parse_value(i_Parser *parser, const DBind *dbind, dtype_t type, const char_t *subtype, void *object);
static void i_write_type(Stream *stm, dtype_t type, const char_t *subtype, const void *data, const bool_t doubleptr);
static void i_write_object(Stream *stm, const void *object, const char_t *type);
static void i_write_opaque(Stream *stm, const void *object, const char_t *type);

/*---------------------------------------------------------------------------*/

static bool_t i_error(const bool_t cond, const bool_t fatal, i_Parser *parser, const char_t *errmsg)
{
    cassert_no_null(parser);

    if (cond == FALSE)
    {
        if (parser->lexeme != NULL && parser->lexsize < 128)
            log_printf("JSON(%d:%d)-%s (%s).", parser->row, parser->col, errmsg, parser->lexeme);
        else
            log_printf("JSON(%d:%d)-%s.", parser->row, parser->col, errmsg);
    }

    if (cond == FALSE && fatal == TRUE)
        return FALSE;
    else
        return TRUE;
}

/*---------------------------------------------------------------------------*/

static void i_new_token(i_Parser *parser)
{
    ltoken_t token;
    cassert_no_null(parser);
    token = stm_read_token(parser->stm);
    parser->row = stm_token_col(parser->stm);
    parser->col = stm_token_row(parser->stm);
    parser->lexeme = stm_token_lexeme(parser->stm, &parser->lexsize);
    switch (token)
    {
    case ekTIDENT:
        if (str_equ_c(parser->lexeme, "true") == TRUE)
            parser->token = i_ekTRUE;
        else if (str_equ_c(parser->lexeme, "false") == TRUE)
            parser->token = i_ekFALSE;
        else if (str_equ_c(parser->lexeme, "null") == TRUE)
            parser->token = i_ekNULL;
        else
            parser->token = i_ekUNKNOWN;
        break;

    case ekTINTEGER:
    case ekTREAL:
        parser->token = i_ekNUMBER;
        if (parser->minus == TRUE)
        {
            bstd_sprintf(parser->number, sizeof(parser->number), "-%s", parser->lexeme);
            parser->minus = FALSE;
        }
        else
        {
            str_copy_c(parser->number, sizeof(parser->number), parser->lexeme);
        }
        break;

    case ekTSTRING:
        cassert(parser->lexeme[0] == '\"');
        cassert(parser->lexeme[parser->lexsize - 1] == '\"');
        ((char_t *)parser->lexeme)[parser->lexsize - 1] = '\0';
        parser->lexeme += 1;
        parser->lexsize -= 2;
        parser->token = i_ekSTRING;
        break;

    case ekTOPENBRAC:
        parser->token = i_ekOPEN_ARRAY;
        break;

    case ekTCLOSBRAC:
        parser->token = i_ekCLOSE_ARRAY;
        break;

    case ekTOPENCURL:
        parser->token = i_ekOPEN_OBJECT;
        break;

    case ekTCLOSCURL:
        parser->token = i_ekCLOSE_OBJECT;
        break;

    case ekTCOMMA:
        parser->token = i_ekCOMMA;
        break;

    case ekTCOLON:
        parser->token = i_ekCOLON;
        break;

    case ekTMINUS:
        cassert(parser->minus == FALSE);
        parser->minus = TRUE;
        i_new_token(parser);
        break;

    case ekTSLCOM:
    case ekTMLCOM:
    case ekTSPACE:
    case ekTEOL:
    case ekTLESS:
    case ekTGREAT:
    case ekTPERIOD:
    case ekTSCOLON:
    case ekTOPENPAR:
    case ekTCLOSPAR:
    case ekTPLUS:
    case ekTASTERK:
    case ekTEQUALS:
    case ekTDOLLAR:
    case ekTPERCENT:
    case ekTPOUND:
    case ekTAMPER:
    case ekTAPOST:
    case ekTQUOTE:
    case ekTCIRCUM:
    case ekTTILDE:
    case ekTEXCLA:
    case ekTQUEST:
    case ekTVLINE:
    case ekTSLASH:
    case ekTBSLASH:
    case ekTAT:
    case ekTOCTAL:
    case ekTHEX:
    case ekTUNDEF:
    case ekTCORRUP:
    case ekTEOF:
    case ekTRESERVED:
    default:
        parser->token = i_ekUNKNOWN;
        break;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_jump_array(i_Parser *parser)
{
    bool_t ok = i_jump_value(parser);

    if (ok == FALSE)
    {
        /* Empty array */
        if (parser->token == i_ekCLOSE_ARRAY)
            return TRUE;
        else
            return i_error(FALSE, TRUE, parser, "Unexpected token jumping array");
    }

    for (;;)
    {
        i_new_token(parser);
        if (parser->token == i_ekCLOSE_ARRAY)
            return TRUE;

        if (parser->token != i_ekCOMMA)
            return i_error(FALSE, TRUE, parser, "Comma expected jumping array");

        ok = i_jump_value(parser);
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_jump_object(i_Parser *parser)
{
    bool_t comma_state = FALSE;
    /* For all object members */
    for (;;)
    {
        /* '}' */
        i_new_token(parser);
        if (parser->token == i_ekCLOSE_OBJECT)
        {
            if (comma_state == FALSE)
                return TRUE;
            else
                return i_error(FALSE, TRUE, parser, "Unexpected Json '}' (member opened)");
        }

        if (parser->token == i_ekCOMMA)
        {
            if (comma_state == FALSE)
            {
                comma_state = TRUE;
                continue;
            }
            else
            {
                return i_error(FALSE, TRUE, parser, "Unexpected Json ','");
            }
        }

        /* "member_name" */
        if (parser->token != i_ekSTRING)
            return i_error(FALSE, TRUE, parser, "Expected Json 'string' (member name)");

        /* ":" */
        i_new_token(parser);
        if (parser->token != i_ekCOLON)
            return i_error(FALSE, TRUE, parser, "Expected Json ':' (object member)");

        /* "member_value" */
        if (i_jump_value(parser) == TRUE)
            comma_state = FALSE;
        else
            return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_jump_value(i_Parser *parser)
{
    i_new_token(parser);
    switch (parser->token)
    {
    case i_ekTRUE:
    case i_ekFALSE:
    case i_ekNULL:
    case i_ekNUMBER:
    case i_ekSTRING:
        return TRUE;
    case i_ekOPEN_ARRAY:
        return i_jump_array(parser);
    case i_ekOPEN_OBJECT:
        return i_jump_object(parser);
    case i_ekCLOSE_ARRAY:
        return FALSE;
    case i_ekCLOSE_OBJECT:
        return i_error(FALSE, TRUE, parser, "Unexpected Json token '}'");
    case i_ekCOMMA:
        return i_error(FALSE, TRUE, parser, "Unexpected Json token ','");
    case i_ekCOLON:
        return i_error(FALSE, TRUE, parser, "Unexpected Json token ':'");
    case i_ekUNKNOWN:
        return i_error(FALSE, TRUE, parser, "Unknown Json token");
        cassert_default();
    }

    parser->minus = FALSE;
    return i_error(FALSE, TRUE, parser, "Fatal Json parsing error");
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_array(i_Parser *parser, dtype_t type, const char_t *subtype, Array *array)
{
    byte_t *obj;
    bool_t ok;

    obj = array_insert(array, UINT32_MAX, 1);
    dbind_init_imp(obj, subtype);

    ok = i_parse_value(parser, NULL, type, subtype, obj);

    if (ok == FALSE)
    {
        /* Empty array */
        if (parser->token == i_ekCLOSE_ARRAY)
        {
            uint32_t s = array_size(array);
            byte_t *elem = array_get(array, s - 1);
            dbind_remove_imp(elem, subtype);
            array_delete(array, s - 1, 1, NULL);
            return TRUE;
        }
        else
        {
            return i_error(FALSE, TRUE, parser, "Unexpected token in ArrSt");
        }
    }

    for (;;)
    {
        i_new_token(parser);
        if (parser->token == i_ekCLOSE_ARRAY)
            return TRUE;

        if (parser->token != i_ekCOMMA)
            return i_error(FALSE, TRUE, parser, "Comma expected in ArrSt");

        obj = array_insert(array, UINT32_MAX, 1);
        dbind_init_imp(obj, subtype);
        ok = i_parse_value(parser, NULL, type, subtype, obj);
        if (ok == FALSE)
            return i_error(FALSE, TRUE, parser, "Object can't be initialized ArrSt");
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_arrptr(i_Parser *parser, const char_t *subtype, Array *array)
{
    void *obj = i_create_type(parser, subtype);

    if (obj == NULL)
    {
        /* Empty array */
        if (parser->token == i_ekCLOSE_ARRAY)
            return TRUE;
        else
            return i_error(FALSE, TRUE, parser, "Unexpected token in ArrPt");
    }

    for (;;)
    {
        void **elem = (void **)array_insert(array, UINT32_MAX, 1);
        *elem = obj;

        i_new_token(parser);
        if (parser->token == i_ekCLOSE_ARRAY)
            return TRUE;

        if (parser->token != i_ekCOMMA)
            return i_error(FALSE, TRUE, parser, "Comma expected in ArrPt");

        obj = i_create_type(parser, subtype);
        if (obj == NULL)
            return i_error(FALSE, TRUE, parser, "Object can't be created ArrPt");
    }
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_value(i_Parser *parser, const DBind *dbind, dtype_t type, const char_t *subtype, void *object)
{
    i_new_token(parser);
    switch (parser->token)
    {
    case i_ekTRUE:
        if (type == ekDTYPE_BOOL)
        {
            *((bool_t *)object) = TRUE;
            return TRUE;
        }
        return i_error(FALSE, TRUE, parser, "Boolean expected");

    case i_ekFALSE:
        if (type == ekDTYPE_BOOL)
        {
            *((bool_t *)object) = FALSE;
            return TRUE;
        }
        return i_error(FALSE, TRUE, parser, "Boolean expected");

    case i_ekNULL:
        switch (type)
        {
        case ekDTYPE_OBJECT:
            dbind_remove_imp((byte_t *)object, subtype);
            return TRUE;

        case ekDTYPE_OBJECT_PTR:
            *(void **)object = NULL;
            return TRUE;

        case ekDTYPE_STRING_PTR:
        case ekDTYPE_STRING:
            cassert(*((String **)object) == NULL);
            *((String **)object) = NULL;
            return TRUE;

        case ekDTYPE_ARRAY:
        case ekDTYPE_ARRPTR:
            *((Array **)object) = NULL;
            return TRUE;

        case ekDTYPE_BOOL:
        case ekDTYPE_INT8:
        case ekDTYPE_INT16:
        case ekDTYPE_INT32:
        case ekDTYPE_INT64:
        case ekDTYPE_UINT8:
        case ekDTYPE_UINT16:
        case ekDTYPE_UINT32:
        case ekDTYPE_UINT64:
        case ekDTYPE_REAL32:
        case ekDTYPE_REAL64:
        case ekDTYPE_ENUM:
        case ekDTYPE_OBJECT_OPAQUE:
        case ekDTYPE_UNKNOWN:
        default:
            return i_error(FALSE, TRUE, parser, "Unexpected Json 'null'");
        }

    case i_ekNUMBER:
        switch (type)
        {
        case ekDTYPE_INT8:
        {
            bool_t err;
            *((int8_t *)object) = str_to_i8(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int8_t");
        }

        case ekDTYPE_INT16:
        {
            bool_t err;
            *((int16_t *)object) = str_to_i16(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int16_t");
        }

        case ekDTYPE_INT32:
        {
            bool_t err;
            *((int32_t *)object) = str_to_i32(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int32_t");
        }

        case ekDTYPE_INT64:
        {
            bool_t err;
            *((int64_t *)object) = str_to_i64(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int64_t");
        }

        case ekDTYPE_UINT8:
        {
            bool_t err;
            *((uint8_t *)object) = str_to_u8(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint8_t");
        }

        case ekDTYPE_UINT16:
        {
            bool_t err;
            *((uint16_t *)object) = str_to_u16(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint16_t");
        }

        case ekDTYPE_UINT32:
        {
            bool_t err;
            *((uint32_t *)object) = str_to_u32(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint32_t");
        }

        case ekDTYPE_UINT64:
        {
            bool_t err;
            *((uint64_t *)object) = str_to_u64(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint64_t");
        }

        case ekDTYPE_REAL32:
            if (dbind != NULL)
            {
                *((real32_t *)object) = dbind_string_to_real32(dbind, *((real32_t *)object), parser->number);
                return TRUE;
            }
            else
            {
                bool_t err;
                *((real32_t *)object) = str_to_r32(parser->number, &err);
                return i_error(!err, FALSE, parser, "Cannot cast to real32_t");
            }
            break;

        case ekDTYPE_REAL64:
            if (dbind != NULL)
            {
                *((real64_t *)object) = dbind_string_to_real64(dbind, *((real64_t *)object), parser->number);
                return TRUE;
            }
            else
            {
                bool_t err;
                *((real64_t *)object) = str_to_r64(parser->number, &err);
                return i_error(!err, FALSE, parser, "Cannot cast to real64_t");
            }
            break;

        case ekDTYPE_ENUM:
        {
            bool_t err;
            *((int32_t *)object) = str_to_i32(parser->number, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to enum");
        }

        case ekDTYPE_BOOL:
        case ekDTYPE_STRING:
        case ekDTYPE_STRING_PTR:
        case ekDTYPE_ARRAY:
        case ekDTYPE_ARRPTR:
        case ekDTYPE_OBJECT:
        case ekDTYPE_OBJECT_PTR:
        case ekDTYPE_OBJECT_OPAQUE:
        case ekDTYPE_UNKNOWN:
        default:
            return i_error(FALSE, TRUE, parser, "Unexpected Json 'number'");
        }

    case i_ekSTRING:
        switch (type)
        {

        case ekDTYPE_STRING_PTR:
        case ekDTYPE_STRING:
            str_upd((String **)object, parser->lexeme);
            return TRUE;

        case ekDTYPE_OBJECT_OPAQUE:
        {
            uint32_t dsize = b64_decoded_size(parser->lexsize);
            byte_t *data = heap_malloc(dsize, "JsonB64Decode");
            uint32_t size = b64_decode(parser->lexeme, parser->lexsize, data);
            const StBind *stbind = dbind_stbind(subtype);
            dbind_stbind_opaque(stbind, data, size, (void **)object);
            heap_free(&data, dsize, "JsonB64Decode");
            return TRUE;
        }

        case ekDTYPE_INT8:
        {
            bool_t err;
            *((int8_t *)object) = str_to_i8(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int8_t");
        }

        case ekDTYPE_INT16:
        {
            bool_t err;
            *((int16_t *)object) = str_to_i16(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int16_t");
        }

        case ekDTYPE_INT32:
        {
            bool_t err;
            *((int32_t *)object) = str_to_i32(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int32_t");
        }

        case ekDTYPE_INT64:
        {
            bool_t err;
            *((int64_t *)object) = str_to_i64(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to int64_t");
        }

        case ekDTYPE_UINT8:
        {
            bool_t err;
            *((uint8_t *)object) = str_to_u8(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint8_t");
        }

        case ekDTYPE_UINT16:
        {
            bool_t err;
            *((uint16_t *)object) = str_to_u16(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint16_t");
        }

        case ekDTYPE_UINT32:
        {
            bool_t err;
            *((uint32_t *)object) = str_to_u32(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint32_t");
        }

        case ekDTYPE_UINT64:
        {
            bool_t err;
            *((uint64_t *)object) = str_to_u64(parser->lexeme, 10, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to uint64_t");
        }

        case ekDTYPE_REAL32:
        {
            bool_t err;
            *((real32_t *)object) = str_to_r32(parser->lexeme, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to real32_t");
        }

        case ekDTYPE_REAL64:
        {
            bool_t err;
            *((real64_t *)object) = str_to_r64(parser->lexeme, &err);
            return i_error(!err, FALSE, parser, "Cannot cast to real64_t");
        }

        case ekDTYPE_BOOL:
        case ekDTYPE_ENUM:
        case ekDTYPE_ARRAY:
        case ekDTYPE_ARRPTR:
        case ekDTYPE_OBJECT:
        case ekDTYPE_OBJECT_PTR:
            return i_error(FALSE, FALSE, parser, "Unexpected Json 'string'");

        case ekDTYPE_UNKNOWN:
            cassert_default();
        }

        return i_error(FALSE, TRUE, parser, "Unexpected Json 'string'");

    case i_ekOPEN_ARRAY:
        if (type == ekDTYPE_ARRAY)
        {
            uint16_t size;
            dtype_t dtype;
            cassert(*(Array **)object != NULL);
            cassert(array_size(*(Array **)object) == 0);
            dtype = dbind_data_type(subtype, NULL, &size);
            cassert(size == array_esize(*(Array **)object));
            return i_parse_array(parser, dtype, subtype, *((Array **)object));
        }
        else if (type == ekDTYPE_ARRPTR)
        {
            cassert(*(Array **)object != NULL);
            cassert(array_size(*(Array **)object) == 0);
            cassert(sizeofptr == array_esize(*(Array **)object));
            return i_parse_arrptr(parser, subtype, *(Array **)object);
        }

        return i_error(FALSE, TRUE, parser, "Unexpected Json 'array'");

    case i_ekOPEN_OBJECT:
        if (type == ekDTYPE_OBJECT)
        {
            return i_parse_object(parser, subtype, object);
        }
        else if (type == ekDTYPE_OBJECT_PTR)
        {
            if (dbind_stbind(subtype) != NULL)
            {
                cassert(*(void **)object == NULL);
                *(void **)object = dbind_create_imp(subtype);
                return i_parse_object(parser, subtype, *(void **)object);
            }
        }

        return i_error(FALSE, TRUE, parser, "Unexpected Json 'object'");

    case i_ekCLOSE_ARRAY:
        return FALSE;
    case i_ekCLOSE_OBJECT:
        return i_error(FALSE, TRUE, parser, "Unexpected Json token '}'");
    case i_ekCOMMA:
        return i_error(FALSE, TRUE, parser, "Unexpected Json token ','");
    case i_ekCOLON:
        return i_error(FALSE, TRUE, parser, "Unexpected Json token ':'");
    case i_ekUNKNOWN:
        return i_error(FALSE, TRUE, parser, "Unknown Json token");
        cassert_default();
    }

    return i_error(FALSE, TRUE, parser, "Fatal Json parsing error");
}

/*---------------------------------------------------------------------------*/

static bool_t i_parse_object(i_Parser *parser, const char_t *subtype, void *object)
{
    bool_t comma_state = FALSE;
    /* For all object members */
    for (;;)
    {
        const StBind *mstbind = NULL;
        const DBind *mbind = NULL;

        /* '}' */
        i_new_token(parser);
        if (parser->token == i_ekCLOSE_OBJECT)
        {
            if (comma_state == FALSE)
                return TRUE;
            else
                return i_error(FALSE, TRUE, parser, "Unexpected Json '}' (member opened)");
        }

        if (parser->token == i_ekCOMMA)
        {
            if (comma_state == FALSE)
            {
                comma_state = TRUE;
                continue;
            }
            else
            {
                return i_error(FALSE, TRUE, parser, "Unexpected Json ','");
            }
        }

        /* "member_name" */
        if (parser->token != i_ekSTRING)
            return i_error(FALSE, TRUE, parser, "Expected Json 'string' (member name)");

        mstbind = dbind_stbind(subtype);
        mbind = dbind_stbind_find(mstbind, parser->lexeme);
        /*if (_dbind_member(subtype, parser->lexeme, &moffset, &mtype, &msubtype) == FALSE)
        {
            String *member = str_printf("Ignored struct member '%s::%s'", subtype, parser->lexeme);
            i_error(FALSE, FALSE, parser, tc(member));
            str_destroy(&member);
            mbind = FALSE;
        }*/

        /* ":" */
        i_new_token(parser);
        if (parser->token != i_ekCOLON)
            return i_error(FALSE, TRUE, parser, "Expected Json ':' (object member)");

        /* "member_value" */
        if (mbind != NULL)
        {
            uint16_t moffset = dbind_offset(mbind);
            dtype_t mtype = dbind_type(mbind);
            const char_t *msubtype = dbind_subtype(mbind);
            if (i_parse_value(parser, mbind, mtype, msubtype, (void *)((byte_t *)object + moffset)) == TRUE)
                comma_state = FALSE;
            else
                return FALSE;
        }
        else
        {
            if (i_jump_value(parser) == TRUE)
                comma_state = FALSE;
            else
                return FALSE;
        }
    }
}

/*---------------------------------------------------------------------------*/

static byte_t *i_create_btype(i_Parser *parser, dtype_t dtype, const char_t *subtype)
{
    byte_t *obj = dbind_create_imp(subtype);
    if (i_parse_value(parser, NULL, dtype, subtype, obj) == FALSE)
        dbind_destroy_imp(&obj, subtype);
    return obj;
}

/*---------------------------------------------------------------------------*/

static void *i_create_type(i_Parser *parser, const char_t *type)
{
    String *subtype = NULL;
    uint16_t size;
    dtype_t dtype;
    byte_t *obj = NULL;

    dtype = dbind_data_type(type, &subtype, &size);
    switch (dtype)
    {
    case ekDTYPE_OBJECT:
        cassert(size > 0);
        cassert_no_null(subtype);
        obj = dbind_create_imp(type);
        if (i_parse_value(parser, NULL, dtype, tc(subtype), obj) == FALSE)
            dbind_destroy_imp(&obj, type);
        break;

    case ekDTYPE_ARRAY:
        i_new_token(parser);
        if (parser->token == i_ekOPEN_ARRAY)
        {
            dtype_t atype = dbind_data_type(tc(subtype), NULL, NULL);
            Array *array = (Array *)dbind_create_imp(type);
            if (i_parse_array(parser, atype, tc(subtype), array) == TRUE)
            {
                obj = (byte_t *)array;
            }
            else
            {
                i_error(FALSE, TRUE, parser, "Error procesing array");
                dbind_destroy_imp((byte_t **)&array, type);
            }
        }
        else
        {
            i_error(FALSE, TRUE, parser, "Array excepted");
        }

        break;

    case ekDTYPE_ARRPTR:
        i_new_token(parser);
        if (parser->token == i_ekOPEN_ARRAY)
        {
            Array *array = (Array *)dbind_create_imp(type);
            if (i_parse_arrptr(parser, tc(subtype), array) == TRUE)
            {
                obj = (byte_t *)array;
            }
            else
            {
                i_error(FALSE, TRUE, parser, "Error procesing array");
                dbind_destroy_imp((byte_t **)&array, type);
            }
        }
        else
        {
            i_error(FALSE, TRUE, parser, "Array excepted");
        }

        break;

    case ekDTYPE_BOOL:
        obj = i_create_btype(parser, dtype, "bool_t");
        break;

    case ekDTYPE_INT8:
        obj = i_create_btype(parser, dtype, "int8_t");
        break;

    case ekDTYPE_INT16:
        obj = i_create_btype(parser, dtype, "int16_t");
        break;

    case ekDTYPE_INT32:
        obj = i_create_btype(parser, dtype, "int32_t");
        break;

    case ekDTYPE_INT64:
        obj = i_create_btype(parser, dtype, "int64_t");
        break;

    case ekDTYPE_UINT8:
        obj = i_create_btype(parser, dtype, "uint8_t");
        break;

    case ekDTYPE_UINT16:
        obj = i_create_btype(parser, dtype, "uint16_t");
        break;

    case ekDTYPE_UINT32:
        obj = i_create_btype(parser, dtype, "uint32_t");
        break;

    case ekDTYPE_UINT64:
        obj = i_create_btype(parser, dtype, "uint64_t");
        break;

    case ekDTYPE_REAL32:
        obj = i_create_btype(parser, dtype, "real32_t");
        break;

    case ekDTYPE_REAL64:
        obj = i_create_btype(parser, dtype, "real64_t");
        break;

    case ekDTYPE_ENUM:
        obj = dbind_create_imp(tc(subtype));
        if (i_parse_value(parser, NULL, dtype, tc(subtype), obj) == FALSE)
            dbind_destroy_imp(&obj, tc(subtype));
        break;

    case ekDTYPE_STRING_PTR:
    case ekDTYPE_STRING:
        i_parse_value(parser, NULL, dtype, NULL, (String **)&obj);
        break;

    case ekDTYPE_OBJECT_OPAQUE:
        i_parse_value(parser, NULL, dtype, tc(subtype), &obj);
        break;

    case ekDTYPE_OBJECT_PTR:
    {
        String *err = str_printf("Unexpected double pointer to object '%s'", tc(subtype));
        i_error(FALSE, TRUE, parser, tc(err));
        str_destroy(&err);
        break;
    }

    case ekDTYPE_UNKNOWN:
    {
        String *err = str_printf("Unknown type '%s'", type);
        i_error(FALSE, TRUE, parser, tc(err));
        str_destroy(&err);
        break;
    }

        cassert_default();
    }

    str_destopt(&subtype);
    return obj;
}

/*---------------------------------------------------------------------------*/

void *json_read_imp(Stream *stm, const JsonOpts *opts, const char_t *type)
{
    i_Parser parser;
    void *obj = NULL;
    unref(opts);
    parser.stm = stm;
    stm_token_escapes(parser.stm, TRUE);
    stm_skip_bom(parser.stm);
    parser.col = 0;
    parser.row = 0;
    parser.lexeme = NULL;
    parser.lexsize = 0;
    parser.minus = FALSE;
    obj = i_create_type(&parser, type);
    return obj;
}

/*---------------------------------------------------------------------------*/

static void i_write_string(Stream *stm, const String *str)
{
    if (str != NULL)
    {
        const char_t *cstr = tc(str);
        uint32_t cp = unicode_to_u32(cstr, ekUTF8);
        stm_writef(stm, "\"");
        while (cp != 0)
        {
            if (cp == '"')
                stm_writef(stm, "\\\"");
            else if (cp == '\\')
                stm_writef(stm, "\\\\");
            /* else if (cp == '/')
             stm_writef(stm, "\\/"); */
            else if (cp == '\b')
                stm_writef(stm, "\\b");
            else if (cp == '\f')
                stm_writef(stm, "\\f");
            else if (cp == '\n')
                stm_writef(stm, "\\n");
            else if (cp == '\r')
                stm_writef(stm, "\\r");
            else if (cp == '\t')
                stm_writef(stm, "\\t");
            else if (cp >= 32)
                stm_write_char(stm, cp);
            cstr = unicode_next(cstr, ekUTF8);
            cp = unicode_to_u32(cstr, ekUTF8);
        }
        stm_writef(stm, "\"");
    }
    else
    {
        stm_writef(stm, "null");
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_array(Stream *stm, const Array *array, const char_t *type)
{
    if (array != NULL)
    {
        const byte_t *data = array_all(array);
        uint32_t i, n = array_size(array);
        uint32_t es = array_esize(array);
        String *subtype = NULL;
        dtype_t atype = dbind_data_type(type, &subtype, NULL);
        const char_t *stype = subtype != NULL ? tc(subtype) : NULL;
        stm_writef(stm, "[ ");
        for (i = 0; i < n; ++i, data += es)
        {
            i_write_type(stm, atype, stype, (const void *)data, FALSE);
            if (i < n - 1)
                stm_writef(stm, ", ");
        }
        stm_writef(stm, " ]");
        str_destopt(&subtype);
    }
    else
    {
        stm_writef(stm, "null");
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_arrpt(Stream *stm, const Array *array, const char_t *type)
{
    if (array != NULL)
    {
        const byte_t *data = array_all(array);
        uint32_t i, n = array_size(array);
        String *subtype = NULL;
        dtype_t atype = dbind_data_type(type, &subtype, NULL);
        const char_t *stype = subtype != NULL ? tc(subtype) : NULL;
        stm_writef(stm, "[ ");
        if (atype == ekDTYPE_STRING)
        {
            for (i = 0; i < n; ++i, data += sizeofptr)
            {
                i_write_string(stm, *(String **)data);
                if (i < n - 1)
                    stm_writef(stm, ", ");
            }
        }
        else if (atype == ekDTYPE_OBJECT)
        {
            for (i = 0; i < n; ++i, data += sizeofptr)
            {
                i_write_object(stm, *(const void **)data, stype);
                if (i < n - 1)
                    stm_writef(stm, ", ");
            }
        }
        else if (atype == ekDTYPE_OBJECT_OPAQUE)
        {
            for (i = 0; i < n; ++i, data += sizeofptr)
            {
                i_write_opaque(stm, *(const void **)data, stype);
                if (i < n - 1)
                    stm_writef(stm, ", ");
            }
        }
        else
        {
            cassert_msg(FALSE, "Json: Invalid ArrPt type.");
        }

        stm_writef(stm, " ]");
        str_destopt(&subtype);
    }
    else
    {
        stm_writef(stm, "null");
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_object(Stream *stm, const void *object, const char_t *type)
{
    if (object != NULL)
    {
        uint32_t n, i;
        const StBind *stbind = dbind_stbind(type);

        cassert_msg(stbind != NULL, "Json: Unknown struct type.");
        n = dbind_stbind_count(stbind);

        stm_writef(stm, "{");

        for (i = 0; i < n; ++i)
        {
            const DBind *dbind = dbind_stbind_member(stbind, i);
            const char_t *mname = dbind_name(dbind);
            uint16_t moffset = dbind_offset(dbind);
            dtype_t mtype = dbind_type(dbind);
            const char_t *mstype = dbind_subtype(dbind);

            stm_printf(stm, "\"%s\" : ", mname);
            i_write_type(stm, mtype, mstype, (const void *)((byte_t *)object + moffset), TRUE);
            if (i < n - 1)
                stm_writef(stm, ", ");
        }

        stm_writef(stm, " }");
    }
    else
    {
        stm_writef(stm, "null");
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_opaque(Stream *stm, const void *object, const char_t *type)
{
    if (object != NULL)
    {
        const StBind *stbind = dbind_stbind(type);
        Stream *objstm = stm_memory(1024);
        const byte_t *data = NULL;
        char_t *b64data = NULL;
        uint32_t size = 0, b64size = 0;
        cassert_msg(stbind != NULL, "Json: Unknown opaque type.");
        dbind_stbind_opaque_write(stbind, object, objstm);
        data = stm_buffer(objstm);
        size = stm_buffer_size(objstm);
        b64size = b64_encoded_size(size);
        b64data = (char_t *)heap_malloc(b64size, "JsonB64Encode");
        b64_encode(data, size, b64data, b64size);
        stm_writef(stm, "\"");
        stm_writef(stm, b64data);
        stm_writef(stm, "\"");
        heap_free((byte_t **)&b64data, b64size, "JsonB64Encode");
        stm_close(&objstm);
    }
    else
    {
        stm_writef(stm, "null");
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_type(Stream *stm, dtype_t type, const char_t *subtype, const void *data, const bool_t doubleptr)
{
    cassert_no_null(data);
    switch (type)
    {
    case ekDTYPE_BOOL:
        if (*(bool_t *)data == TRUE)
        {
            stm_writef(stm, "true");
        }
        else
        {
            cassert(*(bool_t *)data == FALSE);
            stm_writef(stm, "false");
        }
        break;

    case ekDTYPE_INT8:
        stm_printf(stm, "%d", *(int8_t *)data);
        break;

    case ekDTYPE_INT16:
        stm_printf(stm, "%d", *(int16_t *)data);
        break;

    case ekDTYPE_INT32:
        stm_printf(stm, "%d", *(int32_t *)data);
        break;

    case ekDTYPE_INT64:
        stm_printf(stm, "%" PRId64, *(int64_t *)data);
        break;

    case ekDTYPE_UINT8:
        stm_printf(stm, "%u", *(uint8_t *)data);
        break;

    case ekDTYPE_UINT16:
        stm_printf(stm, "%u", *(uint16_t *)data);
        break;

    case ekDTYPE_UINT32:
        stm_printf(stm, "%u", *(uint32_t *)data);
        break;

    case ekDTYPE_UINT64:
        stm_printf(stm, "%" PRIu64, *(uint64_t *)data);
        break;

    case ekDTYPE_REAL32:
        stm_printf(stm, "%f", *(real32_t *)data);
        break;

    case ekDTYPE_REAL64:
        stm_printf(stm, "%f", *(real64_t *)data);
        break;

    case ekDTYPE_ENUM:
        stm_printf(stm, "%u", *(enum_t *)data);
        break;

    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
        if (doubleptr == TRUE)
            i_write_string(stm, *(String **)data);
        else
            i_write_string(stm, (String *)data);
        break;

    case ekDTYPE_ARRAY:
        if (doubleptr == TRUE)
            i_write_array(stm, *(Array **)data, subtype);
        else
            i_write_array(stm, (Array *)data, subtype);
        break;

    case ekDTYPE_ARRPTR:
        if (doubleptr == TRUE)
            i_write_arrpt(stm, *(Array **)data, subtype);
        else
            i_write_arrpt(stm, (Array *)data, subtype);
        break;

    case ekDTYPE_OBJECT:
        i_write_object(stm, data, subtype);
        break;

    case ekDTYPE_OBJECT_PTR:
        if (doubleptr == TRUE)
            i_write_object(stm, *(const void **)data, subtype);
        else
            i_write_object(stm, data, subtype);
        break;

    case ekDTYPE_OBJECT_OPAQUE:
        if (doubleptr == TRUE)
            i_write_opaque(stm, *(const void **)data, subtype);
        else
            i_write_opaque(stm, data, subtype);
        break;

    case ekDTYPE_UNKNOWN:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void json_write_imp(Stream *stm, const void *data, const JsonOpts *opts, const char_t *type)
{
    String *subtype = NULL;
    dtype_t dtype = dbind_data_type(type, &subtype, NULL);
    unref(opts);
    i_write_type(stm, dtype, subtype != NULL ? tc(subtype) : NULL, data, FALSE);
    str_destopt(&subtype);
}

/*---------------------------------------------------------------------------*/

void json_destroy_imp(void **data, const char_t *type)
{
    dbind_destroy_imp((byte_t **)data, type);
}

/*---------------------------------------------------------------------------*/

void json_destopt_imp(void **data, const char_t *type)
{
    dbind_destopt_imp((byte_t **)data, type);
}

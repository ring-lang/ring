/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dbind.c
 *
 */

/* Data bindings */

#include "dbind.h"
#include "dbindh.h"
#include "dbind.inl"
#include "tfilter.inl"
#include "arrpt.h"
#include "arrst.h"
#include "buffer.h"
#include "heap.h"
#include "stream.h"
#include "strings.h"
#include <osbs/log.h>
#include <sewer/bmath.h>
#include <sewer/bmem.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

typedef union _attribs_t Attribs;
typedef struct _enumbind_t EnumBind;
typedef struct _enumvbind_t EnumVBind;
typedef struct _databind_t DataBind;

union _attribs_t
{
    struct _bool_
    {
        bool_t def;
    } boolt;

    struct _int_
    {
        int64_t def;
        int64_t min;
        int64_t max;
        int64_t incr;
        String *format;
    } intt;

    struct _real32_
    {
        real32_t def;
        real32_t min;
        real32_t max;
        real32_t prec;
        real32_t incr;
        uint32_t dec;
        String *format;
    } real32t;

    struct _real64_
    {
        real64_t def;
        real64_t min;
        real64_t max;
        real64_t prec;
        real64_t incr;
        uint32_t dec;
        String *format;
    } real64t;

    struct _enum_
    {
        EnumBind *ebind;
        enum_t def;
    } enumt;

    struct _string_
    {
        String *def;
    } stringt;

    struct _array_
    {
        dtype_t dtype;
        StBind *stbind;
        EnumBind *ebind;
    } arrayt;

    struct _object_
    {
        StBind *stbind;
        void *def;
    } object;
};

struct _dbind_t
{
    StBind *stbind;
    dtype_t type;
    String *name;
    uint16_t offset;
    uint16_t size;
    Attribs attr;
};

struct _stbind_t
{
    String *type;
    uint16_t size;
    FPtr_data func_data;
    FPtr_buffer func_buffer;
    FPtr_copy func_copy;
    FPtr_read func_read;
    FPtr_write func_write;
    FPtr_destroy func_destroy;
    ArrSt(DBind) *members;
};

struct _enumvbind_t
{
    String *name;
    String *alias;
    enum_t value;
};

struct _enumbind_t
{
    String *type;
    ArrSt(EnumVBind) *values;
};

struct _databind_t
{
    ArrPt(StBind) *stbinds;
    ArrPt(EnumBind) *ebinds;
};

/*---------------------------------------------------------------------------*/

DeclSt(EnumVBind);
DeclPt(EnumBind);
DeclSt(DBind);
DeclPt(StBind);

static void i_remove_object(byte_t *data, const StBind *stbind, const uint16_t size);
static void i_destroy_object(byte_t **data, const StBind *stbind, const uint16_t size);
static void i_write_value(Stream *stm, DBind *dbind, dtype_t type, const char_t *subtype, const void *data);
static bool_t i_read_value(Stream *stm, DBind *dbind, dtype_t type, const char_t *subtype, void *data);
static DataBind i_DATABIND = {0, 0};

/*---------------------------------------------------------------------------*/

static StBind *i_find_stbind(const char_t *type, uint32_t *index)
{
    arrpt_foreach(bind, i_DATABIND.stbinds, StBind)
        int compare = str_cmp(bind->type, type);
        if (compare == 0)
        {
            return bind;
        }
        else if (compare > 0)
        {
            ptr_assign(index, bind_i);
            return NULL;
        }
    arrpt_end()

    if (index != NULL)
        *index = arrpt_size(i_DATABIND.stbinds, StBind);
    return NULL;
}

/*---------------------------------------------------------------------------*/

static EnumBind *i_find_enum(const char_t *type, uint32_t *index)
{
    arrpt_foreach(bind, i_DATABIND.ebinds, EnumBind)
        int compare = str_cmp(bind->type, type);
        if (compare == 0)
        {
            return bind;
        }
        else if (compare > 0)
        {
            ptr_assign(index, bind_i);
            return NULL;
        }
    arrpt_end()

    if (index != NULL)
        *index = arrpt_size(i_DATABIND.ebinds, EnumBind);
    return NULL;
}

/*---------------------------------------------------------------------------*/

static void i_remove_member(DBind *member)
{
    cassert_no_null(member);
    str_destroy(&member->name);
    switch (member->type)
    {

    case ekDTYPE_STRING_PTR:
        str_destopt(&member->attr.stringt.def);
        break;

    case ekDTYPE_INT8:
    case ekDTYPE_INT16:
    case ekDTYPE_INT32:
    case ekDTYPE_INT64:
    case ekDTYPE_UINT8:
    case ekDTYPE_UINT16:
    case ekDTYPE_UINT32:
    case ekDTYPE_UINT64:
        str_destopt(&member->attr.intt.format);
        break;

    case ekDTYPE_REAL32:
        str_destroy(&member->attr.real32t.format);
        break;

    case ekDTYPE_REAL64:
        str_destroy(&member->attr.real64t.format);
        break;

    case ekDTYPE_ENUM:
        member->attr.enumt.ebind = NULL;
        break;

    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
        member->attr.arrayt.dtype = ekDTYPE_UNKNOWN;
        member->attr.arrayt.stbind = NULL;
        member->attr.arrayt.ebind = NULL;
        break;

    case ekDTYPE_OBJECT:
        cassert(member->attr.object.def == NULL);
        member->attr.object.stbind = NULL;
        break;

    case ekDTYPE_OBJECT_PTR:
        cassert(member->attr.object.def == NULL);
        member->attr.object.stbind = NULL;
        break;

    case ekDTYPE_OBJECT_OPAQUE:
        if (member->attr.object.def != NULL)
        {
            cassert_no_null(member->attr.object.stbind);
            cassert_no_nullf(member->attr.object.stbind->func_destroy);
            member->attr.object.stbind->func_destroy(&member->attr.object.def);
        }
        member->attr.object.stbind = NULL;
        break;

    case ekDTYPE_BOOL:
    case ekDTYPE_STRING:
    case ekDTYPE_UNKNOWN:
    default:
        break;
    }
}

/*---------------------------------------------------------------------------*/

/* DBind destruction may depends on other StBind */
static void i_remove_stbind(StBind *stbind)
{
    cassert_no_null(stbind);
    if (stbind->members != NULL)
        arrst_destroy(&stbind->members, i_remove_member, DBind);
}

/*---------------------------------------------------------------------------*/

static void i_destroy_stbind(StBind **stbind)
{
    cassert_no_null(stbind);
    cassert_no_null(*stbind);
    cassert((*stbind)->members == NULL);
    str_destroy(&(*stbind)->type);
    heap_delete(stbind, StBind);
}

/*---------------------------------------------------------------------------*/

static void i_remove_evalue(EnumVBind *evalue)
{
    cassert_no_null(evalue);
    str_destroy(&evalue->name);
    str_destroy(&evalue->alias);
}

/*---------------------------------------------------------------------------*/

static void i_destroy_enumbind(EnumBind **ebind)
{
    cassert_no_null(ebind);
    cassert_no_null(*ebind);
    str_destroy(&(*ebind)->type);
    arrst_destroy(&(*ebind)->values, i_remove_evalue, EnumVBind);
    heap_delete(ebind, EnumBind);
}

/*---------------------------------------------------------------------------*/

void _dbind_start(void)
{
    if (i_DATABIND.stbinds == NULL)
    {
        i_DATABIND.stbinds = arrpt_create(StBind);
        i_DATABIND.ebinds = arrpt_create(EnumBind);
    }
}

/*---------------------------------------------------------------------------*/

void _dbind_finish(void)
{
    if (i_DATABIND.stbinds != NULL)
    {
        arrpt_foreach(stbind, i_DATABIND.stbinds, StBind)
            i_remove_stbind(stbind);
        arrpt_end()

        arrpt_destroy(&i_DATABIND.stbinds, i_destroy_stbind, StBind);
        arrpt_destroy(&i_DATABIND.ebinds, i_destroy_enumbind, EnumBind);
    }
}

/*---------------------------------------------------------------------------*/

static const char_t *i_basic_type(const dtype_t type)
{
    switch (type)
    {
    case ekDTYPE_BOOL:
        return "bool_t";
    case ekDTYPE_INT8:
        return "int8_t";
    case ekDTYPE_INT16:
        return "int16_t";
    case ekDTYPE_INT32:
        return "int32_t";
    case ekDTYPE_INT64:
        return "int64_t";
    case ekDTYPE_UINT8:
        return "uint8_t";
    case ekDTYPE_UINT16:
        return "uint16_t";
    case ekDTYPE_UINT32:
        return "uint32_t";
    case ekDTYPE_UINT64:
        return "uint64_t";
    case ekDTYPE_REAL32:
        return "real32_t";
    case ekDTYPE_REAL64:
        return "real64_t";
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
        return "String";

    case ekDTYPE_ENUM:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }

    return "";
}

/*---------------------------------------------------------------------------*/

static const char_t *i_subtype_str(const DBind *member)
{
    cassert_no_null(member);
    switch (member->type)
    {
    case ekDTYPE_ENUM:
        return tc(member->attr.enumt.ebind->type);

    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
        if (member->attr.arrayt.stbind != NULL)
            return tc(member->attr.arrayt.stbind->type);
        else if (member->attr.arrayt.ebind != NULL)
            return tc(member->attr.arrayt.ebind->type);
        else
            return i_basic_type(member->attr.arrayt.dtype);

    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
        cassert_no_null(member->attr.object.stbind);
        return tc(member->attr.object.stbind->type);

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
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_UNKNOWN:
    default:
        return i_basic_type(member->type);
    }
}

/*---------------------------------------------------------------------------*/

static void i_clean_spaces(char_t *dest, const uint32_t size, const char_t *src)
{
    uint32_t i = 0;
    cassert_no_null(dest);
    cassert_no_null(src);
    while (i < size - 1 && *src != 0)
    {
        if (*src != ' ')
        {
            dest[i] = *src;
            i += 1;
        }

        src += 1;
    }

    dest[i] = 0;
}

/*---------------------------------------------------------------------------*/

static dtype_t i_data_type(const char_t *mtypei, String **subtype, uint16_t *size)
{
    char_t mtype[256];

    if (subtype != NULL)
        *subtype = NULL;

    i_clean_spaces(mtype, sizeof(mtype), mtypei);

    if (str_equ_c(mtype, "bool_t") == TRUE)
    {
        ptr_assign(size, sizeof(bool_t));
        return ekDTYPE_BOOL;
    }

    if (str_equ_c(mtype, "uint32_t") == TRUE)
    {
        ptr_assign(size, sizeof(uint32_t));
        return ekDTYPE_UINT32;
    }

    if (str_equ_c(mtype, "real32_t") == TRUE)
    {
        ptr_assign(size, sizeof(real32_t));
        return ekDTYPE_REAL32;
    }

    if (str_equ_c(mtype, "int32_t") == TRUE)
    {
        ptr_assign(size, sizeof(int32_t));
        return ekDTYPE_INT32;
    }

    if (str_equ_c(mtype, "int8_t") == TRUE)
    {
        ptr_assign(size, sizeof(int8_t));
        return ekDTYPE_INT8;
    }

    if (str_equ_c(mtype, "int16_t") == TRUE)
    {
        ptr_assign(size, sizeof(int16_t));
        return ekDTYPE_INT16;
    }

    if (str_equ_c(mtype, "int64_t") == TRUE)
    {
        ptr_assign(size, sizeof(int64_t));
        return ekDTYPE_INT64;
    }

    if (str_equ_c(mtype, "uint8_t") == TRUE)
    {
        ptr_assign(size, sizeof(uint8_t));
        return ekDTYPE_UINT8;
    }

    if (str_equ_c(mtype, "uint16_t") == TRUE)
    {
        ptr_assign(size, sizeof(uint16_t));
        return ekDTYPE_UINT16;
    }

    if (str_equ_c(mtype, "uint64_t") == TRUE)
    {
        ptr_assign(size, sizeof(uint64_t));
        return ekDTYPE_UINT64;
    }

    if (str_equ_c(mtype, "real64_t") == TRUE)
    {
        ptr_assign(size, sizeof(real64_t));
        return ekDTYPE_REAL64;
    }

    if (str_equ_c(mtype, "String*") == TRUE)
    {
        ptr_assign(size, sizeof(String *));
        return ekDTYPE_STRING_PTR;
    }

    if (str_equ_c(mtype, "String") == TRUE)
    {
        ptr_assign(size, sizeof(String *));
        return ekDTYPE_STRING;
    }

    if (str_cmp_cn(mtype, "ArrSt(", 6) == 0)
    {
        const char_t *ctype = mtype + 6;
        uint32_t n = str_len_c(ctype);
        ptr_assign(size, sizeof(Array *));
        if (ctype[n - 1] == '*')
        {
            cassert_msg(ctype[n - 2] == ')', "Binding: Invalid array type.");
            if (subtype != NULL)
                *subtype = str_cn(ctype, n - 2);
        }
        else
        {
            cassert_msg(ctype[n - 1] == ')', "Binding: Invalid array type.");
            if (subtype != NULL)
                *subtype = str_cn(ctype, n - 1);
        }

        return ekDTYPE_ARRAY;
    }

    if (str_cmp_cn(mtype, "ArrPt(", 6) == 0)
    {
        const char_t *ctype = mtype + 6;
        uint32_t n = str_len_c(ctype);
        ptr_assign(size, sizeof(Array *));
        if (ctype[n - 1] == '*')
        {
            cassert_msg(ctype[n - 2] == ')', "Binding: Invalid array type.");
            if (subtype != NULL)
                *subtype = str_cn(ctype, n - 2);
        }
        else
        {
            cassert_msg(ctype[n - 1] == ')', "Binding: Invalid array type.");
            if (subtype != NULL)
                *subtype = str_cn(ctype, n - 1);
        }

        return ekDTYPE_ARRPTR;
    }

    {
        uint32_t n = str_len_c(mtype);
        if (mtype[n - 1] == '*')
        {
            String *lsubtype = str_cn(mtype, n - 1);
            StBind *stbind = i_find_stbind(tc(lsubtype), NULL);
            if (stbind != NULL)
            {
                ptr_assign(size, sizeofptr);

                if (subtype != NULL)
                    *subtype = lsubtype;
                else
                    str_destroy(&lsubtype);

                if (stbind->members != NULL)
                {
                    cassert(arrst_size(stbind->members, DBind) > 0);
                    return ekDTYPE_OBJECT_PTR;
                }
                else
                {
                    cassert(stbind->size == sizeofptr);
                    return ekDTYPE_OBJECT_OPAQUE;
                }
            }
            else
            {
                str_destroy(&lsubtype);
                ptr_assign(size, 0);
                return ekDTYPE_UNKNOWN;
            }
        }
        else
        {
            StBind *stbind = i_find_stbind(mtype, NULL);
            if (stbind != NULL)
            {
                ptr_assign(size, stbind->size);
                if (subtype != NULL)
                    *subtype = str_c(mtype);

                if (stbind->members != NULL)
                {
                    cassert(arrst_size(stbind->members, DBind) > 0);
                    return ekDTYPE_OBJECT;
                }
                else
                {
                    cassert(stbind->size == sizeofptr);
                    return ekDTYPE_OBJECT_OPAQUE;
                }
            }
            else
            {
                EnumBind *ebind = i_find_enum(mtype, NULL);
                if (ebind != NULL)
                {
                    ptr_assign(size, sizeof(enum_t));
                    if (subtype != NULL)
                        *subtype = str_c(mtype);

                    return ekDTYPE_ENUM;
                }
                else
                {
                    ptr_assign(size, 0);
                    return ekDTYPE_UNKNOWN;
                }
            }
        }
    }
}

/*---------------------------------------------------------------------------*/

static DBind *i_find_member(ArrSt(DBind) *members, const uint16_t moffset, uint32_t *index)
{
    arrst_foreach(member, members, DBind)
        if (member->offset == moffset)
        {
            return member;
        }
        else if (member->offset > moffset)
        {
            *index = member_i;
            return NULL;
        }
    arrst_end()

    *index = arrst_size(members, DBind);
    return NULL;
}

/*---------------------------------------------------------------------------*/

static StBind *i_stbind(const char_t *type, const uint16_t size)
{
    uint32_t index = 0;
    StBind *stbind = i_find_stbind(type, &index);
    if (stbind == NULL)
    {
        stbind = heap_new0(StBind);
        arrpt_insert(i_DATABIND.stbinds, index, stbind, StBind);
        stbind->type = str_c(type);
        stbind->size = size;
        stbind->members = arrst_create(DBind);
    }

    return stbind;
}

/*---------------------------------------------------------------------------*/

static void i_add_member(StBind *stbind, const char_t *mname, const char_t *mtype, const uint16_t moffset, const uint16_t msize)
{
    DBind *member;
    uint32_t index = UINT32_MAX;
    cassert_no_null(stbind);
    member = i_find_member(stbind->members, moffset, &index);
    if (member == NULL)
    {
        dtype_t dtype;
        String *subtype = NULL;
        uint16_t size;
        dtype = i_data_type(mtype, &subtype, &size);
        if (dtype != ekDTYPE_UNKNOWN)
        {
            cassert(size == msize);
            member = arrst_insert_n(stbind->members, index, 1, DBind);
            member->stbind = stbind;
            member->type = dtype;
            member->name = str_c(mname);
            member->offset = moffset;
            member->size = msize;

            switch (member->type)
            {
            case ekDTYPE_BOOL:
                member->attr.boolt.def = FALSE;
                break;

            case ekDTYPE_INT8:
                member->attr.intt.def = 0;
                member->attr.intt.min = (int64_t)INT8_MIN;
                member->attr.intt.max = (int64_t)INT8_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%d");
                break;

            case ekDTYPE_INT16:
                member->attr.intt.def = 0;
                member->attr.intt.min = (int64_t)INT16_MIN;
                member->attr.intt.max = (int64_t)INT16_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%d");
                break;

            case ekDTYPE_INT32:
                member->attr.intt.def = 0;
                member->attr.intt.min = (int64_t)INT32_MIN;
                member->attr.intt.max = (int64_t)INT32_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%d");
                break;

            case ekDTYPE_INT64:
                member->attr.intt.def = 0;
                member->attr.intt.min = (int64_t)INT64_MIN;
                member->attr.intt.max = (int64_t)INT64_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%d");
                break;

            case ekDTYPE_UINT8:
                member->attr.intt.def = 0;
                member->attr.intt.min = 0;
                member->attr.intt.max = UINT8_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%u");
                break;

            case ekDTYPE_UINT16:
                member->attr.intt.def = 0;
                member->attr.intt.min = 0;
                member->attr.intt.max = UINT16_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%u");
                break;

            case ekDTYPE_UINT32:
                member->attr.intt.def = 0;
                member->attr.intt.min = 0;
                member->attr.intt.max = UINT32_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%u");
                break;

            case ekDTYPE_UINT64:
                member->attr.intt.def = 0;
                member->attr.intt.min = 0;
                member->attr.intt.max = INT64_MAX;
                member->attr.intt.incr = 1;
                member->attr.intt.format = str_c("%%u");
                break;

            case ekDTYPE_REAL32:
                member->attr.real32t.def = 0;
                member->attr.real32t.min = -1e8f;
                member->attr.real32t.max = 1e8f;
                member->attr.real32t.prec = .01f;
                member->attr.real32t.incr = 1;
                member->attr.real32t.dec = 2;
                member->attr.real32t.format = str_c("%.2f");
                break;

            case ekDTYPE_REAL64:
                member->attr.real64t.def = 0;
                member->attr.real64t.min = -1e8;
                member->attr.real64t.max = 1e8;
                member->attr.real64t.prec = .01;
                member->attr.real64t.incr = 1;
                member->attr.real64t.dec = 2;
                member->attr.real64t.format = str_c("%.2f");
                break;

            case ekDTYPE_STRING_PTR:
                member->attr.stringt.def = str_c("");
                break;

            case ekDTYPE_ENUM:
            {
                const EnumVBind *first;
                cassert(str_equ(subtype, mtype) == TRUE);
                member->attr.enumt.ebind = i_find_enum(mtype, NULL);
                cassert_no_null(member->attr.enumt.ebind);
                first = arrst_get(member->attr.enumt.ebind->values, 0, EnumVBind);
                cassert_no_null(first);
                member->attr.enumt.def = first->value;
                break;
            }

            case ekDTYPE_ARRAY:
                cassert(subtype != NULL);
                member->attr.arrayt.dtype = i_data_type(tc(subtype), NULL, NULL);
                member->attr.arrayt.stbind = NULL;
                member->attr.arrayt.ebind = NULL;

                switch (member->attr.arrayt.dtype)
                {
                /* Allowed array types */
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
                    break;

                case ekDTYPE_ENUM:
                    member->attr.arrayt.ebind = i_find_enum(tc(subtype), NULL);
                    cassert_no_null(member->attr.arrayt.ebind);
                    break;

                case ekDTYPE_OBJECT:
                    member->attr.arrayt.stbind = i_find_stbind(tc(subtype), NULL);
                    cassert_no_null(member->attr.arrayt.stbind);
                    break;

                case ekDTYPE_STRING:
                case ekDTYPE_STRING_PTR:
                case ekDTYPE_ARRAY:
                case ekDTYPE_ARRPTR:
                case ekDTYPE_OBJECT_PTR:
                case ekDTYPE_OBJECT_OPAQUE:
                case ekDTYPE_UNKNOWN:
                    cassert_default();
                }

                break;

            case ekDTYPE_ARRPTR:
                cassert(subtype != NULL);
                member->attr.arrayt.dtype = i_data_type(tc(subtype), NULL, NULL);
                member->attr.arrayt.stbind = NULL;
                member->attr.arrayt.ebind = NULL;

                switch (member->attr.arrayt.dtype)
                {
                /* Allowed pointer array types */
                case ekDTYPE_OBJECT:
                case ekDTYPE_OBJECT_OPAQUE:
                    member->attr.arrayt.stbind = i_find_stbind(tc(subtype), NULL);
                    cassert_no_null(member->attr.arrayt.stbind);
                    break;

                case ekDTYPE_STRING:
                    break;

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
                case ekDTYPE_STRING_PTR:
                case ekDTYPE_ARRAY:
                case ekDTYPE_ARRPTR:
                case ekDTYPE_OBJECT_PTR:
                case ekDTYPE_UNKNOWN:
                    cassert_default();
                }
                break;

            case ekDTYPE_OBJECT:
            case ekDTYPE_OBJECT_PTR:
            case ekDTYPE_OBJECT_OPAQUE:
                cassert(subtype != NULL);
                member->attr.object.stbind = i_find_stbind(tc(subtype), NULL);
                cassert_no_null(member->attr.object.stbind);
                member->attr.object.def = NULL;
                break;

            case ekDTYPE_STRING:
            case ekDTYPE_UNKNOWN:
                cassert_default();
            }
        }
        else
        {
            log_printf("Binding: Struct member '%s::%s' unknown type.", tc(stbind->type), mname);
        }

        str_destopt(&subtype);
    }
    else
    {
        log_printf("Binding: Struct member '%s::%s' already bind.", tc(stbind->type), mname);
    }
}

/*---------------------------------------------------------------------------*/

void dbind_imp(
    const char_t *type,
    const uint16_t size,
    const char_t *mname,
    const char_t *mtype,
    const uint16_t moffset,
    const uint16_t msize)
{
    uint32_t index = 0;
    StBind *stbind = i_stbind(type, size);
    if (stbind == NULL)
    {
        stbind = heap_new0(StBind);
        arrpt_insert(i_DATABIND.stbinds, index, stbind, StBind);
        stbind->type = str_c(type);
        stbind->size = size;
        stbind->members = arrst_create(DBind);
    }

    i_add_member(stbind, mname, mtype, moffset, msize);
}

/*---------------------------------------------------------------------------*/

static EnumBind *i_enum_bind(const char_t *type)
{
    uint32_t index = 0;
    EnumBind *ebind = i_find_enum(type, &index);
    if (ebind == NULL)
    {
        ebind = heap_new(EnumBind);
        ebind->type = str_c(type);
        ebind->values = arrst_create(EnumVBind);
        arrpt_insert(i_DATABIND.ebinds, index, ebind, EnumBind);
    }

    return ebind;
}

/*---------------------------------------------------------------------------*/

static __INLINE EnumVBind *i_enum_vbind(EnumBind *ebind, const char_t *name)
{
    arrst_foreach(evalue, ebind->values, EnumVBind)
        if (str_equ(evalue->name, name) == TRUE)
            return evalue;
    arrst_end()
    return NULL;
}

/*---------------------------------------------------------------------------*/

void dbind_enum_imp(const char_t *type, const char_t *name, const enum_t value, const char_t *alias)
{
    EnumBind *ebind = i_enum_bind(type);
    EnumVBind *evalue = i_enum_vbind(ebind, name);
    if (evalue != NULL)
    {
        cassert(str_equ(evalue->name, name) == TRUE);
        cassert(evalue->value == value);
    }
    else
    {
        evalue = arrst_new(ebind->values, EnumVBind);
        evalue->name = str_c(name);
        evalue->value = value;
        evalue->alias = NULL;
    }

    if (str_empty_c(alias) == TRUE)
        str_upd(&evalue->alias, tc(evalue->name));
    else
        str_upd(&evalue->alias, alias);
}

/*---------------------------------------------------------------------------*/

void dbind_opaque_imp(
    const char_t *type,
    FPtr_data func_data,
    FPtr_buffer func_buffer,
    FPtr_copy func_copy,
    FPtr_read func_read,
    FPtr_write func_write,
    FPtr_destroy func_destroy)
{
    uint32_t index = 0;
    StBind *stbind = i_find_stbind(type, &index);
    cassert(stbind == NULL);
    stbind = heap_new0(StBind);
    arrpt_insert(i_DATABIND.stbinds, index, stbind, StBind);
    stbind->type = str_c(type);
    stbind->size = sizeofptr;
    stbind->members = NULL;
    stbind->func_data = func_data;
    stbind->func_buffer = func_buffer;
    stbind->func_copy = func_copy;
    stbind->func_read = func_read;
    stbind->func_write = func_write;
    stbind->func_destroy = func_destroy;
}

/*---------------------------------------------------------------------------*/

void dbind_opaque_destroy(const char_t *object_type)
{
    if (i_DATABIND.stbinds != NULL)
    {
        arrpt_foreach(stbind, i_DATABIND.stbinds, StBind)
            if (stbind->members != NULL)
            {
                arrst_foreach(member, stbind->members, DBind)
                    if (member->type == ekDTYPE_OBJECT_OPAQUE)
                    {
                        if (member->attr.object.def != NULL)
                        {
                            cassert_no_null(member->attr.object.stbind);
                            if (str_equ(member->attr.object.stbind->type, object_type) == TRUE)
                            {
                                cassert_no_nullf(member->attr.object.stbind->func_destroy);
                                member->attr.object.stbind->func_destroy(&member->attr.object.def);
                            }
                        }
                    }
                arrst_end()
            }
        arrpt_end()
    }
}

/*---------------------------------------------------------------------------*/

static void i_init_object(byte_t *data, const StBind *stbind, const uint16_t size)
{
    cassert_no_null(stbind);
    cassert_unref(stbind->size == size, size);
    arrst_foreach(member, stbind->members, DBind)
        switch (member->type)
        {
        case ekDTYPE_OBJECT:
            i_init_object(data + member->offset, member->attr.object.stbind, member->size);
            break;

        case ekDTYPE_OBJECT_PTR:
            cassert(*((byte_t **)(data + member->offset)) == NULL);
            break;

        case ekDTYPE_OBJECT_OPAQUE:
            cassert(*((byte_t **)(data + member->offset)) == NULL);
            if (member->attr.object.def != NULL)
            {
                void **obj = (void **)(byte_t **)(data + member->offset);
                cassert_no_null(member->attr.object.stbind);
                cassert_no_nullf(member->attr.object.stbind->func_copy);
                *obj = member->attr.object.stbind->func_copy(member->attr.object.def);
            }
            break;

        case ekDTYPE_STRING_PTR:
        {
            String **str = (String **)(data + member->offset);
            cassert(*str == NULL);
            *str = str_copy(member->attr.stringt.def);
            break;
        }

        case ekDTYPE_ARRAY:
        {
            char_t atype[128] = ARRST;
            const char_t *subtype = i_subtype_str(member);
            Array **array = (Array **)(data + member->offset);
            uint16_t esize;
            str_cat_c(atype, 128, subtype);
            i_data_type(subtype, NULL, &esize);
            *array = array_create(esize, atype);
            break;
        }

        case ekDTYPE_ARRPTR:
        {
            char_t atype[128] = ARRPT;
            const char_t *subtype = i_subtype_str(member);
            Array **array = (Array **)(data + member->offset);
            str_cat_c(atype, 128, subtype);
            *array = array_create(sizeofptr, atype);
            break;
        }

        case ekDTYPE_STRING:
            cassert_msg(FALSE, "dbind_destroy: Unexpected member type.");
            break;

        case ekDTYPE_BOOL:
            *(bool_t *)(data + member->offset) = member->attr.boolt.def;
            break;

        case ekDTYPE_INT8:
            *(int8_t *)(data + member->offset) = dbind_int8(member, (int8_t)member->attr.intt.def);
            break;

        case ekDTYPE_INT16:
            *(int16_t *)(data + member->offset) = dbind_int16(member, (int16_t)member->attr.intt.def);
            break;

        case ekDTYPE_INT32:
            *(int32_t *)(data + member->offset) = dbind_int32(member, (int32_t)member->attr.intt.def);
            break;

        case ekDTYPE_INT64:
            *(int64_t *)(data + member->offset) = dbind_int64(member, (int64_t)member->attr.intt.def);
            break;

        case ekDTYPE_UINT8:
            *(uint8_t *)(data + member->offset) = dbind_uint8(member, (uint8_t)member->attr.intt.def);
            break;

        case ekDTYPE_UINT16:
            *(uint16_t *)(data + member->offset) = dbind_uint16(member, (uint16_t)member->attr.intt.def);
            break;

        case ekDTYPE_UINT32:
            *(uint32_t *)(data + member->offset) = dbind_uint32(member, (uint32_t)member->attr.intt.def);
            break;

        case ekDTYPE_UINT64:
            *(uint64_t *)(data + member->offset) = dbind_uint64(member, (uint64_t)member->attr.intt.def);
            break;

        case ekDTYPE_ENUM:
            *(enum_t *)(data + member->offset) = member->attr.enumt.def;
            break;

        case ekDTYPE_REAL32:
            *(real32_t *)(data + member->offset) = dbind_real32(member, member->attr.real32t.def);
            break;

        case ekDTYPE_REAL64:
            *(real64_t *)(data + member->offset) = dbind_real64(member, member->attr.real64t.def);
            break;

        case ekDTYPE_UNKNOWN:
            cassert_default();
        }
    arrst_end()
}

/*---------------------------------------------------------------------------*/

byte_t *dbind_create_imp(const char_t *type)
{
    String *subtype = NULL;
    uint16_t size;
    dtype_t dtype = i_data_type(type, &subtype, &size);
    byte_t *data = NULL;
    switch (dtype)
    {
    case ekDTYPE_OBJECT:
    {
        StBind *stbind = i_find_stbind(tc(subtype), NULL);
        data = heap_calloc_imp(size, type, TRUE);
        i_init_object(data, stbind, size);
        break;
    }

    case ekDTYPE_ARRAY:
    {
        char_t atype[128] = ARRST;
        uint16_t esize;
        i_data_type(tc(subtype), NULL, &esize);
        str_cat_c(atype, 128, tc(subtype));
        data = (byte_t *)array_create(esize, atype);
        break;
    }

    case ekDTYPE_ARRPTR:
    {
        char_t atype[128] = ARRPT;
        str_cat_c(atype, 128, tc(subtype));
        data = (byte_t *)array_create(sizeofptr, atype);
        break;
    }

    case ekDTYPE_STRING:
        data = (byte_t *)str_c("");
        break;

    case ekDTYPE_BOOL:
        data = (byte_t *)heap_new(bool_t);
        break;

    case ekDTYPE_INT8:
        data = (byte_t *)heap_new(int8_t);
        break;

    case ekDTYPE_INT16:
        data = (byte_t *)heap_new(int16_t);
        break;

    case ekDTYPE_INT32:
        data = (byte_t *)heap_new(int32_t);
        break;

    case ekDTYPE_INT64:
        data = (byte_t *)heap_new(int64_t);
        break;

    case ekDTYPE_UINT8:
        data = (byte_t *)heap_new(uint8_t);
        break;

    case ekDTYPE_UINT16:
        data = (byte_t *)heap_new(uint16_t);
        break;

    case ekDTYPE_UINT32:
        data = (byte_t *)heap_new(uint32_t);
        break;

    case ekDTYPE_UINT64:
        data = (byte_t *)heap_new(uint64_t);
        break;

    case ekDTYPE_REAL32:
        data = (byte_t *)heap_new(real32_t);
        break;

    case ekDTYPE_REAL64:
        data = (byte_t *)heap_new(real64_t);
        break;

    case ekDTYPE_ENUM:
        data = heap_malloc_imp(sizeof(enum_t), tc(subtype), TRUE);
        break;

    case ekDTYPE_STRING_PTR:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_msg(FALSE, "Dbind: Unexpected type in constructor.");
        break;
        cassert_default();
    }

    str_destopt(&subtype);
    return data;
}

/*---------------------------------------------------------------------------*/

void dbind_init_imp(byte_t *data, const char_t *type)
{
    uint16_t size;
    dtype_t dtype = i_data_type(type, NULL, &size);
    switch (dtype)
    {
    case ekDTYPE_BOOL:
        *((bool_t *)data) = FALSE;
        break;

    case ekDTYPE_INT8:
        *((int8_t *)data) = 0;
        break;

    case ekDTYPE_INT16:
        *((int16_t *)data) = 0;
        break;

    case ekDTYPE_INT32:
        *((int32_t *)data) = 0;
        break;

    case ekDTYPE_INT64:
        *((int64_t *)data) = 0;
        break;

    case ekDTYPE_UINT8:
        *((uint8_t *)data) = 0;
        break;

    case ekDTYPE_UINT16:
        *((uint16_t *)data) = 0;
        break;

    case ekDTYPE_UINT32:
        *((uint32_t *)data) = 0;
        break;

    case ekDTYPE_UINT64:
        *((uint64_t *)data) = 0;
        break;

    case ekDTYPE_REAL32:
        *((real32_t *)data) = 0;
        break;

    case ekDTYPE_REAL64:
        *((real64_t *)data) = 0;
        break;

    case ekDTYPE_ENUM:
        *((enum_t *)data) = (enum_t)0;
        break;

    case ekDTYPE_OBJECT:
    {
        StBind *stbind = i_find_stbind(type, NULL);
        bmem_set_zero(data, size);
        i_init_object(data, stbind, size);
        break;
    }

    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

static void i_destroy_array(Array **array, const char_t *type)
{
    cassert_no_null(array);
    if (*array != NULL)
    {
        String *subtype = NULL;
        uint16_t size;
        dtype_t dtype = i_data_type(type, &subtype, &size);
        char_t atype[128] = ARRST;
        if (dtype == ekDTYPE_OBJECT)
        {
            StBind *stbind = i_find_stbind(tc(subtype), NULL);
            byte_t *data = array_all(*array);
            uint32_t i, n = array_size(*array);
            cassert(size == array_esize(*array));
            for (i = 0; i < n; ++i, data += size)
                i_remove_object(data, stbind, size);
        }

        if (subtype != NULL)
        {
            str_cat_c(atype, 128, tc(subtype));
            str_destroy(&subtype);
        }
        else
        {
            str_cat_c(atype, 128, type);
        }

        cassert(subtype == NULL);
        array_destroy(array, NULL, atype);
    }
}

/*---------------------------------------------------------------------------*/

static void i_destroy_arrpt(Array **array, const char_t *type)
{
    cassert_no_null(array);
    if (*array != NULL)
    {
        String *subtype = NULL;
        uint16_t size;
        dtype_t dtype = i_data_type(type, &subtype, &size);
        char_t atype[128] = ARRPT;

        switch (dtype)
        {
        case ekDTYPE_OBJECT:
        {
            StBind *stbind = i_find_stbind(tc(subtype), NULL);
            byte_t *data = array_all(*array);
            uint32_t i, n = array_size(*array);
            cassert(sizeofptr == array_esize(*array));
            for (i = 0; i < n; ++i, data += sizeofptr)
                i_destroy_object((byte_t **)data, stbind, size);
            str_cat_c(atype, 128, tc(subtype));
            array_destroy(array, NULL, atype);
            str_destroy(&subtype);
            break;
        }

        case ekDTYPE_STRING:
            str_cat_c(atype, 128, "String");
            array_destroy_ptr(array, (FPtr_destroy)str_destopt, atype);
            break;

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
        case ekDTYPE_STRING_PTR:
        case ekDTYPE_ARRAY:
        case ekDTYPE_ARRPTR:
        case ekDTYPE_OBJECT_PTR:
        case ekDTYPE_OBJECT_OPAQUE:
        case ekDTYPE_UNKNOWN:
            cassert_default();
        }

        cassert(subtype == NULL);
    }
}

/*---------------------------------------------------------------------------*/

static void i_remove_object(byte_t *data, const StBind *stbind, const uint16_t size)
{
    cassert_no_null(stbind);
    cassert_unref(stbind->size == size, size);
    arrst_foreach(member, stbind->members, DBind)
        switch (member->type)
        {
        case ekDTYPE_OBJECT:
            i_remove_object(data + member->offset, member->attr.object.stbind, member->size);
            break;

        case ekDTYPE_OBJECT_PTR:
            i_destroy_object((byte_t **)(data + member->offset), member->attr.object.stbind, member->size);
            break;

        case ekDTYPE_OBJECT_OPAQUE:
        {
            byte_t **obj = (byte_t **)(data + member->offset);
            if (*obj != NULL)
            {
                StBind *mstb = i_find_stbind(i_subtype_str(member), NULL);
                cassert_no_null(mstb);
                cassert_no_nullf(mstb->func_destroy);
                mstb->func_destroy((void **)obj);
            }
            break;
        }

        case ekDTYPE_STRING_PTR:
            str_destopt((String **)(data + member->offset));
            break;

        case ekDTYPE_ARRAY:
            i_destroy_array((Array **)(data + member->offset), i_subtype_str(member));
            break;

        case ekDTYPE_ARRPTR:
            i_destroy_arrpt((Array **)(data + member->offset), i_subtype_str(member));
            break;

        case ekDTYPE_STRING:
            cassert_msg(FALSE, "dbind_destroy: Unexpected member type.");
            break;

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
        case ekDTYPE_UNKNOWN:
        default:
            break;
        }

    arrst_end()
}

/*---------------------------------------------------------------------------*/

void dbind_remove_imp(byte_t *data, const char_t *type)
{
    String *subtype = NULL;
    uint16_t size;
    dtype_t dtype;
    cassert_no_null(data);
    dtype = i_data_type(type, &subtype, &size);
    switch (dtype)
    {
    case ekDTYPE_OBJECT:
    {
        StBind *stbind = i_find_stbind(tc(subtype), NULL);
        i_remove_object(data, stbind, size);
        break;
    }

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
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
    default:
        break;
    }

    str_destopt(&subtype);
}

/*---------------------------------------------------------------------------*/

static void i_destroy_object(byte_t **data, const StBind *stbind, const uint16_t size)
{
    cassert_no_null(data);
    if (*data != NULL)
    {
        i_remove_object(*data, stbind, size);
        heap_free((byte_t **)data, size, tc(stbind->type));
    }
}

/*---------------------------------------------------------------------------*/

void dbind_destroy_imp(byte_t **data, const char_t *type)
{
    String *subtype = NULL;
    uint16_t size;
    dtype_t dtype;
    cassert_no_null(data);
    cassert_no_null(*data);
    dtype = i_data_type(type, &subtype, &size);
    switch (dtype)
    {
    case ekDTYPE_OBJECT:
    {
        StBind *stbind = i_find_stbind(tc(subtype), NULL);
        i_destroy_object(data, stbind, size);
        break;
    }
    case ekDTYPE_ARRAY:
        i_destroy_array((Array **)data, tc(subtype));
        break;
    case ekDTYPE_ARRPTR:
        i_destroy_arrpt((Array **)data, tc(subtype));
        break;
    case ekDTYPE_STRING:
        str_destopt((String **)data);
        break;
    case ekDTYPE_BOOL:
        heap_free(data, sizeof(bool_t), "bool_t");
        break;
    case ekDTYPE_INT8:
        heap_free(data, sizeof(int8_t), "int8_t");
        break;
    case ekDTYPE_INT16:
        heap_free(data, sizeof(int16_t), "int16_t");
        break;
    case ekDTYPE_INT32:
        heap_free(data, sizeof(int16_t), "int16_t");
        break;
    case ekDTYPE_INT64:
        heap_free(data, sizeof(int32_t), "int32_t");
        break;
    case ekDTYPE_UINT8:
        heap_free(data, sizeof(uint8_t), "uint8_t");
        break;
    case ekDTYPE_UINT16:
        heap_free(data, sizeof(uint16_t), "uint16_t");
        break;
    case ekDTYPE_UINT32:
        heap_free(data, sizeof(uint32_t), "uint32_t");
        break;
    case ekDTYPE_UINT64:
        heap_free(data, sizeof(uint64_t), "uint64_t");
        break;
    case ekDTYPE_REAL32:
        heap_free(data, sizeof(real32_t), "real32_t");
        break;
    case ekDTYPE_REAL64:
        heap_free(data, sizeof(real64_t), "real64_t");
        break;
    case ekDTYPE_ENUM:
        heap_free(data, sizeof(enum_t), tc(subtype));
        break;
    case ekDTYPE_OBJECT_OPAQUE:
    {
        StBind *stbind = i_find_stbind(tc(subtype), NULL);
        cassert_no_null(stbind);
        cassert_no_nullf(stbind->func_destroy);
        stbind->func_destroy((void **)data);
        break;
    }

    case ekDTYPE_STRING_PTR:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_UNKNOWN:
        cassert_msg(FALSE, "Dbind: Unexpected type in destructor.");
        break;

        cassert_default();
    }

    str_destopt(&subtype);
}

/*---------------------------------------------------------------------------*/

void dbind_destopt_imp(byte_t **data, const char_t *type)
{
    cassert_no_null(data);
    if (*data != NULL)
        dbind_destroy_imp(data, type);
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_array(Stream *stm, dtype_t type, const char_t *subtype, Array *array)
{
    bool_t ok = TRUE;
    uint32_t i, n = stm_read_u32(stm);
    for (i = 0; i < n; ++i)
    {
        byte_t *obj = array_insert(array, UINT32_MAX, 1);
        dbind_init_imp(obj, subtype);
        ok &= i_read_value(stm, NULL, type, subtype, obj);
    }

    return ok;
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_arrpt(Stream *stm, const char_t *type, Array *array)
{
    bool_t ok = TRUE;
    dtype_t dtype;
    String *subtype = NULL;
    uint32_t i, n = stm_read_u32(stm);
    dtype = i_data_type(type, &subtype, NULL);
    for (i = 0; i < n; ++i)
    {
        void *obj = dbind_create_imp(type);
        ok &= i_read_value(stm, NULL, dtype, tc(subtype), obj);
        if (ok == TRUE)
        {
            void **objins = (void **)array_insert(array, UINT32_MAX, 1);
            *objins = obj;
        }
    }

    str_destopt(&subtype);
    return ok;
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_object(Stream *stm, const char_t *type, void *object)
{
    bool_t ok = TRUE;
    if (object != NULL)
    {
        StBind *stbind = i_find_stbind(type, NULL);
        cassert_msg(stbind != NULL, "DBind: Unknown struct type.");
        arrst_foreach(member, stbind->members, DBind)
            dtype_t mtype = member->type;
            const char_t *mstype = i_subtype_str(member);
            uint16_t moffset = member->offset;
            ok &= i_read_value(stm, member, mtype, mstype, (void *)((byte_t *)object + moffset));
        arrst_end()
    }

    return ok;
}

/*---------------------------------------------------------------------------*/

static void i_read_opaque(Stream *stm, const char_t *type, void **data)
{
    StBind *stbind = i_find_stbind(type, NULL);
    uint32_t size = stm_read_u32(stm);
    void *obj = NULL;
    cassert(stbind->members == NULL);
    if (size > 0)
    {
        if (stbind->func_read != NULL)
        {
            uint64_t start = stm_bytes_readed(stm);
            obj = stbind->func_read(stm);
            cassert_unref((uint32_t)(stm_bytes_readed(stm) - start) == size, start);
        }
        else if (stbind->func_data != NULL)
        {
            byte_t *sdata = heap_malloc(size, "DBindReadOpaque");
            stm_read(stm, sdata, size);
            obj = stbind->func_data(sdata, size);
            heap_free(&sdata, size, "DBindReadOpaque");
        }
        else
        {
            stm_skip(stm, size);
        }
    }

    if (*data != NULL)
    {
        cassert_no_nullf(stbind->func_destroy);
        stbind->func_destroy(data);
    }

    *data = obj;
}

/*---------------------------------------------------------------------------*/

static bool_t i_read_value(Stream *stm, DBind *dbind, dtype_t type, const char_t *subtype, void *data)
{
    switch (type)
    {
    case ekDTYPE_BOOL:
        *((bool_t *)data) = stm_read_bool(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_INT8:
        *((int8_t *)data) = stm_read_i8(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_INT16:
        *((int16_t *)data) = stm_read_i16(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_INT32:
        *((int32_t *)data) = stm_read_i32(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_INT64:
        *((int64_t *)data) = stm_read_i64(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_UINT8:
        *((uint8_t *)data) = stm_read_u8(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_UINT16:
        *((uint16_t *)data) = stm_read_u16(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_UINT32:
        *((uint32_t *)data) = stm_read_u32(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_UINT64:
        *((uint64_t *)data) = stm_read_u64(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_REAL32:
        if (dbind != NULL)
        {
            real32_t value = stm_read_r32(stm);
            *((real32_t *)data) = dbind_real32(dbind, value);
        }
        else
        {
            *((real32_t *)data) = stm_read_r32(stm);
        }
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_REAL64:
        if (dbind != NULL)
        {
            real64_t value = stm_read_r64(stm);
            *((real64_t *)data) = dbind_real64(dbind, value);
        }
        else
        {
            *((real64_t *)data) = stm_read_r64(stm);
        }
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_ENUM:
        *((enum_t *)data) = stm_read_enum(stm, enum_t);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
        str_destopt((String **)data);
        *((String **)data) = str_read(stm);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_ARRAY:
    {
        uint16_t size;
        dtype_t dtype;
        cassert(*(Array **)data != NULL);
        cassert(array_size(*(Array **)data) == 0);
        dtype = i_data_type(subtype, NULL, &size);
        cassert(size == array_esize(*(Array **)data));
        return i_read_array(stm, dtype, subtype, *((Array **)data));
    }

    case ekDTYPE_ARRPTR:
        cassert(*(Array **)data != NULL);
        cassert(array_size(*(Array **)data) == 0);
        cassert(sizeofptr == array_esize(*(Array **)data));
        return i_read_arrpt(stm, subtype, *(Array **)data);

    case ekDTYPE_OBJECT:
        return i_read_object(stm, subtype, data);

    case ekDTYPE_OBJECT_PTR:
        cassert_msg(i_find_stbind(subtype, NULL) != NULL, "DBind unknown struct type");
        cassert(*(void **)data == NULL);
        *(void **)data = dbind_create_imp(subtype);
        return i_read_object(stm, subtype, *(void **)data);

    case ekDTYPE_OBJECT_OPAQUE:
        i_read_opaque(stm, subtype, (void **)data);
        return (bool_t)(stm_state(stm) == ekSTOK);

    case ekDTYPE_UNKNOWN:
        cassert_default();
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static byte_t *i_create_btype(Stream *stm, dtype_t dtype, const char_t *subtype)
{
    byte_t *obj = dbind_create_imp(subtype);
    if (i_read_value(stm, NULL, dtype, subtype, obj) == FALSE)
        dbind_destroy_imp(&obj, subtype);
    return obj;
}

/*---------------------------------------------------------------------------*/

static void *i_create_type(Stream *stm, const char_t *type)
{
    String *subtype = NULL;
    uint16_t size;
    dtype_t dtype;
    byte_t *obj = NULL;

    dtype = i_data_type(type, &subtype, &size);
    switch (dtype)
    {
    case ekDTYPE_OBJECT:
        cassert(size > 0);
        cassert_no_null(subtype);
        obj = dbind_create_imp(type);
        if (i_read_value(stm, NULL, dtype, tc(subtype), obj) == FALSE)
            dbind_destroy_imp(&obj, type);
        break;

    case ekDTYPE_ARRAY:
    {
        StBind *stbind = i_find_stbind(tc(subtype), NULL);
        uint16_t adsize;
        dtype_t adtype;
        Array *array;
        cassert_msg(FALSE, "Not implemented");
        cassert_msg(stbind != NULL, "DBind unknown type");
        array = array_create(stbind->size, tc(subtype));
        adtype = i_data_type(tc(subtype), NULL, &adsize);
        if (i_read_array(stm, adtype, tc(subtype), array) == TRUE)
        {
            obj = (byte_t *)array;
        }
        else
        {
            /* Destroy the array */
            cassert_msg(FALSE, "Not implemented");
        }
        break;
    }

    case ekDTYPE_ARRPTR:
    {
        char_t atype[128] = ARRPT;
        Array *array;
        cassert_msg(i_find_stbind(tc(subtype), NULL) != NULL, "DBind unknown type");
        str_cat_c(atype, 128, tc(subtype));
        array = array_create(sizeofptr, atype);
        if (i_read_arrpt(stm, tc(subtype), array) == TRUE)
        {
            obj = (byte_t *)array;
        }
        else
        {
            /* Destroy the array */
            cassert_msg(FALSE, "Not implemented");
        }
        break;
    }

    case ekDTYPE_BOOL:
        obj = i_create_btype(stm, dtype, "bool_t");
        break;

    case ekDTYPE_INT8:
        obj = i_create_btype(stm, dtype, "int8_t");
        break;

    case ekDTYPE_INT16:
        obj = i_create_btype(stm, dtype, "int16_t");
        break;

    case ekDTYPE_INT32:
        obj = i_create_btype(stm, dtype, "int32_t");
        break;

    case ekDTYPE_INT64:
        obj = i_create_btype(stm, dtype, "int64_t");
        break;

    case ekDTYPE_UINT8:
        obj = i_create_btype(stm, dtype, "uint8_t");
        break;

    case ekDTYPE_UINT16:
        obj = i_create_btype(stm, dtype, "uint16_t");
        break;

    case ekDTYPE_UINT32:
        obj = i_create_btype(stm, dtype, "uint32_t");
        break;

    case ekDTYPE_UINT64:
        obj = i_create_btype(stm, dtype, "uint64_t");
        break;

    case ekDTYPE_REAL32:
        obj = i_create_btype(stm, dtype, "real32_t");
        break;

    case ekDTYPE_REAL64:
        obj = i_create_btype(stm, dtype, "real64_t");
        break;

    case ekDTYPE_ENUM:
        obj = dbind_create_imp(tc(subtype));
        if (i_read_value(stm, NULL, dtype, tc(subtype), obj) == FALSE)
            dbind_destroy_imp(&obj, tc(subtype));
        break;

    case ekDTYPE_STRING_PTR:
    case ekDTYPE_STRING:
        cassert_msg(FALSE, "Use str_read?");
        i_read_value(stm, NULL, dtype, NULL, (String **)&obj);
        break;

    case ekDTYPE_OBJECT_PTR:
        cassert_msg(FALSE, "DBind double pointer to object");
        break;

    case ekDTYPE_UNKNOWN:
        cassert_msg(FALSE, "DBind unknown type");
        break;

    case ekDTYPE_OBJECT_OPAQUE:
        cassert_default();
    }

    str_destopt(&subtype);
    return obj;
}

/*---------------------------------------------------------------------------*/

void *dbind_read_imp(Stream *stm, const char_t *type)
{
    return i_create_type(stm, type);
}

/*---------------------------------------------------------------------------*/

static void i_write_object(Stream *stm, const void *object, const char_t *type)
{
    if (object != NULL)
    {
        StBind *stbind = i_find_stbind(type, NULL);
        cassert_msg(stbind != NULL, "DBind: Unknown struct type.");
        arrst_foreach(member, stbind->members, DBind)
            dtype_t mtype = member->type;
            const char_t *mstype = i_subtype_str(member);
            uint16_t moffset = member->offset;
            i_write_value(stm, member, mtype, mstype, (const void *)((byte_t *)object + moffset));
        arrst_end()
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_opaque(Stream *stm, const void *object, const char_t *type)
{
    if (object != NULL)
    {
        StBind *stbind = i_find_stbind(type, NULL);
        if (stbind != NULL)
        {
            cassert(stbind->members == NULL);
            if (stbind->func_buffer != NULL)
            {
                Buffer *buffer = stbind->func_buffer(object);
                const byte_t *data = buffer_data(buffer);
                uint32_t size = buffer_size(buffer);
                stm_write_u32(stm, size);
                stm_write(stm, data, size);
                buffer_destroy(&buffer);
            }
            else if (stbind->func_write != NULL)
            {
                Stream *mstm = stm_memory(16386);
                const byte_t *data;
                uint32_t size;
                stbind->func_write(mstm, object);
                data = stm_buffer(mstm);
                size = stm_buffer_size(mstm);
                stm_write_u32(stm, size);
                stm_write(stm, data, size);
                stm_close(&mstm);
            }
            else
            {
                stm_write_u32(stm, 0);
            }
        }
        else
        {
            stm_write_u32(stm, 0);
        }
    }
    else
    {
        stm_write_u32(stm, 0);
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
        dtype_t atype = i_data_type(type, &subtype, NULL);
        const char_t *stype = subtype != NULL ? tc(subtype) : NULL;
        stm_write_u32(stm, n);
        for (i = 0; i < n; ++i, data += es)
            i_write_value(stm, NULL, atype, stype, (const void *)data);
        str_destopt(&subtype);
    }
    else
    {
        stm_write_u32(stm, 0);
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
        stm_write_u32(stm, n);
        if (atype == ekDTYPE_STRING)
        {
            for (i = 0; i < n; ++i, data += sizeofptr)
                str_write(stm, *(String **)data);
        }
        else if (atype == ekDTYPE_OBJECT)
        {
            for (i = 0; i < n; ++i, data += sizeofptr)
                i_write_object(stm, *(const void **)data, stype);
        }
        else if (atype == ekDTYPE_OBJECT_OPAQUE)
        {
            for (i = 0; i < n; ++i, data += sizeofptr)
                i_write_opaque(stm, *(const void **)data, stype);
        }
        else
        {
            cassert_msg(FALSE, "DBind: Invalid ArrPt type.");
        }

        str_destopt(&subtype);
    }
    else
    {
        stm_write_u32(stm, 0);
    }
}

/*---------------------------------------------------------------------------*/

static void i_write_value(Stream *stm, DBind *dbind, dtype_t type, const char_t *subtype, const void *data)
{
    cassert_no_null(data);
    switch (type)
    {
    case ekDTYPE_BOOL:
        stm_write_bool(stm, *(bool_t *)data);
        break;
    case ekDTYPE_INT8:
        stm_write_i8(stm, *(int8_t *)data);
        break;
    case ekDTYPE_INT16:
        stm_write_i16(stm, *(int16_t *)data);
        break;
    case ekDTYPE_INT32:
        stm_write_i32(stm, *(int32_t *)data);
        break;
    case ekDTYPE_INT64:
        stm_write_i64(stm, *(int64_t *)data);
        break;
    case ekDTYPE_UINT8:
        stm_write_u8(stm, *(uint8_t *)data);
        break;
    case ekDTYPE_UINT16:
        stm_write_u16(stm, *(uint16_t *)data);
        break;
    case ekDTYPE_UINT32:
        stm_write_u32(stm, *(uint32_t *)data);
        break;
    case ekDTYPE_UINT64:
        stm_write_u64(stm, *(uint64_t *)data);
        break;
    case ekDTYPE_REAL32:
        stm_write_r32(stm, *(real32_t *)data);
        break;
    case ekDTYPE_REAL64:
        stm_write_r64(stm, *(real64_t *)data);
        break;
    case ekDTYPE_ENUM:
    {
        enum_t edata = *(enum_t *)data;
        stm_write_enum(stm, edata, enum_t);
        break;
    }
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
        str_write(stm, *(String **)data);
        break;
    case ekDTYPE_ARRAY:
        if (dbind != NULL)
            i_write_array(stm, *(Array **)data, subtype);
        else
            i_write_array(stm, (Array *)data, subtype);
        break;
    case ekDTYPE_ARRPTR:
        if (dbind != NULL)
            i_write_arrpt(stm, *(Array **)data, subtype);
        else
            i_write_arrpt(stm, (Array *)data, subtype);
        break;
    case ekDTYPE_OBJECT:
        i_write_object(stm, data, subtype);
        break;
    case ekDTYPE_OBJECT_PTR:
        i_write_object(stm, *(const void **)data, subtype);
        break;
    case ekDTYPE_OBJECT_OPAQUE:
        i_write_opaque(stm, *(const void **)data, subtype);
        break;
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void dbind_write_imp(Stream *stm, const void *data, const char_t *type)
{
    String *subtype = NULL;
    dtype_t dtype = i_data_type(type, &subtype, NULL);
    i_write_value(stm, NULL, dtype, subtype != NULL ? tc(subtype) : NULL, data);
    str_destopt(&subtype);
}

/*---------------------------------------------------------------------------*/

static DBind *i_find_by_name(ArrSt(DBind) *members, const char_t *name)
{
    arrst_foreach(member, members, DBind)
        if (str_equ_c(tc(member->name), name) == TRUE)
            return member;
    arrst_end()
    return NULL;
}

/*---------------------------------------------------------------------------*/

static DBind *i_member(const char_t *type, const char_t *name)
{
    StBind *stbind = i_find_stbind(type, NULL);
    if (stbind == NULL)
        return NULL;
    return i_find_by_name(stbind->members, name);
}

/*---------------------------------------------------------------------------*/

void dbind_default_imp(const char_t *type, const char_t *mname, const void *value)
{
    DBind *dbind = i_member(type, mname);
    cassert_no_null(dbind);
    cassert_no_null(value);
    switch (dbind->type)
    {
    case ekDTYPE_BOOL:
        dbind->attr.boolt.def = *(bool_t *)value;
        break;

    case ekDTYPE_INT8:
        dbind->attr.intt.def = *(int8_t *)value;
        break;

    case ekDTYPE_INT16:
        dbind->attr.intt.def = *(int16_t *)value;
        break;

    case ekDTYPE_INT32:
        dbind->attr.intt.def = *(int32_t *)value;
        break;

    case ekDTYPE_INT64:
        dbind->attr.intt.def = *(int64_t *)value;
        break;

    case ekDTYPE_UINT8:
        dbind->attr.intt.def = *(uint8_t *)value;
        break;

    case ekDTYPE_UINT16:
        dbind->attr.intt.def = *(uint16_t *)value;
        break;

    case ekDTYPE_UINT32:
        dbind->attr.intt.def = *(uint32_t *)value;
        break;

    case ekDTYPE_UINT64:
        dbind->attr.intt.def = (int64_t)(*(uint64_t *)value);
        break;

    case ekDTYPE_REAL32:
        dbind->attr.real32t.def = *(real32_t *)value;
        break;

    case ekDTYPE_REAL64:
        dbind->attr.real64t.def = *(real64_t *)value;
        break;

    case ekDTYPE_ENUM:
        dbind->attr.enumt.def = *(enum_t *)value;
        break;

    case ekDTYPE_STRING:
    {
        dbind->attr.stringt.def = str_c(*(const char_t **)value);
        break;
    }

    case ekDTYPE_OBJECT_OPAQUE:
    {
        const void *obj = *((const void **)value);
        if (dbind->attr.object.def != NULL)
        {
            cassert_no_null(dbind->attr.object.stbind);
            cassert_no_nullf(dbind->attr.object.stbind->func_destroy);
            dbind->attr.object.stbind->func_destroy(&dbind->attr.object.def);
        }

        if (obj != NULL)
        {
            cassert_no_nullf(dbind->attr.object.stbind->func_copy);
            dbind->attr.object.def = dbind->attr.object.stbind->func_copy(obj);
        }
        break;
    }

    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_UNKNOWN:
    default:
        break;
    }
}

/*---------------------------------------------------------------------------*/

void dbind_range_imp(const char_t *type, const char_t *mname, const void *min, const void *max)
{
    DBind *dbind = i_member(type, mname);
    cassert_no_null(dbind);
    cassert_no_null(min);
    cassert_no_null(max);
    switch (dbind->type)
    {

    case ekDTYPE_INT8:
        dbind->attr.intt.min = *(int8_t *)min;
        dbind->attr.intt.max = *(int8_t *)max;
        break;

    case ekDTYPE_INT16:
        dbind->attr.intt.min = *(int16_t *)min;
        dbind->attr.intt.max = *(int16_t *)max;
        break;

    case ekDTYPE_INT32:
        dbind->attr.intt.min = *(int32_t *)min;
        dbind->attr.intt.max = *(int32_t *)max;
        break;

    case ekDTYPE_INT64:
        dbind->attr.intt.min = *(int64_t *)min;
        dbind->attr.intt.max = *(int64_t *)max;
        break;

    case ekDTYPE_UINT8:
        dbind->attr.intt.min = *(uint8_t *)min;
        dbind->attr.intt.max = *(uint8_t *)max;
        break;

    case ekDTYPE_UINT16:
        dbind->attr.intt.min = *(uint16_t *)min;
        dbind->attr.intt.max = *(uint16_t *)max;
        break;

    case ekDTYPE_UINT32:
        dbind->attr.intt.min = *(uint32_t *)min;
        dbind->attr.intt.max = *(uint32_t *)max;
        break;

    case ekDTYPE_UINT64:
        dbind->attr.intt.min = (int64_t)(*(uint64_t *)min);
        dbind->attr.intt.max = (int64_t)(*(uint64_t *)max);
        break;

    case ekDTYPE_REAL32:
        dbind->attr.real32t.min = *(real32_t *)min;
        dbind->attr.real32t.max = *(real32_t *)max;
        break;

    case ekDTYPE_REAL64:
        dbind->attr.real64t.min = *(real64_t *)min;
        dbind->attr.real64t.max = *(real64_t *)max;
        break;

    case ekDTYPE_BOOL:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void dbind_precision_imp(const char_t *type, const char_t *mname, const void *prec)
{
    DBind *dbind = i_member(type, mname);
    cassert_no_null(dbind);
    cassert_no_null(prec);
    switch (dbind->type)
    {

    case ekDTYPE_REAL32:
        dbind->attr.real32t.prec = *(real32_t *)prec;
        dbind->attr.real32t.dec = bmath_precf(dbind->attr.real32t.prec);
        str_destroy(&dbind->attr.real32t.format);
        dbind->attr.real32t.format = str_printf("%%.%df", dbind->attr.real32t.dec);
        break;

    case ekDTYPE_REAL64:
        dbind->attr.real64t.prec = *(real64_t *)prec;
        dbind->attr.real64t.dec = bmath_precd(dbind->attr.real64t.prec);
        str_destroy(&dbind->attr.real64t.format);
        dbind->attr.real64t.format = str_printf("%%.%df", dbind->attr.real64t.dec);
        break;

    case ekDTYPE_BOOL:
    case ekDTYPE_INT8:
    case ekDTYPE_INT16:
    case ekDTYPE_INT32:
    case ekDTYPE_INT64:
    case ekDTYPE_UINT8:
    case ekDTYPE_UINT16:
    case ekDTYPE_UINT32:
    case ekDTYPE_UINT64:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void dbind_increment_imp(const char_t *type, const char_t *mname, const void *incr)
{
    DBind *dbind = i_member(type, mname);
    cassert_no_null(dbind);
    cassert_no_null(incr);
    switch (dbind->type)
    {

    case ekDTYPE_INT8:
        dbind->attr.intt.incr = *(int8_t *)incr;
        break;

    case ekDTYPE_INT16:
        dbind->attr.intt.incr = *(int16_t *)incr;
        break;

    case ekDTYPE_INT32:
        dbind->attr.intt.incr = *(int32_t *)incr;
        break;

    case ekDTYPE_INT64:
        dbind->attr.intt.incr = *(int64_t *)incr;
        break;

    case ekDTYPE_UINT8:
        dbind->attr.intt.incr = *(uint8_t *)incr;
        break;

    case ekDTYPE_UINT16:
        dbind->attr.intt.incr = *(uint16_t *)incr;
        break;

    case ekDTYPE_UINT32:
        dbind->attr.intt.incr = *(uint32_t *)incr;
        break;

    case ekDTYPE_UINT64:
        dbind->attr.intt.incr = (int64_t)(*(uint64_t *)incr);
        break;

    case ekDTYPE_REAL32:
        dbind->attr.real32t.incr = *(real32_t *)incr;
        break;

    case ekDTYPE_REAL64:
        dbind->attr.real64t.incr = *(real64_t *)incr;
        break;

    case ekDTYPE_BOOL:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

void dbind_suffix_imp(const char_t *type, const char_t *mname, const char_t *suffix)
{
    DBind *dbind = i_member(type, mname);
    cassert_no_null(dbind);
    switch (dbind->type)
    {

    case ekDTYPE_INT8:
    case ekDTYPE_INT16:
    case ekDTYPE_INT32:
    case ekDTYPE_INT64:
    case ekDTYPE_UINT8:
    case ekDTYPE_UINT16:
    case ekDTYPE_UINT32:
    case ekDTYPE_UINT64:
        str_destroy(&dbind->attr.intt.format);
        if (str_empty_c(suffix) == TRUE)
            dbind->attr.intt.format = str_printf("%%u");
        else
            dbind->attr.intt.format = str_printf("%%u %s", suffix);
        break;

    case ekDTYPE_REAL32:
        str_destroy(&dbind->attr.real32t.format);
        if (str_empty_c(suffix) == TRUE)
            dbind->attr.real32t.format = str_printf("%%.%df", dbind->attr.real32t.dec);
        else
            dbind->attr.real32t.format = str_printf("%%.%df %s", dbind->attr.real32t.dec, suffix);
        break;

    case ekDTYPE_REAL64:
        str_destroy(&dbind->attr.real64t.format);
        if (str_empty_c(suffix) == TRUE)
            dbind->attr.real64t.format = str_printf("%%.%df", dbind->attr.real64t.dec);
        else
            dbind->attr.real64t.format = str_printf("%%.%df %s", dbind->attr.real64t.dec, suffix);
        break;

    case ekDTYPE_BOOL:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        cassert_default();
    }
}

/*---------------------------------------------------------------------------*/

dtype_t dbind_data_type(const char_t *type, String **subtype, uint16_t *size)
{
    return i_data_type(type, subtype, size);
}

/*---------------------------------------------------------------------------*/

const StBind *dbind_stbind(const char_t *type)
{
    return i_find_stbind(type, NULL);
}

/*---------------------------------------------------------------------------*/

const char_t *dbind_stbind_type(const StBind *stbind)
{
    cassert_no_null(stbind);
    return tc(stbind->type);
}

/*---------------------------------------------------------------------------*/

uint16_t dbind_stbind_sizeof(const StBind *stbind)
{
    cassert_no_null(stbind);
    return stbind->size;
}

/*---------------------------------------------------------------------------*/

uint32_t dbind_stbind_count(const StBind *stbind)
{
    cassert_no_null(stbind);
    return arrst_size(stbind->members, DBind);
}

/*---------------------------------------------------------------------------*/

const DBind *dbind_stbind_member(const StBind *stbind, const uint32_t i)
{
    cassert_no_null(stbind);
    return arrst_get(stbind->members, i, DBind);
}

/*---------------------------------------------------------------------------*/

const DBind *dbind_stbind_find(const StBind *stbind, const char_t *name)
{
    cassert_no_null(stbind);
    return i_find_by_name(stbind->members, name);
}

/*---------------------------------------------------------------------------*/

void dbind_stbind_opaque(const StBind *stbind, const byte_t *data, const uint32_t size, void **obj)
{
    /* Create an opaque object from data */
    cassert_no_null(stbind);
    cassert_no_null(obj);
    cassert(stbind->members == NULL);
    if (*obj != NULL)
    {
        cassert_no_nullf(stbind->func_destroy);
        stbind->func_destroy(obj);
    }

    if (stbind->func_data != NULL)
    {
        *obj = stbind->func_data(data, size);
    }
    else if (stbind->func_read != NULL)
    {
        Stream *stm = stm_from_block(data, size);
        *obj = stbind->func_read(stm);
        stm_close(&stm);
    }
}

/*---------------------------------------------------------------------------*/

void dbind_stbind_opaque_upd(const StBind *stbind, void *new_obj, void **obj)
{
    cassert_no_null(stbind);
    cassert(stbind->members == NULL);
    cassert_no_null(obj);
    if (*obj != NULL)
    {
        cassert_no_nullf(stbind->func_destroy);
        stbind->func_destroy(obj);
    }

    if (new_obj != NULL)
    {
        cassert_no_nullf(stbind->func_copy);
        *obj = stbind->func_copy(new_obj);
    }
}

/*---------------------------------------------------------------------------*/

void dbind_stbind_opaque_write(const StBind *stbind, const void *obj, Stream *stm)
{
    cassert_no_null(stbind);
    cassert(stbind->members == NULL);
    cassert_no_nullf(stbind->func_write);
    stbind->func_write(stm, obj);
}

/*---------------------------------------------------------------------------*/

dtype_t dbind_type(const DBind *dbind)
{
    cassert_no_null(dbind);
    return dbind->type;
}

/*---------------------------------------------------------------------------*/

const char_t *dbind_name(const DBind *dbind)
{
    cassert_no_null(dbind);
    return tc(dbind->name);
}

/*---------------------------------------------------------------------------*/

uint16_t dbind_offset(const DBind *dbind)
{
    cassert_no_null(dbind);
    return dbind->offset;
}

/*---------------------------------------------------------------------------*/

uint16_t dbind_sizeof(const DBind *dbind)
{
    cassert_no_null(dbind);
    return dbind->size;
}

/*---------------------------------------------------------------------------*/

const char_t *dbind_subtype(const DBind *dbind)
{
    cassert_no_null(dbind);
    return i_subtype_str(dbind);
}

/*---------------------------------------------------------------------------*/

const StBind *dbind_get_stbind(const DBind *dbind)
{
    cassert_no_null(dbind);
    return dbind->stbind;
}

/*---------------------------------------------------------------------------*/

const char_t *dbind_real32_format(const DBind *dbind)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL32);
    return tc(dbind->attr.real32t.format);
}

/*---------------------------------------------------------------------------*/

const char_t *dbind_real64_format(const DBind *dbind)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL64);
    return tc(dbind->attr.real64t.format);
}

/*---------------------------------------------------------------------------*/

void dbind_real32_range(const DBind *dbind, real32_t *min, real32_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL32);
    cassert_no_null(min);
    cassert_no_null(max);
    *min = dbind->attr.real32t.min;
    *max = dbind->attr.real32t.max;
}

/*---------------------------------------------------------------------------*/

void dbind_real64_range(const DBind *dbind, real64_t *min, real64_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL64);
    cassert_no_null(min);
    cassert_no_null(max);
    *min = dbind->attr.real64t.min;
    *max = dbind->attr.real64t.max;
}

/*---------------------------------------------------------------------------*/

void dbind_int8_range(const DBind *dbind, int8_t *min, int8_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT8);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= INT8_MIN);
    cassert(dbind->attr.intt.max <= INT8_MAX);
    *min = (int8_t)dbind->attr.intt.min;
    *max = (int8_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

void dbind_int16_range(const DBind *dbind, int16_t *min, int16_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT16);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= INT16_MIN);
    cassert(dbind->attr.intt.max <= INT16_MAX);
    *min = (int16_t)dbind->attr.intt.min;
    *max = (int16_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

void dbind_int32_range(const DBind *dbind, int32_t *min, int32_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT32);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= INT32_MIN);
    cassert(dbind->attr.intt.max <= INT32_MAX);
    *min = (int32_t)dbind->attr.intt.min;
    *max = (int32_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

void dbind_int64_range(const DBind *dbind, int64_t *min, int64_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT64);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= INT64_MIN);
    cassert(dbind->attr.intt.max <= INT64_MAX);
    *min = (int64_t)dbind->attr.intt.min;
    *max = (int64_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

void dbind_uint8_range(const DBind *dbind, uint8_t *min, uint8_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT8);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= 0);
    cassert(dbind->attr.intt.max <= UINT8_MAX);
    *min = (uint8_t)dbind->attr.intt.min;
    *max = (uint8_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

void dbind_uint16_range(const DBind *dbind, uint16_t *min, uint16_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT16);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= 0);
    cassert(dbind->attr.intt.max <= UINT16_MAX);
    *min = (uint16_t)dbind->attr.intt.min;
    *max = (uint16_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

void dbind_uint32_range(const DBind *dbind, uint32_t *min, uint32_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT32);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= 0);
    cassert(dbind->attr.intt.max <= UINT32_MAX);
    *min = (uint32_t)dbind->attr.intt.min;
    *max = (uint32_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

void dbind_uint64_range(const DBind *dbind, uint64_t *min, uint64_t *max)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT64);
    cassert_no_null(min);
    cassert_no_null(max);
    cassert(dbind->attr.intt.min >= 0);
    cassert(dbind->attr.intt.max <= INT64_MAX);
    *min = (uint64_t)dbind->attr.intt.min;
    *max = (uint64_t)dbind->attr.intt.max;
}

/*---------------------------------------------------------------------------*/

real32_t dbind_real32(const DBind *dbind, const real32_t value)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL32);
    if (value != REAL32_MAX)
    {
        real32_t v = bmath_clampf(value, dbind->attr.real32t.min, dbind->attr.real32t.max);
        return bmath_round_stepf(v, dbind->attr.real32t.prec);
    }

    return value;
}

/*---------------------------------------------------------------------------*/

real64_t dbind_real64(const DBind *dbind, const real64_t value)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL64);
    if (value != REAL64_MAX)
    {
        real64_t v = bmath_clampd(value, dbind->attr.real64t.min, dbind->attr.real64t.max);
        return bmath_round_stepd(v, dbind->attr.real64t.prec);
    }

    return value;
}

/*---------------------------------------------------------------------------*/

static __INLINE int64_t i_int(const DBind *dbind, const dtype_t type, const int64_t value, const int64_t min, const int64_t max)
{
    cassert_no_null(dbind);
    cassert_unref(dbind->type == type, type);
    cassert_unref(dbind->attr.intt.min >= min, min);
    cassert_unref(dbind->attr.intt.max <= max, max);
    if (value < dbind->attr.intt.min)
        return dbind->attr.intt.min;
    else if (value > dbind->attr.intt.max)
        return dbind->attr.intt.max;
    else
        return value;
}

/*---------------------------------------------------------------------------*/

int8_t dbind_int8(const DBind *dbind, const int8_t value)
{
    return (int8_t)i_int(dbind, ekDTYPE_INT8, (int64_t)value, INT8_MIN, INT8_MAX);
}

/*---------------------------------------------------------------------------*/

int16_t dbind_int16(const DBind *dbind, const int16_t value)
{
    return (int16_t)i_int(dbind, ekDTYPE_INT16, (int64_t)value, INT16_MIN, INT16_MAX);
}

/*---------------------------------------------------------------------------*/

int32_t dbind_int32(const DBind *dbind, const int32_t value)
{
    return (int32_t)i_int(dbind, ekDTYPE_INT32, (int64_t)value, INT32_MIN, INT32_MAX);
}

/*---------------------------------------------------------------------------*/

int64_t dbind_int64(const DBind *dbind, const int64_t value)
{
    return (int64_t)i_int(dbind, ekDTYPE_INT64, (int64_t)value, INT64_MIN, INT64_MAX);
}

/*---------------------------------------------------------------------------*/

uint8_t dbind_uint8(const DBind *dbind, const uint8_t value)
{
    return (uint8_t)i_int(dbind, ekDTYPE_UINT8, (int64_t)value, 0, UINT8_MAX);
}

/*---------------------------------------------------------------------------*/

uint16_t dbind_uint16(const DBind *dbind, const uint16_t value)
{
    return (uint16_t)i_int(dbind, ekDTYPE_UINT16, (int64_t)value, 0, UINT16_MAX);
}

/*---------------------------------------------------------------------------*/

uint32_t dbind_uint32(const DBind *dbind, const uint32_t value)
{
    return (uint32_t)i_int(dbind, ekDTYPE_UINT32, (int64_t)value, 0, UINT32_MAX);
}

/*---------------------------------------------------------------------------*/

uint64_t dbind_uint64(const DBind *dbind, const uint64_t value)
{
    return (uint64_t)i_int(dbind, ekDTYPE_UINT64, (int64_t)value, 0, INT64_MAX);
}

/*---------------------------------------------------------------------------*/

real32_t dbind_incr_real32(const DBind *dbind, const real32_t value, const bool_t pos)
{
    real32_t v = 0;
    real32_t sc = pos ? 1.f : -1.f;
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL32);
    v = bmath_clampf(value + sc * dbind->attr.real32t.incr, dbind->attr.real32t.min, dbind->attr.real32t.max);
    return bmath_round_stepf(v, dbind->attr.real32t.prec);
}

/*---------------------------------------------------------------------------*/

real64_t dbind_incr_real64(const DBind *dbind, const real64_t value, const bool_t pos)
{
    real64_t v = 0;
    real64_t sc = pos ? 1. : -1.;
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL64);
    v = bmath_clampd(value + sc * dbind->attr.real64t.incr, dbind->attr.real64t.min, dbind->attr.real64t.max);
    return bmath_round_stepd(v, dbind->attr.real64t.prec);
}

/*---------------------------------------------------------------------------*/

static __INLINE int64_t i_incr_int(const DBind *dbind, const int64_t value, const bool_t pos)
{
    int64_t v = pos ? value + dbind->attr.intt.incr : value - dbind->attr.intt.incr;
    if (v > dbind->attr.intt.max)
        return dbind->attr.intt.max;
    else if (v < dbind->attr.intt.min)
        return dbind->attr.intt.min;
    return v;
}

/*---------------------------------------------------------------------------*/

int8_t dbind_incr_int8(const DBind *dbind, const int8_t value, const bool_t pos)
{
    return (int8_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

int16_t dbind_incr_int16(const DBind *dbind, const int16_t value, const bool_t pos)
{
    return (int16_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

int32_t dbind_incr_int32(const DBind *dbind, const int32_t value, const bool_t pos)
{
    return (int32_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

int64_t dbind_incr_int64(const DBind *dbind, const int64_t value, const bool_t pos)
{
    return (int64_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

uint8_t dbind_incr_uint8(const DBind *dbind, const uint8_t value, const bool_t pos)
{
    return (uint8_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

uint16_t dbind_incr_uint16(const DBind *dbind, const uint16_t value, const bool_t pos)
{
    return (uint16_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

uint32_t dbind_incr_uint32(const DBind *dbind, const uint32_t value, const bool_t pos)
{
    return (uint32_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

uint64_t dbind_incr_uint64(const DBind *dbind, const uint64_t value, const bool_t pos)
{
    return (uint64_t)i_incr_int(dbind, (int64_t)value, pos);
}

/*---------------------------------------------------------------------------*/

bool_t dbind_string_filter(const DBind *dbind, const char_t *src, char_t *dest, const uint32_t size)
{
    cassert_no_null(dbind);
    switch (dbind->type)
    {
    case ekDTYPE_REAL32:
        tfilter_number(src, dest, size, dbind->attr.real32t.dec, (bool_t)(dbind->attr.real32t.min < 0));
        return TRUE;

    case ekDTYPE_REAL64:
        tfilter_number(src, dest, size, dbind->attr.real64t.dec, (bool_t)(dbind->attr.real64t.min < 0));
        return TRUE;

    case ekDTYPE_INT8:
    case ekDTYPE_INT16:
    case ekDTYPE_INT32:
    case ekDTYPE_INT64:
        tfilter_number(src, dest, size, 0, TRUE);
        return TRUE;

    case ekDTYPE_UINT8:
    case ekDTYPE_UINT16:
    case ekDTYPE_UINT32:
    case ekDTYPE_UINT64:
        tfilter_number(src, dest, size, 0, FALSE);
        return TRUE;

    case ekDTYPE_BOOL:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
    default:
        break;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

real32_t dbind_string_to_real32(const DBind *dbind, const real32_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL32);
    if (value == REAL32_MAX && str_empty_c(src) == TRUE)
    {
        return value;
    }
    else
    {
        real32_t val = str_to_r32(src, NULL);
        val = bmath_clampf(val, (real32_t)dbind->attr.real32t.min, (real32_t)dbind->attr.real32t.max);
        return bmath_round_stepf(val, (real32_t)dbind->attr.real32t.prec);
    }
}

/*---------------------------------------------------------------------------*/

real64_t dbind_string_to_real64(const DBind *dbind, const real64_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_REAL64);
    if (value == REAL64_MAX && str_empty_c(src) == TRUE)
    {
        return value;
    }
    else
    {
        real64_t val = str_to_r64(src, NULL);
        val = bmath_clampd(val, dbind->attr.real64t.min, dbind->attr.real64t.max);
        return bmath_round_stepd(val, dbind->attr.real64t.prec);
    }
}

/*---------------------------------------------------------------------------*/

int8_t dbind_string_to_int8(const DBind *dbind, const int8_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT8);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        int8_t val;
        tfilter_number(src, dest, sizeof(dest), 0, TRUE);
        val = str_to_i8(dest, 10, NULL);
        if (val < dbind->attr.intt.min)
            return (int8_t)dbind->attr.intt.min;
        else if (val > dbind->attr.intt.max)
            return (int8_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

int16_t dbind_string_to_int16(const DBind *dbind, const int16_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT16);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        int16_t val;
        tfilter_number(src, dest, sizeof(dest), 0, TRUE);
        val = str_to_i16(dest, 10, NULL);
        if (val < dbind->attr.intt.min)
            return (int16_t)dbind->attr.intt.min;
        else if (val > dbind->attr.intt.max)
            return (int16_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

int32_t dbind_string_to_int32(const DBind *dbind, const int32_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT32);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        int32_t val;
        tfilter_number(src, dest, sizeof(dest), 0, TRUE);
        val = str_to_i32(dest, 10, NULL);
        if (val < dbind->attr.intt.min)
            return (int32_t)dbind->attr.intt.min;
        else if (val > dbind->attr.intt.max)
            return (int32_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

int64_t dbind_string_to_int64(const DBind *dbind, const int64_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_INT64);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        int64_t val;
        tfilter_number(src, dest, sizeof(dest), 0, TRUE);
        val = str_to_i64(dest, 10, NULL);
        if (val < dbind->attr.intt.min)
            return (int64_t)dbind->attr.intt.min;
        else if (val > dbind->attr.intt.max)
            return (int64_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

uint8_t dbind_string_to_uint8(const DBind *dbind, const uint8_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT8);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        uint8_t val;
        tfilter_number(src, dest, sizeof(dest), 0, FALSE);
        val = str_to_u8(dest, 10, NULL);
        if (val < dbind->attr.intt.min)
            return (uint8_t)dbind->attr.intt.min;
        else if (val > dbind->attr.intt.max)
            return (uint8_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

uint16_t dbind_string_to_uint16(const DBind *dbind, const uint16_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT16);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        uint16_t val;
        tfilter_number(src, dest, sizeof(dest), 0, FALSE);
        val = str_to_u16(dest, 10, NULL);
        if (val < dbind->attr.intt.min)
            return (uint16_t)dbind->attr.intt.min;
        else if (val > dbind->attr.intt.max)
            return (uint16_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

uint32_t dbind_string_to_uint32(const DBind *dbind, const uint32_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT32);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        uint32_t val;
        tfilter_number(src, dest, sizeof(dest), 0, FALSE);
        val = str_to_u32(dest, 10, NULL);
        if (val < dbind->attr.intt.min)
            return (uint32_t)dbind->attr.intt.min;
        else if (val > dbind->attr.intt.max)
            return (uint32_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

uint64_t dbind_string_to_uint64(const DBind *dbind, const uint64_t value, const char_t *src)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_UINT64);
    unref(value);
    if (str_empty_c(src) == FALSE)
    {
        char_t dest[128];
        uint64_t val;
        tfilter_number(src, dest, sizeof(dest), 0, FALSE);
        val = str_to_u64(dest, 10, NULL);
        if (val < (uint64_t)dbind->attr.intt.min)
            return (uint64_t)dbind->attr.intt.min;
        else if (val > (uint64_t)dbind->attr.intt.max)
            return (uint64_t)dbind->attr.intt.max;
        else
            return val;
    }
    else
    {
        return value;
    }
}

/*---------------------------------------------------------------------------*/

void *dbind_opaque_default(const DBind *dbind)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_OBJECT_OPAQUE);
    return dbind->attr.object.def;
}

/*---------------------------------------------------------------------------*/

static bool_t i_is_basic_type(const dtype_t type)
{
    switch (type)
    {
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
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
        return TRUE;

    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
        return FALSE;

    case ekDTYPE_UNKNOWN:
        cassert_default();
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

static bool_t i_is_number(const dtype_t type)
{
    switch (type)
    {
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
        return TRUE;

    case ekDTYPE_BOOL:
    case ekDTYPE_ENUM:
    case ekDTYPE_STRING:
    case ekDTYPE_STRING_PTR:
    case ekDTYPE_ARRAY:
    case ekDTYPE_ARRPTR:
    case ekDTYPE_OBJECT:
    case ekDTYPE_OBJECT_PTR:
    case ekDTYPE_OBJECT_OPAQUE:
    case ekDTYPE_UNKNOWN:
        return FALSE;

        cassert_default();
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t dbind_is_basic_type(const DBind *dbind)
{
    cassert_no_null(dbind);
    return i_is_basic_type(dbind->type);
}

/*---------------------------------------------------------------------------*/

bool_t dbind_is_number_type(const DBind *dbind)
{
    cassert_no_null(dbind);
    return i_is_number(dbind->type);
}

/*---------------------------------------------------------------------------*/

uint32_t dbind_enum_count(const DBind *dbind)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_ENUM);
    return arrst_size(dbind->attr.enumt.ebind->values, EnumVBind);
}

/*---------------------------------------------------------------------------*/

enum_t dbind_enum_value(const DBind *dbind, const uint32_t index)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_ENUM);
    if (index < arrst_size(dbind->attr.enumt.ebind->values, EnumVBind))
    {
        const EnumVBind *ebind = arrst_get(dbind->attr.enumt.ebind->values, index, EnumVBind);
        return ebind->value;
    }

    return ENUM_MAX(enum_t);
}

/*---------------------------------------------------------------------------*/

const char_t *dbind_enum_alias(const DBind *dbind, const uint32_t index)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_ENUM);
    if (index < arrst_size(dbind->attr.enumt.ebind->values, EnumVBind))
    {
        const EnumVBind *ebind = arrst_get(dbind->attr.enumt.ebind->values, index, EnumVBind);
        return tc(ebind->alias);
    }

    return "";
}

/*---------------------------------------------------------------------------*/

uint32_t dbind_enum_index(const DBind *dbind, const enum_t value)
{
    cassert_no_null(dbind);
    cassert(dbind->type == ekDTYPE_ENUM);
    arrst_foreach(ebind, dbind->attr.enumt.ebind->values, EnumVBind)
        if (ebind->value == value)
            return ebind_i;
    arrst_end()
    return UINT32_MAX;
}

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dbind.h
 * https://nappgui.com/en/core/dbind.html
 *
 */

/* Data binding */

#include "core.hxx"

__EXTERN_C

_core_api void dbind_imp(const char_t *type, const uint16_t size, const char_t *mname, const char_t *mtype, const uint16_t moffset, const uint16_t msize);

_core_api void dbind_enum_imp(const char_t *type, const char_t *name, const enum_t value, const char_t *alias);

_core_api byte_t *dbind_create_imp(const char_t *type);

_core_api void dbind_init_imp(byte_t *data, const char_t *type);

_core_api void dbind_remove_imp(byte_t *data, const char_t *type);

_core_api void dbind_destroy_imp(byte_t **data, const char_t *type);

_core_api void dbind_destopt_imp(byte_t **data, const char_t *type);

_core_api void *dbind_read_imp(Stream *stm, const char_t *type);

_core_api void dbind_write_imp(Stream *stm, const void *data, const char_t *type);

_core_api void dbind_default_imp(const char_t *type, const char_t *mname, const void *value);

_core_api void dbind_range_imp(const char_t *type, const char_t *mname, const void *min, const void *max);

_core_api void dbind_precision_imp(const char_t *type, const char_t *mname, const void *prec);

_core_api void dbind_increment_imp(const char_t *type, const char_t *mname, const void *incr);

_core_api void dbind_suffix_imp(const char_t *type, const char_t *mname, const char_t *suffix);

__END_C

#define dbind(type, mtype, mname) \
    ( \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype), \
        dbind_imp( \
            (const char_t *)#type, \
            (uint16_t)sizeof(type), \
            (const char_t *)#mname, \
            (const char_t *)#mtype, \
            (uint16_t)STRUCT_MEMBER_OFFSET(type, mname), \
            (uint16_t)STRUCT_MEMBER_SIZE(type, mname)))

#define dbind_enum(type, value, alias) \
    ( \
        (void)(((type)value) == value), \
        dbind_enum_imp( \
            (const char_t *)#type, \
            (const char_t *)#value, \
            (enum_t)value, \
            alias))

#define dbind_create(type) \
    (type *)dbind_create_imp((const char_t *)#type)

#define dbind_init(data, type) \
    ((void)(data == (type *)data), \
     dbind_init_imp((byte_t *)data, (const char_t *)#type))

#define dbind_remove(data, type) \
    ((void)(data == (type *)data), \
     dbind_remove_imp((byte_t *)data, (const char_t *)#type))

#define dbind_destroy(data, type) \
    ((void)(data == (type **)data), \
     dbind_destroy_imp((byte_t **)data, (const char_t *)#type))

#define dbind_destopt(data, type) \
    ((void)(data == (type **)data), \
     dbind_destopt_imp((byte_t **)data, (const char_t *)#type))

#define dbind_read(stm, type) \
    (type *)dbind_read_imp(stm, (const char_t *)#type)

#define dbind_write(stm, data, type) \
    ((void)((const type *)data == data), \
     dbind_write_imp(stm, (const void *)data, (const char_t *)#type))

#define dbind_default(type, mtype, mname, value) \
    { \
        const mtype ___value = value; \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype); \
        dbind_default_imp( \
            (const char_t *)#type, \
            (const char_t *)#mname, \
            (void *)&___value); \
    }

#define dbind_range(type, mtype, mname, min, max) \
    { \
        mtype ___min = min; \
        mtype ___max = max; \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype); \
        dbind_range_imp( \
            (const char_t *)#type, \
            (const char_t *)#mname, \
            (void *)&___min, \
            (void *)&___max); \
    }

#define dbind_precision(type, mtype, mname, prec) \
    { \
        mtype ___prec = prec; \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype); \
        dbind_precision_imp( \
            (const char_t *)#type, \
            (const char_t *)#mname, \
            (void *)&___prec); \
    }

#define dbind_increment(type, mtype, mname, incr) \
    { \
        mtype ___incr = incr; \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype); \
        dbind_increment_imp( \
            (const char_t *)#type, \
            (const char_t *)#mname, \
            (void *)&___incr); \
    }

#define dbind_suffix(type, mtype, mname, suffix) \
    ( \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype), \
        dbind_suffix_imp( \
            (const char_t *)#type, \
            (const char_t *)#mname, \
            suffix))

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dbindh.h
 *
 */

/* 
* Undocumented (hidden) API to use DBind database 
* 
* StBind = Data binding with struct type
* DBind = Data binding with struct member
* 
*/

#include "coreh.hxx"

__EXTERN_C

_core_api void dbind_opaque_imp(const char_t *type, FPtr_data func_data, FPtr_buffer func_buffer, FPtr_copy func_copy, FPtr_read func_read, FPtr_write func_write, FPtr_destroy func_destroy);

_core_api void dbind_opaque_destroy(const char_t *object_type);

_core_api dtype_t dbind_data_type(const char_t *type, String **subtype, uint16_t *size);

_core_api const StBind *dbind_stbind(const char_t *type);

_core_api const char_t *dbind_stbind_type(const StBind *stbind);

_core_api uint16_t dbind_stbind_sizeof(const StBind *stbind);

_core_api uint32_t dbind_stbind_count(const StBind *stbind);

_core_api const DBind *dbind_stbind_member(const StBind *stbind, const uint32_t i);

_core_api const DBind *dbind_stbind_find(const StBind *stbind, const char_t *name);

_core_api void dbind_stbind_opaque(const StBind *stbind, const byte_t *data, const uint32_t size, void **obj);

_core_api void dbind_stbind_opaque_upd(const StBind *stbind, void *new_obj, void **obj);

_core_api void dbind_stbind_opaque_write(const StBind *stbind, const void *obj, Stream *stm);

_core_api dtype_t dbind_type(const DBind *dbind);

_core_api const char_t *dbind_name(const DBind *dbind);

_core_api uint16_t dbind_offset(const DBind *dbind);

_core_api uint16_t dbind_sizeof(const DBind *dbind);

_core_api const char_t *dbind_subtype(const DBind *dbind);

_core_api const StBind *dbind_get_stbind(const DBind *dbind);

_core_api const char_t *dbind_real32_format(const DBind *dbind);

_core_api const char_t *dbind_real64_format(const DBind *dbind);

_core_api void dbind_real32_range(const DBind *dbind, real32_t *min, real32_t *max);

_core_api void dbind_real64_range(const DBind *dbind, real64_t *min, real64_t *max);

_core_api void dbind_int8_range(const DBind *dbind, int8_t *min, int8_t *max);

_core_api void dbind_int16_range(const DBind *dbind, int16_t *min, int16_t *max);

_core_api void dbind_int32_range(const DBind *dbind, int32_t *min, int32_t *max);

_core_api void dbind_int64_range(const DBind *dbind, int64_t *min, int64_t *max);

_core_api void dbind_uint8_range(const DBind *dbind, uint8_t *min, uint8_t *max);

_core_api void dbind_uint16_range(const DBind *dbind, uint16_t *min, uint16_t *max);

_core_api void dbind_uint32_range(const DBind *dbind, uint32_t *min, uint32_t *max);

_core_api void dbind_uint64_range(const DBind *dbind, uint64_t *min, uint64_t *max);

_core_api real32_t dbind_real32(const DBind *dbind, const real32_t value);

_core_api real64_t dbind_real64(const DBind *dbind, const real64_t value);

_core_api int8_t dbind_int8(const DBind *dbind, const int8_t value);

_core_api int16_t dbind_int16(const DBind *dbind, const int16_t value);

_core_api int32_t dbind_int32(const DBind *dbind, const int32_t value);

_core_api int64_t dbind_int64(const DBind *dbind, const int64_t value);

_core_api uint8_t dbind_uint8(const DBind *dbind, const uint8_t value);

_core_api uint16_t dbind_uint16(const DBind *dbind, const uint16_t value);

_core_api uint32_t dbind_uint32(const DBind *dbind, const uint32_t value);

_core_api uint64_t dbind_uint64(const DBind *dbind, const uint64_t value);

_core_api real32_t dbind_incr_real32(const DBind *dbind, const real32_t value, const bool_t pos);

_core_api real64_t dbind_incr_real64(const DBind *dbind, const real64_t value, const bool_t pos);

_core_api int8_t dbind_incr_int8(const DBind *dbind, const int8_t value, const bool_t pos);

_core_api int16_t dbind_incr_int16(const DBind *dbind, const int16_t value, const bool_t pos);

_core_api int32_t dbind_incr_int32(const DBind *dbind, const int32_t value, const bool_t pos);

_core_api int64_t dbind_incr_int64(const DBind *dbind, const int64_t value, const bool_t pos);

_core_api uint8_t dbind_incr_uint8(const DBind *dbind, const uint8_t value, const bool_t pos);

_core_api uint16_t dbind_incr_uint16(const DBind *dbind, const uint16_t value, const bool_t pos);

_core_api uint32_t dbind_incr_uint32(const DBind *dbind, const uint32_t value, const bool_t pos);

_core_api uint64_t dbind_incr_uint64(const DBind *dbind, const uint64_t value, const bool_t pos);

_core_api bool_t dbind_string_filter(const DBind *dbind, const char_t *src, char_t *dest, const uint32_t size);

_core_api real32_t dbind_string_to_real32(const DBind *dbind, const real32_t value, const char_t *src);

_core_api real64_t dbind_string_to_real64(const DBind *dbind, const real64_t value, const char_t *src);

_core_api int8_t dbind_string_to_int8(const DBind *dbind, const int8_t value, const char_t *src);

_core_api int16_t dbind_string_to_int16(const DBind *dbind, const int16_t value, const char_t *src);

_core_api int32_t dbind_string_to_int32(const DBind *dbind, const int32_t value, const char_t *src);

_core_api int64_t dbind_string_to_int64(const DBind *dbind, const int64_t value, const char_t *src);

_core_api uint8_t dbind_string_to_uint8(const DBind *dbind, const uint8_t value, const char_t *src);

_core_api uint16_t dbind_string_to_uint16(const DBind *dbind, const uint16_t value, const char_t *src);

_core_api uint32_t dbind_string_to_uint32(const DBind *dbind, const uint32_t value, const char_t *src);

_core_api uint64_t dbind_string_to_uint64(const DBind *dbind, const uint64_t value, const char_t *src);

_core_api void *dbind_opaque_default(const DBind *dbind);

_core_api bool_t dbind_is_basic_type(const DBind *dbind);

_core_api bool_t dbind_is_number_type(const DBind *dbind);

_core_api uint32_t dbind_enum_count(const DBind *dbind);

_core_api enum_t dbind_enum_value(const DBind *dbind, const uint32_t index);

_core_api const char_t *dbind_enum_alias(const DBind *dbind, const uint32_t index);

_core_api uint32_t dbind_enum_index(const DBind *dbind, const enum_t value);

__END_C

#define dbind_opaque(type, func_data, func_buffer, func_copy, func_read, func_write, func_destroy) \
    ( \
        FUNC_CHECK_DATA(func_data, type), \
        FUNC_CHECK_BUFFER(func_buffer, type), \
        FUNC_CHECK_COPY(func_copy, type), \
        FUNC_CHECK_READ(func_read, type), \
        FUNC_CHECK_WRITE(func_write, type), \
        FUNC_CHECK_DESTROY(func_destroy, type), \
        dbind_opaque_imp( \
            (const char_t *)#type, \
            (FPtr_data)func_data, \
            (FPtr_buffer)func_buffer, \
            (FPtr_copy)func_copy, \
            (FPtr_read)func_read, \
            (FPtr_write)func_write, \
            (FPtr_destroy)func_destroy))

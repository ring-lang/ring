/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: strings.h
 *
 */

/* UTF8 strings */

#include "core.hxx"

__EXTERN_C

_core_api const char_t *tc(const String *str);

_core_api char_t *tcc(String *str);

_core_api String *str_c(const char_t *str);

_core_api String *str_cn(const char_t *str, const uint32_t n);

_core_api String *str_trim(const char_t *str);

_core_api String *str_trim_n(const char_t *str, const uint32_t n);

_core_api String *str_copy(const String *str);

_core_api String *str_printf(const char_t *format, ...) __PRINTF(1, 2);

_core_api String *str_path(const platform_t platform, const char_t *format, ...) __PRINTF(2, 3);

_core_api String *str_cpath(const char_t *format, ...) __PRINTF(1, 2);

_core_api String *str_relpath(const platform_t platform, const char_t *path1, const char_t *path2);

_core_api String *str_crelpath(const char_t *path1, const char_t *path2);

_core_api String *str_repl(const char_t *str, ...);

_core_api String *str_reserve(const uint32_t n);

_core_api String *str_fill(const uint32_t n, const char_t c);

_core_api String *str_read(Stream *stream);

_core_api void str_write(Stream *stream, const String *str);

_core_api void str_writef(Stream *stream, const String *str);

_core_api void str_copy_c(char_t *dest, const uint32_t size, const char_t *src);

_core_api void str_copy_cn(char_t *dest, const uint32_t size, const char_t *src, const uint32_t n);

_core_api void str_cat(String **dest, const char_t *src);

_core_api void str_cat_c(char_t *dest, const uint32_t size, const char_t *src);

_core_api void str_upd(String **str, const char_t *new_str);

_core_api void str_destroy(String **str);

_core_api void str_destopt(String **str);

_core_api uint32_t str_len(const String *str);

_core_api uint32_t str_len_c(const char_t *str);

_core_api uint32_t str_nchars(const String *str);

_core_api uint32_t str_prefix(const char_t *str1, const char_t *str2);

_core_api bool_t str_is_prefix(const char_t *str, const char_t *prefix);

_core_api bool_t str_is_sufix(const char_t *str, const char_t *sufix);

_core_api int str_scmp(const String *str1, const String *str2);

_core_api int str_cmp(const String *str1, const char_t *str2);

_core_api int str_cmp_c(const char_t *str1, const char_t *str2);

_core_api int str_cmp_cn(const char_t *str1, const char_t *str2, const uint32_t n);

_core_api bool_t str_empty(const String *str);

_core_api bool_t str_empty_c(const char_t *str);

_core_api bool_t str_equ(const String *str1, const char_t *str2);

_core_api bool_t str_equ_c(const char_t *str1, const char_t *str2);

_core_api bool_t str_equ_cn(const char_t *str1, const char_t *str2, const uint32_t n);

_core_api bool_t str_equ_nocase(const char_t *str1, const char_t *str2);

_core_api bool_t str_equ_end(const char_t *str, const char_t *end);

_core_api void str_upper(String *str);

_core_api void str_lower(String *str);

_core_api void str_upper_c(char_t *dest, const uint32_t size, const char_t *str);

_core_api void str_lower_c(char_t *dest, const uint32_t size, const char_t *str);

_core_api void str_subs(String *str, const char_t replace, const char_t with);

_core_api void str_repl_c(char_t *str, const char_t *replace, const char_t *with);

_core_api const char_t *str_str(const char_t *str, const char_t *substr);

_core_api bool_t str_split(const char_t *str, const char_t *substr, String **left, String **right);

_core_api bool_t str_split_trim(const char_t *str, const char_t *substr, String **left, String **right);

_core_api ArrPt(String) *str_splits(const char_t *str, const char_t *substr, const bool_t trim, const bool_t add_empty);

_core_api void str_split_pathname(const char_t *pathname, String **path, String **file);

_core_api void str_split_pathext(const char_t *pathname, String **path, String **file, String **ext);

_core_api const char_t *str_filename(const char_t *pathname);

_core_api const char_t *str_filext(const char_t *pathname);

_core_api uint32_t str_find(const ArrPt(String) *array, const char_t *str);

_core_api int8_t str_to_i8(const char_t *str, const uint32_t base, bool_t *error);

_core_api int16_t str_to_i16(const char_t *str, const uint32_t base, bool_t *error);

_core_api int32_t str_to_i32(const char_t *str, const uint32_t base, bool_t *error);

_core_api int64_t str_to_i64(const char_t *str, const uint32_t base, bool_t *error);

_core_api uint8_t str_to_u8(const char_t *str, const uint32_t base, bool_t *error);

_core_api uint16_t str_to_u16(const char_t *str, const uint32_t base, bool_t *error);

_core_api uint32_t str_to_u32(const char_t *str, const uint32_t base, bool_t *error);

_core_api uint64_t str_to_u64(const char_t *str, const uint32_t base, bool_t *error);

_core_api real32_t str_to_r32(const char_t *str, bool_t *error);

_core_api real64_t str_to_r64(const char_t *str, bool_t *error);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: blib.h
 * https://nappgui.com/en/sewer/blib.html
 *
 */

/* C library funcions */

#include "sewer.hxx"

__EXTERN_C

_sewer_api uint32_t blib_strlen(const char_t *str);

_sewer_api char_t *blib_strstr(const char_t *str, const char_t *substr);

_sewer_api void blib_strcpy(char_t *dest, const uint32_t size, const char_t *src);

_sewer_api void blib_strncpy(char_t *dest, const uint32_t size, const char_t *src, const uint32_t n);

_sewer_api void blib_strcat(char_t *dest, const uint32_t size, const char_t *src);

_sewer_api int blib_strcmp(const char_t *str1, const char_t *str2);

_sewer_api int blib_strncmp(const char_t *str1, const char_t *str2, const uint32_t n);

_sewer_api uint32_t blib_strftime(char_t *dest, const uint32_t size, const char_t *format, const int16_t year, const uint8_t month, const uint8_t mday, const uint8_t wday, const uint8_t hour, const uint8_t minute, const uint8_t second);

_sewer_api int64_t blib_strtol(const char_t *str, char_t **endptr, uint32_t base, bool_t *err);

_sewer_api uint64_t blib_strtoul(const char_t *str, char_t **endptr, uint32_t base, bool_t *err);

_sewer_api real32_t blib_strtof(const char_t *str, char_t **endptr, bool_t *err);

_sewer_api real64_t blib_strtod(const char_t *str, char_t **endptr, bool_t *err);

_sewer_api void blib_qsort(byte_t *array, const uint32_t nelems, const uint32_t size, FPtr_compare func_compare);

_sewer_api void blib_qsort_ex(const byte_t *array, const uint32_t nelems, const uint32_t size, FPtr_compare_ex func_compare, const byte_t *data);

_sewer_api bool_t blib_bsearch(const byte_t *array, const byte_t *key, const uint32_t nelems, const uint32_t size, FPtr_compare func_compare, uint32_t *pos);

_sewer_api bool_t blib_bsearch_ex(const byte_t *array, const byte_t *key, const uint32_t nelems, const uint32_t size, FPtr_compare_ex func_compare, const byte_t *data, uint32_t *pos);

_sewer_api const char_t *blib_getenv(const char_t *name);

_sewer_api void blib_atexit(void (*func)(void));

_sewer_api void blib_abort(void);

_sewer_api void blib_exit(int code);

_sewer_api void blib_debug_break(void);

__END_C

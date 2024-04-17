/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bstd.h
 * https://nappgui.com/en/sewer/bstd.html
 *
 */

/* Basic standard functions */

#include "sewer.hxx"

__EXTERN_C

_sewer_api uint32_t bstd_sprintf(char_t *str, const uint32_t size, const char_t *format, ...) __PRINTF(3, 4);

_sewer_api uint32_t bstd_vsprintf(char_t *str, const uint32_t size, const char_t *format, va_list args);

_sewer_api uint32_t bstd_printf(const char_t *format, ...) __PRINTF(1, 2);

_sewer_api uint32_t bstd_eprintf(const char_t *format, ...) __PRINTF(1, 2);

_sewer_api uint32_t bstd_writef(const char_t *str);

_sewer_api uint32_t bstd_ewritef(const char_t *str);

_sewer_api bool_t bstd_read(byte_t *data, const uint32_t size, uint32_t *rsize);

_sewer_api bool_t bstd_write(const byte_t *data, const uint32_t size, uint32_t *wsize);

_sewer_api bool_t bstd_ewrite(const byte_t *data, const uint32_t size, uint32_t *wsize);

__END_C

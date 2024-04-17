/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: unicode.c
 *
 */

/* Unicode */

#include "unicode.h"
#include "cassert.h"
#include <ctype.h>

/*---------------------------------------------------------------------------*/

typedef uint32_t (*i_Fptr_codepoint_bytes)(const uint32_t codepoint);
typedef uint32_t (*i_Fptr_codepoint_from_str)(const char_t *str, uint32_t *num_bytes);
typedef uint32_t (*i_Fptr_codepoint_to_str)(const uint32_t codepoint, char_t *str);
typedef uint32_t (*i_Fptr_size)(const char_t *str);

/* 1) Unicode global codepoint range is from 0x0000 to 0x10FFFF (17 planes of 2^16 codepoints each)  */
/* 2) Range [0xD800-0xDFFF] is reserved for surrogate pairs (UTF16) */
/* 3) Two last codepoints of each plane 0xnFFFE and 0xnFFFF are reserved for internal use */
/* 4) Range [0xFDD0-0xFDEF] is reserved for internal use */
#define i_UNICODE_VALID_CODEPOINT(codepoint) \
    (bool_t) /* 1) */ ((codepoint) < 0x110000 && \
                       /* 2) */ (((codepoint)&0xFFFFF800) != 0xD800) && \
                       /* 3) */ ((codepoint)&0xFFFE) != 0xFFFE && \
                       /* 4) */ ((codepoint) < 0xFDD0 || (codepoint) > 0xFDEF))

#if defined(__ASSERTS__)
#define i_test_codepoint(codepoint) i_test_codepoint_imp((codepoint))
static uint32_t i_test_codepoint_imp(const uint32_t codepoint)
{
    cassert(i_UNICODE_VALID_CODEPOINT(codepoint) == TRUE);
    return codepoint;
}
#else
#define i_test_codepoint(codepoint) (codepoint)
#endif

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_utf8_bytes(const uint32_t codepoint)
{
    if (__TRUE_EXPECTED(codepoint < 0x0080))
        return 1;
    if (__TRUE_EXPECTED(codepoint < 0x0800))
        return 2;
    if (__TRUE_EXPECTED(codepoint < 0x10000))
        return 3;
    if (__TRUE_EXPECTED(codepoint < 0x200000))
        return 4;
    cassert(FALSE);
    return 0;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_utf16_bytes(const uint32_t codepoint)
{
    if (__TRUE_EXPECTED(codepoint < 0x10000))
        return 2;
    else
        return 4;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_utf32_bytes(const uint32_t codepoint)
{
    unref(codepoint);
    return 4;
}

/*---------------------------------------------------------------------------*/

static i_Fptr_codepoint_bytes i_func_codepoint_bytes[] = {
    i_codepoint_utf8_bytes,
    i_codepoint_utf16_bytes,
    i_codepoint_utf32_bytes};

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_from_utf8(const char_t *utf8_string, uint32_t *num_bytes)
{
    cassert_no_null(utf8_string);
    cassert_no_null(num_bytes);

    /* One byte UTF-8 0xxx xxxx */
    if (__TRUE_EXPECTED((*utf8_string & 0x7F) == *utf8_string))
    {
        cassert((uint32_t)*utf8_string <= 0x007F);
        *num_bytes = 1;
        return i_test_codepoint((uint32_t)*utf8_string);
    }

    /* Two bytes UTF-8 110x xxxx 10xx xxxx */
    if (__TRUE_EXPECTED((*utf8_string & 0xE0) == 0xC0))
    {
        register uint32_t code = ((uint32_t)(*(utf8_string + 0) & 0x1F) << 6) | (uint32_t)(*(utf8_string + 1) & 0x3F);
        cassert(code >= 0x0080 && code <= 0x07FF);
        *num_bytes = 2;
        return i_test_codepoint(code);
    }

    /* Three bytes UTF-8 1110 xxxx 10xx xxxx 10xx xxxx */
    if (__TRUE_EXPECTED((*utf8_string & 0xF0) == 0xE0))
    {
        register uint32_t code = ((uint32_t)(*(utf8_string + 0) & 0x0F) << 12) | ((uint32_t)(*(utf8_string + 1) & 0x3F) << 6) | (uint32_t)(*(utf8_string + 2) & 0x3F);
        cassert(code >= 0x0800 && code <= 0xFFFF);
        *num_bytes = 3;
        return i_test_codepoint(code);
    }

    /* Four bytes UTF-8 1111 0xxx 10xx xxxx 10xx xxxx 10xx xxxx */
    if (__TRUE_EXPECTED((*utf8_string & 0xF8) == 0xF0))
    {
        register uint32_t code = ((uint32_t)(*(utf8_string + 0) & 0x07) << 18) | ((uint32_t)(*(utf8_string + 1) & 0x3F) << 12) | ((uint32_t)(*(utf8_string + 2) & 0x3F) << 6) | (uint32_t)(*(utf8_string + 3) & 0x3F);
        cassert(code >= 0x010000 && code <= 0x1FFFFF);
        *num_bytes = 4;
        return i_test_codepoint(code);
    }

    cassert(FALSE);
    return i_test_codepoint(UINT32_MAX);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_from_utf16(const char_t *utf16_string, uint32_t *num_bytes)
{
    register uint16_t code;
    cassert_no_null(utf16_string);
    cassert_no_null(num_bytes);
    code = *((const uint16_t *)utf16_string);
    if (code >= 0xD800 && code <= 0xDBFF)
    {
        register uint16_t code2 = *(((const uint16_t *)utf16_string) + 1);
        cassert(code2 >= 0xDC00 && code2 <= 0xDFFF);
        *num_bytes = 4;
        return ((uint32_t)code << 10) + (uint32_t)code2 - 0x35FDC00;
    }

    *num_bytes = 2;
    return (uint32_t)code;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_from_utf32(const char_t *utf32_string, uint32_t *num_bytes)
{
    cassert_no_null(utf32_string);
    cassert_no_null(num_bytes);
    *num_bytes = 4;
    return *((uint32_t *)utf32_string);
}

/*---------------------------------------------------------------------------*/

static i_Fptr_codepoint_from_str i_func_codepoint_from_str[] = {
    i_codepoint_from_utf8,
    i_codepoint_from_utf16,
    i_codepoint_from_utf32};

/*---------------------------------------------------------------------------*/

static __INLINE char_t i_to_uchar(const uint32_t value)
{
    cassert(value < 0x100);
    return (char_t)value;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_to_utf8(const uint32_t codepoint, char_t *utf8_string)
{
    cassert(i_UNICODE_VALID_CODEPOINT(codepoint) == TRUE);
    cassert_no_null(utf8_string);
    if (__TRUE_EXPECTED(codepoint < 0x80))
    {
        *utf8_string = i_to_uchar(codepoint);
        return 1;
    }
    else if (__TRUE_EXPECTED(codepoint <= 0x7FF))
    {
        *utf8_string = i_to_uchar((codepoint >> 6) + 0xC0);
        *(utf8_string + 1) = i_to_uchar((codepoint & 0x3F) + 0x80);
        return 2;
    }
    else if (__TRUE_EXPECTED(codepoint <= 0xFFFF))
    {
        *utf8_string = i_to_uchar((codepoint >> 12) + 0xE0);
        *(utf8_string + 1) = i_to_uchar(((codepoint >> 6) & 0x3F) + 0x80);
        *(utf8_string + 2) = i_to_uchar((codepoint & 0x3F) + 0x80);
        return 3;
    }
    else if (__TRUE_EXPECTED(codepoint <= 0x10FFFF))
    {
        *utf8_string = i_to_uchar((codepoint >> 18) + 0xF0);
        *(utf8_string + 1) = i_to_uchar(((codepoint >> 12) & 0x3F) + 0x80);
        *(utf8_string + 2) = i_to_uchar(((codepoint >> 6) & 0x3F) + 0x80);
        *(utf8_string + 3) = i_to_uchar((codepoint & 0x3F) + 0x80);
        return 4;
    }

    cassert(FALSE);
    return 0;
}

/*---------------------------------------------------------------------------*/

static __INLINE uint16_t i_to_uint16(const uint32_t value)
{
    cassert(value < 0x10000);
    return (uint16_t)value;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_to_utf16(const uint32_t codepoint, char_t *utf16_string)
{
    cassert(i_UNICODE_VALID_CODEPOINT(codepoint) == TRUE);
    cassert_no_null(utf16_string);
    if (codepoint < 0x10000)
    {
        *((uint16_t *)utf16_string) = i_to_uint16(codepoint);
        return 2;
    }
    else
    {
        *((uint16_t *)utf16_string) = i_to_uint16((codepoint - 0x10000) / 0x400 + 0xd800);
        *(((uint16_t *)utf16_string) + 1) = i_to_uint16((codepoint - 0x10000) % 0x400 + 0xdc00);
        return 4;
    }
}

/*---------------------------------------------------------------------------*/

static uint32_t i_codepoint_to_utf32(const uint32_t codepoint, char_t *utf32_string)
{
    cassert(i_UNICODE_VALID_CODEPOINT(codepoint) == TRUE);
    cassert_no_null(utf32_string);
    *((uint32_t *)utf32_string) = codepoint;
    return 4;
}

/*---------------------------------------------------------------------------*/

static i_Fptr_codepoint_to_str i_func_codepoint_to_str[] = {
    i_codepoint_to_utf8,
    i_codepoint_to_utf16,
    i_codepoint_to_utf32};

/*---------------------------------------------------------------------------*/

/*  Includes the null-terminated character */
uint32_t unicode_convers_n(const char_t *from_str, char_t *to_str, const unicode_t from, const unicode_t to, const uint32_t isize, const uint32_t osize)
{
    register uint32_t null_size = 0;
    register uint32_t codepoint = 0;
    register uint32_t byte_count = 0;
    uint32_t num_bytes_src = 0;
    register uint32_t total_bytes_src = 0;
    cassert_no_null(from_str);
    cassert_no_null(to_str);
    null_size = i_func_codepoint_bytes[to](0);
    /* At least, the null terminated */
    cassert(osize >= null_size);
    codepoint = i_func_codepoint_from_str[from](from_str, &num_bytes_src);
    while (codepoint != 0)
    {
        register uint32_t num_bytes_dest = i_func_codepoint_to_str[to](codepoint, to_str);
        if (byte_count + num_bytes_dest + null_size <= osize)
        {
            from_str += num_bytes_src;
            to_str += num_bytes_dest;
            byte_count += num_bytes_dest;
            total_bytes_src += num_bytes_src;
            if (total_bytes_src >= isize)
                break;
            codepoint = i_func_codepoint_from_str[from](from_str, &num_bytes_src);
        }
        else
        {
            break;
        }
    }

    {
        register uint32_t num_bytes_dest = i_func_codepoint_to_str[to](0, to_str);
        cassert(num_bytes_dest == null_size);
        byte_count += num_bytes_dest;
    }

    cassert(byte_count <= osize);
    return byte_count;
}

/*---------------------------------------------------------------------------*/

uint32_t unicode_convers(const char_t *from_str, char_t *to_str, const unicode_t from, const unicode_t to, const uint32_t osize)
{
    return unicode_convers_n(from_str, to_str, from, to, UINT32_MAX, osize);
}

/*---------------------------------------------------------------------------*/

/*  Includes the null-terminated character */
uint32_t unicode_convers_nbytes(const char_t *str, const unicode_t from, const unicode_t to)
{
    /* str must be NULL-terminated */
    return unicode_convers_nbytes_n(str, UINT32_MAX, from, to);
}

/*---------------------------------------------------------------------------*/

/*  Includes the null-terminated character */
uint32_t unicode_convers_nbytes_n(const char_t *str, const uint32_t isize, const unicode_t from, const unicode_t to)
{
    uint32_t num_bytes_char = 0;
    uint32_t num_bytes_readed = 0;
    register uint32_t codepoint = 0;
    register uint32_t byte_count = 0;
    cassert_no_null(str);
    codepoint = i_func_codepoint_from_str[from](str, &num_bytes_char);
    while (codepoint != 0)
    {
        num_bytes_readed += num_bytes_char;
        byte_count += i_func_codepoint_bytes[to](codepoint);
        str += num_bytes_char;
        if (num_bytes_readed < isize)
            codepoint = i_func_codepoint_from_str[from](str, &num_bytes_char);
        else
            break;
    }

    byte_count += i_func_codepoint_bytes[to](0);
    return byte_count;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_utf8_buffer_size(const char_t *utf8_string)
{
    register uint32_t byte_count = 0;
    cassert_no_null(utf8_string);
    while (*utf8_string != 0)
    {
        byte_count += 1;
        utf8_string += 1;
    }

    byte_count += 1;
    return byte_count;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_utf16_buffer_size(const char_t *utf16_string)
{
    register uint32_t byte_count = 0;
    register uint16_t *str = (uint16_t *)utf16_string;
    cassert_no_null(utf16_string);
    while (*str != 0)
    {
        byte_count += 2;
        str += 1;
    }

    byte_count += 2;
    return byte_count;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_utf32_buffer_size(const char_t *utf32_string)
{
    register uint32_t byte_count = 0;
    register uint32_t *str = (uint32_t *)utf32_string;
    cassert_no_null(utf32_string);
    while (*str != 0)
    {
        byte_count += 4;
        str += 1;
    }

    byte_count += 4;
    return byte_count;
}

/*---------------------------------------------------------------------------*/

static i_Fptr_size i_func_buffer_size[] = {
    i_utf8_buffer_size,
    i_utf16_buffer_size,
    i_utf32_buffer_size};

/*---------------------------------------------------------------------------*/

/*  Includes the null-terminated character */
uint32_t unicode_nbytes(const char_t *str, const unicode_t format)
{
    return i_func_buffer_size[format](str);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_utf8_num_chars(const char_t *utf8_string)
{
    register uint32_t i = 0;
    cassert_no_null(utf8_string);
    while (*utf8_string != 0)
    {
        if ((*utf8_string & 0xC0) != 0x80)
            i += 1;
        utf8_string += 1;
    }

    return i;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_utf16_num_chars(const char_t *utf16_string)
{
    register uint16_t *str = (uint16_t *)utf16_string;
    register uint32_t i = 0;
    cassert_no_null(utf16_string);
    while (*str != 0)
    {
        if (*str < 0xD800 || *str > 0xDBFF)
            i += 1;
        str += 1;
    }

    return i;
}

/*---------------------------------------------------------------------------*/

static uint32_t i_utf32_num_chars(const char_t *utf32_string)
{
    register uint32_t *str = (uint32_t *)utf32_string;
    register uint32_t i = 0;
    cassert_no_null(utf32_string);
    while (*str != 0)
        i += 1;

    return i;
}

/*---------------------------------------------------------------------------*/

static i_Fptr_size i_func_num_chars[] = {
    i_utf8_num_chars,
    i_utf16_num_chars,
    i_utf32_num_chars};

/*---------------------------------------------------------------------------*/

uint32_t unicode_nchars(const char_t *str, const unicode_t format)
{
    return i_func_num_chars[format](str);
}

/*---------------------------------------------------------------------------*/

uint32_t unicode_to_u32(const char_t *str, const unicode_t format)
{
    uint32_t num_bytes = 0;
    return i_func_codepoint_from_str[format](str, &num_bytes);
}

/*---------------------------------------------------------------------------*/

uint32_t unicode_to_u32b(const char_t *str, const unicode_t format, uint32_t *bytes)
{
    return i_func_codepoint_from_str[format](str, bytes);
}

/*---------------------------------------------------------------------------*/

uint32_t unicode_to_char(const uint32_t codepoint, char_t *str, const unicode_t format)
{
    return i_func_codepoint_to_str[format](codepoint, str);
}

/*---------------------------------------------------------------------------*/

bool_t unicode_valid_str(const char_t *str, const unicode_t format)
{
    return unicode_valid_str_n(str, UINT32_MAX, format);
}

/*---------------------------------------------------------------------------*/

bool_t unicode_valid_str_n(const char_t *str, const uint32_t size, const unicode_t format)
{
    register bool_t ok = TRUE;
    register uint32_t tn = 0;
    uint32_t n;
    uint32_t codepoint = i_func_codepoint_from_str[format](str, &n);
    ok = i_UNICODE_VALID_CODEPOINT(codepoint);
    while (ok && codepoint != 0)
    {
        tn += n;
        if (tn >= size)
            break;
        str += n;
        codepoint = i_func_codepoint_from_str[format](str, &n);
        ok = i_UNICODE_VALID_CODEPOINT(codepoint);
    }

    return ok;
}

/*---------------------------------------------------------------------------*/

bool_t unicode_valid(const uint32_t codepoint)
{
    return i_UNICODE_VALID_CODEPOINT(codepoint);
}

/*---------------------------------------------------------------------------*/

const char_t *unicode_next(const char_t *str, const unicode_t format)
{
    uint32_t num_bytes = 0;
    i_func_codepoint_from_str[format](str, &num_bytes);
    return str + num_bytes;
}

/*---------------------------------------------------------------------------*/

static const char_t *i_utf8_back(const char_t *utf8_string)
{
    register uint32_t i = 0;
    cassert_no_null(utf8_string);
    for (i = 0; i < 4; ++i)
    {
        utf8_string--;
        if ((*utf8_string & 0xc0) != 0x80)
            return utf8_string;
    }

    cassert(FALSE);
    return NULL;
}

/*---------------------------------------------------------------------------*/

const char_t *unicode_back(const char_t *str, const unicode_t format)
{
    if (format == ekUTF8)
    {
        return i_utf8_back(str);
    }
    else
    {
        cassert(FALSE);
        return str;
    }
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isascii(const uint32_t codepoint)
{
    return (bool_t)(codepoint < 128);
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isalnum(const uint32_t codepoint)
{
    if (codepoint < 128)
        return (bool_t)isalnum((int)codepoint);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isalpha(const uint32_t codepoint)
{
    if (codepoint < 128)
        return (bool_t)isalpha((int)codepoint);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t unicode_iscntrl(const uint32_t codepoint)
{
    if (codepoint < 128)
        return (bool_t)iscntrl((int)codepoint);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isdigit(const uint32_t codepoint)
{
    return (bool_t)(codepoint >= 48 && codepoint <= 57);
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isgraph(const uint32_t codepoint)
{
    if (codepoint < 128)
        return (bool_t)isgraph((int)codepoint);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isprint(const uint32_t codepoint)
{
    if (codepoint < 128)
        return (bool_t)isprint((int)codepoint);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t unicode_ispunct(const uint32_t codepoint)
{
    if (codepoint < 128)
        return (bool_t)ispunct((int)codepoint);
    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isspace(const uint32_t codepoint)
{
    return (bool_t)(codepoint == ' ' || codepoint == '\t' || codepoint == '\n' || codepoint == '\v' || codepoint == '\f' || codepoint == '\r');
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isxdigit(const uint32_t codepoint)
{
    if (codepoint < 128)
        return (bool_t)isxdigit((int)codepoint);
    return FALSE;
}

#define i_islower(c) (((c) >= 97) && ((c) <= 122))
#define i_isupper(c) (((c) >= 65) && ((c) <= 90))

/*---------------------------------------------------------------------------*/

bool_t unicode_islower(const uint32_t codepoint)
{
    return (bool_t)i_islower((int)codepoint);
}

/*---------------------------------------------------------------------------*/

bool_t unicode_isupper(const uint32_t codepoint)
{
    return (bool_t)i_isupper((int)codepoint);
}

/*---------------------------------------------------------------------------*/

uint32_t unicode_tolower(const uint32_t codepoint)
{
    if (i_isupper(codepoint) == TRUE)
        return codepoint + 32;
    return codepoint;
}

/*---------------------------------------------------------------------------*/

uint32_t unicode_toupper(const uint32_t codepoint)
{
    if (i_islower(codepoint) == TRUE)
        return codepoint - 32;
    return codepoint;
}

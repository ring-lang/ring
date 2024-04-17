/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: strings.c
 *
 */

/* UTF8 strings */

#include "strings.h"
#include "arrpt.h"
#include "heap.h"
#include "stream.h"
#include <osbs/osbs.h>
#include <sewer/blib.h>
#include <sewer/bmem.h>
#include <sewer/bstd.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>
#include <sewer/unicode.h>

/*---------------------------------------------------------------------------*/

#define i_SIZE(str) *((uint32_t *)str)
#define i_DATA(str) ((char_t *)((char_t *)str + sizeof(uint32_t)))

/*---------------------------------------------------------------------------*/

static String *i_create_string(const uint32_t length, const char_t *data)
{
    String *str = (String *)heap_malloc(length + sizeof32(uint32_t), "String");
    i_SIZE(str) = length;
    if (data != NULL)
        bmem_copy((byte_t *)i_DATA(str), (const byte_t *)data, length);
    return str;
}

/*---------------------------------------------------------------------------*/

void str_destroy(String **str)
{
    cassert_no_null(str);
    cassert_no_null(*str);
    heap_free((byte_t **)str, i_SIZE(*str) + sizeof32(uint32_t), "String");
}

/*---------------------------------------------------------------------------*/

void str_destopt(String **str)
{
    cassert_no_null(str);
    if (*str != NULL)
        heap_free((byte_t **)str, i_SIZE(*str) + sizeof32(uint32_t), "String");
}

/*---------------------------------------------------------------------------*/

const char_t *tc(const String *str)
{
    return str ? i_DATA(str) : "";
}

/*---------------------------------------------------------------------------*/

char_t *tcc(String *str)
{
    cassert_no_null(str);
    return i_DATA(str);
}

/*---------------------------------------------------------------------------*/

String *str_c(const char_t *str)
{
    uint32_t length = blib_strlen(str);
    return i_create_string(length + 1, str);
}

/*---------------------------------------------------------------------------*/

String *str_cn(const char_t *str, const uint32_t n)
{
    String *lstr = i_create_string(n + 1, NULL);
    if (n > 0)
        bmem_copy((byte_t *)i_DATA(lstr), (const byte_t *)str, n);
    i_DATA(lstr)[n] = '\0';
    return lstr;
}

/*---------------------------------------------------------------------------*/

String *str_trim(const char_t *str)
{
    uint32_t size;
    const char_t *end;

    while (*str != '\0')
    {
        if (unicode_isspace((uint32_t)*str) == TRUE)
            str++;
        else
            break;
    }

    size = blib_strlen(str);
    if (size == 0)
        return str_c("");

    end = str + size - 1;

    while (unicode_isspace((uint32_t)*end) == TRUE)
        end -= 1;

    return str_cn(str, (uint32_t)(end - str) + 1);
}

/*---------------------------------------------------------------------------*/

String *str_trim_n(const char_t *str, const uint32_t n)
{
    const char_t *end = str + n - 1;
    uint32_t i = 0;
    while (*str != '\0' && i < n)
    {
        if (unicode_isspace((uint32_t)*str) == TRUE)
        {
            str++;
            i++;
        }
        else
        {
            break;
        }
    }

    if (*str == '\0' || n - i == 0)
        return str_c("");

    while (unicode_isspace((uint32_t)*end) == TRUE)
        end -= 1;

    return str_cn(str, (uint32_t)(end - str) + 1);
}

/*---------------------------------------------------------------------------*/

String *str_copy(const String *str)
{
    cassert_no_null(str);
    return i_create_string(i_SIZE(str), i_DATA(str));
}

/*---------------------------------------------------------------------------*/

String *str_printf(const char_t *format, ...)
{
    String *str = NULL;
    char_t data_static[1024];
    char_t *data_alloc = NULL;
    char_t *data = NULL;
    uint32_t length;

    cassert_no_null(format);

    /* Memory requeriments */
    {
        va_list args;
        va_start(args, format);
        length = 1 + bstd_vsprintf(NULL, 0, format, args);
        va_end(args);
    }

    /* Temporal buffer */
    if (length < 1024)
    {
        data = data_static;
    }
    else
    {
        data_alloc = (char_t *)heap_malloc(length, "StringPrintf");
        data = data_alloc;
    }

    /* Printf */
    {
        register uint32_t clength;
        va_list args;
        va_start(args, format);
        clength = bstd_vsprintf(data, length, format, args);
        va_end(args);
        cassert_unref(clength + 1 == length, clength);
    }

    str = i_create_string(length, data);

    if (data_alloc != NULL)
        heap_free((byte_t **)&data_alloc, length, "StringPrintf");

    return str;
}

/*---------------------------------------------------------------------------*/

String *str_path(const platform_t platform, const char_t *format, ...)
{
    String *str = NULL;
    char_t data_static[1024];
    char_t *data_alloc = NULL;
    char_t *data = NULL;
    uint32_t length;

    cassert_no_null(format);

    /* Memory requeriments */
    {
        va_list args;
        va_start(args, format);
        length = 1 + bstd_vsprintf(NULL, 0, format, args);
        va_end(args);
    }

    /* Temporal buffer */
    if (length < 1024)
    {
        data = data_static;
    }
    else
    {
        data_alloc = (char_t *)heap_malloc(length, "StringPath");
        data = data_alloc;
    }

    /* Printf */
    {
        register uint32_t clength;
        va_list args;
        va_start(args, format);
        clength = bstd_vsprintf(data, length, format, args);
        va_end(args);
        cassert_unref(clength + 1 == length, clength);
    }

    str = i_create_string(length, data);

    if (data_alloc != NULL)
        heap_free((byte_t **)&data_alloc, length, "StringPath");

    if (platform == ekWINDOWS)
        str_subs(str, '/', '\\');
    else
        str_subs(str, '\\', '/');

    return str;
}

/*---------------------------------------------------------------------------*/

String *str_cpath(const char_t *format, ...)
{
    String *str = NULL;
    char_t data_static[1024];
    char_t *data_alloc = NULL;
    char_t *data = NULL;
    uint32_t length;

    cassert_no_null(format);

    /* Memory requeriments */
    {
        va_list args;
        va_start(args, format);
        length = 1 + bstd_vsprintf(NULL, 0, format, args);
        va_end(args);
    }

    /* Temporal buffer */
    if (length < 1024)
    {
        data = data_static;
    }
    else
    {
        data_alloc = (char_t *)heap_malloc(length, "StringPath");
        data = data_alloc;
    }

    /* Printf */
    {
        register uint32_t clength;
        va_list args;
        va_start(args, format);
        clength = bstd_vsprintf(data, length, format, args);
        va_end(args);
        cassert_unref(clength + 1 == length, clength);
    }

    str = i_create_string(length, data);

    if (data_alloc != NULL)
        heap_free((byte_t **)&data_alloc, length, "StringPath");

    if (osbs_platform() == ekWINDOWS)
        str_subs(str, '/', '\\');
    else
        str_subs(str, '\\', '/');

    return str;
}

/*---------------------------------------------------------------------------*/

String *str_relpath(const platform_t platform, const char_t *path1, const char_t *path2)
{
    register uint32_t prefix = str_prefix(path1, path2);
    String *str = NULL;
    if (prefix > 0)
    {
        register uint32_t s1 = str_len_c(path1);
        register uint32_t i, n = 0;
        str = str_c("");

        prefix -= 1;
        while (path1[prefix] != '/' && path1[prefix] != '\\')
            prefix -= 1;

        while (s1 >= prefix)
        {
            if (path1[s1] == '/' || path1[s1] == '\\')
                n += 1;
            s1--;
        }

        for (i = 0; i < n; ++i)
            str_cat(&str, "../");

        str_cat(&str, path2 + prefix + 1);
    }
    else
    {
        str = str_c(path2);
    }

    if (platform == ekWINDOWS)
        str_subs(str, '/', '\\');
    else
        str_subs(str, '\\', '/');

    return str;
}

/*---------------------------------------------------------------------------*/

String *str_crelpath(const char_t *path1, const char_t *path2)
{
    return str_relpath(osbs_platform(), path1, path2);
}

/*---------------------------------------------------------------------------*/

static void i_replace(String **str, const char_t *replace, const char_t *with)
{
    uint32_t len_inp = 0;  /* length of input */
    uint32_t len_rep = 0;  /* length of rep (the string to remove) */
    uint32_t len_with = 0; /* length of with (the string to replace rep with) */
    uint32_t count = 0;    /* number of replacements */
    uint32_t len_new = 0;  /* length of new string */
    String *lstr = NULL;

    cassert_no_null(str);
    cassert_no_null(*str);
    cassert_no_null(replace);
    cassert_no_null(with);

    len_inp = blib_strlen(i_DATA(*str));
    if (len_inp == 0)
        return;

    len_rep = blib_strlen(replace);
    if (len_rep == 0)
        return;

    /* Count the number of replacements needed */
    {
        const char_t *src = NULL; /* the next insert point */
        const char_t *tmp = NULL;
        src = i_DATA(*str);
        tmp = blib_strstr(src, replace);
        for (count = 0; tmp != NULL; ++count)
        {
            src = tmp + len_rep;
            tmp = blib_strstr(src, replace);
        }
    }

    if (count == 0)
        return;

    len_with = (uint32_t)blib_strlen(with);

    /* Create the new String */
    len_new = len_inp;
    if (len_with < len_rep)
        len_new -= (len_rep - len_with) * count;
    else
        len_new += (len_with - len_rep) * count;
    len_new += 1;
    lstr = i_create_string(len_new, NULL);

    /* First time through the loop, all the variable are set correctly from here on.
       src points to the end of the result string
       ins points to the next occurrence of rep in orig
       orig points to the remainder of orig after "end of rep"
     */
    {
        const char_t *src = i_DATA(*str);
        char_t *dest = i_DATA(lstr);
        while (count--)
        {
            const char_t *ins = NULL; /* the next insert point */
            uint32_t len_front = 0;   /* distance between rep and end of last rep */
            ins = blib_strstr(src, replace);
            len_front = (uint32_t)(ins - src);

            if (len_front > 0)
            {
                str_copy_cn(dest, len_new, src, len_front);
                dest += len_front;
                len_new -= len_front;
            }

            if (len_with > 0)
            {
                str_copy_cn(dest, len_new, with, len_with);
                dest += len_with;
                len_new -= len_with;
            }

            src += len_front + len_rep; /* move to next "end of replacement" */
        }

        str_copy_c(dest, len_new, src);
    }

    str_destroy(str);
    *str = lstr;
}

/*---------------------------------------------------------------------------*/

String *str_repl(const char_t *str, ...)
{
    String *rstr = str_c(str);
    va_list params;
    va_start(params, str);
    for (;;)
    {
        const char_t *replace = (const char_t *)va_arg(params, char *);
        const char_t *with = NULL;
        if (replace == NULL)
            break;

        with = (const char_t *)va_arg(params, char *);
        if (with != NULL)
            i_replace(&rstr, replace, with);
    }
    va_end(params);
    return rstr;
}

/*---------------------------------------------------------------------------*/

String *str_reserve(const uint32_t n)
{
    return i_create_string(n + 1, NULL);
}

/*---------------------------------------------------------------------------*/

String *str_fill(const uint32_t n, const char_t c)
{
    String *str = i_create_string(n + 1, NULL);
    if (n > 0)
        bmem_set1((byte_t *)i_DATA(str), n, (byte_t)c);
    i_DATA(str)[n] = '\0';
    return str;
}

/*---------------------------------------------------------------------------*/

String *str_read(Stream *stream)
{
    uint32_t length;
    String *lstr;
    length = stm_read_u32(stream);
    if (length > 0)
    {
        lstr = i_create_string(length, NULL);
        stm_read(stream, (byte_t *)i_DATA(lstr), length);
        cassert(i_DATA(lstr)[length - 1] == '\0');
    }
    else
    {
        lstr = str_c("");
    }

    return lstr;
}

/*---------------------------------------------------------------------------*/

void str_write(Stream *stream, const String *str)
{
    cassert_no_null(str);
    stm_write_u32(stream, i_SIZE(str));
    stm_write(stream, (const byte_t *)i_DATA(str), i_SIZE(str));
}

/*---------------------------------------------------------------------------*/

void str_writef(Stream *stream, const String *str)
{
    cassert_no_null(str);
    stm_write(stream, (const byte_t *)i_DATA(str), i_SIZE(str) - 1);
}

/*---------------------------------------------------------------------------*/

void str_copy_c(char_t *dest, const uint32_t size, const char_t *src)
{
    blib_strcpy(dest, size, src);
}

/*---------------------------------------------------------------------------*/

void str_copy_cn(char_t *dest, const uint32_t size, const char_t *src, const uint32_t n)
{
    blib_strncpy(dest, size, src, n);
}

/*---------------------------------------------------------------------------*/

void str_cat(String **dest, const char_t *src)
{
    uint32_t len;
    cassert_no_null(dest);
    cassert_no_null(src);
    len = blib_strlen(src);
    if (len > 0)
    {
        if (*dest == NULL)
        {
            *dest = i_create_string(len + 1, src);
        }
        else
        {
            uint32_t s = i_SIZE(*dest);
            *dest = (String *)heap_realloc(*(byte_t **)dest, s + (uint32_t)sizeof(uint32_t), s + len + (uint32_t)sizeof(uint32_t), "String");
            bmem_copy((byte_t *)i_DATA(*dest) + s - 1, (const byte_t *)src, len);
            i_DATA(*dest)[s + len - 1] = '\0';
            i_SIZE(*dest) = s + len;
        }
    }
}

/*---------------------------------------------------------------------------*/

void str_cat_c(char_t *dest, const uint32_t size, const char_t *src)
{
    blib_strcat(dest, size, src);
}

/*---------------------------------------------------------------------------*/

void str_upd(String **str, const char_t *new_str)
{
    cassert_no_null(str);

    if (tc(*str) == new_str)
        return;

    if (*str != NULL)
        heap_free((byte_t **)str, i_SIZE(*str) + sizeof32(uint32_t), "String");

    if (new_str != NULL)
    {
        uint32_t length = blib_strlen(new_str);
        *str = i_create_string(length + 1, new_str);
    }
}

/*---------------------------------------------------------------------------*/

/*
void str_stm_printf(const String *str, Stream *stream);
void str_stm_printf(const String *str, Stream *stream)
{
    register uint32_t size;
    cassert_no_null(str);
    size = i_SIZE(str);
    if (i_DATA(str)[size - 1] == '\0')
        size -= 1;
    stm_write_uchar_array_n(stream, i_DATA(str), size);
}
*/

/*---------------------------------------------------------------------------*/

uint32_t str_len(const String *str)
{
    cassert_no_null(str);
    return i_SIZE(str) - 1;
}

/*---------------------------------------------------------------------------*/

uint32_t str_len_c(const char_t *str)
{
    return blib_strlen(str);
}

/*---------------------------------------------------------------------------*/

uint32_t str_nchars(const String *str)
{
    return unicode_nchars(tc(str), ekUTF8);
}

/*---------------------------------------------------------------------------*/

uint32_t str_prefix(const char_t *str1, const char_t *str2)
{
    register uint32_t i = 0;
    cassert_no_null(str1);
    cassert_no_null(str2);
    for (; *str1 != '\0' && *str2 != '\0' && *str1 == *str2; i++, str1++, str2++)
        ;
    return i;
}

/*---------------------------------------------------------------------------*/

bool_t str_is_prefix(const char_t *str, const char_t *prefix)
{
    cassert_no_null(str);
    cassert_no_null(prefix);
    for (; *str != '\0' && *prefix != '\0' && *str == *prefix; str++, prefix++)
        ;
    return (bool_t)(*prefix == 0);
}

/*---------------------------------------------------------------------------*/

bool_t str_is_sufix(const char_t *str, const char_t *sufix)
{
    uint32_t len = blib_strlen(str);
    uint32_t len2 = blib_strlen(sufix);
    const char_t *esufix = NULL;
    const char_t *estr = NULL;

    if (len2 == 0)
        return TRUE;

    if (len2 > len)
        return FALSE;

    estr = str + len - 1;
    esufix = sufix + len2 - 1;

    for (; esufix != sufix && *estr == *esufix; estr -= 1, esufix -= 1)
        ;
    return (bool_t)(*esufix == *estr);
}

/*---------------------------------------------------------------------------*/

int str_scmp(const String *str1, const String *str2)
{
    cassert_no_null(str1);
    cassert_no_null(str2);
    return blib_strcmp(tc(str1), tc(str2));
}

/*---------------------------------------------------------------------------*/

int str_cmp(const String *str1, const char_t *str2)
{
    cassert_no_null(str1);
    return blib_strcmp(tc(str1), str2);
}

/*---------------------------------------------------------------------------*/

int str_cmp_c(const char_t *str1, const char_t *str2)
{
    return blib_strcmp(str1, str2);
}

/*---------------------------------------------------------------------------*/

int str_cmp_cn(const char_t *str1, const char_t *str2, const uint32_t n)
{
    return blib_strncmp(str1, str2, n);
}

/*---------------------------------------------------------------------------*/

bool_t str_empty(const String *str)
{
    if (str == NULL)
        return TRUE;

    if (i_SIZE(str) == 1)
    {
        cassert(i_DATA(str)[0] == '\0');
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t str_empty_c(const char_t *str)
{
    if (str == NULL)
        return TRUE;
    return (bool_t)(str[0] == '\0');
}

/*---------------------------------------------------------------------------*/

bool_t str_equ(const String *str1, const char_t *str2)
{
    return (bool_t)(blib_strcmp(tc(str1), str2) == 0);
}

/*---------------------------------------------------------------------------*/

bool_t str_equ_c(const char_t *str1, const char_t *str2)
{
    return (bool_t)(blib_strcmp(str1, str2) == 0);
}

/*---------------------------------------------------------------------------*/

bool_t str_equ_cn(const char_t *str1, const char_t *str2, const uint32_t n)
{
    int result = blib_strncmp(str1, str2, n);
    return (bool_t)(result == 0);
}

/*---------------------------------------------------------------------------*/

bool_t str_equ_nocase(const char_t *str1, const char_t *str2)
{
    for (;; ++str1, ++str2)
    {
        if (*str1 == '\0')
            return *str2 == '\0';

        if (*str2 == '\0')
            return *str1 == '\0';

        if (unicode_tolower((uint32_t)*str1) != unicode_tolower((uint32_t)*str2))
            return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t str_equ_end(const char_t *str, const char_t *end)
{
    uint32_t l1 = str_len_c(str);
    uint32_t l2 = str_len_c(end);
    if (l1 < l2)
    {
        while (l2 > 0)
        {
            l1 -= 1;
            l2 -= 1;

            if (str[l1] != end[l2])
                return FALSE;
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

void str_upper(String *str)
{
    register char_t *data = NULL, *end_data = NULL;
    cassert_no_null(str);
    data = i_DATA(str);
    end_data = i_DATA(str) + i_SIZE(str);
    for (; data < end_data; ++data)
        *data = (char_t)unicode_toupper((uint32_t)(*data));
}

/*---------------------------------------------------------------------------*/

void str_lower(String *str)
{
    register char_t *data = NULL, *end_data = NULL;
    cassert_no_null(str);
    data = i_DATA(str);
    end_data = i_DATA(str) + i_SIZE(str);
    for (; data < end_data; ++data)
        *data = (char_t)unicode_tolower((uint32_t)(*data));
}

/*---------------------------------------------------------------------------*/

void str_upper_c(char_t *dest, const uint32_t size, const char_t *str)
{
    register char_t *end_dest = dest + size - 1;
    cassert_no_null(str);
    for (; dest < end_dest && *str != '\0'; ++dest, ++str)
        *dest = (char_t)unicode_toupper((uint32_t)(*str));
    *dest = '\0';
}

/*---------------------------------------------------------------------------*/

void str_lower_c(char_t *dest, const uint32_t size, const char_t *str)
{
    register char_t *end_dest = dest + size - 1;
    cassert_no_null(str);
    for (; dest < end_dest && *str != '\0'; ++dest, ++str)
        *dest = (char_t)unicode_tolower((uint32_t)(*str));
    *dest = '\0';
}

/*---------------------------------------------------------------------------*/

void str_subs(String *str, const char_t replace, const char_t with)
{
    register char_t *data = NULL, *end_data = NULL;
    cassert_no_null(str);
    cassert(unicode_isascii((uint32_t)replace) == TRUE);
    cassert(unicode_isascii((uint32_t)with) == TRUE);
    data = i_DATA(str);
    end_data = i_DATA(str) + i_SIZE(str);
    for (; data < end_data; ++data)
    {
        if (*data == replace)
            *data = with;
    }
}

/*---------------------------------------------------------------------------*/

void str_repl_c(char_t *str, const char_t *replace, const char_t *with)
{
    uint32_t l;
    char_t *sub = str;
    cassert_no_null(str);
    cassert_no_null(replace);
    cassert_no_null(with);
    l = blib_strlen(replace);
    cassert(l == blib_strlen(with));
    sub = blib_strstr(sub, replace);
    while (sub != NULL)
    {
        uint32_t i;
        for (i = 0; i < l; ++i)
            *sub++ = with[i];
        sub = blib_strstr(sub, replace);
    }
}

/*---------------------------------------------------------------------------*/

const char_t *str_str(const char_t *str, const char_t *substr)
{
    return blib_strstr(str, substr);
}

/*---------------------------------------------------------------------------*/

static __INLINE const char_t *i_last_separator(const char_t *str)
{
    register const char_t *lsep = NULL;
    cassert_no_null(str);
    while (*str != '\0')
    {
        if (*str == '/' || *str == '\\')
            lsep = str;
        str++;
    }
    return lsep;
}

/*---------------------------------------------------------------------------*/

bool_t str_split(const char_t *str, const char_t *substr, String **left, String **right)
{
    const char_t *fstr = blib_strstr(str, substr);
    if (fstr != NULL)
    {
        if (left != NULL)
            *left = str_cn(str, (uint32_t)(fstr - str));

        if (right != NULL)
        {
            fstr += blib_strlen(substr);
            *right = str_c(fstr);
        }

        return TRUE;
    }
    else
    {
        if (left != NULL)
            *left = str_c(str);

        if (right != NULL)
            *right = str_c("");

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

bool_t str_split_trim(const char_t *str, const char_t *substr, String **left, String **right)
{
    char_t *fstr = blib_strstr(str, substr);
    if (fstr != NULL)
    {
        if (left != NULL)
        {
            uint32_t n = (uint32_t)(fstr - str);
            *left = str_trim_n(str, n);
        }

        if (right != NULL)
        {
            fstr += blib_strlen(substr);
            *right = str_trim(fstr);
        }

        return TRUE;
    }
    else
    {
        if (left != NULL)
            *left = str_trim(str);

        if (right != NULL)
            *right = str_c("");

        return FALSE;
    }
}

/*---------------------------------------------------------------------------*/

ArrPt(String) *str_splits(const char_t *str, const char_t *substr, const bool_t trim, const bool_t add_empty)
{
    ArrPt(String) *strs = arrpt_create(String);
    cassert_no_null(str);
    if (substr != NULL)
    {
        uint32_t sn = blib_strlen(substr);
        char_t *fstr = blib_strstr(str, substr);
        while (fstr != NULL)
        {
            uint32_t n = (uint32_t)(fstr - str);
            String *sstr = NULL;

            if (trim == TRUE)
                sstr = str_trim_n(str, n);
            else
                sstr = str_cn(str, n);

            if (str_empty(sstr) == FALSE || add_empty == TRUE)
                arrpt_append(strs, sstr, String);
            else
                str_destroy(&sstr);

            fstr += sn;
            str = fstr;
            fstr = blib_strstr(str, substr);
        }

        /* Compute the last string */
        {
            String *sstr = NULL;
            if (trim == TRUE)
                sstr = str_trim(str);
            else
                sstr = str_c(str);

            if (str_empty(sstr) == FALSE || add_empty == TRUE)
                arrpt_append(strs, sstr, String);
            else
                str_destroy(&sstr);
        }
    }
    else
    {
        String *sstr = NULL;

        if (trim == TRUE)
            sstr = str_trim(str);
        else
            sstr = str_c(str);

        if (str_empty(sstr) == FALSE || add_empty == TRUE)
            arrpt_append(strs, sstr, String);
        else
            str_destroy(&sstr);
    }

    return strs;
}

/*---------------------------------------------------------------------------*/

void str_split_pathname(const char_t *pathname, String **path, String **file)
{
    register const char_t *lsep = i_last_separator(pathname);

    if (lsep != NULL)
    {
        if (path != NULL)
            *path = str_cn(pathname, (uint32_t)(lsep - pathname));

        if (file != NULL)
            *file = str_c(lsep + 1);
    }
    else
    {
        if (path != NULL)
            *path = str_c("");

        if (file != NULL)
            *file = str_c(pathname);
    }
}

/*---------------------------------------------------------------------------*/

void str_split_pathext(const char_t *pathname, String **path, String **file, String **ext)
{
    register const char_t *lsep = i_last_separator(pathname);
    register const char_t *filename = NULL;
    register const char_t *fileext = NULL;

    if (lsep != NULL)
    {
        if (path != NULL)
            *path = str_cn(pathname, (uint32_t)(lsep - pathname));
        filename = lsep + 1;
    }
    else
    {
        if (path != NULL)
            *path = str_c("");
        filename = pathname;
    }

    fileext = str_filext(filename);
    if (fileext != NULL)
    {
        if (file != NULL)
            *file = str_cn(filename, (uint32_t)(fileext - filename - 1));

        if (ext != NULL)
            *ext = str_c(fileext);
    }
    else
    {
        if (file != NULL)
            *file = str_c(filename);

        if (ext != NULL)
            *ext = str_c("");
    }
}

/*---------------------------------------------------------------------------*/

const char_t *str_filename(const char_t *pathname)
{
    register const char_t *lsep = i_last_separator(pathname);
    if (lsep == NULL)
        return pathname;
    else
        return lsep + 1;
}

/*---------------------------------------------------------------------------*/

const char_t *str_filext(const char_t *pathname)
{
    const char_t *file_extension = NULL;

    for (;;)
    {
        if (*pathname == '\0')
            return file_extension;
        if (*pathname == '.')
            file_extension = pathname + 1;
        pathname++;
    }
}

/*---------------------------------------------------------------------------*/

uint32_t str_find(const ArrPt(String) *array, const char_t *str)
{
    arrpt_foreach_const(astr, array, String)
        if (str_equ(astr, str) == TRUE)
            return astr_i;
    arrpt_end()
    return UINT32_MAX;
}

/*---------------------------------------------------------------------------*/

static __INLINE bool_t i_ok(const char_t *str, const bool_t allow_minus)
{
    unref(str);
    unref(allow_minus);
    return TRUE;

    /*    if (errno == ERANGE)
   {
       return FALSE;
   }
   else
   {
       while (*str == ' ')
           str += 1;

       if (*str == '-')
       {
           if (allow_minus == FALSE)
               return FALSE;
           str += 1;
       }

       while (*str == ' ')
           str += 1;

       while (*str != '\0' && !(*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r'))
       {
           if (*str < '0' || *str > '9')
           {
               return FALSE;
           }

           str += 1;
       }

       return TRUE;
   }
 */
}

/*---------------------------------------------------------------------------*/

static bool_t i_str_to_i64(const char_t *str, int64_t *value, const uint32_t base, const int64_t min, const int64_t max)
{
    bool_t err;
    int64_t v = blib_strtol(str, NULL, base, &err);

    cassert_no_null(value);
    if (i_ok(str, TRUE) == TRUE)
    {
        if (v <= max && v >= min)
        {
            *value = v;
            return TRUE;
        }
        else if (v < min)
        {
            *value = min;
            return FALSE;
        }
        else
        {
            *value = max;
            return FALSE;
        }
    }

    if (err == TRUE)
        *value = max;
    else
        *value = 0;

    return FALSE;
}

/*---------------------------------------------------------------------------*/

int8_t str_to_i8(const char_t *str, const uint32_t base, bool_t *error)
{
    int64_t value;
    bool_t ok = i_str_to_i64(str, &value, base, INT8_MIN, INT8_MAX);
    ptr_assign(error, !ok);
    return (int8_t)value;
}

/*---------------------------------------------------------------------------*/

int16_t str_to_i16(const char_t *str, const uint32_t base, bool_t *error)
{
    int64_t value;
    bool_t ok = i_str_to_i64(str, &value, base, INT16_MIN, INT16_MAX);
    ptr_assign(error, !ok);
    return (int16_t)value;
}

/*---------------------------------------------------------------------------*/

int32_t str_to_i32(const char_t *str, const uint32_t base, bool_t *error)
{
    int64_t value;
    bool_t ok = i_str_to_i64(str, &value, base, INT32_MIN, INT32_MAX);
    ptr_assign(error, !ok);
    return (int32_t)value;
}

/*---------------------------------------------------------------------------*/

int64_t str_to_i64(const char_t *str, const uint32_t base, bool_t *error)
{
    int64_t value;
    bool_t ok = i_str_to_i64(str, &value, base, INT64_MIN, INT64_MAX);
    ptr_assign(error, !ok);
    return value;
}

/*---------------------------------------------------------------------------*/

static bool_t i_str_to_u64(const char_t *str, uint64_t *value, const uint32_t base, const uint64_t max)
{
    bool_t err;
    uint64_t v = blib_strtoul(str, NULL, base, &err);

    cassert_no_null(value);
    if (i_ok(str, FALSE) == TRUE)
    {
        if (v <= max)
        {
            *value = v;
            return TRUE;
        }
        else
        {
            *value = max;
            return FALSE;
        }
    }

    if (err == TRUE)
        *value = max;
    else
        *value = 0;

    return FALSE;
}

/*---------------------------------------------------------------------------*/

uint8_t str_to_u8(const char_t *str, const uint32_t base, bool_t *error)
{
    uint64_t value;
    bool_t ok = i_str_to_u64(str, &value, base, UINT8_MAX);
    ptr_assign(error, !ok);
    return (uint8_t)value;
}

/*---------------------------------------------------------------------------*/

uint16_t str_to_u16(const char_t *str, const uint32_t base, bool_t *error)
{
    uint64_t value;
    bool_t ok = i_str_to_u64(str, &value, base, UINT16_MAX);
    ptr_assign(error, !ok);
    return (uint16_t)value;
}

/*---------------------------------------------------------------------------*/

uint32_t str_to_u32(const char_t *str, const uint32_t base, bool_t *error)
{
    uint64_t value;
    bool_t ok = i_str_to_u64(str, &value, base, UINT32_MAX);
    ptr_assign(error, !ok);
    return (uint32_t)value;
}

/*---------------------------------------------------------------------------*/

uint64_t str_to_u64(const char_t *str, const uint32_t base, bool_t *error)
{
    uint64_t value;
    bool_t ok = i_str_to_u64(str, &value, base, UINT64_MAX);
    ptr_assign(error, !ok);
    return value;
}

/*---------------------------------------------------------------------------*/

real32_t str_to_r32(const char_t *str, bool_t *error)
{
    return blib_strtof(str, NULL, error);
}

/*---------------------------------------------------------------------------*/

real64_t str_to_r64(const char_t *str, bool_t *error)
{
    return blib_strtod(str, NULL, error);
}

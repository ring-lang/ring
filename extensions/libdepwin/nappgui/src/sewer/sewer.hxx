/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: sewer.hxx
 * https://nappgui.com/en/sewer/sewer.html
 *
 */

/* Sewer library */

#ifndef __SEWER_HXX__
#define __SEWER_HXX__

#include "config.hxx"
#include "sewer.def"

typedef enum _unicode_t
{
    ekUTF8,
    ekUTF16,
    ekUTF32
} unicode_t;

typedef struct _renv_t REnv;

typedef void (*FPtr_destroy)(void **item);
#define FUNC_CHECK_DESTROY(func, type) \
    (void)((void (*)(type **))func == func)

typedef void *(*FPtr_copy)(const void *item);
#define FUNC_CHECK_COPY(func, type) \
    (void)((type * (*)(const type *)) func == func)

typedef void (*FPtr_scopy)(void *dest, const void *src);
#define FUNC_CHECK_SCOPY(func, type) \
    (void)((void (*)(type *, const type *))func == func)

typedef int (*FPtr_compare)(const void *item1, const void *item2);
#define FUNC_CHECK_COMPARE(func, type) \
    (void)((int (*)(const type *, const type *))func == func)
#define FUNC_CHECK_COMPARE_KEY(func, type, ktype) \
    (void)((int (*)(const type *, const ktype *))func == func)

typedef int (*FPtr_compare_ex)(const void *item1, const void *item2, const void *data);
#define FUNC_CHECK_COMPARE_EX(func, type, dtype) \
    (void)((int (*)(const type *, const type *, dtype *))func == func)

typedef void (*FPtr_assert)(void *item, const uint32_t group, const char_t *caption, const char_t *detail, const char_t *file, const uint32_t line);
#define FUNC_CHECK_ASSERT_FUNC(func, type) \
    (void)((void (*)(type *, const uint32_t, const char_t *, const char_t *, const char_t *, const uint32_t))func == func)

#endif

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: cassert.h
 * https://nappgui.com/en/sewer/cassert.html
 *
 */

/* Code assertion */

#include "sewer.hxx"

__EXTERN_C

_sewer_api void cassert_set_func(void *data, FPtr_assert func_assert);

_sewer_api void cassert_imp(bool_t cond, const char_t *detail, const char_t *file, const uint32_t line);

_sewer_api void cassert_fatal_imp(bool_t cond, const char_t *detail, const char_t *file, const uint32_t line);

_sewer_api void cassert_no_null_imp(void *ptr, const char_t *detail, const char_t *file, const uint32_t line);

_sewer_api void cassert_no_nullf_imp(void (*ptr)(void), const char_t *detail, const char_t *file, const uint32_t line);

_sewer_api void cassert_default_imp(const char_t *file, const uint32_t line);

__END_C

#if defined(__ASSERTS__)

#define cassert(cond) \
    cassert_imp((bool_t)(cond), #cond, __FILE__, __LINE__)

#define cassert_msg(cond, msg) \
    cassert_imp((bool_t)(cond), #msg, __FILE__, __LINE__)

#define cassert_fatal(cond) \
    cassert_fatal_imp((bool_t)(cond), #cond, __FILE__, __LINE__)

#define cassert_fatal_msg(cond, msg) \
    cassert_fatal_imp((bool_t)(cond), #msg, __FILE__, __LINE__)

#define cassert_no_null(ptr) \
    cassert_no_null_imp((void *)ptr, #ptr, __FILE__, __LINE__)

#ifdef __cplusplus

#if defined(_MSC_VER)
#define cassert_no_nullf(fptr) \
    cassert_no_null_imp((void *)fptr, #fptr, __FILE__, __LINE__)
#else
#define cassert_no_nullf(fptr) \
    cassert_no_nullf_imp((void (*)(void))fptr, #fptr, __FILE__, __LINE__)
#endif

#else /* C Compiler */

#if defined(_MSC_VER) && _MSC_VER >= 1935 /* Visual Studio 2022 version 17.5.0 */
#define cassert_no_nullf(fptr) \
    cassert_no_nullf_imp((void (*)(void))((void *)fptr), #fptr, __FILE__, __LINE__)
#else
#define cassert_no_nullf(fptr) \
    cassert_no_nullf_imp((void (*)(void))fptr, #fptr, __FILE__, __LINE__)
#endif

#endif

#define cassert_default() \
    default: \
        cassert_default_imp(__FILE__, __LINE__)

#define cassert_unref(cond, v) \
    cassert_imp((bool_t)(cond), #cond, __FILE__, __LINE__)

#else

#define cassert(cond) (void)(1 == 1)
#define cassert_msg(cond, msg) (void)(1 == 1)
#define cassert_fatal(cond) (void)(1 == 1)
#define cassert_fatal_msg(cond, msg) (void)(1 == 1)
#define cassert_no_null(ptr) (void)(ptr)
#define cassert_no_nullf(fptr) (void)(fptr)
#define cassert_default() default:
#define cassert_unref(cond, v) unref(v)

#endif

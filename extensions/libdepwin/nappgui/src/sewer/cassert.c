/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: cassert.c
 *
 */

/* Code assertion */

#include "cassert.h"

#include "nowarn.hxx"
#include <stdarg.h>
#include "warn.hxx"

static void *i_ERROR_DATA = NULL;
static FPtr_assert i_ERROR_FUNC = NULL;

/*---------------------------------------------------------------------------*/

void cassert_set_func(void *data, FPtr_assert func_assert)
{
    i_ERROR_DATA = data;
    i_ERROR_FUNC = func_assert;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_assert_message(const uint32_t group, const char_t *caption, const char_t *detail, const char_t *file, const uint32_t line)
{
    if (i_ERROR_FUNC != NULL)
        i_ERROR_FUNC(i_ERROR_DATA, group, caption, detail, file, line);
}

/*---------------------------------------------------------------------------*/

void cassert_imp(bool_t cond, const char_t *detail, const char_t *file, const uint32_t line)
{
    if (cond == 0)
        i_assert_message(1, "Assertion failed", detail, file, line);
}

/*---------------------------------------------------------------------------*/

void cassert_fatal_imp(bool_t cond, const char_t *detail, const char_t *file, const uint32_t line)
{
    if (cond == 0)
        i_assert_message(0, "Fatal assertion failed", detail, file, line);
}

/*---------------------------------------------------------------------------*/

void cassert_no_null_imp(void *ptr, const char_t *detail, const char_t *file, const uint32_t line)
{
    if (ptr == NULL)
        i_assert_message(0, "NULL pointer access", detail, file, line);
}

/*---------------------------------------------------------------------------*/

void cassert_no_nullf_imp(void (*ptr)(void), const char_t *detail, const char_t *file, const uint32_t line)
{
    if (ptr == NULL)
        i_assert_message(0, "NULL function access", detail, file, line);
}

/*---------------------------------------------------------------------------*/

void cassert_default_imp(const char_t *file, const uint32_t line)
{
    i_assert_message(1, "Switch default", "", file, line);
}

/*---------------------------------------------------------------------------*/

#if defined __WINDOWS__

/*
This function is used by C++ compiler in VS2012 and later
If you tried to link a >= VS2012 generated .lib in VS2010 and lower, you'll get
a linker error. The next lines will solve the problem
http://cubicspot.blogspot.com/2015/07/solving-unresolved-external-symbol.html
 */
#if _MSC_VER < 1700

__declspec(noreturn) void __cdecl __report_rangecheckfailure(void)
{
    cassert_msg(FALSE, "report_rangecheckfailure ERROR! Program will crash!!");
}

#endif

#endif

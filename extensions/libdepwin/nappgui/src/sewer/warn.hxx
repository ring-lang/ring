/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: warn.hxx
 *
 */

/* This header will restore ALL warnings from 'nowarn.hxx' */
/* USE ONLY FOR THIRD PARTY HEADERS, NOT FOR PROJECT ONES */
/* #include "nowarn.hxx"    Disable all warnings */
/* #include <gdiplus.h>     Include third party header */
/* #include "warn.hxx"      Restore all warnings */

#if defined(_MSC_VER)
#pragma pop_macro("Set")
#pragma warning(pop)
#pragma warning(disable : 4514)
#pragma warning(default : 4625)
#pragma warning(default : 4626)
#pragma warning(default : 4668)
#pragma warning(default : 4255)

#if _MSC_VER > 1700
#pragma warning(default : 4458)
#endif

#pragma warning(default : 4201)
#pragma warning(default : 4548)
#undef _CRT_SECURE_NO_WARNINGS
#endif

#if defined(__GNUC__)

#if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
/* Was added in GCC 4.6 */
#pragma GCC diagnostic pop
#else
#pragma GCC diagnostic warning "-Wall"
#endif

#endif

#if defined(__clang__)
#pragma GCC diagnostic pop
#endif

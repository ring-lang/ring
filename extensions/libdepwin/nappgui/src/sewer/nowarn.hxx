/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: nowarn.hxx
 *
 */

/* This header will ignore ALL warnings until 'warn.hxx' */
/* USE ONLY FOR THIRD PARTY HEADERS, NOT IN PROYECT FILES */
/* #include "nowarn.hxx"    Disable all warnings */
/* #include <gdiplus.h>     Include third party header */
/* #include "warn.hxx"      Restore all warnings */

#if defined(_MSC_VER)
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(push, 0)
#pragma push_macro("Set")
#undef Set
/* Unreferenced inline function has been removed */
#pragma warning(disable : 4514)
#pragma warning(disable : 4625)
#pragma warning(disable : 4626)
/* C:\Program Files (x86)\Windows Kits\10\Include\10.0.17763.0\ucrt\corecrt.h(212,7): warning C4668: '__cplusplus' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif' */
#pragma warning(disable : 4668)
/* C:\Program Files (x86)\Windows Kits\10\Include\10.0.17763.0\um\winuser.h(6537,32): warning C4255: 'EnableMouseInPointerForThread': no function prototype given: converting '()' to '(void)' */
#pragma warning(disable : 4255)

#if _MSC_VER > 1700
/* C:\Program Files (x86)\Windows Kits\10\Include\10.0.17763.0\um\GdiplusHeaders.h(701,40): warning C4458: declaration of 'nativeCap' hides class member */
#pragma warning(disable : 4458)
#endif

/* C:\Program Files (x86)\Windows Kits\10\Include\10.0.17763.0\um\Richedit.h(783,3): warning C4201: nonstandard extension used: nameless struct/union */
#pragma warning(disable : 4201)
/* C:\Program Files (x86)\Windows Kits\10\Include\10.0.10240.0\ucrt\malloc.h(160): warning C4548: expression before comma has no effect; expected expression with side-effect1> */
#pragma warning(disable : 4548)
#endif

#if defined(__GNUC__)

#if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
/* Was added in GCC 4.6 */
#pragma GCC diagnostic push
#endif

#pragma GCC diagnostic ignored "-Wall"

#if (__GNUC__ >= 5)
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wvariadic-macros"
#endif

#if (__GNUC__ >= 9)
#pragma GCC diagnostic ignored "-Wcast-function-type"
#endif

/*
#pragma GCC diagnostic ignored "-Wformat"
#pragma GCC diagnostic ignored "-Wpointer-sign"
#pragma GCC diagnostic ignored "-Wbad-function-cast"
#pragma GCC diagnostic ignored "-Wtraditional"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma GCC diagnostic ignored "-Wformat-nonliteral"
#pragma GCC diagnostic ignored "-Wformat-security"
#pragma GCC diagnostic ignored "-Wextra"
#pragma GCC diagnostic ignored "-Wpointer-arith"
#pragma GCC diagnostic ignored "-Wbad-function-cast"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Waggregate-return"
#pragma GCC diagnostic ignored "-Wstrict-prototypes"
#pragma GCC diagnostic ignored "-Wold-style-definition"
#pragma GCC diagnostic ignored "-Wmissing-declarations"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#pragma GCC diagnostic ignored "-Wmissing-format-attribute"
#pragma GCC diagnostic ignored "-Wshadow"
 */

#if defined(__APPLE__)
/* Disable QuickDraw support in old MacOSX */
#if (__GNUC__ == 4) && (__GNUC_MINOR__ == 2)
#define __QUICKDRAW__
#define __QUICKDRAWAPI__
#define __PALETTES__
#define __PICTUTILS__
#define __QUICKDRAWTYPES__
#define __QDOFFSCREEN__
#define __VIDEO__
#define __DISPLAYS__
#define __ATSUNICODEDRAWING__
#define __HISHAPE__
#define __ICONS__
#endif
#endif

#endif

#if defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wall"
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Weverything"
#pragma GCC diagnostic ignored "-Wconversion"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wmissing-prototypes"
#pragma clang diagnostic ignored "-Wobjc-method-access"
/* #pragma GCC diagnostic ignored "-Wstrict-prototypes" */
/* #pragma clang diagnostic ignored "-Wdeprecated-implementations" */

#endif

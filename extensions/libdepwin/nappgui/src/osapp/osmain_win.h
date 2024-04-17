/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmain_win.h
 *
 */

/* Cross-platform main */

#include <sewer/nowarn.hxx>
#include <Windows.h>
#include <sewer/warn.hxx>

#if (_MSC_VER)
/* Enabling Visual Styles for WindowsXP and later */
#if defined(_M_IX86)
#define MANIFEST_PROCESSORARCHITECTURE "x86"
#elif defined(_M_AMD64)
#define MANIFEST_PROCESSORARCHITECTURE "amd64"
#elif defined(_M_IA64)
#define MANIFEST_PROCESSORARCHITECTURE "ia64"
#else
#error Unknown Architecture
#endif

#pragma comment(linker, \
                "\"/manifestdependency:type='Win32' " \
                "name='Microsoft.Windows.Common-Controls' " \
                "version='6.0.0.0' " \
                "processorArchitecture='" MANIFEST_PROCESSORARCHITECTURE "' " \
                "publicKeyToken='6595b64144ccf1df' " \
                "language='*'\"")

#else
#error Unsupported compiler (XP visual styles)

#endif

#define osmain(func_create, func_destroy, options, type) \
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) \
    { \
        (void)(hPrevInstance), \
            (void)(lpCmdLine), \
            (void)(nCmdShow), \
            FUNC_CHECK_APP_CREATE(func_create, type), \
            FUNC_CHECK_DESTROY(func_destroy, type), \
            osmain_imp( \
                0, NULL, (void *)hInstance, 0., \
                (FPtr_app_create)func_create, \
                (FPtr_app_update)NULL, \
                (FPtr_destroy)func_destroy, \
                options); \
        return 0; \
    }

#define osmain_sync(lframe, func_create, func_destroy, func_update, options, type) \
    int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) \
    { \
        (void)(hPrevInstance), \
            (void)(lpCmdLine), \
            (void)(nCmdShow), \
            FUNC_CHECK_APP_CREATE(func_create, type), \
            FUNC_CHECK_APP_UPDATE(func_update, type), \
            FUNC_CHECK_DESTROY(func_destroy, type), \
            osmain_imp( \
                0, NULL, (void *)hInstance, lframe, \
                (FPtr_app_create)func_create, \
                (FPtr_app_update)func_update, \
                (FPtr_destroy)func_destroy, \
                options); \
        return 0; \
    }

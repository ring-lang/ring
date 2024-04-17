/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmain.h
 *
 */

/* Cross-platform main */

#include "osmain.hxx"

__EXTERN_C

_osapp_api void osmain_imp(uint32_t argc, char_t **argv, void *instance, const real64_t lframe, FPtr_app_create func_create, FPtr_app_update func_update, FPtr_destroy func_destroy, char_t *options);

__END_C

#if defined(__WINDOWS__)
#include "osmain_win.h"
#elif defined(__MACOS__)
#include "osmain_osx.h"
#elif defined(__LINUX__)
#include "osmain_gtk.h"
#else
#error Unknown platform
#endif

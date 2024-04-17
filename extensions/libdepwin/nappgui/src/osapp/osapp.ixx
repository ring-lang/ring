/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp.ixx
 *
 */

/* Application runloop */

#ifndef __OSAPP_IXX__
#define __OSAPP_IXX__

#include "osapp.hxx"
#include <gui/gui.ixx>

typedef struct _osapp_t OSApp;

typedef void (*FPtr_app_call)(void *item);
#define FUNC_CHECK_APP_CALL(func, type) \
    (void)((void (*)(type *))func == func)

typedef void (*FPtr_app_void)(void);
#define FUNC_CHECK_APP_VOID(func) \
    (void)((void (*)(void))func == func)

#endif

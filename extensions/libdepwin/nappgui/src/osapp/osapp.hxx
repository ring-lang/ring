/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp.hxx
 * https://nappgui.com/en/osapp/osapp.html
 *
 */

/* Application runloop */

#ifndef __OSAPP_HXX__
#define __OSAPP_HXX__

#include <gui/gui.hxx>
#include "osapp.def"

typedef uint32_t (*FPtr_task_main)(void *data);
#define FUNC_CHECK_TASK_MAIN(func, type) \
    (void)((uint32_t(*)(type *))func == func)

typedef void (*FPtr_task_update)(void *data);
#define FUNC_CHECK_TASK_UPDATE(func, type) \
    (void)((void (*)(type *))func == func)

typedef void (*FPtr_task_end)(void *data, const uint32_t rvalue);
#define FUNC_CHECK_TASK_END(func, type) \
    (void)((void (*)(type *, const uint32_t))func == func)

#endif

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osapp.h
 * https://nappgui.com/en/osapp/osapp.html
 *
 */

/* Application runloop */

#include "osapp.hxx"

__EXTERN_C

_osapp_api void osapp_finish(void);

_osapp_api void osapp_task_imp(void *data, const real32_t updtime, FPtr_task_main func_task_main, FPtr_task_update func_task_update, FPtr_task_end func_task_end);

_osapp_api void osapp_menubar(Menu *menu, Window *window);

_osapp_api void osapp_open_url(const char_t *url);

__END_C

#define osapp_task(data, updtime, func_main, func_update, func_end, type) \
    ((void)((type *)data == data), \
     FUNC_CHECK_TASK_MAIN(func_main, type), \
     FUNC_CHECK_TASK_UPDATE(func_update, type), \
     FUNC_CHECK_TASK_END(func_end, type), \
     osapp_task_imp((void *)data, updtime, (FPtr_task_main)func_main, (FPtr_task_update)func_update, (FPtr_task_end)func_end))

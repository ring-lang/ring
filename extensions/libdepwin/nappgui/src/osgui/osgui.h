/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui.h
 *
 */

/* Operating system native gui */

#include "osgui.hxx"

__EXTERN_C

_osgui_api void osgui_start(void);

_osgui_api void osgui_finish(void);

_osgui_api void osgui_set_menubar(OSMenu *menu, OSWindow *window);

_osgui_api void osgui_unset_menubar(OSMenu *menu, OSWindow *window);

_osgui_api void osgui_redraw_menubar(void);

_osgui_api void osgui_message_loop(void);

_osgui_api bool_t osgui_is_initialized(void);

_osgui_api void osgui_initialize(void);

_osgui_api void osgui_terminate(void);

_osgui_api void osgui_set_app(void *app, void *icon);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osview.h
 *
 */

/* Operating System native custom view */

#include "osgui.hxx"

__EXTERN_C

_osgui_api OSView *osview_create(const uint32_t flags);

_osgui_api void osview_destroy(OSView **view);

_osgui_api void osview_OnDraw(OSView *view, Listener *listener);

_osgui_api void osview_OnOverlay(OSView *view, Listener *listener);

_osgui_api void osview_OnEnter(OSView *view, Listener *listener);

_osgui_api void osview_OnExit(OSView *view, Listener *listener);

_osgui_api void osview_OnMoved(OSView *view, Listener *listener);

_osgui_api void osview_OnDown(OSView *view, Listener *listener);

_osgui_api void osview_OnUp(OSView *view, Listener *listener);

_osgui_api void osview_OnClick(OSView *view, Listener *listener);

_osgui_api void osview_OnDrag(OSView *view, Listener *listener);

_osgui_api void osview_OnWheel(OSView *view, Listener *listener);

_osgui_api void osview_OnKeyDown(OSView *view, Listener *listener);

_osgui_api void osview_OnKeyUp(OSView *view, Listener *listener);

_osgui_api void osview_OnFocus(OSView *view, Listener *listener);

_osgui_api void osview_OnResignFocus(OSView *view, Listener *listener);

_osgui_api void osview_OnAcceptFocus(OSView *view, Listener *listener);

_osgui_api void osview_OnScroll(OSView *view, Listener *listener);

_osgui_api void osview_scroll(OSView *view, const real32_t x, const real32_t y);

_osgui_api void osview_scroll_get(const OSView *view, real32_t *x, real32_t *y);

_osgui_api void osview_scroller_size(const OSView *view, real32_t *width, real32_t *height);

_osgui_api void osview_scroller_visible(OSView *view, const bool_t horizontal, const bool_t vertical);

_osgui_api void osview_content_size(OSView *view, const real32_t width, const real32_t height, const real32_t line_width, const real32_t line_height);

_osgui_api real32_t osview_scale_factor(const OSView *view);

_osgui_api void osview_set_need_display(OSView *view);

_osgui_api void *osview_get_native_view(const OSView *view);

_osgui_api void osview_attach(OSView *view, OSPanel *panel);

_osgui_api void osview_detach(OSView *view, OSPanel *panel);

_osgui_api void osview_visible(OSView *view, const bool_t visible);

_osgui_api void osview_enabled(OSView *view, const bool_t enabled);

_osgui_api void osview_size(const OSView *view, real32_t *width, real32_t *height);

_osgui_api void osview_origin(const OSView *view, real32_t *x, real32_t *y);

_osgui_api void osview_frame(OSView *view, const real32_t x, const real32_t y, const real32_t width, const real32_t height);

__END_C

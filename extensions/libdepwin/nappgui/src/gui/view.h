/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: view.h
 * https://nappgui.com/en/gui/view.html
 *
 */

/* Custom view */

#include "gui.hxx"

__EXTERN_C

_gui_api View *view_create(void);

_gui_api View *view_scroll(void);

_gui_api View *view_custom(const bool_t scroll, const bool_t border);

_gui_api void view_data_imp(View *view, void **data, FPtr_destroy func_destroy_data);

_gui_api void *view_get_data_imp(const View *view);

_gui_api void view_size(View *view, const S2Df size);

_gui_api void view_OnDraw(View *view, Listener *listener);

_gui_api void view_OnOverlay(View *view, Listener *listener);

_gui_api void view_OnSize(View *view, Listener *listener);

_gui_api void view_OnEnter(View *view, Listener *listener);

_gui_api void view_OnExit(View *view, Listener *listener);

_gui_api void view_OnMove(View *view, Listener *listener);

_gui_api void view_OnDown(View *view, Listener *listener);

_gui_api void view_OnUp(View *view, Listener *listener);

_gui_api void view_OnClick(View *view, Listener *listener);

_gui_api void view_OnDrag(View *view, Listener *listener);

_gui_api void view_OnWheel(View *view, Listener *listener);

_gui_api void view_OnKeyDown(View *view, Listener *listener);

_gui_api void view_OnKeyUp(View *view, Listener *listener);

_gui_api void view_OnFocus(View *view, Listener *listener);

_gui_api void view_OnResignFocus(View *view, Listener *listener);

_gui_api void view_OnAcceptFocus(View *view, Listener *listener);

_gui_api void view_OnScroll(View *view, Listener *listener);

_gui_api void view_keybuf(View *view, KeyBuf *buffer);

_gui_api void view_get_size(const View *view, S2Df *size);

_gui_api void view_content_size(View *view, const S2Df size, const S2Df line);

_gui_api void view_scroll_x(View *view, const real32_t pos);

_gui_api void view_scroll_y(View *view, const real32_t pos);

_gui_api void view_scroll_size(const View *view, real32_t *width, real32_t *height);

_gui_api void view_scroll_visible(View *view, const bool_t horizontal, const bool_t vertical);

_gui_api void view_viewport(const View *view, V2Df *pos, S2Df *size);

_gui_api void view_point_scale(const View *view, real32_t *scale);

_gui_api void view_update(View *view);

_gui_api void *view_native(View *view);

__END_C

#define view_data(view, data, func_destroy_data, type) \
    ( \
        (void)((type **)data == data), \
        FUNC_CHECK_DESTROY(func_destroy_data, type), \
        view_data_imp(view, (void **)data, (FPtr_destroy)func_destroy_data))

#define view_get_data(view, type) \
    (type *)view_get_data_imp(view)

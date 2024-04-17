/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: panel.h
 * https://nappgui.com/en/gui/panel.html
 *
 */

/* Panel */

#include "gui.hxx"

__EXTERN_C

_gui_api Panel *panel_create(void);

_gui_api Panel *panel_scroll(const bool_t hscroll, const bool_t vscroll);

_gui_api Panel *panel_custom(const bool_t hscroll, const bool_t vscroll, const bool_t border);

_gui_api void panel_data_imp(Panel *panel, void **data, FPtr_destroy func_destroy_data);

_gui_api void *panel_get_data_imp(const Panel *panel);

_gui_api void panel_size(Panel *panel, const S2Df size);

_gui_api uint32_t panel_layout(Panel *panel, Layout *layout);

_gui_api Layout *panel_get_layout(Panel *panel, const uint32_t index);

_gui_api void panel_visible_layout(Panel *panel, const uint32_t index);

_gui_api void panel_update(Panel *panel);

_gui_api real32_t panel_scroll_width(const Panel *panel);

_gui_api real32_t panel_scroll_height(const Panel *panel);

__END_C

#define panel_data(panel, data, func_destroy_data, type) \
    ( \
        (void)((type **)data == data), \
        FUNC_CHECK_DESTROY(func_destroy_data, type), \
        panel_data_imp(panel, (void **)data, (FPtr_destroy)func_destroy_data))

#define panel_get_data(panel, type) \
    (type *)panel_get_data_imp(panel)

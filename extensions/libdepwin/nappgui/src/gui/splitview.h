/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: splitview.h
 * https://nappgui.com/en/gui/splitview.html
 *
 */

/* Split view */

#include "gui.hxx"

__EXTERN_C

_gui_api SplitView *splitview_horizontal(void);

_gui_api SplitView *splitview_vertical(void);

_gui_api void splitview_size(SplitView *split, const S2Df size);

_gui_api void splitview_view(SplitView *split, View *view, const bool_t tabstop);

_gui_api void splitview_text(SplitView *split, TextView *view, const bool_t tabstop);

_gui_api void splitview_split(SplitView *split, SplitView *child);

_gui_api void splitview_panel(SplitView *split, Panel *panel);

_gui_api void splitview_pos(SplitView *split, const real32_t pos);

__END_C

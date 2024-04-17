/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: tableview.h
 * https://nappgui.com/en/gui/tableview.html
 *
 */

/* TableView */

#include "gui.hxx"

__EXTERN_C

_gui_api TableView *tableview_create(void);

_gui_api void tableview_OnData(TableView *view, Listener *listener);

_gui_api void tableview_OnSelect(TableView *view, Listener *listener);

_gui_api void tableview_OnRowClick(TableView *view, Listener *listener);

_gui_api void tableview_OnHeaderClick(TableView *view, Listener *listener);

_gui_api void tableview_font(TableView *view, const Font *font);

_gui_api void tableview_size(TableView *view, S2Df size);

_gui_api uint32_t tableview_new_column_text(TableView *view);

_gui_api void tableview_column_width(TableView *view, const uint32_t column_id, const real32_t width);

_gui_api void tableview_column_limits(TableView *view, const uint32_t column_id, const real32_t min, const real32_t max);

_gui_api void tableview_column_resizable(TableView *view, const uint32_t column_id, const bool_t resizable);

_gui_api void tableview_column_freeze(TableView *view, const uint32_t last_column_id);

_gui_api void tableview_header_title(TableView *view, const uint32_t column_id, const char_t *text);

_gui_api void tableview_header_align(TableView *view, const uint32_t column_id, const align_t align);

_gui_api void tableview_header_indicator(TableView *view, const uint32_t column_id, const uint32_t indicator);

_gui_api void tableview_header_visible(TableView *view, const bool_t visible);

_gui_api void tableview_header_clickable(TableView *view, const bool_t clickable);

_gui_api void tableview_header_resizable(TableView *view, const bool_t resizable);

_gui_api void tableview_header_height(TableView *view, const real32_t height);

_gui_api void tableview_row_height(TableView *view, const real32_t height);

_gui_api void tableview_hkey_scroll(TableView *view, const bool_t force_column, const real32_t scroll);

_gui_api void tableview_multisel(TableView *view, const bool_t multisel, const bool_t preserve);

_gui_api void tableview_grid(TableView *view, const bool_t hlines, const bool_t vlines);

_gui_api void tableview_update(TableView *view);

_gui_api void tableview_select(TableView *view, const uint32_t *rows, const uint32_t n);

_gui_api void tableview_deselect(TableView *view, const uint32_t *rows, const uint32_t n);

_gui_api void tableview_deselect_all(TableView *view);

_gui_api const ArrSt(uint32_t) *tableview_selected(const TableView *view);

_gui_api void tableview_focus_row(TableView *view, const uint32_t row, const align_t align);

_gui_api uint32_t tableview_get_focus_row(const TableView *view);

_gui_api void tableview_scroll_visible(TableView *view, const bool_t horizontal, const bool_t vertical);

__END_C

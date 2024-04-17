/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: cell.h
 * https://nappgui.com/en/gui/cell.html
 *
 */

/* Layout-cells */

#include "gui.hxx"

__EXTERN_C

_gui_api bool_t cell_empty(Cell *cell);

_gui_api GuiControl *cell_control(Cell *cell);

_gui_api Label *cell_label(Cell *cell);

_gui_api Button *cell_button(Cell *cell);

_gui_api PopUp *cell_popup(Cell *cell);

_gui_api Edit *cell_edit(Cell *cell);

_gui_api Combo *cell_combo(Cell *cell);

_gui_api ListBox *cell_listbox(Cell *cell);

_gui_api UpDown *cell_updown(Cell *cell);

_gui_api Slider *cell_slider(Cell *cell);

_gui_api Progress *cell_progress(Cell *cell);

_gui_api View *cell_view(Cell *cell);

_gui_api TextView *cell_textview(Cell *cell);

_gui_api ImageView *cell_imageview(Cell *cell);

_gui_api TableView *cell_tableview(Cell *cell);

_gui_api SplitView *cell_splitview(Cell *cell);

_gui_api Panel *cell_panel(Cell *cell);

_gui_api Layout *cell_layout(Cell *cell);

_gui_api void cell_enabled(Cell *cell, const bool_t enabled);

_gui_api void cell_visible(Cell *cell, const bool_t visible);

_gui_api void cell_padding(Cell *cell, const real32_t pall);

_gui_api void cell_padding2(Cell *cell, const real32_t ptb, const real32_t plr);

_gui_api void cell_padding4(Cell *cell, const real32_t pt, const real32_t pr, const real32_t pb, const real32_t pl);

_gui_api void cell_dbind_imp(
    Cell *cell,
    const char_t *type,
    const uint16_t size,
    const char_t *mname,
    const char_t *mtype,
    const uint16_t moffset,
    const uint16_t msize);

__END_C

#define cell_dbind(cell, type, mtype, mname) \
    ( \
        CHECK_STRUCT_MEMBER_TYPE(type, mname, mtype), \
        cell_dbind_imp( \
            cell, \
            (const char_t *)#type, \
            (uint16_t)sizeof(type), \
            (const char_t *)#mname, \
            (const char_t *)#mtype, \
            (uint16_t)STRUCT_MEMBER_OFFSET(type, mname), \
            (uint16_t)STRUCT_MEMBER_SIZE(type, mname)))

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: cell.inl
 *
 */

/* Layout-cells */

#include "gui.ixx"

__EXTERN_C

GuiComponent *_cell_component(Cell *cell);

Layout *_cell_parent(Cell *cell);

void _cell_set_radio(Cell *on_cell);

void _cell_set_radio_index(Cell *on_cell, const uint32_t index);

uint32_t _cell_radio_index(Cell *on_cell);

Button *_cell_radio_listener(Cell *on_cell);

Cell *_cell_radio_dbind_cell(Cell *on_cell);

bool_t _cell_filter_str(Cell *cell, const char_t *str, char_t *dest, const uint32_t size);

void _cell_upd_bool(Cell *cell, const bool_t value);

void _cell_upd_uint32(Cell *cell, const uint32_t value);

void _cell_upd_norm_real32(Cell *cell, const real32_t value);

void _cell_upd_string(Cell *cell, const char_t *str);

void _cell_upd_image(Cell *cell, const Image *image);

void _cell_upd_increment(Cell *cell, const bool_t pos);

bool_t _cell_enabled(const Cell *cell);

__END_C

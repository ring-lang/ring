/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: layout.inl
 *
 */

/* Layouts */

#include "gui.ixx"

__EXTERN_C

void _layout_destroy(Layout **layout);

void _layout_attach_to_panel(Layout *layout, Panel *panel);

Panel *_layout_panel(const Layout *layout);

Layout *_layout_search_component(const Layout *layout, const GuiComponent *component, Cell **in_cell, const bool_t in_subpanels);

bool_t _layout_search_layout(const Layout *layout, Layout *sublayout);

void _layout_components(const Layout *layout, ArrPt(GuiComponent) *components);

void _layout_compose(Layout *layout, const S2Df *required_size, S2Df *final_size);

void _layout_dimension(Layout *layout, const uint32_t di, real32_t *dim0, real32_t *dim1);

void _layout_expand(Layout *layout, const uint32_t di, const real32_t current_size, const real32_t required_size, real32_t *final_size);

void _layout_locate(Layout *layout);

void _layout_taborder(const Layout *layout, Window *window);

void _layout_dbind_update(Layout *layout, const DBind *dbind);

ArrPt(Cell) *_layout_cells(Layout *layout);

void _layout_notif(Layout *layout, void **obj, const char_t **obj_type, Listener **listener);

__END_C

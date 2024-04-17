/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: gbind.inl
 *
 */

/* Gui data binding */

#include "gui.ixx"

__EXTERN_C

void gbind_upd_component(Cell *cell, const StBind *stbind, const DBind *dbind, void *obj);

void gbind_upd_layout(Layout *layout, const StBind *stbind, const DBind *dbind, void *obj);

void gbind_upd_bool(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, bool_t value);

void gbind_upd_uint32(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, uint32_t value);

void gbind_upd_norm_real32(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, const real32_t value);

void gbind_upd_string(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, const char_t *str);

void gbind_upd_image(Layout *layout, const DBind *dbind, void *objbind, const Image *image);

void gbind_upd_increment(Layout *layout, const DBind *dbind, void *obj, Layout *layout_notif, const bool_t pos);

bool_t gbind_modify_data(const void *obj, const char_t *type, const uint16_t size, const char_t *mname, const char_t *mtype, const uint16_t moffset, const uint16_t msize, const EvBind *evbind);

__END_C

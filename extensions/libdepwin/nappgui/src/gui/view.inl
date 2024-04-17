/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: view.inl
 *
 */

/* Custom view */

#include "gui.ixx"

__EXTERN_C

void view_add_transition(View *view, Listener *listener);

void view_delete_transition(View *view);

View *_view_create(const uint32_t flags);

void _view_destroy(View **view);

void _view_set_subtype(View *view, const char_t *subtype);

const char_t *_view_subtype(const View *view);

void _view_dimension(View *view, const uint32_t i, real32_t *dim0, real32_t *dim1);

void _view_OnResize(View *view, const S2Df *size);

Cell *_view_cell(View *view);

void *_view_get_native_imp(View *view);

void view_OnEmpty(View *view, FPtr_gctx_call func_empty);

void view_OnUInt32(View *view, FPtr_gctx_set_uint32 func_uint32);

void view_OnImage(View *view, FPtr_set_image func_image);

void _view_empty(View *view);

void _view_uint32(View *view, const uint32_t value);

void _view_image(View *view, const Image *image);

__END_C

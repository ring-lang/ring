/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: edit.inl
 *
 */

/* Edit Box */

#include "gui.ixx"

__EXTERN_C

void _edit_destroy(Edit **edit);

void _edit_dimension(Edit *edit, const uint32_t i, real32_t *dim0, real32_t *dim1);

void _edit_locale(Edit *edit);

bool_t _edit_is_multiline(const Edit *edit);

void _edit_text(Edit *edit, const char_t *text);

__END_C

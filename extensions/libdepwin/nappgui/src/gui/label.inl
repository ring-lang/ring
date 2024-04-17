/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: label.inl
 *
 */

/* Label */

#include "gui.ixx"

__EXTERN_C

void _label_destroy(Label **label);

void _label_dimension(Label *label, const uint32_t i, real32_t *dim0, real32_t *dim1);

void _label_locale(Label *label);

void _label_text(Label *label, const char_t *text);

bool_t _label_is_multiline(const Label *label);

__END_C

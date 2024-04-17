/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: combo.inl
 *
 */

/* Combo box */

#include "gui.ixx"

__EXTERN_C

void _combo_destroy(Combo **combo);

void _combo_dimension(Combo *combo, const uint32_t i, real32_t *dim0, real32_t *dim1);

void _combo_locale(Combo *combo);

__END_C

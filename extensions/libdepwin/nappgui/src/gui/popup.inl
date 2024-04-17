/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: popup.inl
 *
 */

/* Pop-up button */

#include "gui.ixx"

__EXTERN_C

void _popup_destroy(PopUp **popup);

void _popup_dimension(PopUp *popup, const uint32_t i, real32_t *dim0, real32_t *dim1);

void _popup_locale(PopUp *popup);

uint32_t _popup_size(const PopUp *popup);

void _popup_list_height(PopUp *popup, const uint32_t elems);

void _popup_uint32(PopUp *popup, const uint32_t value);

void _popup_add_enum_item(PopUp *popup, const char_t *text);

__END_C

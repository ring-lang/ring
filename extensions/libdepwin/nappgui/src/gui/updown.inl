/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: updown.inl
 *
 */

/* Up Down */

#include "gui.ixx"

__EXTERN_C

void _updown_destroy(UpDown **updown);

void _updown_dimension(UpDown *updown, const uint32_t i, real32_t *dim0, real32_t *dim1);

__END_C

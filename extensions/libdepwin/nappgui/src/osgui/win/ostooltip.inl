/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ostooltip.inl
 *
 */

/* Tooltips */

#include "osgui_win.ixx"

__EXTERN_C

void _ostooltip_set_text(HWND *tooltip_hwnd, HWND control_hwnd, const char_t *text);

void _ostooltip_destroy_optional(HWND *tooltip_hwnd, HWND control_hwnd);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslabel_win.inl
 *
 */

/* Operating System label */

#include "osgui_win.ixx"

__EXTERN_C

COLORREF _oslabel_color(const OSLabel *label);

HBRUSH _oslabel_background_color(const OSLabel *label, COLORREF *color);

__END_C

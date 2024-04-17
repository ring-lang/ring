/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ostext.inl
 *
 */

/* Operating System native text view */

#include "osgui.ixx"

__EXTERN_C

void ostext_detach_and_destroy(OSText **view, OSPanel *panel);

void ostext_focus(OSText *view, const bool_t focus);

__END_C

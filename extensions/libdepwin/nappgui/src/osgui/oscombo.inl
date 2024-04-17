/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscombo.inl
 *
 */

/* Operating System native combo box */

#include "osgui.ixx"

__EXTERN_C

void oscombo_detach_and_destroy(OSCombo **combo, OSPanel *panel);

bool_t oscombo_resign_focus(const OSCombo *combo);

void oscombo_focus(OSCombo *combo, const bool_t focus);

__END_C

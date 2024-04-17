/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osedit.inl
 *
 */

/* Operating System edit box */

#include "osgui.ixx"

__EXTERN_C

void osedit_detach_and_destroy(OSEdit **edit, OSPanel *panel);

bool_t osedit_resign_focus(const OSEdit *edit);

void osedit_focus(OSEdit *edit, const bool_t focus);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscombo_gtk.inl
 *
 */

/* Operating System native combo box */

#include "osgui_gtk.ixx"

__EXTERN_C

GtkWidget *_oscombo_focus_widget(OSCombo *combo);

void _oscombo_elem(GtkComboBox *combo, const ctrl_op_t op, const uint32_t index, const char_t *text, const Image *image, ArrPt(String) *texts, ArrPt(Image) *images, uint32_t *imgwidth, uint32_t *imgheight);

__END_C

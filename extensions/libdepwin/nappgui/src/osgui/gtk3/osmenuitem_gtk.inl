/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osmenuitem_gtk.inl
 *
 */

/* Operating System native menu item */

#include "osgui_gtk.ixx"

__EXTERN_C

GtkWidget *_osmenuitem_widget(OSMenuItem *item);

GtkWidget *_osmenuitem_bar_widget(OSMenuItem *item);

void _osmenuitem_set_parent(OSMenuItem *item, OSMenu *menu, GtkMenuShell *menushell);

void _osmenuitem_unset_parent(OSMenuItem *item, OSMenu *menu, GtkMenuShell *menushell);

void _osmenuitem_set_accel(OSMenuItem *item, GtkAccelGroup *accel);

void _osmenuitem_unset_accel(OSMenuItem *item, GtkAccelGroup *accel);

__END_C

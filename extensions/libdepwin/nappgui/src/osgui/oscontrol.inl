/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscontrol.inl
 *
 */

/* Control common functions */

#include "osgui.ixx"

__EXTERN_C

gui_type_t oscontrol_type(const OSControl *control);

const char_t *oscontrol_type_str(const gui_type_t type);

OSControl *oscontrol_parent(const OSControl *control);

void oscontrol_frame(const OSControl *control, OSFrame *rect);

OSWidget *oscontrol_focus_widget(const OSControl *control);

bool_t oscontrol_widget_visible(const OSWidget *widget);

bool_t oscontrol_widget_enable(const OSWidget *widget);

void oscontrol_detach_and_destroy(OSControl **control, OSPanel *panel);

__END_C

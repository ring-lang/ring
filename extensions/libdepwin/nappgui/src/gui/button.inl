/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: button.inl
 *
 */

/* Button */

#include "gui.ixx"

__EXTERN_C

void _button_destroy(Button **button);

void _button_dimension(Button *button, const uint32_t i, real32_t *dim0, real32_t *dim1);

void _button_locale(Button *button);

uint32_t _button_flags(const Button *button);

bool_t _button_is_pushbutton(const Button *button);

bool_t _button_is_radio(const Button *button);

Listener *_button_radio_listener(const Button *button);

void _button_radio_state(Button *button, const gui_state_t state);

void _button_bool(Button *button, const bool_t value);

void _button_uint32(Button *button, const uint32_t value);

__END_C

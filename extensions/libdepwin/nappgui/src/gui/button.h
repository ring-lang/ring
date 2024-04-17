/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: button.h
 * https://nappgui.com/en/gui/button.html
 *
 */

/* Button */

#include "gui.hxx"

__EXTERN_C

_gui_api Button *button_push(void);

_gui_api Button *button_check(void);

_gui_api Button *button_check3(void);

_gui_api Button *button_radio(void);

_gui_api Button *button_flat(void);

_gui_api Button *button_flatgle(void);

_gui_api void button_OnClick(Button *button, Listener *listener);

_gui_api void button_text(Button *button, const char_t *text);

_gui_api void button_text_alt(Button *button, const char_t *text);

_gui_api void button_tooltip(Button *button, const char_t *text);

_gui_api void button_font(Button *button, const Font *font);

_gui_api void button_image(Button *button, const Image *image);

_gui_api void button_image_alt(Button *button, const Image *image);

_gui_api void button_state(Button *button, const gui_state_t state);

_gui_api void button_tag(Button *button, const uint32_t tag);

_gui_api void button_vpadding(Button *button, const real32_t padding);

_gui_api gui_state_t button_get_state(const Button *button);

_gui_api uint32_t button_get_tag(const Button *button);

_gui_api real32_t button_get_height(const Button *button);

__END_C

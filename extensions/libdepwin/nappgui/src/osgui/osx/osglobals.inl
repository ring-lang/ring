/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osglobals.inl
 *
 */

/* Operating System globals */

void osglobals_init(void);

void osglobals_finish(void);

uint32_t osglobals_check_width(void);

uint32_t osglobals_check_height(void);

NSSize osglobals_check_size(void);

NSRect osglobals_check_rect(void);

NSRect osglobals_header_rect(void);

NSImage *osglobals_checkbox_image(const bool_t pressed, const ctrl_state_t state);

NSImage *osglobals_header_image(const bool_t pressed);

const CGFloat *osglobals_text_color(void);

const CGFloat *osglobals_seltx_color(void);

const CGFloat *osglobals_hottx_color(void);

const CGFloat *osglobals_textbackdrop_color(void);

const CGFloat *osglobals_seltxbackdrop_color(void);

const CGFloat *osglobals_hottxbackdrop_color(void);

const CGFloat *osglobals_back_color(void);

const CGFloat *osglobals_hotbg_color(void);

const CGFloat *osglobals_selbg_color(void);

const CGFloat *osglobals_backbackdrop_color(void);

const CGFloat *osglobals_hotbgbackdrop_color(void);

const CGFloat *osglobals_selbgbackdrop_color(void);

color_t osglobals_focus_color(void);

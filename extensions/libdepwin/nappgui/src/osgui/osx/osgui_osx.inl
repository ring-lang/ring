/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui_osx.inl
 *
 */

/* Operating system native gui */

#include "osgui_osx.ixx"

__EXTERN_C

extern NSNumber *kUNDERLINE_STYLE_NONE;
extern NSNumber *kUNDERLINE_STYLE_SINGLE;
extern NSMutableParagraphStyle *kLEFT_PARAGRAPH_STYLE;
extern NSMutableParagraphStyle *kCENTER_PARAGRAPH_STYLE;
extern NSMutableParagraphStyle *kRIGHT_PARAGRAPH_STYLE;

vkey_t osgui_vkey(unsigned short keycode);

void osgui_modifier_flags(
    NSUInteger flags,
    bool_t *rshift, bool_t *rctrl, bool_t *rcommand, bool_t *ralt,
    bool_t *lshift, bool_t *lctrl, bool_t *lcommand, bool_t *lalt);

uint32_t osgui_modifiers(NSUInteger flags);

uint32_t osgui_key_equivalent_text(const char_t *text, char_t *buff, const uint32_t size);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui.inl
 *
 */

/* Operating system native gui */

#include "osgui.ixx"

__EXTERN_C

void osgui_start_imp(void);

void osgui_finish_imp(void);

Font *osgui_create_default_font(void);

void osgui_word_size(StringSizeData *data, const char_t *word, real32_t *width, real32_t *height);

void osgui_text_bounds(StringSizeData *data, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height);

gui_size_t osgui_size_font(const real32_t font_size);

vkey_t osgui_vkey_from_text(const char_t *text);

void osgui_select_text(const int32_t st, const int32_t ed, int32_t *platform_st, int32_t *platform_ed);

void osgui_attach_menubar(OSWindow *window, OSMenu *menu);

void osgui_detach_menubar(OSWindow *window, OSMenu *menu);

void osgui_change_menubar(OSWindow *window, OSMenu *previous_menu, OSMenu *new_menu);

void osgui_message_loop_imp(void);

bool_t osgui_is_pre_initialized_imp(void);

void osgui_pre_initialize_imp(void);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: res_gui.h
 *
 */

/* Gui library resources */

#include <core/core.hxx>

__EXTERN_C

/* Messages */
extern ResId ASSERT_CRASH;
extern ResId ASSERT_INFO;
extern ResId CONTACT_INFO;
extern ResId FILE_TEXT;
extern ResId LINE_TEXT;
extern ResId SHOW_ASSERT;
extern ResId ASSERT_LOG;
extern ResId ASSERT_TITLE;
extern ResId DEBUG_TEXT;
extern ResId CONTINUE_TEXT;
extern ResId EXIT_TEXT;

/* Files */
extern ResId BOMB_PNG;
extern ResId BOMB_DARK_PNG;
extern ResId CONFUSED_PNG;
extern ResId CONFUSED_DARK_PNG;
extern ResId LOGO_PNG;
extern ResId LOGO_DARK_PNG;

ResPack *res_gui_respack(const char_t *locale);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osgui.c
 *
 */

/* Operating system native gui */

#include "osgui.h"
#include "osgui.inl"
#include "oswindow.inl"
#include <draw2d/draw2d.h>
#include <draw2d/font.h>
#include <draw2d/image.h>
#include <core/arrpt.h>
#include <core/heap.h>
#include <core/strings.h>
#include <osbs/log.h>
#include <sewer/blib.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>
#include <sewer/unicode.h>

static uint32_t i_NUM_USERS = 0;
static Font *i_DEFAULT_FONT = NULL;
static OSWindow *i_MAIN_WINDOW = NULL;
static OSMenu *i_MAIN_MENU = NULL;

static const vkey_t kASCII_VIRTUAL_KEY[] =
    {
        ekKEY_A,
        ekKEY_B,
        ekKEY_C,
        ekKEY_D,
        ekKEY_E,
        ekKEY_F,
        ekKEY_G,
        ekKEY_H,
        ekKEY_I,
        ekKEY_J,
        ekKEY_K,
        ekKEY_L,
        ekKEY_M,
        ekKEY_N,
        ekKEY_O,
        ekKEY_P,
        ekKEY_Q,
        ekKEY_R,
        ekKEY_S,
        ekKEY_T,
        ekKEY_U,
        ekKEY_V,
        ekKEY_W,
        ekKEY_X,
        ekKEY_Y,
        ekKEY_Z};

/*---------------------------------------------------------------------------*/

static void i_osgui_atexit(void)
{
    if (i_NUM_USERS != 0)
        log_printf("Error! osgui is not properly closed (%d)\n", i_NUM_USERS);
}

/*---------------------------------------------------------------------------*/

void osgui_start(void)
{
    if (i_NUM_USERS == 0)
    {
        draw2d_start();
        osgui_start_imp();
        blib_atexit(i_osgui_atexit);
    }

    i_NUM_USERS += 1;
}

/*---------------------------------------------------------------------------*/

void osgui_finish(void)
{
    cassert(i_NUM_USERS > 0);
    if (i_NUM_USERS == 1)
    {
        if (i_DEFAULT_FONT != NULL)
            font_destroy(&i_DEFAULT_FONT);

        osgui_finish_imp();
        draw2d_finish();
    }

    i_NUM_USERS -= 1;
}

/*---------------------------------------------------------------------------*/

void osgui_set_menubar(OSMenu *menu, OSWindow *window)
{
    cassert_no_null(window);
    cassert(i_MAIN_WINDOW == NULL || i_MAIN_WINDOW == window);
    i_MAIN_WINDOW = window;
    if (i_MAIN_MENU != menu)
    {
        if (i_MAIN_MENU != NULL && menu != NULL)
        {
            osgui_change_menubar(i_MAIN_WINDOW, i_MAIN_MENU, menu);
        }
        else if (i_MAIN_MENU != NULL && menu == NULL)
        {
            osgui_detach_menubar(i_MAIN_WINDOW, i_MAIN_MENU);
        }
        else
        {
            cassert(i_MAIN_MENU == NULL && menu != NULL);
            osgui_attach_menubar(i_MAIN_WINDOW, menu);
        }

        i_MAIN_MENU = menu;
    }
}

/*---------------------------------------------------------------------------*/

void osgui_unset_menubar(OSMenu *menu, OSWindow *window)
{
    if ((menu != NULL && i_MAIN_MENU == menu) || (window != NULL && i_MAIN_WINDOW == window))
    {
        cassert_no_null(i_MAIN_WINDOW);
        osgui_detach_menubar(i_MAIN_WINDOW, i_MAIN_MENU);
        i_MAIN_MENU = NULL;
        i_MAIN_WINDOW = NULL;
    }
}

/*---------------------------------------------------------------------------*/

void osgui_redraw_menubar(void)
{
#if defined(__WINDOWS__)
    if (i_MAIN_MENU != NULL && i_MAIN_WINDOW != NULL)
        osgui_change_menubar(i_MAIN_WINDOW, i_MAIN_MENU, i_MAIN_MENU);
#endif
}

/*---------------------------------------------------------------------------*/

void osgui_message_loop(void)
{
    osgui_message_loop_imp();
}

/*---------------------------------------------------------------------------*/

bool_t osgui_is_initialized(void)
{
    return osgui_is_pre_initialized_imp();
}

/*---------------------------------------------------------------------------*/

void osgui_initialize(void)
{
    osgui_pre_initialize_imp();
}

/*---------------------------------------------------------------------------*/

void osgui_terminate(void)
{
    oswindow_set_app_terminate();
}

/*---------------------------------------------------------------------------*/

void osgui_set_app(void *app, void *icon)
{
    oswindow_set_app(app, icon);
}

/*---------------------------------------------------------------------------*/

Font *osgui_create_default_font(void)
{
    if (i_DEFAULT_FONT == NULL)
        i_DEFAULT_FONT = font_system(font_regular_size(), 0);
    return font_copy(i_DEFAULT_FONT);
}

/*---------------------------------------------------------------------------*/

static const char_t *i_jump_blanks(const char_t *str)
{
    cassert_no_null(str);
    for (; *str != '\0';)
    {
        if (*str == ' ' || *str == '\t' || *str == '\r')
        {
            str += 1;
        }
        else
        {
            return str;
        }
    }

    return str;
}

/*---------------------------------------------------------------------------*/

static const char_t *i_jump_not_blanks(const char_t *str)
{
    cassert_no_null(str);
    for (; *str != '\0';)
    {
        if (*str != ' ' && *str != '\t' && *str != '\r' && *str != '\0' && *str != '\n')
        {
            str += 1;
        }
        else
        {
            return str;
        }
    }

    return str;
}

/*---------------------------------------------------------------------------*/
#define i_WORD_TYPE_END 0
#define i_WORD_TYPE_NEW_LINE 1
#define i_WORD_TYPE_BLANCKS 2
#define i_WORD_TYPE_TEXT 3

static const char_t *i_next_word(const char_t *str, int *word_type)
{
    cassert_no_null(str);
    cassert_no_null(word_type);
    {
        if (*str == '\0')
        {
            *word_type = i_WORD_TYPE_END;
            return NULL;
        }
        else if (*str == '\n')
        {
            *word_type = i_WORD_TYPE_NEW_LINE;
            return str + 1;
        }
    }

    {
        register const char_t *end = i_jump_blanks(str);
        if (end != str)
        {
            *word_type = i_WORD_TYPE_BLANCKS;
            return end;
        }
    }

    {
        register const char_t *end = i_jump_not_blanks(str);
        cassert(end != str);
        *word_type = i_WORD_TYPE_TEXT;
        return end;
    }
}

/*---------------------------------------------------------------------------*/

static void i_new_line(StringSizeData *data, real32_t *current_width, real32_t *current_height, real32_t *current_width_without_spaces, uint32_t *num_lines, real32_t *width, real32_t *height)
{
    cassert_no_null(current_width);
    cassert_no_null(current_height);
    cassert_no_null(current_width_without_spaces);
    cassert_no_null(num_lines);
    cassert_no_null(width);
    cassert_no_null(height);

    if (*current_width_without_spaces == 0.f)
    {
        real32_t word_width = 0.f, word_height = 0.f;
        osgui_word_size(data, "A", &word_width, &word_height);
        *current_width_without_spaces = 0;
        *current_height = word_height;
    }
    else
    {
        cassert(*current_height > 0.f);
    }

    if (*current_width_without_spaces > *width)
        *width = *current_width_without_spaces;
    *height += *current_height;

    *current_width = 0.f;
    *current_width_without_spaces = 0.f;
    *current_height = 0.f;
    *num_lines += 1;
}

/*---------------------------------------------------------------------------*/

static real32_t i_ceil(const real32_t n)
{
    int32_t in = (int32_t)n;
    if (n == (real32_t)in)
    {
        return (real32_t)in;
    }

    return (real32_t)(in + 1);
}

/*---------------------------------------------------------------------------*/

void osgui_text_bounds(StringSizeData *data, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    uint32_t num_lines = 0;
    real32_t ref_width = refwidth > 0.f ? refwidth : 1e8f;
    real32_t current_width = 0.f, current_height = 0.f, current_width_without_spaces = 0.f;
    register const char_t *ctext = text;
    cassert_no_null(width);
    cassert_no_null(height);
    *width = 0.f;
    *height = 0.f;

    while (ctext != NULL)
    {
        const char_t *next_text = NULL;
        int word_type = 0;

        next_text = i_next_word(ctext, &word_type);

        switch (word_type)
        {

        case i_WORD_TYPE_END:
            if (current_width > .01f || num_lines == 0)
                i_new_line(data, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
            break;

        case i_WORD_TYPE_NEW_LINE:
            i_new_line(data, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
            break;

        case i_WORD_TYPE_BLANCKS:
            if (current_width_without_spaces > 0.f)
            {
                char_t word[128];
                real32_t word_width = 0.f, word_height = 0.f;
                register uint32_t size = (uint32_t)(next_text - ctext);
                cassert(next_text > ctext);
                str_copy_cn(word, 128, ctext, size);
                word[size] = '\0';
                osgui_word_size(data, word, &word_width, &word_height);
                if (current_width + word_width <= ref_width)
                {
                    current_width += word_width;
                    if (word_height > current_height)
                        current_height = word_height;
                }
                else
                {
                    i_new_line(data, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
                }
            }
            break;

        case i_WORD_TYPE_TEXT:
        {
            char_t word[128];
            real32_t word_width = 0.f, word_height = 0.f;
            register uint32_t size = (uint32_t)(next_text - ctext);
            cassert(next_text > ctext);
            cassert(word_type == i_WORD_TYPE_TEXT);
            str_copy_cn(word, 128, ctext, size);
            word[size] = '\0';
            osgui_word_size(data, word, &word_width, &word_height);

            if (current_width + word_width <= ref_width)
            {
                current_width += word_width;
                if (word_height > current_height)
                    current_height = word_height;
            }
            else
            {
                i_new_line(data, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
                current_width = word_width;
                current_height = word_height;
            }

            current_width_without_spaces = current_width;
            break;
        }

            cassert_default();
        }

        ctext = next_text;
    }

    *width = i_ceil(*width);
    *height = i_ceil(*height);
}

/*---------------------------------------------------------------------------*/

gui_size_t osgui_size_font(const real32_t font_size)
{
    if (font_size > font_regular_size() - 0.1f)
        return ekGUI_SIZE_REGULAR;
    if (font_size > font_small_size() - 0.1f)
        return ekGUI_SIZE_SMALL;
    return ekGUI_SIZE_MINI;
}

/*---------------------------------------------------------------------------*/

vkey_t osgui_vkey_from_text(const char_t *text)
{
    uint32_t vcp = 0;
    uint32_t nb = 0;
    uint32_t cp = unicode_to_u32b(text, ekUTF8, &nb);
    bool_t prev_ampersand = FALSE;

    while (cp != 0)
    {
        if (cp == '&')
        {
            prev_ampersand = !prev_ampersand;
        }
        else if (prev_ampersand == TRUE)
        {
            vcp = cp;
            prev_ampersand = FALSE;
        }
        else
        {
            prev_ampersand = FALSE;
        }

        text += nb;
        cp = unicode_to_u32b(text, ekUTF8, &nb);
    }

    vcp = unicode_toupper(vcp);

    /* Only letters will be transformed into hotkey */
    if (vcp >= 'A' && vcp <= 'Z')
    {
        cassert(sizeof(kASCII_VIRTUAL_KEY) / sizeof(vkey_t) == 'Z' - 'A' + 1);
        return kASCII_VIRTUAL_KEY[vcp - 'A'];
    }

    return ENUM_MAX(vkey_t);
}

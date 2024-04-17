/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw2d.c
 *
 */

/* Operating system 2D drawing support */

#include "draw2d.h"
#include "draw2d.inl"
#include "draw.inl"
#include "font.inl"
#include "image.inl"
#include "image.h"
#include "color.h"
#include "font.h"
#include <core/arrpt.h>
#include <core/arrst.h>
#include <core/core.h>
#include <core/dbindh.h>
#include <core/heap.h>
#include <core/strings.h>
#include <osbs/log.h>
#include <sewer/blib.h>
#include <sewer/bmath.h>
#include <sewer/bmem.h>
#include <sewer/cassert.h>

typedef struct _icolor_t IColor;

struct _icolor_t
{
    uint16_t index;
    color_t color;
};

DeclSt(IColor);

#define i_WORD_TYPE_END 0
#define i_WORD_TYPE_NEW_LINE 1
#define i_WORD_TYPE_BLANCKS 2
#define i_WORD_TYPE_TEXT 3

static uint32_t i_NUM_USERS = 0;
static ArrPt(String) *i_FONT_FAMILIES;
static ArrSt(IColor) *i_INDEXED_COLORS;

/*---------------------------------------------------------------------------*/

static void i_draw2d_atexit(void)
{
    if (i_NUM_USERS != 0)
        log_printf("Error! draw2d is not properly closed (%d)\n", i_NUM_USERS);
}

/*---------------------------------------------------------------------------*/

void draw2d_start(void)
{
    if (i_NUM_USERS == 0)
    {
        core_start();
        osimage_alloc_globals();
        osfont_alloc_globals();
        draw_alloc_globals();
        blib_atexit(i_draw2d_atexit);

        i_FONT_FAMILIES = arrpt_create(String);

        {
            String *str = str_c("__SYSTEM__");
            arrpt_append(i_FONT_FAMILIES, str, String);
        }

        {
            String *str = str_c("__MONOSPACE__");
            arrpt_append(i_FONT_FAMILIES, str, String);
        }

        i_INDEXED_COLORS = arrst_create(IColor);
        dbind_opaque(Image, image_from_data, NULL, image_copy, NULL, image_write, image_destroy);
    }

    i_NUM_USERS += 1;
}

/*---------------------------------------------------------------------------*/

void draw2d_finish(void)
{
    cassert(i_NUM_USERS > 0);
    if (i_NUM_USERS == 1)
    {
        /* Destroy all image in dbind, before release OS image support */
        dbind_opaque_destroy("Image");
        arrpt_destroy(&i_FONT_FAMILIES, str_destroy, String);
        arrst_destroy(&i_INDEXED_COLORS, NULL, IColor);
        osfont_dealloc_globals();
        osimage_dealloc_globals();
        draw_dealloc_globals();
        core_finish();
    }

    i_NUM_USERS -= 1;
}

/*---------------------------------------------------------------------------*/

uint32_t draw2d_register_font(const char_t *font_family)
{
    arrpt_foreach(family, i_FONT_FAMILIES, String)
        if (str_cmp(family, font_family) == 0)
            return family_i;
    arrpt_end()

    if (font_exists_family(font_family) == TRUE)
    {
        uint32_t num_elems = arrpt_size(i_FONT_FAMILIES, String);
        String *family = str_c(font_family);
        arrpt_append(i_FONT_FAMILIES, family, String);
        return num_elems;
    }
    else
    {
        return (uint32_t)ekFONT_FAMILY_SYSTEM;
    }
}

/*---------------------------------------------------------------------------*/

const char_t *draw2d_font_family(const uint32_t family)
{
    const String *font_family = arrpt_get(i_FONT_FAMILIES, family, String);
    return tc(font_family);
}

/*---------------------------------------------------------------------------*/

color_t color_indexed(const uint16_t index, const color_t color)
{
    if (index == 0)
        return kCOLOR_DEFAULT;

    cassert((uint8_t)(color >> 24) != 0);

    arrst_foreach(ic, i_INDEXED_COLORS, IColor)
        if (index == ic->index)
        {
            ic->color = color;
            return color;
        }
    arrst_end()

    {
        IColor *nc = arrst_new(i_INDEXED_COLORS, IColor);
        nc->index = index;
        nc->color = color;
        return color;
    }
}

/*---------------------------------------------------------------------------*/

color_t draw2d_get_indexed_color(const uint16_t index)
{
    if (index == 0)
        return kCOLOR_DEFAULT;

    arrst_foreach(ic, i_INDEXED_COLORS, IColor)
        if (ic->index == index)
            return ic->color;
    arrst_end()

    cassert(FALSE);
    return kCOLOR_DEFAULT;
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

static const char_t *i_next_word(const char_t *str, int *word_type)
{
    cassert_no_null(str);
    cassert_no_null(word_type);
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

static void i_new_line(void *data, FPtr_word_extents func_word_extents, real32_t *current_width, real32_t *current_height, real32_t *current_width_without_spaces, uint32_t *num_lines, real32_t *width, real32_t *height)
{
    cassert_no_null(current_width);
    cassert_no_null(current_height);
    cassert_no_null(current_width_without_spaces);
    cassert_no_null(num_lines);
    cassert_no_null(width);
    cassert_no_null(height);

    if (*current_width_without_spaces == 0)
    {
        real32_t word_width = 0, word_height = 0;
        func_word_extents(data, "A", &word_width, &word_height);
        *current_width_without_spaces = word_width;
        *current_height = word_height;
    }
    else
    {
        cassert(*current_height > 0);
    }

    if (*current_width_without_spaces > *width)
        *width = *current_width_without_spaces;
    *height += *current_height;

    *current_width = 0;
    *current_width_without_spaces = 0;
    *current_height = 0;
    *num_lines += 1;
}

/*---------------------------------------------------------------------------*/

void draw2d_extents_imp(void *data, FPtr_word_extents func_word_extents, const bool_t newlines, const char_t *str, const real32_t refwidth, real32_t *width, real32_t *height)
{
    uint32_t num_lines = 0;
    real32_t ref_width = refwidth > 0 ? refwidth : 1e8f;
    real32_t current_width = 0, current_height = 0, current_width_without_spaces = 0;
    register const char_t *ctext = str;

    cassert_no_nullf(func_word_extents);
    cassert_no_null(width);
    cassert_no_null(height);
    *width = 0;
    *height = 0;

    while (ctext != NULL)
    {
        const char_t *next_text = NULL;
        int word_type = 0;

        next_text = i_next_word(ctext, &word_type);

        switch (word_type)
        {

        case i_WORD_TYPE_END:
            if (current_width > .01f || num_lines == 0)
                i_new_line(data, func_word_extents, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
            break;

        case i_WORD_TYPE_NEW_LINE:
            if (newlines == TRUE)
                i_new_line(data, func_word_extents, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
            break;

        case i_WORD_TYPE_BLANCKS:
            if (current_width_without_spaces > 0)
            {
                char_t word[256];
                real32_t word_width = 0, word_height = 0;
                register uint32_t size = (uint32_t)(next_text - ctext);
                cassert(next_text > ctext);
                str_copy_cn(word, sizeof(word), ctext, size);
                word[size] = '\0';
                func_word_extents(data, word, &word_width, &word_height);
                if (current_width + word_width <= ref_width)
                {
                    current_width += word_width;
                    if (word_height > current_height)
                        current_height = word_height;
                }
                else
                {
                    i_new_line(data, func_word_extents, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
                }
            }
            break;

        case i_WORD_TYPE_TEXT:
        {
            char_t word[256];
            real32_t word_width = 0.f, word_height = 0.f;
            register uint32_t size = (uint32_t)(next_text - ctext);
            cassert(next_text > ctext);
            cassert(word_type == i_WORD_TYPE_TEXT);
            str_copy_cn(word, sizeof(word), ctext, size);
            word[size] = '\0';
            func_word_extents(data, word, &word_width, &word_height);

            if (current_width + word_width <= ref_width)
            {
                current_width += word_width;
                if (word_height > current_height)
                    current_height = word_height;
            }
            else
            {
                i_new_line(data, func_word_extents, &current_width, &current_height, &current_width_without_spaces, &num_lines, width, height);
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

    *width = bmath_ceilf(*width);
    *height = bmath_ceilf(*height);
}

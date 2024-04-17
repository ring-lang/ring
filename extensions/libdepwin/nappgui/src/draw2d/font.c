/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: font.c
 *
 */

/* Fonts */

#include "font.h"
#include "font.inl"
#include "draw2d.inl"
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _font_t
{
    uint32_t num_instances;
    uint32_t family;
    uint32_t style;
    real32_t size;
    real32_t cell_size;
    real32_t internal_leading;
    String *family_name;
    OSFont *osfont;
};

/*---------------------------------------------------------------------------*/

#define i_abs(x) (((x) < 0.f) ? -(x) : (x))

/*---------------------------------------------------------------------------*/

static Font *i_create_font(const uint32_t family, const real32_t size, const uint32_t style)
{
    Font *font = heap_new(Font);
    font->num_instances = 1;
    font->family = family;
    font->size = size;
    font->style = style;
    font->cell_size = -1;
    font->internal_leading = -1;
    font->family_name = NULL;
    font->osfont = NULL;
    return font;
}

/*---------------------------------------------------------------------------*/

void font_destroy(Font **font)
{
    cassert_no_null(font);
    cassert_no_null(*font);
    if ((*font)->num_instances == 1)
    {
        if ((*font)->osfont != NULL)
            osfont_destroy(&(*font)->osfont);
        str_destopt(&(*font)->family_name);
        heap_delete(font, Font);
    }
    else
    {
        cassert((*font)->num_instances > 0);
        (*font)->num_instances -= 1;
    }
}

/*---------------------------------------------------------------------------*/

Font *font_create(const char_t *family, const real32_t size, const uint32_t style)
{
    uint32_t ffamily = draw2d_register_font(family);
    return i_create_font(ffamily, size, style);
}

/*---------------------------------------------------------------------------*/

Font *font_system(const real32_t size, const uint32_t style)
{
    return i_create_font((uint32_t)ekFONT_FAMILY_SYSTEM, size, style);
}

/*---------------------------------------------------------------------------*/

Font *font_monospace(const real32_t size, const uint32_t style)
{
    return i_create_font((uint32_t)ekFONT_FAMILY_MONOSPACE, size, style);
}

/*---------------------------------------------------------------------------*/

Font *font_with_style(const Font *font, const uint32_t style)
{
    cassert_no_null(font);
    return i_create_font(font->family, font->size, style);
}

/*---------------------------------------------------------------------------*/

Font *font_copy(const Font *font)
{
    cassert_no_null(font);
    ((Font *)font)->num_instances += 1;
    return (Font *)font;
}

/*---------------------------------------------------------------------------*/

bool_t font_equals(const Font *font1, const Font *font2)
{
    cassert_no_null(font1);
    cassert_no_null(font2);
    if (font1->family != font2->family)
        return FALSE;
    if (i_abs(font1->size - font2->size) > 0.0001f)
        return FALSE;
    if (font1->style != font2->style)
        return FALSE;
    return TRUE;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_osfont(Font *font)
{
    cassert_no_null(font);
    if (font->osfont == NULL)
    {
        const char_t *fname = draw2d_font_family(font->family);
        font->osfont = osfont_create(fname, font->size, font->style);
    }
}

/*---------------------------------------------------------------------------*/

const char_t *font_family(const Font *font)
{
    cassert_no_null(font);
    if (font->family_name == NULL)
    {
        i_osfont((Font *)font);
        ((Font *)font)->family_name = osfont_family_name(font->osfont);
    }

    return tc(font->family_name);
}

/*---------------------------------------------------------------------------*/

real32_t font_size(const Font *font)
{
    cassert_no_null(font);
    return font->size;
}

/*---------------------------------------------------------------------------*/

/* Review this function -- Can create a GDI font in a GDI+ context!!! */
real32_t font_height(const Font *font)
{
    cassert_no_null(font);
    if (font->cell_size < 0)
    {
        i_osfont((Font *)font);
        osfont_metrics(font->osfont, &((Font *)font)->internal_leading, &((Font *)font)->cell_size);
    }
    return font->cell_size;
}

/*---------------------------------------------------------------------------*/

real32_t font_leading(const Font *font)
{
    cassert_no_null(font);
    if (font->internal_leading < 0)
    {
        i_osfont((Font *)font);
        osfont_metrics(font->osfont, &((Font *)font)->internal_leading, &((Font *)font)->cell_size);
    }
    return font->internal_leading;
}

/*---------------------------------------------------------------------------*/

uint32_t font_style(const Font *font)
{
    cassert_no_null(font);
    return font->style;
}

/*---------------------------------------------------------------------------*/

void font_extents(const Font *font, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    cassert_no_null(font);
    i_osfont((Font *)font);
    osfont_extents(font->osfont, text, refwidth, width, height);
}

/*---------------------------------------------------------------------------*/

const void *font_native(const Font *font)
{
    cassert_no_null(font);
    i_osfont((Font *)font);
    return font->osfont;
}

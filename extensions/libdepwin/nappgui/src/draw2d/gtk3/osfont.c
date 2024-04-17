/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osfont.c
 *
 */

/* Fonts */

#include "font.h"
#include "font.inl"
#include "dctxh.h"
#include <core/arrpt.h>
#include <core/heap.h>
#include <core/strings.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

#if !defined(__GTK3__)
#error This file is only for GTK Toolkit
#endif

#include <sewer/nowarn.hxx>
#include <pango/pangocairo.h>
#include <sewer/warn.hxx>

/* System font should be set from GTK or other toolkit manager */
static String *kSYSTEM_FONT = NULL;
static real32_t kFONT_REGULAR_SIZE = 0.f;
static real32_t kFONT_SMALL_SIZE = 0.f;
static real32_t kFONT_MINI_SIZE = 0.f;
static real32_t i_PANGO_TO_PIXELS = -1;
static cairo_t *i_CAIRO = NULL;
static PangoLayout *i_LAYOUT = NULL;

/*---------------------------------------------------------------------------*/

void osfont_alloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

void osfont_dealloc_globals(void)
{
    str_destopt(&kSYSTEM_FONT);

    if (i_CAIRO != NULL)
    {
        g_object_unref(i_LAYOUT);
        cairo_destroy(i_CAIRO);
        i_LAYOUT = NULL;
        i_CAIRO = NULL;
    }
}

/*---------------------------------------------------------------------------*/

static real32_t i_device_to_pixels(void)
{
    if (i_PANGO_TO_PIXELS < 0)
    {
        /* This object is owned by Pango and must not be freed */
        PangoFontMap *fontmap = pango_cairo_font_map_get_default();
        real32_t dpi = (real32_t)pango_cairo_font_map_get_resolution((PangoCairoFontMap *)fontmap);
        i_PANGO_TO_PIXELS = (dpi / 72.f) / PANGO_SCALE;
    }

    return i_PANGO_TO_PIXELS;
}

/*---------------------------------------------------------------------------*/

real32_t font_regular_size(void)
{
    cassert(kSYSTEM_FONT != NULL);
    return kFONT_REGULAR_SIZE;
}

/*---------------------------------------------------------------------------*/

real32_t font_small_size(void)
{
    cassert(kSYSTEM_FONT != NULL);
    return kFONT_SMALL_SIZE;
}

/*---------------------------------------------------------------------------*/

real32_t font_mini_size(void)
{
    cassert(kSYSTEM_FONT != NULL);
    return kFONT_MINI_SIZE;
}

/*---------------------------------------------------------------------------*/

static gint i_font_height(const real32_t size, const uint32_t style)
{
    if ((style & ekFPOINTS) == ekFPOINTS)
    {
        return (gint)(size * (real32_t)PANGO_SCALE);
    }
    else
    {
        cassert((style & ekFPIXELS) == ekFPIXELS);
        return (gint)(size / i_device_to_pixels());
    }
}

/*---------------------------------------------------------------------------*/

OSFont *osfont_create(const char_t *family, const real32_t size, const uint32_t style)
{
    register const char_t *name;
    register gint psize;
    PangoFontDescription *font;

    if (str_equ_c(family, "__SYSTEM__") == TRUE)
    {
        cassert(kSYSTEM_FONT != NULL);
        name = tc(kSYSTEM_FONT);
    }
    else if (str_equ_c(family, "__MONOSPACE__") == TRUE)
    {
        name = "Ubuntu Mono";
    }
    else
    {
        name = family;
    }

    psize = i_font_height(size, style);
    font = pango_font_description_new();
    pango_font_description_set_family(font, name);
    pango_font_description_set_size(font, psize);
    pango_font_description_set_style(font, (style & ekFITALIC) == ekFITALIC ? PANGO_STYLE_ITALIC : PANGO_STYLE_NORMAL);
    pango_font_description_set_weight(font, (style & ekFBOLD) == ekFBOLD ? PANGO_WEIGHT_BOLD : PANGO_WEIGHT_NORMAL);
    heap_auditor_add("PangoFontDescription");
    return (OSFont *)font;
}

/*---------------------------------------------------------------------------*/

void osfont_destroy(OSFont **font)
{
    cassert_no_null(font);
    cassert_no_null(*font);
    pango_font_description_free(*((PangoFontDescription **)font));
    heap_auditor_delete("PangoFontDescription");
    *font = NULL;
}

/*---------------------------------------------------------------------------*/

void osfont_extents(const OSFont *font, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    int w, h;
    cassert_no_null(font);
    if (i_CAIRO == NULL)
    {
        i_CAIRO = cairo_create(NULL);
        i_LAYOUT = pango_cairo_create_layout(i_CAIRO);
    }

    pango_layout_set_font_description(i_LAYOUT, (PangoFontDescription *)font);
    pango_layout_set_text(i_LAYOUT, (const char *)text, -1);
    pango_layout_set_width(i_LAYOUT, refwidth < 0 ? -1 : (int)(refwidth * PANGO_SCALE));
    pango_layout_get_pixel_size(i_LAYOUT, &w, &h);
    ptr_assign(width, (real32_t)w);
    ptr_assign(height, (real32_t)h);
}

/*---------------------------------------------------------------------------*/

const void *osfont_native(const OSFont *font)
{
    cassert_no_null(font);
    return (void *)font;
}

/*---------------------------------------------------------------------------*/

String *osfont_family_name(const OSFont *font)
{
    const PangoFontDescription *ffont = NULL;
    const char *desc = NULL;
    cassert_no_null(font);
    ffont = (PangoFontDescription *)font;
    desc = pango_font_description_get_family(ffont);
    return str_c(desc);
}

/*---------------------------------------------------------------------------*/

void osfont_metrics(const OSFont *font, real32_t *internal_leading, real32_t *cell_size)
{
    PangoFontMap *fontmap;
    PangoContext *context;
    PangoFont *ffont;
    PangoFontMetrics *metrics;
    real32_t height;
    cassert_no_null(font);
    cassert_no_null(internal_leading);
    cassert_no_null(cell_size);
    /* This object is owned by Pango and must not be freed */
    fontmap = pango_cairo_font_map_get_default();
    context = pango_font_map_create_context(fontmap);
    ffont = pango_font_map_load_font(fontmap, context, (PangoFontDescription *)font);
    metrics = pango_font_get_metrics(ffont, NULL);
    *internal_leading = 10;
    height = (real32_t)pango_font_metrics_get_ascent(metrics);
    height += (real32_t)pango_font_metrics_get_descent(metrics);
    /* height = (real32_t)pango_font_metrics_get_height(metrics); */
    height /= PANGO_SCALE;
    g_object_unref(context);
    g_object_unref(ffont);
    pango_font_metrics_unref(metrics);
    *cell_size = height;
}

/*---------------------------------------------------------------------------*/

const char_t *font_register(const byte_t *data, const uint32_t size)
{
    unref(data);
    unref(size);
    cassert(FALSE);
    return NULL;
}

/*---------------------------------------------------------------------------*/

bool_t font_exists_family(const char_t *font_family)
{
    PangoFontMap *fontmap;
    PangoFontFamily **families;
    int i, n;

    /* This object is owned by Pango and must not be freed. */
    fontmap = pango_cairo_font_map_get_default();
    /* This array should be freed with g_free(). */
    pango_font_map_list_families(fontmap, &families, &n);
    for (i = 0; i < n; i++)
    {
        const char_t *name = (const char_t *)pango_font_family_get_name(families[i]);
        if (str_equ_nocase(font_family, name) == TRUE)
            break;
    }
    g_free(families);
    return (bool_t)(i < n);
}

/*---------------------------------------------------------------------------*/

ArrPt(String) *font_installed_families(void)
{
    ArrPt(String) *fonts;
    PangoFontMap *fontmap;
    PangoFontFamily **families;
    int i, n;

    fonts = arrpt_create(String);
    /* This object is owned by Pango and must not be freed. */
    fontmap = pango_cairo_font_map_get_default();
    /* This array should be freed with g_free(). */
    pango_font_map_list_families(fontmap, &families, &n);
    for (i = 0; i < n; i++)
    {
        const char_t *name = (const char_t *)pango_font_family_get_name(families[i]);
        String *font = str_c(name);
        arrpt_append(fonts, font, String);
    }
    g_free(families);
    return fonts;
}

/*---------------------------------------------------------------------------*/

void dctx_set_default_osfont(DCtx *ctx, const void *font)
{
    const PangoFontDescription *fdesc = (const PangoFontDescription *)font;
    real32_t scale = i_device_to_pixels();
    const char *family = NULL;
    real32_t size = 0;
    unref(ctx);
    cassert(kSYSTEM_FONT == NULL);
    family = pango_font_description_get_family(fdesc);
    size = (real32_t)pango_font_description_get_size(fdesc);
    kSYSTEM_FONT = str_c((const char_t *)family);
    kFONT_REGULAR_SIZE = size * scale;
    kFONT_SMALL_SIZE = kFONT_REGULAR_SIZE - 2.f;
    kFONT_MINI_SIZE = kFONT_REGULAR_SIZE - 4.f;
}

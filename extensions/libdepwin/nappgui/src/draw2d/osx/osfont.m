/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osfont.m
 *
 */

/* Font native implementation */

#include <sewer/nowarn.hxx>
#include <Cocoa/Cocoa.h>
#include <sewer/warn.hxx>
#include "draw2d_osx.ixx"

#include "font.h"
#include "font.inl"
#include "draw2d.inl"
#include "draw.inl"
#include <core/arrpt.h>
#include <core/strings.h>
#include <sewer/cassert.h>

#if !defined(__MACOS__)
#error This file is only for OSX
#endif

/*---------------------------------------------------------------------------*/

#define i_abs(x) (((x) < 0.f) ? -(x) : (x))

/*---------------------------------------------------------------------------*/

void osfont_alloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

void osfont_dealloc_globals(void)
{
}

/*---------------------------------------------------------------------------*/

real32_t font_regular_size(void)
{
    return (real32_t)[NSFont systemFontSize];
}

/*---------------------------------------------------------------------------*/

real32_t font_small_size(void)
{
    return (real32_t)[NSFont smallSystemFontSize];
}

/*---------------------------------------------------------------------------*/

real32_t font_mini_size(void)
{
    return (real32_t)[NSFont smallSystemFontSize] - 2.f;
}

/*---------------------------------------------------------------------------*/

static NSFont *i_convent_to_italic(NSFont *font, const CGFloat height, NSFontManager *font_manager)
{
    NSFont *italic_font = nil;
    NSFontTraitMask fontTraits = (NSFontTraitMask)0;
    cassert_no_null(font);

    italic_font = [font_manager convertFont:font toHaveTrait:NSItalicFontMask];
    fontTraits = [font_manager traitsOfFont:italic_font];

    if ((fontTraits & NSItalicFontMask) == 0)
    {
        NSAffineTransform *font_transform = [NSAffineTransform transform];
        [font_transform scaleBy:height];

        {
            NSAffineTransformStruct data;
            NSAffineTransform *italic_transform = nil;
            data.m11 = 1.f;
            data.m12 = 0.f;
            data.m21 = -tanf(/*italic_angle*/ -10.f * 0.017453292519943f);
            data.m22 = 1.f;
            data.tX = 0.f;
            data.tY = 0.f;
            italic_transform = [NSAffineTransform transform];
            [italic_transform setTransformStruct:data];
            [font_transform appendTransform:italic_transform];
        }

        italic_font = [NSFont fontWithDescriptor:[italic_font fontDescriptor] textTransform:font_transform];
    }

    return italic_font;
}

/*---------------------------------------------------------------------------*/

OSFont *osfont_create(const char_t *family, const real32_t size, const uint32_t style)
{
    const char_t *name = NULL;
    NSFont *nsfont = nil;
    cassert(size > 0.f);

    if (str_equ_c(family, "__SYSTEM__") == TRUE)
    {
        if (style & ekFBOLD)
            nsfont = [NSFont boldSystemFontOfSize:(CGFloat)size];
        else
            nsfont = [NSFont systemFontOfSize:(CGFloat)size];
    }
    else if (str_equ_c(family, "__MONOSPACE__") == TRUE)
    {
#if defined(MAC_OS_X_VERSION_10_15) && MAC_OS_X_VERSION_MIN_REQUIRED >= MAC_OS_X_VERSION_10_15
        if (style & ekFBOLD)
            nsfont = [NSFont monospacedSystemFontOfSize:(CGFloat)size weight:NSFontWeightBold];
        else
            nsfont = [NSFont monospacedSystemFontOfSize:(CGFloat)size weight:NSFontWeightLight];
#else
        name = "Courier New";
#endif
    }
    else
    {
        name = family;
    }

    if (nsfont == nil)
    {
        NSFontManager *fontManager = [NSFontManager sharedFontManager];
        NSString *ffamily = [NSString stringWithUTF8String:name];
        NSUInteger mask = (style & ekFBOLD) ? NSBoldFontMask : 0;
        nsfont = [fontManager fontWithFamily:ffamily traits:(NSFontTraitMask)mask weight:5 size:(CGFloat)size];
        cassert_fatal_msg(nsfont != nil, "Font is not available on this computer.");
    }

    if (nsfont != nil)
    {
        if (style & ekFITALIC)
        {
            NSFontManager *fontManager = [NSFontManager sharedFontManager];
            nsfont = i_convent_to_italic(nsfont, (CGFloat)size, fontManager);
        }

        [nsfont retain];
    }

    return (OSFont *)nsfont;
}

/*---------------------------------------------------------------------------*/

void osfont_destroy(OSFont **font)
{
    cassert_no_null(font);
    cassert_no_null(*font);
    [(NSFont *)*font release];
}

/*---------------------------------------------------------------------------*/

String *osfont_family_name(const OSFont *font)
{
    NSFont *nsfont = (NSFont *)font;
    NSString *fname = nil;
    const char_t *utf8name = NULL;
    cassert_no_null(nsfont);
    fname = [nsfont familyName];
    utf8name = (const char_t *)[fname UTF8String];
    return str_c(utf8name);
}

/*---------------------------------------------------------------------------*/

void osfont_metrics(const OSFont *font, real32_t *internal_leading, real32_t *cell_size)
{
    NSFont *nsfont = (NSFont *)font;
    /*NSRect rect = [nsfont boundingRectForFont];*/
    CGFloat ascender = [nsfont ascender];
    CGFloat descender = -[nsfont descender];
    CGFloat leading = [nsfont leading];
    cassert_no_null(internal_leading);
    cassert_no_null(cell_size);
    *internal_leading = (real32_t)leading;
    *cell_size = (real32_t)(ascender + descender);
}

/*---------------------------------------------------------------------------*/

void osfont_extents(const OSFont *font, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height)
{
    MeasureStr data;
    id objects[1];
    id keys[1];
    NSUInteger count = sizeof(objects) / sizeof(id);
    objects[0] = (NSFont *)font;
    keys[0] = NSFontAttributeName;
    cassert(count == 1);
    data.dict = [NSDictionary dictionaryWithObjects:objects forKeys:keys count:count];
    draw2d_extents(&data, draw_word_extents, TRUE, text, refwidth, width, height, MeasureStr);
}

/*---------------------------------------------------------------------------*/

const void *osfont_native(const OSFont *font)
{
    return (void *)font;
}

/*---------------------------------------------------------------------------*/

bool_t font_exists_family(const char_t *ffamily)
{
    NSFontManager *fontManager = nil;
    NSArray *families = nil;
    NSUInteger i, count;
    fontManager = [NSFontManager sharedFontManager];
    cassert_no_null(fontManager);
    families = [fontManager availableFontFamilies];
    count = [families count];
    for (i = 0; i < count; ++i)
    {
        NSString *family = (NSString *)[families objectAtIndex:i];
        const char_t *family_str = [family UTF8String];
        if (str_equ_c(ffamily, family_str) == TRUE)
            return TRUE;
    }

    return FALSE;
}

/*---------------------------------------------------------------------------*/

ArrPt(String) *font_installed_families(void)
{
    NSFontManager *fontManager = nil;
    NSArray *families = nil;
    NSUInteger i, count;
    ArrPt(String) *font_families = NULL;
    fontManager = [NSFontManager sharedFontManager];
    cassert_no_null(fontManager);
    families = [fontManager availableFontFamilies];
    count = [families count];
    font_families = arrpt_create(String);
    for (i = 0; i < count; ++i)
    {
        NSString *family = (NSString *)[families objectAtIndex:i];
        const char_t *family_str = [family UTF8String];
        String *ffamily = str_c(family_str);
        arrpt_append(font_families, ffamily, String);
    }

    return font_families;
}

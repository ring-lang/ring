/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw2d.ixx
 *
 */

/* Operating system 2D drawing support */

#ifndef __OSDRAW_IXX__
#define __OSDRAW_IXX__

#include "draw2d.hxx"

typedef struct _measurestr_t MeasureStr;

enum font_family_t
{
    ekFONT_FAMILY_SYSTEM = 0,
    ekFONT_FAMILY_MONOSPACE = 1
};

typedef struct _osfont_t OSFont;
typedef struct _osimage_t OSImage;

typedef void (*FPtr_word_extents)(void *data, const char_t *word, real32_t *width, real32_t *height);
#define FUNC_CHECK_WORD_EXTENTS(func, type) \
    (void)((void (*)(type *, const char_t *, real32_t *, real32_t *))func == func)

#endif

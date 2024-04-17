/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: font.inl
 *
 */

/* Fonts */

#include "draw2d.ixx"

__EXTERN_C

void osfont_alloc_globals(void);

void osfont_dealloc_globals(void);

OSFont *osfont_create(const char_t *family, const real32_t size, const uint32_t style);

void osfont_destroy(OSFont **font);

String *osfont_family_name(const OSFont *font);

void osfont_metrics(const OSFont *font, real32_t *internal_leading, real32_t *cell_size);

void osfont_extents(const OSFont *font, const char_t *text, const real32_t refwidth, real32_t *width, real32_t *height);

const void *osfont_native(const OSFont *font);

__END_C

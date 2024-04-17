/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: sewer.h
 * https://nappgui.com/en/sewer/sewer.html
 *
 */

/* Sewer library */

#include "sewer.hxx"

__EXTERN_C

_sewer_api void sewer_start(void);

_sewer_api void sewer_finish(void);

_sewer_api uint32_t sewer_nappgui_major(void);

_sewer_api uint32_t sewer_nappgui_minor(void);

_sewer_api uint32_t sewer_nappgui_patch(void);

_sewer_api uint32_t sewer_nappgui_build(void);

_sewer_api const char_t *sewer_nappgui_version(const bool_t full);

__END_C

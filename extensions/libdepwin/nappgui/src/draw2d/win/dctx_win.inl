/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: dctx_win.inl
 *
 */

/* Draw context */

#include "draw2d_win.ixx"

__EXTERN_C

//Gdiplus::ColorPalette* _dctx_4bpp_grayscale_palette(void);

Gdiplus::ColorPalette *_dctx_8bpp_grayscale_palette(void);

void _dctx_gradient_transform(DCtx *ctx);

__END_C

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osdrawctrl.h
 *
 */

/* Operating System Custom Control Drawing */

#include "osgui.hxx"

__EXTERN_C

_osgui_api Font *osdrawctrl_font(const DCtx *ctx);

_osgui_api uint32_t osdrawctrl_row_padding(const DCtx *ctx);

_osgui_api uint32_t osdrawctrl_check_width(const DCtx *ctx);

_osgui_api uint32_t osdrawctrl_check_height(const DCtx *ctx);

_osgui_api ctrl_msel_t osdrawctrl_multisel(const DCtx *ctx, const vkey_t key);

_osgui_api void osdrawctrl_clear(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const enum_t nonused);

_osgui_api void osdrawctrl_header(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

_osgui_api void osdrawctrl_indicator(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const indicator_t indicator);

_osgui_api void osdrawctrl_fill(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

_osgui_api void osdrawctrl_focus(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

_osgui_api void osdrawctrl_line(DCtx *ctx, const int32_t x0, const int32_t y0, const int32_t x1, const int32_t y1);

_osgui_api void osdrawctrl_text(DCtx *ctx, const char_t *text, const int32_t x, const int32_t y, const ctrl_state_t state);

_osgui_api void osdrawctrl_image(DCtx *ctx, const Image *image, const int32_t x, const int32_t y, const ctrl_state_t state);

_osgui_api void osdrawctrl_checkbox(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

_osgui_api void osdrawctrl_uncheckbox(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

__END_C

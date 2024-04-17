/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: drawctrl.inl
 *
 */

/* Drawing custom GUI controls */

#include "gui.hxx"

__EXTERN_C

Font *drawctrl_font(DCtx *ctx);

uint32_t drawctrl_row_padding(DCtx *ctx);

uint32_t drawctrl_check_width(DCtx *ctx);

uint32_t drawctrl_check_height(DCtx *ctx);

ctrl_msel_t drawctrl_multisel(DCtx *ctx, const vkey_t key);

void drawctrl_clear(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height);

void drawctrl_header(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

void drawctrl_indicator(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const uint32_t indicator);

void drawctrl_fill(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

void drawctrl_line(DCtx *ctx, const int32_t x0, const int32_t y0, const int32_t x1, const int32_t y1);

void drawctrl_focus(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state);

void drawctrl_text(DCtx *ctx, const char_t *text, const int32_t x, const int32_t y, const ctrl_state_t state);

void drawctrl_image(DCtx *ctx, const Image *image, const int32_t x, const int32_t y);

void drawctrl_checkbox(DCtx *ctx, const int32_t x, const int32_t y, const ctrl_state_t state);

void drawctrl_uncheckbox(DCtx *ctx, const int32_t x, const int32_t y, const ctrl_state_t state);

__END_C

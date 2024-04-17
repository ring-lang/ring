/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: drawctrl.c
 *
 */

/* Drawing custom GUI controls */

#include "drawctrl.inl"
#include <draw2d/guictx.h>

static uint32_t kCHECK_WIDTH = 0;
static uint32_t kCHECK_HEIGHT = 0;

/*---------------------------------------------------------------------------*/

Font *drawctrl_font(DCtx *ctx)
{
    const GuiCtx *context = guictx_get_current();
    return (Font *)context->func_drawctrl_font(ctx);
}

/*---------------------------------------------------------------------------*/

uint32_t drawctrl_row_padding(DCtx *ctx)
{
    const GuiCtx *context = guictx_get_current();
    return context->func_drawctrl_row_padding(ctx);
}

/*---------------------------------------------------------------------------*/

uint32_t drawctrl_check_width(DCtx *ctx)
{
    if (kCHECK_WIDTH == 0)
    {
        const GuiCtx *context = guictx_get_current();
        kCHECK_WIDTH = context->func_drawctrl_check_width(ctx);
    }

    return kCHECK_WIDTH;
}

/*---------------------------------------------------------------------------*/

uint32_t drawctrl_check_height(DCtx *ctx)
{
    if (kCHECK_HEIGHT == 0)
    {
        const GuiCtx *context = guictx_get_current();
        kCHECK_HEIGHT = context->func_drawctrl_check_height(ctx);
    }

    return kCHECK_HEIGHT;
}

/*---------------------------------------------------------------------------*/

ctrl_msel_t drawctrl_multisel(DCtx *ctx, const vkey_t key)
{
    const GuiCtx *context = guictx_get_current();
    return (ctrl_msel_t)context->func_drawctrl_multisel(ctx, (enum_t)key);
}

/*---------------------------------------------------------------------------*/

void drawctrl_clear(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_clear(ctx, x, y, width, height, (enum_t)0);
}

/*---------------------------------------------------------------------------*/

void drawctrl_header(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_header(ctx, x, y, width, height, (enum_t)state);
}

/*---------------------------------------------------------------------------*/

void drawctrl_indicator(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const uint32_t indicator)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_indicator(ctx, x, y, width, height, (enum_t)indicator);
}

/*---------------------------------------------------------------------------*/

void drawctrl_fill(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_fill(ctx, x, y, width, height, (enum_t)state);
}

/*---------------------------------------------------------------------------*/

void drawctrl_line(DCtx *ctx, const int32_t x0, const int32_t y0, const int32_t x1, const int32_t y1)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_line(ctx, x0, y0, x1, y1);
}

/*---------------------------------------------------------------------------*/

void drawctrl_focus(DCtx *ctx, const int32_t x, const int32_t y, const uint32_t width, const uint32_t height, const ctrl_state_t state)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_focus(ctx, x, y, width, height, (enum_t)state);
}

/*---------------------------------------------------------------------------*/

void drawctrl_text(DCtx *ctx, const char_t *text, const int32_t x, const int32_t y, const ctrl_state_t state)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_text(ctx, text, x, y, (enum_t)state);
}

/*---------------------------------------------------------------------------*/

void drawctrl_image(DCtx *ctx, const Image *image, const int32_t x, const int32_t y)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_image(ctx, image, x, y, (enum_t)0);
}

/*---------------------------------------------------------------------------*/

void drawctrl_checkbox(DCtx *ctx, const int32_t x, const int32_t y, const ctrl_state_t state)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_checkbox(ctx, x, y, kCHECK_WIDTH, kCHECK_HEIGHT, (enum_t)state);
}

/*---------------------------------------------------------------------------*/

void drawctrl_uncheckbox(DCtx *ctx, const int32_t x, const int32_t y, const ctrl_state_t state)
{
    const GuiCtx *context = guictx_get_current();
    context->func_drawctrl_uncheckbox(ctx, x, y, kCHECK_WIDTH, kCHECK_HEIGHT, (enum_t)state);
}

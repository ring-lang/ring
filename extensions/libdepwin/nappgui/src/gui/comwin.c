/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: comwin.c
 *
 */

/* Common windows */

#include "comwin.h"
#include "window.inl"
#include <draw2d/guictx.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

const char_t *comwin_open_file(Window *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir)
{
    const GuiCtx *context = guictx_get_current();
    void *ositem = parent ? _window_ositem(parent) : NULL;
    cassert_no_null(context);
    return context->func_comwin_file(ositem, ftypes, size, start_dir, TRUE);
}

/*---------------------------------------------------------------------------*/

const char_t *comwin_save_file(Window *parent, const char_t **ftypes, const uint32_t size, const char_t *start_dir)
{
    const GuiCtx *context = guictx_get_current();
    void *ositem = parent ? _window_ositem(parent) : NULL;
    cassert_no_null(context);
    return context->func_comwin_file(ositem, ftypes, size, start_dir, FALSE);
}

/*---------------------------------------------------------------------------*/

void comwin_color(Window *parent, const char_t *title, const real32_t x, const real32_t y, const align_t halign, const align_t valign, const color_t current, color_t *colors, const uint32_t n, Listener *OnChange)
{
    const GuiCtx *context = guictx_get_current();
    void *ositem = parent ? _window_ositem(parent) : NULL;
    cassert_no_null(context);
    context->func_comwin_color(ositem, title, x, y, halign, valign, current, colors, n, OnChange);
}

/*
void commonwin_open_file_sheet(Window *parent_window, const uchar_t **allowed_file_types, const uint32_t num_file_types, Listener *OnAccept_listener);
void commonwin_open_file_sheet(Window *parent_window, const uchar_t **allowed_file_types, const uint32_t num_file_types, Listener *OnAccept_listener)
{
    const GuiCtx *guicontext;
    void *renderable_item;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_file);
    renderable_item = _window_renderable_item(parent_window);
    guicontext->func_common_file(renderable_item, allowed_file_types, num_file_types, TRUE, OnAccept_listener);
}*/

/*---------------------------------------------------------------------------*/

/*
void commonwin_save_file_sheet(Window *parent_window, const uchar_t **allowed_file_types, const uint32_t num_file_types, Listener *OnAccept_listener);
void commonwin_save_file_sheet(Window *parent_window, const uchar_t **allowed_file_types, const uint32_t num_file_types, Listener *OnAccept_listener)
{
    const GuiCtx *guicontext;
    void *renderable_item;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_file);
    renderable_item = _window_renderable_item(parent_window);
    guicontext->func_common_file(renderable_item, allowed_file_types, num_file_types, FALSE, OnAccept_listener);
}*/

/*---------------------------------------------------------------------------*/

/*
void commonwin_colour_close(void);
void commonwin_colour_close(void)
{
    const GuiCtx *guicontext;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_colour_close);
    guicontext->func_common_colour_close();
}*/

/*---------------------------------------------------------------------------*/

/*
void commonwin_colour_convert_to_hud(void);
void commonwin_colour_convert_to_hud(void)
{
    const GuiCtx *guicontext;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_colour_convert_to_hud);
    guicontext->func_common_colour_convert_to_hud();
}*/

/*---------------------------------------------------------------------------*/

/*
void commonwin_colour_set_size(const real32_t width, const real32_t height);
void commonwin_colour_set_size(const real32_t width, const real32_t height)
{
    const GuiCtx *guicontext;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_colour_set_size);
    guicontext->func_common_colour_set_size(width, height);
}
*/
/*---------------------------------------------------------------------------*/

/*
void commonwin_colour_get_size(real32_t *width, real32_t *height);
void commonwin_colour_get_size(real32_t *width, real32_t *height)
{
    const GuiCtx *guicontext;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_colour_get_size);
    guicontext->func_common_colour_get_size(width, height);
}
*/
/*---------------------------------------------------------------------------*/

/*
void commonwin_colour_set_origin(const real32_t x, const real32_t y);
void commonwin_colour_set_origin(const real32_t x, const real32_t y)
{
    const GuiCtx *guicontext;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_colour_set_origin);
    guicontext->func_common_colour_set_origin(x, y);
}*/

/*---------------------------------------------------------------------------*/

/*
void commonwin_colour_get_origin(real32_t *x, real32_t *y);
void commonwin_colour_get_origin(real32_t *x, real32_t *y)
{
    const GuiCtx *guicontext;
    guicontext = _gui_context_get_current();
    cassert_no_null(guicontext);
    cassert_no_nullf(guicontext->func_common_colour_get_origin);
    guicontext->func_common_colour_get_origin(x, y);
}*/

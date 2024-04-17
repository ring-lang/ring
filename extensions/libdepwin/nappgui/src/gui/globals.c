/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: globals.c
 *
 */

/* System globals */

#include "globals.h"
#include <draw2d/color.h>
#include <draw2d/guictx.h>
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

device_t globals_device(void)
{
    const GuiCtx *context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_globals_device);
    return (device_t)context->func_globals_device(NULL);
}

/*---------------------------------------------------------------------------*/

void globals_resolution(S2Df *resolution)
{
    const GuiCtx *context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_globals_resolution);
    cassert_no_null(resolution);
    context->func_globals_resolution(NULL, &resolution->width, &resolution->height);
}

/*---------------------------------------------------------------------------*/

V2Df globals_mouse_position(void)
{
    V2Df pos;
    const GuiCtx *context = guictx_get_current();
    cassert_no_null(context);
    cassert_no_nullf(context->func_globals_mouse_position);
    context->func_globals_mouse_position(NULL, &pos.x, &pos.y);
    return pos;
}

/*---------------------------------------------------------------------------*/

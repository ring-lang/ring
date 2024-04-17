/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osview.c
 *
 */

/* Operating System native custom view */

#include "osview.h"
#include "osview.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void osview_detach_and_destroy(OSView **view, OSPanel *panel)
{
    cassert_no_null(view);
    osview_detach(*view, panel);
    osview_destroy(view);
}

/*---------------------------------------------------------------------------*/

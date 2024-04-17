/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospanel.c
 *
 */

/* Operating System native panel */

#include "ospanel.h"
#include "ospanel.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void ospanel_detach_and_destroy(OSPanel **child, OSPanel *panel)
{
    cassert_no_null(child);
    ospanel_detach(*child, panel);
    ospanel_destroy(child);
}

/*---------------------------------------------------------------------------*/

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osupdown.c
 *
 */

/* Operating System native updown */

#include "osupdown.h"
#include "osupdown.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void osupdown_detach_and_destroy(OSUpDown **updown, OSPanel *panel)
{
    cassert_no_null(updown);
    osupdown_detach(*updown, panel);
    osupdown_destroy(updown);
}

/*---------------------------------------------------------------------------*/

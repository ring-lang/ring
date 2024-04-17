/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osprogress.c
 *
 */

/* Operating System native progress indicator */

#include "osprogress.h"
#include "osprogress.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void osprogress_detach_and_destroy(OSProgress **progress, OSPanel *panel)
{
    cassert_no_null(progress);
    osprogress_detach(*progress, panel);
    osprogress_destroy(progress);
}

/*---------------------------------------------------------------------------*/

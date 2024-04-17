/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: ospopup.c
 *
 */

/* Operating System native popup button */

#include "ospopup.h"
#include "ospopup.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void ospopup_detach_and_destroy(OSPopUp **popup, OSPanel *panel)
{
    cassert_no_null(popup);
    ospopup_detach(*popup, panel);
    ospopup_destroy(popup);
}

/*---------------------------------------------------------------------------*/

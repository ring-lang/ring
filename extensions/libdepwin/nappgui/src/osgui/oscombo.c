/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oscombo.c
 *
 */

/* Operating System native combo box */

#include "oscombo.h"
#include "oscombo.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void oscombo_detach_and_destroy(OSCombo **combo, OSPanel *panel)
{
    cassert_no_null(combo);
    oscombo_detach(*combo, panel);
    oscombo_destroy(combo);
}

/*---------------------------------------------------------------------------*/

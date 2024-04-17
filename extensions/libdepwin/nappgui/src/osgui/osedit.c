/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osedit.c
 *
 */

/* Operating System edit box */

#include "osedit.h"
#include "osedit.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void osedit_detach_and_destroy(OSEdit **edit, OSPanel *panel)
{
    cassert_no_null(edit);
    osedit_detach(*edit, panel);
    osedit_destroy(edit);
}

/*---------------------------------------------------------------------------*/

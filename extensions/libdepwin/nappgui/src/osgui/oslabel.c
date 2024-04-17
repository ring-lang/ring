/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: oslabel.c
 *
 */

/* Operating System label */

#include "oslabel.h"
#include "oslabel.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void oslabel_detach_and_destroy(OSLabel **label, OSPanel *panel)
{
    cassert_no_null(label);
    oslabel_detach(*label, panel);
    oslabel_destroy(label);
}

/*---------------------------------------------------------------------------*/

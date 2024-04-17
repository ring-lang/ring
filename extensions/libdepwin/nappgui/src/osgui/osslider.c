/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: osslider.c
 *
 */

/* Operating System native slider */

#include "osslider.h"
#include "osslider.inl"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

void osslider_detach_and_destroy(OSSlider **slider, OSPanel *panel)
{
    cassert_no_null(slider);
    osslider_detach(*slider, panel);
    osslider_destroy(slider);
}

/*---------------------------------------------------------------------------*/

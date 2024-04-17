/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: inet.c
 *
 */

/* inet library */

#include "inet.h"
#include "oshttpreq.inl"
#include <core/core.h>
#include <osbs/log.h>
#include <sewer/blib.h>
#include <sewer/cassert.h>

static uint32_t i_NUM_USERS = 0;

/*---------------------------------------------------------------------------*/

static void i_inet_atexit(void)
{
    if (i_NUM_USERS != 0)
        log_printf("Error! inet is not properly closed (%d)\n", i_NUM_USERS);
}

/*---------------------------------------------------------------------------*/

void inet_start(void)
{
    if (i_NUM_USERS == 0)
    {
        core_start();
        oshttp_init();
        blib_atexit(i_inet_atexit);
    }

    i_NUM_USERS += 1;
}

/*---------------------------------------------------------------------------*/

void inet_finish(void)
{
    cassert(i_NUM_USERS > 0);
    if (i_NUM_USERS == 1)
    {
        oshttp_finish();
        core_finish();
    }

    i_NUM_USERS -= 1;
}

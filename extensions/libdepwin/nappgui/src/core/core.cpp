/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: core.cpp
 *
 */

/* Core library */

#include "core.h"
#include "dbind.inl"
#include "heap.inl"
#include "stream.inl"
#include <osbs/osbs.h>
#include <osbs/bproc.h>
#include <osbs/log.h>
#include <sewer/bmem.h>
#include <sewer/blib.h>
#include <sewer/cassert.h>

static uint32_t i_NUM_USERS = 0;

/*---------------------------------------------------------------------------*/

static void i_core_atexit(void)
{
    if (i_NUM_USERS != 0)
        log_printf("Error! core is not properly closed (%d)\n", i_NUM_USERS);
}

/*---------------------------------------------------------------------------*/

static void i_assert_to_log(void *item, const uint32_t group, const char_t *caption, const char_t *detail, const char_t *file, const uint32_t line)
{
    unref(item);
    unref(group);
    if (group == 0)
    {
        log_printf("FATAL ASSERT: %s (%s:%d): %s", caption, file, line, detail);
        bproc_exit(1000);
    }
    else
    {
        log_printf("ASSERT: %s (%s:%d): %s", caption, file, line, detail);
    }
}

/*---------------------------------------------------------------------------*/

void core_start(void)
{
    if (i_NUM_USERS == 0)
    {
        osbs_start();
        _heap_start();
        _stm_start();
        _dbind_start();
        cassert_set_func(NULL, i_assert_to_log);
        blib_atexit(i_core_atexit);

        i_NUM_USERS = 1;
#if defined(__APPLE__) || defined(__LINUX__)
        cassert(sizeof(EventHandler) == 2 * sizeofptr);
#else
        cassert(sizeof(EventHandler) == sizeofptr);
#endif
    }
    else
    {
        i_NUM_USERS += 1;
    }
}

/*---------------------------------------------------------------------------*/

void core_finish(void)
{
    cassert(i_NUM_USERS > 0);
    if (i_NUM_USERS == 1)
    {
        i_NUM_USERS = 0;
        _dbind_finish();
        _stm_finish();
        _heap_finish();
        osbs_finish();
    }
    else
    {
        i_NUM_USERS -= 1;
    }
}

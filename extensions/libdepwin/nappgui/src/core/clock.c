/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: clock.c
 *
 */

/* Clock (Frame counter) */

#include "clock.h"
#include "heap.h"
#include <osbs/btime.h>
#include <sewer/cassert.h>
#include <sewer/ptr.h>

struct _clock_t
{
    real64_t start_second;
    real64_t frame_rate;
    real64_t handling_time_stamp;
    real64_t last_event_time_stamp;
    real64_t last_update_time_stamp;
    bool_t is_running;
};

/*---------------------------------------------------------------------------*/

#define i_TIME_SEC(microseconds) ((real64_t)microseconds / 1000000.)

/*---------------------------------------------------------------------------*/

static Clock *i_create_clock(
    const bool_t is_running,
    const real64_t start_second,
    const real64_t frame_rate,
    const real64_t handling_time_stamp,
    const real64_t last_event_time_stamp,
    const real64_t last_update_time_stamp)
{
    Clock *clk = heap_new(Clock);
    clk->is_running = is_running;
    clk->start_second = start_second;
    clk->frame_rate = frame_rate;
    clk->handling_time_stamp = handling_time_stamp;
    clk->last_event_time_stamp = last_event_time_stamp;
    clk->last_update_time_stamp = last_update_time_stamp;
    return clk;
}

/*---------------------------------------------------------------------------*/

Clock *clock_create(const real64_t interval)
{
    uint64_t now = btime_now();
    cassert(interval >= 0.);

    return i_create_clock(
        PARAM(is_running, FALSE),
        i_TIME_SEC(now), interval,
        PARAM(handling_time_stamp, 0.),
        PARAM(last_event_time_stamp, 0.),
        PARAM(last_update_time_stamp, 0.));
}

/*---------------------------------------------------------------------------*/

void clock_destroy(Clock **clk)
{
    heap_delete(clk, Clock);
}

/*---------------------------------------------------------------------------*/

bool_t clock_frame(Clock *clk, real64_t *prev_frame, real64_t *curr_frame)
{
    bool_t must_update;
    real64_t tms_new;

    cassert_no_null(clk);

    {
        uint64_t now = btime_now();
        tms_new = i_TIME_SEC(now) - clk->start_second;
    }

    if (clk->is_running == FALSE)
    {
        cassert(clk->handling_time_stamp == 0.);
        clk->is_running = TRUE;
        clk->last_event_time_stamp = tms_new;
        must_update = FALSE;
    }
    else
    {
        if (tms_new < clk->last_update_time_stamp)
        {
            clk->last_update_time_stamp = tms_new;
            clk->last_event_time_stamp = tms_new;
        }

        cassert(clk->last_update_time_stamp >= clk->last_event_time_stamp);

        if (tms_new - clk->last_event_time_stamp < clk->frame_rate)
        {
            /*! <Is early for event launch> */
            must_update = FALSE;
        }
        else
        {
            if (tms_new - clk->last_update_time_stamp > clk->frame_rate)
            {
                /*! <More time since last update (application pause or similar...)> */
                clk->last_event_time_stamp = tms_new;
            }
            else
            {
                clk->last_event_time_stamp += clk->frame_rate;
            }

            ptr_assign(prev_frame, clk->handling_time_stamp);
            clk->handling_time_stamp += clk->frame_rate;
            ptr_assign(curr_frame, clk->handling_time_stamp);
            must_update = TRUE;
        }
    }

    clk->last_update_time_stamp = tms_new;
    return must_update;
}

/*---------------------------------------------------------------------------*/

void clock_reset(Clock *clk)
{
    uint64_t now;
    cassert_no_null(clk);
    now = btime_now();
    clk->start_second = i_TIME_SEC(now);
}

/*---------------------------------------------------------------------------*/

real64_t clock_elapsed(const Clock *clk)
{
    uint64_t now;
    cassert_no_null(clk);
    now = btime_now();
    return i_TIME_SEC(now) - clk->start_second;
}

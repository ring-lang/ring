/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: clock.h
 * https://nappgui.com/en/core/clock.html
 *
 */

/* Clock (Frame counter) */

#include "core.hxx"

__EXTERN_C

_core_api Clock *clock_create(const real64_t interval);

_core_api void clock_destroy(Clock **clk);

_core_api bool_t clock_frame(Clock *clk, real64_t *prev_frame, real64_t *curr_frame);

_core_api void clock_reset(Clock *clk);

_core_api real64_t clock_elapsed(const Clock *clk);

__END_C

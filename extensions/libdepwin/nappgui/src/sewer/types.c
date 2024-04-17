/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: types.c
 *
 */

/* Basic types utils */

#include "cassert.h"
#include "types.h"

/*---------------------------------------------------------------------------*/

uint32_t min_u32(const uint32_t v1, const uint32_t v2)
{
    return v1 < v2 ? v1 : v2;
}

/*---------------------------------------------------------------------------*/

real32_t min_r32(const real32_t v1, const real32_t v2)
{
    return v1 < v2 ? v1 : v2;
}

/*---------------------------------------------------------------------------*/

real64_t min_r64(const real64_t v1, const real64_t v2)
{
    return v1 < v2 ? v1 : v2;
}

/*---------------------------------------------------------------------------*/

uint32_t max_u32(const uint32_t v1, const uint32_t v2)
{
    return v1 > v2 ? v1 : v2;
}

/*---------------------------------------------------------------------------*/

real32_t max_r32(const real32_t v1, const real32_t v2)
{
    return v1 > v2 ? v1 : v2;
}

/*---------------------------------------------------------------------------*/

real64_t max_r64(const real64_t v1, const real64_t v2)
{
    return v1 > v2 ? v1 : v2;
}

/*---------------------------------------------------------------------------*/

real32_t abs_r32(const real32_t v)
{
    return v >= 0.f ? v : -v;
}

/*---------------------------------------------------------------------------*/

uint8_t to_u8(const uint32_t v)
{
    cassert(v < 256);
    return (uint8_t)v;
}

/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: s2d.cpp
 *
 */

/* Size 2d */

#include "s2d.h"
#include "s2d.hpp"

/*---------------------------------------------------------------------------*/

S2Df s2df(const real32_t width, const real32_t height)
{
    S2Df s2d;
    s2d.width = width;
    s2d.height = height;
    return s2d;
}

/*---------------------------------------------------------------------------*/

S2Df s2di(const uint32_t width, const uint32_t height)
{
    S2Df s2d;
    s2d.width = (real32_t)width;
    s2d.height = (real32_t)height;
    return s2d;
}

/*---------------------------------------------------------------------------*/

S2Dd s2dd(const real64_t width, const real64_t height)
{
    S2Dd s2d;
    s2d.width = width;
    s2d.height = height;
    return s2d;
}

/*---------------------------------------------------------------------------*/

const S2Df kS2D_ZEROf = {0, 0};
const S2Dd kS2D_ZEROd = {0, 0};

template <>
const S2D<real32_t>(*S2D<real32_t>::kZERO) = ((S2D<real32_t> *)&kS2D_ZEROf);

template <>
const S2D<real64_t>(*S2D<real64_t>::kZERO) = ((S2D<real64_t> *)&kS2D_ZEROd);

/*---------------------------------------------------------------------------*/

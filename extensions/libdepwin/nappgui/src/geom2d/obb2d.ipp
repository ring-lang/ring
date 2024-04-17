/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: obb2d.ipp
 *
 */

/* Oriented Box 2d */

#ifndef __OBB2D_IPP__
#define __OBB2D_IPP__

#include "obb2d.hpp"
#include "col2d.ipp"

template <typename real>
struct OBB2DI
{
    static SATPoly<real> *(*sat_poly)(const OBB2D<real> *obb);
};

#endif

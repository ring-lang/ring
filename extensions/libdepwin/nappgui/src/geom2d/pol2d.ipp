/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: pol2d.ipp
 *
 */

/* 2d convex polygon */

#ifndef __POL2D_IPP__
#define __POL2D_IPP__

#include "pol2d.hpp"
#include "col2d.ipp"
#include <core/arrpt.hpp>

template <typename real>
struct Pol2DI
{
    static const V2D<real> *(*vertices)(const Pol2D<real> *pol, uint32_t *n);

    static SATPoly<real> *(*sat_poly)(const Pol2D<real> *pol);

    static V2D<real> (*poly_label)(const Pol2D<real> *pol, const real norm_tol);

    static ArrPt<SATPoly<real> > *(*get_convex_sat_polys)(const Pol2D<real> *pol);

    static ArrPt<SATPoly<real> > *(*convex_sat_polys)(Pol2D<real> *pol);
};

#endif

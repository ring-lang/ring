/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: col2d.ipp
 *
 */

/* 2D Collision detection */

#ifndef __COL2D_IPP__
#define __COL2D_IPP__

#include "box2d.hpp"

// Separation Axis Theorem polygon
template <typename real>
struct SATPoly
{
    uint32_t num_vertices;
    uint32_t num_axis;
    V2D<real> *vertex;
    V2D<real> *axis;
    real *min;
    real *max;
    bool_t updated;

    static SATPoly<real> *(*create)(const uint32_t num_vertices, const uint32_t num_axis);

    static SATPoly<real> *(*copy)(const SATPoly<real> *poly);

    static void (*destroy)(SATPoly<real> **poly);

    static Box2D<real> (*bbox)(const SATPoly<real> *poly);

    static void (*limits)(const V2D<real> *vertex, const V2D<real> *axis, const uint32_t num_vertices, const uint32_t num_axis, real *min, real *max);
};

#endif

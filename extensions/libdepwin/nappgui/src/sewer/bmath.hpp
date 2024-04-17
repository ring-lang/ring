/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bmath.hpp
 *
 */

/* Math funcions */

#include "sewer.hxx"

template <typename real>
struct BMath
{
    _sewer_api static real (*cos)(const real angle);

    _sewer_api static real (*sin)(const real angle);

    _sewer_api static real (*tan)(const real angle);

    _sewer_api static real (*acos)(const real cos);

    _sewer_api static real (*asin)(const real sin);

    _sewer_api static real (*atan2)(const real y, const real x);

    _sewer_api static real (*norm_angle)(const real a);

    _sewer_api static real (*sqrt)(const real value);

    _sewer_api static real (*isqrt)(const real value);

    _sewer_api static real (*log)(const real value);

    _sewer_api static real (*log10)(const real value);

    _sewer_api static real (*exp)(const real value);

    _sewer_api static real (*pow)(const real base, const real exponent);

    _sewer_api static real (*abs)(const real value);

    _sewer_api static real (*max)(const real value1, const real value2);

    _sewer_api static real (*min)(const real value1, const real value2);

    _sewer_api static real (*clamp)(const real value, const real min, const real max);

    _sewer_api static real (*mod)(const real num, const real den);

    _sewer_api static real (*modf)(const real value, real *intpart);

    _sewer_api static uint32_t (*prec)(const real value);

    _sewer_api static real (*round)(const real value);

    _sewer_api static real (*round_step)(const real value, const real step);

    _sewer_api static real (*floor)(const real value);

    _sewer_api static real (*ceil)(const real value);

    _sewer_api static const real kE;
    _sewer_api static const real kLN2;
    _sewer_api static const real kLN10;
    _sewer_api static const real kPI;
    _sewer_api static const real kSQRT2;
    _sewer_api static const real kSQRT3;
    _sewer_api static const real kDEG2RAD;
    _sewer_api static const real kRAD2DEG;
    _sewer_api static const real kINFINITY;
};

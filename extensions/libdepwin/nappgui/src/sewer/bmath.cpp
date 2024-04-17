/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: bmath.cpp
 *
 */

/* Math funcions */

#include "bmath.h"
#include "bmath.hpp"
#include "bmath.inl"
#include "bmem.h"
#include "cassert.h"
#include "ptr.h"

#include "nowarn.hxx"
extern "C"
{
#include <math.h>
}
#include "warn.hxx"

//#if defined(__ASSERTS__)
//static const uint32_t i_PASCAL_TRIANGLE_LEVELS = 30;
//#endif
//
//static const uint32_t i_PASCAL_TRIANGLE[] = {
//1,
//1, 1,
//1, 2, 1,
//1, 3, 3, 1,
//1, 4, 6, 4, 1,
//1, 5, 10, 10, 5, 1,
//1, 6, 15, 20, 15, 6, 1,
//1, 7, 21, 35, 35, 21, 7, 1,
//1, 8, 28, 56, 70, 56, 28, 8, 1,
//1, 9, 36, 84, 126, 126, 84, 36, 9, 1,
//1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1,
//1, 11, 55, 165, 330, 462, 462, 330, 165, 55, 11, 1,
//1, 12, 66, 220, 495, 792, 924, 792, 495, 220, 66, 12, 1,
//1, 13, 78, 286, 715, 1287, 1716, 1716, 1287, 715, 286, 78, 13, 1,
//1, 14, 91, 364, 1001, 2002, 3003, 3432, 3003, 2002, 1001, 364, 91, 14, 1,
//1, 15, 105, 455, 1365, 3003, 5005, 6435, 6435, 5005, 3003, 1365, 455, 105, 15, 1,
//1, 16, 120, 560, 1820, 4368, 8008, 11440, 12870, 11440, 8008, 4368, 1820, 560, 120, 16, 1,
//1, 17, 136, 680, 2380, 6188, 12376, 19448, 24310, 24310, 19448, 12376, 6188, 2380, 680, 136, 17, 1,
//1, 18, 153, 816, 3060, 8568, 18564, 31824, 43758, 48620, 43758, 31824, 18564, 8568, 3060, 816, 153, 18, 1,
//1, 19, 171, 969, 3876, 11628, 27132, 50388, 75582, 92378, 92378, 75582, 50388, 27132, 11628, 3876, 969, 171, 19, 1,
//1, 20, 190, 1140, 4845, 15504, 38760, 77520, 125970, 167960, 184756, 167960, 125970, 77520, 38760, 15504, 4845, 1140, 190, 20, 1,
//1, 21, 210, 1330, 5985, 20349, 54264, 116280, 203490, 293930, 352716, 352716, 293930, 203490, 116280, 54264, 20349, 5985, 1330, 210, 21, 1,
//1, 22, 231, 1540, 7315, 26334, 74613, 170544, 319770, 497420, 646646, 705432, 646646, 497420, 319770, 170544, 74613, 26334, 7315, 1540, 231, 22, 1,
//1, 23, 253, 1771, 8855, 33649, 100947, 245157, 490314, 817190, 1144066, 1352078, 1352078, 1144066, 817190, 490314, 245157, 100947, 33649, 8855, 1771, 253, 23, 1,
//1, 24, 276, 2024, 10626, 42504, 134596, 346104, 735471, 1307504, 1961256, 2496144, 2704156, 2496144, 1961256, 1307504, 735471, 346104, 134596, 42504, 10626, 2024, 276, 24, 1,
//1, 25, 300, 2300, 12650, 53130, 177100, 480700, 1081575, 2042975, 3268760, 4457400, 5200300, 5200300, 4457400, 3268760, 2042975, 1081575, 480700, 177100, 53130, 12650, 2300, 300, 25, 1,
//1, 26, 325, 2600, 14950, 65780, 230230, 657800, 1562275, 3124550, 5311735, 7726160, 9657700, 10400600, 9657700, 7726160, 5311735, 3124550, 1562275, 657800, 230230, 65780, 14950, 2600, 325, 26, 1,
//1, 27, 351, 2925, 17550, 80730, 296010, 888030, 2220075, 4686825, 8436285, 13037895, 17383860, 20058300, 20058300, 17383860, 13037895, 8436285, 4686825, 2220075, 888030, 296010, 80730, 17550, 2925, 351, 27, 1,
//1, 28, 378, 3276, 20475, 98280, 376740, 1184040, 3108105, 6906900, 13123110, 21474180, 30421755, 37442160, 40116600, 37442160, 30421755, 21474180, 13123110, 6906900, 3108105, 1184040, 376740, 98280, 20475, 3276, 378, 28, 1,
//1, 29, 406, 3654, 23751, 118755, 475020, 1560780, 4292145, 10015005, 20030010, 34597290, 51895935, 67863915, 77558760, 77558760, 67863915, 51895935, 34597290, 20030010, 10015005, 4292145, 1560780, 475020, 118755, 23751, 3654, 406, 29, 1};

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_equals(const real value1, const real value2, const real tolerance)
{
    real diff = value1 - value2;
    cassert(tolerance >= 0);
    if (diff < 0)
        diff = -diff;
    if (diff < tolerance)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_less(const real value1, const real value2, const real tolerance)
{
    cassert(tolerance >= (real)0. /*CMath<real>::k0*/);
    if ((value1 + tolerance) < value2)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_less_eq(const real value1, const real value2, const real tolerance)
{
    cassert(tolerance >= (real)0. /*CMath<real>::k0*/);
    //	cassert(tolerance >= CMath<real>::k0);
    if (value1 < value2)
        return TRUE;
    else if (value2 - value1 < tolerance)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_great(const real value1, const real value2, const real tolerance)
{
    cassert(tolerance >= (real)0. /*CMath<real>::k0*/);

    //	cassert(tolerance >= CMath<real>::k0);
    if ((value1 - tolerance) > value2)
        return TRUE;
    else
        return FALSE;
}

/*---------------------------------------------------------------------------*/

real32_t bmath_cosf(const real32_t angle)
{
    return (real32_t)cosf((float)angle);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_cosd(const real64_t angle)
{
    return (real64_t)cos((double)angle);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_sinf(const real32_t angle)
{
    return (real32_t)sinf((float)angle);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_sind(const real64_t angle)
{
    return (real64_t)sin((double)angle);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_tanf(const real32_t angle)
{
    return (real32_t)tanf((float)angle);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_tand(const real64_t angle)
{
    return (real64_t)tan((double)angle);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_acosf(const real32_t cos)
{
    cassert(cos >= -1.f && cos <= 1.f);
    return (real32_t)acosf((float)cos);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_acosd(const real64_t cos)
{
    cassert(cos >= -1. && cos <= 1.);
    return (real64_t)acos((double)cos);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_asinf(const real32_t sin)
{
    cassert(sin >= -1.f && sin <= 1.f);
    return (real32_t)asinf((float)sin);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_asind(const real64_t sin)
{
    cassert(sin >= -1. && sin <= 1.);
    return (real64_t)asin((double)sin);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_atan2f(const real32_t y, const real32_t x)
{
    return (real32_t)atan2f((float)y, (float)x);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_atan2d(const real64_t y, const real64_t x)
{
    return (real64_t)atan2((double)y, (double)x);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_norm_anglef(const real32_t a)
{
    const real32_t twopi = 2 * kBMATH_PIf;
    real32_t nangle = a - twopi * bmath_floorf((a + kBMATH_PIf) / twopi);
    cassert(nangle > -kBMATH_PIf && nangle <= kBMATH_PIf);
    return nangle;
}

/*---------------------------------------------------------------------------*/

real64_t bmath_norm_angled(const real64_t a)
{
    const real64_t twopi = 2 * kBMATH_PId;
    real64_t nangle = a - twopi * bmath_floord((a + kBMATH_PId) / twopi);
    cassert(nangle > -kBMATH_PId && nangle <= kBMATH_PId);
    return nangle;
}

/*---------------------------------------------------------------------------*/

real32_t bmath_sqrtf(const real32_t value)
{
    cassert(value >= 0.f);
    return (real32_t)sqrtf((float)value);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_sqrtd(const real64_t value)
{
    cassert(value >= 0.);
    return (real64_t)sqrt((double)value);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_isqrtf(const real32_t value)
{
    /*    real32_t nvalue = value;
    real32_t half_value = CMath<real32_t>::kONE_OVER_TWO * value;
    int32_t i = *(int32_t*)&nvalue;
    cassert(value > CMath<real32_t>::k0);
    i = 0x5f3759df - (i >> 1);
    nvalue = *(real32_t*)&i;
    nvalue = nvalue * (CMath<real32_t>::kTHREE_OVER_TWO - half_value * nvalue * nvalue);
    return nvalue; */

    cassert(value > 0.f);
    return 1.f / sqrtf((float)value);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_isqrtd(const real64_t value)
{

    /*    real64_t nvalue = value;    
    real64_t half_value = CMath<real64_t>::kONE_OVER_TWO * value;
    uint64_t i = *(uint64_t*)(&nvalue);

    cassert(value > CMath<real32_t>::k0);

    i = 0x5fe6ec85e7de30da - ( i >> 1 );
    nvalue = *(real64_t*)&i;    
    nvalue = nvalue * (CMath<real64_t>::kTHREE_OVER_TWO - half_value * nvalue * nvalue);        
    return nvalue;*/

    cassert(value > 0.);
    return 1.f / sqrt((double)value);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_logf(const real32_t value)
{
    return (real32_t)logf((float)value);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_logd(const real64_t value)
{
    return (real64_t)log((double)value);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_log10f(const real32_t value)
{
    return (real32_t)log10f((float)value);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_log10d(const real64_t value)
{
    return (real64_t)log10((double)value);
}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_log2u32(const uint32_t value);
//uint32_t bmath_log2u32(const uint32_t value)
//{
//    register uint32_t valuep = value;
//    register uint32_t log2p = 0;
//    cassert(valuep > 0);
//    while (valuep > 0)
//    {
//        valuep >>= 1;
//        log2p++;
//    }
//
//    return log2p;
//}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_next_power_of_two(const uint32_t value);
//uint32_t bmath_next_power_of_two(const uint32_t value)
//{
//    register uint32_t v = value;
//    v--;
//    v |= v >> 1;
//    v |= v >> 2;
//    v |= v >> 4;
//    v |= v >> 8;
//    v |= v >> 16;
//    v++;
//    return v;
//}

/*---------------------------------------------------------------------------*/

real32_t bmath_expf(const real32_t value)
{
    return (real32_t)expf((float)value);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_expd(const real64_t value)
{
    return (real64_t)exp((double)value);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_powf(const real32_t base, const real32_t exponent)
{
    return (real32_t)powf((float)base, (float)exponent);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_powd(const real64_t base, const real64_t exponent)
{
    return (real64_t)pow((double)base, (double)exponent);
}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_powu32(const uint32_t base, const uint32_t exp);
//uint32_t bmath_powu32(const uint32_t base, const uint32_t exp)
//{
//    register uint32_t res = 1;
//    register uint32_t ibase = base;
//    register uint32_t iexp = exp;
//    while (iexp)
//    {
//        if (iexp & 1)
//            res *= ibase;
//        iexp >>= 1;
//        ibase *= ibase;
//    }
//    return res;
//}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_bincoeffu32(const uint32_t upper, const uint32_t lower);
//uint32_t bmath_bincoeffu32(const uint32_t upper, const uint32_t lower)
//{
//    register uint32_t offset;
//    cassert(upper < i_PASCAL_TRIANGLE_LEVELS);
//    cassert(lower <= upper);
//    offset = upper * upper + upper;
//    cassert(offset % 2 == 0);
//    offset = offset / 2 + lower;
//    return i_PASCAL_TRIANGLE[offset];
//}

/*---------------------------------------------------------------------------*/

real32_t bmath_absf(const real32_t value)
{
    if (value < 0.f)
        return -value;
    else
        return value;

    /*    uint32_t absv;
    absv = (*(uint32_t*)&value) & 0x7FFFFFFF;    
    return *((real32_t*)&absv);*/
}

/*---------------------------------------------------------------------------*/

real64_t bmath_absd(const real64_t value)
{
    if (value < 0.f)
        return -value;
    else
        return value;
    /*    uint64_t mask;
    uint64_t absv;

    mask = ((uint64_t)0x7FFFFFFF << 32) | (0xFFFFFFFF);
    absv = (*(uint64_t*)&value) & mask;    
    return *((real64_t*)&absv);*/
}

/*---------------------------------------------------------------------------*/

real32_t bmath_maxf(const real32_t value1, const real32_t value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

/*---------------------------------------------------------------------------*/

//real32_t bmath_max3f(const real32_t value1, const real32_t value2, const real32_t value3);
//real32_t bmath_max3f(const real32_t value1, const real32_t value2, const real32_t value3)
//{
//    real32_t max;
//
//    if (value1 > value2)
//        max = value1;
//    else
//        max = value2;
//
//    if (value3 > max)
//        max = value3;
//
//    return max;
//}

/*---------------------------------------------------------------------------*/

//real32_t bmath_max4f(const real32_t value1, const real32_t value2, const real32_t value3, const real32_t value4);
//real32_t bmath_max4f(const real32_t value1, const real32_t value2, const real32_t value3, const real32_t value4)
//{
//    real32_t max;
//
//    if (value1 > value2)
//        max = value1;
//    else
//        max = value2;
//
//    if (value3 > max)
//        max = value3;
//
//    if (value4 > max)
//        max = value4;
//
//    return max;
//}

/*---------------------------------------------------------------------------*/

real64_t bmath_maxd(const real64_t value1, const real64_t value2)
{
    if (value1 > value2)
        return value1;
    else
        return value2;
}

/*---------------------------------------------------------------------------*/

real32_t bmath_minf(const real32_t value1, const real32_t value2)
{
    if (value1 < value2)
        return value1;
    else
        return value2;
}

/*---------------------------------------------------------------------------*/

//real32_t bmath_min3f(const real32_t value1, const real32_t value2, const real32_t value3);
//real32_t bmath_min3f(const real32_t value1, const real32_t value2, const real32_t value3)
//{
//    real32_t min;
//
//    if (value1 < value2)
//        min = value1;
//    else
//        min = value2;
//
//    if (value3 < min)
//        min = value3;
//
//    return min;
//}

/*---------------------------------------------------------------------------*/

//real32_t bmath_min4f(const real32_t value1, const real32_t value2, const real32_t value3, const real32_t value4);
//real32_t bmath_min4f(const real32_t value1, const real32_t value2, const real32_t value3, const real32_t value4)
//{
//    real32_t min;
//
//    if (value1 < value2)
//        min = value1;
//    else
//        min = value2;
//
//    if (value3 < min)
//        min = value3;
//
//    if (value4 < min)
//        min = value4;
//
//    return min;
//}

/*---------------------------------------------------------------------------*/

real64_t bmath_mind(const real64_t value1, const real64_t value2)
{
    if (value1 < value2)
        return value1;
    else
        return value2;
}

/*---------------------------------------------------------------------------*/

real32_t bmath_clampf(const real32_t value, const real32_t min, const real32_t max)
{
    cassert(min < max);

    if (__FALSE_EXPECTED(value < min))
        return min;

    else if (__FALSE_EXPECTED(value > max))
        return max;

    return value;
}

/*---------------------------------------------------------------------------*/

real64_t bmath_clampd(const real64_t value, const real64_t min, const real64_t max)
{
    cassert(min < max);

    if (__FALSE_EXPECTED(value < min))
        return min;

    else if (__FALSE_EXPECTED(value > max))
        return max;

    return value;
}

/*---------------------------------------------------------------------------*/

real32_t bmath_modf(const real32_t num, const real32_t den)
{
    return (real32_t)fmodf((float)num, (float)den);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_modd(const real64_t value, const real64_t den)
{
    return (real64_t)fmod((double)value, (double)den);
}

/*---------------------------------------------------------------------------*/

real32_t bmath_modff(const real32_t value, real32_t *intpart)
{
    return (real32_t)modff((float)value, (float *)intpart);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_modfd(const real64_t num, real64_t *intpart)
{
    return (real64_t)modf((double)num, (double *)intpart);
}

/*---------------------------------------------------------------------------*/

template <typename real>
uint32_t i_precision(const real value)
{
    real e = 1, v = value, frac, intpart;
    uint32_t p = 0;

    if (v < 0)
        v = -v;

    frac = BMath<real>::modf(v, &intpart);

    for (;;)
    {
        if (frac + .000001 > e)
            return p;

        e /= 10;
        p += 1;
    }
}

/*---------------------------------------------------------------------------*/

uint32_t bmath_precf(const real32_t value)
{
    return i_precision<real32_t>(value);
}

/*---------------------------------------------------------------------------*/

uint32_t bmath_precd(const real64_t value)
{
    return i_precision<real64_t>(value);
}

/*---------------------------------------------------------------------------*/

//uint8_t bmath_round_real32_to_uint8(const real32_t value);
//uint8_t bmath_round_real32_to_uint8(const real32_t value)
//{
//    cassert(value >= 0.f);
//    cassert(value <= (real32_t)UINT8_MAX);
//	return (uint8_t)floorf((float)(value + .5f));
//}

/*---------------------------------------------------------------------------*/

//uint8_t bmath_round_real64_to_uint8(const real64_t value);
//uint8_t bmath_round_real64_to_uint8(const real64_t value)
//{
//    cassert(value >= 0.);
//    cassert(value <= (real64_t)UINT8_MAX);
//	return (uint8_t)floor((double)(value + .5));
//}

/*---------------------------------------------------------------------------*/

//uint16_t bmath_round_real32_to_uint16(const real32_t value);
//uint16_t bmath_round_real32_to_uint16(const real32_t value)
//{
//    cassert(value >= 0.f);
//    cassert(value <= (real32_t)UINT16_MAX);
//	return (uint16_t)floorf((float)(value + .5f));
//}

/*---------------------------------------------------------------------------*/

//uint16_t bmath_round_real64_to_uint16(const real64_t value);
//uint16_t bmath_round_real64_to_uint16(const real64_t value)
//{
//    cassert(value >= 0.);
//    cassert(value <= (real64_t)UINT16_MAX);
//	return (uint16_t)floor((double)(value + .5));
//}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_round_real32_to_uint32(const real32_t value);
//uint32_t bmath_round_real32_to_uint32(const real32_t value)
//{
//    cassert(value >= 0.f);
//    cassert(value <= (real32_t)UINT32_MAX);
//	return (uint32_t)floorf((float)(value + .5f));
//}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_round_real64_to_uint32(const real64_t value);
//uint32_t bmath_round_real64_to_uint32(const real64_t value)
//{
//    cassert(value >= 0.);
//    cassert(value <= (real64_t)UINT32_MAX);
//	return (uint32_t)floor((double)(value + .5));
//}

/*---------------------------------------------------------------------------*/

real32_t bmath_roundf(const real32_t value)
{
    return (real32_t)floorf((float)(value + .5f));
}

/*---------------------------------------------------------------------------*/

real64_t bmath_roundd(const real64_t value)
{
    return floor((double)(value + .5));
}

/*---------------------------------------------------------------------------*/

real32_t bmath_round_stepf(const real32_t value, const real32_t step)
{
    cassert(step > 0.f);
    return step * (real32_t)floorf((float)(value / step + .5f));
}

/*---------------------------------------------------------------------------*/

real64_t bmath_round_stepd(const real64_t value, const real64_t step)
{
    cassert(step > 0.f);
    return step * (real64_t)floor((double)(value / step + .5));
}

/*---------------------------------------------------------------------------*/

//uint16_t bmath_uint32_to_uint16(const uint32_t value);
//uint16_t bmath_uint32_to_uint16(const uint32_t value)
//{
//    cassert(value <= 0xFFFF);
//    return (uint16_t)value;
//}

/*---------------------------------------------------------------------------*/

//real32_t bmath_round_tolerance_real32(const real32_t value, const real32_t tolerance);
//real32_t bmath_round_tolerance_real32(const real32_t value, const real32_t tolerance)
//{
//    real32_t blocks;
//    cassert(tolerance > 0.f);
//    blocks = (real32_t)floorf((float)(value / tolerance + .5f));
//    return blocks * tolerance;
//}

/*---------------------------------------------------------------------------*/

real32_t bmath_floorf(const real32_t value)
{
    return (real32_t)floorf((float)value);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_floord(const real64_t value)
{
    return (real64_t)floor((double)value);
}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_floor32f(const real32_t value);
//uint32_t bmath_floor32f(const real32_t value)
//{
//    cassert(value >= 0.f);
//    cassert(value < (real32_t)UINT32_MAX);
//	return (uint32_t)floorf((float)value);
//}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_floor_real64_to_uint32(const real64_t value);
//uint32_t bmath_floor_real64_to_uint32(const real64_t value)
//{
//    cassert(value >= 0.);
//    cassert(value < (real64_t)UINT32_MAX);
//	return (uint32_t)floor((double)value);
//}

/*---------------------------------------------------------------------------*/

real32_t bmath_ceilf(const real32_t value)
{
    return (real32_t)ceilf((float)value);
}

/*---------------------------------------------------------------------------*/

real64_t bmath_ceild(const real64_t value)
{
    return (real64_t)ceil((double)value);
}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_ceil_real64_to_uint32(const real64_t value);
//uint32_t bmath_ceil_real64_to_uint32(const real64_t value)
//{
//    cassert(value >= 0.);
//    cassert(value < (real64_t)UINT32_MAX);
//	return (uint32_t)ceil((double)value);
//}

/*---------------------------------------------------------------------------*/

//void bmath_descompose_uvaluef(const real32_t value, uint32_t *integer, real32_t *fraction);
//void bmath_descompose_uvaluef(const real32_t value, uint32_t *integer, real32_t *fraction)
//{
//    real32_t _integer;
//    real32_t _fraction;
//
//    cassert(value >= 0.f);
//
//    _fraction = (real32_t)modff((float)value, (float*)&_integer);
//
//    if (integer != NULL)
//        *integer = (uint32_t)_integer;
//
//    if (fraction != NULL)
//        *fraction = _fraction;
//}

/*---------------------------------------------------------------------------*/

//void bmath_descompose_uvalued(const real64_t value, uint32_t *integer, real64_t *fraction);
//void bmath_descompose_uvalued(const real64_t value, uint32_t *integer, real64_t *fraction)
//{
//    real64_t _integer;
//    real64_t _fraction;
//
//    cassert(value >= 0.);
//
//    _fraction = (real64_t)modf((double)value, (double*)&_integer);
//
//    if (integer != NULL)
//        *integer = (uint32_t)_integer;
//
//    if (fraction != NULL)
//        *fraction = _fraction;
//}

/*---------------------------------------------------------------------------*/

/*
uint32_t bmath_uint32_from_fractionf(const real32_t value, const uint32_t max_iters);
uint32_t bmath_uint32_from_fractionf(const real32_t value, const uint32_t max_iters)
{
    register uint32_t i;
    real32_t current_value = value;
    cassert(value >= CMath<real32_t>::k0);
    for (i = 0; i < max_iters; ++i)
    {
        real32_t intpart;
        real32_t frapart;
        frapart = (real32_t)modff((float)current_value, (float*)&intpart);
        if (frapart == 0.f)
            return (uint32_t)intpart;

        current_value *= 10.f;
    }

    return (uint32_t)current_value;
}*/

/*---------------------------------------------------------------------------*/

//template<typename real>
//static bool_t i_measure_error(const real original_value, const real measure_value, const real max_absolute_error, const real max_relative_error)
//{
//    real absolute_error;
//    real relative_error;
//
//    /*
//    cassert(max_absolute_error > CMath<real>::k0);
//    cassert(max_relative_error > CMath<real>::k0);
//    cassert(max_relative_error < CMath<real>::k1);
//*/
//    absolute_error = (real)0.;//CMath<real>::k0;
//    relative_error = (real)0.;//CMath<real>::k0;
//    absolute_error = original_value - measure_value;
//
//    if (absolute_error < (real)0./*CMath<real>::k0*/)
//        absolute_error = - absolute_error;
//
//    if (absolute_error <= max_absolute_error)
//        return FALSE;
//
//    if (original_value != (real)0./*CMath<real>::k0*/)
//    {
//        relative_error = (original_value - measure_value) / original_value;
//
//        if (relative_error < (real)0./*CMath<real>::k0*/)
//            relative_error = - relative_error;
//
//        if (relative_error <= max_relative_error)
//            return FALSE;
//    }
//    else
//    {
//        relative_error = (real)kINFINITYd/* CMath<real>::kINFINITY*/;
//    }
//
//    return TRUE;
//}

/*---------------------------------------------------------------------------*/

//bool_t bmath_measure_errorf(const real32_t original_value, const real32_t measure_value, const real32_t max_absolute_error, const real32_t max_relative_error);
//bool_t bmath_measure_errorf(const real32_t original_value, const real32_t measure_value, const real32_t max_absolute_error, const real32_t max_relative_error)
//{
//    return i_measure_error<real32_t>(original_value, measure_value, max_absolute_error, max_relative_error);
//}

/*---------------------------------------------------------------------------*/

//bool_t bmath_measure_errord(const real64_t original_value, const real64_t measure_value, const real64_t max_absolute_error, const real64_t max_relative_error);
//bool_t bmath_measure_errord(const real64_t original_value, const real64_t measure_value, const real64_t max_absolute_error, const real64_t max_relative_error)
//{
//    return i_measure_error<real64_t>(original_value, measure_value, max_absolute_error, max_relative_error);
//}

/*---------------------------------------------------------------------------*/

//template<typename real>
//static compare_t i_compare_relative(const real value1, const real value2, const real epsilon)
//{
//    real abs_value1 = value1;
//
//    cassert(epsilon > (real)0.);
//
//    if (abs_value1 < (real)0.)
//        abs_value1 = - abs_value1;
//
//    if (abs_value1 < epsilon)
//    {
//        real abs_diff = value1 - value2;
//
//        if (abs_diff < (real)0.)
//            abs_diff = - abs_diff;
//
//        if (abs_diff < epsilon)
//            return ekEQUALS;
//        else if (value1 < value2)
//            return ekFIRST_SMALLER;
//        else
//            return ekSECOND_SMALLER;
//    }
//    else
//    {
//        real abs_diff;
//
//        abs_diff = (value1 - value2) / value1;
//
//        if (abs_diff < (real)0.)
//            abs_diff = - abs_diff;
//
//        if (abs_diff < epsilon)
//            return ekEQUALS;
//        else if (value1 < value2)
//            return ekFIRST_SMALLER;
//        else
//            return ekSECOND_SMALLER;
//    }
//}

/*---------------------------------------------------------------------------*/

//compare_t bmath_compare_relativef(const real32_t value1, const real32_t value2, const real32_t epsilon);
//compare_t bmath_compare_relativef(const real32_t value1, const real32_t value2, const real32_t epsilon)
//{
//    return i_compare_relative<real32_t>(value1, value2, epsilon);
//}

/*---------------------------------------------------------------------------*/

//void bmath_convers_realfd(real32_t *dest, const real64_t *src, const uint32_t num_elems);
//void bmath_convers_realfd(real32_t *dest, const real64_t *src, const uint32_t num_elems)
//{
//    register uint32_t i;
//    cassert_no_null(dest);
//    cassert_no_null(src);
//    for (i = 0; i < num_elems; ++i, ++dest, ++src)
//        *dest = (real32_t)*src;
//}

/*---------------------------------------------------------------------------*/

/* Random numbers */
/* Originally developed and coded by Makoto Matsumoto and Takuji
 * Nishimura.  Please mail <matumoto@math.keio.ac.jp>, if you're using
 * code from this file in your own programs or libraries.
 * Further information on the Mersenne Twister can be found at
 * http://www.math.sci.hiroshima-u.ac.jp/~m-mat/MT/emt.html
 */

/* Period parameters */
#define N 624
#define M 397
#define MATRIX_A 0x9908b0df   /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */

/* Tempering parameters */
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y) (y >> 11)
#define TEMPERING_SHIFT_S(y) (y << 7)
#define TEMPERING_SHIFT_T(y) (y << 15)
#define TEMPERING_SHIFT_L(y) (y >> 18)

struct _renv_t
{
    uint32_t mti;
    uint32_t mt[N];
};

static REnv *i_GLOBAL_RENV = NULL;

/*---------------------------------------------------------------------------*/

//uint32_t bmath_time_seed(void);
//uint32_t bmath_time_seed(void)
//{
//    return (uint32_t)(btime_now() % UINT32_MAX);
//}

/*---------------------------------------------------------------------------*/

void _bmath_finish(void)
{
    if (i_GLOBAL_RENV != NULL)
        bmem_free((byte_t *)i_GLOBAL_RENV);
}

/*---------------------------------------------------------------------------*/

static void i_set_seed(REnv *env, const uint32_t seed)
{
    cassert_no_null(env);
    env->mt[0] = seed;
    for (env->mti = 1; env->mti < N; env->mti++)
        env->mt[env->mti] = (uint32_t)1812433253UL * (env->mt[env->mti - 1] ^ (env->mt[env->mti - 1] >> 30)) + env->mti;
}

/*---------------------------------------------------------------------------*/

static __INLINE void i_global_env(void)
{
    if (__FALSE_EXPECTED(i_GLOBAL_RENV == NULL))
    {
        i_GLOBAL_RENV = (REnv *)bmem_malloc(sizeof(REnv));
        i_set_seed(i_GLOBAL_RENV, TEMPERING_MASK_B);
        i_GLOBAL_RENV->mti = N;
    }
}

/*---------------------------------------------------------------------------*/

void bmath_rand_seed(const uint32_t seed)
{
    i_global_env();
    i_set_seed(i_GLOBAL_RENV, seed);
}

/*---------------------------------------------------------------------------*/

static uint32_t i_next_random(REnv *env)
{
    uint32_t y;
    static const uint32_t mag01[2] = {0x0, MATRIX_A};

    cassert_no_null(env);

    /* Generate N words at one time */
    if (env->mti >= N)
    {
        register uint32_t kk;
        register uint32_t *mt = env->mt;

        for (kk = 0; kk < N - M; kk++)
        {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + M] ^ (y >> 1) ^ mag01[y & 0x1];
        }

        for (; kk < N - 1; kk++)
        {
            y = (mt[kk] & UPPER_MASK) | (mt[kk + 1] & LOWER_MASK);
            mt[kk] = mt[kk + (uint32_t)(M - N)] ^ (y >> 1) ^ mag01[y & 0x1];
        }

        y = (mt[N - 1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
        mt[N - 1] = mt[M - 1] ^ (y >> 1) ^ mag01[y & 0x1];

        env->mti = 0;
    }

    y = env->mt[env->mti++];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);

    return y;
}

/*---------------------------------------------------------------------------*/

//bool_t bmath_rand_bool(void);
//bool_t bmath_rand_bool(void)
//{
//    if (i_next_random() % 2 == 0)
//        return TRUE;
//    else
//        return FALSE;
//}

/*---------------------------------------------------------------------------*/

//uint8_t bmath_rand_uint8(void);
//uint8_t bmath_rand_uint8(void)
//{
//    return (uint8_t)(i_next_random() % 0x100);
//}

/*---------------------------------------------------------------------------*/

//uint16_t bmath_rand_uint16(void);
//uint16_t bmath_rand_uint16(void)
//{
//    return (uint16_t)(i_next_random() % 0x10000);
//}

/*---------------------------------------------------------------------------*/

//uint32_t bmath_rand_uint32(void);
//uint32_t bmath_rand_uint32()
//{
//    return i_next_random();
//}

/*---------------------------------------------------------------------------*/

real32_t bmath_randf(const real32_t from, const real32_t to)
{
    cassert(from < to);
    i_global_env();
    return from + (real32_t)(i_next_random(i_GLOBAL_RENV) % 1000001) * (to - from) * .000001f;
}

/*---------------------------------------------------------------------------*/

real64_t bmath_randd(const real64_t from, const real64_t to)
{
    cassert(from < to);
    i_global_env();
    return from + (real64_t)(i_next_random(i_GLOBAL_RENV) % 100000001) * (to - from) * .00000001;
}

/*---------------------------------------------------------------------------*/

uint32_t bmath_randi(const uint32_t from, const uint32_t to)
{
    cassert(from < to);
    i_global_env();
    return from + (i_next_random(i_GLOBAL_RENV) % (to - from + 1));
}

/*---------------------------------------------------------------------------*/

REnv *bmath_rand_env(const uint32_t seed)
{
    REnv *env = (REnv *)bmem_malloc(sizeof(REnv));
    env->mti = N;
    i_set_seed(env, seed);
    return env;
}

/*---------------------------------------------------------------------------*/

void bmath_rand_destroy(REnv **env)
{
    cassert_no_null(env);
    bmem_free((byte_t *)*env);
    *env = NULL;
}

/*---------------------------------------------------------------------------*/

real32_t bmath_rand_mtf(REnv *env, const real32_t from, const real32_t to)
{
    cassert(from < to);
    return from + (real32_t)(i_next_random(env) % 1000001) * (to - from) * .000001f;
}

/*---------------------------------------------------------------------------*/

real64_t bmath_rand_mtd(REnv *env, const real64_t from, const real64_t to)
{
    cassert(from < to);
    return from + (real64_t)(i_next_random(env) % 100000001) * (to - from) * .00000001;
}

/*---------------------------------------------------------------------------*/

uint32_t bmath_rand_mti(REnv *env, const uint32_t from, const uint32_t to)
{
    cassert(from < to);
    return from + (i_next_random(env) % (to - from + 1));
}

/*---------------------------------------------------------------------------*/

const real32_t kBMATH_Ef = 2.7182818284590452353602874713526624977572470937000f;
const real64_t kBMATH_Ed = 2.7182818284590452353602874713526624977572470937000;
template <>
const real32_t BMath<real32_t>::kE = 2.7182818284590452353602874713526624977572470937000f;
template <>
const real64_t BMath<real64_t>::kE = 2.7182818284590452353602874713526624977572470937000;
const real32_t kBMATH_LN2f = 0.69314718055994530941723212145817656807550013436026f;
const real64_t kBMATH_LN2d = 0.69314718055994530941723212145817656807550013436026;
template <>
const real32_t BMath<real32_t>::kLN2 = 0.69314718055994530941723212145817656807550013436026f;
template <>
const real64_t BMath<real64_t>::kLN2 = 0.69314718055994530941723212145817656807550013436026;
const real32_t kBMATH_LN10f = 2.3025850929940456840179914546843642076011014886288f;
const real64_t kBMATH_LN10d = 2.3025850929940456840179914546843642076011014886288;
template <>
const real32_t BMath<real32_t>::kLN10 = 2.3025850929940456840179914546843642076011014886288f;
template <>
const real64_t BMath<real64_t>::kLN10 = 2.3025850929940456840179914546843642076011014886288;
const real32_t kBMATH_PIf = 3.1415926535897932384626433832795028841971693993751f;
const real64_t kBMATH_PId = 3.1415926535897932384626433832795028841971693993751;
template <>
const real32_t BMath<real32_t>::kPI = 3.1415926535897932384626433832795028841971693993751f;
template <>
const real64_t BMath<real64_t>::kPI = 3.1415926535897932384626433832795028841971693993751;
const real32_t kBMATH_SQRT2f = 1.4142135623730950488016887242096980785696718753769f;
const real64_t kBMATH_SQRT2d = 1.4142135623730950488016887242096980785696718753769;
template <>
const real32_t BMath<real32_t>::kSQRT2 = 1.4142135623730950488016887242096980785696718753769f;
template <>
const real64_t BMath<real64_t>::kSQRT2 = 1.4142135623730950488016887242096980785696718753769;
const real32_t kBMATH_SQRT3f = 1.732050807568877293527446f;
const real64_t kBMATH_SQRT3d = 1.732050807568877293527446;
template <>
const real32_t BMath<real32_t>::kSQRT3 = 1.732050807568877293527446f;
template <>
const real64_t BMath<real64_t>::kSQRT3 = 1.732050807568877293527446;
const real32_t kBMATH_DEG2RADf = 0.017453292519943f;
const real64_t kBMATH_DEG2RADd = 0.017453292519943;
template <>
const real32_t BMath<real32_t>::kDEG2RAD = 0.017453292519943f;
template <>
const real64_t BMath<real64_t>::kDEG2RAD = 0.017453292519943;
const real32_t kBMATH_RAD2DEGf = 57.29577951308232f;
const real64_t kBMATH_RAD2DEGd = 57.29577951308232;
template <>
const real32_t BMath<real32_t>::kRAD2DEG = 57.29577951308232f;
template <>
const real64_t BMath<real64_t>::kRAD2DEG = 57.29577951308232;
const real32_t kBMATH_INFINITYf = REAL32_MAX;
const real64_t kBMATH_INFINITYd = REAL64_MAX;
template <>
const real32_t BMath<real32_t>::kINFINITY = REAL32_MAX;
template <>
const real64_t BMath<real64_t>::kINFINITY = REAL64_MAX;

/*---------------------------------------------------------------------------*/

template <>
real32_t (*BMath<real32_t>::cos)(const real32_t) = bmath_cosf;

template <>
real64_t (*BMath<real64_t>::cos)(const real64_t) = bmath_cosd;

template <>
real32_t (*BMath<real32_t>::sin)(const real32_t) = bmath_sinf;

template <>
real64_t (*BMath<real64_t>::sin)(const real64_t) = bmath_sind;

template <>
real32_t (*BMath<real32_t>::tan)(const real32_t) = bmath_tanf;

template <>
real64_t (*BMath<real64_t>::tan)(const real64_t) = bmath_tand;

template <>
real32_t (*BMath<real32_t>::acos)(const real32_t) = bmath_acosf;

template <>
real64_t (*BMath<real64_t>::acos)(const real64_t) = bmath_acosd;

template <>
real32_t (*BMath<real32_t>::asin)(const real32_t) = bmath_asinf;

template <>
real64_t (*BMath<real64_t>::asin)(const real64_t) = bmath_asind;

template <>
real32_t (*BMath<real32_t>::atan2)(const real32_t, const real32_t) = bmath_atan2f;

template <>
real64_t (*BMath<real64_t>::atan2)(const real64_t, const real64_t) = bmath_atan2d;

template <>
real32_t (*BMath<real32_t>::norm_angle)(const real32_t) = bmath_norm_anglef;

template <>
real64_t (*BMath<real64_t>::norm_angle)(const real64_t) = bmath_norm_angled;

template <>
real32_t (*BMath<real32_t>::sqrt)(const real32_t) = bmath_sqrtf;

template <>
real64_t (*BMath<real64_t>::sqrt)(const real64_t) = bmath_sqrtd;

template <>
real32_t (*BMath<real32_t>::isqrt)(const real32_t) = bmath_isqrtf;

template <>
real64_t (*BMath<real64_t>::isqrt)(const real64_t) = bmath_isqrtd;

template <>
real32_t (*BMath<real32_t>::log)(const real32_t) = bmath_logf;

template <>
real64_t (*BMath<real64_t>::log)(const real64_t) = bmath_logd;

template <>
real32_t (*BMath<real32_t>::log10)(const real32_t) = bmath_log10f;

template <>
real64_t (*BMath<real64_t>::log10)(const real64_t) = bmath_log10d;

template <>
real32_t (*BMath<real32_t>::exp)(const real32_t) = bmath_expf;

template <>
real64_t (*BMath<real64_t>::exp)(const real64_t) = bmath_expd;

template <>
real32_t (*BMath<real32_t>::abs)(const real32_t) = bmath_absf;

template <>
real64_t (*BMath<real64_t>::abs)(const real64_t) = bmath_absd;

template <>
real32_t (*BMath<real32_t>::max)(const real32_t, const real32_t) = bmath_maxf;

template <>
real64_t (*BMath<real64_t>::max)(const real64_t, const real64_t) = bmath_maxd;

template <>
real32_t (*BMath<real32_t>::min)(const real32_t, const real32_t) = bmath_minf;

template <>
real64_t (*BMath<real64_t>::min)(const real64_t, const real64_t) = bmath_mind;

template <>
real32_t (*BMath<real32_t>::clamp)(const real32_t, const real32_t, const real32_t) = bmath_clampf;

template <>
real64_t (*BMath<real64_t>::clamp)(const real64_t, const real64_t, const real64_t) = bmath_clampd;

template <>
real32_t (*BMath<real32_t>::mod)(const real32_t, const real32_t) = bmath_modf;

template <>
real64_t (*BMath<real64_t>::mod)(const real64_t, const real64_t) = bmath_modd;

template <>
real32_t (*BMath<real32_t>::modf)(const real32_t, real32_t *) = bmath_modff;

template <>
real64_t (*BMath<real64_t>::modf)(const real64_t, real64_t *) = bmath_modfd;

template <>
uint32_t (*BMath<real32_t>::prec)(const real32_t) = bmath_precf;

template <>
uint32_t (*BMath<real64_t>::prec)(const real64_t) = bmath_precd;

template <>
real32_t (*BMath<real32_t>::round)(const real32_t) = bmath_roundf;

template <>
real64_t (*BMath<real64_t>::round)(const real64_t) = bmath_roundd;

template <>
real32_t (*BMath<real32_t>::round_step)(const real32_t, const real32_t) = bmath_round_stepf;

template <>
real64_t (*BMath<real64_t>::round_step)(const real64_t, const real64_t) = bmath_round_stepd;

template <>
real32_t (*BMath<real32_t>::floor)(const real32_t) = bmath_floorf;

template <>
real64_t (*BMath<real64_t>::floor)(const real64_t) = bmath_floord;

template <>
real32_t (*BMath<real32_t>::ceil)(const real32_t) = bmath_ceilf;

template <>
real64_t (*BMath<real64_t>::ceil)(const real64_t) = bmath_ceild;

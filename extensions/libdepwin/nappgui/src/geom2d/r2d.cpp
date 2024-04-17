/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: r2d.cpp
 *
 */

/* 2D rectangles */

#include "r2d.h"
#include "r2d.hpp"
#include <sewer/cassert.h>

/*---------------------------------------------------------------------------*/

R2Df r2df(const real32_t x, const real32_t y, const real32_t width, const real32_t height)
{
    R2Df rect;
    rect.pos.x = x;
    rect.pos.y = y;
    rect.size.width = width;
    rect.size.height = height;
    return rect;
}

/*---------------------------------------------------------------------------*/

R2Dd r2dd(const real64_t x, const real64_t y, const real64_t width, const real64_t height)
{
    R2Dd rect;
    rect.pos.x = x;
    rect.pos.y = y;
    rect.size.width = width;
    rect.size.height = height;
    return rect;
}

/*---------------------------------------------------------------------------*/

V2Df r2d_centerf(const R2Df *r2d)
{
    V2Df c;
    cassert_no_null(r2d);
    c.x = r2d->pos.x + r2d->size.width / 2;
    c.y = r2d->pos.y + r2d->size.height / 2;
    return c;
}

/*---------------------------------------------------------------------------*/

V2Dd r2d_centerd(const R2Dd *r2d)
{
    V2Dd c;
    cassert_no_null(r2d);
    c.x = r2d->pos.x + r2d->size.width / 2;
    c.y = r2d->pos.y + r2d->size.height / 2;
    return c;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static V2D<real> i_center(const R2D<real> *r2d)
{
    V2D<real> c;
    cassert_no_null(r2d);
    c.x = r2d->pos.x + r2d->size.width / 2;
    c.y = r2d->pos.y + r2d->size.height / 2;
    return c;
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_collide(const R2D<real> *r2d1, const R2D<real> *r2d2)
{
    cassert_no_null(r2d1);
    cassert_no_null(r2d2);

    if (r2d1->pos.x > r2d2->pos.x + r2d2->size.width)
        return FALSE;

    if (r2d2->pos.x > r2d1->pos.x + r2d1->size.width)
        return FALSE;

    if (r2d1->pos.y > r2d2->pos.y + r2d2->size.height)
        return FALSE;

    if (r2d2->pos.y > r2d1->pos.y + r2d1->size.height)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

bool_t r2d_collidef(const R2Df *r2d1, const R2Df *r2d2)
{
    return i_collide<real32_t>((const R2D<real32_t> *)r2d1, (const R2D<real32_t> *)r2d2);
}

/*---------------------------------------------------------------------------*/

bool_t r2d_collided(const R2Dd *r2d1, const R2Dd *r2d2)
{
    return i_collide<real64_t>((const R2D<real64_t> *)r2d1, (const R2D<real64_t> *)r2d2);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_contains(const R2D<real> *r2d, const real x, const real y)
{
    cassert_no_null(r2d);
    if (x < r2d->pos.x)
        return FALSE;

    if (x > r2d->pos.x + r2d->size.width)
        return FALSE;

    if (y < r2d->pos.y)
        return FALSE;

    if (y > r2d->pos.y + r2d->size.height)
        return FALSE;

    return TRUE;
}

/*---------------------------------------------------------------------------*/

bool_t r2d_containsf(const R2Df *r2d, const real32_t x, const real32_t y)
{
    return i_contains<real32_t>((const R2D<real32_t> *)r2d, x, y);
}

/*---------------------------------------------------------------------------*/

bool_t r2d_containsd(const R2Dd *r2d, const real64_t x, const real64_t y)
{
    return i_contains<real64_t>((const R2D<real64_t> *)r2d, x, y);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static bool_t i_clip(const R2D<real> *viewport, const R2D<real> *r2d)
{
    register real x, y;
    cassert_no_null(viewport);
    cassert_no_null(r2d);

    x = r2d->pos.x - viewport->pos.x;
    if (x + r2d->size.width < 0)
        return TRUE;
    if (x > viewport->size.width)
        return TRUE;

    y = r2d->pos.y - viewport->pos.y;
    if (y + r2d->size.height < 0)
        return TRUE;
    if (y > viewport->size.height)
        return TRUE;

    return FALSE;
}

/*---------------------------------------------------------------------------*/

bool_t r2d_clipf(const R2Df *viewport, const R2Df *r2d)
{
    return i_clip<real32_t>((const R2D<real32_t> *)viewport, (const R2D<real32_t> *)r2d);
}

/*---------------------------------------------------------------------------*/

bool_t r2d_clipd(const R2Dd *viewport, const R2Dd *r2d)
{
    return i_clip<real64_t>((const R2D<real64_t> *)viewport, (const R2D<real64_t> *)r2d);
}

/*---------------------------------------------------------------------------*/

template <typename real>
static void i_join(R2D<real> *r2d, const R2D<real> *src)
{
    register real minX0, minY0, minX1, minY1;
    register real maxX0, maxY0, maxX1, maxY1;
    register real minX, minY, maxX, maxY;
    cassert_no_null(r2d);
    cassert_no_null(src);
    minX0 = r2d->pos.x;
    minY0 = r2d->pos.y;
    minX1 = src->pos.x;
    minY1 = src->pos.y;
    maxX0 = r2d->pos.x + r2d->size.width;
    maxY0 = r2d->pos.y + r2d->size.height;
    maxX1 = src->pos.x + src->size.width;
    maxY1 = src->pos.y + src->size.height;
    minX = minX0 < minX1 ? minX0 : minX1;
    minY = minY0 < minY1 ? minY0 : minY1;
    maxX = maxX0 > maxX1 ? maxX0 : maxX1;
    maxY = maxY0 > maxY1 ? maxY0 : maxY1;
    r2d->pos.x = minX;
    r2d->pos.y = minY;
    r2d->size.width = maxX - minX;
    r2d->size.height = maxY - minY;
}

/*---------------------------------------------------------------------------*/

void r2d_joinf(R2Df *r2d, const R2Df *src)
{
    i_join<real32_t>((R2D<real32_t> *)r2d, (const R2D<real32_t> *)src);
}

/*---------------------------------------------------------------------------*/

void r2d_joind(R2Dd *r2d, const R2Dd *src)
{
    i_join<real64_t>((R2D<real64_t> *)r2d, (const R2D<real64_t> *)src);
}

/*---------------------------------------------------------------------------*/

const R2Df kR2D_ZEROf = {{0, 0}, {0, 0}};
const R2Dd kR2D_ZEROd = {{0, 0}, {0, 0}};

template <>
const R2D<real32_t>(*R2D<real32_t>::kZERO) = ((R2D<real32_t> *)&kR2D_ZEROf);

template <>
const R2D<real64_t>(*R2D<real64_t>::kZERO) = ((R2D<real64_t> *)&kR2D_ZEROd);

template <>
V2D<real32_t> (*R2D<real32_t>::center)(const R2D<real32_t> *) = i_center<real32_t>;

template <>
V2D<real64_t> (*R2D<real64_t>::center)(const R2D<real64_t> *) = i_center<real64_t>;

template <>
bool_t (*R2D<real32_t>::collide)(const R2D<real32_t> *, const R2D<real32_t> *) = i_collide<real32_t>;

template <>
bool_t (*R2D<real64_t>::collide)(const R2D<real64_t> *, const R2D<real64_t> *) = i_collide<real64_t>;

template <>
bool_t (*R2D<real32_t>::contains)(const R2D<real32_t> *, const real32_t, const real32_t) = i_contains<real32_t>;

template <>
bool_t (*R2D<real64_t>::contains)(const R2D<real64_t> *, const real64_t, const real64_t) = i_contains<real64_t>;

template <>
bool_t (*R2D<real32_t>::clip)(const R2D<real32_t> *, const R2D<real32_t> *) = i_clip<real32_t>;

template <>
bool_t (*R2D<real64_t>::clip)(const R2D<real64_t> *, const R2D<real64_t> *) = i_clip<real64_t>;

template <>
void (*R2D<real32_t>::join)(R2D<real32_t> *, const R2D<real32_t> *) = i_join<real32_t>;

template <>
void (*R2D<real64_t>::join)(R2D<real64_t> *, const R2D<real64_t> *) = i_join<real64_t>;

//bool_t rect2d_point_insidei(const Rect2Di *rect2d, const V2Di *point2d, V2Di *local_point2d_opc);
//
//bool_t rect2d_is_inside_containerf(const Rect2Df *rect, const Rect2Df *container);
//
//bool_t rect2d_is_inside_containeri(const Rect2Di *rect, const Rect2Di *container);
//
//bool_t rect2d_is_inside_sizei(const Rect2Di *rect, const S2Di *container_size);
//
//bool_t rect2d_is_zerof(const Rect2Df *rect);
//
//bool_t rect2d_is_zeroi(const Rect2Di *rect);
//
//bool_t rect2d_overlapsf(const Rect2Df *rect1, const Rect2Df *rect2);
//
//void rect2d_real_from_relativef(const Rect2Df *relative_frame, const S2Df *container_size, Rect2Df *real_frame);
//
//void rect2d_real_from_relativei(const Rect2Df *relative_frame, const S2Di *container_size, Rect2Di *real_frame);
//
//void rect2d_scale_factorf(const Rect2Df *rect2d_reference, const Rect2Df *rect2d_other, V2Df *scale);
//
///*void rect2d_linear_interpolationi(Rect2Di *dest, const Rect2Di *start, const Rect2Di *end, const real32_t time);*/
//
///*---------------------------------------------------------------------------*/
//
//bool_t rect2d_point_insidei(const Rect2Di *rect2d, const V2Di *point2d, V2Di *local_point2d_opc)
//{
//    cassert_no_null(rect2d);
//    cassert_no_null(point2d);
//
//    if (point2d->x < rect2d->origin.x)
//        return FALSE;
//
//    if (point2d->x >= rect2d->origin.x + rect2d->size.width)
//        return FALSE;
//
//    if (point2d->y < rect2d->origin.y)
//        return FALSE;
//
//    if (point2d->y >= rect2d->origin.y + rect2d->size.height)
//        return FALSE;
//
//    if (local_point2d_opc != NULL)
//    {
//        local_point2d_opc->x = point2d->x - rect2d->origin.x;
//        local_point2d_opc->y = point2d->y - rect2d->origin.y;
//    }
//
//    return TRUE;
//}
//
///*---------------------------------------------------------------------------*/
//
//bool_t rect2d_is_inside_containerf(const Rect2Df *rect, const Rect2Df *container)
//{
//    cassert_no_null(rect);
//    cassert_no_null(container);
//
//    if (container->origin.x > rect->origin.x)
//        return FALSE;
//
//    if (container->origin.y > rect->origin.y)
//        return FALSE;
//
//    if (container->origin.x + container->size.width < rect->origin.x + rect->size.width)
//        return FALSE;
//
//    if (container->origin.y + container->size.height < rect->origin.y + rect->size.height)
//        return FALSE;
//
//    return TRUE;
//}
//
///*---------------------------------------------------------------------------*/
//
//bool_t rect2d_is_inside_containeri(const Rect2Di *rect, const Rect2Di *container)
//{
//    cassert_no_null(rect);
//    cassert_no_null(container);
//
//    if (container->origin.x > rect->origin.x)
//        return FALSE;
//
//    if (container->origin.y > rect->origin.y)
//        return FALSE;
//
//    if (container->origin.x + container->size.width < rect->origin.x + rect->size.width)
//        return FALSE;
//
//    if (container->origin.y + container->size.height < rect->origin.y + rect->size.height)
//        return FALSE;
//
//    return TRUE;
//}
//
///*---------------------------------------------------------------------------*/
//
//bool_t rect2d_is_inside_sizei(const Rect2Di *rect, const S2Di *container_size)
//{
//    cassert_no_null(rect);
//    cassert_no_null(container_size);
//
//    if (container_size->width < rect->origin.x + rect->size.width)
//        return FALSE;
//
//    if (container_size->height < rect->origin.y + rect->size.height)
//        return FALSE;
//
//    return TRUE;
//}
//
///*---------------------------------------------------------------------------*/
//
//bool_t rect2d_is_zerof(const Rect2Df *rect)
//{
//    cassert_no_null(rect);
//    if (rect->size.width == 0.f || rect->size.height == 0.f)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///*---------------------------------------------------------------------------*/
//
//bool_t rect2d_is_zeroi(const Rect2Di *rect)
//{
//    cassert_no_null(rect);
//    if (rect->origin.x == 0 && rect->origin.y == 0 && rect->size.width == 0 && rect->size.height == 0)
//        return TRUE;
//    else
//        return FALSE;
//}
//
///*---------------------------------------------------------------------------*/
//
//#define i_MAX(x,y) ((x) > (y)) ? (x) : (y)
//#define i_MIN(x,y) ((x) < (y)) ? (x) : (y)
//bool_t rect2d_overlapsf(const Rect2Df *rect1, const Rect2Df *rect2)
//{
//    real32_t x0, x1;
//    cassert_no_null(rect1);
//    cassert_no_null(rect2);
//
//    x0 = i_MAX(rect1->origin.x, rect2->origin.x);
//    x1 = i_MIN(rect1->origin.x + rect1->size.width, rect2->origin.x + rect2->size.width);
//    if (x0 > x1)
//        return FALSE;
//
//    x0 = i_MAX(rect1->origin.y, rect2->origin.y);
//    x1 = i_MIN(rect1->origin.y + rect1->size.height, rect2->origin.y + rect2->size.height);
//    if (x0 > x1)
//        return FALSE;
//
//    return TRUE;
//}
//
///*---------------------------------------------------------------------------*/
//
//void rect2d_real_from_relativef(const Rect2Df *relative_frame, const S2Df *container_size, Rect2Df *real_frame)
//{
//    cassert_no_null(real_frame);
//    cassert_no_null(container_size);
//    cassert_no_null(relative_frame);
//
//    real_frame->origin.x = container_size->width * relative_frame->origin.x;
//    real_frame->origin.y = container_size->height * relative_frame->origin.y;
//    real_frame->size.width = container_size->width * relative_frame->size.width;
//    real_frame->size.height = container_size->height * relative_frame->size.height;
//}
//
///*---------------------------------------------------------------------------*/
//
//void rect2d_real_from_relativei(const Rect2Df *relative_frame, const S2Di *container_size, Rect2Di *real_frame)
//{
//    cassert_no_null(real_frame);
//    cassert_no_null(container_size);
//    cassert_no_null(relative_frame);
//    real_frame->origin.x = (uint32_t)((real32_t)container_size->width * relative_frame->origin.x + kONE_OVER_TWOf);
//    real_frame->origin.y = (uint32_t)((real32_t)container_size->height * relative_frame->origin.y + kONE_OVER_TWOf);
//    real_frame->size.width = (uint32_t)((real32_t)container_size->width * relative_frame->size.width + kONE_OVER_TWOf);
//    real_frame->size.height = (uint32_t)((real32_t)container_size->height * relative_frame->size.height + kONE_OVER_TWOf);
//}
//
///*---------------------------------------------------------------------------*/
//
//void rect2d_scale_factorf(const Rect2Df *rect2d_reference, const Rect2Df *rect2d_other, V2Df *scale)
//{
//    cassert_no_null(rect2d_reference);
//    cassert_no_null(rect2d_other);
//    cassert_no_null(scale);
//    cassert_check(rect2d_reference->size.width > k0f);
//    cassert_check(rect2d_reference->size.height > k0f);
//    scale->x = rect2d_other->size.width / rect2d_reference->size.width;
//    scale->y = rect2d_other->size.height / rect2d_reference->size.height;
//}
//
///*---------------------------------------------------------------------------*/
//
///*
//void rect2d_linear_interpolationi(Rect2Di *dest, const Rect2Di *start, const Rect2Di *end, const real32_t time)
//{
//    cassert_no_null(dest);
//    cassert_no_null(start);
//    cassert_no_null(end);
//
//    if (__FALSE_EXPECTED(time == 0.f))
//    {
//        *dest = *start;
//    }
//    else if (__FALSE_EXPECTED(time == 1.f))
//    {
//        *dest = *end;
//    }
//    else
//    {
//        if (__TRUE_EXPECTED(start->origin.x != end->origin.x))
//            dest->origin.x = fmath_round_real32_to_uint32((real32_t)start->origin.x + (real32_t)(end->origin.x - start->origin.x) * time);
//        else
//            dest->origin.x = start->origin.x;
//
//        if (__TRUE_EXPECTED(start->origin.y != end->origin.y))
//            dest->origin.y = fmath_round_real32_to_uint32((real32_t)start->origin.y + (real32_t)(end->origin.y - start->origin.y) * time);
//        else
//            dest->origin.y = start->origin.y;
//
//        if (__TRUE_EXPECTED(start->size.width != end->size.width))
//            dest->size.width = fmath_round_real32_to_uint32((real32_t)start->size.width + (real32_t)((uint32_t)end->size.width - (uint32_t)start->size.width) * time);
//        else
//            dest->size.width = start->size.width;
//
//        if (__TRUE_EXPECTED(start->size.height != end->size.height))
//            dest->size.height = fmath_round_real32_to_uint32((real32_t)start->size.height + (real32_t)((uint32_t)end->size.height - (uint32_t)start->size.height) * time);
//        else
//            dest->size.height = start->size.height;
//    }
//}
//*/
//
///*---------------------------------------------------------------------------*/

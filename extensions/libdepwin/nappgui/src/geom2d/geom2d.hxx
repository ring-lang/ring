/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: geom2d.hxx
 * https://nappgui.com/en/geom2d/geom2d.html
 *
 */

/* 2d geometry */

#ifndef __GEOM2D_HXX__
#define __GEOM2D_HXX__

#include <core/core.hxx>
#include "geom2d.def"

typedef struct _v2df_t V2Df;
typedef struct _v2dd_t V2Dd;
typedef struct _s2df_t S2Df;
typedef struct _s2dd_t S2Dd;
typedef struct _r2df_t R2Df;
typedef struct _r2dd_t R2Dd;
typedef struct _t2df_t T2Df;
typedef struct _t2dd_t T2Dd;
typedef struct _seg2df_t Seg2Df;
typedef struct _seg2dd_t Seg2Dd;
typedef struct _cir2df_t Cir2Df;
typedef struct _cir2dd_t Cir2Dd;
typedef struct _box2df_t Box2Df;
typedef struct _box2dd_t Box2Dd;
typedef struct _obb2df_t OBB2Df;
typedef struct _obb2dd_t OBB2Dd;
typedef struct _tri2df_t Tri2Df;
typedef struct _tri2dd_t Tri2Dd;
typedef struct _pol2df_t Pol2Df;
typedef struct _pol2dd_t Pol2Dd;
typedef struct _col2df_t Col2Df;
typedef struct _col2dd_t Col2Dd;

struct _v2df_t
{
    real32_t x;
    real32_t y;
};

struct _v2dd_t
{
    real64_t x;
    real64_t y;
};

struct _s2df_t
{
    real32_t width;
    real32_t height;
};

struct _s2dd_t
{
    real64_t width;
    real64_t height;
};

struct _r2df_t
{
    V2Df pos;
    S2Df size;
};

struct _r2dd_t
{
    V2Dd pos;
    S2Dd size;
};

struct _t2df_t
{
    V2Df i;
    V2Df j;
    V2Df p;
};

struct _t2dd_t
{
    V2Dd i;
    V2Dd j;
    V2Dd p;
};

struct _seg2df_t
{
    V2Df p0;
    V2Df p1;
};

struct _seg2dd_t
{
    V2Dd p0;
    V2Dd p1;
};

struct _cir2df_t
{
    V2Df c;
    real32_t r;
};

struct _cir2dd_t
{
    V2Dd c;
    real64_t r;
};

struct _box2df_t
{
    V2Df min;
    V2Df max;
};

struct _box2dd_t
{
    V2Dd min;
    V2Dd max;
};

struct _tri2df_t
{
    V2Df p0;
    V2Df p1;
    V2Df p2;
};

struct _tri2dd_t
{
    V2Dd p0;
    V2Dd p1;
    V2Dd p2;
};

struct _col2df_t
{
    V2Df p;
    V2Df n;
    real32_t d;
};

struct _col2dd_t
{
    V2Dd p;
    V2Dd n;
    real64_t d;
};

DeclSt(V2Df);
DeclSt(V2Dd);
DeclSt(S2Df);
DeclSt(S2Dd);
DeclSt(R2Df);
DeclSt(R2Dd);
DeclSt(T2Df);
DeclSt(T2Dd);
DeclSt(Seg2Df);
DeclSt(Seg2Dd);
DeclSt(Cir2Df);
DeclSt(Cir2Dd);
DeclSt(Box2Df);
DeclSt(Box2Dd);
DeclSt(Tri2Df);
DeclSt(Tri2Dd);
DeclPt(Pol2Df);
DeclPt(Pol2Dd);
DeclSt(Col2Df);
DeclSt(Col2Dd);

#endif

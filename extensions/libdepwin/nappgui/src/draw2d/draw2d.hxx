/*
 * NAppGUI Cross-platform C SDK
 * 2015-2024 Francisco Garcia Collado
 * MIT Licence
 * https://nappgui.com/en/legal/license.html
 *
 * File: draw2d.hxx
 * https://nappgui.com/en/draw2d/draw2d.html
 *
 */

/* Operating system 2D drawing support */

#ifndef __DRAW2D_HXX__
#define __DRAW2D_HXX__

#include <geom2d/geom2d.hxx>
#include "draw2d.def"

typedef enum _pixformat_t
{
    ekINDEX1,
    ekINDEX2,
    ekINDEX4,
    ekINDEX8,
    ekGRAY8,
    ekRGB24,
    ekRGBA32,

    ekFIMAGE
} pixformat_t;

typedef enum _codec_t
{
    ekJPG = 1,
    ekPNG,
    ekBMP,
    ekGIF
} codec_t;

typedef enum _fstyle_t
{
    ekFNORMAL = 0,
    ekFBOLD = 1,
    ekFITALIC = 2,
    ekFSTRIKEOUT = 4,
    ekFUNDERLINE = 8,
    ekFSUBSCRIPT = 16,
    ekFSUPSCRIPT = 32,

    ekFPIXELS = 0,
    ekFPOINTS = 64
} fstyle_t;

typedef enum _linecap_t
{
    ekLCFLAT,
    ekLCSQUARE,
    ekLCROUND
} linecap_t;

typedef enum _linejoin_t
{
    ekLJMITER,
    ekLJROUND,
    ekLJBEVEL
} linejoin_t;

typedef enum _fillwrap_t
{
    ekFCLAMP,
    ekFTILE,
    ekFFLIP
} fillwrap_t;

typedef enum _drawop_t
{
    ekSTROKE = 1,
    ekFILL,
    ekSKFILL,
    ekFILLSK
} drawop_t;

typedef enum _align_t
{
    ekLEFT = 1,
    ekTOP = 1,
    ekCENTER = 2,
    ekRIGHT = 3,
    ekBOTTOM = 3,
    ekJUSTIFY = 4
} align_t;

typedef enum _ellipsis_t
{
    ekELLIPNONE = 1,
    ekELLIPBEGIN,
    ekELLIPMIDDLE,
    ekELLIPEND,
    ekELLIPMLINE
} ellipsis_t;

typedef enum _indicator_t
{
    ekINDNONE = 0,
    ekINDUP_ARROW,
    ekINDDOWN_ARROW
} indicator_t;

typedef uint32_t color_t;
typedef struct _dctx_t DCtx;
typedef struct _palette_t Palette;
typedef struct _pixbuf_t Pixbuf;
typedef struct _image_t Image;
typedef struct _font_t Font;
DeclSt(color_t);
DeclPt(Image);

#endif

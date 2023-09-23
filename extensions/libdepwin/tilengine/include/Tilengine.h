/*
* Tilengine - The 2D retro graphics engine with raster effects
* Copyright (C) 2015-2019 Marc Palacios Domenech <mailto:megamarc@hotmail.com>
* All rights reserved
*
* This Source Code Form is subject to the terms of the Mozilla Public
* License, v. 2.0. If a copy of the MPL was not distributed with this
* file, You can obtain one at http://mozilla.org/MPL/2.0/.
* */

#ifndef _TILENGINE_H
#define _TILENGINE_H

/**
 * \defgroup types
 * \brief Common data types
 * @{ */

/* Tilengine shared */
#if defined _MSC_VER
	#ifdef LIB_EXPORTS
		#define TLNAPI __declspec(dllexport)
	#else
		#define TLNAPI __declspec(dllimport)
	#endif
	
	#pragma warning(disable : 4200)

	#if _MSC_VER >= 1600	/* Visual C++ 2010? */
		#include <stdint.h>
	#else
		typedef char			int8_t;		/*!< signed 8-bit wide data */
		typedef short			int16_t;	/*!< signed 16-bit wide data */
		typedef int				int32_t;	/*!< signed 32-bit wide data */
		typedef unsigned char	uint8_t;	/*!< unsigned 8-bit wide data */
		typedef unsigned short	uint16_t;	/*!< unsigned 16-bit wide data */
		typedef unsigned int	uint32_t;	/*!< unsigned 32-bit wide data */
	#endif

	#if _MSC_VER >= 1800	/* Visual C++ 2013? */
		#include <stdbool.h>
	#else
		typedef unsigned char bool;		/*!< C++ bool type for C language */
		#define false	0
		#define true	1
	#endif

#else
	#ifdef LIB_EXPORTS
		#define TLNAPI __attribute__((visibility("default")))
	#else
		#define TLNAPI
	#endif
	#include <stdint.h>
	#include <stdbool.h>
#endif

#include <stdio.h>

/* version */
#define TILENGINE_VER_MAJ	2
#define TILENGINE_VER_MIN	8
#define TILENGINE_VER_REV	5
#define TILENGINE_HEADER_VERSION ((TILENGINE_VER_MAJ << 16) | (TILENGINE_VER_MIN << 8) | TILENGINE_VER_REV)

#define BITVAL(n) (1<<(n))

/*! tile/sprite flags. Can be none or a combination of the following: */
typedef enum
{
	FLAG_NONE		= 0,			/*!< no flags */
	FLAG_FLIPX		= BITVAL(15),	/*!< horizontal flip */
	FLAG_FLIPY		= BITVAL(14),	/*!< vertical flip */
	FLAG_ROTATE		= BITVAL(13),	/*!< row/column flip (unsupported, Tiled compatibility) */
	FLAG_PRIORITY	= BITVAL(12),	/*!< tile goes in front of sprite layer */
	FLAG_MASKED		= BITVAL(11),	/*!< sprite won't be drawn inside masked region */
}
TLN_TileFlags;

/*!
 * layer blend modes. Must be one of these and are mutually exclusive:
 */
typedef enum
{
	BLEND_NONE,		/*!< blending disabled */
	BLEND_MIX25,	/*!< color averaging 1 */
	BLEND_MIX50,	/*!< color averaging 2 */
	BLEND_MIX75,	/*!< color averaging 3 */
	BLEND_ADD,		/*!< color is always brighter (simulate light effects) */
	BLEND_SUB,		/*!< color is always darker (simulate shadow effects) */
	BLEND_MOD,		/*!< color is always darker (simulate shadow effects) */
	BLEND_CUSTOM,	/*!< user provided blend function with TLN_SetCustomBlendFunction() */
	MAX_BLEND,
	BLEND_MIX = BLEND_MIX50
}
TLN_Blend;

/*! Affine transformation parameters */
typedef struct
{
	float angle;	/*!< rotation in degrees */
	float dx;		/*!< horizontal translation */
	float dy;		/*!< vertical translation */
	float sx;		/*!< horizontal scaling */
	float sy;		/*!< vertical scaling */
}
TLN_Affine;

/*! Tile item for Tilemap access methods */
typedef union Tile
{
	uint32_t value;
	struct
	{
		uint16_t index;		/*!< tile index */
		uint16_t flags;		/*!< attributes (FLAG_FLIPX, FLAG_FLIPY, FLAG_PRIORITY) */
	};
}
Tile;

/*! frame animation definition */
typedef struct
{
	int index;		/*!< tile/sprite index */
	int delay;		/*!< time delay for next frame */
}
TLN_SequenceFrame;

/*! color strip definition */
typedef struct
{
	int delay;		/*!< time delay between frames */
	uint8_t first;	/*!< index of first color to cycle */
	uint8_t count;	/*!< number of colors in the cycle */
	uint8_t dir;	/*!< direction: 0=descending, 1=ascending */
}
TLN_ColorStrip;

/*! sequence info returned by TLN_GetSequenceInfo */
typedef struct
{
	char name[32];	/*!< sequence name */
	int num_frames;	/*!< number of frames */
}
TLN_SequenceInfo;

/*! Sprite creation info for TLN_CreateSpriteset() */
typedef struct
{
	char name[64];	/*!< entry name */
	int x;			/*!< horizontal position */
	int y;			/*!< vertical position */
	int w;			/*!< width */
	int h;			/*!< height */
}
TLN_SpriteData;

/*! Sprite information */
typedef struct
{
	int w;			/*!< width of sprite */
	int h;			/*!< height of sprite */
}
TLN_SpriteInfo;

/*! Tile information returned by TLN_GetLayerTile() */
typedef struct
{
	uint16_t index;	/*!< tile index */
	uint16_t flags;	/*!< attributes (FLAG_FLIPX, FLAG_FLIPY, FLAG_PRIORITY) */
	int row;		/*!< row number in the tilemap */
	int col;		/*!< col number in the tilemap */
	int xoffset;	/*!< horizontal position inside the title */
	int yoffset;	/*!< vertical position inside the title */
	uint8_t color;	/*!< color index at collision point */
	uint8_t type;	/*!< tile type */
	bool empty;		/*!< cell is empty*/
}
TLN_TileInfo;

/*! Object item info returned by TLN_GetObjectInfo() */
typedef struct
{
	uint16_t id;	/*!< unique ID */
	uint16_t gid;	/*!< graphic ID (tile index) */
	uint16_t flags;	/*!< attributes (FLAG_FLIPX, FLAG_FLIPY, FLAG_PRIORITY) */
	int x;			/*!< horizontal position */
	int y;			/*!< vertical position */
	int width;		/*!< horizontal size */
	int height;		/*!< vertical size */
	uint8_t type;	/*!< type property */
	bool visible;	/*!< visible property */
	char name[64];	/*!< name property */
}
TLN_ObjectInfo;

/*! Tileset attributes for TLN_CreateTileset() */
typedef struct
{
	uint8_t	type;		/*!< tile type */
	bool	priority;	/*!< priority flag set */
}
TLN_TileAttributes;

/*! overlays for CRT effect */
typedef enum
{
	TLN_OVERLAY_NONE,		/*!< no overlay */
	TLN_OVERLAY_SHADOWMASK,	/*!< Shadow mask pattern */
	TLN_OVERLAY_APERTURE,	/*!< Aperture grille pattern */
	TLN_OVERLAY_SCANLINES,	/*!< Scanlines pattern */
	TLN_OVERLAY_CUSTOM,		/*!< User-provided when calling TLN_CreateWindow() */
	TLN_MAX_OVERLAY
}
TLN_Overlay;

/*! pixel mapping for TLN_SetLayerPixelMapping() */
typedef struct
{
	int16_t dx;		/*! horizontal pixel displacement */
	int16_t dy;		/*! vertical pixel displacement */
}
TLN_PixelMap;

typedef struct Engine*		 TLN_Engine;			/*!< Engine context */
typedef union  Tile*		 TLN_Tile;				/*!< Tile reference */
typedef struct Tileset*		 TLN_Tileset;			/*!< Opaque tileset reference */
typedef struct Tilemap*		 TLN_Tilemap;			/*!< Opaque tilemap reference */
typedef struct Palette*		 TLN_Palette;			/*!< Opaque palette reference */
typedef struct Spriteset*	 TLN_Spriteset;			/*!< Opaque sspriteset reference */
typedef struct Sequence*	 TLN_Sequence;			/*!< Opaque sequence reference */
typedef struct SequencePack* TLN_SequencePack;		/*!< Opaque sequence pack reference */
typedef struct Bitmap*		 TLN_Bitmap;			/*!< Opaque bitmap reference */
typedef struct ObjectList*	 TLN_ObjectList;		/*!< Opaque object list reference */

/*! Image Tile items for TLN_CreateImageTileset() */
typedef struct
{
	TLN_Bitmap bitmap;
	uint16_t id;
	uint8_t	type;
}
TLN_TileImage;

/*! Sprite state */
typedef struct
{
	int x;						/*!< Screen position x */
	int y;						/*!< Screen position y */
	int w;						/*!< Actual width in screen (after scaling) */
	int h;						/*!< Actual height in screen (after scaling) */
	uint32_t flags;				/*!< flags */
	TLN_Palette palette;		/*!< assigned palette */	 
	TLN_Spriteset spriteset;	/*!< assigned spriteset */	
	int index;					/*!< graphic index inside spriteset */
	bool enabled;				/*!< enabled or not */
	bool collision;				/*!< per-pixel collision detection enabled or not */
}
TLN_SpriteState;

/* callbacks */
typedef union SDL_Event SDL_Event;
typedef void(*TLN_VideoCallback)(int scanline);
typedef uint8_t(*TLN_BlendFunction)(uint8_t src, uint8_t dst);
typedef void(*TLN_SDLCallback)(SDL_Event*);

/*! Player index for input assignment functions */
typedef enum
{
	PLAYER1,	/*!< Player 1 */
	PLAYER2,	/*!< Player 2 */
	PLAYER3,	/*!< Player 3 */
	PLAYER4,	/*!< Player 4 */
}
TLN_Player;

/*! Standard inputs query for TLN_GetInput() */
typedef enum
{
	INPUT_NONE,		/*!< no input */
	INPUT_UP,		/*!< up direction */
	INPUT_DOWN,		/*!< down direction */
	INPUT_LEFT,		/*!< left direction */
	INPUT_RIGHT,	/*!< right direction */
	INPUT_BUTTON1,	/*!< 1st action button */
	INPUT_BUTTON2,	/*!< 2nd action button */
	INPUT_BUTTON3,	/*!< 3th action button */
	INPUT_BUTTON4,	/*!< 4th action button */
	INPUT_BUTTON5,	/*!< 5th action button */
	INPUT_BUTTON6,	/*!< 6th action button */
	INPUT_START,	/*!< Start button */
	INPUT_QUIT,		/*!< Window close (only Player 1 keyboard) */
	INPUT_CRT,		/*!< CRT toggle (only Player 1 keyboard) */

	/* ... up to 32 unique inputs */

	INPUT_P1 = (PLAYER1 << 5), 	/*!< request player 1 input (default) */
	INPUT_P2 = (PLAYER2 << 5),	/*!< request player 2 input */
	INPUT_P3 = (PLAYER3 << 5),	/*!< request player 3 input */
	INPUT_P4 = (PLAYER4 << 5),	/*!< request player 4 input */

	/* compatibility symbols for pre-1.18 input model */
	INPUT_A = INPUT_BUTTON1,
	INPUT_B = INPUT_BUTTON2,
	INPUT_C = INPUT_BUTTON3,
	INPUT_D = INPUT_BUTTON4,
	INPUT_E = INPUT_BUTTON5,
	INPUT_F = INPUT_BUTTON6,
}
TLN_Input;

/*! CreateWindow flags. Can be none or a combination of the following: */
enum
{
	CWF_FULLSCREEN	= (1 << 0),	/*!< create a fullscreen window */
	CWF_VSYNC		= (1 << 1),	/*!< sync frame updates with vertical retrace */
	CWF_S1			= (1 << 2),	/*!< create a window the same size as the framebuffer */
	CWF_S2			= (2 << 2),	/*!< create a window 2x the size the framebuffer */
	CWF_S3			= (3 << 2),	/*!< create a window 3x the size the framebuffer */
	CWF_S4			= (4 << 2),	/*!< create a window 4x the size the framebuffer */
	CWF_S5			= (5 << 2),	/*!< create a window 5x the size the framebuffer */
	CWF_NEAREST		= (1 << 6),	/*<! unfiltered upscaling */
};

/*! Error codes */
typedef enum
{
	TLN_ERR_OK,				/*!< No error */
	TLN_ERR_OUT_OF_MEMORY,	/*!< Not enough memory */
	TLN_ERR_IDX_LAYER,		/*!< Layer index out of range */
	TLN_ERR_IDX_SPRITE,		/*!< Sprite index out of range */
	TLN_ERR_IDX_ANIMATION,	/*!< Animation index out of range */
	TLN_ERR_IDX_PICTURE,	/*!< Picture or tile index out of range */
	TLN_ERR_REF_TILESET,	/*!< Invalid TLN_Tileset reference */
	TLN_ERR_REF_TILEMAP,	/*!< Invalid TLN_Tilemap reference */
	TLN_ERR_REF_SPRITESET,	/*!< Invalid TLN_Spriteset reference */
	TLN_ERR_REF_PALETTE,	/*!< Invalid TLN_Palette reference */
	TLN_ERR_REF_SEQUENCE,	/*!< Invalid TLN_Sequence reference */
	TLN_ERR_REF_SEQPACK,	/*!< Invalid TLN_SequencePack reference */
	TLN_ERR_REF_BITMAP,		/*!< Invalid TLN_Bitmap reference */
	TLN_ERR_NULL_POINTER,	/*!< Null pointer as argument */
	TLN_ERR_FILE_NOT_FOUND,	/*!< Resource file not found */
	TLN_ERR_WRONG_FORMAT,	/*!< Resource file has invalid format */
	TLN_ERR_WRONG_SIZE,		/*!< A width or height parameter is invalid */
	TLN_ERR_UNSUPPORTED,	/*!< Unsupported function */
	TLN_ERR_REF_LIST,		/*!< Invalid TLN_ObjectList reference */
	TLN_MAX_ERR,
}
TLN_Error;

/*! Debug level */
typedef enum
{
	TLN_LOG_NONE,		/*!< Don't print anything (default) */
	TLN_LOG_ERRORS,		/*!< Print only runtime errors */
	TLN_LOG_VERBOSE,	/*!< Print everything */
}
TLN_LogLevel;

/**@}*/

#ifdef __cplusplus
extern "C"{
#endif

/**
 * \defgroup setup
 * \brief Basic setup and management
 * @{ */
TLNAPI TLN_Engine TLN_Init (int hres, int vres, int numlayers, int numsprites, int numanimations);
TLNAPI void TLN_Deinit (void);
TLNAPI bool TLN_DeleteContext (TLN_Engine context);
TLNAPI bool TLN_SetContext(TLN_Engine context);
TLNAPI TLN_Engine TLN_GetContext(void);
TLNAPI int TLN_GetWidth (void);
TLNAPI int TLN_GetHeight (void);
TLNAPI uint32_t TLN_GetNumObjects (void);
TLNAPI uint32_t TLN_GetUsedMemory (void);
TLNAPI uint32_t TLN_GetVersion (void);
TLNAPI int TLN_GetNumLayers (void);
TLNAPI int TLN_GetNumSprites (void);
TLNAPI void TLN_SetBGColor (uint8_t r, uint8_t g, uint8_t b);
TLNAPI bool TLN_SetBGColorFromTilemap (TLN_Tilemap tilemap);
TLNAPI void TLN_DisableBGColor (void);
TLNAPI bool TLN_SetBGBitmap (TLN_Bitmap bitmap);
TLNAPI bool TLN_SetBGPalette (TLN_Palette palette);
TLNAPI void TLN_SetRasterCallback (TLN_VideoCallback);
TLNAPI void TLN_SetFrameCallback (TLN_VideoCallback);
TLNAPI void TLN_SetRenderTarget (uint8_t* data, int pitch);
TLNAPI void TLN_UpdateFrame (int frame);
TLNAPI void TLN_SetLoadPath (const char* path);
TLNAPI void TLN_SetCustomBlendFunction (TLN_BlendFunction);
TLNAPI void TLN_SetLogLevel(TLN_LogLevel log_level);
TLNAPI bool TLN_OpenResourcePack(const char* filename, const char* key);
TLNAPI void TLN_CloseResourcePack(void);

/**@}*/

/**
 * \defgroup errors
 * \brief Basic setup and management
* @{ */
TLNAPI void TLN_SetLastError (TLN_Error error);
TLNAPI TLN_Error TLN_GetLastError (void);
TLNAPI const char *TLN_GetErrorString (TLN_Error error);
/**@}*/

/**
 * \defgroup windowing
 * \brief Built-in window and input management
* @{ */
TLNAPI bool TLN_CreateWindow (const char* overlay, int flags);
TLNAPI bool TLN_CreateWindowThread (const char* overlay, int flags);
TLNAPI void TLN_SetWindowTitle (const char* title);
TLNAPI bool TLN_ProcessWindow (void);
TLNAPI bool TLN_IsWindowActive (void);
TLNAPI bool TLN_GetInput (TLN_Input id);
TLNAPI void TLN_EnableInput (TLN_Player player, bool enable);
TLNAPI void TLN_AssignInputJoystick (TLN_Player player, int index);
TLNAPI void TLN_DefineInputKey (TLN_Player player, TLN_Input input, uint32_t keycode);
TLNAPI void TLN_DefineInputButton (TLN_Player player, TLN_Input input, uint8_t joybutton);
TLNAPI void TLN_DrawFrame (int frame);
TLNAPI void TLN_WaitRedraw (void);
TLNAPI void TLN_DeleteWindow (void);
TLNAPI void TLN_EnableBlur (bool mode);
TLNAPI void TLN_EnableCRTEffect (TLN_Overlay overlay, uint8_t overlay_factor, uint8_t threshold, uint8_t v0, uint8_t v1, uint8_t v2, uint8_t v3, bool blur, uint8_t glow_factor);
TLNAPI void TLN_DisableCRTEffect (void);
TLNAPI void TLN_SetSDLCallback(TLN_SDLCallback);
TLNAPI void TLN_Delay (uint32_t msecs);
TLNAPI uint32_t TLN_GetTicks (void);
TLNAPI int TLN_GetWindowWidth(void);
TLNAPI int TLN_GetWindowHeight(void);

/**@}*/

/**
 * \defgroup spriteset
 * \brief Spriteset resources management for sprites
* @{ */
TLNAPI TLN_Spriteset TLN_CreateSpriteset (TLN_Bitmap bitmap, TLN_SpriteData* data, int num_entries);
TLNAPI TLN_Spriteset TLN_LoadSpriteset (const char* name);
TLNAPI TLN_Spriteset TLN_CloneSpriteset (TLN_Spriteset src);
TLNAPI bool TLN_GetSpriteInfo (TLN_Spriteset spriteset, int entry, TLN_SpriteInfo* info);
TLNAPI TLN_Palette TLN_GetSpritesetPalette (TLN_Spriteset spriteset);
TLNAPI int TLN_FindSpritesetSprite (TLN_Spriteset spriteset, const char* name);
TLNAPI bool TLN_SetSpritesetData (TLN_Spriteset spriteset, int entry, TLN_SpriteData* data, void* pixels, int pitch);
TLNAPI bool TLN_DeleteSpriteset (TLN_Spriteset Spriteset);
/**@}*/

/**
 * \defgroup tileset
 * \brief Tileset resources management for background layers 
* @{ */
TLNAPI TLN_Tileset TLN_CreateTileset (int numtiles, int width, int height, TLN_Palette palette, TLN_SequencePack sp, TLN_TileAttributes* attributes);
TLNAPI TLN_Tileset TLN_CreateImageTileset(int numtiles, TLN_TileImage* images);
TLNAPI TLN_Tileset TLN_LoadTileset (const char* filename);
TLNAPI TLN_Tileset TLN_CloneTileset (TLN_Tileset src);
TLNAPI bool TLN_SetTilesetPixels (TLN_Tileset tileset, int entry, uint8_t* srcdata, int srcpitch);
TLNAPI int TLN_GetTileWidth (TLN_Tileset tileset);
TLNAPI int TLN_GetTileHeight (TLN_Tileset tileset);
TLNAPI int TLN_GetTilesetNumTiles(TLN_Tileset tileset);
TLNAPI TLN_Palette TLN_GetTilesetPalette (TLN_Tileset tileset);
TLNAPI TLN_SequencePack TLN_GetTilesetSequencePack (TLN_Tileset tileset);
TLNAPI bool TLN_DeleteTileset (TLN_Tileset tileset);
/**@}*/

/**
 * \defgroup tilemap
 * \brief Tilemap resources management for background layers 
* @{ */
TLNAPI TLN_Tilemap TLN_CreateTilemap (int rows, int cols, TLN_Tile tiles, uint32_t bgcolor, TLN_Tileset tileset);
TLNAPI TLN_Tilemap TLN_LoadTilemap (const char* filename, const char* layername);
TLNAPI TLN_Tilemap TLN_CloneTilemap (TLN_Tilemap src);
TLNAPI int TLN_GetTilemapRows (TLN_Tilemap tilemap);
TLNAPI int TLN_GetTilemapCols (TLN_Tilemap tilemap);
TLNAPI TLN_Tileset TLN_GetTilemapTileset (TLN_Tilemap tilemap);
TLNAPI bool TLN_GetTilemapTile (TLN_Tilemap tilemap, int row, int col, TLN_Tile tile);
TLNAPI bool TLN_SetTilemapTile (TLN_Tilemap tilemap, int row, int col, TLN_Tile tile);
TLNAPI bool TLN_CopyTiles (TLN_Tilemap src, int srcrow, int srccol, int rows, int cols, TLN_Tilemap dst, int dstrow, int dstcol);
TLNAPI bool TLN_DeleteTilemap (TLN_Tilemap tilemap);
/**@}*/

/**
 * \defgroup palette
 * \brief Color palette resources management for sprites and background layers
* @{ */
TLNAPI TLN_Palette TLN_CreatePalette (int entries);
TLNAPI TLN_Palette TLN_LoadPalette (const char* filename);
TLNAPI TLN_Palette TLN_ClonePalette (TLN_Palette src);
TLNAPI bool TLN_SetPaletteColor (TLN_Palette palette, int color, uint8_t r, uint8_t g, uint8_t b);
TLNAPI bool TLN_MixPalettes (TLN_Palette src1, TLN_Palette src2, TLN_Palette dst, uint8_t factor);
TLNAPI bool TLN_AddPaletteColor (TLN_Palette palette, uint8_t r, uint8_t g, uint8_t b, uint8_t start, uint8_t num);
TLNAPI bool TLN_SubPaletteColor (TLN_Palette palette, uint8_t r, uint8_t g, uint8_t b, uint8_t start, uint8_t num);
TLNAPI bool TLN_ModPaletteColor (TLN_Palette palette, uint8_t r, uint8_t g, uint8_t b, uint8_t start, uint8_t num);
TLNAPI uint8_t* TLN_GetPaletteData (TLN_Palette palette, int index);
TLNAPI bool TLN_DeletePalette (TLN_Palette palette);
/**@}*/

/**
 * \defgroup bitmap
 * \brief Bitmap management
* @{ */
TLNAPI TLN_Bitmap TLN_CreateBitmap (int width, int height, int bpp);
TLNAPI TLN_Bitmap TLN_LoadBitmap (const char* filename);
TLNAPI TLN_Bitmap TLN_CloneBitmap (TLN_Bitmap src);
TLNAPI uint8_t* TLN_GetBitmapPtr (TLN_Bitmap bitmap, int x, int y);
TLNAPI int TLN_GetBitmapWidth (TLN_Bitmap bitmap);
TLNAPI int TLN_GetBitmapHeight (TLN_Bitmap bitmap);
TLNAPI int TLN_GetBitmapDepth (TLN_Bitmap bitmap);
TLNAPI int TLN_GetBitmapPitch (TLN_Bitmap bitmap);
TLNAPI TLN_Palette TLN_GetBitmapPalette (TLN_Bitmap bitmap);
TLNAPI bool TLN_SetBitmapPalette (TLN_Bitmap bitmap, TLN_Palette palette);
TLNAPI bool TLN_DeleteBitmap (TLN_Bitmap bitmap);
/**@}*/

/**
 * \defgroup objects
 * \brief ObjectList resources management
 * @{ */
TLNAPI TLN_ObjectList TLN_CreateObjectList(void);
TLNAPI bool TLN_AddTileObjectToList(TLN_ObjectList list, uint16_t id, uint16_t gid, uint16_t flags, int x, int y);
TLNAPI TLN_ObjectList TLN_LoadObjectList(const char* filename, const char* layername);
TLNAPI TLN_ObjectList TLN_CloneObjectList(TLN_ObjectList src);
TLNAPI int TLN_GetListNumObjects(TLN_ObjectList list);
TLNAPI bool TLN_GetListObject(TLN_ObjectList list, TLN_ObjectInfo* info);
TLNAPI bool TLN_DeleteObjectList(TLN_ObjectList list);
/**@}*/

/**
 * \defgroup layer
 * \brief Background layers management
* @{ */
TLNAPI bool TLN_SetLayer (int nlayer, TLN_Tileset tileset, TLN_Tilemap tilemap);
TLNAPI bool TLN_SetLayerTilemap(int nlayer, TLN_Tilemap tilemap);
TLNAPI bool TLN_SetLayerBitmap(int nlayer, TLN_Bitmap bitmap);
TLNAPI bool TLN_SetLayerPalette (int nlayer, TLN_Palette palette);
TLNAPI bool TLN_SetLayerPosition (int nlayer, int hstart, int vstart);
TLNAPI bool TLN_SetLayerScaling (int nlayer, float xfactor, float yfactor);
TLNAPI bool TLN_SetLayerAffineTransform (int nlayer, TLN_Affine *affine);
TLNAPI bool TLN_SetLayerTransform (int layer, float angle, float dx, float dy, float sx, float sy);
TLNAPI bool TLN_SetLayerPixelMapping (int nlayer, TLN_PixelMap* table);
TLNAPI bool TLN_SetLayerBlendMode (int nlayer, TLN_Blend mode, uint8_t factor);
TLNAPI bool TLN_SetLayerColumnOffset (int nlayer, int* offset);
TLNAPI bool TLN_SetLayerClip (int nlayer, int x1, int y1, int x2, int y2);
TLNAPI bool TLN_DisableLayerClip (int nlayer);
TLNAPI bool TLN_SetLayerMosaic (int nlayer, int width, int height);
TLNAPI bool TLN_DisableLayerMosaic (int nlayer);
TLNAPI bool TLN_ResetLayerMode (int nlayer);
TLNAPI bool TLN_SetLayerObjects(int nlayer, TLN_ObjectList objects, TLN_Tileset tileset);
TLNAPI bool TLN_SetLayerPriority(int nlayer, bool enable);
TLNAPI bool TLN_SetLayerParent(int nlayer, int parent);
TLNAPI bool TLN_DisableLayerParent(int nlayer);
TLNAPI bool TLN_DisableLayer (int nlayer);
TLNAPI TLN_Palette TLN_GetLayerPalette (int nlayer);
TLNAPI bool TLN_GetLayerTile (int nlayer, int x, int y, TLN_TileInfo* info);
TLNAPI int  TLN_GetLayerWidth (int nlayer);
TLNAPI int  TLN_GetLayerHeight (int nlayer);

/**@}*/

/**
 * \defgroup sprite
 * \brief Sprites management
* @{ */
TLNAPI bool TLN_ConfigSprite (int nsprite, TLN_Spriteset spriteset, uint32_t flags);
TLNAPI bool TLN_SetSpriteSet (int nsprite, TLN_Spriteset spriteset);
TLNAPI bool TLN_SetSpriteFlags (int nsprite, uint32_t flags);
TLNAPI bool TLN_EnableSpriteFlag(int nsprite, uint32_t flag, bool enable);
TLNAPI bool TLN_SetSpritePosition (int nsprite, int x, int y);
TLNAPI bool TLN_SetSpritePicture (int nsprite, int entry);
TLNAPI bool TLN_SetSpritePalette (int nsprite, TLN_Palette palette);
TLNAPI bool TLN_SetSpriteBlendMode (int nsprite, TLN_Blend mode, uint8_t factor);
TLNAPI bool TLN_SetSpriteScaling (int nsprite, float sx, float sy);
TLNAPI bool TLN_ResetSpriteScaling (int nsprite);
//TLNAPI bool TLN_SetSpriteRotation (int nsprite, float angle);
//TLNAPI bool TLN_ResetSpriteRotation (int nsprite);
TLNAPI int  TLN_GetSpritePicture (int nsprite);
TLNAPI int  TLN_GetAvailableSprite (void);
TLNAPI bool TLN_EnableSpriteCollision (int nsprite, bool enable);
TLNAPI bool TLN_GetSpriteCollision (int nsprite);
TLNAPI bool TLN_GetSpriteState(int nsprite, TLN_SpriteState* state);
TLNAPI bool TLN_SetFirstSprite(int nsprite);
TLNAPI bool TLN_SetNextSprite(int nsprite, int next);
TLNAPI bool TLN_EnableSpriteMasking(int nsprite, bool enable);
TLNAPI void TLN_SetSpritesMaskRegion(int top_line, int bottom_line);
TLNAPI bool TLN_SetSpriteAnimation (int nsprite, TLN_Sequence sequence, int loop);
TLNAPI bool TLN_DisableSpriteAnimation(int nsprite);
TLNAPI bool TLN_DisableSprite (int nsprite);
TLNAPI TLN_Palette TLN_GetSpritePalette (int nsprite);
/**@}*/

/**
 * \defgroup sequence
 * \brief Sequence resources management for layer, sprite and palette animations
* @{ */
TLNAPI TLN_Sequence TLN_CreateSequence (const char* name, int target, int num_frames, TLN_SequenceFrame* frames);
TLNAPI TLN_Sequence TLN_CreateCycle (const char* name, int num_strips, TLN_ColorStrip* strips);
TLNAPI TLN_Sequence TLN_CreateSpriteSequence(const char* name, TLN_Spriteset spriteset, const char* basename, int delay);
TLNAPI TLN_Sequence TLN_CloneSequence (TLN_Sequence src);
TLNAPI bool TLN_GetSequenceInfo (TLN_Sequence sequence, TLN_SequenceInfo* info);
TLNAPI bool TLN_DeleteSequence (TLN_Sequence sequence);
/**@}*/

/**
 * \defgroup sequencepack
 * \brief Sequence pack manager for grouping and finding sequences
* @{ */
TLNAPI TLN_SequencePack TLN_CreateSequencePack (void);
TLNAPI TLN_SequencePack TLN_LoadSequencePack (const char* filename);
TLNAPI TLN_Sequence TLN_GetSequence (TLN_SequencePack sp, int index);
TLNAPI TLN_Sequence TLN_FindSequence (TLN_SequencePack sp, const char* name);
TLNAPI int TLN_GetSequencePackCount (TLN_SequencePack sp);
TLNAPI bool TLN_AddSequenceToPack (TLN_SequencePack sp, TLN_Sequence sequence);
TLNAPI bool TLN_DeleteSequencePack (TLN_SequencePack sp);
/**@}*/

/**
 * \defgroup animation
 * \brief Color cycle animation
* @{ */
TLNAPI bool TLN_SetPaletteAnimation (int index, TLN_Palette palette, TLN_Sequence sequence, bool blend);
TLNAPI bool TLN_SetPaletteAnimationSource (int index, TLN_Palette);
TLNAPI bool TLN_GetAnimationState (int index);
TLNAPI bool TLN_SetAnimationDelay (int index, int frame, int delay);
TLNAPI int  TLN_GetAvailableAnimation (void);
TLNAPI bool TLN_DisablePaletteAnimation(int index);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif

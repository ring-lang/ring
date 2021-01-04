# Tilengine changelog

## [2.8.4] - 12/5/2020
- Deprecates old TLN_SetLayer that required passing a NULL tileset, and replaces with new TLN_SetLayerTilemap that just requires the tilemap
- TLN_SetLoadPath() not needed anymore: chain loading of resources being loaded from subdirectories (.tsx -> .tmx -> png)
- TLN_DrawFrame(): frame parameter can be always 0, in that case it auto-increments internally. Application doesn't need to keep track of frames just to make the animation engine work. 
- Updates many samples to use current features, making them easier to follow

## [2.8.3] - 11/5/2020
- Changes tileset animation method: discards internal bitmap copy and backup of pixel data, and replaces by an intermediate LUT of indexes
- Removes TLN_CopyTile(), not needed anymore
- Tilemaps created procedurally are visible by default

## [2.8.2] - 9/5/2020
- Fixes bug where tileset animations weren't correctly played on layer index other than 0
- Enhanced TMX compatibility: 
  - handles "visible" property on layers and objects 
  - correctly loads "Rectangle" objects in addition to "Tile" ones
  - TLN_ObjectInfo returns standard TMX properties: "name", "type" (integer) and "visible"

## [2.8.0] - 3/5/2020
- Revamped animation engine. Slotted animations used only by palette (color cycle)
- Tileset sequences: a frame and the target tile can be the same
- Enhanced .tmx loader: more layers and shared tileset (.tsx) on several layers
- Updated ResourcePacker loader to collision-free hashes (get packer get at https://megamarc.itch.io/resourcepacker)
- Forest sample adds optional parameter to specify resource pack file and encryption password
- Window: fullscreen windows are desktop borderless instead of exclusive

## [2.7.0] - 26/4/2020
- Adds sprite linked list order: TLN_SetFirstSprite() and TLN_SetNextSprite()
- Adds sprite masking: TLN_EnableSpriteMasking() and TLN_SetSpritesMaskRegion()
- Removes parameter "count" in TLN_CreateSpriteSequence(), now gets detected from sprite names
- CRT effect: when disabled always uses nearest-neighbor interpolation
- Fixes compiler-induced optimization bugs in built-in window
- Samples: removes usage of old sqx files for sprite animation and replaces with TLN_CreateSpriteAnimation() (shooter, supermarioclone, forest)
- Fixes broken loading of txt-based spritesheets in 2.6.0

## [2.6.0] - 22/4/2020
- Supports .json array for spritesheet loader, compatible with Aseprite, Texturepacker, Piskel...
- Supports loading of 24/32 bpp pixel data on the fly. Note that bitmaps must have less than 255 unique colors

## [2.5.0] - 15/4/2020
- Adds support for Tiled editor image-based tilesets and objet layers
- ObjectList: Removes old TLN_AddSpriteToList(), TLN_GetObjectsInReigion() and TLN_Object struct
- ObjectList: Renames old TLN_AddObjectToList() to TLN_AddTileObjectToList()
- ObjectList: Adds TLN_GetListNumObjects(), TLN_GetListObject() and TLN_ObjectInfo struct
- Tileset: adds new function TLN_CreateImageTileset() and TLN_TileImage struct
- Fixes TLN_GetLayerTile() crashing when passing negative x
- Adds TLN_ERR_REF_LIST error value to signal bad TLN_ObjectList reference
- Updates sample "Forest" to showcase new image-based tileset and object list features

## [2.4.2] - 22/12/2019
- Fixes broken crt effect in x64, due to mismatched bool for uint8_t causing misalignment of indexed data. Updates windows binaries

## [2.4.1] - 19/11/2019
- Uses explicit casts on all functions returning generic void*, allows for more strict C++ compile-time checks but it's still full pure C compliant
- Sibling objects are destroyed by explicit TLN_DestroyXXX() destructor instead of improperly calling generic DeleteBaseObject() on siblings, causing memory leaks.
- Other fixes related to issue #53 (proper context destroy, xml parser fix...)
- TLN_SetLayerBitmap() checks for validity of palette before setting permission.

## [2.4.0] - 9/5/2019
- Adds object lists and layer objects for decorations: TLN_ObjectList and TLN_SetLayerObjects()
- Adds layer priority: TLN_SetLayerPriority()
- Adds layer parent for synchronized scroll in several layers: TLN_SetLayerParent()
- Adds creation of sequential name-based sprite animations: TLN_CreateSpriteSequence()
- Adds new example for illustrating the new features: "Forest"
- Removes unused assets
- Fixes some compilation warnings

## [2.3.0] - ]19/3/2019
- Supports resource packager with AES-128 encryption
- Adds TLN_OpenResourcePack() and TLN_CloseResourcePack() to bind a resource pack created with the `respack` tool: https://megamarc.itch.io/resourcepacker

## [2.2.1] - 17/3/2019
- Windowing: adds TLN_GetWindowWidth() and TLN_GetWindowHeight() to get actual size of created window, to properly scaling mouse coordinates when using SDL_callback.
- Sprite: adds TLN_GetSpriteState() function and TLN_SpriteState structure to query detailed runtime info about a given sprite (position, actual size, etc.)

## [2.2.0 MPL] - 18/2/2019
- Changes license to MPL 2.0. Allows linking as static library, compatible with licensing requirements of console devkits

## [2.1.2] 2/2/2019
- Window: expands unique inputs up to 32 per player
- Window: added two new standard inputs: INPUT_QUIT for closing the window, and INPUT_CRT for toggling the CRT effect. They're assigned to Escape and Backspace by default, but can be remapped with TLN_DefineInputKey()
- Library: prints version, CPU word size and build date to the standard output on TLN_Init()

## [2.1.0] - 16/8/2018
- Adds logging support to standard output with TLN_SetLogLevel() and TLN_LogLevel enum type. Defaults to none
- Internal changes to enable the logging feature. Object creation and type checking now concentrates much of the internal error handling
- Loaders destroy the used SimpleXmlParser instance, there was a memory leak
- Test.c now test for various runtime errors
- fixes segment violation in various linux builds

## [2.0.0 LGPL] - 4/7/2018
- Releases full source code under LGPL 2.1 license
- Adds context mechanism with TLN_Engine and associated companion functions to work with multiple instances of the engine using a global context. Backwards compatible with previous version
- Functionally equivalent to older 1.21 MIT-licensed version

## [1.21.1] - 19/5/2018
- Window title and CRT effect state is retained between fullscreen/windowed mode toggles.
- TLN_LoadBitmap() loader only loads 8 bpp png images and discards other formats with a "TLN_ERR_WRONG_FORMAT" error instead of crashing.
- TLN_LoadTileset() loader discards non-multiple of 8 pixel tiles with a "TLN_ERR_WRONG_SIZE" error.
- String texts are copied with bounded strncpy() instead of strcpy() to avoid possible buffer overflows.

## [1.21.0] - 18/5/2018
- Adds function TLN_SetSDLCallback() to register a user-provided function that gets called every time an event is generated in the underlying SDL2 layer. This function receives a pointer to a SDL_Event union. You must include SDL_event.h from your SDL2 sdk. This callback is very useful to bypass the built-in input handling in Tilengine, reacting to custom keys, gamepad, mouse, etc

## [1.20] - 15/5/2018
- Adds new background type: full bitmap layers. Enable with TLN_SetLayerBitmap()
- Provides binaries for Windows x86 and x64, other builds to come
- Updates Python and C# bindings

## [1.19] - 3/12/2017
- Spriteset: adds TLN_SetSpritesetData() to modify spriteset attributes and pixels at runtime.
- Window: adds CWF_NEAREST window flag to the TLN_WindowFlags enumeration for window creation. This flag upscales window with nearest-neighbor instead of default bilinear filter.
- Engine: adds TLN_SetFrameCallback() to get a user-provided function called when a frame is about to be drawn. Especially useful for multi-threaded window

## [1.18] - 23/11/2017
- Vastly improved user input: 6 action buttons, start button, up to four simultaneous players. Key bindings and joystick buttons can be redefined. Introduces TLN_EnableInput(), TLN_AssignInputJoystick(), TLN_DefineInputKey(), TLN_DefineInputButton() and new input names
- Sequences can be queried for info about name and number of frames. Introduces TLN_GetSequenceInfo() and associated TLN_SequenceInfo structure

## [1.17] - 9/11/2017
- Tilesets edited in Tiled editor support a new property: "priority". Setting it to "true", sets all occurrences of the tile in a tilemap with the priority flag, so they are rendered in front of regular sprites
- TLN_CreateTileset() functions takes an array of the new TLN_TileAttributes structure instead of the old array of integers that just accepted the tile type

## [1.16] - 5/10/2017
- Fixed TLN_LoadTilemap() when loading other layer than the first one in
a tmx with many layers
- Fixed TLN_GetSpriteInfo() that returned wrong sprite dimensions
- Sprite flag FLAG_PRIORITY implemented, so now objects can be placed in
four different "priority spaces

## [1.14] - 2/6/2017 7:28:23
- Loads Tileset from Tilemap and attaches a reference
- Loads background color attribute from Tilemap
- Loads SequencePack from Tileset with pattern animations and attaches a
reference
- Loads the type of tile in Tileset, via custom attribute: "type"
integer in range 0-255
- New struture SequenceFrame to build Sequence objects at runtime, with
delay per-frame
- Deleted old TLN_Cycle object, unified its functionality to Sequence
object
- Extended TLN_TileInfo struct with new members to tell the type of a
tile and if a given cell is empty
- Added TLN_SetLayerMap() function to setup a layer only with a Tilemap
reference, it extracts and loads the attached Tileset automatically
- Added TLN_SetBGColorFromTilemap() function to set the background color
from a given Tilemap
- Added new functions to retrieve the new associations between objects
(Tileset -> Tilemap -> SequencePack), the dimensions of a layer in
pixels, the number of sequences in a SequencePack, and to query the
contained sequences by an index

## [1.13] - 6/5/2017
- New user defined pixel mapping transform for layers:
TLN_SetLayerPixelMapping()
- Fixed "shooter" example that crashed when boss was going to appear in
64 bit builds

## [1.12] - 26/4/2017
- Improved overall performance, especially with big tilesets, solid
areas and blending
- Reworked blending: deprecated "factor" parameter, added custom
blending function callback BLEND_CUSTOM and TLN_SetCustomBlendFunction
- Added mosaic effect for layers: TLN_SetLayerMosaic()
- Added CRT post-processing effect: TLN_EnableCRTEffect()
- Added palette manipulation functions: TLN_AddPaletteColor(),
TLN_SubPaletteColor, TLN_ModPaletteColor()
- The "Benchmark" sample now uses a real tsx/tmx pair instead of just
random noise

## [1.11] - 13/4/2017
- Implemented background layer clipping to a given rectangle:
TLN_SetLayerClip() and TLN_DisableLayerClip()

## [1.10] - 28/12/2016
- New TLN_GetErrorString(): returns string description about an error
- New TLN_SetLoadPath(): Graphic assets can now be located in their own
directory
- New TLN_SetTilesetAnimation(): implemented tileset animation in the
animation engine
- New modulation blending mode: BLEND_MUL
- TLN_TileInfo struct has new member ::color that returns color index at
the given location, useful for implementing pixel accurate collision
detection between sprite and tilemap
- Improved spriteset loader: can now read CSV files compatible with
online Leshy Spriteset Tool:
https://www.leshylabs.com/blog/posts/2013-12-03-Leshy_SpriteSheet_Tool.html
- Improved tilemap loader: can now accept NULL as layer name to read
the first layer in a multilayer tmx file
- Added SuperMarioClone sample that shows many of the new features

## [1.7] - 15/2/2016
- New active rendering without callbacks. See TLN_BeginFrame,
TLN_DrawNextScanline, TLN_BeginWindowFrame, TLN_EndWindowFrame

## [1.6.5] - 29/1/2016
- Fixed samples source code to match 1.6.5 API version
- New function TLN_Delay () to pause execution
- Affine transformed layers can now be combined with blending modes
- Adds native x64 Windows build

## [1.6] - 13/1/2016
- Per-pixel sprite collision detection
- Added two new functions: TLN_EnableSpriteCollision() and
TLN_GetSpriteCollision() to check collisions at pixel level

## [1.5] - 9/1/2016
- Runtime error information
- Adds TLN_GetLastError() and TLN_Error enumeration to check error causes at runtime

## [1.4] - 6/9/2015
- First public release

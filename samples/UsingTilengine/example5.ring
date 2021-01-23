#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"

HRES = 424
VRES = 240

LAYER_PROPS_FRONT 	= 0
LAYER_FOREGROUND 	= 1
LAYER_PROPS 		= 2
LAYER_MIDDLEGROUND	= 3
LAYER_BACKGROUND	= 4
NUM_LAYERS		= 5

xworld = 0
oldx = -1

TLN_Init(HRES, VRES, NUM_LAYERS, 8, 0)

/* load assets */
TLN_SetLogLevel(TLN_LOG_ERRORS)
TLN_SetLoadPath("assets/forest")
foreground = TLN_LoadTilemap("map.tmx", "Main Layer")
middleground = TLN_LoadBitmap("middleground.png")
background = TLN_LoadBitmap("background.png")
atlas = TLN_LoadSpriteset("atlas.png")
props_list = TLN_LoadObjectList("map.tmx", NULL)

/* setup layers */
TLN_SetLayer(LAYER_FOREGROUND, NULL, foreground)
TLN_SetLayerBitmap(LAYER_MIDDLEGROUND, middleground)
TLN_SetLayerBitmap(LAYER_BACKGROUND, background)
width = TLN_GetLayerWidth(LAYER_FOREGROUND)
height = TLN_GetLayerHeight(LAYER_FOREGROUND)

/* objects layer: add back objects (behind sprites) */
TLN_SetLayerObjects(LAYER_PROPS, props_list, NULL)

/* sync props layer positions to main layer */
TLN_SetLayerParent(LAYER_PROPS_FRONT, LAYER_FOREGROUND)
TLN_SetLayerParent(LAYER_PROPS, LAYER_FOREGROUND)

/* create sprite sequences */
idle = TLN_CreateSpriteSequence(NULL, atlas, "player-idle/player-idle-", 6)
skip = TLN_CreateSpriteSequence(NULL, atlas, "player-skip/player-skip-", 6)

/* setup main player sprite */
xplayer = 48
yplayer = 144
TLN_ConfigSprite(0, atlas, 0)
TLN_SetSpriteAnimation(0, idle, 0)

/* create window & main loop */
TLN_CreateWindow(NULL, 0)
TLN_DisableCRTEffect()
while TLN_ProcessWindow()
	TLN_DrawFrame(0)

	/* move 3 pixels right/left main layer */
	if (TLN_GetInput(INPUT_LEFT) && xworld > 0)
		xworld -= 3
	elseif (TLN_GetInput(INPUT_RIGHT) && xworld < width - HRES)
		xworld += 3
	ok

	/* update on change */
	if xworld != oldx
		TLN_SetLayerPosition(LAYER_FOREGROUND, xworld, 32)
		TLN_SetLayerPosition(LAYER_MIDDLEGROUND, xworld / 2, 0)
		TLN_SetLayerPosition(LAYER_BACKGROUND, xworld / 3, 0)
		TLN_SetSpritePosition(0, xplayer - xworld, yplayer)
		oldx = xworld
	ok
end

/* release resources */
TLN_DeleteTilemap(foreground)
TLN_DeleteBitmap(middleground)
TLN_CloseResourcePack()
TLN_DeleteSpriteset(atlas)
TLN_DeleteObjectList(props_list)

TLN_DeleteWindow()
TLN_Deinit()

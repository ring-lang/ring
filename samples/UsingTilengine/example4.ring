#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"

WIDTH = 400
HEIGHT=	240

LAYER_FOREGROUND = 0
LAYER_BACKGROUND = 1
MAX_LAYER = 2


player_x = -16
player_y = 160

/* basic setup */
TLN_Init(WIDTH, HEIGHT, MAX_LAYER,1,0)
TLN_SetBGColor(0, 96, 184)

/* load resources */
TLN_SetLoadPath("assets/smw")
foreground = TLN_LoadTilemap("smw_foreground.tmx", NULL)
background = TLN_LoadTilemap("smw_background.tmx", NULL)
TLN_SetLayerTilemap(LAYER_FOREGROUND, foreground)
TLN_SetLayerTilemap(LAYER_BACKGROUND, background)
TLN_SetLayerPosition(LAYER_FOREGROUND, 0,48)
TLN_SetLayerPosition(LAYER_BACKGROUND, 0,80)

/* setup sprite */
spriteset = TLN_LoadSpriteset("smw_sprite")
TLN_SetSpriteSet(0, spriteset)
TLN_SetSpritePicture(0, 0)
TLN_SetSpritePosition(0, player_x, player_y)

/* setup animations */
seq_walking = TLN_CreateSpriteSequence(NULL, spriteset, "walking", 6)
TLN_SetSpriteAnimation(0, seq_walking, 0)

/* main loop */
TLN_CreateWindow(NULL, 0)
while TLN_ProcessWindow()
	player_x += 1
	if player_x >= WIDTH
		player_x = -16
	ok
	TLN_SetSpritePosition(0, player_x, player_y)
	TLN_DrawFrame(0)
end

/* deinit */
TLN_DeleteTilemap(foreground)
TLN_DeleteTilemap(background)
TLN_Deinit()

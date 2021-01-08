#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"

WIDTH  = 400
HEIGHT = 240

frame = 0

/* setup engine */
TLN_Init(WIDTH, HEIGHT, 1,0,0)

/* load layer */
tilemap = TLN_LoadTilemap("assets/sonic/Sonic_md_fg1.tmx", NULL)

/* setup the layer */
TLN_SetLayer(0, NULL, tilemap)
TLN_SetBGColor(32,32,128)

/* main loop */
TLN_CreateWindow(NULL, 0)
while TLN_ProcessWindow ()

	/* scroll the layer, one pixel per frame */
	TLN_SetLayerPosition (0, frame, 0)

	/* render to the window */
	TLN_DrawFrame (0)

	frame++
end

/* release resources */
TLN_DeleteTilemap(tilemap)
TLN_Deinit()

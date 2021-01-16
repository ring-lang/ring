#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"

WIDTH  = 400
HEIGHT = 240

sky = [
	[0x1D, 0x44, 0x7B],
	[0x7F, 0xA4, 0xD9],
	[0x0B, 0x00, 0x4E],
	[0xEB, 0x99, 0x9D]
]

sky_hi_r = 0
sky_hi_g = 0
sky_hi_b = 0
sky_lo_r = 0
sky_lo_g = 0
sky_lo_b = 0

frame = 0
xpos = 0
speed = 2
max_xpos = 4720

/* layers */
	LAYER_FOREGROUND = 0
	LAYER_BACKGROUND = 1
	MAX_LAYER = 2


/* entry point */
func main 

	/* setup engine */
		TLN_Init (WIDTH, HEIGHT, 2,1,0)
		TLN_SetBGColor (0,128,238)
		TLN_SetRasterCallback ("raster_callback()")

	/* load resources */
		TLN_SetLoadPath ("assets/sotb")
		foreground = TLN_LoadTilemap ("SOTB_fg.tmx", NULL)
		background = TLN_LoadTilemap ("SOTB_bg.tmx", NULL)
		TLN_SetLayerTilemap (LAYER_FOREGROUND, foreground)
		TLN_SetLayerTilemap (LAYER_BACKGROUND, background)

	spriteset = TLN_LoadSpriteset ("SOTB")
	walk = TLN_CreateSpriteSequence (NULL, spriteset, "walk", 6)

	TLN_SetSpriteSet (0, spriteset)
	TLN_SetSpritePosition (0, 200,160)
	TLN_SetSpriteAnimation (0, walk, 0)
	
	xpos = 2000

	sky_hi_r = sky[1][1]
	sky_hi_g = sky[1][2]
	sky_hi_b = sky[1][3]
	sky_lo_r = sky[2][1]
	sky_lo_g = sky[2][2]
	sky_lo_b = sky[2][3]

	/* main loop */
	TLN_CreateWindow (NULL, 0)
	while (TLN_ProcessWindow ())
	{
		if (xpos < max_xpos)
		{
			xpos += speed
			if (xpos >= max_xpos)
			{
				TLN_DisableSpriteAnimation (0)
				TLN_SetSpritePicture (0, 0)
			}
		}
			
		/* sky gradient */
		if (frame>=300 && frame<=900)
		{
			/* interpolate upper color */
			sky_hi_r = lerp (frame, 300,900, sky[1][1], sky[3][1])
			sky_hi_g = lerp (frame, 300,900, sky[1][2], sky[3][2])
			sky_hi_b = lerp (frame, 300,900, sky[1][3], sky[3][3])

			/* interpolate lower color */
			sky_lo_r = lerp (frame, 300,900, sky[2][1], sky[4][1])
			sky_lo_g = lerp (frame, 300,900, sky[2][2], sky[4][2])
			sky_lo_b = lerp (frame, 300,900, sky[2][3], sky[4][3])
		}

		TLN_SetLayerPosition (LAYER_FOREGROUND, xpos, 0)

		/* render to the window */
		TLN_DrawFrame (frame)
		frame++
	}

	/* release resources */
	TLN_DeleteSequence(walk)
	TLN_DeleteTilemap (foreground)
	TLN_DeleteTilemap (background)
	TLN_Deinit ()

func raster_callback

	line = TLN_GetScanLine()
	pos = 0

	/* sky color */
	if (line < 192)
	{
		//color = new RGB
		/* interpolate between upper and lower color */
		r = lerp (line, 0,191, sky_hi_r, sky_lo_r)
		g = lerp (line, 0,191, sky_hi_g, sky_lo_g)
		b = lerp (line, 0,191, sky_hi_b, sky_lo_b)
		TLN_SetBGColor (r, g ,b)
	}

	/* background layer */
	pos = -1
	if (line = 0 || line = 24 || line = 64 || line = 88 || line = 96)
		pos = lerp (line, 0,96, xpos*0.7 , xpos*0.2 )
	elseif (line = 120)
		pos = xpos/2
	elseif (line = 208 || line = 216 || line = 224 || line = 232)
		pos = lerp (line,208,232,xpos*1,xpos*2)
	ok

	if (pos != -1)
		TLN_SetLayerPosition (LAYER_BACKGROUND, pos, 0)
	ok

	/* foreground layer */
	pos = -1
	if (line = 0)
		pos = xpos
	elseif (line = 216)
		pos = xpos*3
	ok
	if (pos != -1)
		TLN_SetLayerPosition (LAYER_FOREGROUND, pos, 0)
	ok

func lerp x,x0,x1,fx0,fx1
	/* linear interploation */
	return (fx0 + (fx1-fx0)*(x-x0)/(x1-x0))

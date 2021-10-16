#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"

WIDTH	 = 400
HEIGHT = 240

sky = [
	[0x1B, 0x00, 0x8B],
	[0x00, 0x74, 0xD7],
	[0x24, 0x92, 0xDB],
	[0x1F, 0x7F, 0xBE]
]

/* layers */
LAYER_FOREGROUND = 0
LAYER_BACKGROUND = 1
MAX_LAYER = 2

pos_foreground = 0
pos_background = list(6)
inc_background = list(6)
speed = 0
ypos = 0

color = list(3)

/* entry point */
func main

	/* setup engine */
	TLN_Init (WIDTH,HEIGHT, MAX_LAYER, 0, 1)
	TLN_SetRasterCallback ("raster_callback()")
	TLN_SetBGColor (0,128,238)

	/* load resources*/
	TLN_SetLoadPath ("assets/sonic")
	foreground = TLN_LoadTilemap ("Sonic_md_fg1.tmx", NULL)
	background = TLN_LoadTilemap ("Sonic_md_bg1.tmx", NULL)
	TLN_SetLayerTilemap (LAYER_FOREGROUND, foreground)
	TLN_SetLayerTilemap (LAYER_BACKGROUND, background)
	sp = TLN_LoadSequencePack ("Sonic_md_seq.sqx")
	sequence = TLN_FindSequence (sp, "seq_water")

	/* assign color sequence to various entries in palette */
	palette = TLN_GetLayerPalette (LAYER_BACKGROUND)
	TLN_SetPaletteAnimation (TLN_GetAvailableAnimation(), palette, sequence, true)

	/* compute increments for variable background scrolling speeds */
	inc_background[1] = 0.562f
	inc_background[2] = 0.437f
	inc_background[3] = 0.375f
	inc_background[4] = 0.625f
	inc_background[5] = 1.0f
	inc_background[6] = 2.0f

	/* startup display */
	TLN_CreateWindow (NULL, 0)

	/* main loop */
	while TLN_ProcessWindow ()
		if TLN_GetInput (INPUT_RIGHT)
			speed += 0.02
			if speed > 1.0
				speed = 1.0f 
			ok
		elseif speed > 0.0
			speed -= 0.02
			if speed < 0.0
				speed = 0.0f
			ok
		ok
			 
		if TLN_GetInput (INPUT_LEFT)
			speed -= 0.02
			if speed < -1
				speed = -1
			ok
		elseif speed < 0
			speed += 0.02
			if speed > 0
				speed = 0
			ok
		ok

		/* scroll */
		pos_foreground += 3*speed
		TLN_SetLayerPosition (LAYER_FOREGROUND, pos_foreground, ypos)
		for c=1 to 6
			pos_background[c] += (inc_background[c] * speed)
		next
	
		/* render to window */
		TLN_DrawFrame (0)
	end

	/* deinit */
	TLN_DeleteTilemap (foreground)
	TLN_DeleteTilemap (background)
	TLN_DeleteSequencePack (sp)
	TLN_Deinit ()

/* raster callback (virtual HBLANK) */
func raster_callback 

	line = TLN_GetScanLine()
	pos =- 1
	
	if line=0
		pos = pos_background[1]
	elseif line=32
		pos = pos_background[2]
	elseif line=48
		pos = pos_background[3]
	elseif line=64
		pos = pos_background[4]
	elseif line=112
		pos = pos_background[5]
	elseif line >= 152
		pos = lerp (line, 152,224, pos_background[5], pos_background[6])
	ok

	if pos != -1
		TLN_SetLayerPosition (LAYER_BACKGROUND, pos, 0)
	ok
	
	/* background color gradients */
	if line < 112
		InterpolateColor (line, 0,112, sky[1], sky[2], color)
		TLN_SetBGColor (color[1], color[2], color[3])
	elseif line >= 144
		InterpolateColor (line, 144,HEIGHT, sky[3], sky[4], color)
		TLN_SetBGColor (color[1], color[2], color[3])
	ok

func InterpolateColor v,v1,v2,color1,color2,result
	result[1] = lerp (v, v1,v2, color1[1], color2[1])
	result[2] = lerp (v, v1,v2, color1[2], color2[2])
	result[3] = lerp (v, v1,v2, color1[3], color2[3])

/* linear interpolation */
func lerp x,x0,x1,fx0,fx1
	return (fx0) + ((fx1) - (fx0))*((x) - (x0))/((x1) - (x0))

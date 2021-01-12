#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"
load "sin.ring"

WIDTH		 = 400
HEIGHT		 = 240
FIXED_BITS	 = 16
LAYER_FOREGROUND = 0
LAYER_BACKGROUND = 1
MAX_LAYER	 = 2
MAP_HORIZON	 = 0
MAP_TRACK	 = 1
MAX_MAP		 = 2

road		 = NULL
x		 = NULL
y		 = NULL
angle		 = NULL

func main

	/* setup engine */

		TLN_Init (WIDTH,HEIGHT, MAX_LAYER, 0, 0)
		TLN_SetRasterCallback ("raster_callback()")
		TLN_SetBGColor (0,0,0)

	/* load resources*/

		TLN_SetLoadPath ("assets/smk")
		road = TLN_LoadTilemap ("track1.tmx", NULL)
		horizon = TLN_LoadTilemap ("track1_bg.tmx", NULL)

	/* startup display */

		TLN_CreateWindow (NULL, 0)
		x = int2fix(-136)
		y = int2fix(336)
		s = 0
		a = float2fix(0.2)
		angle = 0
		BuildSinTable ()

	/* main loop */

		while (TLN_ProcessWindow ())
			TLN_SetLayerTilemap (LAYER_FOREGROUND, horizon)
			TLN_SetLayerTilemap (LAYER_BACKGROUND, horizon)
			TLN_SetLayerPosition (LAYER_FOREGROUND, lerp(angle*2, 0,360, 0,256), 24)
			TLN_SetLayerPosition (LAYER_BACKGROUND, lerp(angle, 0,360, 0,256), 0)
			TLN_ResetLayerMode (LAYER_BACKGROUND)

			/* input */		

				if (TLN_GetInput (INPUT_LEFT))
					angle-=2
				elseif (TLN_GetInput (INPUT_RIGHT))
					angle+=2
				ok

				if (TLN_GetInput (INPUT_UP))
					s += a
					if (s > int2fix(2))
						s = int2fix(2)
					ok
				elseif (s >= a)
					s -= a
				ok

				if (TLN_GetInput (INPUT_DOWN))
					s -= a
					if (s < -int2fix(2))
						s = -int2fix(2)
					ok
				elseif (s <= -a)
					s += a
				ok

				if (s != 0)
					angle = angle%360
					if (angle < 0)
						angle += 360
					ok

					x += CalcSin (angle, s)
					y -= CalcCos (angle, s)
				ok

			/* render to window */

				TLN_DrawFrame (0)
	end

	/* deinit */

		TLN_DeleteTilemap (road)
		TLN_DeleteTilemap (horizon)
		TLN_DeleteWindow ()
		TLN_Deinit ()


/* raster callback (virtual HBLANK) */

func raster_callback 

	line = TLN_GETSCANLINE()

	if (line = 24)
		TLN_SetLayerTilemap (LAYER_BACKGROUND, road)
		TLN_SetLayerPosition (LAYER_BACKGROUND, fix2int(x), fix2int(y))
		TLN_DisableLayer (LAYER_FOREGROUND)
	elseif (line >= 24)
		s0 = float2fix (0.2)
		s1 = float2fix (5.0)
		s = lerp (line, 24,HEIGHT, s0,s1)
		scale = fix2float (s)
		TLN_SetLayerTransform (LAYER_BACKGROUND, angle, WIDTH/2, HEIGHT, scale, scale)
	ok

func lerp x,x0,x1,fx0,fx1
	return (fx0) + ((fx1) - (fx0)) * ((x) - (x0))/((x1) - (x0))

func float2fix f	return f * (1 << FIXED_BITS)
func int2fix i		return i << FIXED_BITS
func fix2int f		return f >> FIXED_BITS
func fix2float f	return f/(1 << FIXED_BITS)

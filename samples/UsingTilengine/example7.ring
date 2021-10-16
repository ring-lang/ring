#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

load "tilengine.ring"
load "sin.ring"

WIDTH   =	320
HEIGHT  =	192
COLUMNS	= WIDTH/8 + 2

/* layers */
LAYER_FOREGROUND = 0
LAYER_BACKGROUND = 1
MAX_LAYER = 2

frame = 0
column = list(COLUMNS)

/* entry point */
func main

	/* setup engine */

		TLN_Init (WIDTH,HEIGHT, MAX_LAYER, 0, 5)
		TLN_SetRasterCallback ("raster_callback()")
		TLN_SetBGColor (0,0,0)

	/* load resources*/

		TLN_SetLoadPath ("assets/tf3")
		foreground = TLN_LoadTilemap ("tf3_bg2.tmx", NULL)
		background = TLN_LoadTilemap ("tf3_bg3.tmx", NULL)
		TLN_SetLayerTilemap (LAYER_FOREGROUND, foreground)
		TLN_SetLayerTilemap (LAYER_BACKGROUND, background)

		BuildSinTable ()

		# Convert the Column List to Array of Integers  	
			intArray = "" for item in column intArray += int2Bytes(item) next 		

		TLN_SetLayerColumnOffset (LAYER_BACKGROUND, :intArray)

	/* main loop */

		TLN_CreateWindow (NULL, 0)
		while (TLN_ProcessWindow ())

			/* scroll */

				TLN_SetLayerPosition (LAYER_FOREGROUND, frame*3, 0)
				TLN_SetLayerPosition (LAYER_BACKGROUND, frame, 0)

			/* update column offset table */

				for c=1 to COLUMNS
					column[c] = CalcSin (frame*5 + c*20, 3)		
				next

			/* render to window */

				TLN_DrawFrame (frame)
				frame++

		end

		/* deinit */

			TLN_DeleteTilemap (foreground)
			TLN_DeleteTilemap (background)
			TLN_Deinit ()

func raster_callback 

	/* raster callback (virtual HBLANK) */

		line = TLN_GetScanLine()
		TLN_SetLayerPosition (LAYER_FOREGROUND, frame*2, CalcSin((frame+line)<<1, 8) + 8)
		TLN_SetLayerPosition (LAYER_BACKGROUND, frame + CalcSin((frame + line)<<1, 10), 0)

func lerp x,x0,x1,fx0,fx1

	/* linear interpolation */

		return (fx0) + ((fx1) - (fx0))*((x) - (x0))/((x1) - (x0))

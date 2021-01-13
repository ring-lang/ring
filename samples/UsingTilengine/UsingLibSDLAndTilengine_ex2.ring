#==========================================================================#
# This example uses LibSDL & Tilengine Together
# Scaling using SDL_RenderCopy() function
#==========================================================================#

load "tilengine.ring"
load "libsdl.ring"

factor = 3
width  = 400*factor
height = 220*factor

func main

	# Start Tilengine
		TLN_Init(width, height, 2, 80, 0)

	# Start LibSDL
		SDL_Init(SDL_INIT_EVERYTHING)
		win = SDL_CreateWindow("Using LibSDL and Tilengine", 40, 40, width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL)
		ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC )

	# Create the Surface in LibSDL that will be used by Tilengine for Drawing	
 		surface = SDL_CreateRGBSurface(0, width, height, 32, 0,0,0,0)
	# Get the Surface Pixels pointer from the Surface Structure
		pixels = SDL_Get_SDL_Surface_Pixels(surface)
	# Pass the Pixels pointer to Tilengine 	
		TLN_SetRenderTarget(pixels, width * 4)

	# Using Tilengine 
		TLN_SetLoadPath("assets\sonic")
		foreground = TLN_LoadTilemap ("Sonic_md_fg1.tmx", NULL)
		TLN_SetLayerTilemap(0, foreground)

	# Using LibSDL Events Loop
		oEvent = SDL_New_SDL_Event()

		while true

			# Using Tilengine to Update the Frame		
			        TLN_UpdateFrame(0)

			# Draw Tilengine results using LibSDL 
			# ( Surface --> Texture --> Render)
				tex = SDL_CreateTextureFromSurface(ren, surface);

				rectSource = SDL_New_SDL_Rect()
				SDL_Set_SDL_Rect_x(rectSource,0)
				SDL_Set_SDL_Rect_y(rectSource,0)
				SDL_Set_SDL_Rect_w(rectSource,400)
				SDL_Set_SDL_Rect_h(rectSource,220)

				rectDest = SDL_New_SDL_Rect()
				SDL_Set_SDL_Rect_x(rectDest,0)
				SDL_Set_SDL_Rect_y(rectDest,0)
				SDL_Set_SDL_Rect_w(rectDest,width)
				SDL_Set_SDL_Rect_h(rectDest,height)

				SDL_RenderCopy(ren,tex,rectSource,rectDest)
				SDL_Destroy_SDL_Rect(rectSource)
				SDL_Destroy_SDL_Rect(rectDest)
				SDL_DestroyTexture(tex)

			# Draw Rectangle using LibSDL 
				rect = SDL_New_SDL_Rect()
				SDL_Set_SDL_Rect_x(rect,40)
				SDL_Set_SDL_Rect_y(rect,5)
				SDL_Set_SDL_Rect_w(rect,230)
				SDL_Set_SDL_Rect_h(rect,200)
				SDL_SetRenderDrawColor(ren,255,255,255,255)
				SDL_RenderDrawRect(ren,rect)
				SDL_Destroy_SDL_Rect(rect)

			# Display Results using LibSDL
				SDL_RenderPresent(ren)

			# Check Events

			        SDL_PollEvent(oEvent)
			        switch SDL_Get_SDL_Event_Type(oEvent)
			                on SDL_Get_SDL_Quit()
			                        exit
			                on SDL_Get_SDL_Keydown()
		        	                Key = SDL_Get_SDL_Event_key_Keysym_Sym(oEvent)
		                	        if key = 27 exit ok
			        off
		end

	# End of Tilengine Usage
		TLN_Deinit()

	# End of LibSDL Usage
		SDL_DestroyWindow(win)
		SDL_Quit()

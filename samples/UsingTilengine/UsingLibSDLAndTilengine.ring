#==========================================================================#
# This example uses LibSDL & Tilengine Together
# So we can extend Tilengine with LibSDL power
# This means (More control on windows, Drawing Text, Playing Music, etc.)
#==========================================================================#

load "tilengine.ring"
load "libsdl.ring"

width  = 640
height = 480

func main

	# Start Tilengine
		TLN_Init(width, height, 2, 80, 0)

	# Start LibSDL
		SDL_Init(SDL_INIT_EVERYTHING)
		win = SDL_CreateWindow("Using LibSDL and Tilengine", 100, 100, width, height, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL)
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
				SDL_RenderCopy2(ren,tex)
				SDL_DestroyTexture(tex)

			# Draw Rectangle using LibSDL 
				rect = SDL_New_SDL_Rect()
				SDL_Set_SDL_Rect_x(rect,10)
				SDL_Set_SDL_Rect_y(rect,10)
				SDL_Set_SDL_Rect_w(rect,100)
				SDL_Set_SDL_Rect_h(rect,100)
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

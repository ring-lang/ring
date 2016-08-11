# The Ring Standard Library
# Game Engine for 2D Games
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

load "libsdl.ring"

# Keyboard
GL_SPACE = SDLK_SPACE
GL_ESC = SDLK_ESCAPE
GL_KEY_RIGHT = SDLK_RIGHT
GL_KEY_LEFT = SDLK_LEFT
GL_KEY_UP = SDLK_UP
GL_KEY_DOWN = SDLK_DOWN

# Display
GL_FULLSCREEN = -1

# Events
GL_EVENT_DISPLAY_CLOSE = SDL_QUIT
GL_EVENT_TIMER = -2
GL_EVENT_MOUSE_AXES = SDL_MOUSEMOTION 
GL_EVENT_MOUSE_ENTER_DISPLAY = -3 
GL_EVENT_MOUSE_BUTTON_UP = SDL_MOUSEBUTTONUP 
GL_EVENT_KEY_DOWN = SDL_KEYDOWN 
GL_EVENT_KEY_UP = SDL_KEYUP 

# Text
GL_ALIGN_LEFT = -1

# Sound
GL_PLAYMODE_ONCE = -1
GL_PLAYMODE_LOOP = -1

# render 
SDL_win = NULL
SDL_ren = NULL
SDL_target = NULL
SDL_event = NULL

# Frames per second
SDL_FPS = 1000 / 60
SDL_CLOCK = clock()

#other
sdl_v1=0
sdl_v2=0
sdl_v3=0
sdl_v4=0

func gl_start_playing
	gl_game_start()
    	main()

func gl_game_start
	sdl_init(SDL_INIT_EVERYTHING)
	flags = IMG_INIT_JPG | IMG_INIT_PNG
	IMG_Init(flags)
	TTF_Init()
	Mix_OpenAudio( 44100, sdl_get_mix_default_format() , 2, 10000)
	Mix_AllocateChannels(4)
	
	# colors
	GE_COLOR_WHITE = gl_map_rgb(255,255,255)
	GE_COLOR_RED = gl_map_rgb(255,0,0)
	GE_COLOR_GREEN = gl_map_rgb(0,255,0)
	GE_COLOR_BLUE = gl_map_rgb(0,0,255)

func gl_map_rgb r,g,b
	color = sdl_new_sdl_color()
	sdl_set_sdl_color_r(color,r)
	sdl_set_sdl_color_g(color,g)
	sdl_set_sdl_color_b(color,b)
	return color

func gl_load_bitmap cFileName
	image = IMG_Load(cFileName)
	tex = SDL_CreateTextureFromSurface(SDL_ren,image)	
	return [image,tex]

func gl_destroy_bitmap image
	SDL_FreeSurface(image[1])
	SDL_DestroyTexture(image[2])
	image = []

func gl_load_ttf_font cfilename,nSize,p3
	return TTF_OpenFont(cfilename,nSize)

func gl_destroy_font pObject
	TTF_CloseFont(pObject)

func gl_set_window_title display,title
	SDL_SetWindowTitle(display,title)

func gl_create_display screen_w,screen_h
	SDL_win = SDL_CreateWindow("", 100, 100, screen_w,screen_h, SDL_WINDOW_SHOWN)
	SDL_ren = SDL_CreateRenderer(SDL_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC )
	return SDL_win

func gl_set_new_display_flags nFlags

func gl_events display,event_queue,ev,timer,timeout

func gl_new_glib_event

func gl_new_glib_timeout

func gl_create_event_queue
	SDL_event = sdl_new_sdl_event()
	return SDL_event

func gl_create_timer nCount

func gl_wait_for_event_until event_queue, ev, timeout
	sdl_pollevent(event_queue)

func gl_get_glib_event_type ev
	if clock() - SDL_CLOCK >= SDL_FPS
		SDL_CLOCK = clock()
		return GL_EVENT_TIMER
	ok
	return sdl_get_sdl_event_type(SDL_event)

func gl_get_glib_event_keyboard_keycode ev
	nKey = SDL_GET_SDL_Event_key_keysym_sym(SDL_event)
	return nKey

func gl_is_event_queue_empty event_queue
	return true

func gl_clear_to_color nColor
	SDL_RenderClear(SDL_ren)

func gl_flip_display
	SDL_RenderPresent(SDL_ren)

func gl_exit
	SDL_Quit()
	bye

func gl_destroy display,event_queue,timeout,ev,timer
	Mix_CloseAudio()
	Mix_Quit()
	SDL_DestroyWindow(SDL_win)

func gl_convert_mask_to_alpha image,transparentcolor
	myformat = SDL_get_sdl_surface_format(image[1])	
	white = SDL_MapRGB(myformat, 255, 255, 255)
	SDL_SetColorKey(image[1], SDL_True, white)
	SDL_DestroyTexture(image[2])
	image[2] = SDL_CreateTextureFromSurface(SDL_ren,image[1])	


func gl_draw_bitmap image,x,y,nvalue
	tex = image[2]
	rect = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect,x)
	sdl_set_sdl_rect_y(rect,y)
	sdl_set_sdl_rect_w(rect,gl_texture_width(tex))
	sdl_set_sdl_rect_h(rect,gl_texture_height(tex))
	SDL_RenderCopy(SDL_ren,tex,nullpointer(),rect)
	sdl_destroy_sdl_rect(rect)

func gl_get_bitmap_height image
	return gl_texture_height(image[2])

func gl_get_bitmap_width image
	return gl_texture_width(image[2])

func gl_draw_scaled_bitmap image,p2,p3,p4,p5,p6,p7,p8,p9,p10
	tex = image[2]
	rect = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect,p6)
	sdl_set_sdl_rect_y(rect,p7)
	sdl_set_sdl_rect_w(rect,p8)
	sdl_set_sdl_rect_h(rect,p9)
	SDL_RenderCopy(SDL_ren,tex,nullpointer(),rect)
	sdl_destroy_sdl_rect(rect)

func gl_draw_text font,color,x,y,nAlign,text
	text = TTF_RenderText_Solid(font,text,color)
	tex = SDL_CreateTextureFromSurface(SDL_ren,text)
	rect = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect,0)
	sdl_set_sdl_rect_y(rect,0)
	sdl_set_sdl_rect_w(rect,sdl_get_sdl_surface_w(text))
	sdl_set_sdl_rect_h(rect,sdl_get_sdl_surface_h(text))
	rect2 = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect2,x)
	sdl_set_sdl_rect_y(rect2,y)
	sdl_set_sdl_rect_w(rect2,sdl_get_sdl_surface_w(text))
	sdl_set_sdl_rect_h(rect2,sdl_get_sdl_surface_h(text))
	SDL_RenderCopy(SDL_ren,tex,rect,rect2)
	sdl_destroytexture(tex)
	sdl_freesurface(text)
	sdl_destroy_sdl_rect(rect)
	sdl_destroy_sdl_rect(rect2)

func gl_draw_bitmap_region image,p2,p3,p4,p5,p6,p7,p8
	tex = image[2]
	rect = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect,p2)
	sdl_set_sdl_rect_y(rect,p3)
	sdl_set_sdl_rect_w(rect,p4)
	sdl_set_sdl_rect_h(rect,p5)
	rect2 = sdl_new_sdl_rect()
	sdl_set_sdl_rect_x(rect2,p6)
	sdl_set_sdl_rect_y(rect2,p7)
	sdl_set_sdl_rect_w(rect2,p4)
	sdl_set_sdl_rect_h(rect2,p5)
	SDL_RenderCopy(SDL_ren,tex,rect,rect2)
	sdl_destroy_sdl_rect(rect)
	sdl_destroy_sdl_rect(rect2)

func gl_load_sample cfilename
	return Mix_LoadWav( cFileName )

func gl_get_backbuffer display
	return SDL_win

func gl_set_target_bitmap oBitmap
	SDL_Target = oBitmap

func gl_new_glib_sample_id

func gl_play_sample sound,p2,p3,p4,p5,p6	
	#Mix_VolumeChunk(sound,1)
	Mix_PlayChannel(-1,sound,-1)

func gl_destroy_glib_sample_id sampleid

func gl_destroy_sample sample
	Mix_FreeChunk( sample )

# Private Functions - Not used by the Game Engine  

func gl_delay x
	SDL_Delay(x)

func gl_texture_format tex
	SDL_QueryTexture(tex,"sdl_v1", "sdl_v2","sdl_v3","sdl_v4")
	return sdl_v1

func gl_texture_width tex
	SDL_QueryTexture(tex,"sdl_v1", "sdl_v2","sdl_v3","sdl_v4")
	return sdl_v3

func gl_texture_height tex
	SDL_QueryTexture(tex,"sdl_v1", "sdl_v2","sdl_v3","sdl_v4")
	return sdl_v4
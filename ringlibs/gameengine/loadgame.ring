load "gamelib.ring"

func al_game_start 

	al_init()
	al_init_font_addon()
	al_init_ttf_addon()
	al_init_image_addon()
	al_install_audio()
	al_init_acodec_addon()
	al_reserve_samples(1)

	# colors
	GE_COLOR_WHITE = al_map_rgb(255,255,255)
	GE_COLOR_RED = al_map_rgb(255,0,0)
	GE_COLOR_GREEN = al_map_rgb(0,255,0)
	GE_COLOR_BLUE = al_map_rgb(0,0,255)

    	main()
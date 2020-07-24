Load "gamelib.ring"

? al_init()
? al_init_acodec_addon()
? al_install_audio()

voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2) 
mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2)  

? voice
? mixer 

al_attach_mixer_to_voice(mixer, voice)
al_set_default_mixer(mixer)
al_reserve_samples(1)

display = al_create_display(640,480)
al_clear_to_color(al_map_rgb(0,0,255))
al_flip_display()
al_rest(1)

al_destroy_display(display)

al_exit()

Load "libsdl.ring"

SDL_Init(SDL_INIT_EVERYTHING)

win = SDL_CreateWindow("Mouse Events ", 100, 100, 640, 480, SDL_WINDOW_SHOWN)

TTF_Init()
font = TTF_OpenFont("pirulen.ttf", 16)
color = sdl_new_sdl_color()
sdl_set_sdl_color_r(color,0)
sdl_set_sdl_color_g(color,255)
sdl_set_sdl_color_b(color,0)

surface = SDL_GetWindowSurface(win)

myevent = sdl_new_sdl_event()
while true
        cMsg = ""
        sdl_pollevent(myevent)
        switch sdl_get_sdl_event_type(myevent)
                on SDL_QUIT
                        exit
                on SDL_KEYDOWN
                        Key = SDL_GET_SDL_Event_key_keysym_sym(myevent)
                        if key = 27 exit ok
                on SDL_MOUSEBUTTONDOWN
                        if sdl_get_Sdl_Event_button_button(myevent) = SDL_BUTTON_LEFT
                                SDL_SETWINDOWTITLE(win, " Button_Left_Down " )
                        but sdl_get_Sdl_Event_button_button(myevent) = SDL_BUTTON_MIDDLE
                                SDL_SETWINDOWTITLE(win,  " Button_Middle_Down " )
                        but sdl_get_Sdl_Event_button_button(myevent) = SDL_BUTTON_RIGHT
                                SDL_SETWINDOWTITLE(win,  " Button_Right_Down " )
                        ok
                on SDL_MOUSEMOTION
                        sdl_fillrect(surface,null,0)
                        if sdl_get_sdl_event_motion_xrel(myevent) < 0
                                cMsg += " Left "
                        else
                                cMsg += " Right "
                        ok
                        if sdl_get_sdl_event_motion_yrel(myevent) < 0
                                cMsg += " Up "
                        else
                                cMsg += " Down "
                        ok
                        cMsg += " x = " + sdl_get_sdl_event_motion_x(myevent)
                        cMsg += " y = " + sdl_get_sdl_event_motion_y(myevent)
                        showmsg(cMsg)
        off
end

SDL_Destroy_SDL_Color(Color)
TTF_CloseFont(font)
SDL_DestroyWindow(win)
SDL_Quit()

func showmsg mymsg
        text = TTF_RenderText_Solid(font,mymsg,color)
        SDL_BlitSurface(text, null, surface, null)
        SDL_UpdateWindowSurface(win)
        SDL_FreeSurface(text)

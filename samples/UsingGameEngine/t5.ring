# The Ring Standard Library
# Game Engine for 2D Games
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

load "gameengine.ring"

gl_start_playing()

func main	
	win = gl_create_display(800,600)	
	gl_set_window_title(win,"Hello World")	
	myimage = gl_load_bitmap("images/stars.jpg")
	gl_draw_bitmap(myimage,0,0,0)
	myfont = gl_load_ttf_font("fonts/pirulen.ttf",24,0)
	color = gl_map_rgb(255,255,255)
	color2 = gl_map_rgb(0,255,0)
	color3 = gl_map_rgb(255,25,25)
	gl_draw_text(myfont,color,100,100,0,"Welcome to the Ring Language")
	gl_draw_text(myfont,color2,100,200,0,"Welcome to the Ring Language")
	gl_draw_text(myfont,color3,100,300,0,"Welcome to the Ring Language")
	gl_flip_display()	
	gl_delay(2000)
	gl_exit()

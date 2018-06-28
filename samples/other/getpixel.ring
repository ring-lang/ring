Load "gamelib.ring"

al_init()
al_init_image_addon()

display = al_create_display(640,480)
al_set_target_bitmap(al_get_backbuffer(display))
al_clear_to_color(al_map_rgb(255,255,255))

image = al_load_bitmap("man2.jpg")
al_draw_rotated_bitmap(image,0,0,250,250,150,0)
al_draw_scaled_bitmap(image,0,0,250,250,20,20,400,400,0)

? ring_getpixel(image,0,0)

al_flip_display()
al_rest(2)

al_destroy_bitmap(image)
al_destroy_display(display)

func ring_getpixel image,x,y
	newcolor = al_get_pixel(image,x,y)
	r=copy(" ",4)  g=copy(" ",4)  b=copy(" ",4)
	al_unmap_rgb_f(newcolor, VarPtr("r","float"), VarPtr("g","float") , VarPtr("b","float") )
	return [bytes2float(r),bytes2float(g),bytes2float(b)]

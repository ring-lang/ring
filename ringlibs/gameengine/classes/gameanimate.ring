Class Animate from Sprite

	frames = 0
	frame = 1
	framewidth = 30
	animate = false
	scaled = false

	func draw oengine
		if not enabled return ok
		if transparent
			if not transparentdone
				transparentdone = true
				gl_convert_mask_to_alpha(image,transparentcolor)
			ok
		ok
		if Scaled
			gl_draw_scaled_bitmap(image,(framewidth*(frame-1)),0,framewidth,
			gl_get_bitmap_height(image),x,y,width,height,0)
		else
			gl_draw_bitmap_region(image,(framewidth*(frame-1)),0, framewidth, height, x, y, 0)
		ok


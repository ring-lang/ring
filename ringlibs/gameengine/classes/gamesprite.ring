class sprite from gameobject
	image	point=400
	direction = 1	nstep=1
	ncounter = 0
	r = 0
	cimagefile = ""
	type = 0
	transparent = false	transparentdone = false
	transparentcolor = GE_COLOR_WHITE

	file=0

	func setfile cfilename
		image = oresources.loadimage(cfilename)
		cimagefile = cfilename

	func dotransparent
		gl_convert_mask_to_alpha(image,transparentcolor)

	func draw oengine
		if not enabled return ok
		if transparent
			if not transparentdone
				transparentdone = true
				dotransparent()
			ok
		ok
		if Scaled
			gl_draw_scaled_bitmap(image,0,0,gl_get_bitmap_width(image),
			gl_get_bitmap_height(image),x,y,width,height,0)
		else
			gl_draw_bitmap(image,x,y,0)
		ok

	func animate oGame,oSelf
		if not enabled return ok
		if not state = ""				 		
				call state(oGame,oSelf) 
		ok
		if not animate return ok
		if direction = ge_direction_inc
			if x < point
				x+=nstep
				y+=nstep
			else
				x = 0
				y = 0
			ok
		but direction = ge_direction_dec
			if x > point
				x-=nstep
				y-=nstep
			else
				x = 0
				y = 0
			ok
		but direction = ge_direction_incvertical
			if y < point				
				y+=nstep
			else
				oGame.remove(nindex)
			ok
		but direction = ge_direction_decvertical
			if y > point				
				y-=nstep
			else
				oGame.remove(nindex)
			ok
		but direction = ge_direction_inchorizontal
			if x < point				
				x+=nstep
			else
				oGame.remove(nindex)
			ok
		but direction = ge_direction_dechorizontal
			if x > point				
				x-=nstep
			else
				oGame.remove(nindex)
			ok
		but direction = ge_direction_random
			if ncounter = 0
				r = random(7)
				ncounter++
			else
				if ncounter=10
					ncounter=0
				else
					ncounter++
				ok
			ok
			switch r
			on 0	x+=nstep
			on 1	x-=nstep
			on 2	y+=nstep
			on 3	y-=nstep
			on 4	x+=nstep y+=nstep
			on 5	x-=nstep y-=nstep
			on 6	x+=nstep y-=nstep
			on 7	x-=nstep y+=nstep
			off
		ok

	func delete
		oresources.unloadimage(cimagefile)


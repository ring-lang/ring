class text from sprite

	size = 14
	font  cfontfile  text="" color = GE_COLOR_WHITE
	
	func setfile cfilename
		font = oresources.loadfont(cfilename,size)
		cfontfile = cfilename

	func draw oGame
		if isNULL(font)
			raise("The font object is NULL - be sure to set the font and that the font file exist")
		ok
		gl_draw_text(font, color, x, y,GL_ALIGN_LEFT,text)		

	func delete
		oresources.unloadfont(cfontfile,size)

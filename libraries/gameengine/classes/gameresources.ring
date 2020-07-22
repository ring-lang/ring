class resources

	aimages = []
	afonts = []

	func loadimage cfilename
		npos = find(aimages,cfilename,1)
		if npos = 0
			aimages + [cfilename,gl_load_bitmap(cfilename)]
			npos = len(aimages)
		ok
		return aimages[npos][2]

	func unloadimage cfilename
		npos = find(aimages,cfilename,1)
		if not npos = 0
			gl_destroy_bitmap(aimages[npos][2])
			del(aimages,npos)
		ok

	func loadfont cfilename,nSize
		npos = find(afonts,cfilename,1)
		if npos = 0 or aFonts[nPos][2] != nSize
			afonts + [cfilename,nSize,gl_load_ttf_font(cfilename,nSize,0)]
			npos = len(afonts)
		ok
		return afonts[npos][3]

	func unloadfont cfilename,size
		for x=1 to len(aFonts)
			if aFonts[x][1] = cFileName and aFonts[x][2] = size
				gl_destroy_font(afonts[x][3])
				del(afonts,x)
				exit
			ok
		next


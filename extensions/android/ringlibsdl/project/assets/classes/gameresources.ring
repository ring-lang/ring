class resources

	aimages = []
	afonts = []

	func loadimage cFileName
		npos = find(aimages,cFileName,1)
		if npos = 0
			aimages + [cFileName,gl_load_bitmap(cFileName)]
			npos = len(aimages)
		ok
		return aimages[npos][2]

	func unloadimage cFileName
		npos = find(aimages,cFileName,1)
		if not npos = 0
			gl_destroy_bitmap(aimages[npos][2])
			del(aimages,npos)
		ok

	func loadfont cFileName,nSize
		npos = 0
		for x=1 to len(aFonts)
			if aFonts[x][1] = cFileName and aFonts[x][2] = nSize
				nPos = x
				exit
			ok
		next
		if npos = 0 or aFonts[nPos][2] != nSize
			afonts + [cFileName,nSize,gl_load_ttf_font(cFileName,nSize,0)]
			npos = len(afonts)
		ok
		return afonts[npos][3]

	func unloadfont cFileName,size
		for x=1 to len(aFonts)
			if aFonts[x][1] = cFileName and aFonts[x][2] = size
				gl_destroy_font(afonts[x][3])
				del(afonts,x)
				exit
			ok
		next


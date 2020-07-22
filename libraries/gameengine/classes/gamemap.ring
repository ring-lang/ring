Class Map from Sprite

	aMap = []
	aImages = []
	aPImages = []
	BlockWidth = 32
	BlockHeight = 32
	Animate = false
	width = 800
	height = 600

	lbraceend = true

	func braceend
		if lbraceend 
			lbraceend = false
			loadimages()
		ok

	func loadimages
		for t in aImages
			aPImages + oresources.loadimage(t)
			image = aPImages[len(aPImages)]
			gl_convert_mask_to_alpha(image,transparentcolor)
		next

	func draw oGame
		nX = X
		nY = Y
		for y1 in aMap
			for x1 in y1
				if  x1 != 0 
					image = aPImages[x1]	
					gl_draw_scaled_bitmap(image,0,0,gl_get_bitmap_width(image),
					gl_get_bitmap_height(image),nX,nY,blockwidth,blockheight,0)
				ok
				nX += BlockWidth
				if nX > SCREEN_W
					EXIT
				ok
			next
			nY += BlockHeight
			nX = X
			if nY > SCREEN_H
				EXIT
			ok

		next
		
	func animate oGame,oSelf
		if not state = ""				 		
				call state(oGame,oSelf) 
		ok

	func getvalue x1,y1
		x2 = getcol(x1,y1)
		y2 = getrow(x1,y1)
		if y2 > 0 and y2 <= len(aMap)
			aList = aMap[y2]
			if x2 > 0 and x2 <= len(aList)
				return aList[x2]
			ok
		ok
		return 0

	func getcol x1,y1
		x2 = ceil(((-1*x) + x1)/blockwidth)
		if x2 > len(aMap[1]) 
			x2 = len(aMap[1])
		ok
		return x2
		
	func getrow x1,y1
		y2 = ceil(((-1*y) + y1)/blockheight)
		if y2 > len(aMap) 
			x2 = len(aMap)
		ok
		return y2

func MouseInfo nKbHit, nKey
	if isWindows()
		return GetMouseInfo()
	else
		if nKbhit
			return GetMouseInfoTerm(nKey)
		else
			return GetMouseInfo()
		ok
	ok


func getMouseInfoTerm nKey
	aList = []
	switch nKey
		on MOUSEEVENT_START
			aList + true
			getMousePosTerm(aList)
			aList + 2
			aList + 0
			aList + 0
		on MOUSEMOVE_NOBUTTON
			aList + true
			getMousePosTerm(aList)
			aList + 0
			aList + 0
			aList + 0
		on MOUSEEVENT_CLICK
			aList + true
			getMousePosTerm(aList)
			aList + 1
			aList + 0
			aList + 0
		on MOUSEMOVE_LEFTBTNDOWN
			aList + true
			getMousePosTerm(aList)
			aList + 1
			aList + 0
			aList + 0
		on MOUSEMOVE_RIGHTBTNDOWN
			aList + true
			getMousePosTerm(aList)
			aList + 2
			aList + 0
			aList + 0
		on MOUSEEVENT_SCROLL
			aList + true
			getMousePosTerm(aList)
			aList + 0
			aList + 4
			aList + 0
		on MOUSEEVENT_SCROLLUP
			aList + true
			getMousePosTerm(aList)
			aList + 0
			aList + 4
			aList + 1
		on MOUSEEVENT_SCROLLDOWN
			aList + true
			getMousePosTerm(aList)
			aList + 0
			aList + 4
			aList + 0
		other
			for t=1 to 6
				aList + 0
			next
	off
	for t=1 to 3
		aList + 0
	next
	return aList

func getMousePosTerm aList

	c = char(getch())
	cStr = ""
	while upper(c) != "M" 
		cStr += c
		c = char(getch())		       
	end
	
	nSemPos = substr(cStr,";")
	cStr = substr(cStr,nSemPos+1)
	nSemPos = substr(cStr,";")
	nCol = 0 + left(cStr, nSemPos - 1)
	nRow = 0 + substr(cStr,nSemPos + 1)
		
	aList + nCol
	aList + nRow


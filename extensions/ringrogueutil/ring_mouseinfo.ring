func getmouseinfo_term nKey
	aList = []
	switch nKey
		on MOUSEEVENT_START
			aList + true
			getmousepos_term(aList)
			aList + 2
			aList + 0
			aList + 0
		on MOUSEMOVE_NOBUTTON
			aList + true
			getmousepos_term(aList)
			aList + 0
			aList + 0
			aList + 0
		on MOUSEEVENT_CLICK
			aList + true
			getmousepos_term(aList)
			aList + 1
			aList + 0
			aList + 0
		on MOUSEMOVE_LEFTBTNDOWN
			aList + true
			getmousepos_term(aList)
			aList + 1
			aList + 0
			aList + 0
		on MOUSEMOVE_RIGHTBTNDOWN
			aList + true
			getmousepos_term(aList)
			aList + 2
			aList + 0
			aList + 0
		on MOUSEEVENT_SCROLL
			aList + true
			getmousepos_term(aList)
			aList + 0
			aList + 4
			aList + 0
		on MOUSEEVENT_SCROLLUP
			aList + true
			getmousepos_term(aList)
			aList + 0
			aList + 4
			aList + 1
		on MOUSEEVENT_SCROLLDOWN
			aList + true
			getmousepos_term(aList)
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

func getmousepos_term aList

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


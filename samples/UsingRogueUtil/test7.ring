load "rogueutil.ring"

enablemouse()

cls()

C_MSG = 'You Can Move Me Using Arrows/WSAD or Mouse Left Button'

C_MSGLEN = len(C_MSG)

C_SCREENROWS = tRows()
C_SCREENCOLS = tCols()

C_DEFAULTX = 10
C_DEFAULTY = 10

hideCursor()
setConsoleTitle("Using Mouse (Windows/Linux)")

nX = C_DEFAULTX
nY = C_DEFAULTY

prepareScreen()
showMsg()

fflush(stdout)

while True

	# Window resize
	if tRows() != C_SCREENROWS or tCols() != C_SCREENCOLS
		prepareScreen()
		nX = C_DEFAULTX
		nY = C_DEFAULTY
		C_SCREENROWS = tRows()
		C_SCREENCOLS = tCols()
		showMsg()
	ok


	# Using the Keyboard
	nKbhit = kbhit()
	if nKbhit 
		nKey = getkey() 
		if nKey = KEY_ESCAPE exit ok
		clearMsg()
		if nKey = KEY_RIGHT or Upper(Char(nKey)) = "D"
			nX += 1
			if nX > tCols()-C_MSGLEN+1  nX -= 1 ok
		but nKey = KEY_LEFT or Upper(Char(nKey)) = "A"
			nX -= 1
			if nX < 1  nX = 1 ok
		but nKey = KEY_UP or Upper(Char(nKey)) = "W"
			nY -= 1
			if nY < 1  nY = 1 ok
		but nKey = KEY_DOWN or Upper(Char(nKey)) = "S"
			nY += 1
			if nY > tRows()  nY -= 1 ok
		ok
		showMsg()	
	  
	ok


	# Using the Mouse 
	if isWindows()
		aMouse = GetMouseInfo()
	else
		if nKbhit
			aMouse = GetMouseInfo_Term(nKey)
		else
			aMouse = GetMouseInfo()
		ok
	ok

	if aMouse[MOUSEINFO_ACTIVE]

		printxy(1,2,"X: " +  aMouse[MOUSEINFO_X] +
			    " Y: " + aMouse[MOUSEINFO_Y] + 
			    " B: " + aMouse[MOUSEINFO_BUTTONS] + "     ")

		if aMouse[MOUSEINFO_EVENTS] = MOUSEINFO_WHEELEVENT
			printxy(1,3,"Scroll Direction : " + aMouse[MOUSEINFO_SCROLLDIRECTION])
		else 
			printxy(1,3,Copy(" ",50))
		ok

		if aMouse[MOUSEINFO_BUTTONS] = MOUSEINFO_LEFTBUTTON
			clearMsg()
			nX = aMouse[MOUSEINFO_X]
			nY = aMouse[MOUSEINFO_Y]	
			if nX < 1  nX = 1 ok
			if nY < 1  nY = 1 ok
			if nY > tRows()  nY = tRows() ok
			if nX > tCols()-C_MSGLEN+1  nX = tCols()-C_MSGLEN+1 ok
			showMsg()
		ok

	ok

end

disablemouse()
showCursor()
echoON()

func prepareScreen
	setColor(White)
	setBackgroundColor(Red)
	cls()

func showMsg
	printXY(nX,nY,C_MSG)
	
func clearMsg
	printXY(nX,nY,Copy(" ",C_MSGLEN))
	
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


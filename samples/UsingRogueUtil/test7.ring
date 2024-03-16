load "rogueutil.ring"

enableMouse()

cls()

C_MSG = 'You Can Move Me Using Arrows/WSAD or Mouse Left Button'

C_MSGLEN = len(C_MSG)

C_SCREENROWS = tRows()
C_SCREENCOLS = tCols()

C_DEFAULTX = 10
C_DEFAULTY = 10

hideCursor()
setConsoleTitle("Using Mouse (Windows/Linux/macOS)")

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
	nBuffer = kbhit()
	nKey    = 0
	if nBuffer 
		nKey = getKey() 
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
		aMouse = MouseInfo(nBuffer,nKey)

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

disableMouse()
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
	

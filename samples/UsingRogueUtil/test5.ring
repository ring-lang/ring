load "rogueutil.ring"

C_MSG = 'You Can Move Me Using Keyboard Arrows or WSAD'
C_MSGLEN = len(C_MSG)

C_SCREENROWS = tRows()
C_SCREENCOLS = tCols()

C_DEFAULTX = 10
C_DEFAULTY = 10

hideCursor()
setConsoleTitle("Moving Text")

nX = C_DEFAULTX
nY = C_DEFAULTY

prepareScreen()
showMsg()

fflush(stdout)

while True
	if tRows() != C_SCREENROWS or tCols() != C_SCREENCOLS
		prepareScreen()
		nX = C_DEFAULTX
		nY = C_DEFAULTY
		C_SCREENROWS = tRows()
		C_SCREENCOLS = tCols()
		showMsg()
	ok
	if kbhit()
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
end

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

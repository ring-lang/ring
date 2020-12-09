load "libui.ring"

oWindow = uiNewWindow( "Draw Gradient", 800, 600, True)
uiWindowOnClosing(oWindow,"closeApp()")

oAreaHandler = uiNewAreaHandler("draw()","","","","")
area = uiNewArea(oAreaHandler)

btnClose = uiNewButton("Close Application")
uiButtonOnClicked(btnClose,"closeApp()")

hbox = uiNewVerticalBox()
uiBoxSetPadded(hbox, 1)
uiBoxAppend(hbox,btnClose,0)
uiBoxAppend(hbox,area,1)
uiWindowSetChild(oWindow, hbox)

uiControlShow( oWindow )
uiMain()

func draw
	nWidth = uiEventAreaWidth()		nHeight = uiEventAreaHeight()
	Rectangle(0, 0, nWidth, nHeight, colorBlue)
	for y=0 to 255 step 2
		customColor = y
		Rectangle(0, y, nWidth, y+1, customColor)
	next

func Rectangle x,y,width,height,color
	oContext = uiEventContext()
	oBrush = uiNewSolidBrush(color)	
	oPath = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathAddRectangle(oPath, x, y, width, height)
	uiDrawPathEnd(oPath)
	uiDrawFill(oContext, oPath, oBrush)
	uiDrawFreePath(oPath)

func closeApp
	uiQuit()

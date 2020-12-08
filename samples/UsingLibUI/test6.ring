load "libui.ring"

oWindow = uiNewWindow( "Drawing Sample", 400, 400, True)
uiWindowOnClosing(oWindow,"closeApp()")

oAreaHandler = uiNewAreaHandler("draw()","","","","")
area = uiNewArea(oAreaHandler)

btnClose = uiNewButton("Close Application")
uiButtonOnClicked(btnClose,"closeApp()")

g = uiNewGrid() uiGridSetPadded(g, 1) uiWindowSetChild(oWindow, g)
uiGridAppend(g, area, 0, 0, 0, 0, 0, uiAlignFill, 0, uiAlignEnd)
uiGridAppend(g, btnClose, 0, 0, 2, 1, 1, uiAlignEnd, 0, uiAlignEnd)

uiControlShow( oWindow )
uiMain()

func draw
		Rectangle(0, 0, 400, 400, colorWhite)
		Rectangle(10, 10, 20, 20, colorRed)
		Rectangle(30, 30, 30, 30, colorGreen)
		Rectangle(60, 60, 40, 40, colorBlue)

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

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

	oContext = uiEventContext()

	# Define some colors
		colorWhite = dec("FFFFFF")	
		colorRed = dec("FF0000")
		colorGreen = dec("00FF00")
		colorBlue = dec("0000FF")

	# Draw White Rectangle
		Rectangle(oContext, 0, 0, 400, 400, colorWhite)

	# Draw Red Rectangle
		Rectangle(oContext, 10, 10, 20, 20, colorRed)

	# Draw Green Rectangle
		Rectangle(oContext, 30, 30, 30, 30, colorGreen)

	# Draw Blue Rectangle
		Rectangle(oContext, 60, 60, 40, 40, colorBlue)

func Rectangle oContext,x,y,width,height,color
	oBrush = uiNewSolidBrush(color)	
	oPath = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathAddRectangle(oPath, x, y, width, height)
	uiDrawPathEnd(oPath)
	uiDrawFill(oContext, oPath, oBrush)
	uiDrawFreePath(oPath)


func closeApp
	uiQuit()

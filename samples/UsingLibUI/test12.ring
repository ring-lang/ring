# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

oWindow = uiNewWindow( "Drawing Sample", 260, 300, True)
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

	source = new_uiDrawBrush()
	sp = new_uiDrawStrokeParams()

	x         = 25.6
	y         = 25.6
	width         = 204.8
	height        = 204.8
	aspect        = 1.0
	corner_radius = height

	radius = corner_radius / aspect
	degrees = uiPi / 180.0

	source = uiNewSolidBrush(colorBlue)	
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)	
	set_uiDrawStrokeParams_NumDashes(sp,0)		
	set_uiDrawStrokeParams_DashPhase(sp,0)	
	set_uiDrawStrokeParams_Thickness(sp,30)	

	path = uiDrawNewPath(uiDrawFillModeWinding)

	// top right corner
	uiDrawPathNewFigureWithArc(path,
		x + width - radius, y + radius,
		radius,
		-90 * degrees, uiPi / 2,
		0)
	// bottom right corner
	uiDrawPathArcTo(path,
		x + width - radius, y + height - radius,
		radius,
		0 * degrees, uiPi / 2,
		0)
	// bottom left corner
	uiDrawPathArcTo(path,
		x + radius, y + height - radius,
		radius,
		90 * degrees, uiPi / 2,
		0)
	// top left corner
	uiDrawPathArcTo(path,
		x + radius, y + radius,
		radius,
		180 * degrees, uiPi / 2,
		0)
	uiDrawPathCloseFigure(path)
	uiDrawPathEnd(path)

	uiCrSourceRGBA(source, 0.5, 0.5, 1, 1)
	uiDrawFill(uiEventContext(), path, source)
	uiCrSourceRGBA(source, 0.5, 0, 0, 0.5)
	set_uiDrawStrokeParams_Thickness(sp,10)	
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

func closeApp
	uiQuit()

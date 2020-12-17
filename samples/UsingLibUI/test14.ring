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
	m = new_uiDrawMatrix()
	source = uiNewSolidBrush(colorBlue)	
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)	
	set_uiDrawStrokeParams_NumDashes(sp,0)		
	set_uiDrawStrokeParams_DashPhase(sp,0)	
	set_uiDrawStrokeParams_Thickness(sp,6)	

	path = uiDrawNewPath(uiDrawFillModeAlternate)
	uiDrawPathAddRectangle(path, 12, 12, 232, 70)
	uiDrawPathNewFigureWithArc(path,
		64, 64,
		40,
		0, 2*uiPi,
		0)
	uiDrawPathNewFigureWithArc(path,
		192, 64,
		40,
		0, -2*uiPi,
		1)
	uiDrawPathEnd(path)

	uicrsourcergba(source, 0, 0.7, 0, 1)
	uiDrawFill(uiEventContext(), path, source)
	uicrsourcergba(source, 0, 0, 0, 1)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

	uiDrawMatrixSetIdentity(m)
	uiDrawMatrixTranslate(m, 0, 128)
	uiDrawTransform(uiEventContext(), m)

	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathAddRectangle(path, 12, 12, 232, 70)
	uiDrawPathNewFigureWithArc(path,
		64, 64,
		40,
		0, 2*uiPi,
		0)
	uiDrawPathNewFigureWithArc(path,
		192, 64,
		40,
		0, -2*uiPi,
		1)
	uiDrawPathEnd(path)

	uicrsourcergba(source, 0, 0, 0.9, 1)
	uiDrawFill(uiEventContext(), path, source)
	uicrsourcergba(source, 0, 0, 0, 1)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

func closeApp
	uiQuit()

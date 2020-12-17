# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

oWindow = uiNewWindow( "Drawing Sample", 400, 400, True)
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
	source = uiNewSolidBrush(colorBlack)	
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)	
	set_uiDrawStrokeParams_NumDashes(sp,0)		
	set_uiDrawStrokeParams_DashPhase(sp,0)	
	set_uiDrawStrokeParams_Thickness(sp,30)	

	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, 64.0, 50.0)
	uiDrawPathLineTo(path, 64.0, 200.0)
	uiDrawPathEnd(path)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapRound)	
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, 128.0, 50.0)
	uiDrawPathLineTo(path, 128.0, 200.0)
	uiDrawPathEnd(path)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapSquare)	
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, 192.0, 50.0)
	uiDrawPathLineTo(path, 192.0, 200.0)
	uiDrawPathEnd(path)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

	// draw helping lines
	// keep the square cap to match the reference picture on the cairo website
	uiCrSourceRGBA(source, 1, 0.2, 0.2, 1)
	set_uiDrawStrokeParams_Thickness(sp,2.56)	
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, 64.0, 50.0)
	uiDrawPathLineTo(path, 64.0, 200.0)
	uiDrawPathNewFigure(path, 128.0, 50.0)
	uiDrawPathLineTo(path, 128.0, 200.0)
	uiDrawPathNewFigure(path, 192.0, 50.0)
	uiDrawPathLineTo(path, 192.0, 200.0)
	uiDrawPathEnd(path)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

func closeApp
	uiQuit()

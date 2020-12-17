# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

oWindow = uiNewWindow( "Drawing Sample", 300, 300, True)
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

	source = uiNewSolidBrush(colorBlue)	
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)	
	set_uiDrawStrokeParams_NumDashes(sp,0)		
	set_uiDrawStrokeParams_DashPhase(sp,0)	

	path = uiDrawNewPath(uiDrawFillModeWinding)

	uiDrawPathNewFigure(path, 50.0, 75.0)
	uiDrawPathLineTo(path, 200.0, 75.0)

	uiDrawPathNewFigure(path, 50.0, 125.0)
	uiDrawPathLineTo(path, 200.0, 125.0)

	uiDrawPathNewFigure(path, 50.0, 175.0)
	uiDrawPathLineTo(path, 200.0, 175.0)
	uiDrawPathEnd(path)

	set_uiDrawStrokeParams_Thickness(sp,30)	
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapRound)	
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

func closeApp
	uiQuit()

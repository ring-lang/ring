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
	source = uiNewSolidBrush(colorBlue)	
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)	
	set_uiDrawStrokeParams_NumDashes(sp,0)		
	set_uiDrawStrokeParams_DashPhase(sp,0)	

	path = uiDrawNewPath(uiDrawFillModeWinding)

	uiDrawPathNewFigure(path, 128.0, 25.6)
	uiDrawPathLineTo(path, 230.4, 230.4)
	uiDrawPathLineTo(path, 230.4 - 102.4, 230.4 + 0.0)
	uiDrawPathBezierTo(path, 51.2, 230.4, 51.2, 128.0, 128.0, 128.0)
	uiDrawPathCloseFigure(path)

	uiDrawPathNewFigure(path, 64.0, 25.6)
	uiDrawPathLineTo(path, 64.0 + 51.2, 25.6 + 51.2)
	uiDrawPathLineTo(path, 64.0 + 51.2 -51.2, 25.6 + 51.2 + 51.2)
	uiDrawPathLineTo(path, 64.0 + 51.2 -51.2 -51.2, 25.6 + 51.2 + 51.2 -51.2)
	uiDrawPathCloseFigure(path)

	uiDrawPathEnd(path)

	set_uiDrawStrokeParams_Thickness(sp,10)	
	uicrsourcergba(source, 0, 0, 1, 1)
	uiDrawFill(uiEventContext(), path, source)
	uicrsourcergba(source, 0, 0, 0, 1)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

func closeApp
	uiQuit()

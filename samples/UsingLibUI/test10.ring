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
	source = uiNewSolidBrush(colorBlue)	
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)	
	set_uiDrawStrokeParams_NumDashes(sp,0)		
	set_uiDrawStrokeParams_DashPhase(sp,0)	
	set_uiDrawStrokeParams_Thickness(sp,40.96)	

	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, 76.8, 84.48)
	uiDrawPathLineTo(path, 76.8 + 51.2, 84.48 -51.2)
	uiDrawPathLineTo(path, 76.8 + 51.2 + 51.2, 84.48 - 51.2 + 51.2)
	uiDrawPathEnd(path)
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, 76.8, 161.28)
	uiDrawPathLineTo(path, 76.8 + 51.2, 161.28 -51.2)
	uiDrawPathLineTo(path, 76.8 + 51.2 + 51.2, 161.28 - 51.2 + 51.2)
	uiDrawPathEnd(path)
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinBevel)	
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, 76.8, 238.08)
	uiDrawPathLineTo(path, 76.8 + 51.2, 238.08 -51.2)
	uiDrawPathLineTo(path, 76.8 + 51.2 + 51.2, 238.08 - 51.2 + 51.2)
	uiDrawPathEnd(path)
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinRound)	
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

func closeApp
	uiQuit()

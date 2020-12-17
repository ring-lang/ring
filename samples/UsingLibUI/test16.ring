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

	x=25.6   y=128.0
	x1=102.4 y1=230.4
	x2=153.6 y2=25.6
  x3=230.4 y3=128.0

	uicrsourcergba(source, 0, 0, 0, 1)
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)	
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)	
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)	
	set_uiDrawStrokeParams_NumDashes(sp,0)		
	set_uiDrawStrokeParams_DashPhase(sp,0)	

	path = uiDrawNewPath(uiDrawFillModeWinding)

	uiDrawPathNewFigure(path, x, y)
	uiDrawPathBezierTo(path, x1, y1, x2, y2, x3, y3)
	uiDrawPathEnd(path)
  set_uiDrawStrokeParams_Thickness(sp,10)		
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

	uicrsourcergba(source, 1, 0.2, 0.2, 0.6)
  set_uiDrawStrokeParams_Thickness(sp,6)		
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, x, y)
	uiDrawPathLineTo(path, x1, y1)
	uiDrawPathNewFigure(path, x2, y2)
	uiDrawPathLineTo(path, x3, y3)
	uiDrawPathEnd(path)
	uiDrawStroke(uiEventContext(), path, source, sp)
	uiDrawFreePath(path)

func closeApp
	uiQuit()

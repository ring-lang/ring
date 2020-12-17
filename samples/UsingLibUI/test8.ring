# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

datapoints	= list(10)
currentPoint	= -1

// some metrics
xoffLeft	= 20			/* histogram margins */
yoffTop		= 20
xoffRight	= 20
yoffBottom	= 20
pointRadius	= 5

histogram	= NULL
mainwin		= NULL
colorButton	= NULL

func pointLocations width, height, xs, ys
	xincr = width / 9		// 10 - 1 to make the last point be at the end
	yincr = height / 100
	for i = 1 to 10
		// get the value of the point
		n = uiSpinboxValue(datapoints[i])
		// because y=0 is the top but n=0 is the bottom, we need to flip
		n = 100 - n;
		xs[i] = xincr * i
		ys[i] = yincr * n
	next

func constructGraph width, height, extend
	xs = list(10)
	ys = list(10)
	pointLocations(width, height, xs, ys)
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path, xs[1], ys[1])
	for i = 2 to 10
		uiDrawPathLineTo(path, xs[i], ys[i])
	next
	if extend
		uiDrawPathLineTo(path, width, height)
		uiDrawPathLineTo(path, 0, height)
		uiDrawPathCloseFigure(path)
	ok
	uiDrawPathEnd(path)
	return path


func graphSize clientWidth, clientHeight
	graphWidth = clientWidth - xoffLeft - xoffRight
	graphHeight = clientHeight - yoffTop - yoffBottom
	return [graphWidth,graphHeight]

func handlerDraw
	// fill the area with white
	Brush = uiNewSolidBrush(0)	
	setSolidBrush(brush, colorWhite, 1.0)
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathAddRectangle(path, 0, 0, uiEventAreaWidth(), uiEventAreaHeight())
	uiDrawPathEnd(path)
	uiDrawFill(uiEventContext(), path, brush)
	uiDrawFreePath(path)

	// figure out dimensions
	aOut = graphSize(uiEventAreaWidth(), uiEventAreaHeight())
	graphWidth = aOut[1]
	graphHeight = aOut[2]

	sp = new_managed_uiDrawStrokeParams()
	set_uiDrawStrokeParams_Cap(sp,uiDrawLineCapFlat)
	set_uiDrawStrokeParams_Join(sp,uiDrawLineJoinMiter)
	set_uiDrawStrokeParams_Thickness(sp,2)
	set_uiDrawStrokeParams_MiterLimit(sp,uiDrawDefaultMiterLimit)

	// draw the axes
	setSolidBrush(brush, colorBlack, 1.0)
	path = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathNewFigure(path,
		xoffLeft, yoffTop)
	uiDrawPathLineTo(path,
		xoffLeft, yoffTop + graphHeight)
	uiDrawPathLineTo(path,
		xoffLeft + graphWidth, yoffTop + graphHeight)
	uiDrawPathEnd(path)
	uiDrawStroke(uiEventContext(), path, brush, sp)
	uiDrawFreePath(path)

	// now transform the coordinate space so (0, 0) is the top-left corner of the graph
	m = new_managed_uiDrawMatrix()
	uiDrawMatrixSetIdentity(m)
	uiDrawMatrixTranslate(m, xoffLeft, yoffTop)
	uiDrawTransform(uiEventContext(), m)

	// now get the color for the graph itself and set up the brush

	GraphR=0
	GraphG=0
	GraphB=0
	GraphA=0

	uiColorButtonColor(colorButton, :graphR,
		 :graphG, 
		 :graphB, 
		 :graphA)

	uiSetBrushType(brush,uiDrawBrushTypeSolid)
	uiSetBrushR(brush,graphR)
	uiSetBrushG(brush,graphG)
	uiSetBrushB(brush,graphB)

	// we set brush->A below to different values for the fill and stroke

	// now create the fill for the graph below the graph line
	path = constructGraph(graphWidth, graphHeight, 1)

  uiSetBrushA(brush, graphA / 2)
	uiDrawFill(uiEventContext(), path, brush)
	uiDrawFreePath(path)

	// now draw the histogram line
	path = constructGraph(graphWidth, graphHeight, 0)
	uiSetBrushA(brush,graphA)
	uiDrawStroke(uiEventContext(), path, brush, sp)
	uiDrawFreePath(path)

	// now draw the point being hovered over
	if currentPoint != -1
		xs = list(10)
		ys = list(10)
		pointLocations(graphWidth, graphHeight, xs, ys)
		path = uiDrawNewPath(uiDrawFillModeWinding)

		uiDrawPathNewFigureWithArc(path,
			xs[currentPoint], ys[currentPoint],
			pointRadius,
			0, 6.23,		// TODO pi
			0)
		uiDrawPathEnd(path)
		// use the same brush as for the histogram lines
		uiDrawFill(uiEventContext(), path, brush)
		uiDrawFreePath(path)
	ok

func inPoint x, y, xtest, ytest
	// TODO switch to using a matrix
	x -= xoffLeft
	y -= yoffTop
	return (x >= xtest - pointRadius) &&
		(x <= xtest + pointRadius) &&
		(y >= ytest - pointRadius) &&
		(y <= ytest + pointRadius)

func handlerMouseEvent
	xs = list(10)
	ys = list(10)

	aOut = graphSize(uiEventAreaWidth(), uiEventAreaHeight())
	graphWidth = aOut[1]
	graphHeight = aOut[2]

	pointLocations(graphWidth, graphHeight, xs, ys)

	e = uiEventAreaMouseEvent()
	eX = get_uiAreaMouseEvent_X(e)
	eY = get_uiAreaMouseEvent_Y(e)
	for i=1 to 10
		if inPoint(eX, eY, xs[i], ys[i])
			exit 
		ok
	next
	if i = 11		// not in a point
		i = -1
	ok

	currentPoint = i

	uiAreaQueueRedrawAll(histogram)

func onDatapointChanged
	uiAreaQueueRedrawAll(histogram)

func onColorChanged
	uiAreaQueueRedrawAll(histogram);

func onClosing
	uiControlDestroy(uiControl(mainwin))
	uiQuit()
	return 0

func shouldQuit
	uiControlDestroy(uiControl(mainwin))

func main

	uiOnShouldQuit("shouldQuit()")

	mainwin = uiNewWindow("Histogram Sample", 800, 480, 1)
	uiWindowSetMargined(mainwin, 1)
	uiWindowOnClosing(mainwin, "onClosing()")

	Brush = uiNewSolidBrush(0)	

	hbox = uiNewHorizontalBox()
	uiBoxSetPadded(hbox, 1)
	uiWindowSetChild(mainwin, uiControl(hbox))

	vbox = uiNewVerticalBox()
	uiBoxSetPadded(vbox, 1)
	uiBoxAppend(hbox, uiControl(vbox), 0)

	srandom(clock());
	for i=1 to 10
		datapoints[i] = uiNewSpinbox(0, 100)
		uiSpinboxSetValue(datapoints[i], random() % 101)
		uiSpinboxOnChanged(datapoints[i], "onDatapointChanged()")
		uiBoxAppend(vbox, uiControl(datapoints[i]), 0)
	next

	colorButton = uiNewColorButton()

	setSolidBrush(brush, colorDodgerBlue, 1.0)

	uiColorButtonSetColor(colorButton,
		uiBrushR(brush),
		uiBrushG(brush),
		uiBrushB(brush),
		uiBrushA(brush))

	uiColorButtonOnChanged(colorButton, "onColorChanged()")
	uiBoxAppend(vbox, uiControl(colorButton), 0)

	oAreaHandler = uiNewAreaHandler("handlerDraw()","handlerMouseEvent()","","","")
	histogram = uiNewArea(oAreaHandler)
	uiBoxAppend(hbox, uiControl(histogram), 1)

	uiControlShow(uiControl(mainwin))
	uiMain()

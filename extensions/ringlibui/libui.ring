if isWindows()
	LoadLib("ring_libui.dll")
but ismacosx()
	LoadLib("libring_libui.dylib")
else
	LoadLib("libring_libui.so")
ok

load "ring_libui.rh"

uiInit()

# Define some colors
	colorAqua = dec("00FFFF")
	colorGray = dec("808080")
	colorNavy = dec("000080")
	colorSilver = dec("C0C0C0")
	colorBlack = dec("000000")
	colorGreen = dec("008000")
	colorOlive = dec("808000")
	colorTeal = dec("008080")
	colorBlue = dec("0000FF")
	colorLime = dec("00FF00")
	colorPurple = dec("800080")
	colorWhite = dec("FFFFFF")	
	colorFuchsia = dec("FF00FF")
	colorMaroon = dec("800000")
	colorRed = dec("FF0000")
	colorYellow = dec("FFFF00")
	colorDarkGray = dec("A9A9A9")

func uiControl x
	return x

func uiMenuItem x
	return x

func uiEventContext 
	return Get_uiAreaDrawParams_Context(uiEventAreaDrawParams())

func uiEventAreaWidth
	return get_uiareadrawparams_areawidth(uiEventAreaDrawParams())

func uiEventAreaHeight
	return get_uiareadrawparams_areaheight(uiEventAreaDrawParams())

func uiNewBrush
	return new_managed_uiDrawBrush()

func uiRectangle x,y,width,height,color
	oContext = uiEventContext()
	oBrush = uiNewSolidBrush(color)	
	oPath = uiDrawNewPath(uiDrawFillModeWinding)
	uiDrawPathAddRectangle(oPath, x, y, width, height)
	uiDrawPathEnd(oPath)
	uiDrawFill(oContext, oPath, oBrush)
	uiDrawFreePath(oPath)

func uiNewSolidBrush oColor
	oBrush = uiNewBrush()	
	setSolidBrush(oBrush, oColor, 1.0);
	return oBrush

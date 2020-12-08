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
	colorBlack = dec("000000")
	colorWhite = dec("FFFFFF")	
	colorRed = dec("FF0000")
	colorGreen = dec("00FF00")
	colorBlue = dec("0000FF")


func uiControl x
	return x

func uiMenuItem x
	return x

func uiEventContext 
	return Get_uiAreaDrawParams_Context(uiEventAreaDrawParams())

func uiNewBrush
	return new_managed_uiDrawBrush()

func uiNewSolidBrush oColor
	oBrush = uiNewBrush()	
	setSolidBrush(oBrush, oColor, 1.0);
	return oBrush

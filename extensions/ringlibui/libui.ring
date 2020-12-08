if isWindows()
	LoadLib("ring_libui.dll")
but ismacosx()
	LoadLib("libring_libui.dylib")
else
	LoadLib("libring_libui.so")
ok

load "ring_libui.rh"

uiInit()

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

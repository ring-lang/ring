load "libui.ring"

uiInit()

oWindow = uiNewWindow( "Hello, World", 800, 600, True)

uiControlShow( oWindow )

btn1 = uiNewButton("SayHello")
btn2 = uiNewButton("Close")

g = uiNewGrid() uiGridSetPadded(g, 1) uiWindowSetChild(oWindow, g)

uiGridAppend(g, btn1, 0, 0, 2, 1, 1, uiAlignFill, 0, uiAlignFill)

uiGridAppend(g, btn2, 0, 1, 1, 1, 1, uiAlignFill, 0, uiAlignFill)

uiWindowOnClosing(oWindow,"closeapp()")
uiButtonOnClicked(btn1,"one()")
uiButtonOnClicked(btn2,"two()")


uiMain()
uiUninit()

func closeApp
	? "close the window!"
	uiControlDestroy(oWindow)
	? "close the application!"
	shutdown(0)

func one 
	? "Hello!"

func two 
	closeApp()
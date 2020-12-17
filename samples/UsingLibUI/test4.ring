# Sample ported to Ring 
# Based on original sample from : https://github.com/andlabs/libui

load "libui.ring"

w = uiNewWindow("Hello", 320, 240, 0)
uiWindowSetMargined(w, 1)

b = uiNewVerticalBox()
uiBoxSetPadded(b, 1)
uiWindowSetChild(w, b)

e = uiNewMultilineEntry()
uiMultilineEntrySetReadOnly(e, 1)

btn = uiNewButton("Say Something")
uiButtonOnClicked(btn, "saySomething()")
uiBoxAppend(b, btn, 0)

uiBoxAppend(b, e, 1)

uiTimer(1000, "sayTime()")

uiWindowOnClosing(w, "onClosing()")
uiControlShow(w)
uiMain()

func saySomething
	uiMultilineEntryAppend(e, "Saying something"+nl)

func sayTime 
	uiMultilineEntryAppend(e, Time()+nl)

func onClosing
	uiQuit()

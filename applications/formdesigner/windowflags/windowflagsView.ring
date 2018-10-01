/*
**	Project : Form Designer 
**	File Purpose :  Window Flags Window
**	Date : 2017.04.27
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

Load "stdlibcore.ring"
Load "guilib.ring"

import System.GUI

if IsMainSourceFile() { 
	new App {
		StyleFusion()
		new windowflagsView { win.show() } 
		exec()
	}
}

class windowflagsView from WindowsViewParent
	win = new MainWindow() { 
		move(0,14)
		resize(474,376)
		setWindowTitle(T_FROMDESIGNER_WF_WINDOWFLAGS)	 # "Window Flags"
		setLayoutDirection(T_LAYOUTDIRECTION)
		LabelType = new label(win) {
			move(10,13)
			resize(31,26)
			setText(T_FROMDESIGNER_WF_TYPE)	 # "Type"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		LabelHints = new label(win) {
			move(9,143)
			resize(32,27)
			setText(T_FROMDESIGNER_WF_HINTS)	 # "Hints"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		ListType = new listwidget(win) {
			move(56,13)
			resize(321,113)
			AddItem(T_FROMDESIGNER_WF_WINDOW)	 # "Window"
			AddItem(T_FROMDESIGNER_WF_DIALOG)	 # "Dialog"
			AddItem(T_FROMDESIGNER_WF_SHEET)	 # "Sheet"
			AddItem(T_FROMDESIGNER_WF_DRAWER)	 # "Drawer"
			AddItem(T_FROMDESIGNER_WF_POPUP)	 # "Popup"
			AddItem(T_FROMDESIGNER_WF_TOOL)	 # "Tool"
			AddItem(T_FROMDESIGNER_WF_TOOLTIP)	 # "Tooltip"
			AddItem(T_FROMDESIGNER_WF_SPLASHSCREEN)	 # "Splash Screen"
		}
		ListHints = new listwidget(win) {
			move(56,143)
			resize(321,163)
			AddItem(T_FROMDESIGNER_WF_WINDOWTITLE)	 # "Window title"
			AddItem(T_FROMDESIGNER_WF_WINDOWSYSTEMMENU)	 # "Window system menu"
			AddItem(T_FROMDESIGNER_WF_WINDOWMINIMIZEBUTTON)	 # "Window minimize button"
			AddItem(T_FROMDESIGNER_WF_WINDOWMAXIMIZEBUTTON)	 # "Window maximize button"
			AddItem(T_FROMDESIGNER_WF_WINDOWCLOSEBUTTON)	 # "Window close button"
			AddItem(T_FROMDESIGNER_WF_WINDOWCONTEXTHELPBUTTON)	 # "Window context help button"
			AddItem(T_FROMDESIGNER_WF_WINDOWSHADEBUTTON)	 # "Window shade button"
			AddItem(T_FROMDESIGNER_WF_WINDOWSTAYSONTOP)	 # "Window stays on top"
			AddItem(T_FROMDESIGNER_WF_WINDOWSTAYSONBOTTOM)	 # "Window stays on bottom"
			AddItem(T_FROMDESIGNER_WF_CUSTOMIZEWINDOW)	 # "Customize window"
		}
		BtnOk = new pushbutton(win) {
			move(236,315)
			resize(68,25)
			setText(T_FROMDESIGNER_WF_OK)	 # "Ok"
			setClickEvent(Method(:okAction))
		}
		BtnCancel = new pushbutton(win) {
			move(309,315)
			resize(68,25)
			setText(T_FROMDESIGNER_WF_CANCEL)	 # "Cancel"
			setClickEvent(Method(:CancelAction))
			
		}
		Layout1 = new QHBoxLayout() {
			AddWidget(LabelType)
			AddWidget(ListType)
			
		}
		Layout2 = new QHBoxLayout() {
			AddWidget(LabelHints)
			AddWidget(ListHints)
			
		}
		Layout3 = new QHBoxLayout() {
			AddWidget(BtnOk)
			AddWidget(BtnCancel)
			
		}
		Layout4 = new QVBoxLayout() {
			AddLayout(Layout1)
			AddLayout(Layout2)
			AddLayout(Layout3)
		}

		oMWLayoutWidget = new qWidget() { setLayout(Layout4) }
		setCentralWidget(oMWLayoutWidget) 
	}

# End of the Generated Source Code File...

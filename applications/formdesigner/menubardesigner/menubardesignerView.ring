/*
**	Project : Form Designer 
**	File Purpose :  Menubar Designer 
**	Date : 2017.04.27
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

Load "stdlibcore.ring"
Load "guilib.ring"

import System.GUI

if IsMainSourceFile() { 
	new App {
		StyleFusion()
		new menubardesignerView { win.show() } 
		exec()
	}
}

class menubardesignerView from WindowsViewParent
	win = new MainWindow() { 
		move(0,0)
		resize(872,722)
		setWindowTitle(T_FROMDESIGNER_MB_MENUBARDESIGNER)	 # "Menubar Designer"
		setLayoutDirection(T_LAYOUTDIRECTION)
		setWindowFlags(Qt_Window | Qt_WindowTitleHint | Qt_WindowCloseButtonHint | Qt_WindowStaysOnTopHint | Qt_CustomizeWindowHint) 
		Label1 = new label(win) {
			move(8,24)
			resize(164,44)
			setText(T_FROMDESIGNER_MB_MENUITEMS)	 # "Menu Items"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		TreeWidget1 = new treewidget(win) {
			move(186,29)
			resize(503,316)
			setColumnCount(1)
			oList = new qstringlist() {
				Append(T_FROMDESIGNER_MB_TEXT)	 # "Text"
			}
			setheaderlabels(oList)
			oList.delete()
			setHeaderHidden(True)
			setclickedEvent(Method(:ItemClickAction))
		}
		Button1 = new pushbutton(win) {
			move(715,29)
			resize(129,34)
			setText(T_FROMDESIGNER_MB_NEW)	 # "New"
			setClickEvent(Method(:NewAction))
		}
		Button2 = new pushbutton(win) {
			move(715,73)
			resize(129,34)
			setText(T_FROMDESIGNER_MB_DELETE)	 # "Delete"
			setClickEvent(Method(:DeleteAction))
		}
		Label2 = new label(win) {
			move(9,362)
			resize(163,31)
			setText(T_FROMDESIGNER_MB_TEXT)	 # "Text"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		Label3 = new label(win) {
			move(9,403)
			resize(163,33)
			setText(T_FROMDESIGNER_MB_IMAGE)	 # "Image"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		Label4 = new label(win) {
			move(9,446)
			resize(163,28)
			setText(T_FROMDESIGNER_MB_SHORTCUT)	 # "Shortcut"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		Label5 = new label(win) {
			move(9,484)
			resize(160,34)
			setText(T_FROMDESIGNER_MB_ACTION)	 # "Action"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		ItemText = new lineedit(win) {
			move(186,365)
			resize(503,30)
			setreturnPressedEvent(Method(:ItemTextChangeAction))
		}
		ItemImage = new lineedit(win) {
			move(186,405)
			resize(503,30)
			setreturnPressedEvent(Method(:ItemImageChangeAction))
		}
		ItemShortcut = new lineedit(win) {
			move(186,445)
			resize(503,30)
			setreturnPressedEvent(Method(:ItemShortCutChangeAction))
		}
		ItemAction = new lineedit(win) {
			move(186,485)
			resize(503,30)
			setreturnPressedEvent(Method(:ItemActionChangeAction))
		}
		Button3 = new pushbutton(win) {
			move(715,117)
			resize(129,34)
			setText(T_FROMDESIGNER_MB_CLOSE)	 # "Close"
			setClickEvent(Method(:CloseAction))
		}
		Layout1 = new QHBoxLayout() {
			AddWidget(Label1)
			AddWidget(TreeWidget1)
			
		}
		Layout2 = new QHBoxLayout() {
			AddWidget(Label2)
			AddWidget(ItemText)
			
		}
		Layout3 = new QHBoxLayout() {
			AddWidget(Label3)
			AddWidget(ItemImage)
			
		}
		Layout4 = new QHBoxLayout() {
			AddWidget(Label4)
			AddWidget(ItemShortcut)
			
		}
		Layout5 = new QHBoxLayout() {
			AddWidget(Label5)
			AddWidget(ItemAction)
			
		}
		Layout6 = new QVBoxLayout() {
			AddLayout(Layout1)
			AddLayout(Layout2)
			AddLayout(Layout3)
			AddLayout(Layout4)
			AddLayout(Layout5)
			
		}
		Layout7 = new QVBoxLayout() {
			AddWidget(Button1)
			AddWidget(Button2)
			AddWidget(Button3)
			
		}
		Layout8 = new QHBoxLayout() {
			AddLayout(Layout6)
			AddLayout(Layout7)
			
		}

		oMWLayoutWidget = new qWidget() { setLayout(Layout8) }
		setCentralWidget(oMWLayoutWidget) 
	}

# End of the Generated Source Code File...

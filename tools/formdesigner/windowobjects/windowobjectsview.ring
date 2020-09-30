/*
**	Project : Form Designer 
**	File Purpose :  Window Objects - View Class
**	Date : 2017.04.27
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class windowObjectsView from WindowsViewParent
	win = new qWidget() {
		move(64,40)
		resize(395,376)
		setWindowTitle(T_FROMDESIGNER_WO_WINDOWOBJECTS) # "Window Objects"
		setLayoutDirection(T_LAYOUTDIRECTION)
		LabelObjects = new qlabel(win) {
			move(10,13)
			resize(41,26)
			oFont = new qfont("arial",10,0,0)
			setfont(oFont)
			setText(T_FROMDESIGNER_WO_OBJECTS) # "Objects"
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		ListObjects = new qlistwidget(win) {
			move(56,13)
			resize(321,290)
			oFont = new qfont("arial",10,0,0)
			setfont(oFont)
		}
		BtnOk = new qpushbutton(win) {
			move(236,315)
			resize(68,25)
			oFont = new qfont("arial",10,0,0)
			setfont(oFont)
			setText(T_FROMDESIGNER_WO_OK) # "Ok"
			setClickEvent(Method(:okAction))

		}
		BtnCancel = new qpushbutton(win) {
			move(309,315)
			resize(68,25)
			oFont = new qfont("arial",10,0,0)
			setfont(oFont)
			setText(T_FROMDESIGNER_WO_CANCEL) # "Cancel"
			setClickEvent(Method(:CancelAction))
		}
		Layout1 = new QHBoxLayout() {
			AddWidget(LabelObjects)
			AddWidget(ListObjects)
		}
		Layout2 = new QHBoxLayout() {
			AddWidget(BtnOk)
			AddWidget(BtnCancel)
		}
		Layout3 = new QVBoxLayout() {
			AddLayout(Layout1)
			AddLayout(Layout2)
		}
		setLayout(Layout3) 
	}

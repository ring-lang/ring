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
		setWindowTitle("Window Objects")
		setstylesheet("background-color:rgba(239,235,231,255);")
		LabelObjects = new qlabel(win) {
			move(10,13)
			resize(41,26)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Objects")
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		ListObjects = new qlistwidget(win) {
			move(56,13)
			resize(321,290)
			setstylesheet("color:black;background-color:white;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
		}
		BtnOk = new qpushbutton(win) {
			move(236,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Ok")
			setClickEvent(Method(:okAction))

		}
		BtnCancel = new qpushbutton(win) {
			move(309,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Cancel")
			setClickEvent(Method(:CancelAction))
		}
	}

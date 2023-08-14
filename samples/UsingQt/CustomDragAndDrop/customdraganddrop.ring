load "guilib.ring"

lstatus     = :ReadyForNewDrag
cObjectText = NULL

app = new QApp {

	win = new QWidget() {

		setWindowTitle("Custom Drag & Drop - Drag label and drop it on itself or on another label")
		resize(600,400)

		lbl1 = new QLabel(win) {
			move(10,10) resize(100,30)
			setText("one")
			setStyleSheet("color:white;background-color:purple;font-size:14px;")
			oEvents1 = new QAllEvents(win) {
				setmousemoveevent("mousemove(oEvents1,lbl1)")
				setmousebuttonreleaseevent("mouseup(oEvents1,lbl1)")
			}
			installeventfilter(oEvents1)
		}

		lbl2 = new QLabel(win) {
			move(10,100) resize(100,30)
			setText("two")
			setStyleSheet("color:black;background-color:yellow;font-size:14px;")
			oEvents2 = new QAllEvents(win) {
				setmousemoveevent("mousemove(oEvents2,lbl2)")
				setmousebuttonreleaseevent("mouseup(oEvents2,lbl2)")
			}
			installeventfilter(oEvents2)
		}

		show()
	}
	exec()
}

func mousemove oEvents, oLbl
	if lStatus != :ReadyForNewDrag return ok
	lStatus = :DragStarted
	myx = fabs( oEvents.getx() + oLbl.x() )
	myy = fabs( oEvents.gety() + oLbl.y() )
	myobj = win.childat(myx,myy)
	if ! isnull(myobj.pObject)
		mylabel = new qlabel 
		mylabel.pObject = myobj.pObject
		cObjectText = mylabel.text()
		win.setcursor(new qcursor() { setshape(20) }  )
	ok

func mouseup oEvents, oLbl
	lStatus = :ReadyForNewDrag	
	win.setcursor(new qcursor() { setshape(0) }  )
	myx = fabs( oEvents.getx() + oLbl.x() )
	myy = fabs( oEvents.gety() + oLbl.y() )
	myobj = win.childat(myx,myy)
	if ! isnull(myobj.pObject)
		mylabel = new qlabel 
		mylabel.pObject = myobj.pObject
		mylabel.setText( mylabel.text() + " " + cObjectText )
		mylabel.resize(  mylabel.width() + (len(cObjectText)*7) , 
				 mylabel.height() )
	ok
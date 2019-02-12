load "guilib.ring"

new qApp {
	w = new qWidget() {
		setWindowTitle("Using QCalendar")
		move(100,100) resize(400,400)
		c = new qCalendarwidget(w) {
			move(20,20) resize(350,350)
		}
		b = new qPushButton(w) {
			move(20,370) resize(100,30) setText("Selected Date")
			setClickEvent("ShowDate()")
		}
		show()
	}
	exec()
}

func ShowDate 
	oDate = c.selecteddate()
	cMsg = "Day : " + oDate.day() + nl +
	       "Month : " + oDate.month() + nl +
	       "Year : " + oDate.Year() 
	msginfo("Selected Date",cMsg)

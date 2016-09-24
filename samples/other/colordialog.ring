load "guilib.ring"

new qApp {

	win = new qWidget() {
		resize(400,400)
		move(200,200)
		setWindowTitle("select color")	
		new qPushButton(win) {
			setText("Color")
			setClickEvent("pColor()")
		}
		show()
	}	
	exec()
}

func pColor

	new qColorDialog() {
		exec()		
		oColor = currentcolor()
		r = oColor.red()
		g = oColor.green()
		b = oColor.blue()
		win.setstylesheet("background-color: rgb("+r+", " + g+ "," + b + ")")
	}

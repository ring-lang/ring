
load "guilib.ring"

myApp = new qApp{

	win = new qWidget() {

		setWindowTitle("Test Button Form")
		resize(600,400)

		btn = new qPushButton(win){
			setText("Click Here")
			setGeometry(100,150,200,50)
			f = new qFont("tahoma", 16 ,70,0)
			setFont(f)
		}

		show()

	}

	exec()
}


load "guilib.ring"

my = new qApp{

	win = new qWidget(){

		resize(600,400)
		txtCSS = "border:2px solid blue;color:darkred;border-radius:20px;background-color:#aaa;"

		txt = new qLineEdit(win) {
			setText("Welcome To Egypt ☺ ♥ ☺")
			setGeometry(100,150,450,65)
			setFont( new qFont("tahoma", 18 ,0,0) )
			setStyleSheet(txtCSS)
		}

		txt2 = new qLineEdit(win) {
			setText("Hello aHMED")
			setGeometry(100,230,450,65)
			setFont( new qFont("tahoma", 18 ,0,0) )
			setStyleSheet(txtCSS)
		}

		show()
	}	

	exec()
}

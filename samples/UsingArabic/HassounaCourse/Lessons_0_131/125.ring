
load "guilib.ring"

myApp = new qApp{
	
	win = new qWidget(){
		setWindowTitle("My Form")
		resize(600,400)

		txt = new qLineEdit(win){
			setGeometry(100,150,450,60)
			setAlignment(Qt_AlignHCenter)
			setText("Welcome To Egypt ☺ ♥ ☺")
			myFont = new qFont("impact",25,1,0)			
			setFont(myFont)
		}	

		show()
	}

	exec()

}


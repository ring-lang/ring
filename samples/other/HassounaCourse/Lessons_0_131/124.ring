
load "guilib.ring"

myApp = new qApp{

	win = new qWidget(){

		setWindowTitle("My Form")
		resize(600,400)
		
		txt = new qLineEdit(win){
			//resize(450, 50)
			//move(100,150)
			setGeometry(100,150,450,50)
			setAlignment(Qt_AlignHCenter)
			setText("This Is My Text Box ☺")
		}

		show()
	}
	
	exec()	

}



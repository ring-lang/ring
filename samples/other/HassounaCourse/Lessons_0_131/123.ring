
load "guilib.ring"

myApp = new qApp{
	win = new qWidget(){
		setWindowTitle("Hello World!")
		setGeometry(180 , 150 , 600 , 400)
		//resize(600 , 400)
		//move( 180  ,  150 )
		show()
	}
	exec()
}

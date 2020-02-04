
load "guilib.ring"

myApp = new qApp{

	win = new qWidget(){

		setWinIcon( win , "Emp.png" )

		show()
	}

	exec()
}

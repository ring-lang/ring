Load "guilib.ring"

new qApp 
{
	$ObjectName = "oFirstWindow"
	oFirstWindow = new FirstWindow

	$ObjectName = "oSecondWindow"
	oSecondWindow = new SecondWindow

	exec()
}

Class FirstWindow

	win = new qWidget() {
		setgeometry(0,50,300,200)
		setWindowTitle("First Window")
		label1 = new qLabel(win)
		{
			setgeometry(10,10,300,30)
			setText("0")
		}
		btn1 = new qPushButton(win)
		{
			move(100,100)
			setText("Increment")
			setClickEvent($ObjectName+".increment()")
		}
		show()
	}	

	Func Increment
		label1 {
			setText( "" + ( 0 + text() + 1 ) )
		}


Class SecondWindow

	win = new qWidget() {
		setgeometry(400,50,300,200)
		setWindowTitle("Second Window")
		label1 = new qLabel(win)
		{
			setgeometry(10,10,300,30)
			setText("0")
		}
		btn1 = new qPushButton(win)
		{
			move(100,100)
			setText("Decrement")
			setClickEvent($ObjectName+".decrement()")
		}
		show()
	}	

	Func Decrement
		label1 {
			setText( "" + ( 0 + text() - 1 ) )
		}



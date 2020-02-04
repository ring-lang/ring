load "guilib.ring"

myApp = new qApp {

	win = new qWidget() {
		resize(350,200)

		f = new qFont("arial",16,0,0)

		lbl1 = new qLabel(win) {
			setText("Number 1: ")
			setFont(f)
			move(20,20)
		}

		txt1 = new qLineEdit(win) {
			setFont(f)
			setText("0")
			move(120,20)
		}

		lbl2 = new qLabel(win) {
			setText("Number 2: ")
			setFont(f)
			move(20,60)
		}

		txt2 = new qLineEdit(win) {
			setFont(f)
			setText("0")
			move(120,60)
		}

		btnAdd = new qPushbutton(win) {
			setFont(f)
			setText("+")
			move(20,100)
			setClickEvent("calc('+')")
		}

		btnSub = new qPushbutton(win) {
			setFont(f)
			setText("-")
			move(100,100)
			setClickEvent("calc('-')")
		}

		btnMulti = new qPushbutton(win) {
			setFont(f)
			setText("*")
			move(180,100)
			setClickEvent("calc('*')")
		}

		btnDiv = new qPushbutton(win) {
			setFont(f)
			setText("/")
			move(260,100)
			setClickEvent("calc('/')")
		}

		lblR = new qLabel(win) {
			setText("0")
			resize(200,60)
			setFont(f)
			move(20,130)
		}

		show()
	}

	exec()
}

func calc(ope){
	num1 = number( txt1.Text() )
	num2 = number( txt2.Text() )
	if ope="+"
		lblR.setText( string( num1 + num2 ) )
	but ope="-"
		lblR.setText( string( num1 - num2 ) )
	but ope="*"
		lblR.setText( string( num1 * num2 ) )
	else
		if num2!=0 lblR.setText( string( num1 / num2 ) ) ok
	ok
}

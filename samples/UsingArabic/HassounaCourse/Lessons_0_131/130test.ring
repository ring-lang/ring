load "guilib.ring"

myapp = new qApp{

	win = new qWidget() {

		resize(350,200)
		setWindowTitle("My Calculator")

		myFont = new qFont("arial",16,0,0)
		lbl1 = new qLabel(win) {
			move(20,20)
			setText("Number 1:")
			setFont(myFont)
		}

		txt1 = new qLineEdit(win) {
			move(120,20)
			setFont(myFont)
			setText("7")
		}

		lbl2 = new qLabel(win) {
			move(20,60)
			setText("Number 2:")
			setFont(myFont)
		}

		txt2 = new qLineEdit(win) {
			move(120,60)
			setFont(myFont)
			setText("3")
		}

		btnAdd = new qPushButton(win) {
			setFont(myFont)
			move(20,100)
			setText("+")
			setClickEvent("calc('+')")
		}

		btnSub = new qPushButton(win) {
			setFont(myFont)
			move(100,100)
			setText("-")
			setClickEvent("calc('-')")
		}

		btnMulti = new qPushButton(win) {
			setFont(myFont)
			move(180,100)
			setText("*")
			setClickEvent("calc('*')")
		}

		btnDiv = new qPushButton(win) {
			setFont(myFont)
			move(260,100)
			setText("/")
			setClickEvent("calc('/')")
		}

		lblR = new qLabel(win) {
			move(20,150)
			resize(200,30)
			setText("0")
			setFont(myFont)
		}

		show()
	}

	exec()

}

func calc(ope){
	num1 = number( txt1.Text() )
	num2 = number( txt2.Text() )
	if ope="+"
		lblR.setText( string(num1+num2) )
	but ope="-"
		lblR.setText( string(num1-num2) )
	but ope="*"
		lblR.setText( string(num1*num2) )
	else
		if num2!=0	lblR.setText( string(num1/num2) ) ok
	ok
}

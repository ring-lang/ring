
load "guilib.ring"

myApp = new qApp{

	win = new qWidget() {

		setWindowTitle("Test Button Form")
		resize(600,400)

		f = new qFont("tahoma", 16 ,70,0)

		lbl = new qLabel(win){
			myF = new qFont("tahoma",25,80,0)
			setFont(myF)
			resize(600,65)
			setAlignment(Qt_AlignHCenter)
		}

		txt = new qLineEdit(win){
			setFont(f)
			move(100,100)
		}

		btn = new qPushButton(win){
			setText("Click Here")
			setGeometry(100,170,200,50)
			setFont(f)
			/////setClickEvent("lbl.setText('Hello')")
			///setClickEvent("lbl.setText('Hello ' + txt.Text())")
			setClickEvent("sayHello() setBtn()")
		}

		show()

	}

	exec()
}


func sayHello(){
	lbl.setText("Hello " + txt.Text())
}

func setBtn(){
	btn.setText("Now Pressed")
}


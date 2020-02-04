
load "guilib.ring"

myApp = new qApp{

	frm = new qWidget(){
		setWindowTitle("My Test Form")
		resize(700,500)
		myFont = new qFont("Tahoma",14,70,0)
		setFont(myFont)
		lblHeader = new qLabel(frm){
			setText("Employee Form")
			resize(700,60)
			setAlignment(Qt_AlignHCenter)
			headerFont = new qFont("impact",35,0,0)
			setFont(headerFont)
		}

		lbl = new qLabel(frm){
			setText("Employee Name")
			
			//setFont(myFont)			
			move(20,150)
		}

		txt = new qLineEdit(frm){
			//setFont(myFont)
			move(190,150)
			//resize(700,50)
			setAlignment(Qt_AlignHCenter)
		}

		show()
	}	

	exec()
}

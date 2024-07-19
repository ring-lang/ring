#----------------------------------------------#
# Application 	: Factorial Recursion Function #
# Author	: Tawfik Yasser Tawfik         #
# Date		: 07-09-2020                   #
#----------------------------------------------#
# -------- First Program in Ring --------------#

/* You can type the number and automatically
   the factorial values will be calculated
   and also if you pressed the Calculate Button.
*/

load "guilib.ring"

facApp = new qApp {

	window = new qWidget() {

		setWindowTitle("Factorial")
        	setFixedSize(400,400)
		setWinIcon(self, "facImg.png")

		//Label for header 
		lblHeader = new qLabel(window) {
			setText("Factorial Calculator using Tail Recursion")
			setGeometry(78,12,248,42)
			setAlignment(Qt_AlignHCenter)
		}
			
		// LineEdit to takes the number	
		numEdit = new qLineEdit(window) {
			setGeometry(51,68,297,47)
			setTextChangedEvent("calcFac(numEdit.text())")
		}
		
		//Button Calculating
		btnCalc = new qPushbutton(window) {
			setGeometry(104,166,177,57)
			setText("Calculate")
			setClickevent("calcFac(numEdit.text())")

		}
		
		//Label to show the result 
		lblRes = new qLabel(window) {
			setText("Result")
			setGeometry(118,257,144,63)
			setAlignment(Qt_AlignHCenter)
		}

		show()
		
	}

	exec()

}

func calcFac n

	try     
	if n < 251
		lblRes.setText(String(fact(n)))
	else
		lblRes.setText("")
	ok
	catch done

func fact x 

	if x = 0 return 1 
	else return x * fact(x-1) 
	ok

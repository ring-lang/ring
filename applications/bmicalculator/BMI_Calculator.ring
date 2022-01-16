#--------------------------------#
# Application 	: BMI Calculator #
# Author	: Ahmed Mohamed  #
# Date		: 25-11-2019     #
#--------------------------------#


load "lightguilib.ring"
load "sqlitelib.ring"

win2 = null

app = new qApp {
	win = new qWidget() {
			
		setWindowTitle("BMI")
		setWinIcon(self, "bmi_icon.png")
        	setFixedSize(290,355)			
		

		lblHeader = new qLabel(win) {
			setText("BMI Calculator")
			setFont(new qFont("Tahoma",15,100,0))
			setGeometry(0,10,290,60)
			setAlignment(Qt_AlignHCenter)
			setStyleSheet("text-decoration:underline")
		}

		lblWeight = new qLabel(win){
			setText("Weight (KM)")
			setFont(new qFont("Tahoma",8,100,0))
			setGeometry(10,70,200,30)
			setStyleSheet("color:navy")
		}

	        txtWeight = new qlineedit(win) {
	            	setGeometry(100, 70, 180,30)
			setAlignment(Qt_AlignHCenter)
		    	setStyleSheet("background-color: lightyellow;color:darkred;font-size: 15pt;")         
			setTextChangedevent("numbersOnly('Weight')")		        
		}

		lblLength = new qLabel(win){
			setText("Length (CM)")
			setFont(new qFont("Tahoma",8,100,0))
			setGeometry(10,110,200,30)
			setStyleSheet("color:navy")
		}

	        txtLength = new qlineedit(win) {
	            	setGeometry(100, 110, 180,30)
	            	setAlignment(Qt_AlignHCenter)
	            	setStyleSheet("background-color: lightyellow;color:darkred;font-size: 15pt;")         
			setTextChangedevent("numbersOnly('Length')")		        
	        
		}

		btnCalc = new qPushButton(win){
			setGeometry(20,150,120,40)
			setText("Calculate BMI")
			setFont(new qFont("Tahoma",10,100,0))
			setClickevent("calculateBMI()")
			setStyleSheet("background-color:#49afcd;border:2px solid #2f96b4;border-radius:7px;color:#ffffff;")
		}

		btnClear = new qPushButton(win){
			setGeometry(150,150,50,40)
			setText("Clear")
			setFont(new qFont("Tahoma",10,100,0))
			setClickevent("clearFields()")
			setStyleSheet("background-color:#49afcd;border:2px solid #2f96b4;border-radius:7px;color:#ffffff;")
		}

		btnExit = new qPushButton(win){
			setGeometry(210,150,50,40)
			setText("Exit")
			setFont(new qFont("Tahoma",10,100,0))
			setClickevent("exitApp()")
			setStyleSheet("background-color:#da4f49;border:2px solid #bd362f ;border-radius:7px;color:#ffffff;")
		}

		lblBMI = new qLabel(win) {
			setGeometry(20,200,240,40)
			setFont(new qFont("Tahoma",15,100,0))
			setAlignment(Qt_AlignVCenter | Qt_AlignHCenter)
			setStylesheet("background-color: #2196F3; border: 3px solid #BBB")		
		}

		lblResult = new qLabel(win) {
			setGeometry(20,250,240,40)
			setFont(new qFont("Tahoma",10,100,0))
			setAlignment(Qt_AlignVCenter | Qt_AlignHCenter)
		}

		btnHistory = new qPushbutton(win) {
			setGeometry(20,300,240,40)
			setText("History")
			setFont(new qFont("Tahoma",10,100,0))
			setClickevent("BMIhistory()")
			setStyleSheet("background-color:#49afcd;border:2px solid #2f96b4;border-radius:7px;color:#ffffff;")
		}

		show()	
	}
	exec()
}


func calculateBMI
	weight = 0 + (txtWeight.text())
	length = 0 + (txtlength.text())
  
	if weight = 0 or length = 0 
		messageBox("Fields Cannot Be Empty")
		bye	
	ok

	lengthInMeters = length / 100 # Convert Length To Meters
	SquareLength = lengthInMeters * lengthInMeters # Multiply the lengthInMeters in the same
	PersonBMI = weight / squareLength

	 lblBMI.setText("Your BMI Is " + floor(PersonBMI))

	
	if PersonBMI < 16
		lblResult.setText("Very severely underweight")
		lblResult.setStylesheet("background-color: #74b9ff; border: 3px solid #BBB; color: #FFF")
	but PersonBMI >= 16 and PersonBMI < 18.5
		lblResult.setText("underweight")
		lblResult.setStylesheet("background-color: #74b9ff; border: 3px solid #BBB; color: #FFF")
	but PersonBMI >= 18.5 and PersonBMI < 25
		lblResult.setText("Normal (healthy weight)")
		lblResult.setStylesheet("background-color: #dfe6e9; border: 3px solid #BBB; color: #00b894")
	but PersonBMI >= 25 and PersonBMI < 30
		lblResult.setText("Overweight")
		lblResult.setStylesheet("background-color: #fdcb6e; border: 3px solid #BBB; color: #FFF")
	but PersonBMI >= 30 and PersonBMI < 35
		lblResult.setText("Moderately obese")
		lblResult.setStylesheet("background-color: #f39c12; border: 3px solid #BBB; color: #FFF")
	but PersonBMI >= 35 and PersonBMI <= 40
		lblResult.setText("Severely obese")
		lblResult.setStylesheet("background-color: #e74c3c; border: 3px solid #BBB; color: #FFF")
	but PersonBMI > 40
		lblResult.setText("Very severely obese")
		lblResult.setStylesheet("background-color: #e74c3c; border: 3px solid #BBB; color: #FFF")
	ok
	
	insertBMI()



func numbersOnly txtName

	if txtName = "Weight"

		weight = txtWeight.text()
		if not isdigit(weight) and weight != 0
			removeChar = substr(weight, 1, len(weight) - 1)
			txtWeight.setText(removeChar)
		ok

	but txtName = "Length"

		length = txtLength.text()

		if not isdigit(length) and length != 0 
			removeChar = substr(length, 1, len(length) - 1)
			txtLength.setText(removeChar)	
		ok

	ok


func clearFields
	txtWeight.setText("")
	txtLength.setText("")
	lblBMI.setText("")
	lblResult.setText("")
	lblResult.setstylesheet("")


func exitApp
	App.quit()


func BMIhistory
	name = "Ahmed"
	win2 = new qWidget() {
        	setwindowtitle("History Of BMI Calculator")
		setwinicon(self, "bmi_icon.png")
	        setparent(win)
		setFixedSize(800,300)
        	setwindowflags(qt_dialog)

		table1 = new qTableWidget(win2) {
            		setGeometry(10,10,780,250)
            		setcolumncount(5)
		       	setHorizontalHeaderItem(0, new QTableWidgetItem("Weight"))
		       	setHorizontalHeaderItem(1, new QTableWidgetItem("Length"))
		        setHorizontalHeaderItem(2, new QTableWidgetItem("BMI"))
		        setHorizontalHeaderItem(3, new QTableWidgetItem("Result"))
		        setHorizontalHeaderItem(4, new QTableWidgetItem("Date") )			
            		setcolumnwidth(3,180)
            		setcolumnwidth(4,180)

			oSQLite = sqlite_init()
			sqlite_open(oSQLite,"bmiHistory.db")
			Data = sqlite_execute(oSQLite, "SELECT * FROM bmiTable")
			x = 0

			for row in data	
               			insertrow(x)
                		setitem(x,0,new qtablewidgetitem(row[:weight]))
                		setitem(x,1,new qtablewidgetitem(row[:length]))
                		setitem(x,2,new qtablewidgetitem(row[:bmi]))
                		setitem(x,3,new qtablewidgetitem(row[:result]))
                		setitem(x,4,new qtablewidgetitem(row[:bmi_date]))		
				x++							
			next
			sqlite_close(oSQLite)
		}

		new qPushbutton(win2) {
            		setGeometry(10,265,100,30)
			setText("Delete")
			setclickevent("deleteBMI()")
		}


		show()
	}	


func insertBMI
	weight 	= txtWeight.text()
	length 	= txtLength.text()
	bmi	= lblBMI.text()
	result 	= lblResult.text()

	oSQLite = sqlite_init()
	sqlite_open(oSQLite,"bmiHistory.db")
    	sqlite_execute(oSQLite, "insert into `bmiTable` (`weight`, `length`, `bmi`, `result`) values('"+ weight +"','"+ length +"', '"+ bmi +"', '"+ result +"');")
	sqlite_close(oSQLite)

func deleteBMI
	oSQLite = sqlite_init()
	sqlite_open(oSQLite,"bmiHistory.db")
    	sqlite_execute(oSQLite, "DELETE FROM bmiTable")
	sqlite_close(oSQLite)
	win2.close()
	BMIhistory()

func messageBox msg
        new qmessagebox(win){
            settext(msg)
            show()
        }



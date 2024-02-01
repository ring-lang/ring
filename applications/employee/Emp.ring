###----------------------------------------------------------
### Employee Application
### 2017-10-23  Ahmed Hassouna
### Video : https://www.youtube.com/watch?v=gY6ybUam7Yc
###----------------------------------------------------------


load "lightguilib.ring"
load "stdlibcore.ring"

import System.GUI

empNum = 0
btnCursor = new qCursor() { setShape(Qt_PointingHandCursor) }

myApp = new App {

	win1 = new Window() {

		myFont = new Font("Tahoma",14,100,0)

		setWindowTitle("Employee Data With Images ☺")
		setGeometry(260,125, 900, 500)
		setFont(myFont)
		setwinicon(win1, CurrentDir() + "/Image/emp.png")
		setStyleSheet("background-color:#fff;")

		cssText    = "border:1px solid black;border-radius:7px;color:blue;"
		cssLabel   = "color:navy;"
		cssButton = "QPushButton{background-color:navy;border:2px solid #9977fa;border-radius:7px;color:lightblue;} QPushButton:hover{color:navy;background-color:lightblue;} QPushButton:pressed{color:#aaa;background-color:#33116a; }"

		lblHeader = new qLabel(win1) {
			setText("Employee Data Form")
			setFont(new qFont("Tahoma",24,100,0))
			setGeometry(0,20,900,60)
			setAlignment(Qt_AlignHCenter)
			setStyleSheet("text-decoration:underline")
		}

		lblEmpNO = new Label(win1){
			setText("Employee NO:")
			setGeometry(20,100,200,30)
			setStyleSheet(cssLabel)
		}

		txtEmpNO = new LineEdit(win1) {
			setGeometry(210,101,450,30)
			setAlignment(Qt_AlignHCenter)
			setStyleSheet(cssText)
		}

		lblEmpName = new Label(win1){
			setText("Name:")
			setGeometry(20,150,200,30)
			setStyleSheet(cssLabel)
		}

		txtEmpName = new LineEdit(win1) {
			setGeometry(210,151,450,30)
			setAlignment(Qt_AlignHCenter)
			setStyleSheet(cssText)
		}

		lblAddress = new Label(win1){
			setText("Address:")
			setGeometry(20,200,200,30)
			setStyleSheet(cssLabel)
		}

		txtAddress = new LineEdit(win1) {
			setGeometry(210,201,450,30)
			setAlignment(Qt_AlignHCenter)
			setStyleSheet(cssText)
		}

		lblSalary = new Label(win1) {
			setText("Salary:")
			setGeometry(20,250,200,30)
			setStyleSheet(cssLabel)
		}

		txtSalary = new LineEdit(win1) {
			setGeometry(210,251,450,30)
			setAlignment(Qt_AlignHCenter)
			setStyleSheet(cssText)
		}

		lblEmpImage = new Label(win1) {
			setText("Image:")
			setGeometry(20,300,200,30)
			setStyleSheet(cssLabel)
		}

		txtImagePath = new LineEdit(win1) {
			setGeometry(210,301,450,30)
			setReadOnly(true)
			setStyleSheet(cssText)
		}

		btnSelectImage = new PushButton(win1) {
			setGeometry(680,301,190,30)
			setText("Select Image")
			setStyleSheet(cssButton)
			setClickEvent("openImage()")
			setCursor( btnCursor )
		}

		imgEmp = new label(win1) {
			move(680,100)
			resize(190,183)
			setstylesheet("border:2px solid black;border-radius:7px;")
			setScaledContents(true);
		}

		btnSave = new PushButton(win1){
			setGeometry(20+38,390,150,40)
			setText("Add New")
			setClickEvent("addEmp()")
			setStyleSheet(cssButton)
			setCursor( btnCursor )
		}

		btnFind = new PushButton(win1){
			setGeometry(180+38,390,150,40)
			setText("Find")
			setClickEvent("findEmp()")
			setStyleSheet(cssButton)
			setCursor( btnCursor )
		}

		btnClear = new PushButton(win1){
			setGeometry(340+38,390,150,40)
			setText("Clear")
			setClickEvent("clearData()")
			setStyleSheet(cssButton)
			setCursor( btnCursor )
		}

		btnDelete = new PushButton(win1){
			setGeometry(500+38,390,150,40)
			setText("Delete")
			setClickEvent("delEmp()")
			setStyleSheet(cssButton)
			setCursor( btnCursor )
		}

		btnExit = new PushButton(win1){
			setGeometry(660+38,390,150,40)
			setText("Exit")
			setClickEvent("myApp.quit()")
			setStyleSheet(cssButton)
			setCursor( btnCursor )
		}

		show()

	}

	exec()

}

func msgBox(text) {
	m = new qMessageBox(win1) {
		setWindowTitle("H Academy")
		setText(text)
		show()
	}
}

func inBox(text) {
	oInput = New QInputDialog(win1)
	{
		setwindowtitle(text)
		setlabeltext(text)
		settextvalue("111")
		lcheck = exec()
		if lCheck empNum = oInput.textvalue() ok
	}
}

func openImage {
	new qfiledialog(win1) {
		cName = getopenfilename(win1,"open file","","Images Files(*.jpg;*.png)")
		imgEmp.setPixMap(New qPixMap(cName))
		txtImagePath.setText(cName)
	}
}

func clearData {
	txtEmpNO.setText("")
	txtEmpName.setText("")
	txtAddress.setText("")
	txtSalary.setText("")
	txtImagePath.setText("")
	imgEmp.clear()
	txtEmpNO.setFocus(0)
}

func addEmp {
	try
		if dirExists("data") = 0 System('mkdir data') ok
		if dirExists("data/img") = 0 System('mkdir data\img') ok	
		filePath = 'data/' + txtEmpNO.Text() +  '.txt'	
		if fExists(filePath) = 0
			f = fOpen( filePath , 'w')
			data = '' + txtEmpNO.Text() + nl + txtEmpName.Text() + nl + txtAddress.Text() + nl + txtSalary.Text() + nl
			fPuts( f , data )
			fClose(f)
			distPath = txtImagePath.Text()
			toPath    = currentDir() + "/data/img/" + txtEmpNO.Text() + ".jpg"
			if isWindows()
				distPath = subStr(distPath , "/" , "\")
				toPath = subStr(toPath , "/" , "\")
			ok
			system("copy " + distPath + " " + toPath )
			msgBox("Employee is Added...")
			clearData()
		else
			msgBox("This Employee Already Exists !")
		ok
	catch	
		msgBox(cCatchError)
	end
}

func findEmp {
	try
		inBox("Enter Employee NO")
		empPath = 'data/' + empNum + '.txt'
		if fExists(empPath) = 0
			msgBox("This Employee Not Exists !")
			clearData()
		else
			f = fOpen(empPath , "r")
			txtEmpNO.setText(readLine(f))
			txtEmpName.setText(readLine(f))
			txtAddress.setText(readLine(f))
			txtSalary.setText(readLine(f))
			imgPath = "data/img/" + subStr(txtEmpNO.Text() , 1 , len(txtEmpNO.Text())-1   ) + '.jpg'
			if fExists(imgPath)
				imgEmp.setPixMap(New qPixMap( imgPath ))
			ok
		ok
	catch
		msgBox(cCatchError)
	end
}

func delEmp {
	try
		inBox("Enter Employee NO")
		empPath = 'data/' + empNum + '.txt'
		if fExists(empPath)
			remove(empPath)
			msgBox("Employee Is Deleted...")
			clearData()
		else
			msgBox("This Employee Not Exists !")
		ok
		imgPath = "data/img/" + subStr(txtEmpNO.Text() , 1 , len(txtEmpNO.Text())-1   ) + '.jpg'
		if fExists(imgPath)
			remove(imgPath)
		ok
	catch
		msgBox(cCatchError)
	end
}

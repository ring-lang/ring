load "guilib.ring"

oFormDesigner = new FormDesigner { start("oFormDesigner") }

Class FormDesigner

	winToolBox  winForm

	aObjects = []

	func start cObjectName

		oApp = new qApp

		winToolBox = new qWidget() 
		winToolBox.setWindowTitle("ToolBox")
		winToolBox.move(10,10)
		winToolBox.resize(300,600)
		
		btn = new qPushButton(winToolBox) 
		btn.resize(300,30)
		btn.setText("Create Button")
		btn.setClickEvent(cObjectName+".pCreateButton()")
		btn.show()		

		winToolBox.show()

		winForm = new qWidget() {
			move(400,50)
			setWindowTitle("Form Designer")
			resize(600,600)
			show()	
		}

		oApp.exec()


	func pCreateButton		

		nCount = len(aObjects)

		aObjects + new MyButton(winForm) 
		{
			nIndex = nCount + 1
			setText("Button"+ nIndex) 
			Move(30*nIndex,30*nIndex)
			resize(100,30)
			show()
		}


Class MyButton from qPushButton
	nIndex = 0

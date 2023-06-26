oSelectFile       = NULL
oSelectFileList   = NULL
oSelectFileFilter = NULL

class RNoteSelectFile

	func OpenSelectFileWindow

		if len(aFilesLines) < 2
			msginfo(T_RINGNOTEPAD_SELECTFILESORRY,T_RINGNOTEPAD_SELECTFILEMSG)
			return 
		ok

		oSelectFile = new QWidget() {
			setwindowtitle(T_RINGNOTEPAD_SELECTFILETEXT) # "Select File"
			resize(400,350)
			setwindowflags(Qt_WindowStaysOnTopHint)

			oLabel = new QLabel(oSelectFile) {
				setGeometry(50,30,100,20)
				settext(T_RINGNOTEPAD_SELECTFILETEXTCOLON) # "Select File: "
			}
          
			oSelectFileList = new QListWidget(oSelectFile) {
				setGeometry(150,30,200,200)
				oSelectFileList.setitemactivatedEvent(Method(:SelectFileOkAction))
				for cFile in this.aFilesLines
					additem(cFile[1])
				next 
			}
 
			BtntnOk = new qpushbutton(oSelectFile) {
				setgeometry(180,250,50,50)
				setText(T_RINGNOTEPAD_SELECTFILEOK)
				setClickEvent(Method(:SelectFileOkAction))
			}

			BtnCancel = new qpushbutton(oSelectFile) {
				setgeometry(250,250,50,50)
				setText(T_RINGNOTEPAD_SELECTFILECANCEL)
				setClickEvent(Method(:SelectFileCancelAction))
			}

			oSelectFileLayout1 = new qVBoxlayout() {
				AddWidget(oLabel)
				AddWidget(oSelectFileList)
			}

			oSelectFileLayout2 = new qVBoxlayout() {
				AddWidget(BtntnOk)
				AddWidget(BtnCancel)
			}

			LayoutButtonMain = new QHBoxLayout()			
			LayoutButtonMain.AddLayout(oSelectFileLayout1)
			LayoutButtonMain.AddLayout(oSelectFileLayout2)

			setLayout(LayoutButtonMain)
			setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint) 

			oSelectFileFilter = new qallevents(oSelectFile)
			oSelectFileFilter.setKeyPressEvent(Method(:SelectFileKeyPress))
			installeventfilter(oSelectFileFilter)

			show()

		}

	func SelectFileOkAction

		nIndex = oSelectFileList.currentRow()+1
		if (nIndex > 0) and (nIndex <= len(aFilesLines))
			cFile = aFilesLines[nIndex][1]
			nRow  = aFilesLines[nIndex][2]		
			CheckSaveBeforeChange()
			cActiveFileName = cFile 
			openFile(cFile)
			GotoLine(nRow)		
			displayFunctionsList()
			displayClassesList()
			lAsktoSave = False
			cTextHash  = sha256(textedit1.toplaintext())
			oDockSourceCode.raise()
			SelectFileCancelAction()
		ok

	func SelectFileCancelAction
		oSelectFile.close()

	func SelectFileKeyPress
		if oSelectFileFilter.getKeyCode() = Qt_Key_Escape
			SelectFileCancelAction()
		ok

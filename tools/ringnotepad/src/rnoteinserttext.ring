oInsert 	= NULL
templateList 	= NULL

load "templates.ring"

class RNoteInsertText

	func OpenInsertWindow

		oInsert = new QWidget() {
			setwindowtitle(T_RINGNOTEPAD_INSERTTEXT) # "Insert Text"
			resize(400,350)
			setwindowflags(Qt_WindowStaysOnTopHint)


			templateLabel = new QLabel(oInsert) {
				setGeometry(50,30,100,20)
				settext(T_RINGNOTEPAD_INSERTTEXTCOLON) # "Insert Text : "
			}
          
			templateList = new QListWidget(oInsert) {
				setGeometry(150,30,200,200)
				for aCodeTemplate in aCodeTemplates
					addItem(aCodeTemplate[1])
				next	
				templateList.setitemactivatedEvent(Method(:insertText))
			}
 
			BtntnOk = new qpushbutton(oInsert) {
				setgeometry(180,250,50,50)
				setText(T_FROMDESIGNER_WF_OK)
				setClickEvent(Method(:insertText))
			}

			BtnCancel = new qpushbutton(oInsert) {
				setgeometry(250,250,50,50)
				setText(T_FROMDESIGNER_WF_CANCEL)
				setClickEvent(Method(:pCancel))
			}

			oInsertLayout1 = new qVBoxlayout() {
				AddWidget(templateLabel)
				AddWidget(templateList)
			}

			oInsertLayout2 = new qVBoxlayout() {
				AddWidget(BtntnOk)
				AddWidget(BtnCancel)
			}

			LayoutButtonMain = new QHBoxLayout()			
			LayoutButtonMain.AddLayout(oInsertLayout1)
			LayoutButtonMain.AddLayout(oInsertLayout2)

			setLayout(LayoutButtonMain)
			setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint) 
			show()

		}

       func insertText

		nr = templateList.currentRow()+1
		cFunction = aCodeTemplates[nr][2]
		output = call cFunction()
		textedit1.textcursor().insertText(output)

	func pCancel

		oInsert.close()

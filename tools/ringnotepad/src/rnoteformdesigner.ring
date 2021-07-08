# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteFormDesigner

	func FormDesignerDock
		cDir = CurrentDir()
		chdir(exefolder() + "/../tools/formdesigner")
		# Import Classes 
			import formdesigner 
		open_windowAndLink(:FormDesignerController,self)
		# We still use setParentObject() and avoid using
		# IsRNOTE() and RNote() in the Form Designer 
		# So we can reuse the Form Designer in other Projects
		# I.e. Ring Notepad need to know about the Form Designer 
		# But It's necessary for the Form Designer to Know that
		# It's used in another project!
		FormDesigner().setParentObject(self)
		oDockFormDesigner.setWidget(FormDesigner().oView.win)
		chdir(cDir)

	func ClearActiveFormFile
		cFormFile = ""

	func NewEventName cFunctionName 
		cStr = textedit1.toPlainText()	
		nPos = substr(cStr,"func " + cFunctionName)
		if nPos = 0
			cStr += WindowsNL() + 
				Tab + "func " + cFunctionName + WindowsNL() +
				Tab + Tab + "oView {" + WindowsNL() +
				Tab + Tab + Tab + WindowsNL() + 
				Tab + Tab + "}" + WindowsNL()
			textedit1.setPlainText(cStr)
		else
			oCursor = textedit1.textcursor()
			oCursor.setposition(nPos,0)
			textedit1.settextcursor(oCursor) 			
		ok

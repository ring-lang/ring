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
		cFunctionName = trim(cFunctionName)
		# Be sure that we have saved form file 
			if FormDesigner().ActiveFileName() = "" return ok
		# Be sure that the Controller class source code is opened
			if lower(cActiveFileName) != lower(substr(FormDesigner().ActiveFileName(),".rform","Controller.ring"))
				return 
			ok
		# Be sure that the event code doesn't contains (, ', ", ` and spaces
			if substr(cFunctionName," ") or 			
			   substr(cFunctionName,"'") or 
			   substr(cFunctionName,'"') or 
			   substr(cFunctionName,"`") or 
			   substr(cFunctionName,"(")
				return 
			ok


		# Be sure that the event code doesn't exist before 
			cStr = textedit1.toPlainText()	
			nPos = substr(cStr,"func " + cFunctionName)
		if nPos = 0
			# Create the Event Code
				cStr = WindowsNL() + 
					Tab + "func " + cFunctionName + WindowsNL() +
					Tab + Tab + "oView {" + WindowsNL() +
					Tab + Tab + Tab + WindowsNL() + 
					Tab + Tab + "}" + WindowsNL()
				textedit1.appendPlainText(cStr)
		ok

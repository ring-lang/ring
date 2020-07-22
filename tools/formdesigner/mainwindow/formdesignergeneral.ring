/*
**	Project : Form Designer 
**	File Purpose :  Form Designer General
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

Class FormDesignerGeneral from ObjectsParent 

	oCursor =  new QCursor()

	oColor = new QColorDialog() {
		SetColorSelectedEvent(Method("oGeneral.NewColor"))
	}	
	cColorOperation = :None

	oFont = new QFontDialog() {
			setFontSelectedEvent(Method("oGeneral.NewFont"))
	}
	cFontOperation = :None

	func FormDesigner 
		return Me()

	func oCursorA
		oCursor.setShape(Qt_ArrowCursor)
		return oCursor

	func oCursorF
		oCursor.setShape(Qt_SizeFDiagCursor)
		return oCursor

	func oCursorB
		oCursor.setShape(Qt_SizeBDiagCursor)
		return oCursor

	func oCursorH
		oCursor.setShape(Qt_SizeHorCursor)
		return oCursor

	func oCursorV
		oCursor.setShape(Qt_SizeVerCursor)
		return oCursor

	func NewColor 
		oNewColor = oColor.selectedcolor()
		r = oNewColor.red()
		g = oNewColor.green()
		b = oNewColor.blue()
		r=hex(r) g=hex(g) b=hex(b)
		if len(r) < 2 { r = "0" + r }
		if len(g) < 2 { g = "0" + g }
		if len(b) < 2 { b = "0" + b }
		cColor = "#" + r + g + b

		Switch cColorOperation {
			case :TextColor 
				FormDesigner().oModel.ActiveObject().ApplyTextColor(FormDesigner(),cColor)
			case :BackColor 
				FormDesigner().oModel.ActiveObject().ApplyBackColor(FormDesigner(),cColor)
			case :MSTextColor 
				FormDesigner().ApplyMSTextColor(cColor)
			case :MSBackColor 
				FormDesigner().ApplyMSBackColor(cColor)
		}

	func SelectColor		
		oColor.Show()

	func NewFont
		cFont = oFont.selectedfont().tostring()
		switch cFontOperation {
			case :font 
				FormDesigner().oModel.ActiveObject().ApplyFont(FormDesigner(),cFont)
			case :MSFont 
				FormDesigner().ApplyMSFont(cFont)
		}

	func SelectFont
		oFont.show()

	func SelectFile oDesigner
		if ! isWebAssembly() {
			oFileDialog = new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getopenfilename(oDesigner.oView.win,"Open File",currentdir(),"*.*")
			}
			return cInputFileName
		else 
			WebAssemblyUpload("Image Files (*)",Method("oGeneral.NewImageFile"))
		}

	func NewImageFile 
		cInputFileName = WebAssemblyUploadedFileName()
		if fexists( cInputFileName ) {
			remove( cInputFileName )
		}
		Write(   cInputFileName ,
			 WebAssemblyUploadedFileContent()
		)
		FormDesigner().oModel.ActiveObject().ApplyOpenImageFile(FormDesigner(),cInputFileName)

/*
**	Project : Form Designer 
**	File Purpose :  Form Designer General
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

Class FormDesignerGeneral

	func oCursorA
		oCursor =  new qCursor()
		oCursor.setShape(Qt_ArrowCursor)
		return oCursor

	func oCursorF
		oCursor =  new qCursor()
		oCursor.setShape(Qt_SizeFDiagCursor)
		return oCursor

	func oCursorB
		oCursor =  new qCursor()
		oCursor.setShape(Qt_SizeBDiagCursor)
		return oCursor

	func oCursorH
		oCursor =  new qCursor()
		oCursor.setShape(Qt_SizeHorCursor)
		return oCursor

	func oCursorV
		oCursor =  new qCursor()
		oCursor.setShape(Qt_SizeVerCursor)
		return oCursor

	func SelectColor
		oColor = new qColorDialog()
		aColor = oColor.GetColor()
		r=hex(acolor[1]) g=hex(acolor[2]) b=hex(acolor[3])
		if len(r) < 2 { r = "0" + r }
		if len(g) < 2 { g = "0" + g }
		if len(b) < 2 { b = "0" + b }
		cColor = "#" + r + g + b
		return cColor

	func SelectFont
		cFont = ""
		oFontDialog = new qfontdialog() {
			aFont = getfont()
		}
		if aFont[1] != NULL {
			cFont = aFont[1]
		}
		return cFont

	func SelectFile oDesigner
		new qfiledialog(oDesigner.oView.win) {
			cInputFileName = getopenfilename(oDesigner.oView.win,"Open File",currentdir(),"*.*")
		}
		return cInputFileName


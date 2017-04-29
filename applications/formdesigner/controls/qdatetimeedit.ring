/*
**	Project : Form Designer 
**	File Purpose :  QDateTime Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

class FormDesigner_QDateTimeEdit from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))


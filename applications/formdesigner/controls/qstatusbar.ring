/*
**	Project : Form Designer 
**	File Purpose :  QStatusbar Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QStatusbar from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cMessage = ""

	func MessageValue
		return cMessage

	func SetMessageValue cValue
		cMessage = cValue

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Message",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(MessageValue())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON {
			setMessageValue(cValue)
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :Message =  "' + oDesigner.PrepareStringForFormFile(MessageValue()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'ShowMessage("#{f1}",0)' + nl +
				'win.setStatusBar(#{f2})'
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(MessageValue()))
		cOutput = substr(cOutput,"#{f2}",oDesigner.oModel.GetObjectName(self))
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setMessageValue(itemdata[:Message])

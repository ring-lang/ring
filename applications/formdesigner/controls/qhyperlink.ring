/*
**	Project : Form Designer 
**	File Purpose :  QHyperLink Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QHyperLink from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cLink = "http://www.ring-lang.net"
	cText = "Ring Language Website"

	func LinkValue
		return cLink

	func SetLinkValue cValue
		cLink = cValue

	func TextValue
		return cText

	func SetTextValue cValue
		cText = cValue
		cOutput = '<a href="#{f1}">#{f2}</a>'
		cOutput = substr(cOutput,"#{f1}",LinkValue())
		cOutput = substr(cOutput,"#{f2}",TextValue())
		setText(cOutput)

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Link",False)
		oDesigner.oView.AddProperty("Text",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Link Value
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(LinkValue())
		# Set the Text Value
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(TextValue())
		oPropertiesTable.Blocksignals(False)
		setTextValue(cText)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON
				setLinkValue(cValue)
			case C_AFTERCOMMON + 1
				setTextValue(cValue)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :Link =  "' + oDesigner.PrepareStringForFormFile(LinkValue()) + '"'
		cOutput += "," + nl + cTabs + ' :Text =  "' + oDesigner.PrepareStringForFormFile(TextValue()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = `setText('<a href="#{f1}">#{f2}</a>')` + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(LinkValue()))
		cOutput = substr(cOutput,"#{f2}",TextValue())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setLinkValue(itemdata[:Link])
		setTextValue(itemdata[:Text])

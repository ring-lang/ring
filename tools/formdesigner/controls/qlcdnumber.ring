/*
**	Project : Form Designer 
**	File Purpose :  QLCDNumber Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QLCDNumber from QLCDNumber

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nDisplay  = 0

	func DisplayValue
		return nDisplay

	func SetDisplayValue nValue
		nDisplay = nValue
		Display(nDisplay)

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_DISPLAY,False) # "Display"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Display Value
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(""+DisplayValue())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON {
			setDisplayValue(NumOrZero(cValue))
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :display =  ' + DisplayValue()
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'Display(#{f1})' + nl
		cOutput = substr(cOutput,"#{f1}",""+DisplayValue())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setDisplayValue(itemdata[:Display])

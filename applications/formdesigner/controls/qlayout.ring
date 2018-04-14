/*
**	Project : Form Designer 
**	File Purpose :  QLayout Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QLayout from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nLayoutType = 0
	cLayoutObjects = ""

	func LayoutTypeValue
		return nLayoutType

	func SetLayoutTypeValue Value
		nLayoutType = Value

	func LayoutObjectsValue
		return cLayoutObjects

	func SetLayoutObjectsValue cValue
		cLayoutObjects = cValue

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_TYPE,
			[T_FORMDESIGNER_ATTRIBUTE_VERTICAL,T_FORMDESIGNER_ATTRIBUTE_HORIZONTAL]) # "Type" "Vertical" "Horizontal"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_OBJECTSSCOMMA,True) # "Objects (S: Comma)"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Layout Type
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(LayoutTypeValue())
			oCombo.BlockSignals(False)
		# Set the Layout Objects
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(LayoutObjectsValue())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON
				setLayoutTypeValue(cValue)
			case C_AFTERCOMMON + 1
				setLayoutObjectsValue(cValue)
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ComboItemAction oDesigner,nRow
		nLayoutTypePos = C_AFTERCOMMON
		if nRow = nLayoutTypePos  {		# Layout Type
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nLayoutTypePos,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			nIndex = oCombo.CurrentIndex()
			setLayoutTypeValue(nIndex)
		}

	func DialogButtonAction oDesigner,nRow
		CommonDialogButtonAction(oDesigner,nRow)
		switch nRow {
			case C_AFTERCOMMON + 1 	# Layout Objects
				open_window(:WindowObjectsController)
				Last_Window().setParentObject(oDesigner)
				Last_Window().setPropertyIndex(C_AFTERCOMMON+1)
				Last_Window().setMethodName("setLayoutObjectsValue")
				aList = oDesigner.oModel.GetObjectsNames()
				# Remove the window Object name
					del(aList,1)
				# Remove the current layout object name
					del(aList,std_find(aList,oDesigner.oModel.GetObjectName(self)))
				Last_Window().LoadObjectsData(aList)
				Last_Window().LoadSelectedItems()
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :LayoutType =  ' + LayoutTypeValue()
		cOutput += "," + nl + cTabs + ' :LayoutObjects =  "' + oDesigner.PrepareStringForFormFile(LayoutObjectsValue()) + '"'
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) +
		oDesigner.oModel.GetObjectName(self) + " = " +
		'new #{f1}() {
#{f2}
		}' + nl
		switch LayoutTypeValue()	{
			case 0
				cClass = "QVBoxLayout"
			case 1
				cClass = "QHBoxLayout"
		}
		cOutput = substr(cOutput,"#{f1}",cClass)
		cOutput = substr(cOutput,"#{f2}",AddTabs(GenerateCustomCode(oDesigner),3))
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if LayoutObjectsValue() != NULL {
			aItems = split(LayoutObjectsValue(),",")
			for item in aItems {
				if not oDesigner.oModel.GetObjectClassByName(item) = "formdesigner_qlayout" {
					cOutput += 'AddWidget(#{f1})' + nl
				else
					cOutput += 'AddLayout(#{f1})' + nl
				}
				cOutput = substr(cOutput,"#{f1}",Item)
			}
		}
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setLayoutTypeValue(itemdata[:LayoutType])
		setLayoutObjectsValue(itemdata[:LayoutObjects])
		setText(oDesigner.oModel.GetObjectName(self))

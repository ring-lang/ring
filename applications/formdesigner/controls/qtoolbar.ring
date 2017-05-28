/*
**	Project : Form Designer 
**	File Purpose :  QToolbar Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QToolBar from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cTitle = ""
	cToolbarObjects = ""

	func TitleValue
		return cTitle

	func SetTitleValue cValue
		cTitle = cValue

	func ToolbarObjectsValue
		return cToolbarObjects

	func SetToolbarObjectsValue cValue
		cToolbarObjects = cValue

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Title",True)
		oDesigner.oView.AddProperty("Objects (S: Comma)",True)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# The Title
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(TitleValue())
		# Set the Toolbar Objects
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(ToolbarObjectsValue())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON
				setTitleValue(cValue)
			case C_AFTERCOMMON+1
				setToolbarObjectsValue(cValue)
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))


	func DialogButtonAction oDesigner,nRow
		CommonDialogButtonAction(oDesigner,nRow)
		switch nRow {
			case C_AFTERCOMMON+1  	# Toolbar Objects
				open_window(:WindowObjectsController)
				Last_Window().setParentObject(oDesigner)
				Last_Window().setPropertyIndex(C_AFTERCOMMON+1)
				Last_Window().setMethodName("setToolbarObjectsValue")
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
		cOutput += "," + nl + cTabs + ' :Title =  "' + oDesigner.PrepareStringForFormFile(TitleValue()) + '"'
		cOutput += "," + nl + cTabs + ' :ToolbarObjects =  "' + oDesigner.PrepareStringForFormFile(ToolbarObjectsValue()) + '"'
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) +
		oDesigner.oModel.GetObjectName(self) + " = " +
		'win.AddToolbar("#{f1}") {
#{f2}
		}' + nl
		cOutput = substr(cOutput,"#{f1}",TitleValue())
		cOutput = substr(cOutput,"#{f2}",AddTabs(GenerateCustomCode(oDesigner),3))
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if ToolbarObjectsValue() != NULL {
			aItems = split(ToolbarObjectsValue(),",")
			for item in aItems {
				if not std_lower(Item) = "separator" {
					cOutput += 'AddWidget(#{f1})' + nl
					cOutput = substr(cOutput,"#{f1}",Item)
				else
					cOutput += 'AddSeparator()' + nl
				}
			}
		}
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setTitleValue(itemdata[:Title])
		setToolbarObjectsValue(itemdata[:ToolbarObjects])



/*
**	Project : Form Designer 
**	File Purpose :  QFrame3 Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QFrame3 from QFrame3

	nFrameType = 0

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func FrameType
		return nFrameType

	func SetFrameType nIndex
		nFrameType = nIndex
		Switch nIndex {
			case 0
				setFrameStyle(QFrame_Plain | QFrame_WinPanel )
			case 1
				setFrameStyle(QFrame_Raised | QFrame_WinPanel)
			case 2
				setFrameStyle(QFrame_Sunken | QFrame_WinPanel)
		}

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_FRAMESTYLE,
			[T_FORMDESIGNER_ATTRIBUTE_PLAIN,T_FORMDESIGNER_ATTRIBUTE_RAISED,T_FORMDESIGNER_ATTRIBUTE_SUNKEN]) # "Frame Style" "Plain" "Raised""Sunken"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Frame Type
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(nFrameType)
			oCombo.BlockSignals(False)
		oPropertiesTable.Blocksignals(False)
		SetFrameType(nFrameType)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)

	func ComboItemAction oDesigner,nRow
		nFrameStylePos = C_AFTERCOMMON
		if nRow = nFrameStylePos  {
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nFrameStylePos,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			nIndex = oCombo.CurrentIndex()
			setFrameType(nIndex)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :FrameType =  ' + FrameType()
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setFrameStyle(#{f2})'
		Switch nFrameType {
			case 0
				cOutput = substr(cOutput,"#{f2}","QFrame_Plain | QFrame_WinPanel")
			case 1
				cOutput = substr(cOutput,"#{f2}","QFrame_Raised | QFrame_WinPanel" )
			case 2
				cOutput = substr(cOutput,"#{f2}","QFrame_Sunken | QFrame_WinPanel" )
		}
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setFrameType(NumOrZero(itemdata[:FrameType]))

/*
**	Project : Form Designer 
**	File Purpose :  QLabel Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QLabel from QLabel

	nTextAlign = 0

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func TextAlign
		return nTextAlign

	func SetTextAlign nIndex
		nTextAlign = nIndex
		Switch nIndex {
			case 0
				setalignment(Qt_AlignLeft |  Qt_AlignVCenter )
			case 1
				setalignment(Qt_AlignHCenter |  Qt_AlignVCenter )
			case 2
				setalignment(Qt_AlignRight |  Qt_AlignVCenter )
		}

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXT, # "Text"
						False)
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_TEXTALIGN,	# "Text Align"
			[T_FORMDESIGNER_ATTRIBUTE_TEXTALIGNLEFT, # "Left"
			T_FORMDESIGNER_ATTRIBUTE_TEXTALIGNCENTER,# "Center" 
			T_FORMDESIGNER_ATTRIBUTE_TEXTALIGNRIGHT] # "Right"
			)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(text())
		# Text Align
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON+1,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(nTextAlign)
			oCombo.BlockSignals(False)
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON {
			setText(cValue)
		}

	func ComboItemAction oDesigner,nRow
		nTextAlignPos = C_AFTERCOMMON+1
		if nRow = nTextAlignPos  {		# Text Align
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nTextAlignPos,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			nIndex = oCombo.CurrentIndex()
			setTextAlign(nIndex)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :text =  "' + oDesigner.PrepareStringForFormFile(Text()) + '"'
		cOutput += "," + nl + cTabs + ' :textalign =  ' + TextAlign()
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setText("#{f1}")' + nl + 'setAlignment(#{f2})'
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(text()))
		Switch nTextAlign {
			case 0
				cOutput = substr(cOutput,"#{f2}","Qt_AlignLeft |  Qt_AlignVCenter")
			case 1
				cOutput = substr(cOutput,"#{f2}","Qt_AlignHCenter |  Qt_AlignVCenter" )
			case 2
				cOutput = substr(cOutput,"#{f2}","Qt_AlignRight |  Qt_AlignVCenter" )
		}
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setText(itemdata[:text])
		setTextAlign(NumOrZero(itemdata[:textalign]))

/*
**	Project : Form Designer 
**	File Purpose :  QProgressbar Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QProgressbar from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nOrientation = 0

	cMinimum = ""
	cMaximum = ""
	cRange = ""
	cValue = ""

	cvalueChangedEvent = ""

	func OrientationValue
		return nOrientation

	func SetOrientationValue nIndex
		nOrientation = nIndex

	func MinimumValue
		return cMinimum

	func SetMinimumValue Value
		cMinimum = Value

	func MaximumValue
		return cMaximum

	func SetMaximumValue Value
		cMaximum = Value

	func RangeValue
		return cRange

	func SetRangeValue Value
		cRange = Value

	func ValueValue
		return cValue

	func SetValueValue Value
		cValue = Value

	func SetvalueChangedEventCode cValue
		cvalueChangedEvent = cValue

	func valueChangedEventCode
		return cvalueChangedEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_SETORIENTATION,[T_FORMDESIGNER_ATTRIBUTE_HORIZONTAL,T_FORMDESIGNER_ATTRIBUTE_VERTICAL]) # "Set Orientation" "Horizontal" "Vertical"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETMINIMUM,False)			# "Set Minimum"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETMAXIMUM,False)			# "Set Maximum"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETRANGE,False)			# "Set Range"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETVALUE,False)			# "Set Value"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_VALUECHANGEDEVENT,False)		# "valueChangedEvent"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Orientation
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(OrientationValue())
			oCombo.BlockSignals(False)
		# Minimum, Maximum, Range and Value
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(MinimumValue())
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(MaximumValue())
			oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(RangeValue())
			oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(ValueValue())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(valueChangedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ComboItemAction oDesigner,nRow
		nOrientationPos = C_AFTERCOMMON
		if nRow = nOrientationPos  {		# Orientation
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nOrientationPos,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			nIndex = oCombo.CurrentIndex()
			setOrientationValue(nIndex)
		}

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON+1
					setMinimumValue(cValue)
				case C_AFTERCOMMON+2
					setMaximumValue(cValue)
				case C_AFTERCOMMON+3
					setRangeValue(cValue)
				case C_AFTERCOMMON+4
					setValueValue(cValue)
				case C_AFTERCOMMON+5
					setvalueChangedEventCode(cValue)
					oDesigner.NewEventName(cValue)
			}
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :orientation =  ' + OrientationValue()
		cOutput += "," + nl + cTabs + ' :minimum =  "' + oDesigner.PrepareStringForFormFile(MinimumValue())  + '"'
		cOutput += "," + nl + cTabs + ' :maximum =  "' + oDesigner.PrepareStringForFormFile(MaximumValue())  + '"'
		cOutput += "," + nl + cTabs + ' :range =  "' + oDesigner.PrepareStringForFormFile(RangeValue())  + '"'
		cOutput += "," + nl + cTabs + ' :value =  "' + oDesigner.PrepareStringForFormFile(ValueValue())  + '"'
		cOutput += "," + nl + cTabs + ' :setvalueChangedEvent =  "' + oDesigner.PrepareStringForFormFile(valueChangedEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setOrientation(#{f1})' + nl
		cOutput = substr(cOutput,"#{f1}",""+(OrientationValue()+1))
		if Minimumvalue() != NULL {
			cOutput += 'setMinimum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MinimumValue())
		}
		if Maximumvalue() != NULL {
			cOutput += 'setMaximum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MaximumValue())
		}
		if Rangevalue() != NULL {
			cOutput += 'setRange(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+RangeValue())
		}
		if ValueValue() != NULL {
			cOutput += 'setValue(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+ValueValue())
		}
		cOutput += 'setvalueChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,valueChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",valueChangedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setOrientationValue(NumOrZero(itemdata[:orientation]))
		setMinimumValue(itemdata[:minimum])
		setMaximumValue(itemdata[:maximum])
		setRangeValue(itemdata[:range])
		setValueValue(itemdata[:value])
		SetvalueChangedEventCode(itemdata[:setvalueChangedEvent])


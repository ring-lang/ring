/*
**	Project : Form Designer 
**	File Purpose :  QSlider Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QSlider from QSlider

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nOrientation = 0

	cMinimum = ""
	cMaximum = ""
	cRange = ""
	cValue = ""

	cactionTriggeredEvent = ""
	crangeChangedEvent = ""
	csliderMovedEvent = ""
	csliderPressedEvent = ""
	csliderReleasedEvent = ""
	cvalueChangedEvent = ""

	func OrientationValue
		return nOrientation

	func SetOrientationValue nIndex
		nOrientation = nIndex
		setOrientation(nIndex)

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

	func SetactionTriggeredEventCode cValue
		cactionTriggeredEvent = cValue

	func actionTriggeredEventCode
		return cactionTriggeredEvent

	func SetrangeChangedEventCode cValue
		crangeChangedEvent = cValue

	func rangeChangedEventCode
		return crangeChangedEvent

	func SetsliderMovedEventCode cValue
		csliderMovedEvent = cValue

	func sliderMovedEventCode
		return csliderMovedEvent

	func SetsliderPressedEventCode cValue
		csliderPressedEvent = cValue

	func sliderPressedEventCode
		return csliderPressedEvent

	func SetsliderReleasedEventCode cValue
		csliderReleasedEvent = cValue

	func sliderReleasedEventCode
		return csliderReleasedEvent

	func SetvalueChangedEventCode cValue
		cvalueChangedEvent = cValue

	func valueChangedEventCode
		return cvalueChangedEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_SETORIENTATION,[T_FORMDESIGNER_ATTRIBUTE_VERTICAL,T_FORMDESIGNER_ATTRIBUTE_HORIZONTAL])	# "Set Orientation" "Vertical" "Horizontal"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETMINIMUM,False)			 	# "Set Minimum"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETMAXIMUM,False)				 # "Set Maximum"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETRANGE,False)				 # "Set Range"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETVALUE,False)				 # "Set Value"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ACTIONTRIGGEREDEVENT,False)			 # "actionTriggeredEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_RANGECHANGEDEVENT,False)			 # "rangeChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SLIDERMOVEDEVENT,False)			 # "sliderMovedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SLIDERPRESSEDEVENT,False)			 # "sliderPressedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SLIDERRELEASEDEVENT,False)			 # "sliderReleasedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_VALUECHANGEDEVENT,False)			 # "valueChangedEvent"

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
		# Events
			oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(actionTriggeredEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(rangeChangedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+7,1).settext(sliderMovedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+8,1).settext(sliderPressedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+9,1).settext(sliderReleasedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+10,1).settext(valueChangedEventcode())
		oPropertiesTable.Blocksignals(False)

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
					setactionTriggeredEventCode(cValue)
				case C_AFTERCOMMON+6
					setrangeChangedEventCode(cValue)
				case C_AFTERCOMMON+7
					setsliderMovedEventCode(cValue)
				case C_AFTERCOMMON+8
					setsliderPressedEventCode(cValue)
				case C_AFTERCOMMON+9
					setsliderReleasedEventCode(cValue)
				case C_AFTERCOMMON+10
					setvalueChangedEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+5 ) and 
			   (nRow <= C_AFTERCOMMON+10 ) {
					oDesigner.NewEventName(cValue)
			}
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :orientation =  ' + OrientationValue()
		cOutput += "," + nl + cTabs + ' :minimum =  "' + oDesigner.PrepareStringForFormFile(MinimumValue())  + '"'
		cOutput += "," + nl + cTabs + ' :maximum =  "' + oDesigner.PrepareStringForFormFile(MaximumValue())  + '"'
		cOutput += "," + nl + cTabs + ' :range =  "' +oDesigner.PrepareStringForFormFile( RangeValue()) + '"'
		cOutput += "," + nl + cTabs + ' :value =  "' + oDesigner.PrepareStringForFormFile(ValueValue())  + '"'
		cOutput += "," + nl + cTabs + ' :setactionTriggeredEvent =  "' + oDesigner.PrepareStringForFormFile(actionTriggeredEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setrangeChangedEvent =  "' + oDesigner.PrepareStringForFormFile(rangeChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setsliderMovedEvent =  "' + oDesigner.PrepareStringForFormFile(sliderMovedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setsliderPressedEvent =  "' + oDesigner.PrepareStringForFormFile(sliderPressedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setsliderReleasedEvent =  "' + oDesigner.PrepareStringForFormFile(sliderReleasedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setvalueChangedEvent =  "' + oDesigner.PrepareStringForFormFile(valueChangedEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setOrientation(#{f1})' + nl
		cOutput = substr(cOutput,"#{f1}",""+OrientationValue())
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
		cOutput += 'setactionTriggeredEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,actionTriggeredEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",actionTriggeredEventCode())
		cOutput += 'setrangeChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,rangeChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",rangeChangedEventCode())
		cOutput += 'setsliderMovedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,sliderMovedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",sliderMovedEventCode())
		cOutput += 'setsliderPressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,sliderPressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",sliderPressedEventCode())
		cOutput += 'setsliderReleasedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,sliderReleasedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",sliderReleasedEventCode())
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
		SetactionTriggeredEventCode(itemdata[:setactionTriggeredEvent])
		SetrangeChangedEventCode(itemdata[:setrangeChangedEvent])
		SetsliderMovedEventCode(itemdata[:setsliderMovedEvent])
		SetsliderPressedEventCode(itemdata[:setsliderPressedEvent])
		SetsliderReleasedEventCode(itemdata[:setsliderReleasedEvent])
		SetvalueChangedEventCode(itemdata[:setvalueChangedEvent])



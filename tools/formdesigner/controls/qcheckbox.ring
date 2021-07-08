/*
**	Project : Form Designer 
**	File Purpose :  QCheckbox Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QCheckBox from QCheckBox

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cstateChangedEvent = ""
	cclickedEvent = ""
	cpressedEvent = ""
	creleasedEvent = ""
	ctoggledEvent = ""

	func SetstateChangedEventCode cValue
		cstateChangedEvent = cValue

	func stateChangedEventCode
		return cstateChangedEvent

	func SetclickedEventCode cValue
		cclickedEvent = cValue

	func clickedEventCode
		return cclickedEvent

	func SetpressedEventCode cValue
		cpressedEvent = cValue

	func pressedEventCode
		return cpressedEvent

	func SetreleasedEventCode cValue
		creleasedEvent = cValue

	func releasedEventCode
		return creleasedEvent

	func SettoggledEventCode cValue
		ctoggledEvent = cValue

	func toggledEventCode
		return ctoggledEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXT,False)		# "Text"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_STATECHANGEDEVENT,False)	# "stateChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CLICKEDEVENT,False)	# "clickedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_PRESSEDEVENT,False)	# "pressedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_RELEASEDEVENT,False)	# "releasedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TOGGLEDEVENT,False)	# "toggledEvent"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(text())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(stateChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(clickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(pressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(releasedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(toggledEventcode())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setText(cValue)
				case C_AFTERCOMMON+1
					setstateChangedEventCode(cValue)
				case C_AFTERCOMMON+2
					setclickedEventCode(cValue)
				case C_AFTERCOMMON+3
					setpressedEventCode(cValue)
				case C_AFTERCOMMON+4
					setreleasedEventCode(cValue)
				case C_AFTERCOMMON+5
					settoggledEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+1 ) and 
			   (nRow <= C_AFTERCOMMON+5 ) {
					oDesigner.NewEventName(cValue)
			}
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :text =  "' + oDesigner.PrepareStringForFormFile(Text()) + '"'
		cOutput += "," + nl + cTabs + ' :setstateChangedEvent =  "' + oDesigner.PrepareStringForFormFile(stateChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setclickedEvent =  "' + oDesigner.PrepareStringForFormFile(clickedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setpressedEvent =  "' + oDesigner.PrepareStringForFormFile(pressedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setreleasedEvent =  "' + oDesigner.PrepareStringForFormFile(releasedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :settoggledEvent =  "' + oDesigner.PrepareStringForFormFile(toggledEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setText("#{f1}")' + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(text()))
		cOutput += 'setstateChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,stateChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",stateChangedEventCode())
		cOutput += 'setclickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,clickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",clickedEventCode())
		cOutput += 'setpressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,pressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",pressedEventCode())
		cOutput += 'setreleasedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,releasedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",releasedEventCode())
		cOutput += 'settoggledEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,toggledEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",toggledEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setText(itemdata[:text])
		SetstateChangedEventCode(itemdata[:setstateChangedEvent])
		SetclickedEventCode(itemdata[:setclickedEvent])
		SetpressedEventCode(itemdata[:setpressedEvent])
		SetreleasedEventCode(itemdata[:setreleasedEvent])
		SettoggledEventCode(itemdata[:settoggledEvent])

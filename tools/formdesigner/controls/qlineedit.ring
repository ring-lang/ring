/*
**	Project : Form Designer 
**	File Purpose :  QLineEdit Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QLineEdit from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cText = ""

	cTextChangedEvent = ""
	ccursorPositionChangedEvent = ""
	ceditingFinishedEvent = ""
	creturnPressedEvent = ""
	cselectionChangedEvent = ""
	ctextEditedEvent = ""

	cBackColor = "white"

	func TextValue
		return cText

	func SetTextValue value
		cText = value

	func SetTextChangedEventCode cValue
		cTextChangedEvent = cValue

	func TextChangedEventCode
		return cTextChangedEvent

	func SetcursorPositionChangedEventCode cValue
		ccursorPositionChangedEvent = cValue

	func cursorPositionChangedEventCode
		return ccursorPositionChangedEvent

	func SeteditingFinishedEventCode cValue
		ceditingFinishedEvent = cValue

	func editingFinishedEventCode
		return ceditingFinishedEvent

	func SetreturnPressedEventCode cValue
		creturnPressedEvent = cValue

	func returnPressedEventCode
		return creturnPressedEvent

	func SetselectionChangedEventCode cValue
		cselectionChangedEvent = cValue

	func selectionChangedEventCode
		return cselectionChangedEvent

	func SettextEditedEventCode cValue
		ctextEditedEvent = cValue

	func textEditedEventCode
		return ctextEditedEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXT,False)	 		# "Text"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXTCHANGEDEVENT,False)		# "TextChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURSORPOSITIONCHANGEDEVENT,False)	# "cursorPositionChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_EDITINGFINSHEDEVENT,False)		# "editingFinishedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_RETURNPRESSEDEVENT,False) 		# "returnPressedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SELECTIONCHANGEDEVENT,False)	# "selectionChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXTEDITEDEVENT,False)		# "textEditedEvent"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(TextValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(TextChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(cursorPositionChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(editingFinishedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(returnPressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(selectionChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(textEditedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setTextValue(cValue)
				case C_AFTERCOMMON+1
					setTextChangedEventCode(cValue)
				case C_AFTERCOMMON+2
					setcursorPositionChangedEventCode(cValue)
				case C_AFTERCOMMON+3
					seteditingFinishedEventCode(cValue)
				case C_AFTERCOMMON+4
					setreturnPressedEventCode(cValue)
				case C_AFTERCOMMON+5
					setselectionChangedEventCode(cValue)
				case C_AFTERCOMMON+6
					settextEditedEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+1 ) and 
			   (nRow <= C_AFTERCOMMON+6 ) {
					oDesigner.NewEventName(cValue)
			}
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :text =  "' + oDesigner.PrepareStringForFormFile(TextValue()) + '"'
		cOutput += "," + nl + cTabs + ' :setTextChangedEvent =  "' + oDesigner.PrepareStringForFormFile(TextChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcursorPositionChangedEvent =  "' + oDesigner.PrepareStringForFormFile(cursorPositionChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :seteditingFinishedEvent =  "' + oDesigner.PrepareStringForFormFile(editingFinishedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setreturnPressedEvent =  "' + oDesigner.PrepareStringForFormFile(returnPressedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setselectionChangedEvent =  "' + oDesigner.PrepareStringForFormFile(selectionChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :settextEditedEvent =  "' + oDesigner.PrepareStringForFormFile(textEditedEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setText("#{f1}")' + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(textValue()))
		cOutput += 'setTextChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,TextChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",TextChangedEventCode())
		cOutput += 'setcursorPositionChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cursorPositionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cursorPositionChangedEventCode())
		cOutput += 'seteditingFinishedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,editingFinishedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",editingFinishedEventCode())
		cOutput += 'setreturnPressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,returnPressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",returnPressedEventCode())
		cOutput += 'setselectionChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,selectionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",selectionChangedEventCode())
		cOutput += 'settextEditedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,textEditedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",textEditedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setTextValue(itemdata[:text])
		setText(oDesigner.oModel.GetObjectName(self))
		SetTextChangedEventCode(itemdata[:setTextChangedEvent])
		SetcursorPositionChangedEventCode(itemdata[:setcursorPositionChangedEvent])
		SeteditingFinishedEventCode(itemdata[:seteditingFinishedEvent])
		SetreturnPressedEventCode(itemdata[:setreturnPressedEvent])
		SetselectionChangedEventCode(itemdata[:setselectionChangedEvent])
		SettextEditedEventCode(itemdata[:settextEditedEvent])


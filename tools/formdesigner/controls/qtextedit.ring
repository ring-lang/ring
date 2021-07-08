/*
**	Project : Form Designer 
**	File Purpose :  QTextEdit Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

# We use QLineEdit as parent - We need just the looking (not functionality)
class FormDesigner_QTextEdit from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cText = ""

	ccopyAvailableEvent = ""
	ccurrentCharFormatChangedEvent = ""
	ccursorPositionChangedEvent = ""
	credoAvailableEvent = ""
	cselectionChangedEvent = ""
	ctextChangedEvent = ""
	cundoAvailableEvent = ""

	cBackColor = "white"

	func TextValue
		return cText

	func SetTextValue value
		cText = value

	func SetcopyAvailableEventCode cValue
		ccopyAvailableEvent = cValue

	func copyAvailableEventCode
		return ccopyAvailableEvent

	func SetcurrentCharFormatChangedEventCode cValue
		ccurrentCharFormatChangedEvent = cValue

	func currentCharFormatChangedEventCode
		return ccurrentCharFormatChangedEvent

	func SetcursorPositionChangedEventCode cValue
		ccursorPositionChangedEvent = cValue

	func cursorPositionChangedEventCode
		return ccursorPositionChangedEvent

	func SetredoAvailableEventCode cValue
		credoAvailableEvent = cValue

	func redoAvailableEventCode
		return credoAvailableEvent

	func SetselectionChangedEventCode cValue
		cselectionChangedEvent = cValue

	func selectionChangedEventCode
		return cselectionChangedEvent

	func SettextChangedEventCode cValue
		ctextChangedEvent = cValue

	func textChangedEventCode
		return ctextChangedEvent

	func SetundoAvailableEventCode cValue
		cundoAvailableEvent = cValue

	func undoAvailableEventCode
		return cundoAvailableEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXT,False)				# "Text"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_COPYAVAILABLEEVENT,False)			# "copyAvailableEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURRENTCHARFORMATCHANGEDEVENT,False)	# "currentCharFormatChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURSORPOSITIONCHANGEDEVENT,False)		# "cursorPositionChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_REDOAVAIABLEEVENT,False)			# "redoAvailableEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SELECTIONCHANGEDEVENT,False)		# "selectionChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXTCHANGEDEVENT,False)			# "textChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_UNDOAVAILABLEEVENT,False)			# "undoAvailableEvent"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(TextValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(copyAvailableEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(currentCharFormatChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(cursorPositionChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(redoAvailableEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(selectionChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(textChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+7,1).settext(undoAvailableEventcode())
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
					setcopyAvailableEventCode(cValue)
				case C_AFTERCOMMON+2
					setcurrentCharFormatChangedEventCode(cValue)
				case C_AFTERCOMMON+3
					setcursorPositionChangedEventCode(cValue)
				case C_AFTERCOMMON+4
					setredoAvailableEventCode(cValue)
				case C_AFTERCOMMON+5
					setselectionChangedEventCode(cValue)
				case C_AFTERCOMMON+6
					settextChangedEventCode(cValue)
				case C_AFTERCOMMON+7
					setundoAvailableEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+1 ) and 
			   (nRow <= C_AFTERCOMMON+7 ) {
					oDesigner.NewEventName(cValue)
			}
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :text =  "' + oDesigner.PrepareStringForFormFile(TextValue()) + '"'
		cOutput += "," + nl + cTabs + ' :setcopyAvailableEvent =  "' + oDesigner.PrepareStringForFormFile(copyAvailableEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentCharFormatChangedEvent =  "' + oDesigner.PrepareStringForFormFile(currentCharFormatChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcursorPositionChangedEvent =  "' + oDesigner.PrepareStringForFormFile(cursorPositionChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setredoAvailableEvent =  "' + oDesigner.PrepareStringForFormFile(redoAvailableEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setselectionChangedEvent =  "' + oDesigner.PrepareStringForFormFile(selectionChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :settextChangedEvent =  "' + oDesigner.PrepareStringForFormFile(textChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setundoAvailableEvent =  "' + oDesigner.PrepareStringForFormFile(undoAvailableEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setText("#{f1}")' + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(textValue()))
		cOutput += 'setcopyAvailableEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,copyAvailableEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",copyAvailableEventCode())
		cOutput += 'setcurrentCharFormatChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,currentCharFormatChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",currentCharFormatChangedEventCode())
		cOutput += 'setcursorPositionChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cursorPositionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cursorPositionChangedEventCode())
		cOutput += 'setredoAvailableEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,redoAvailableEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",redoAvailableEventCode())
		cOutput += 'setselectionChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,selectionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",selectionChangedEventCode())
		cOutput += 'settextChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,textChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",textChangedEventCode())
		cOutput += 'setundoAvailableEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,undoAvailableEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",undoAvailableEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setTextValue(itemdata[:text])
		setText(oDesigner.oModel.GetObjectName(self))
		SetcopyAvailableEventCode(itemdata[:setcopyAvailableEvent])
		SetcurrentCharFormatChangedEventCode(itemdata[:setcurrentCharFormatChangedEvent])
		SetcursorPositionChangedEventCode(itemdata[:setcursorPositionChangedEvent])
		SetredoAvailableEventCode(itemdata[:setredoAvailableEvent])
		SetselectionChangedEventCode(itemdata[:setselectionChangedEvent])
		SettextChangedEventCode(itemdata[:settextChangedEvent])
		SetundoAvailableEventCode(itemdata[:setundoAvailableEvent])


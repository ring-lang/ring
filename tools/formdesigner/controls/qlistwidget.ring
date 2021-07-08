/*
**	Project : Form Designer 
**	File Purpose :  QListWidget Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

# We use QLineEdit as parent - We need just the looking (not functionality)
class FormDesigner_QListWidget from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cItems = ""
	cCurrentRow = ""

	ccurrentItemChangedEvent = ""
	ccurrentRowChangedEvent = ""
	ccurrentTextChangedEvent = ""
	citemActivatedEvent = ""
	citemChangedEvent = ""
	citemClickedEvent = ""
	citemDoubleClickedEvent = ""
	citemEnteredEvent = ""
	citemPressedEvent = ""
	citemSelectionChangedEvent = ""

	cBackColor = "white"

	func SetcItems cValue
		cItems = cValue

	func cItemsValue
		return cItems

	func setcCurrentRow cValue
		cCurrentRow = cValue

	func cCurrentRowValue
		return cCurrentRow

	func SetcurrentItemChangedEventCode cValue
		ccurrentItemChangedEvent = cValue

	func currentItemChangedEventCode
		return ccurrentItemChangedEvent

	func SetcurrentRowChangedEventCode cValue
		ccurrentRowChangedEvent = cValue

	func currentRowChangedEventCode
		return ccurrentRowChangedEvent

	func SetcurrentTextChangedEventCode cValue
		ccurrentTextChangedEvent = cValue

	func currentTextChangedEventCode
		return ccurrentTextChangedEvent

	func SetitemActivatedEventCode cValue
		citemActivatedEvent = cValue

	func itemActivatedEventCode
		return citemActivatedEvent

	func SetitemChangedEventCode cValue
		citemChangedEvent = cValue

	func itemChangedEventCode
		return citemChangedEvent

	func SetitemClickedEventCode cValue
		citemClickedEvent = cValue

	func itemClickedEventCode
		return citemClickedEvent

	func SetitemDoubleClickedEventCode cValue
		citemDoubleClickedEvent = cValue

	func itemDoubleClickedEventCode
		return citemDoubleClickedEvent

	func SetitemEnteredEventCode cValue
		citemEnteredEvent = cValue

	func itemEnteredEventCode
		return citemEnteredEvent

	func SetitemPressedEventCode cValue
		citemPressedEvent = cValue

	func itemPressedEventCode
		return citemPressedEvent

	func SetitemSelectionChangedEventCode cValue
		citemSelectionChangedEvent = cValue

	func itemSelectionChangedEventCode
		return citemSelectionChangedEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMS,False) 			# "Items (S: Comma)"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURRENTROW,False) 			# "Current Row"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURRENTITEMCHANGEDEVENT,False)	# "currentItemChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURRENTROWCHANGEDEVENT,False)	# "currentRowChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURRENTTEXTCHANGEDEVENT,False)	# "currentTextChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMACTIVATEDEVENT,False)		# "itemActivatedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMCHANGEDEVENT,False)		# "itemChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMCLICKEDEVENT,False)		# "itemClickedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMDOUBLECLICKEDEVENT,False)	# "itemDoubleClickedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMENTEREDEVENT,False)		# "itemEnteredEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMPRESSEDEVENT,False)		# "itemPressedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMSELECTIONCHANGEDEVENT,False)	# "itemSelectionChangedEvent"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		oPropertiesTable.item(C_AFTERCOMMON,1).settext(cItemsValue())
 		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(cCurrentRowValue())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(currentItemChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(currentRowChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(currentTextChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(itemActivatedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(itemChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+7,1).settext(itemClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+8,1).settext(itemDoubleClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+9,1).settext(itemEnteredEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+10,1).settext(itemPressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+11,1).settext(itemSelectionChangedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setcItems(cValue)
				case C_AFTERCOMMON+1
					setcCurrentRow(cValue)
				case C_AFTERCOMMON+2
					setcurrentItemChangedEventCode(cValue)
				case C_AFTERCOMMON+3
					setcurrentRowChangedEventCode(cValue)
				case C_AFTERCOMMON+4
					setcurrentTextChangedEventCode(cValue)
				case C_AFTERCOMMON+5
					setitemActivatedEventCode(cValue)
				case C_AFTERCOMMON+6
					setitemChangedEventCode(cValue)
				case C_AFTERCOMMON+7
					setitemClickedEventCode(cValue)
				case C_AFTERCOMMON+8
					setitemDoubleClickedEventCode(cValue)
				case C_AFTERCOMMON+9
					setitemEnteredEventCode(cValue)
				case C_AFTERCOMMON+10
					setitemPressedEventCode(cValue)
				case C_AFTERCOMMON+11
					setitemSelectionChangedEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+2 ) and 
			   (nRow <= C_AFTERCOMMON+11 ) {
					oDesigner.NewEventName(cValue)
			}
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :cItems =  "' + oDesigner.PrepareStringForFormFile(cItemsValue()) + '"'
		cOutput += "," + nl + cTabs + ' :cCurrentRow =  "' + oDesigner.PrepareStringForFormFile(cCurrentRowValue()) + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentItemChangedEvent =  "' + oDesigner.PrepareStringForFormFile(currentItemChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentRowChangedEvent =  "' + oDesigner.PrepareStringForFormFile(currentRowChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentTextChangedEvent =  "' + oDesigner.PrepareStringForFormFile(currentTextChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setitemActivatedEvent =  "' + oDesigner.PrepareStringForFormFile(itemActivatedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setitemChangedEvent =  "' + oDesigner.PrepareStringForFormFile(itemChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setitemClickedEvent =  "' + oDesigner.PrepareStringForFormFile(itemClickedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setitemDoubleClickedEvent =  "' + oDesigner.PrepareStringForFormFile(itemDoubleClickedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setitemEnteredEvent =  "' + oDesigner.PrepareStringForFormFile(itemEnteredEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setitemPressedEvent =  "' + oDesigner.PrepareStringForFormFile(itemPressedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setitemSelectionChangedEvent =  "' + oDesigner.PrepareStringForFormFile(itemSelectionChangedEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if cItemsValue() != NULL {
			aItems = split(cItemsValue(),",")
			for item in aItems {
				cOutput += 'AddItem("#{f1}")' + nl
				cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(Item))
			}
		}
		if cCurrentRowValue() != NULL {
			cOutput += 'setcurrentRow(#{f1},2)' + nl
			cOutput = substr(cOutput,"#{f1}",ccurrentRowValue())
		}
		cOutput += 'setcurrentItemChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,currentItemChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",currentItemChangedEventCode())
		cOutput += 'setcurrentRowChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,currentRowChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",currentRowChangedEventCode())
		cOutput += 'setcurrentTextChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,currentTextChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",currentTextChangedEventCode())
		cOutput += 'setitemActivatedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemActivatedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemActivatedEventCode())
		cOutput += 'setitemChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemChangedEventCode())
		cOutput += 'setitemClickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemClickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemClickedEventCode())
		cOutput += 'setitemDoubleClickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemDoubleClickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemDoubleClickedEventCode())
		cOutput += 'setitemEnteredEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemEnteredEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemEnteredEventCode())
		cOutput += 'setitemPressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemPressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemPressedEventCode())
		cOutput += 'setitemSelectionChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemSelectionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemSelectionChangedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setText(oDesigner.oModel.GetObjectName(self))
		SetcItems(itemdata[:cItems])
		SetcCurrentRow(itemdata[:cCurrentRow])
		SetcurrentItemChangedEventCode(itemdata[:setcurrentItemChangedEvent])
		SetcurrentRowChangedEventCode(itemdata[:setcurrentRowChangedEvent])
		SetcurrentTextChangedEventCode(itemdata[:setcurrentTextChangedEvent])
		SetitemActivatedEventCode(itemdata[:setitemActivatedEvent])
		SetitemChangedEventCode(itemdata[:setitemChangedEvent])
		SetitemClickedEventCode(itemdata[:setitemClickedEvent])
		SetitemDoubleClickedEventCode(itemdata[:setitemDoubleClickedEvent])
		SetitemEnteredEventCode(itemdata[:setitemEnteredEvent])
		SetitemPressedEventCode(itemdata[:setitemPressedEvent])
		SetitemSelectionChangedEventCode(itemdata[:setitemSelectionChangedEvent])

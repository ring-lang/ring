/*
**	Project : Form Designer 
**	File Purpose :  QTableWidget Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QTableWidget from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cRowCount = ""
	cColumnCount = "0"
	cHorizontalHeaders = ""
	cColumnsWidth = ""
	cHorizontalHeaderStyle = ""
	cVerticalHeaderStyle = ""

	nSelectionBehavior = 0
	nAlternatingColors = 0

	ccellActivatedEvent = ""
	ccellChangedEvent = ""
	ccellClickedEvent = ""
	ccellDoubleClickedEvent = ""
	ccellEnteredEvent = ""
	ccellPressedEvent = ""
	ccurrentCellChangedEvent = ""
	ccurrentItemChangedEvent = ""
	citemActivatedEvent = ""
	citemChangedEvent = ""
	citemClickedEvent = ""
	citemDoubleClickedEvent = ""
	citemEnteredEvent = ""
	citemPressedEvent = ""
	citemSelectionChangedEvent = ""

	func RowCountValue
		return cRowCount

	func setRowCountValue Value
		cRowCount = Value

	func ColumnCountValue
		return cColumnCount

	func SetColumnCountValue Value
		cColumnCount = Value

	func HorizontalHeadersValue
		return cHorizontalHeaders

	func SetHorizontalHeadersValue Value
		cHorizontalHeaders = Value

	func ColumnsWidthValue
		return cColumnsWidth

	func SetColumnsWidthValue Value
		cColumnsWidth = Value

	func HorizontalHeaderStyleValue
		return cHorizontalHeaderStyle

	func SetHorizontalHeaderStyleValue Value
		cVerticalHeaderStyle = Value

	func VerticalHeaderStyleValue
		return cVerticalHeaderStyle

	func SetVerticalHeaderStyleValue Value
		cVerticalHeaderStyle = Value

	func SelectionBahviorValue
		return nSelectionBehavior

	func SetSelectionBehaviorValue Value
		nSelectionBehavior = Value

	func AlternatingColorsValue
		return nAlternatingColors

	func SetAlternatingColorsValue Value
		nAlternatingColors = Value

	func SetcellActivatedEventCode cValue
		ccellActivatedEvent = cValue

	func cellActivatedEventCode
		return ccellActivatedEvent

	func SetcellChangedEventCode cValue
		ccellChangedEvent = cValue

	func cellChangedEventCode
		return ccellChangedEvent

	func SetcellClickedEventCode cValue
		ccellClickedEvent = cValue

	func cellClickedEventCode
		return ccellClickedEvent

	func SetcellDoubleClickedEventCode cValue
		ccellDoubleClickedEvent = cValue

	func cellDoubleClickedEventCode
		return ccellDoubleClickedEvent

	func SetcellEnteredEventCode cValue
		ccellEnteredEvent = cValue

	func cellEnteredEventCode
		return ccellEnteredEvent

	func SetcellPressedEventCode cValue
		ccellPressedEvent = cValue

	func cellPressedEventCode
		return ccellPressedEvent

	func SetcurrentCellChangedEventCode cValue
		ccurrentCellChangedEvent = cValue

	func currentCellChangedEventCode
		return ccurrentCellChangedEvent

	func SetcurrentItemChangedEventCode cValue
		ccurrentItemChangedEvent = cValue

	func currentItemChangedEventCode
		return ccurrentItemChangedEvent

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
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ROWCOUNT,False)			 	# "Row Count"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_COLUMNCOUNT,False)			 	# "Column Count"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_HORIZONTALHEADERSSCOMMA,False)		# "Horizontal Headers (S: Comma)"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_COLUMNSWIDTHSCOMMA,False)			# "Columns Width (S: Comma)"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_HORIZONTALHEADERSTYLE,False)		# "Horizontal Header Style"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_VERTICALHEADERSTYLE,False)			# "Vertical Header Style"
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_SELECTIONBEHAVIOR,
							[T_FORMDESIGNER_ATTRIBUTE_ITEMS,T_FORMDESIGNER_ATTRIBUTE_ROWS,T_FORMDESIGNER_ATTRIBUTE_COLUMNS])  # "Selection Behavior" "Items" "Rows" "Columns"
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_ALTERNATINGROWCOLORS,
							[T_FORMDESIGNER_ATTRIBUTE_TRUE,T_FORMDESIGNER_ATTRIBUTE_FALSE])			 # "Alternating Row Colors" "True" "False"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CELLACTIVATEDEVENT,False)			# "cellActivatedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CELLCHANGEDEVENT,False)			# "cellChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CELLCLICKEDEVENT,False)			# "cellClickedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CELLDOUBLECLICKEDEVENT,False)		# "cellDoubleClickedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CELLENTEREDEVENT,False)			# "cellEnteredEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CELLPRESSEDEVENT,False)			# "cellPressedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURRENTCELLCHANGEDEVENT,False)		# "currentCellChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_CURRENTITEMCHANGEDEVENT,False)		# "currentItemChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMACTIVATEDEVENT,False)			# "itemActivatedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMCHANGEDEVENT,False)			# "itemChangedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMCLICKEDEVENT,False)			# "itemClickedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMDOUBLECLICKEDEVENT,False)		# "itemDoubleClickedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMENTEREDEVENT,False)			# "itemEnteredEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMPRESSEDEVENT,False)			# "itemPressedEvent"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_ITEMSELECTIONCHANGEDEVENT,False)		# "itemSelectionChangedEvent"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		oPropertiesTable.item(C_AFTERCOMMON,1).settext(RowCountValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(ColumnCountValue())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(HorizontalHeadersValue())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(ColumnsWidthValue())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(HorizontalHeaderStyleValue())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(VerticalHeaderStyleValue())
		# Selection Behaviour
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON+6,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(SelectionBahviorValue())
			oCombo.BlockSignals(False)
		# Alternating Colors
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON+7,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(AlternatingColorsValue())
			oCombo.BlockSignals(False)
		oPropertiesTable.item(C_AFTERCOMMON+8,1).settext(cellActivatedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+9,1).settext(cellChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+10,1).settext(cellClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+11,1).settext(cellDoubleClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+12,1).settext(cellEnteredEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+13,1).settext(cellPressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+14,1).settext(currentCellChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+15,1).settext(currentItemChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+16,1).settext(itemActivatedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+17,1).settext(itemChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+18,1).settext(itemClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+19,1).settext(itemDoubleClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+20,1).settext(itemEnteredEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+21,1).settext(itemPressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+22,1).settext(itemSelectionChangedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ComboItemAction oDesigner,nRow
		nSelectionBehaviorPos = C_AFTERCOMMON+6
		nAlternatingColorsPos = C_AFTERCOMMON+7
		switch nRow   {
			case nSelectionBehaviorPos
				oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nSelectionBehaviorPos,1)
				oCombo = new qCombobox
				oCombo.pObject = oWidget.pObject
				nIndex = oCombo.CurrentIndex()
				setSelectionBehaviorValue(nIndex)
			case nAlternatingColorsPos
				oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nAlternatingColorsPos,1)
				oCombo = new qCombobox
				oCombo.pObject = oWidget.pObject
				nIndex = oCombo.CurrentIndex()
				setAlternatingColorsValue(nIndex)
		}

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setRowCountValue(cValue)
				case C_AFTERCOMMON+1
					setColumnCountValue(cValue)
				case C_AFTERCOMMON+2
					setHorizontalHeadersValue(cValue)
				case C_AFTERCOMMON+3
					setColumnsWidthValue(cValue)
				case C_AFTERCOMMON+4
					setHorizontalHeaderStyleValue(cValue)
				case C_AFTERCOMMON+5
					setVerticalHeaderStyleValue(cValue)
				case C_AFTERCOMMON+6
					setSelectionbehaviorValue(cValue)
				case C_AFTERCOMMON+7
					setAlternatingrowcolorsValue(cValue)
				case C_AFTERCOMMON+8
					setcellActivatedEventCode(cValue)
				case C_AFTERCOMMON+9
					setcellChangedEventCode(cValue)
				case C_AFTERCOMMON+10
					setcellClickedEventCode(cValue)
				case C_AFTERCOMMON+11
					setcellDoubleClickedEventCode(cValue)
				case C_AFTERCOMMON+12
					setcellEnteredEventCode(cValue)
				case C_AFTERCOMMON+13
					setcellPressedEventCode(cValue)
				case C_AFTERCOMMON+14
					setcurrentCellChangedEventCode(cValue)
				case C_AFTERCOMMON+15
					setcurrentItemChangedEventCode(cValue)
				case C_AFTERCOMMON+16
					setitemActivatedEventCode(cValue)
				case C_AFTERCOMMON+17
					setitemChangedEventCode(cValue)
				case C_AFTERCOMMON+18
					setitemClickedEventCode(cValue)
				case C_AFTERCOMMON+19
					setitemDoubleClickedEventCode(cValue)
				case C_AFTERCOMMON+20
					setitemEnteredEventCode(cValue)
				case C_AFTERCOMMON+21
					setitemPressedEventCode(cValue)
				case C_AFTERCOMMON+22
					setitemSelectionChangedEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+8 ) and 
			   (nRow <= C_AFTERCOMMON+22 ) {
					oDesigner.NewEventName(cValue)
			}
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :RowCount =  "' + oDesigner.PrepareStringForFormFile(RowCountValue()) + '"'
		cOutput += "," + nl + cTabs + ' :ColumnCount =  "' + oDesigner.PrepareStringForFormFile(ColumnCountValue()) + '"'
		cOutput += "," + nl + cTabs + ' :HorizontalHeaders =  "' + oDesigner.PrepareStringForFormFile(HorizontalHeadersValue()) + '"'
		cOutput += "," + nl + cTabs + ' :ColumnsWidth =  "' + oDesigner.PrepareStringForFormFile(ColumnsWidthValue()) + '"'
		cOutput += "," + nl + cTabs + ' :HorizontalHeaderStyle =  "' + oDesigner.PrepareStringForFormFile(HorizontalHeaderStyleValue()) + '"'
		cOutput += "," + nl + cTabs + ' :VerticalHeaderStyle =  "' + oDesigner.PrepareStringForFormFile(VerticalHeaderStyleValue()) + '"'
		cOutput += "," + nl + cTabs + ' :selectionbehavior =  ' + SelectionBahviorValue()
		cOutput += "," + nl + cTabs + ' :alternatingcolors =  ' + AlternatingColorsValue()
		cOutput += "," + nl + cTabs + ' :setcellActivatedEvent =  "' + oDesigner.PrepareStringForFormFile(cellActivatedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcellChangedEvent =  "' + oDesigner.PrepareStringForFormFile(cellChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcellClickedEvent =  "' + oDesigner.PrepareStringForFormFile(cellClickedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcellDoubleClickedEvent =  "' + oDesigner.PrepareStringForFormFile(cellDoubleClickedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcellEnteredEvent =  "' + oDesigner.PrepareStringForFormFile(cellEnteredEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcellPressedEvent =  "' + oDesigner.PrepareStringForFormFile(cellPressedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentCellChangedEvent =  "' + oDesigner.PrepareStringForFormFile(currentCellChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentItemChangedEvent =  "' + oDesigner.PrepareStringForFormFile(currentItemChangedEventCode()) + '"'
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
		if RowCountValue() != NULL {
			cOutput += 'setRowCount(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",RowCountValue())
		}
		if ColumnCountValue() != NULL {
			cOutput += 'setColumnCount(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",ColumnCountValue())
		}
		if HorizontalHeadersValue() != NULL {
			aTempList = Split(HorizontalHeadersValue(),",")
			nPos = oDesigner.oModel.FormObject().IndexStart()
			for item in aTempList {
				cOutput += 'setHorizontalHeaderItem(#{f1}, new QTableWidgetItem("#{f2}"))' + nl
				cOutput = substr(cOutput,"#{f1}",""+nPos)
				cOutput = substr(cOutput,"#{f2}",oDesigner.PrepareStringForFormFile(item))
				nPos++
			}
		}
		if ColumnsWidthValue() != NULL {
			aTempList = Split(ColumnsWidthValue(),",")
			nPos = oDesigner.oModel.FormObject().IndexStart()
			for item in aTempList {
				cOutput += 'setColumnwidth(#{f1},#{f2})' + nl
				cOutput = substr(cOutput,"#{f1}",""+nPos)
				cOutput = substr(cOutput,"#{f2}",item)
				nPos++
			}
		}
		if HorizontalHeaderStyleValue() != NULL {
			cOutput += 'horizontalHeader().setStyleSheet("#{f1}")' + nl
			cOutput = substr(cOutput,"#{f1}",HorizontalHeaderStyle())
		}
		if VerticalHeaderStyleValue() != NULL {
			cOutput += 'verticalHeader().setStyleSheet("#{f1}")' + nl
			cOutput = substr(cOutput,"#{f1}",VerticalHeaderStyleValue())
		}
		# Selection Behavior
			cOutput += 'setSelectionBehavior(#{f1})' + nl
			switch SelectionBahviorValue() {
			case 0
				cOutput = substr(cOutput,"#{f1}","QAbstractItemView_SelectItems" )
			case 1
				cOutput = substr(cOutput,"#{f1}","QAbstractItemView_SelectRows" )
			case 2
				cOutput = substr(cOutput,"#{f1}","QAbstractItemView_SelectColumns" )
			}
		# Alternating Row Colors
			cOutput += 'setAlternatingRowColors(#{f1})' + nl
			switch AlternatingColorsValue() {
			case 0
				cOutput = substr(cOutput,"#{f1}","True")
			case 1
				cOutput = substr(cOutput,"#{f1}","False")
			}
		cOutput += 'setcellActivatedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cellActivatedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cellActivatedEventCode())
		cOutput += 'setcellChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cellChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cellChangedEventCode())
		cOutput += 'setcellClickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cellClickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cellClickedEventCode())
		cOutput += 'setcellDoubleClickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cellDoubleClickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cellDoubleClickedEventCode())
		cOutput += 'setcellEnteredEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cellEnteredEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cellEnteredEventCode())
		cOutput += 'setcellPressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cellPressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cellPressedEventCode())
		cOutput += 'setcurrentCellChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,currentCellChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",currentCellChangedEventCode())
		cOutput += 'setcurrentItemChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,currentItemChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",currentItemChangedEventCode())
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
		SetRowCountValue(itemdata[:RowCount])
		SetColumnCountValue(itemdata[:ColumnCount])
		SetHorizontalHeadersValue(itemdata[:HorizontalHeaders])
		SetColumnsWidthValue(itemdata[:ColumnsWidth])
		SetHorizontalHeaderStyleValue(itemdata[:HorizontalHeaderStyle])
		SetVerticalHeaderStyleValue(itemdata[:VerticalHeaderStyle])
		SetSelectionbehaviorValue(itemdata[:SelectionBehavior])
		SetAlternatingColorsValue(itemdata[:AlternatingColors])
		SetcellActivatedEventCode(itemdata[:setcellActivatedEvent])
		SetcellChangedEventCode(itemdata[:setcellChangedEvent])
		SetcellClickedEventCode(itemdata[:setcellClickedEvent])
		SetcellDoubleClickedEventCode(itemdata[:setcellDoubleClickedEvent])
		SetcellEnteredEventCode(itemdata[:setcellEnteredEvent])
		SetcellPressedEventCode(itemdata[:setcellPressedEvent])
		SetcurrentCellChangedEventCode(itemdata[:setcurrentCellChangedEvent])
		SetcurrentItemChangedEventCode(itemdata[:setcurrentItemChangedEvent])
		SetitemActivatedEventCode(itemdata[:setitemActivatedEvent])
		SetitemChangedEventCode(itemdata[:setitemChangedEvent])
		SetitemClickedEventCode(itemdata[:setitemClickedEvent])
		SetitemDoubleClickedEventCode(itemdata[:setitemDoubleClickedEvent])
		SetitemEnteredEventCode(itemdata[:setitemEnteredEvent])
		SetitemPressedEventCode(itemdata[:setitemPressedEvent])
		SetitemSelectionChangedEventCode(itemdata[:setitemSelectionChangedEvent])
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))


/*
**	Project : Form Designer 
**	File Purpose :  QPushButton Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QPushButton from QPushButton

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cClickEvent = ""
	cBtnImage = ""

	func SetClickEventCode cValue
		cClickEvent = cValue

	func ClickEventCode
		return cClickEvent

	func BtnImageValue
		return cBtnImage

	func SetBtnImageValue cValue
		cBtnImage = cValue

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TEXT, 		# "Text"
						False)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_IMAGE,		# "Image"
						True)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETCLICKEVENT, 	# "Set Click Event"
						False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(text())
		# Set the Button Image
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(BtnImageValue())
			DisplayButtonImage(oDesigner,BtnImageValue())
		# Set the Click Event
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(clickeventcode())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setText(cValue)
					CreateEventCodeFromButtonText(oDesigner,cValue)
				case C_AFTERCOMMON+1
					setBtnImageValue(cValue)
					DisplayButtonImage(oDesigner,cValue)
				case C_AFTERCOMMON+2  	# Click Event
					setClickEventCode(cValue)
					oDesigner.NewEventName(cValue)
			}
		}

	func CreateEventCodeFromButtonText oDesigner,cValue 
		if cClickEvent = NULL {
			cValue = substr(trim(cValue)," ","_")
			setClickEventCode(cValue)
			oDesigner.NewEventName(cValue)
			oDesigner.oView.oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(clickeventcode())
		}


	func DialogButtonAction oDesigner,nRow
		CommonDialogButtonAction(oDesigner,nRow)
		switch nRow {
			case C_AFTERCOMMON+1	# Button Image
				cFile = oDesigner.oGeneral.SelectFile(oDesigner)
				if ! isWebAssembly() {
					ApplyOpenImageFile(oDesigner,cFile)
				}
		}

	func ApplyOpenImageFile oDesigner,cFile
		setBtnImageValue(cFile)
		DisplayProperties(oDesigner)

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :text =  "' + oDesigner.PrepareStringForFormFile(Text()) + '"'
		cOutput += "," + nl + cTabs + ' :BtnImage =  "' + oDesigner.PrepareStringForFormFile(BtnImageValue()) + '"'
		cOutput += "," + nl + cTabs + ' :setClickEvent =  "' + oDesigner.PrepareStringForFormFile(ClickEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setText("#{f1}")' + nl
		cOutput += 'setClickEvent("#{f2}")' + nl
		cOutput += 'setBtnImage(#{f3},"#{f4}")' + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(text()))
		cOutput = PrepareEvent(cOutput,ClickEventCode(),"#{f2}")
		cOutput = substr(cOutput,"#{f2}",ClickEventCode())
		cOutput = substr(cOutput,"#{f3}",oDesigner.oModel.GetObjectName(self))
		cOutput = substr(cOutput,"#{f4}",BtnImageValue())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setText(itemdata[:text])
		SetBtnImageValue(itemdata[:BtnImage])
		SetClickEventCode(itemdata[:setClickEvent])
		DisplayButtonImage(oDesigner,itemdata[:BtnImage])

	func DisplayButtonImage oDesigner,cFile 
		if fexists(cFile) {
			setBtnImage(self,cFile)
		else 
			cFileAndPath = JustFilePath(oDesigner.oFile.GetFileName())+cFile	
			setBtnImage(self,cFileAndPath)
		}

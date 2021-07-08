/*
**	Project : Form Designer 
**	File Purpose :  QWebView Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QWebView from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cURL = ""

	cloadProgressEvent  = ""
	cloadStartedEvent  = ""
	cselectionChangedEvent  = ""
	curlChangedEvent  = ""

	func URLValue
		return cURL

	func SetURLvalue value
		cURL = value

	func SetloadProgressEventCode cValue
		cloadProgressEvent  = cValue

	func loadProgressEventCode
		return cloadProgressEvent

	func SetloadStartedEventCode cValue
		cloadStartedEvent  = cValue

	func loadStartedEventCode
		return cloadStartedEvent

	func SetselectionChangedEventCode cValue
		cselectionChangedEvent  = cValue

	func selectionChangedEventCode
		return cselectionChangedEvent

	func SeturlChangedEventCode cValue
		curlChangedEvent  = cValue

	func urlChangedEventCode
		return curlChangedEvent

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_URL,False)			 	# "URL"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_LOADPROGRESSEVENT,False)		# "loadProgressEvent "
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_LOADSTARTEDEVENT,False)		# "loadStartedEvent "
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SELECTIONCHANGEDEVENT,False)	# "selectionChangedEvent "
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_URLCHANGEDEVENT,False)		# "urlChangedEvent "

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(URLValue())
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(loadProgressEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(loadStartedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(selectionChangedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(urlChangedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setURLValue(cValue)
				case C_AFTERCOMMON+1
					setloadProgressEventCode(cValue)
				case C_AFTERCOMMON+2
					setloadStartedEventCode(cValue)
				case C_AFTERCOMMON+3
					setselectionChangedEventCode(cValue)
				case C_AFTERCOMMON+4
					seturlChangedEventCode(cValue)
			}
			if (nRow >= C_AFTERCOMMON+1 ) and 
			   (nRow <= C_AFTERCOMMON+4 ) {
					oDesigner.NewEventName(cValue)
			}
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :URL =  "' + oDesigner.PrepareStringForFormFile(URLValue()) + '"'
		cOutput += "," + nl + cTabs + ' :setloadProgressEvent  =  "' + oDesigner.PrepareStringForFormFile(loadProgressEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setloadStartedEvent  =  "' + oDesigner.PrepareStringForFormFile(loadStartedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :setselectionChangedEvent  =  "' + oDesigner.PrepareStringForFormFile(selectionChangedEventCode()) + '"'
		cOutput += "," + nl + cTabs + ' :seturlChangedEvent  =  "' + oDesigner.PrepareStringForFormFile(urlChangedEventCode()) + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'loadpage(new qURL("#{f1}"))' + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(URLValue()))
		cOutput += 'setloadProgressEvent ("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,loadProgressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",loadProgressEventCode())
		cOutput += 'setloadStartedEvent ("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,loadStartedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",loadStartedEventCode())
		cOutput += 'setselectionChangedEvent ("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,selectionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",selectionChangedEventCode())
		cOutput += 'seturlChangedEvent ("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,urlChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",urlChangedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setURLValue(itemdata[:URL])
		SetloadProgressEventCode(itemdata[:setloadProgressEvent ])
		SetloadStartedEventCode(itemdata[:setloadStartedEvent ])
		SetselectionChangedEventCode(itemdata[:setselectionChangedEvent ])
		SeturlChangedEventCode(itemdata[:seturlChangedEvent ])

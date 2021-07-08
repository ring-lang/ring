/*
**	Project : Form Designer 
**	File Purpose :  QTimer Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QTimer from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cInterval = "1000"
	cTimeOut = ""

	func IntervalValue
		return cInterval

	func SetIntervalValue cValue
		cInterval = cValue

	func TimeOutValue
		return cTimeOut

	func SetTimeOutValue cValue
		cTimeOut = cValue

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_INTERVAL,False)	 # "Interval"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TIMEOUTEVENT,False) # "Timeout Event"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Interval Value
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(IntervalValue())
		# Set the Timeout Event Value
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(TimeOutValue())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON
				setIntervalValue(cValue)
			case C_AFTERCOMMON + 1
				setTimeOutValue(cValue)
				oDesigner.NewEventName(cValue)
		}
		# Set the object name
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :Interval =  "' + oDesigner.PrepareStringForFormFile(IntervalValue()) + '"'
		cOutput += "," + nl + cTabs + ' :Timeout =  "' + oDesigner.PrepareStringForFormFile(TimeoutValue()) + '"'
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) +
		oDesigner.oModel.GetObjectName(self) + " = " +
		'new #{f1}(win) {
#{f2}
		}' + nl
		cClass = substr(classname(self),"formdesigner_","")
		cOutput = substr(cOutput,"#{f1}",cClass)
		cOutput = substr(cOutput,"#{f2}",AddTabs(GenerateCustomCode(oDesigner),3))
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setInterval(#{f1})' + nl +
				'setTimeoutevent("#{f2}")' + nl +
				'start()' + nl
		cOutput = substr(cOutput,"#{f1}",IntervalValue())
		cOutput = PrepareEvent(cOutput,TimeoutValue(),"#{f2}")
		cOutput = substr(cOutput,"#{f2}",TimeoutValue())
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setIntervalValue(itemdata[:Interval])
		setTimeoutValue(itemdata[:Timeout])
		setText(oDesigner.oModel.GetObjectName(self))

/*
**	Project : Form Designer 
**	File Purpose :  QVideoWidget Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QVideoWidget from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cVideoFile = ""

	func SetVideoFile cValue
		cVideoFile = cValue

	func VideoFile
		return cVideoFile

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_VIDEOFILE,True)	# "Video File"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Image File
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(VideoFile())
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			if cVideoFile = NULL {
				setText(oDesigner.oModel.GetObjectName(self))
			}

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON {
			setVideoFile(cValue)
		}
		# Set the object name
			if cVideoFile = NULL {
				setText(oDesigner.oModel.GetObjectName(self))
			}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :Videofile =  "' + oDesigner.PrepareStringForFormFile(VideoFile()) + '"'
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setVideoFile(itemdata[:Videofile])
		DisplayProperties(oDesigner)

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'player#{f2} = new qmediaplayer() { ' + nl +
			'setmedia(new qurl("#{f1}"))' + nl +
			' setvideooutput(#{f2})' + nl +
			'}' + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(VideoFile()))
		cObjName = oDesigner.oModel.GetObjectName(self)
		cOutput = substr(cOutput,"#{f2}",cObjName)
		return cOutput

	func DialogButtonAction oDesigner,nRow
		CommonDialogButtonAction(oDesigner,nRow)
		if nRow = C_AFTERCOMMON {	# Video File
			cFile = oDesigner.oGeneral.SelectFile(oDesigner)
			setVideoFile(cFile)
			DisplayProperties(oDesigner)
		}


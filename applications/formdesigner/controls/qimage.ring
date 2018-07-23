/*
**	Project : Form Designer 
**	File Purpose :  QImage Control
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QImage from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cImageFile = ""

	func SetImageFile cValue
		cImageFile = cValue

	func ImageFile
		return cImageFile

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_IMAGEFILE,True)	# "Image File"

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Image File
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(ImageFile())
			DisplayTheImage(oDesigner)
		oPropertiesTable.Blocksignals(False)
		# Set the object name
			if cImageFile = NULL {
				setText(oDesigner.oModel.GetObjectName(self))
			}

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON {
			setImageFile(cValue)
			DisplayTheImage(oDesigner)
		}
		# Set the object name
			if cImageFile = NULL {
				setText(oDesigner.oModel.GetObjectName(self))
			}

	func DisplayTheImage oDesigner
		if fexists(ImageFile()) {
			setpixmap(new qpixmap(ImageFile()))	
		else 
			cFileAndPath = JustFilePath(oDesigner.oFile.GetFileName())+ImageFile()				
			setpixmap(new qpixmap(cFileAndPath))
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount)
		cOutput += "," + nl + cTabs + ' :imagefile =  "' + oDesigner.PrepareStringForFormFile(ImageFile()) + '"'
		return cOutput

	func RestoreProperties oDesigner,Item
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setImageFile(itemdata[:imagefile])
		DisplayProperties(oDesigner)

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setPixMap(New qPixMap("#{f1}"))' + nl
		cOutput = substr(cOutput,"#{f1}",oDesigner.PrepareStringForFormFile(ImageFile()))
		return cOutput

	func DialogButtonAction oDesigner,nRow
		CommonDialogButtonAction(oDesigner,nRow)
		if nRow = C_AFTERCOMMON {	# Image File
			cFile = oDesigner.oGeneral.SelectFile(oDesigner)
			# Use Relative Path
				cFormPath = JustFilePath(oDesigner.oFile.GetFileName())+ImageFile()				
				if len(cFile) > len(cFormPath) {
					if left(cFile,len(cFormPath)) = cFormPath {
						cFile = substr(cFile,len(cFormPath)+1)
					}
				} 
			setImageFile(cFile)
			DisplayProperties(oDesigner)
		}


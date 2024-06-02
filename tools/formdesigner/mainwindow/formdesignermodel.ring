/*
**	Project : Form Designer 
**	File Purpose :  Form Designer Model
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

Class FormDesignerModel

	aManySelectedObjects = []
	aObjectsList = []
	nActiveObject = 0
	nIDCounter = 0
	nLabelsCount = 0
	nPushButtonsCount = 0
	nLineEditsCount = 0
	nTextEditsCount = 0
	nListWidgetsCount = 0
	nCheckBoxesCount = 0
	nImagesCount = 0
	nSlidersCount = 0
	nProgressbarsCount = 0
	nSpinBoxesCount = 0
	nComboBoxesCount = 0
	nDateTimeEditsCount = 0
	nTableWidgetsCount = 0
	nTreeWidgetsCount = 0
	nRadioButtonsCount = 0
	nWebViewsCount = 0
	nDialsCount = 0
	nVideoWidgetsCount = 0
	nFramesCount = 0
	nLCDNumbersCount = 0
	nHyperLinksCount = 0
	nTimersCount = 0
	nAllEventsCount = 0
	nLayoutsCount = 0
	nTabsCount = 0
	nStatusbarsCount = 0
	nToolbarsCount = 0

	cCurrentParent = ""
	oCurrentParentCache = NULL

	func AddObject cName,oObject
		nIDCounter++
		aObjectsList + [cName,oObject,nIDCounter]
		nActiveObject = len(aObjectsList)

	func getCurrentID
		return nIDCounter

	func IDToIndex nID
		return find(aObjectsList,nID,3)

	func GetObjects
		return aObjectsList

	func ActiveObject
		return aObjectsList[nActiveObject][2]

	func ActiveObjectIndex
		return nActiveObject

	func GetObjectByIndex nIndex
		return aObjectsList[nIndex][2]

	func GetObjectByID nID
		return GetObjectByIndex(IDToIndex(nID))

	func FormObject
		return aObjectsList[1][2]

	func CurrentParent
		if ClassName(ActiveObject()) = "formdesigner_qtabwidget" {
			if len(ActiveObject().aTabs) > 0 {
				cCurrentParent = GetObjectName(ActiveObject())+"Page"+(ActiveObject().CurrentIndex()+1)
				oCurrentParentCache = ActiveObject()
				return ActiveObject().aTabs[ActiveObject().CurrentIndex()+1][1]
			}
		}
		if isObject(oCurrentParentCache) {
				cCurrentParent = GetObjectName(oCurrentParentCache)+"Page"+(oCurrentParentCache.CurrentIndex()+1)
				return oCurrentParentCache.aTabs[oCurrentParentCache.CurrentIndex()+1][1]
		}
		cCurrentParent = "win"	# Window Object (Generated Name)
		return FormObject()

	func CurrentParentCache
		return oCurrentParentCache

	func RemoveCurrentParentCache
		oCurrentParentCache = NULL

	func CurrentParentName
		return cCurrentParent

	func CurrentParentByName cName
		if (cName = NULL) or (cName = "win") {
			return FormObject()
		}
		# Here Control belong to a Tab Page
			aList = split(cName,"Page")
			# aList[1] = Tab Control Name
			# aList[2] = Tab Index (start from 1)
			nPos = find(aObjectsList,aList[1],1)
			oTab = aObjectsList[nPos][2]
			return oTab.aTabs[NumOrZero(aList[2])][1]
		return FormObject()

	func ObjectsCount
		return len(aObjectsList)

	func AddLabel oObject
		nLabelsCount++
		AddObject("Label"+nLabelsCount,oObject)

	func LabelsCount
		return nLabelsCount

	func IsFormActive
		return nActiveObject = 1

	func DeleteActiveObject
		del(aObjectsList,nActiveObject)
		nActiveObject = 1

	func ClearSelectedObjects
		aManySelectedObjects = []

	func AddSelectedObject nIndex
		if nIndex != 1 {
			aManySelectedObjects + aObjectsList[nIndex]
		}

	func GetSelectedObjects
		return aManySelectedObjects

	func RefreshSelectedObjects
		# Refresh objects to update properties after updates to the group
		# We need this when we select group, update font and color for them
		# Then Click Duplicate  (Copy and Paste)
		if len(aManySelectedObjects) < 1 { return }
		for oObject in aManySelectedObjects {
			nPos = find(aObjectsList,oObject[3],3)
			oObject = aObjectsList[nPos]
		}

	func IsManySelected
		return len(aManySelectedObjects) 	# 0=False  & other values = True

	func DeleteSelectedObjects
		for item in aManySelectedObjects {
			nPos = find(aObjectsList,item[3],3)
			del(aObjectsList,nPos)
		}
		ClearSelectedObjects()
		nActiveObject = 1

	func IsObjectSelected nObjectID
		if find(aManySelectedObjects,nObjectID,3) {
			return True
		}
		return False

	func RemoveSelectedObject nObjectID
		nPos = find(aManySelectedObjects,nObjectID,3)
		if nPos {
			del(aManySelectedObjects,nPos)
		}

	func AddPushButton oObject
		nPushButtonsCount++
		AddObject("Button"+nPushButtonsCount,oObject)

	func PushButtonsCount
		return nPushButtonsCount

	func AddLineEdit oObject
		nLineEditsCount++
		AddObject("LineEdit"+nLineEditsCount,oObject)

	func LineEditsCount
		return nLineEditsCount

	func AddTextEdit oObject
		nTextEditsCount++
		AddObject("TextEdit"+nTextEditsCount,oObject)

	func TextEditsCount
		return nTextEditsCount

	func AddListWidget oObject
		nListWidgetsCount++
		AddObject("ListWidget"+nListWidgetsCount,oObject)

	func ListWidgetsCount
		return nListWidgetsCount

	func AddCheckBox oObject
		nCheckBoxesCount++
		AddObject("CheckBox"+nCheckBoxesCount,oObject)

	func CheckBoxesCount
		return nCheckBoxesCount

	func AddImage oObject
		nImagesCount++
		AddObject("Image"+nImagesCount,oObject)

	func ImagesCount
		return nImagesCount

	func AddSlider oObject
		nSlidersCount++
		AddObject("Slider"+nSlidersCount,oObject)

	func SlidersCount
		return nSlidersCount

	func AddProgressbar oObject
		nProgressbarsCount++
		AddObject("Progressbar"+nProgressbarsCount,oObject)

	func ProgressbarsCount
		return nProgressbarsCount

	func AddSpinBox oObject
		nSpinBoxesCount++
		AddObject("Spinbox"+nSpinBoxesCount,oObject)

	func SpinBoxesCount
		return nSpinBoxesCount

	func AddComboBox oObject
		nComboBoxesCount++
		AddObject("Combobox"+nComboBoxesCount,oObject)

	func ComboBoxesCount
		return nComboBoxesCount

	func AddDateTimeEdit oObject
		nDateTimeEditsCount++
		AddObject("Datetimeedit"+nDateTimeEditsCount,oObject)

	func DateTimeEditsCount
		return nDateTimeEditsCount

	func AddTableWidget oObject
		nTableWidgetsCount++
		AddObject("TableWidget"+nTableWidgetsCount,oObject)

	func TableWidgetsCount
		return nTableWidgetsCount

	func AddTreeWidget oObject
		nTreeWidgetsCount++
		AddObject("TreeWidget"+nTreeWidgetsCount,oObject)

	func TreeWidgetsCount
		return nTreeWidgetsCount

	func AddRadioButton oObject
		nRadioButtonsCount++
		AddObject("RadioButton"+nRadioButtonsCount,oObject)

	func RadioButtonsCount
		return nRadioButtonsCount

	func AddWebView oObject
		nWebViewsCount++
		AddObject("WebView"+nWebViewsCount,oObject)

	func WebViewsCount
		return nWebViewsCount

	func AddDial oObject
		nDialsCount++
		AddObject("Dial"+nDialsCount,oObject)

	func DialsCount
		return nDialsCount

	func AddVideoWidget oObject
		nVideoWidgetsCount++
		AddObject("VideoWidget"+nVideoWidgetsCount,oObject)

	func VideoWidgetsCount
		return nVideoWidgetsCount

	func AddFrame oObject
		nFramesCount++
		AddObject("Frame"+nFramesCount,oObject)

	func FramesCount
		return nFramesCount

	func AddLCDNumber oObject
		nLCDNumbersCount++
		AddObject("LCDNumber"+nLCDNumbersCount,oObject)

	func LCDNumbersCount
		return nLCDNumbersCount

	func AddHyperLink oObject
		nHyperLinksCount++
		AddObject("HyperLink"+nHyperLinksCount,oObject)

	func HyperLinksCount
		return nHyperLinksCount

	func AddTimer oObject
		nTimersCount++
		AddObject("Timer"+nTimersCount,oObject)

	func TimersCount
		return nTimersCount

	func AddAllEvents oObject
		nAllEventsCount++
		AddObject("AllEvents"+nAllEventsCount,oObject)

	func AllEventsCount
		return nAllEventsCount

	func AddLayout oObject
		nLayoutsCount++
		AddObject("Layout"+nLayoutsCount,oObject)

	func LayoutsCount
		return nLayoutsCount

	func AddTab oObject
		nTabsCount++
		AddObject("Tab"+nTabsCount,oObject)

	func TabsCount
		return nTabsCount

	func AddStatusbar oObject
		nStatusbarsCount++
		AddObject("Statusbar"+nStatusbarsCount,oObject)

	func StatusbarsCount
		return nStatusbarsCount

	func AddToolbar oObject
		nToolbarsCount++
		AddObject("Toolbar"+nToolbarsCount,oObject)

	func ToolbarsCount
		return nToolbarsCount

	func DeleteAllObjects
		aManySelectedObjects = []
		nActiveObject = 1
		nIDCounter = 1
		nLabelsCount = 0
		nPushButtonsCount = 0
		nLineEditsCount = 0
		nTextEditsCount = 0
		nListWidgetsCount = 0
		nCheckBoxesCount = 0
		nImagesCount = 0
		nSlidersCount = 0
		nProgressbarsCount = 0
		nSpinBoxesCount = 0
		nComboBoxesCount = 0
		nDateTimeEditsCount = 0
		nTableWidgetsCount = 0
		nTreeWidgetsCount = 0
		nRadioButtonsCount = 0
		nWebViewsCount = 0
		nDialsCount = 0
		nVideoWidgetsCount = 0
		nFramesCount = 0
		nLCDNumbersCount = 0
		nHyperLinksCount = 0
		nTimersCount = 0
		nAllEventsCount = 0
		nLayoutsCount = 0
		nTabsCount = 0
		nStatusbarsCount = 0
		nToolbarsCount = 0

		# Delete Objects but Keep the Form Object
		while  len(aObjectsList) > 1 {
			del(aObjectsList,2)
		}

	func GetObjectName oObject
		for Item in aObjectsList {
			if PtrCmp( Item[2].pObject , oObject.pObject ) {
				return Item[1]
			}
		}
		raise("Can't find the object!")

	func SetObjectName oDesigner,oObject,cValue
		# Check duplication
			for Item in aObjectsList {
				if lower(trim(Item[1])) = lower(trim(cValue)) {
					if not PtrCmp( Item[2].pObject , oObject.pObject ) {
						oDesigner.ShowMsg("Sorry","Name Duplication!","Write another Name!")
					}
					return
				}
			}
		# Set the new name 
			for Item in aObjectsList {
				if PtrCmp( Item[2].pObject , oObject.pObject ) {
					cOldName = Item[1]
					Item[1] = cValue
				}
			}
		# Update Control Name in Layouts  		
			for Item in aObjectsList {
				if ClassName(Item[2]) = "formdesigner_qlayout" {
					cLayoutObjects = Item[2].layoutobjectsValue()
					cLayoutObjects = substr(cLayoutObjects,cOldName,cValue)
					Item[2].setlayoutobjectsValue(cLayoutObjects)
				}
			}



	func GetObjectClassByName cName
		cOutput = ""
		for Item in aObjectsList {
			if lower(trim(Item[1])) = lower(trim(cName))  {
				cOutput = lower(classname(Item[2]))
				exit
			}
		}
		return cOutput

	func GetObjectsNames
		aList = []
		for Item in aObjectsList {
			aList + Item[1]
		}
		return aList

	func GetLayoutsNames 
		aList = []
		for Item in aObjectsList {
			if ClassName(Item[2]) = "formdesigner_qlayout" {
				aList + Item[1]
			}
		}
		return aList

	func ActiveObjectItemAsList
		return [ aObjectsList[nActiveObject] ]

	func RaiseActiveObject
		aObjectsList + 0
		swap(aObjectsList,nActiveObject,len(aObjectsList))
		del(aObjectsList,nActiveObject)

	func LowerActiveObject
		cParentValue = ActiveObject().CurrentParentName()
		for x = 2 to len(aObjectsList) {
				if aObjectsList[x][2].CurrentParentName() = cParentValue {
					exit
				}
		}
		if not x = nActiveObject {
			insert(aObjectsList,x,0)
			swap(aObjectsList,nActiveObject+1,x+1)
			del(aObjectsList,nActiveObject+1)
		}

	func MoveObjectDown nIndex 
		swap(aObjectsList,nIndex+1,nIndex+2)

	func MoveObjectUp nIndex 
		swap(aObjectsList,nIndex+1,nIndex)

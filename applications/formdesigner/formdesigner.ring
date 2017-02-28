/*
**	Project : Form Designer (Under Development)
**	File Purpose :  Main File
**	Date : 2017.02.17
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "guilib.ring"
load "stdlib.ring"

cCurrentDir = CurrentDir() + "/"

# Prepare Controls Classes 
	for cClassName in [
		:FormDesigner_QLabel,
		:FormDesigner_QPushButton,
		:FormDesigner_QLineEdit,
		:FormDesigner_QTextEdit,
		:FormDesigner_QListWidget,
		:FormDesigner_QCheckBox,
		:FormDesigner_QImage,
		:FormDesigner_QSlider,
		:FormDesigner_QProgressbar,
		:FormDesigner_QSpinBox,
		:FormDesigner_QComboBox,
		:FormDesigner_QDateTimeEdit,
		:FormDesigner_QTableWidget,
		:FormDesigner_QTreeWidget,
		:FormDesigner_QRadioButton
	] {
		mergemethods(cClassName,:MoveResizeCorners)
		mergemethods(cClassName,:CommonAttributesMethods)
	}

new qApp {
	StyleFusion()
	Open_Window(:FormDesignerController)
	exec()
}

Class FormDesignerController from WindowsControllerParent

	oView = new FormDesignerView
	oModel = new FormDesignerModel
	oGeneral = new FormDesignerGeneral
	oFile = new FormDesignerFileSystem

	func Start
		oView.CreateMainWindow(oModel)
		AddObjectsToCombo()
		AddObjectProperties()
		DisplayObjectProperties()		
		oView.WindowMoveResizeEvents()

	func ObjectProperties
		AddObjectProperties()
		DisplayObjectProperties()	

	func AddObjectsToCombo
		oView.oObjectsCombo.blocksignals(True)
		oView.oObjectsCombo.Clear()
		aObjects = oModel.GetObjects() 
		for item in aObjects {			
			oView.oObjectsCombo.AddItem(item[1],0)
		}
		oView.oObjectsCombo.setcurrentindex(len(aObjects)-1)
		oView.oObjectsCombo.blocksignals(False)

	func AddObjectProperties  
		oView.oPropertiesTable   {	
			# Remove Rows
				nCount = rowcount()
				for t = 1 to nCount {
					removerow(0)
				}
			setHorizontalHeaderItem(0, new QTableWidgetItem("Property"))
			setHorizontalHeaderItem(1, new QTableWidgetItem("Value"))
			setHorizontalHeaderItem(2, new QTableWidgetItem(""))
		}
		oModel.ActiveObject().AddObjectProperties(self)

	func DisplayObjectProperties 
		oModel.ActiveObject().DisplayProperties(self)	

	func SetToolboxModeToSelect
		oView.oToolBtn1.setChecked(2)
		ChangeToolBoxAction()
	
	func UpdateProperties
		SetToolboxModeToSelect()
		nRow = oView.oPropertiesTable.Currentrow()
		nCol = oView.oPropertiesTable.Currentcolumn() 
		cValue = oView.oPropertiesTable.item(nRow,nCol).text()
		oModel.ActiveObject().UpdateProperties(self,nRow,nCol,cValue)

	func ResizeWindowAction
		oView.oLabelSelect.Hide()
		SetToolboxModeToSelect()
		oModel.FormObject().DisplayProperties(self)	
		oView.oFilter.seteventoutput(False)

	func MoveWindowAction
		oView.oLabelSelect.Hide()
		SetToolboxModeToSelect()
		oModel.FormObject().DisplayProperties(self)	

	func MousePressAction
		oModel.FormObject().MousePressAction(self)
		if oView.oToolBtn1.ischecked() {	# Select Mode
			# Activate the Window Object 
			ChangeObjectByCode(0)
		}
		oView.oFilter.seteventoutput(False)

	func MouseReleaseAction
		oModel.FormObject().MouseReleaseAction(self)
		oView.oFilter.seteventoutput(False)

	func MouseMoveAction
		oModel.FormObject().MouseMoveAction(self)
		oView.oFilter.seteventoutput(False)

	func DialogButtonAction nRow 
		SetToolboxModeToSelect()
		oModel.ActiveObject().DialogButtonAction(self,nRow)

	func ComboItemAction nRow 
		SetToolboxModeToSelect()
		oModel.ActiveObject().ComboItemAction(self,nRow)

	func SelectDrawAction aRect 
		if oView.oToolBtn1.ischecked()  { # Select
			oModel.ClearSelectedObjects()
			SelectObjects(aRect)
			if oModel.IsManySelected() {
				nWidth = oView.oPropertiesDock.width()
				oView.oPropertiesDock.setWidget(oView.oProperties2)
				oView.oPropertiesDock.setminimumwidth(nWidth)
			else
				oView.oPropertiesDock.setminimumwidth(10)
				oView.oPropertiesDock.setWidget(oView.oProperties)
			}
		elseif oView.oToolBtn2.ischecked()   # Create Label 
			HideCorners()
			oModel.AddLabel(new FormDesigner_QLabel(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
				}
			)
			NewControlEvents("Label",oModel.LabelsCount())
		elseif oView.oToolBtn3.ischecked()   # Create QPushButton
			HideCorners()
			oModel.AddPushButton(new FormDesigner_QPushButton(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setMouseTracking(True)
					setFocusPolicy(0)
				}
			)
			NewControlEvents("Button",oModel.PushButtonsCount())
		elseif oView.oToolBtn4.ischecked()   # Create QLineEdit
			HideCorners()
			oModel.AddLineEdit(new FormDesigner_QLineEdit(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("LineEdit",oModel.LineEditsCount())
		elseif oView.oToolBtn5.ischecked()   # Create QTextEdit
			HideCorners()
			oModel.AddTextEdit(new FormDesigner_QTextEdit(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("TextEdit",oModel.TextEditsCount())
		elseif oView.oToolBtn6.ischecked()   # Create QListWidget
			HideCorners()
			oModel.AddListWidget(new FormDesigner_QListWidget(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("ListWidget",oModel.ListWidgetsCount())
		elseif oView.oToolBtn7.ischecked()   # Create QCheckBox
			HideCorners()
			oModel.AddCheckBox(new FormDesigner_QCheckBox(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("CheckBox",oModel.CheckBoxesCount())
		elseif oView.oToolBtn8.ischecked()   # Create QImage
			HideCorners()
			oModel.AddImage(new FormDesigner_QImage(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("Image",oModel.ImagesCount())
		elseif oView.oToolBtn9.ischecked()   # Create QSlider
			HideCorners()
			oModel.AddSlider(new FormDesigner_QSlider(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("Slider",oModel.SlidersCount())
		elseif oView.oToolBtn10.ischecked()   # Create QProgressBar
			HideCorners()
			oModel.AddProgressbar(new FormDesigner_QProgressbar(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("Progressbar",oModel.ProgressbarsCount())
		elseif oView.oToolBtn11.ischecked()   # Create QSpinBox
			HideCorners()
			oModel.AddSpinBox(new FormDesigner_QSpinBox(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("SpinBox",oModel.SpinBoxesCount())
		elseif oView.oToolBtn12.ischecked()   # Create QComboBox
			HideCorners()
			oModel.AddComboBox(new FormDesigner_QComboBox(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("ComboBox",oModel.ComboBoxesCount())
		elseif oView.oToolBtn13.ischecked()   # Create QDateTimeEdit
			HideCorners()
			oModel.AddDateTimeEdit(new FormDesigner_QDateTimeEdit(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("DateTimeEdit",oModel.DateTimeEditsCount())
		elseif oView.oToolBtn14.ischecked()   # Create QTableWidget 
			HideCorners()
			oModel.AddTableWidget(new FormDesigner_QTableWidget(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("TableWidget",oModel.TableWidgetsCount())
		elseif oView.oToolBtn15.ischecked()   # Create QTreeWidget 
			HideCorners()
			oModel.AddTreeWidget(new FormDesigner_QTreeWidget(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("TreeWidget",oModel.TreeWidgetsCount())
		elseif oView.oToolBtn16.ischecked()   # Create QRadioButton  
			HideCorners()
			oModel.AddRadioButton(new FormDesigner_QRadioButton(oModel.FormObject()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
				}
			)
			NewControlEvents("RadioButton",oModel.RadioButtonsCount())


		}

	func NewControlEvents cName,nCount
			oFilter = new qAllevents(oModel.ActiveObject()) {
				setmousebuttonpressevent(Method(:ActiveObjectMousePress+"("+this.oModel.GetCurrentID()+")"))
				setMouseButtonReleaseEvent(Method(:ActiveObjectMouseRelease+"("+this.oModel.GetCurrentID()+")")) 
				setMouseMoveEvent(Method(:ActiveObjectMouseMove+"("+this.oModel.GetCurrentID()+")"))
			}
			oModel.ActiveObject().installeventfilter(oFilter)
			oModel.ActiveObject().oFilter = oFilter
			oModel.ActiveObject().setText(cName+nCount)
			oModel.ActiveObject().Show()
			oModel.ActiveObject().CreateCorners()
			AddObjectsToCombo()
			ObjectProperties()

	func SelectObjects aRect
		nSX = aRect[1]
		nSY = aRect[2]
		nSX2 = nSX + aRect[3]
		nSY2 = nSY + aRect[4]
		aObjects = oModel.GetObjects() 
		for x = 2 to len(aObjects) {	# Start from 2 to avoid the Form Object	
			item = aObjects[x]
			oObject = item[2]	
			nX = oObject.x() 
			nY = oObject.y()
			nX2 = nX + oObject.Width()
			nY2 = nY + oObject.Height() 		
			if Intersection(nX,nY,nX2,nY2,nSX,nSY,nSX2,nSY2) {
				oObject.oCorners.Show()
				oModel.AddSelectedObject(x)
			}	 
		}

	func Intersection nX,nY,nX2,nY2,nSX,nSY,nSX2,nSY2 
		if pointinbox(nX,nY,nSX,nSY,nSX2,nSY2) or 
			pointinbox(nX,nY2,nSX,nSY,nSX2,nSY2) or 
			pointinbox(nX2,nY,nSX,nSY,nSX2,nSY2) or 
			pointinbox(nX2,nY2,nSX,nSY,nSX2,nSY2) or
			pointinbox(nSX,nSY,nX,nY,nX2,nY2) or 
			pointinbox(nSX,nSY2,nX,nY,nX2,nY2) or 
			pointinbox(nSX2,nSY,nX,nY,nX2,nY2) or 
			pointinbox(nSX2,nSY2,nX,nY,nX2,nY2) or
			IntersectionLikePlusOperator(nX,nY,nX2,nY2,nSX,nSY,nSX2,nSY2 ) { 
			return True
		}
		return False 

	func pointinbox nX,nY,nSX,nSY,nSX2,nSY2 
		if nX >= nSX and nX <= nSX2 and nY >= nSY and nY <= nSY2 {
			return True
		}
		return False

	func intersectionlikeplusOperator nX,nY,nX2,nY2,nSX,nSY,nSX2,nSY2 
		if ( nY < nSY and nY2 >  nSY2 and 
			nX > nSX and nX2 <  nSX2 ) or 
		( nSY < nY and nSY2 > nY2 and 
			nSX > nX and nSX2 <  nX2 )  {
			return True
		}
		return False 

	func CancelSelectedObjects
		aObjects = oModel.getselectedObjects()
		if len(aObjects) = 0 { return }
		for item in aObjects {
			oObject = item[2]
			oObject.oCorners.Hide()
		}
		oModel.clearSelectedObjects()

	func ChangeObjectAction
		if oView.oObjectsCombo.count() = 0 { return }
		HideCorners()
		nIndex = oView.oObjectsCombo.currentindex()  
		oModel.nActiveObject = nIndex + 1
		ObjectProperties()
		ShowCorners()

	func ChangeObjectByCode nIndex 
		HideCorners()
		oView.oObjectsCombo.blocksignals(True)
		oView.oObjectsCombo.setcurrentindex(nIndex)  
		oModel.nActiveObject = nIndex + 1
		ObjectProperties()
		oView.oObjectsCombo.blocksignals(False)
		ShowCorners()

	func HideCorners
		CancelSelectedObjects()
		if isattribute(oModel.activeObject(),"oCorners") {
			oModel.activeObject().oCorners.Hide()
		}

	func ShowCorners
		if isattribute(oModel.activeObject(),"oCorners") {
			oModel.activeObject().oCorners.Show()
		}

	func ActiveObjectMousePress nObjectID
		nObjectIndex = oModel.IDToIndex(nObjectID)
		if oView.oToolBtn1.ischecked() {	# Select Mode
			if oModel.IsManySelected() and oModel.IsObjectSelected(nObjectID) { 
				oModel.GetObjectByIndex(nObjectIndex).MousePressMany(self) 
				return 
			}
			ChangeObjectByCode(nObjectIndex-1)  
			if classname(oModel.ActiveObject()) != "formdesigner_qwidget" {
				oModel.ActiveObject().MousePress(self)
			}
		}

	func ActiveObjectMouseRelease nObjectID
		nObjectIndex = oModel.IDToIndex(nObjectID)
		if oView.oToolBtn1.ischecked() {	# Select Mode
			if oModel.IsManySelected() { 
				oModel.GetObjectByIndex(nObjectIndex).MouseReleaseMany(self) 
				return 
			}
			if classname(oModel.ActiveObject()) != "formdesigner_qwidget" {
				oModel.ActiveObject().MouseRelease(self)
			}
		}

	func ActiveObjectMouseMove nObjectID
		nObjectIndex = oModel.IDToIndex(nObjectID)
		if oView.oToolBtn1.ischecked() {	# Select Mode
			if oModel.IsManySelected() { 
				oModel.GetObjectByIndex(nObjectIndex).MouseMoveMany(self) 
				return 
			}
			if classname(oModel.ActiveObject()) != "formdesigner_qwidget" {
				oModel.ActiveObject().MouseMove(self)
			}
		}

	func ChangeToolBoxAction
		if oView.oToolBtn1.ischecked() {	# Select Mode 
			oModel.FormObject().setCursor(new qCursor() { setShape(Qt_ArrowCursor) } )
		else
			oModel.FormObject().setCursor(new qCursor() { setShape(Qt_CrossCursor) } )
		}

	func KeyPressAction
		if oModel.IsManySelected() { KeyPressManyAction() return }
		if oModel.IsFormActive() { return }
		nKey = oView.oFilter.getkeycode()
		nModifier = oView.oFilter.getmodifiers()
		switch nModifier  {
			case 	0 # No CTRL Key is pressed
				switch nkey {
					case Qt_Key_Right
						oModel.ActiveObject().move( oModel.ActiveObject().x() + 10 , oModel.ActiveObject().y() )
					case Qt_Key_Left
						oModel.ActiveObject().move( oModel.ActiveObject().x() - 10 , oModel.ActiveObject().y() )
					case Qt_Key_Up
						oModel.ActiveObject().move( oModel.ActiveObject().x()  , oModel.ActiveObject().y()  - 10)
					case Qt_Key_Down
						oModel.ActiveObject().move( oModel.ActiveObject().x()  , oModel.ActiveObject().y()  + 10)
					case Qt_Key_Delete
						HideCorners()
						oModel.ActiveObject().close() 
						oModel.deleteactiveObject()
						ShowCorners()
						AddObjectsToCombo()
				}	
			case 33554432	# Shift	
				switch nkey {
					case Qt_Key_Right
						oModel.ActiveObject().resize( oModel.ActiveObject().width() + 10 , oModel.ActiveObject().height() )
					case Qt_Key_Left
						oModel.ActiveObject().resize( oModel.ActiveObject().width() - 10 , oModel.ActiveObject().height() )
					case Qt_Key_Up
						oModel.ActiveObject().resize( oModel.ActiveObject().width()  , oModel.ActiveObject().height() - 10)
					case Qt_Key_Down
						oModel.ActiveObject().resize( oModel.ActiveObject().width()  , oModel.ActiveObject().height() + 10)
				}	
		}
		if ismethod(oModel.ActiveObject(),"refreshcorners") {
			oModel.ActiveObject().refreshCorners(oModel.ActiveObject())
		}

	func KeyPressManyAction
		nKey = oView.oFilter.getkeycode()
		nModifier = oView.oFilter.getmodifiers()
		aObjects = oModel.getselectedObjects()
		switch nModifier  {
			case 	0 # No CTRL Key is pressed
				switch nkey {
					case Qt_Key_Right
						for item in aObjects {
							oObject = item[2]
							oObject.move( oObject.x() + 10 , oObject.y() )
							oObject.oCorners.refresh(oObject)
						}
					case Qt_Key_Left
						for item in aObjects {
							oObject = item[2]
							oObject.move( oObject.x() - 10 , oObject.y() )
							oObject.oCorners.refresh(oObject)
						}
					case Qt_Key_Up
						for item in aObjects {
							oObject = item[2]
							oObject.move( oObject.x()  , oObject.y()  - 10)
							oObject.oCorners.refresh(oObject)
						}
					case Qt_Key_Down
						for item in aObjects {
							oObject = item[2]
							oObject.move( oObject.x()  , oObject.y()  + 10)
							oObject.oCorners.refresh(oObject)
						}
					case Qt_Key_Delete
						for item in aObjects {
							oObject = item[2]
							oObject.oCorners.Hide() 
							oObject.Close() 
						}
						oModel.deleteselectedObjects()
						AddObjectsToCombo()						
				}	
			case 33554432	# Shift	
				switch nkey {
					case Qt_Key_Right
						for item in aObjects {
							oObject = item[2]
							oObject.resize( oObject.width() + 10 , oObject.height() )
							oObject.oCorners.refresh(oObject)
						}
					case Qt_Key_Left
						for item in aObjects {
							oObject = item[2]
							oObject.resize( oObject.width() - 10 , oObject.height() )
							oObject.oCorners.refresh(oObject)
						}
					case Qt_Key_Up
						for item in aObjects {
							oObject = item[2]
							oObject.resize( oObject.width()  , oObject.height() - 10)
							oObject.oCorners.refresh(oObject)
						}
					case Qt_Key_Down
						for item in aObjects {
							oObject = item[2]
							oObject.resize( oObject.width()  , oObject.height() + 10)
							oObject.oCorners.refresh(oObject)
						}
				}	
		}


	func MSAlignLeft
		aObjects = oModel.GetSelectedObjects()
		nX = 5000
		for item in aObjects {
			oObject = item[2]
			nX = min( nX , oObject.x() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.move( nX , oObject.y() )
			oObject.oCorners.Refresh(oObject)
		}

	func MSAlignRight
		aObjects = oModel.GetSelectedObjects()
		nRight = 0
		for item in aObjects {
			oObject = item[2]
			nRight = max( nRight , oObject.x() + oObject.width() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.move( nRight  - oObject.width() , oObject.y() )
			oObject.oCorners.Refresh(oObject)
		}

	func MSAlignTop
		aObjects = oModel.GetSelectedObjects()
		nY = 5000
		for item in aObjects {
			oObject = item[2]
			nY = min( nY , oObject.y() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.move( oObject.x() , nY )
			oObject.oCorners.Refresh(oObject)
		}

	func MSAlignBottom
		aObjects = oModel.GetSelectedObjects()
		nBottom = 0
		for item in aObjects {
			oObject = item[2]
			nBottom = max( nBottom , oObject.y() + oObject.height() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.move( oObject.x() , nbottom  - oObject.height() )
			oObject.oCorners.Refresh(oObject)
		}

	func MSCenterVer
		aObjects = oModel.GetSelectedObjects()
		for item in aObjects {
			oObject = item[2]
			nTop = (oObject.ParentWidget().Height() - oObject.height() ) / 2
			oObject.move(oObject.x() , nTop)
			oObject.oCorners.Refresh(oObject)
		}

	func MSCenterHor
		aObjects = oModel.GetSelectedObjects()
		for item in aObjects {
			oObject = item[2]
			nLeft = (oObject.ParentWidget().Width() - oObject.Width() ) / 2
			oObject.move(nLeft,oObject.y())
			oObject.oCorners.Refresh(oObject)
		}

	func MSSizeToTallest
		aObjects = oModel.GetSelectedObjects()
		nHeight = 0
		for item in aObjects {
			oObject = item[2]
			nHeight = max( nHeight , oObject.height() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.resize( oObject.width() , nHeight )
			oObject.oCorners.Refresh(oObject)
		}

	func MSSizeToShortest
		aObjects = oModel.GetSelectedObjects()
		nHeight = 5000
		for item in aObjects {
			oObject = item[2]
			nHeight = min( nHeight , oObject.height() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.resize( oObject.width() , nHeight )
			oObject.oCorners.Refresh(oObject)
		}

	func MSSizeToWidest
		aObjects = oModel.GetSelectedObjects()
		nWidth = 0
		for item in aObjects {
			oObject = item[2]
			nWidth = max( nWidth , oObject.width() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.resize( nWidth, oObject.Height() )
			oObject.oCorners.Refresh(oObject)
		}

	func MSSizeToNarrowest
		aObjects = oModel.GetSelectedObjects()
		nWidth = 5000
		for item in aObjects {
			oObject = item[2]
			nWidth = min( nWidth , oObject.width() )
		}
		for item in aObjects {
			oObject = item[2]
			oObject.resize( nWidth, oObject.Height() )
			oObject.oCorners.Refresh(oObject)
		}

	func MSHorSpacingMakeEqual
		aObjects = oModel.GetSelectedObjects()		
		nLastLeft = 0 
		for x = 1 to len(aObjects) {
			item = aObjects[x]
			oObject = item[2]
			if x = 1 {
				nLastLeft = oObject.x() + oObject.Width() + 10
				loop 
			}
			oObject.move( nLastLeft  , oObject.y() )
			nLastLeft = oObject.x() + oObject.Width() + 10
			oObject.oCorners.Refresh(oObject)
		}

	func MSHorSpacingIncrease
		aObjects = oModel.GetSelectedObjects()		 
		for x = 2 to len(aObjects) {
			item = aObjects[x]
			oObject = item[2]
			oObject.move( oObject.x() + (10*(x-1)) , oObject.y() )
			oObject.oCorners.Refresh(oObject)
		}

	func MSHorSpacingDecrease
		aObjects = oModel.GetSelectedObjects()		 
		for x = 2 to len(aObjects) {
			item = aObjects[x]
			oObject = item[2]
			oObject.move( oObject.x() - (10*(x-1)) , oObject.y() )
			oObject.oCorners.Refresh(oObject)
		}

	func MSVerSpacingMakeEqual
		aObjects = oModel.GetSelectedObjects()		
		nLastTop = 0 
		for x = 1 to len(aObjects) {
			item = aObjects[x]
			oObject = item[2]
			if x = 1 {
				nLastTop = oObject.y() + oObject.Height() + 10
				loop 
			}
			oObject.move( oObject.x() , nLastTop )
			nLastTop = oObject.y() + oObject.Height() + 10
			oObject.oCorners.Refresh(oObject)
		}

	func MSVerSpacingIncrease
		aObjects = oModel.GetSelectedObjects()		 
		for x = 2 to len(aObjects) {
			item = aObjects[x]
			oObject = item[2]
			oObject.move(oObject.x() , oObject.y() + (10*(x-1))  )
			oObject.oCorners.Refresh(oObject)
		}

	func MSVerSpacingDecrease
		aObjects = oModel.GetSelectedObjects()		 
		for x = 2 to len(aObjects) {
			item = aObjects[x]
			oObject = item[2]
			oObject.move(oObject.x() , oObject.y() - (10*(x-1))  )
			oObject.oCorners.Refresh(oObject)
		}

	func MSTextColor
		cColor = oGeneral.SelectColor()
		aObjects = oModel.GetSelectedObjects()		 
		for item in aObjects {
			oObject = item[2]
			oModel.GetObjectByID(item[3]).setTextColor(cColor)
		}
	
	func MSBackColor
		cColor = oGeneral.SelectColor()
		aObjects = oModel.GetSelectedObjects()		 
		for item in aObjects {
			oObject = item[2]
			oModel.GetObjectByID(item[3]).setBackColor(cColor)
		}

	func MSFont
		cFont = oGeneral.SelectFont()
		aObjects = oModel.GetSelectedObjects()		 
		for item in aObjects {
			oObject = item[2]
			oModel.GetObjectByID(item[3]).setFontProperty(cFont)
		}

	func NewAction
		oFile.NewAction(self)

	func OpenAction
		oFile.OpenAction(self)

	func SaveAction
		oFile.SaveAction(self)

	func SaveAsAction
		oFile.SaveAsAction(self)

	func ExitAction
		Super.CloseAction()

Class FormDesignerView from WindowsViewParent

	oForm oSub oFilter oArea win  

	oPropertiesDock oProperties oProperties2 
	oObjectsCombo 	oPropertiesTable oLabelSelect

	oToolBtn1 oToolBtn2 oToolBtn3 oToolBtn4 oToolBtn5 
	oToolBtn6 oToolBtn7 oToolBtn8 oToolBtn9 oToolBtn10 
	oToolBtn11 oToolBtn12 oToolBtn13 oToolBtn14 
	oToolBtn15  oToolBtn16

	func CreateMainWindow oModel

		# Create the form 
			oModel.AddObject("Window",
				 new FormDesigner_qWidget() {
					setWindowTitle("Form1")
				}
			)

		# Create the Select/Draw Label
			oLabelSelect = new qlabel(oModel.FormObject()) {
				setGeometry(100,100,400,400)
		 		setstylesheet("background-color:rgba(50,150,255,0.3);border: 1px solid black")				 
				setautoFillBackground(false)
				settext("")
				setmousetracking(false)
				hide()
			}


		# Add the form to the Sub Window 
			oSub =  new QMdiSubWindow(null) {
				move(100,100)
				resize(400,400)
				setwidget(oModel.FormObject())
				oModel.ActiveObject().setSubWindow(this.oSub)
				setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint ) 
			}

		# Add the sub Window to the Mdi Area
			oArea = new qMdiArea(null) {
				addSubWindow(this.oSub,0)
				setHorizontalScrollBarPolicy(Qt_ScrollBarAlwaysOn)
				setVerticalScrollbarpolicy(Qt_ScrollBarAlwaysOn)
			}

		# Create the Main Window and use the Mdi Area
			win = new qMainwindow() {
				setWindowTitle("Form Designer")		
				setcentralWidget(this.oArea)
			}	
			setwinicon(win,cCurrentDir + "/image/project.png")

		# Create the ToolBox
			CreateToolBox()

		# Create Properties Window
			CreateProperties()

		# Create the Menubar
			CreateMenuBar()

		# Create the Toolbar 
			CreateToolBar()

		# Create the Statusbar 
			CreateStatusBar()

		# Show the Window 
			win.showmaximized()

	func WindowMoveResizeEvents
		oFilter = new qAllEvents(oSub)
                oFilter.setResizeEvent(Method(:ResizeWindowAction))
       	        oFilter.setMoveEvent(Method(:MoveWindowAction))
		oFilter.setMouseButtonPressEvent(Method(:MousePressAction))
		oFilter.setMouseButtonReleaseEvent(Method(:MouseReleaseAction))
		oFilter.setMouseMoveEvent(Method(:MouseMoveAction))
		oFilter.setKeyPressevent(Method(:KeyPressAction))
                oSub.installeventfilter(oFilter)

	func CreateMenuBar
		menu1 = new qmenubar(win) {		
			subFile = addmenu("File")
			subFile { 
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+n"))
					setbtnimage(self,"image/new.png")
					settext("New")
					setclickevent(Method(:NewAction))
				}
				addaction(oAction)
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+o"))
					setbtnimage(self,"image/open.png") 
					settext("Open")
					setclickevent(Method(:OpenAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+s"))
					setbtnimage(self,"image/save.png")
					settext("Save")
					setclickevent(Method(:SaveAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+e"))
					setbtnimage(self,"image/saveas.png")
					settext("Save As")
					setclickevent(Method(:SaveAsAction))
				}
				addaction(oAction)
				addseparator()
				oAction = new qaction(this.win) {
					setShortcut(new QKeySequence("Ctrl+q"))
					setbtnimage(self,"image/close.png") 
					settext("Exit")
					setstatustip("Exit")
					setclickevent(Method(:ExitAction))
				}
				addaction(oAction)
			}
		}
		win.setmenubar(menu1)

	func CreateStatusBar
		status1 = new qstatusbar(win) {
			showmessage("Ready!",0)
		}
		win.setstatusbar(status1)

	func CreateToolBar
		aBtns = [
				new qpushbutton(win) { 
					setbtnimage(self,"image/new.png") 
					setclickevent(Method(:NewAction))
					settooltip("New File")
				} ,
				new qpushbutton(win) { 
					setbtnimage(self,"image/open.png") 
					setclickevent(Method(:OpenAction))
					settooltip("Open File")
				} ,
				new qpushbutton(win) { 
					setbtnimage(self,"image/save.png")
					setclickevent(Method(:SaveAction))
					settooltip("Save")
				 } ,
				new qpushbutton(win) { 
					setbtnimage(self,"image/saveas.png")
					setclickevent(Method(:SaveAsAction))
					settooltip("Save As")
				 } ,				
				new qpushbutton(win) { 
					setbtnimage(self,"image/close.png") 
					setclickevent(Method(:ExitAction))
					settooltip("Exit")
				} 
			]

		tool1 = win.addtoolbar("files")  {
	  		for x in aBtns addwidget(x) addseparator() next
		}

	func CreateToolBox
		oToolBox = new qWidget() {
 			this.oToolbtn1 = new qPushButton(oToolBox) {
					setText(this.TextSize("Select",20))
					setbtnimage(self,"image/select.png") 
					setminimumwidth(150)
					setCheckable(True)
					setChecked(True)
			}
 			this.oToolbtn2 = new qPushButton(oToolBox) {
					setText(this.TextSize("Label",20))
					setbtnimage(self,"image/label.png") 
					setCheckable(True)
			}
 			this.oToolbtn3 = new qPushButton(oToolBox) {
					setText(this.TextSize("Button",18))
					setbtnimage(self,"image/pushbutton.png") 
					setCheckable(True)
			}
 			this.oToolbtn4 = new qPushButton(oToolBox) {
					setText(this.TextSize("LineEdit",19))
					setbtnimage(self,"image/textfield.png") 
					setCheckable(True)
			}
 			this.oToolbtn5 = new qPushButton(oToolBox) {
					setText(this.TextSize("TextEdit",19))
					setbtnimage(self,"image/textarea.png") 
					setCheckable(True)
			}
 			this.oToolbtn6 = new qPushButton(oToolBox) {
					setText(this.TextSize("ListWidget",17))
					setbtnimage(self,"image/listview.png") 
					setCheckable(True)
			}
 			this.oToolbtn7 = new qPushButton(oToolBox) {
					setText(this.TextSize("Checkbox",16))
					setbtnimage(self,"image/checkbox.png") 
					setCheckable(True)
			}
 			this.oToolbtn8 = new qPushButton(oToolBox) {
					setText(this.TextSize("Image",19))
					setbtnimage(self,"image/image.png") 
					setCheckable(True)
			}
 			this.oToolbtn9 = new qPushButton(oToolBox) {
					setText(this.TextSize("Slider",20))
					setbtnimage(self,"image/slider.png") 
					setCheckable(True)
			}
 			this.oToolbtn10 = new qPushButton(oToolBox) {
					setText(this.TextSize("Progressbar",15))
					setbtnimage(self,"image/progressbar.png") 
					setCheckable(True)
			}
 			this.oToolbtn11 = new qPushButton(oToolBox) {
					setText(this.TextSize("SpinBox",17))
					setbtnimage(self,"image/spinner.bmp") 
					setCheckable(True)
			}
 			this.oToolbtn12 = new qPushButton(oToolBox) {
					setText(this.TextSize("ComboBox",17))
					setbtnimage(self,"image/combobox.bmp") 
					setCheckable(True)
			}
 			this.oToolbtn13 = new qPushButton(oToolBox) {
					setText(this.TextSize("DateTimeEdit",17))
					setbtnimage(self,"image/datepicker.bmp") 
					setCheckable(True)
			}
 			this.oToolbtn14 = new qPushButton(oToolBox) {
					setText(this.TextSize("TableWidget",17))
					setbtnimage(self,"image/grid.bmp") 
					setCheckable(True)
			}
 			this.oToolbtn15 = new qPushButton(oToolBox) {
					setText(this.TextSize("TreeWidget",17))
					setbtnimage(self,"image/tree.bmp") 
					setCheckable(True)
			}
 			this.oToolbtn16 = new qPushButton(oToolBox) {
					setText(this.TextSize("RadioButton",17))
					setbtnimage(self,"image/radiobutton.png") 
					setCheckable(True)
			}

			Layout1 = new qVBoxLayout() {
				AddWidget(this.oToolbtn1)
				AddWidget(this.oToolbtn2)
				AddWidget(this.oToolbtn3)
				AddWidget(this.oToolbtn4)
				AddWidget(this.oToolbtn5)
				AddWidget(this.oToolbtn6)
				AddWidget(this.oToolbtn7)
				AddWidget(this.oToolbtn8)
				AddWidget(this.oToolbtn9)
				AddWidget(this.oToolbtn10)
				AddWidget(this.oToolbtn11)
				AddWidget(this.oToolbtn12)
				AddWidget(this.oToolbtn13)
				AddWidget(this.oToolbtn14)
				AddWidget(this.oToolbtn15)
				AddWidget(this.oToolbtn16)
				insertStretch( -1, 1 )
			}
			btnsGroup = new qButtonGroup(oToolBox) {
				setbuttonClickedEvent(Method(:ChangeToolBoxAction))
				AddButton(this.oToolbtn1,0)
				AddButton(this.oToolbtn2,1)
				AddButton(this.oToolbtn3,2)
				AddButton(this.oToolbtn4,3)
				AddButton(this.oToolbtn5,4)
				AddButton(this.oToolbtn6,5)
				AddButton(this.oToolbtn7,6)
				AddButton(this.oToolbtn8,7)
				AddButton(this.oToolbtn9,8)
				AddButton(this.oToolbtn10,9)
				AddButton(this.oToolbtn11,10)
				AddButton(this.oToolbtn12,11)
				AddButton(this.oToolbtn13,12)
				AddButton(this.oToolbtn14,13)
				AddButton(this.oToolbtn15,14)
				AddButton(this.oToolbtn16,15)
			}
			setLayout(Layout1)
		}
		oScroll = new qScrollArea(null) {
			setWidget(oToolBox)
		}
		oToolBoxDock = new qdockwidget(NULL,0) {
			setWindowTitle("ToolBox")			
			setWidget(oScroll)
		}
		win.Adddockwidget(1,oToolBoxDock,1)

	func TextSize cText,nSize
		nSpaces = (nSize - len(cText))/2
		return copy(" ",nSpaces)+cText+Copy(" ",nSpaces)

	func CreateProperties
		oProperties = new qWidget() {
			oLabelObject = new qLabel(this.oProperties) {
				setText("Object")
				setMaximumWidth(50)
			}
			this.oObjectsCombo = new qCombobox(this.oProperties) {
				setcurrentIndexChangedEvent(Method(:ChangeObjectAction))
			}
			oLayout1 = new qHBoxlayout() {
				AddWidget(oLabelObject)
				AddWidget(this.oObjectsCombo)
			}
			this.oPropertiesTable = new qTableWidget(this.oProperties) {				
				setrowcount(0)
				setcolumncount(3)
				setselectionbehavior(QAbstractItemView_SelectRows)
				setHorizontalHeaderItem(0, new QTableWidgetItem("Property"))
				setHorizontalHeaderItem(1, new QTableWidgetItem("Value"))
				setHorizontalHeaderItem(2,  new QTableWidgetItem(""))
				setColumnwidth(2,40)
				setAlternatingRowColors(true)
				horizontalHeader().setStyleSheet("color: blue")
				verticalHeader().setStyleSheet("color: red")
				setitemChangedEvent(Method(:UpdateProperties))
			}
			oLayout2 = new qVBoxLayout() {
				AddLayout(oLayout1)
				AddWidget(this.oPropertiesTable)
			}
			setLayout(oLayout2)
		}
		oProperties2 = new qWidget() {
			oLabel = new qLabel(this.oProperties2) {
				setText("Multiple Selection")
				setalignment(Qt_AlignHCenter |  Qt_AlignVCenter )
				setStylesheet("color:White;background-color:purple;")
			}
			oBtn1 = new qPushbutton(this.oProperties2) {
				setText("Align - Left Sides")
				setClickEvent(Method(:MSAlignLeft))
			}
			oBtn2 = new qPushbutton(this.oProperties2) {
				setText("Align - Right Sides")
				setClickEvent(Method(:MSAlignRight))
			}
			oBtn3 = new qPushbutton(this.oProperties2) {
				setText("Align - Top Sides")
				setClickEvent(Method(:MSAlignTop))
			}
			oBtn4 = new qPushbutton(this.oProperties2) {
				setText("Align - Bottom Sides")
				setClickEvent(Method(:MSAlignBottom))
			}
			oBtn5 = new qPushbutton(this.oProperties2) {
				setText("Center Vertically")
				setClickEvent(Method(:MSCenterVer))
			}
			oBtn6 = new qPushbutton(this.oProperties2) {
				setText("Center Horizontally")
				setClickEvent(Method(:MSCenterHor))
			}
			oBtn7 = new qPushbutton(this.oProperties2) {
				setText("Size - To Tallest")
				setClickEvent(Method(:MSSizeToTallest))
			}
			oBtn8 = new qPushbutton(this.oProperties2) {
				setText("Size - To Shortest")
				setClickEvent(Method(:MSSizeToShortest))
			}
			oBtn9 = new qPushbutton(this.oProperties2) {
				setText("Size - To Widest")
				setClickEvent(Method(:MSSizeToWidest))
			}
			oBtn10 = new qPushbutton(this.oProperties2) {
				setText("Size - To Narrowest")
				setClickEvent(Method(:MSSizeToNarrowest))
			}
			oBtn11 = new qPushbutton(this.oProperties2) {
				setText("Horizontal Spacing - Make Equal")
				setClickEvent(Method(:MSHorSpacingMakeEqual))
			}
			oBtn12 = new qPushbutton(this.oProperties2) {
				setText("Horizontal Spacing - Increase")
				setClickEvent(Method(:MSHorSpacingIncrease))
			}
			oBtn13 = new qPushbutton(this.oProperties2) {
				setText("Horizontal Spacing - Decrease")
				setClickEvent(Method(:MSHorSpacingDecrease))
			}
			oBtn14 = new qPushbutton(this.oProperties2) {
				setText("Vertical Spacing - Make Equal")
				setClickEvent(Method(:MSVerSpacingMakeEqual))
			}
			oBtn15 = new qPushbutton(this.oProperties2) {
				setText("Vertical Spacing - Increase")
				setClickEvent(Method(:MSVerSpacingIncrease))
			}
			oBtn16 = new qPushbutton(this.oProperties2) {
				setText("Vertical Spacing - Decrease")
				setClickEvent(Method(:MSVerSpacingDecrease))
			}
			oBtn17 = new qPushbutton(this.oProperties2) {
				setText("Text Color")
				setClickEvent(Method(:MSTextColor))
			}
			oBtn18 = new qPushbutton(this.oProperties2) {
				setText("Back Color")
				setClickEvent(Method(:MSBackColor))
			}
			oBtn19 = new qPushbutton(this.oProperties2) {
				setText("Font")
				setClickEvent(Method(:MSFont))
			}
			oLayout = new qVBoxLayout() {
				AddWidget(oLabel)
				AddWidget(oBtn1)
				AddWidget(oBtn2)
				AddWidget(oBtn3)
				AddWidget(oBtn4)
				AddWidget(oBtn5)
				AddWidget(oBtn6)
				AddWidget(oBtn7)
				AddWidget(oBtn8)
				AddWidget(oBtn9)
				AddWidget(oBtn10)
				AddWidget(oBtn11)
				AddWidget(oBtn12)
				AddWidget(oBtn13)
				AddWidget(oBtn14)
				AddWidget(oBtn15)
				AddWidget(oBtn16)
				AddWidget(oBtn17)
				AddWidget(oBtn18)
				AddWidget(oBtn19)
				insertStretch( -1, 1 )
			}
			setLayout(oLayout)		
		}
		oPropertiesDock = new qDockWidget(NULL,0) {
			setWindowTitle("Properties")
			setWidget(this.oProperties)
		}
		win.Adddockwidget(2,oPropertiesDock,2)

	func AddProperty cItem,lButton
		oPropertiesTable.blocksignals(True)
		nRow = oPropertiesTable.rowcount()
		oPropertiesTable.insertrow(nRow)
		# Property Name
			item = new qTableWidgetItem(cItem)
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,0,item)
		# Property Value
			item = new qTableWidgetItem("")
			oPropertiesTable.setItem(nRow,1,item)
		if lButton = False {
			item = new qTableWidgetItem("")
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,2,item)
		else
			oBtn = new qPushButton(NULL) { 
				setText("::") 
				setfixedwidth(30)
				setClickEvent(Method(:DialogButtonAction+"("+nRow+")"))
			}
			oPropertiesTable.setCellwidget(nRow,2,oBtn)
		}
		oPropertiesTable.blocksignals(false)

	func AddPropertyCombobox cItem,aList
		oPropertiesTable.blocksignals(True)
		nRow = oPropertiesTable.rowcount()
		oPropertiesTable.insertrow(nRow)
		# Property Name
			item = new qTableWidgetItem(cItem)
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,0,item)
		# Combobox
			oCombo = new qCombobox(NULL) {
				for cValue in aList { AddItem(cValue,0) }
				setCurrentIndexchangedevent(Method(:ComboItemAction+"("+nRow+")"))
			}
			oPropertiesTable.setCellwidget(nRow,1,oCombo)
		# No Button
			item = new qTableWidgetItem("")
			item.setFlags(False)	# Can't Edit the Item
			oPropertiesTable.setItem(nRow,2,item)
		oPropertiesTable.blocksignals(false)

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

	func GetObjectByIndex nIndex 
		return aObjectsList[nIndex][2]

	func GetObjectByID nID
		return GetObjectByIndex(IDToIndex(nID))

	func FormObject
		return aObjectsList[1][2]
 
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
		aManySelectedObjects + aObjectsList[nIndex]

	func GetSelectedObjects
		return aManySelectedObjects

	func IsManySelected
		return len(aManySelectedObjects) 	# 0=False  & other values = True

	func DeleteSelectedObjects
		for item in aManySelectedObjects {
			nPos = find(aObjectsList,item[3],3)
			del(aObjectsList,nPos)
		}
		ClearSelectedObjects()

	func IsObjectSelected nObjectID
		if find(aManySelectedObjects,nObjectID,3) {
			return True
		}
		return False

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
		# Delete Objects but Keep the Form Object
		while  len(aObjectsList) > 1 {
			del(aObjectsList,2)
		}
		

Class FormDesignerGeneral

	func oCursorA
		oCursor =  new qCursor() 
		oCursor.setShape(Qt_ArrowCursor) 
		return oCursor 

	func oCursorF 	
		oCursor =  new qCursor() 
		oCursor.setShape(Qt_SizeFDiagCursor) 
		return oCursor 

	func oCursorB 
		oCursor =  new qCursor() 
		oCursor.setShape(Qt_SizeBDiagCursor) 
		return oCursor 

	func oCursorH 
		oCursor =  new qCursor()
		oCursor.setShape(Qt_SizeHorCursor) 
		return oCursor 

	func oCursorV 
		oCursor =  new qCursor()  
		oCursor.setShape(Qt_SizeVerCursor) 
		return oCursor 

	func SelectColor
		oColor = new qColorDialog()
		aColor = oColor.GetColor()
		r=hex(acolor[1]) g=hex(acolor[2]) b=hex(acolor[3])
		if len(r) < 2 { r = "0" + r }
		if len(g) < 2 { g = "0" + g }
		if len(b) < 2 { b = "0" + b }			
		cColor = "#" + r + g + b
		return cColor

	func SelectFont
		cFont = ""
		oFontDialog = new qfontdialog() {
			aFont = getfont()
		}
		if aFont[1] != NULL {
			cFont = aFont[1]
		}
		return cFont

class FormDesigner_QWidget from QWidget 

	cBackColor = ""

	oSubWindow

	nX=0 nY=0		# for Select/Draw

	func BackColor
		return cBackColor

	func setBackColor cValue 
		cBackColor=cValue	
		updatestylesheets()

	func updatestylesheets
		setstylesheet("background-color:"+cBackColor+";")

	func setSubWindow oObject 
		oSubWindow = oObject

	func AddObjectProperties  oDesigner
		oDesigner.oView.AddProperty("X",False)
		oDesigner.oView.AddProperty("Y",False)
		oDesigner.oView.AddProperty("Width",False)
		oDesigner.oView.AddProperty("Height",False)
		oDesigner.oView.AddProperty("Title",False)
		oDesigner.oView.AddProperty("Back Color",True)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		if nCol = 1 {
			switch nRow {
				case 0 	# x
					oSubWindow.move(0+cValue,oSubWindow.y())
				case 1 	# y
					oSubWindow.move(oSubWindow.x(),0+cValue)
				case 2	# width
					oSubWindow.resize(0+cValue,oSubWindow.height())
				case 3 	# height
					oSubWindow.resize(oSubWindow.width(),0+cValue)
				case 4  	# Title 			
					setWindowTitle(cValue)
				case 5	# back color
					setBackColor(cValue)
			}
		}

	func DisplayProperties oDesigner
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the X
			oPropertiesTable.item(0,1).settext(""+oSubWindow.x())
		# Set the Y
			oPropertiesTable.item(1,1).settext(""+oSubWindow.y())
		# Set the Width
			oPropertiesTable.item(2,1).settext(""+oSubWindow.width())
		# Set the Height
			oPropertiesTable.item(3,1).settext(""+oSubWindow.height())
		# Set the Title
			oPropertiesTable.item(4,1).settext(windowtitle())
		# Set the BackColor
			oPropertiesTable.item(5,1).settext(backcolor())
		oPropertiesTable.Blocksignals(False)

	func DialogButtonAction oDesigner,nRow 
		if nRow = 5 {	# Back Color
			cColor = oDesigner.oGeneral.SelectColor()
			setBackColor(cColor)
			DisplayProperties(oDesigner)
		}

	func MousePressAction oDesigner
		nX = oDesigner.oView.oFilter.getglobalx()  
		ny = oDesigner.oView.oFilter.getglobaly()  
		oDesigner.oView.oLabelSelect.raise()
		oDesigner.oView.oLabelSelect.resize(1,1)
		oDesigner.oView.oLabelSelect.show()

	func MouseReleaseAction oDesigner
	        oDesigner.oView.oLabelSelect.hide()
		aRect = GetRectDim(oDesigner)
		oDesigner.SelectDrawAction(aRect)

	func MouseMoveAction oDesigner 
		aRect = GetRectDim(oDesigner)
		oDesigner.oView.oLabelSelect {
			move(aRect[1],aRect[2]) 
			resize(aRect[3],aRect[4])
		}

	func GetRectDim oDesigner
		C_TOPMARGIN = 25 
		nX2 = oDesigner.oView.oFilter.getglobalx()
		ny2 = oDesigner.oView.oFilter.getglobaly()
		top = min(nY2,nY) - oDesigner.oView.oArea.y() - oSubWindow.y() - y() - C_TOPMARGIN - oDesigner.oView.win.y()
		left = min(nX2,nX) - oDesigner.oView.oArea.x()  - oSubWindow.x() - x() - oDesigner.oView.win.x()
		width = max(nX,nX2) - min(nX,nX2)  
		height = max(nY,nY2) - min(nY,nY2)  
		return [left,top,width,height]

	func ObjectDataAsString nTabsCount
		cTabs = copy(char(9),nTabsCount) 
		cOutput = cTabs + " :x = #{f1} , : y = #{f2}  , " + nl
		cOutput += cTabs + " :width =  #{f3} , :height = #{f4} , " + nl
		cOutput += cTabs + ' :title =  "#{f5}" , ' + nl
		cOutput += cTabs + ' :backcolor =  "#{f6}" '
		cOutput = substr(cOutput,"#{f1}",""+parentwidget().x())
		cOutput = substr(cOutput,"#{f2}",""+parentwidget().y())
		cOutput = substr(cOutput,"#{f3}",""+parentwidget().width())
		cOutput = substr(cOutput,"#{f4}",""+parentwidget().height())
		cOutput = substr(cOutput,"#{f5}",windowtitle())
		cOutput = substr(cOutput,"#{f6}",backcolor())
		return cOutput 

Class MoveResizeCorners 

	func CreateMoveResizeCornersAttributes
		# Movement Event 
			AddAttribute(self,:nX)
			AddAttribute(self,:nY)
			AddAttribute(self,:lPress)
			AddAttribute(self,:oFilter)
			AddAttribute(self,:lMoveEvent)
		# Resize Event
			AddAttribute(self,:lResize)
			AddAttribute(self,:nResizeMode)
		# Corners
			AddAttribute(self,:oCorners)
		# Default Values
			lPress=False
			lMoveEvent=False
			lResize=False
			nResizeMode=0

	func CreateCorners
		oCorners = new ObjectCorners(self)

	func RefreshCorners oParent 
		oCorners.refresh(oParent)

	func MousePress oDesigner
	        lPress = True
		lMoveEvent=False
		lResize = False
		nResizeMode = 0
        	nX = oFilter.getglobalx()
	        ny = oFilter.getglobaly()
		setCursor(oDesigner.oGeneral.oCursorA())

	func MouseRelease oDesigner
	        lPress = False
		lMoveEvent=False
		lResize = False
		nResizeMode = 0
		setCursor(oDesigner.oGeneral.oCursorA())

	func MouseMove oDesigner
		if not resizeEvent(oDesigner) { return }
		MoveEvent(oDesigner) 
		
	func ResizeEvent oDesigner
		# Resize Event
			nXPos =  oFilter.getx()	
			nYPos = ofilter.gety() 
			if (nResizeMode = 0 or lPress = False) and lMoveEvent=False  {
				if nXPos < 5 {
					if nYPos < 5 {	# Top + Left
						setCursor(oDesigner.oGeneral.oCursorF() )
						nResizeMode = 1
					elseif nYPos > Height() - 5	# Left + Bottom
						setCursor(oDesigner.oGeneral.oCursorB() )
						nResizeMode = 2
					else 			# Left 
						setCursor(oDesigner.oGeneral.oCursorH() )
						nResizeMode = 3
					}
					lResize = True
				elseif nYPos < 5 		
					if nXPos > Width() - 5 {	# Top+Width
						setCursor(oDesigner.oGeneral.oCursorB() )
						nResizeMode = 4
					else					# Top 
						setCursor(oDesigner.oGeneral.oCursorV() )
						nResizeMode = 5
					}
					if lPress { 	lResize = True } 
				elseif nYPos > Height() - 5		 
					if nXPos > Width() - 5 {	# Bottom+Width
						setCursor(oDesigner.oGeneral.oCursorF() )
						nResizeMode = 6
					else					# Bottom 
						setCursor(oDesigner.oGeneral.oCursorV())
						nResizeMode = 7
					}
					if lPress { 	lResize = True } 
				elseif nXPos > Width() - 5		# Left+Width
					setCursor(oDesigner.oGeneral.oCursorH() )
					nResizeMode = 8
					if lPress { 	lResize = True } 
				else
 					lResizeMode = 0
					lResize = False				
					setCursor(oDesigner.oGeneral.oCursorA())
				}
			}

			if lResize and lPress and lMoveEvent=False {
				switch nResizeMode {
					case 1	# Top+Left
						move(x()+nXPos,y()+nYPos)
						resize(width() + (-1) * nXPos , height() + (-1) * nYPos)
					case 2	# Left + Bottom 
						move(x()+ nXPos,y())
						resize(width() + (-1) *  nXPos , nYPos)
					case 3	# Left
						move(x()+nXPos,y())
						resize(width() + (-1) * nXPos , height() )
					case 4	# Top+Width 
						move(x(), y() + nYPos)
						resize(   nXPos , height() + (-1) *  nYPos )
					case 5	# Top
						move(x(), y() + nYPos)
						resize(width() , height() + (-1) *  nYPos )
					case 6	# Bottom+Width
						move(x(), y())
						resize(nXPos , nYPos )
					case 7	# Bottom
						move(x(), y() )
						resize(width() , nYPos )
					case 8	# Left+Width
						move(x(), y() )
						resize(nXPos , height() )
				}
				oCorners.refresh(oDesigner.oModel.ActiveObject())
				return false
			}
			return True 

	func MoveEvent oDesigner
		# Move Event
		if lPress {
			lMoveEvent=True	
			nX2 = oFilter.getglobalx()
			ny2 = oFilter.getglobaly()
			ndiffx = nX2 - nX
			ndiffy = nY2 - nY
			move(x()+ndiffx,y()+ndiffy)
			nX = nX2
			ny = nY2
			oCorners.refresh(oDesigner.oModel.ActiveObject())
		}

	func MousePressMany oDesigner
		MousePress(oDesigner)

	func MouseMoveMany oDesigner
		if lPress {
			lMoveEvent=True	
			nX2 = oFilter.getglobalx()
			ny2 = oFilter.getglobaly()
			ndiffx = nX2 - nX
			ndiffy = nY2 - nY
			nX = nX2
			ny = nY2
			# Move the objects together 
			aObjects = oDesigner.oModel.getselectedObjects()
			for item in aObjects {
				oObject = item[2]
				oObject.move(oObject.x()+ndiffx,oObject.y()+ndiffy)
				oObject.oCorners.refresh(oObject)
			}
		}

	func MouseReleaseMany oDesigner
		MouseRelease(oDesigner)


class ObjectCorners

	oCorner1 oCorner2 oCorner3 oCorner4

	func init oParent

		oCorner1 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()-5,oParent.y()-5)
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}		

		oCorner2 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()-5,oParent.y()+oParent.height())
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}		

		oCorner3 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()+oParent.Width(),oParent.y()-5)
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}		

		oCorner4 = new qPushButton(oParent.ParentWidget()) {
			move(oParent.x()+oParent.width(),oParent.y()+oParent.height())
			resize(5,5)
			setStyleSheet("background-color:black;")
			setEnabled(False)
			setMouseTracking(False)
			show()
		}		

	func refresh  oParent 

		oCorner1  {
			move(oParent.x()-5,oParent.y()-5)
			resize(5,5)
		}		

		oCorner2  {
			move(oParent.x()-5,oParent.y()+oParent.height())
			resize(5,5)
		}		

		oCorner3  {
			move(oParent.x()+oParent.Width(),oParent.y()-5)
			resize(5,5)
		}		

		oCorner4 {
			move(oParent.x()+oParent.width(),oParent.y()+oParent.height())
			resize(5,5)
		}		

	func show

		oCorner1.show()
		oCorner2.show()
		oCorner3.show()
		oCorner4.show()

	func hide 
	
		oCorner1.hide()
		oCorner2.hide()
		oCorner3.hide()
		oCorner4.hide()

class CommonAttributesMethods

	
	func CreateCommonAttributes	
		AddAttribute(self,:cTextColor)
		AddAttribute(self,:cBackColor)
		AddAttribute(self,:cFontProperty)
		cTextColor = "black"
		cBackColor = ""
		cFontProperty = ""

	func TextColor
		return cTextColor

	func setTextColor cValue 
		cTextColor=cValue	
		updatestylesheets()

	func BackColor
		return cBackColor

	func setBackColor cValue 
		cBackColor=cValue	
		updatestylesheets()

	func FontProperty
		return cFontProperty

	func setFontProperty cValue 
		cFontProperty = cValue 
		oFont = new qfont("",0,0,0)
		oFont.fromstring(cValue)
		setfont(oFont)

	func updatestylesheets
		setstylesheet("color:"+cTextColor+";background-color:"+cBackColor+";")

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)

	func AddObjectCommonProperties  oDesigner
		oDesigner.oView.AddProperty("X",False)
		oDesigner.oView.AddProperty("Y",False)
		oDesigner.oView.AddProperty("Width",False)
		oDesigner.oView.AddProperty("Height",False)
		oDesigner.oView.AddProperty("Text",False)
		oDesigner.oView.AddProperty("Text Color",True)
		oDesigner.oView.AddProperty("Back Color",True)
		oDesigner.oView.AddProperty("Font",True)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		if nCol = 1 {
			switch nRow {
				case 0 	# x
					move(0+cValue,y())
				case 1 	# y
					move(x(),0+cValue)
				case 2	# width
					resize(0+cValue,height())
				case 3 	# height
					resize(width(),0+cValue)
				case 4  	# Text			
					setText(cValue)
				case 5	# Text color
					setTextColor(cValue)
				case 6	# back color
					setBackColor(cValue)
				case 7	# font
					setFontProperty(cValue)

			}
		}

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)

	func DisplayCommonProperties oDesigner
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the X
			oPropertiesTable.item(0,1).settext(""+x())
		# Set the Y
			oPropertiesTable.item(1,1).settext(""+y())
		# Set the Width
			oPropertiesTable.item(2,1).settext(""+width())
		# Set the Height
			oPropertiesTable.item(3,1).settext(""+height())
		# Set the Title
			oPropertiesTable.item(4,1).settext(text())
		# Set the Text Color
			oPropertiesTable.item(5,1).settext(textcolor())
		# Set the BackColor
			oPropertiesTable.item(6,1).settext(backcolor())
		# Set the Font
			oPropertiesTable.item(7,1).settext(fontproperty())

		oPropertiesTable.Blocksignals(False)

	func DialogButtonAction oDesigner,nRow 
		if nRow = 5 {	# Text Color
			cColor = oDesigner.oGeneral.SelectColor()
			setTextColor(cColor)
			DisplayProperties(oDesigner)
		elseif nRow = 6 	# Back Color
			cColor = oDesigner.oGeneral.SelectColor()
			setBackColor(cColor)
			DisplayProperties(oDesigner)
		elseif nRow = 7 	# Font
			cFont = oDesigner.oGeneral.SelectFont()
			setFontProperty(cFont)
			DisplayProperties(oDesigner) 
		}

	func ObjectDataAsString nTabsCount
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput = cTabs + " :x = #{f1} , : y = #{f2}  , " + nl
		cOutput += cTabs + " :width =  #{f3} , :height = #{f4} , " + nl
		cOutput += cTabs + ' :textcolor =  "#{f5}" , ' + nl
		cOutput += cTabs + ' :backcolor =  "#{f6}" , ' + nl
		cOutput += cTabs + ' :font =  "#{f7}" , ' + nl
		cOutput += cTabs + ' :text =  "#{f8}"'
		cOutput = substr(cOutput,"#{f1}",""+x())
		cOutput = substr(cOutput,"#{f2}",""+y())
		cOutput = substr(cOutput,"#{f3}",""+width())
		cOutput = substr(cOutput,"#{f4}",""+height())
		cOutput = substr(cOutput,"#{f5}",textcolor())
		cOutput = substr(cOutput,"#{f6}",backcolor())
		cOutput = substr(cOutput,"#{f7}",fontproperty())
		cOutput = substr(cOutput,"#{f8}",text())
		return cOutput 

class FormDesigner_QLabel from QLabel

	nTextAlign = 0

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func SetTextAlign nIndex
		nTextAlign = nIndex
		Switch nIndex {
			case 0
				setalignment(Qt_AlignLeft |  Qt_AlignVCenter )
			case 1
				setalignment(Qt_AlignHCenter |  Qt_AlignVCenter )			
			case 2
				setalignment(Qt_AlignRight |  Qt_AlignVCenter )
		}

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox("Text Align",["Left","Center","Right"])

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Text Align 
			oWidget = oPropertiesTable.cellwidget(8,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(nTextAlign)
			oCombo.BlockSignals(False)
		oPropertiesTable.Blocksignals(False)

	func ComboItemAction oDesigner,nRow
		if nRow = 8 {		# Text Align 
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(8,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			nIndex = oCombo.CurrentIndex()
			setTextAlign(nIndex)
		}

class FormDesigner_QPushButton from QPushButton 

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

class FormDesigner_QLineEdit from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

# We use QLineEdit as parent - We need just the looking (not functionality)
class FormDesigner_QTextEdit from QLineEdit 

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

# We use QLineEdit as parent - We need just the looking (not functionality)
class FormDesigner_QListWidget from QLineEdit 

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

class FormDesigner_QCheckBox from QCheckBox

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

class FormDesigner_QImage from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

class FormDesigner_QSlider from QSlider

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func text return ""

	func settext cValue 

class FormDesigner_QProgressbar from QProgressbar

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func text return ""

	func settext cValue 

class FormDesigner_QSpinBox from QSpinBox

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func text return ""

	func settext cValue 

class FormDesigner_QComboBox from QComboBox

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func text return ""

	func settext cValue 

class FormDesigner_QDateTimeEdit from QDateTimeedit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func text return ""

	func settext cValue 

class FormDesigner_QTableWidget from QTableWidget 

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func text return ""

	func settext cValue 

class FormDesigner_QTreeWidget from QTreeWidget

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func text return ""

	func settext cValue 

class FormDesigner_QRadioButton from QRadioButton

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()


class FormDesignerFileSystem

	cFileName = "noname.rform"

	func NewAction oDesigner
		# Set the file Name
			new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getsavefilename(oDesigner.oView.win,"New Form",currentdir(),"*.rform")
			}
			if cInputFileName = NULL { return }
			cFileName = cInputFileName

	func OpenAction oDesigner
		# Get the file Name
			new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getopenfilename(oDesigner.oView.win,"Open Form",currentdir(),"*.rform")
			}
			if cInputFileName = NULL { return }
			cFileName = cInputFileName
			LoadFormFromFile(oDesigner)

	func SaveAction oDesigner
		# Check file not saved before 
			if cFileName = "noname.rform" {
				SaveFile(oDesigner)
				return 
			}
		SaveFormToFile(oDesigner)

	func SaveAsAction oDesigner	
		SaveFile(oDesigner)

	func SaveFile oDesigner
		# Set the file Name
			new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getsavefilename(oDesigner.oView.win,"Save Form",currentdir(),"*.rform")
			}
			if cInputFileName = NULL { return }
			cFileName = cInputFileName
			SaveFormToFile(oDesigner)

	func SaveFormToFile oDesigner
		cHeader = "# Start Form Designer File" + nl
		cEnd = nl + "# End Form Designer File"

		# Save the Objects Data 

			# Start of The List
				cContent = "
					aObjectsList = [" + nl

			# Objects 
				for x = 1 to len(oDesigner.oModel.aObjectsList) {
					aObject  = oDesigner.oModel.aObjectsList[x]
					cObjContent = Copy(char(9),6) + 
					'[ :name = "#{f1}" , :id = #{f2} , :classname = "#{f3}" , :data = [' + nl
					cObjContent += aObject[2].ObjectDataAsString(7) + nl
					cObjContent += Copy(char(9),7) +	"]" + nl + Copy(char(9),6) + "]" 
					cObjContent = substr(cObjContent,"#{f1}",aObject[1])
					cObjContent = substr(cObjContent,"#{f2}",""+aObject[3])
					cObjContent = substr(cObjContent,"#{f3}",classname(aObject[2]))
					if x != len(oDesigner.oModel.aObjectsList) {
						cObjContent += ","
					}
					cObjContent += nl
					cContent += cObjContent
				}

			# End of The List 
				cContent += "
					]
				"

		# Write the Form File 
			write(cFileName,cHeader+cContent+cEnd)
			
	func LoadFormFromFile oDesigner
		# Delete objects
			for x = 2 to len(oDesigner.oModel.aObjectsList) {
				item = oDesigner.oModel.aObjectsList[x]
				oObject = item[2]
				oObject.oCorners.Hide() 
				oObject.Close() 
			}
			oDesigner.oModel.DeleteAllObjects()
			oDesigner.AddObjectsToCombo()		
		# Load the Form Data 
			eval(read(cFileName))		
		# Create Objects 
			for item in aObjectsList {
				cClass = item[:classname] 	
				switch cClass {

					case :formdesigner_qwidget
						oDesigner.oView.oSub {
							blocksignals(True)
							move(item[:data][:x],item[:data][:y]) 
							resize(item[:data][:width],item[:data][:height])
							setWindowTitle(item[:data][:title])
							show()
							blocksignals(False)
						}
						oDesigner.oModel.FormObject().setBackColor(item[:data][:backcolor])

					case :FormDesigner_QLabel
						oDesigner.HideCorners()
						oDesigner.oModel.AddLabel(new FormDesigner_QLabel(oDesigner.oModel.FormObject()) 	)
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.LabelsCount())
						RestoreCommonProperties(oDesigner,item)

					case :FormDesigner_QPushButton
						oDesigner.HideCorners()
						oDesigner.oModel.AddPushButton(new FormDesigner_QPushButton(oDesigner.oModel.FormObject()) {
								setMouseTracking(True)
								setFocusPolicy(0)
							}
						)
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.PushButtonsCount())
						RestoreCommonProperties(oDesigner,item)

					case :FormDesigner_QLineEdit

					case :FormDesigner_QTextEdit

					case :FormDesigner_QListWidget

					case :FormDesigner_QCheckBox

					case :FormDesigner_QImage

					case :FormDesigner_QSlider

					case :FormDesigner_QProgressbar

					case :FormDesigner_QSpinBox

					case :FormDesigner_QComboBox

					case :FormDesigner_QDateTimeEdit

					case :FormDesigner_QTableWidget

					case :FormDesigner_QTreeWidget

					case :FormDesigner_QRadioButton

				}				
			}

		func RestoreCommonProperties oDesigner,item 
			oDesigner.oModel.ActiveObject().move(item[:data][:x],item[:data][:y]) 
			oDesigner.oModel.ActiveObject().resize(item[:data][:width],item[:data][:height])
			oDesigner.oModel.ActiveObject().setText(item[:data][:text])
			oDesigner.oModel.ActiveObject().setTextColor(item[:data][:textcolor])
			oDesigner.oModel.ActiveObject().setBackColor(item[:data][:backcolor])
			oDesigner.oModel.ActiveObject().setFontProperty(item[:data][:font])
			oDesigner.oModel.ActiveObject().refreshCorners(oDesigner.oModel.ActiveObject())
			oDesigner.ObjectProperties()

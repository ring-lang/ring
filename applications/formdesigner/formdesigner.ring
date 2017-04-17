/*
**	Project : Form Designer (Under Development)
**	File Purpose :  Main File
**	Date : 2017.02.17
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

load "guilib.ring"
load "stdlib.ring"

import formdesigner

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
		:FormDesigner_QRadioButton,
		:FormDesigner_QWebView,
		:FormDesigner_QDial,
		:FormDesigner_QVideoWidget,
		:FormDesigner_QFrame3,
		:FormDesigner_QLCDNumber,
		:FormDesigner_QHyperLink,
		:FormDesigner_QTimer,
		:FormDesigner_QAllEvents,
		:FormDesigner_QLayout,
		:FormDesigner_QTabWidget,
		:FormDesigner_QStatusBar,
		:FormDesigner_QToolbar
	] {
		mergemethods(cClassName,:MoveResizeCorners)
		mergemethods(cClassName,:CommonAttributesMethods)
	}

# Constants and Public Variables 
	C_AFTERCOMMON  = 8			# Index After common properties
	cCurrentDir = CurrentDir() + "/"

# Start the Application
	if IsMainSourceFile() { 
		oFDApp = new qApp {
			StyleFusion()
			Open_Window(:FormDesignerController)
			exec()
		}
	}

package formdesigner  

class FormDesignerController from WindowsControllerParent

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

	func ToolBtnChangeAction
		if oView.oToolBtn1.isChecked() { # Select Mode 
			oModel.FormObject().setCursor(new qCursor() { setShape(Qt_ArrowCursor) } )
			EnableMouseEventsForControls()
		else 
			oModel.FormObject().setCursor(new qCursor() { setShape(Qt_CrossCursor) } )
			DisableMouseEventsForControls()
		}

	func DisableMouseEventsForControls
		aObjects = oModel.GetObjects() 
		for x = 2 to len(aObjects) {			
			aObjects[x][2].setAttribute(Qt_WA_TransparentForMouseEvents,True)
		}

	func EnableMouseEventsForControls
		aObjects = oModel.GetObjects() 
		for x = 2 to len(aObjects) {			
			aObjects[x][2].setAttribute(Qt_WA_TransparentForMouseEvents,False)
		}

	func SetToolboxModeToSelectAfterDraw
		if not oView.oToolLock.isChecked() {
			SetToolboxModeToSelect()
		else 
			# To include the latest created control 
				DisableMouseEventsForControls()
		}

	func SetToolboxModeToSelect
		oView.oToolBtn1.setChecked(2)
		ToolBtnChangeAction()
	
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
			oModel.RemoveCurrentParentCache()
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
			UpdatePositionForParent(aRect)
			oModel.AddLabel(new FormDesigner_QLabel(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setMouseTracking(True)
					setFocusPolicy(0)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Label",oModel.LabelsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn3.ischecked()   # Create QPushButton
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddPushButton(new FormDesigner_QPushButton(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setMouseTracking(True)
					setFocusPolicy(0)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Button",oModel.PushButtonsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn4.ischecked()   # Create QLineEdit
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddLineEdit(new FormDesigner_QLineEdit(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("LineEdit",oModel.LineEditsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn5.ischecked()   # Create QTextEdit
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddTextEdit(new FormDesigner_QTextEdit(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("TextEdit",oModel.TextEditsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn6.ischecked()   # Create QListWidget
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddListWidget(new FormDesigner_QListWidget(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("ListWidget",oModel.ListWidgetsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn7.ischecked()   # Create QCheckBox
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddCheckBox(new FormDesigner_QCheckBox(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("CheckBox",oModel.CheckBoxesCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn8.ischecked()   # Create QImage
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddImage(new FormDesigner_QImage(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Image",oModel.ImagesCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn9.ischecked()   # Create QSlider
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddSlider(new FormDesigner_QSlider(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Slider",oModel.SlidersCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn10.ischecked()   # Create QProgressBar
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddProgressbar(new FormDesigner_QProgressbar(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Progressbar",oModel.ProgressbarsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn11.ischecked()   # Create QSpinBox
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddSpinBox(new FormDesigner_QSpinBox(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("SpinBox",oModel.SpinBoxesCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn12.ischecked()   # Create QComboBox
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddComboBox(new FormDesigner_QComboBox(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("ComboBox",oModel.ComboBoxesCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn13.ischecked()   # Create QDateTimeEdit
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddDateTimeEdit(new FormDesigner_QDateTimeEdit(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("DateTimeEdit",oModel.DateTimeEditsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn14.ischecked()   # Create QTableWidget 
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddTableWidget(new FormDesigner_QTableWidget(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("TableWidget",oModel.TableWidgetsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn15.ischecked()   # Create QTreeWidget 
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddTreeWidget(new FormDesigner_QTreeWidget(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("TreeWidget",oModel.TreeWidgetsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn16.ischecked()   # Create QRadioButton  
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddRadioButton(new FormDesigner_QRadioButton(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("RadioButton",oModel.RadioButtonsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn17.ischecked()   # Create QWebView 
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddWebView(new FormDesigner_QWebView(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("WebView",oModel.WebViewsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn18.ischecked()   # Create QDial
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddDial(new FormDesigner_QDial(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Dial",oModel.DialsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn19.ischecked()   # Create QVideoWidget
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddVideoWidget(new FormDesigner_QVideoWidget(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("VideoWidget",oModel.VideoWidgetsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn20.ischecked()   # Create QFrame
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddFrame(new FormDesigner_QFrame3(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Frame",oModel.FramesCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn21.ischecked()   # Create QLCDNumber
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddLCDNumber(new FormDesigner_QLCDNumber(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("LCDNumber",oModel.LCDNumbersCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn22.ischecked()   # Create QHyperLink
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddHyperLink(new FormDesigner_QHyperLink(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("HyperLink",oModel.HyperLinksCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn23.ischecked()   # Create QTimer
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddTimer(new FormDesigner_QTimer(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Timer",oModel.TimersCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn24.ischecked()   # Create QAllEvents
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddAllEvents(new FormDesigner_QAllEvents(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("AllEvents",oModel.AllEventsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn25.ischecked()   # Create QLayout 
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddLayout(new FormDesigner_QLayout(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Layout",oModel.LayoutsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn26.ischecked()   # Create QTab
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddTab(new FormDesigner_QTabWidget(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("Tab",oModel.TabsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn27.ischecked()   # Create QStatusBar
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddStatusBar(new FormDesigner_QStatusBar(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("StatusBar",oModel.StatusBarsCount())
			SetToolboxModeToSelectAfterDraw()
		elseif oView.oToolBtn28.ischecked()   # Create QToolbar
			HideCorners()
			UpdatePositionForParent(aRect)
			oModel.AddToolBar(new FormDesigner_QToolbar(oModel.CurrentParent()) {
					move(aRect[1],aRect[2]) 
					resize(aRect[3],aRect[4])
					setFocusPolicy(0)
					setMouseTracking(True)
					cParent = this.oModel.CurrentParentName()
				}
			)
			oModel.ActiveObject().setCurrentParentName(cParent)
			NewControlEvents("ToolBar",oModel.ToolBarsCount())
			SetToolboxModeToSelectAfterDraw()
		}

	func UpdatePositionForParent aRect
		if classname(oModel.ActiveObject()) = "formdesigner_qtabwidget" {
			aRect[1] -= oModel.ActiveObject().x()
			# 28 for the tab title height
				aRect[2] -= oModel.ActiveObject().y() + 28 
		elseif isObject(oModel.CurrentParentCache()) 
			aRect[1] -= oModel.CurrentParentCache().x()
			# 28 for the tab title height
				aRect[2] -= oModel.CurrentParentCache().y() + 28 
		}

	func NewControlEvents cName,nCount
			oFilter = new qAllevents(oModel.ActiveObject()) {
				setmousebuttonpressevent(Method(:ActiveObjectMousePress+"("+this.oModel.GetCurrentID()+")"))
				setMouseButtonReleaseEvent(Method(:ActiveObjectMouseRelease+"("+this.oModel.GetCurrentID()+")")) 
				setMouseMoveEvent(Method(:ActiveObjectMouseMove+"("+this.oModel.GetCurrentID()+")"))
			}
			oModel.ActiveObject().installeventfilter(oFilter)
			oModel.ActiveObject().oFilter = oFilter
			if find([:formdesigner_qlabel,
				 :formdesigner_qpushbutton,
				 :formdesigner_qcheckbox,
				 :formdesigner_qradiobutton
				],classname(oModel.ActiveObject())) {
				oModel.ActiveObject().setText(cName+nCount)
			}
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
			if not (oObject.CurrentParentName() = "win" or oObject.CurrentParentName() = "") {
				loop
			}
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
			if oModel.IsManySelected() {
				if oModel.IsObjectSelected(nObjectID) { 
					if oFDApp.keyboardmodifiers() {
						oModel.RemoveSelectedObject(nObjectIndex)
						oModel.GetObjectByIndex(nObjectIndex).oCorners.Hide()
					else 
						oModel.GetObjectByIndex(nObjectIndex).MousePressMany(self) 
					}
					return 
				else 
					if oFDApp.keyboardmodifiers() {
						oModel.AddSelectedObject(nObjectIndex)
						oModel.GetObjectByIndex(nObjectIndex).MousePressMany(self) 
						oModel.GetObjectByIndex(nObjectIndex).oCorners.Show()
						return 			
					}					
				}
			else 
				# Here we don't have many objects selected 
				# Support starting multiple selection operation using the keyboard 
				if oFDApp.keyboardmodifiers() {
					oModel.ClearSelectedObjects()
					ChangeObjectByCode(nObjectIndex-1)  
					oModel.ActiveObject().oCorners.Show()
					oModel.AddSelectedObject(nObjectIndex)						
					nWidth = oView.oPropertiesDock.width()
					oView.oPropertiesDock.setWidget(oView.oProperties2)
					oView.oPropertiesDock.setminimumwidth(nWidth)
					return 
				}
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

	func KeyPressAction
		if oModel.IsManySelected() { KeyPressManyAction() return }
		if oModel.IsFormActive() { return }
		nKey = oView.oFilter.getkeycode()
		nModifier = oView.oFilter.getmodifiers()
		switch nModifier  {
			case 	0 # No CTRL Key is pressed
				switch nkey {
					case Qt_Key_Right
						oModel.ActiveObject().move( oModel.ActiveObject().x() + 10 ,
											oModel.ActiveObject().y() )
					case Qt_Key_Left
						oModel.ActiveObject().move( oModel.ActiveObject().x() - 10 ,
											oModel.ActiveObject().y() )
					case Qt_Key_Up
						oModel.ActiveObject().move( oModel.ActiveObject().x()  ,
											oModel.ActiveObject().y()  - 10)
					case Qt_Key_Down
						oModel.ActiveObject().move( oModel.ActiveObject().x()  ,
											oModel.ActiveObject().y()  + 10)
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
						oModel.ActiveObject().resize( oModel.ActiveObject().width() + 10 ,
											oModel.ActiveObject().height() )
					case Qt_Key_Left
						oModel.ActiveObject().resize( oModel.ActiveObject().width() - 10 ,
											oModel.ActiveObject().height() )
					case Qt_Key_Up
						oModel.ActiveObject().resize( oModel.ActiveObject().width()  ,
											oModel.ActiveObject().height() - 10)
					case Qt_Key_Down
						oModel.ActiveObject().resize( oModel.ActiveObject().width()  ,
											oModel.ActiveObject().height() + 10)
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
		# Get Minimum Top and Maximum Top+Height 
		nMinTop = 5000
		nMaxTopHeight = 0
		for item in aObjects {
			oObject = item[2]
			nMinTop = min(nMinTop,oObject.y())
			nMaxTopHeight = max(nMaxTopHeight,oObject.y()+oObject.Height())
		}
		# Get Top Difference 
			nDiff = nMaxTopHeight - nMinTop
			nTop = (oObject.ParentWidget().Height() - nDiff ) / 2
			nDiff = nMinTop - nTop
		# Apply the Top difference to all controls 
		for item in aObjects {
			oObject = item[2]
			oObject.move(oObject.x() ,oObject.y()-nDiff)
			oObject.oCorners.Refresh(oObject)
		}

	func MSCenterHor
		aObjects = oModel.GetSelectedObjects()
		# Get Minimum Left and Maximum Left+Width
		nMinLeft = 5000
		nMaxLeftWidth = 0
		for item in aObjects {
			oObject = item[2]
			nMinLeft = min(nMinLeft,oObject.x())
			nMaxLeftWidth = max(nMaxLeftWidth,oObject.x()+oObject.Width())
		}
		# Get Left Difference 
			nDiff = nMaxLeftWidth - nMinLeft
			nLeft = (oObject.ParentWidget().Width() - nDiff ) / 2
			nDiff = nMinLeft - nLeft
		# Apply the Left difference to all controls 
		for item in aObjects {
			oObject = item[2]
			oObject.move(oObject.x()-nDiff,oObject.y())
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

	func Duplicate 
		# Selected objects - if we have many objects selected 
			oModel.RefreshSelectedObjects()
			aObjects = oModel.GetSelectedObjects()
		# Support duplication of one selected object  
			if  len(aObjects) = 0  and not oModel.IsFormActive()  {
				aObjects = oModel.ActiveObjectItemAsList() 
			}
		# Display messagebox if not objects are selected 
			if len(aObjects) = 0 {
				ShowMsg("Sorry!","No objects are selected","Select objects first to be duplicated")
				return 
			}
		# Duplication of selected objects 
			cCode  = oFile.Objects2String(self,aObjects)
			eval(cCode)
			# Update Name and Position
				nIndex = 0
				for item in aObjectsList {
					nIndex++
					# Remove Numbers from the name 
						for char in item[:name] {
							if not isalpha(char) and isalnum(char) {
								char = " "
							}
						}
						item[:name] = substr(item[:name]," ","")
					# Add New number to the name 
						# -1 to avoid counting the window object 
							item[:name] += "" + (oModel.ObjectsCount()+nIndex-1)
					# Update Position
						item[:data][:x] += 10
						item[:data][:y] += 10
				}
			nCount = oModel.ObjectsCount()
			oFile.CreateFormObjects(self,aObjectsList)
			# Select the new objects 
				aObjects = oModel.GetObjects() 
				for x = nCount+1 to len(aObjects) {	
					item = aObjects[x]
					oObject = item[2]	
					oObject.oCorners.Show()
					oModel.AddSelectedObject(x)	 
				}

	func ShowMsg cTitle,cText,cText2
		new qmessagebox(oView.win)
		{
			setwindowtitle(cTitle)
			settext(cText)
			setInformativeText(cText2)
			setstandardbuttons(QMessageBox_Ok)
			exec()
		}

	func BringToFront
		if CheckOneObject() { 
			oModel.ActiveObject().raise()
			oModel.RaiseActiveObject()
			AddObjectsToCombo()
		}

	func SendToBack
		if CheckOneObject() { 
			oModel.ActiveObject().lower()
			oModel.LowerActiveObject()
			AddObjectsToCombo()
		}

	func CheckOneObject 
		if oModel.IsFormActive()  or oModel.IsManySelected() {
			ShowMsg("Sorry!","Object selection is not correct","Select one object first!")
			return False
		}
		return True

	func Toolbox
		if oView.oToolBoxDock.isvisible() {
			oView.oToolBoxDock.hide()
		else
			oView.oToolBoxDock.Show()
		}

	func Properties
		if oView.oPropertiesDock.isvisible() {
			oView.oPropertiesDock.hide()
		else
			oView.oPropertiesDock.Show()
		}

	func OpenCHMAction
		System( "start " + exefolder()+"/../docs/ring.chm" )

	func OpenPDFAction
		System( "start " + exefolder()+"/../docs/ring.pdf" )

	Func MsgBox cTitle,cMessage
		new qMessagebox(NULL) {
			setwindowtitle(cTitle)
			setText(cMessage)
			show()
		}
	
	func LangAction
		MsgBox("Programming Language",
			"This application developed using the Ring programming language")

	func GUIAction
		MsgBox("GUI Library",
			"This application uses the Qt GUI Library through RingQt")

	func AboutAction
		MsgBox("About",
		"2017, Mahmoud Fayed <msfclipper@yahoo.com>")		

Class FormDesignerView from WindowsViewParent

	oForm oSub oFilter oArea win  

	oPropertiesDock oProperties oProperties2 
	oObjectsCombo 	oPropertiesTable oLabelSelect

	oToolBoxDock	oToolLock
	oToolBtn1 oToolBtn2 oToolBtn3 oToolBtn4 oToolBtn5 
	oToolBtn6 oToolBtn7 oToolBtn8 oToolBtn9 oToolBtn10 
	oToolBtn11 oToolBtn12 oToolBtn13 oToolBtn14 
	oToolBtn15  oToolBtn16 oToolBtn17 oToolBtn18 
	oToolBtn19 oToolBtn20 oToolBtn21 oToolBtn22 oToolBtn23
	oToolBtn24 oToolBtn25 oToolBtn26 oToolBtn27  oToolBtn28

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
			subEdit = addmenu("Edit")
			subEdit {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+v"))
					settext("Duplicate")
					setclickevent(Method(:Duplicate))
				}
				addaction(oAction)			
				addseparator()	
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+f"))
					settext("Bring to front")
					setclickevent(Method(:BringToFront))
				}
				addaction(oAction)			
				addseparator()	
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+b"))
					settext("Send to back")
					setclickevent(Method(:SendToBack))
				}
				addaction(oAction)			
			}
			subView = addmenu("View")
			subView {
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+t"))
					settext("ToolBox")
					setclickevent(Method(:ToolBox))
				}
				addaction(oAction)			
				addseparator()	
				oAction = new qAction(this.win) {
					setShortcut(new QKeySequence("Ctrl+p"))
					setclickevent(Method(:Properties))
					settext("Properties")
				}
				addaction(oAction)	
				addseparator()	
			}
			subHelp = addmenu("Help")
			subHelp { 
				subHelpLF = addmenu("Language Reference")
				subHelpLF { 
					oAction = new qAction(this.win) {
						settext("CHM File")
						setclickevent(Method(:OpenCHMAction))
					}
					addaction(oAction)
					oAction = new qAction(this.win) {
						settext("PDF File")
						setclickevent(Method(:OpenPDFAction))
					}
					addaction(oAction)
				}
				addseparator()
				subHelpTools = addmenu("Development Tools")
				subHelpTools { 
					oAction = new qAction(this.win) {
						settext("Programming Language")
						setclickevent(Method(:LangAction))
					}
					addaction(oAction)
					oAction = new qAction(this.win) {
						settext("GUI Library")
						setclickevent(Method(:GUIAction))
					}
					addaction(oAction)
				}
				addseparator()
				oAction = new qAction(this.win) {
					settext("About")
					setclickevent(Method(:AboutAction))
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
	  		for x in aBtns { addwidget(x) addseparator() }
		}

	func CreateToolBox
		oToolBox = new qWidget() {
 			this.oToolLock = new qPushButton(oToolBox) {
					setText(this.TextSize("Lock",20))
					setbtnimage(self,"image/lock.png") 
					setCheckable(True)
					setChecked(false)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn1 = new qPushButton(oToolBox) {
					setText(this.TextSize("Select",20))
					setbtnimage(self,"image/select.png") 
					setminimumwidth(150)
					setCheckable(True)
					setChecked(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn2 = new qPushButton(oToolBox) {
					setText(this.TextSize("Label",20))
					setbtnimage(self,"image/label.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn3 = new qPushButton(oToolBox) {
					setText(this.TextSize("Button",18))
					setbtnimage(self,"image/pushbutton.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn4 = new qPushButton(oToolBox) {
					setText(this.TextSize("LineEdit",19))
					setbtnimage(self,"image/textfield.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn5 = new qPushButton(oToolBox) {
					setText(this.TextSize("TextEdit",19))
					setbtnimage(self,"image/textarea.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn6 = new qPushButton(oToolBox) {
					setText(this.TextSize("ListWidget",17))
					setbtnimage(self,"image/listview.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn7 = new qPushButton(oToolBox) {
					setText(this.TextSize("Checkbox",16))
					setbtnimage(self,"image/checkbox.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn8 = new qPushButton(oToolBox) {
					setText(this.TextSize("Image",19))
					setbtnimage(self,"image/image.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn9 = new qPushButton(oToolBox) {
					setText(this.TextSize("Slider",20))
					setbtnimage(self,"image/slider.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn10 = new qPushButton(oToolBox) {
					setText(this.TextSize("Progressbar",15))
					setbtnimage(self,"image/progressbar.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn11 = new qPushButton(oToolBox) {
					setText(this.TextSize("SpinBox",17))
					setbtnimage(self,"image/spinner.bmp") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn12 = new qPushButton(oToolBox) {
					setText(this.TextSize("ComboBox",17))
					setbtnimage(self,"image/combobox.bmp") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn13 = new qPushButton(oToolBox) {
					setText(this.TextSize("DateTimeEdit",17))
					setbtnimage(self,"image/datepicker.bmp") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn14 = new qPushButton(oToolBox) {
					setText(this.TextSize("TableWidget",17))
					setbtnimage(self,"image/grid.bmp") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn15 = new qPushButton(oToolBox) {
					setText(this.TextSize("TreeWidget",17))
					setbtnimage(self,"image/tree.bmp") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn16 = new qPushButton(oToolBox) {
					setText(this.TextSize("RadioButton",17))
					setbtnimage(self,"image/radiobutton.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn17 = new qPushButton(oToolBox) {
					setText(this.TextSize("WebView",17))
					setbtnimage(self,"image/webview.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn18 = new qPushButton(oToolBox) {
					setText(this.TextSize("Dial Slider",20))
					setbtnimage(self,"image/dial.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn19 = new qPushButton(oToolBox) {
					setText(this.TextSize("Video Widget",17))
					setbtnimage(self,"image/videowidget.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn20 = new qPushButton(oToolBox) {
					setText(this.TextSize("Frame",20))
					setbtnimage(self,"image/frame.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn21 = new qPushButton(oToolBox) {
					setText(this.TextSize("LCD Number",17))
					setbtnimage(self,"image/lcdnumber.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn22 = new qPushButton(oToolBox) {
					setText(this.TextSize("HyperLink",20))
					setbtnimage(self,"image/hyperlink.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn23 = new qPushButton(oToolBox) {
					setText(this.TextSize("Timer",22))
					setbtnimage(self,"image/timer.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn24 = new qPushButton(oToolBox) {
					setText(this.TextSize("All Events",20))
					setbtnimage(self,"image/allevents.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn25 = new qPushButton(oToolBox) {
					setText(this.TextSize("Layout",20))
					setbtnimage(self,"image/layout.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn26 = new qPushButton(oToolBox) {
					setText(this.TextSize("Tab Widget",18))
					setbtnimage(self,"image/tab.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn27 = new qPushButton(oToolBox) {
					setText(this.TextSize("Statusbar",20))
					setbtnimage(self,"image/statusbar.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}
 			this.oToolbtn28 = new qPushButton(oToolBox) {
					setText(this.TextSize("Toolbar",20))
					setbtnimage(self,"image/toolbar.png") 
					setCheckable(True)
					setClickEvent(Method(:ToolBtnChangeAction))
			}

			Layout1 = new qVBoxLayout() {
				AddWidget(this.oToolLock)
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
				AddWidget(this.oToolbtn17)
				AddWidget(this.oToolbtn18)
				AddWidget(this.oToolbtn19)
				AddWidget(this.oToolbtn20)
				AddWidget(this.oToolbtn21)
				AddWidget(this.oToolbtn22)
				AddWidget(this.oToolbtn23)
				AddWidget(this.oToolbtn24)
				AddWidget(this.oToolbtn25)
				AddWidget(this.oToolbtn26)
				AddWidget(this.oToolbtn27)
				AddWidget(this.oToolbtn28)
				insertStretch( -1, 1 )
			}
			btnsGroup = new qButtonGroup(oToolBox) {
				setbuttonClickedEvent(Method(:ToolBtnChangeAction))
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
				AddButton(this.oToolbtn17,16)
				AddButton(this.oToolbtn18,17)
				AddButton(this.oToolbtn19,18)
				AddButton(this.oToolbtn20,19)
				AddButton(this.oToolbtn21,20)
				AddButton(this.oToolbtn22,21)
				AddButton(this.oToolbtn23,22)
				AddButton(this.oToolbtn24,23)
				AddButton(this.oToolbtn25,24)
				AddButton(this.oToolbtn26,25)
				AddButton(this.oToolbtn27,26)
				AddButton(this.oToolbtn28,27)
			}
			setLayout(Layout1)
		}
		oScroll = new qScrollArea(null) {
			setWidget(oToolBox)
			setMiniMumWidth(185)
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
				setColumnwidth(0,190)
				setColumnwidth(2,40)
				setAlternatingRowColors(true)
				horizontalHeader().setStyleSheet("color: blue")
				verticalHeader().setStyleSheet("color: red")
				setitemChangedEvent(Method(:UpdateProperties))
				setminimumwidth(370)
			}
			oLayout2 = new qVBoxLayout() {
				AddLayout(oLayout1)
				AddWidget(this.oPropertiesTable)
			}
			setLayout(oLayout2)
		}
		oProperties2 = new qWidget() {
			oLabel = new qLabel(this.oProperties2) {
				setText("Options")
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
			return oTab.aTabs[0+aList[2]][1]
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
		aManySelectedObjects + aObjectsList[nIndex]

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
		for Item in aObjectsList {
			if PtrCmp( Item[2].pObject , oObject.pObject ) {
				Item[1] = cValue
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

	func ActiveObjectItemAsList
		return [ aObjectsList[nActiveObject] ] 

	func RaiseActiveObject
		swap(aObjectsList,nActiveObject,len(aObjectsList))

	func LowerActiveObject
		cParentValue = ActiveObject().CurrentParentName()
		for x = 2 to len(aObjectsList) {
				if aObjectsList[x][2].CurrentParentName() = cParentValue {
					exit 
				}
		}
		if not x = nActiveObject {
			swap(aObjectsList,nActiveObject,x)
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

	func SelectFile oDesigner
		new qfiledialog(oDesigner.oView.win) {
			cInputFileName = getopenfilename(oDesigner.oView.win,"Open File",currentdir(),"*.*")
		}
		return cInputFileName

class FormDesigner_QWidget from QWidget 

	cBackColor = ""
	oSubWindow
	nX=0 nY=0		# for Select/Draw
	cWindowFlags = ""
	cMainLayout = ""
	cWindowIcon = ""

	func BackColor
		return cBackColor

	func setBackColor cValue 
		cBackColor=cValue	
		updatestylesheets()

	func updatestylesheets
		setstylesheet("background-color:"+cBackColor+";")

	func setSubWindow oObject 
		oSubWindow = oObject

	func WindowFlagsValue
		return cWindowFlags

	func SetWindowFlagsValue cValue 
		cWindowFlags = cValue

	func MainLayoutValue 
		return cMainLayout

	func SetMainLayoutValue cValue 
		cMainLayout = cValue 

	func WindowIconValue
		return cWindowIcon

	func SetWindowIconValue cValue 
		cWindowIcon = cValue 

	func AddObjectProperties  oDesigner
		oDesigner.oView.AddProperty("X",False)
		oDesigner.oView.AddProperty("Y",False)
		oDesigner.oView.AddProperty("Width",False)
		oDesigner.oView.AddProperty("Height",False)
		oDesigner.oView.AddProperty("Title",False)
		oDesigner.oView.AddProperty("Back Color",True)
		oDesigner.oView.AddProperty("Window Flags",True)
		oDesigner.oView.AddProperty("Set Layout",False)
		oDesigner.oView.AddProperty("Window Icon",True)

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
				case 6	# Window Flags
					setWindowFlagsValue(cValue)
				case 7  	# Main Layout
					setMainLayoutValue(cValue)
				case 8  	# Window Icon
					setWindowIconValue(cValue)
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
		# Set the Window Flags
			oPropertiesTable.item(6,1).settext(WindowFlagsValue())
		# Set the Main Layout
			oPropertiesTable.item(7,1).settext(MainLayoutValue())
		# Set the Window Icon 
			oPropertiesTable.item(8,1).settext(WindowIconValue())
		oPropertiesTable.Blocksignals(False)

	func DialogButtonAction oDesigner,nRow 
		switch nRow {
			case 5 	# Back Color
				cColor = oDesigner.oGeneral.SelectColor()
				setBackColor(cColor)
				DisplayProperties(oDesigner)
			case 6	# Window Flags 				
				open_window(:WindowFlagsController)
				Last_Window().setParentObject(oDesigner)
			case 8	# Window Icon 
				cFile = oDesigner.oGeneral.SelectFile(oDesigner)
				setWindowIconValue(cFile)
				DisplayProperties(oDesigner)
		}

	func MousePressAction oDesigner
		# 8, 6 to start drawing from the center of the Mouse Cursor 
			nX = oDesigner.oView.oFilter.getglobalx() - 8
			ny = oDesigner.oView.oFilter.getglobaly() - 6
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

	func ObjectDataAsString oDesigner,nTabsCount
		cTabs = copy(char(9),nTabsCount) 
		cOutput = cTabs + " :x = #{f1} , : y = #{f2}  , " + nl
		cOutput += cTabs + " :width =  #{f3} , :height = #{f4} , " + nl
		cOutput += cTabs + ' :title =  "#{f5}" , ' + nl
		cOutput += cTabs + ' :backcolor =  "#{f6}" , ' + nl
		cOutput += cTabs + ' :windowflags =  "#{f7}" , ' + nl
		cOutput += cTabs + ' :mainlayout =  "#{f8}" ,' + nl
		cOutput += cTabs + ' :WindowIcon =  "#{f9}" ' + nl
		cOutput = substr(cOutput,"#{f1}",""+parentwidget().x())
		cOutput = substr(cOutput,"#{f2}",""+parentwidget().y())
		cOutput = substr(cOutput,"#{f3}",""+parentwidget().width())
		cOutput = substr(cOutput,"#{f4}",""+parentwidget().height())
		cOutput = substr(cOutput,"#{f5}",windowtitle())
		cOutput = substr(cOutput,"#{f6}",backcolor())
		cOutput = substr(cOutput,"#{f7}",WindowFlagsValue())
		cOutput = substr(cOutput,"#{f8}",MainLayoutValue())
		cOutput = substr(cOutput,"#{f9}",WindowIconValue())
		return cOutput 

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) + 
		'move(#{f1},#{f2})
		resize(#{f3},#{f4})
		setWindowTitle("#{f5}")
		setstylesheet("background-color:#{f6};") ' + nl
		if not WindowFlagsValue() = NULL {
			cOutput += '
		setWindowFlags(#{f7}) ' + nl
		}
		if not WindowIconValue() = NULL {
			cOutput += '
		setWinIcon(win,"#{f8}") ' + nl
		}
		cOutput = substr(cOutput,"#{f1}",""+parentwidget().x())
		cOutput = substr(cOutput,"#{f2}",""+parentwidget().y())
		cOutput = substr(cOutput,"#{f3}",""+parentwidget().width())
		cOutput = substr(cOutput,"#{f4}",""+parentwidget().height())
		cOutput = substr(cOutput,"#{f5}",windowtitle())
		cOutput = substr(cOutput,"#{f6}",backcolor())
		cOutput = substr(cOutput,"#{f7}",WindowFlagsValue())
		cOutput = substr(cOutput,"#{f8}",WindowIconValue())
		return cOutput

	func GenerateCodeAfterObjects oDesigner
		cOutput = ""
		if not MainLayoutValue() = NULL {
			cOutput += '
		setLayout(#{f1}) ' + nl
			cOutput = substr(cOutput,"#{f1}",MainLayoutValue())
		}
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
		if not oDesigner.oModel.IsManySelected() {
			DisplayProperties(oDesigner)
		}

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
		AddAttribute(self,:cCurrentParentName)
		cTextColor = "black"
		cBackColor = ""
		cFontProperty = ""
		cCurrentParentName = "win"

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

	func CurrentParentName
		return cCurrentParentName

	func SetCurrentParentName cValue
		cCurrentParentName = cValue

	func updatestylesheets
		setstylesheet("color:"+cTextColor+";background-color:"+cBackColor+";")

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)

	func AddObjectCommonProperties  oDesigner
		oDesigner.oView.AddProperty("Name",False)
		oDesigner.oView.AddProperty("X",False)
		oDesigner.oView.AddProperty("Y",False)
		oDesigner.oView.AddProperty("Width",False)
		oDesigner.oView.AddProperty("Height",False)
		oDesigner.oView.AddProperty("Text Color",True)
		oDesigner.oView.AddProperty("Back Color",True)
		oDesigner.oView.AddProperty("Font",True)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)

	func UpdateCommonProperties oDesigner,nRow,nCol,cValue
		if nCol = 1 {
			switch nRow {
				case 0	# Name
					oDesigner.oModel.SetObjectName(oDesigner,self,cValue)
					oDesigner.AddObjectsToCombo()
					# Because we may prevent name change (duplication)
						DisplayCommonProperties(oDesigner)
				case 1 	# x
					move(0+cValue,y())
				case 2 	# y
					move(x(),0+cValue)
				case 3	# width
					resize(0+cValue,height())
				case 4 	# height
					resize(width(),0+cValue)
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
		# Set the Name 
			oPropertiesTable.item(0,1).settext(
				oDesigner.oModel.GetObjectName(self))
		# Set the X
			oPropertiesTable.item(1,1).settext(""+x())
		# Set the Y
			oPropertiesTable.item(2,1).settext(""+y())
		# Set the Width
			oPropertiesTable.item(3,1).settext(""+width())
		# Set the Height
			oPropertiesTable.item(4,1).settext(""+height())
		# Set the Text Color
			oPropertiesTable.item(5,1).settext(textcolor())
		# Set the BackColor
			oPropertiesTable.item(6,1).settext(backcolor())
		# Set the Font
			oPropertiesTable.item(7,1).settext(fontproperty())

		oPropertiesTable.Blocksignals(False)

	func DialogButtonAction oDesigner,nRow 
		CommonDialogButtonAction(oDesigner,nRow)

	func CommonDialogButtonAction oDesigner,nRow 
		if nRow = 5 {	# Text Color
			cColor = oDesigner.oGeneral.SelectColor()
			setTextColor(cColor)
			DisplayProperties(oDesigner)
		elseif nRow = 6 	# Back Color
			cColor = oDesigner.oGeneral.SelectColor()
			setBackColor(cColor)
			DisplayProperties(oDesigner)
		elseif nRow = 7	# Font
			cFont = oDesigner.oGeneral.SelectFont()
			setFontProperty(cFont)
			DisplayProperties(oDesigner) 
		}

	func  ObjectDataAsString oDesigner,nTabsCount
		return ObjectDataAsString2(oDesigner,nTabsCount)

	func ObjectDataAsString2 oDesigner,nTabsCount
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput = cTabs + " :x = #{f1} , : y = #{f2}  , " + nl
		cOutput += cTabs + " :width =  #{f3} , :height = #{f4} , " + nl
		cOutput += cTabs + ' :textcolor =  "#{f5}" , ' + nl
		cOutput += cTabs + ' :backcolor =  "#{f6}" , ' + nl
		cOutput += cTabs + ' :font =  "#{f7}" , ' + nl
		cOutput += cTabs + ' :parent =  "#{f8}"  ' 
		cOutput = substr(cOutput,"#{f1}",""+x())
		cOutput = substr(cOutput,"#{f2}",""+y())
		cOutput = substr(cOutput,"#{f3}",""+width())
		cOutput = substr(cOutput,"#{f4}",""+height())
		cOutput = substr(cOutput,"#{f5}",textcolor())
		cOutput = substr(cOutput,"#{f6}",backcolor())
		cOutput = substr(cOutput,"#{f7}",fontproperty())
		cOutput = substr(cOutput,"#{f8}",CurrentParentName())
		return cOutput 

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) + 
		oDesigner.oModel.GetObjectName(self) + " = " +
		'new #{f1}(#{f10}) {
			move(#{f2},#{f3})
			resize(#{f4},#{f5})
			setstylesheet("color:#{f6};background-color:#{f7};")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("#{f8}")
			setfont(oFont)
#{f9}
		}' + nl
		cClass = substr(classname(self),"formdesigner_","")
		if cClass  = "qimage" or cClass = "qhyperlink"  {
			cClass = "qlabel"
		}
		cOutput = substr(cOutput,"#{f1}",cClass)
		cOutput = substr(cOutput,"#{f2}",""+x())
		cOutput = substr(cOutput,"#{f3}",""+y())
		cOutput = substr(cOutput,"#{f4}",""+width())
		cOutput = substr(cOutput,"#{f5}",""+height())
		cOutput = substr(cOutput,"#{f6}",textcolor())
		cOutput = substr(cOutput,"#{f7}",backcolor())
		cOutput = substr(cOutput,"#{f8}",fontproperty())
		cOutput = substr(cOutput,"#{f9}",AddTabs(GenerateCustomCode(oDesigner),3))
		cOutput = substr(cOutput,"#{f10}",CurrentParentName())
		return cOutput

	func AddTabs cText,nCount
		cTabs = std_copy(char(9),nCount)
		cText = cTabs + cText
		cText = substr(cText,nl,nl+cTabs)
		return cText

	func GenerateCustomCode oDesigner
		return ""

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)

	func RestoreCommonProperties oDesigner,item 
		itemdata = item[:data]
		blocksignals(true)
		setMouseTracking(True)
		setFocusPolicy(0)
		oDesigner.oModel.SetObjectName(oDesigner,self,item[:name])
		move(itemdata[:x],itemdata[:y]) 
		resize(itemdata[:width],itemdata[:height])
		setTextColor(itemdata[:textcolor])
		setBackColor(itemdata[:backcolor])
		setFontProperty(itemdata[:font])
		setCurrentParentName(itemdata[:parent])
		refreshCorners(oDesigner.oModel.ActiveObject())			
		blocksignals(false)

	func PrepareEvent cCode,cEvent,cReplace 
		# Remove " " around event if we uses Code		
		cEvent = std_lower(cEvent)
		if substr(cEvent,"(") > 0 {
			cCode = substr(cCode,char(34)+cReplace+char(34),cReplace)
		else
			if cEvent != "" {
				cCode = substr(cCode,char(34)+cReplace+char(34),"Method(:"+cReplace+")")
			}
		}
		return cCode

class FormDesigner_QLabel from QLabel

	nTextAlign = 0

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func TextAlign
		return nTextAlign

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
		oDesigner.oView.AddProperty("Text",False)
		oDesigner.oView.AddPropertyCombobox("Text Align",["Left","Center","Right"])

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(text())
		# Text Align 
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON+1,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(nTextAlign)
			oCombo.BlockSignals(False)
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON { 
			setText(cValue)
		}

	func ComboItemAction oDesigner,nRow
		nTextAlignPos = C_AFTERCOMMON+1
		if nRow = nTextAlignPos  {		# Text Align 
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nTextAlignPos,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			nIndex = oCombo.CurrentIndex()
			setTextAlign(nIndex)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :text =  "' + Text() + '"'
		cOutput += "," + nl + cTabs + ' :textalign =  ' + TextAlign() 
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setText("#{f1}")' + nl + 'setAlignment(#{f2})'
		cOutput = substr(cOutput,"#{f1}",text())
		Switch nTextAlign {
			case 0
				cOutput = substr(cOutput,"#{f2}","Qt_AlignLeft |  Qt_AlignVCenter")
			case 1
				cOutput = substr(cOutput,"#{f2}","Qt_AlignHCenter |  Qt_AlignVCenter" )			
			case 2
				cOutput = substr(cOutput,"#{f2}","Qt_AlignRight |  Qt_AlignVCenter" )
		}
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setText(itemdata[:text])
		setTextAlign(0+itemdata[:textalign])

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
		oDesigner.oView.AddProperty("Text",False)
		oDesigner.oView.AddProperty("Image",True)
		oDesigner.oView.AddProperty("Set Click Event",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(text())
		# Set the Button Image
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(BtnImageValue())
			setBtnImage(self,BtnImageValue())
		# Set the Click Event 
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(clickeventcode())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON 
					setText(cValue)
				case C_AFTERCOMMON+1
					setBtnImageValue(cValue)
					setBtnImage(self,cValue)
				case C_AFTERCOMMON+2  	# Click Event 
					setClickEventCode(cValue)
			}
		}

	func DialogButtonAction oDesigner,nRow 
		CommonDialogButtonAction(oDesigner,nRow)
		switch nRow {
			case C_AFTERCOMMON+1	# Button Image
				cFile = oDesigner.oGeneral.SelectFile(oDesigner)
				setBtnImageValue(cFile)
				DisplayProperties(oDesigner)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :text =  "' + Text() + '"'
		cOutput += "," + nl + cTabs + ' :BtnImage =  "' + BtnImageValue() + '"'
		cOutput += "," + nl + cTabs + ' :setClickEvent =  "' + ClickEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setText("#{f1}")' + nl 
		cOutput += 'setClickEvent("#{f2}")' + nl
		cOutput += 'setBtnImage(#{f3},"#{f4}")' + nl
		cOutput = substr(cOutput,"#{f1}",text())
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

class FormDesigner_QLineEdit from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cText = ""

	cTextChangedEvent = ""
	ccursorPositionChangedEvent = ""
	ceditingFinishedEvent = ""
	creturnPressedEvent = ""
	cselectionChangedEvent = ""
	ctextEditedEvent = ""

	func TextValue 
		return cText

	func SetTextValue value 
		cText = value 

	func SetTextChangedEventCode cValue
		cTextChangedEvent = cValue

	func TextChangedEventCode
		return cTextChangedEvent
			
	func SetcursorPositionChangedEventCode cValue
		ccursorPositionChangedEvent = cValue

	func cursorPositionChangedEventCode
		return ccursorPositionChangedEvent
			
	func SeteditingFinishedEventCode cValue
		ceditingFinishedEvent = cValue

	func editingFinishedEventCode
		return ceditingFinishedEvent
			
	func SetreturnPressedEventCode cValue
		creturnPressedEvent = cValue

	func returnPressedEventCode
		return creturnPressedEvent
			
	func SetselectionChangedEventCode cValue
		cselectionChangedEvent = cValue

	func selectionChangedEventCode
		return cselectionChangedEvent
			
	func SettextEditedEventCode cValue
		ctextEditedEvent = cValue

	func textEditedEventCode
		return ctextEditedEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Text",False)
		oDesigner.oView.AddProperty("TextChangedEvent",False)
		oDesigner.oView.AddProperty("cursorPositionChangedEvent",False)
		oDesigner.oView.AddProperty("editingFinishedEvent",False)
		oDesigner.oView.AddProperty("returnPressedEvent",False)
		oDesigner.oView.AddProperty("selectionChangedEvent",False)
		oDesigner.oView.AddProperty("textEditedEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(TextValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(TextChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(cursorPositionChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(editingFinishedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(returnPressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(selectionChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(textEditedEventcode())
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
					setTextChangedEventCode(cValue)
				case C_AFTERCOMMON+2
					setcursorPositionChangedEventCode(cValue)
				case C_AFTERCOMMON+3
					seteditingFinishedEventCode(cValue)
				case C_AFTERCOMMON+4
					setreturnPressedEventCode(cValue)
				case C_AFTERCOMMON+5
					setselectionChangedEventCode(cValue)
				case C_AFTERCOMMON+6
					settextEditedEventCode(cValue)
			}
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :text =  "' + TextValue() + '"'
		cOutput += "," + nl + cTabs + ' :setTextChangedEvent =  "' + TextChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcursorPositionChangedEvent =  "' + cursorPositionChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :seteditingFinishedEvent =  "' + editingFinishedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setreturnPressedEvent =  "' + returnPressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setselectionChangedEvent =  "' + selectionChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :settextEditedEvent =  "' + textEditedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setText("#{f1}")' + nl  
		cOutput = substr(cOutput,"#{f1}",textValue())
		cOutput += 'setTextChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,TextChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",TextChangedEventCode())
		cOutput += 'setcursorPositionChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,cursorPositionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",cursorPositionChangedEventCode())
		cOutput += 'seteditingFinishedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,editingFinishedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",editingFinishedEventCode())
		cOutput += 'setreturnPressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,returnPressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",returnPressedEventCode())
		cOutput += 'setselectionChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,selectionChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",selectionChangedEventCode())
		cOutput += 'settextEditedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,textEditedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",textEditedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setTextValue(itemdata[:text])
		SetTextChangedEventCode(itemdata[:setTextChangedEvent])
		SetcursorPositionChangedEventCode(itemdata[:setcursorPositionChangedEvent])
		SeteditingFinishedEventCode(itemdata[:seteditingFinishedEvent])
		SetreturnPressedEventCode(itemdata[:setreturnPressedEvent])
		SetselectionChangedEventCode(itemdata[:setselectionChangedEvent])
		SettextEditedEventCode(itemdata[:settextEditedEvent])

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
		oDesigner.oView.AddProperty("Text",False)
		oDesigner.oView.AddProperty("copyAvailableEvent",False)
		oDesigner.oView.AddProperty("currentCharFormatChangedEvent",False)
		oDesigner.oView.AddProperty("cursorPositionChangedEvent",False)
		oDesigner.oView.AddProperty("redoAvailableEvent",False)
		oDesigner.oView.AddProperty("selectionChangedEvent",False)
		oDesigner.oView.AddProperty("textChangedEvent",False)
		oDesigner.oView.AddProperty("undoAvailableEvent",False)

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
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :text =  "' + TextValue() + '"'
		cOutput += "," + nl + cTabs + ' :setcopyAvailableEvent =  "' + copyAvailableEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentCharFormatChangedEvent =  "' + currentCharFormatChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcursorPositionChangedEvent =  "' + cursorPositionChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setredoAvailableEvent =  "' + redoAvailableEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setselectionChangedEvent =  "' + selectionChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :settextChangedEvent =  "' + textChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setundoAvailableEvent =  "' + undoAvailableEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setText("#{f1}")' + nl  
		cOutput = substr(cOutput,"#{f1}",textValue())
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
		SetcopyAvailableEventCode(itemdata[:setcopyAvailableEvent])
		SetcurrentCharFormatChangedEventCode(itemdata[:setcurrentCharFormatChangedEvent])
		SetcursorPositionChangedEventCode(itemdata[:setcursorPositionChangedEvent])
		SetredoAvailableEventCode(itemdata[:setredoAvailableEvent])
		SetselectionChangedEventCode(itemdata[:setselectionChangedEvent])
		SettextChangedEventCode(itemdata[:settextChangedEvent])
		SetundoAvailableEventCode(itemdata[:setundoAvailableEvent])

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
		oDesigner.oView.AddProperty("Items (S: Comma)",False)
		oDesigner.oView.AddProperty("Current Row",False)
		oDesigner.oView.AddProperty("currentItemChangedEvent",False)
		oDesigner.oView.AddProperty("currentRowChangedEvent",False)
		oDesigner.oView.AddProperty("currentTextChangedEvent",False)
		oDesigner.oView.AddProperty("itemActivatedEvent",False)
		oDesigner.oView.AddProperty("itemChangedEvent",False)
		oDesigner.oView.AddProperty("itemClickedEvent",False)
		oDesigner.oView.AddProperty("itemDoubleClickedEvent",False)
		oDesigner.oView.AddProperty("itemEnteredEvent",False)
		oDesigner.oView.AddProperty("itemPressedEvent",False)
		oDesigner.oView.AddProperty("itemSelectionChangedEvent",False)

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
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :cItems =  "' + cItemsValue() + '"'
		cOutput += "," + nl + cTabs + ' :cCurrentRow =  "' + cCurrentRowValue() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentItemChangedEvent =  "' + currentItemChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentRowChangedEvent =  "' + currentRowChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentTextChangedEvent =  "' + currentTextChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemActivatedEvent =  "' + itemActivatedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemChangedEvent =  "' + itemChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemClickedEvent =  "' + itemClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemDoubleClickedEvent =  "' + itemDoubleClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemEnteredEvent =  "' + itemEnteredEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemPressedEvent =  "' + itemPressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemSelectionChangedEvent =  "' + itemSelectionChangedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if cItemsValue() != NULL {
			aItems = split(cItemsValue(),",")
			for item in aItems {
				cOutput += 'AddItem("#{f1}")' + nl
				cOutput = substr(cOutput,"#{f1}",Item)
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

class FormDesigner_QCheckBox from QCheckBox

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cstateChangedEvent = ""
	cclickedEvent = ""
	cpressedEvent = ""
	creleasedEvent = ""
	ctoggledEvent = ""

	func SetstateChangedEventCode cValue
		cstateChangedEvent = cValue

	func stateChangedEventCode
		return cstateChangedEvent
			
	func SetclickedEventCode cValue
		cclickedEvent = cValue

	func clickedEventCode
		return cclickedEvent
			
	func SetpressedEventCode cValue
		cpressedEvent = cValue

	func pressedEventCode
		return cpressedEvent
			
	func SetreleasedEventCode cValue
		creleasedEvent = cValue

	func releasedEventCode
		return creleasedEvent
			
	func SettoggledEventCode cValue
		ctoggledEvent = cValue

	func toggledEventCode
		return ctoggledEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Text",False)
		oDesigner.oView.AddProperty("stateChangedEvent",False)
		oDesigner.oView.AddProperty("clickedEvent",False)
		oDesigner.oView.AddProperty("pressedEvent",False)
		oDesigner.oView.AddProperty("releasedEvent",False)
		oDesigner.oView.AddProperty("toggledEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(text())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(stateChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(clickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(pressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(releasedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(toggledEventcode())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON 
					setText(cValue)
				case C_AFTERCOMMON+1
					setstateChangedEventCode(cValue)
				case C_AFTERCOMMON+2
					setclickedEventCode(cValue)
				case C_AFTERCOMMON+3
					setpressedEventCode(cValue)
				case C_AFTERCOMMON+4
					setreleasedEventCode(cValue)
				case C_AFTERCOMMON+5
					settoggledEventCode(cValue)
			}
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :text =  "' + Text() + '"'
		cOutput += "," + nl + cTabs + ' :setstateChangedEvent =  "' + stateChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setclickedEvent =  "' + clickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setpressedEvent =  "' + pressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setreleasedEvent =  "' + releasedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :settoggledEvent =  "' + toggledEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setText("#{f1}")' + nl 
		cOutput = substr(cOutput,"#{f1}",text())
		cOutput += 'setstateChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,stateChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",stateChangedEventCode())
		cOutput += 'setclickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,clickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",clickedEventCode())
		cOutput += 'setpressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,pressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",pressedEventCode())
		cOutput += 'setreleasedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,releasedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",releasedEventCode())
		cOutput += 'settoggledEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,toggledEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",toggledEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setText(itemdata[:text])
		SetstateChangedEventCode(itemdata[:setstateChangedEvent])
		SetclickedEventCode(itemdata[:setclickedEvent])
		SetpressedEventCode(itemdata[:setpressedEvent])
		SetreleasedEventCode(itemdata[:setreleasedEvent])
		SettoggledEventCode(itemdata[:settoggledEvent])

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
		oDesigner.oView.AddProperty("Image File",True)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Set the Image File
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(ImageFile())
			setpixmap(new qpixmap(ImageFile()))
		oPropertiesTable.Blocksignals(False) 
		# Set the object name 
			if cImageFile = NULL {
				setText(oDesigner.oModel.GetObjectName(self))
			}

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON { 
			setImageFile(cValue)
			setpixmap(new qpixmap(ImageFile()))
		}
		# Set the object name 
			if cImageFile = NULL {
				setText(oDesigner.oModel.GetObjectName(self))
			}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :imagefile =  "' + ImageFile() + '"'
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setImageFile(itemdata[:imagefile])
		DisplayProperties(oDesigner)

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setPixMap(New qPixMap("#{f1}"))' + nl
		cOutput = substr(cOutput,"#{f1}",ImageFile())
		return cOutput

	func DialogButtonAction oDesigner,nRow 
		CommonDialogButtonAction(oDesigner,nRow)
		if nRow = C_AFTERCOMMON {	# Image File
			cFile = oDesigner.oGeneral.SelectFile(oDesigner)
			setImageFile(cFile)
			DisplayProperties(oDesigner)
		}

class FormDesigner_QSlider from QSlider

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nOrientation = 0

	cMinimum = ""
	cMaximum = ""
	cRange = ""
	cValue = ""

	cactionTriggeredEvent = ""
	crangeChangedEvent = ""
	csliderMovedEvent = ""
	csliderPressedEvent = ""
	csliderReleasedEvent = ""
	cvalueChangedEvent = ""

	func OrientationValue
		return nOrientation

	func SetOrientationValue nIndex
		nOrientation = nIndex
		setOrientation(nIndex)

	func MinimumValue
		return cMinimum

	func SetMinimumValue Value
		cMinimum = Value 

	func MaximumValue
		return cMaximum

	func SetMaximumValue Value
		cMaximum = Value 

	func RangeValue
		return cRange

	func SetRangeValue Value
		cRange = Value 

	func ValueValue
		return cValue

	func SetValueValue Value
		cValue = Value 

	func SetactionTriggeredEventCode cValue
		cactionTriggeredEvent = cValue

	func actionTriggeredEventCode
		return cactionTriggeredEvent
			
	func SetrangeChangedEventCode cValue
		crangeChangedEvent = cValue

	func rangeChangedEventCode
		return crangeChangedEvent
			
	func SetsliderMovedEventCode cValue
		csliderMovedEvent = cValue

	func sliderMovedEventCode
		return csliderMovedEvent
			
	func SetsliderPressedEventCode cValue
		csliderPressedEvent = cValue

	func sliderPressedEventCode
		return csliderPressedEvent
			
	func SetsliderReleasedEventCode cValue
		csliderReleasedEvent = cValue

	func sliderReleasedEventCode
		return csliderReleasedEvent
			
	func SetvalueChangedEventCode cValue
		cvalueChangedEvent = cValue

	func valueChangedEventCode
		return cvalueChangedEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox("Set Orientation",["Vertical","Horizontal"])
		oDesigner.oView.AddProperty("Set Minimum",False)
		oDesigner.oView.AddProperty("Set Maximum",False)
		oDesigner.oView.AddProperty("Set Range",False)
		oDesigner.oView.AddProperty("Set Value",False)
		oDesigner.oView.AddProperty("actionTriggeredEvent",False)
		oDesigner.oView.AddProperty("rangeChangedEvent",False)
		oDesigner.oView.AddProperty("sliderMovedEvent",False)
		oDesigner.oView.AddProperty("sliderPressedEvent",False)
		oDesigner.oView.AddProperty("sliderReleasedEvent",False)
		oDesigner.oView.AddProperty("valueChangedEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Orientation
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(OrientationValue())
			oCombo.BlockSignals(False)
		# Minimum, Maximum, Range and Value 
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(MinimumValue())
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(MaximumValue())
			oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(RangeValue())
			oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(ValueValue())
		# Events 
			oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(actionTriggeredEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(rangeChangedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+7,1).settext(sliderMovedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+8,1).settext(sliderPressedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+9,1).settext(sliderReleasedEventcode())
			oPropertiesTable.item(C_AFTERCOMMON+10,1).settext(valueChangedEventcode())
		oPropertiesTable.Blocksignals(False)

	func ComboItemAction oDesigner,nRow
		nOrientationPos = C_AFTERCOMMON
		if nRow = nOrientationPos  {		# Orientation
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nOrientationPos,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			nIndex = oCombo.CurrentIndex()
			setOrientationValue(nIndex)
		}

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON+1
					setMinimumValue(cValue)
				case C_AFTERCOMMON+2
					setMaximumValue(cValue)
				case C_AFTERCOMMON+3
					setRangeValue(cValue)
				case C_AFTERCOMMON+4
					setValueValue(cValue)
				case C_AFTERCOMMON+5
					setactionTriggeredEventCode(cValue)
				case C_AFTERCOMMON+6
					setrangeChangedEventCode(cValue)
				case C_AFTERCOMMON+7
					setsliderMovedEventCode(cValue)
				case C_AFTERCOMMON+8
					setsliderPressedEventCode(cValue)
				case C_AFTERCOMMON+9
					setsliderReleasedEventCode(cValue)
				case C_AFTERCOMMON+10
					setvalueChangedEventCode(cValue)
			}
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :orientation =  ' + OrientationValue() 
		cOutput += "," + nl + cTabs + ' :minimum =  "' + MinimumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :maximum =  "' + MaximumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :range =  "' + RangeValue()  + '"'
		cOutput += "," + nl + cTabs + ' :value =  "' + ValueValue()  + '"'
		cOutput += "," + nl + cTabs + ' :setactionTriggeredEvent =  "' + actionTriggeredEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setrangeChangedEvent =  "' + rangeChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setsliderMovedEvent =  "' + sliderMovedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setsliderPressedEvent =  "' + sliderPressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setsliderReleasedEvent =  "' + sliderReleasedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setvalueChangedEvent =  "' + valueChangedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setOrientation(#{f1})' + nl
		cOutput = substr(cOutput,"#{f1}",""+OrientationValue())
		if Minimumvalue() != NULL {
			cOutput += 'setMinimum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MinimumValue())
		}
		if Maximumvalue() != NULL {
			cOutput += 'setMaximum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MaximumValue())
		}
		if Rangevalue() != NULL {
			cOutput += 'setRange(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+RangeValue())
		}
		if ValueValue() != NULL {
			cOutput += 'setValue(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+ValueValue())
		}
		cOutput += 'setactionTriggeredEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,actionTriggeredEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",actionTriggeredEventCode())
		cOutput += 'setrangeChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,rangeChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",rangeChangedEventCode())
		cOutput += 'setsliderMovedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,sliderMovedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",sliderMovedEventCode())
		cOutput += 'setsliderPressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,sliderPressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",sliderPressedEventCode())
		cOutput += 'setsliderReleasedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,sliderReleasedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",sliderReleasedEventCode())
		cOutput += 'setvalueChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,valueChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",valueChangedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setOrientationValue(0+itemdata[:orientation])
		setMinimumValue(itemdata[:minimum])
		setMaximumValue(itemdata[:maximum])
		setRangeValue(itemdata[:range])
		setValueValue(itemdata[:value])
		SetactionTriggeredEventCode(itemdata[:setactionTriggeredEvent])
		SetrangeChangedEventCode(itemdata[:setrangeChangedEvent])
		SetsliderMovedEventCode(itemdata[:setsliderMovedEvent])
		SetsliderPressedEventCode(itemdata[:setsliderPressedEvent])
		SetsliderReleasedEventCode(itemdata[:setsliderReleasedEvent])
		SetvalueChangedEventCode(itemdata[:setvalueChangedEvent])

class FormDesigner_QProgressbar from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nOrientation = 0

	cMinimum = ""
	cMaximum = ""
	cRange = ""
	cValue = ""

	cvalueChangedEvent = ""

	func OrientationValue
		return nOrientation

	func SetOrientationValue nIndex
		nOrientation = nIndex

	func MinimumValue
		return cMinimum

	func SetMinimumValue Value
		cMinimum = Value 

	func MaximumValue
		return cMaximum

	func SetMaximumValue Value
		cMaximum = Value 

	func RangeValue
		return cRange

	func SetRangeValue Value
		cRange = Value 

	func ValueValue
		return cValue

	func SetValueValue Value
		cValue = Value 

	func SetvalueChangedEventCode cValue
		cvalueChangedEvent = cValue

	func valueChangedEventCode
		return cvalueChangedEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox("Set Orientation",["Horizontal","Vertical"])
		oDesigner.oView.AddProperty("Set Minimum",False)
		oDesigner.oView.AddProperty("Set Maximum",False)
		oDesigner.oView.AddProperty("Set Range",False)
		oDesigner.oView.AddProperty("Set Value",False)
		oDesigner.oView.AddProperty("valueChangedEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Orientation
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(OrientationValue())
			oCombo.BlockSignals(False)
		# Minimum, Maximum, Range and Value 
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(MinimumValue())
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(MaximumValue())
			oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(RangeValue())
			oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(ValueValue())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(valueChangedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ComboItemAction oDesigner,nRow
		nOrientationPos = C_AFTERCOMMON
		if nRow = nOrientationPos  {		# Orientation
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nOrientationPos,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			nIndex = oCombo.CurrentIndex()
			setOrientationValue(nIndex)
		}

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON+1
					setMinimumValue(cValue)
				case C_AFTERCOMMON+2
					setMaximumValue(cValue)
				case C_AFTERCOMMON+3
					setRangeValue(cValue)
				case C_AFTERCOMMON+4
					setValueValue(cValue)
				case C_AFTERCOMMON+5
					setvalueChangedEventCode(cValue)

			}
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :orientation =  ' + OrientationValue() 
		cOutput += "," + nl + cTabs + ' :minimum =  "' + MinimumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :maximum =  "' + MaximumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :range =  "' + RangeValue()  + '"'
		cOutput += "," + nl + cTabs + ' :value =  "' + ValueValue()  + '"'
		cOutput += "," + nl + cTabs + ' :setvalueChangedEvent =  "' + valueChangedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setOrientation(#{f1})' + nl
		cOutput = substr(cOutput,"#{f1}",""+(OrientationValue()+1))
		if Minimumvalue() != NULL {
			cOutput += 'setMinimum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MinimumValue())
		}
		if Maximumvalue() != NULL {
			cOutput += 'setMaximum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MaximumValue())
		}
		if Rangevalue() != NULL {
			cOutput += 'setRange(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+RangeValue())
		}
		if ValueValue() != NULL {
			cOutput += 'setValue(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+ValueValue())
		}
		cOutput += 'setvalueChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,valueChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",valueChangedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setOrientationValue(0+itemdata[:orientation])
		setMinimumValue(itemdata[:minimum])
		setMaximumValue(itemdata[:maximum])
		setRangeValue(itemdata[:range])
		setValueValue(itemdata[:value])
		SetvalueChangedEventCode(itemdata[:setvalueChangedEvent])

class FormDesigner_QSpinBox from QLineEdit 

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cMinimum = ""
	cMaximum = ""
	cRange = ""
	cValue = ""

	cvalueChangedEvent = ""

	func MinimumValue
		return cMinimum

	func SetMinimumValue Value
		cMinimum = Value 

	func MaximumValue
		return cMaximum

	func SetMaximumValue Value
		cMaximum = Value 

	func RangeValue
		return cRange

	func SetRangeValue Value
		cRange = Value 

	func ValueValue
		return cValue

	func SetValueValue Value
		cValue = Value 

	func SetvalueChangedEventCode cValue
		cvalueChangedEvent = cValue

	func valueChangedEventCode
		return cvalueChangedEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Set Minimum",False)
		oDesigner.oView.AddProperty("Set Maximum",False)
		oDesigner.oView.AddProperty("Set Range",False)
		oDesigner.oView.AddProperty("Set Value",False)
		oDesigner.oView.AddProperty("valueChangedEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Minimum, Maximum, Range and Value 
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(MinimumValue())
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(MaximumValue())
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(RangeValue())
			oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(ValueValue())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(valueChangedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setMinimumValue(cValue)
				case C_AFTERCOMMON+1
					setMaximumValue(cValue)
				case C_AFTERCOMMON+2
					setRangeValue(cValue)
				case C_AFTERCOMMON+3
					setValueValue(cValue)
				case C_AFTERCOMMON+4
					setvalueChangedEventCode(cValue)
			}
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :minimum =  "' + MinimumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :maximum =  "' + MaximumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :range =  "' + RangeValue()  + '"'
		cOutput += "," + nl + cTabs + ' :value =  "' + ValueValue()  + '"'
		cOutput += "," + nl + cTabs + ' :setvalueChangedEvent =  "' + valueChangedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if Minimumvalue() != NULL {
			cOutput += 'setMinimum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MinimumValue())
		}
		if Maximumvalue() != NULL {
			cOutput += 'setMaximum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MaximumValue())
		}
		if Rangevalue() != NULL {
			cOutput += 'setRange(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+RangeValue())
		}
		if ValueValue() != NULL {
			cOutput += 'setValue(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+ValueValue())
		}
		cOutput += 'setvalueChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,valueChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",valueChangedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setMinimumValue(itemdata[:minimum])
		setMaximumValue(itemdata[:maximum])
		setRangeValue(itemdata[:range])
		setValueValue(itemdata[:value])
		SetvalueChangedEventCode(itemdata[:setvalueChangedEvent])

class FormDesigner_QComboBox from QComboBox

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cItems = ""
	cCurrentIndex  = ""

	cactivatedEvent = ""
	ccurrentIndexChangedEvent = ""
	ceditTextChangedEvent = ""
	chighlightedEvent = ""

	func SetcItems cValue
		cItems = cValue

	func cItemsValue
		return cItems

	func setcCurrentIndex cValue
		cCurrentIndex = cValue
	
	func cCurrentIndexValue
		return cCurrentIndex

	func SetactivatedEventCode cValue
		cactivatedEvent = cValue

	func activatedEventCode
		return cactivatedEvent
			
	func SetcurrentIndexChangedEventCode cValue
		ccurrentIndexChangedEvent = cValue

	func currentIndexChangedEventCode
		return ccurrentIndexChangedEvent
			
	func SeteditTextChangedEventCode cValue
		ceditTextChangedEvent = cValue

	func editTextChangedEventCode
		return ceditTextChangedEvent
			
	func SethighlightedEventCode cValue
		chighlightedEvent = cValue

	func highlightedEventCode
		return chighlightedEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Items (S: Comma)",False)
		oDesigner.oView.AddProperty("Current Index",False)
		oDesigner.oView.AddProperty("activatedEvent",False)
		oDesigner.oView.AddProperty("currentIndexChangedEvent",False)
		oDesigner.oView.AddProperty("editTextChangedEvent",False)
		oDesigner.oView.AddProperty("highlightedEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		oPropertiesTable.item(C_AFTERCOMMON,1).settext(cItemsValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(cCurrentIndexValue())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(activatedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(currentIndexChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(editTextChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(highlightedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			clear() AddItem(oDesigner.oModel.GetObjectName(self),0)


	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setcItems(cValue)
				case C_AFTERCOMMON+1
					setcCurrentIndex(cValue)
				case C_AFTERCOMMON+2
					setactivatedEventCode(cValue)
				case C_AFTERCOMMON+3
					setcurrentIndexChangedEventCode(cValue)
				case C_AFTERCOMMON+4
					seteditTextChangedEventCode(cValue)
				case C_AFTERCOMMON+5
					sethighlightedEventCode(cValue)
			}
		}
		# Set the object name 
			clear() AddItem(oDesigner.oModel.GetObjectName(self),0)


	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :cItems =  "' + cItemsValue() + '"'
		cOutput += "," + nl + cTabs + ' :cCurrentIndex =  "' + cCurrentIndexValue() + '"'
		cOutput += "," + nl + cTabs + ' :setactivatedEvent =  "' + activatedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentIndexChangedEvent =  "' + currentIndexChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :seteditTextChangedEvent =  "' + editTextChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :sethighlightedEvent =  "' + highlightedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if cItemsValue() != NULL {
			aItems = split(cItemsValue(),",")
			for item in aItems {
				cOutput += 'AddItem("#{f1}",0)' + nl
				cOutput = substr(cOutput,"#{f1}",Item)
			}
		}
		if cCurrentIndexValue() != NULL {
			cOutput += 'setcurrentIndex(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",ccurrentIndexValue())
		}
		cOutput += 'setactivatedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,activatedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",activatedEventCode())
		cOutput += 'setcurrentIndexChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,currentIndexChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",currentIndexChangedEventCode())
		cOutput += 'seteditTextChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,editTextChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",editTextChangedEventCode())
		cOutput += 'sethighlightedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,highlightedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",highlightedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		SetcItems(itemdata[:cItems])
		SetcCurrentIndex(itemdata[:cCurrentIndex])
		SetactivatedEventCode(itemdata[:setactivatedEvent])
		SetcurrentIndexChangedEventCode(itemdata[:setcurrentIndexChangedEvent])
		SeteditTextChangedEventCode(itemdata[:seteditTextChangedEvent])
		SethighlightedEventCode(itemdata[:sethighlightedEvent])

class FormDesigner_QDateTimeEdit from QLineEdit 

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))


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
		oDesigner.oView.AddProperty("Row Count",False)
		oDesigner.oView.AddProperty("Column Count",False)
		oDesigner.oView.AddProperty("Horizontal Headers (S: Comma)",False)
		oDesigner.oView.AddProperty("Columns Width (S: Comma)",False)
		oDesigner.oView.AddProperty("Horizontal Header Style",False)
		oDesigner.oView.AddProperty("Vertical Header Style",False)
		oDesigner.oView.AddPropertyCombobox("Selection Behavior",["Items","Rows","Columns"])
		oDesigner.oView.AddPropertyCombobox("Alternating Row Colors",["True","False"])
		oDesigner.oView.AddProperty("cellActivatedEvent",False)
		oDesigner.oView.AddProperty("cellChangedEvent",False)
		oDesigner.oView.AddProperty("cellClickedEvent",False)
		oDesigner.oView.AddProperty("cellDoubleClickedEvent",False)
		oDesigner.oView.AddProperty("cellEnteredEvent",False)
		oDesigner.oView.AddProperty("cellPressedEvent",False)
		oDesigner.oView.AddProperty("currentCellChangedEvent",False)
		oDesigner.oView.AddProperty("currentItemChangedEvent",False)
		oDesigner.oView.AddProperty("itemActivatedEvent",False)
		oDesigner.oView.AddProperty("itemChangedEvent",False)
		oDesigner.oView.AddProperty("itemClickedEvent",False)
		oDesigner.oView.AddProperty("itemDoubleClickedEvent",False)
		oDesigner.oView.AddProperty("itemEnteredEvent",False)
		oDesigner.oView.AddProperty("itemPressedEvent",False)
		oDesigner.oView.AddProperty("itemSelectionChangedEvent",False)

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
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :RowCount =  "' + RowCountValue() + '"'
		cOutput += "," + nl + cTabs + ' :ColumnCount =  "' + ColumnCountValue() + '"'
		cOutput += "," + nl + cTabs + ' :HorizontalHeaders =  "' + HorizontalHeadersValue() + '"'
		cOutput += "," + nl + cTabs + ' :ColumnsWidth =  "' + ColumnsWidthValue() + '"'
		cOutput += "," + nl + cTabs + ' :HorizontalHeaderStyle =  "' + HorizontalHeaderStyleValue() + '"'
		cOutput += "," + nl + cTabs + ' :VerticalHeaderStyle =  "' + VerticalHeaderStyleValue() + '"'
		cOutput += "," + nl + cTabs + ' :selectionbehavior =  ' + SelectionBahviorValue() 
		cOutput += "," + nl + cTabs + ' :alternatingcolors =  ' + AlternatingColorsValue() 
		cOutput += "," + nl + cTabs + ' :setcellActivatedEvent =  "' + cellActivatedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcellChangedEvent =  "' + cellChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcellClickedEvent =  "' + cellClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcellDoubleClickedEvent =  "' + cellDoubleClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcellEnteredEvent =  "' + cellEnteredEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcellPressedEvent =  "' + cellPressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentCellChangedEvent =  "' + currentCellChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentItemChangedEvent =  "' + currentItemChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemActivatedEvent =  "' + itemActivatedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemChangedEvent =  "' + itemChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemClickedEvent =  "' + itemClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemDoubleClickedEvent =  "' + itemDoubleClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemEnteredEvent =  "' + itemEnteredEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemPressedEvent =  "' + itemPressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemSelectionChangedEvent =  "' + itemSelectionChangedEventCode() + '"'
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
			nPos = 0
			for item in aTempList {
				cOutput += 'setHorizontalHeaderItem(#{f1}, new QTableWidgetItem("#{f2}"))' + nl
				cOutput = substr(cOutput,"#{f1}",""+nPos)
				cOutput = substr(cOutput,"#{f2}",item)
				nPos++
			}
		}
		if ColumnsWidthValue() != NULL {
			aTempList = Split(ColumnsWidthValue(),",")
			nPos = 0
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

class FormDesigner_QTreeWidget from QLineEdit

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cColumnCount = "0"
	cHeaderLabels = ""
	nHeaderHidden = 0

	ccollapsedEvent = ""
	cexpandedEvent = ""
	cactivatedEvent = ""
	cclickedEvent = ""
	cdoubleClickedEvent = ""
	centeredEvent = ""
	cpressedEvent = ""
	cviewportEnteredEvent = ""
	ccurrentItemChangedEvent = ""
	citemActivatedEvent = ""
	citemChangedEvent = ""
	citemClickedEvent = ""
	citemCollapsedEvent = ""
	citemDoubleClickedEvent = ""
	citemEnteredEvent = ""
	citemExpandedEvent = ""
	citemPressedEvent = ""
	citemSelectionChangedEvent = ""

	func SetColumnCountValue cValue
		cColumnCount = cValue

	func ColumnCountValue 
		return cColumnCount

	func SetHeaderLabelsValue cValue
		cHeaderLabels = cValue

	func HeaderLabelsValue
		return cHeaderLabels

	func HeaderHiddenValue
		return nHeaderHidden

	func SetHeaderHiddenValue Value 
		nHeaderHidden = Value 

	func SetcollapsedEventCode cValue
		ccollapsedEvent = cValue

	func collapsedEventCode
		return ccollapsedEvent
			
	func SetexpandedEventCode cValue
		cexpandedEvent = cValue

	func expandedEventCode
		return cexpandedEvent
			
	func SetactivatedEventCode cValue
		cactivatedEvent = cValue

	func activatedEventCode
		return cactivatedEvent
			
	func SetclickedEventCode cValue
		cclickedEvent = cValue

	func clickedEventCode
		return cclickedEvent
			
	func SetdoubleClickedEventCode cValue
		cdoubleClickedEvent = cValue

	func doubleClickedEventCode
		return cdoubleClickedEvent
			
	func SetenteredEventCode cValue
		centeredEvent = cValue

	func enteredEventCode
		return centeredEvent
			
	func SetpressedEventCode cValue
		cpressedEvent = cValue

	func pressedEventCode
		return cpressedEvent
			
	func SetviewportEnteredEventCode cValue
		cviewportEnteredEvent = cValue

	func viewportEnteredEventCode
		return cviewportEnteredEvent
			
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
			
	func SetitemCollapsedEventCode cValue
		citemCollapsedEvent = cValue

	func itemCollapsedEventCode
		return citemCollapsedEvent
			
	func SetitemDoubleClickedEventCode cValue
		citemDoubleClickedEvent = cValue

	func itemDoubleClickedEventCode
		return citemDoubleClickedEvent
			
	func SetitemEnteredEventCode cValue
		citemEnteredEvent = cValue

	func itemEnteredEventCode
		return citemEnteredEvent
			
	func SetitemExpandedEventCode cValue
		citemExpandedEvent = cValue

	func itemExpandedEventCode
		return citemExpandedEvent
			
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
		oDesigner.oView.AddProperty("Column Count",False)
		oDesigner.oView.AddProperty("Header Labels (S: Comma)",False)
		oDesigner.oView.AddPropertyCombobox("Header Hidden",["True","False"])
		oDesigner.oView.AddProperty("collapsedEvent",False)
		oDesigner.oView.AddProperty("expandedEvent",False)
		oDesigner.oView.AddProperty("activatedEvent",False)
		oDesigner.oView.AddProperty("clickedEvent",False)
		oDesigner.oView.AddProperty("doubleClickedEvent",False)
		oDesigner.oView.AddProperty("enteredEvent",False)
		oDesigner.oView.AddProperty("pressedEvent",False)
		oDesigner.oView.AddProperty("viewportEnteredEvent",False)
		oDesigner.oView.AddProperty("currentItemChangedEvent",False)
		oDesigner.oView.AddProperty("itemActivatedEvent",False)
		oDesigner.oView.AddProperty("itemChangedEvent",False)
		oDesigner.oView.AddProperty("itemClickedEvent",False)
		oDesigner.oView.AddProperty("itemCollapsedEvent",False)
		oDesigner.oView.AddProperty("itemDoubleClickedEvent",False)
		oDesigner.oView.AddProperty("itemEnteredEvent",False)
		oDesigner.oView.AddProperty("itemExpandedEvent",False)
		oDesigner.oView.AddProperty("itemPressedEvent",False)
		oDesigner.oView.AddProperty("itemSelectionChangedEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		oPropertiesTable.item(C_AFTERCOMMON,1).settext(ColumnCountValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(HeaderLabelsValue())
		# Header Hidden
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON+2,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(HeaderHiddenValue())
			oCombo.BlockSignals(False)
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(collapsedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(expandedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(activatedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(clickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+7,1).settext(doubleClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+8,1).settext(enteredEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+9,1).settext(pressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+10,1).settext(viewportEnteredEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+11,1).settext(currentItemChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+12,1).settext(itemActivatedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+13,1).settext(itemChangedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+14,1).settext(itemClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+15,1).settext(itemCollapsedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+16,1).settext(itemDoubleClickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+17,1).settext(itemEnteredEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+18,1).settext(itemExpandedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+19,1).settext(itemPressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+20,1).settext(itemSelectionChangedEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setColumnCountValue(cValue)
				case C_AFTERCOMMON+1
					setHeaderLabelsValue(cValue)
				case C_AFTERCOMMON+2
					setHeaderHiddenValue(cValue)
				case C_AFTERCOMMON+3
					setcollapsedEventCode(cValue)
				case C_AFTERCOMMON+4
					setexpandedEventCode(cValue)
				case C_AFTERCOMMON+5
					setactivatedEventCode(cValue)
				case C_AFTERCOMMON+6
					setclickedEventCode(cValue)
				case C_AFTERCOMMON+7
					setdoubleClickedEventCode(cValue)
				case C_AFTERCOMMON+8
					setenteredEventCode(cValue)
				case C_AFTERCOMMON+9
					setpressedEventCode(cValue)
				case C_AFTERCOMMON+10
					setviewportEnteredEventCode(cValue)
				case C_AFTERCOMMON+11
					setcurrentItemChangedEventCode(cValue)
				case C_AFTERCOMMON+12
					setitemActivatedEventCode(cValue)
				case C_AFTERCOMMON+13
					setitemChangedEventCode(cValue)
				case C_AFTERCOMMON+14
					setitemClickedEventCode(cValue)
				case C_AFTERCOMMON+15
					setitemCollapsedEventCode(cValue)
				case C_AFTERCOMMON+16
					setitemDoubleClickedEventCode(cValue)
				case C_AFTERCOMMON+17
					setitemEnteredEventCode(cValue)
				case C_AFTERCOMMON+18
					setitemExpandedEventCode(cValue)
				case C_AFTERCOMMON+19
					setitemPressedEventCode(cValue)
				case C_AFTERCOMMON+20
					setitemSelectionChangedEventCode(cValue)

			}
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ComboItemAction oDesigner,nRow
		nHeaderHiddenPos = C_AFTERCOMMON+2
		if nRow = nHeaderHiddenPos  {		 
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nHeaderHiddenPos,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			nIndex = oCombo.CurrentIndex()
			setHeaderHiddenValue(nIndex)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :columncount =  "' + ColumnCountValue() + '"'
		cOutput += "," + nl + cTabs + ' :headerlabels =  "' + HeaderLabelsValue() + '"'
		cOutput += "," + nl + cTabs + ' :HeaderHidden =  ' + HeaderHiddenValue() 
		cOutput += "," + nl + cTabs + ' :setcollapsedEvent =  "' + collapsedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setexpandedEvent =  "' + expandedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setactivatedEvent =  "' + activatedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setclickedEvent =  "' + clickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setdoubleClickedEvent =  "' + doubleClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setenteredEvent =  "' + enteredEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setpressedEvent =  "' + pressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setviewportEnteredEvent =  "' + viewportEnteredEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setcurrentItemChangedEvent =  "' + currentItemChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemActivatedEvent =  "' + itemActivatedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemChangedEvent =  "' + itemChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemClickedEvent =  "' + itemClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemCollapsedEvent =  "' + itemCollapsedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemDoubleClickedEvent =  "' + itemDoubleClickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemEnteredEvent =  "' + itemEnteredEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemExpandedEvent =  "' + itemExpandedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemPressedEvent =  "' + itemPressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setitemSelectionChangedEvent =  "' + itemSelectionChangedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'setColumnCount(#{f1})' + nl
		cOutput = substr(cOutput,"#{f1}",ColumnCountValue())
		if HeaderLabelsValue() != NULL {
			cOutput += 'oList = new qstringlist() {' + nl
			aItems = split(HeaderLabelsValue(),",")
			for item in aItems {
				cOutput += char(9) + 'Append("#{f1}")' + nl
				cOutput = substr(cOutput,"#{f1}",Item)
			}
			cOutput += '}' + nl +"setheaderlabels(oList)" + nl
		}
		# Header Hidden
			cOutput += 'setHeaderHidden(#{f1})' + nl
			switch HeaderHiddenValue() {
			case 0
				cOutput = substr(cOutput,"#{f1}","True")
			case 1
				cOutput = substr(cOutput,"#{f1}","False")
			}
		cOutput += 'setcollapsedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,collapsedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",collapsedEventCode())
		cOutput += 'setexpandedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,expandedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",expandedEventCode())
		cOutput += 'setactivatedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,activatedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",activatedEventCode())
		cOutput += 'setclickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,clickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",clickedEventCode())
		cOutput += 'setdoubleClickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,doubleClickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",doubleClickedEventCode())
		cOutput += 'setenteredEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,enteredEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",enteredEventCode())
		cOutput += 'setpressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,pressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",pressedEventCode())
		cOutput += 'setviewportEnteredEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,viewportEnteredEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",viewportEnteredEventCode())
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
		cOutput += 'setitemCollapsedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemCollapsedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemCollapsedEventCode())
		cOutput += 'setitemDoubleClickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemDoubleClickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemDoubleClickedEventCode())
		cOutput += 'setitemEnteredEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemEnteredEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemEnteredEventCode())
		cOutput += 'setitemExpandedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,itemExpandedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",itemExpandedEventCode())
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
		SetColumnCountValue(itemdata[:columncount])
		SetHeaderLabelsValue(itemdata[:headerlabels])
		SetHeaderHiddenValue(itemdata[:HeaderHidden])
		SetcollapsedEventCode(itemdata[:setcollapsedEvent])
		SetexpandedEventCode(itemdata[:setexpandedEvent])
		SetactivatedEventCode(itemdata[:setactivatedEvent])
		SetclickedEventCode(itemdata[:setclickedEvent])
		SetdoubleClickedEventCode(itemdata[:setdoubleClickedEvent])
		SetenteredEventCode(itemdata[:setenteredEvent])
		SetpressedEventCode(itemdata[:setpressedEvent])
		SetviewportEnteredEventCode(itemdata[:setviewportEnteredEvent])
		SetcurrentItemChangedEventCode(itemdata[:setcurrentItemChangedEvent])
		SetitemActivatedEventCode(itemdata[:setitemActivatedEvent])
		SetitemChangedEventCode(itemdata[:setitemChangedEvent])
		SetitemClickedEventCode(itemdata[:setitemClickedEvent])
		SetitemCollapsedEventCode(itemdata[:setitemCollapsedEvent])
		SetitemDoubleClickedEventCode(itemdata[:setitemDoubleClickedEvent])
		SetitemEnteredEventCode(itemdata[:setitemEnteredEvent])
		SetitemExpandedEventCode(itemdata[:setitemExpandedEvent])
		SetitemPressedEventCode(itemdata[:setitemPressedEvent])
		SetitemSelectionChangedEventCode(itemdata[:setitemSelectionChangedEvent])

class FormDesigner_QRadioButton from QRadioButton

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cclickedEvent = ""
	cpressedEvent = ""
	creleasedEvent = ""
	ctoggledEvent = ""

	func SetclickedEventCode cValue
		cclickedEvent = cValue

	func clickedEventCode
		return cclickedEvent
			
	func SetpressedEventCode cValue
		cpressedEvent = cValue

	func pressedEventCode
		return cpressedEvent
			
	func SetreleasedEventCode cValue
		creleasedEvent = cValue

	func releasedEventCode
		return creleasedEvent
			
	func SettoggledEventCode cValue
		ctoggledEvent = cValue

	func toggledEventCode
		return ctoggledEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Text",False)
		oDesigner.oView.AddProperty("clickedEvent",False)
		oDesigner.oView.AddProperty("pressedEvent",False)
		oDesigner.oView.AddProperty("releasedEvent",False)
		oDesigner.oView.AddProperty("toggledEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(text())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(clickedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(pressedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(releasedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(toggledEventcode())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON 
					setText(cValue)
				case C_AFTERCOMMON+1
					setclickedEventCode(cValue)
				case C_AFTERCOMMON+2
					setpressedEventCode(cValue)
				case C_AFTERCOMMON+3
					setreleasedEventCode(cValue)
				case C_AFTERCOMMON+4
					settoggledEventCode(cValue)

			}
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :text =  "' + Text() + '"'
		cOutput += "," + nl + cTabs + ' :setclickedEvent =  "' + clickedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setpressedEvent =  "' + pressedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setreleasedEvent =  "' + releasedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :settoggledEvent =  "' + toggledEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setText("#{f1}")' + nl 
		cOutput = substr(cOutput,"#{f1}",text())
		cOutput += 'setclickedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,clickedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",clickedEventCode())
		cOutput += 'setpressedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,pressedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",pressedEventCode())
		cOutput += 'setreleasedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,releasedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",releasedEventCode())
		cOutput += 'settoggledEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,toggledEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",toggledEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setText(itemdata[:text])
		SetclickedEventCode(itemdata[:setclickedEvent])
		SetpressedEventCode(itemdata[:setpressedEvent])
		SetreleasedEventCode(itemdata[:setreleasedEvent])
		SettoggledEventCode(itemdata[:settoggledEvent])

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
		oDesigner.oView.AddProperty("URL",False)
		oDesigner.oView.AddProperty("loadProgressEvent ",False)
		oDesigner.oView.AddProperty("loadStartedEvent ",False)
		oDesigner.oView.AddProperty("selectionChangedEvent ",False)
		oDesigner.oView.AddProperty("urlChangedEvent ",False)

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
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :URL =  "' + URLValue() + '"'
		cOutput += "," + nl + cTabs + ' :setloadProgressEvent  =  "' + loadProgressEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setloadStartedEvent  =  "' + loadStartedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setselectionChangedEvent  =  "' + selectionChangedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :seturlChangedEvent  =  "' + urlChangedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		cOutput += 'loadpage(new qURL("#{f1}"))' + nl  
		cOutput = substr(cOutput,"#{f1}",URLValue())
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

class FormDesigner_QDial from QDial

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cMinimum = ""
	cMaximum = ""
	cRange = ""
	cValue = ""

	cvalueChangedEvent = ""

	func MinimumValue
		return cMinimum

	func SetMinimumValue Value
		cMinimum = Value 

	func MaximumValue
		return cMaximum

	func SetMaximumValue Value
		cMaximum = Value 

	func RangeValue
		return cRange

	func SetRangeValue Value
		cRange = Value 

	func ValueValue
		return cValue

	func SetValueValue Value
		cValue = Value 

	func SetvalueChangedEventCode cValue
		cvalueChangedEvent = cValue

	func valueChangedEventCode
		return cvalueChangedEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Set Minimum",False)
		oDesigner.oView.AddProperty("Set Maximum",False)
		oDesigner.oView.AddProperty("Set Range",False)
		oDesigner.oView.AddProperty("Set Value",False)
		oDesigner.oView.AddProperty("valueChangedEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		# Minimum, Maximum, Range and Value 
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(MinimumValue())
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(MaximumValue())
			oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(RangeValue())
			oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(ValueValue())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(valueChangedEventcode())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setMinimumValue(cValue)
				case C_AFTERCOMMON+1
					setMaximumValue(cValue)
				case C_AFTERCOMMON+2
					setRangeValue(cValue)
				case C_AFTERCOMMON+3
					setValueValue(cValue)
				case C_AFTERCOMMON+4
					setvalueChangedEventCode(cValue)
			}
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :minimum =  "' + MinimumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :maximum =  "' + MaximumValue()  + '"'
		cOutput += "," + nl + cTabs + ' :range =  "' + RangeValue()  + '"'
		cOutput += "," + nl + cTabs + ' :value =  "' + ValueValue()  + '"'
		cOutput += "," + nl + cTabs + ' :setvalueChangedEvent =  "' + valueChangedEventCode() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if Minimumvalue() != NULL {
			cOutput += 'setMinimum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MinimumValue())
		}
		if Maximumvalue() != NULL {
			cOutput += 'setMaximum(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+MaximumValue())
		}
		if Rangevalue() != NULL {
			cOutput += 'setRange(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+RangeValue())
		}
		if ValueValue() != NULL {
			cOutput += 'setValue(#{f1})' + nl
			cOutput = substr(cOutput,"#{f1}",""+ValueValue())
		}
		cOutput += 'setvalueChangedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,valueChangedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",valueChangedEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setMinimumValue(itemdata[:minimum])
		setMaximumValue(itemdata[:maximum])
		setRangeValue(itemdata[:range])
		setValueValue(itemdata[:value])
		SetvalueChangedEventCode(itemdata[:setvalueChangedEvent])

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
		oDesigner.oView.AddProperty("Video File",True)

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
		cOutput += "," + nl + cTabs + ' :Videofile =  "' + VideoFile() + '"'
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
		cOutput = substr(cOutput,"#{f1}",VideoFile())
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

class FormDesigner_QFrame3 from QFrame3

	nFrameType = 0

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	func FrameType
		return nFrameType

	func SetFrameType nIndex
		nFrameType = nIndex
		Switch nIndex {
			case 0
				setFrameStyle(QFrame_Plain | QFrame_WinPanel )
			case 1
				setFrameStyle(QFrame_Raised | QFrame_WinPanel)			
			case 2
				setFrameStyle(QFrame_Sunken | QFrame_WinPanel)
		}

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox("Frame Style",["Plain","Raised","Sunken"])

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Frame Type
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(nFrameType)
			oCombo.BlockSignals(False)
		oPropertiesTable.Blocksignals(False)
		SetFrameType(nFrameType)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)

	func ComboItemAction oDesigner,nRow
		nFrameStylePos = C_AFTERCOMMON
		if nRow = nFrameStylePos  {		 
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nFrameStylePos,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			nIndex = oCombo.CurrentIndex()
			setFrameType(nIndex)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :FrameType =  ' + FrameType() 
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'setFrameStyle(#{f2})'
		Switch nFrameType {
			case 0
				cOutput = substr(cOutput,"#{f2}","QFrame_Plain | QFrame_WinPanel")
			case 1
				cOutput = substr(cOutput,"#{f2}","QFrame_Raised | QFrame_WinPanel" )			
			case 2
				cOutput = substr(cOutput,"#{f2}","QFrame_Sunken | QFrame_WinPanel" )
		}
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setFrameType(0+itemdata[:FrameType])

class FormDesigner_QLCDNumber from QLCDNumber

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nDisplay  = 0

	func DisplayValue
		return nDisplay

	func SetDisplayValue nValue
		nDisplay = nValue	
		Display(nDisplay)	

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Display",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Display Value
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(""+DisplayValue())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON { 
			setDisplayValue(0+cValue)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :display =  ' + DisplayValue()
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'Display(#{f1})' + nl 
		cOutput = substr(cOutput,"#{f1}",""+DisplayValue())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setDisplayValue(itemdata[:Display])

class FormDesigner_QHyperLink from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cLink = "http://www.ring-lang.net"
	cText = "Ring Language Website"

	func LinkValue
		return cLink

	func SetLinkValue cValue
		cLink = cValue	

	func TextValue
		return cText

	func SetTextValue cValue
		cText = cValue	
		cOutput = '<a href="#{f1}">#{f2}</a>'
		cOutput = substr(cOutput,"#{f1}",LinkValue())
		cOutput = substr(cOutput,"#{f2}",TextValue())
		setText(cOutput)

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Link",False)
		oDesigner.oView.AddProperty("Text",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Link Value
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(LinkValue())
		# Set the Text Value
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(TextValue())
		oPropertiesTable.Blocksignals(False)
		setTextValue(cText) 

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON 
				setLinkValue(cValue)
			case C_AFTERCOMMON + 1
				setTextValue(cValue)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :Link =  "' + LinkValue() + '"'
		cOutput += "," + nl + cTabs + ' :Text =  "' + TextValue() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = `setText('<a href="#{f1}">#{f2}</a>')` + nl 
		cOutput = substr(cOutput,"#{f1}",LinkValue())
		cOutput = substr(cOutput,"#{f2}",TextValue())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setLinkValue(itemdata[:Link])
		setTextValue(itemdata[:Text])

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
		oDesigner.oView.AddProperty("Interval",False)
		oDesigner.oView.AddProperty("Timeout Event",False)

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
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :Interval =  "' + IntervalValue() + '"'
		cOutput += "," + nl + cTabs + ' :Timeout =  "' + TimeoutValue() + '"'
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

class FormDesigner_QAllEvents from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cControlName = "win"

	cKeyPressEvent = ""
	cMouseButtonPressEvent = ""
	cMouseButtonReleaseEvent = ""
	cMouseButtonDblClickEvent = ""
	cMouseMoveEvent = ""
	cCloseEvent = ""
	cContextMenuEvent = ""
	cDragEnterEvent = ""
	cDragLeaveEvent = ""
	cDragMoveEvent = ""
	cDropEvent = ""
	cEnterEvent = ""
	cFocusInEvent = ""
	cFocusOutEvent = ""
	cKeyReleaseEvent = ""
	cLeaveEvent = ""
	cNonClientAreaMouseButtonDblClickEvent = ""
	cNonClientAreaMouseButtonPressEvent = ""
	cNonClientAreaMouseButtonReleaseEvent = ""
	cNonClientAreaMouseMoveEvent = ""
	cMoveEvent = ""
	cResizeEvent = ""
	cWindowActivateEvent = ""
	cWindowBlockedEvent = ""
	cWindowDeactivateEvent = ""
	cWindowStateChangeEvent = ""
	cWindowUnblockedEvent = ""
	cPaintEvent = ""

	func ControlNameValue 
		return cControlName

	func SetControlNameValue  cValue 
		cControlName = cValue

	func SetKeyPressEventCode cValue
		cKeyPressEvent = cValue

	func KeyPressEventCode
		return cKeyPressEvent
			
	func SetMouseButtonPressEventCode cValue
		cMouseButtonPressEvent = cValue

	func MouseButtonPressEventCode
		return cMouseButtonPressEvent
			
	func SetMouseButtonReleaseEventCode cValue
		cMouseButtonReleaseEvent = cValue

	func MouseButtonReleaseEventCode
		return cMouseButtonReleaseEvent
			
	func SetMouseButtonDblClickEventCode cValue
		cMouseButtonDblClickEvent = cValue

	func MouseButtonDblClickEventCode
		return cMouseButtonDblClickEvent
			
	func SetMouseMoveEventCode cValue
		cMouseMoveEvent = cValue

	func MouseMoveEventCode
		return cMouseMoveEvent
			
	func SetCloseEventCode cValue
		cCloseEvent = cValue

	func CloseEventCode
		return cCloseEvent
			
	func SetContextMenuEventCode cValue
		cContextMenuEvent = cValue

	func ContextMenuEventCode
		return cContextMenuEvent
			
	func SetDragEnterEventCode cValue
		cDragEnterEvent = cValue

	func DragEnterEventCode
		return cDragEnterEvent
			
	func SetDragLeaveEventCode cValue
		cDragLeaveEvent = cValue

	func DragLeaveEventCode
		return cDragLeaveEvent
			
	func SetDragMoveEventCode cValue
		cDragMoveEvent = cValue

	func DragMoveEventCode
		return cDragMoveEvent
			
	func SetDropEventCode cValue
		cDropEvent = cValue

	func DropEventCode
		return cDropEvent
			
	func SetEnterEventCode cValue
		cEnterEvent = cValue

	func EnterEventCode
		return cEnterEvent
			
	func SetFocusInEventCode cValue
		cFocusInEvent = cValue

	func FocusInEventCode
		return cFocusInEvent
			
	func SetFocusOutEventCode cValue
		cFocusOutEvent = cValue

	func FocusOutEventCode
		return cFocusOutEvent
			
	func SetKeyReleaseEventCode cValue
		cKeyReleaseEvent = cValue

	func KeyReleaseEventCode
		return cKeyReleaseEvent
			
	func SetLeaveEventCode cValue
		cLeaveEvent = cValue

	func LeaveEventCode
		return cLeaveEvent
			
	func SetNonClientAreaMouseButtonDblClickEventCode cValue
		cNonClientAreaMouseButtonDblClickEvent = cValue

	func NonClientAreaMouseButtonDblClickEventCode
		return cNonClientAreaMouseButtonDblClickEvent
			
	func SetNonClientAreaMouseButtonPressEventCode cValue
		cNonClientAreaMouseButtonPressEvent = cValue

	func NonClientAreaMouseButtonPressEventCode
		return cNonClientAreaMouseButtonPressEvent
			
	func SetNonClientAreaMouseButtonReleaseEventCode cValue
		cNonClientAreaMouseButtonReleaseEvent = cValue

	func NonClientAreaMouseButtonReleaseEventCode
		return cNonClientAreaMouseButtonReleaseEvent
			
	func SetNonClientAreaMouseMoveEventCode cValue
		cNonClientAreaMouseMoveEvent = cValue

	func NonClientAreaMouseMoveEventCode
		return cNonClientAreaMouseMoveEvent
			
	func SetMoveEventCode cValue
		cMoveEvent = cValue

	func MoveEventCode
		return cMoveEvent
			
	func SetResizeEventCode cValue
		cResizeEvent = cValue

	func ResizeEventCode
		return cResizeEvent
			
	func SetWindowActivateEventCode cValue
		cWindowActivateEvent = cValue

	func WindowActivateEventCode
		return cWindowActivateEvent
			
	func SetWindowBlockedEventCode cValue
		cWindowBlockedEvent = cValue

	func WindowBlockedEventCode
		return cWindowBlockedEvent
			
	func SetWindowDeactivateEventCode cValue
		cWindowDeactivateEvent = cValue

	func WindowDeactivateEventCode
		return cWindowDeactivateEvent
			
	func SetWindowStateChangeEventCode cValue
		cWindowStateChangeEvent = cValue

	func WindowStateChangeEventCode
		return cWindowStateChangeEvent
			
	func SetWindowUnblockedEventCode cValue
		cWindowUnblockedEvent = cValue

	func WindowUnblockedEventCode
		return cWindowUnblockedEvent
			
	func SetPaintEventCode cValue
		cPaintEvent = cValue

	func PaintEventCode
		return cPaintEvent
			
	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Control Name",False)
		oDesigner.oView.AddProperty("KeyPressEvent",False)
		oDesigner.oView.AddProperty("MouseButtonPressEvent",False)
		oDesigner.oView.AddProperty("MouseButtonReleaseEvent",False)
		oDesigner.oView.AddProperty("MouseButtonDblClickEvent",False)
		oDesigner.oView.AddProperty("MouseMoveEvent",False)
		oDesigner.oView.AddProperty("CloseEvent",False)
		oDesigner.oView.AddProperty("ContextMenuEvent",False)
		oDesigner.oView.AddProperty("DragEnterEvent",False)
		oDesigner.oView.AddProperty("DragLeaveEvent",False)
		oDesigner.oView.AddProperty("DragMoveEvent",False)
		oDesigner.oView.AddProperty("DropEvent",False)
		oDesigner.oView.AddProperty("EnterEvent",False)
		oDesigner.oView.AddProperty("FocusInEvent",False)
		oDesigner.oView.AddProperty("FocusOutEvent",False)
		oDesigner.oView.AddProperty("KeyReleaseEvent",False)
		oDesigner.oView.AddProperty("LeaveEvent",False)
		oDesigner.oView.AddProperty("NonClientAreaMouseButtonDblClickEvent",False)
		oDesigner.oView.AddProperty("NonClientAreaMouseButtonPressEvent",False)
		oDesigner.oView.AddProperty("NonClientAreaMouseButtonReleaseEvent",False)
		oDesigner.oView.AddProperty("NonClientAreaMouseMoveEvent",False)
		oDesigner.oView.AddProperty("MoveEvent",False)
		oDesigner.oView.AddProperty("ResizeEvent",False)
		oDesigner.oView.AddProperty("WindowActivateEvent",False)
		oDesigner.oView.AddProperty("WindowBlockedEvent",False)
		oDesigner.oView.AddProperty("WindowDeactivateEvent",False)
		oDesigner.oView.AddProperty("WindowStateChangeEvent",False)
		oDesigner.oView.AddProperty("WindowUnblockedEvent",False)
		oDesigner.oView.AddProperty("PaintEvent",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True) 
		oPropertiesTable.item(C_AFTERCOMMON,1).settext(ControlNameValue())
		oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(KeyPressEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+2,1).settext(MouseButtonPressEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+3,1).settext(MouseButtonReleaseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+4,1).settext(MouseButtonDblClickEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+5,1).settext(MouseMoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+6,1).settext(CloseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+7,1).settext(ContextMenuEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+8,1).settext(DragEnterEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+9,1).settext(DragLeaveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+10,1).settext(DragMoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+11,1).settext(DropEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+12,1).settext(EnterEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+13,1).settext(FocusInEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+14,1).settext(FocusOutEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+15,1).settext(KeyReleaseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+16,1).settext(LeaveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+17,1).settext(NonClientAreaMouseButtonDblClickEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+18,1).settext(NonClientAreaMouseButtonPressEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+19,1).settext(NonClientAreaMouseButtonReleaseEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+20,1).settext(NonClientAreaMouseMoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+21,1).settext(MoveEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+22,1).settext(ResizeEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+23,1).settext(WindowActivateEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+24,1).settext(WindowBlockedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+25,1).settext(WindowDeactivateEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+26,1).settext(WindowStateChangeEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+27,1).settext(WindowUnblockedEventcode())
		oPropertiesTable.item(C_AFTERCOMMON+28,1).settext(PaintEventcode())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nCol = 1 {
			switch nRow {
				case C_AFTERCOMMON
					setControlNameValue(cValue)
				case C_AFTERCOMMON+1
					setKeyPressEventCode(cValue)
				case C_AFTERCOMMON+2
					setMouseButtonPressEventCode(cValue)
				case C_AFTERCOMMON+3
					setMouseButtonReleaseEventCode(cValue)
				case C_AFTERCOMMON+4
					setMouseButtonDbllickEventCode(cValue)
				case C_AFTERCOMMON+5
					setMouseMoveEventCode(cValue)
				case C_AFTERCOMMON+6
					setCloseEventCode(cValue)
				case C_AFTERCOMMON+7
					setContextMenuEventCode(cValue)
				case C_AFTERCOMMON+8
					setDragEnterEventCode(cValue)
				case C_AFTERCOMMON+9
					setDragLeaveEventCode(cValue)
				case C_AFTERCOMMON+10
					setDragMoveEventCode(cValue)
				case C_AFTERCOMMON+11
					setDropEventCode(cValue)
				case C_AFTERCOMMON+12
					setEnterEventCode(cValue)
				case C_AFTERCOMMON+13
					setFocusInEventCode(cValue)
				case C_AFTERCOMMON+14
					setFocusOutEventCode(cValue)
				case C_AFTERCOMMON+15
					setKeyReleaseEventCode(cValue)
				case C_AFTERCOMMON+16
					setLeaveEventCode(cValue)
				case C_AFTERCOMMON+17
					setNonClientAreaMouseButtonDblClickEventCode(cValue)
				case C_AFTERCOMMON+18
					setNonClientAreaMouseButtonPressEventCode(cValue)
				case C_AFTERCOMMON+19
					setNonClientAreaMouseButtonReleaseEventCode(cValue)
				case C_AFTERCOMMON+20
					setNonClientAreaMouseMoveEventCode(cValue)
				case C_AFTERCOMMON+21
					setMoveEventCode(cValue)
				case C_AFTERCOMMON+22
					setResizeEventCode(cValue)
				case C_AFTERCOMMON+23
					setWindowActivateEventCode(cValue)
				case C_AFTERCOMMON+24
					setWindowBlockedEventCode(cValue)
				case C_AFTERCOMMON+25
					setWindowDeactivateEventCode(cValue)
				case C_AFTERCOMMON+26
					setWindowStateChangeEventCode(cValue)
				case C_AFTERCOMMON+27
					setWindowUnblockedEventCode(cValue)
				case C_AFTERCOMMON+28
					setPaintEventCode(cValue)
			}
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :controlname =  "' + ControlNameValue() + '"'
		cOutput += "," + nl + cTabs + ' :setKeyPressEvent =  "' + KeyPressEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setMouseButtonPressEvent =  "' + MouseButtonPressEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setMouseButtonReleaseEvent =  "' + MouseButtonReleaseEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setMouseButtonDblClickEvent =  "' + MouseButtonDblClickEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setMouseMoveEvent =  "' + MouseMoveEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setCloseEvent =  "' + CloseEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setContextMenuEvent =  "' + ContextMenuEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setDragEnterEvent =  "' + DragEnterEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setDragLeaveEvent =  "' + DragLeaveEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setDragMoveEvent =  "' + DragMoveEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setDropEvent =  "' + DropEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setEnterEvent =  "' + EnterEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setFocusInEvent =  "' + FocusInEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setFocusOutEvent =  "' + FocusOutEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setKeyReleaseEvent =  "' + KeyReleaseEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setLeaveEvent =  "' + LeaveEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseButtonDblClickEvent =  "' + NonClientAreaMouseButtonDblClickEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseButtonPressEvent =  "' + NonClientAreaMouseButtonPressEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseButtonReleaseEvent =  "' + NonClientAreaMouseButtonReleaseEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setNonClientAreaMouseMoveEvent =  "' + NonClientAreaMouseMoveEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setMoveEvent =  "' + MoveEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setResizeEvent =  "' + ResizeEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setWindowActivateEvent =  "' + WindowActivateEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setWindowBlockedEvent =  "' + WindowBlockedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setWindowDeactivateEvent =  "' + WindowDeactivateEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setWindowStateChangeEvent =  "' + WindowStateChangeEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setWindowUnblockedEvent =  "' + WindowUnblockedEventCode() + '"'
		cOutput += "," + nl + cTabs + ' :setPaintEvent =  "' + PaintEventCode() + '"'
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) + 
		"#{f4} = " +
		'new #{f1}(win) {			
#{f2}
		}
		#{f3}.installEventFilter(#{f4})' + nl
		
		cClass = substr(classname(self),"formdesigner_","")
		cOutput = substr(cOutput,"#{f1}",cClass)
		cOutput = substr(cOutput,"#{f2}",AddTabs(GenerateCustomCode(oDesigner),3))
		cOutput = substr(cOutput,"#{f3}",ControlNameValue())
		cOutput = substr(cOutput,"#{f4}",oDesigner.oModel.GetObjectName(self))
		return cOutput

	func GenerateCustomCode oDesigner 
		cOutput = ""
		cOutput += 'setKeyPressEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,KeyPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",KeyPressEventCode())
		cOutput += 'setMouseButtonPressEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseButtonPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseButtonPressEventCode())
		cOutput += 'setMouseButtonReleaseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseButtonReleaseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseButtonReleaseEventCode())
		cOutput += 'setMouseButtonDblClickEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseButtonDblClickEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseButtonDblClickEventCode())
		cOutput += 'setMouseMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MouseMoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MouseMoveEventCode())
		cOutput += 'setCloseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,CloseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",CloseEventCode())
		cOutput += 'setContextMenuEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,ContextMenuEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",ContextMenuEventCode())
		cOutput += 'setDragEnterEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,KeyPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DragEnterEventCode())
		cOutput += 'setDragLeaveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,DragLeaveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DragLeaveEventCode())
		cOutput += 'setDragMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,DragMoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DragMoveEventCode())
		cOutput += 'setDropEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,DropEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",DropEventCode())
		cOutput += 'setEnterEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,EnterEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",EnterEventCode())
		cOutput += 'setFocusInEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,FocusInEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",FocusInEventCode())
		cOutput += 'setFocusOutEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,FocusOutEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",FocusOutEventCode())
		cOutput += 'setKeyReleaseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,KeyReleaseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",KeyReleaseEventCode())
		cOutput += 'setLeaveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,LeaveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",LeaveEventCode())
		cOutput += 'setNonClientAreaMouseButtonDblClickEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseButtonDblClickEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseButtonDblClickEventCode())
		cOutput += 'setNonClientAreaMouseButtonPressEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseButtonPressEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseButtonPressEventCode())
		cOutput += 'setNonClientAreaMouseButtonReleaseEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseButtonReleaseEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseButtonReleaseEventCode())
		cOutput += 'setNonClientAreaMouseMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,NonClientAreaMouseMoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",NonClientAreaMouseMoveEventCode())
		cOutput += 'setMoveEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,MoveEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",MoveEventCode())
		cOutput += 'setResizeEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,ResizeEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",ResizeEventCode())
		cOutput += 'setWindowActivateEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowActivateEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowActivateEventCode())
		cOutput += 'setWindowBlockedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowBlockedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowBlockedEventCode())
		cOutput += 'setWindowDeactivateEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowDeactivateEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowDeactivateEventCode())
		cOutput += 'setWindowStateChangeEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowStateChangeEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowStateChangeEventCode())
		cOutput += 'setWindowUnblockedEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,WindowUnblockedEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",WindowUnblockedEventCode())
		cOutput += 'setPaintEvent("#{f1}")' + nl
		cOutput = PrepareEvent(cOutput,PaintEventCode(),"#{f1}")
		cOutput = substr(cOutput,"#{f1}",PaintEventCode())
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		SetControlNameValue(itemdata[:ControlName])
		SetKeyPressEventCode(itemdata[:setKeyPressEvent])
		SetMouseButtonPressEventCode(itemdata[:setMouseButtonPressEvent])
		SetMouseButtonReleaseEventCode(itemdata[:setMouseButtonReleaseEvent])
		SetMouseButtonDblClickEventCode(itemdata[:setMouseButtonDblClickEvent])
		SetMouseMoveEventCode(itemdata[:setMouseMoveEvent])
		SetCloseEventCode(itemdata[:setCloseEvent])
		SetContextMenuEventCode(itemdata[:setContextMenuEvent])
		SetDragEnterEventCode(itemdata[:setDragEnterEvent])
		SetDragLeaveEventCode(itemdata[:setDragLeaveEvent])
		SetDragMoveEventCode(itemdata[:setDragMoveEvent])
		SetDropEventCode(itemdata[:setDropEvent])
		SetEnterEventCode(itemdata[:setEnterEvent])
		SetFocusInEventCode(itemdata[:setFocusInEvent])
		SetFocusOutEventCode(itemdata[:setFocusOutEvent])
		SetKeyReleaseEventCode(itemdata[:setKeyReleaseEvent])
		SetLeaveEventCode(itemdata[:setLeaveEvent])
		SetNonClientAreaMouseButtonDblClickEventCode(itemdata[:setNonClientAreaMouseButtonDblClickEvent])
		SetNonClientAreaMouseButtonPressEventCode(itemdata[:setNonClientAreaMouseButtonPressEvent])
		SetNonClientAreaMouseButtonReleaseEventCode(itemdata[:setNonClientAreaMouseButtonReleaseEvent])
		SetNonClientAreaMouseMoveEventCode(itemdata[:setNonClientAreaMouseMoveEvent])
		SetMoveEventCode(itemdata[:setMoveEvent])
		SetResizeEventCode(itemdata[:setResizeEvent])
		SetWindowActivateEventCode(itemdata[:setWindowActivateEvent])
		SetWindowBlockedEventCode(itemdata[:setWindowBlockedEvent])
		SetWindowDeactivateEventCode(itemdata[:setWindowDeactivateEvent])
		SetWindowStateChangeEventCode(itemdata[:setWindowStateChangeEvent])
		SetWindowUnblockedEventCode(itemdata[:setWindowUnblockedEvent])
		SetPaintEventCode(itemdata[:setPaintEvent])

class FormDesigner_QLayout from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nLayoutType = 0
	cLayoutObjects = ""

	func LayoutTypeValue
		return nLayoutType

	func SetLayoutTypeValue Value 
		nLayoutType = Value 

	func LayoutObjectsValue
		return cLayoutObjects

	func SetLayoutObjectsValue cValue
		cLayoutObjects = cValue	

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddPropertyCombobox("Type",["Vertical","Horizontal"])
		oDesigner.oView.AddProperty("Objects (S: Comma)",True)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Layout Type
			oWidget = oPropertiesTable.cellwidget(C_AFTERCOMMON,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(LayoutTypeValue())
			oCombo.BlockSignals(False)
		# Set the Layout Objects
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(LayoutObjectsValue())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON 
				setLayoutTypeValue(cValue)
			case C_AFTERCOMMON + 1
				setLayoutObjectsValue(cValue)
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ComboItemAction oDesigner,nRow
		nLayoutTypePos = C_AFTERCOMMON
		if nRow = nLayoutTypePos  {		# Layout Type
			oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nLayoutTypePos,1)
			oCombo = new qCombobox 
			oCombo.pObject = oWidget.pObject 
			nIndex = oCombo.CurrentIndex()
			setLayoutTypeValue(nIndex)
		}

	func DialogButtonAction oDesigner,nRow 
		CommonDialogButtonAction(oDesigner,nRow)
		switch nRow {
			case C_AFTERCOMMON + 1 	# Layout Objects
				open_window(:WindowObjectsController)
				Last_Window().setParentObject(oDesigner)
				aList = oDesigner.oModel.GetObjectsNames()
				# Remove the window Object name
					del(aList,1)	
				# Remove the current layout object name 
					del(aList,std_find(aList,oDesigner.oModel.GetObjectName(self))) 
				Last_Window().LoadObjectsData(aList)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :LayoutType =  ' + LayoutTypeValue()
		cOutput += "," + nl + cTabs + ' :LayoutObjects =  "' + LayoutObjectsValue() + '"'
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) + 
		oDesigner.oModel.GetObjectName(self) + " = " +
		'new #{f1}() {			
#{f2}
		}' + nl
		switch LayoutTypeValue()	{
			case 0
				cClass = "QVBoxLayout"
			case 1 
				cClass = "QHBoxLayout"
		}
		cOutput = substr(cOutput,"#{f1}",cClass)
		cOutput = substr(cOutput,"#{f2}",AddTabs(GenerateCustomCode(oDesigner),3))
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if LayoutObjectsValue() != NULL {
			aItems = split(LayoutObjectsValue(),",")
			for item in aItems {
				if not oDesigner.oModel.GetObjectClassByName(item) = "formdesigner_qlayout" {
					cOutput += 'AddWidget(#{f1})' + nl
				else
					cOutput += 'AddLayout(#{f1})' + nl
				}
				cOutput = substr(cOutput,"#{f1}",Item)
			}
		}
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setLayoutTypeValue(itemdata[:LayoutType])
		setLayoutObjectsValue(itemdata[:LayoutObjects])

class FormDesigner_QTabWidget from QTabWidget 

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	nPagesCount = 0
	cPagesTitles = ""

	aTabs = []

	func PagesCountValue
		return ""+nPagesCount

	func SetPagesCountValue cValue
		nPagesCount = 0+cValue	
		if nPagesCount > 0 {
			for x = len(aTabs) + 1 to nPagesCount {
				aTabs + [new qWidget(),"Page " + x]
				inserttab(len(aTabs)-1,aTabs[len(aTabs)][1],aTabs[len(aTabs)][2])
			}
			if nPagesCount < len(aTabs) {	# Delete Tabs
				nCount = len(aTabs)-nPagesCount
				for x = 1  to nCount {
					removeTab(len(aTabs)-1)
					del(aTabs,len(aTabs))
				}
			}
		}
		if nPagesCount = 0 and len(aTabs) > 0 {
			nCount = len(aTabs)
			for x = nCount to 1 step -1 {
				removeTab(x-1)
			}
			aTabs = [] 
		}

	func PagesTitlesValue
		return cPagesTitles

	func SetPagesTitlesValue cValue
		cPagesTitles = cValue	
		aItems = split(cPagesTitles,",")
		for x = 1 to len(aItems) {
			if x <= len(aTabs) { 
				aTabs[x][2] = aItems[x]
				setTabText(x-1,aItems[x])
			}
		}

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Pages Count",False)
		oDesigner.oView.AddProperty("Pages Titles (S: Comma)",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Pages Count Value
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(PagesCountValue())
		# Set the Pages Titles Value
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(PagesTitlesValue())
		oPropertiesTable.Blocksignals(False)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON 
				setPagesCountValue(cValue)
			case C_AFTERCOMMON + 1
				setPagesTitlesValue(cValue)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :PagesCount =  "' + PagesCountValue() + '"'
		cOutput += "," + nl + cTabs + ' :PagesTitles =  "' + PagesTitlesValue() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		for x = 1 to len(aTabs) {
			cOutput += '	#{f1}page#{f2} = new qwidget()' + nl +
                       	'inserttab(#{f3},#{f1}page#{f2},"#{f4}")'
			if not x = len(aTabs) {
				cOutput += nl
			}
			cOutput  = substr(cOutput,"#{f1}",oDesigner.oModel.GetObjectName(self))
			cOutput  = substr(cOutput,"#{f2}",""+x)
			cOutput  = substr(cOutput,"#{f3}",""+(x-1))
			cOutput  = substr(cOutput,"#{f4}",aTabs[x][2])
		}
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setPagesCountValue(itemdata[:PagesCount])
		setPagesTitlesValue(itemdata[:PagesTitles])

class FormDesigner_QStatusbar from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cMessage = ""

	func MessageValue 
		return cMessage

	func SetMessageValue cValue 
		cMessage = cValue 

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Message",False)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the Text
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(MessageValue())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		if nRow = C_AFTERCOMMON { 
			setMessageValue(cValue)
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :Message =  "' + MessageValue() + '"'
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = 'ShowMessage("#{f1}",0)' + nl +
				'win.setStatusBar(#{f2})'
		cOutput = substr(cOutput,"#{f1}",MessageValue())
		cOutput = substr(cOutput,"#{f2}",oDesigner.oModel.GetObjectName(self))
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setMessageValue(itemdata[:Message])

class FormDesigner_QToolBar from QLabel

	CreateCommonAttributes()
	CreateMoveResizeCornersAttributes()

	cTitle = ""
	cToolbarObjects = ""

	func TitleValue
		return cTitle

	func SetTitleValue cValue
		cTitle = cValue 

	func ToolbarObjectsValue
		return cToolbarObjects

	func SetToolbarObjectsValue cValue
		cToolbarObjects = cValue	

	func AddObjectProperties  oDesigner
		AddObjectCommonProperties(oDesigner)
		oDesigner.oView.AddProperty("Title",True)
		oDesigner.oView.AddProperty("Objects (S: Comma)",True)

	func DisplayProperties oDesigner
		DisplayCommonProperties(oDesigner)
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# The Title
			oPropertiesTable.item(C_AFTERCOMMON,1).settext(TitleValue())
		# Set the Toolbar Objects
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(ToolbarObjectsValue())
		oPropertiesTable.Blocksignals(False)
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))

	func UpdateProperties oDesigner,nRow,nCol,cValue
		UpdateCommonProperties(oDesigner,nRow,nCol,cValue)
		switch nRow {
			case C_AFTERCOMMON
				setTitleValue(cValue)
			case C_AFTERCOMMON+1
				setToolbarObjectsValue(cValue)
		}
		# Set the object name 
			setText(oDesigner.oModel.GetObjectName(self))


	func DialogButtonAction oDesigner,nRow 
		CommonDialogButtonAction(oDesigner,nRow)
		switch nRow {
			case C_AFTERCOMMON+1  	# Toolbar Objects
				open_window(:WindowObjectsController)
				Last_Window().setParentObject(oDesigner)
				aList = oDesigner.oModel.GetObjectsNames()
				# Remove the window Object name
					del(aList,1)	
				# Remove the current layout object name 
					del(aList,std_find(aList,oDesigner.oModel.GetObjectName(self))) 
				Last_Window().LoadObjectsData(aList)
		}

	func ObjectDataAsString oDesigner,nTabsCount
		cOutput = ObjectDataAsString2(oDesigner,nTabsCount)
		cTabs = std_copy(char(9),nTabsCount) 
		cOutput += "," + nl + cTabs + ' :Title =  "' + TitleValue() + '"'
		cOutput += "," + nl + cTabs + ' :ToolbarObjects =  "' + ToolbarObjectsValue() + '"'
		return cOutput

	func GenerateCode oDesigner
		cOutput = char(9) + char(9) + 
		oDesigner.oModel.GetObjectName(self) + " = " +
		'new win.addtoolbar("#{f1}") {			
#{f2}
		}' + nl
		cOutput = substr(cOutput,"#{f1}",TitleValue())
		cOutput = substr(cOutput,"#{f2}",AddTabs(GenerateCustomCode(oDesigner),3))
		return cOutput

	func GenerateCustomCode oDesigner
		cOutput = ""
		if ToolbarObjectsValue() != NULL {
			aItems = split(ToolbarObjectsValue(),",")
			for item in aItems {
				cOutput += 'AddWidget(#{f1})' + nl
				cOutput = substr(cOutput,"#{f1}",Item)
			}
		}
		return cOutput

	func RestoreProperties oDesigner,Item 
		RestoreCommonProperties(oDesigner,item)
		itemdata = item[:data]
		setTitleValue(itemdata[:Title])
		setToolbarObjectsValue(itemdata[:ToolbarObjects])


class FormDesignerFileSystem

	cFileName = "noname.rform"
	oGenerator = new FormDesignerCodeGenerator

	func NewAction oDesigner
		# Set the file Name
			new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getsavefilename(oDesigner.oView.win,"New Form",currentdir(),"*.rform")
			}
			if cInputFileName = NULL { return }
			cInputFileName = AddExtensionToName(cInputFileName)
			cFileName = cInputFileName
		# Delete Objects 
			DeleteAllObjects(oDesigner)
		# Set Default Form Properties 
			oDesigner.oView.oSub {
				blocksignals(True)
				move(100,100) 
				resize(400,400)
				setWindowTitle("Form1")
				blocksignals(False)
			}
			oDesigner.oModel.FormObject().setBackColor("")
		# Save Form 
			SaveFormToFile(oDesigner)
		# Properties 
			oDesigner.ObjectProperties()

	func AddExtensionToName cInputFileName
		if not right(lower(cInputFileName),5) = "rform" {
			cInputFileName += ".rform"
		}
		return cInputFileName

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
			cInputFileName = AddExtensionToName(cInputFileName)
			cFileName = cInputFileName
			SaveFormToFile(oDesigner)

	func SaveFormToFile oDesigner
		cHeader = "# Start Form Designer File" + nl
		cEnd = "# End Form Designer File"
		# Save the Objects Data 
			cContent = Objects2String(oDesigner,oDesigner.oModel.aObjectsList)
		# Write the Form File 
			cFileContent = cHeader+cContent+cEnd
			cFileContent = substr(cFileContent,nl,windowsnl())
			write(cFileName,cFileContent)
		# Generate Code 
			oGenerator.Generate(oDesigner,cFileName)

	func Objects2String oDesigner,aObjectsList
		# Start of The List
			cContent = "aObjectsList = [" + nl
		# Objects 
			for x = 1 to len(aObjectsList) {
				aObject  = aObjectsList[x]
				cObjContent = Copy(char(9),1) + 
				'[ :name = "#{f1}" , :id = #{f2} , :classname = "#{f3}" , :data = [' + nl
				cObjContent += aObject[2].ObjectDataAsString(oDesigner,2) + nl
				cObjContent += Copy(char(9),2) +	"]" + nl + Copy(char(9),1) + "]" 
				cObjContent = substr(cObjContent,"#{f1}",aObject[1])
				cObjContent = substr(cObjContent,"#{f2}",""+aObject[3])
				cObjContent = substr(cObjContent,"#{f3}",classname(aObject[2]))
				if x != len(aObjectsList) {
					cObjContent += ","
				}
				cObjContent += nl
				cContent += cObjContent
			}
		# End of The List 
			cContent += "]" + nl
		return cContent

	func DeleteAllobjects oDesigner
		for x = 2 to len(oDesigner.oModel.aObjectsList) {
			item = oDesigner.oModel.aObjectsList[x]
			oObject = item[2]
			oObject.oCorners.Hide() 
			oObject.Close() 
		}
		oDesigner.oModel.DeleteAllObjects()
		oDesigner.AddObjectsToCombo()		
			
	func LoadFormFromFile oDesigner
		# Delete objects
			DeleteAllObjects(oDesigner)
		# Load the Form Data 
			eval(read(cFileName))	
		# Create Objects 
			CreateFormObjects(oDesigner,aObjectsList)

	func CreateFormObjects oDesigner,aObjectsList
		# Use the List data to create the objects 
			for item in aObjectsList {
				cClass = item[:classname] 	
				itemdata = item[:data]
				switch cClass {
					case :formdesigner_qwidget
						oDesigner.oView.oSub {
							blocksignals(True)
							move(itemdata[:x],itemdata[:y]) 
							resize(itemdata[:width],itemdata[:height])
							setWindowTitle(itemdata[:title])
							show()
							blocksignals(False)
						}						
						oDesigner.oModel.FormObject() { 
							setWindowTitle(itemdata[:title])
						 	setBackColor(itemdata[:backcolor])
							setWindowFlagsValue(itemdata[:windowflags])
							setMainLayoutValue(itemdata[:MainLayout])
							setWindowIconValue(itemdata[:WindowIcon])
						}
					case :FormDesigner_QLabel
						oDesigner.HideCorners()
						oDesigner.oModel.AddLabel(new FormDesigner_QLabel(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.LabelsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QPushButton
						oDesigner.HideCorners()
						oDesigner.oModel.AddPushButton(new FormDesigner_QPushButton(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.PushButtonsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QLineEdit
						oDesigner.HideCorners()
						oDesigner.oModel.AddLineEdit(new FormDesigner_QLineEdit(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.LineEditsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTextEdit
						oDesigner.HideCorners()
						oDesigner.oModel.AddLineEdit(new FormDesigner_QTextEdit(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.TextEditsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QListWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddListWidget(new FormDesigner_QListWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.ListWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QCheckBox
						oDesigner.HideCorners()
						oDesigner.oModel.AddCheckBox(new FormDesigner_QCheckBox(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.CheckBoxesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QImage
						oDesigner.HideCorners()
						oDesigner.oModel.AddImage(new FormDesigner_QImage(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.ImagesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QSlider
						oDesigner.HideCorners()
						oDesigner.oModel.AddSlider(new FormDesigner_QSlider(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.SlidersCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QProgressbar
						oDesigner.HideCorners()
						oDesigner.oModel.AddProgressBar(new FormDesigner_QProgressBar(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.ProgressBarsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QSpinBox
						oDesigner.HideCorners()
						oDesigner.oModel.AddSpinBox(new FormDesigner_QSpinBox(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.SpinBoxesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QComboBox
						oDesigner.HideCorners()
						oDesigner.oModel.AddComboBox(new FormDesigner_QCombobox(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.ComboBoxesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QDateTimeEdit
						oDesigner.HideCorners()
						oDesigner.oModel.AddDateTimeEdit(new FormDesigner_QDateTimeEdit(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.DateTimeEditsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTableWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddTableWidget(new FormDesigner_QTableWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.TableWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTreeWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddTreeWidget(new FormDesigner_QTreeWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.TreeWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QRadioButton
						oDesigner.HideCorners()
						oDesigner.oModel.AddRadioButton(new FormDesigner_QRadioButton(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.RadioButtonsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QWebView
						oDesigner.HideCorners()
						oDesigner.oModel.AddWebView(new FormDesigner_QWebView(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.WebViewsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QDial
						oDesigner.HideCorners()
						oDesigner.oModel.AddDial(new FormDesigner_QDial(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.DialsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QVideoWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddVideoWidget(new FormDesigner_QVideoWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.VideoWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QFrame3
						oDesigner.HideCorners()
						oDesigner.oModel.AddFrame(new FormDesigner_QFrame3(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.FramesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QLCDNumber
						oDesigner.HideCorners()
						oDesigner.oModel.AddLCDNumber(new FormDesigner_QLCDNumber(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.LCDNumbersCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QHyperLink
						oDesigner.HideCorners()
						oDesigner.oModel.AddHyperLink(new FormDesigner_QHyperLink(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.HyperLinksCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTimer
						oDesigner.HideCorners()
						oDesigner.oModel.AddTimer(new FormDesigner_QTimer(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.TimersCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QAllEvents
						oDesigner.HideCorners()
						oDesigner.oModel.AddAllEvents(new FormDesigner_QAllEvents(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.AllEventsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QLayout
						oDesigner.HideCorners()
						oDesigner.oModel.AddLayout(new FormDesigner_QLayout(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.LayoutsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTabWidget	
						oDesigner.HideCorners()
						oDesigner.oModel.AddTab(new FormDesigner_QTabWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.TabsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QStatusbar	
						oDesigner.HideCorners()
						oDesigner.oModel.AddStatusbar(new FormDesigner_QStatusBar(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.StatusBarsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QToolba
						oDesigner.HideCorners()
						oDesigner.oModel.AddToolbar(new FormDesigner_QStatusBar(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.NewControlEvents(item[:name],oDesigner.oModel.ToolbarsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
				}				
			}
		# Objects List 
			oDesigner.AddObjectsToCombo()
		# Object Properties
			oDesigner.ObjectProperties()

class FormDesignerCodeGenerator
	
	cSourceFileName 

	func Generate oDesigner,cFormFileName
		cSourceFileName = substr(cFormFileName,".rform","View.ring")
		cFormName = GetFileNameOnlyWithoutPath(substr(cFormFileName,".rform",""))
		cClassName = cFormName + "View"
		# Add the File Header 
			cOutput = "# Form/Window View - Generated Source Code File " + nl +
					"# Generated by the Ring "+version()+" Form Designer" + nl +
					"# Date : " + date() + nl +
					"# Time : " + time() + nl + nl
		# Write general code to show the window 
			cOutput += 'Load "stdlib.ring"' + nl + 
					'Load "guilib.ring"' + nl + nl +
					"if IsMainSourceFile() { " + nl + 
					char(9) + "new qApp {" + nl + 
					char(9) + char(9) + "StyleFusion()" + nl + 
					char(9) + char(9) + "new " + cClassName + " { win.show() } " + nl + 
					char(9) + char(9) + "exec()" + nl +
					char(9) + "}" + nl + 
					 "}" + nl + nl
		# Write the Class 
			cOutput += "class " + cClassName + " from WindowsViewParent" + nl +
					char(9) + "win = new qMainWindow() { " + nl +
					GenerateWindowCode(oDesigner) +
					GenerateObjectsCode(oDesigner) +
					GenerateWindowCodeAfterObjects(oDesigner) +
					char(9) + "}" + nl + nl	
		# Add the End of file 
			cOutput += "# End of the Generated Source Code File..."
			cOutput = substr(cOutput,nl,WindowsNL())
			write(cSourceFileName,cOutput)
		# Write the Controller Source File
			cSourceFileName = substr(cFormFileName,".rform","Controller.ring")
			if fexists(cSourceFileName) { return }
			cOutput = `# Form/Window Controller - Source Code File

load "#{f1}View.ring"

if IsMainSourceFile() { 
	new qApp {
		StyleFusion()
		open_window(:#{f1}Controller)
		exec()
	}
}

class #{f1}controller from windowsControllerParent

	oView = new #{f1}View 
`
			cOutput = substr(cOutput,"#{f1}",cFormName)
			write(cSourceFileName,cOutput)		

	func GetFileNameOnlyWithoutPath cFileName
		cFN = cFileName
		nCount = 0
		for x = len(cFileName) to 1 step -1 {
			if cFileName[x] = "/" or cFileName[x] = "\" {
				cFN = right(cFileName,nCount)
				exit 	
			}
			nCount++
		}
		return cFN

	func GenerateWindowCode oDesigner
		return oDesigner.oModel.FormObject().GenerateCode(oDesigner)

	func GenerateWindowCodeAfterObjects oDesigner
		return oDesigner.oModel.FormObject().GenerateCodeAfterObjects(oDesigner)

	func GenerateObjectsCode oDesigner
		cCode = ""
		for x = 2 to len( oDesigner.oModel.GetObjects() ) {
			oObject = oDesigner.oModel.GetObjects()[x][2]
			cCode += oObject.GenerateCode(oDesigner)
		}
		return cCode

class windowflagsView from WindowsViewParent
	win = new qWidget() { 
		move(64,40)
		resize(395,376)
		setWindowTitle("Window Flags")
		setstylesheet("background-color:;")
		LabelType = new qlabel(win) {
			move(10,13)
			resize(31,26)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Type")
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		LabelHints = new qlabel(win) {
			move(9,143)
			resize(32,27)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Hints")
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		ListType = new qlistwidget(win) {
			move(56,13)
			resize(321,113)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			AddItem("Window")
			AddItem("Dialog")
			AddItem("Sheet")
			AddItem("Drawer")
			AddItem("Popup")
			AddItem("Tool")
			AddItem("Tooltip")
			AddItem("Splash Screen")
		}
		ListHints = new qlistwidget(win) {
			move(56,143)
			resize(321,163)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			AddItem("Window title")
			AddItem("Window system menu")
			AddItem("Window minimize button")
			AddItem("Window maximize button")
			AddItem("Window close button")
			AddItem("Window context help button")
			AddItem("Window shade button")
			AddItem("Window stays on top")
			AddItem("Window stays on bottom")
			AddItem("Customize window")
		}
		BtnOk = new qpushbutton(win) {
			move(236,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Ok")
			setClickEvent(Method(:okAction))
			
		}
		BtnCancel = new qpushbutton(win) {
			move(309,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Cancel")
			setClickEvent(Method(:CancelAction))
		}
	}

class windowflagscontroller from windowsControllerParent

	oView = new windowflagsView {
		win.setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint )
		ListHints.setselectionmode(QAbstractItemView_MultiSelection)
		win.setwindowmodality(2)
	}

	aTypeList = [ "Qt_Window"  , "Qt_dialog"  , "Qt_sheet"  ,
			"Qt_Drawer"  , "Qt_popup"  , "Qt_Tool"  , "Qt_ToolTip"  , 
			"Qt_SplashScreen"  ]

	aHintsList = ["Qt_WindowTitleHint"  , 
			"Qt_WindowSystemMenuHint"  ,
			"Qt_WindowMinimizeButtonHint"  , 
			"Qt_WindowMaximizeButtonHint"  ,
			"Qt_WindowCloseButtonHint" ,
			"Qt_WindowContextHelpButtonHint"  ,
			"Qt_WindowShadeButtonHint" ,
			"Qt_WindowStaysOnTopHint"  ,
			"Qt_WindowStaysOnBottomHint"  ,
			"Qt_CustomizeWindowHint" ]

	cFlags = ""	# The window output 

	func OkAction
		cFlags = ""
		nType = oView.ListType.currentrow() + 1
		cFlags += aTypeList[nType]
		for x = 1 to len(aHintsList) {
			if oView.ListHints.item(x-1).isSelected() {
				cFlags += " | " + aHintsList[x]
			}
		}		
		oPropertiesTable = parent().oView.oPropertiesTable
		# Set the Window Flags
			oPropertiesTable.Blocksignals(True)
			oPropertiesTable.item(6,1).settext(cFlags)
			oPropertiesTable.Blocksignals(False)
		parent().oModel.FormObject().setWindowFlagsValue(cFlags)
		oView.Close()

	func CancelAction
		oView.Close()

class windowObjectsView from WindowsViewParent
	win = new qWidget() { 
		move(64,40)
		resize(395,376)
		setWindowTitle("Window Objects")
		setstylesheet("background-color:;")
		LabelObjects = new qlabel(win) {
			move(10,13)
			resize(41,26)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Objects")
			setAlignment(Qt_AlignRight |  Qt_AlignVCenter)
		}
		ListObjects = new qlistwidget(win) {
			move(56,13)
			resize(321,290)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
		}
		BtnOk = new qpushbutton(win) {
			move(236,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Ok")
			setClickEvent(Method(:okAction))
			
		}
		BtnCancel = new qpushbutton(win) {
			move(309,315)
			resize(68,25)
			setstylesheet("color:black;background-color:;")
			oFont = new qfont("",0,0,0)
			oFont.fromstring("")
			setfont(oFont)
			setText("Cancel")
			setClickEvent(Method(:CancelAction))
		}
	}

class windowObjectscontroller from windowsControllerParent

	oView = new windowObjectsView {
		win.setwindowflags(Qt_CustomizeWindowHint | Qt_WindowTitleHint | Qt_WindowStaysOnTopHint )
		ListObjects.setselectionmode(QAbstractItemView_MultiSelection)
		win.setwindowmodality(2)
	}

	aObjectsList = []

	func LoadObjectsData aList
		aObjectsList = aList 
		for item in aObjectsList {
			oView.ListObjects.AddItem(item)
		}

	func OkAction
		cObjects = ""
		for x = 1 to len(aObjectsList) {
			if oView.ListObjects.item(x-1).isSelected() {
				if not cObjects = NULL {
					cObjects += "," + aObjectsList[x]
				else 
					cObjects += aObjectsList[x]
				}
			}
		}		
		oPropertiesTable = parent().oView.oPropertiesTable
		# Set the Window Flags
			oPropertiesTable.Blocksignals(True)
			oPropertiesTable.item(C_AFTERCOMMON+1,1).settext(cObjects)
			oPropertiesTable.Blocksignals(False)
		parent().oModel.ActiveObject().setLayoutObjectsValue(cObjects)
		oView.Close()

	func CancelAction
		oView.Close()


/*
**	Project : Form Designer 
**	File Purpose :  QWidget
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesigner_QWidget from QWidget

	cBackColor = ""
	oSubWindow
	nX=0 nY=0		# for Select/Draw
	cWindowFlags = ""
	cMainLayout = ""
	cWindowIcon = ""
	cMenubar = ""
	nMenubarCounter = [0,0]	# For [Menus,Items] Names

	nIndexType = 0

	nGUILibrary = 0

	# For Mobile Devices 
		nClockValue = 0
		nClocksCount = clockspersecond() / 4

	func init
		super.init()
		return self

	func GUILibraryValue
		return nGUILibrary

	func SetGUILibraryValue Value
		nGUILibrary = Value

	func IndexTypeValue
		return nIndexType

	func SetIndexTypeValue Value
		nIndexType = Value

	func IndexStart
		if IndexTypeValue() = 0 {
			return 1
		}
		return 0

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

	func MenubarValue
		return cMenubar

	func SetMenubarValue cValue
		cMenubar = cValue

	func AddObjectProperties  oDesigner
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_X,False) 		# "X"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_Y,False) 		# "Y"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WIDTH,False) 	# "Width"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_HEIGHT,False) 	# "Height"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_TITLE,False)	# "Title"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_BACKCOLOR,True)	# "Back Color"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WINDOWFLAGS,True)	# "Window Flags"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_SETLAYOUT,True)	# "Set Layout"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_WINDOWICON,True)	# "Window Icon"
		oDesigner.oView.AddProperty(T_FORMDESIGNER_ATTRIBUTE_MENUBAR,True)	# "Menubar"
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_INDEXTYPE, # "Index Type"
				[T_FORMDESIGNER_ATTRIBUTE_STARTFROM1, 			# "Start from 1"
				T_FORMDESIGNER_ATTRIBUTE_STARTFROM0] 			# "Start from 0"
				)
		oDesigner.oView.AddPropertyCombobox(T_FORMDESIGNER_ATTRIBUTE_GUILIBRARY, # "GUI Library"
				[T_FORMDESIGNER_ATTRIBUTE_GUILIB, 			# "GUILib"
				T_FORMDESIGNER_ATTRIBUTE_LIGHTGUILIB] 			# "Light GUILib"
				)

	func UpdateProperties oDesigner,nRow,nCol,cValue
		if nCol = 1 {
			switch nRow {
				case 0 	# x
					oSubWindow.move(NumOrZero(cValue),oSubWindow.y())
				case 1 	# y
					oSubWindow.move(oSubWindow.x(),NumOrZero(cValue))
				case 2	# width
					oSubWindow.resize(NumOrZero(cValue),oSubWindow.height())
				case 3 	# height
					oSubWindow.resize(oSubWindow.width(),NumOrZero(cValue))
				case 4  	# Title
					setWindowTitle(cValue)
					oDesigner.oView.oSub {
						setWindowTitle(cValue)
						show()
					}
				case 5	# back color
					setBackColor(cValue)
				case 6	# Window Flags
					setWindowFlagsValue(cValue)
				case 7  	# Main Layout
					setMainLayoutValue(cValue)
				case 8  	# Window Icon
					setWindowIconValue(cValue)
				case 9	# Menubar
					setMenubarValue(cValue)

			}
		}

	func ComboItemAction oDesigner,nRow
		nIndexTypePos = 10
		nGUILibraryPos = 11
		Switch nRow { 
			on nIndexTypePos  
				oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nIndexTypePos,1)
				oCombo = new qCombobox
				oCombo.pObject = oWidget.pObject
				nIndex = oCombo.CurrentIndex()
				setIndexTypeValue(nIndex)
			on nGUILibraryPos
				oWidget = oDesigner.oView.oPropertiesTable.cellwidget(nGUILibraryPos,1)
				oCombo = new qCombobox
				oCombo.pObject = oWidget.pObject
				nIndex = oCombo.CurrentIndex()
				setGUILibraryValue(nIndex)
		}

	func DisplayProperties oDesigner
		oPropertiesTable = oDesigner.oView.oPropertiesTable
		oPropertiesTable.Blocksignals(True)
		# Set the X
			oPropertiesTable.item(0,1).settext(""+(oSubWindow.x()+oDesigner.oview.oArea.horizontalScrollBar().value()))
		# Set the Y
			oPropertiesTable.item(1,1).settext(""+(oSubWindow.y()+oDesigner.oview.oArea.verticalScrollBar().value()))
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
		# Set the Menubar
			oPropertiesTable.item(9,1).settext(MenubarValue())
		# Index Type 
			oWidget = oPropertiesTable.cellwidget(10,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(IndexTypeValue())
			oCombo.BlockSignals(False)
		# GUI Library
			oWidget = oPropertiesTable.cellwidget(11,1)
			oCombo = new qCombobox
			oCombo.pObject = oWidget.pObject
			oCombo.BlockSignals(True)
			oCombo.setCurrentIndex(GUILibraryValue())
			oCombo.BlockSignals(False)
		oPropertiesTable.Blocksignals(False)

	func DialogButtonAction oDesigner,nRow
		switch nRow {
			case 5 	# Back Color
				oDesigner.oGeneral.cColorOperation = :BackColor
				oDesigner.oGeneral.SelectColor()
			case 6	# Window Flags
				openWindowInPackages(:WindowFlagsController,[
					"System.GUI"
				])
				lastWindow().setParentObject(oDesigner)
				lastWindow().LoadSelectedItems()
			case 7  # Window Layout 
				openWindow(:WindowObjectsController)
				lastWindow().setParentObject(oDesigner)
				lastWindow().setPropertyIndex(7)
				lastWindow().setMethodName("setMainLayoutValue")
				aList = oDesigner.oModel.GetLayoutsNames()
				lastWindow().LoadObjectsData(aList)
				lastWindow().LoadSelectedItems()
			case 8	# Window Icon
				cFile = oDesigner.oGeneral.SelectFile(oDesigner)
				if ! isWebAssembly() {
					ApplyOpenImageFile(oDesigner,cFile)
				}
			case 9	# Menubar
				openWindowInPackages(:MenubarDesignerController,[
					"System.GUI"
				])
				lastWindow().setParentObject(oDesigner)
				lastWindow().setMenubar(MenubarValue())
		}

	func ApplyOpenImageFile oDesigner,cFile
		setWindowIconValue(cFile)
		DisplayProperties(oDesigner)

	func ApplyBackColor oDesigner,cColor
		setBackColor(cColor)
		DisplayProperties(oDesigner)

	func MousePressAction oDesigner
		if isWebAssembly() {
			nFixX = 0
			nFixY = 0
		else 
			nFixX = -1
			nFixY = -6
		}
		# Start drawing from the center of the Mouse Cursor
			nX = oDesigner.oView.oFilter.getglobalx() + nFixX
			ny = oDesigner.oView.oFilter.getglobaly() + nFixY
		oDesigner.oView.oLabelSelect.raise()
		oDesigner.oView.oLabelSelect.move(nX,nY)
		oDesigner.oView.oLabelSelect.resize(1,1)
		oDesigner.oView.oLabelSelect.show()

	func MouseReleaseAction oDesigner
		oDesigner.oView.oLabelSelect.hide()
		aRect = GetRectDim(oDesigner)
		oDesigner.SelectDrawAction(aRect)

	func MouseMoveAction oDesigner
		if MobileEventDelay() { return }
		aRect = GetRectDim(oDesigner)
		oDesigner.oView.oLabelSelect {
			move(aRect[1],aRect[2])
			resize(aRect[3],aRect[4])
			if isMobile() {
				show()
				oFDApp.processevents()
			}
		}

	func MobileEventDelay
		if isMobile() {
			if nClockValue != 0 and clock() - nClockValue < nClocksCount {
				return True
			}
			nClockValue = clock()
		}
		return False

	func GetRectDim oDesigner
		if isWebAssembly() {
			C_TOPMARGIN = 0
		else 
			C_TOPMARGIN = 25
		}
		nX2 = oDesigner.oView.oFilter.getglobalx()
		ny2 = oDesigner.oView.oFilter.getglobaly()
		top = min(nY2,nY) - oDesigner.oView.oArea.y() - oSubWindow.y() - y() - C_TOPMARGIN - oDesigner.oView.win.y()
		left = min(nX2,nX) - oDesigner.oView.oArea.x()  - oSubWindow.x() - x() - oDesigner.oView.win.x()
		# Take in mind embedding the Designer in another Window like RNote
			if oDesigner.HasParent() {
				top -= oDesigner.oView.win.parentwidget().y()
				left -= oDesigner.oView.win.parentwidget().x()
				# Where we move RNOTE main window down then draw button
				top -= oDesigner.oView.win.parentwidget().parentwidget().y()
				left -= oDesigner.oView.win.parentwidget().parentwidget().x()
			}
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
		cOutput += cTabs + ' :WindowIcon =  "#{f9}" , ' + nl
		cOutput += cTabs + ' :Menubar =  "#{f10}"  ,' + nl
		cOutput += cTabs + ' :IndexType =  #{f11}  ,' + nl
		cOutput += cTabs + ' :GUILibrary =  #{f12}  ' + nl
		cOutput = substr(cOutput,"#{f1}",""+parentwidget().x())
		cOutput = substr(cOutput,"#{f2}",""+parentwidget().y())
		cOutput = substr(cOutput,"#{f3}",""+parentwidget().width())
		cOutput = substr(cOutput,"#{f4}",""+parentwidget().height())
		cOutput = substr(cOutput,"#{f5}",windowtitle())
		cOutput = substr(cOutput,"#{f6}",backcolor())
		cOutput = substr(cOutput,"#{f7}",WindowFlagsValue())
		cOutput = substr(cOutput,"#{f8}",MainLayoutValue())
		cOutput = substr(cOutput,"#{f9}",WindowIconValue())
		cOutput = substr(cOutput,"#{f10}",MenubarValue())
		cOutput = substr(cOutput,"#{f11}",""+IndexTypeValue())
		cOutput = substr(cOutput,"#{f12}",""+GUILibraryValue())
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
		if not MenubarValue() = NULL {
			cOutput += '
		#{f9} ' + nl
		}
		cOutput = substr(cOutput,"#{f1}",""+max(parentwidget().x(),0))
		cOutput = substr(cOutput,"#{f2}",""+max(parentwidget().y(),0))
		cOutput = substr(cOutput,"#{f3}",""+parentwidget().width())
		cOutput = substr(cOutput,"#{f4}",""+max(parentwidget().height()-26,0))
		cOutput = substr(cOutput,"#{f5}",windowtitle())
		cOutput = substr(cOutput,"#{f6}",backcolor())
		cOutput = substr(cOutput,"#{f7}",WindowFlagsValue())
		cOutput = substr(cOutput,"#{f8}",WindowIconValue())
		cOutput = substr(cOutput,"#{f9}",MenubarCode())
		return cOutput

	func GenerateCodeAfterObjects oDesigner
		cOutput = ""
		if not MainLayoutValue() = NULL {
			cOutput += '
		oMWLayoutWidget = new qWidget() { setLayout(#{f1}) }
		setCentralWidget(oMWLayoutWidget) ' + nl
			cOutput = substr(cOutput,"#{f1}",MainLayoutValue())
		}
		return cOutput

	func MenubarCode
		if MenubarValue() = NULL { return }
		cCode = GenerateMenubarCode(MenubarValue())
		return cCode

	func GenerateMenubarCode cMenu
		eval(cMenu)
		nMenubarCounter = [0,0]
		cCode = "oMenuBar = new qmenubar(win) {" + nl
		aChild = aMenuData[:Children]
		if len(aChild) > 0 {
			cCode += GenerateSubMenuCode(aChild)
		}
		cCode += Copy(Char(9),2) +  "}" + nl
		cCode += Copy(Char(9),2) + "win.SetMenuBar(oMenuBar)" + nl
		return cCode

	func GenerateSubMenuCode aChild
		nMenubarCounter[2]=0
		nMenuID = nMenubarCounter[1]
		cCode = ""
		for Item in aChild {
			nMenubarCounter[2]++
			if ( len(Item[:Children]) > 0 ) or (nMenuID = 0) {
				# Menu
				nMenubarCounter[1]++
				nMenuID2 = nMenubarCounter[1]
				cTempCode = Copy(Char(9),3) + 'subMenu#{f1} = addmenu("#{f2}")' + nl
				cTempCode += Copy(Char(9),3) + 'subMenu#{f1} {' + nl
				cTempCode += GenerateSubMenuCode(Item[:Children])
				cTempCode += Copy(Char(9),3) + '}' + nl
				cTempCode = SubStr(cTempCode,"#{f1}",""+nMenuID2)
				cTempCode = SubStr(cTempCode,"#{f2}",Item[:Text])
				cCode += cTempCode
			else
				# Action
				cTempCode = `
				oAction#{f5}_#{f6} = new qAction(win) {
					setShortcut(new QKeySequence("#{f1}"))
					setbtnimage(self,"#{f2}")
					settext("#{f3}")
					setclickevent(Method(:#{f4}))
				}
				addaction(oAction#{f5}_#{f6})`+nl
				cTempCode = SubStr(cTempCode,"#{f1}",Item[:ShortCut])
				cTempCode = SubStr(cTempCode,"#{f2}",Item[:Image])
				cTempCode = SubStr(cTempCode,"#{f3}",Item[:Text])
				if Item[:Action] = NULL {
					Item[:Action] = "NoAction"
				}
				cTempCode = SubStr(cTempCode,"#{f4}",Item[:Action])
				cTempCode = SubStr(cTempCode,"#{f5}",""+nMenubarCounter[1])
				cTempCode = SubStr(cTempCode,"#{f6}",""+nMenubarCounter[2])
				cCode += cTempCode
			}
		}
		return cCode


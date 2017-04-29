/*
**	Project : Form Designer (Under Development)
**	File Purpose :  Main File
**	Date : 2017.02.17
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Standard Libraries
	load "guilib.ring"
	load "stdlib.ring"

# Load Main Window Files 
	load "mainwindow/qwidget.ring"
	load "mainwindow/formdesignercontroller.ring"
	load "mainwindow/formdesignermodel.ring"
	load "mainwindow/formdesignerview.ring"
	load "mainwindow/formdesignergeneral.ring"

# Load Sub Windows/Systems
	load "menubardesigner/menubarDesignerController.ring"
	load "windowflags/windowflagscontroller.ring"
	load "windowobjects/windowobjectscontroller.ring"

# Load Controls
	load "controls/qlabel.ring"
	load "controls/qpushbutton.ring"
	load "controls/qlineedit.ring"
	load "controls/qtextedit.ring"
	load "controls/qlistwidget.ring"
	load "controls/qcheckbox.ring"
	load "controls/qimage.ring"
	load "controls/qslider.ring"
	load "controls/qprogressbar.ring"
	load "controls/qspinbox.ring"
	load "controls/qcombobox.ring"
	load "controls/qdatetimeedit.ring"
	load "controls/qtablewidget.ring"
	load "controls/qtreewidget.ring"
	load "controls/qradiobutton.ring"
	load "controls/qwebview.ring"
	load "controls/qdial.ring"
	load "controls/qvideowidget.ring"
	load "controls/qframe3.ring"
	load "controls/qlcdnumber.ring"
	load "controls/qhyperlink.ring"
	load "controls/qtimer.ring"
	load "controls/qallevents.ring"
	load "controls/qlayout.ring"
	load "controls/qtabwidget.ring"
	load "controls/qstatusbar.ring"
	load "controls/qtoolbar.ring"

# Common/Shared Classes between controls
	load "common/commonattributesmethods.ring"
	load "common/moveresizecorners.ring"
	load "common/objectcorners.ring"

# Load File System
	load "filesystem/filesystem.ring"
	load "filesystem/codegenerator.ring"

# Access the package classes
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


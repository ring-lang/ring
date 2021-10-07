/*
**	Project : Form Designer 
**	File Purpose :  File System
**	Date : 2017.04.29
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/

package formdesigner

class FormDesignerFileSystem from ObjectsParent 

	cFileName = "noname.rform"
	oGenerator = new FormDesignerCodeGenerator

	lUseFileDialogStaticMethods = ! isWebAssembly()

	oNewFileDialog = new QFileDialog(NULL) {
		setFilter(QDir_AllEntries|QDir_Hidden|QDir_System)
		setFileSelectedevent(Method("oFile.NewFileDialogOperation()"))
		setWindowTitle("New Form")
		setLabelText(QFileDialog_Accept,"Save")
		setNameFilter("Form files (*.rform *)")
		setDefaultSuffix("rform")
		setFileMode(QFileDialog_AnyFile)
		setViewMode(QFileDialog_List)
		setOption(QFileDialog_ShowDirsOnly,False)
	}

	oOpenFileDialog = new QFileDialog(NULL) {
		setFilter(QDir_AllEntries|QDir_Hidden|QDir_System)
		setFileSelectedevent(Method("oFile.OpenFileDialogOperation()"))
		setWindowTitle("Open Form")
		setLabelText(QFileDialog_Accept,"Open")
		setNameFilter("Form files (*.rform *)")
		setDefaultSuffix("rform")
		setFileMode(QFileDialog_ExistingFile)
		setViewMode(QFileDialog_List)
		setOption(QFileDialog_ShowDirsOnly,False)
	}

	oSaveFileDialog = new QFileDialog(NULL) {
		setFilter(QDir_AllEntries|QDir_Hidden|QDir_System)
		setFileSelectedevent(Method("oFile.SaveFileDialogOperation()"))
		setWindowTitle("Save Form")
		setLabelText(QFileDialog_Accept,"Save")
		setNameFilter("Form files (*.rform *)")
		setDefaultSuffix("rform")
		setFileMode(QFileDialog_AnyFile)
		setViewMode(QFileDialog_List)
		setOption(QFileDialog_ShowDirsOnly,False)
	}

	cInputFileName

	func FormDesigner 
		return Me()

	func GetFileNameFromDialog oDialog 
		cInputFileName = ""
		if oDialog.selectedfiles().count() = 0 return ok
		cInputFileName = oDialog.selectedfiles().at(0)

	func NewFileDialogOperation
		GetFileNameFromDialog(oNewFileDialog)
		NewFileDialogSaveAction(FormDesigner())

	func OpenFileDialogOperation
		GetFileNameFromDialog(oOpenFileDialog)
		OpenFileDialogOpenAction(FormDesigner())

	func SaveFileDialogOperation
		GetFileNameFromDialog(oSaveFileDialog)
		SaveFileDialogSaveAction(FormDesigner())

	func SetFileName cFile 
		cFileName = cFile 
	
	func GetFileName 
		return cFileName

	func ActiveDir oDesigner
		cDir = CurrentDir()
		if oDesigner.IsParent() {
			if isMethod(oDesigner.Parent(),"getactivefolder") {
				cDir = oDesigner.Parent().GetActiveFolder()
			}
		}
		return cDir

	func NewAction oDesigner
		# Set the file Name
			cDir = ActiveDir(oDesigner)
		if lUseFileDialogStaticMethods {
			oFileDialog = new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getsavefilename(oDesigner.oView.win,"New Form",cDir,"*.rform")
			}
			if cInputFileName = NULL { return }
			cInputFileName = AddExtensionToName(cInputFileName)
			cFileName = cInputFileName	
			startNewForm(oDesigner)		
		else 
			if oDesigner.oView.lUseWebAssemblyMEMFS {
				oNewFileDialog.setDirectory(cDir) 
				oNewFileDialog.show()
			else 
				cFileName = "noname.rform"
				startNewForm(oDesigner)
			}
		}

	func NewFileDialogSaveAction oDesigner
		if cInputFileName = NULL { return }
		cInputFileName = AddExtensionToName(cInputFileName)
		cFileName = cInputFileName
		startNewForm(oDesigner)

	func startNewForm oDesigner
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
			oDesigner.oModel.FormObject().setWindowTitle("Form1")
			oDesigner.oModel.FormObject().setBackColor("")
			oDesigner.oModel.FormObject().setWindowFlagsValue("")
			oDesigner.oModel.FormObject().setMenubarValue("")
			oDesigner.oModel.FormObject().setMainLayoutValue("")
		# Save Form
			SaveFormToFile(oDesigner)
		# Properties
			oDesigner.ObjectProperties()
		# Open controller class in Ring Notepad 
			OpenControllerClassInParent(oDesigner)

	func OpenControllerClassInParent oDesigner
		if oDesigner.IsParent() {
			if isMethod(oDesigner.Parent(),"openfile") {
				cDir = oDesigner.Parent().openfile(substr(cFileName,".rform","Controller.ring"))
			}
		}


	func AddExtensionToName cInputFileName
		if not right(lower(cInputFileName),5) = "rform" {
			cInputFileName += ".rform"
		}
		return cInputFileName

	func CloseAction oDesigner
		# Delete objects
			DeleteAllObjects(oDesigner)	
		# No File Name
			cFileName = "noname.rform"
		PrepareTheForm(oDesigner)
		# Tell the Parent (Ring Notepad for example)
			if oDesigner.isParent() {
				if isMethod(oDesigner.Parent(),"clearactiveformfile") {
					oDesigner.Parent().ClearActiveFormFile()
				}
			}

	func PrepareTheForm oDesigner
		# Default Properties
			oDesigner.oView.oSub {
				blocksignals(True)
				move(100,100)
				resize(400,400)
				setWindowTitle("Form 1")
				show()
				blocksignals(False)
			}
			oDesigner.oModel.FormObject() {
		 		setBackColor("")
				setWindowTitle("Form 1")
			}
		# Properties
			oDesigner.ObjectProperties()


	func OpenAction oDesigner
		# Get the file Name
			cDir = ActiveDir(oDesigner)
		if lUseFileDialogStaticMethods {
			oFileDialog = new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getopenfilename(oDesigner.oView.win,"Open Form",cDir,"*.rform")
			}
			if cInputFileName = NULL { return }
			cFileName = cInputFileName
			LoadFormFromFile(oDesigner)
			# Open controller class in Ring Notepad 
				OpenControllerClassInParent(oDesigner)
		else
			oOpenFileDialog.setDirectory(cDir) 
			oOpenFileDialog.show()
		}

	func OpenFileDialogOpenAction oDesigner
			if cInputFileName = NULL { return }
			cFileName = cInputFileName
			LoadFormFromFile(oDesigner)
		# Open controller class in Ring Notepad 
			OpenControllerClassInParent(oDesigner)

	func SaveAction oDesigner
		# Check file not saved before
			if cFileName = "noname.rform" {
				SaveFile(oDesigner)
				return
			}
		SaveFormToFile(oDesigner)

	func SaveIfOnlyFileIsOpened oDesigner 
		# Used by Ring Notepad to Save before Run
			if cFileName != "noname.rform" {
				SaveFormToFile(oDesigner)
			}

	func SaveAsAction oDesigner
		SaveFile(oDesigner)

	func SaveFile oDesigner
		# Set the file Name
			cDir = ActiveDir(oDesigner)
		if lUseFileDialogStaticMethods {
			oFileDialog = new qfiledialog(oDesigner.oView.win) {
				cInputFileName = getsavefilename(oDesigner.oView.win,"Save Form",cDir,"*.rform")
			}
			if cInputFileName = NULL { return }
			cInputFileName = AddExtensionToName(cInputFileName)
			cFileName = cInputFileName
			SaveFormToFile(oDesigner)
			# Open controller class in Ring Notepad 
				OpenControllerClassInParent(oDesigner)
		else 
			oSaveFileDialog.setDirectory(cDir)
			oSaveFileDialog.show()
		}

	func SaveFileDialogSaveAction oDesigner
			if cInputFileName = NULL { return }
			cInputFileName = AddExtensionToName(cInputFileName)
			cFileName = cInputFileName
			SaveFormToFile(oDesigner)
		# Open controller class in Ring Notepad 
			OpenControllerClassInParent(oDesigner)

	func FormFileContent oDesigner
		cHeader = "# Start Form Designer File" + nl
		cEnd = "# End Form Designer File"
		# Save the Objects Data
			cContent = Objects2String(oDesigner,oDesigner.oModel.aObjectsList)
		# Write the Form File
			cFileContent = cHeader+cContent+cEnd
			cFileContent = substr(cFileContent,nl,windowsnl())
		return cFileContent 

	func SaveFormToFile oDesigner
			write(cFileName,FormFileContent(oDesigner))
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
			oDesigner.oModel.aObjectsList[x][2] {
				oCorners.close()
				close()
			}
		}
		DeleteAllObjectsFromModel(oDesigner)

	func DeleteAllObjectsFromModel oDesigner
		oDesigner.oModel.DeleteAllObjects()
		oDesigner.AddObjectsToCombo()
		oDesigner.AddObjectProperties()

	func LoadFormFromFile oDesigner
		# Disable Updates 
			oDesigner.oView.oSub.setupdatesenabled(False)
			oDesigner.oView.oSub.blocksignals(True)
		# Delete objects
			DeleteAllObjects(oDesigner)
		# Create New Form 
			PrepareTheForm(oDesigner)
		# Load the Form Data
			eval(read(cFileName))
		# Create Objects
			CreateFormObjects(oDesigner,aObjectsList)
		# Enable Updates
			oDesigner.oView.oSub.setupdatesenabled(True)
			oDesigner.oView.oSub.blocksignals(False)

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
							setMenubarValue(itemdata[:Menubar])
							setMainLayoutValue(itemdata[:MainLayout])
							setWindowIconValue(itemdata[:WindowIcon])
							if itemdata[:IndexType] != NULL {
								setIndexTypeValue(itemdata[:IndexType])
							else 
								setIndexTypeValue(0)
							}
							if itemdata[:GUILibrary] != NULL {
								setGUILibraryValue(itemdata[:GUILibrary])
							else 
								setGUILibraryValue(0)
							}
							show()
						}
					case :FormDesigner_QLabel
						oDesigner.HideCorners()
						oDesigner.oModel.AddLabel(new FormDesigner_QLabel(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.LabelsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QPushButton
						oDesigner.HideCorners()
						oDesigner.oModel.AddPushButton(new FormDesigner_QPushButton(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.PushButtonsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QLineEdit
						oDesigner.HideCorners()
						oDesigner.oModel.AddLineEdit(new FormDesigner_QLineEdit(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.LineEditsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTextEdit
						oDesigner.HideCorners()
						oDesigner.oModel.AddLineEdit(new FormDesigner_QTextEdit(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.TextEditsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QListWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddListWidget(new FormDesigner_QListWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.ListWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QCheckBox
						oDesigner.HideCorners()
						oDesigner.oModel.AddCheckBox(new FormDesigner_QCheckBox(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.CheckBoxesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QImage
						oDesigner.HideCorners()
						oDesigner.oModel.AddImage(new FormDesigner_QImage(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.ImagesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QSlider
						oDesigner.HideCorners()
						oDesigner.oModel.AddSlider(new FormDesigner_QSlider(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.SlidersCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QProgressbar
						oDesigner.HideCorners()
						oDesigner.oModel.AddProgressBar(new FormDesigner_QProgressBar(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.ProgressBarsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QSpinBox
						oDesigner.HideCorners()
						oDesigner.oModel.AddSpinBox(new FormDesigner_QSpinBox(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.SpinBoxesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QComboBox
						oDesigner.HideCorners()
						oDesigner.oModel.AddComboBox(new FormDesigner_QCombobox(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.ComboBoxesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QDateTimeEdit
						oDesigner.HideCorners()
						oDesigner.oModel.AddDateTimeEdit(new FormDesigner_QDateTimeEdit(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.DateTimeEditsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTableWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddTableWidget(new FormDesigner_QTableWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.TableWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTreeWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddTreeWidget(new FormDesigner_QTreeWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.TreeWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QRadioButton
						oDesigner.HideCorners()
						oDesigner.oModel.AddRadioButton(new FormDesigner_QRadioButton(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.RadioButtonsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QWebView
						oDesigner.HideCorners()
						oDesigner.oModel.AddWebView(new FormDesigner_QWebView(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.WebViewsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QDial
						oDesigner.HideCorners()
						oDesigner.oModel.AddDial(new FormDesigner_QDial(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.DialsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QVideoWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddVideoWidget(new FormDesigner_QVideoWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.VideoWidgetsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QFrame3
						oDesigner.HideCorners()
						oDesigner.oModel.AddFrame(new FormDesigner_QFrame3(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.FramesCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QLCDNumber
						oDesigner.HideCorners()
						oDesigner.oModel.AddLCDNumber(new FormDesigner_QLCDNumber(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.LCDNumbersCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QHyperLink
						oDesigner.HideCorners()
						oDesigner.oModel.AddHyperLink(new FormDesigner_QHyperLink(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.HyperLinksCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTimer
						oDesigner.HideCorners()
						oDesigner.oModel.AddTimer(new FormDesigner_QTimer(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.TimersCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QAllEvents
						oDesigner.HideCorners()
						oDesigner.oModel.AddAllEvents(new FormDesigner_QAllEvents(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.AllEventsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QLayout
						oDesigner.HideCorners()
						oDesigner.oModel.AddLayout(new FormDesigner_QLayout(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.LayoutsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QTabWidget
						oDesigner.HideCorners()
						oDesigner.oModel.AddTab(new FormDesigner_QTabWidget(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.TabsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QStatusbar
						oDesigner.HideCorners()
						oDesigner.oModel.AddStatusbar(new FormDesigner_QStatusBar(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.StatusBarsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
					case :FormDesigner_QToolbar
						oDesigner.HideCorners()
						oDesigner.oModel.AddToolbar(new FormDesigner_QToolbar(oDesigner.oModel.CurrentParentByName(itemdata[:parent])))
						oDesigner.CreateControlEventsCornersNoInit(item[:name],oDesigner.oModel.ToolbarsCount())
						oDesigner.oModel.ActiveObject().RestoreProperties(oDesigner,item)
				}
			}
		# Objects List
			oDesigner.AddObjectsToCombo()
		# Object Properties
			oDesigner.ObjectProperties()

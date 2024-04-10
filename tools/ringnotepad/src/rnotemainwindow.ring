# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteMainWindow

	func CreateMainWindow 

		oDesktop = new RNoteDesktop

		win1 = new qMainWindow() {
			if isWindows() and T_LAYOUTDIRECTION
				RightToLeft( WinID() )
			ok
			setwindowtitle(T_RINGNOTEPAD_APPNAME) # "Ring Notepad"
			setwinicon(self,this.cCurrentDir + "/image/notepad.png")
			this.oFilter = new qAllEvents(this.win1)
			this.oFilter.setCloseEvent(Method(:RingNotepadXButton))
			installEventFilter(this.oFilter)
			this.CreateToolbars()	
			this.CreateMenubar()
			this.CreateStatusbar()
			this.CreateProjectFiles()	
			this.CreateSourceCode()
			this.CreateWebBrowser()	
			this.CreateFunctionsList()
			this.CreateClassesList()
			this.CreateOutputWindow()
			this.CreateFormDesigner()
			this.PrepareDockableWindows()
		}
	
	func CreateToolBars
		win1 {
			aBtns = [
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/new.png")
						setclickEvent(Method(:NewFile))
						settooltip(T_RINGNOTEPAD_NEWFILECTRLN) # "New File (Ctrl+N)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/open.png")
						setclickEvent(Method(:Open))
						settooltip(T_RINGNOTEPAD_OPENFILECTRLO) # "Open File (Ctrl+O)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/save.png")
						setclickEvent(Method(:Save))
						settooltip(T_RINGNOTEPAD_SAVECTRLS) # "Save (Ctrl+S)"
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/saveas.png")
						setclickEvent(Method(:SaveAs))
						settooltip(T_RINGNOTEPAD_SAVEASCTRLE) # "Save As (Ctrl+E)"
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/undo.png")
						setclickEvent(Method(:Undo))
						settooltip(T_RINGNOTEPAD_UNDOCTRLZ) # "Undo (Ctrl+Z)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/cut.png")
						setclickEvent(Method(:Cut))
						settooltip(T_RINGNOTEPAD_CUTCTRLX) # "Cut (Ctrl+X)"
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/copy.png")
						setclickEvent(Method(:CopyText))
						settooltip(T_RINGNOTEPAD_COPYCTRLC) # "Copy (Ctrl+C)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/paste.png")
						setclickEvent(Method(:Paste))
						settooltip(T_RINGNOTEPAD_PASTECTRLV) # "Paste (Ctrl+V)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/font.png")
						setclickEvent(Method(:Font))
						settooltip(T_RINGNOTEPAD_FONTCTRLI) # "Font (Ctrl+I)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/search.png")
						setclickEvent(Method(:OpenFindWindow))
						settooltip(T_RINGNOTEPAD_FINDANDREPLACECTRLF) # "Find and Replace (Ctrl+F)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/print.png")
						setclickEvent(Method(:Print))
						settooltip(T_RINGNOTEPAD_PRINTCTRLP) # "Print (Ctrl+P)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/debug.png")
						setclickevent(Method(:Debug)) 
						settooltip(T_RINGNOTEPAD_DEBUGRUNTHENWAITCTRLD) # "Debug - Run then wait! (Ctrl+D)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/run.png")
						setclickEvent(Method(:Run))
						settooltip(T_RINGNOTEPAD_RUNTHEPROGRAMCTRLR) # "Run the program (Ctrl+R) "
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/rungui.png")
						setclickEvent(Method(:RunNoConsole))
						settooltip(T_RINGNOTEPAD_RUNGUIAPPLICATIONNOCONSOLECTRLF5) # "Run GUI Application - No Console (Ctrl+F5)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/web.png")
						setclickEvent(Method(:RunInBrowser))
						settooltip(T_RINGNOTEPAD_RUNWEBAPPLICATIONOPENINBROWSERCTRLF6) # "Run Web Application - Open In Browser (Ctrl+F6)"
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/closeapp.png")
						setclickEvent(Method(:Quit))
						settooltip(T_RINGNOTEPAD_QUITCTRLQ) # "Quit (Ctrl+Q)"
					}
				]
	
			tool1 = addtoolbar("files")  {
				for x in aBtns addwidget(x) addseparator() next
			}
	
			# Main File Toolbar
			tool2 = addtoolbar("mainfile")  {
				oLblMainFile = new qLabel(this.win1) {
					setText(T_RINGNOTEPAD_MAINFILE) # "Main File : "
				}
				this.oTxtMainFile = new qLineEdit(this.win1) {
					setStylesheet("border: 0px;  background-color: rgba(0, 0, 0, 0);")
					setReadOnly(True)
				}
				oBtnSetFile = new qtoolbutton(this.win1) {
					setbtnimage(self,"image/open.png")
					setclickEvent(Method(:SetMainFile))
					settooltip(T_RINGNOTEPAD_SETTHEMAINFILE) # "Set the Main File to be the current source file (Ctrl+Shift+M)"
				}
				oBtnDebugMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/debug.png")
						setclickevent(Method(:DebugMainFile)) 
						settooltip(T_RINGNOTEPAD_MAINFILEDEBUG) # "Main File : Debug  - Run then wait! (Ctrl+Shift+D)"
				} 
				oBtnRunMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/run.png")
						setclickEvent(Method(:RunMainFile))
						settooltip(T_RINGNOTEPAD_MAINFILERUN) # "Main File : Run the program (Ctrl+Shift+R)"
				} 
				oBtnRunGUIMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/rungui.png")
						setclickEvent(Method(:RunGUIMainFile))
						settooltip(T_RINGNOTEPAD_MAINFILERUNGUI) # "Main File : Run GUI Application - No Console (Ctrl+Shift+F5)"
				} 
				oBtnRunWebMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/web.png")
						setclickEvent(Method(:RunInBrowserMainFile))
						settooltip(T_RINGNOTEPAD_MAINFILERUNWEB) # "Main File : Run Web Application - Open In Browser (Ctrl+Shift+F6)"
				} 
				AddWidget(oLblMainFile)
				AddWidget(this.oTxtMainFile)
				AddWidget(oBtnSetFile)
				AddWidget(oBtnDebugMainFile)
				AddWidget(oBtnRunMainFile)
				AddWidget(oBtnRunGUIMainFile)
				AddWidget(oBtnRunWebMainFile)
			}
		}
	
	func CreateMenubar 
		win1 {
				menu1 = new qmenubar(this.win1) {
					subFile 	= addmenu(T_RINGNOTEPAD_FILE) # "File"
					subEdit 	= addmenu(T_RINGNOTEPAD_EDIT) # "Edit"
					subView 	= addmenu(T_RINGNOTEPAD_VIEW) # "View"
					subProgram 	= addmenu(T_RINGNOTEPAD_PROGRAM) # "Program"
					subBrowser 	= addmenu(T_RINGNOTEPAD_BROWSER) # "Browser"
					subTools 	= addmenu(T_RINGNOTEPAD_TOOLS) # "Tools"
					subDistribute   = addmenu(T_RINGNOTEPAD_DISTRIBUTE) # "Distribute"
					subHelp 	= addmenu(T_RINGNOTEPAD_HELP) # "Help"
					subFile {
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+n"))
							setbtnimage(self,"image/new.png")
							settext(T_RINGNOTEPAD_NEW) # "New"
							setclickEvent(Method(:NewFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+o"))
							setbtnimage(self,"image/open.png")
							settext(T_RINGNOTEPAD_OPEN) # "Open"
							setclickEvent(Method(:Open))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+s"))
							setbtnimage(self,"image/save.png")
							settext(T_RINGNOTEPAD_SAVE) # "Save"
							setclickEvent(Method(:Save))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+e"))
							setbtnimage(self,"image/saveas.png")
							settext(T_RINGNOTEPAD_SAVEAS) # "Save As"
							setclickEvent(Method(:SaveAs))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+p"))
							setbtnimage(self,"image/print.png")
							settext(T_RINGNOTEPAD_PRINTTOPDF) # "Print to PDF"
							setclickEvent(Method(:Print))
						}
						addaction(oAction)
						addseparator()
						oAction = new qaction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+q"))
							setbtnimage(self,"image/closeapp.png")
							settext(T_RINGNOTEPAD_EXIT) # "Exit"
							setstatustip(T_RINGNOTEPAD_EXIT)
							setclickEvent(Method(:Quit))
						}
						addaction(oAction)
					}
					subEdit {
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+z"))
							setbtnimage(self,"image/undo.png")
							settext(T_RINGNOTEPAD_UNDO) # "Undo"
							setclickEvent(Method(:Undo))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+x"))
							setbtnimage(self,"image/cut.png")
							settext(T_RINGNOTEPAD_CUT) # "Cut"
							setclickEvent(Method(:Cut))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+c"))
							setbtnimage(self,"image/copy.png")
							settext(T_RINGNOTEPAD_COPY) # "Copy"
							setclickEvent(Method(:CopyText))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+v"))
							setbtnimage(self,"image/paste.png")
							settext(T_RINGNOTEPAD_PASTE) # "Paste"
							setclickEvent(Method(:Paste))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+i"))
							setbtnimage(self,"image/font.png")
							settext(T_RINGNOTEPAD_FONT) # "Font"
							setclickEvent(Method(:Font))
						}
						addseparator()
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+t"))
							setbtnimage(self,"image/colors.png")
							settext(T_RINGNOTEPAD_TEXTCOLOR) # "Text Color"
							setclickEvent(Method(:SelectColor))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+b"))
							setbtnimage(self,"image/colors.png")
							settext(T_RINGNOTEPAD_BACKCOLOR) # "Back Color"
							setclickEvent(Method(:SelectColor2))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+h"))
							settext(T_RINGNOTEPAD_SETTABWIDTH) # "Set Tab Width"
							setclickEvent(Method(:TabWidth))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+g"))
							settext(T_RINGNOTEPAD_GOTOLINE) # "Go to line"
							setclickEvent(Method(:Goto))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+f"))
							setbtnimage(self,"image/search.png")
							settext(T_RINGNOTEPAD_FINDANDREPLACE) # "Find and Replace"
							setclickEvent(Method(:OpenFindWindow))
						}
						addaction(oAction)
						addseparator()
                        oAction = new qAction(this.win1) {
                            setShortcut(new QKeySequence("Ctrl+Shift+i"))
                            settext(T_RINGNOTEPAD_INSERTTEXT) # "Insert Text"
                            setclickEvent(Method(:OpenInsertWindow))
                        }
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+L"))
							settext(T_RINGNOTEPAD_LOWERCASE) # "Lower case"
							setclickEvent(Method(:lowerCase))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+U"))
							settext(T_RINGNOTEPAD_UPPERCASE) # "Upper case"
							setclickEvent(Method(:upperCase))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+C"))
							settext(T_RINGNOTEPAD_CAPITALIZE) # "Capitalize"
							setclickEvent(Method(:capitalize))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+alt+C"))
							setbtnimage(self,"image/comment2.png")
							settext(T_RINGNOTEPAD_COMMENTLINES) # "Comment Lines"
							setclickEvent(Method(:CommentLines))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+alt+B"))
							setbtnimage(self,"image/comment.png")
							settext(T_RINGNOTEPAD_COMMENTBLOCKOFLINES) # "Comment Block Of Lines"
							setclickEvent(Method(:CommentBlockLines))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+alt+f"))
							setbtnimage(self,"image/search.png")
							settext(T_RINGNOTEPAD_FINDINFILES) # "Find in Files"
							setclickEvent(Method(:OpenFindInFiles))
						}
						addaction(oAction)
	
					}
					subView {

						subActivate = addmenu(T_RINGNOTEPAD_ACTIVATE) # "Activate"
						subActivate {	
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Alt+p"))
								setbtnimage(self,"image/project.png")
								settext(T_RINGNOTEPAD_PROJECTFILES) # "Project Files"
								setclickEvent(Method(:ActivateProjectWindow))
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Alt+s"))
								setbtnimage(self,"image/source.png")
								setclickEvent(Method(:ActivateSourceCodeWindow))
								settext(T_RINGNOTEPAD_SOURCECODE) # "Source Code"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Alt+w"))
								setbtnimage(self,"image/richtext.png")
								setclickEvent(Method(:ActivateWebBrowserWindow))
								settext(T_RINGNOTEPAD_WEBBROWSER) # "Web Browser"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Alt+f"))
								setbtnimage(self,"image/source.png")
								setclickEvent(Method(:ActivateFunctionsListWindow))
								settext(T_RINGNOTEPAD_FUNCTIONSLIST) # "Functions List"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Alt+c"))
								setbtnimage(self,"image/source.png")
								setclickEvent(Method(:ActivateClassesListWindow))
								settext(T_RINGNOTEPAD_CLASSESLIST) # "Classes List"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Alt+o"))
								setbtnimage(self,"image/source.png")
								setclickEvent(Method(:ActivateOutputWindow))
								settext(T_RINGNOTEPAD_OUTPUTWINDOW) # "Output Window"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Alt+d"))
								setbtnimage(self,"image/formdesigner.png")
								setclickEvent(Method(:ActivateFormDesignerWindow))
								settext(T_RINGNOTEPAD_FORMDESIGNERWINDOW) # "Form Designer Window"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setbtnimage(self,"image/open.png")
								setShortcut(new QKeySequence("Alt+l"))
								settext(T_RINGNOTEPAD_SELECTFILEOPTION) # "Select File"
								setclickEvent(Method(:OpenSelectFileWindow))
							}
							addaction(oAction)
						}
						addseparator()

						subAppearance = addmenu(T_RINGNOTEPAD_APPEARANCE) # "Appearance"
						subAppearance {	
							this.oCheckAction1 = new qAction(this.win1) {
								setCheckable(True)
								setChecked(this.lShowProject)
								settext(T_RINGNOTEPAD_PROJECTFILES) # "Project Files"
								setclickEvent(Method(:ProjectWindowStatus))
							}
							addaction(this.oCheckAction1)
							addseparator()
							this.oCheckAction2 = new qAction(this.win1) {
								setCheckable(True)
								setChecked(this.lShowSourceCode)
								setclickEvent(Method(:SourceCodeWindowStatus))
								settext(T_RINGNOTEPAD_SOURCECODE) # "Source Code"
							}
							addaction(this.oCheckAction2)
							addseparator()
							this.oCheckAction3 = new qAction(this.win1) {
								setCheckable(True)
								setChecked(this.lShowBrowser)
								setclickEvent(Method(:WebBrowserWindowStatus))
								settext(T_RINGNOTEPAD_WEBBROWSER) # "Web Browser"
							}
							addaction(this.oCheckAction3)
							addseparator()
							this.oCheckAction4 = new qAction(this.win1) {
								setCheckable(True)
								setChecked(this.lShowFunctionsList)
								setclickEvent(Method(:FunctionsListWindowStatus))
								settext(T_RINGNOTEPAD_FUNCTIONSLIST) # "Functions List"
							}
							addaction(this.oCheckAction4)
							addseparator()
							this.oCheckAction5 = new qAction(this.win1) {
								setCheckable(True)
								setChecked(this.lShowClassesList)
								setclickEvent(Method(:ClassesListWindowStatus))
								settext(T_RINGNOTEPAD_CLASSESLIST) # "Classes List"
							}
							addaction(this.oCheckAction5)
							addseparator()
							this.oCheckAction6 = new qAction(this.win1) {
								setCheckable(True)
								setChecked(this.lShowOutputWindow)
								setclickEvent(Method(:OutputWindowStatus))
								settext(T_RINGNOTEPAD_OUTPUTWINDOW) # "Output Window"
							}
							addaction(this.oCheckAction6)
							addseparator()
							this.oCheckAction7 = new qAction(this.win1) {
								setCheckable(True)
								setChecked(this.lShowFormDesigner)
								setclickEvent(Method(:FormDesignerWindowStatus))
								settext(T_RINGNOTEPAD_FORMDESIGNERWINDOW) # "Form Designer Window"
							}
							addaction(this.oCheckAction7)
						}
						addseparator()
						subMode = addmenu(T_RINGNOTEPAD_MODE) # "Mode"
						subMode {
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+1"))
								setclickEvent(Method("SetMode(1)"))
								settext(T_RINGNOTEPAD_GENERAL) # "General"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+2"))
								setclickEvent(Method("SetMode(2)"))
								settext(T_RINGNOTEPAD_LEARNINGRINGEDITORDOCUMENTATION) # "Learning Ring (Editor + Documentation)"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+3"))
								setclickEvent(Method("SetMode(3)"))
								settext(T_RINGNOTEPAD_CODINGPROJECTFILEEDITOR) # "Coding (Project File + Editor)"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+4"))
								setclickEvent(Method("SetMode(4)"))
								settext(T_RINGNOTEPAD_CODINGALLWINDOWS) # "Coding (All Windows)"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+5"))
								setclickEvent(Method("SetMode(5)"))
								settext(T_RINGNOTEPAD_CODINGCODEEDITOR) # "Coding (Code Editor)"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+6"))
								setclickEvent(Method("SetMode(6)"))
								settext(T_RINGNOTEPAD_GUIDEVELOPMENTCODEEDITORFORMDESIGNER) # "GUI Development (Code Editor + Form Designer)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+7"))
								setclickEvent(Method("SetMode(7)"))
								settext(T_RINGNOTEPAD_WEBDEVELOPMENTCODEEDITORWEBBROWSER) # "Web Development (Code Editor + Web Browser)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+8"))
								setclickEvent(Method("SetMode(8)"))
								settext(T_RINGNOTEPAD_TESTINGPROJECTFILESCODEEDITOROUTPUTWINDOW) # "Testing (Project Files + Code Editor + Output Window)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+9"))
								setclickEvent(Method("SetMode(9)"))
								settext(T_RINGNOTEPAD_COMMONALLWINDOWSOUTPUTWINDOWINTHEBOTTOM) # "Common (All Windows + Output Window in the bottom)")
							}
							addaction(oAction)
						}
						subStyle = addmenu(T_RINGNOTEPAD_STYLE) # "Style"
						subStyle {
							setbtnimage(self,"image/colors.png")
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+W"))
								setclickEvent(Method("SetStyleColor(0)"))
								settext(T_RINGNOTEPAD_WINDOWS) # "Windows"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+2"))
								setclickEvent(Method("SetStyleColor(1)"))
								settext(T_RINGNOTEPAD_FUSIONWHITE) # "Fusion : White"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+3"))
								setclickEvent(Method("SetStyleColor(2)"))
								settext(T_RINGNOTEPAD_FUSIONBLUE) # "Fusion : Blue"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+4"))
								setclickEvent(Method("SetStyleColor(3)"))
								settext(T_RINGNOTEPAD_FUSIONBLACK) # "Fusion : Black"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+5"))
								setclickEvent(Method("SetStyleColor(4)"))
								settext(T_RINGNOTEPAD_MODERN) # "Modern"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+6"))
								setclickEvent(Method("SetStyleColor(5)"))
								settext(T_RINGNOTEPAD_MODERNBLACK) # "Modern : Black"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+7"))
								setclickEvent(Method("SetStyleColor(6)"))
								settext(T_RINGNOTEPAD_MODERNBLACK2) # "Modern : Black 2"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+8"))
								setclickEvent(Method("SetStyleColor(7)"))
								settext(T_RINGNOTEPAD_NOTEPADWHITE) # "Notepad : White"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+9"))
								setclickEvent(Method("SetStyleColor(8)"))
								settext(T_RINGNOTEPAD_NOTEPADPURPLE) # "Notepad : Purple"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+A"))
								setclickEvent(Method("SetStyleColor(9)"))
								settext(T_RINGNOTEPAD_NOTEPADDARKBLUE) # "Notepad : DarkBlue"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F7"))
								setclickEvent(Method("SetStyleColor(10)"))
								settext(T_RINGNOTEPAD_NOTEPADBLACK) # "Notepad : Black"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F8"))
								setclickEvent(Method("SetStyleColor(11)"))
								settext(T_RINGNOTEPAD_ART) # "Art"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F9"))
								setclickEvent(Method("SetStyleColor(12)"))
								settext(T_RINGNOTEPAD_ART2) # "Art 2"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F10"))
								setclickEvent(Method("SetStyleColor(13)"))
								settext(T_RINGNOTEPAD_ART3) # "Art 3"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F11"))
								setclickEvent(Method("SetStyleColor(14)"))
								settext(T_RINGNOTEPAD_IMAGE) # "Image"
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F12"))
								setclickEvent(Method("SetStyleColor(15)"))
								settext(T_RINGNOTEPAD_IMAGE2) # "Image 2"
							}
							addaction(oAction)
						}
						addseparator()
						oAction = new qAction(this.win1) {
							setclickEvent(Method(:EditFullScreen))
							setbtnimage(self,"image/source.png")
							setShortcut(new QKeySequence("Ctrl+Shift+F1"))
							settext(T_RINGNOTEPAD_SOURCECODEFULLSCREEN) # "Source Code (Full Screen)"
						}
						addaction(oAction)
						addseparator()
					} 
					subProgram {
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+d"))
							setbtnimage(self,"image/debug.png")
							settext(T_RINGNOTEPAD_DEBUGRUNTHENWAIT) # "Debug (Run then wait!)"
							setclickEvent(Method(:Debug))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+r"))
							setbtnimage(self,"image/run.png")
							settext(T_RINGNOTEPAD_RUN) # "Run"
							setclickEvent(Method(:Run))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+F5"))
							setbtnimage(self,"image/rungui.png")
							settext(T_RINGNOTEPAD_RUNGUIAPPLICATIONNOCONSOLE) # "Run GUI Application (No Console)"
							setclickEvent(Method(:RunNoConsole))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+F6"))
							setbtnimage(self,"image/web.png")
							settext(T_RINGNOTEPAD_RUNWEBAPPLICATIONOPENINBROWSER) # "Run Web Application (Open In Browser)"
							setclickEvent(Method(:RunInBrowser))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+M"))
							setbtnimage(self,"image/open.png")
							settext(T_RINGNOTEPAD_SETTHEMAINFILETOBETHECURRENTSOURCEFILE) # "Set the Main File to be the current source file"
							setclickEvent(Method(:SetMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+d"))
							setbtnimage(self,"image/debug.png")
							settext(T_RINGNOTEPAD_MAINFILEDEBUGRUNTHENWAIT) # "Main File : Debug (Run then wait!)"
							setclickEvent(Method(:DebugMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+r"))
							setbtnimage(self,"image/run.png")
							settext(T_RINGNOTEPAD_MAINFILERUN) # "Main File : Run"
							setclickEvent(Method(:RunMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+F5"))
							setbtnimage(self,"image/rungui.png")
							settext(T_RINGNOTEPAD_MAINFILERUNGUIAPPLICATIONNOCONSOLE) # "Main File : Run GUI Application (No Console)"
							setclickEvent(Method(:RunGUIMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+F6"))
							setbtnimage(self,"image/web.png")
							settext(T_RINGNOTEPAD_MAINFILERUNWEBAPPLICATIONOPENINBROWSER) # "Main File : Run Web Application (Open In Browser)"
							setclickEvent(Method(:RunInBrowserMainFile))
						}
						addaction(oAction)
					}  
					subBrowser {
						for x=1 to len(this.aBrowserLinks)
							item = this.aBrowserLinks[x]
							oAction = new qAction(this.win1) {
								settext(item[1])
								setclickEvent(Method(:BrowserLink+"("+x+")"))
							}
							addaction(oAction)
							if x != len(this.aBrowserLinks)
								addseparator()
							ok
						next
					}
					subTools {
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_FORMDESIGNER) # "Form Designer"
							setclickEvent(Method(:OpenFormDesigner))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+R"))
							settext(T_RINGNOTEPAD_RINGREPLCONSOLE) # "RingREPL - Console"
							setclickEvent(Method(:REPLConsole))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+Shift+R"))
							settext(T_RINGNOTEPAD_RINGREPLGUI) # "RingREPL - GUI"
							setclickEvent(Method(:REPLGUI))
						}
						addaction(oAction)
						addseparator()
						subOSTools = addmenu(T_RINGNOTEPAD_OPERATINGSYSTEMTOOLS) # "Operating System Tools"
						subOSTools {
							oAction = new qAction(this.win1) {
								settext(T_RINGNOTEPAD_TERMINALCOMMANDPROMPT) # "Terminal (Command Prompt)"
								setShortcut(new QKeySequence("Alt+Shift+T"))
								setclickEvent(Method(:OSTerminal))
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								settext(T_RINGNOTEPAD_FILESMANAGEREXPLORER) # "Files Manager (Explorer)"
								setShortcut(new QKeySequence("Alt+Shift+F"))
								setclickEvent(Method(:OSFilesManager))
							}
							addaction(oAction)
						}
					}
					subDistribute {
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_GENERATERINGOBJECTFILE) # "Generate Ring Object File (*.ringo)"
							setclickEvent(Method("Distribute(1)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEBUILDCONSOLEAPPLICATION) # "Ring2EXE (Build Console Application)"
							setclickEvent(Method("Distribute(2)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEBUILDGUIAPPLICATION) # "Ring2EXE (Build GUI Application)"
							setclickEvent(Method("Distribute(10)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEDISTRIBUTEAPPLICATIONUSEALLRUNTIME) # "Ring2EXE (Distribute Application - Use All Runtime)"
							setclickEvent(Method("Distribute(3)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEDISTRIBUTEAPPLICATIONUSEALLRUNTIMEHIDECONSOLEWINDOW) "Ring2EXE (Distribute Application - Use All Runtime - Hide Console Window)"
							setclickEvent(Method("Distribute(4)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEDISTRIBUTERINGQTAPPLICATION) # "Ring2EXE (Distribute RingQt Application)"
							setclickEvent(Method("Distribute(5)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEDISTRIBUTERINGALLEGROGAME) # "Ring2EXE (Distribute RingAllegro Game)"
							setclickEvent(Method("Distribute(6)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEDISTRIBUTELIGHTRINGQTAPPLICATION) # "Ring2EXE (Distribute Light RingQt Application - Using [QtCore, QtGui, QtWidgets])"
							setclickEvent(Method("Distribute(9)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEPREPAREQTPROJECTDISTRIBUTEFORMOBILEDEVICES) # "Ring2EXE (Prepare Qt Project - Distribute for Mobile Devices)")
							setclickEvent(Method("Distribute(7)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_RING2EXEPREPAREQTPROJECTDISTRIBUTEFORWEBASSEMBLY) # "Ring2EXE (Prepare Qt Project - Distribute for Web Browsers using WebAssembly)")
							setclickEvent(Method("Distribute(8)"))
						}
						addaction(oAction)
					}
					subHelp {
						subHelpLF = addmenu(T_RINGNOTEPAD_LANGUAGEREFERENCE) # "Language Reference"
						subHelpLF {
							oAction = new qAction(this.win1) {
								settext(T_RINGNOTEPAD_CHMFILE) # "CHM File"
								setclickEvent(Method(:OpenCHM))
							}
							addaction(oAction)
							oAction = new qAction(this.win1) {
								settext(T_RINGNOTEPAD_PDFFILE) # "PDF File"
								setclickEvent(Method(:OpenPDF))
							}
							addaction(oAction)
						}
						addseparator()
						subHelpTools = addmenu(T_RINGNOTEPAD_DEVELOPMENTTOOLS) # "Development Tools"
						subHelpTools {
	
							oAction = new qAction(this.win1) {
								settext(T_RINGNOTEPAD_PROGRAMMINGLANGUAGE) # "Programming Language"
								setclickEvent(Method(:Lang))
							}
							addaction(oAction)
							oAction = new qAction(this.win1) {
								settext(T_RINGNOTEPAD_GUILIBRARY) # "GUI Library"
								setclickEvent(Method(:GUI))
							}
							addaction(oAction)
						}
						addseparator()
						oAction = new qAction(this.win1) {
							settext(T_RINGNOTEPAD_ABOUT) # "About"
							setclickEvent(Method(:pAbout))
						}
						addaction(oAction)
					}
				}
				setmenubar(menu1)
		}

	func CreateStatusbar
		win1 {
			this.status1 = new qstatusbar(this.win1) {
				showmessage(T_RINGNOTEPAD_READY,0) # "Ready!"
			}
			setstatusbar(this.status1)
		}

	func StatusMessage cMsg
		status1.showmessage(cMsg,0)

	func CreateProjectFiles
		win1 {
			this.tree1 = new qtreeview(this.win1) {
				setStylesheet("font-size: 30")
				setclickedEvent(Method(:ChangeFile))
				setActivatedEvent(Method(:ChangeFile))
				setGeometry(0,0,200,400)
				setminimumwidth(floor(this.oDesktop.width()*this.oDesktop.nProjectFilesPer))
                		chdir(this.cStartUpFolder)
				oDir = new QDir()
				this.ofile = new QFileSystemModel() {
					setrootpath(oDir.currentpath())
					myfiles = new qstringlist() {
						append("*.ring")
						append("*.rh")
						append("*.rform")
						append("*.txt")
						append("*.html")
						append("*.rhtml")
						append("*.css")
						append("*.js")
						append("*.xml")
						append("*.data")
						append("*.template")
						append("*.sh")
						append("*.bat")
						append("*.md")
						append("*.cf")
						append("*.qml")
						append("*.ini")
						append("*.qrc")
						append("*.رينج")
					}
					setnamefilters(myfiles)
					setNameFilterDisables(false)
				}
				setmodel(this.ofile)
				myindex = this.ofile.index(oDir.currentpath(),0)
				for x = 1 to this.ofile.columncount()
					hidecolumn(x)
				next
				setcurrentindex(myindex)
				setexpanded(myindex,true)
				header().hide()
				chdir(exefolder())
				this.cWebsite = this.GetHelpURL()
			}
			this.oDockProjectFiles = new qdockwidget(this.win1,0) {
				myFilter = new qAllEvents(this.oDockProjectFiles)
				myFilter.setCloseEvent(Method("CloseDockable(1)"))
				installEventFilter(myFilter)
				setGeometry(00,00,200,200)
				setwindowtitle(T_RINGNOTEPAD_PROJECTFILES) # "Project Files"
				setwidget(this.tree1)
			}
		}

	func CreateSourceCode
		win1 {
			oTabsFilter = new qAllEvents(this.win1) {
				setContextmenuEvent(Method(:TabsContextMenu))
	                }

			this.filestabs = new qTabWidget(this.win1) {
				setFixedheight(35)
				settabsclosable(True)
				AddTab(new qWidget(),T_RINGNOTEPAD_NONAME) # "noname"
				setcurrentchangedevent(Method(:ChangeFileTab))
				Settabcloserequestedevent(Method(:CloseFileTab))
				installeventfilter(oTabsFilter)
			}

			if T_RINGNOTEPAD_LAYOUTDIRECTION
				this.textedit1 = new RingNotepadQTextEdit(this.win1) 
			else 
				this.textedit1 = new CodeEditor(this.win1) 
			ok

			this.textedit1 {
				setCursorPositionChangedEvent(Method(:CursorPositionChanged))
				setTextChangedEvent(Method(:TextChanged))
				# Not supported by QTextEdit 
					setLineWrapMode(QTextEdit_NoWrap)
					setLineNumbersAreaColor(this.aStyleColors[:LineNumbersAreaColor])
					setLineNumbersAreaBackColor(this.aStyleColors[:LineNumbersAreaBackColor])
				this.oFilterTextEdit = new qAllEvents(this.win1)
				this.oFilterTextEdit.setkeypressevent(Method(:TextEditKeyPress))
				installEventFilter(this.oFilterTextEdit)
			}

			this.AutoComplete()
			this.oACTimer = new qtimer(this.win1) {
				setinterval(5000)
				settimeoutevent(Method(:AutoCompleteTimer))
				start()
			}

			this.ApplySyntaxColors()

			this.oTabsAndText = new qWidget() {
				this.oLayoutTabsText = new qVBoxlayout() {
					AddWidget(this.filestabs)
					AddWidget(this.textedit1)
					setContentsMargins(0,0,0,0)
					setspacing(0)
				}
				setLayout(this.oLayoutTabsText)
			}
			this.oDockSourceCode = new qdockwidget(this.win1,0) {
				myFilter = new qAllEvents(this.oDockSourceCode)
				myFilter.setCloseEvent(Method("CloseDockable(2)"))
				installEventFilter(myFilter)
				setwidget(this.oTabsAndText)
				setwindowtitle(T_RINGNOTEPAD_SOURCECODE) # "Source Code"
				setminimumwidth(floor(this.oDesktop.width()*0.17))                                                     
			}
		}

	func ApplySyntaxColors 
		new RingCodeHighLighter(this.textedit1.document() ) {
			if ismethod(self,:setkeywordsbold) 
				setKeywordsbold(this.lKeywordsBold)
			ok
			if len(T_RINGNOTEPAD_CUSTOMKEYWORDS)
				mykeywords = new QStringList() {
					for cKeyword in T_RINGNOTEPAD_CUSTOMKEYWORDS
						append("\b"+cKeyword+"\b")
					next
				}
				setCustomKeywords(mykeywords)
			ok
			setColors(
				this.aStyleColors[:SyntaxKeywordsColor],
				this.aStyleColors[:SyntaxClassNamesColor],
				this.aStyleColors[:SyntaxCommentsColor],
				this.aStyleColors[:SyntaxLiteralsColor],
				this.aStyleColors[:SyntaxFunctionCallsColor]
			)
		}

	func CreateWebBrowser
		win1 {
			this.oWebBrowser = new qWidget() {
				setWindowFlags(Qt_SubWindow)
				oWBLabel = new qLabel(this.win1) {
					setText(T_RINGNOTEPAD_WEBSITE) # "Website: "
				}
				this.oWBText = new qLineEdit(this.win1) {
					setText(this.cWebSite)
					setReturnPressedEvent(Method(:WebGo))
				}
				oWBGo = new qPushButton(this.win1) {
					setText(T_RINGNOTEPAD_GO) # "Go"
					setClickEvent(Method(:WebGo))
				}
				oWBBack = new qPushButton(this.win1) {
					setText(T_RINGNOTEPAD_BACK) # "Back"
					setClickEvent(Method(:WebBack))
				}
				oWBLayout1 = new qHBoxLayout() {
					addWidget(oWBLabel)
					addWidget(this.oWBText)
					addWidget(oWBGo)
					addWidget(oWBBack)
				}
				this.oWebView = new qWebView(this.win1) {
					loadpage(new qurl(this.cWebSite))
				}
				oWBlayout2 = new qVBoxLayout() {
					addLayout(oWBLayout1)
					addWidget(this.oWebView)
				}
				setLayout(oWBLayout2)
			}
			this.oDockWebBrowser = new qdockwidget(this.win1,0) {
				myFilter = new qAllEvents(this.oDockWebBrowser)
				myFilter.setCloseEvent(Method("CloseDockable(3)"))
				installEventFilter(myFilter)
				setwidget(this.oWebBrowser)
				setwindowtitle(T_RINGNOTEPAD_WEBBROWSER) # "Web Browser"
			}
		}

	func CreateFunctionsList
		win1 {
			this.aFunctionsPos = []	# Lines Numbers for each function
			this.oFunctionsList = new qListwidget(this.win1) {
				setitemdoubleclickedEvent(Method(:SelectFunction))
				setitemactivatedEvent(Method(:SelectFunction))
			}
			this.oDockFunctionsList = new qDockwidget(this.win1,0) {
				myFilter = new qAllEvents(this.oDockFunctionsList)
				myFilter.setCloseEvent(Method("CloseDockable(4)"))
				installEventFilter(myFilter)
				setWidget(this.oFunctionsList)
				setwindowtitle(T_RINGNOTEPAD_FUNCTIONS) # "Functions"
			}
		}

	func CreateClassesList
		win1 {
			this.aClassesPos = []	# Lines Numbers for each class
			this.oClassesList = new qListwidget(this.win1) {
				setitemdoubleclickedEvent(Method(:SelectClass))
				setitemactivatedEvent(Method(:SelectClass))
			}
			this.oDockClassesList = new qDockwidget(this.win1,0) {
				myFilter = new qAllEvents(this.oDockClassesList)
				myFilter.setCloseEvent(Method("CloseDockable(5)"))
				installEventFilter(myFilter)
				setWidget(this.oClassesList)
				setwindowtitle(T_RINGNOTEPAD_CLASSES) # "Classes"
			}
		}

	func CreateOutputWindow
		win1 {
			this.oProcess = NULL
			this.oOutputWindow = new qWidget()
			oProcessLabel = new qLabel(this.oOutputWindow) {
				setText(T_RINGNOTEPAD_INPUT) # "Input :"
			}
			this.oProcessText = new qlineEdit(this.oOutputWindow) {
				setreturnPressedEvent(Method(:SendProcessData))
			}
			oProcessbtnSend = new qpushbutton(this.oOutputWindow) {
				setText(T_RINGNOTEPAD_SEND) # "Send"
				setClickEvent(Method(:SendProcessData))
			}
			oClearbtn = new qpushbutton(this.oOutputWindow) {
				settooltip(T_RINGNOTEPAD_CLEAROUTPUTSTOPRUNNINGPROGRAM) # "Clear output/Stop running program"
				setbtnimage(self,this.cCurrentDir+"/image/pause.png")
				setmaximumwidth(100)
				setClickevent(Method(:ClearProcess))
			}
			oProcessLayout1 = new qhboxlayout() {
				AddWidget(oProcessLabel)
				AddWidget(this.oProcessText)
				Addwidget(oProcessbtnSend)
                		Addwidget(oClearbtn)
			}
			this.oProcessEditbox = new QPlaintextedit(this.oOutputWindow)  {
				if T_RINGNOTEPAD_LAYOUTDIRECTION
					document().setdefaulttextoption(new qtextoption(Qt_AlignRight))
				ok
			}
			oProcessLayout2 = new qvboxlayout() {
				addWidget(this.oProcesseditbox)
				addlayout(oProcesslayout1)
			}
			this.oOutputWindow.setlayout(oProcessLayout2)
			this.oDockOutputWindow = new qDockWidget(this.win1,0) {
				myFilter = new qAllEvents(this.oDockOutputWindow)
				myFilter.setCloseEvent(Method("CloseDockable(6)"))
				installEventFilter(myFilter)
				setwidget( this.oOutputWindow )
				setwindowtitle(T_RINGNOTEPAD_OUTPUT) # "Output"
			}
			
		}

	func CreateFormDesigner
		win1 {
			this.oDockFormDesigner = new qDockwidget(this.win1,0) {
				myFilter = new qAllEvents(this.oDockFormDesigner)
				myFilter.setCloseEvent(Method("CloseDockable(7)"))
				installEventFilter(myFilter)
				setwindowtitle(T_RINGNOTEPAD_FORMDESIGNER) # "Form Designer"
			}
			this.FormDesignerDock()
		}

	func PrepareDockableWindows
		win1 {
			adddockwidget(Qt_LeftDockWidgetArea,this.oDockProjectFiles,1)
			adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,2)
			adddockwidget(Qt_RightDockWidgetArea,this.oDockFunctionsList,1)
			adddockwidget(Qt_RightDockWidgetArea,this.oDockClassesList,1)
			adddockwidget(Qt_RightDockWidgetArea,this.oDockWebBrowser,1)
			adddockwidget(Qt_BottomDockWidgetArea,this.oDockOutputWindow,1)
			adddockwidget(Qt_RightDockWidgetArea,this.oDockFormDesigner,1)
			this.win1 {
				tabifydockwidget(this.oDockFunctionsList,this.oDockClassesList)
				tabifydockwidget(this.oDockFunctionsList,this.oDockOutputWindow)
				tabifydockwidget(this.oDockSourceCode,this.oDockFormDesigner)
				tabifydockwidget(this.oDockSourceCode,this.oDockWebBrowser)
			}
			this.oDockSourceCode.raise()
			this.oDockFunctionsList.raise()
		}

	func RingNotepadXButton
		SaveSettings()
		oApp.Quit()

	func EditFullScreen
		if lEditboxFullScreen 
			oDockSourceCode { show() raise() }
			textedit1.setParent(oTabsAndText)
			oLayoutTabsText.AddWidget(textedit1)
			textedit1 { show() setfocus(7) }
			this.win1.show() 
			ActivateSourceCodeWindow()
		else 
			oDockSourceCode.hide()
			textedit1 { 
				setParent(NULL)
				showfullscreen()
				setfocus(7)
			}
			this.win1.hide()
		ok
		lEditboxFullScreen = ! lEditboxFullScreen 

	func TextEditKeyPress
		nKeyCode  = this.oFilterTextEdit.getkeycode()
		nModifier = this.oFilterTextEdit.getModifiers()
		K_Ctrl    = 67108864

		# Check CTRL+SHIFT+F1
		if lEditboxFullScreen 
			if nKeyCode = Qt_Key_Escape
				EditFullScreen()
				return
			but nModifier = K_Ctrl 
				if nKeyCode = Qt_Key_G 
					GoTo()
					return
				but nKeyCode = Qt_Key_F
					OpenFindWindow()
					return
				but nKeyCode = Qt_Key_H
					TabWidth()
					return
				ok 			
			ok
		ok
		this.oFilterTextEdit.setEventoutput(False)


class RingNotepadQTextEdit from QTextEdit 

	func init oParent 
		super.init(oParent) 
		return self

	func setLineWrapMode p1
	func setLineNumbersAreaColor p1
	func setLineNumbersAreaBackColor p1
	func setCompleter p1

class RNoteDesktop

	oDeskWidget = new QDesktopWidget()
	nDeskWidgetWidth  = oDeskWidget.width()
	nDeskWidgetHeight = oDeskWidget.height()

	if nDeskWidgetWidth >= 1920
		nProjectFilesPer = 0.2
	else 
		nProjectFilesPer = 0.26
	ok

	func width 
		return min(1920,nDeskWidgetWidth)

	func height 
		return min(1080,nDeskWidgetHeight)

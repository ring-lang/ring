# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteMainWindow

	func CreateMainWindow 

		oDesktop = new qDesktopWidget()

		win1 = new qMainWindow() {
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
						settooltip("New File (Ctrl+N)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/open.png")
						setclickEvent(Method(:Open))
						settooltip("Open File (Ctrl+O)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/save.png")
						setclickEvent(Method(:Save))
						settooltip("Save (Ctrl+S)")
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/saveas.png")
						setclickEvent(Method(:SaveAs))
						settooltip("Save As (Ctrl+E)")
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/undo.png")
						setclickEvent(Method(:Undo))
						settooltip("Undo (Ctrl+Z)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/cut.png")
						setclickEvent(Method(:Cut))
						settooltip("Cut (Ctrl+X)")
					 } ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/copy.png")
						setclickEvent(Method(:CopyText))
						settooltip("Copy (Ctrl+C)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/paste.png")
						setclickEvent(Method(:Paste))
						settooltip("Paste (Ctrl+V)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/font.png")
						setclickEvent(Method(:Font))
						settooltip("Font (Ctrl+I)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/search.png")
						setclickEvent(Method(:OpenFindWindow))
						settooltip("Find and Replace (Ctrl+F)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/print.png")
						setclickEvent(Method(:Print))
						settooltip("Print (Ctrl+P)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/debug.png")
						setclickevent(Method(:Debug)) 
						settooltip("Debug - Run then wait! (Ctrl+D)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/run.png")
						setclickEvent(Method(:Run))
						settooltip("Run the program (Ctrl+R) ")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/rungui.png")
						setclickEvent(Method(:RunNoConsole))
						settooltip("Run GUI Application - No Console (Ctrl+F5)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/web.png")
						setclickEvent(Method(:RunInBrowser))
						settooltip("Run Web Application - Open In Browser (Ctrl+F6)")
					} ,
					new qtoolbutton(this.win1) {
						setbtnimage(self,"image/close.png")
						setclickEvent(Method(:Quit))
						settooltip("Quit (Ctrl+Q)")
					}
				]
	
			tool1 = addtoolbar("files")  {
				for x in aBtns addwidget(x) addseparator() next
			}
	
			# Main File Toolbar
			tool2 = addtoolbar("mainfile")  {
				oLblMainFile = new qLabel(this.win1) {
					setText("Main File : ")
				}
				this.oTxtMainFile = new qLineEdit(this.win1) {
					setStylesheet("border: 0px;  background-color: rgba(0, 0, 0, 0);")
					setReadOnly(True)
				}
				oBtnSetFile = new qtoolbutton(this.win1) {
					setbtnimage(self,"image/open.png")
					setclickEvent(Method(:SetMainFile))
					settooltip("Set the Main File to be the current source file (Ctrl+Shift+M)")
				}
				oBtnDebugMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/debug.png")
						setclickevent(Method(:DebugMainFile)) 
						settooltip("Main File : Debug  - Run then wait! (Ctrl+Shift+D)")
				} 
				oBtnRunMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/run.png")
						setclickEvent(Method(:RunMainFile))
						settooltip("Main File : Run the program (Ctrl+Shift+R)")
				} 
				oBtnRunGUIMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/rungui.png")
						setclickEvent(Method(:RunGUIMainFile))
						settooltip("Main File : Run GUI Application - No Console (Ctrl+Shift+F5)")
				} 
				oBtnRunWebMainFile = new qtoolbutton(this.win1) {
						setbtnimage(self,"image/web.png")
						setclickEvent(Method(:RunInBrowserMainFile))
						settooltip("Main File : Run Web Application - Open In Browser (Ctrl+Shift+F6)")
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
							setbtnimage(self,"image/close.png")
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
							settext("Undo")
							setclickEvent(Method(:Undo))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+x"))
							setbtnimage(self,"image/cut.png")
							settext("Cut")
							setclickEvent(Method(:Cut))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+c"))
							setbtnimage(self,"image/copy.png")
							settext("Copy")
							setclickEvent(Method(:CopyText))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+v"))
							setbtnimage(self,"image/paste.png")
							settext("Paste")
							setclickEvent(Method(:Paste))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+i"))
							setbtnimage(self,"image/font.png")
							settext("Font")
							setclickEvent(Method(:Font))
						}
						addseparator()
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+t"))
							setbtnimage(self,"image/colors.png")
							settext("Text Color")
							setclickEvent(Method(:SelectColor))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+b"))
							setbtnimage(self,"image/colors.png")
							settext("Back Color")
							setclickEvent(Method(:SelectColor2))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+h"))
							settext("Set Tab Width")
							setclickEvent(Method(:TabWidth))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+g"))
							settext("Go to line")
							setclickEvent(Method(:Goto))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+f"))
							setbtnimage(self,"image/search.png")
							settext("Find and Replace")
							setclickEvent(Method(:OpenFindWindow))
						}
						addaction(oAction)
						addseparator()
                                                oAction = new qAction(this.win1) {
	                                                setShortcut(new QKeySequence("Ctrl+Shift+i"))
	                                                settext("Insert Text")
	                                                setclickEvent(Method(:OpenInsertWindow))
                                                }
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+L"))
							settext("Lower case")
							setclickEvent(Method(:lowerCase))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+U"))
							settext("Upper case")
							setclickEvent(Method(:upperCase))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+C"))
							settext("Capitalize")
							setclickEvent(Method(:capitalize))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+alt+C"))
							setbtnimage(self,"image/comment2.png")
							settext("Comment Lines")
							setclickEvent(Method(:CommentLines))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+alt+B"))
							setbtnimage(self,"image/comment.png")
							settext("Comment Block Of Lines")
							setclickEvent(Method(:CommentBlockLines))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+alt+f"))
							setbtnimage(self,"image/search.png")
							settext("Find in Files")
							setclickEvent(Method(:OpenFindInFiles))
						}
						addaction(oAction)
	
					}
					subView {
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+j"))
							setbtnimage(self,"image/project.png")
							settext("Project Files")
							setclickEvent(Method(:ProjectWindowStatus))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+u"))
							setbtnimage(self,"image/source.png")
							setclickEvent(Method(:SourceCodeWindowStatus))
							settext("Source Code")
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+w"))
							setbtnimage(self,"image/richtext.png")
							setclickEvent(Method(:WebBrowserWindowStatus))
							settext("Web Browser")
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+f"))
							setbtnimage(self,"image/source.png")
							setclickEvent(Method(:FunctionsListWindowStatus))
							settext("Functions List")
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+c"))
							setbtnimage(self,"image/source.png")
							setclickEvent(Method(:ClassesListWindowStatus))
							settext("Classes List")
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+o"))
							setbtnimage(self,"image/source.png")
							setclickEvent(Method(:OutputWindowStatus))
							settext("Output Window")
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("CTRL+SHIFT+F"))
							setbtnimage(self,"image/formdesigner.png")
							setclickEvent(Method(:FormDesignerWindowStatus))
							settext("Form Designer Window")
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setclickEvent(Method(:EditFullScreen))
							setbtnimage(self,"image/source.png")
							setShortcut(new QKeySequence("Ctrl+Shift+F1"))
							settext("Source Code (Full Screen)")
						}
						addaction(oAction)
						addseparator()
						subStyle = addmenu("Style")
						subStyle {
							setbtnimage(self,"image/colors.png")
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+W"))
								setclickEvent(Method("SetStyleColor(0)"))
								settext("Windows")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+2"))
								setclickEvent(Method("SetStyleColor(1)"))
								settext("Fusion : White")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+3"))
								setclickEvent(Method("SetStyleColor(2)"))
								settext("Fusion : Blue")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+4"))
								setclickEvent(Method("SetStyleColor(3)"))
								settext("Fusion : Black")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+5"))
								setclickEvent(Method("SetStyleColor(4)"))
								settext("Modern")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+6"))
								setclickEvent(Method("SetStyleColor(5)"))
								settext("Modern : Black")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+7"))
								setclickEvent(Method("SetStyleColor(6)"))
								settext("Modern : Black 2")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+8"))
								setclickEvent(Method("SetStyleColor(7)"))
								settext("Notepad : White")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+9"))
								setclickEvent(Method("SetStyleColor(8)"))
								settext("Notepad : Purple")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+A"))
								setclickEvent(Method("SetStyleColor(9)"))
								settext("Notepad : DarkBlue")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F7"))
								setclickEvent(Method("SetStyleColor(10)"))
								settext("Notepad : Black")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F8"))
								setclickEvent(Method("SetStyleColor(11)"))
								settext("Art")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F9"))
								setclickEvent(Method("SetStyleColor(12)"))
								settext("Art 2")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F10"))
								setclickEvent(Method("SetStyleColor(13)"))
								settext("Art 3")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F11"))
								setclickEvent(Method("SetStyleColor(14)"))
								settext("Image")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+Shift+F12"))
								setclickEvent(Method("SetStyleColor(15)"))
								settext("Image 2")
							}
							addaction(oAction)
						}
						addseparator()
						subStyle = addmenu("Mode")
						subStyle {
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+1"))
								setclickEvent(Method("SetMode(1)"))
								settext("General")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+2"))
								setclickEvent(Method("SetMode(2)"))
								settext("Learning Ring (Editor + Documentation)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+3"))
								setclickEvent(Method("SetMode(3)"))
								settext("Coding (Project File + Editor)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+4"))
								setclickEvent(Method("SetMode(4)"))
								settext("Coding (All Windows)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+5"))
								setclickEvent(Method("SetMode(5)"))
								settext("Coding (Code Editor)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+6"))
								setclickEvent(Method("SetMode(6)"))
								settext("GUI Development (Code Editor + Form Designer)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+7"))
								setclickEvent(Method("SetMode(7)"))
								settext("Web Development (Code Editor + Web Browser)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+8"))
								setclickEvent(Method("SetMode(8)"))
								settext("Testing (Project Files + Code Editor + Output Window)")
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								setShortcut(new QKeySequence("Ctrl+9"))
								setclickEvent(Method("SetMode(9)"))
								settext("Common (All Windows + Output Window in the bottom)")
							}
							addaction(oAction)
						}
					} 
					subProgram {
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+d"))
							setbtnimage(self,"image/debug.png")
							settext("Debug (Run then wait!)")
							setclickEvent(Method(:Debug))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+r"))
							setbtnimage(self,"image/run.png")
							settext("Run")
							setclickEvent(Method(:Run))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+F5"))
							setbtnimage(self,"image/rungui.png")
							settext("Run GUI Application (No Console)")
							setclickEvent(Method(:RunNoConsole))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+F6"))
							setbtnimage(self,"image/web.png")
							settext("Run Web Application (Open In Browser)")
							setclickEvent(Method(:RunInBrowser))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+M"))
							setbtnimage(self,"image/open.png")
							settext("Set the Main File to be the current source file")
							setclickEvent(Method(:SetMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+d"))
							setbtnimage(self,"image/debug.png")
							settext("Main File : Debug (Run then wait!)")
							setclickEvent(Method(:DebugMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+r"))
							setbtnimage(self,"image/run.png")
							settext("Main File : Run")
							setclickEvent(Method(:RunMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+F5"))
							setbtnimage(self,"image/rungui.png")
							settext("Main File : Run GUI Application (No Console)")
							setclickEvent(Method(:RunGUIMainFile))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+F6"))
							setbtnimage(self,"image/web.png")
							settext("Main File : Run Web Application (Open In Browser)")
							setclickEvent(Method(:RunInBrowserMainFile))
						}
						addaction(oAction)
                                                addseparator()
                                                oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Ctrl+Shift+P"))
							setbtnimage(self,"image/web.png")
							settext("Fix Ring files permissions to run by Apache")
							setclickEvent(Method(:MakeFilesExecutable))
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
							settext("Form Designer")
							setclickEvent(Method(:OpenFormDesigner))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+R"))
							settext("RingREPL - Console")
							setclickEvent(Method(:REPLConsole))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							setShortcut(new QKeySequence("Alt+Shift+R"))
							settext("RingREPL - GUI")
							setclickEvent(Method(:REPLGUI))
						}
						addaction(oAction)
						addseparator()
						subOSTools = addmenu("Operating System Tools")
						subOSTools {
							oAction = new qAction(this.win1) {
								settext("Terminal (Command Prompt)")
								setShortcut(new QKeySequence("Alt+Shift+T"))
								setclickEvent(Method(:OSTerminal))
							}
							addaction(oAction)
							addseparator()
							oAction = new qAction(this.win1) {
								settext("Files Manager (Explorer)")
								setShortcut(new QKeySequence("Alt+Shift+F"))
								setclickEvent(Method(:OSFilesManager))
							}
							addaction(oAction)
						}
					}
					subDistribute {
						oAction = new qAction(this.win1) {
							settext("Generate Ring Object File (*.ringo)")
							setclickEvent(Method("Distribute(1)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Build Console Application)")
							setclickEvent(Method("Distribute(2)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Build GUI Application)")
							setclickEvent(Method("Distribute(10)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute Application - Use All Runtime)")
							setclickEvent(Method("Distribute(3)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute Application - Use All Runtime - Hide Console Window)")
							setclickEvent(Method("Distribute(4)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute RingQt Application)")
							setclickEvent(Method("Distribute(5)"))
						}
						addaction(oAction)
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute RingAllegro Game)")
							setclickEvent(Method("Distribute(6)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Distribute Light RingQt Application - Using [QtCore, QtGui, QtWidgets])")
							setclickEvent(Method("Distribute(9)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Prepare Qt Project - Distribute for Mobile Devices)")
							setclickEvent(Method("Distribute(7)"))
						}
						addaction(oAction)
						addseparator()
						oAction = new qAction(this.win1) {
							settext("Ring2EXE (Prepare Qt Project - Distribute for Web Browsers using WebAssembly)")
							setclickEvent(Method("Distribute(8)"))
						}
						addaction(oAction)
					}
					subHelp {
						subHelpLF = addmenu("Language Reference")
						subHelpLF {
							oAction = new qAction(this.win1) {
								settext("CHM File")
								setclickEvent(Method(:OpenCHM))
							}
							addaction(oAction)
							oAction = new qAction(this.win1) {
								settext("PDF File")
								setclickEvent(Method(:OpenPDF))
							}
							addaction(oAction)
						}
						addseparator()
						subHelpTools = addmenu("Development Tools")
						subHelpTools {
	
							oAction = new qAction(this.win1) {
								settext("Programming Language")
								setclickEvent(Method(:Lang))
							}
							addaction(oAction)
							oAction = new qAction(this.win1) {
								settext("GUI Library")
								setclickEvent(Method(:GUI))
							}
							addaction(oAction)
						}
						addseparator()
						oAction = new qAction(this.win1) {
							settext("About")
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
				showmessage("Ready!",0)
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
				setGeometry(00,00,200,400)
				setminimumwidth(floor(this.oDesktop.width()*0.2))
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
				if not ismacosx()
					this.cWebsite = "file:///"+oDir.CurrentPath() + "/../documents/build/html/index.html"
				ok
			}
			this.oDockProjectFiles = new qdockwidget(this.win1,0) {
				setGeometry(00,00,200,200)
				setwindowtitle("Project Files")
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
				AddTab(new qWidget(),"noname")
				setcurrentchangedevent(Method(:ChangeFileTab))
				Settabcloserequestedevent(Method(:CloseFileTab))
				installeventfilter(oTabsFilter)
			}

			this.textedit1 = new codeeditor(this.win1) {
				setCursorPositionChangedEvent(Method(:CursorPositionChanged))
				setLineWrapMode(QTextEdit_NoWrap)
				setTextChangedEvent(Method(:TextChanged))
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
			new RingCodeHighLighter(this.textedit1.document() ) {
				if ismethod(self,:setkeywordsbold) 
					setKeywordsbold(this.lKeywordsBold)
				ok
				setColors(
					this.aStyleColors[:SyntaxKeywordsColor],
					this.aStyleColors[:SyntaxClassNamesColor],
					this.aStyleColors[:SyntaxCommentsColor],
					this.aStyleColors[:SyntaxLiteralsColor],
					this.aStyleColors[:SyntaxFunctionCallsColor]
				)
			}
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
				setwidget(this.oTabsAndText)
				setwindowtitle("Source Code")
				setminimumwidth(floor(this.oDesktop.width()*0.17))                                                     
			}
		}

	func CreateWebBrowser
		win1 {
			this.oWebBrowser = new qWidget() {
				setWindowFlags(Qt_SubWindow)
				oWBLabel = new qLabel(this.win1) {
					setText("Website: ")
				}
				this.oWBText = new qLineEdit(this.win1) {
					setText(this.cWebSite)
					setReturnPressedEvent(Method(:WebGo))
				}
				oWBGo = new qPushButton(this.win1) {
					setText("Go")
					setClickEvent(Method(:WebGo))
				}
				oWBBack = new qPushButton(this.win1) {
					setText("Back")
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
				setwidget(this.oWebBrowser)
				setwindowtitle("Web Browser")
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
				setWidget(this.oFunctionsList)
				setwindowtitle("Functions")
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
				setWidget(this.oClassesList)
				setwindowtitle("Classes")
			}
		}

	func CreateOutputWindow
		win1 {
			this.oProcess = NULL
			this.oOutputWindow = new qWidget()
			oProcessLabel = new qLabel(this.oOutputWindow) {
				setText("Input :")
			}
			this.oProcessText = new qlineEdit(this.oOutputWindow) {
				setreturnPressedEvent(Method(:SendProcessData))
			}
			oProcessbtnSend = new qpushbutton(this.oOutputWindow) {
				setText("Send")
				setClickEvent(Method(:SendProcessData))
			}
			oClearbtn = new qpushbutton(this.oOutputWindow) {
				settooltip("Clear output/Stop running program")
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
			this.oProcessEditbox = new qPlaintextedit(this.oOutputWindow) 
			oProcessLayout2 = new qvboxlayout() {
				addWidget(this.oProcesseditbox)
				addlayout(oProcesslayout1)
			}
			this.oOutputWindow.setlayout(oProcessLayout2)
			this.oDockOutputWindow = new qDockWidget(this.win1,0) {
				setwidget( this.oOutputWindow )
				setwindowtitle("Output")
			}
		}

	func CreateFormDesigner
		win1 {
			this.oDockFormDesigner = new qDockwidget(this.win1,0) {
				setwindowtitle("Form Designer")
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

	func EditFullScreen
		if lEditboxFullScreen 
			oDockSourceCode { show() raise() }
			textedit1.setParent(oTabsAndText)
			oLayoutTabsText.AddWidget(textedit1)
			textedit1 { show() setfocus(7) }
		else 
			oDockSourceCode.hide()
			textedit1 { 
				setParent(NULL)
				showfullscreen()
				setfocus(7)
			}
		ok
		lEditboxFullScreen = ! lEditboxFullScreen 

	func TextEditKeyPress
		nKeyCode = this.oFilterTextEdit.getkeycode()
		# Check CTRL+SHIFT+F1
		if lEditboxFullScreen and nKeyCode = Qt_Key_Escape
			EditFullScreen()
			return
		ok
		this.oFilterTextEdit.setEventoutput(False)

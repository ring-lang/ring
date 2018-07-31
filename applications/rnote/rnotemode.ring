# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteMode 

	func pSetMode nMode
		switch nMode
			on VIEWMODE_GENERAL	
				oDockProjectFiles.Show()
				oDockSourceCode.show()
				oDockWebBrowser.show()
				oDockClassesList.show()
				oDockFunctionsList.show()
				oDockOutputWindow.show()
				oDockFormDesigner.show()
				win1 {
					adddockwidget(Qt_LeftDockWidgetArea,this.oDockProjectFiles,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,2)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockFunctionsList,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockClassesList,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockWebBrowser,1)
					adddockwidget(Qt_BottomDockWidgetArea,this.oDockOutputWindow,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockFormDesigner,1)
					tabifydockwidget(this.oDockFunctionsList,this.oDockClassesList)
					tabifydockwidget(this.oDockFunctionsList,this.oDockOutputWindow)
					tabifydockwidget(this.oDockSourceCode,this.oDockFormDesigner)
					tabifydockwidget(this.oDockSourceCode,this.oDockWebBrowser)
				}
				oDockSourceCode.raise()
				oDockFunctionsList.raise()				
			on VIEWMODE_LEARNINGRING
				oDockProjectFiles.Show()
				oDockSourceCode.show()
				oDockWebBrowser.show()
				oDockClassesList.hide()
				oDockFunctionsList.hide()
				oDockOutputWindow.hide()
				oDockFormDesigner.hide()
				win1 {
					adddockwidget(Qt_LeftDockWidgetArea,this.oDockProjectFiles,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,2)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockWebBrowser,1)
				}
				pBrowserLink(1)
			on VIEWMODE_CODING	# Coding (Project Files + Editor)
				oDockProjectFiles.Show()
				oDockSourceCode.show()
				oDockWebBrowser.hide()
				oDockClassesList.hide()
				oDockFunctionsList.hide()
				oDockOutputWindow.hide()
				oDockFormDesigner.hide()
			on VIEWMODE_CODING2	# Coding (All Windows)
				pSetMode(VIEWMODE_GENERAL)
				win1 {
					tabifydockwidget(this.oDockProjectFiles,this.oDockFunctionsList)
					tabifydockwidget(this.oDockProjectFiles,this.oDockClassesList)
					tabifydockwidget(this.oDockProjectFiles,this.oDockOutputWindow)
					tabifydockwidget(this.oDockSourceCode,this.oDockFormDesigner)
					tabifydockwidget(this.oDockSourceCode,this.oDockWebBrowser)
				}
				oDockSourceCode.raise()
				oDockProjectFiles.raise()
			on VIEWMODE_CODING3	# Coding (Code Editor)
				oDockProjectFiles.hide()
				oDockSourceCode.show()
				oDockWebBrowser.hide()
				oDockClassesList.hide()
				oDockFunctionsList.hide()
				oDockOutputWindow.hide()
				oDockFormDesigner.hide()
			on VIEWMODE_GUIDEV	# GUI Development (Code Editor + Form Designer)
				oDockProjectFiles.hide()
				oDockSourceCode.show()
				oDockWebBrowser.hide()
				oDockClassesList.hide()
				oDockFunctionsList.hide()
				oDockOutputWindow.hide()
				oDockFormDesigner.show()
				win1 {
					adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,2)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockFormDesigner,1)
				}
			on VIEWMODE_WEBDEV	# Web Development (Code Editor + Web Browser)
				oDockProjectFiles.hide()
				oDockSourceCode.show()
				oDockWebBrowser.show()
				oDockClassesList.hide()
				oDockFunctionsList.hide()
				oDockOutputWindow.hide()
				oDockFormDesigner.hide()
				pBrowserLink(2)
				win1 {
					adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,2)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockWebBrowser,1)
				}
			on VIEWMODE_TESTING	
				oDockProjectFiles.Show()
				oDockSourceCode.show()
				oDockWebBrowser.hide()
				oDockClassesList.hide()
				oDockFunctionsList.hide()
				oDockOutputWindow.show()
				oDockFormDesigner.hide()
				win1 {
					adddockwidget(Qt_LeftDockWidgetArea,this.oDockProjectFiles,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,2)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockOutputWindow,1)
				}
			on VIEWMODE_COMMON	
				pSetMode(VIEWMODE_GENERAL)
				win1 {
					adddockwidget(Qt_LeftDockWidgetArea,this.oDockProjectFiles,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockSourceCode,1)
					adddockwidget(Qt_RightDockWidgetArea,this.oDockOutputWindow,2)
					tabifydockwidget(this.oDockFormDesigner,this.oDockSourceCode)
					# Change the order
						tabifydockwidget(this.oDockSourceCode,this.oDockFormDesigner)
					tabifydockwidget(this.oDockFormDesigner,this.oDockWebBrowser)
				}
				oDockSourceCode.raise()
		off
		nDefaultMode = nMode

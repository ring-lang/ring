load "string2constantview.ring"

import System.GUI

if isMainSourceFile() { 
	new App
	{
		StyleFusion()
		open_window(:string2constantController)
		exec()
	}
}

class string2constantController from WindowsControllerParent

	oView = new string2constantView

	oView { 
		win.showmaximized()	
		LineEditConstantStart.setText("C_FORMDESIGNER_")
		TextEditInput.setFocus(True)
	}

	func process

		cConstant = oView.LineEditConstantStart.text()
		cText = oView.TextEditInput.toplaintext()
		cOutput = ""
		cConstantsList = ""
		aList = str2list(cText)
		nMax = len(aList)
		for x = 1 to nMax step 1 { 
			cLine = aList[x]
			nMax2 = len(cLine)
			nStart = 0
			nEnd = 0
			lStart = False
			cStartChar = ""
			for x2 = 1 to nMax2 step 1 { 
				cChar = cLine[x2]
				if cChar = "#" {
					exit 
				}
				if lStart = False and (cChar = '"' or cChar = "'" or cChar = "`") { 
					lStart = True
					cStartChar = cChar
					nStart = x2
					loop 
				}
				if lStart = True and cChar = cStartChar { 
					nEnd = x2
					cStartChar = ""
					cNewLine = substr(cLine,1,nStart-1)
					cNewLine = cNewLine+cConstant
					cStringBase = substr(cLine,nStart,nEnd-nStart+1)
					cString = upper(cStringBase)
					cString = substr(cString,2,len(cString)-2)
					cString = substr(cString," ","")
					cString = substr(cString,"(","")
					cString = substr(cString,")","")
					cString = substr(cString,":","")
					cNewLine = cNewLine + cString
					cStringEnd = SubStr(cLine,nEnd+1)
					cNewLine = cNewLine + cStringEnd
					cNewLine = cNewLine + Copy(Tab,3) + " # " + cStringBase
					aList[x] = cNewLine
					lStart = False
					cConstantsList += cConstant+cString + Copy(Tab,3) + " = " + cStringBase + WindowsNL()
					x -= 1
					exit 
				}
			}
		}
		cOutput = list2str(aList)
		oView.TextEditOutput.setText(cOutput)
		oView.TextEditConstants.setText(cConstantsList)

	func clear

		oView {
			LineEditConstantStart.settext("")
			TextEditInput.settext("")
			TextEditOutput.settext("")
			TextEditConstants.settext("")
		}

	func closeapp

		oView.win.close()

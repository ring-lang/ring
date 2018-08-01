# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteHelp

	func pOpenCHM
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(exefolder(),"\","/")+"../docs/ring.chm") )
		}

	func pOpenPDF
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(exefolder(),"\","/")+"../docs/ring.pdf") )
		}

	func MsgBox cTitle,cMessage
		win = new qMessagebox(win1) {
			setwindowtitle(cTitle)
			setText(cMessage)
			setwinicon(win,this.cCurrentDir + "/image/notepad.png")
			show()
		}

	func pLang
		MsgBox("Programming Language",
			"This application developed using the Ring programming language" + nl +
			"Ring Version : " + version())

	func pGUI
		MsgBox("GUI Library",
			"This application uses the Qt GUI Library through RingQt")

	func pAbout
		MsgBox("About",
			"Ring Notepad (Ring Version : " + Version() + ")" + nl +			
			"2016-2018, Mahmoud Fayed <msfclipper@yahoo.com>")


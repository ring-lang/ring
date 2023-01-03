# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteHelp

	func OpenCHM
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(exefolder(),"\","/")+"../documents/ring.chm") )
		}

	func OpenPDF
		new QDesktopServices {
			OpenURL(new qURL("file:///"+substr(exefolder(),"\","/")+"../documents/ring.pdf") )
		}

	func MsgBox cTitle,cMessage
		win = new qMessagebox(win1) {
			setwindowtitle(cTitle)
			setText(cMessage)
			setwinicon(win,this.cCurrentDir + "/image/notepad.png")
			show()
		}

	func Lang
		MsgBox("Programming Language",
			"This application is developed using the Ring programming language" + nl +
			"Ring Version : " + version())

	func GUI
		MsgBox("GUI Library",
			"This application uses the Qt Framework through RingQt")

	func pAbout
		MsgBox("About",
			"Ring Notepad (Ring Version : " + Version() + ")" + nl +			
			"2016-2023, Mahmoud Fayed <msfclipper@yahoo.com>")


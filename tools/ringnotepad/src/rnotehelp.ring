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
		MsgBox(T_RINGNOTEPAD_HELPPL,
			T_RINGNOTEPAD_HELPLANGUSED + nl +
			T_RINGNOTEPAD_RINGVERSION + version())

	func GUI
		MsgBox(T_RINGNOTEPAD_HELPGUILIB,
			T_RINGNOTEPAD_HELPGUILIBNAME)

	func pAbout
		MsgBox(T_RINGNOTEPAD_HELPABOUT,
			T_RINGNOTEPAD_HELPAPPRINGVERSION + Version() + T_RINGNOTEPAD_HELPAPPRINGVERSIONAFTER + nl +			
			R_RINGNOTEPAD_AUTHOR)


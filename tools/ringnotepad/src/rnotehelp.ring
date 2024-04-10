# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteHelp

	func OpenCHM
		cFile = substr(exefolder(),"\","/")+"../documents/ring.chm"
		cFile = substr(cFile,"/bin/../","/")
		if fexists(cFile)
			new QDesktopServices {
				OpenURL(new qURL("file:///"+cFile) )
			}
		else 
			msginfo("Sorry","The file " + cFile + " doesn't exist! " + nl +
					"Download the file using (ringpm install ringhelpchm) " + nl +
					"OR download it from Ring Website (Download Page) ")
		ok

	func OpenPDF
		cFile = substr(exefolder(),"\","/")+"../documents/ring.pdf"
		cFile = substr(cFile,"/bin/../","/")
		if fexists(cFile)
			new QDesktopServices {
				OpenURL(new qURL("file:///"+cFile) )
			}
		else 
			msginfo("Sorry","The file " + cFile + " doesn't exist! " + nl + 
					"Download the file using (ringpm install ringhelppdf) "+ nl +
					"OR download it from Ring Website (Download Page) ")
		ok

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
			T_RINGNOTEPAD_AUTHOR)


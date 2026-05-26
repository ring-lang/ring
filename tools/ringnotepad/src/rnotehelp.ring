# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteHelp

	func DocumentationFileFullPath cFile
		cFile = substr(exefolder(),"\","/")+"../documents/" + cFile
		cFile = substr(cFile,"/bin/../","/")
		return cFile

	func CheckDocmentationFile cFile
		return fexists(DocumentationFileFullPath(cFile))

	func CheckCHMFile
		return CheckDocmentationFile("ring.chm")

	func CheckPDFFile
		return CheckDocmentationFile("ring.pdf")

	func OpenCHM
		cFile = DocumentationFileFullPath("ring.chm")
		if CheckCHMFile()
			new QDesktopServices {
				OpenURL(new qURL("file:///"+cFile) )
			}
		else 
			msginfo("Sorry","The file " + cFile + " doesn't exist! " + nl +
					"Download the file using (ringpm install ringhelpchm) " + nl +
					"OR download it from Ring Website (Download Page) ")
		ok

	func OpenPDF
		cFile = DocumentationFileFullPath("ring.pdf")
		if CheckPDFFile()
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
			T_RINGNOTEPAD_RINGVERSION + version(True))

	func GUI
		MsgBox(T_RINGNOTEPAD_HELPGUILIB,
			T_RINGNOTEPAD_HELPGUILIBNAME)

	func pAbout
		MsgBox(T_RINGNOTEPAD_HELPABOUT,
			T_RINGNOTEPAD_HELPAPPRINGVERSION + Version(True) + T_RINGNOTEPAD_HELPAPPRINGVERSIONAFTER + nl +			
			T_RINGNOTEPAD_AUTHOR)


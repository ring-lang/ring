# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteActiveFolder

	func SaveCurrentFolder
		oItem = tree1.currentindex()
		if ofile.isdir(oItem)
			cStartupFolder = ofile.filepath(oItem)
		else
			cFile = ofile.filepath(oItem)
			for t = len(cFile) to 1 step -1
				if cFile[t] = "/" or cFile[t] = "\"
					cFile = left(cFile,t-1)
					exit
				ok
			next
			cStartupFolder = cFile
		ok

	func GetActiveFolder
		return cStartUpFolder

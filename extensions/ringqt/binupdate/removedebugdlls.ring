# Remove debug dlls and *.pdb files from ring/bin folder
# 2020, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"

aAvoid = [
"Qt5Gamepad.dll",
"Qt5VirtualKeyboard.dll"
]

aFiles = listallfiles(exefolder(),"*.dll")
aFiles = Map(aFiles, func item {
	item = justFileName(item)
	return item
})

aFiles = Filter(aFiles, func item {
	if left(lower(item),3) = "qt5" and
		right(item,5) = "d.dll"
		if not find(aAvoid,item) 
			return True
		ok
	ok
	return False
})

DeleteFiles(aFiles)

aFiles = listallfiles(exefolder(),"*.pdb")

DeleteFiles(aFiles)

func DeleteFiles aFiles
	for cFile in aFiles
		? "Delete File: " + cFile
		remove(exefolder()+"\"+cFile)
	next

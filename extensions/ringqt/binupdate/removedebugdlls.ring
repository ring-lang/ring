# Remove debug dlls and *.pdb files from ring/bin folder
# 2020, Mahmoud Fayed <msfclipper@yahoo.com>

load "stdlibcore.ring"

aAvoid = [
"Qt5Gamepad.dll",
"Qt5VirtualKeyboard.dll"
]

aFiles = listAllFiles(exefolder(),"*.dll")
aFiles = Map(aFiles, func item {
	item = justFileName(item)
	return item
})

aFiles = myFilter(aFiles, func item {
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

// Since stdlibcore.ring have another global scope starting from Ring 1.20
// It's filter() function can't access the global list aAvoid
// So we define a custom filter function

Func myFilter alist,cFunc
	alist2 = []
	for x in alist
		if call cFunc(x)
			alist2 + x
		ok
	next
	return alist2
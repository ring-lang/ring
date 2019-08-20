/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 17/12/2017
*/
#================================================================

aFiles = dir("c:/ring/Developer/Arabic/Samer")

# Get *.ring files
	alist = []
	for aFile in aFiles
		if right(aFile[1],5) = ".ring"
			alist + aFile[1]
		ok
	next
# sort the list of files
	alist = sort(alist) 

# print files as list
	x = 1
	for cFile in alist
		? "(" + x +") " + cFile
		x++
	next
# Get the file number 
	give cNumber
	nNumber = 0 + cNumber
	if cNumber < len(alist)
		? read(alist[nNumber])
	ok

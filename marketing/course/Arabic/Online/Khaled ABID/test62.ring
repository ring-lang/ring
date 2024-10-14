/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 05/02/2018
*/

aFiles = dir("Z:\Ring\developers\Arabic\Khaled ABID")

# Get *.ring files 
aList = []
	for aFile in aFiles
		if right(aFile[1],5)= ".ring"
			aList + aFile[1]
		ok
	next

# Sort the list of files
	aList = sort(aList)

# Print files as a list
	x = 1
	for cFile in aList
		? "(" + x + ") " + cFile
		x++
	next

# Get the file number 
	give cNumber
	nNumber = 0 + cNumber
	if nNumber < len(aList)
		? read(aList[nNumber])
	ok

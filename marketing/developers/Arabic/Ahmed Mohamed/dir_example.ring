/*
	Application	: Dir Example
	Author		: Ahmed Mohamed
	Date		: 2019/10/16
*/

aFiles = dir("C:\ring\applications\Ahmed Mohamed\Lecture_7")

# Get * .ring Files

	aList = []

	for aFile in aFiles
		if right(aFile[1], 5) = ".ring"	
			aList + aFile[1]
		ok
	next

# Sort The List Of Files

	aList = sort(aList)

# Print Files as a list
	x = 0
	for cFile in aList
		x = x + 1
		? "(" + x + ")" + cFile
	next

# Get The File Number
	give cNumber
	nNumber = 0 + cNumber

	if nNumber < len(aList)
		? read(aList[nNumber])
	ok




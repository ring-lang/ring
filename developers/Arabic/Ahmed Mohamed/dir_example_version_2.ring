/*
	Application	: Dir Example Version 2
	Author		: Ahmed Mohamed
	Date		: 2019/10/24
*/

aFiles = dir("E:\Development\Ring\ring\applications\Ahmed Mohamed\Lecture_7")

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
	nNumber = floor(nNumber)
	if nNumber > 0 and nNumber < len(aList)
		? read(aList[nNumber])
	ok




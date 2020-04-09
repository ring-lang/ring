/*
	Application	: Dir
	Author		: Ahmed Mohamed
	Date		: 2019/10/16
*/

aFiles = dir("C:\ring\applications\Ahmed Mohamed\Lecture_7")

x = 0

for aFile in aFiles
	x = x + 1
	if right(aFile[1], 5) = ".ring"
	
	? "================="
	? "File Number " + x
	? "File ( " + x + " ) " + aFile[1]
	? "================="
	? read(aFile[1])

	ok

next

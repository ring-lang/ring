/*
**	Application Name : Dir;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-18;		
*/
#Get Files 
aFiles = dir("c:/ring/applications/lessons")

#Get Ring files
	aList = []
	for aFile in aFiles
		if right(aFile[1], 5) = ".ring"
			aList + aFile[1]
		ok
	next
#sort the list
aList = sort(aList)
#Print file name
x = 1
	for cFile in aList
		? "(" + x + ")" + cFile
		x++
	next
#Give options
	give cNumber
		nNumber = 0 + cNumber
		if nNumber < len(aList)
			? read(aList[nNumber])
		ok 	










/*
**	Application		: Ring lessons .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 08 .
*/

aFiles = dir("c:/ring/developers/Arabic/Osama Ballan")

# Get *.ring Files
aRingFiles = []

	for aFile in aFiles
		if right(aFile[1],5) = ".ring"
			aRingFiles + aFile[1]
		ok
	next

# Sort The List Of Files
	aRingFiles = sort(aRingFiles)

# Print Files as a List
	nFile = 1
	for cFile in aRingFiles 
		if nFile<10
		? "(0" + nFile + ')  ' + cFile
		else
		? "(" + nFile + ')  ' + cFile
		ok
	nFile++
	next

# Get The File Number
	? "Enter The Number Of File To Read It ..." 
	give cNumber
	nNumber = 0 + cNumber
	if nNumber < len(aRingFiles)
		? read(aRingFiles[nNumber])
	ok























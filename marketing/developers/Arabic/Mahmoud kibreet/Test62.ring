/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.28
*/

aFiles = dir("C:\ring\developers\Arabic\Mahmoud Kibreet")

# Get *.ring of files
aList = []
	for aFile in aFiles
		if right(aFile[1],5) = ".ring"
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
	if nNumber < Len(aList)
		? read(aList[nNumber])
	ok


/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.29
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
        nNumber = floor(nNumber)
	if nNumber > 0 and nNumber <= Len(aList)
		? read(aList[nNumber])
	ok


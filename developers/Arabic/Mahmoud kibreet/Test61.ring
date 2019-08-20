/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.28
*/

aFiles = dir("C:\ring\developers\Arabic\Mahmoud Kibreet")

for aFile in aFiles
	if right(aFile[1],5) = ".ring"
		? "File :" + aFile[1]
		? read(aFile[1])
	ok	
next

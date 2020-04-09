/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 17/12/2017
*/
#================================================================

aFiles = dir("c:/ring/Developer/Arabic/Samer")

for aFile in aFiles
	if right(aFile[1],5) = ".ring"
		? "file: " + aFile[1]
		? read(afile[1])
	ok
next

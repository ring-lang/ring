/*
**	Application Name : Dir;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-18;		
*/
aFiles = dir("c:/ring/applications/lessons")
for aFile in aFiles
	if right(aFile[1], 5) = ".ring"
	 	? "file " + aFile[1] 
	? read(aFile[1])
	ok
next


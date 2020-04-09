/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

aFiles = dir("b:/ring/developers/arabic/mahmoud")

for aFile in aFiles 
	if right(aFile[1],5) = ".ring"
		? "File : " + aFile[1]
		? read(aFile[1])
	ok
next 

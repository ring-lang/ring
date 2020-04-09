/*
	Application	: Ring Lessons
	Author		: Khaled ABID
	Date		: 05/02/2018
*/

aFiles = dir("Z:\Ring\developers\Arabic\Khaled ABID")

for aFile in aFiles
	if right(aFile[1],5)= ".ring"
		? "File: " + aFile[1]
		? read(aFile[1])
	ok
next

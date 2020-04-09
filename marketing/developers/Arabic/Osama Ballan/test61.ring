/*
**	Application		: Ring lessons .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 08 .
*/

aFiles = dir("c:/ring/developers/Arabic/Osama Ballan")

for aFile in aFiles

	if right(aFile[1],5) = ".ring"
		? "File : " + aFile[1]
		? read(aFile[1])
	ok

next







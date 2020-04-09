/*
**	Application  	: Variables  ( Lists) - Version 2 .
**	Author 	    	: Osama Ballan .
**	Date			: 2018 - 01 - 04 .
*/

# Variable Types (String, Number, List, Object, c Object)

aList = [
		:name	= "Osama",
		:Job 	  	= "programmer",
		:Country 	= "Syria",
		:city		= "Damas"
	]

? "Size = " + len(aList)
for aItem in aList
	? aItem[2]
next

? "======="

? aList[1][2]

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
? aList[:name]
? aList[:job]
# ? isNull(aList[:city])
# if isNULL(aList[:city]) aList[:city] = "Swaida" ok
if aList[:city] = "" aList[:city] = "Swaida" ok
? aList[:city]

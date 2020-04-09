/*
**	Application  	: Conversion Between Lists And Strings .
**	Author 	    	: Osama Ballan .
**	Date			: 2018 - 01 - 04 .
*/

# Variable Types (String, Number, List, Object, c Object)

aList = [:one, :two, :three, :four, :five]
? len(aList)
see aList

cString = list2str(aList)
? len(cString)
? cString

aList2 = str2list(cString)
? len(aList2)
? aList2

/*
	Application	: Variables (Lists) - version 3
	Author		: Khaled ABID
	Date		:25/12/2017
*/

# Variable Types (String, Number, List, Object, C Object)

aList = [
	:name	= "Khaled ABID",
	:job	= "software Programmer",
	:country= "Algeria",
	:city	= "Oran"
]

? "Size: " + len(aList)
for aItem in aList
	? aItem[2]

next

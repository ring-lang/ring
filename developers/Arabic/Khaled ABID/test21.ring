/*
	Application	: Variables (Lists) - version 2
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

? aList[:name]
? aList[:job] ? aList[:country]

if aList[:city] = null aList [:city] = "Algiers" ok
? aList[:city]

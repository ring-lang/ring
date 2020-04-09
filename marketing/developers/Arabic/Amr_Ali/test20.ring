/*
**	Application	: variables (List) 
**	Author    	: Amr Ali
**	Date   		: 08/03/2018
*/
####################################################################
# Variables types(String, Number, List, Objet, c object)

aList = [
	:name 	 = "Amr",
	:address = "Hadara",
	:Job     = "Programmer"
]

? "Size : " + len(aList)
for aItem in aList
	? aItem[2]
next



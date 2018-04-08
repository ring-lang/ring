/*
**	Application	: Conversion between Lists and strings
**	Author    	: Amr Ali
**	Date   		: 08/03/2018
*/
####################################################################
# Variables types(String, Number, List, Objet, c object)

aList = [:one, :two, :three, :four]

? aList
? "Size: " + len(aList)

cstr = list2str(aList)

? len(cstr)

cstr2 = str2list(cstr)
? len(cstr2)


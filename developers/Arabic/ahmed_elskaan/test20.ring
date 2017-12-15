/*
**	Application Name : conversion between lists and strings;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-11;		
*/
aList = [ :one, :two, :three, :four]
? aList 
? len(aList)
cStr = list2str(aList)
? cStr 
? len(cStr)
aList2 = str2list(cStr)
? len(aList2)

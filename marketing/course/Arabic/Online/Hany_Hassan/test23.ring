/*
**  Application: Conversion between lists and strings
**  Author     : Hany Hassan
**  Date       : 2017.12.13
*/
#=========================================================================================
# Variable Types (String, Number, List, Object, C Object)
#	  1	2	3	4	5 
aList = [ :one, :two, :three, :four, :five]

? aList 
? len(aList)

cString = list2str(aList)
? len(cString)

? cString 

aList2 = str2list(cString)
? len(aList2)
#=========================================================================================

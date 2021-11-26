/*
**	Application		:Conversions (list-string)
**	Author			:Adel Mahmoud
**	Date			:2018.01.28
*/

#=========================================================
#	   1	2     3     4	  5
aList = [ :one, :two, :three, :four, :five ]

? len(aList) + nl
? aList

cString = list2str(aList)
? cString + nl
? len(cString) + nl		# 23 but actual it is 19 as nl is counted

aList2 = str2list(cString)
? aList2 
? len(aList2)


#=========================================================

/*
**	Application  	: List Functions .
**	Author 	    	: Osama Ballan .
**	Date			: 2018 - 01 - 04 .
*/

# Variable Types (String, Number, List, Object, c Object)

aList = 1:10			# 10 Items
? aList

del(aList, 5)			# 9 Items
? aList

aList + "Syria"			# 10
aList + "Lebanon"		# 11
aList + "Egypt"			# 12

? aList
? "Syria Position is : " + find(aList, "Syria")

aList = [
		["Osama",100],
		["Mahmoud",200],
		["Sami",300],
		["Kareem",400]
	]

? aList[find(alist,"Mahmoud",1)][2]
? aList[find(alist,"Kareem",1)][2]

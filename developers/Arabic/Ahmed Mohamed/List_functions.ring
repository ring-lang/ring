/*
	Application	: List Functions
	Author		: Ahmed Mohamed
	Date		: 2019/10/14
*/


# Variables Types (Strings, Number, List, Object, C Object)

aList = 1:10		# 10 Items

? aList

del(aList, 5)		# 9 Items

? aList

aList + "Egypt"		# 10
aList + "Ksa"		# 11
aList + "France"	# 12

? "Egypt Position : " + find(aList, "Egypt")

aList = [
	["Ahmed", 	100],
	["Mohamed", 	200],
	["Ibrahim", 	300],
	["Kamal", 	400]
]

? aList[find(aList, "Ibrahim", 1)][2]
? aList[find(aList, "Mohamed", 1)][2]




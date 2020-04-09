/*
**	Application : List Functions
**	     Author : Khalid Khairy
**	       Date : 14/12/2017
*/

#========================================================
aList = 1:10
?aList          	# 10 item
del(aList, 5)
? aList         	# 9 item
	
aList + "Egypt" 	# 10
aList + "KSA"   	# 11
aList + "France"	# 12

? "Egypt position : " + find(aList, "Egypt")

aList = [
	["Mohammed",	100],
	["Mahmoud",	200],
	["Ahmed",	300],
	["Ibrahim",	400]
]
? aList[find(aList, "Mohammed", 1)][2]
? aList[find(aList, "Ahmed", 1)][2]



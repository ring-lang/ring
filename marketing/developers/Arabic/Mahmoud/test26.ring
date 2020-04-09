/*
	Application 	: List Functions 
	Author		: Mahmoud Fayed
	Date		: 2017.12.13
*/

# Variable Types (String, Number, List, Object, C Object)

aList = 1:10		# 10 items
? aList 

del(aList,5)		# 9 items 
? aList 

aList + "Egypt"		# 10
aList + "KSA"		# 11
aList + "France"	# 12

? "Egypt position : " + find(aList,"Egypt") 

aList = [ 
	["Mohammed"	,100],
	["Mahmoud"	,200],
	["Ahmed"	,300],
	["Ibrahim"	,400]
]

? aList[find(aList,"Mohammed",1)][2]
? aList[find(aList,"Ahmed",1)][2]




/*
	Application	: Lists Functions
	Author		: Khaled ABID
	Date		:25/12/2017
*/

# Variable Types (String, Number, List, Object, C Object)

aList = 1:10 		# 10
? aList

del(aList,5) 		# 9
? aList 

aList + "Jordan"	# 10
aList + "oran"		# 11
aList + "Tunisia"	# 12

? "Tunisia Position is " + find(aList,"Tunisia") # 12
? "Enter Item To Find Position: " Give aItem
? "Item is " + aItem + ", it Position is " + find(aList,aItem) # OutPut Item is tunisia, it Position is 0
								# 	Item is Tunisia, it Position is 12
								# 	Item is 8, it Position is 0


aList2 = [ 
	 ["Mohammed"	,1001],
	 ["Mahmoud"	,1002],
	 ["Ahmed"	,1003],
	 ["Khaled"	,1004]
]

? aList2[find(aList2,"Mahmoud",1)][2]
? aList2[find(aList2,"Khaled",1)][2]
# ? aList2[find(aList2,"khaled",1)][2]	error on  "K" in line32 is Upper but in line33 is lower
/* Line 35 Error (R2) : Array Access (Index out of range) ! 
					in file Z:/Ring/developers/Arabic/Khaled ABID/test26.ring */
/*? "Enter Item: " give aItem2
? "Item is "+ aItem2 + " it Value is " + aList2[find(aList2,aItem2,1)][2]*/

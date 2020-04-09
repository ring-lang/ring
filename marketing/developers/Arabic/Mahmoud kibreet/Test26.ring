/*
          Application : List Functions
          Author      : Mahmoud Kibreet
          Date        : 2018.01.24
*/

# Variable Types (String , Number , List , Object , C Object)

aList = 1:10      # 10 items
? aList

del(aList,5)      # 9 items
? aList

aList + "Lebanon" # 10
aList + "KSA"     # 11 
aList + "Lebanon" # 12

? "Lebanon position : " + find(aList,"Lebanon") 

aList =[
	["Mahmoud"	,100],
	["Mohammad"	,200],
	["Kibreet"	,300],
	["Ibriham"	,400]
]

? aList[find(aList,"Mahmoud",1)][2]
? aList[find(aList,"Kibreet",1)][2]

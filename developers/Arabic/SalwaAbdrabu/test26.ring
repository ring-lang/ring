/*
	Application : List Functions
	Author      : Salwa Abdrabu
*/

# Variables Type( String, Number, List, Object, C Object )
aList = 1:10                 # 10 Items
? aList

del(aList,5)                # 9 Items
? aList

aList + "Egypt"            # 10
aList + "KSA"              # 11
aList + "France"           # 12

? "Egypt Position :"+ find(aList,"Egypt")

aList = [
	["Salwa"   ,100],
	["Ahmed"   ,200],
	["Fatma"   ,300],
	["Mohamed" ,400]
]

? aList[ find(aList,"Salwa",1)][2]
? aList[ find(aList,"Fatma",1)][2]

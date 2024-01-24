aList = 1:3
add(aList,4:6)
? len(aList)	# 4

aList = 1:3
add(aList,4:6,True) 
? len(aList)	# 6
? aList

add(aList,["seven","eight","nine"],True)
? len(aList)	# 9
? aList

add(aList,[1,"two",["three","four"]],True)
? len(aList)	# 12
? aList
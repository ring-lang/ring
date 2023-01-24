# Before using Ref(), The Assignment(=) uses copy by value
# After  using Ref(), The Assignment(=) uses copy by reference 

aList     = [1,2,3,4,5]	# RC = 1
aListCopy = aList	# Copy by Value
aList2 = ref(aList)	# RC = 2
aList3 = aList2		# RC = 3 
aList4 = aList3		# RC = 4
aList5 = aList4		# RC = 5

? refcount(aList)
aList5 = [6,7,8,9,10]
? refcount(aList)
aList4[1] = 10
aList4[2] = 20
aList4[3] = 30
aList4[4] = 40
aList4[5] = 50
? aList
? aListCopy
? aList5
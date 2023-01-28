aList     = [1,2,3]
aListCopy = aList	# Copy by Value 
aList2    = ref(aList)	# Copy by Reference  (RC: 2)
aList3    = aList 	# Copy by Reference  (RC: 3)
for item in aList
	item *= 10
next
? aList3		# 10 20 30
? aListCopy		# 1 2 3
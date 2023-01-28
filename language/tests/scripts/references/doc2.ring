aList  = 1:10
aList2 = ref(aList)
? refcount(aList)	# 2
? refcount(aList2)	# 2
aList3 = aList2
aList4 = aList
aList5 = aList4
? refcount(aList)	# 5
? refcount(aList2)	# 5
? refcount(aList3)	# 5
? refcount(aList4)	# 5
? refcount(aList5)	# 5
aList5 = NULL
aList4 = []
aList3 = [10]
? refcount(aList)	# 2
? refcount(aList2)	# 2